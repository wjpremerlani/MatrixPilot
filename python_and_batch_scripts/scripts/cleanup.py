
import argparse
import sys

                
if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='cleanup.py',
        description='cleans up after previous batch processing')
    
    args = parser.parse_args()
    
    rabbit_log_file = open("rabbit_log.txt" , "w")
    print("rabbit_log.txt was opened and emptied.")
    

    
    
    
        
