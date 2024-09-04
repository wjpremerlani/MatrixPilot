
#include "libDCM_internal.h"
#include "mathlibNAV.h"
#include "deadReckoning.h"
#include "gpsParseCommon.h"
#include "../libUDB/magnetometer.h"
#include "../libUDB/heartbeat.h"
#include "../libUDB/ADchannel.h"
#include <math.h>
#include "../libDCM/matrix_vector_32_bit.h"
#include "../libDCM/rmat_32.h"

// These are the routines for maintaining a direction cosine matrix
// that can be used to transform vectors between the earth and plane
// coordinate systems. The 9 direction cosines in the matrix completely
// define the orientation of the plane with respect to the earth.
// The inverse of the matrix is equal to its transpose. This defines
// the so-called orthogonality conditions, which impose 6 constraints on
// the 9 elements of the matrix.

// All numbers are stored in 2.14 format.
// Vector and matrix libraries work in 1.15 format.
// This combination allows values of matrix elements between -2 and +2.
// Multiplication produces results scaled by 1/2.

extern boolean logging_on ;

extern boolean gyro_locking_on ;
extern boolean slide_in_progress ;
extern void udb_blink_red(void);
extern void udb_blink_green(void);

extern boolean led_red_run ;
extern boolean led_green_standby ;


#define RMAX15 24576 //0b0110000000000000   // 1.5 in 2.14 format

#define GGAINX CALIBRATIONX*SCALEGYRO*6*(RMAX*(1.0/HEARTBEAT_HZ)) // integration multiplier for gyros
#define GGAINY CALIBRATIONY*SCALEGYRO*6*(RMAX*(1.0/HEARTBEAT_HZ)) // integration multiplier for gyros
#define GGAINZ CALIBRATIONZ*SCALEGYRO*6*(RMAX*(1.0/HEARTBEAT_HZ)) // integration multiplier for gyros
fractional ggain[] =  { GGAINX, GGAINY, GGAINZ };

#if (GYRO_RANGE != 1000)
#error "only GYRO_RANGE 1000 is presently supported"
#endif // GYRO_RANGE

uint16_t spin_rate = 0;

// the gains are constant because the gravity vector is normalized
//#define KPROLLPITCH ( 2*2048 )
//#define KIROLLPITCH ( (uint32_t) 4*2560 / (uint32_t) HEARTBEAT_HZ)

#define KPROLLPITCH ( 8*2048 )
//#define KPROLLPITCH ( 2048 )
#define KIROLLPITCH ( (uint32_t) 64*2560 / (uint32_t) HEARTBEAT_HZ)

#define KPYAW ( 2*2048 )
//#define KPYAW ( 0 )
#define KIYAW ((uint32_t) 4*2560/(uint32_t)HEARTBEAT_HZ)

//#define GYROSAT 15000 // no longer used
// threshold at which gyros may be saturated

// rmat is the matrix of direction cosines relating
// the body and earth coordinate systems.
// The columns of rmat are the axis vectors of the plane,
// as measured in the earth reference frame.
// The rows of rmat are the unit vectors defining the body frame in the earth frame.
// rmat therefore describes the body frame B relative to the Earth frame E
// and in Craig's notation is represented as (B->E)R: LateX format: presupsub{E}{B}R
// To transform a point from body frame to Earth frame, multiply from the left
// with rmat.

// rmat is initialized to the identity matrix in 2.14 fractional format

#ifdef INITIALIZE_VERTICAL  // for VTOL vertical initialization
fractional rmat[] = { RMAX, 0, 0, 0, 0, RMAX, 0, -RMAX, 0 };
static fractional rmatDelayCompensated[] =  { RMAX, 0, 0, 0, 0, RMAX, 0, -RMAX, 0 };

#else // the usual case, horizontal initialization
fractional rmat[] = { RMAX, 0, 0, 0, RMAX, 0, 0, 0, RMAX };
#if (MAG_YAW_DRIFT == 1)
static fractional rmatDelayCompensated[] = { RMAX, 0, 0, 0, RMAX, 0, 0, 0, RMAX };
#endif
#endif

// rup is the rotational update matrix.
// At each time step, the new rmat is equal to the old one, multiplied by rup.
//fractional rup[] = { RMAX, 0, 0, 0, RMAX, 0, 0, 0, RMAX };

// gyro rotation vector:
fractional omegagyro[] = { 0, 0, 0 };
fractional omega[] = { 0, 0, 0 };

// gyro correction vectors:
static fractional omegacorrP[] = { 0, 0, 0 };
fractional omegacorrI[] = { 0, 0, 0 };

// acceleration, as measured in GPS earth coordinate system
fractional accelEarth[] = { 0, 0, 0 };

//union longww accelEarthFiltered[] = { { 0 }, { 0 },  { 0 } };

// correction vector integrators;
union longww gyroCorrectionIntegral[] =  { { 0 }, { 0 },  { 0 } };
union longww gyro_fraction[] =  { { 0 }, { 0 },  { 0 } };

// accumulator for computing adjusted omega:
fractional omegaAccum[] = { 0, 0, 0 };

// gravity, as measured in plane coordinate system

fractional gplane[] = { 0, 0, GRAVITY };
int16_t aero_force[] = { 0 , 0 , -GRAVITY };
union longww aero_force_filtered[3];

// horizontal velocity over ground, as measured by GPS (Vz = 0)
fractional dirOverGndHGPS[] = { 0, RMAX, 0 };

// horizontal direction over ground, as indicated by Rmatrix
fractional dirOverGndHrmat[] = { 0, RMAX, 0 };

// rotation angle equal to omega times integration factor:
//fractional theta[] = { 0, 0, 0 };

// matrix buffer:
//fractional rbuff[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// vector buffer
fractional errorRP[] = { 0, 0, 0 };
fractional errorYawground[] = { 0, 0, 0 };
fractional errorYawplane[]  = { 0, 0, 0 };

// measure of error in orthogonality, used for debugging purposes:
static fractional error = 0;

