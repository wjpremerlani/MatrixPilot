
#ifndef options_LUGE7_SN136_H
#define	options_LUGE7_SN136_H

#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 15 )
#define YACCEL_OFFSET	( -56 )
#define ZACCEL_OFFSET	( 12 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn136.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4100
#define CAL_GRAV_Y	4100
#define CAL_GRAV_Z	4077

// cross coupling is diminimus

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN136_H */
