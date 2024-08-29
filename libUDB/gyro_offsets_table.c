/* 
 * File:   gyro_offsets_table.h
 * Author: bill
 *
 * Created on December 20, 2022, 9:35 AM
 */

#include <stdint.h>
#include "../libDCM/libDCM.h"
#include "../libDCM/libDCM_defines.h"
#include "../libDCM/mathlibNAV.h"
#include "../libDCM/gpsData.h"
#include "../libDCM/gpsParseCommon.h"
#include "../libDCM/rmat.h"
#include "../libUDB/heartbeat.h"
#include "../libUDB/serialIO.h"
#include "../libUDB/servoOut.h"
#include "../libUDB/ADchannel.h"
#include <math.h>


typedef struct gyro_offset_table_entry { int16_t x ; int16_t y ; int16_t z ; } gyro_offset_table_entry ;

#include GYRO_OFFSET_TABLE

#if (STEP_SIZE == 1024)
#define LOOKUP_LSB_MASK 0x03FF
#define MSB_SHIFT 10
#elif ( STEP_SIZE == 256 )
#define LOOKUP_LSB_MASK 0x00FF
#define MSB_SHIFT 8
#elif ( STEP_SIZE == 64 )
#define LOOKUP_LSB_MASK 0x003F
#define MSB_SHIFT 6
#else
#error "unsupported or undefine STEP_SIZE"
#endif // STEP_SIZE

extern struct ADchannel mpu_temp;

int16_t temperature_index ;

int16_t gyro_offset[3] ;


#ifdef X_CROSS_COUPLING
int16_t cross_coupling = X_CROSS_COUPLING ;
#else
int16_t cross_coupling = 0 ;
#endif

uint16_t index_msb = 0 ;
uint16_t index_lsb = 0 ;
int16_t left_entry[3];
int16_t right_minus_left[3];
uint16_t number_entries ;
int16_t accel_gyro_coupling_compensation[]= { 0 , 0 , 0 };
#ifdef SIMULATED_GYRO
void lookup_gyro_offsets(void)
{
    gyro_offset[0] = 1600 ;
    gyro_offset[1] = -3200 ;
    gyro_offset[2] = 4800 ;    
}
#else
void lookup_gyro_offsets(void)
{
#ifdef X_CROSS_COUPLING
    accel_gyro_coupling_compensation[0] = 
            (int16_t)(__builtin_mulss(aero_force[2],X_CROSS_COUPLING)>>11 ) ;
#endif //
#ifdef Y_CROSS_COUPLING
    accel_gyro_coupling_compensation[1] = 
            (int16_t)(__builtin_mulss(aero_force[2],Y_CROSS_COUPLING)>>11 ) ;   
#endif //
#ifdef Z_CROSS_COUPLING
        accel_gyro_coupling_compensation[2] = 
            (int16_t)(__builtin_mulss(aero_force[2],Z_CROSS_COUPLING)>>11 ) ;
#endif //    
	temperature_index = mpu_temp.value - TABLE_ORIGIN ;
	if (temperature_index < 0)
	{
		index_msb = 0 ;
		index_lsb = 0 ;
		gyro_offset[0] = accel_gyro_coupling_compensation[0]+residual_offset[0]+ gyro_offset_table[0].x ;
		gyro_offset[1] = accel_gyro_coupling_compensation[1]+residual_offset[1]+ gyro_offset_table[0].y ;
		gyro_offset[2] = accel_gyro_coupling_compensation[2]+residual_offset[2]+ gyro_offset_table[0].z ;
	}
	else
	{
		index_lsb = temperature_index & LOOKUP_LSB_MASK ;
		index_msb = temperature_index >> MSB_SHIFT ; 
		number_entries = (sizeof (gyro_offset_table))/(sizeof (gyro_offset_table_entry)) ;
		if ( index_msb >= (number_entries - 1 ))
		{
			gyro_offset[0] = accel_gyro_coupling_compensation[0]+residual_offset[0]+ gyro_offset_table[number_entries - 1].x ;
			gyro_offset[1] = accel_gyro_coupling_compensation[1]+residual_offset[1]+ gyro_offset_table[number_entries - 1].y ;
			gyro_offset[2] = accel_gyro_coupling_compensation[2]+residual_offset[2]+ gyro_offset_table[number_entries - 1].z ;
		}
		else
		{
			left_entry[0]= gyro_offset_table[index_msb].x ;
			left_entry[1]= gyro_offset_table[index_msb].y ;
			left_entry[2]= gyro_offset_table[index_msb].z ;
			
			right_minus_left[0]= gyro_offset_table[index_msb+1].x - left_entry[0] ;
			right_minus_left[1]= gyro_offset_table[index_msb+1].y - left_entry[1] ;
			right_minus_left[2]= gyro_offset_table[index_msb+1].z - left_entry[2] ;
			
			gyro_offset[0] = accel_gyro_coupling_compensation[0]
                    +residual_offset[0] 
					+ left_entry[0] 
					+ __builtin_divsd(__builtin_mulss(right_minus_left[0],index_lsb),STEP_SIZE);
			gyro_offset[1] = accel_gyro_coupling_compensation[1]
                    +residual_offset[1] 
					+ left_entry[1] 
					+ __builtin_divsd(__builtin_mulss(right_minus_left[1],index_lsb),STEP_SIZE);
			gyro_offset[2] = accel_gyro_coupling_compensation[2]
                    +residual_offset[2] 
					+ left_entry[2] + 
					__builtin_divsd(__builtin_mulss(right_minus_left[2],index_lsb),STEP_SIZE);
		}
	}
}
#endif // SIMULATED_GYRO

