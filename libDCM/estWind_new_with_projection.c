// This file is part of MatrixPilot.
//
//    http://code.google.com/p/gentlenav/
//
// Copyright 2009-2011 MatrixPilot Team
// See the AUTHORS.TXT file for a list of authors of MatrixPilot.
//
// MatrixPilot is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MatrixPilot is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with MatrixPilot.  If not, see <http://www.gnu.org/licenses/>.


#include "libDCM.h"
#include "mathlibNAV.h"
#include "gpsData.h"
#include "estWind.h"
#include "rmat.h"
#include ".\..\libDCM\deadReckoning.h"

#define GRAVITY_TIMES_2 (1961)  // cm/sec/sec
#define UPDATE_RATE (4)  // 4 updates per second


int16_t estimatedWind[3] = { 0, 0, 0 };

uint32_t previous_energy = 0 ;
uint32_t present_energy = 0 ;

int16_t VectorDot_3(int16_t * vector1 , int16_t * vector2) 
{
	union longww dot_accum;
	dot_accum.WW = __builtin_mulss( vector1[0] , vector2[0]);
	dot_accum.WW += __builtin_mulss( vector1[1] , vector2[1]);
	dot_accum.WW += __builtin_mulss( vector1[2] , vector2[2]);
	dot_accum.WW *= 4;
	return dot_accum._.W1 ;
}

int16_t total_speed_update(void)
{
	int32_t total_speed_32 ;
	present_energy = __builtin_muluu ( air_speed_3DIMU  , air_speed_3DIMU ) ;
	total_speed_32 = present_energy - previous_energy ;
	previous_energy = present_energy ;
	total_speed_32 = total_speed_32 / (GRAVITY_TIMES_2/UPDATE_RATE) ;
	total_speed_32 += IMUvelocityz._.W1 ;
	return (int16_t) total_speed_32 ;
}

#if (WIND_ESTIMATION == 1)

static int16_t groundVelocityHistory[3] = { 0, 0, 0 };
static int16_t fuselageDirectionHistory[3] = { 0, RMAX , 0 };

#define MINROTATION ((int16_t)(0.1 * RMAX))


int16_t airspeed_numerator ;
uint16_t airspeed_denominator ;
uint16_t airspeed_2 ;

void estWind(int16_t angleOfAttack)
{
	int16_t index;
	int16_t groundVelocity[3];
	int16_t groundVelocityDiff[3];
	int16_t fuselageDirection[3];
	int16_t f2_cross_f1[3] ;
	int16_t f1_cross_f2_cross_f1[3];
	uint16_t magf2_cross_f1 ;
	int16_t wind_update[3] ;
	int16_t wind_update_cross_f2_cross_f1[3] ;
	union longww longaccum;


	if (dcm_flags._.skip_yaw_drift) return;

	groundVelocity[0] = IMUvelocityx._.W1;
	groundVelocity[1] = IMUvelocityy._.W1;
	groundVelocity[2] = IMUvelocityz._.W1;

	fuselageDirection[0] = -rmat[1];
	fuselageDirection[1] =  rmat[4];
	fuselageDirection[2] = -rmat[7];

	// adjust "fuselage direction" for angle of attack
	longaccum.WW = (__builtin_mulss(- rmat[2], angleOfAttack)) << 2;
	fuselageDirection[0] += longaccum._.W1;
	longaccum.WW = (__builtin_mulss(  rmat[5], angleOfAttack)) << 2;
	fuselageDirection[1] += longaccum._.W1;
	longaccum.WW = (__builtin_mulss(- rmat[8], angleOfAttack)) << 2;
	fuselageDirection[2] += longaccum._.W1;

	// compute the cross product of the latest fuselage vector with the previous one
	VectorCross( f2_cross_f1 , fuselageDirection , fuselageDirectionHistory ) ;
	// normalize f2 cross f1 and capture its magnitude
	magf2_cross_f1 = vector3_normalize( f2_cross_f1 , f2_cross_f1 ) ;
	
	if (magf2_cross_f1 > MINROTATION)
	{
		// compute the change in IMU velocity
		for (index = 0; index < 3; index++)
		{
			groundVelocityDiff[index] = groundVelocity[index] - groundVelocityHistory[index];	
		}
		// compute ( f1 cross ( f2 cross f1 ) )
		VectorCross ( f1_cross_f2_cross_f1 , fuselageDirectionHistory , f2_cross_f1 ) ;
		// compute numerator and denominator of expression for estimated airspeed 
		airspeed_numerator = VectorDot_3( groundVelocityDiff , f1_cross_f2_cross_f1 ) ;
		if ( airspeed_numerator < 0 ) airspeed_numerator = 0 ;
		airspeed_denominator = magf2_cross_f1 ;
		
		airspeed_2 = __builtin_divud( __builtin_muluu( RMAX , airspeed_numerator ) , airspeed_denominator ) ;
		
		for (index = 0; index < 3; index++)
		{
			wind_update[index] = groundVelocity[index] 
					- __builtin_divsd( __builtin_mulsu ( fuselageDirection[index], airspeed_2 ), RMAX ) 
					- estimatedWind[index] ;
		}
		
		// project the update onto plane containing f1 and f2
		// by computing n cross ( wind_update cross n) where n is unit vector parallel to f2 cross f1
		// n cross ( x cross n ) = x - n (n dot x) is in a plane perpendicular to n
		VectorCross( wind_update_cross_f2_cross_f1 , wind_update , f2_cross_f1 ) ;
		VectorCross( wind_update , f2_cross_f1 , wind_update_cross_f2_cross_f1 ) ;
			
		for (index = 0; index < 3; index++)
		{
			estimatedWind[index] = estimatedWind[index] + (wind_update[index]>>4) ;
			groundVelocityHistory[index] = groundVelocity[index];
			fuselageDirectionHistory[index] = fuselageDirection[index];
		}	
	}
}

#else

void estWind(int16_t angleOfAttack)
{
}

#endif // WIND_ESTIMATION
