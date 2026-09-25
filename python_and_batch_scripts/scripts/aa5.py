

global minimum_speed
minimum_speed = 20.0

import numpy as np
import argparse
from math import sin, cos, atan2, sqrt, radians, degrees

NUM_COLS  = 11

XA_COL = 0 
YA_COL = 1 
ZA_COL = 2 
YAW_COL = 3 
PITCH_COL = 4 
ROLL_COL = 5

global args


global first_line
first_line = 1
global line_number
line_number = 0 

global yaw_offset , pitch_offset , roll_offset
yaw_offset = 0.0
pitch_offset = 0.0
roll_offset = 0.0

global gx , gy , gz
gx = 0
gy = 0
gz = 0

global yaw_drift , pitch_drift , roll_drift
yaw_drift = 0.0
pitch_drift = 0.0
roll_drift = 0.0

global pitch_zero , roll_zero
pitch_zero = 0.0
roll_zero = 0.0

#note: end = start + elapsed
global rotation , start , end , elapsed
#default values
rotation = 0.0
start = 0
elapsed = 300.
end = 300.

global ypr_o_mat , ypr_o_mat_trans, y_mat , p_mat , r_mat , yp_mat , ypr_mat
global drift_mat
global first_mat
ypr_o_mat = np.zeros((3,3))
ypr_o_mat_trans = np.zeros((3,3))
y_mat = np.zeros((3,3))
p_mat = np.zeros((3,3))
r_mat = np.zeros((3,3))
yp_mat = np.zeros((3,3))
ypr_mat = np.zeros((3,3))
drift_mat = np.zeros((3,3))
first_mat = np.zeros((3,3))

global force_in , force_out
force_in = np.zeros((3,1))
force_out = np.zeros((3,1))

global gyro_wp, gyro_sled
gyro_wp = np.zeros((3,1))
gyro_sled = np.zeros((3,1))

global heading , previous_yaw

global matrix_out, matrix_in , matrix_out_prev , matrix_in_prev
global matrix_update
global matrix_adjusted
matrix_out = np.zeros((3,3))
matrix_in = np.zeros((3,3))
matrix_out_prev = np.zeros((3,3))
matrix_in_prev = np.zeros((3,3))
matrix_update = np.zeros((3,3))
matrix_adjusted = np.zeros((3,3))

global xa_in, ya_in, za_in , xa_out, ya_out, za_out
xa_in = 0
ya_in = 0
za_in = 0
xa_out = 0
ya_out = 0
za_out = 0

global yaw_in, pitch_in, roll_in, yaw_out, pitch_out, roll_out
yaw_in = 0
pitch_in = 0
roll_in = 0
yaw_out = 0
pitch_out = 0
roll_out = 0

global first_heading
global first_heading_recorded
first_heading_recorded = 0

global speed
speed = 0
global x , y
x = 0
y = 0


def create_yaw_matrix(angle) :
    global y_mat
    y_mat[0,0] = cos(radians(angle))
    y_mat[0,1] = -sin(radians(angle))
    y_mat[0,2] = 0.0
    y_mat[1,0] = sin(radians(angle))
    y_mat[1,1] = cos(radians(angle))
    y_mat[1,2] = 0.0
    y_mat[2,0] = 0.0
    y_mat[2,1] = 0.0
    y_mat[2,2] = 1.0

def create_pitch_matrix(angle) :
    global p_mat
    p_mat[0,0] = cos(radians(angle))
    p_mat[0,1] = 0.0
    p_mat[0,2] = sin(radians(angle))
    p_mat[1,0] = 0.0
    p_mat[1,1] = 1.0
    p_mat[1,2] = 0.0
    p_mat[2,0] = -sin(radians(angle))
    p_mat[2,1] = 0.0
    p_mat[2,2] = cos(radians(angle))
   