#ifdef ACCEL_TABLE

int16_t accel_offset[3] ;

void lookup_accel_offsets(void)
{
  	temperature_index = mpu_temp.value - ACCEL_TABLE_ORIGIN ;
	if (temperature_index < 0)
	{
		index_msb = 0 ;
		index_lsb = 0 ;
		accel_offset[0] = accel_residual_offset[0]+ accel_offset_table[0].x ;
        accel_offset[1] = accel_residual_offset[1]+ accel_offset_table[0].y ;
        accel_offset[2] = accel_residual_offset[2]+ accel_offset_table[0].z ;

	}
	else
	{
		index_lsb = temperature_index & LOOKUP_LSB_MASK ;
		index_msb = temperature_index >> MSB_SHIFT ; 
		number_entries = (sizeof (accel_offset_table))/(sizeof (gyro_offset_table_entry)) ;
		if ( index_msb >= (number_entries - 1 ))
		{
			accel_offset[0] = accel_residual_offset[0]+ accel_offset_table[number_entries - 1].x ;
            accel_offset[1] = accel_residual_offset[1]+ accel_offset_table[number_entries - 1].y ;
			accel_offset[2] = accel_residual_offset[2]+ accel_offset_table[number_entries - 1].z ;
				
        }
		else
		{
			left_entry[0]= accel_offset_table[index_msb].x ;
			left_entry[1]= accel_offset_table[index_msb].y ;
			left_entry[2]= accel_offset_table[index_msb].z ;
			
			right_minus_left[0]= accel_offset_table[index_msb+1].x - left_entry[0] ;
			right_minus_left[1]= accel_offset_table[index_msb+1].y - left_entry[1] ;
			right_minus_left[2]= accel_offset_table[index_msb+1].z - left_entry[2] ;
			
			accel_offset[0] = 
                    accel_residual_offset[0] 
					+ left_entry[0] 
					+ __builtin_divsd(__builtin_mulss(right_minus_left[0],index_lsb),STEP_SIZE);
			accel_offset[1] = 
                    accel_residual_offset[1] 
					+ left_entry[1] 
					+ __builtin_divsd(__builtin_mulss(right_minus_left[1],index_lsb),STEP_SIZE);
			accel_offset[2] = 
                    accel_residual_offset[2] 
					+ left_entry[2] 
					+ __builtin_divsd(__builtin_mulss(right_minus_left[2],index_lsb),STEP_SIZE);
			
		}
	} 
    udb_xaccel.offset = accel_offset[0] ;
	udb_yaccel.offset = accel_offset[1] ;
	udb_zaccel.offset = accel_offset[2] ;
}

#else

void lookup_accel_offsets(void)
{
    
}

#endif // ACCEL_TABLE

