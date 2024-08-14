import numpy as np
from math import sin, cos, atan2, sqrt, radians


GRAVITY = -32.174


MIN_NUM_COLS_IN  = 13
MAX_NUM_COLS_IN  = 13

number_rows = 0 
import argparse

number_lines = 0
row_number = 0

def record_initial_temperature():
    global initial_temperature
    for line in lines:
        parts = line.split(' ')
        for part in parts:
            if part == "initial":
                initial_temperature = parts[3]
    return None

def gyro_table_start():
    gyro_file.write("\n#define TABLE_ORIGIN ( "+initial_temperature+")\n\n")
    gyro_file.write("int16_t residual_offset[] = { 0 , 0 , 0 } ; \n\n")
    gyro_file.write("const struct gyro_offset_table_entry gyro_offset_table[] = {\n")
    return None

def gyro_table_end():
    gyro_file.write("};\n\n")
    return None

def acc_table_start():
    accel_file.write("\n#define ACCEL_TABLE\n\n")
    accel_file.write("\n#define ACCEL_TABLE_ORIGIN ( "+initial_temperature+")\n\n")
    accel_file.write("int16_t accel_residual_offset[] = { 0 , 0 , 0 } ; \n\n")
    accel_file.write("const struct gyro_offset_table_entry accel_offset_table[] = {\n")    
    return None

def acc_table_end():
    accel_file.write("};\n\n")
    return None

def read_raw_data_from_txt(path):
    global number_rows
    global number_lines
    global lines
    row = 0
    file = open(path)
    dataStr = file.read()

    lines = dataStr.splitlines(keepends=False)
    number_lines = len(lines)
    lists = np.zeros((MIN_NUM_COLS_IN, len(lines)))
    if dataStr:
        for line in lines:
            try:
                parts = line.split(',')
                if MIN_NUM_COLS_IN <= len(parts) <= MAX_NUM_COLS_IN:
                    for i in range(MIN_NUM_COLS_IN):
                        if i < len(parts):
                            try:
                                f = parts[i]
                            except:
                                f = 0
                            lists[i][row] = f
                    row += 1
                    number_rows += 1
            except ValueError:
                pass
        return lists
    return None


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog='process_tables.py',
        description='constructs temperature compensate tables from raw data.')
    parser.add_argument('-f','--filename', help="base name of files")
    args = parser.parse_args()
    file_base_name = args.filename
    gyro_file = open(file_base_name+"_gyro_table.txt", "w")
    accel_file = open(file_base_name+"_accel_table.txt", "w")
    rows = read_raw_data_from_txt(file_base_name+".txt")
    print("rows = "+str(number_rows)+"\nlines = "+str(number_lines))
    record_initial_temperature()
    print("initial temperature = " , initial_temperature )
    
    # these function are called once per row
    def process_offsets(row):
        global row_number
        global sum_column_4
        global sum_column_5
        global sum_column_6
        global sum_column_7
        global sum_column_8
        global sum_column_9     
        if row_number < number_rows :
            sum_column_4 += int(row[4])
            sum_column_5 += int(row[5])
            sum_column_6 += int(row[6])
            sum_column_7 += int(row[7])
            sum_column_8 += int(row[8])
            sum_column_9 += int(row[9])
            row_number += 1   
    def process_gyro_table(row):
        global row_number
        if row_number < number_rows :
            gyro_file.write("{"+str(int(row[7]))+","+str(int(row[8]))+","+str(int(row[9]))+"},\n")
            row_number += 1
    def process_acc_table(row):
        global row_number
        if row_number < number_rows :
            accel_file.write("{"+str(int(row[10]))+","+str(int(row[11]))+","+str(int(row[12]))+"},\n")
            row_number += 1
    # applies the above functions to each row
    row_number = 0
    sum_column_4 = 0
    sum_column_5 = 0
    sum_column_6 = 0
    sum_column_7 = 0
    sum_column_8 = 0
    sum_column_9 = 0
    np.apply_along_axis(process_offsets, axis=0, arr=rows)
    print("offsets = "+str(int((sum_column_7-sum_column_4)/number_rows))+" , "+str(int((sum_column_8-sum_column_5)/number_rows))+" , " +str(int((sum_column_9-sum_column_6)/number_rows))+"\n")
    row_number = 0
    gyro_table_start()
    np.apply_along_axis(process_gyro_table, axis=0, arr=rows)
    gyro_table_end()
    row_number = 0
    acc_table_start()
    np.apply_along_axis(process_acc_table, axis=0, arr=rows)
    acc_table_end()
    gyro_file.flush()
    accel_file.flush()
    gyro_file.close()
    accel_file.close()
