

#define CAM_VIEW_LAUNCH         { 0, 0, 0 }


const struct waypointDef waypoints[] = {
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -66, 182, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 155, 20, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 165, -52, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { 96, -66, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { -67, 182, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 155, 20, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 165, -52, 35 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { 94, -65, 20 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 12
	{ { -5, 3, 5 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 13
	{ { -125, 105, -10 } , 0 , 0 , F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 14
};



const struct waypointDef rtlWaypoints[] = {
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -66, 182, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 155, 20, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 165, -52, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { 96, -66, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { 0, 0, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -125, 105, 75 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { -67, 182, 75 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 155, 20, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 165, -52, 35 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { 94, -65, 20 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 12
	{ { -5, 3, 5 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 13
	{ { -125, 105, -10 } , 0 , 0 , F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 14
};

