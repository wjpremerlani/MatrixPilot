
#ifndef options_LUGE7_SN085_H
#define	options_LUGE7_SN085_H

#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn085.h"

//#define CUSTOM_OFFSETS
//#define XACCEL_OFFSET	( 0 )
//#define YACCEL_OFFSET	( -29 )
//#define ZACCEL_OFFSET	( 3 )

#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134

#if (ACCEL_RANGE == 8 )
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4104
#define CAL_GRAV_Y	4104
#define CAL_GRAV_Z	4072
#elif (ACCEL_RANGE == 16 )
#define CALIB_GRAVITY	2048
#define CAL_GRAV_X	2048
#define CAL_GRAV_Y	2048
#define CAL_GRAV_Z	2048
#endif // ACCEL_RANGE

#endif	/* options_LUGE7_SN085_H */

