

//#define DATE "Wolf_pac_2 , firmware 5.5, 5/28/2024\r\n"
// improved continuous gyro bias estimation
//#define DATE "Wolf_pac_2 , firmware 5.6, 8/8/2024\r\n" 
// 5.6: no change in software, but improved "in situ" temperature compensation
#define DATE "Wolf_pac_2 , firmware 5.7, 8/16/2024\r\n" 
// 5.7: major improvement in jostle detection by using
// the sum of the squares of the standard deviations of the three gyro channels
// over a 2 second window

#define CONING_CORRECTION
#define CONING_CORRECTION_IN_RMAT

#ifdef CONING_CORRECTION
#define MINI5 "UDBmini5 hardware, 8000 Hz sampling.\r\n"
#define MINI6 "UDBmini6 hardware, 8000 Hz sampling.\r\n"
#define LUGE7 "UDBluge7 hardware, 8000 Hz sampling.\r\n"
#else
#define MINI5 "UDBmini5 hardware, 200 Hz sampling.\r\n"
#define MINI6 "UDBmini6 hardware, 200 Hz sampling.\r\n"
#define LUGE7 "UDBluge7 hardware, 200 Hz sampling.\r\n"
#endif // CONING_CORRECTION

// the following defines select what gets sent to the logger
// for a normal production run, define LOG_IMU_WP2, NORMAL_RUN, LOG_RESIDUALS AND RESIDUAL_LOG_PERIOD
#define LOG_IMU_WP2               // logs IMU data during a run for wolf_pac version 2
                                    // you will also need to turn on the following:
#define NORMAL_RUN // this one must be turned on for normal operation 100 hz
#define LOG_RESIDUALS         // logs residual offsets between runs
#define RESIDUAL_LOG_PERIOD 2  // 30 times per minute

//#define LOG_PITCH_RATE // not commonly used

// the following are used to measure offsets and gains for commissioning
//#define RECORD_OFFSETS        // record raw accelerometer data and verify residual gyro offsets
// the following two options are presently used together
//#define BUILD_OFFSET_TABLE    // builds gyro temperature compensation table
//#define ACCEL_AND_GYRO_OFFSETS

// the following are special logging options
//#define SPECTRAL_ANALYSIS_BURST // 5 hz, start at 15, remember to also uncomment the following line
//#define SAMPLES_PER_BURST 80 
//#define SPECTRAL_ANALYSIS_CONTINUOUS // also known as the fire hose
//#define TEST_SLED // set logging Hz to 200 start at 15
//#define KUFEN // set logging Hz to 200 and start angle to 30 degrees


// When using USE_PACKETIZED_TELEMERTY, baud will be 460800, and some 
// non-printable characters are written out, as header bytes for packets.
//#define USE_PACKETIZED_TELEMERTY

#define LOG_EULER
//#define LOG_RATE_AND_EULER
//#define LOG_PITCH_AND_TWO_FORCES


// set the logger hertz, allowable values are 1,2,4,5,10,20,25,40,50,100 or 200
#define LOGGER_HZ	10
#define HEADER_HZ	20          // records per second during header logging
#define SLIDE_DET_HZ	200     // computations per second to detect beginning of a run
//#define TILT_STOP_DELAY 10      // delay in seconds to allow for a roll over
#define TILT_STOP_DELAY 1      // delay in seconds to allow for a roll over
//#define TILT_START	30          // tilt angle to start for Kufen
#define TILT_START	15          // tilt angle threshold in degrees to start recording a run
#define TILT_STOP	60          // tilt angle threshold in degrees to stop recording a run
//#define TILT_STOP	135         // used for some types of ground testing

// select a wolf_pac by defining its internal label
//#define LUGE7_SNnew // used to program a WP without a serial number

//bill's research boards
//#define LUGE7_SNts1
//#define LUGE7_SNts2


//#define LUGE7_SN050
//#define LUGE7_SN051
//#define LUGE7_SN052
//#define LUGE7_SN053
//#define LUGE7_SN054

//#define LUGE7_SN080
//#define LUGE7_SN081
//#define LUGE7_SN082
//#define LUGE7_SN083

//#define LUGE7_SN084
//#define LUGE7_SN085

//#define LUGE7_SN086
//#define LUGE7_SN087
//#define LUGE7_SN088
//#define LUGE7_SN089

