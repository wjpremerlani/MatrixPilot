
import argparse
import sys

import numpy as np
import argparse
from math import sin, cos, atan2, sqrt, radians, degrees

NUM_COLS  = 11

XA_COL = 0 
YA_COL = 1 
ZA_COL = 2 
YAW_COL = 3 
PITCH_COL = 4 
ROLL_COL = 5

T0_SPIKE_HALF_WIDTH = 0.15

# Once we find the highest x_acceleration peak during the start, look for a slightly earlier one of at least this
# scale of the largest, in case the 1st peak is not actually largest
PRE_PEAK_SCALE = 0.7



global log_rate
log_rate = 100.0
def SLR(time) :
    return int(time * log_rate )



global x_force_rows , roll_rows

def compute_start(file_name) :   
    global x_force_rows , roll_rows
    x_force_rows = []
    roll_rows = []  
    try :
        input_file = open(file_name)
        data = input_file.read()
    except :
        print("unable to open file " , file_name , " file will be skipped.\n")
        log_file.write(f"unable to open file {file_name}, file will be skipped.\n")
        return -1
    lines = data.splitlines(keepends=False)
    for line in lines :
        columns = line.split(',')
        if len(columns) == NUM_COLS :
            try :
                x_force = float(columns[XA_COL])
                x_force_rows.append(x_force)
                roll = float(columns[ROLL_COL])
                roll_rows.append(roll)
            except ValueError:
                pass
        else:
            pass
    first_turn = SLR(10)
    first_turn_roll = 20 
    first_turn_padding = SLR(3)

    # Find first roll
    for i in range(first_turn, len(roll_rows), 20):
        if abs(roll_rows [ i] ) > first_turn_roll and abs(roll_rows [ i+1]) > first_turn_roll and abs(roll_rows [ i+2]) > first_turn_roll :
            first_turn = i
            break

    # Find X_ACC peak before first turn
    halfW = SLR(T0_SPIKE_HALF_WIDTH)
    start = max(halfW, first_turn-SLR(20))
    peak = np.argmax(x_force_rows[start:first_turn-first_turn_padding]) + start


    # In case there was a slightly lower peak within 2.0 sec, use that as t0
    start = max(0, peak-SLR(2.0))
    prepeak = np.argmax(x_force_rows[start:peak-SLR(0.25)])+start
    if x_force_rows[prepeak] > x_force_rows[peak] * PRE_PEAK_SCALE:
        peak = prepeak

    start_time = float(peak)/float(log_rate)

    log_file.write(f"computed start time for file {file_name} is {round(start_time,2)}\n")

    return round(float(peak)/float(log_rate),2)
            

if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='prep.py',
        description='Prepares for the Wright brothers two-step.')
    parser.add_argument('-f','--filename', help="Name of the file containing a list of files of run data.")
    parser.add_argument('-s','--sort',action='store_true',help="Sort files by run time.")
    parser.add_argument('-fcn','--first_curve_number', help="First curve number.")
    parser.add_argument('-skip','--skip_list', help = "Skip list in quotes with commas, such as -skip \" 9 , 10 \" .")
    parser.add_argument('-yrs','--yrs',action='store_true',help="use yaw rate for slicing into plotlets.")
    parser.add_argument('-curves','--curves',help="expected number of curves.")
    
    args = parser.parse_args()

    if args.filename :
        list_of_files_file_name = args.filename
        print("name of list of files : ",list_of_files_file_name)
        file_name_parts = list_of_files_file_name.split('.' )
        base_name = file_name_parts[0]
        log_file = open(base_name+"_log.txt" , "w" )
        bat_file = open(base_name+".bat" , "w" )
        merge_file = open(base_name+"_merge_list.txt" , "w" )
        print("base name = " , base_name )
        log_file.write(f"base name = {base_name} \r")  
        try :
            input_file = open(list_of_files_file_name)
            print(list_of_files_file_name," was opened.")
            log_file.write(f"{list_of_files_file_name} was opened.\r")
            log_file.write(f"data file descriptors: \r")
            bat_file.write(f"cleanup.py\n")
        except :
            print("unable to open list of files, check spelling.")
            log_file.write("unable to open list of files, check spelling.\r")
            exit()
        dataStr = input_file.read()
        lines = dataStr.splitlines(keepends=False)
        if dataStr:
            for line in lines :
                name_and_start = line.split(',')
                data_file_name = name_and_start[0]
                data_file_base_name = data_file_name.split('.')[0]
                if len(name_and_start) > 1 :
                    data_file_start = round(float(name_and_start[1]),2)
                    log_file.write(f"start time for {data_file_name} = {data_file_start} was read from {list_of_files_file_name}\n")
                else :
                    data_file_start = compute_start(data_file_name )
                if data_file_start > 0 :
                    log_file.write(f"name = {data_file_base_name} , start = {data_file_start} \r")            
                    bat_file.write(f"map.py -bill -f {data_file_name} -s {data_file_start} -e 60.0")
                    if args.yrs :
                        bat_file.write(f" -yrs")
                    if args.curves :
                        bat_file.write(f" -curves {args.curves}")
                    bat_file.write(f"\n")
                    merge_file.write(f"{data_file_base_name}_time_map_100_HZ.csv\n")
                else :
                    log_file.write(f"unable to determine start time for {data_file_name}, file will be skipped.\n")        
            if args.sort :
                bat_file.write(f"sort.py -f {base_name}_sorted_merge_list.txt\n")
                bat_file.write(f"merge.py -f {base_name}_sorted_merge_list.txt")
                if args.curves :
                    bat_file.write(f" -curves {args.curves}")
                bat_file.wriite(f"\n")
                bat_file.write(f"slice.py -f {base_name}_sorted_merge_list_plots.csv -zeros 100")
            else :
                bat_file.write(f"merge.py -f {base_name}_merge_list.txt")
                if args.curves :
                    bat_file.write(f" -curves {args.curves}")
                bat_file.write(f"\n")
                bat_file.write(f"slice.py -f {base_name}_merge_list_plots.csv -zeros 100")
            if args.first_curve_number :
                bat_file.write(f" -fcn {args.first_curve_number}")
            if args.skip_list:
                bat_file.write(f" -skip \" {args.skip_list} \"")
            bat_file.write(f"\n")
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