def create_roll_matrix(angle) :
    global r_mat
    r_mat[0,0] = 1.0
    r_mat[0,1] = 0.0
    r_mat[0,2] = 0.0
    r_mat[1,0] = 0.0
    r_mat[1,1] = cos(radians(angle))
    r_mat[1,2] = -sin(radians(angle))
    r_mat[2,0] = 0.0
    r_mat[2,1] = sin(radians(angle))
    r_mat[2,2] = cos(radians(angle))

def create_ypr_matrix(yaw,pitch,roll) :
    global y_mat
    global yp_mat
    global ypr_mat
    create_yaw_matrix(yaw)
    create_pitch_matrix(pitch)
    create_roll_matrix(roll)
    yp_mat = np.matmul(y_mat,p_mat)
    ypr_mat = np.matmul(yp_mat,r_mat)


def read_data(file):
    global xa_in, ya_in, za_in , xa_out, ya_out, za_out
    global yaw_in, pitch_in, roll_in, yaw_out, pitch_out, roll_out
    global matrix_out, matrix_in , matrix_out_prev , matrix_in_prev , deter
    global ypr_mat, ypr_o_mat , ypr_o_mat_transpose
    global heading , previous_yaw
    global first_line
    global line_number
    global force_in , force_out
    global gyro_wp , gyro_sled
    global start , end , elapsed
    global first_heading
    global first_heading_recorded
    global rotation
    global speed
    global x , y
    global yaw_drift , pitch_drift , roll_drift
    global yaw_offset , pitch_offset , roll_offset
    global gx , gy , gz
    global drift_mat
    global matrix_adjusted
    global matrix_update
    global pitch_zero , roll_zero
    global pitch_start , pitch_end , roll_start , roll_end
    global args
    gravity = np.zeros((3,1))
    gravity_sum = np.zeros((3,1))
    g_sqr_sum = 0
    x_yaw = np.zeros((2,1))
    x_pitch = np.zeros((2,1))
    x_roll = np.zeros((2,1))
    xTx = np.zeros((2,2))
    xTx_inv = np.zeros((2,2))
    xTx_sum = np.zeros((2,2))
    beta_yaw = np.zeros((2,1))
    beta_pitch = np.zeros((2,1))
    beta_roll = np.zeros((2,1))
    yaw_sqr_sum = 0
    pitch_sqr_sum = 0
    roll_sqr_sum = 0

    yaw_var = 0
    pitch_var = 0
    roll_var = 0
    
    
    N = 0
    
    dataStr = file.read()
    lines = dataStr.splitlines(keepends=False)
    first_line = 1
    line_number = 0 
    if dataStr:
        for line in lines:
            columns = line.split(',')
            if len(columns) == NUM_COLS :
                try:
                    gravity[0,0] = - float(columns[XA_COL])
                    gravity[1,0] = - float(columns[YA_COL])
                    gravity[2,0] = - float(columns[ZA_COL])
                    yaw_in = float(columns[YAW_COL])
                    pitch_in = float(columns[PITCH_COL])
                    roll_in = float(columns[ROLL_COL])
                    if line_number < int(100*start):
                        N = N + 1
                        gravity_sum = gravity_sum + gravity
                        g_sqr_sum = g_sqr_sum + np.vdot(gravity,gravity)
                        xTx[0,0] = N*N
                        xTx[1,1] = 1.0
                        xTx[0,1] = N
                        xTx[1,0] = N
                        xTx_sum = xTx_sum + xTx
                        x_yaw[0,0] = x_yaw[0,0] + N*yaw_in
                        x_yaw[1,0] = x_yaw[1,0] + yaw_in
                        x_pitch[0,0] = x_pitch[0,0] + N*pitch_in
                        x_pitch[1,0] = x_pitch[1,0] + pitch_in
                        x_roll[0,0] = x_roll[0,0] + N*roll_in
                        x_roll[1,0] = x_roll[1,0] + roll_in
                        yaw_sqr_sum = yaw_sqr_sum + yaw_in**2
                        pitch_sqr_sum = pitch_sqr_sum + pitch_in**2
                        roll_sqr_sum = roll_sqr_sum + roll_in**2
                        
                    line_number = line_number + 1
                
                except ValueError:
                    pass    
            else:
                pass                             

        g_var = N*g_sqr_sum - np.vdot(gravity_sum , gravity_sum)
        if g_var > 0 :
            g_std = sqrt(g_var)/N
        else:
            g_std = 0

        if N > 10 :
            xTx_inv = np.linalg.inv(xTx_sum)
            
            beta_yaw = np.matmul(xTx_inv,x_yaw)
            beta_pitch = np.matmul(xTx_inv,x_pitch)
            beta_roll = np.matmul(xTx_inv,x_roll)
            yaw_var = yaw_sqr_sum - np.vdot(x_yaw, beta_yaw )
            pitch_var = pitch_sqr_sum - np.vdot(x_pitch, beta_pitch )
            roll_var = roll_sqr_sum - np.vdot(x_roll, beta_roll )
            
            print("beta yaw = " , beta_yaw , " standard deviation yaw = " , round(sqrt(yaw_var/N),2) , "drift = " , round(6000.0*beta_yaw[0,0],2) )
            print("beta pitch = " , beta_pitch , " standard deviation pitch = " , round(sqrt(pitch_var/N),2), "drift = " , round(6000.0*beta_pitch[0,0],2) )
            print("beta roll = " , beta_roll , " standard deviation roll = " , round(sqrt(roll_var/N),2), "drift = " , round(6000.0*beta_roll[0,0],2) )

            log_file.write(f"gyro drift analysis:\r\r")
            log_file.write(f"yaw: slope and offset = {beta_yaw} , stdev = {round(sqrt(yaw_var/N),2)} degrees , drift = {round(6000.0*beta_yaw[0,0],2)} deg/min\r\r")
            log_file.write(f"pitch: slope and offset = {beta_pitch} , stdev = {round(sqrt(pitch_var/N),2)} degrees , drift = {round(6000.0*beta_pitch[0,0],2)} deg/min\r\r")
            log_file.write(f"roll: slope and offset = {beta_roll} , stdev = {round(sqrt(roll_var/N),2)} degrees , drift = {round(6000.0*beta_roll[0,0],2)} deg/min\r\r")
            log_file.write(f"note: standard deviations refer to how well the data fits a straight line.\r\r")
        else:
            log_file.write("gyro drift not analzed, not enough data.\r\r")
        
        gx = gravity_sum[0,0]
        gy = gravity_sum[1,0]
        gz = gravity_sum[2,0]

        log_file.write("analysis of specific force data:\r\r")
        log_file.write(f"x, y and z average force vector = {round(gravity_sum[0,0]/N,2)} , {round(gravity_sum[1,0]/N,2)} , {round(gravity_sum[2,0]/N,2)} feet per second per second.\r")
        log_file.write(f"square root of the sum of the squares of x, y and z standard deviations = {round(g_std,2)} feet per second per second.\r\r")
        
        if not args.yaw_offset :
            log_file.write(f"default yaw alignment offset of {yaw_offset} degrees was used.\r")              
        else:
            log_file.write(f"yaw alignment offset of {yaw_offset} degrees was specified.\r")

        if not args.pitch_offset :
            pitch_offset = round(degrees(atan2(-gx , sqrt((gy)**2+(gz)**2))),2)
            log_file.write(f"pitch alignment offset of {pitch_offset} degrees was computed.\r")              
        else:
            log_file.write(f"pitch alignment offset of {pitch_offset} degrees was specified.\r")

        if not args.roll_offset :
            roll_offset = round(degrees(atan2(gy,gz)),2)
            log_file.write(f"roll alignment offset of {roll_offset} degrees was computed.\r\r")
        else:
            log_file.write(f"roll alignment offset of {roll_offset} degrees was specified.\r\r")

        
        if args.yaw_drift :
            log_file.write(f"yaw drift of {yaw_drift} degrees per minute was specified.\r")
        else :
            log_file.write(f"default yaw drift of {yaw_drift} degrees per minute was used.\r")

        if args.pitch_drift :
            log_file.write(f"pitch drift {pitch_drift} degrees per minute was specified.\r")
        else :
            if N > 10 :
                pitch_drift = round(6000.0*beta_pitch[0,0],2)
                log_file.write(f"pitch drift of {pitch_drift} degrees/minute was computed.\r")
            else:
                log_file.write(f"default pitch drift of {pitch_drift} degrees/minute was used.\r")

        if args.roll_drift :
            log_file.write(f"roll drift of {roll_drift} degrees/minute was specified.\r")
        else :
            if N > 10 :
                roll_drift = round(6000.0*beta_roll[0,0],2)
                log_file.write(f"roll drift of {roll_drift} degrees/minute was computed.\r")
            else:
                log_file.write(f"default roll drift of {roll_drift} degrees/minute was used.\r")
                
    first_line = 1
    line_number = 0 


    print("yaw alignment offset of wolf-pac mounting = " , yaw_offset , " degrees.")
    print("pitch alignment offset of wolf-pac mounting = " , pitch_offset , " degrees.")
    print("roll alignment offset of wolf-pac mounting = " , roll_offset, " degrees." )

    print("pitch alignment offset of sled with respect to level at first line = " , pitch_zero , " degrees.")
    print("roll alignment offset of sled with respect to level at first line = " , roll_zero, " degrees." )
    
    print("yaw gyro bias  = " , yaw_drift , " degrees per minute.")
    print("pitch gyro bias  = " , pitch_drift , " degrees per minute.")
    print("roll gyro bias  = " , roll_drift , " degrees per minute.")

    print("g_sqr_sum = " , g_sqr_sum  , "g_var ",  g_var , " g_std = " , g_std , " N = " , N )

    
    print("map rotation = " , rotation , " degrees")
    print("start map at line " , int(100*start ))
    print("end map at line " , int(100*(start+elapsed) ))

    #log_file.write("\rparameters used in adjustments for gyro drift and misalignment and map generation:\r")
    log_file.write("\radjustment parameters:\r\r")
    log_file.write("yaw alignment offset of wolf-pac mounting = "+str(yaw_offset)+" degrees.\r")
    log_file.write("pitch alignment offset of wolf-pac mounting = "+str(pitch_offset)+" degrees.\r")
    log_file.write("roll alignment offset of wolf-pac mounting = "+str(roll_offset)+" degrees.\r" )

    log_file.write("pitch alignment offset of sled with respect to level at first line = "+str(pitch_zero)+" degrees.\r")
    log_file.write("roll alignment offset of sled with respect to level at first line = "+str(roll_zero)+" degrees.\r" )
    
    log_file.write("yaw gyro bias  = "+str(yaw_drift)+" degrees per minute.\r")
    log_file.write("pitch gyro bias  = "+str(pitch_drift)+" degrees per minute.\r")
    log_file.write("roll gyro bias  = "+str(roll_drift)+" degrees per minute.\r\r")

    log_file.write("map generation parameters:\r\r")
    log_file.write(f"map rotation = {rotation} degrees\r")               
    log_file.write(f"start map at line {int(100*start)}\r")
    log_file.write(f"end map at line {int(100*(start+elapsed))}\r")

    output_file.write("reprocessed file to account for gyro drift and misalignments.\r\r")
    output_file.write("yaw alignment offset of wolf-pac mounting = "+str(yaw_offset)+" degrees.\r")
    output_file.write("pitch alignment offset of wolf-pac mounting = "+str(pitch_offset)+" degrees.\r")
    output_file.write("roll alignment offset of wolf-pac mounting = "+str(roll_offset)+" degrees.\r" )

    output_file.write("pitch alignment offset of sled with respect to level at first line = "+str(pitch_zero)+" degrees.\r")
    output_file.write("roll alignment offset of sled with respect to level at first line = "+str(roll_zero)+" degrees.\r" )
    
    output_file.write("yaw gyro bias  = "+str(yaw_drift)+" degrees per minute.\r")
    output_file.write("pitch gyro bias  = "+str(pitch_drift)+" degrees per minute.\r")
    output_file.write("roll gyro bias  = "+str(roll_drift)+" degrees per minute.\r\r")


    #map_file.write("reprocessed file to account for gyro drift and misalignments.\r\r")
    #map_file.write("yaw alignment offset of wolf-pac mounting = "+str(yaw_offset)+" degrees.\r")
    #map_file.write("pitch alignment offset of wolf-pac mounting = "+str(pitch_offset)+" degrees.\r")
    #map_file.write("roll alignment offset of wolf-pac mounting = "+str(roll_offset)+" degrees.\r" )

    #map_file.write("pitch alignment offset of sled with respect to level at first line = "+str(pitch_zero)+" degrees.\r")
    #map_file.write("roll alignment offset of sled with respect to level at first line = "+str(roll_zero)+" degrees.\r" )
    
    #map_file.write("yaw gyro bias  = "+str(yaw_drift)+" degrees per minute.\r")
    #map_file.write("pitch gyro bias  = "+str(pitch_drift)+" degrees per minute.\r")
    #map_file.write("roll gyro bias  = "+str(roll_drift)+" degrees per minute.\r\r")

    #map_file.write("map rotation = "+str(rotation)+" degrees\r")
    #map_file.write("start map at line "+str(int(100*start ))+"\r")
    #map_file.write("end map at line "+str(int(100*(start+elapsed)))+"\r\r" )

    #compare_file.write("comparison of input and output force and euler angles.\r")

    #compare_file.write("yaw alignment offset of wolf-pac mounting = "+str(yaw_offset)+" degrees.\r")
    #compare_file.write("pitch alignment offset of wolf-pac mounting = "+str(pitch_offset)+" degrees.\r")
    #compare_file.write("roll alignment offset of wolf-pac mounting = "+str(roll_offset)+" degrees.\r" )

    #compare_file.write("pitch alignment offset of sled with respect to level at first line = "+str(pitch_zero)+" degrees.\r")
    #compare_file.write("roll alignment offset of sled with respect to level at first line = "+str(roll_zero)+" degrees.\r" )
    
    #compare_file.write("yaw gyro bias  = "+str(yaw_drift)+" degrees per minute.\r")
    #compare_file.write("pitch gyro bias  = "+str(pitch_drift)+" degrees per minute.\r")
    #compare_file.write("roll gyro bias  = "+str(roll_drift)+" degrees per minute.\r\r")

    
    
    create_ypr_matrix(yaw_offset, pitch_offset , roll_offset)
    ypr_o_mat = ypr_mat
    print("offset matrix")
    print(ypr_o_mat)
    #compare_file.write("offset matrix\r")
    #compare_file.write(f"{ypr_o_mat}\r")
    ypr_o_mat_transpose = np.transpose(ypr_o_mat)
    create_ypr_matrix(-yaw_drift/6000.0, -pitch_drift/6000.0, -roll_drift/6000.0)    
    drift_mat = ypr_mat
    print("drift matrix")
    print (drift_mat)
    #compare_file.write("drift matrix")
    #compare_file.write(f"{drift_mat}\r")
    create_ypr_matrix(0.0, pitch_zero , roll_zero)
    first_mat = ypr_mat
    print("first record orientation matrix")
    print(first_mat)
    #compare_file.write("first record orientation matrix\r")
    #compare_file.write(f"{first_mat}\r\r")

    compare_file.write("x_force_in , x_force_out , y_force_in, y_force_out , z_force_in , z_force_out , yaw_in , yaw_out , pitch_in , pitch_out, roll_in , roll_out\r")
 
    map_file.write("x_force_xx,y_force_xx,z_force_xx,yaw_xx,pitch_xx,roll_xx,yaw_rate_xx,pitch_rate_xx,roll_rate_xx,max_gyro_pct_xx,cpu_xx,seq_no_xx,tmptur_xx,speed_xx,X_xx,Y_xx\r")
        
    lines = dataStr.splitlines(keepends=False)
    if dataStr:
        for line in lines:
            columns = line.split(',')
            if len(columns) == NUM_COLS :
                try:
                    xa_in = float(columns[XA_COL])
                    ya_in = float(columns[YA_COL])
                    za_in = float(columns[ZA_COL])
                    yaw_in = float(columns[YAW_COL])
                    pitch_in = float(columns[PITCH_COL])
                    roll_in = float(columns[ROLL_COL])

                    line_number = line_number + 1
                    
                    create_ypr_matrix(yaw_in,pitch_in,roll_in)
                    matrix_in = ypr_mat
                    if first_line == 1 :
                        matrix_out = np.matmul(first_mat,ypr_o_mat)
                        matrix_in_prev = matrix_in
                        matrix_out_prev = matrix_out
                    else :
                        matrix_update = np.matmul(np.matmul(np.transpose(matrix_in_prev),matrix_in),drift_mat)
                        matrix_out = np.matmul(matrix_out_prev,matrix_update)
                        matrix_out_prev = matrix_out
                        matrix_in_prev = matrix_in
                        
                        gyro_wp[0,0] = 50.0*degrees(matrix_update[2,1]-matrix_update[1,2])
                        gyro_wp[1,0] = 50.0*degrees(matrix_update[0,2]-matrix_update[2,0])
                        gyro_wp[2,0] = 50.0*degrees(matrix_update[1,0]-matrix_update[0,1])

                        gyro_sled = np.matmul(ypr_o_mat,gyro_wp)
                        
                        
                    deter = np.linalg.det(matrix_out)

                    matrix_adjusted = np.matmul(matrix_out,ypr_o_mat_transpose)
                    
                    yaw_out = round(degrees(atan2(matrix_adjusted[1,0],matrix_adjusted[0,0])),2)
                    pitch_out = round(degrees(atan2(-matrix_adjusted[2,0], sqrt((matrix_adjusted[2,1])**2+(matrix_adjusted[2,2])**2))),2)
                    roll_out = round(degrees(atan2(matrix_adjusted[2,1],matrix_adjusted[2,2])),2)

                    force_in[0,0] = xa_in
                    force_in[1,0] = ya_in
                    force_in[2,0] = za_in

                    force_out = np.matmul(ypr_o_mat,force_in)

                    xa_out = round(force_out[0,0],2)
                    ya_out = round(force_out[1,0],2)
                    za_out = round(force_out[2,0],2)
                    
                    
                    if first_line == 1 :
                        first_line = 0
                        heading = yaw_out
                        previous_yaw = yaw_out
                    else :
                        if abs(yaw_out - previous_yaw) < 90 :
                            heading = heading + yaw_out - previous_yaw
                        else :
                            if yaw_out - previous_yaw > 0 :
                                heading = heading + yaw_out - previous_yaw - 360
                            else :
                                heading = heading + yaw_out - previous_yaw + 360
                        previous_yaw = yaw_out
                    
                    output_file.write(str(xa_out)+","+str(ya_out)+","+str(za_out)+",")
                    output_file.write(str(round(heading,2))+","+str(pitch_out)+","+str(roll_out)+",")
                    output_file.write(columns[6]+","+columns[7]+","+columns[8]+","+columns[9]+","+columns[10]+"\r")
                    
                    compare_file.write(f"{xa_in},{xa_out},{ya_in},{ya_out},{za_in},{za_out},{yaw_in},{round(heading,2)},{pitch_in},{pitch_out},{roll_in},{roll_out}\r")
                    
                    end = start + elapsed
                    if int(100*start) <= line_number <= int(100*end) :
                        if first_heading_recorded == 0 :
                            first_heading = heading
                            first_heading_recorded = 1
                        cosine = cos(radians(heading-first_heading+rotation))
                        sine = -sin(radians(heading-first_heading+rotation))
                        speed = speed +(xa_out - 32.174*sin(radians(pitch_out)))/100
                        if speed < minimum_speed and line_number > int(100*(start + elapsed/2)) :
                            speed = minimum_speed
                        x = x + (speed/100)*cosine
                        y = y + (speed/100)*sine
                        map_file.write(f"{xa_out},{ya_out},{za_out},")
                        map_file.write(f"{round(heading,2)},{pitch_out},{roll_out},")
                        map_file.write(f"{round(gyro_sled[2,0],2)},{round(gyro_sled[1,0],2)},{round(gyro_sled[0,0],2)},")
                        map_file.write(f"{columns[7]},{columns[8]},{columns[9]},{columns[10]},")
                        map_file.write(f"{round(speed,2)},{round(x,2)},{round(y,2)}\r")
                    
                    
                except ValueError:
                    output_file.write(line+"\r")
                    pass    
            else:
                output_file.write(line+"\r")                             
    return None


