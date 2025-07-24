global args_strmlt , args_only_curves , args_log_time , all_data_first_curve
global args_curve_number
args_strmlt = True
args_only_curves = False
args_log_time = False
all_data_first_curve = False
args_curve_number = False

global shift_range , margin , start_margin , end_margin , minimum_curve_duration , minimum_roll
global time_after_last_curve
#shift_range determines the minimum and maximum shit in the range of elements
#used to scan cross variance as a function of element number shift
#start_margin and end_margin define the extra number of elements included when slicing a portion of a run into a plotlet
#minimum_roll defines the data window in which variance weights are non-zero
shift_range = 200 #time shift range of +- 2 seconds
#shift_range = 20 #time shift range of +- .2 seconds
#art_margin = 20 # .2 seconds worth of data
#end_margin = 5
start_margin = 0 
end_margin = 0
#end_margin = 150
minimum_roll = 15.0
time_after_last_curve = 300

import argparse
import sys
import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime

global number_of_zeros
number_of_zeros = 0

minimum_curve_duration = 50 # minimum time steps for valid curve marks

global STATE_COLUMN, ROLL_COLUMN ,TIME_COLUMN
TIME_COLUMN = 0
STATE_COLUMN = 2
ROLL_COLUMN = 6
PITCH_COLUMN = 7 
YAW_COLUMN = 8
Z_FORCE_COLUMN = 5
Y_FORCE_COLUMN = 4

global CURVE_START_COLUMN , CURVE_END_COLUMN
CURVE_START_COLUMN = 2
CURVE_END_COLUMN = 3

global only_curve_number , first_curve_number
first_curve_number = 0

global plotlet_offsets , plotlet_size

global cross_indices

global columns_per_run , columns_per_line
global column_numbers 
global number_of_runs , run_numbers
run_numbers = []

global rows , row_numbers , number_of_rows , labels , label_names


global states , rolls , pitches, times , yaws , matrices , z_forces , y_forces, fz_max , fz_min
states = []
rolls = []
pitches = []
yaws = []
times = []
matrices = []
z_forces = []
y_forces = []
fz_max = []


global hex_byte
hex_byte = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
global colors
colors = []

for msb in range(16) :
    for lsb in range(16) :
        color = "#"+hex_byte[msb]+hex_byte[lsb]+"FF00"
        colors.append(color)

for msb in range(16) :
    for lsb in range(16) :
        color = "#FF"+hex_byte[15-msb]+hex_byte[15-lsb]+"00"
        colors.append(color)




global alignment_offsets , alignment_variances , alignment_variance
alignment_offsets = []
alignment_variances = []
alignment_variance = 0

def create_yaw_matrix(angle) :
    y_mat = np.zeros((3,3))
    y_mat[0,0] = cos(radians(angle))
    y_mat[0,1] = -sin(radians(angle))
    y_mat[0,2] = 0.0
    y_mat[1,0] = sin(radians(angle))
    y_mat[1,1] = cos(radians(angle))
    y_mat[1,2] = 0.0
    y_mat[2,0] = 0.0
    y_mat[2,1] = 0.0
    y_mat[2,2] = 1.0
    return y_mat

def create_pitch_matrix(angle) :
    p_mat = np.zeros((3,3))
    p_mat[0,0] = cos(radians(angle))
    p_mat[0,1] = 0.0
    p_mat[0,2] = sin(radians(angle))
    p_mat[1,0] = 0.0
    p_mat[1,1] = 1.0
    p_mat[1,2] = 0.0
    p_mat[2,0] = -sin(radians(angle))
    p_mat[2,1] = 0.0
    p_mat[2,2] = cos(radians(angle))
    return p_mat
   

def create_roll_matrix(angle) :
    r_mat = np.zeros((3,3))
    r_mat[0,0] = 1.0
    r_mat[0,1] = 0.0
    r_mat[0,2] = 0.0
    r_mat[1,0] = 0.0
    r_mat[1,1] = cos(radians(angle))
    r_mat[1,2] = -sin(radians(angle))
    r_mat[2,0] = 0.0
    r_mat[2,1] = sin(radians(angle))
    r_mat[2,2] = cos(radians(angle))
    return r_mat

def create_ypr_matrix(yaw,pitch,roll) :
    y_mat = create_yaw_matrix(yaw)
    p_mat = create_pitch_matrix(pitch)
    r_mat = create_roll_matrix(roll)
    yp_mat = np.matmul(y_mat,p_mat)
    ypr_mat = np.matmul(yp_mat,r_mat)
    return ypr_mat


def matrix_to_angle_axis(input_matrix) :
    angles = []
    roll = degrees (( input_matrix[2,1] - input_matrix[1,2] ) / 2.0 )
    pitch = degrees (( input_matrix[0,2] - input_matrix[2,0] ) / 2.0 )
    yaw = degrees (( input_matrix[1,0] - input_matrix[0,1] ) / 2.0 )
    angles.append(roll)
    angles.append(pitch)
    angles.append(yaw)
    return angles

global fetch_valid , skip

#perform a protected extraction of a value from an array
#that allows the index to fall outside of the list
def fetch_line_run ( array_of_values, index , run  ) :
    global fetch_valid
    if index < 0 :
        fetch_valid = False
        return 0
    else :
        try :
            value = array_of_values[index][run]
        except :
            fetch_valid = False
            value = 0
        return value 

global fetch_valid_true , fetch_valid_false

fetch_valid_true = 0
fetch_valid_false = 0

#perform a protected extraction of a value from a list
#that allows the index to fall outside of the list
def fetch( list_of_values, index ) :
    global fetch_valid
    global fetch_valid_true , fetch_valid_false
    if index < 0 :
        fetch_valid = False
        fetch_valid_false = fetch_valid_false + 1
        return 0
    else :
        try :
            value = list_of_values[index]
            fetch_valid_true = fetch_valid_true + 1
        except :
            fetch_valid = False
            fetch_valid_false = fetch_valid_false + 1
            value = 0
        return value 