//#define LUGE7_SN101 // switched, used to be 108
//#define LUGE7_SN102
//#define LUGE7_SN103
//#define LUGE7_SN104
//#define LUGE7_SN105
//#define LUGE7_SN106
//#define LUGE7_SN107
//#define LUGE7_SN108 // switched, used to be 101
//#define LUGE7_SN109
//#error #define LUGE7_SN110 // not in service, wifi issue at low temp
//#define LUGE7_SN111
//#define LUGE7_SN112
//#define LUGE7_SN113
//#define LUGE7_SN114
//#define LUGE7_SN115
//#define LUGE7_SN116
//#define LUGE7_SN117
//#define LUGE7_SN118
//#define LUGE7_SN119
//#define LUGE7_SN120
//#define LUGE7_SN121
//#define LUGE7_SN122
//#define LUGE7_SN123
//#define LUGE7_SN124
//#define LUGE7_SN125
//#define LUGE7_SN126
#define LUGE7_SN127
//#define LUGE7_SN128
//#define LUGE7_SN129
//#define LUGE7_SN130
//#define LUGE7_SN131
//#define LUGE7_SN132
//#define LUGE7_SN133
//#define LUGE7_SN134
//#define LUGE7_SN135
//#define LUGE7_SN136
//#define LUGE7_SN137
//#define LUGE7_SN138
//#error #define LUGE7_SN139 //out of service too much drift
//#define LUGE7_SN140
//#define LUGE7_SN141
//#define LUGE7_SN142
//#define LUGE7_SN143
//#define LUGE7_SN144
//#error #define LUGE7_SN145 out of service
//#define LUGE7_SN146
//#define LUGE7_SN147
//#define LUGE7_SN148
//#define LUGE7_SN149
//#define LUGE7_SN150
//#define LUGE7_SN151
//#define LUGE7_SN152
//#define LUGE7_SN153
//#define LUGE7_SN154
//#define LUGE7_SN155
//#define LUGE7_SN156
//#define LUGE7_SN157
//#define LUGE7_SN158
//#define LUGE7_SN159
//#define LUGE7_SN160
//#define LUGE7_SN161
//#define LUGE7_SN162
//#define LUGE7_SN163

//#define LUGE7_SN164
//#define LUGE7_SN165
//#define LUGE7_SN166
//#define LUGE7_SN167

//#define LUGE7_SN168
//#define LUGE7_SN169
//#define LUGE7_SN170
//#define LUGE7_SN171

//#define LUGE7_SN172
//#define LUGE7_SN173
//#define LUGE7_SN174
//#define LUGE7_SN175

//#define LUGE7_SN176
//#define LUGE7_SN177

//#define LUGE7_SN178
//#define LUGE7_SN179
//#define LUGE7_SN180
//#define LUGE7_SN181

//#define LUGE7_SN182
//#define LUGE7_SN183
//#define LUGE7_SN184
//#define LUGE7_SN185

//#define LUGE7_SN186
//#define LUGE7_SN187
//#define LUGE7_SN188
//#define LUGE7_SN189

//#define LUGE7_SN190
//#define LUGE7_SN191
//#define LUGE7_SN192
//#define LUGE7_SN193

//#define LUGE7_SN194
//#define LUGE7_SN195
//#define LUGE7_SN196
//#define LUGE7_SN197


//#define MINI6_SN4 // SN1, Tucker West
//#define MINI5_SN14 // was SN14, now SN2
//#define MINI6_SN3 // SN3
//SN4 is mini6_sn1 but it is out of service
//#define MINI6_SN5 // SN5
//#define MINI6_SN6 // SN6
//#define MINI5_SN7 // SN7
//#define MINI5_SN1 // SN8
//#define MINI5_SN2 // SN9
//#define MINI5_SN3 // SN10
//#define MINI5_SN4 // SN11
//#define MINI5_SN12 // SN12
//#define MINI6_SN2 // was SN2, now SN14
//#define MINI6_SN15 // SN15

#ifdef LUGE7_SNnew
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SNnew.h"
#endif // LUGE7_SNnew


#ifdef LUGE7_SNts1
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	8
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SNts1.h"
#endif // LUGE7_SNts1

#ifdef LUGE7_SNts2
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	8
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SNts2.h"
#endif // LUGE7_SNts2

#ifdef LUGE7_SN101
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
// used to be 108
#include "options_LUGE7_SN108.h"
#endif // LUGE7_SN101

#ifdef LUGE7_SN102
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // LUGE7_SN102

#ifdef LUGE7_SN103
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // LUGE7_SN103

