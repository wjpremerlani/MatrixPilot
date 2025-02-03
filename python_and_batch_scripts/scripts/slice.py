

global shift_range , margin , start_margin , end_margin , minimum_curve_duration , minimum_roll
#shift_range determines the minimum and maximum shit in the range of elements
#used to scan cross variance as a function of element number shift
#start_margin and end_margin define the extra number of elements included when slicing a portion of a run into a plotlet
#minimum_roll defines the data window in which variance weights are non-zero
#shift_range = 50 #time shift range of +- 1/2 of a second
shift_range = 300 #time shift range of +- 1/2 of a second
start_margin = 20 # .2 seconds worth of data
end_margin = 5
minimum_roll = 15.0

import argparse
import sys
import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees

global number_of_zeros
number_of_zeros = 0

minimum_curve_duration = 50 # minimum time steps for valid curve marks

global STATE_COLUMN, ROLL_COLUMN ,TIME_COLUMN
TIME_COLUMN = 0
STATE_COLUMN = 2
ROLL_COLUMN = 6
PITCH_COLUMN = 7 
YAW_COLUMN = 8

global CURVE_START_COLUMN , CURVE_END_COLUMN
CURVE_START_COLUMN = 2
CURVE_END_COLUMN = 3

global only_curve_number , first_curve_number
first_curve_number = 1

global plotlet_offsets , plotlet_size

global cross_indices

global columns_per_run , columns_per_line
global column_numbers 
global number_of_runs , run_numbers
run_numbers = []

global rows , row_numbers , number_of_rows , labels


global states , rolls , pitches, times , yaws , matrices
states = []
rolls = []
pitches = []
yaws = []
times = []
matrices = []

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

#perform a protected extraction of a value from a list
#that allows the index to fall outside of the list
#as well as a round to 2 decimal places
def fndr( list_of_values, index ) :
    if index < 0 :
        return 0.0
    else :
        try :
            value = list_of_values[index]
        except :
            value = 0.0
        return round(value ,2)
          

#perform a protected extraction of a value from a list
#that allows the index to fall outside of the list
def fetch( list_of_values, index ) :
    if index < 0 :
        return 0
    else :
        try :
            value = list_of_values[index]
        except :
            value = 0
        return value 
    
#compute the cross variance of list2 with respect to list1
#with list2 in effect shifted by offset elements
def cross_variance(list1, list2, offset) :
    global minimum_roll , reference_rolls 
    variance_sum = 0.0
    weight_sum = 0.0 
    N = 0
    list2_index = offset
    for value1 in list1 :
        value2 = fetch ( list2 , list2_index )
        reference_roll = abs(fetch ( reference_rolls , list2_index ))
        if reference_roll > minimum_roll :
            variance_term = (value1-value2)*(value1-value2)*reference_roll
            weight_sum = weight_sum + reference_roll
            variance_sum = variance_sum + variance_term
            N = N + 1
        list2_index = int(list2_index + 1)
    if ( N > 0 ) and ( weight_sum > 0 ):
        return variance_sum/weight_sum
    else :
        return 0


#determine the similarity of two plots as a function of a relative time shift between them
#this is done by computing the cross variance, the sum of the squares of the differences between plots
def compute_similarity (reference_list,input_list) :
    global alignment_variance
    first_index = True
    best_index = 0
    for index in cross_indices  :
        variance = cross_variance(reference_list,input_list,index)
        if first_index == True :
            minimum_variance = variance
            first_index = False
        else :
            if variance < minimum_variance :
                best_index = index
                minimum_variance = variance
    alignment_variance = sqrt(minimum_variance)
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

