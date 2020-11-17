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
int16_t estimatedWind_unfiltered[2] = { 0, 0 };
union longww estimatedWind_filtered[2]= { {0}, {0} };

uint32_t previous_energy = 0 ;
uint32_t present_energy = 0 ;

int16_t vertical_wind(void)
{
	return IMUvelocityz._.W1 - __builtin_divsd ( __builtin_mulsu(-rmat[7],air_speed_3DIMU),RMAX ) ;
}

int16_t total_speed_update(void)
{
	int32_t total_speed_32 ;
	present_energy = air_speed_3DIMU_sqr ;
	total_speed_32 = present_energy - previous_energy ;
	previous_energy = present_energy ;
	total_speed_32 = total_speed_32 / (GRAVITY_TIMES_2/UPDATE_RATE) ;
	total_speed_32 += IMUvelocityz._.W1 ;
	return (int16_t) total_speed_32 ;
}

#if (WIND_ESTIMATION == 1)

int8_t thetaDiff_log ;
uint16_t estimatedAirspeed_log ;

#define MINROTATION ((int16_t)(0.2 * RMAX))
#define MAX_AGE 20 // maximum delay between computations

uint16_t estWindAge = 0 ;
uint16_t estWindAge_log ;

static int16_t groundVelocityHistory[3] = { 0, 0, 0 };
static int16_t fuselageDirectionHistory[3] = { 0, 0, 0 };
static uint16_t airspeed_history = 0;

