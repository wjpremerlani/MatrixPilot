

#ifndef options_LUGE7_SN050_H
#define	options_LUGE7_SN050_H

#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 27 )
#define YACCEL_OFFSET	( -61 )
#define ZACCEL_OFFSET	( -30 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn050.h"
#define CALIBRATIONX	1.0132
#define CALIBRATIONY	1.0184
#define CALIBRATIONZ	1.0129
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4108
#define CAL_GRAV_Y	4106
#define CAL_GRAV_Z	4075

// cross coupling not measured yet
#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN050_H */