global force_wt
force_wt = 1.0

global N_minimum 
N_minimum = 50

global first_var_log
first_var_log = True
    
#compute the cross variance of list2 with respect to list1
#with list2 in effect shifted by offset elements
def cross_variance(list1, list2, offset , roll_list , plt_num , rn_num ) :
    global fetch_valid , skip , N_minimum , N_samples
    global minimum_roll , reference_rolls , rolls ,z_forces , y_forces, states
    global first_var_log
    variance_sum = 0.0
    weight_sum = 0.0
    z_variance = 0.0
    z_variance_sum = 0.0
    N = 0
    list2_index = offset
    for list1_index in range ( len ( list1)) :
        #initialize fetch_valid to be true
        #fetch() will set it to false if there is an issue
        #it will not change it if everything is ok
        fetch_valid = True
        value1 = fetch ( list1 , list1_index )      
        roll = fetch ( roll_list , list1_index )       
        value2 = fetch ( list2 , list2_index )      
        reference_roll = (fetch ( reference_rolls , list2_index ))
        state = fetch_line_run ( states , list2_index , rn_num )
        force = fetch_line_run ( z_forces , list2_index , rn_num )
        force_ref = fetch_line_run ( z_forces , list1_index , 0 )
        
        if fetch_valid == True :
            weight = abs(roll*reference_roll)
            variance_term = (value1-value2)*(value1-value2)*weight
            z_var_term = (force-force_ref)**2
            weight_sum = weight_sum + weight
            variance_sum = variance_sum + variance_term
            z_variance_sum = z_variance_sum + z_var_term
            N = N + 1
        list2_index = int(list2_index + 1)

    

    if ( N > N_minimum ) and ( weight_sum > 0 ):
        skip = False
        variance = variance_sum/weight_sum
        z_variance = (force_wt*z_variance_sum) / N
        if first_var_log == True :
            try :
                variance_file.write(f"plot_let_number,run_number,offset,yaw_var,force_var\n")
            except :
                pass
            first_var_log = False
        if rn_num != 0 :
            try :
                variance_file.write(f"{plt_num},{rn_num},{offset},{round((variance),2)},{round((z_variance),2)}\n")
            except :
                pass
        #log_file.write(f"offset = {offset} , N = {N} , weight_sum = {round(weight_sum,2)} , var = {round(variance,2)} \n")
        return variance + z_variance
    else :
        skip = True
        return 10000000000000.0


#determine the similarity of two plots as a function of a relative time shift between them
#this is done by computing the cross variance, the sum of the squares of the differences between plots
def compute_similarity (reference_list,input_list , roll_list , plt_num, rn_num ) :
    global alignment_variance , skip
    first_index = True
    best_index = 0
    if rn_num == 0 :
        return 0
    if (plt_num > 0) or ( all_data_first_curve == False ) :
        for index in cross_indices  :
            variance = cross_variance(reference_list,input_list,index , roll_list , plt_num, rn_num )
            if skip == False :
                #log_file.write(f"index = {index} , var = {variance} \n")
                if first_index == True :
                    minimum_variance = variance
                    first_index = False
                else :
                    if variance < minimum_variance :
                        best_index = index
                        minimum_variance = variance
            #log_file.write(f"var = {round(variance,2)} , min_var = {round(minimum_variance,2)} , index = {index} , best = {best_index} \n")
        alignment_variance = sqrt(minimum_variance)
    else :
        minimum_variance = cross_variance(reference_list,input_list,0 , roll_list , plt_num, rn_num )
        best_index = 0
        alignment_variance = sqrt(minimum_variance)
    #log_file.write(f"best index = {best_index}\n")
    return best_index


#generates a list of indexes from 0 to size-1
def numbers(size) :
    number = 0
    list_of_numbers = []
    while number < size :
        list_of_numbers.append(number)
        number = number + 1
    return list_of_numbers

#generates a list of cross indexes from -size to +size
def create_cross_indices(size) :
    global cross_indices
    cross_indices = []
    cross_index = -int(abs(size))
    while cross_index <= size :
        cross_indices.append(cross_index)
        cross_index = cross_index + 1

global rows , row_numbers , number_of_rows , labels , label_names

def factor_labels () :
    global run_names , signal_names , number_of_runs , number_of_signals , row_numbers
    global label_names
    log_file.write(f"labels :\n {label_names}\n")
    run_names = []
    signal_names = []
    for label in label_names :
        label_parts = label.split('__')
        if label_parts[0] not in signal_names :
            signal_names.append(label_parts[0])
        if label_parts[1] not in run_names :
            run_names.append(label_parts[1])
    number_of_runs = len(run_names)
    number_of_signals = len(signal_names)
    log_file.write(f"number of runs = {number_of_runs}\n")
    log_file.write(f"run names = \n{run_names}\n")
    log_file.write(f"number of signals = {number_of_signals}\n")
    log_file.write(f"signal names = \n{signal_names}\n")

