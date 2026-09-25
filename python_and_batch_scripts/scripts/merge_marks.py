import argparse
import sys

global file_names, file_numbers , files , dataStr , model_dataStr

file_names = []
file_numbers = []
files = []

global n_in , n_out , s_in , s_out , d_in , d_out , t_in , t_out , v_in , v_out
n_in = []
n_out = []
s_in = []
s_out = []
d_in = []
d_out = []
t_in = []
t_out = []
v_in = []
v_out = []

global first_file , first_line , number_of_rows_in , number_of_rows , N , row_numbers , row_number
first_file = True
first_line = True
number_of_rows_in = 0
number_of_rows_out = 0
N = 0
row_numbers = []
row_number = 0 

global mark_number_in , mark_state_in , mark_distance_in , mark_time_in , mark_velocity_in
global mark_number_out , mark_state_out , mark_distance_out , mark_time_out , mark_velocity_out

mark_number_in = 0
mark_state_in = 0
mark_distance_in = 0.0
mark_time_in = 0.0
mark_velocity_in = 0.0

mark_number_out = 0
mark_state_out = 0
mark_distance_out = 0.0
mark_time_out = 0.0
mark_velocity_out = 0.0

N_COL = 0
S_COL = 1
D_COL = 2
T_COL = 3
V_COL = 4

def print_model() :
    global n_out , s_out , d_out ,  t_out , v_out
    row_number = 0
    output_file.write("mark_number,mark_state,distance,time,velocity\r")
    for mark_number in n_out :
        output_file.write(f"{mark_number},")
        output_file.write(f"{s_out[row_number]},")
        output_file.write(f"{round( (d_out[row_number]/number_of_files) , 2)},")
        output_file.write(f"{round( (t_out[row_number]/number_of_files) , 2)},")
        output_file.write(f"{round( (v_out[row_number]/number_of_files) , 2)}\r" )
        row_number = row_number + 1

def process_model() :
    
    global file_names, file_numbers , files , dataStr , model_dataStr , number_of_files , number_of_rows
    global n_in , n_out , s_in , s_out , d_in , d_out , t_in , t_out , v_in , v_out
    global first_file , first_line , number_of_rows_in , number_of_rows_out , N , row_numbers , row_number
    global mark_number_in , mark_state_in , mark_distance_in , mark_time_in , mark_velocity_in
    global mark_number_out , mark_state_out , mark_distance_out , mark_time_out , mark_velocity_out

    number_of_rows_in = 0
    row_number = 0
    first_line = True
    if model_dataStr:
        model_lines = model_dataStr.splitlines(keepends=False)
        if first_file == True :
            first_file = False
            for model_line in model_lines:
                if first_line == True :
                    first_line = False
                else :
                    try:
                        columns = model_line.split(',')
                        n_out.append(int(columns[N_COL]))
                        s_out.append(int(float(columns[S_COL])))
                        d_out.append(float(columns[D_COL]))
                        t_out.append(float(columns[T_COL]))
                        v_out.append(float(columns[V_COL]))
                        row_numbers.append(row_number)
                        row_number = row_number+1
                        number_of_rows_in = number_of_rows_in + 1
                    except :
                        pass
            number_of_rows = number_of_rows_in
            log_file.write(f"processed the first file, which has { number_of_rows_in } rows.\r")
            print("number of rows in first file = " , number_of_rows_in )
        else:
            first_line = True
            model_lines = model_dataStr.splitlines(keepends=False)
            number_of_rows_in = len(model_lines)
            log_file.write(f"processing file number {number_of_files}\r")
            log_file.write(f"it has {( number_of_rows_in - 1 ) } rows\r")
            print("processing file number " , number_of_files )
            print("it has " , number_of_rows_in - 1 , "rows" )
            if number_of_rows_in - 1 == number_of_rows :
                print("which agrees with the first file.")
                log_file.write("which agrees with the first file.\r")
                row_number = 0
                for model_line in model_lines :
                    if first_line == True :
                        first_line = False
                    else :
                        columns = model_line.split(',')
                        try:
                            mark_number = int(columns[N_COL])
                            mark_state = int(float(columns[S_COL]))
                            mark_distance = float(columns[D_COL])
                            mark_time = float(columns[T_COL])
                            mark_velocity = float(columns[V_COL])
                            if mark_state != s_out[row_number] :
                                print("warning: mark state " , mark_state , "in file number " , number_of_files , " in row number " , row_number , "does not match."  )
                                log_file.write(f"warning: mark state  , {mark_state} , in file number  , {number_of_files} ,  in row number  , {row_number} does not match.\r"  )
                            if mark_number != n_out[row_number] :
                                print("warning: mark state " , mark_number , "in file number " , number_of_files , " in row number " , row_number , "does not match."  )
                                log_file.write(f"warning: mark state  , {mark_state} , in file number  , {number_of_files} ,  in row number  , {row_number} does not match\r"  )                       
                            d_out[row_number] = d_out[row_number] + mark_distance
                            t_out[row_number] = t_out[row_number] + mark_time
                            v_out[row_number] = v_out[row_number] + mark_velocity                        
                            row_number = row_number + 1 
                        except :
                            pass
            else:
                log_file.write("which does not agree with the first file, file will be skipped.\r")
                print("which does not agree with the first file, file will be skipped.")
                pass
            

def open_files() :
    #global dataStr
    global file_names, file_numbers , files , model_dataStr , number_of_files
    global n_in , n_out , s_in , s_out , d_in , d_out , t_in , t_out , v_in , v_out
    global first_file , first_line , number_of_rows_in , number_of_rows_out , N , row_numbers , row_number
    global mark_number_in , mark_state_in , mark_distance_in , mark_time_in , mark_velocity_in
    global mark_number_out , mark_state_out , mark_distance_out , mark_time_out , mark_velocity_out

    number_of_files = 0 
    log_file.write(f"reading list of files from {list_of_files_file_name} \r")
    print("reading list of files from " , list_of_files_file_name )
    dataStr = input_file.read()
    lines = dataStr.splitlines(keepends=False)
    if dataStr:
        for line in lines:
            number_of_files = number_of_files + 1
            file_names.append(line)
            file_numbers.append(number_of_files)
            try :
                model_file = open(line)
                files.append(model_file)
                print(line,"was opened")
                log_file.write(f"{line} was opened.\r")
                model_dataStr = model_file.read()
                process_model()   
            except:
                print("not able to open " , line , " ,it was skipped.")
                log_file.write(f"not able to open {line} , it was skipped.")
    print_model()                  


if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='merge_marks.py',
        description='combines multiple track timing marks into a track timing mark file')
    parser.add_argument('-f','--filename', help="name of the file with list of files to be processed")
    
    args = parser.parse_args()

    if args.filename :
        list_of_files_file_name = args.filename
        print("name of list of files : ",list_of_files_file_name)
        try :
            input_file = open(list_of_files_file_name)
        except :
            print("unable to open list of files, check spelling.")
            exit()
        output_file = open("track_timing_mark_model_"+list_of_files_file_name , "w" )
        log_file = open("log_"+list_of_files_file_name , "w" )
        open_files()                    
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
