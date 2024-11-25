global acc_z_gain , gravity_value , z_x_ccc
acc_z_gain = 1.0
gravity_value = 32.174
z_x_cc = 0.0

global minimum_speed

global jostle_window, corner_variance 
jostle_window = 30
corner_variance = 0.5

minimum_speed = 20.0
skip_lines = 100

global max_err
max_err = 20

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

global line_numbers , gxs, gys, gzs, yaws, pitches, rolls
line_numbers = []
gxs = []
gys = []
gzs = []
yaws = []
pitches = []
rolls = []


global line_nums
line_nums = []
global weights
weights = []
global wx_list , wy_list , wz_list , fx_list, fy_list , fz_list
wx_list = []
wy_list = []
wz_list = []
fx_list = []
fy_list = []
fz_list = []
global wx_filt , wy_filt , wz_filt , fx_filt, fy_filt , fz_filt
wx_filt = []
wy_filt = []
wz_filt = []
fx_filt = []
fy_filt = []
fz_filt = []
global gx_list , gy_list , gz_list
gx_list = []
gy_list = []
gz_list = []
global heading_list , pitch_list
heading_list = []
pitch_list = []
global errors_in, errors_out
errors_in = []
errors_out = []

global filter_size
filter_size = 8
#note : width of the window is 2*filter_size + 1


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
global x , y , distance , x_ef, y_ef
x = 0
y = 0
distance = 0
x_ef = 0
y_ef = 0

global velocity , velocity_dot , omega , s_force , g_force , velocity_x
velocity = np.zeros((3,1))
velocity_x = np.zeros((3,1))
velocity_dot = np.zeros((3,1))
omega = np.zeros((3,1))
s_force = np.zeros((3,1))
g_force = np.zeros((3,1))

def indices (size) :
    table = []
    tab_index = 0
    offset = - size
    num_offsets = int(1+2*size)
    while tab_index < num_offsets :
        table.append(offset)
        offset = offset + 1
        tab_index = tab_index + 1
    return table

def windowed_variance(input_list,mean,index_table) :
    variance_table = []
    line = 0
    for dummy in input_list :
        N = 0
        total = 0
        for index in index_table :
            try :
                total = total + (input_list[line+index]-mean)**2
                N = N + 1
            except :
                pass
        if N > 0 :
            variance_table.append(total/N)
        else :
            variance_table.append(0)
        line = line + 1
    return variance_table

def mav_filter(raw_list,filtered_list,index_table) :
    line = 0
    for dummy in raw_list :
        N = 0
        total = 0
        for index in index_table :
            try :
                total = total + raw_list[line+index]
                N = N + 1
            except :
                pass
        if N > 0 :
            filtered_list.append(total/N)
        else :
            filtered_list.append(0)
        line = line + 1
    
def cross_t(a,b) :
    return np.transpose(np.cross(np.transpose(a),np.transpose(b)))

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

#corner_w is the pitch rate in radians per second at which the kalman gain is 0.5
global corner_w
corner_w = 1.4
#feedback_gain is the multiplier in the feedback loop
global feedback_gain
feedback_gain = 1.0

def k_gain(w,v,f):
    return w*w/(w*w+corner_w*corner_w)

def k_error(w,v,f,gain) :   
    return((-f/w)-v)*gain