def open_file() :
    global states , rolls , pitches, yaws , times , matrices , z_forces , y_forces
    global number_of_runs , run_numbers
    global rows , row_numbers , number_of_rows , labels , label_names
    global columns_per_run
    global columns_per_line
    global column_numbers
    global fz_min
    global fy_min , fy_max
    global fz_min_all , fy_min_all , fy_max_all
    row_number = 0
    first_row = True
    rows = []
    row_numbers = []
    run_data = input_file.read()
    lines = run_data.splitlines(keepends=False)
    for line in lines :
        if first_row == True :
            labels = line
            label_names = labels.split(',')
            columns_per_line = len(label_names)
            column_numbers = numbers(columns_per_line)
            found_blanks = False
            run_number = 0          
            if args_strmlt :
                factor_labels()
                for index in range(number_of_runs) :
                    run_numbers.append(index)
                log_file.write(f"number of runs : {number_of_runs}\n")
                log_file.write(f"run numbers : {run_numbers}\n")
            else :
                for label_name in label_names :             
                    if ( label_name != "   ") and ( found_blanks == False ):
                        run_numbers.append(run_number)
                        run_number = run_number + 1
                    else :
                        found_blanks = True
            first_row = False
            
            if ( not args_strmlt) :
                number_of_runs = run_number
                columns_per_run = int((columns_per_line + 1 ) / (number_of_runs + 1))
            else :
                columns_per_run = number_of_signals
                
            print("number of runs = " , number_of_runs )
            print("run indices (which start from zero) = " , run_numbers )
            print("columns per line = " , columns_per_line )
            print("columns per run = " , columns_per_run )
        else :
            row = line.split(',')
            rows.append(row)
            row_numbers.append(row_number)
            state_row = []
            roll_row = []
            pitch_row = []
            matrix_row = []
            time_row = []
            yaw_row = []
            z_force_row = []
            y_force_row = []

            if args_strmlt :
                for run_number in run_numbers :
                    state_row.append(int(float((row[int(run_number + STATE_COLUMN*(number_of_runs))]))))
                    roll_row.append(float(row[int(run_number + ROLL_COLUMN*(number_of_runs))]))
                    z_force_row.append(float(row[int(run_number + Z_FORCE_COLUMN*(number_of_runs))]))
                    y_force_row.append(float(row[int(run_number + Y_FORCE_COLUMN*(number_of_runs))]))
                    time_row.append(float(row[int(run_number + TIME_COLUMN*(number_of_runs))]))
                    yaw_row.append(float(row[int(run_number + YAW_COLUMN*(number_of_runs))]))
                    pitch_row.append(float(row[int(run_number + PITCH_COLUMN*(number_of_runs))]))
                    euler_yaw = (float(row[int(run_number + YAW_COLUMN*(number_of_runs))]))
                    euler_pitch = (float(row[int(run_number + PITCH_COLUMN*(number_of_runs))]))
                    euler_roll = (float(row[int(run_number + ROLL_COLUMN*(number_of_runs))]))
                    matrix_value = create_ypr_matrix(euler_yaw,euler_pitch,euler_roll)
                    matrix_row.append(matrix_value)
            else :
                for run_number in run_numbers :
                    state_row.append(int(float((row[int(run_number + STATE_COLUMN*(number_of_runs+1))]))))
                    roll_row.append(float(row[int(run_number + ROLL_COLUMN*(number_of_runs+1))]))
                    z_force_row.append(float(row[int(run_number + Z_FORCE_COLUMN*(number_of_runs+1))]))
                    y_force_row.append(float(row[int(run_number + Y_FORCE_COLUMN*(number_of_runs+1))]))                   
                    time_row.append(float(row[int(run_number + TIME_COLUMN*(number_of_runs+1))]))
                    yaw_row.append(float(row[int(run_number + YAW_COLUMN*(number_of_runs+1))]))
                    pitch_row.append(float(row[int(run_number + PITCH_COLUMN*(number_of_runs+1))]))
                    euler_yaw = (float(row[int(run_number + YAW_COLUMN*(number_of_runs+1))]))
                    euler_pitch = (float(row[int(run_number + PITCH_COLUMN*(number_of_runs+1))]))
                    euler_roll = (float(row[int(run_number + ROLL_COLUMN*(number_of_runs+1))]))
                    matrix_value = create_ypr_matrix(euler_yaw,euler_pitch,euler_roll)
                    matrix_row.append(matrix_value)

            row_number = row_number + 1
            states.append(state_row)
            rolls.append(roll_row)
            #log_file.write(f"time row = {time_row}\n")
            times.append(time_row)
            yaws.append(yaw_row)
            pitches.append(pitch_row)
            matrices.append(matrix_row)
            z_forces.append(z_force_row)
            y_forces.append(y_force_row)
    number_of_rows = row_number
    #log_file.write(f"{z_forces}\r\n")
    fz_min = min(z_forces[:][:])
    fz_min_all = min(fz_min)
    log_file.write(f"\r\n\r\n  fz minimum = {fz_min}\r\n\r\n")
    log_file.write(f"fz minimum global = {fz_min_all}\r\n")
    fy_min = min(y_forces[:][:])
    fy_max = max(y_forces[:][:])
    fy_min_all = min(fy_min)
    fy_max_all = max(fy_max)
    log_file.write(f"\r\n\r\n fy min = {fy_min}\r\n fy max = {fy_max}\r\n")
    log_file.write(f"fy global min, max = {fy_min_all} , {fy_max_all}\r\n")
    
    
        
        

#sequence of processing is
#create_cross_indices
#generate_curve_timing_marks
#write_timing_marks
#write_lists_of_numbers
#prepare_plotlet_tables
#write_plotlet_tables
#compute_fine_adjustments
#log_fine_adjustments
#compute_column_fine_adjustments
#write_plotlets        

global ct_mark_tables
ct_mark_tables = []

global plotlet_numbers

def write_timing_marks() :
    global ct_mark_tables , run_numbers
    global plotlet_numbers
    table_lengths = []
    for run_number in run_numbers :
        table_length = 0
        marks_file.write(f"\r\rcurve timing marks for run number {int(run_number+1)}.\r")
        marks_file.write(f"curve_number,direction,start_time,end_time,end_time-start_time\r")
        for table_entry in ct_mark_tables[run_number] :
            table_length = table_length + 1
            marks_file.write(f"{table_entry[0]},")
            marks_file.write(f"{table_entry[1]},")
            marks_file.write(f"{table_entry[4]},")
            marks_file.write(f"{table_entry[5]},")
            marks_file.write(f"{round((table_entry[5]-table_entry[4]),2)}")
            marks_file.write(f"\r")
        table_lengths.append(table_length)
    minimum_length = min(table_lengths)
    table_number = 0
    for table_length in table_lengths :
        table_number = table_number + 1
        if table_length > minimum_length :
            print("timing mark table length check was not passed.")
            print("table number " , table_number , " has "  , table_length , " entries , which are more than what the other tables have.")
            exit()
        else :
            plotlet_numbers = numbers(minimum_length)
            print("timing mark table length check for table number " , table_number , " was passed.")
    log_file.write(f"plotlet timing marks\r\r")
    for plotlet_number in plotlet_numbers :
        for run_number in run_numbers :
            log_file.write(f"{ct_mark_tables[run_number][plotlet_number]}\r")

