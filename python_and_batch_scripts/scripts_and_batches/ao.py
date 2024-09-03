import numpy as np
import argparse
from math import sin, cos, atan2, sqrt, radians

MIN_NUM_COLS  = 14
MAX_NUM_COLS = 17
FIRST_COL = 3



def read_magnetometer_data(file):
    offsets = np.zeros((1,3))
    calibrations = np.zeros((1,3))
    X = np.zeros((1,6))
    XT = np.zeros((6,1))
    XTY = np.zeros((6,1))
    XTY_sum = np.zeros((6,1))
    XTX = np.zeros((6,6))
    XTX_sum = np.zeros((6,6))
    XTX_inverse = np.zeros((6,6))
    beta = np.zeros((6,1))
    dataStr = file.read()
    vsqr = 0 

    lines = dataStr.splitlines(keepends=False)
    row = 0
    if dataStr:
        for line in lines:
            try:
                columns = line.split(',')
                if MIN_NUM_COLS <= len(columns) <= MAX_NUM_COLS :
                    i = 0
                    Y = 0
                    while i < 3 :
                        X[0,i]=(float(columns[i+FIRST_COL]))**2
                        XT[i,0]=(float(columns[i+FIRST_COL]))**2
                        X[0,i+3]=float(columns[i+FIRST_COL])
                        XT[i+3,0]=float(columns[i+FIRST_COL])
                        i=i+1
                    XTX = np.matmul(XT,X)
                    XTX_sum = XTX_sum + XTX
                    XTY[0,0] = X[0,0]
                    XTY[1,0] = X[0,1]
                    XTY[2,0] = X[0,2]
                    XTY[3,0] = X[0,3]
                    XTY[4,0] = X[0,4]
                    XTY[5,0] = X[0,5]         
                    XTY_sum = XTY_sum + XTY             
            except ValueError:
                pass
        #print("XTY_sum")
        #print(XTY_sum)
        #output_file.write("XTY_sum\r")
        #output_file.write(str(XTY_sum)+"\r")
        #print("XTX_sum")
        #print(XTX_sum)
        #output_file.write("XTX_sum\r")
        #output_file.write(str(XTX_sum)+"\r")           
        XTX_inverse = np.linalg.inv(XTX_sum)
        #print("XTX_inverse")
        #print(XTX_inverse)
        #output_file.write("XTX_inverse\r")
        #output_file.write(str(XTX_inverse)+"\r") 
        beta = np.matmul(XTX_inverse,XTY_sum)
        #print("beta")
        #print(beta)
        #output_file.write("beta\r")
        #output_file.write(str(beta)+"\r")
        calibrations[0,0]= 1/sqrt(beta[0,0])
        calibrations[0,1]= 1/sqrt(beta[1,0])
        calibrations[0,2]= 1/sqrt(beta[2,0])
        #print("calibrations")
        #print(calibrations)
        #output_file.write("calibrations\r")
        #output_file.write(str(calibrations)+"\r")
        offsets[0,0] = -(beta[3,0]/beta[0,0])/2
        offsets[0,1] = -(beta[4,0]/beta[1,0])/2
        offsets[0,2] = -(beta[5,0]/beta[2,0])/2
        #Bsqr = beta[3,0] - ( offsets[0,0]* offsets[0,0]  +  offsets[0,1]* offsets[0,1] + offsets[0,2]* offsets[0,2] )
        #print("offsets")
        #print(offsets)
        #output_file.write("offsets\r")
        #output_file.write(str(int(offsets[0,0]))+","+str(int(offsets[0,1]))+","+str(int(offsets[0,2]))+"\r")
        #print("B")
        #print(sqrt(Bsqr))
        vsqr = (offsets[0,0]/calibrations[0,0])**2+(offsets[0,1]/calibrations[0,1])**2+(offsets[0,2]/calibrations[0,2])**2
        adjustment = sqrt(1.0 + vsqr)
        #output_file.write("vsqr= "+str(vsqr)+" , adjustment= "+str(adjustment)+"\r")
        calibrations[0,0]=int(adjustment*calibrations[0,0])
        calibrations[0,1]=int(adjustment*calibrations[0,1])
        calibrations[0,2]=int(adjustment*calibrations[0,2])
        offsets[0,0]=adjustment*offsets[0,0]
        offsets[0,1]=adjustment*offsets[0,1]
        offsets[0,2]=adjustment*offsets[0,2]
        output_file.write("adjusted calibrations\r\n")
        #output_file.write(str(calibrations)+"\r")
        output_file.write(str(int(calibrations[0,0]))+","+str(int(calibrations[0,1]))+","+str(int(calibrations[0,2]))+"\r\n")   
        output_file.write("adjusted offsets\r\n")
        output_file.write(str(int(offsets[0,0]))+","+str(int(offsets[0,1]))+","+str(int(offsets[0,2]))+"\r\n")
               
    return None



if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog='mag_offset_and_calibration.py',
        description='computes magnetometer offsets and calibrations.')
    parser.add_argument('-f','--filename', help="base name of files")
    args = parser.parse_args()
    file_base_name = args.filename
    input_file = open(file_base_name+".csv")
    output_file = open(file_base_name+"_output.txt", "w")
    output_file.write("input file : "+file_base_name+".txt\r")
    read_magnetometer_data(input_file)