#if (MAG_YAW_DRIFT == 1)
static fractional declinationVector[2];
#endif

#if (DECLINATIONANGLE_VARIABLE == 1)
union intbb dcm_declination_angle;
#endif

void estimate_velocity(void);

void lookup_gyro_offsets(void);
void lookup_accel_offsets(void);

void yaw_drift_reset(void)
{
	errorYawground[0] = errorYawground[1] = errorYawground[2] = 0; // turn off yaw drift
}

void align_roll_pitch(fractional tilt_mat[])
{
	fractional vertical[3] ;
	fractional Z , one_plus_Z ;
	vertical[0] = gplane[0] ;
	vertical[1] = gplane[1] ;
	vertical[2] = gplane[2] ;
	vector3_normalize( vertical , vertical ) ;
	tilt_mat[2] = - vertical[0] ;
	tilt_mat[5] = - vertical[1] ;
	tilt_mat[6] = vertical[0] ;
	tilt_mat[7] = vertical[1] ;
	tilt_mat[8] = vertical[2] ;
	Z = vertical[2] ;
	one_plus_Z = RMAX + Z ;
	if ( one_plus_Z > 0 )
	{
		tilt_mat[0] = Z+__builtin_divsd( __builtin_mulss( vertical[1], vertical[1]),one_plus_Z );
		tilt_mat[4] = Z+__builtin_divsd( __builtin_mulss( vertical[0], vertical[0]),one_plus_Z );
		tilt_mat[1] = - __builtin_divsd( __builtin_mulss( vertical[0], vertical[1]),one_plus_Z );
		tilt_mat[3] = tilt_mat[1];
	}
	else
	{
        // this is an arbitrary approximation for case of perfectly inverted
        // because a pure tilt rotation vector for this situation is not unique
		tilt_mat[0] = - Z ;
		tilt_mat[4] = Z ;
		tilt_mat[1] = 0 ;
		tilt_mat[3] = 0 ;
	}
}

void dcm_init_rmat(void)
{
#if (MAG_YAW_DRIFT == 1)
#if (DECLINATIONANGLE_VARIABLE == 1)
	dcm_declination_angle.BB = DECLINATIONANGLE;
#endif
	declinationVector[0] = cosine((int8_t) (DECLINATIONANGLE >> 8));
	declinationVector[1] = sine((int8_t) (DECLINATIONANGLE >> 8));
#endif
}

union longww omegagyro_filtered_backup[]= { { 0 }, { 0 },  { 0 } } ;
union longlongLL theta_32_filtered_backup[] = { { 0 }, { 0 },  { 0 } };

union longww omegagyro_filtered[]= { { 0 }, { 0 },  { 0 } } ;
union longlongLL theta_32_filtered[] = { { 0 }, { 0 },  { 0 } };

union longww omegagyro_filtered_temporary[] = { { 0 }, { 0 },  { 0 } };
union longlongLL theta_32_filtered_temporary[] = { { 0 }, { 0 },  { 0 } };

union longlongLL long_long_accum ;

#define GYRO_FILTER_SHIFT 12

int16_t motion_detect = 1 ;
extern int16_t accelOn ;
extern int16_t gyro_offset[];
union longww gyro_offset_32[] = { { 0 }, { 0 },  { 0 } };
union longww gyro_offset_32_coning[] = { { 0 }, { 0 },  { 0 } };
union longww accum32 ;
extern int32_t omegagyro32X[] ;
extern union longww theta_32[];

uint64_t _gyro_sum_of_squares = 0 ;
uint16_t _total_samples = 0 ;
int32_t _gyro_sum[] = { 0 , 0 , 0 };
uint64_t gyro_sum_of_squares = 0 ;
uint16_t total_samples = 0 ;
int32_t gyro_sum[] = { 0 , 0 , 0 };
int32_t gyro_sum16x[] = { 0 , 0 , 0 };
uint64_t stdev_sqr = 0 ;

uint64_t _accel_sum_of_squares = 0 ;
int32_t _accel_sum[] = { 0 , 0 , 0 };
uint64_t accel_sum_of_squares = 0 ;
int32_t accel_sum[] = { 0 , 0 , 0 };
uint64_t accel_stdev_sqr = 0 ;

int32_t _roll_pitch_error_sum[] = { 0 , 0 , 0 };
int32_t roll_pitch_error_sum[] = { 0 , 0 , 0 };

uint64_t net_dev_sqr = 0 ;

extern int16_t check_for_jostle ;
uint16_t jostle_counter = 0 ;

boolean log_jostle = 0 ;
boolean signal_jostle = 0 ; 
extern int16_t rmat_16[] ;