def open_file() :
    global states , rolls , pitches, yaws , times , matrices
    global number_of_runs , run_numbers
    global rows , row_numbers , number_of_rows , labels , label_names
    global columns_per_run
    global columns_per_line
    global column_numbers
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
            for label_name in label_names :             
                if ( label_name != "   ") and ( found_blanks == False ):
                    run_numbers.append(run_number)
                    run_number = run_number + 1
                else :
                    found_blanks = True
            first_row = False
            number_of_runs = run_number
            columns_per_run = int((columns_per_line + 1 ) / (number_of_runs + 1))
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
            for run_number in run_numbers :
                state_row.append(int(float((row[int(run_number + STATE_COLUMN*(number_of_runs+1))]))))
                roll_row.append(float(row[int(run_number + ROLL_COLUMN*(number_of_runs+1))]))
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
            times.append(time_row)
            yaws.append(yaw_row)
            pitches.append(pitch_row)
            matrices.append(matrix_row)
    number_of_rows = row_number


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
    previous_state = 0
    start_curve_row = 0
    start_curve_time = 0
    end_curve_row = 0
    end_curve_time = 0
    curve_number = 1
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
        file_name = base_name.split('_')[1]
        file_names.append(file_name)

def write_column_names( column_name) :
    global file_names, run_numbers
    for run_number in run_numbers :
        output_file.write(f"{column_name}{file_names[run_number]} , ")
    output_file.write(f" , " )

def write_column_names_commas_first( column_name) :
    global file_names, run_numbers
    output_file.write(f" , ")
    for run_number in run_numbers :
        output_file.write(f" , {column_name}{file_names[run_number]}")

global curve_number

def write_plotlets() :
    global file_names
    global matrices
    global alignment_variances
    global reference_times , all_reference_times , label_names , reference_time
    global plotlet_numbers , column_numbers , plotlet_sizes , column_offsets , rows , labels , plotlet_size
    global plotlet_offset_table , column_offset_table
    global only_curve_number , first_curve_number
    global curve_number

    extract_file_names()

    output_file.write(f" , curve_number , , ")

    write_column_names("delta_time_")
    write_column_names("degs_align_stdev_")
    write_column_names("degs_pivot_stdev_")
    write_column_names("degs_pivot_")
    
    
    output_file.write(f"{labels}")

    write_column_names_commas_first("gauss_map_degs_x_")
    write_column_names_commas_first("gauss_map_degs_y_")
    output_file.write(f"\n")

    curve_numbers = []

    curve_number = first_curve_number

    for plotlet_number in plotlet_numbers :
        while curve_number in skip_list_numbers :
            curve_number = curve_number + 1
        curve_numbers.append(curve_number)
        curve_number = curve_number + 1
    print("curve numbers " , curve_numbers )
    

    for plotlet_number in plotlet_numbers :
        if ( not args.curve_number ) or  ( curve_numbers[plotlet_number] == only_curve_number ) :
            pivot_var_sums = []
            pivot_samples = []
            pivot_stdev = []
            for run_number in run_numbers :
                pivot_var_sums.append(0.0)
                pivot_samples.append(0)
                pivot_stdev.append(0)
                
            
            for line_number in numbers(plotlet_sizes[plotlet_number]) :
                is_first_run = True
                for run_number in run_numbers :
                    plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                    if is_first_run == True :
                        rabbit_matrix = matrices[line_number+plotlet_offset][run_number]
                        is_first_run = False 
                    run_matrix = matrices[line_number+plotlet_offset][run_number]
                    pivot_matrix = np.matmul(np.transpose(rabbit_matrix),run_matrix)
                    pivot_angles = matrix_to_angle_axis(pivot_matrix)
                    pivot_var_sums[run_number] = pivot_var_sums[run_number] + (pivot_angles[2])**2
                    pivot_samples[run_number] = pivot_samples[run_number] + 1

            for run_number in run_numbers :
                pivot_stdev[run_number] = sqrt( pivot_var_sums[run_number] / pivot_samples[run_number] )
                #print (pivot_stdev[run_number])
                
            for line_number in numbers(plotlet_sizes[plotlet_number]) :
                output_file.write(f" , {curve_numbers[plotlet_number]} , , ")
                is_first_run = True
                for run_number in run_numbers :
                    plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                    time_value = times[line_number + plotlet_offset][run_number]
                    if is_first_run == True :
                        reference_time = time_value
                        is_first_run = False              
                    output_file.write(f"{(round(time_value-reference_time,2))} , ")
                output_file.write(f" ,  ")

                for run_number in run_numbers :
                    standard_dev = alignment_variances[plotlet_number][run_number]
                    output_file.write(f"{round(standard_dev,2)} , ")

                output_file.write(f" , ")
                
                is_first_run = True
                lists_of_angles = []
                for run_number in run_numbers :
                    plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                    if is_first_run == True :
                        rabbit_matrix = matrices[line_number+plotlet_offset][run_number]
                        is_first_run = False 
                    run_matrix = matrices[line_number+plotlet_offset][run_number]
                    pivot_matrix = np.matmul(np.transpose(rabbit_matrix),run_matrix)
                    pivot_angles = matrix_to_angle_axis(pivot_matrix)
                    lists_of_angles.append(pivot_angles)

                for run_number in run_numbers :
                    output_file.write(f"{round(pivot_stdev[run_number],2)} , ")
                output_file.write(f" , ")    

                for run_number in run_numbers :
                    output_file.write(f"{round(lists_of_angles[run_number][2],2)} , ")    
                output_file.write(f" , ")

            
                
                is_first_column = True
                for column_number in column_numbers :
                    if is_first_column == True :
                        output_file.write(f"{fetch_row_col(line_number, plotlet_number , column_number)}")
                        is_first_column = False
                    else :
                        output_file.write(f",{fetch_row_col(line_number, plotlet_number , column_number)}")

                output_file.write(f" , ")
                for run_number in run_numbers :
                    output_file.write(f" , {round(lists_of_angles[run_number][1],2)} ")    
                output_file.write(f" , ")

                for run_number in run_numbers :
                    output_file.write(f" , {round(lists_of_angles[run_number][0],2)} ")
                output_file.write(f"\n")
                
            if number_of_zeros > 0 :
                block_of_zeros()

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

