
import argparse
import sys

import numpy as np
import argparse
from math import sin, cos, atan2, sqrt, radians, degrees

global args_yrs , args_strmlt , args_log_time , args_dfs , args_adfc

args_yrs = False
args_strmlt = False
args_log_time = False
args_dfs = False
args_adfc = False

global elapsed
elapsed = 70.0


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
    #parser.add_argument('-s','--sort',action='store_true',help="Sort files by run time.")
    parser.add_argument('-fcn','--first_curve_number', help="First curve number.")
    parser.add_argument('-skip','--skip_list', help = "Skip list in quotes with commas, such as -skip \" 9 , 10 \" .")
    #parser.add_argument('-yrs','--yrs',action='store_true',help="use yaw rate for slicing into plotlets.")
    parser.add_argument('-curves','--curves',help="expected number of curves.")
    #parser.add_argument('-strmlt','--strmlt',action='store_true',help="option to prepare for streamlit plotting")
    parser.add_argument('-bill','--bill',action='store_true',help="generate the files that bill looks at")
    parser.add_argument('-bruce','--bruce',action='store_true',help="generate adjusted, 100 Hz and 1000 Hz files")
    parser.add_argument('-all','--all',action='store_true',help="generate all files")
    parser.add_argument('-zfl','--zfl',help="z force limit, f/s/s ")
    parser.add_argument('-fw','--fw',help="z force fine alignment weighting, default is 1.0")
    #parser.add_argument('-log_time','--log_time',action='store_true',help="log the time at key points in the data processing.")
    parser.add_argument('-cr','--cr',help="compass rotation, degrees, used to re-orient the x-y track map.")
    parser.add_argument('-y', '--y',help = "yaw misalignment.")
    parser.add_argument('-fhs','--fhs',help = "filter half size, window width = 2*fhs+1.")
    #parser.add_argument('-dfs','--dfs',action='store_true',help="dual filter switch : filter twice")
    parser.add_argument('-talc','--talc',help="extra time after last curve in seconds")
    parser.add_argument('-dtpe','--dtpe',help="delta time from peak of pull")
    parser.add_argument('-adfc','--adfc',action='store_true',help="option for all data on the first curve, starting from the pull")
    parser.add_argument('-e', '--elapsed', help="time window in seconds for the map")
    parser.add_argument('-b_radius','--b_radius',help="button radius in seconds, must be less than 2.0")
    parser.add_argument('-b_space','--b_space',help="space between button centers, seconds")
    parser.add_argument('-b_range','--b_range',help="search range, seconds, must be less than 2.0")
    
    
    args = parser.parse_args()

    if args.adfc :
        args_adfc = True

    if args.elapsed :
        elapsed = float(args.elapsed)

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
            #bat_file.write(f"cleanup.py\n")
        except :
            print("unable to open list of files, check spelling.")
            log_file.write("unable to open list of files, check spelling.\r")
            exit()
        dataStr = input_file.read()
        lines = dataStr.splitlines(keepends=False)
        new_format = False
        if dataStr:
            for line in lines :
                name_and_start = line.split(',')
                option_pieces = line.split('-')
                if len(option_pieces) > 2 :
                    options = line
                    new_format = True
                    continue
                data_file_name = name_and_start[0]
                data_file_base_name = data_file_name.split('.')[0]
                if len(name_and_start) > 1 :
                    data_file_start = round(float(name_and_start[1]),2)
                    log_file.write(f"start time for {data_file_name} = {data_file_start} was read from {list_of_files_file_name}\n")
                else :
                    data_file_start = compute_start(data_file_name )

                if data_file_start > 0 :
                    log_file.write(f"name = {data_file_base_name} , start = {data_file_start} \r")
                    if args.all :
                        bat_file.write(f"process_map_st_TS.py -all -f {data_file_name} -s {data_file_start} -e {elapsed}")
                    elif args.bruce :
                        bat_file.write(f"process_map_st_TS.py -bruce -f {data_file_name} -s {data_file_start} -e {elapsed}")
                    elif args.bill :
                        bat_file.write(f"process_map_s_TSt.py -bill -f {data_file_name} -s {data_file_start} -e {elapsed}")
                    else :
                        bat_file.write(f"process_map_st_TS.py -f {data_file_name} -s {data_file_start} -e {elapsed}")
                    if args_log_time :
                        bat_file.write(f" -log_time")
                    if args_strmlt  :
                        bat_file.write(f" -strmlt")
                    if args_dfs :
                        bat_file.write(f" -dfs")
                    if args.zfl :
                        bat_file.write(f" -zfl {args.zfl}")
                    if args_yrs :
                        bat_file.write(f" -yrs")
                    if args.curves :
                        bat_file.write(f" -curves {args.curves}")
                    if args.cr :
                        bat_file.write(f" -cr {args.cr}")
                    if args.y :
                        bat_file.write(f" -y {args.y}")
                    if args.fhs :
                        bat_file.write(f" -fhs {args.fhs}")
                    if args.dtpe :
                        bat_file.write(f" -dtpe {args.dtpe}")
                    if len(name_and_start) == 6 :
                        bat_file.write(f" {name_and_start[5]}")
                    try :
                        bat_file.write(f" {options}")
                    except :
                        pass
                    bat_file.write(f"\n")
                    merge_file.write(f"{data_file_base_name}_time_map_100_HZ.csv\n")
                else :
                    log_file.write(f"unable to determine start time for {data_file_name}, file will be skipped.\n")        
            
            
            bat_file.write(f"merge_st.py -f {base_name}_merge_list.txt")
            if args.curves :
                bat_file.write(f" -curves {args.curves}")
            if args_strmlt :
                bat_file.write(f" -strmlt")
            if args_log_time :
                bat_file.write(f" -log_time")
            try :
                bat_file.write(f" {options}")
            except :
                pass
            bat_file.write(f"\n")
            
            bat_file.write(f"slice_st_TS.py -f {base_name}_merge_list_plots.csv")
            if args.first_curve_number :
                bat_file.write(f" -fcn {args.first_curve_number}")
            if args.fw :
                bat_file.write(f" -fw {args.fw}")
            if args.skip_list:
                bat_file.write(f" -skip \" {args.skip_list} \"")
            if args_strmlt :
                bat_file.write(f" -strmlt")
            if args_log_time :
                bat_file.write(f" -log_time")
            if args.talc :
                bat_file.write(f" -talc {args.talc}")
            if args_adfc :
                bat_file.write(f" -adfc")
            if args.b_radius :
                bat_file.write(f" -b_radius {args.b_radius}")
            if args.b_space :
                bat_file.write(f" -b_space {args.b_space}")
            if args.b_range :
                bat_file.write(f" -b_range {args.b_range}")
                
            try :
                bat_file.write(f" {options}")
            except :
                pass
            bat_file.write(f"\n")
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