static inline void read_gyros(void)
{
    int16_t acc_net[3] ;
    int16_t roll_pitch_error[3];
    int16_t roll_pitch_reference[3];
    // accumulate information needed to align matrix
    vector3_normalize(roll_pitch_reference,gplane);
    VectorCross(roll_pitch_error,roll_pitch_reference,&rmat_16[6]);
    _roll_pitch_error_sum[0] += (int32_t) roll_pitch_error[0];
    _roll_pitch_error_sum[1] += (int32_t) roll_pitch_error[1];
    _roll_pitch_error_sum[2] += (int32_t) roll_pitch_error[2];
       
    // accumulate partial sums over the jostle checking window to compute variance
    // partial sums include integral of gyro signals and integral of their squares
    _total_samples += 1 ;
    _gyro_sum[0] += (int32_t) omegagyro[0];
    _gyro_sum[1] += (int32_t) omegagyro[1];
    _gyro_sum[2] += (int32_t) omegagyro[2];
    
    _gyro_sum_of_squares += (uint64_t)__builtin_mulss( omegagyro[0],omegagyro[0])
            + (uint64_t)__builtin_mulss( omegagyro[1],omegagyro[1])
            + (uint64_t)__builtin_mulss( omegagyro[2],omegagyro[2]) ;
    
    acc_net[0] = udb_xaccel.value - udb_xaccel.offset ;
    acc_net[1] = udb_yaccel.value - udb_yaccel.offset ;
    acc_net[2] = udb_zaccel.value - udb_zaccel.offset ;
    
    _accel_sum[0] += (int32_t) acc_net[0] ;
    _accel_sum[1] += (int32_t) acc_net[1] ;
    _accel_sum[2] += (int32_t) acc_net[2] ;
    
    _accel_sum_of_squares += (uint64_t)__builtin_mulss( acc_net[0],acc_net[0])
            + (uint64_t)__builtin_mulss( acc_net[1],acc_net[1])
            + (uint64_t)__builtin_mulss( acc_net[2],acc_net[2]) ;
    
    
    if ((udb_heartbeat_counter % HEARTBEAT_HZ )== 0) jostle_counter ++ ;
			if ( jostle_counter == JOSTLE_CHECK_PERIOD ) 
			{
				jostle_counter = 0 ;
				check_for_jostle = 1 ;
			}
	if ( check_for_jostle == 1 )
    {
        total_samples = _total_samples ;
        
        // compute the average of the sum of the squares of the signals
        gyro_sum_of_squares = _gyro_sum_of_squares / ((uint64_t)total_samples);
        accel_sum_of_squares = _accel_sum_of_squares / ((uint64_t)total_samples);
        
        // compute the average of the gyro signals
        gyro_sum[0] = _gyro_sum[0]/((int32_t)total_samples) ;
        gyro_sum[1] = _gyro_sum[1]/((int32_t)total_samples) ;
        gyro_sum[2] = _gyro_sum[2]/((int32_t)total_samples) ;
        gyro_sum16x[0] = ((_gyro_sum[0])<<4)/((int32_t)total_samples) ;
        gyro_sum16x[1] = ((_gyro_sum[1])<<4)/((int32_t)total_samples) ;
        gyro_sum16x[2] = ((_gyro_sum[2])<<4)/((int32_t)total_samples) ;
        
        
        accel_sum[0] = _accel_sum[0] /((int32_t)total_samples) ;
        accel_sum[1] = _accel_sum[1] /((int32_t)total_samples) ;
        accel_sum[2] = _accel_sum[2] /((int32_t)total_samples) ;
        
       
        // compute the variance, which is the mean of the squares of the samples
        // minus the products of the means of the samples, using the classic equation
        
        
        stdev_sqr = (uint64_t)(_gyro_sum_of_squares * ((uint64_t)total_samples)
                - ((int64_t)_gyro_sum[0])*((int64_t)_gyro_sum[0])
                - ((int64_t)_gyro_sum[1])*((int64_t)_gyro_sum[1])
                - ((int64_t)_gyro_sum[2])*((int64_t)_gyro_sum[2]))/(((uint64_t)total_samples)*((uint64_t)total_samples)) ;

#if (ACCEL_RANGE == 2)
        accel_stdev_sqr = ((uint64_t)(_accel_sum_of_squares * ((uint64_t)total_samples)
                - ((int64_t)_accel_sum[0])*((int64_t)_accel_sum[0])
                - ((int64_t)_accel_sum[1])*((int64_t)_accel_sum[1])
                - ((int64_t)_accel_sum[2])*((int64_t)_accel_sum[2]))/(((uint64_t)total_samples)*((uint64_t)total_samples)))>>7 ;
#elif (ACCEL_RANGE == 4)
        accel_stdev_sqr = ((uint64_t)(_accel_sum_of_squares * ((uint64_t)total_samples)
                - ((int64_t)_accel_sum[0])*((int64_t)_accel_sum[0])
                - ((int64_t)_accel_sum[1])*((int64_t)_accel_sum[1])
                - ((int64_t)_accel_sum[2])*((int64_t)_accel_sum[2]))/(((uint64_t)total_samples)*((uint64_t)total_samples)))>>5 ;        
#elif (ACCEL_RANGE == 8)          
        accel_stdev_sqr = ((uint64_t)(_accel_sum_of_squares * ((uint64_t)total_samples)
                - ((int64_t)_accel_sum[0])*((int64_t)_accel_sum[0])
                - ((int64_t)_accel_sum[1])*((int64_t)_accel_sum[1])
                - ((int64_t)_accel_sum[2])*((int64_t)_accel_sum[2]))/(((uint64_t)total_samples)*((uint64_t)total_samples)))>>3 ;
#elif (ACCEL_RANGE == 16)
        accel_stdev_sqr = ((uint64_t)(_accel_sum_of_squares * ((uint64_t)total_samples)
                - ((int64_t)_accel_sum[0])*((int64_t)_accel_sum[0])
                - ((int64_t)_accel_sum[1])*((int64_t)_accel_sum[1])
                - ((int64_t)_accel_sum[2])*((int64_t)_accel_sum[2]))/(((uint64_t)total_samples)*((uint64_t)total_samples)))>>1 ;

#endif // 
        
        net_dev_sqr = stdev_sqr + accel_stdev_sqr ;
        
        if (net_dev_sqr < TOTAL_VARIANCE_MARGIN )
        {
            roll_pitch_error_sum[0] = _roll_pitch_error_sum[0]/((int32_t)total_samples) ;
            roll_pitch_error_sum[1] = _roll_pitch_error_sum[1]/((int32_t)total_samples) ;
            roll_pitch_error_sum[2] = _roll_pitch_error_sum[2]/((int32_t)total_samples) ;         
        }
        else
        {
            roll_pitch_error_sum[0] = 0 ;
            roll_pitch_error_sum[1] = 0 ;
            roll_pitch_error_sum[2] = 0 ;          
        }
        
        _total_samples = 0 ;
        
        _roll_pitch_error_sum[0] = 0 ;
        _roll_pitch_error_sum[1] = 0 ;
        _roll_pitch_error_sum[2] = 0 ;
        
        _gyro_sum[0] = 0 ;
        _gyro_sum[1] = 0 ;
        _gyro_sum[2] = 0 ;
        _gyro_sum_of_squares = 0 ;
               
        _accel_sum[0] = 0 ;
        _accel_sum[1] = 0 ;
        _accel_sum[2] = 0 ;
        _accel_sum_of_squares = 0 ;
        
        
        if ((net_dev_sqr > TOTAL_VARIANCE_MARGIN)&&(CENTRIFUGAL_TESTING == 0))
        {
            motion_detect = 1 ;
            log_jostle = 0 ;
            signal_jostle = 1 ;
        }
        else
        {   
            motion_detect = 0 ;
            signal_jostle = 0 ;           
        } 
        
        if ( motion_detect == 1 )
        {
            omegagyro_filtered[0].WW = omegagyro_filtered_temporary[0].WW = omegagyro_filtered_backup[0].WW ;
            omegagyro_filtered[1].WW = omegagyro_filtered_temporary[1].WW = omegagyro_filtered_backup[1].WW ;
            omegagyro_filtered[2].WW = omegagyro_filtered_temporary[2].WW = omegagyro_filtered_backup[2].WW ;
            theta_32_filtered[0].LL = theta_32_filtered_temporary[0].LL = theta_32_filtered_backup[0].LL ;
            theta_32_filtered[1].LL = theta_32_filtered_temporary[1].LL = theta_32_filtered_backup[1].LL ;
            theta_32_filtered[2].LL = theta_32_filtered_temporary[2].LL = theta_32_filtered_backup[2].LL ;
            
            motion_detect = 0 ;             
        }
        else
        {
            omegagyro_filtered_backup[0].WW = omegagyro_filtered[0].WW = omegagyro_filtered_temporary[0].WW ;
            omegagyro_filtered_backup[1].WW = omegagyro_filtered[1].WW = omegagyro_filtered_temporary[1].WW;
            omegagyro_filtered_backup[2].WW = omegagyro_filtered[2].WW = omegagyro_filtered_temporary[2].WW;
            theta_32_filtered_backup[0].LL = theta_32_filtered[0].LL = theta_32_filtered_temporary[0].LL ;
            theta_32_filtered_backup[1].LL = theta_32_filtered[1].LL = theta_32_filtered_temporary[1].LL ;
            theta_32_filtered_backup[2].LL = theta_32_filtered[2].LL = theta_32_filtered_temporary[2].LL;          
        }
        check_for_jostle = 0 ;
    }
	lookup_gyro_offsets();
    lookup_accel_offsets();
	gyro_offset_32[0].WW += ((int32_t)gyro_offset[0]) << 10 ;
	gyro_offset_32[1].WW += ((int32_t)gyro_offset[1]) << 10 ;
	gyro_offset_32[2].WW += ((int32_t)gyro_offset[2]) << 10 ;

	gyro_offset_32_coning[0].WW = XRATE_SIGN_ORIENTED(((int32_t)gyro_offset[0]) << 10) ;
	gyro_offset_32_coning[1].WW = YRATE_SIGN_ORIENTED(((int32_t)gyro_offset[1]) << 10) ;
	gyro_offset_32_coning[2].WW = ZRATE_SIGN_ORIENTED(((int32_t)gyro_offset[2]) << 10) ;

	udb_xrate.offset = (gyro_offset_32[0]._.W1) ;
	udb_yrate.offset = (gyro_offset_32[1]._.W1) ;
	udb_zrate.offset = (gyro_offset_32[2]._.W1) ;
	gyro_offset_32[0]._.W1 = 0 ;
	gyro_offset_32[1]._.W1 = 0 ;
	gyro_offset_32[2]._.W1 = 0 ;
    omegagyro[0] = XRATE_VALUE;
	omegagyro[1] = YRATE_VALUE;
	omegagyro[2] = ZRATE_VALUE;

    
#ifdef CONING_CORRECTION
    if(motion_detect == 0)
    {
	omegagyro_filtered_temporary[0].WW += ((int32_t)(-omegagyro32X[0])>>(GYRO_FILTER_SHIFT-11)) 
          + (( -((int32_t)(omegagyro_filtered_temporary[0].WW ))
            +((int32_t)(gyro_offset_32_coning[0].WW )))>>GYRO_FILTER_SHIFT) ;
	omegagyro_filtered_temporary[1].WW += ((int32_t)(-omegagyro32X[1])>>(GYRO_FILTER_SHIFT-11)) 
           + (( -((int32_t)(omegagyro_filtered_temporary[1].WW ))
            +((int32_t)(gyro_offset_32_coning[1].WW )))>>GYRO_FILTER_SHIFT);
	omegagyro_filtered_temporary[2].WW += ((int32_t)(-omegagyro32X[2])>>(GYRO_FILTER_SHIFT-11)) 
          + ((  -((int32_t)(omegagyro_filtered_temporary[2].WW )) 
            +((int32_t)(gyro_offset_32_coning[2].WW )))>>GYRO_FILTER_SHIFT);
    
    long_long_accum._.L0 = 0 ;
    
    long_long_accum._.L1 = theta_32[0].WW ;
    theta_32_filtered_temporary[0].LL += ((long_long_accum.LL - theta_32_filtered_temporary[0].LL)>>GYRO_FILTER_SHIFT );
    long_long_accum._.L1 = theta_32[1].WW ;
    theta_32_filtered_temporary[1].LL += ((long_long_accum.LL - theta_32_filtered_temporary[1].LL)>>GYRO_FILTER_SHIFT );
    long_long_accum._.L1 = theta_32[2].WW ;
    theta_32_filtered_temporary[2].LL += ((long_long_accum.LL - theta_32_filtered_temporary[2].LL)>>GYRO_FILTER_SHIFT );
    
    }
#else
	
	if (motion_detect == 0 )
	{
	accum32._.W1 = -omegagyro[0] ;
	accum32._.W0 = 0 ;
	omegagyro_filtered[0].WW += ((int32_t)(accum32.WW)>>GYRO_FILTER_SHIFT) -((int32_t)(omegagyro_filtered[0].WW )>>GYRO_FILTER_SHIFT) ;
	accum32._.W1 = -omegagyro[1] ;
	omegagyro_filtered[1].WW += ((int32_t)(accum32.WW)>>GYRO_FILTER_SHIFT) -((int32_t)(omegagyro_filtered[1].WW )>>GYRO_FILTER_SHIFT) ;
	accum32._.W1 = -omegagyro[2] ;
	omegagyro_filtered[2].WW += ((int32_t)(accum32.WW)>>GYRO_FILTER_SHIFT) -((int32_t)(omegagyro_filtered[2].WW )>>GYRO_FILTER_SHIFT) ;
	}
#endif // CONING_CORRECTION
}
boolean first_accel = 1 ;
int16_t aero_force_new[] = { 0 , 0 , 0 } ;
int16_t aero_force_previous[] = { 0 , 0 , 0 } ;

