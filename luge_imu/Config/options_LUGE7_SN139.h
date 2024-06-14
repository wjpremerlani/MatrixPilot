
#ifndef options_LUGE7_SN139_H
#define	options_LUGE7_SN139_H

#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( -2 )
#define YACCEL_OFFSET	( -48 )
#define ZACCEL_OFFSET	( -14 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_luge7_sn139.h"
#define CALIBRATIONX	1.0134
#define CALIBRATIONY	1.0134
#define CALIBRATIONZ	1.0134
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4102
#define CAL_GRAV_Y	4101
#define CAL_GRAV_Z	4094

#error "very large cross coupling"

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

#endif	/* options_LUGE7_SN139_H */

