import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime
import argparse
import io

NUM_COLS  = 11

XA_COL = 0
YA_COL = 1
ZA_COL = 2
YAW_COL = 3
PITCH_COL = 4
ROLL_COL = 5


global mark_state, mark_number
global roll_max , roll_ratio , peak_threshold , start_threshold
global heading_start , yaw_threshold

start_threshold = 15.0 # roll angle to detect the start of a curve
peak_threshold = 20.0 # roll angle to confirm a curve
yaw_threshold = 7.5
roll_ratio = 0.1 # value of roll/roll_max needed to detect end of curve
mark_number = 0
mark_state = 0

global line_numbers , yaws , rolls
line_numbers = []
yaws = []
rolls = []

global filter_size
filter_size = 10

global yaws_filtered , rolls_filtered , roll_rates_filtered
roll_rates_filtered = [ 0.0 ]

def count_curves () :
    global yaws_filtered , rolls_filtered , roll_rates_filtered
    for sample_number in range( len (rolls_filtered )) :
        two_phase_roll_update_timing_marks(roll_rates_filtered[sample_number] , rolls_filtered[sample_number] , yaws_filtered[sample_number] )
        

def compute_roll_rates() :
    global rolls_filtered , roll_rates_filtered
    for line_index in range ( 1 , len(rolls_filtered)) :
        roll_rate = ( rolls_filtered[line_index] - rolls_filtered[line_index-1] ) * 100.0
        roll_rates_filtered.append(roll_rate)
    

def filter_data () :
    global yaws_filtered , rolls_filtered 
    global yaws , rolls 
    yaw_filt_once = mav_filter( yaws , indices(filter_size ))
    roll_filt_once = mav_filter( rolls , indices(filter_size ))
    yaws_filtered = mav_filter( yaw_filt_once , indices(filter_size ))
    rolls_filtered = mav_filter( roll_filt_once , indices(filter_size ))

def indices (size):
    table = []
    tab_index = 0
    offset = - size
    num_offsets = int(1+2*size)
    while tab_index < num_offsets:
        table.append(offset)
        offset = offset + 1
        tab_index = tab_index + 1
    return table

def mav_filter(raw_list,index_table):
    filter_table = []
    line = 0
    for dummy in raw_list:
        N = 0
        total = 0
        for index in index_table:
            try:
                total = total + raw_list[line+index]
                N = N + 1
            except:
                pass
        if N > 0:
            filter_table.append(total/N)
        else:
            filter_table.append(0)
        line = line + 1
    return filter_table

def read_data(run_file) :
    global line_numbers , yaws , rolls
    dataStr = run_file.read()
    lines = dataStr.splitlines(keepends=False)
    first_line = 1
    line_number = 0
    if dataStr:
        for line in lines:
            columns = line.split(',')
            if len(columns) == NUM_COLS:
                try:
                    yaw_in = float(columns[YAW_COL])
                    roll_in = float(columns[ROLL_COL])
                    line_numbers.append(line_number)
                    yaws.append(yaw_in)
                    rolls.append(roll_in)
                    line_number = line_number+1
                except ValueError:
                    pass

def run_steps() :
    read_data(input_file)
    filter_data()
    compute_roll_rates()
    count_curves()


def two_phase_roll_update_timing_marks(roll_rate , roll_out , heading ):
    global mark_state, mark_number
    global roll_max , roll_ratio , peak_threshold , start_threshold
    global heading_start , yaw_threshold
    
    if mark_state == 0:
        if abs(roll_out) > start_threshold:
            heading_start = heading
            mark_state = np.sign(roll_out)
            mark_number = mark_number + 1
            roll_max = start_threshold
    else:
        roll_max = max(abs(roll_out),roll_max)       

        if (abs(roll_out) < roll_ratio*roll_max ) and ( np.sign(roll_out) != np.sign(roll_rate)) and ( roll_max > peak_threshold ) and (abs(heading - heading_start) > yaw_threshold ):
            mark_state = 0
            mark_number = mark_number+1
            roll_max = start_threshold

def build_arg_parser():
    parser = argparse.ArgumentParser(
        prog='cc.py',
        description='computes the approximate number of curves in a run')
    parser.add_argument('-f', '--filename', help="file to be processed")
    parser.add_argument('-log', '--log' , action = 'store_true' , help="append result to a log file") 
    
    return parser



if __name__ == "__main__":
    parser = build_arg_parser()
    args = parser.parse_args()
    if args.filename:
        file_name = args.filename
        file_base_name = file_name.split('.')[0]
    else:
        print("you need to supply a file name")
        exit()
    if args.log :
        cc_log = open("fc_log.txt", "a")
    try :
        input_file = open(file_name)
    except :
        exit

    run_steps()

    print(int(mark_number/2))

    if args.log :
        cc_log.write(f"{int(mark_number/2)} , {file_name}\n")

