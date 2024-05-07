
#ifndef options_LUGE7_SN082_H
#define	options_LUGE7_SN082_H

#define CUSTOM_OFFSETS

#if (ACCEL_RANGE == 8 )

#define XACCEL_OFFSET	( -9 )
#define YACCEL_OFFSET	( -33 )
#define ZACCEL_OFFSET	( 84 )
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4109
#define CAL_GRAV_Y	4102
#define CAL_GRAV_Z	4099
#endif // (ACCEL_RANGE == 8 )

#if (ACCEL_RANGE == 2 )

#define CALIB_GRAVITY	16384
#define CAL_GRAV_X	16384
#define CAL_GRAV_Y	16384
#define CAL_GRAV_Z	16384
#endif // (ACCEL_RANGE == 2 )


#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn082.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN082_H */

