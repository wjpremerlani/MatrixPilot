
#ifndef options_LUGE7_SN080_H
#define	options_LUGE7_SN080_H

#define CUSTOM_OFFSETS
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn080.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134
#if (ACCEL_RANGE == 8)
#define XACCEL_OFFSET	( 29 )
#define YACCEL_OFFSET	( 0 )
#define ZACCEL_OFFSET	( -45 )
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4106
#define CAL_GRAV_Y	4099
#define CAL_GRAV_Z	4101
#endif // ACCEL_RANGE == 8

#if (ACCEL_RANGE == 2)
#define XACCEL_OFFSET	( 127 )
#define YACCEL_OFFSET	( -24 )
#define ZACCEL_OFFSET	( -219 )
#define CALIB_GRAVITY	16384
#define CAL_GRAV_X	16430
#define CAL_GRAV_Y	16404
#define CAL_GRAV_Z	16373
#endif // ACCEL_RANGE == 2

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN080_H */

