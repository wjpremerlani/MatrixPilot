
#ifndef options_LUGE7_SN081_H
#define	options_LUGE7_SN081_H

#define CUSTOM_OFFSETS
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn081.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134
#if (ACCEL_RANGE == 8)
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4102
#define CAL_GRAV_Y	4101
#define CAL_GRAV_Z	4109
#define XACCEL_OFFSET	( -17 )
#define YACCEL_OFFSET	( -1 )
#define ZACCEL_OFFSET	( -72 )
#endif // ACCEL_RANGE == 8
#if (ACCEL_RANGE == 4)
#define CALIB_GRAVITY	8192
#define CAL_GRAV_X	8207
#define CAL_GRAV_Y	8204
#define CAL_GRAV_Z	8197
#define XACCEL_OFFSET	( -29 )
#define YACCEL_OFFSET	( -22 )
#define ZACCEL_OFFSET	( -205 )
#endif // ACCEL_RANGE == 4
#if (ACCEL_RANGE == 2)
#define CALIB_GRAVITY	16384
#define CAL_GRAV_X	16418
#define CAL_GRAV_Y	16383
#define CAL_GRAV_Z	16403
#define XACCEL_OFFSET	( -69 )
#define YACCEL_OFFSET	( -29 )
#define ZACCEL_OFFSET	( -343 )
#endif // ACCEL_RANGE == 2

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN081_H */

