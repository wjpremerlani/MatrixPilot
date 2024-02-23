

#ifndef options_LUGE7_SN104_H
#define	options_LUGE7_SN104_H

#define CUSTOM_OFFSETS
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn104.h"
//#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_no_compensation.h"
#define CALIBRATIONX	1.0167
#define CALIBRATIONY	1.0175
#define CALIBRATIONZ	1.0184
#if (ACCEL_RANGE == 8)
#define XACCEL_OFFSET	( 12 )
#define YACCEL_OFFSET	( -50 )
#define ZACCEL_OFFSET	( -28 )
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4109
#define CAL_GRAV_Y	4101
#define CAL_GRAV_Z	4083
#endif // ACCEL_RANGE == 8 

#if (ACCEL_RANGE == 2)
// temperature range 905 to 2381
#define XACCEL_OFFSET	( 8 )
#define YACCEL_OFFSET	( -142 )
#define ZACCEL_OFFSET	( -78 )
#define CALIB_GRAVITY	16384
#define CAL_GRAV_X	16432
#define CAL_GRAV_Y	16405
#define CAL_GRAV_Z	16385
#endif // ACCEL_RANGE == 2 

// cross coupling not measured yet
#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN104_H */

