

#ifndef TABLE_LUGE7_SN102_H
#define	TABLE_LUGE7_SN102_H

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( 0 )

//#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	0	,	0	,	0	},
{	0	,	0	,	0	},
{	0	,	0	,	0	}
};

#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( 0 )

int16_t accel_residual_offset[] = {0 , 0 , 0 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{0 , 0 , 0},
{0 , 0 , 0},
{0 , 0 , 0}
};

#endif	/* TABLE_LUGE7_SN102_H */