#ifdef LUGE7_SN104
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 4
//#define ACCEL_RANGE         8
#define ACCEL_RANGE         2
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN104.h"
#endif // 

#ifdef LUGE7_SN105
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN105.h"
#endif // 

#ifdef LUGE7_SN106
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN106.h"
#endif // 

#ifdef LUGE7_SN107
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN107.h"
#endif // 

#ifdef LUGE7_SN108
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
// used to be 101
#include "options_LUGE7_SN101.h"
#endif // 

#ifdef LUGE7_SN109
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN109.h"
#endif // LUGE7_SN109

#ifdef LUGE7_SN110
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN110.h"
#endif // LUGE7_SN110

#ifdef LUGE7_SN111
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN111.h"
#endif // LUGE7_SN111

#ifdef LUGE7_SN112
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN112.h"
#endif // LUGE7_SN112

#ifdef LUGE7_SN113
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN113.h"
#endif // LUGE7_SN113

#ifdef LUGE7_SN114
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN114.h"
#endif // LUGE7_SN114

#ifdef LUGE7_SN115
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN115.h"
#endif // LUGE7_SN115

#ifdef LUGE7_SN116
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN116.h"
#endif // LUGE7_SN116

#ifdef LUGE7_SN117
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN117.h"
#endif // LUGE7_SN117

#ifdef LUGE7_SN118
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN118.h"
#endif // LUGE7_SN118

#ifdef LUGE7_SN119
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN119.h"
#endif // LUGE7_SN119

#ifdef LUGE7_SN120
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN120.h"
#endif // LUGE7_SN120

#ifdef LUGE7_SN121
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN121.h"
#endif // LUGE7_SN121

#ifdef LUGE7_SN122
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN122.h"
#endif // LUGE7_SN122

#ifdef LUGE7_SN123
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN123.h"
#endif // LUGE7_SN123

#ifdef LUGE7_SN124
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN124.h"
#endif // LUGE7_SN124

#ifdef LUGE7_SN125
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN125.h"
#endif // LUGE7_SN125

#ifdef LUGE7_SN126
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN126.h"
#endif // LUGE7_SN126

#ifdef LUGE7_SN127
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN127.h"
#endif // LUGE7_SN127

#ifdef LUGE7_SN128
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN128.h"
#endif // LUGE7_SN128

#ifdef LUGE7_SN129
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	2
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN129.h"
#endif // LUGE7_SN129

#ifdef LUGE7_SN130
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN130.h"
#endif // LUGE7_SN130

#ifdef LUGE7_SN131
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1 1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN131.h"
#endif // LUGE7_SN131

#ifdef LUGE7_SN132
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN132.h"
#endif // LUGE7_SN132

#ifdef LUGE7_SN133
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN133.h"
#endif // LUGE7_SN133

#ifdef LUGE7_SN134
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN134.h"
#endif // LUGE7_SN134

#ifdef LUGE7_SN135
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN135.h"
#endif // LUGE7_SN135

#ifdef LUGE7_SN136
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN136.h"
#endif // LUGE7_SN136

#ifdef LUGE7_SN137
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN137.h"
#endif // LUGE7_SN137

#ifdef LUGE7_SN138
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN138.h"
#endif // LUGE7_SN138

#ifdef LUGE7_SN139
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	3
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN139.h"
#endif // LUGE7_SNnew

#ifdef LUGE7_SN140
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN140.h"
#endif // LUGE7_SN140

#ifdef LUGE7_SN141
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN141.h"
#endif // LUGE7_SN141

#ifdef LUGE7_SN142
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN142.h"
#endif // LUGE7_SN142

#ifdef LUGE7_SN143
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN143.h"
#endif // LUGE7_SN143

#ifdef LUGE7_SN144
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN144.h"
#endif // LUGE7_SN144

#ifdef LUGE7_SN145
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN145.h"
#endif // LUGE7_SN145

#ifdef LUGE7_SN146
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN146.h"
#endif // LUGE7_SN146

#ifdef LUGE7_SN147
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN147.h"
#endif // LUGE7_SN147

#ifdef LUGE7_SN148
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN148.h"
#endif // LUGE7_SN148

#ifdef LUGE7_SN149
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	4
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN149.h"
#endif // LUGE7_SN149

#ifdef LUGE7_SN150
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN150.h"
#endif // LUGE7_SN150

#ifdef LUGE7_SN151
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN151.h"
#endif // LUGE7_SN151

#ifdef LUGE7_SN152
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN152.h"
#endif // LUGE7_SN152

