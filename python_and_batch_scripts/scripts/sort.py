
import argparse
import sys
import numpy as np

                
if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='sort.py',
        description='sort files by run time')
    parser.add_argument('-f','--filename', help="Name of file to store sorted merge list.")
    args = parser.parse_args()

    if args.filename :
        merge_list_name = args.filename
        try :
            output_file = open(merge_list_name,"w")
        except :
            print("unable to open" , merge_list_name , "is it already open?")
            exit
    else:
        print("missing name of merge list file.")
        exit()
    
    try :
        rabbit_log_file = open("rabbit_log.txt", "r")
    except :
        print ("rabbit_log.txt not found, batch processing stopped")
        exit()
    file_data = rabbit_log_file.read()
    rows = file_data.splitlines(keepends=False)
    names = []
    times = []
    for row in rows :     
        columns = row.split(',')
        names.append(columns[0])
        times.append(int(columns[1]))
    indices = np.argsort(times)
    for index in indices :
        output_file.write(f"{names[index]}_time_map_100_HZ.csv\n")
    
    
    
    
    
    
    

    
    
    
        
