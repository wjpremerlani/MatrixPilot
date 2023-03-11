

//#include "libUDB.h"
//#include "oscillator.h"
//#include "interrupt.h"
//#include "heartbeat.h"
#include "../libUDB/udbTypes.h"


int32_t fract_32_mpy( int32_t arg1 , int32_t arg2 )
{
	union longww result ;
	union longww x,y;
	x.WW = arg1 ;
	y.WW = arg2 ;
	int16_t sign = 1 ;
	if ( x.WW < 0 )
	{
		sign = - sign ;
		x.WW = - (x.WW ) ;
	}
	if ( y.WW < 0)
	{
		sign = - sign ;
		y.WW = - (y.WW ) ;
	}
	
	result.WW = __builtin_muluu( x._.W1 , y._.W1 )
			+  (__builtin_muluu( x._.W1 , y._.W0 )>>16 )
			+  (__builtin_muluu( x._.W0 , y._.W1 )>>16 ) ;
	
	if ( sign < 0)
	{
		result.WW = - ( result.WW ) ;
	}
	return result.WW ;
}

int32_t dot_fract_32( int32_t row[], int32_t col[], int16_t row_index , int16_t col_index )
{
	return fract_32_mpy(row[row_index],col[col_index])
			+fract_32_mpy(row[row_index+1],col[col_index+3])
			+fract_32_mpy(row[row_index+2],col[col_index+6]) ;
}

void matrix_mpy_fract_32( int32_t dest[] , int32_t arg1[] , int32_t arg2[] )
{
	dest[0] = dot_fract_32(arg1,arg2,0,0);
	dest[1] = dot_fract_32(arg1,arg2,0,1);
	dest[2] = dot_fract_32(arg1,arg2,0,2);
	dest[3] = dot_fract_32(arg1,arg2,3,0);
	dest[4] = dot_fract_32(arg1,arg2,3,1);
	dest[5] = dot_fract_32(arg1,arg2,3,2);
	dest[6] = dot_fract_32(arg1,arg2,6,0);
	dest[7] = dot_fract_32(arg1,arg2,6,1);
	dest[8] = dot_fract_32(arg1,arg2,6,2);
}