def read_data(file):
    global line_numbers , gxs, gys, gzs, yaws, pitches, rolls
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
    global velocity , velocity_dot , omega , s_force , g_force , velocity_x
    global x_ef, y_ef
    global x , y , distance
    global yaw_drift , pitch_drift , roll_drift
    global yaw_offset , pitch_offset , roll_offset
    global gx , gy , gz
    global acc_z_gain , gravity_value
    global drift_mat
    global matrix_adjusted
    global matrix_update
    global pitch_zero , roll_zero
    global pitch_start , pitch_end , roll_start , roll_end
    global args
    global wx_list , wy_list , wz_list , fx_list, fy_list , fz_list
    global wx_filt , wy_filt , wz_filt , fx_filt, fy_filt , fz_filt
    global gx_list , gy_list , gz_list
    global heading_list , pitch_list
    global line_nums
    global errors_in, errors_out
    global max_err
    global weights
    global jostle_window , corner_variance , corner_w
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

    pitch_gravity = 0
    roll_gravity = 0

    dataStr = file.read()
        
    lines = dataStr.splitlines(keepends=False)
    first_line = 1
    line_number = 0 
    if dataStr:
        for line in lines:
            columns = line.split(',')
            if len(columns) == NUM_COLS :
                try:
                    if line_number < int(100*start):
                        gravity[0,0] = - float(columns[XA_COL])
                        gravity[1,0] = - float(columns[YA_COL])
                        gravity[2,0] = - float(columns[ZA_COL])
                        yaw_in = float(columns[YAW_COL])
                        pitch_in = float(columns[PITCH_COL])
                        roll_in = float(columns[ROLL_COL])
                        line_numbers.append(line_number)
                        gxs.append(gravity[0,0])
                        gys.append(gravity[1,0])
                        gzs.append(gravity[2,0])
                        yaws.append(yaw_in)
                        pitches.append(pitch_in)
                        rolls.append(roll_in)
                        line_number = line_number+1              
                except ValueError:
                    pass    
            else:
                pass  
    N = 0
    gx_sum = 0
    gy_sum = 0
    gx_sqr_sum = 0
    gy_sqr_sum = 0

    for line_number in line_numbers :
        if line_number < int(100*start) :
            gx_sum = gx_sum + gxs[line_number]
            gy_sum = gy_sum + gys[line_number]
            gx_sqr_sum = gx_sqr_sum + gxs[line_number]**2
            gy_sqr_sum = gy_sqr_sum + gys[line_number]**2
            N = N + 1
    if N > 10 :
        gx_bar = gx_sum/N
        gy_bar = gy_sum/N
        gx_sqr_bar = gx_sqr_sum/N
        gy_sqr_bar = gy_sqr_sum/N
        gx_var = gx_sqr_bar - gx_bar**2
        gy_var = gy_sqr_bar - gy_bar**2
        

    variance_indices = indices(jostle_window)
    gx_variance = windowed_variance(gxs,gx_bar,variance_indices)
    gy_variance = windowed_variance(gys,gy_bar,variance_indices)
    gx_gy_variance = gx_variance + gy_variance

    variance_file.write(f"gx,gxwvar,gy,gywvar,total_var,weight,") 
    variance_file.write(f"gx_bar ={round(gx_bar,2)},")
    variance_file.write(f"gy_bar ={round(gy_bar,2)},")
    variance_file.write(f"gx_var ={round(gx_var,2)},")
    variance_file.write(f"gy_var ={round(gy_var,2)},")
    
    
    for line_number in line_numbers :
        total_variance = gx_gy_variance[line_number]
        if args.no_weights :
            weight = 1.0
        else :
            weight = corner_variance / (corner_variance + total_variance)
        weights.append(weight)
        variance_file.write(f"{round(gxs[line_number],2)},")
        variance_file.write(f"{round(gx_variance[line_number],2)},")
        variance_file.write(f"{round(gys[line_number],2)},")
        variance_file.write(f"{round(gy_variance[line_number],2)},")   
        variance_file.write(f"{round(gx_gy_variance[line_number],2)},{round(weight,2)}\r")
        
    N = 0
    weight_sum = 0
    lines = dataStr.splitlines(keepends=False)
    first_line = 1
    line_number = 0
    gravity_sum = np.zeros((3,1))
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
                    if  line_number < int(100*start):
                        pitch_gravity = round(degrees(atan2(-gravity[0,0] , sqrt((gravity[1,0])**2+(gravity[2,0])**2))),2)
                        roll_gravity = round(degrees(atan2(gravity[1,0],gravity[2,0])),2)
                        #debug_file.write(f"{pitch_in},{pitch_gravity},{roll_in},{roll_gravity}\r")
                        weight = weights[line_number]
                        weight_sum = weight_sum + weight
                        N = N + 1
                        gravity_sum = gravity_sum + weight*gravity
                        g_sqr_sum = g_sqr_sum + np.vdot(gravity,gravity)*weight
                        xTx[0,0] = N*N
                        xTx[1,1] = 1.0
                        xTx[0,1] = N
                        xTx[1,0] = N
                        xTx_sum = xTx_sum + weight*xTx
                        x_yaw[0,0] = x_yaw[0,0] + N*yaw_in*weight
                        x_yaw[1,0] = x_yaw[1,0] + yaw_in*weight
                        x_pitch[0,0] = x_pitch[0,0] + N*(pitch_in-pitch_gravity)*weight
                        x_pitch[1,0] = x_pitch[1,0] + (pitch_in-pitch_gravity)*weight
                        x_roll[0,0] = x_roll[0,0] + N*(roll_in-roll_gravity)*weight
                        x_roll[1,0] = x_roll[1,0] + (roll_in-roll_gravity)*weight
                        yaw_sqr_sum = yaw_sqr_sum + (yaw_in**2)*weight
                        pitch_sqr_sum = pitch_sqr_sum + ((pitch_in-pitch_gravity)**2)*weight
                        roll_sqr_sum = roll_sqr_sum + ((roll_in-roll_gravity)**2)*weight
                        
                    line_number = line_number + 1
                
                except ValueError:
                    pass    
            else:
                pass                             

        g_bar = gravity_sum/weight_sum
        g_bar_sqr = np.vdot(g_bar,g_bar)
        g_sqr_bar = g_sqr_sum/weight_sum
        g_var = g_sqr_bar - g_bar_sqr
        if g_var > 0 :
            g_std = sqrt(g_var)
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
            
            print("beta yaw = " , beta_yaw , " standard deviation yaw = " , round(sqrt(yaw_var/weight_sum),2) , "drift = " , round(6000.0*beta_yaw[0,0],2) )
            print("beta pitch = " , beta_pitch , " standard deviation pitch = " , round(sqrt(pitch_var/weight_sum),2), "drift = " , round(6000.0*beta_pitch[0,0],2) )
            print("beta roll = " , beta_roll , " standard deviation roll = " , round(sqrt(roll_var/weight_sum),2), "drift = " , round(6000.0*beta_roll[0,0],2) )

            log_file.write(f"statistical processing tuning parameters:\r")
            log_file.write(f"\rjostle detection weighting parameters, window size = {2*jostle_window+1} samples , corner variance = { corner_variance } ft/sec/sec squared.\r")
            log_file.write(f"\rspeed estimation kalman filter corner rotation rate = {corner_w} radians per second .\r\r")
      
            log_file.write(f"gyro drift analysis:\r\r")
            log_file.write(f"yaw: slope and offset = {beta_yaw} , stdev = {round(sqrt(yaw_var/weight_sum),2)} degrees , drift = {round(6000.0*beta_yaw[0,0],2)} deg/min\r\r")
            log_file.write(f"pitch: slope and offset = {beta_pitch} , stdev = {round(sqrt(pitch_var/weight_sum),2)} degrees , drift = {round(6000.0*beta_pitch[0,0],2)} deg/min\r\r")
            log_file.write(f"roll: slope and offset = {beta_roll} , stdev = {round(sqrt(roll_var/weight_sum),2)} degrees , drift = {round(6000.0*beta_roll[0,0],2)} deg/min\r\r")
            log_file.write(f"note: standard deviations refer to how well the data fits a straight line.\r\r")
            log_file.write(f"g_bar = {g_bar}\r")
            log_file.write(f"g_bar_sqr = { g_bar_sqr }\r")
            log_file.write(f"g_sqr_bar = { g_sqr_bar }\r")
            log_file.write(f"g_var = { g_sqr_bar - g_bar_sqr}\r")
        else:
            log_file.write("gyro drift not analyzed, not enough data.\r\r")
        
        gx = gravity_sum[0,0]
        gy = gravity_sum[1,0]
        gz = gravity_sum[2,0]

        
        log_file.write("\ranalysis of specific force data:\r\r")
        log_file.write(f"x, y and z weighted average force vector = {round(gravity_sum[0,0]/weight_sum,2)} , {round(gravity_sum[1,0]/weight_sum,2)} , {round(gravity_sum[2,0]/weight_sum,2)} feet per second per second.\r")
        log_file.write(f"square root of the sum of the squares of x, y and z standard deviations = {round(g_std,2)} feet per second per second.\r")

        log_file.write(f"\r>>>>> note: this version of map.py is using statistical weighting of the data points to reduce the standard deviation of the estimate of the parameters. <<<<<<\r\r")
        log_file.write(f"There were {N} data points used, with a sum of weights equal to {round(weight_sum,2)}\r\r")
        
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
    log_file.write(f"\r\rkalman gain = {corner_w}\r")

    output_file.write("reprocessed file to account for gyro drift and misalignments.\r\r")
    output_file.write("yaw alignment offset of wolf-pac mounting = "+str(yaw_offset)+" degrees.\r")
    output_file.write("pitch alignment offset of wolf-pac mounting = "+str(pitch_offset)+" degrees.\r")
    output_file.write("roll alignment offset of wolf-pac mounting = "+str(roll_offset)+" degrees.\r" )

    output_file.write("pitch alignment offset of sled with respect to level at first line = "+str(pitch_zero)+" degrees.\r")
    output_file.write("roll alignment offset of sled with respect to level at first line = "+str(roll_zero)+" degrees.\r" )
    
    output_file.write("yaw gyro bias  = "+str(yaw_drift)+" degrees per minute.\r")
    output_file.write("pitch gyro bias  = "+str(pitch_drift)+" degrees per minute.\r")
    output_file.write("roll gyro bias  = "+str(roll_drift)+" degrees per minute.\r\r")
      
    if args.centrifuge_testing :
        create_ypr_matrix(yaw_offset, pitch_offset , roll_offset)
        first_mat = ypr_mat
        create_ypr_matrix(0.0, 0.0 , 0.0)
        ypr_o_mat = ypr_mat
        ypr_o_mat_transpose = ypr_mat
        print("centrifuge testing.")
    else :
        create_ypr_matrix(yaw_offset, pitch_offset , roll_offset)      
        ypr_o_mat = ypr_mat
        ypr_o_mat_transpose = np.transpose(ypr_o_mat)
        create_ypr_matrix(0.0, pitch_zero , roll_zero)
        first_mat = ypr_mat
              
    print("offset matrix")
    print(ypr_o_mat)
    create_ypr_matrix(-yaw_drift/6000.0, -pitch_drift/6000.0, -roll_drift/6000.0)    
    drift_mat = ypr_mat
    print("drift matrix")
    print (drift_mat)
    print("first record orientation matrix")
    print(first_mat)
    
    compare_file.write("x_force_in , x_force_out , y_force_in, y_force_out , z_force_in , z_force_out , yaw_in , yaw_out , pitch_in , pitch_out, roll_in , roll_out\r")
     
    first_line = 1
    line_number = 0 

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

                    line_nums.append(line_number)

                    line_number = line_number + 1

                    if line_number > skip_lines :
                    
                        create_ypr_matrix(yaw_in,pitch_in,roll_in)
                        matrix_in = ypr_mat
                        if first_line == 1 or line_number == int(100*start) :
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

                            omega[0,0] = radians(gyro_wp[0,0])
                            omega[1,0] = radians(gyro_wp[1,0])
                            omega[2,0] = radians(gyro_wp[2,0])

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
                    else :
                        xa_out = xa_in
                        ya_out = ya_in
                        za_out = za_in
                        heading = yaw_in
                        pitch_out = pitch_in
                        roll_out = roll_in
                    
                    output_file.write(str(xa_out)+","+str(ya_out)+","+str(za_out)+",")
                    output_file.write(str(round(heading,2))+","+str(pitch_out)+","+str(roll_out)+",")
                    output_file.write(columns[6]+","+columns[7]+","+columns[8]+","+columns[9]+","+columns[10]+"\r")
                    
                    compare_file.write(f"{xa_in},{xa_out},{ya_in},{ya_out},{za_in},{za_out},{yaw_in},{round(heading,2)},{pitch_in},{pitch_out},{roll_in},{roll_out}\r")
                    wx_list.append(omega[0,0])
                    wy_list.append(omega[1,0])
                    wz_list.append(omega[2,0])
                    
                    fx_list.append(force_out[0,0])
                    fy_list.append(force_out[1,0])
                    fz_list.append(force_out[2,0])
                    
                    g_force[0,0]=gravity_value*matrix_adjusted[2,0]
                    g_force[1,0]=gravity_value*matrix_adjusted[2,1]
                    g_force[2,0]=gravity_value*matrix_adjusted[2,2]

                    gx_list.append(g_force[0,0])
                    gy_list.append(g_force[1,0])
                    gz_list.append(g_force[2,0])

                    heading_list.append(heading)
                    pitch_list.append(pitch_out)
                    
                                                              
                except ValueError:
                    output_file.write(line+"\r")
                    pass    
            else:
                output_file.write(line+"\r")                             
                                                                              
    return None


