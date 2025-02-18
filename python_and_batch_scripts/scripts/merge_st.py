
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

file_name_list = []
file_numbers = []
number_of_files = 0
number_of_rows = 0
row_numbers = []
file_data = []
column_numbers = []
number_of_columns = 0

MARK_COLUMN_NUMBER = 1 

def process():
    global file_name_list
    global file_numbers
    global number_of_files
    global row_numbers
    global number_of_rows   
    global file_data
    global column_numbers
    global number_of_columns
    #print("number of columns = " , number_of_columns )
    #print("column numbers :" )
    #print(column_numbers)
    #print("number of rows = " , number_of_rows )
    #print("row numbers")
    #print(row_numbers)
    for row_number in row_numbers :
        values = []
        value_numbers = []
        for file_number in file_numbers :
            try :
                row = file_data[file_number][row_number]
                #print("row")
                #print(row)
                columns = row.split(',')
                for column_number in column_numbers :
                    try :
                        value = columns[column_number]
                    except :
                        value = str(0)
                    values.append(value)
            except :
                for column_number in column_numbers :
                    value = str(0)
                    values.append(value)
        value_number = 0
        for value in values :
            value_numbers.append(value_number)
            value_number = value_number + 1
        #print("value numbers : ")
        #print(value_numbers)
        value_number = 0
        for column_number in column_numbers :
            for file_number in file_numbers :
                index = file_number*number_of_columns + column_number
                value = values[index]
                if row_number == 0 :
                    if value_number == 0 :
                        output_file.write(f" {str(value)}")
                    else :
                        output_file.write(f" , {str(value)}")
                else :
                    if value_number == 0 :
                        output_file.write(f"{str(value)}")
                    else :
                        output_file.write(f" , {str(value)}")
                value_number = value_number + 1
            if ( column_number < number_of_columns - 1 ) and ( not args.no_gaps ) :
                output_file.write(f" ,  ")
        output_file.write(f" \n")

def preprocess():
    global file_name_list
    global file_numbers
    global number_of_files
    global row_numbers
    global number_of_rows
    global file_data
    global column_numbers
    global number_of_columns
    
    for file_number in file_numbers :
        rows = file_data[file_number]
        if len(rows)  > number_of_rows :
            number_of_rows = len(rows)
        #print("rows : ")
        #print(rows)
        #print("max row number = " , number_of_rows )
        columns = rows[0].split(',')
        if len(columns) > number_of_columns :
            number_of_columns = len(columns)
    #print( number_of_rows , " rows and " , number_of_columns , " columns " )
    column_number = 0
    while column_number < number_of_columns :
        column_numbers.append(column_number)
        column_number = column_number + 1
    row_number = 0
    while row_number < number_of_rows :
        row_numbers.append(row_number)
        row_number = row_number + 1
    #print("column numbers ")
    #print(column_numbers)
    #print("row_numbers")
    #print(row_numbers)

def validate_curves() :
    global valid_file_names
    opened_file_names = []
    valid_file_names = []
    max_mark_numbers = []
    dataStr = input_file.read()
    file_names = dataStr.splitlines(keepends=False)
    if dataStr:
        for file_name in file_names:         
            try :
                plot_file = open(file_name)
                data = plot_file.read()
                rows = data.splitlines(keepends=False)
                opened_file_names.append(file_name)
                mark_numbers = []
                for row in rows :
                    columns = row.split(',')
                    try :
                        mark_number = int(columns[MARK_COLUMN_NUMBER])
                        mark_numbers.append(mark_number)
                    except :
                        pass
                max_mark_number = max(mark_numbers)
                max_mark_numbers.append(max_mark_number)
                log_file.write(f"max mark = {max_mark_number} for file {file_name}\n")
                plot_file.close()
            except:
                pass
    input_file.close()
    #print("max mark numbers " , max_mark_numbers )
    if args.curves :
        min_mark = number_of_marks
    else :
        min_mark = min(max_mark_numbers)
    log_file.write(f"valid number of marks = {min_mark}.\n")
    for index in range(len(opened_file_names)) :
        if max_mark_numbers[index] == min_mark :
            valid_file_names.append(opened_file_names[index] )
        else :
            print("---->>>>> warning <<<<<<<<<<--------")
            print(opened_file_names[index] , "has wrong number of timing marks = " , max_mark_numbers[index])
            log_file.write(f"warning-->>> {opened_file_names[index]} has wrong number of timing marks = {max_mark_numbers[index]}.\n")
    log_file.write(f"valid runs : \n")
    for file_name in valid_file_names :
        log_file.write(f"{file_name}\n")
    

def open_files() :
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
    file_names = dataStr.splitlines(keepends=False)
    if dataStr:
        for file_name in valid_file_names:         
            try :
                plot_file = open(file_name)
                print(file_name,"was opened")
                log_file.write(f"{file_name} was opened.\r")
                data = plot_file.read()
                rows = data.splitlines(keepends=False)
                file_data.append(rows)
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
    #print("file_data")
    #print(file_data)
                 
if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='merge_plots.py',
        description='combines multiple plots into a single plot')
    parser.add_argument('-f','--filename', help="name of the file with list of plot files to be processed")
    parser.add_argument('-curves','--curves', help="expected number of curves.")
    parser.add_argument('-no_gaps','--no_gaps',action='store_true',help="option to remove gaps for streamlit plotting")
    
    args = parser.parse_args()

    if args.curves :
        number_of_marks = int(2*int(args.curves))

    if args.filename :
        list_of_files_file_name = args.filename
        base_name = list_of_files_file_name.split('.')[0]
        print("name of list of files : ",list_of_files_file_name)
        try :
            input_file = open(list_of_files_file_name)
        except :
            print("unable to open list of files, check spelling.")
            exit()
        output_file = open(base_name+"_plots.csv" , "w" )
        log_file = open(base_name+"_log.txt" , "w" )
        validate_curves()
        input_file = open(list_of_files_file_name)
        open_files()
        preprocess()
        process()
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
