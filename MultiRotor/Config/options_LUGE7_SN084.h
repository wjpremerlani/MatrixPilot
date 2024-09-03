
#ifndef options_LUGE7_SN084_H
#define	options_LUGE7_SN084_H

#define CUSTOM_OFFSETS

#if (ACCEL_RANGE == 8)
#define XACCEL_OFFSET	( 21 )
#define YACCEL_OFFSET	( -25 )
#define ZACCEL_OFFSET	( 17 )
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4102
#define CAL_GRAV_Y	4102
#define CAL_GRAV_Z	4099
#endif // (ACCEL_RANGE == 8)

#if (ACCEL_RANGE == 4)
#define CALIB_GRAVITY	8192
#define CAL_GRAV_X	8207
#define CAL_GRAV_Y	8212
#define CAL_GRAV_Z	8150
#endif // (ACCEL_RANGE == 4) 

//8207. 8212. 8150.


    
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn084.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134



#endif	/* options_LUGE7_SN084_H */