inline void read_accel(void)
{

	gplane[0] = __builtin_divsd(__builtin_mulss(XACCEL_VALUE,CALIB_GRAVITY),CAL_GRAV_X);
	gplane[1] = __builtin_divsd(__builtin_mulss(YACCEL_VALUE,CALIB_GRAVITY),CAL_GRAV_Y);
	gplane[2] = __builtin_divsd(__builtin_mulss(ZACCEL_VALUE,CALIB_GRAVITY),CAL_GRAV_Z);
	
	aero_force_new[0] = - gplane[0] ;
	aero_force_new[1] = - gplane[1] ;
	aero_force_new[2] = - gplane[2] ;
	
	if (first_accel == 1 )
	{
        align_roll_pitch(rmat);
		aero_force[0] = aero_force_new[0] ;
		aero_force[1] = aero_force_new[1] ;
		aero_force[2] = aero_force_new[2] ;
	
		aero_force_previous[0] = aero_force_new[0] ;
		aero_force_previous[1] = aero_force_new[1] ;
		aero_force_previous[2] = aero_force_new[2] ;
	}
	else
	{
		aero_force[0] = (aero_force_new[0] + aero_force_previous[0])/2 ;
		aero_force[1] = (aero_force_new[1] + aero_force_previous[1])/2 ;
		aero_force[2] = (aero_force_new[2] + aero_force_previous[2])/2 ;
	
		aero_force_previous[0] = aero_force_new[0] ;
		aero_force_previous[1] = aero_force_new[1] ;
		aero_force_previous[2] = aero_force_new[2] ;
	}
	
	if (first_accel == 1 )
	{
		aero_force_filtered[0]._.W1 = aero_force[0] ;
		aero_force_filtered[1]._.W1 = aero_force[1] ;
		aero_force_filtered[2]._.W1 = aero_force[2] ;
		aero_force_filtered[0]._.W0 = 0 ;
		aero_force_filtered[1]._.W0 = 0 ;
		aero_force_filtered[2]._.W0 = 0 ;
		first_accel = 0 ;
	}
	else
	{
		aero_force_filtered[0].WW += (((int32_t)aero_force[0])<<10)-((aero_force_filtered[0].WW)>>6);
		aero_force_filtered[1].WW += (((int32_t)aero_force[1])<<10)-((aero_force_filtered[1].WW)>>6);
		aero_force_filtered[2].WW += (((int32_t)aero_force[2])<<10)-((aero_force_filtered[2].WW)>>6);
	}



        // gplane is a vector that represents the gravity vector minus the acceleration vector,
        // as seen in the body frame. Taking the dot products of gplane with the rows of the
        // rotation matrix is the same thing as multiplying the rotation matrix times gplane vector,
        // which is the same thing as transforming gplane into the earth frame,
        // which gives us gravity minus acceleration in the earth frame,
        // regardless of the orientation of the aircraft.
        //
        // We want acceleration minus gravity in the earth frame, so sign flip all three components.
        // Going from UDB coordinates to Earth coordinates (east, north, up) requires us to apply
        // another sign flip to x and z. So, taking the dot products and
        // flipping only the sign of y, gives us acceleration minus gravity in the earth frame.
        //
        // The final step is to add gravity, which is equal to -GRAVITY, since gravity (which is down)
        // is in the opposite direction to the earth up direction. so, the final step is to add -GRAVITY.
        //
        // See the following URL for further details of the frame reference conventions for UDB / MatrixPilot
        // https://code.google.com/p/gentlenav/wiki/UDBCoordinateSystems
	accelEarth[0] = +(VectorDotProduct(3, &rmat[0], gplane) << 1);
	accelEarth[1] = -(VectorDotProduct(3, &rmat[3], gplane) << 1);
	accelEarth[2] = +(-((int16_t)GRAVITY) + (VectorDotProduct(3, &rmat[6], gplane) << 1));

//	accelEarthFiltered[0].WW += ((((int32_t)accelEarth[0])<<16) - accelEarthFiltered[0].WW)>>5;
//	accelEarthFiltered[1].WW += ((((int32_t)accelEarth[1])<<16) - accelEarthFiltered[1].WW)>>5;
//	accelEarthFiltered[2].WW += ((((int32_t)accelEarth[2])<<16) - accelEarthFiltered[2].WW)>>5;
}