int64_t samples_64t = 0 ;
int32_t samples_32t = 0 ;
int16_t gyro_offset_entry[] = { 0 , 0 , 0 } ;
int64_t xx_sum = 0 ;
int64_t xy_sum[] = { 0 , 0 , 0  } ;
int32_t x_sum = 0 ;
int32_t y_sum[] = { 0 , 0 , 0  } ;
int32_t xx_bar = 0 ;
int32_t xy_bar[] = { 0 , 0 , 0  } ;
int16_t x_bar = 0 ;
int16_t y_bar[] = { 0 , 0 , 0  } ;
int64_t xx_bar_minus_x_bar_x_bar ;
int16_t offset_left[3] ;
int16_t offset_right[3] ;
int16_t offset_previous[3];

int16_t adjusted_temperature = 0 ;
int16_t temperature_offset = 0 ;
int16_t initial_temperature = 0 ;
int16_t reported_temperature = -8000 ;

int16_t initial_temp_recorded = 0 ;
int16_t initial_temp_reported = 0 ;

extern uint8_t udb_cpu_load(void);
extern void serial_output(const char* format, ...);

void update_offset_table(void)
{
	reported_temperature = mpu_temp.value ;
	if ( initial_temp_recorded == 0 )
	{
		initial_temperature = reported_temperature ;
		temperature_offset = initial_temperature ;
		initial_temp_recorded = 1 ;
		LED_RED = LED_ON ;
		LED_GREEN = LED_OFF ;
	}
	adjusted_temperature = reported_temperature - temperature_offset ;
	{
		gyro_offset_entry[0]= 64*udb_xrate.value ;
		gyro_offset_entry[1]= 64*udb_yrate.value ;
		gyro_offset_entry[2]= 64*udb_zrate.value ;
		
		xx_sum += (uint64_t) __builtin_mulss( adjusted_temperature,adjusted_temperature) ;
		
		xy_sum[0] += (int64_t)	__builtin_mulss( adjusted_temperature,gyro_offset_entry[0]) ;
		xy_sum[1] += (int64_t)	__builtin_mulss( adjusted_temperature,gyro_offset_entry[1]) ;
		xy_sum[2] += (int64_t)	__builtin_mulss( adjusted_temperature,gyro_offset_entry[2]) ;
		
		x_sum += (int32_t ) adjusted_temperature ;
		
		y_sum[0] += (int32_t ) gyro_offset_entry[0] ;
		y_sum[1] += (int32_t ) gyro_offset_entry[1] ;
		y_sum[2] += (int32_t ) gyro_offset_entry[2] ;
		
		samples_32t ++ ;
		
		if ( adjusted_temperature >= STEP_SIZE )
		{
			udb_led_toggle(LED_GREEN);
			udb_led_toggle(LED_RED);
			temperature_offset += STEP_SIZE ;
			samples_64t = (int64_t)samples_32t ;
			if (samples_32t>0)
			{
				xx_bar = (int32_t)(xx_sum /samples_64t) ;
			
				xy_bar[0] = (int32_t)(xy_sum[0] /samples_64t) ;
				xy_bar[1] = (int32_t)(xy_sum[1] /samples_64t) ;
				xy_bar[2] = (int32_t)(xy_sum[2] /samples_64t) ;
			
				x_bar = (int16_t)(x_sum/samples_32t);
			
				y_bar[0] = (int16_t)(y_sum[0]/samples_32t);
				y_bar[1] = (int16_t)(y_sum[1]/samples_32t);
				y_bar[2] = (int16_t)(y_sum[2]/samples_32t);
			
				xx_bar_minus_x_bar_x_bar = (int64_t)(((int64_t)xx_bar) - ((int64_t)x_bar)*((int64_t)x_bar)) ;
			
				// prevent division by 0, also, in theory xx_bar_minus_x_bar_x_bar must be positive
				if (xx_bar_minus_x_bar_x_bar <= ((int64_t)0)) xx_bar_minus_x_bar_x_bar = 1 ;
			
				offset_left[0] = (int16_t) ((
					((int64_t)y_bar[0])*((int64_t)xx_bar)
					-((int64_t)x_bar)*((int64_t)xy_bar[0])		
					)/xx_bar_minus_x_bar_x_bar );
			
				offset_left[1] = (int16_t) ((
					((int64_t)y_bar[1])*((int64_t)xx_bar)
					-((int64_t)x_bar)*((int64_t)xy_bar[1])		
					)/xx_bar_minus_x_bar_x_bar );
			
				offset_left[2] = (int16_t) ((
					((int64_t)y_bar[2])*((int64_t)xx_bar)
					-((int64_t)x_bar)*((int64_t)xy_bar[2])		
					)/xx_bar_minus_x_bar_x_bar );
			
				offset_right[0] = (int16_t)((
					
					((int64_t)y_bar[0])*(((int64_t)xx_bar)-(((int64_t)STEP_SIZE)*((int64_t)x_bar)))
					-
					((int64_t)xy_bar[0])*(((int64_t)x_bar)-((int64_t)STEP_SIZE))
					)/xx_bar_minus_x_bar_x_bar);
			
				offset_right[1] = (int16_t)((
					
					((int64_t)y_bar[1])*(((int64_t)xx_bar)-(((int64_t)STEP_SIZE)*((int64_t)x_bar)))
					-
					((int64_t)xy_bar[1])*(((int64_t)x_bar)-((int64_t)STEP_SIZE))
					)/xx_bar_minus_x_bar_x_bar);
			
				offset_right[2] = (int16_t)((
					
					((int64_t)y_bar[2])*(((int64_t)xx_bar)-(((int64_t)STEP_SIZE)*((int64_t)x_bar)))
					-
					((int64_t)xy_bar[2])*(((int64_t)x_bar)-((int64_t)STEP_SIZE))
					)/xx_bar_minus_x_bar_x_bar);
			}
			else
			{
				x_bar = 0 ;
				y_bar[0] = 0 ;
				y_bar[1] = 0 ;
				y_bar[2] = 0 ;
				xx_bar = 0 ;
				xy_bar[0] = 0 ;
				xy_bar[1] = 0 ;
				xy_bar[2] = 0 ;
				xx_bar_minus_x_bar_x_bar = 0 ;
				offset_left[0] = 0 ;
				offset_left[1] = 0 ;
				offset_left[2] = 0 ;
				offset_right[0] = 0 ;
				offset_right[1] = 0 ;
				offset_right[2] = 0 ;
			}
			if (initial_temp_reported == 1)
			{
#ifdef DEBUG_TABLE_BUILD
				serial_output("%i,%i,%li,%i,%i,%i,%i,%li,%li,%li,%li,%li,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n",
                    reported_temperature,
                    udb_cpu_load(),
					samples_32t,
					x_bar,
					y_bar[0],y_bar[1],y_bar[2],
					xx_bar,
					xy_bar[0], xy_bar[1],xy_bar[2],
					(int32_t)xx_bar_minus_x_bar_x_bar ,
					offset_left[0],offset_left[1],offset_left[2],
					offset_right[0],offset_right[1],offset_right[2],
					(offset_previous[0]+ offset_left[0])/2 ,
					(offset_previous[1]+ offset_left[1])/2 ,
					(offset_previous[2]+ offset_left[2])/2 ) ;
#else
				serial_output("{ %i , %i , %i } , \r\n",
					(offset_previous[0]+ offset_left[0])/2 ,
					(offset_previous[1]+ offset_left[1])/2 ,
					(offset_previous[2]+ offset_left[2])/2 ) ;	
		

#endif // 	DEBUG_TABLE_BUILD
                offset_previous[0] = offset_right[0] ;
				offset_previous[1] = offset_right[1] ;
				offset_previous[2] = offset_right[2] ;
			}
			else
			{
				initial_temp_reported = 1 ;
#ifdef DEBUG_TABLE_BUILD
				serial_output("initial temperature = %i\r\n%i,%i,%li,%i,%i,%i,%i,%li,%li,%li,%li,%li,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n",
					initial_temperature ,
                    reported_temperature ,
					udb_cpu_load(),
					samples_32t,
					x_bar,
					y_bar[0],y_bar[1],y_bar[2],
					xx_bar,
					xy_bar[0], xy_bar[1],xy_bar[2],
					(int32_t)xx_bar_minus_x_bar_x_bar ,
					offset_left[0],offset_left[1],offset_left[2],
					offset_right[0],offset_right[1],offset_right[2],
					offset_left[0],offset_left[1],offset_left[2]);
#else
				serial_output("initial temperature = %i\r\n{ %i , %i , %i } , \r\n",
					initial_temperature ,
					offset_left[0],offset_left[1],offset_left[2]	
						);
#endif // DEBUG_TABLE_BUILD
				offset_previous[0] = offset_right[0] ;
				offset_previous[1] = offset_right[1] ;
				offset_previous[2] = offset_right[2] ;
			}
			
			samples_32t = 0 ;
			xx_sum = 0 ;
			x_sum = 0 ;
			xy_sum[0] = 0 ;
			xy_sum[1] = 0 ;
			xy_sum[2] = 0 ;
			y_sum[0] = 0 ;
			y_sum[1] = 0 ;
			y_sum[2] = 0 ;
		}
	}		
}
int32_t acc_sum[] = { 0 , 0 , 0 } ;
int16_t acc_prev[] = { 0 , 0 , 0 } ;
int16_t acc_base[3] ;
int16_t acc_off_entry[3] ;
int32_t gyro_value_sum[] = { 0 , 0 , 0 } ;
int16_t gyro_value_bar[] = { 0 , 0 , 0 } ;
int16_t gyro_value_prev[] = { 0 , 0 , 0 } ;
int16_t gyro_value_entry[] = { 0 , 0 , 0 } ;
int32_t gyro_offset_sum[] = { 0 , 0 , 0 } ;
int16_t gyro_offset_bar[] = { 0 , 0 , 0 } ;
int16_t gyro_offset_prev[] = { 0 , 0 , 0 } ;
extern uint16_t omega_magnitude ;

