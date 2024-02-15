/* 
 * File:   serial_output.h
 * Author: benjie
 *
 * Created on February 14, 2024, 2:51 PM
 */

#include "../../libUDB/libUDB.h"

#define PKT_CMD_HEADER 0xDE
#define PKT_CMD_START 0xD1
#define PKT_CMD_MSG 0xD2
#define PKT_CMD_STOP 0xD3
#define PKT_CMD_RUN_START 0xD4

void udb_serial_start_sending_data(void);
void serial_output(const char* format, ...);
void serial_output_send_packet_cmd(uint8_t cmd);
void udb_serial_stop_sending_data(void);
