#define USE_HILSIM_PITOT		    1
#define USE_SPEED_IN_HEIGHT_CONTROL	    0
#define USE_THROTTLE_FILTER		    0

#define GNSS_HDOP_REQUIRED_FOR_STARTUP       20  //  Horizontal Dilution of Precision
#define GNSS_VDOP_REQUIRED_FOR_STARTUP	     60  //  Vertical Dilution of Precision
#define GNSS_SVS_REQUIRED_FOR_STARTUP	      6  //  Number of Sattelites in View

#define SLOW_TURN_RATE_SCALING 1

#define USE_FIXED_ORIGIN	    0
//#define FIXED_ORIGIN_LOCATION	    { -1219950467, 374124664, 30.0 }	// A point in Baylands Park in Sunnyvale, CA
#define FIXED_ORIGIN_LOCATION	    { 113480854, 472580108, 578 }	// Innsbruck, useful for X-Plane flight simulator

#define WAYPOINT_PROXIMITY_RADIUS   (5)

#define CAM_VIEW_LAUNCH         { 0, 0, 0 }


#define BOARD_ORIENTATION                   ORIENTATION_FORWARDS
#define AIRFRAME_TYPE                       AIRFRAME_STANDARD
#define GPS_TYPE                            GPS_STD

#define USE_EXTENDED_NAV

#define ROLL_STABILIZATION_AILERONS         1
#define ROLL_STABILIZATION_RUDDER           0
#define PITCH_STABILIZATION                 1
#define YAW_STABILIZATION_RUDDER            1
#define YAW_STABILIZATION_AILERON           0

#define AILERON_NAVIGATION                  1
#define RUDDER_NAVIGATION                   0

#define CROSS_TRACK_MARGIN                  511

#define WIND_GAIN_ADJUSTMENT                0

#define ALTITUDEHOLD_STABILIZED             AH_FULL
#define ALTITUDEHOLD_WAYPOINT               AH_FULL


#define SPEED_CONTROL                       1
#define DESIRED_SPEED                       110.0    // meters/second

#define INVERTED_FLIGHT_STABILIZED_MODE     0
#define INVERTED_FLIGHT_WAYPOINT_MODE       0

#define HOVERING_STABILIZED_MODE            0
#define HOVERING_WAYPOINT_MODE              0

#define USE_CAMERA_STABILIZATION            0

#define MAG_YAW_DRIFT                       0

#define BAROMETER_ALTITUDE                  0

#define LAUNCH_ALTITUDE                     300

#define RACING_MODE                         0
#define RACING_MODE_WP_THROTTLE             1.0

#define NORADIO                             0

#define USE_PPM_INPUT                       0
#define PPM_NUMBER_OF_CHANNELS              8
#define PPM_SIGNAL_INVERTED                 0
#define PPM_ALT_OUTPUT_PINS                 0

#define NUM_INPUTS                          5

#define THROTTLE_INPUT_CHANNEL              CHANNEL_3
#define AILERON_INPUT_CHANNEL               CHANNEL_1
#define ELEVATOR_INPUT_CHANNEL              CHANNEL_2
#define RUDDER_INPUT_CHANNEL                CHANNEL_4
#define MODE_SWITCH_INPUT_CHANNEL           CHANNEL_5
//#define MODE_SWITCH_INPUT_CHANNEL           CHANNEL_5
#define CAMERA_PITCH_INPUT_CHANNEL          CHANNEL_UNUSED
#define CAMERA_YAW_INPUT_CHANNEL            CHANNEL_UNUSED
#define CAMERA_MODE_INPUT_CHANNEL           CHANNEL_UNUSED
#define OSD_MODE_SWITCH_INPUT_CHANNEL       CHANNEL_UNUSED
#define PASSTHROUGH_A_INPUT_CHANNEL         CHANNEL_UNUSED
#define PASSTHROUGH_B_INPUT_CHANNEL         CHANNEL_UNUSED
#define PASSTHROUGH_C_INPUT_CHANNEL         CHANNEL_UNUSED
#define PASSTHROUGH_D_INPUT_CHANNEL         CHANNEL_UNUSED

#define NUM_OUTPUTS                         4

#define THROTTLE_OUTPUT_CHANNEL             CHANNEL_3
#define AILERON_OUTPUT_CHANNEL              CHANNEL_1
#define ELEVATOR_OUTPUT_CHANNEL             CHANNEL_2
#define RUDDER_OUTPUT_CHANNEL               CHANNEL_4
#define AILERON_SECONDARY_OUTPUT_CHANNEL    CHANNEL_UNUSED
#define CAMERA_PITCH_OUTPUT_CHANNEL         CHANNEL_UNUSED
#define CAMERA_YAW_OUTPUT_CHANNEL           CHANNEL_UNUSED
#define TRIGGER_OUTPUT_CHANNEL              CHANNEL_UNUSED
#define PASSTHROUGH_A_OUTPUT_CHANNEL        CHANNEL_UNUSED
#define PASSTHROUGH_B_OUTPUT_CHANNEL        CHANNEL_UNUSED
#define PASSTHROUGH_C_OUTPUT_CHANNEL        CHANNEL_UNUSED
#define PASSTHROUGH_D_OUTPUT_CHANNEL        CHANNEL_UNUSED