#ifdef LUGE7_SN153
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN153.h"
#endif // LUGE7_SN153

#ifdef LUGE7_SN154
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN154.h"
#endif // LUGE7_SN154

#ifdef LUGE7_SN155
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN155.h"
#endif // LUGE7_SN155

#ifdef LUGE7_SN156
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN156.h"
#endif // LUGE7_SN156

#ifdef LUGE7_SN157
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN157.h"
#endif // LUGE7_SN157

#ifdef LUGE7_SN158
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN158.h"
#endif // LUGE7_SN158

#ifdef LUGE7_SN159
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN159.h"
#endif // LUGE7_SN159

#ifdef LUGE7_SN160
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN160.h"
#endif // LUGE7_SN160

#ifdef LUGE7_SN161
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN161.h"
#endif // LUGE7_SN161

#ifdef LUGE7_SN162
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN162.h"
#endif // LUGE7_SN162

#ifdef LUGE7_SN163
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN163.h"
#endif // LUGE7_SN163

#ifdef LUGE7_SN164
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN164.h"
#endif // LUGE7_SN164

#ifdef LUGE7_SN165
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN165.h"
#endif // LUGE7_SN165

#ifdef LUGE7_SN166
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN166.h"
#endif // LUGE7_SN166

#ifdef LUGE7_SN167
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN167.h"
#endif // LUGE7_SN167

#ifdef LUGE7_SN168
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN168.h"
#endif // LUGE7_SN168

#ifdef LUGE7_SN169
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	6
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN169.h"
#endif // LUGE7_SN169

#ifdef LUGE7_SN170
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN170.h"
#endif // LUGE7_SN170

#ifdef LUGE7_SN171
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN171.h"
#endif // LUGE7_SN171

#ifdef LUGE7_SN172
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN172.h"
#endif // LUGE7_SN172

#ifdef LUGE7_SN173
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN173.h"
#endif // LUGE7_SN173

#ifdef LUGE7_SN174
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN174.h"
#endif // LUGE7_SN174

#ifdef LUGE7_SN175
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN175.h"
#endif // LUGE7_SN175

#ifdef LUGE7_SN176
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN176.h"
#endif // LUGE7_SN176

#ifdef LUGE7_SN177
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN177.h"
#endif // LUGE7_SN177

#ifdef LUGE7_SN178
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN178.h"
#endif // LUGE7_SN178

#ifdef LUGE7_SN179
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	7
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN179.h"
#endif // LUGE7_SN179

#ifdef LUGE7_SN180
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN180.h"
#endif // LUGE7_SN180

#ifdef LUGE7_SN181
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN181.h"
#endif // LUGE7_SN181

#ifdef LUGE7_SN182
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN182.h"
#endif // LUGE7_SN182

#ifdef LUGE7_SN183
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN183.h"
#endif // LUGE7_SN183


#ifdef LUGE7_SN184
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN184.h"
#endif // LUGE7_SN184

#ifdef LUGE7_SN185
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN185.h"
#endif // LUGE7_SN185

#ifdef LUGE7_SN186
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN186.h"
#endif // LUGE7_SN186

#ifdef LUGE7_SN187
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN187.h"
#endif // LUGE7_SN187

#ifdef LUGE7_SN188
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN188.h"
#endif // LUGE7_SN188

#ifdef LUGE7_SN189
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN189.h"
#endif // LUGE7_SN189

#ifdef LUGE7_SN190
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN190.h"
#endif // LUGE7_SN190

#ifdef LUGE7_SN191
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN191.h"
#endif // LUGE7_SN191

#ifdef LUGE7_SN192
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN192.h"
#endif // LUGE7_SN192

#ifdef LUGE7_SN193
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN193.h"
#endif // LUGE7_SN193

#ifdef LUGE7_SN194
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN194.h"
#endif // LUGE7_SN194

#ifdef LUGE7_SN195
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN195.h"
#endif // LUGE7_SN195

#ifdef LUGE7_SN196
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN196.h"
#endif // LUGE7_SN196

#ifdef LUGE7_SN197
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	1
#define SERIAL_NUMBERD2	9
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN197.h"
#endif // LUGE7_SN197


#ifdef LUGE7_SN050
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN050.h"
#endif // LUGE7_SN050

#ifdef LUGE7_SN051
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN051.h"
#endif // LUGE7_SN051

#ifdef LUGE7_SN052
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN052.h"
#endif // LUGE7_SN052

