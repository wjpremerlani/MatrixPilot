// This file is part of the MatrixPilotQuad firmware.
//
//    http://code.google.com/p/gentlenav/
//
// Copyright 2009-2011 MatrixPilot Team
// See the AUTHORS.TXT file for a list of authors of MatrixPilot.
//
// MatrixPilot is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MatrixPilot is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with MatrixPilot.  If not, see <http://www.gnu.org/licenses/>.

#include "../libDCM/libDCM.h"
#include "../libDCM/gpsData.h"
#include "../libDCM/gpsParseCommon.h"
#include "../libDCM/rmat.h"
#include "../libDCM/mathlibNAV.h"
#include "../libUDB/heartbeat.h"
#include "../libUDB/serialIO.h"
#include "../libUDB/servoOut.h"
#include "../libUDB/ADchannel.h"
#include "../libUDB/mcu.h"
#include "../libUDB/libUDB.h"
#include "../libDCM/matrix_vector_32_bit.h"
#include "../libDCM/rmat_32.h"
#include "../libUDB/oscillator.h"
#include "serial_output.h"

// Used for serial debug output
#include <stdio.h>
#if ( GYRO_RANGE == 250 )
#define GYRO_FACTOR ((double)(65.5))
#elif ( GYRO_RANGE == 500 )
#define GYRO_FACTOR ((double)(32.75))
#elif ( GYRO_RANGE == 1000 )
#define GYRO_FACTOR ((double)(16.375))
#elif ( GYRO_RANGE == 2000 )
#define GYRO_FACTOR ((double)(8.1875))
#else
#error "invalid GYRO_RANGE"
#endif // GYRO_RANGE 	
		
#if ( ACCEL_RANGE == 2 )
#define ACCEL_FACTOR ((double)(8192.0/32.17))
#elif ( ACCEL_RANGE == 4 )
#define ACCEL_FACTOR ((double)(4096.0/32.17))
#elif ( ACCEL_RANGE == 8 )
#define ACCEL_FACTOR ((double)(2048.0/32.17))
#elif ( ACCEL_RANGE == 16 )
#define ACCEL_FACTOR ((double)(1024.0/32.17))
#else
#error "invalid ACCEL_RANGE"
#endif // ACCEL_RANGE 	

int16_t rms_filt_16 = 0 ;


char debug_buffer[1024] ;
int db_index = 0 ;
boolean hasWrittenHeader = 0 ;
int header_line = 0 ;

extern int16_t theta[3] , roll_control , pitch_control , yaw_control , accelEarth[3] , accel_feedback ;
extern int16_t commanded_roll, commanded_pitch, commanded_yaw, pwManual[] ;
extern int16_t roll_error , pitch_error , yaw_error ;
extern union longww roll_error_integral, pitch_error_integral , yaw_error_integral ;
extern int16_t target_rmat[9] ;
extern int16_t altitude , altitude_control , climb_rate ;
extern int16_t number_pulses ;
extern int16_t IMU_climb , IMU_altitude ;
extern int16_t target_rate[3] ;
extern union longww IMUlocationx , IMUlocationy , IMUvelocityx , IMUvelocityy ;
extern int16_t x_velocity_feedback , y_velocity_feedback ;
extern int16_t x_velocity_target , y_velocity_target ;
extern int16_t udb_magFieldBody[3] ;
extern fractional magFieldEarth[3];
extern fractional magAlignment[4];
extern int16_t udb_magOffset[3] , errorYawplane[3] , magGain[3] ;
extern uint16_t mission_time ;
extern void compute_euler(void);
extern void compute_euler_8k(void);
extern void compute_bill_angles(void);
extern void update_offset_table(void);
extern float roll_angle , pitch_angle , yaw_angle ;
extern float roll_angle_8k , pitch_angle_8k , yaw_angle_8k ;
extern float bill_angle_x , bill_angle_y , bill_angle_z ;
extern int16_t omegacorrI[];
extern uint16_t omega_magnitude ;
extern uint16_t accel_magnitude ;
extern union longww omegagyro_filtered[];
extern struct ADchannel mpu_temp;
extern uint16_t samples ;
extern uint64_t samples_64t ;
extern uint32_t samples_32t ;
extern int16_t adjusted_temperature ;
extern int16_t gyro_offset_entry[] ;
extern uint64_t xx_sum ;
extern int64_t xy_sum[] ;
extern int32_t x_sum ;
extern int32_t y_sum[] ;
extern uint32_t xx_bar ;
extern int32_t xy_bar[] ;
extern int16_t x_bar ;
extern int16_t y_bar[] ;
extern int16_t gyro_offset[];
extern uint16_t max_gyro ;
extern int32_t yaw_rate ;

extern int16_t gplane[];
extern int16_t aero_force[];
// Prepare a line of serial output and start it sending
// GPS data needs to be passed in
extern int16_t yaw_rmat[];
extern int16_t target_altitude , target_climb_rate ;
extern union longww throttle_accum ;
extern void initialize_yaw_rmat(void) ;
uint16_t record_number = 0 ;
#define DIGITS_5 -12805
extern float tilt_angle ;
extern boolean start_log , stop_log ;
boolean logging_on = 0 ;
extern int16_t omega_dot_rmat6 ;
extern int16_t omega_scaled[];
extern int16_t omega_yaw_drift[];
extern int16_t gravity_estimate[];
extern int16_t acceleration[];
boolean gyro_locking_on = 1;
extern int16_t accelOn ;
extern int16_t errorYawplane[];
extern int16_t errorRP[];
extern union longww gyroCorrectionIntegral[];
extern float aero_force_float[];
extern float gravity_float[];
extern float acceleration_float[];
extern float omegaAccum_float[];
extern float velocity ;
extern uint16_t index_msb , index_lsb ;
float yaw_previous ;
float heading ;
float heading_previous ;
float delta_yaw ;
float yaw_previous_8k ;
float heading_8k ;
float heading_previous_8k ;
float delta_yaw_8k ;
boolean is_first_header = 1;
boolean log_residuals = 1 ;
extern boolean start_residuals ;
extern int16_t omega[];
extern int16_t rup_copy[];
extern union longww coning_angle_adjustment[];
extern union longww omega32[];
extern union longww theta_32[];
extern union longww ggain_32[];
extern int16_t theta_16[];

extern union longww rmat_32[];
extern int32_t renorm_32_row_3 	;	
extern union longlongLL theta_32_filtered[];
extern union longww theta_32_adjusted[];
extern union longww theta_sum[];
extern union longww r_update_sum[];
extern union longww rmat_sum[];
extern int16_t residual_offset[];
extern int16_t misalignment[];

extern int16_t is_level ;

extern void update_offset_table_gyros_and_accelerometers(void);

int16_t omega_filt_16_previous[] = {0,0,0};

extern int64_t gyro_sum_of_squares ;
extern int16_t total_samples ;
extern int32_t gyro_sum[];
extern uint64_t stdev_sqr ;

