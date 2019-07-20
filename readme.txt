This branch (additional_control_gains_and_ranges) was developed as part of a project to implement autolandings, particularly in the context of HILSIM using aircraft with high airspeeds, such as jets. Several improvements were made and several options were made. Some items serve all types of aircraft, some were developed with high speed operation.
Core infrastructure improvements included increased resolution of course over ground angles from 8 bits to 16 bits,
and height control variables from 16 bits to 32 bits.

Velocity damping terms were added to vertical and cross-tracking lateral control to improve vertical and cross tracking control.

Flap and speed control items were added to waypoint definitions and the waypoint editor was updated accordingly.

Several new options and parameters were added to the options.h file, most of which were to support control of high speed jets.

Several new options and parameters were added to the options.h file. To make the new code compatible with existing options.h files, default values for each option and parameter are set if they are not defined in options.h. The default values are for an EasyStar. The following is a summary of the new options and parameters:

#define USE_HILSIM_PITOT (0 or 1) // default is effectively 0 if USE_HILSIM_PITOT is not defined
Set to 1 to simulate a PITOT tube under HILSIM only for the computation of wind speed. This was provided because during typical HILSIM jet flights, there are not enough turns to converge the wind estimator.

#define USE_THROTTLE_FILTER (0 or 1) // default is 1
Set to 0 to turn off the throttle filter. This was implemented in an effort to improve speed control of jets. It turned out to be of limited value.

#define SLOW_TURN_RATE_SCALING (0 or 1) // default is effectively 0 if SLOW_TURN_RATE_SCALING is not defined
Set to 1 to provide better (8X) resolution of turn rate control of jets when the turn rate gains are less than 5 degrees per second.

#USE_SPEED_IN_HEIGHT_CONTROL (0 or 1) // default is 1
It was found that better altitude control was obtained if the energy associated with speed was not included in elevator control of altitude. (Both speed and height are used for speed control.) This is consistent with the NASA paper on the subject of total energy control. Although the default is 1, the recommended value is 0.

In addition, if you are using flaps, you will need to define input and output flap channels and flap polarity.

Finally, there are two new control parameters:

#define X_TRACK_V_SHIFT (INTEGER) // default is 4 for EasyStar, 2 is recommended for a jet

#define SPEED_MARGIN (INTEGER) // default is 0 for EasyStar, 4 is recommended for a jet

Both X_TRACK_V_SHIFT and SPEED_MARGIN are integer arguments in a shift operation to increase/decrease a gain by factors of 2.

X_TRACK_V_SHIFT is an abbreviation of cross track velocity damping shift and is used in the code as follows:

	crossVector[0].WW -= IMUlocationx.WW + ((IMUvelocityx.WW) >> X_TRACK_V_SHIFT );
	crossVector[1].WW -= IMUlocationy.WW + ((IMUvelocityy.WW) >> X_TRACK_V_SHIFT );

This is a right shift, so increasing the parameter reduces the gain of the cross track velocity control feedback.

SPEED_MARGIN is used in the computation of throttle response to speed error:

	heightError.WW = ((heightError.WW + IMUlocationz.WW + speed_height) >> (13+SPEED_MARGIN));

This is a right shift, so increasing the parameter reduces the gain of the throttle control response to speed. It was found necessary for speed control of jets in which the same equivalent height margin cannot be applied to both speed and altitude control.