def compute_fine_adjustments() :
    global alignment_variance , alignment_variances
    global first_curve_number
    global label_names
    global reference_times , reference_time , reference_rolls
    global run_numbers , rolls , yaws , times , number_of_runs , plotlet_offsets , fine_adjustments 
    global plotlet_offset_table
    global plotlet_number, plotlet_numbers
    timing_file.write(f"curve_number , ,")
    is_first_run = True
    for run_number in run_numbers :
        if is_first_run == True :
            timing_file.write(f"delta_{label_names[0]}")
            is_first_run = False
        else :
            timing_file.write(f",delta_{label_names[run_number]}")
    timing_file.write(f"\r")
    for plotlet_number in plotlet_numbers :
        log_file.write(f"computing fine adjustments for plotlet number : {plotlet_number} \r")
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
                plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                roll_value = rolls[line_number + plotlet_offset][run_number]
                time_value = times[line_number + plotlet_offset][run_number]
                yaw_value = yaws[line_number + plotlet_offset][run_number]
                total_roll = total_roll + roll_value
                total_time = total_time + time_value
                total_yaw = total_yaw + yaw_value
                if is_first_run == True :
                    reference_time_value = time_value
                    is_first_run = False       
            reference_roll_value = total_roll / number_of_runs
            reference_yaw_value = total_yaw / number_of_runs
            reference_rolls.append(round(reference_roll_value,2))
            reference_times.append(round(reference_time_value,2))
            reference_yaws.append(round(reference_yaw_value,2))
            
        for line_number in numbers(plotlet_sizes[plotlet_number]) :
            timing_file.write(f"{plotlet_number+first_curve_number} ,  , ")
            is_first_ref_time = True
            for run_number in run_numbers :
                plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                time_value = times[line_number + plotlet_offset][run_number]
                reference_time = reference_times[line_number]
                if is_first_ref_time == True :
                    timing_file.write(f"{(round(time_value-reference_time,2))}")
                    is_first_ref_time = False
                else :
                    timing_file.write(f",{(round(time_value-reference_time,2))}")
            timing_file.write(f"\r")
                    
        input_data = []
        for run_number in run_numbers :
            input_column = []
            for line_number in numbers(plotlet_sizes[plotlet_number]) :
                plotlet_offset = plotlet_offset_table[plotlet_number][run_number]
                yaw_value = yaws[line_number + plotlet_offset][run_number]
                input_column.append(yaw_value)
            input_data.append(input_column)
        #log_file.write(f"reference rolls = {reference_rolls} \r " )
        #log_file.write(f"input data = {input_data} \r  ")
        adjustment_list = []
        variance_list = []
        for run_number in run_numbers :
            similarity_index = compute_similarity ( reference_yaws , input_data[run_number] )
            adjustment_list.append(similarity_index)
            variance_list.append(alignment_variance)
            #print("similarity index = " , similarity_index , "for run " , run_number , " plotlet " , plotlet_number )
        fine_adjustments.append(adjustment_list)
        alignment_variances.append(variance_list)

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
                fine_offset_list.append(fine_adjustments[plotlet_number][0])
                for run_number in run_numbers :
                    fine_offset_list.append(fine_adjustments[plotlet_number][run_number] )
        fine_offset_columns.append(fine_offset_list)
    log_file.write(f"\r\rfine offset columns \r {fine_offset_columns}\r")
        