#ifdef LUGE7_SN053
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN053.h"
#endif // LUGE7_SN053

#ifdef LUGE7_SN054
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	5
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN054.h"
#endif // LUGE7_SN054

#ifdef LUGE7_SN080
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         2
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN080.h"
#endif // LUGE7_SN080

#ifdef LUGE7_SN081
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         4
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN081.h"
#endif // LUGE7_SN081

#ifdef LUGE7_SN082
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 2
//#define ACCEL_RANGE         8
#define ACCEL_RANGE         2
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN082.h"
#endif // LUGE7_SN082

#ifdef LUGE7_SN083
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN083.h"
#endif // LUGE7_SN083

#ifdef LUGE7_SN084
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         4
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN084.h"
#endif // LUGE7_SN084

#ifdef LUGE7_SN085
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN085.h"
#endif // LUGE7_SN085

#ifdef LUGE7_SN086
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN086.h"
#endif // LUGE7_SN086

#ifdef LUGE7_SN087
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN087.h"
#endif // LUGE7_SN087

#ifdef LUGE7_SN088
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN088.h"
#endif // LUGE7_SN088

#ifdef LUGE7_SN089
#define ENABLE_ESP32
#define UDB7LUGE
#define BOARD LUGE7
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	8
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#include "options_LUGE7_SN089.h"
#endif // LUGE7_SNnew

#ifdef LUGE7_SN102
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 0 )
#define YACCEL_OFFSET	( -40 )
#define ZACCEL_OFFSET	( 6 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_21.h"
#define CALIBRATIONX	1.0133
#define CALIBRATIONY	1.0132
#define CALIBRATIONZ	1.0151
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4106
#define CAL_GRAV_Y	4103
#define CAL_GRAV_Z	4087
#endif //LUGE7_SN102

#ifdef LUGE7_SN103
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 18 )
#define YACCEL_OFFSET	( -63 )
#define ZACCEL_OFFSET	( -11 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_22.h"
#define CALIBRATIONX	1.0204
#define CALIBRATIONY	1.0106
#define CALIBRATIONZ	1.0145
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4104
#define CAL_GRAV_Y	4101
#define CAL_GRAV_Z	4078
#endif //LUGE7_SN103

#ifdef MINI6_SN1
#define BOARD MINI6
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 4
// used to be SN1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // MINI6_SN1

#ifdef MINI6_SN2
#define BOARD MINI6
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // MINI6_SN2

#ifdef MINI6_SN3
#define NAME "Bruce Norman"
#define BOARD MINI6
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // MINI6_SN3

#ifdef MINI6_SN4
#define BOARD MINI6
#define NAME "Tucker West"
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 1
// used to be SN4
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // MINI6_SN4

#ifdef MINI6_SN5
#define BOARD MINI6
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // MINI6_SN5

#ifdef MINI6_SN6
#define BOARD MINI6
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 6
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // MINI6_SN6

#ifdef MINI6_SN15
#define BOARD MINI6
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 5
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#define LOG_EULER
#endif // MINI6_SN6

#ifdef MINI5_SN4
// was SN4
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 1
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN4

#ifdef MINI5_SN7
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 7
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN7

#ifdef MINI5_SN12
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN12

#ifdef MINI5_SN13
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 3
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN13

#ifdef MINI5_SN14
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 2
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN14

#ifdef MINI5_SN2
// was SN2
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 9
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN2

#ifdef MINI5_SN3
// was SN3
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	1
#define SERIAL_NUMBERD3 0
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN2

#ifdef MINI5_SN1
// was SN1
#define BOARD MINI5
#define SERIAL_NUMBERD1	0
#define SERIAL_NUMBERD2	0
#define SERIAL_NUMBERD3 8
#define ACCEL_RANGE         8
#define GYRO_RANGE	    1000
#endif // MINI5_SN1

#ifdef MINI5_SN1
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 80 )
#define YACCEL_OFFSET	( -17 )
#define ZACCEL_OFFSET	( -288 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_9.h"
//#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_7.h"
#define CALIBRATIONX	1.0159
#define CALIBRATIONY	1.0100
#define CALIBRATIONZ	1.0119
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4089
#define CAL_GRAV_Y	4074
#define CAL_GRAV_Z	4162
#endif //MINI5_SN1

#ifdef MINI5_SN2
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 74 )
#define YACCEL_OFFSET	( -42 )
#define ZACCEL_OFFSET	( 275 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_16.h"
#define CALIBRATIONX	1.0144
#define CALIBRATIONY	1.0179
#define CALIBRATIONZ	1.0192
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4124
#define CAL_GRAV_Y	4085
#define CAL_GRAV_Z	4140
#endif //MINI5_SN2