void update_offset_table_gyros_and_accelerometers(void)
{
	reported_temperature = mpu_temp.value ;
	if ( initial_temp_recorded == 0 )
	{
		initial_temperature = reported_temperature ;
        acc_base[0] = udb_xaccel.value ;
        acc_base[1] = udb_yaccel.value ;
        acc_base[2] = udb_zaccel.value ;
		temperature_offset = initial_temperature ;
		initial_temp_recorded = 1 ;
		LED_RED = LED_ON ;
		LED_GREEN = LED_OFF ;
	}
	adjusted_temperature = reported_temperature - temperature_offset ;
	{
        
        gyro_value_entry[0]= 64*udb_xrate.value ;
		gyro_value_entry[1]= 64*udb_yrate.value ;
		gyro_value_entry[2]= 64*udb_zrate.value ;

        
		gyro_offset_entry[0]= gyro_offset[0] ;
		gyro_offset_entry[1]= gyro_offset[1] ;
		gyro_offset_entry[2]= gyro_offset[2] ;
     
        acc_off_entry[0]= (udb_xaccel.value-acc_base[0]) ;
		acc_off_entry[1]= (udb_yaccel.value-acc_base[1]) ;
		acc_off_entry[2]= (udb_zaccel.value-acc_base[2]) ;
    		
		gyro_offset_sum[0] += (int32_t ) gyro_offset_entry[0] ;
		gyro_offset_sum[1] += (int32_t ) gyro_offset_entry[1] ;
		gyro_offset_sum[2] += (int32_t ) gyro_offset_entry[2] ;

		gyro_value_sum[0] += (int32_t ) gyro_value_entry[0] ;
		gyro_value_sum[1] += (int32_t ) gyro_value_entry[1] ;
		gyro_value_sum[2] += (int32_t ) gyro_value_entry[2] ;
        
        acc_sum[0] += (int32_t ) acc_off_entry[0] ;
	    acc_sum[1] += (int32_t ) acc_off_entry[1] ;
	    acc_sum[2] += (int32_t ) acc_off_entry[2] ;
		
		samples_32t ++ ;
		
		if ( adjusted_temperature >= STEP_SIZE )
		{
			udb_led_toggle(LED_GREEN);
			udb_led_toggle(LED_RED);
			temperature_offset += STEP_SIZE ;
			samples_64t = (int64_t)samples_32t ;
			if (samples_32t>0)
			{
				gyro_value_bar[0] = (int16_t)(gyro_value_sum[0]/samples_32t);
				gyro_value_bar[1] = (int16_t)(gyro_value_sum[1]/samples_32t);
				gyro_value_bar[2] = (int16_t)(gyro_value_sum[2]/samples_32t);
 
                gyro_offset_bar[0] = (int16_t)(gyro_offset_sum[0]/samples_32t);
				gyro_offset_bar[1] = (int16_t)(gyro_offset_sum[1]/samples_32t);
				gyro_offset_bar[2] = (int16_t)(gyro_offset_sum[2]/samples_32t);
 
                acc_off_entry[0]= (int16_t)(acc_sum[0]/samples_32t);
                acc_off_entry[1]= (int16_t)(acc_sum[1]/samples_32t);
                acc_off_entry[2]= (int16_t)(acc_sum[2]/samples_32t);
               
			}
			else
			{
				gyro_value_bar[0] = 0 ;
				gyro_value_bar[1] = 0 ;
				gyro_value_bar[2] = 0 ;
                
                gyro_offset_bar[0] = 0;
				gyro_offset_bar[1] = 0;
				gyro_offset_bar[2] = 0;             
                
                acc_off_entry[0]= 0;
                acc_off_entry[1]= 0;
                acc_off_entry[2]= 0;
			}
			if (initial_temp_reported == 1)
			{               
				serial_output("%i,%i,%li,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n",
                    reported_temperature,
                    udb_cpu_load(),
					samples_32t,
                     omega_magnitude ,
					(gyro_offset_prev[0]+ gyro_offset_bar[0])/2 ,
					(gyro_offset_prev[1]+ gyro_offset_bar[1])/2 ,
					(gyro_offset_prev[2]+ gyro_offset_bar[2])/2 ,
                        
 					(gyro_value_prev[0]+ gyro_value_bar[0])/2 ,
  					(gyro_value_prev[1]+ gyro_value_bar[1])/2 ,
 					(gyro_value_prev[2]+ gyro_value_bar[2])/2 ,
                       
                    (acc_prev[0]+ acc_off_entry[0])/2 , 
                    (acc_prev[1]+ acc_off_entry[1])/2 , 
                    (acc_prev[2]+ acc_off_entry[2])/2                
                        ) ;	

                gyro_value_prev[0] = gyro_value_bar[0] ;
				gyro_value_prev[1] = gyro_value_bar[1] ;
				gyro_value_prev[2] = gyro_value_bar[2] ;
                
                gyro_offset_prev[0] = gyro_offset_bar[0];              
                gyro_offset_prev[1] = gyro_offset_bar[1];              
                gyro_offset_prev[2] = gyro_offset_bar[2];              
                
                acc_prev[0] = acc_off_entry[0] ;
                acc_prev[1] = acc_off_entry[1] ;
                acc_prev[2] = acc_off_entry[2] ;
                
			}
			else
			{
				initial_temp_reported = 1 ;
                
                serial_output("\r\ninitial temperature = %i\r\n", initial_temperature);
                serial_output("\r\ntmptr,cpu,smpls,gyro_mag,gyro_off_x,gyro_off_y,gyro_off_z,gyro_raw_x,gyro_raw_y,gyro_raw_z,acc_x,acc_y,acc_z\r\n");
                serial_output("%i,%i,%li,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i\r\n",   
                    reported_temperature,
                    udb_cpu_load(),
					samples_32t,
                    omega_magnitude ,
                        
					gyro_offset_bar[0],
                    gyro_offset_bar[1],
                    gyro_offset_bar[2],
                        
 					gyro_value_bar[0] ,
  					gyro_value_bar[1] ,
 					gyro_value_bar[2] ,
                       
                    acc_off_entry[0] ,
                    acc_off_entry[1] ,
                    acc_off_entry[2]                 
                        ) ;	

                gyro_value_prev[0] = gyro_value_bar[0] ;
				gyro_value_prev[1] = gyro_value_bar[1] ;
				gyro_value_prev[2] = gyro_value_bar[2] ;
                
                gyro_offset_prev[0] = gyro_offset_bar[0];              
                gyro_offset_prev[1] = gyro_offset_bar[1];              
                gyro_offset_prev[2] = gyro_offset_bar[2];              
                
                acc_prev[0] = acc_off_entry[0] ;
                acc_prev[1] = acc_off_entry[1] ;
                acc_prev[2] = acc_off_entry[2] ;
                
			}	
			samples_32t = 0 ;
            
			gyro_offset_sum[0] = 0 ;
			gyro_offset_sum[1] = 0 ;
			gyro_offset_sum[2] = 0 ;
            
            gyro_value_sum[0] = 0 ;
            gyro_value_sum[1] = 0 ;
            gyro_value_sum[2] = 0 ;
                     
            acc_sum[0] = 0 ;
            acc_sum[1] = 0 ;
            acc_sum[2] = 0 ;      
		}
	}		
}