def generate_curve_table(run_number) :
    global shift_range , margin , start_margin , end_margin , minimum_curve_duration
    global rows , row_numbers , number_of_rows , labels
    global all_data_first_curve
    start_curve_row = 0
    start_curve_time = 0
    end_curve_row = 0
    end_curve_time = 0
    curve_number = 1
    log_file.write(f"calling generate_curve_table, run number = {run_number}\n")
    if args_only_curves :
        previous_state = 0
        for row_number in row_numbers :
            time = times[row_number][run_number]
            state = states[row_number][run_number]
            if state != previous_state :
                if abs(state) > 0 :
                    if previous_state == 0 :
                        start_curve_row = row_number
                        start_curve_time = time
                        previous_state = state               
                else:
                    if row_number - start_curve_row > minimum_curve_duration :
                       end_curve_row = row_number
                       end_curve_time = time
                       table_entry = [curve_number , previous_state , start_curve_row , end_curve_row , start_curve_time , end_curve_time]
                       ct_mark_tables[run_number].append(table_entry)
                       previous_state = 0
                       curve_number = curve_number + 1
                    else :
                        print("warning, run number with index " , run_number , " had an apparent glitch at curve " , curve_number )
                        print("the glitch was removed, but you might want to take a look.")
    else :
        previous_state = 0
        if all_data_first_curve == True :
            previous_row = 0
        else :
            previous_row = shift_range + 1
        previous_time = float ( previous_row ) / 100.0
        for row_number in row_numbers :
            time = times[row_number][run_number]
            state = states[row_number][run_number]
            if state != previous_state :               
                if abs(state) == 0 :
                    if row_number - previous_row > minimum_curve_duration :
                        end_curve_row = row_number
                        end_curve_time = time
                        table_entry = [ curve_number , previous_state , previous_row , end_curve_row , previous_time , end_curve_time ]
                        ct_mark_tables[run_number].append(table_entry)
                        curve_number = curve_number + 1
                        previous_row = row_number
                        previous_time = time
                    else :
                        print("warning, run number with index " , run_number , " had an apparent glitch at curve " , curve_number )
                        print("the glitch was removed, but you might want to take a look.")
                previous_state = state
                


def generate_curve_timing_marks() :
    for run_number in run_numbers :
        ct_mark_table = []
        ct_mark_tables.append(ct_mark_table)
        generate_curve_table(run_number)

def write_lists_of_numbers() :
    global run_numbers , row_numbers , column_numbers
    global plotlet_numbers
    log_file.write(f"\rrun numbers:\r\r{run_numbers}\r")
    log_file.write(f"\rcolumn_numbers\r\r{column_numbers}\r")
    log_file.write(f"\rplotlet numbers\r\r{plotlet_numbers}\r")

global plotlet_offsets , plotlet_size , column_offsets

global plotlet_sizes
plotlet_sizes = []

def fetch_row_col(output_line,plotlet_number,column_number) :
    global rows , column_offset_table , fine_offset_columns
    try :
        data_item = rows[output_line+column_offset_table[plotlet_number][column_number]+fine_offset_columns[plotlet_number][column_number]][column_number]
        return data_item
    except :
        return 0

def block_of_zeros() :
    for line in numbers(number_of_zeros) :
        #first_line = True
        #for column_number in column_numbers :
            #if  first_line == True :
                #output_file.write(f" 0.0 ")
                #first_line = False
            #else:
                #output_file.write(f" , 0.0 ")
        #output_file.write(f" , 0.0 , 0.0 " )
        #for run_number in run_numbers :
            #output_file.write(f" , 0.0 ")
        output_file.write(f"\n")

global file_names

def extract_file_names() :
    global file_names , label_names , run_numbers
    file_names = []
    for run_number in run_numbers :
        base_name = label_names[run_number]
        file_name = base_name.split('__')[1]
        file_names.append(file_name)

def write_column_names( column_name) :
    global file_names, run_numbers
    for run_number in run_numbers :
        output_file.write(f"{column_name}{file_names[run_number]},")
    if ( not args_strmlt ) :
        output_file.write(f" , " )

def write_column_names_commas_first( column_name) :
    global file_names, run_numbers
    if ( not args_strmlt ) :
        output_file.write(f" , " )
    for run_number in run_numbers :
        output_file.write(f",{column_name}{file_names[run_number]}")

global curve_number

#HM_RED = '#FF0000'
#HM_ORANGE = '#FF6E00'
#HM_YELLOW = '#FFF200'
#HM_GREEN = '#00FF00'
HM_GREEN = colors[0]
HM_RED = colors[511]
HM_YELLOW = colors[256]
HM_ORANGE = colors[256+128]
HM_BLUE = '#0000FF'


def scale_roll(roll_angle) :
    color_index = int((511.0/90.0)*abs(roll_angle))
    if color_index < 0 :
        color_index = 0
    if color_index > 511 :
        color_index = 511
    return color_index

def map_roll_color(roll_in) :
    return colors[scale_roll(roll_in)]

def scale_y(specific_force_in,run) :
    global fy_min, fy_max , fy_min_all , fy_max_all
    scale_range = max(abs(fy_min_all),abs(fy_max_all))
    if scale_range > 0 :
        color_index = 256 + int((256.0*specific_force_in)/scale_range)
    else :
        color_index = 256
    if color_index < 0 :
        color_index = 0
    if color_index > 511 :
        color_index = 511
    return color_index

def map_y_color(force_in,run) :
    return colors[scale_y(force_in,run)]