void udb_callback_read_sensors(void)
{
	read_gyros(); // record the average values for both DCM and for offset measurements
	read_accel();
}

fractional theta[3];
extern int16_t theta_16[];
fractional rup_copy[9];
// The update algorithm!!
static void rupdate(void)
{
	// This is the key routine. It performs a small rotation
	// on the direction cosine matrix, based on the gyro vector and correction.
	// It uses vector and matrix routines furnished by Microchip.
	fractional delta_angle[9];
	fractional delta_angle_square_over_2[9];
	fractional delta_angle_cube_over_6[9];
	fractional rup[9];

	fractional rbuff[9];
		
//	VectorAdd(3, omegaAccum, omegagyro, omegacorrI);
	
	gyro_fraction[0]._.W1 = omegagyro[0] ;
	gyro_fraction[1]._.W1 = omegagyro[1] ;
	gyro_fraction[2]._.W1 = omegagyro[2] ;
	
	// gyro_fraction._.W0 intentionally not zeroed out
		
	if ((accelOn == 1 ) ||(CONTINUOUS_MATRIX_LOCKING==1))
	{
		gyro_fraction[0].WW = gyro_fraction[0].WW + gyroCorrectionIntegral[0].WW ;
		gyro_fraction[1].WW = gyro_fraction[1].WW + gyroCorrectionIntegral[1].WW ;
		gyro_fraction[2].WW = gyro_fraction[2].WW + gyroCorrectionIntegral[2].WW ;
	}
	else
	{
		gyro_fraction[0].WW = gyro_fraction[0].WW + omegagyro_filtered[0].WW ;	
		gyro_fraction[1].WW = gyro_fraction[1].WW + omegagyro_filtered[1].WW ;
		gyro_fraction[2].WW = gyro_fraction[2].WW + omegagyro_filtered[2].WW ;
	}
	
	omegaAccum[0] = gyro_fraction[0]._.W1 ;
	omegaAccum[1] = gyro_fraction[1]._.W1 ;
	omegaAccum[2] = gyro_fraction[2]._.W1 ;
	
	gyro_fraction[0]._.W1 = 0 ;
	gyro_fraction[1]._.W1 = 0 ;
	gyro_fraction[2]._.W1 = 0 ;
	
	VectorAdd(3, omega, omegaAccum, omegacorrP);
	//	scale by the integration factors:
	VectorMultiply(3, theta, omega, ggain); // Scalegain of 2
	// diagonal elements of the update matrix:
	rup[0] = RMAX;
	rup[4] = RMAX;
	rup[8] = RMAX;
	rup[1] = 0 ;
	rup[2] = 0 ;
	rup[3] = 0 ;
	rup[5] = 0 ;
	rup[6] = 0 ;
	rup[7] = 0 ;

#ifdef CONING_CORRECTION_IN_RMAT

	if ((accelOn == 1 ) ||(CONTINUOUS_MATRIX_LOCKING==1))
	{
		// construct the delta angle matrix without coning correction
		// because it includes residual offset compensation
		// and coning correction is not needed during standby mode
		delta_angle[0] = 0 ;
		delta_angle[1] = -theta[2];
		delta_angle[2] =  theta[1];
		delta_angle[3] =  theta[2];
		delta_angle[4] = 0 ;
		delta_angle[5] = -theta[0];
		delta_angle[6] = -theta[1];
		delta_angle[7] =  theta[0];
		delta_angle[8] = 0 ;
	}
	else
	{
		// construct the delta angle matrix with coning correction:
		delta_angle[0] = 0 ;
		delta_angle[1] = -theta_16[2];
		delta_angle[2] =  theta_16[1];
		delta_angle[3] =  theta_16[2];
		delta_angle[4] = 0 ;
		delta_angle[5] = -theta_16[0];
		delta_angle[6] = -theta_16[1];
		delta_angle[7] =  theta_16[0];
		delta_angle[8] = 0 ;
	}
#else
	
	// construct the delta angle matrix:
	delta_angle[0] = 0 ;
	delta_angle[1] = -theta[2];
	delta_angle[2] =  theta[1];
	delta_angle[3] =  theta[2];
	delta_angle[4] = 0 ;
	delta_angle[5] = -theta[0];
	delta_angle[6] = -theta[1];
	delta_angle[7] =  theta[0];
	delta_angle[8] = 0 ;
#endif // CONING_CORRECTION_IN_RMAT
	
	// compute 1/2 of square of the delta angle matrix
	// since a matrix multiply divides by 2, we get it for free	
	MatrixMultiply( 3, 3, 3, delta_angle_square_over_2 , delta_angle , delta_angle );
	
	// first step in computing delta angle cube over 6, compute it over 4 ;
	MatrixMultiply( 3, 3, 3, delta_angle_cube_over_6 , delta_angle_square_over_2 , delta_angle );
	
	// multiply by 2/3
	int16_t loop_index ;
	for ( loop_index = 0 ; loop_index <= 8 ; ++ loop_index ) 
	{
		delta_angle_cube_over_6[loop_index] = __builtin_divsd(__builtin_mulsu(delta_angle_cube_over_6[loop_index],2 ),3);
	}
	
	// form the update matrix
	MatrixAdd(3, 3, rup, rup, delta_angle );
	MatrixAdd(3, 3, rup, rup, delta_angle_square_over_2 );
	MatrixAdd(3, 3, rup, rup, delta_angle_cube_over_6 );

	// for debugging
	VectorCopy(9,rup_copy,rup);
	// matrix multiply the rmatrix by the update matrix
	MatrixMultiply(3, 3, 3, rbuff, rmat, rup);
	// multiply by 2 and copy back from rbuff to rmat:
	MatrixAdd(3, 3, rmat, rbuff, rbuff);
}

