
#ifndef options_LUGE7_SN128_H
#define	options_LUGE7_SN128_H

#define CUSTOM_OFFSETS
//#define XACCEL_OFFSET	( 2 )
//#define YACCEL_OFFSET	( -58 )
//#define ZACCEL_OFFSET	( 47 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn128.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4109
#define CAL_GRAV_Y	4110
#define CAL_GRAV_Z	4076

//#define X_CROSS_COUPLING 16
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN128_H */

