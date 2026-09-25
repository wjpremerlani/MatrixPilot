import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime
import argparse

global step_size
step_size = 100

def stamp(out_file,in_file) :
    time_stamp = 0.0
    in_file_data = in_file.read()
    in_file_lines = in_file_data.splitlines(keepends=False)
    for line in in_file_lines :
        out_file.write(f"{line},{int(time_stamp)}\n")
        time_stamp = time_stamp + step_size      

def build_arg_parser():
    parser = argparse.ArgumentParser(
        prog='stamper.py',
        description='adds a time stamp to the end of each line of a file')
    parser.add_argument('-f', '--filename', help="base name of files")
    parser.add_argument('-step','--step', help="step ratio between stamps")
    return parser
 

# Run from command line
if __name__ == "__main__":
    parser = build_arg_parser()
    args = parser.parse_args()
    if args.step:
        step_size = float(args.step)*100.0
    if args.filename:
        file_name = args.filename
        input_file = open(file_name+".txt",'r')
        if input_file :
            output_file = open(file_name+"_TS.txt",'w')
            stamp(output_file,input_file)
        else :
            print("input file not found")
            exit()
                           
    else :
        print("no file supplied")
        exit()
        
