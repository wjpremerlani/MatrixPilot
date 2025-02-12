
import argparse
import sys


if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='streamlit_prep.py',
        description='Prepares for generation of 8 plots using streamlit.')
    parser.add_argument('-f','--filename', help="Name of the file being plotted")
    
    args = parser.parse_args()               

    if args.filename :
        bat_file = open("streamlit_plots.bat" , "w" )    
        bat_file.write(f"start cmd /c streamlit run yaw.py \"{args.filename}\"\n")
        bat_file.write(f"start cmd /c streamlit run roll.py \"{args.filename}\"\n")
        bat_file.write(f"start cmd /c streamlit run force.py \"{args.filename}\"\n")
        bat_file.write(f"start cmd /c streamlit run delta_time_and_pivot.py \"{args.filename}\"\n")      
    else :
        print(" You must provide a file with a list of the names of files to be processed")

    
    
    
        