void send_euler_angles(void)
{
    int16_t omega_filt_16[3];
    omega_filt_16[0]=(int16_t)((omegagyro_filtered[0].WW)>>12);
    omega_filt_16[1]=(int16_t)((omegagyro_filtered[1].WW)>>12);
    omega_filt_16[2]=(int16_t)((omegagyro_filtered[2].WW)>>12); 

    compute_euler_8k();
    serial_output("(W10),(L%i),(Y%.1f),(P%.1f),(R%.1f)\r\n", 
            vector3_mag(
            omega_filt_16[0]-omega_filt_16_previous[0],
            omega_filt_16[1]-omega_filt_16_previous[1],
            omega_filt_16[2]-omega_filt_16_previous[2]),
            yaw_angle_8k , pitch_angle_8k , roll_angle_8k);
    omega_filt_16_previous[0]=omega_filt_16[0];
    omega_filt_16_previous[1]=omega_filt_16[1];
    omega_filt_16_previous[2]=omega_filt_16[2];  
    
}

 
void send_rms_and_lpf(void)
{
    int16_t omega_filt_16[3];
    omega_filt_16[0]=(int16_t)((omegagyro_filtered[0].WW)>>12);
    omega_filt_16[1]=(int16_t)((omegagyro_filtered[1].WW)>>12);
    omega_filt_16[2]=(int16_t)((omegagyro_filtered[2].WW)>>12); 
    rms_filt_16 += (((((int16_t)vector3_mag(omegagyro[0],omegagyro[1],omegagyro[2]))<<4)-rms_filt_16)>>4);
    serial_output("(w10),(r%i),(x%i),(y%i),(z%i)\r\n",
                rms_filt_16>>4,
				omega_filt_16[0] , // 16x
				omega_filt_16[1] ,
                omega_filt_16[2] ); 
}

