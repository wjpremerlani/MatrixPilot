

#define CAM_VIEW_LAUNCH         { 0, 0, 0 }


const struct waypointDef waypoints[] = {
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -66, 182, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 155, 20, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 96, -66, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -67, 182, 75 } , 10 , 0 , F_NORMAL  , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 155, 20, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 94, -65, 30 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 0, 0, 3 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { -125, 105, -5 } , 0 , 0 , F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
};



const struct waypointDef rtlWaypoints[] = {
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -66, 182, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 155, 20, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 96, -66, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -67, 182, 75 } , 10 , 0 , F_NORMAL  , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 155, 20, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 94, -65, 30 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 0, 0, 3 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { -125, 105, -5 } , 0 , 0 , F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
};