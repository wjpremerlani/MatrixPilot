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


#include "libUDB.h"
#include "oscillator.h"
#include "interrupt.h"
#include "heartbeat.h"
#include "serialIO.h"
#include "servoOut.h"
#include "radioIn.h"
#include "eeprom_udb4.h"
#include "ADchannel.h"
#include "mpu6000.h"
#include "analogs.h"
#include "events.h"
#include "osd.h"
#include "options_ports.h"

#if (USE_I2C1_DRIVER == 1)
#include "I2C.h"
#endif

// Include the NV memory services if required
#if (USE_NV_MEMORY == 1)
#include "NV_memory.h"
#include "../MatrixPilot/data_storage.h"
#include "../MatrixPilot/data_services.h"
#endif

// Include flexifunction mixers if required
#if (USE_FLEXIFUNCTION_MIXING == 1)
#include "../libflexifunctions/flexifunctionservices.h"
#endif

//#include "../MatrixPilot/telemetry.h"
//#include "../libDCM/gpsParseCommon.h"

// TODO: do something about these declarations being here - RobD
void udb_init_ADC(void);
void udb_init_clock(void);

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

//	init_analogs();

//	udb_init_ADC();
//	init_events();
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
//	radioIn_init(); // was udb_init_capture();
#if (MAG_YAW_DRIFT == 1 && HILSIM != 1)
//	udb_init_I2C();
#endif
//	servoOut_init(); // was udb_init_pwm()
//	osd_init();

//FIXME: add AUAV3 support
#if (BOARD_TYPE == UDB4_BOARD || BOARD_TYPE == UDB5_BOARD || BOARD_TYPE == UDB7LUGE_BOARD)
//	udb_eeprom_init();
#endif

#if (BOARD_TYPE == UDB5_BOARD || BOARD_TYPE == AUAV3_BOARD || BOARD_TYPE == UDB7LUGE_BOARD)
	MPU6000_init16(&heartbeat);
#endif

	udb_init_irq(); // turn on all interrupt priorities
}

extern void gyro_sleep() ;
extern uint16_t no_jostle_count ;

// for testing purposes, equivalent to a delay of 2*10 = 20 seconds
//#define MAX_NO_JOSTLE 10 
// for production purposes, equivalent to a delay of 2*1800 = 3600 seconds
#define MAX_NO_JOSTLE 1800

// udb_run either goes into idle mode or all power down mode,
// depending on how long there has not been any jostling.
// when there has not been any jostling for a time period equal to
// 2*MAX_NO_JOSTLE seconds, the wolf_pac shuts off all power loads.
// after that it will require the power to be turned off and back on.

#define NEEDED_ZEROS 100
int16_t number_of_zeros = 0 ;
boolean is_even = true ;
uint16_t battery_counter = 0 ;

void udb_run(void)
{
#ifdef BATTERY_SAVER
    // Wait for 1 second after boot before starting to test the battery sensor pin
    static boolean boot_settled = false;
    if ( udb_heartbeat_counter > HEARTBEAT_HZ ) boot_settled = true;
    
#ifdef LV_DETECTION
    
    {
        if ( battery_counter ++ == HEARTBEAT_HZ)
        {
            battery_counter = 0 ;
            if ( is_even )
            {
                if(boot_settled && _RD8 == 0 )
                {
                    number_of_zeros ++ ;
                }
                else
                {
                    if ( number_of_zeros > 0 )
                    {
                        number_of_zeros -- ;
                    }
                }
                _TRISD8 = 0 ;
                _LATD8 = 1 ;
                
            }
            else
            {
                _TRISD8 = 1 ;
                
            }
            is_even = ! is_even ;
        }
    }
    
    
#endif
    if ( ( no_jostle_count > MAX_NO_JOSTLE ) || (number_of_zeros > NEEDED_ZEROS) ) {
        SRbits.IPL = 7; // turn off the interrupts
        delay_us(100); // wait for any in-progress communications to stop
        gyro_sleep(); // turn off the gyros
        delay_us(320); // wait
        LED_RED = LED_OFF; // turn off the LEDs
        LED_GREEN = LED_OFF;
        _LATD15 = 0; // turn off the ESP32
        _LATF2 = 0; // turn off the supply for the battery sense pull-up

        // Sleep hardening. Do not rely on SRbits.IPL alone to keep the core
        // asleep: mask every interrupt source, and stop the peripherals that
        // would otherwise keep driving pins into the powered down loads.
        U2MODEbits.UARTEN = 0; // UART2 must stop talking to the ESP32
        U2STAbits.UTXEN = 0;
        SPI2STATbits.SPIEN = 0; // SPI2 is the IMU bus on the UDB5/luge board
        AD1CON1bits.ADON = 0; // stop the A/D converter and its DMA front end
        PMD1 = 0xFFFF; // turn off every peripheral module
        PMD2 = 0xFFFF;
        IEC0 = IEC1 = IEC2 = IEC3 = IEC4 = 0; // mask every peripheral interrupt
        IFS0 = IFS1 = IFS2 = IFS3 = IFS4 = 0; // clear any request that is already pending
        
        Sleep(); // turn off the dsPIC
        Nop(); // Always put a NOP after sleep
        
        // We should never get here, but if we do, don't leave
        while(1);
    }
#endif
    // pause cpu counting timer while not in an ISR
    indicate_loading_main;
    Idle();
}