#ifdef MINI5_SN3
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 158 )
#define YACCEL_OFFSET	( -29 )
#define ZACCEL_OFFSET	( -287 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_8.h"
#define CALIBRATIONX	1.0120
#define CALIBRATIONY	1.0185
#define CALIBRATIONZ	1.0090
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4103
#define CAL_GRAV_Y	4082
#define CAL_GRAV_Z	4174
#endif //MINI5_SN3

#ifdef MINI5_SN4
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 132 )
#define YACCEL_OFFSET	( 56 )
#define ZACCEL_OFFSET	( -330 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_11.h"
#define CALIBRATIONX	1.0072
#define CALIBRATIONY	1.0057
#define CALIBRATIONZ	1.0039
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4123
#define CAL_GRAV_Y	4096
#define CAL_GRAV_Z	4198
#endif //MINI5_SN4

#ifdef MINI5_SN12
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 163 )
#define YACCEL_OFFSET	( 20 )
#define ZACCEL_OFFSET	( -156 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_12.h"
#define CALIBRATIONX	1.0051
#define CALIBRATIONY	1.0101
#define CALIBRATIONZ	1.0190
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4105
#define CAL_GRAV_Y	4075
#define CAL_GRAV_Z	4190
#endif //MINI5_SN12

#ifdef MINI5_SN13
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 0)
#define YACCEL_OFFSET	( 0 )
#define ZACCEL_OFFSET	( 0 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_13.h"
#define CALIBRATIONX	1.0000
#define CALIBRATIONY	1.0000
#define CALIBRATIONZ	1.0000
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4096
#define CAL_GRAV_Y	4096
#define CAL_GRAV_Z	4096
#endif //MINI5_SN13

#ifdef MINI5_SN14
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 159 )
#define YACCEL_OFFSET	( 38 )
#define ZACCEL_OFFSET	( -495 )
//#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_18.h"
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_20.h"
#define CALIBRATIONX	1.0022
#define CALIBRATIONY	1.0072
#define CALIBRATIONZ	1.0104
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4132
#define CAL_GRAV_Y	4094
#define CAL_GRAV_Z	4169
#endif //MINI5_SN14


#ifdef MINI5_SN7
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 133)
#define YACCEL_OFFSET	( 40 )
#define ZACCEL_OFFSET	( 52 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_14.h"
#define CALIBRATIONX	1.0000
#define CALIBRATIONY	1.0198
#define CALIBRATIONZ	1.0076
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4127
#define CAL_GRAV_Y	4078
#define CAL_GRAV_Z	4192
#endif //MINI5_SN7

#ifdef MINI6_SN1
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 83 )
#define YACCEL_OFFSET	( -15 )
#define ZACCEL_OFFSET	( -16 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_15.h"
#define CALIBRATIONX	1.0109
#define CALIBRATIONY	1.0171
#define CALIBRATIONZ	1.0066
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4101
#define CAL_GRAV_Y	4099
#define CAL_GRAV_Z	4153
#endif // MINI6_SN1

#ifdef MINI6_SN2
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 72 )
#define YACCEL_OFFSET	( -42 )
#define ZACCEL_OFFSET	( 26 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_4.h"
#define CALIBRATIONX	1.0141
#define CALIBRATIONY	1.0056
#define CALIBRATIONZ	1.0127
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4103
#define CAL_GRAV_Y	4103
#define CAL_GRAV_Z	4108
#endif // MINI6_SN2

#ifdef MINI6_SN3
#define CUSTOM_OFFSETS
#define XACCEL_OFFSET	( 58 )
#define YACCEL_OFFSET	( -34 )
#define ZACCEL_OFFSET	( -77 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_10.h"
#define CALIBRATIONX	1.0135
#define CALIBRATIONY	1.0009
#define CALIBRATIONZ	1.0067
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4100
#define CAL_GRAV_Y	4104
#define CAL_GRAV_Z	4148
#endif // MINI6_SN3

#ifdef MINI6_SN4
#define XACCEL_OFFSET	( 83 )
#define YACCEL_OFFSET	( -50 )
#define ZACCEL_OFFSET	( -21 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_17.h"
#define CALIBRATIONX	1.0112
#define CALIBRATIONY	1.0043
#define CALIBRATIONZ	1.0067
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4105
#define CAL_GRAV_Y	4098
#define CAL_GRAV_Z	4122
#endif // MINI6_SN4

