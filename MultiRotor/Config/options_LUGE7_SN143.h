
#ifndef options_LUGE7_SN143_H
#define	options_LUGE7_SN143_H

#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( -7)
#define YACCEL_OFFSET	( -53 )
#define ZACCEL_OFFSET	( -60 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn143.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4103
#define CAL_GRAV_Y	4099
#define CAL_GRAV_Z	4075

// cross coupling was measured but results were not consistent

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN143_H */