if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='aa4.py',
        description='adjusts for misalignment, computes speed, gyro rates and generates map')
    parser.add_argument('-f','--filename', help="base name of files")
    parser.add_argument('-y','--yaw_offset', help="yaw alignment offset of wolf-pac with respect to sled")
    parser.add_argument('-p','--pitch_offset', help="pitch alignment offset of wolf-pac with respect to sled")
    parser.add_argument('-r','--roll_offset', help="roll alignment offset of wolf-pac with respect to sled")
    parser.add_argument('-b','--rotation', help="map orientation rotation")
    parser.add_argument('-s','--start', help="time in seconds with respect to first data point to start drawing map")
    parser.add_argument('-e','--elapsed', help="time window in seconds for the map")
    parser.add_argument('-yd','--yaw_drift', help="yaw gyro drift, deg/min")
    parser.add_argument('-pd','--pitch_drift', help="pitch gyro drift, deg/min")
    parser.add_argument('-rd','--roll_drift', help="roll gyro drift, deg/min")
    parser.add_argument('-pz','--pitch_at_zero', help="actual pitch of the sled at the first data point, degrees")
    parser.add_argument('-rz','--roll_at_zero', help="actual roll of the sled at the first data point, degrees")
    
    
    args = parser.parse_args()
    file_base_name = args.filename

    if args.yaw_offset :
        yaw_offset = float(args.yaw_offset)
    if args.pitch_offset :
        pitch_offset = float(args.pitch_offset)
    if args.roll_offset :
        roll_offset = float(args.roll_offset)
    if args.rotation :
        rotation = float(args.rotation)
    if args.start :
        start = float(args.start)
    if args.elapsed :
        elapsed = float(args.elapsed)
    if args.yaw_drift :
        yaw_drift = float(args.yaw_drift)
    if args.pitch_drift :
        pitch_drift = float(args.pitch_drift)
    if args.roll_drift :
        roll_drift = float(args.roll_drift)
    if args.pitch_at_zero :
        pitch_zero = float(args.pitch_at_zero)
    if args.roll_at_zero :
        roll_zero = float(args.roll_at_zero)         
        
    input_file = open(file_base_name+".txt")
    output_file = open(file_base_name+"_adjusted.txt", "w")
    map_file = open(file_base_name+"_map.csv", "w")
    compare_file = open(file_base_name+"_compare.csv", "w")
    log_file = open(file_base_name+"_log.txt" , "w")
        
    read_data(input_file)

