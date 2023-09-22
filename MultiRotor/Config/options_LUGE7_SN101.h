

#ifndef options_LUGE7_SN101_H
#define	options_LUGE7_SN101_H

#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 9 )
#define YACCEL_OFFSET	( -29 )
#define ZACCEL_OFFSET	( 3 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn101.h"
#define CALIBRATIONX	1.0098
#define CALIBRATIONY	1.0090
#define CALIBRATIONZ	1.0098
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4105
#define CAL_GRAV_Y	4101
#define CAL_GRAV_Z	4077

// cross coupling not measured yet
#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN101_H */