#define AILERON_CHANNEL_REVERSED            1
#define ELEVATOR_CHANNEL_REVERSED           1
#define RUDDER_CHANNEL_REVERSED             1
#define AILERON_SECONDARY_CHANNEL_REVERSED  0
#define THROTTLE_CHANNEL_REVERSED           0
#define CAMERA_PITCH_CHANNEL_REVERSED       0
#define CAMERA_YAW_CHANNEL_REVERSED         0

#define ELEVON_VTAIL_SURFACES_REVERSED      0

//#define MODE_SWITCH_THRESHOLD_LOW           2000
//#define MODE_SWITCH_THRESHOLD_HIGH          4500

#define MODE_SWITCH_THRESHOLD_LOW           2666
#define MODE_SWITCH_THRESHOLD_HIGH          3334

#define MODE_SWITCH_TWO_POSITION            0

#define FAILSAFE_INPUT_CHANNEL              MODE_SWITCH_INPUT_CHANNEL
#define FAILSAFE_INPUT_MIN                  2000
#define FAILSAFE_INPUT_MAX                  4500

//#define FAILSAFE_INPUT_MIN                  1500
//#define FAILSAFE_INPUT_MAX                  4500

#define FAILSAFE_TYPE                       FAILSAFE_RTL

#define FAILSAFE_HOLD                       0

#define SERIAL_OUTPUT_FORMAT                SERIAL_UDB_EXTRA

//#define SERIAL_BAUDRATE                     19200

#define SERIAL_BAUDRATE                     57600

#define MAVLINK_SYSID                       1

#define ANALOG_CURRENT_INPUT_CHANNEL        CHANNEL_UNUSED
#define ANALOG_VOLTAGE_INPUT_CHANNEL        CHANNEL_UNUSED
#define ANALOG_RSSI_INPUT_CHANNEL           CHANNEL_UNUSED

#define MAX_CURRENT                         900 // 90.0 Amps max for the sensor from SparkFun (in tenths of Amps)
#define CURRENT_SENSOR_OFFSET               10  // Add 1.0 Amp to whatever value we sense

#define MAX_VOLTAGE                         543 // 54.3 Volts max for the sensor from SparkFun (in tenths of Volts)
#define VOLTAGE_SENSOR_OFFSET               0   // Add 0.0 Volts to whatever value we sense

#define RSSI_MIN_SIGNAL_VOLTAGE             0.5     // Voltage when RSSI should show 0%
#define RSSI_MAX_SIGNAL_VOLTAGE             3.3     // Voltage when RSSI should show 100%

#define USE_SONAR_INPUT                     0

#define TRIGGER_TYPE                        TRIGGER_TYPE_NONE
#define TRIGGER_ACTION                      TRIGGER_PULSE_HIGH
#define TRIGGER_SERVO_LOW                   2000
#define TRIGGER_SERVO_HIGH                  4000
#define TRIGGER_PULSE_DURATION              250
#define TRIGGER_REPEAT_PERIOD               4000

#define SERVOSAT                            1.0

#define FEED_FORWARD						0.8

//#define TURN_RATE_NAV							30.0
//#define TURN_RATE_FBW							60.0
#define TURN_RATE_NAV							3.0
#define TURN_RATE_FBW							6.0

#define KD_ON_OFF						  ( 1.0  )
#define ROLLKP                              0.6
//#define ROLLKP                              0.2
#define ROLLKD                              0.00*KD_ON_OFF
#define YAWKP_AILERON                       0.10*0.0
#define YAWKD_AILERON                       0.05*0.0


//#define PITCHGAIN                           0.5
//#define PITCHGAIN                           0.6
#define PITCHGAIN                           0.4
//#define PITCHKD                             0.04*KD_ON_OFF
#define PITCHKD                             0.2*KD_ON_OFF
#define ELEVATOR_BOOST                        0.5

// 747
#define ANGLE_OF_ATTACK_NORMAL				( 0.0 )
#define ANGLE_OF_ATTACK_INVERTED			( 0.0 )
#define ELEVATOR_TRIM_NORMAL				( 0.0 )
#define ELEVATOR_TRIM_INVERTED				( 0.0 )
//#define CRUISE_SPEED						( 177.0 )
#define REFERENCE_SPEED						( 110.0 )


 
//#define INVERTED_NEUTRAL_PITCH             ( 8.0 ) // not needed with AoA model

