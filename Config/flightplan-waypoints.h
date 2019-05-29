

#define CAM_VIEW_LAUNCH         { 0, 0, 0 }

#define TRACK_OPTION 0

const struct waypointDef waypoints[] = {
	{ { -738042715, 427377643, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -738043896, 427412156, 50 } , 8 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -738018145, 427413101, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { -738010850, 427322321, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { -738041318, 427320667, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { -738042821, 427377642, 50 } , 8 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { -738044218, 427412318, 50 } , 8 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -738018146, 427413100, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { -738011172, 427321455, 25 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { -738041211, 427321928, 25 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { -738042661, 427377633, 5 } , 5 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { -738044003, 427412156, -20 } , 0 , 0 , F_ABSOLUTE + F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
};



const struct waypointDef rtlWaypoints[] = {
	{ { -738042715, 427377643, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 1
	{ { -738043896, 427412156, 50 } , 8 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 2
	{ { -738018145, 427413101, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 3
	{ { -738010850, 427322321, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 4
	{ { -738041318, 427320667, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 5
	{ { -738042821, 427377642, 50 } , 8 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 6
	{ { -738044218, 427412318, 50 } , 8 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 7
	{ { -738018146, 427413100, 50 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 8
	{ { -738011172, 427321455, 25 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 9
	{ { -738041211, 427321928, 25 } , 8 , 0 , F_ABSOLUTE , CAM_VIEW_LAUNCH } , //Waypoint 10
	{ { -738042661, 427377633, 5 } , 5 , 0 , F_ABSOLUTE + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 11
	{ { -738044003, 427412156, -20 } , 0 , 0 , F_ABSOLUTE + F_LAND + F_CROSS_TRACK , CAM_VIEW_LAUNCH } , //Waypoint 12
};

