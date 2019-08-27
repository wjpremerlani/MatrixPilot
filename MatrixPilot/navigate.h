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

#ifndef NAVIGATE_H
#define NAVIGATE_H


extern int16_t tofinish_line;
extern int8_t extended_range;
extern int8_t desired_dir;
extern uint16_t turngainfbw; // fly by wire turn gain
extern uint16_t turngainnav; // waypoints turn gain

void init_navigation(void);
void save_navigation(void);
#ifdef USE_EXTENDED_NAV
void navigate_set_goal(struct relative3D_32 fromPoint, struct relative3D_32 toPoint);
#else
void navigate_set_goal(struct relative3D fromPoint , struct relative3D toPoint);
#endif // USE_EXTENDED_NAV
void navigate_set_goal_height(int16_t z);
void navigate_compute_bearing_to_goal(void);
void navigate_process_flightplan(void);
int16_t navigate_determine_deflection(char navType);
union longww navigate_desired_height(void);

// NEW STUFF:
int16_t navigate_get_goal(vect3_16t* goal);

uint16_t wind_gain_adjustment(void);


#endif // NAVIGATE_H