if __name__ == "__main__":
    global args
    parser = argparse.ArgumentParser(
        prog='map.py',
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
    parser.add_argument('-ct','--centrifuge_testing',action = 'store_true',help="centrifuge testing option")
    parser.add_argument('-nk','--no_kalman',action = 'store_true',help="turn off kalman filter")
    parser.add_argument('-kg','--kalman_gain', help="kalman corner gain, default is 1.4")
    parser.add_argument('-nw','--no_weights', action = 'store_true', help="no weights : option to use equal weighting to estimate alignment and drift")
    
    
    
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
    if args.no_kalman :
        max_err = 100.0
    if args.kalman_gain :
        corner_w = float(args.kalman_gain)
        
    input_file = open(file_base_name+".txt")
    output_file = open(file_base_name+"_adjusted.txt", "w")
    map_file = open(file_base_name+"_map.csv", "w")
    compare_file = open(file_base_name+"_compare.csv", "w")
    if args.no_weights :
        log_file = open(file_base_name+"_log_no_weights.txt" , "w")
    else :
        log_file = open(file_base_name+"_log.txt" , "w")
    debug_file = open(file_base_name+"_debug.csv" , "w")
    variance_file = open(file_base_name+"_variance.csv" , "w") 
        
    read_data(input_file)

    mav_filter(fx_list,fx_filt,indices(filter_size))
    mav_filter(fy_list,fy_filt,indices(filter_size))
    mav_filter(fz_list,fz_filt,indices(filter_size))
    mav_filter(wx_list,wx_filt,indices(filter_size))
    mav_filter(wy_list,wy_filt,indices(filter_size))
    mav_filter(wz_list,wz_filt,indices(filter_size))
    
    debug_file.write(f"line,fx_raw,fx_filt,fy_raw,fy_filt,fz_raw,fz_filt,wx_raw,wx_filt,wy_raw,wy_filt,wz_raw,wz_filt,")
    debug_file.write(f"gx,gy,gz,heading,pitch\r")

    end = start + elapsed

    error_sum = 0
    acc_sum = 0
  
    for line_number in line_nums :
        debug_file.write(f"{line_number},")
        debug_file.write(f"{round(fx_list[line_number],2)},{round(fx_filt[line_number],2)},")
        debug_file.write(f"{round(fy_list[line_number],2)},{round(fy_filt[line_number],2)},")
        debug_file.write(f"{round(fz_list[line_number],2)},{round(fz_filt[line_number],2)},")
        debug_file.write(f"{round(wx_list[line_number],2)},{round(wx_filt[line_number],2)},")
        debug_file.write(f"{round(wy_list[line_number],2)},{round(wy_filt[line_number],2)},")
        debug_file.write(f"{round(wz_list[line_number],2)},{round(wz_filt[line_number],2)},")
        debug_file.write(f"{round(gx_list[line_number],2)},")
        debug_file.write(f"{round(gy_list[line_number],2)},")
        debug_file.write(f"{round(gz_list[line_number],2)},")
        debug_file.write(f"{round(heading_list[line_number],2)},")
        debug_file.write(f"{round(pitch_list[line_number],2)}\r")
        if int(100*start) <= line_number <= int(100*end) :
            heading = heading_list[line_number]
            pitch_out = pitch_list[line_number]
            g_force[0,0]=gx_list[line_number]
            g_force[1,0]=gy_list[line_number]
            g_force[2,0]=gz_list[line_number]
            force_out[0,0]=fx_filt[line_number]
            force_out[1,0]=fy_filt[line_number]
            force_out[2,0]=fz_filt[line_number]
            omega[0,0]=wx_filt[line_number]
            omega[1,0]=wy_filt[line_number]
            omega[2,0]=wz_filt[line_number]                                  
            
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
            distance = distance + (speed/100)              

            x_ef = x_ef + velocity[0,0]*(cosine/100.0)
            y_ef = y_ef + velocity[0,0]*(sine/100.0)

            velocity_dot = g_force + force_out

            correction_gain = k_gain(omega[1,0],velocity[0,0],velocity_dot[2,0])
            v_error = k_error(omega[1,0],velocity[0,0],velocity_dot[2,0],correction_gain)

            if v_error > max_err :
                v_error = max_err
            if v_error < -max_err :
                v_error = -max_err

            
            velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0] + feedback_gain*v_error + z_x_cc*velocity_dot[2,0] )/100.0

            error_sum = error_sum + v_error
            acc_sum = acc_sum + velocity_dot[2,0]

    z_x_cc = error_sum/acc_sum
    log_file.write(f"z to x residual specific cross coupling = {round(z_x_cc,4)}\r")

    first_heading_recorded = 0
    speed = 0
    distance = 0
    x=0
    y=0
    x_ef=0
    y_ef=0
    velocity = np.zeros((3,1))
    new_distance = 0
    v_error = 0
            
    for line_number in line_nums :
        
        if int(100*start) <= line_number <= int(100*end) :
            heading = heading_list[line_number]
            pitch_out = pitch_list[line_number]
            g_force[0,0]=gx_list[line_number]
            g_force[1,0]=gy_list[line_number]
            g_force[2,0]=gz_list[line_number]
            force_out[0,0]=fx_filt[line_number]
            force_out[1,0]=fy_filt[line_number]
            force_out[2,0]=fz_filt[line_number]
            omega[0,0]=wx_filt[line_number]
            omega[1,0]=wy_filt[line_number]
            omega[2,0]=wz_filt[line_number]                                  
            
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
            distance = distance + (speed/100)              

            x_ef = x_ef + velocity[0,0]*(cosine/100.0)
            y_ef = y_ef + velocity[0,0]*(sine/100.0)

            velocity_dot = g_force + force_out

            correction_gain = k_gain(omega[1,0],velocity[0,0],velocity_dot[2,0])
            v_error = k_error(omega[1,0],velocity[0,0],velocity_dot[2,0],correction_gain)


            if v_error > max_err :
                v_error = max_err
            if v_error < -max_err :
                v_error = -max_err

            if args.no_kalman :
                velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0] + z_x_cc*velocity_dot[2,0] )/100.0
            else:
                velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0] + feedback_gain*v_error + z_x_cc*velocity_dot[2,0] )/100.0

            new_distance = new_distance + velocity[0,0]/100.0

        errors_in.append(v_error)                                                        

    mav_filter(errors_in,errors_out,indices(20))

    first_heading_recorded = 0
    speed = 0
    distance = 0
    x=0
    y=0
    x_ef=0
    y_ef=0
    velocity = np.zeros((3,1))
    new_distance = 0

    map_file.write("roll_rate,pitch_rate,yaw_rate,x_spec_frc,y_spec_frc,z_spec_frc,gravity_x,gravity_y,gravity_z,")
    map_file.write("total_force_x,total_force_y,total_force_z,correction_gain,error,omega*velocity,filtered_error,velocity,distance,map_x,map_y\r")
   

    for line_number in line_nums :
        
        if int(100*start) <= line_number <= int(100*end) :
            heading = heading_list[line_number]
            pitch_out = pitch_list[line_number]
            g_force[0,0]=gx_list[line_number]
            g_force[1,0]=gy_list[line_number]
            g_force[2,0]=gz_list[line_number]
            force_out[0,0]=fx_filt[line_number]
            force_out[1,0]=fy_filt[line_number]
            force_out[2,0]=fz_filt[line_number]
            omega[0,0]=wx_filt[line_number]
            omega[1,0]=wy_filt[line_number]
            omega[2,0]=wz_filt[line_number]                                  
            
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
            distance = distance + (speed/100)              

            x_ef = x_ef + velocity[0,0]*(cosine/100.0)
            y_ef = y_ef + velocity[0,0]*(sine/100.0)

            velocity_dot = g_force + force_out

            correction_gain = k_gain(omega[1,0],velocity[0,0],velocity_dot[2,0])
            v_error = k_error(omega[1,0],velocity[0,0],velocity_dot[2,0],correction_gain)

            if v_error > max_err :
                v_error = max_err
            if v_error < -max_err :
                v_error = -max_err

            if args.no_kalman :
                velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0]  + z_x_cc*velocity_dot[2,0] )/100.0
            else:
                velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0] + feedback_gain*v_error + z_x_cc*velocity_dot[2,0] )/100.0

            
            new_distance = new_distance + velocity[0,0]/100.0

            wv = round(velocity_dot[0,0]*omega[1,0],2)
                       
                                 
            map_file.write(f"{round(degrees(omega[0,0]),2)},{round(degrees(omega[1,0]),2)},{round(degrees(omega[2,0]),2)},")
            map_file.write(f"{round(force_out[0,0],2)},{round(force_out[1,0],2)},{round(force_out[2,0],2)},")
            map_file.write(f"{round(g_force[0,0],2)},{round(g_force[1,0],2)},{round(g_force[2,0],2)},")
            map_file.write(f"{round(velocity_dot[0,0],2)},{round(velocity_dot[1,0],2)},{round(velocity_dot[2,0],2)},")
            map_file.write(f"{round(correction_gain,2)},{round(v_error,2)},{wv},{round(errors_out[line_number],2)},{round(velocity[0,0],2)},{round(new_distance,2)},")
            map_file.write(f"{round(x_ef,2)},{round(y_ef,2)}\r")

    
            
    
    
        

    

    
    