#define YAWKP_RUDDER                        0.4
//#define YAWKP_RUDDER                        0.10
#define YAWKD_RUDDER                        0.05*KD_ON_OFF
#define ROLLKP_RUDDER                       0.20*0.0
#define ROLLKD_RUDDER                       0.05*0.0
#define MANUAL_AILERON_RUDDER_MIX           0.00
#define RUDDER_BOOST                        0.5

#define HOVER_ROLLKP                        0.05
#define HOVER_ROLLKD                        0.05
#define HOVER_PITCHGAIN                     0.2
#define HOVER_PITCHKD                       0.25
#define HOVER_PITCH_OFFSET                  0.0        // + leans towards top, - leans towards bottom
#define HOVER_YAWKP                         0.2
#define HOVER_YAWKD                         0.25
#define HOVER_YAW_OFFSET                    0.0
#define HOVER_PITCH_TOWARDS_WP             30.0
#define HOVER_NAV_MAX_PITCH_RADIUS         20

#define CAMERA_MODE_THRESHOLD_LOW          2600
#define CAMERA_MODE_THRESHOLD_HIGH         3400

#define CAM_TAN_PITCH_IN_STABILIZED_MODE    1433    // 1443 is 5 degrees of pitch. Example: 15 degrees is 4389
#define CAM_YAW_IN_STABILIZED_MODE          0       // in degrees relative to the plane's yaw axis.    Example: 0

// All number should be integers
#define CAM_PITCH_SERVO_THROW               95      // Camera lens rotation at maximum PWM change (2000 to 4000), in degrees.          
#define CAM_PITCH_SERVO_MAX                 85      // Max pitch up that plane can tilt and keep camera level, in degrees.  
#define CAM_PITCH_SERVO_MIN                -22      // Max pitch down that plane can tilt and keep camera level, in degrees. 
#define CAM_PITCH_OFFSET_CENTRED            38      // Offset in degrees of servo that results in a level camera.           
                                                    // Example: 30 would mean that a centered pitch servo points the camera
                                                    // 30 degrees down from horizontal when looking to the front of the plane.

#define CAM_YAW_SERVO_THROW                 350     // Camera yaw movement for maximum yaw PWM change (2000 to 4000) in Degrees. 
#define CAM_YAW_SERVO_MAX                   130     // Max positive yaw of camera relative to front of plane in Degrees.              
#define CAM_YAW_SERVO_MIN                  -130     // Min reverse  yaw of camera relative to front of plane in Degrees.   
#define CAM_YAW_OFFSET_CENTRED              11      // Yaw offset in degrees that results in camera pointing forward. 

#define CAM_TESTING_OVERIDE                 0       // Set to 1 for camera to move to test angles in stabilized mode.
#define CAM_TESTING_YAW_ANGLE               90      // e.g. 90 degrees. Will try to swing 90 degrees left, then 90 degrees right
#define CAM_TESTING_PITCH_ANGLE             90      // In degrees.

#define CAM_USE_EXTERNAL_TARGET_DATA        0

#define HEIGHT_TARGET_MIN                   100.0
#define HEIGHT_TARGET_MAX                   1200.0

//#define HEIGHT_MARGIN                       100
//#define HEIGHT_MARGIN                       1000
#define HEIGHT_MARGIN                       50

#define ALT_HOLD_THROTTLE_MIN               0.0
#define ALT_HOLD_THROTTLE_MAX               1.0

//#define ALT_HOLD_PITCH_MIN                 -15.0
//#define ALT_HOLD_PITCH_MAX                  15.0
//#define ALT_HOLD_PITCH_HIGH                -15.0

#define ALT_HOLD_PITCH_MIN                 -15.0
#define ALT_HOLD_PITCH_MAX                  15.0
#define ALT_HOLD_PITCH_HIGH                -15.0

#define RTL_PITCH_DOWN                      0.0

#define HILSIM                              1
#define HILSIM_USB                          0           // AUAV3 only (under development)
#define HILSIM_BAUD                         38400

#define FLIGHT_PLAN_TYPE                    FP_WAYPOINTS

//#define ID_DIY_DRONES_URL "http://www.diydrones.com/profile/PeterHollands"
#define ID_VEHICLE_MODEL_NAME               "Cirrus HILSIM"
#define ID_VEHICLE_REGISTRATION             "helical version, body frame pitch"
#define ID_LEAD_PILOT                       "WJP"
#define ID_DIY_DRONES_URL                   ""

#define FLY_BY_DATALINK_ENABLED             0

#define RECORD_FREE_STACK_SPACE             0

#define CONSOLE_UART                        0

#define GPS_PORT                            4
#define TLM_PORT                            3
#define DBG_PORT                            1

#define USE_TELELOG                         0

#define USE_CONFIGFILE                      0

#define USE_USB                             0

#define USE_MSD                             0