def scale_z(specific_force_in,run) :
    global fz_min , fz_min_all
    specific_force = abs(specific_force_in)
    if specific_force < 32.0 :
        specific_force = 32.0
    if specific_force > abs(fz_min_all) :
        specific_force = abs(fz_min_all)
    if abs(fz_min_all) > 32.0 :
        color_index = int(512.0*((specific_force-32.)/(abs(fz_min_all)-32.0)))
    else :
        color_index = 256
    if color_index < 0 :
        color_index = 0
    if color_index > 511 :
        color_index = 511
    return color_index

def map_z_color(force_in,run) :
    return colors[scale_z(force_in,run)]

global map_colors , map_thresholds
map_colors = [ HM_BLUE , HM_GREEN , HM_YELLOW , HM_ORANGE , HM_RED ]
map_thresholds = [ -0.7 , -.2 , .2 , .7 ]

def map_color(dtime) :
    global map_colors , map_thresholds
    global min_dt , max_dt
    heat_color = "blue"
    if max_dt > min_dt :
        scaled_time = (dtime) / (max_dt - min_dt)
        for index in range(len(map_thresholds)) :
            if scaled_time > map_thresholds[index] :
                heat_color = map_colors[index+1]
    else :
        heat_color = "yellow"
    return heat_color
           

