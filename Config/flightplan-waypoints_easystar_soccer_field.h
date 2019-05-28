

#define CAM_VIEW_LAUNCH         { 0, 0, 0 }


const struct waypointDef waypoints[] = {
	{ { 0, 0, 50 } , 20 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -124, 107, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -103, 144, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 92, -3, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 66, -59, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { 0, 0, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { -124, 107, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -103, 144, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 92, -3, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 66, -59, 25 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 0, 0, 5 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { -124, 107, -5 } , 20 , 0 , F_LAND + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
};



const struct waypointDef rtlWaypoints[] = {
	{ { 0, 0, 50 } , 20 , 0 , F_NORMAL , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -124, 107, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -103, 144, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { 92, -3, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { 66, -59, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { 0, 0, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { -124, 107, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -103, 144, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { 92, -3, 50 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { 66, -59, 25 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { 0, 0, 5 } , 20 , 0 , F_NORMAL + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { -124, 107, -5 } , 20 , 0 , F_LAND + F_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
};
