
#############################################################################
# The pound sign, # , is for a comment.
# This section contains parameters that you might want to change.
# The port numpers are as follows for align tools 83, 86, 87, 88 and 89:
# 83 : 8102
# 86 : 8086
# 87 : 8087
# 88 : 8088
# 89 : 8089
#
PORT = 8107
#
# In order to label the gauges with the serial number of the alignement gauge,
# set SERIAL_NUMBER to 'sn83', 'sn86', 'sn87', 'sn88' or 'sn89',
# depending which alignment gauge will be using this particular script.
# The single quotes, ' , are required.
#
SERIAL_NUMBER = 's166'
#
# Set the maximum ranges of the yaw, pitch and roll gauges.
#
max_yaw = 200
max_pitch = 100
max_roll = 200
#
# Set the number of samples required for initialization.
#
REQUIRED_SAMPLES = 600
#
# Those are the only parameters that you might want to change.
#
###############################################################################



#!/usr/bin/python3
import time
import socket
import signal
import select
import sys
import threading
import argparse
import tkinter as tk
import tk_tools

root = None
debug = 0

lock_gauge = None
yaw_gauge = None
pitch_gauge = None
roll_gauge = None

max_lock = 50
#min_lock = -.001
min_lock = 0.0

EULER_IDLE = 0
EULER_START = 1
EULER_PARSE = 2
EULER_END = 3
EULER_WHICH_GAUGE = 4


ALIGN_POWER_UP = 0
ALIGN_INITIALIZE = 1
ALIGN_RUN = 2
ALIGN_TARE = 3
ALIGN_READY = 4

LOCK_GAUGE = 1
YAW_GAUGE = 2
PITCH_GAUGE = 3
ROLL_GAUGE = 4
W_GAUGE = 5

global gauge_number
gauge_number = W_GAUGE


count = 0
up = True

HOST = socket.gethostname()


output_file = None
nextConnectionNum = 1
depacketize = False


global lock_value, yaw_value , previous_yaw , pitch_value , roll_value , heading_value
global yaw_offset , pitch_offset, roll_offset , heading_offset 
lock_value = 0.0
yaw_value = 0.0
previous_yaw = 0.0
pitch_value = 0.0
roll_value = 0.0
yaw_offset = 0.0
pitch_offset = 0.0
roll_offset = 0.0
heading_offset = 0.0
heading_value = 0.0


global click_count
click_count = 0

global reset_flag
reset_flag = False
global LED

def align(on_off:bool):
    global reset_flag
    global click_count
    global LED
    global align_state
    try :
        if align_state == ALIGN_POWER_UP :
            LED.to_red()
            align_state = ALIGN_INITIALIZE
        else :     
            #click_count = click_count+1
            if align_state == ALIGN_TARE :
                LED.to_green()
                align_state = ALIGN_RUN
            elif align_state == ALIGN_RUN :
                LED.to_yellow()
                align_state = ALIGN_TARE
            elif align_state == ALIGN_READY :
                LED.to_green()
                align_state = ALIGN_RUN 
            #print("reset_flag = " , reset_flag )
            #print("click_couunt = "  , click_count)
    except :
        #print("LED not yet known")
        click_count = click_count + 1
