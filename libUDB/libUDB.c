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


#include "libUDB_internal.h"
#include "oscillator.h"
#include "interrupt.h"
#include "analogs.h"
#include "events.h"
#include "osd.h"

#if (USE_I2C1_DRIVER == 1)
#include "I2C.h"
#endif

// Include the NV memory services if required
#if (USE_NV_MEMORY == 1)
#include "NV_memory.h"
#include "data_storage.h"
#include "data_services.h"
#endif

// Include flexifunction mixers if required
#if (USE_FLEXIFUNCTION_MIXING == 1)
#include "../libflexifunctions/flexifunctionservices.h"
#endif


union udb_fbts_byte udb_flags;

// Functions only included with nv memory.
#if (USE_NV_MEMORY == 1)
UDB_SKIP_FLAGS udb_skip_flags = {0, 0, 0};

void udb_skip_radio_trim(boolean b)
{
	udb_skip_flags.skip_radio_trim = 1;
}

void udb_skip_imu_calibration(boolean b)
{
	udb_skip_flags.skip_imu_cal = 1;
}
#endif // (USE_NV_MEMORY == 1)

void udb_init(void)
{
	udb_flags.B = 0;

	init_analogs();

//	udb_init_ADC();
	init_events();
#if (USE_I2C1_DRIVER == 1)
	I2C1_Init();
#endif
#if (USE_NV_MEMORY == 1)
	nv_memory_init();
	data_storage_init();
	data_services_init();
#endif
#if (USE_FLEXIFUNCTION_MIXING == 1)
	flexiFunctionServiceInit();
#endif
	udb_init_clock();
	udb_init_capture();
#if (MAG_YAW_DRIFT == 1 && HILSIM != 1)
//	udb_init_I2C();
#endif
#if (CONSOLE_UART != 1)
	udb_init_GPS();
#endif
#if (CONSOLE_UART != 2)
	udb_init_USART();
#endif
	udb_init_pwm();
	osd_init();

//FIXME: add AUAV3 support
#if (BOARD_TYPE == UDB4_BOARD || BOARD_TYPE == UDB5_BOARD)
	udb_eeprom_init();
#endif

#if (BOARD_TYPE == UDB5_BOARD || BOARD_TYPE == AUAV3_BOARD)
	MPU6000_init16();
#endif

	SRbits.IPL = 0; // turn on all interrupt priorities
}

void udb_run(void)
{
#if (USE_MCU_IDLE == 1)
	Idle();
#else
	// pause cpu counting timer while not in an ISR
	indicate_loading_main;
#endif
}

#ifdef INITIALIZE_VERTICAL // for VTOL, vertical initialization
void udb_a2d_record_offsets(void)
{
#if (USE_NV_MEMORY == 1)
	if (udb_skip_flags.skip_imu_cal == 1)
		return;
#endif

	// almost ready to turn the control on, save the input offsets
	UDB_XACCEL.offset = UDB_XACCEL.value;
	udb_xrate.offset = udb_xrate.value;
	UDB_YACCEL.offset = UDB_YACCEL.value - (Y_GRAVITY_SIGN ((int16_t)(2*GRAVITY))); // opposite direction
	udb_yrate.offset = udb_yrate.value;
	UDB_ZACCEL.offset = UDB_ZACCEL.value;
	udb_zrate.offset = udb_zrate.value;
#ifdef VREF
	udb_vref.offset = udb_vref.value;
#endif
}
#else  // horizontal initialization
void udb_a2d_record_offsets(void)
{
#if (USE_NV_MEMORY == 1)
	if (udb_skip_flags.skip_imu_cal == 1)
		return;
#endif

#ifdef CUSTOM_OFFSETS
	// offsets have been measured manually and entered into the options.h file
	udb_xaccel.offset = XACCEL_OFFSET ;
	udb_yaccel.offset = YACCEL_OFFSET ;
	udb_zaccel.offset = ZACCEL_OFFSET ;
#if ( BOARD_TYPE == UDB4_BOARD )
	udb_xrate.offset  = udb_xrate.value;
	udb_yrate.offset  = udb_yrate.value;
	udb_zrate.offset  = udb_zrate.value;
#else
	udb_xrate.offset = XRATE_OFFSET ;
	udb_yrate.offset = YRATE_OFFSET ;
	udb_zrate.offset = ZRATE_OFFSET ;
#endif // UDB4_BOARD
#else
	// almost ready to turn the control on, save the input offsets
	UDB_XACCEL.offset = UDB_XACCEL.value;
	udb_xrate.offset  = udb_xrate.value;
	UDB_YACCEL.offset = UDB_YACCEL.value;
	udb_yrate.offset  = udb_yrate.value;
	UDB_ZACCEL.offset = UDB_ZACCEL.value + (Z_GRAVITY_SIGN ((int16_t)(2*GRAVITY))); // same direction
	udb_zrate.offset  = udb_zrate.value;
#endif	// CUSTOM_OFFSETS
#ifdef VREF
	udb_vref.offset   = udb_vref.value;
#endif
}
#endif // INITIALIZE_VERTICAL

// saturation logic to maintain pulse width within bounds
int16_t udb_servo_pulsesat(int32_t pw)
{
	if (pw > SERVOMAX) pw = SERVOMAX;
	if (pw < SERVOMIN) pw = SERVOMIN;
	return (int16_t)pw;
}
