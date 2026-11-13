import argparse
import sys

global file_name_list
global file_numbers
global number_of_files
global row_numbers
global number_of_rows   
global file_data
global column_numbers
global number_of_columns
global valid_file_names
global runs
global output_file

file_name_list = []
file_numbers = []
number_of_files = 0
runs = []

def open_files() :
    global runs
    global file_name_list
    global file_numbers
    global number_of_files
    global row_numbers
    global number_of_rows   
    global file_data
    global column_numbers
    global number_of_columns
    global valid_file_names
    number_of_files = 0 
    log_file.write(f"reading list of files from {list_of_files_file_name} \r")
    print("reading list of files from " , list_of_files_file_name )
    dataStr = input_file.read()
    file_name_rows = dataStr.splitlines(keepends=False)
    if dataStr:
        for file_name_row in file_name_rows:
            file_name_row_columns = file_name_row.split(',')
            file_name = file_name_row_columns[0]
            try :
                plot_file = open(file_name)
                run = plot_file.read()
                runs.append(run)
                print(file_name,"was opened")
                log_file.write(f"{file_name} was opened.\r")
                number_of_files = number_of_files + 1
                file_name_list.append(file_name)
                file_numbers.append(number_of_files-1)
            except:
                print("not able to open " , file_name , " , it was skipped.")
                log_file.write(f"not able to open {file_name} , it was skipped.\r")
    print("file name list")
    print(file_name_list)
    print("file_numbers")      
    print(file_numbers)
    print("number of files = " , number_of_files )
    #print("runs")
    #print(runs)


def process() :
    global file_numbers
    global number_of_files
    global runs
    global output_file
    for file_index in range(len(file_numbers)):
        file_number = number_of_files - 1 - file_index
        run_data = runs[file_number]
        run_rows = run_data.splitlines(keepends=False)
        if file_index == 0 :
            print("processing :", file_name_list[file_number])
            for run_row in run_rows :
                output_file.write(f"{run_row}\n")
        else :
            is_data = False
            residual_lines = 0 
            print("processing :", file_name_list[file_number])         
            for run_row in run_rows :
                columns = run_row.split(',')
                if ( len(columns) == 11) :
                    residual_lines = residual_lines + 1
                if (( (len(columns) == 1 ) or (len(columns) == 5 )) and is_data ) :
                    output_file.write(f"{run_row}\n")
                if columns[0] == str("z_force_xx") :
                    is_data = True
                    lost_blocks = residual_lines - 1
                    for block_number in range(lost_blocks) :
                        for set_number in range(200) :
                            for column in range (4 ) :
                                output_file.write(f"0.0,")
                            output_file.write(f"0.0\n")
                            for line_no in range (9) :
                                output_file.write(f"0.0\n")
                     
                     

                     
                     
            
    return

if __name__ == "__main__":
    global args
    global output_file
    parser = argparse.ArgumentParser(
        prog='concatenate.py',
        description='sequentially combines multiple runs into a run')
    parser.add_argument('-f','--filename', help="name of the file with list of plot files to be processed")

    args = parser.parse_args()

    if args.filename :
        list_of_files_file_name = args.filename
        base_name = list_of_files_file_name.split('.')[0]
        print("name of list of files : ",list_of_files_file_name)
        try :
            input_file = open(list_of_files_file_name)
            output_file = open(base_name+"_output.txt",'w')
                 
        except :
            print("unable to open list of files, check spelling.")
            exit()
        log_file = open(base_name+"_log.txt" , "w" )
        open_files()
        process()
        
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