// The normalization algorithm
static void normalize(void)
{
	//  This is the routine that maintains the orthogonality of the
	//  direction cosine matrix, which is expressed by the identity
	//  relationship that the cosine matrix multiplied by its
	//  transpose should equal the identity matrix.
	//  Small adjustments are made at each time step to assure orthogonality.

	fractional norm;    // actual magnitude
	fractional renorm;  // renormalization factor
	fractional rbuff[9];

	// take the tilt row without any adjustments
	VectorCopy( 3 , &rbuff[6] , &rmat[6] ) ;
	// compute the negative of the dot product between rows 2 and 3
	error =  - 2*VectorDotProduct(3, &rmat[3], &rmat[6]);
	// compute adjustment to row 2 that will make it more perpendicular to row 3
	VectorScale( 3 , &rbuff[3] , &rbuff[6] , error ) ;
	VectorAdd( 3, &rbuff[3] , &rbuff[3] , &rmat[3] ) ;
	// use the cross product of row 2 and 3 to get the first row
	VectorCross(&rbuff[0] , &rbuff[3] , &rbuff[6] ) ;

	// Use a Taylor's expansion for 1/sqrt(X*X) to avoid division in the renormalization

	// rescale row1
	norm = VectorPower(3, &rbuff[0]); // Scalegain of 0.5
	renorm = RMAX15 - norm;
	VectorScale(3, &rbuff[0], &rbuff[0], renorm);
	VectorAdd(3, &rmat[0], &rbuff[0], &rbuff[0]);
	// rescale row2
	norm = VectorPower(3, &rbuff[3]);
	renorm = RMAX15 - norm;
	VectorScale(3, &rbuff[3], &rbuff[3], renorm);
	VectorAdd(3, &rmat[3], &rbuff[3], &rbuff[3]);
	// rescale row3
	norm = VectorPower(3, &rbuff[6]);
	renorm = RMAX15 - norm;
	VectorScale(3, &rbuff[6], &rbuff[6], renorm);
	VectorAdd(3, &rmat[6], &rbuff[6], &rbuff[6]);
}

