

#define CAM_VIEW_LAUNCH         { 0, 0, 0 }


const struct waypointDef waypoints[] = {
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -106, 78, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -128, 113, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { -121, 150, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { -92, 165, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { -48, 159, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { 155, 20, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { 175, -10, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 165, -52, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 137, -69, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 96, -66, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
	{ { -107, 78, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 13
	{ { -128, 113, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 14
	{ { -121, 150, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 15
	{ { -92, 165, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 16
	{ { -49, 158, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 17
	{ { 155, 20, 45 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 18
	{ { 175, -10, 37 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 19
	{ { 165, -52, 30 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 20
	{ { 137, -69, 25 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 21
	{ { 94, -65, 20 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 22
	{ { -5, 3, 10 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 23
	{ { -140, 97, -5 } , 0 , 0 , F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 24
};




const struct waypointDef rtlWaypoints[] = {
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -106, 78, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -128, 113, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { -121, 150, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { -92, 165, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { -48, 159, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { 155, 20, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { 175, -10, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 165, -52, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 137, -69, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 96, -66, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
	{ { -107, 78, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 13
	{ { -128, 113, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 14
	{ { -121, 150, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 15
	{ { -92, 165, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 16
	{ { -49, 158, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 17
	{ { 155, 20, 45 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 18
	{ { 175, -10, 37 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 19
	{ { 165, -52, 30 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 20
	{ { 137, -69, 25 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 21
	{ { 94, -65, 20 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 22
	{ { -5, 3, 10 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 23
	{ { -140, 97, -5 } , 0 , 0 , F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 24
};
