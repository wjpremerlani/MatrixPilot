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
    gyro_accel_file.write("\n\n#ifndef TABLE_LUGE7_SN"+file_base_name+"_H\n")
    gyro_accel_file.write("#define TABLE_LUGE7_SN"+file_base_name+"_H\n")
    gyro_accel_file.write("\n// used in LUGE7_SN"+file_base_name+" partition size 64\n")
    gyro_accel_file.write("\n//#define X_CROSS_COUPLING 0\n")
    gyro_accel_file.write("#define Y_CROSS_COUPLING 0\n")
    gyro_accel_file.write("#define Z_CROSS_COUPLING 0\n")
    gyro_accel_file.write("\n\n#define STEP_SIZE 64\n\n\n")   
    gyro_accel_file.write("\n#define TABLE_ORIGIN ( "+initial_temperature+")\n\n")
    gyro_accel_file.write("int16_t residual_offset[] = { 0 , 0 , 0 } ; \n\n")
    gyro_accel_file.write("const struct gyro_offset_table_entry gyro_offset_table[] = {\n")
    return None

def gyro_table_end():
    gyro_accel_file.write("};\n\n")
    return None

def acc_table_start():
    gyro_accel_file.write("\n#define ACCEL_TABLE\n\n")
    gyro_accel_file.write("\n#define ACCEL_TABLE_ORIGIN ( "+initial_temperature+")\n\n")
    gyro_accel_file.write("int16_t accel_residual_offset[] = { 0 , 0 , 0 } ; \n\n")
    gyro_accel_file.write("const struct gyro_offset_table_entry accel_offset_table[] = {\n")    
    return None

def acc_table_end():
    gyro_accel_file.write("};\n\n")
    gyro_accel_file.write("#endif /* TABLE_LUGE7_SN"+file_base_name+"_H */\n\n")
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
    gyro_accel_file = open("table_luge7_sn"+file_base_name+".h", "w")
    rows = read_raw_data_from_txt("sn"+file_base_name+"_t_comp_data.txt")
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
        global sum_dxsq
        global sum_dysq
        global sum_dzsq
        if row_number < number_rows :
            sum_column_4 += int(row[4])
            sum_column_5 += int(row[5])
            sum_column_6 += int(row[6])
            sum_column_7 += int(row[7])
            sum_column_8 += int(row[8])
            sum_column_9 += int(row[9])
            sum_dxsq += (int(row[4])-int(row[7]))**2
            sum_dysq += (int(row[5])-int(row[8]))**2
            sum_dzsq += (int(row[6])-int(row[9]))**2              
            row_number += 1   
    def process_gyro_table(row):
        global row_number
        if row_number < number_rows :
            gyro_accel_file.write("{"+str(int(row[7]))+","+str(int(row[8]))+","+str(int(row[9]))+"},\n")
            row_number += 1
    def process_acc_table(row):
        global row_number
        if row_number < number_rows :
            gyro_accel_file.write("{"+str(int(row[10]))+","+str(int(row[11]))+","+str(int(row[12]))+"},\n")
            row_number += 1
    # applies the above functions to each row
    row_number = 0
    sum_column_4 = 0
    sum_column_5 = 0
    sum_column_6 = 0
    sum_column_7 = 0
    sum_column_8 = 0
    sum_column_9 = 0
    sum_dxsq = 0
    sum_dysq = 0
    sum_dzsq = 0
    
    np.apply_along_axis(process_offsets, axis=0, arr=rows)
    dx_bar = int((sum_column_7-sum_column_4)/number_rows)
    dy_bar = int((sum_column_8-sum_column_5)/number_rows)
    dz_bar = int((sum_column_9-sum_column_6)/number_rows)
    dxsq_bar = sum_dxsq / number_rows
    dysq_bar = sum_dysq / number_rows
    dzsq_bar = sum_dzsq / number_rows
    sdevx = int(sqrt(dxsq_bar - dx_bar**2)/64)
    sdevy = int(sqrt(dysq_bar - dy_bar**2)/64)
    sdevz = int(sqrt(dzsq_bar - dz_bar**2)/64)
    sdevrms = int(sqrt(sdevx**2+sdevy**2+sdevz**2))
                          
    print("offsets = "+str(dx_bar)+" , "+str(dy_bar)+" , " +str(dx_bar)+"\n")
    print("standard deviations, x = "+str(sdevx)+" , y = "+str(sdevy)+" , z = " +str(sdevz)+" , total rms = "+str(sdevrms)+"\n")
    row_number = 0
    gyro_table_start()
    np.apply_along_axis(process_gyro_table, axis=0, arr=rows)
    gyro_table_end()
    row_number = 0
    acc_table_start()
    np.apply_along_axis(process_acc_table, axis=0, arr=rows)
    acc_table_end()
    gyro_accel_file.flush()
    gyro_accel_file.close()