int16_t accelOn ;
int16_t launched ;
extern int16_t accelEarthVertical ;
extern int32_t velocityEarthVertical ;
int16_t launch_count ;

int16_t omega_dot_rmat6 ;
int16_t omega_scaled[3] ;
int16_t omega_yaw_drift[3] ;
uint16_t omega_magnitude ;

uint16_t accel_magnitude ;
boolean matrix_jostle = 0 ;

boolean log_matrix_jostle = 1 ;

static void roll_pitch_drift(void)
{	
	accel_magnitude = vector3_mag(gplane[0],gplane[1],gplane[2]);
	omega_magnitude = vector3_mag(omegagyro[0]+omegagyro_filtered[0]._.W1,
        omegagyro[1]+omegagyro_filtered[1]._.W1,
        omegagyro[2]+omegagyro_filtered[2]._.W1); 
#ifdef BUILD_OFFSET_TABLE // the following interferes with LED signals during table build
    return ;
#endif // BUILD_OFFSET_TABLE
	if(net_dev_sqr>TOTAL_VARIANCE_MARGIN)
	{
        matrix_jostle = 1 ;
        log_matrix_jostle = 0 ;
    }
    
    if ((( logging_on == 0)||(CONTINUOUS_MATRIX_LOCKING==1))&&(matrix_jostle == 0 ))
    {
		int16_t gplane_nomalized[3] ;
		vector3_normalize( gplane_nomalized , gplane ) ;
		VectorCross(errorRP, gplane_nomalized, &rmat[6]);
        
        dirOverGndHrmat[0] = rmat[0] ;
		dirOverGndHrmat[1] = rmat[3] ;
		dirOverGndHrmat[2] = 0 ;
		dirOverGndHGPS[0] = RMAX ;
		dirOverGndHGPS[1] = 0 ;
		dirOverGndHGPS[2] = 0 ;
        
        if ( logging_on == 0)
        {
        
            VectorCross(errorYawground, dirOverGndHrmat , dirOverGndHGPS );
        
            // convert to "plane" frame:
            // *** Note: this accomplishes multiplication rmat transpose times errorYawground!!
            MatrixMultiply(1, 3, 3, errorYawplane, errorYawground, rmat) ;
        }
        else
        {
            errorYawplane[0]= 0 ;
            errorYawplane[1]= 0 ;
            errorYawplane[2]= 0 ;
            
        }

	}
	else
	{
		errorRP[0] = 0 ;
		errorRP[1] = 0 ;
		errorRP[2] = 0 ;
		errorYawplane[0] = 0 ;
		errorYawplane[1] = 0 ;
		errorYawplane[2] = 0 ;
	}

	if((gyro_locking_on == 1)&&(motion_detect == 0))
	{
		accelOn = 1 ;
	}
	else
	{
		accelOn = 0 ;
	}

}

#define MAXIMUM_SPIN_DCM_INTEGRAL 20.0 // degrees per second

static void PI_feedback(void)
{
	fractional errorRPScaled[3];
	int16_t kpyaw;
	int16_t kprollpitch;

	{
		kpyaw = KPYAW;
		kprollpitch = KPROLLPITCH;
	}
	
	VectorScale(3, omegacorrP, errorYawplane, kpyaw);   // Scale gain = 2
	VectorScale(3, errorRPScaled, errorRP, kprollpitch);// Scale gain = 2
	VectorAdd(3, omegacorrP, omegacorrP, errorRPScaled);

	{	
		gyroCorrectionIntegral[0].WW += (__builtin_mulsu(errorRP[0], KIROLLPITCH)>>6);
		gyroCorrectionIntegral[1].WW += (__builtin_mulsu(errorRP[1], KIROLLPITCH)>>6);
		gyroCorrectionIntegral[2].WW += (__builtin_mulsu(errorRP[2], KIROLLPITCH)>>6);

		gyroCorrectionIntegral[0].WW += (__builtin_mulsu(errorYawplane[0], KIYAW)>>6);
		gyroCorrectionIntegral[1].WW += (__builtin_mulsu(errorYawplane[1], KIYAW)>>6);
		gyroCorrectionIntegral[2].WW += (__builtin_mulsu(errorYawplane[2], KIYAW)>>6);
	}

	omegacorrI[0] = gyroCorrectionIntegral[0]._.W1;
	omegacorrI[1] = gyroCorrectionIntegral[1]._.W1;
	omegacorrI[2] = gyroCorrectionIntegral[2]._.W1;
}

