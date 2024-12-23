
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
                        output_file.write(f"{str(value)}")
                    else :
                        output_file.write(f" , {str(value)}")
                else :
                    if value_number == 0 :
                        output_file.write(f"{str(value)}")
                    else :
                        output_file.write(f" , {str(value)}")
                value_number = value_number + 1
            if column_number < number_of_columns - 1 :
                output_file.write(f" ,  ")
        output_file.write(f" \r")

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

def open_files() :
    global file_name_list
    global file_numbers
    global number_of_files
    global row_numbers
    global number_of_rows   
    global file_data
    global column_numbers
    global number_of_columns
    number_of_files = 0 
    log_file.write(f"reading list of files from {list_of_files_file_name} \r")
    print("reading list of files from " , list_of_files_file_name )
    dataStr = input_file.read()
    file_names = dataStr.splitlines(keepends=False)
    if dataStr:
        for file_name in file_names:         
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
    
    args = parser.parse_args()

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
        open_files()
        preprocess()
        process()
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