#ifdef MINI6_SN5
#define XACCEL_OFFSET	( 58 )
#define YACCEL_OFFSET	( -30 )
#define ZACCEL_OFFSET	( -104 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_5.h"
#define CALIBRATIONX	1.0146
#define CALIBRATIONY	1.0009
#define CALIBRATIONZ	1.0061
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4097
#define CAL_GRAV_Y	4106
#define CAL_GRAV_Z	4124
#endif // MINI6_SN5

#ifdef MINI6_SN6
#define XACCEL_OFFSET	( 135 )
#define YACCEL_OFFSET	( -37 )
#define ZACCEL_OFFSET	( -100 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_6.h"
#define CALIBRATIONX	1.0145
#define CALIBRATIONY	1.0037
#define CALIBRATIONZ	1.0055
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4098
#define CAL_GRAV_Y	4108
#define CAL_GRAV_Z	4134
#endif // MINI6_SN6

#ifdef MINI6_SN15
#define XACCEL_OFFSET	( 79 )
#define YACCEL_OFFSET	( -22 )
#define ZACCEL_OFFSET	( -113 )
#define GYRO_OFFSET_TABLE "../libUDB/gyro_tables/table_19.h"
#define CALIBRATIONX	1.0115
#define CALIBRATIONY	1.0019
#define CALIBRATIONZ	1.0053
#define CALIB_GRAVITY	4096
#define CAL_GRAV_X	4100
#define CAL_GRAV_Y	4105
#define CAL_GRAV_Z	4153
#endif // MINI6_SN15


#ifdef GYRO_CALIB
#undef LOGGER_HZ
#define LOGGER_HZ 10
#undef ALWAYS_LOG
#undef TILT_STOP
#define TILT_STOP 500
#define UPSIDE_DOWN
#endif // GYRO_CALIB

#ifdef FILTERED_ACCELEROMETER
#undef LOGGER_HZ
#define LOGGER_HZ 2
#ifndef ALWAYS_LOG
#define ALWAYS_LOG
#endif // ALWAYS_LOG
#endif // FILTERED_ACCELEROMETER

#ifdef GYRO_OFFSETS
#undef LOGGER_HZ
//#define LOGGER_HZ 4
#define LOGGER_HZ 1
#undef ALWAYS_LOG
#define ALWAYS_LOG
#undef ALWAYS_SYNC_GYROS
//#define ALWAYS_SYNC_GYROS
#undef TILT_STOP
#define TILT_STOP 600
#endif // GYRO_OFFSETS

#ifdef GYRO_DRIFT
#undef LOGGER_HZ
#define LOGGER_HZ 10
#undef ALWAYS_LOG
#define ALWAYS_LOG
#undef ALWAYS_SYNC_GYROS
//#define ALWAYS_SYNC_GYROS
#undef TILT_STOP
#define TILT_STOP 60
#endif // GYRO_DRIFT

#ifdef RECORD_OFFSETS
#undef LOG_IMU_WP2
#undef LOGGER_HZ
#define LOGGER_HZ 10
//#define LOGGER_HZ 1
#ifndef ALWAYS_LOG
#define ALWAYS_LOG
#endif // ALWAYS_LOG
#endif // RECORD_OFFSETS

#ifdef CROSS_COUPLING
#define ADJUST_THETA
#define SIMULATE_TILT
#define LOG_R_UPDATE
#define WARM_UP_TIME 210
#define RUN_TIME 30
#ifndef LOG_IMU_WP2
#define LOG_IMU_WP2               // logs IMU data during a run for wolf_pac version 2
#endif // LOG_IMU_WP2
#ifndef LOG_RESIDUALS
#define LOG_RESIDUALS         // logs residual offsets between runs
#endif //LOG_RESIDUALS
#undef RESIDUAL_LOG_PERIOD
#define RESIDUAL_LOG_PERIOD 1  // 60 times per minute
#undef LOGGER_HZ
#define LOGGER_HZ 1
#endif // CROSS_COUPLING

#ifdef LOG_VELOCITY
#undef LOGGER_HZ
#define LOGGER_HZ 20
#undef ALWAYS_LOG
#endif // LOG_VELOCITY

#ifdef TEST_GYRO_LOCK 
#define ALWAYS_SYNC_GYROS
#define ALWAYS_LOG
#undef LOGGER_HZ
#define LOGGER_HZ 1
#endif // TEST_GYRO_LOCK