def write_plotlets() :
    global min_dt , max_dt
    global file_names
    global matrices
    global alignment_variances
    global reference_times , all_reference_times , label_names , reference_time
    global plotlet_numbers , column_numbers , plotlet_sizes , column_offsets , rows , labels , plotlet_size
    global plotlet_offset_table , column_offset_table
    global only_curve_number , first_curve_number
    global curve_number

    log_file.write(f"minimum dt = {min_dt} , maximum dt = {max_dt} \n")

    extract_file_names()

    if args_strmlt :
        output_file.write(f"curve_number ,")
    else:
        output_file.write(f" , curve_number , ,")

    write_column_names(" delta_time__")
    write_column_names(" z_force_g__")
    write_column_names(" y_force_g__")   
    #write_column_names(" degs_align_stdev__")
    #write_column_names(" degs_pivot_stdev__")
    write_column_names(" degs_pivot__")
    
    
    output_file.write(f"{labels}")

    #write_column_names_commas_first(" gauss_map_degs_x__")
    #write_column_names_commas_first(" gauss_map_degs_y__")
    output_file.write(f"\n")

    curve_numbers = []

    curve_number = first_curve_number

    for plotlet_number in plotlet_numbers :
        while curve_number in skip_list_numbers :
            curve_number = curve_number + 1
        curve_numbers.append(curve_number)
        curve_number = curve_number + 1
    print("curve numbers " , curve_numbers )

    

    last_plotlet = plotlet_numbers[len(plotlet_numbers)-1]
    log_file.write(f"plotlet numbers = {plotlet_numbers}\n")
    log_file.write(f"last plotlet = {last_plotlet}\n")
    last_plotlet_offset = plotlet_offset_table[last_plotlet][0]
    log_file.write(f"last plotlet offset = {last_plotlet_offset}\n")
    time_reference = times[last_plotlet_offset][0]
    log_file.write(f"time reference = {time_reference}\n")

    min_delta_finish_time = 0.0
    pivot_reference = 0

    for run_number in run_numbers :
        plotlet_offset = plotlet_offset_table[last_plotlet][run_number]
        log_file.write(f"run number = {run_number} , plotlet_offset = {plotlet_offset} \n")
        time_value = times[plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
        d_t = time_value - time_reference
        log_file.write(f"time = {time_value} , dt = {d_t}\n")
        if d_t < min_delta_finish_time :
            pivot_reference = run_number
        min_delta_finish_time = min(min_delta_finish_time , d_t)

    log_file.write(f"pivot angle reference run = {pivot_reference} \n")

   

    for plotlet_number in plotlet_numbers :
        if ( not args_curve_number ) or  ( curve_numbers[plotlet_number] == only_curve_number ) :
            pivot_var_sums = []
            pivot_samples = []
            pivot_stdev = []
            for run_number in run_numbers :
                pivot_var_sums.append(0.0)
                pivot_samples.append(0)
                pivot_stdev.append(0)
                
            
            for line_number in numbers(plotlet_sizes[plotlet_number]) :
                #is_first_run = True
                for run_number in run_numbers :
                    try :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        rabbit_matrix = matrices[line_number+plotlet_offset+fine_adjustments[plotlet_number][run_number]][pivot_reference]
                        run_matrix = matrices[line_number+plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
                        pivot_matrix = np.matmul(np.transpose(rabbit_matrix),run_matrix)
                        pivot_angles = matrix_to_angle_axis(pivot_matrix)
                        pivot_var_sums[run_number] = pivot_var_sums[run_number] + (pivot_angles[2])**2
                        pivot_samples[run_number] = pivot_samples[run_number] + 1
                    except :
                        pass
            for run_number in run_numbers :
                try :
                    pivot_stdev[run_number] = sqrt( pivot_var_sums[run_number] / pivot_samples[run_number] )
                except :
                    pass
                #print (pivot_stdev[run_number])

            valid_data = True   
            for line_number in numbers(plotlet_sizes[plotlet_number]) :
                if args_strmlt :
                    output_file.write(f"{curve_numbers[plotlet_number]} , ")
                else :
                    output_file.write(f" , {curve_numbers[plotlet_number]} , , ")

                is_first_run = True
                min_dt = 100.0
                max_dt = -100.0

                is_first_run = True
                for run_number in run_numbers :
                    try :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        time_value = times[line_number + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
                        if is_first_run == True :
                            reference_time = time_value
                            is_first_run = False
                        delta_time = time_value-reference_time
                        min_dt = min(min_dt , delta_time)
                        max_dt = max(max_dt , delta_time)
                    except :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        time_value = times[line_number-1 + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
                        if is_first_run == True :
                            reference_time = time_value
                            is_first_run = False
                        delta_time = time_value-reference_time
                        min_dt = min(min_dt , delta_time)
                        max_dt = max(max_dt , delta_time)

                is_first_run = True
                for run_number in run_numbers :
                    try :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        time_value = times[line_number + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
                        if is_first_run == True :
                            reference_time = time_value
                            is_first_run = False
                        delta_time = time_value-reference_time
                        output_file.write(f"{(round(delta_time - min_dt ,2))},")
                    except :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        time_value = times[line_number-1 + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
                        if is_first_run == True :
                            reference_time = time_value
                            is_first_run = False
                        delta_time = time_value-reference_time
                        output_file.write(f"{(round(delta_time - min_dt ,2))},")
                        valid_data = False
                if ( not args_strmlt ) :
                    output_file.write(f" , ")
                    

                for run_number in run_numbers :
                    try :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        z_force_value = z_forces[line_number + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]                  
                        output_file.write(f"{round(z_force_value/32.17,4)},")
                    except :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        z_force_value = z_forces[line_number - 1 + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]                  
                        output_file.write(f"{round(z_force_value/32.17,4)},")
                        valid_data = False
                if ( not args_strmlt ) :
                    output_file.write(f",")

                for run_number in run_numbers :
                    try :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        y_force_value = y_forces[line_number + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]                  
                        output_file.write(f"{round(y_force_value/32.17,4)},")
                    except :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        y_force_value = y_forces[line_number-1 + plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]                  
                        output_file.write(f"{round(y_force_value/32.17,4)},")
                        valid_data = False
                if ( not args_strmlt ) :
                    output_file.write(f",")                  

                for run_number in run_numbers :
                    try :
                        standard_dev = alignment_variances[plotlet_number][run_number]
                        #output_file.write(f"{round(standard_dev,2)} , ")
                    except :
                        #output_file.write(f"0,")
                        valid_data = False
                if ( not args_strmlt ) :
                    output_file.write(f",")             
                
                lists_of_angles = []
                for run_number in run_numbers :
                    try :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        rabbit_matrix = matrices[line_number+plotlet_offset+fine_adjustments[plotlet_number][run_number]][pivot_reference]
                        run_matrix = matrices[line_number+plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
                        pivot_matrix = np.matmul(np.transpose(rabbit_matrix),run_matrix)
                        pivot_angles = matrix_to_angle_axis(pivot_matrix)
                        lists_of_angles.append(pivot_angles)
                    except :
                        plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                        rabbit_matrix = matrices[line_number-1+plotlet_offset+fine_adjustments[plotlet_number][run_number]][pivot_reference]
                        run_matrix = matrices[line_number-1+plotlet_offset+fine_adjustments[plotlet_number][run_number]][run_number]
                        pivot_matrix = np.matmul(np.transpose(rabbit_matrix),run_matrix)
                        pivot_angles = matrix_to_angle_axis(pivot_matrix)
                        lists_of_angles.append(pivot_angles)

                #for run_number in run_numbers :
                    #try :
                        #output_file.write(f"{round(pivot_stdev[run_number],2)} , ")
                    #except :
                        #output_file.write(f"0,")
                        #valid_data = False
                if ( not args_strmlt ) :
                    output_file.write(f" , ")    

                for run_number in run_numbers:
                    try :
                        output_file.write(f"{round(lists_of_angles[run_number][2],4)} , ")
                    except :
                        output_file.write(f"0,")
                        valid_data = False
                if ( not args_strmlt ) :
                    output_file.write(f" , ") 

            
                
                is_first_column = True
                for column_number in column_numbers :
                    try :
                        if is_first_column == True :
                            output_file.write(f"{fetch_row_col(line_number, plotlet_number , column_number)}")
                            is_first_column = False
                        else :
                            output_file.write(f",{fetch_row_col(line_number, plotlet_number , column_number)}")
                    except :
                        if is_first_column == True :
                            output_file.write(f"{fetch_row_col(line_number-1, plotlet_number , column_number)}")
                            is_first_column = False
                        else :
                            output_file.write(f",{fetch_row_col(line_number-1, plotlet_number , column_number)}")              
                        valid_data = False
                if ( not args_strmlt ) :
                    output_file.write(f" , ") 

                #for run_number in run_numbers :
                    #try :
                        #output_file.write(f" , {round(lists_of_angles[run_number][1],4)} ")
                    #except :
                        #output_file.write(f" , 0")
                        #valid_data = False
                    
                if ( not args_strmlt ) :
                    output_file.write(f" , ") 

                #for run_number in run_numbers :
                    #try :
                        #output_file.write(f" , {round(lists_of_angles[run_number][0],4)} ")
                    #except :
                        #output_file.write(f" , 0")
                        #valid_data = False
                    
                output_file.write(f" \n")

                if valid_data == False :
                    try :
                        log_file.write(f"****************************************\n")
                        log_file.write(f"*\n*\n*\n*\n*\n*\n*\n*\n*\n")
                        log_file.write(f"*   warning: there was not enough data to complete all computations.\n")
                        log_file.write(f"*\n*\n*\n*\n*\n*\n*\n*\n*\n")
                        log_file.write(f"****************************************\n")
                    except :
                        pass          
                                       
                    sys.exit()
                
            if ( number_of_zeros > 0 ) and ( not args_strmlt) :
                block_of_zeros()

#sequence of processing is
#create_cross_indices
#generate_curve_timing_marks
#write_timing_marks
#write_lists_of_numbers
#prepare_plotlet_tables
#write_plotlet_tables
#compute_fine_adjustments
#log_fine_adjustments
#compute_column_fine_adjustments
#write_plotlets        


def write_plotlet_tables() :
    global plotlet_sizes , plotlet_offsets , column_offsets
    global plotlet_offset_table
    global column_offset_table
    log_file.write(f"\rplotlet_sizes :\r{plotlet_sizes}\r\r")
    log_file.write(f"\rplotlet_offsets :\r{plotlet_offset_table}\r\r")
    log_file.write(f"\rcolumn_offsets :\r{column_offset_table}\r\r")

global plotlet_offset_table
global column_offset_table
plotlet_offset_table = []
column_offset_table = []


def prepare_plotlet_tables() :
    global plotlet_offset_table
    global column_offset_table
    global plotlet_offsets
    global column_offsets
    for plotlet_number in plotlet_numbers :
        prepare_plotlet(plotlet_number)
        plotlet_offset_table.append(plotlet_offsets)
        column_offset_table.append(column_offsets)

global fine_adjustments
fine_adjustments = []

def log_fine_adjustments():
    global run_numbers
    global plotlet_numbers
    global fine_adjustments
    log_file.write(f"\r\rfine adjustments table : \r")
    for plotlet_number in plotlet_numbers :
        log_file.write(f"{fine_adjustments[plotlet_number]}\r")

global all_reference_times
all_reference_times = []

global min_dt , max_dt
min_dt = 100.0
max_dt = -100.0


def compute_fine_adjustments() :
    global min_dt , max_dt
    global alignment_variance , alignment_variances
    global first_curve_number
    global label_names
    global reference_times , reference_time , reference_rolls
    global run_numbers , rolls , yaws , times , number_of_runs , plotlet_offsets , fine_adjustments 
    global plotlet_offset_table
    global plotlet_number, plotlet_numbers
    try :
        timing_file.write(f"curve_number , ,")
    except :
        pass
    is_first_run = True
    for run_number in run_numbers :
        if is_first_run == True :
            try :
                timing_file.write(f"delta_{label_names[0]}")
            except :
                pass
            is_first_run = False
        else :
            try :
                timing_file.write(f",delta_{label_names[run_number]}")
            except :
                pass
    try :
        timing_file.write(f"\r")
    except :
        pass
    for plotlet_number in plotlet_numbers :
        #log_file.write(f"computing fine adjustments for plotlet number : {plotlet_number} \r")
        print("computing fine adjustments for plotlet number " , plotlet_number )
        reference_rolls = []
        reference_times = []
        all_reference_times.append(reference_times)
        reference_yaws = []
        for line_number in numbers(plotlet_sizes[plotlet_number]) :
            total_yaw = 0
            total_roll = 0
            total_time = 0
            is_first_run = True
            for run_number in run_numbers :
                try :
                    plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                    roll_value = rolls[line_number + plotlet_offset][run_number]
                    z_force_value = z_forces[line_number + plotlet_offset][run_number]
                    time_value = times[line_number + plotlet_offset][run_number]
                    yaw_value = yaws[line_number + plotlet_offset][run_number]
                    total_roll = total_roll + roll_value
                    total_time = total_time + time_value
                    total_yaw = total_yaw + yaw_value
                    if is_first_run == True :
                        reference_time_value = time_value
                        reference_yaw_value = yaw_value
                        is_first_run = False
                    else :
                        min_dt = min(min_dt , time_value - reference_time_value )
                        max_dt = max(max_dt , time_value - reference_time_value )
                except :
                    pass
            reference_roll_value = total_roll / number_of_runs
            #reference_yaw_value = total_yaw / number_of_runs
            reference_rolls.append(round(reference_roll_value,2))
            reference_times.append(round(reference_time_value,2))
            reference_yaws.append(round(reference_yaw_value,2))
            
        for line_number in numbers(plotlet_sizes[plotlet_number]) :
            try :
                timing_file.write(f"{plotlet_number+first_curve_number} ,  , ")
            except :
                pass
            is_first_ref_time = True
            for run_number in run_numbers :
                try :
                    plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                    time_value = times[line_number + plotlet_offset][run_number]
                    reference_time = reference_times[line_number]
                    if is_first_ref_time == True :
                        try :
                            timing_file.write(f"{(round(time_value-reference_time,2))}")
                        except :
                            pass
                        is_first_ref_time = False
                    else :
                        try :
                            timing_file.write(f",{(round(time_value-reference_time,2))}")
                        except :
                            pass
                except :
                    pass
            try :
                timing_file.write(f"\r")
            except :
                pass
                    
        input_data = []
        roll_column_data = []
        for run_number in run_numbers :
            input_column = []
            roll_column = []
            for line_number in numbers(plotlet_sizes[plotlet_number]) :
                try :
                    plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                    yaw_value = yaws[line_number + plotlet_offset][run_number]
                    roll_value = rolls[line_number + plotlet_offset][run_number]
                    input_column.append(yaw_value)
                    roll_column.append(roll_value )
                except :
                    pass
            input_data.append(input_column)
            roll_column_data.append(roll_column)
        #log_file.write(f"reference rolls = {reference_rolls} \r " )
        #log_file.write(f"input data = {input_data} \r  ")
        adjustment_list = []
        variance_list = []
        for run_number in run_numbers :
            similarity_index = compute_similarity ( reference_yaws , input_data[run_number] , roll_column_data[run_number] , plotlet_number , run_number )
            #log_file.write(f"for pn {plotlet_number}, rn {run_number}, similarity index = {similarity_index}\n")
            adjustment_list.append(similarity_index)
            variance_list.append(alignment_variance)
        fine_adjustments.append(adjustment_list)
        alignment_variances.append(variance_list)

#sequence of processing is
#create_cross_indices
#generate_curve_timing_marks
#write_timing_marks
#write_lists_of_numbers
#prepare_plotlet_tables
#write_plotlet_tables
#compute_fine_adjustments
#log_fine_adjustments
#compute_column_fine_adjustments
#write_plotlets        

global fine_offset_columns

fine_offset_columns = []

def compute_column_fine_adjustments() :
    global fine_adjustments , plotlet_numbers , fine_offset_columns , run_numbers , fine_adjustments
    for plotlet_number in plotlet_numbers :
        is_first_column = True
        fine_offset_list = []
        for run_column in numbers(columns_per_run) :
            if is_first_column == True :
                for run_number in run_numbers :
                    fine_offset_list.append(fine_adjustments[plotlet_number][run_number] )
                is_first_column = False
            else :
                if not args_strmlt :
                    fine_offset_list.append(fine_adjustments[plotlet_number][0])
                for run_number in run_numbers :
                    fine_offset_list.append(fine_adjustments[plotlet_number][run_number] )
        fine_offset_columns.append(fine_offset_list)
    log_file.write(f"\r\rfine offset columns \r {fine_offset_columns}\r")

#sequence of processing is
#create_cross_indices
#generate_curve_timing_marks
#write_timing_marks
#write_lists_of_numbers
#prepare_plotlet_tables
#write_plotlet_tables
#compute_fine_adjustments
#log_fine_adjustments
#compute_column_fine_adjustments
#write_plotlets        

def prepare_plotlet(plot_number) :
    global plotlet_sizes
    global plotlet_offsets , plotlet_size , column_offsets
    global ct_mark_tables
    global CURVE_START_COLUMN , CURVE_END_COLUMN
    global margin , start_margin , end_margin
    global plotlet_numbers
    last_plotlet = plotlet_numbers[len(plotlet_numbers)-1]
    plotlet_offsets = []
    column_offsets = []
    total_margin = start_margin + end_margin
    if plot_number == last_plotlet :
        total_margin = total_margin + time_after_last_curve
    max_size = total_margin
    for run_number in run_numbers :
        curve_start = ct_mark_tables[run_number][plot_number][CURVE_START_COLUMN]
        curve_end = ct_mark_tables[run_number][plot_number][CURVE_END_COLUMN]
        plotlet_offsets.append(curve_start - start_margin)
        max_size = max(max_size, (total_margin + curve_end - curve_start))
    plotlet_size = max_size
    plotlet_sizes.append(max_size)
    is_first_column = True
    for run_column in numbers(columns_per_run) :
        if is_first_column == True :
            for run_number in run_numbers :
                column_offsets.append(plotlet_offsets[run_number])
            is_first_column = False
        else :
            if not args_strmlt :
                column_offsets.append(plotlet_offsets[0])
            for run_number in run_numbers :
                column_offsets.append(plotlet_offsets[run_number])       
 
if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='slice.py',
        description='slices a merged run file into plotlet')
    parser.add_argument('-f','--filename', help="name of the file with plotlets")
    #parser.add_argument('-zeros','--nz', help="optional number of zeros between plotlets")
    #parser.add_argument('-curve','--curve_number', help="plot data for exactly one curve")
    parser.add_argument('-fcn','--fcn', help="first curve number")
    parser.add_argument('-skip','--skip_list', help = "Skip list in quotes with commas, such as -skip \" 9 , 10 \" .")
    #parser.add_argument('-strmlt','--strmlt',action='store_true',help="option for streamlit plotting")
    #parser.add_argument('-only_curves','--only_curves',action='store_true',help="option to plot only curves")
    parser.add_argument('-fw','--fw',help = "fine alignment force weighting, default = 1.0")
    #parser.add_argument('-log_time','--log_time',action='store_true',help="record processing timing information")
    parser.add_argument('-cr','--cr',help="not used but must be allowed.")
    parser.add_argument('-curves','--curves',help="not used but must be allowed.")
    parser.add_argument('-talc','--talc',help="time after last curve in seconds")
    parser.add_argument('-adfc','--adfc',action='store_true',help="plot all data for the first curve")
    
    
    args = parser.parse_args()

    skip_list_numbers = []

    if args.adfc :
        args_adfc = True

    if args.talc :
        time_after_last_curve = int(100.0*float(args.talc))

    if args.fw :
        force_wt = float(args.fw)
    
    if args.skip_list :
        skip_list = args.skip_list.split(',')
        for item in skip_list :
            skip_list_numbers.append(int(item))
    print(skip_list_numbers)

    if args.fcn :
        first_curve_number = int(args.fcn)
        print("first curve number = " , first_curve_number )

    #if args_curve_number :
        #only_curve_number = int(args_curve_number)
        #print("")
        #print(">>> data will be printed only for curve number " , only_curve_number  )
        #print("")

    if args.filename :
        run_file_name = args.filename
        base_name = run_file_name.split('.')[0]
        print("name of file : ",run_file_name)
        try :
            input_file = open(run_file_name)
        except :
            print("unable to open merged run file, check spelling.")
            exit()
        if args_curve_number :
            output_file = open(base_name+"_curve_"+str(only_curve_number)+"_plotlets.csv" , "w" )
            log_file = open(base_name+"_curve_"+str(only_curve_number)+"_log.txt" , "w" )
            
            marks_file = open(base_name+"_curve_"+str(only_curve_number)+"_marks.txt" , "w" )
            #timing_file = open(base_name+"_curve_"+str(only_curve_number)+"_timing.csv" , "w" )
        else :
            output_file = open(base_name+"_plotlets.csv" , "w" )
            log_file = open(base_name+"_log.txt" , "w" )
            marks_file = open(base_name+"_marks.txt" , "w" )
            #timing_file = open(base_name+"_timing.csv" , "w" )
            #variance_file = open(base_name+"_variance.csv" , "w")
        log_file.write(f"fine alignment force weighting = {round(force_wt,2)}\n\n")
        create_cross_indices(shift_range)
        open_file()

        #if args_log_time :
            #time_log = open("time_log.txt","a")
            #now = datetime.now()
            #time = now.time()
            #time_log.write(f"slice.py, starting to process {run_file_name} , time = {time}.\n")

        
        print("number of zeros inserted between plotlets as curve separaters = " , number_of_zeros )
        generate_curve_timing_marks()
        write_timing_marks()
        write_lists_of_numbers()
        prepare_plotlet_tables()
        write_plotlet_tables()
        compute_fine_adjustments()
        log_fine_adjustments()
        compute_column_fine_adjustments()
        write_plotlets()
        now = datetime.now()
        time = now.time()
        #if args_log_time :
            #time_log.write(f"slice.py, processing complete for {run_file_name} , time = {time}.\n")
        log_file.write(f"fetch valid = {fetch_valid_true} , fetch invalid = {fetch_valid_false} \n")
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