def setup_gauges():
    global root, lock_gauge , yaw_gauge , pitch_gauge , roll_gauge
    global lock_value , yaw_value , pitch_value , roll_value
    global LED
    global status_label
    
    root = tk.Tk()

    #LED = tk_tools.Led(root)
    LED = tk_tools.Led(root,on_click_callback = align)
    LED.grid(row=0,column=2, sticky='news')

    status_label = tk.Label(root,text="status\nlabel",width = 15, height = 4, font = ('Helvetica','20') )
    status_label.grid(row=1,column=2, sticky='news')
    
    lock_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value= max_lock,
                                min_value = min_lock ,
                               yellow = 30 ,
                               red = 50 ,
                                label=SERIAL_NUMBER+' residual',
                               unit=' binary',
                               bg='grey')
    lock_gauge.grid(row=0, column=0, sticky='news')
    lock_gauge.set_value(0)

    yaw_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value=max_yaw,
                               min_value= -max_yaw,
                               yellow = 100 ,
                               yellow_low = 0 ,
                               red = 100 ,
                               red_low = 0 ,
                               label=SERIAL_NUMBER+' yaw',
                               unit=' degs',
                               bg='grey')
    yaw_gauge.grid(row=0, column=1, sticky='news')
    yaw_gauge.set_value(0)

    pitch_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value=max_pitch,
                               min_value= -max_pitch,
                               yellow = 100 ,
                               yellow_low = 0 ,
                               red = 100 ,
                               red_low = 0 ,
                               label=SERIAL_NUMBER+' pitch',
                               unit=' degs',
                               bg='grey')
    pitch_gauge.grid(row=1, column=0, sticky='news')
    pitch_gauge.set_value(0)
    
    roll_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value=max_roll,
                               min_value= -max_roll,
                               yellow = 100 ,
                               yellow_low = 0 ,
                               red = 100 ,
                               red_low = 0 ,
                               label=SERIAL_NUMBER+' roll',
                               unit=' degs',
                               bg='grey')
    roll_gauge.grid(row=1, column=1, sticky='news')
    roll_gauge.set_value(0)

    
    root.update()

global initial_delay

global required_samples
required_samples = REQUIRED_SAMPLES


def unwrap(angle_in) :
    if angle_in > 180 :
        return (angle_in - 360 )
    elif angle_in < -180 :
        return (angle_in + 360 )
    else :
        return angle_in        


global align_state
align_state = ALIGN_POWER_UP

def update_gauges():
    global lock_value, yaw_value , previous_yaw , pitch_value , roll_value , heading_value
    global yaw_offset , pitch_offset, roll_offset , heading_offset
    global status_label
    global required_samples
    global align_state
    global LED
    global reset_flag
    if align_state == ALIGN_POWER_UP :
        status_label.config(text="To Calibrate:\n1. Turn on wolf-pac\n2. Click Grey LED\nto start")
    elif align_state == ALIGN_INITIALIZE :
        status_label.config(text="Calibrating:\nRemaining\nSamples:\n"+str(int(required_samples)))
        if required_samples == 0 :
            align_state = ALIGN_READY
    elif align_state == ALIGN_READY :
        status_label.config(text="Calibration is\ncomplete.\nClick LED\nto continue.")
    elif align_state == ALIGN_RUN :
        status_label.config(text="Proceed to Align\n-or-\nClick LED to\nstart re-capture of\nSteel Orientation")
    elif align_state == ALIGN_TARE :
        status_label.config(text="Click LED to\nCapture\nSteel Orienation\nwith Wolf-Pac\nperfectly still")

    # update the gauges according to their value
    if align_state == ALIGN_RUN :
        lock_gauge.set_value(lock_value)
        yaw_gauge.set_value(unwrap(yaw_value-yaw_offset))
        pitch_gauge.set_value(unwrap(pitch_value-pitch_offset))
        roll_gauge.set_value(unwrap(roll_value-roll_offset))
    else  :
        lock_gauge.set_value(lock_value)
        yaw_offset = yaw_value
        pitch_offset = pitch_value
        roll_offset = roll_value
        yaw_gauge.set_value(0)
        pitch_gauge.set_value(0)
        roll_gauge.set_value(0)
    
    root.update()