#ifdef LOG_PITCH_AND_TWO_FORCES
#undef LOGGER_HZ
#define LOGGER_HZ 200
#endif // LOG_PITCH_AND_TWO_FORCES

#ifdef ROAD_TEST
#undef ALWAYS_LOG
#undef LOGGER_HZ
//#define ALWAYS_LOG
#define LOGGER_HZ 40
#endif // ROAD_TEST

#ifdef BUILD_OFFSET_TABLE
#define ALWAYS_LOG
#undef LOG_IMU_WP2
#define BUILD_OFFSET_HZ 200
#endif // 

#ifdef CONING_CORRECTION
#define FILTERING "Force data reported at 100 or 200 Hz is a 5 sample average of 1000 Hz sampling.\r\n"
#else
#define FILTERING "Force data is filtered by averaging pairs of 200 Hz samples.\r\n"
#endif // CONING_CORRECTION

#define TEST_LIDAR 0

#define DR_TAU 2.5

#define GPS_TYPE						GPS_NONE
#define NO_RADIO						1
#define MAG_YAW_DRIFT 						0
#define DEBUG_MAG						0

#define NUM_INPUTS	7
#define NUM_OUTPUTS	4

#define CONSOLE_UART            0
#define HILSIM			0

#if (GYRO_RANGE==1000)
//#define GYRO_OFFSET_MARGIN 1000
#define GYRO_OFFSET_MARGIN 100
#elif (GYRO_RANGE==500)
#define GYRO_OFFSET_MARGIN 50
#else
#error "invalid GYRO_RANGE"
#endif // GYRO_RANGE

#define GYRO_VARIANCE_MARGIN 150

#define MATRIX_GYRO_OFFSET_MARGIN 100

////////////////////////////////////////////////////////////////////////////////
// Use board orientation to change the mounting direction of the board.
// The following 4 orientations have the board parallel with the ground.
// ORIENTATION_FORWARDS:  Component-side up,   GPS connector front
// ORIENTATION_BACKWARDS: Component-side up,   GPS connector back
// ORIENTATION_INVERTED:  Component-side down, GPS connector front
// ORIENTATION_FLIPPED:   Component-side down, GPS connector back
// The following 2 orientations are "knife edge" mountings
// ORIENTATION_ROLLCW: Rick's picture #9, board rolled 90 degrees clockwise,
//		from point of view of the pilot
// ORIENTATION_ROLLCW180: Rick's pitcure #11, board rolled 90 degrees clockwise,
//		from point of view of the pilot, then rotate the board 180 around the Z axis of the plane,
//		so that the GPS connector points toward the tail of the plane
// ********** NOTE: orientations are withrespect to the front motor for + configuration,  *******
// or with respect to left front motor, for X configuration

#ifdef UPSIDE_DOWN
#define BOARD_ORIENTATION	ORIENTATION_FLIPPED
#else
#define BOARD_ORIENTATION	ORIENTATION_FORWARDS
#endif // 

#define CONTINUOUS_MATRIX_LOCKING 1 // option to perform matrix alignment 
// while waiting for the track to clear, must be set to 1 to use the option
#define JOSTLE_CHECK_PERIOD 2 // check jostle every 2 seconds

#define TEST_RUNTIME_TILT_ALIGN 0

#ifdef START_TRACK_LOG
#error "START_TRACK_LOG is probably not the option you are looking for"
#endif // START_TRACK_LOG

#define RMS_AND_LPF_GUI 0

#define EULER_GUI 0

#if (RMS_AND_LPF_GUI==1)
#undef LOG_IMU_WP2
#undef LOG_RESIDUALS
#undef NORMAL_RUN
#undef LOGGER_HZ
#define LOGGER_HZ 10
#endif // RMS_AND_LPF_GUI

#if (EULER_GUI==1)
#undef USE_PACKETIZED_TELEMERTY
#undef LOGGER_HZ
#undef LOG_IMU_WP2              
#undef NORMAL_RUN
#undef LOG_RESIDUALS
#define LOG_IMU_WP2              
#define NORMAL_RUN
#define LOG_RESIDUALS
#define LOGGER_HZ 10
#undef MATRIX_GYRO_OFFSET_MARGIN
#define MATRIX_GYRO_OFFSET_MARGIN 100
#endif // EULER_GUI_GUI

//#define RESIDUAL_HZ 10

#define CENTRIFUGAL_TESTING 0
#define TURTLE_TESTING 1

