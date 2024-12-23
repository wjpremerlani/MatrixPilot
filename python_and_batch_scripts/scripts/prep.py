
import argparse
import sys
              
if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='prep.py',
        description='Prepares for the Wright brothers two-step.')
    parser.add_argument('-f','--filename', help="Name of the file containing a list of files of run data.")
    
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
        except :
            print("unable to open list of files, check spelling.")
            log_file.write("unable to open list of files, check spelling.\r")
            exit()
        dataStr = input_file.read()
        lines = dataStr.splitlines(keepends=False)
        if dataStr:
            for line in lines :
                name_and_start = line.split(',')
                if len(name_and_start) > 1 :
                    data_file_name = name_and_start[0]
                    data_file_base_name = data_file_name.split('.')[0]
                    data_file_start = name_and_start[1]
                    log_file.write(f"name = {data_file_base_name} , start = {data_file_start } \r")            
                    bat_file.write(f"map.py -bill -f {data_file_name} -s {data_file_start} -e 60.0\n")
                    merge_file.write(f"{data_file_base_name}_time_map_100_HZ.csv\n")
            bat_file.write(f"merge.py -f {base_name}_merge_list.txt\n")
            bat_file.write(f"slice.py -f {base_name}_merge_list_plots.csv -zeros 200 -fcn 4\n")
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