def parse_rms():
    global lock_value , yaw_value , pitch_value , roll_value , w_value
    global gauge_number
    global data
    global required_samples
    rms_state = EULER_IDLE
    parse_value = bytearray()
    for b in data :      
        if rms_state == EULER_IDLE :
            if b == ord("("):
                rms_state = EULER_WHICH_GAUGE
        elif rms_state == EULER_WHICH_GAUGE :
            if b == ord("W"):
                if debug == 1 :
                    print ("W")  
                gauge_number = W_GAUGE
            elif b == ord("L"):
                if debug == 1 :
                    print ("L")  
                gauge_number = LOCK_GAUGE
            elif b == ord("Y"):
                if debug == 1 :
                    print ("Y")  
                gauge_number = YAW_GAUGE
            elif b == ord("P"):
                if debug == 1 :
                    print ("P")                
                gauge_number = PITCH_GAUGE
            elif b == ord("R"):
                if debug == 1 :
                    print ("R")  
                gauge_number = ROLL_GAUGE
            rms_state = EULER_PARSE
                  
        elif rms_state == EULER_PARSE :
            if b == ord(")"):
                rms_state = EULER_END
            else:
                parse_value.append(b)
        elif rms_state == EULER_END :
            if gauge_number == W_GAUGE :
                w_value = int(parse_value)
                parse_value = bytearray()
            if gauge_number == LOCK_GAUGE :
                lock_value = float(parse_value)
                parse_value = bytearray()
                if required_samples > 0 :
                    required_samples = required_samples - 1
            elif gauge_number == YAW_GAUGE :
                yaw_value = float(parse_value)
                parse_value = bytearray()
            elif gauge_number == PITCH_GAUGE :
                pitch_value = float(parse_value)
                parse_value = bytearray()
            elif gauge_number == ROLL_GAUGE :
                roll_value = float(parse_value)
                parse_value = bytearray()
            rms_state = EULER_IDLE
 
def listen_to_client(conn):
    # This function is run for each incoming connection from a WolfPac, on a separate thread
    global nextConnectionNum
    global lock_value
    global data
    readBuffer = bytearray()
    connectionNum = nextConnectionNum
    nextConnectionNum +=1

    with conn:
        #if args.verbose:
        print(f"!!! Connection {connectionNum} Open", file=sys.stderr)
        inputs = [conn]
        while True:
            readable, writable, exceptional = select.select(inputs, [], inputs, 1.0)
            if exceptional:
                break
            if readable:
                try:
                    data = conn.recv(1024)
                    if depacketize:
                        readBuffer += data
                        data = process_packet_data(readBuffer)

                    if len(data):
                        parse_rms()
                        if output_file:
                            output_file.write(data)
                            output_file.flush()

                        outStr = data.decode("unicode_escape", errors='ignore')
                        print(outStr, end='')
                except (TimeoutError, ConnectionResetError):
                    break
            else:
                # Send 1 char per second while we're not receiving data, so the TCP layer
                # will eventually notice when a connected ESP32 gets turned off.
                conn.send(b".")
        #if args.verbose:
        print(f"!!! Connection {connectionNum} Closed", file=sys.stderr)


STATE_IDLE = 0
STATE_GET_CMD = 1
STATE_GET_LENH = 2
STATE_GET_LENL = 3
STATE_GET_BYTE = 4

PACKET_MAGIC = 0xDE
PACKET_CMD_START = 0xD1
PACKET_CMD_MSG = 0xD2
PACKET_CMD_END = 0xD3
PACKET_CMD_RUN = 0xD4
CONTROL_BYTES = [PACKET_MAGIC, PACKET_CMD_START, PACKET_CMD_MSG, PACKET_CMD_END, PACKET_CMD_RUN]


