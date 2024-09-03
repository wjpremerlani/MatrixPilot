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

rms_gauge = None
x_lpf_gauge = None
y_lpf_gauge = None
z_lpf_gauge = None

max_rms = 50
max_lpf = 400

RMS_IDLE = 0
RMS_START = 1
RMS_PARSE = 2
RMS_END = 3
RMS_WHICH_GAUGE = 4

RMS_GAUGE = 1
X_GAUGE = 2
Y_GAUGE = 3
Z_GAUGE = 4
W_GAUGE = 5

global gauge_number
gauge_number = RMS_GAUGE


count = 0
up = True

HOST = socket.gethostname()
PORT = 8101

output_file = None
nextConnectionNum = 1
depacketize = False


global rms_value, x_value , y_value , z_value
rms_value = 0
x_value = 0
y_value = 0
z_value = 0

def setup_gauges():
    global root, rms_gauge , x_lpf_gauge , y_lpf_gauge , z_lpf_gauge
    global rms_value, x_value , y_value , z_value
    
    root = tk.Tk()
    rms_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value=max_rms,
                               yellow = 30 ,
                               red = 50 ,
                               label='residual magnitude',
                               unit=' tics',
                               bg='grey')
    rms_gauge.grid(row=0, column=0, sticky='news')
    rms_gauge.set_value(0)

    x_lpf_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value=max_lpf,
                               min_value= -max_lpf,
                               yellow = 75 ,
                               yellow_low = 25 ,
                               red = 100 ,
                               red_low = 0 ,
                               label='x gyro lpf',
                               unit=' 16*tics',
                               bg='grey')
    x_lpf_gauge.grid(row=0, column=1, sticky='news')
    x_lpf_gauge.set_value(0)

    y_lpf_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value=max_lpf,
                               min_value= -max_lpf,
                               yellow = 75 ,
                               yellow_low = 25 ,
                               red = 100 ,
                               red_low = 0 ,
                               label='y gyro lpf',
                               unit=' 16*tics',
                               bg='grey')
    y_lpf_gauge.grid(row=1, column=0, sticky='news')
    y_lpf_gauge.set_value(0)
    
    z_lpf_gauge = tk_tools.Gauge(root,
                               width=350,
                               height=170,
                               max_value=max_lpf,
                               min_value= -max_lpf,
                               yellow = 75 ,
                               yellow_low = 25 ,
                               red = 100 ,
                               red_low = 0 ,
                               label='z gyro lpf',
                               unit=' 16*tics',
                               bg='grey')
    z_lpf_gauge.grid(row=1, column=1, sticky='news')
    z_lpf_gauge.set_value(0)

    
    root.update()



def update_gauges():
    global rms_gauge , x_lpf_gauge , y_lpf_gauge , z_lpf_gauge
    global rms_value , x_value, y_value, z_value
 
    # update the gauges according to their value
    rms_gauge.set_value(rms_value)
    x_lpf_gauge.set_value(x_value)
    y_lpf_gauge.set_value(y_value)
    z_lpf_gauge.set_value(z_value)
    
    root.update()

def parse_rms():
    global rms_value , x_value, y_value, z_value
    global gauge_number
    global data
    rms_state = RMS_IDLE
    for b in data :      
        if rms_state == RMS_IDLE :
            if b == ord("("):
                parse_value = bytearray()
                rms_state = RMS_WHICH_GAUGE
        elif rms_state == RMS_WHICH_GAUGE :
            if b == ord("w"):
                if debug == 1 :
                    print ("w")  
                gauge_number = W_GAUGE
            elif b == ord("r"):
                if debug == 1 :
                    print ("r")  
                gauge_number = RMS_GAUGE
            elif b == ord("x"):
                if debug == 1 :
                    print ("x")  
                gauge_number = X_GAUGE
            elif b == ord("y"):
                if debug == 1 :
                    print ("y")                
                gauge_number = Y_GAUGE
            elif b == ord("z"):
                if debug == 1 :
                    print ("z")  
                gauge_number = Z_GAUGE
            rms_state = RMS_PARSE
                  
        elif rms_state == RMS_PARSE :
            if b == ord(")"):
                rms_state = RMS_END
            else:
                parse_value.append(b)
        elif rms_state == RMS_END :
            if gauge_number == RMS_GAUGE :
                rms_value = int(parse_value)
                #print("rms = " , rms_value )
            elif gauge_number == X_GAUGE :
                x_value = int(parse_value)
                #print("x = " , x_value )
            elif gauge_number == Y_GAUGE :
                y_value = int(parse_value)
                #print("y = " , x_value )
            elif gauge_number == Z_GAUGE :
                z_value = int(parse_value)
                #print("z = " , x_value )
            rms_state = RMS_IDLE
 
def listen_to_client(conn):
    # This function is run for each incoming connection from a WolfPac, on a separate thread
    global nextConnectionNum
    global rms_residual
    global data
    readBuffer = bytearray()
    connectionNum = nextConnectionNum
    nextConnectionNum +=1

    with conn:
        if args.verbose:
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
        if args.verbose:
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
        if args.verbose:
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
    
