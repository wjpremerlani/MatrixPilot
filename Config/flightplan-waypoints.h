

#define CAM_VIEW_LAUNCH         { 0, 0, 0 }

#define TRACK_OPTION 0

const struct waypointDef waypoints[] = {
	{ { 0, 4, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -6, 170, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { 94, 173, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 104, -134, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 3, -135, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { -5, 170, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { 94, 173, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { 104, -133, 25 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 3, -138, 25 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 0, -7, 25 } , 0 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { -8, 257, 25 } , 10 , 0 , F_NORMAL + F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
};


const struct waypointDef rtlWaypoints[] = {
	{ { 0, 4, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -6, 170, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { 94, 173, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 104, -134, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 3, -135, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { -5, 170, 50 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { 94, 173, 50 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { 104, -133, 25 } , 10 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 3, -138, 25 } , 10 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 0, -7, 25 } , 0 , 0 , F_NORMAL + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { -8, 257, 25 } , 10 , 0 , F_NORMAL + F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
};

