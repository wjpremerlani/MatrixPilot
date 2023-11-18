
#ifndef options_LUGE7_SN51_H
#define	options_LUGE7_SN51_H

#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 29 )
#define YACCEL_OFFSET	( -31 )
#define ZACCEL_OFFSET	( 15 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn051.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4110
#define CAL_GRAV_Y	4097
#define CAL_GRAV_Z	4068

// cross coupling not measured

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN51_H */