void dcm_run_imu_step(void)
{
    roll_pitch_drift();         // local
	rupdate();                  // local
#ifdef CONING_CORRECTION
	rmat_32_update();
#endif // CONING_CORRECTION
	normalize();                // local

	PI_feedback();              // local
#ifdef LOG_VELOCITY
	estimate_velocity();
#endif // LOG_VELOCITY
}
float roll_angle , pitch_angle , yaw_angle ;
float roll_angle_8k , pitch_angle_8k , yaw_angle_8k ;
float bill_angle_x , bill_angle_y , bill_angle_z ;
float rmat_f[9];
float rmat_f_8k[9];
extern int16_t rmat_16[];
#define DEG_PER_RAD 57.296
void compute_euler_8k(void)
{
	rmat_f_8k[0]=(float)rmat_16[0] ;
	//rmat_f_8k[1]=(float)rmat_16[1] ;
	//rmat_f_8k[2]=(float)rmat_16[2] ;
	rmat_f_8k[3]=(float)rmat_16[3] ;
	//rmat_f_8k[4]=(float)rmat_16[4] ;
	//rmat_f_8k[5]=(float)rmat_16[5] ;
	rmat_f_8k[6]=(float)rmat_16[6] ;
	rmat_f_8k[7]=(float)rmat_16[7] ;
	rmat_f_8k[8]=(float)rmat_16[8] ;

	pitch_angle_8k = DEG_PER_RAD*atan2f(-rmat_f_8k[6],sqrtf(rmat_f_8k[7]*rmat_f_8k[7]+rmat_f_8k[8]*rmat_f_8k[8]));
	roll_angle_8k = DEG_PER_RAD*atan2f(rmat_f_8k[7],rmat_f_8k[8]);
	yaw_angle_8k = DEG_PER_RAD*atan2f(rmat_f_8k[3],rmat_f_8k[0]);
}

void compute_euler(void)
{
	rmat_f[0]=(float)rmat[0] ;
//	rmat_f[1]=(float)rmat[1] ;
//	rmat_f[2]=(float)rmat[2] ;
	rmat_f[3]=(float)rmat[3] ;
//	rmat_f[4]=(float)rmat[4] ;
//	rmat_f[5]=(float)rmat[5] ;
	rmat_f[6]=(float)rmat[6] ;
	rmat_f[7]=(float)rmat[7] ;
	rmat_f[8]=(float)rmat[8] ;

	pitch_angle = DEG_PER_RAD*atan2f(-rmat_f[6],sqrtf(rmat_f[7]*rmat_f[7]+rmat_f[8]*rmat_f[8]));
	roll_angle = DEG_PER_RAD*atan2f(rmat_f[7],rmat_f[8]);
	yaw_angle = DEG_PER_RAD*atan2f(rmat_f[3],rmat_f[0]);
}

void compute_bill_angles(void)
{
	rmat_f[0]=(float)rmat[0] ;
	rmat_f[1]=(float)rmat[1] ;
	rmat_f[2]=(float)rmat[2] ;
//	rmat_f[3]=(float)rmat[3] ;
//	rmat_f[4]=(float)rmat[4] ;
//	rmat_f[5]=(float)rmat[5] ;
//	rmat_f[6]=(float)rmat[6] ;
//	rmat_f[7]=(float)rmat[7] ;
//	rmat_f[8]=(float)rmat[8] ;

	bill_angle_x = DEG_PER_RAD*atan2f(rmat_f[2],rmat_f[1]);
	bill_angle_y = DEG_PER_RAD*atan2f(rmat_f[0],rmat_f[2]);
	bill_angle_z = DEG_PER_RAD*atan2f(rmat_f[1],rmat_f[0]);
}

int16_t gravity_estimate[3];
union longww gravity_long[3];
int16_t acceleration[3];
float gravity_float[3] ;
float aero_force_float[3] ;
float acceleration_float[3];
float omegaAccum_float[3] ;
float velocity ;

#define MINIMUM_OMEGA_SQUARE 0.0625 // 14 degrees/second

void estimate_velocity(void)
{
	float omega_square ;
	
	omegaAccum_float[0] = (((float)omegaAccum[0])*((float)GYRO_RANGE))/(57.296*((float)16384)) ;
	omegaAccum_float[1] = (((float)omegaAccum[1])*((float)GYRO_RANGE))/(57.296*((float)16384)) ;
	omegaAccum_float[2] = (((float)omegaAccum[2])*((float)GYRO_RANGE))/(57.296*((float)16384)) ;
			
	gravity_long[0].WW= 2*__builtin_mulss(rmat[6],CALIB_GRAVITY);
	gravity_long[1].WW= 2*__builtin_mulss(rmat[7],CALIB_GRAVITY);
	gravity_long[2].WW= 2*__builtin_mulss(rmat[8],CALIB_GRAVITY);
	
	gravity_estimate[0] = gravity_long[0]._.W1 ;
	gravity_estimate[1] = gravity_long[1]._.W1 ;
	gravity_estimate[2] = gravity_long[2]._.W1 ;
	
	//note: CALIB_GRAVITY has a factor of 2 built
	
	gravity_float[0] = ((float)gravity_estimate[0])*(((float)19.6)/((float)CALIB_GRAVITY));
	gravity_float[1] = ((float)gravity_estimate[1])*(((float)19.6)/((float)CALIB_GRAVITY));
	gravity_float[2] = ((float)gravity_estimate[2])*(((float)19.6)/((float)CALIB_GRAVITY));
	
	aero_force_float[0] = ((float)aero_force[0])*(((float)19.6)/((float)CALIB_GRAVITY));
	aero_force_float[1] = ((float)aero_force[1])*(((float)19.6)/((float)CALIB_GRAVITY));
	aero_force_float[2] = ((float)aero_force[2])*(((float)19.6)/((float)CALIB_GRAVITY));
	
	acceleration_float[0] = gravity_float[0] + aero_force_float[0] ;
	acceleration_float[1] = gravity_float[1] + aero_force_float[1] ;
	acceleration_float[2] = gravity_float[2] + aero_force_float[2] ;
	
	omega_square = omegaAccum_float[1]*omegaAccum_float[1] + omegaAccum_float[2]*omegaAccum_float[2] ;
	if (omega_square>MINIMUM_OMEGA_SQUARE )
	{
		velocity = fabsf((omegaAccum_float[2]*acceleration_float[1]-omegaAccum_float[1]*acceleration_float[2])/omega_square);
	}
	else
	{
		velocity = 0 ;
	}
	
}