def prepare_plotlet(plot_number) :
    global plotlet_sizes
    global plotlet_offsets , plotlet_size , column_offsets
    global ct_mark_tables
    global CURVE_START_COLUMN , CURVE_END_COLUMN
    global margin , start_margin , end_margin 
    plotlet_offsets = []
    column_offsets = []
    total_margin = start_margin + end_margin
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
            column_offsets.append(plotlet_offsets[0])
            for run_number in run_numbers :
                column_offsets.append(plotlet_offsets[run_number])       
 
if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='slice.py',
        description='slices a merged run file into plotlet')
    parser.add_argument('-f','--filename', help="name of the file with plotlets")
    parser.add_argument('-zeros','--nz', help="optional number of zeros between plotlets")
    parser.add_argument('-curve','--curve_number', help="plot data for exactly one curve")
    parser.add_argument('-fcn','--fcn', help="first curve number")
    parser.add_argument('-skip','--skip_list', help = "Skip list in quotes with commas, such as -skip \" 9 , 10 \" .")

     
    args = parser.parse_args()

    skip_list_numbers = []
    
    if args.skip_list :
        skip_list = args.skip_list.split(',')
        for item in skip_list :
            skip_list_numbers.append(int(item))
    print(skip_list_numbers)

    if args.fcn :
        first_curve_number = int(args.fcn)
        print("first curve number = " , first_curve_number )

    if args.nz :
        number_of_zeros = int(args.nz)

    if args.curve_number :
        only_curve_number = int(args.curve_number)
        print("")
        print(">>> data will be printed only for curve number " , only_curve_number  )
        print("")

    if args.filename :
        run_file_name = args.filename
        base_name = run_file_name.split('.')[0]
        print("name of file : ",run_file_name)
        try :
            input_file = open(run_file_name)
        except :
            print("unable to open merged run file, check spelling.")
            exit()
        if args.curve_number :
            output_file = open(base_name+"_curve_"+str(only_curve_number)+"_plotlets.csv" , "w" )
            log_file = open(base_name+"_curve_"+str(only_curve_number)+"_log.txt" , "w" )
            marks_file = open(base_name+"_curve_"+str(only_curve_number)+"_marks.txt" , "w" )
            timing_file = open(base_name+"_curve_"+str(only_curve_number)+"_timing.csv" , "w" )
        else :
            output_file = open(base_name+"_plotlets.csv" , "w" )
            log_file = open(base_name+"_log.txt" , "w" )
            marks_file = open(base_name+"_marks.txt" , "w" )
            timing_file = open(base_name+"_timing.csv" , "w" )
        create_cross_indices(shift_range)
        open_file()
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
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