def process_packet_data(read_buffer):
    out_data = bytearray()
    packet_data_bytes_read = 0
    bytes_read = 0
    state = STATE_IDLE
    packet_len = 0

    for b in read_buffer.copy():
        bytes_read += 1
        if state == STATE_GET_BYTE:
            out_data.append(b)
            if b in CONTROL_BYTES:
                print(f"!!! Control byte '{b}' inside packet data of length {packet_len}", file=sys.stderr)
            packet_data_bytes_read += 1
            if packet_data_bytes_read == packet_len:
                del read_buffer[:bytes_read]
                return bytes(out_data)
        elif state == STATE_IDLE:
            if b == PACKET_MAGIC:
                state = STATE_GET_CMD
            elif b in CONTROL_BYTES:
                print(f"!!! Control byte '{b}' found outside of a packet", file=sys.stderr)
            else:
                print(chr(b), end='', file=sys.stderr)
                del read_buffer[:bytes_read]
                bytes_read = 0
        elif state == STATE_GET_CMD:
            if b == PACKET_CMD_START:
                if args.verbose:
                    print("!!! Open File", file=sys.stderr)
                del read_buffer[:bytes_read]
                bytes_read = 0
                state = STATE_IDLE
            elif b == PACKET_CMD_END:
                if args.verbose:
                    print("!!! Close File", file=sys.stderr)
                del read_buffer[:bytes_read]
                bytes_read = 0
                state = STATE_IDLE
            elif b == PACKET_CMD_MSG:
                state = STATE_GET_LENH
            elif b == PACKET_CMD_RUN:
                if args.verbose:
                    print("!!! Start Run", file=sys.stderr)
                del read_buffer[:bytes_read]           
                bytes_read = 0
                state = STATE_IDLE
            else:
                print("!!! Bad Packet Command", file=sys.stderr)
        elif state == STATE_GET_LENH:
            packet_len = int(b)*256
            state = STATE_GET_LENL
        elif state == STATE_GET_LENL:
            packet_len += int(b)
            state = STATE_GET_BYTE

    return bytes()


def server_program():
    # Main server function runs on the main thread and accepts new connections
    # We allow multiple (up to 8, why not) connections at once, because if you turn an ESP32 off and back on while
    # connected, it will try to reconnect while this server still hasn't realized that the previous connection is dead.
    # global rms_residual
    # rms_residual = 0
    setup_gauges()

    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
        server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        # Cause the server.accept() to timeout after 0.05sec, so that the loop below will cycle fast enough to update the UI
        server.settimeout(0.05)
        server.bind((HOST, PORT))
        server.listen(8)
        #if args.verbose:
        print(f"!!! Listening on port {PORT}...", file=sys.stderr)
        while True:
            try:
                conn, addr = server.accept()
                conn.settimeout(0)
                threading.Thread(target=listen_to_client, daemon=True, args=(conn,)).start()
            except socket.timeout:
                pass
            update_gauges()  # update the UI every 0.05sec

    
def ctrl_c_handler(signum, frame):
    # Handle Ctrl-C cleanly, as the primary means of quitting/exiting
    if args.verbose:
        print("\n!!! Quitting\n", file=sys.stderr)
    if output_file:
        output_file.close()
    root.destroy()  # Close the UI window cleanly when we're done
    exit()


# When this script is run directly, parse incoming command line args, and then
# set up the Ctrl-C handler and start up the server if appropriate.
if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        prog='debug_listener.py',
        description='Listens on a TCP port for data over connections from Wolf-Pac boards running WIFI_SERIAL ESP32 firmware')
    parser.add_argument('-i', '--show-ip-address', action='store_true', help="Print this computer's ip address")
    parser.add_argument('-p', '--port', help="Set the port to listen on (default 8086)")
    parser.add_argument('-d', '--depacketize', action='store_true', help="If this option is specified, process data as packets, and report any errors")
    parser.add_argument('-f', '--filename', help="Optionally output to a file")
    parser.add_argument('-v', '--verbose', action='store_true', help="Output status messages to stderr, for debugging.")
    args = parser.parse_args()

    if args.show_ip_address:
        print(f"Running in Python {sys.version}")
        try:
            addr = socket.gethostbyname(hostname)
            print(f"This computer's IP address is {addr}")
        except:
            hostname = socket.gethostname()
            print(f"This computer's hostname is {hostname}")
            try:
                addr = socket.gethostbyname(hostname)
                print(f"This computer's IP address is {addr}")
            except:
                try:
                    addr = socket.gethostbyname(socket.getfqdn())
                    print(f"This computer's IP address is {addr}")
                except:
                    print(f"Determining IP address failed.")
        exit(0)

    if args.depacketize:
        depacketize = True

    if args.filename:
        output_file = open(args.filename, "wb")

    if args.port:
        PORT = int(args.port)

    signal.signal(signal.SIGINT, ctrl_c_handler)
 
    server_program()
    