void estWind(int16_t angleOfAttack)
{
	int16_t index;
	int16_t groundVelocity[3];
	int16_t groundVelocitySum[3];
	int16_t groundVelocityDiff[3];
	int16_t fuselageDirection[3];
//	int16_t fuselageDirectionSum[3];
	int16_t fuselageDirectionDiff[3];
	uint16_t magVelocityDiff;
	uint16_t magDirectionDiff;
	int8_t angleVelocityDiff;
	int8_t angleDirectionDiff;
	int8_t thetaDiff;
	int16_t costhetaDiff;
	int16_t sinthetaDiff;
	union longww longaccum;
	struct relative2D xy;
	uint16_t estimatedAirspeed;
	int16_t Vx1, Vx2, Vy1, Vy2 , Vxsum , Vysum ;

	if (dcm_flags._.skip_yaw_drift) return;
	
	fuselageDirection[0] = -rmat[1];
	fuselageDirection[1] =  rmat[4];
	//fuselageDirection[2] = -rmat[7];
	fuselageDirection[2] = 0 ;
	// adjust "fuselage direction" for angle of attack
	longaccum.WW = (__builtin_mulss(- rmat[2], angleOfAttack)) << 2;
	fuselageDirection[0] += longaccum._.W1;
	longaccum.WW = (__builtin_mulss(  rmat[5], angleOfAttack)) << 2;
	fuselageDirection[1] += longaccum._.W1;
	longaccum.WW = (__builtin_mulss(- rmat[8], angleOfAttack)) << 2;
	//fuselageDirection[2] += longaccum._.W1;
	
	groundVelocity[0] = IMUvelocityx._.W1 ;
	groundVelocity[1] = IMUvelocityy._.W1 ;
	groundVelocity[2] = 0 ; // Z velocity is computed separately
	
	for (index = 0; index < 3; index++)
	{
		groundVelocityDiff[index] = (groundVelocity[index] - groundVelocityHistory[index])>>1;
		groundVelocitySum[index] = (groundVelocity[index] + groundVelocityHistory[index])>>1;
		fuselageDirectionDiff[index] = (fuselageDirection[index] - fuselageDirectionHistory[index])>>1;
	}
	
	magDirectionDiff = vector3_mag(fuselageDirectionDiff[0],
	                               fuselageDirectionDiff[1],
	                               fuselageDirectionDiff[2]);
	
	magVelocityDiff = vector3_mag(groundVelocityDiff[0],
	                              groundVelocityDiff[1],
	                              groundVelocityDiff[2]);
	
	if ( estWindAge > MAX_AGE )
	{
		estWindAge = 0 ;
		for (index = 0; index < 3; index++)
		{
			groundVelocityHistory[index] = groundVelocity[index];
			fuselageDirectionHistory[index] = fuselageDirection[index];
		}
		return ;
	}

	if (magDirectionDiff > MINROTATION)
	{

#if ((HILSIM == 1)&&(USE_PITOT==1))
		estimatedAirspeed = hilsim_airspeed.BB; // use the simulation as a pitot tube
		estimatedAirspeed_log = estimatedAirspeed ;
#else
		estimatedAirspeed = __builtin_divud(longaccum.WW, magDirectionDiff);
		estimatedAirspeed_log = estimatedAirspeed ;
		
#endif
		Vx2 = __builtin_divsd( __builtin_mulus(estimatedAirspeed,fuselageDirection[0]),RMAX)>>1 ;
		Vx1 = __builtin_divsd( __builtin_mulus(airspeed_history,fuselageDirectionHistory[0]),RMAX)>>1;
		Vy2 = __builtin_divsd( __builtin_mulus(estimatedAirspeed,fuselageDirection[1]),RMAX)>>1 ;
		Vy1 = __builtin_divsd( __builtin_mulus(airspeed_history,fuselageDirectionHistory[1]),RMAX)>>1;
		Vxsum = Vx1 + Vx2 ;
		Vysum = Vy1 + Vy2 ;
		xy.x = (Vx2-Vx1) ;
		xy.y = (Vy2-Vy1) ;
		angleDirectionDiff = rect_to_polar(&xy);

		xy.x = groundVelocityDiff[0];
		xy.y = groundVelocityDiff[1];
		angleVelocityDiff = rect_to_polar(&xy);

		thetaDiff = angleVelocityDiff - angleDirectionDiff;
		costhetaDiff = cosine(thetaDiff);
		sinthetaDiff = sine(thetaDiff);

		estWindAge_log = estWindAge ;
		estWindAge = 0 ;
		thetaDiff_log = thetaDiff ;
	
		
		estimatedWind_unfiltered[0] = estimatedWind_unfiltered[0] + 
		    ((groundVelocitySum[0]  
				- (__builtin_divsd ( __builtin_mulss( costhetaDiff , Vxsum),RMAX))
				+ (__builtin_divsd ( __builtin_mulss( sinthetaDiff , Vysum),RMAX))
				- estimatedWind_unfiltered[0]) >> 4);

		estimatedWind_unfiltered[1] = estimatedWind_unfiltered[1] + 
		    ((groundVelocitySum[1]  
				- (__builtin_divsd ( __builtin_mulss( sinthetaDiff , Vxsum),RMAX))
				- (__builtin_divsd ( __builtin_mulss( costhetaDiff , Vysum),RMAX))
				- estimatedWind_unfiltered[1]) >> 4);
		
		estimatedWind_unfiltered[2] = 0 ;

		for (index = 0; index < 3; index++)
		{
			groundVelocityHistory[index] = groundVelocity[index];
			fuselageDirectionHistory[index] = fuselageDirection[index];
			airspeed_history = estimatedAirspeed ;
		}
	}
	else
	{
		estWindAge++ ;
	}
}
#endif //estimate wind

#if ((WIND_ESTIMATION == 1))
void filterWind()
{
	int16_t index ;
	union longww filter_input[2];
	// expected to execute at 40 Hz
	for (index = 0; index < 2 ; index++)
	{
		filter_input[index]._.W1= estimatedWind_unfiltered[index] ;
		filter_input[index]._.W0= 0 ;
		estimatedWind_filtered[index].WW = estimatedWind_filtered[index].WW +
		((filter_input[index].WW - estimatedWind_filtered[index].WW)>>7) ; // time constant (2^7)/40 = 3.2 seconds
		estimatedWind[index] = estimatedWind_filtered[index]._.W1 ;
	}	
}
#endif


#if(!(WIND_ESTIMATION == 1))

void estWind(int16_t angleOfAttack)
{
}
void filterWind(void)
{
	
}
#endif