uint16_t warmup_count = 0 ;
uint16_t run_count = 0 ;
int16_t check_for_jostle = 0 ;
#if ( EULER_GUI == 1)
void send_residual_data(void)
{
    // no need to do anything, it is always in "run" mode
/*    int16_t omega_filt_16[3];
    omega_filt_16[0]=(int16_t)((omegagyro_filtered[0].WW)>>12);
    omega_filt_16[1]=(int16_t)((omegagyro_filtered[1].WW)>>12);
    omega_filt_16[2]=(int16_t)((omegagyro_filtered[2].WW)>>12); 

    compute_euler_8k();
    serial_output("(W10),(L%i),(Y%.1f),(P%.1f),(R%.1f)\r\n", 
            vector3_mag(
            omega_filt_16[0]-omega_filt_16_previous[0],
            omega_filt_16[1]-omega_filt_16_previous[1],
            omega_filt_16[2]-omega_filt_16_previous[2]),
            yaw_angle_8k , pitch_angle_8k , roll_angle_8k);
    omega_filt_16_previous[0]=omega_filt_16[0];
    omega_filt_16_previous[1]=omega_filt_16[1];
    omega_filt_16_previous[2]=omega_filt_16[2]; 
 */ 
   
}
#else
extern int32_t gyro_sum16x[];
extern boolean log_jostle ;
extern boolean log_matrix_jostle ;
void send_residual_data(void)
{
	if ( start_residuals == 1)
	{
		start_residuals = 0 ;
#ifndef LOG_R_UPDATE
#ifndef TILT_INIT
		serial_output("\r\n\r\nimu_temp_yy,filtring_yy,aligning_yy,x_force_yy,y_force_yy,z_force_yy,x_rate16_yy,y_rate16_yy,z_rate16_yy,rms_rate16_yy,x_flt16_yy,y_flt16_yy,z_flt16_yy,stdev_yy\r\n") ;
#else
        serial_output("\r\n\r\nStandbymode\r\naccOn,logOn,nx_force,y_force,z_force,yaw8,pitch8,roll8,yaw,pitch,roll\r\n");        
#endif // TILT_INIT
#else
        serial_output("\r\n\r\nimu_temp,filter_en,ax,ay,az,x_filt_64,y,z,theta_filtx,y,z\r\n");
#endif // LOG_R_UPDATE
	}
	else
	{
#ifdef SIMULATE_TILT
        if (warmup_count++ >= WARM_UP_TIME)
        {
            warmup_count = 0 ;
            is_level = 1 ;
        }
#endif // SIMULATE_TILT
        union longww omgfilt_rounded[3];
        omgfilt_rounded[0].WW = omegagyro_filtered[0].WW+0x00008000 ;
        omgfilt_rounded[1].WW = omegagyro_filtered[1].WW+0x00008000 ;
        omgfilt_rounded[2].WW = omegagyro_filtered[2].WW+0x00008000 ;

#ifndef  LOG_R_UPDATE 
#ifndef TILT_INIT
        //int16_t omega_filt_16[3];
        //omega_filt_16[0]=(int16_t)((omegagyro_filtered[0].WW)>>12);
        //omega_filt_16[1]=(int16_t)((omegagyro_filtered[1].WW)>>12);
        //omega_filt_16[2]=(int16_t)((omegagyro_filtered[2].WW)>>12); 
        if((TURTLE_TESTING==0)||((log_jostle==1)&&(log_matrix_jostle==1)))
        {
        serial_output("%i,%i,%i,%.1f,%.1f,%.1f,%li,%li,%li,%i,%li,%li,%li,%i\r\n",  
                mpu_temp.value,
				log_jostle ,
                log_matrix_jostle ,
                ((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
    			gyro_sum16x[0],
                gyro_sum16x[1],
                gyro_sum16x[2],
                vector3_mag(((int16_t)gyro_sum16x[0]),((int16_t)gyro_sum16x[1]),((int16_t)gyro_sum16x[2])),
				(omegagyro_filtered[0].WW)>>12 , // 16x
				(omegagyro_filtered[1].WW)>>12 ,
                (omegagyro_filtered[2].WW)>>12 ,
//              total_samples ,
//              gyro_sum_of_squares ,
//              gyro_sum[0],
//              gyro_sum[1],
//              gyro_sum[2],
                sqrt_long((uint32_t)stdev_sqr)
                
    				);
        }
        log_jostle = 1 ;
        log_matrix_jostle = 1 ;
#else
        compute_euler();
        compute_euler_8k();
                serial_output("%u,%u,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\r\n",
                        accelOn , logging_on ,
            	((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
                yaw_angle_8k ,  pitch_angle_8k , roll_angle_8k ,     
				yaw_angle ,  pitch_angle , roll_angle                  
			);       
#endif // TILT_DEF
#else
        serial_output("%i,%i,%i,%i,%i,%i,%i,%i,%li,%li,%li\r\n",
				mpu_temp.value,
				accelOn ,
                aero_force[0],
                aero_force[1],
                aero_force[2],
                (int16_t)((omegagyro_filtered[0].WW)>>10) , // 64x
				(int16_t)((omegagyro_filtered[1].WW)>>10) ,
				(int16_t)((omegagyro_filtered[2].WW)>>10) ,
                theta_32_filtered[0]._.L1 , theta_32_filtered[1]._.L1 ,theta_32_filtered[2]._.L1 
					);

#endif // LOG_R_UPDATE
	}
}
#endif // EULER_GUI
#ifdef TEST_SLED

extern uint8_t accel_read_buffer_index ;
extern uint8_t accel_write_buffer_index ;
extern int16_t x_accel[] ;
extern int16_t y_accel[] ;
extern int16_t z_accel[] ;
extern union longww x_theta_32[] ;
extern union longww y_theta_32[] ;
extern union longww z_theta_32[] ;

union longww bottom_row[3] ;
union longww coning_vector[3];
union longww interpolation_vector1[3];
union longww interpolation_vector2[3];
union longww interpolation_vector3[3];
union longww interpolation_vector4[3];
union longww interpolated_tilt1[3];
union longww interpolated_tilt2[3];
union longww interpolated_tilt3[3];
union longww interpolated_tilt4[3];



void log_x_accel_data(void)
{
    bottom_row[0].WW = rmat_32[6].WW ;
    bottom_row[1].WW = rmat_32[7].WW ;
    bottom_row[2].WW = rmat_32[8].WW ;
    
    coning_vector[0].WW = x_theta_32[5*accel_read_buffer_index+1].WW ;
    coning_vector[1].WW = y_theta_32[5*accel_read_buffer_index+1].WW ;
    coning_vector[2].WW = z_theta_32[5*accel_read_buffer_index+1].WW ;
    VectorCross_32(interpolation_vector1,bottom_row,coning_vector ) ;
    interpolated_tilt1[0].WW = interpolation_vector1[0].WW + bottom_row[0].WW ;
    interpolated_tilt1[1].WW = interpolation_vector1[1].WW + bottom_row[1].WW ;
    interpolated_tilt1[2].WW = interpolation_vector1[2].WW + bottom_row[2].WW ;
 
    coning_vector[0].WW = x_theta_32[5*accel_read_buffer_index+2].WW ;
    coning_vector[1].WW = y_theta_32[5*accel_read_buffer_index+2].WW ;
    coning_vector[2].WW = z_theta_32[5*accel_read_buffer_index+2].WW ;
    VectorCross_32(interpolation_vector2,bottom_row,coning_vector ) ;
    interpolated_tilt2[0].WW = interpolation_vector2[0].WW + bottom_row[0].WW ;
    interpolated_tilt2[1].WW = interpolation_vector2[1].WW + bottom_row[1].WW ;
    interpolated_tilt2[2].WW = interpolation_vector2[2].WW + bottom_row[2].WW ;
 
 
    coning_vector[0].WW = x_theta_32[5*accel_read_buffer_index+3].WW ;
    coning_vector[1].WW = y_theta_32[5*accel_read_buffer_index+3].WW ;
    coning_vector[2].WW = z_theta_32[5*accel_read_buffer_index+3].WW ;
    VectorCross_32(interpolation_vector3,bottom_row,coning_vector ) ;
    interpolated_tilt3[0].WW = interpolation_vector3[0].WW + bottom_row[0].WW ;
    interpolated_tilt3[1].WW = interpolation_vector3[1].WW + bottom_row[1].WW ;
    interpolated_tilt3[2].WW = interpolation_vector3[2].WW + bottom_row[2].WW ;
 
    coning_vector[0].WW = x_theta_32[5*accel_read_buffer_index+4].WW ;
    coning_vector[1].WW = y_theta_32[5*accel_read_buffer_index+4].WW ;
    coning_vector[2].WW = z_theta_32[5*accel_read_buffer_index+4].WW ;
    VectorCross_32(interpolation_vector4,bottom_row,coning_vector ) ;
    interpolated_tilt4[0].WW = interpolation_vector4[0].WW + bottom_row[0].WW ;
    interpolated_tilt4[1].WW = interpolation_vector4[1].WW + bottom_row[1].WW ;
    interpolated_tilt4[2].WW = interpolation_vector4[2].WW + bottom_row[2].WW ;
 
    
    serial_output("%i,%i\r\n%i,%i\r\n%i,%i\r\n%i,%i\r\n",
            -x_accel[5*accel_read_buffer_index+1],
     
            - interpolated_tilt1[0]._.W1 ,
            //interpolated_tilt1[1]._.W1 ,
            //interpolated_tilt1[2]._.W1 ,
      
            -x_accel[5*accel_read_buffer_index+2],
 
            - interpolated_tilt2[0]._.W1 ,
            //interpolated_tilt2[1]._.W1 ,
            //interpolated_tilt2[2]._.W1 ,
            
            -x_accel[5*accel_read_buffer_index+3],
 
           - interpolated_tilt3[0]._.W1 ,
            //interpolated_tilt3[1]._.W1 ,
            //interpolated_tilt3[2]._.W1 ,    
            
            -x_accel[5*accel_read_buffer_index+4] , 
            
            - interpolated_tilt4[0]._.W1 
            //interpolated_tilt4[1]._.W1 ,
            //interpolated_tilt4[2]._.W1 
              
            );
}

#endif // TEST_SLED

#ifdef KUFEN

extern uint8_t accel_read_buffer_index ;
extern uint8_t accel_write_buffer_index ;
extern int16_t x_accel[] ;
extern int16_t y_accel[] ;
extern int16_t z_accel[] ;

void log_z_accel_data(void)
{
    serial_output("%i\r\n%i\r\n%i\r\n%i\r\n",
            -z_accel[5*accel_read_buffer_index+1],
            -z_accel[5*accel_read_buffer_index+2],
            -z_accel[5*accel_read_buffer_index+3],
            -z_accel[5*accel_read_buffer_index+4]          
            );
}

#endif // KUFEN


#ifdef SPECTRAL_ANALYSIS_CONTINUOUS

extern uint8_t accel_read_buffer_index ;
extern uint8_t accel_write_buffer_index ;
extern int16_t x_accel[] ;
extern int16_t y_accel[] ;
extern int16_t z_accel[] ;

void log_accel_data(void)
{
    serial_output("%i,%i,%i\r\n%i,%i,%i\r\n%i,%i,%i\r\n%i,%i,%i\r\n",
            -x_accel[5*accel_read_buffer_index+1],
            -y_accel[5*accel_read_buffer_index+1],
           -z_accel[5*accel_read_buffer_index+1],
            -x_accel[5*accel_read_buffer_index+2],
            -y_accel[5*accel_read_buffer_index+2],
            -z_accel[5*accel_read_buffer_index+2],
            -x_accel[5*accel_read_buffer_index+3],
            -y_accel[5*accel_read_buffer_index+3],
            -z_accel[5*accel_read_buffer_index+3],
            -x_accel[5*accel_read_buffer_index+4],
            -y_accel[5*accel_read_buffer_index+4],
            -z_accel[5*accel_read_buffer_index+4]          
            );
}

#endif // SPECTRAL_ANALYSIS_CONTINUOUS


#ifdef SPECTRAL_ANALYSIS_BURST
uint16_t spectral_record_number ;
uint16_t sample_index ;

extern int16_t x_gyro[];
extern int16_t y_gyro[];
extern int16_t z_gyro[];
extern uint16_t spectral_sample_number ;

void log_burst_data(void)
{
    sample_index = 1 ;
    while ( sample_index < SAMPLES_PER_BURST )
        {
            serial_output("%i,%i,%i\r\n",
                x_gyro[sample_index],
                y_gyro[sample_index],
                z_gyro[sample_index]                    
                    );
            sample_index++ ;        
        }
    spectral_sample_number = 0 ; 
}


void send_spectral_data(void)
{
  	if (start_log == 1)
	{
		hasWrittenHeader = 0 ;
#ifdef USE_PACKETIZED_TELEMERTY
        is_first_header = 1;
#endif
		if ( is_first_header)
		{
			header_line = 0 ;
			is_first_header = 0 ;
		}
		else
		{	
			header_line = 22 ;
		}
		start_log = 0 ;
		logging_on = 1 ;
#ifdef		ALWAYS_SYNC_GYROS
		gyro_locking_on = 1 ;
#else
		gyro_locking_on = 0 ;
#endif // ALWAYS_SYNC_GYROS	
	}
	if ( stop_log == 1)
	{
		stop_log = 0 ;
		logging_on = 0 ;
		gyro_locking_on = 1 ;
        serial_output_send_packet_cmd(PKT_CMD_STOP);
	}
	if (logging_on == 0 ) return ;
    if ( spectral_sample_number == SAMPLES_PER_BURST )
    {
        serial_output("0,0,0,%i,%i\r\n",
            spectral_record_number++,
            udb_cpu_load());
        udb_background_trigger(&log_burst_data);
    }
}
#endif // SPECTRAL_ANALYSIS_BURST
void send_imu_data(void)
{
#if ( RMS_AND_LPF_GUI == 1 )
    return ;
#endif // RMS_AND_LPF_GUI   
    
#ifndef ALWAYS_LOG
	if (start_log == 1)
	{
		serial_output_send_packet_cmd(PKT_CMD_RUN_START);
		hasWrittenHeader = 0 ;
#ifdef USE_PACKETIZED_TELEMERTY
        is_first_header = 1;
#endif
		if ( is_first_header)
		{
			header_line = 0 ;
			is_first_header = 0 ;
		}
		else
		{	
			header_line = 22 ;
		}
		start_log = 0 ;
		logging_on = 1 ;
#ifdef		ALWAYS_SYNC_GYROS
		gyro_locking_on = 1 ;
#else
		gyro_locking_on = 0 ;
#endif // ALWAYS_SYNC_GYROS	
	}
	if ( stop_log == 1)
	{
		stop_log = 0 ;
		logging_on = 0 ;
		gyro_locking_on = 1 ;
        serial_output_send_packet_cmd(PKT_CMD_STOP);
	}
	if (logging_on == 0 ) return ;
#else
	logging_on = 1 ;
	if (start_log == 1)
	{
		start_log = 0 ;
#ifdef		ALWAYS_SYNC_GYROS
		gyro_locking_on = 1 ;
#else
		gyro_locking_on = 0 ;
#endif // ALWAYS_SYNC_GYROS	
	}
	if ( stop_log == 1)
	{
		stop_log = 0 ;
		gyro_locking_on = 1 ;
	}
#endif // ALWAYS_LOG
	db_index = 0 ;
	if (!hasWrittenHeader)
	{
		header_line ++ ;
		switch ( header_line ) {
		case 1:
			initialize_yaw_rmat();
			break ;
		case 2:
			{
#ifndef NAME
				serial_output("WOLF-PAC SN%i%i%i IMU ", SERIAL_NUMBERD1 , SERIAL_NUMBERD2 , SERIAL_NUMBERD3 ) ;
#else
				serial_output("WOLF-PAC SN%i%i%i IMU, assigned to %s, ", SERIAL_NUMBERD1 , SERIAL_NUMBERD2 , SERIAL_NUMBERD3, NAME ) ;
#endif
			}
			break ;
		case 3:
			{
				serial_output(DATE);
                serial_output("%u MIPS\r\n",MIPS);
#ifdef SPECTRAL_ANALYSIS_BURST
                serial_output("*--> roll analysis logging <--*\r\n");
#endif // SPECTRAL_ANALYSIS_BURST
#ifdef  SPECTRAL_ANALYSIS_CONTINUOUS
                serial_output("*--> force data at 1 kHz and euler angles at 200 Hz <--*\r\n");
#endif //  SPECTRAL_ANALYSIS_CONTINUOUS
#ifdef  TEST_SLED
                serial_output("*--> test sled, x_force and pitch logged at 1kHz <--*\r\n");
#endif //  TEST_SLED
#ifdef  KUFEN
                serial_output("*--> Kufen logging <--*\r\n");
 #endif //  KUFEN                               
			}
			break;
		case 4:
			{
				serial_output("Measurements expressed in north-east-down body frame.\r\n") ;
			}
			break ;	
		case 5:
			{
#ifdef LOG_RATE
				serial_output("gyro rate version\r\n");
#endif // LOG_RATE
				
#ifdef LOG_EULER
				serial_output("Euler angle version.\r\n");
#endif // LOG_EULER
#ifdef LOG_RATE_AND_EULER
			serial_output("gyro rates and euler angles version\r\n");	
#endif // LOG_RATE_AND_EULER
#ifdef LOG_PITCH_AND_TWO_FORCES
			serial_output("x force, z force and pitch angle\r\n");
#endif // LOG_PITCH_AND_TWO_FORCES
			}
			break ;
		case 6:
			{
				serial_output("Specific forces in ft/s^2.\r\n") ;
			}
			break ;	
		case 7:
			{
				serial_output("CCW rotation rates in d/s.\r\n");
			}
			break ;	
		case 8:
			{
				serial_output( BOARD );
			}
		break ;
		case 9:
			{
				serial_output( "Accelerometer range is %i times gravity.\r\n" , ACCEL_RANGE ) ;
			}
			break ;
		case 10:
			{
				serial_output( "Gyro range is %i deg/sec.\r\n" , GYRO_RANGE ) ;
			}
			break ;
		case 12:
			{
				serial_output("Gyro calibrations are x=%6.4f, y=%6.4f, z=%6.4f.\r\n", 
						CALIBRATIONX ,CALIBRATIONY,CALIBRATIONZ );		
			}
			break ;
		case 14:
            {
                serial_output("Gyro strain offsets are x=%i, y=%i, z=%i.\r\nZ->X cross coupling = %i.\r\n",
                        residual_offset[0] , residual_offset[1] , residual_offset[2] , X_CROSS_COUPLING
                        );
            }
			break ;
        case 15:
            {
                serial_output("Jostle detection thresholds are %i variance for gyro filtering,\r\n %i rate for matrix alignment.\r\n",
                        GYRO_VARIANCE_MARGIN , MATRIX_GYRO_OFFSET_MARGIN 
                        );
            }
            break ;
		case 16:
			{
				serial_output("Tilt start angle = %i deg, stop = %i deg.\r\n", TILT_START , TILT_STOP);
			}
			break ;
		case 18:
			{
#ifdef XACCEL_OFFSET
				serial_output( "Accel offsets are x=%i, y=%i, z=%i.\r\n",
					accel_residual_offset[0] ,
					accel_residual_offset[1] , 
					accel_residual_offset[2] 
					 );	
#endif // XACCEL_OFFSET
			}
			break;
		case 19:
			{
				serial_output( "Accel calibrations are x=%i, y=%i, z=%i.\r\n",
					CAL_GRAV_X ,
					CAL_GRAV_Y , 
					CAL_GRAV_Z 
					 );
			}
			break;
		case 20:
			{
#ifdef KUFEN
				serial_output("Run data rate is %i records/s.\r\nBetween runs residuals are logged every %i seconds.\r\n", 
                        LOGGER_HZ/2 , RESIDUAL_LOG_PERIOD  );   
#else
				serial_output("Run data rate is %i records/s.\r\nBetween runs residuals are logged every %i seconds.\r\n", 
                        LOGGER_HZ , RESIDUAL_LOG_PERIOD  );
#endif // KUFEN
			}
			break;
		case 21:
			{
				serial_output(FILTERING);
#ifndef ALWAYS_LOG
#ifndef USE_PACKETIZED_TELEMERTY
#if (EULER_GUI==1)
                hasWrittenHeader = 1 ;
#else
				stop_log = 1 ;
				start_residuals = 1 ;
				hasWrittenHeader = 1 ;
#endif // EULER_GUI
#endif
#endif // ALWAYS_LOG
				
			}
			break;
		case 23:
			{
#ifdef LOG_IMU_WP1
				// initialize the unwrapping of yaw angle
				compute_euler();
				yaw_previous = yaw_angle ;
				heading_previous = 0.0 ;
#ifdef LOG_RATE
				serial_output( "forward_force , lateral , vertical , roll_rate , pitch , yaw\r\n" ) ;
#endif // LOG_RATE
#ifdef LOG_EULER
#ifndef THETA_LOG
#ifndef UDB7LUGE
				serial_output( "\r\n\r\nx_force_xx,y_force_xx,z_force_xx,yaw_xx,pitch_xx,roll_xx,max_gyro_pct_xx\r\n" ) ;
#else
				serial_output( "\r\n\r\nx_force_xx,y_force_xx,z_force_xx,yaw_xx,pitch_xx,roll_xx,max_gyro_pct_xx,cpu,line_no\r\n" ) ;
#endif // UDB7LUGE
#else
				serial_output("\r\r\r\nx_theta,y_theta,x_omega,y_omega,pitch,roll\r\n") ;
#endif // THETA_LOG
#endif // LOG_EULER	
#ifdef LOG_RATE_AND_EULER
				serial_output( "\r\n\r\nx_rate_xx,y_rate_xx,z_rate_xx,yaw_xx,pitch_xx,roll_xx\r\n" ) ;		
#endif // LOG_RATE_AND_EULER
#ifdef LOG_PITCH_AND_TWO_FORCES
				serial_output( "\r\n\r\nx_force_xx,z_force,pitch_xx\r\n" ) ;	
#endif // LOG_PITCH_AND_TWO_FORCES
#endif // LOG_IMU_WP1
				
#ifdef LOG_IMU_WP2
				max_gyro = 0 ;
#ifndef CONING_CORRECTION
				compute_euler();
				yaw_previous = yaw_angle ;
				heading_previous = 0.0 ;
#else // CONING_CORRECTION
#ifndef TEST_SLED
				compute_euler_8k();
				yaw_previous_8k = yaw_angle_8k ;
				heading_previous_8k = 0.0 ;
#endif // TEST_SLED
#endif // CONING_CORRECTION
#ifdef START_TRACK_LOG
                serial_output("\r\nx_force_xx,y_force_xx,pitch_xx\r\n");
#else
#ifndef LOG_R_UPDATE
#ifdef TILT_INIT
                serial_output("\r\n\r\nRunmode\r\naccOn,logOn,nx_force,y_force,z_force,yaw8,pitch8,roll8,yaw,pitch,roll\r\n");        
#else

//#define SPECTRAL_ANALYSIS_CONTINUOUS
//#define NORMAL_RUN
//#define TEST_SLED
//#define KUFEN                
//#define SPECTRAL_ANALYSIS_BURST
                
#ifdef  NORMAL_RUN
#ifdef LOG_PITCH_RATE
            serial_output("\r\nx_force_xx,y_force_xx,z_force_xx,yaw_xx,pitch_xx,roll_xx,max_gyro_pct_xx,cpu_xx,seq_no_xx,pitch_rate_xx\r\n");                              
#elif (TEST_RUNTIME_TILT_ALIGN == 1)
            serial_output("\r\nx_force,y_force,z_force,yaw_32,pitch_32,roll_32,max_gyro,cpu,seq_no,tmptur,yaw_16,pitch_16,roll_16,lpx,lpy,lpz,algn_x,algn_y,algn_z\r\n");              
              
#else
           serial_output("\r\nx_force_xx,y_force_xx,z_force_xx,yaw_xx,pitch_xx,roll_xx,yaw_rate_xx,max_gyro_pct_xx,cpu_xx,seq_no_xx,tmptur_xx\r\n");              
#endif // LOG_PITCH_RATE , TEST_RUNTIME_TILT_ALIGN
#endif // NORMAL_RUN

#ifdef SPECTRAL_ANALYSIS_BURST
                spectral_sample_number = 0 ;
                serial_output("\r\nx_gyro_xx,y_gyro_xx,z_gyro_xx,x_force_xx,y_force_xx,z_force_xx,yaw_xx,pitch_xx,roll_xx,max_gyro_pct_xx,cpu_xx,seq_no_xx,tmptur_xx\r\n");
#endif //  SPECTRAL_ANALYSIS_BURST              

#ifdef TEST_SLED
                serial_output("\r\nx_force_xx,pitch_xx,cpu_xx,seq_no_xx\r\n");
#endif // TEST_SLED 
                
#ifdef KUFEN
                serial_output("\r\nz_force_xx,yaw_xx,roll_xx,cpu_xx,seq_no_xx\r\n");
#endif // KUFEN
                
#ifdef SPECTRAL_ANALYSIS_CONTINUOUS
                serial_output("\r\nx_force_xx,y_force_xx,z_force_xx,yaw_xx,pitch_xx,roll_xx,max_gyro_pct_xx,cpu_xx,seq_no_xx,tmptur_xx\r\n");              
#endif // SPECTRAL_ANALYSIS_CONTINUOUS                
                  
                
#endif // TILT_INIT
#else
                serial_output("\r\ngyro_lck,accelOn,theta_sum_x,y,z,LPF1_x,y,z,LPF2_x,y,z\r\n");
#endif //   LOG_R_UPDATE              
#endif // START_TRACK_LOG
#endif // LOG_IMU_WP2
                
#ifdef FILTERED_ACCELEROMETER
                serial_output("\r\nx_force,y_force,z_force\r\n");               
#endif //FILTERED_ACCELEROMETER
				
#ifdef RECORD_OFFSETS
				serial_output("tmptur,ax,ay,az,gx_val,gy_val,gz_val,gyr_x,gyr_y,gyr_z,gyr_rms\r\n");
#endif // RECORD_OFFSETS
				
#ifdef TEST_LOGGER_HZ
				serial_output("logger bandwidth test\r\n");
#endif // TEST_LOGGER_HZ
#ifdef GYRO_CALIB
				serial_output("X, Y, Z calib angles\r\n") ;
#endif // GYRO_CALIB
#ifdef LOG_VELOCITY
				serial_output( "gyro_sync,cpu,wx,wy,wz,fx,fy,fz,gx,gy,gz,ax,ay,az,vel\r\n");
#endif // LOG_VELOCITY
#ifdef TEST_GYRO_LOCK
				serial_output("o_dot_r6,errYx,errYy,errYz,errRPx,errRPy,errRPz,wx,wy,wz\r\n" );
#endif // TEST_GYRO_LOCK
#ifdef GYRO_DRIFT
//				serial_output("gx,gy,gyz,gxfilt,gyfilt,gzfilt,ax,ay,az,axfilt,ayfilt,azfilt\r\n");
				serial_output("\r\ntmptur,synch,cpu_load,w_mag,acc_mag,yaw,pitch,roll,gx,gy,gz,gxlp,gylp,gzlp,errx,erry,errz\r\n");
#endif // GYRO_DRIFT
#ifdef GYRO_OFFSETS
				serial_output("\r\ntmptr,ind_msb,ind_lsb,w_mag,acc_mag,xrv,yrv,zrv,xro,yro,zro,wx,wy,wz\r\n");
#endif //				
#ifdef ROAD_TEST
		serial_output("synch,gx,gy,gyz,ax,ay,az,r6,r7,r8\r\n");
#endif // ROAD_TEST
#ifdef BUILD_OFFSET_TABLE
#ifdef ACCEL_AND_GYRO_OFFSETS
        //serial_output ("\r\ntmptr,cpu,smpls,gyro_mag,gyro_off_x,gyro_off_y,gyro_off_z,gyro_raw_x,gyro_raw_y,gyro_raw_z,acc_x,acc_y,acc_z\r\n");
#else
		serial_output("\r\ntmptr,cpu,smpls,X_bar,Y_bar_x,Y_bar_y,Y_bar_z,XX_bar,XY_bar_x,XY_bar_y,XY_bar_z,denom,lft_o_x,lft_o_y,lft_o_z,rght_o_x,rght_o_y,rght_o_z,offx,offy,offz\r\n");
#endif //
#endif //BUILD_OFFSET_TABLE
			}
			break ;	
		case 25:
            start_residuals = 1 ;
            hasWrittenHeader = 1 ;
			break ;
		default:
			break ;
		}
	}
	else
	{
#ifdef RECORD_OFFSETS 
		{
			serial_output( "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n" ,
			mpu_temp.value,
			udb_xaccel.value - udb_xaccel.offset , 
            udb_yaccel.value - udb_yaccel.offset , 
            udb_zaccel.value - udb_zaccel.offset ,
			udb_xrate.value , udb_yrate.value , udb_zrate.value	,
			omegagyro[0],omegagyro[1],omegagyro[2] ,
            vector3_mag(omegagyro[0],omegagyro[1],omegagyro[2])
			 ) ;
		}
#endif // RECORD_OFFSETS
		
#ifdef GYRO_OFFSETS
		{
			serial_output( "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n" ,
				mpu_temp.value,
				index_msb , index_lsb ,
				omega_magnitude ,
				accel_magnitude ,
				64*udb_xrate.value , 64*udb_yrate.value , 64*udb_zrate.value	,	
				gyro_offset[0] , gyro_offset[1] , gyro_offset[2] ,
				omegagyro[0] , omegagyro[1], omegagyro[2]
			 ) ;
		}
#endif // 

#ifdef TEST_LOGGER_HZ
#ifdef PARTIAL_RECORD		
		{
			serial_output("22 chars test string\r\n") ;
		}
#endif // PARTIAL_RECORD
#ifdef FULL_RECORD
		{
			serial_output("43 chars test string 43 chars test string\r\n") ;
		}
#endif	
#endif // TEST_LOGGER_HZ
#ifdef FILTERED_ACCELEROMETER
  {
			serial_output( "%.3f,%.3f,%.3f\r\n" ,
				((double)(aero_force_filtered[0]._.W1))/ACCEL_FACTOR ,
				((double)(aero_force_filtered[1]._.W1))/ACCEL_FACTOR ,
				((double)(aero_force_filtered[2]._.W1))/ACCEL_FACTOR
				 ) ;	
		}      
#endif // FILTERED_ACCELEROMETER

#ifdef LOG_IMU_WP1
#ifdef LOG_RATE
		{
			serial_output( "%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\r\n" ,
				((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
				((double)(omegaAccum[0]))/GYRO_FACTOR ,
				((double)(omegaAccum[1]))/GYRO_FACTOR , 
				((double)(omegaAccum[2]))/GYRO_FACTOR ) ;	
		}
#endif // LOG_RATE
#ifdef LOG_EULER
		{
			compute_euler();
			delta_yaw = yaw_angle - yaw_previous ;
			if (abs(delta_yaw)<90.0)
			{
				heading = heading_previous + delta_yaw ;
			}
			else if(delta_yaw>0)
			{
				heading = heading_previous + delta_yaw - 360.0 ;
			}
			else
			{
				heading = heading_previous + delta_yaw + 360.0 ;
			}
			heading_previous = heading ;
			yaw_previous = yaw_angle ;
#ifndef THETA_LOG
#ifndef UDB7LUGE
			serial_output( "%.2f,%.1f,%.1f,%.1f,%.2f,%.1f,%u\r\n" ,
				((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
				heading ,  pitch_angle , roll_angle , max_gyro/328  ) ;	
			max_gyro = 0 ;
#else

            serial_output( "%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%u,%u,%u\r\n" ,
				((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
				heading ,  pitch_angle , roll_angle , max_gyro/328 , udb_cpu_load() , record_number ++   ) ;	
			max_gyro = 0 ;
            
#endif // UDB7LUGE

#else
			serial_output("%i,%i,%i,%i,%.2f,%.2f\r\n" ,
					theta[0] , theta[1] ,
					omega[0] , omega[1] ,
					pitch_angle , roll_angle ) ;
#endif // THETA_LOG
		}
#endif // LOG_EULER
#ifdef LOG_RATE_AND_EULER
		{
			compute_euler();
			serial_output( "%.1f,%.1f,%.1f,%.1f,%.2f,%.1f\r\n" ,
				((double)(omegaAccum[0]))/GYRO_FACTOR ,
				((double)(omegaAccum[1]))/GYRO_FACTOR , 
				((double)(omegaAccum[2]))/GYRO_FACTOR ,
				yaw_angle ,  pitch_angle , roll_angle ) ;	
		}
#endif // LOG_RATE_AND_EULER
#ifdef LOG_PITCH_AND_TWO_FORCES
		{
			compute_euler();
			serial_output( "%.2f,%.1f,%.2f\r\n" ,
				((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
				pitch_angle   ) ;	
		}	
#endif // LOG_PITCH_AND_TWO_FORCES
#endif // LOG_IMU_WP1
#ifdef LOG_IMU_WP2
        {
#ifndef LOG_R_UPDATE
#ifndef CONING_CORRECTION
 			compute_euler();
			delta_yaw = yaw_angle - yaw_previous ;
			if (abs(delta_yaw)<90.0)
			{
				heading = heading_previous + delta_yaw ;
			}
			else if(delta_yaw>0)
			{
				heading = heading_previous + delta_yaw - 360.0 ;
			}
			else
			{
				heading = heading_previous + delta_yaw + 360.0 ;
			}
			heading_previous = heading ;
			yaw_previous = yaw_angle ;
#else // CONING_CORRECTION
#ifndef START_TRACK_LOG
#ifndef TEST_SLED
			compute_euler_8k();
#endif // TEST_SLED
#ifdef TILT_INIT
            compute_euler() ;
#endif // TILT_INIT
			delta_yaw_8k = yaw_angle_8k - yaw_previous_8k ;
			if (abs(delta_yaw_8k)<90.0)
			{
				heading_8k = heading_previous_8k + delta_yaw_8k ;
			}
			else if(delta_yaw_8k>0)
			{
				heading_8k = heading_previous_8k + delta_yaw_8k - 360.0 ;
			}
			else
			{
				heading_8k = heading_previous_8k + delta_yaw_8k + 360.0 ;
			}
			heading_previous_8k = heading_8k ;
			yaw_previous_8k = yaw_angle_8k ;
#else
			compute_euler();
			delta_yaw = yaw_angle - yaw_previous ;
			if (abs(delta_yaw)<90.0)
			{
				heading = heading_previous + delta_yaw ;
			}
			else if(delta_yaw>0)
			{
				heading = heading_previous + delta_yaw - 360.0 ;
			}
			else
			{
				heading = heading_previous + delta_yaw + 360.0 ;
			}
			heading_previous = heading ;
			yaw_previous = yaw_angle ;
         
#endif // START_TRACK_LOG
#endif // CONING_CORRECTION	
#endif // LOG_R_UPDATE
#ifdef START_TRACK_LOG
            serial_output("%.3f,%.2f,%.3f\r\n",
            	((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				pitch_angle ) ;				       
#else
#ifndef LOG_R_UPDATE
#ifndef TILT_INIT

#ifdef  NORMAL_RUN 
#if (EULER_GUI==1)
    int16_t omega_filt_16[3];
    omega_filt_16[0]=(int16_t)((omegagyro_filtered[0].WW)>>12);
    omega_filt_16[1]=(int16_t)((omegagyro_filtered[1].WW)>>12);
    omega_filt_16[2]=(int16_t)((omegagyro_filtered[2].WW)>>12); 

    compute_euler_8k();
    serial_output("(W10),(L%.1f),(Y%.1f),(P%.1f),(R%.1f)\r\n", 
       ((float)    vector3_mag(
            omega_filt_16[0],
            omega_filt_16[1],
            omega_filt_16[2]))/16.0,
            yaw_angle_8k , pitch_angle_8k , roll_angle_8k);
    //omega_filt_16_previous[0]=omega_filt_16[0];
    //omega_filt_16_previous[1]=omega_filt_16[1];
    //omega_filt_16_previous[2]=omega_filt_16[2];  
#else
            serial_output("%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%u,%u,%u,%i", 
            	((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
#ifndef CONING_CORRECTION
				heading ,  pitch_angle , roll_angle ,
#else
				heading_8k ,  pitch_angle_8k , roll_angle_8k ,
#endif 
                ((double) (yaw_rate))/ ((double)93701.65) ,    
				max_gyro/328  ,
                udb_cpu_load(),
                record_number ++ ,
#ifdef LOG_PITCH_RATE
                omegagyro[1]
#else
                mpu_temp.value 
#endif // LOG_PITCH_RATE
			);
#if ( TEST_RUNTIME_TILT_ALIGN == 1 )
            compute_euler() ;
            serial_output(",%.2f,%.2f,%.2f,%i,%i,%i,%i,%i,%i\r\n",
                    yaw_angle, pitch_angle, roll_angle ,
                (int16_t)((omegagyro_filtered[0].WW)>>12) , // 16x
				(int16_t)((omegagyro_filtered[1].WW)>>12) ,
				(int16_t)((omegagyro_filtered[2].WW)>>12) ,
                    misalignment[0],
                    misalignment[1],
                    misalignment[2]                   
                    );
#else
            serial_output("\r\n");
#endif // TEST_RUNTIME_TILT_ALIGN
#endif // EULER_GUI
#endif // NORMAL_RUN

#ifdef SPECTRAL_ANALYSIS_BURST
            serial_output("%i,%i,%i,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%u,%u,%u,%i\r\n",     
                x_gyro[0],y_gyro[0],z_gyro[0],
                ((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
#ifndef CONING_CORRECTION
				heading ,  pitch_angle , roll_angle ,
#else
				heading_8k ,  pitch_angle_8k , roll_angle_8k ,
#endif                
				max_gyro/328  ,
                udb_cpu_load(),
                record_number ++ ,
                mpu_temp.value                    
			);
            if ( spectral_sample_number == SAMPLES_PER_BURST ) udb_background_trigger(&log_burst_data);
#endif //  SPECTRAL_ANALYSIS_BURST              

#ifdef TEST_SLED
                serial_output("%i,%i,%u,%u\r\n",
                -x_accel[5*accel_read_buffer_index],
                 - rmat_32[6]._.W1 ,
                        
                        //rmat_32[7]._.W1 ,rmat_32[8]._.W1 ,
                        
                udb_cpu_load(),record_number ++                  
			);
            udb_background_trigger(&log_x_accel_data);            

#endif // TEST_SLED 
                
#ifdef KUFEN
        if(accel_read_buffer_index) {   
                serial_output("%i,%.2f,%.2f,%u,%u\r\n",
                -z_accel[5*accel_read_buffer_index],
#ifndef CONING_CORRECTION
				yaw_angle , roll_angle ,
#else
				yaw_angle_8k , roll_angle_8k ,
#endif                
                udb_cpu_load(),record_number ++                  
			);
        }
        else
        {
            serial_output("%i\r\n",
                -z_accel[5*accel_read_buffer_index]);
        }
            udb_background_trigger(&log_z_accel_data);            

#endif // KUFEN
                
#ifdef SPECTRAL_ANALYSIS_CONTINUOUS
            serial_output("%i,%i,%i,%.2f,%.2f,%.2f,%u,%u,%u,%i\r\n",
               - x_accel[5*accel_read_buffer_index],
               - y_accel[5*accel_read_buffer_index],
               - z_accel[5*accel_read_buffer_index],
#ifndef CONING_CORRECTION
				heading ,  pitch_angle , roll_angle ,
#else
				heading_8k ,  pitch_angle_8k , roll_angle_8k ,
#endif                
				max_gyro/328  ,
                udb_cpu_load(),
                record_number ++ ,
                mpu_temp.value                    
			);
            udb_background_trigger(&log_accel_data);            
#endif // SPECTRAL_ANALYSIS_CONTINUOUS                

         
#else
                serial_output("%u,%u,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f,%.1f\r\n",
                        accelOn , logging_on ,
            	((double)(aero_force[0]))/ACCEL_FACTOR ,
				((double)(aero_force[1]))/ACCEL_FACTOR ,
				((double)(aero_force[2]))/ACCEL_FACTOR ,
                yaw_angle_8k ,  pitch_angle_8k , roll_angle_8k ,     
				yaw_angle ,  pitch_angle , roll_angle                  
			);

#endif // TILT_INIT
#else
#ifdef SIMULATE_TILT
            if ( run_count++ >= RUN_TIME)
            {
                run_count = 0 ;
                is_level = 0 ;
            }
#endif // SIMULATE_TILT
            serial_output("%i,%i,%i,%i,%i,%i,%i,%i,%li,%li,%li\r\n",
                    gyro_locking_on ,
                    accelOn ,
                    theta_sum[0]._.W1 ,
                    theta_sum[1]._.W1 ,
                    theta_sum[2]._.W1 ,
 //                   (int16_t)((omegagyro_filtered[0].WW)>>12) , // 16x
 //                   (int16_t)((omegagyro_filtered[1].WW)>>12) ,
 //                   (int16_t)((omegagyro_filtered[2].WW)>>12) ,
                    (int16_t)((omegagyro_filtered[0].WW)>>10) , // 64x
                    (int16_t)((omegagyro_filtered[1].WW)>>10) ,
                    (int16_t)((omegagyro_filtered[2].WW)>>10) ,
 
                    theta_32_filtered[0]._.L1 , theta_32_filtered[1]._.L1 ,theta_32_filtered[2]._.L1 
                    );

#endif // LOG_R_UPDATE
#endif // START_TRACK_LOG
			max_gyro = 0 ;
		}
#endif // LOG_IMU_WP2
#ifdef GYRO_CALIB

		{	compute_bill_angles();
			serial_output("%6.1f,%6.1f,%6.1f\r\n", bill_angle_x , bill_angle_y , bill_angle_z);

		}	
#endif // GYRO_CALIB
#ifdef GYRO_DRIFT
		compute_euler();
		serial_output("%i,%i,%i,%i,%i,%.1f,%.1f,%.1f,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n",
				mpu_temp.value,
				accelOn ,
				udb_cpu_load(),
				omega_magnitude ,
				accel_magnitude ,
				yaw_angle , pitch_angle , roll_angle ,
				omegagyro[0],
				omegagyro[1],
				omegagyro[2],
				(int16_t)((omegagyro_filtered[0].WW)>>12) ,
				(int16_t)((omegagyro_filtered[1].WW)>>12) ,
				(int16_t)((omegagyro_filtered[2].WW)>>12) ,
				errorRP[0] ,
				errorRP[1] ,
				errorRP[2]
					);
		
#endif // GYRO_DRIFT
		
#ifdef BUILD_OFFSET_TABLE
#ifdef ACCEL_AND_GYRO_OFFSETS
        update_offset_table_gyros_and_accelerometers();
#else
		update_offset_table();	
#endif // ACCEL_AND_GYRO_OFFSETS
#endif // BUILD_OFFSET_TABLE

#ifdef ROAD_TEST
		serial_output("%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n",
				gyro_locking_on ,
				omegaAccum[0],
				omegaAccum[1],
				omegaAccum[2] ,
				aero_force[0] ,
				aero_force[1] ,
				aero_force[2] ,
				rmat[6] ,
				rmat[7] ,
				rmat[8] 
					);
	
#endif // GYRO_DRIFT


#ifdef LOG_VELOCITY
		{
			serial_output("%i,%i,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f,%.2f\r\n",
					accelOn , udb_cpu_load() ,
					omegaAccum_float[0] ,
					omegaAccum_float[1] , 
					omegaAccum_float[2] ,
					aero_force_float[0] , aero_force_float[1] , aero_force_float[2] ,
					gravity_float[0] , gravity_float[1] , gravity_float[2] ,
					acceleration_float[0] , acceleration_float[1] , acceleration_float[2] , velocity 
					);
		}
#endif // LOG_VELOCITY
		
#ifdef TEST_GYRO_LOCK
		{
			serial_output( "%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n",
					omega_dot_rmat6 ,
					errorYawplane[0] , errorYawplane[1] , errorYawplane[2] , 
					errorRP[0] , errorRP[1] , errorRP[2] , 
					omegaAccum[0] , omegaAccum[1] , omegaAccum[2] 
					) ;
		}
#endif // 
	}
	return ;
}
/*
extern int gplane[] ;
// Prepare a line of serial output and start it sending
void send_debug_line( void )
{
	db_index = 0 ;
	
	if (!hasWrittenHeader)
	{
		sprintf(debug_buffer, "w0 , w1 , w2 , a0 , a1 , a2\r\n") ;
		hasWrittenHeader = 1 ;
	}
	else
	{
		sprintf(debug_buffer, "%i , %i , %i , %i , %i , %i\r\n" ,
		omegagyro[0] , 	omegagyro[1] , omegagyro[2] ,
		gplane[0] , gplane[1] , gplane[2]
		 ) ;
	}
	
	udb_serial_start_sending_data() ;
	
	return ;
}
*/

