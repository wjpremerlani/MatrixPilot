import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime
import argparse
import io


global skip_pass_7_and_8
skip_pass_7_and_8 = True

############################################
#
# the following are the thresholds for detecting problems with computing alignment and drift
# feel free to change them
#
global gyro_stdev_max , gyro_drift_max, force_stdev_max, weights_min , MINIMUM_VALID_SAMPLES
gyro_stdev_max = 3.0
gyro_drift_max = 3.0
force_stdev_max = 3.0
weights_min = 1000
MINIMUM_VALID_SAMPLES = 30
#
#thresholds for detetecting plotlets
#in order to provide hysteris, start must be significantly larger than end
global start_threshold , end_threshold , yaw_rate_start , yaw_rate_end
global roll_ratio , roll_max , peak_threshold , minimum_curve , curve_timer , yaw_threshold
start_threshold = 15.0 # roll angle to detect the start of a curve
peak_threshold = 20.0 # roll angle to confirm a curve
#yaw_threshold = 15.0 # minimum change in heading to start checking for the curve end
yaw_threshold = 7.5
roll_ratio = 0.1 # value of roll/roll_max needed to detect end of curve
yaw_rate_start = 10.0
yaw_rate_end = 3.0
#
#
#
global z_force_plot_limit
# z_force_plot_limit is used to clip the reported z force
# the purpose is to make it easier to examine z force
# in the straighaways during development of gaplet analysis
#
z_force_plot_limit = - 600.0
#
#
# don't edit anything below this line.
###########################################

curve_timer = 0

roll_max = start_threshold

global alignment_accel
alignment_accel = 0

global roll_edge_filter_size , roll_threshold , start_distance
roll_edge_filter_size = 16
roll_threshold = 3.0
start_distance = 50.0

global previous_distance
previous_distance = 0

global gyro_stdev , gyro_drift, force_stdev, weight_sum
gyro_stdev = 0.0
gyro_drift = 0.0
force_stdev = 0.0
weight_sum = 0.0

global acc_z_gain , gravity_value , z_x_cc
acc_z_gain = 1.0
gravity_value = 32.174
z_x_cc = 0.0

global minimum_speed

global jostle_window, corner_variance
jostle_window = 30
corner_variance = 0.5

minimum_speed = 20.0
skip_lines = 0

global max_err
max_err = 30



global current_date , current_time , current_date_time
current_date_time = datetime.now()
current_time = current_date_time.time()
current_date = current_date_time.date()


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

# output_data = []

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
global gx_list , gy_list , gz_list
gx_list = []
gy_list = []
gz_list = []
global heading_list , pitch_list , roll_list , heading_filt , pitch_filt , roll_filt , heading_hf , pitch_hf , roll_hf
heading_list = []
pitch_list = []
roll_list = []
global errors_in, errors_out , acceleration
errors_in = []
errors_out = []
acceleration = []

global omega_e , omegas_e_x, omegas_e_y , omegas_e_z , omegas_e_f_x , omegas_e_f_y , omegas_e_f_z
omega_e = np.zeros((3,1))
omegas_e_x = []
omegas_e_y = []
omegas_e_z = []
omegas_e_f_x = []
omegas_e_f_y = []
omegas_e_f_z = []

global roll_edges ,yaw_rate_edges


global filter_size
filter_size = 20
#filter_size = 40
#note: width of the window is 2*filter_size + 1


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

def pad_14(instring):
    outstring = instring
    lenstring = len(instring)
    if lenstring < 14:
        pads = int(14-lenstring)
        for index in range(pads):
            outstring = " "+outstring
    return outstring


def round_and_pad(adjustment):
    adj_string = str(round(adjustment,2))
    return pad_14(adj_string)

def summary_log_write_adjustements(po,ro,pd,rd):
    global start
    summary_log_file.write(f"{round_and_pad(start)},")
    summary_log_file.write(f"{round_and_pad(po)},")
    summary_log_file.write(f"{round_and_pad(ro)},")
    summary_log_file.write(f"{round_and_pad(pd)},")
    summary_log_file.write(f"{round_and_pad(rd)}\n")

def saturate(input_value,size):
    if abs(input_value) <= size:
        return input_value
    else:
        return size*np.sign(input_value)

def threshold(input_value,level):
    if abs(input_value) >= level:
        return 1.0*np.sign(-input_value)
    else:
        return 0.0

def indices (size):
    table = []
    tab_index = 0
    offset = - size
    num_offsets = int(1+2*size)
    while tab_index < num_offsets:
        table.append(offset)
        offset = offset + 1
        tab_index = tab_index + 1
    return table

def windowed_variance(input_list,mean,index_table):
    variance_table = []
    line = 0
    for dummy in input_list:
        N = 0
        total = 0
        for index in index_table:
            try:
                total = total + (input_list[line+index]-mean)**2
                N = N + 1
            except:
                pass
        if N > 0:
            variance_table.append(total/N)
        else:
            variance_table.append(0)
        line = line + 1
    return variance_table

def edge_filter(input_list,index_table):
    edges = []
    line = 0
    for dummy in input_list:
        N = 0
        total = 0
        for index in index_table:
            N = N + 1
            try:
                if index > 0:
                    total = total + input_list[line+index]
                if index < 0:
                    total = total - input_list[line-index]
            except:
                pass
        if N > 0:
            edges.append(total/N)
        else:
            edges.append(0)
        line = line + 1
    return edges

def mav(data_list,where,index_table):
    N = 0
    total = 0
    for index in index_table:
        try:
            total = total + data_list[where+index]
            N = N + 1
        except:
            pass
        if N > 0:
            return (total/N)
        else:
            return 0

def mav_filter(raw_list,index_table):
    filter_table = []
    line = 0
    for dummy in raw_list:
        N = 0
        total = 0
        for index in index_table:
            try:
                total = total + raw_list[line+index]
                N = N + 1
            except:
                pass
        if N > 0:
            filter_table.append(total/N)
        else:
            filter_table.append(0)
        line = line + 1
    return filter_table

def cross_t(a,b):
    return np.transpose(np.cross(np.transpose(a),np.transpose(b)))

def create_yaw_matrix(angle):
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

def create_pitch_matrix(angle):
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


def create_roll_matrix(angle):
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

def create_ypr_matrix(yaw,pitch,roll):
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

def k_error(w,v,f,gain):
    return((-f/w)-v)*gain

global tr_mdl_num , tr_mdl_state ,tr_mdl_distance ,tr_mdl_time,tr_mdl_speed
tr_mdl_num = []
tr_mdl_state = []
tr_mdl_distance = []
tr_mdl_time = []
tr_mdl_speed = []
tr_mdl_adjust = []

global run_end_distance , run_end_time , table_end_distance , table_end_time
run_end_distance = 0
run_end_time = 0
table_end_distance = 100000
table_end_time = 0

global run_time
run_time = 0

def write_new_mark():
    global run_time
    run_time = int (line_number - line_origin )
    try:
        marks_file.write(f"{mark_number},")
        marks_file.write(f"{mark_state},")
        marks_file.write(f"{round((new_distance-distance_origin),2)},")
        marks_file.write(f"{round(float(line_number-line_origin),2)},")
        marks_file.write(f"{round(velocity[0,0],2)}\r")
    except:
        pass

global number_of_marks , heading_start

def two_phase_roll_update_timing_marks(write_requests, roll_rate , roll_out , heading ):
    global mark_state, mark_number, new_distance , distance_origin , line_origin , velocity , line_number , yaw_rate_start , yaw_rate_end , number_of_marks
    global roll_max , roll_ratio , peak_threshold , end_threshold
    global minimum_curve , curve_timer , heading_start , yaw_threshold
    if ( args.curves ):
        if mark_number == number_of_marks:
            return
    if mark_state == 0:
        if abs(roll_out) > start_threshold:
            heading_start = heading
            mark_state = np.sign(roll_out)
            if ( write_requests ==1 ):
                write_new_mark()
            if ( write_requests == 2 ):
                write_both_marks ()
            mark_number = mark_number + 1
            roll_max = start_threshold
    else:
        roll_max = max(abs(roll_out),roll_max)
        if (abs(roll_out) < roll_ratio*roll_max ):
            roll_flag = 10.2
        else:
            roll_flag = -.1

        if ( np.sign(roll_out) != np.sign(roll_rate)):
            roll_sign_flag = 10.2
        else:
            roll_sign_flag = -.1

        if ( roll_max > peak_threshold ):
            roll_max_flag = 10.2
        else:
            roll_max_flag = -.1

        if (abs(heading - heading_start) > yaw_threshold ):
            yaw_flag = 10.2
        else:
            yaw_flag = -.1
        try:
            debug_marks_file.write(f"{mark_number},{roll_flag},{roll_sign_flag},{roll_max_flag},{yaw_flag},,{round(roll_out,2)},{round(heading,2)}\n")
        except:
            pass

        if (abs(roll_out) < roll_ratio*roll_max ) and ( np.sign(roll_out) != np.sign(roll_rate)) and ( roll_max > peak_threshold ) and (abs(heading - heading_start) > yaw_threshold ):
            mark_state = 0
            if ( write_requests ==1 ):
                write_new_mark()
            if ( write_requests == 2 ):
                write_both_marks ()
            mark_number = mark_number+1
            roll_max = start_threshold

def update_timing_mark(yaw_rate,roll_rate,roll_out,heading):
    global mark_state, mark_number, new_distance , distance_origin , line_origin , velocity , line_number , yaw_rate_start , yaw_rate_end , number_of_marks
    if ( args.curves ):
        if mark_number == number_of_marks:
            return
    if args.yrs == True:
        signal = degrees(yaw_rate)
        start = yaw_rate_start
        end = yaw_rate_end

        if mark_state == 0:
            if abs(signal) > start:
                mark_state = np.sign(signal)
                mark_number = mark_number + 1
        else:
            if abs(signal) < end:
                mark_state = 0
                mark_number = mark_number + 1
    else:
        two_phase_roll_update_timing_marks(0,roll_rate,roll_out,heading)

def update_mark_state_no_tr_mdl(yaw_rate,roll_rate,roll_out,heading):
    global mark_state, mark_number, new_distance , distance_origin , line_origin , velocity , line_number , yaw_rate_start , yaw_rate_end , number_of_marks
    if ( args.curves ):
        if mark_number == number_of_marks:
            return
    if args.yrs == True:
        signal = degrees(yaw_rate)
        start = yaw_rate_start
        end = yaw_rate_end

        if mark_state == 0:
            if abs(signal) > start:
                mark_state = np.sign(signal)
                write_new_mark()
                mark_number = mark_number + 1
        else:
            if abs(signal) < end:
                mark_state = 0
                write_new_mark()
                mark_number = mark_number + 1
    else:
        two_phase_roll_update_timing_marks(1,roll_rate,roll_out,heading)

def write_both_marks ():
    global run_end_distance , run_end_time , table_end_distance , table_end_time
    global mark_state, mark_number, new_distance , distance_origin , line_origin , velocity , line_number 

    if mark_number < len (tr_mdl_num):
        table_index = mark_number
    else:
        table_index = len (tr_mdl_num ) - 1

    run_end_distance = round((new_distance-distance_origin),2)
    table_end_distance = tr_mdl_distance[table_index]
    run_end_time = (line_number-line_origin)
    table_end_time = tr_mdl_time[table_index]

    try:

        marks_file.write(f"{mark_number},")
        marks_file.write(f"{tr_mdl_num[table_index]},")

        marks_file.write(f"{mark_state},")
        marks_file.write(f"{tr_mdl_state[table_index]},")

        marks_file.write(f"{round((new_distance-distance_origin),2)},")
        marks_file.write(f"{tr_mdl_distance[table_index]},")

        marks_file.write(f"{(line_number-line_origin)},")
        marks_file.write(f"{tr_mdl_time[table_index]},")

        marks_file.write(f"{round(velocity[0,0],2)},")
        marks_file.write(f"{tr_mdl_speed[table_index]},")

        marks_file.write(f"\r")

    except:
        pass

def update_mark_state_with_tr_mdl(yaw_rate,roll_rate,roll_out,heading):
    global mark_state, mark_number, new_distance , distance_origin , line_origin , velocity , line_number , previous_line_number , previous_distance  , yaw_rate_start , yaw_rate_end , number_of_marks
    if ( args.curves ):
        if mark_number == number_of_marks:
            return
    if args.yrs == True:
        signal = degrees(yaw_rate)
        start = yaw_rate_start
        end = yaw_rate_end

        if mark_state == 0:
            if abs(signal) > start:
                mark_state = np.sign(signal)
                write_both_marks()
                mark_number = mark_number + 1
        else:
            if abs(signal) < end:
                mark_state = 0
                write_both_marks()
                mark_number = mark_number + 1
    else:
        two_phase_roll_update_timing_marks(2,roll_rate,roll_out,heading)

def read_markers(marker_file):
    marker_data = marker_file.read()
    marker_lines = marker_data.splitlines(keepends=False)
    for marker in marker_lines:
        marker_columns = marker.split(',')
        try:
            tr_mdl_num.append(int(marker_columns[0]))
            tr_mdl_state.append(int(marker_columns[1]))
            tr_mdl_distance.append(float(marker_columns[2]))
            tr_mdl_time.append(float(marker_columns[3]))
            tr_mdl_speed.append(float(marker_columns[4]))
        except ValueError:
            pass
    try:
        log_file.write(f"number,state,distance,time,speed\r")
        for marker_number in tr_mdl_num:
            log_file.write(f"{marker_number},")
            log_file.write(f"{tr_mdl_state[marker_number]},")
            log_file.write(f"{tr_mdl_distance[marker_number]},")
            log_file.write(f"{tr_mdl_time[marker_number]},")
            log_file.write(f"{tr_mdl_speed[marker_number]}\r")
    except:
        pass


global valid_run

def read_data(file):
    global roll_threshold
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
    global x , y , distance , start_distance
    global yaw_drift , pitch_drift , roll_drift
    global yaw_offset , pitch_offset , roll_offset
    global gx , gy , gz
    global acc_z_gain , gravity_value , z_x_cc
    global drift_mat
    global matrix_adjusted
    global matrix_update
    global pitch_zero , roll_zero
    global pitch_start , pitch_end , roll_start , roll_end
    global args
    global wx_list , wy_list , wz_list , fx_list, fy_list , fz_list
    global wx_filt , wy_filt , wz_filt , fx_filt, fy_filt , fz_filt
    global gx_list , gy_list , gz_list
    global heading_list , pitch_list , roll_list , heading_filt , pitch_filt , roll_filt , heading_hf , pitch_hf , roll_hf
    global omega_e , omegas_e_x, omegas_e_y , omegas_e_z , omegas_e_f_x , omegas_e_f_y , omegas_e_f_z
    global line_nums
    global errors_in, errors_out
    global max_err
    global weights
    global jostle_window , corner_variance , corner_w
    global gyro_stdev_max , gyro_drift_max, force_stdev_max, weights_min
    global gyro_stdev , gyro_drift, force_stdev, weight_sum
    global roll_edges ,yaw_rate_edges
    global valid_run
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

    total_valid_samples = 0

    NUM_RES_COLUMNS = 14

    VALID_COLUMN = 1


    dataStr = file.read()

    lines = dataStr.splitlines(keepends=False)
    first_line = 1
    line_number = 0
    if dataStr:
    ##################################################################
    #
    #
    #  compute yaw misalignment
    #
    #
    ################################################################

        A = np.zeros((1,2))
        AT = np.transpose(A)
        ATA = np.matmul(AT,A)
        Y = np.zeros((1,1))
        ATY = np.matmul(AT,Y)

    
        for line in lines :
            columns = line.split(',')
            if len(columns) == NUM_COLS:
                try:
                    roll_angle = float(columns[ROLL_COL])
                    if abs(roll_angle) > 45 :
                        Y[0,0] = float(columns[PITCH_COL])
                        A[0,0] = 1
                        A[0,1] = sin(radians(roll_angle))
                        AT = np.transpose(A)
                        ATA = ATA + np.matmul(AT,A)
                        ATY = ATY + np.matmul(AT,Y)
                except:
                    pass
        ATA_INVERSE = np.linalg.inv(ATA)
        cross = np.matmul(ATA_INVERSE,ATY)
        yaw_offset= - cross[1,0]
        track_pitch = cross[0,0]

        try :
            log_file.write(f"yaw misalignment model\r\n")
            log_file.write(f"ATA={ATA}\r\n")
            log_file.write(f"ATY={ATY}\r\n")
            log_file.write(f"det of ATA = {np.linalg.det(ATA)}\r\n")        
            log_file.write(f"ATA inverse = {ATA_INVERSE}\r\n")       
            log_file.write(f"yaw model = {cross}\r\n")       
            log_file.write(f"yaw_offset = {yaw_offset}\r\n")
            log_file.write(f"average track slope = {track_pitch} degrees.\r\n")
        except :
            pass 
         
        for line in lines:
            columns = line.split(',')
            if len(columns) == NUM_COLS:
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
            if len(columns) == NUM_RES_COLUMNS:
                try:
                    total_valid_samples = total_valid_samples + int (columns[VALID_COLUMN])
                except ValueError:
                    pass
            else:
                pass
    try :
        log_file.write(f"\n\ntotal number of valid samples = {total_valid_samples} \n")
    except :
        pass

    if total_valid_samples > MINIMUM_VALID_SAMPLES:
        valid_run = True
    else:
        valid_run = False

    N = 0
    gx_sum = 0
    gy_sum = 0
    gx_sqr_sum = 0
    gy_sqr_sum = 0

    for line_number in line_numbers:
        if line_number < int(100*start):
            gx_sum = gx_sum + gxs[line_number]
            gy_sum = gy_sum + gys[line_number]
            gx_sqr_sum = gx_sqr_sum + gxs[line_number]**2
            gy_sqr_sum = gy_sqr_sum + gys[line_number]**2
            N = N + 1
    if N > 10:
        gx_bar = gx_sum/N
        gy_bar = gy_sum/N
        gx_sqr_bar = gx_sqr_sum/N
        gy_sqr_bar = gy_sqr_sum/N
        gx_var = gx_sqr_bar - gx_bar**2
        gy_var = gy_sqr_bar - gy_bar**2

    try:
        variance_indices = indices(jostle_window)
        gx_variance = windowed_variance(gxs,gx_bar,variance_indices)
        gy_variance = windowed_variance(gys,gy_bar,variance_indices)
        gx_gy_variance = gx_variance + gy_variance
    except:
        print("not enough data to compute variance, did you specify -s and -e values?")
        exit()

    try:

        variance_file.write(f"gx_bar ={round(gx_bar,2)},")
        variance_file.write(f"gy_bar ={round(gy_bar,2)},")
        variance_file.write(f"gx_var ={round(gx_var,2)},")
        variance_file.write(f"gy_var ={round(gy_var,2)}\r")
        variance_file.write(f"gx,gxwvar,gy,gywvar,total_var,weight\r")
    except:
        pass


    for line_number in line_numbers:
        total_variance = gx_gy_variance[line_number]
        if args.no_weights:
            weight = 1.0
        else:
            weight = corner_variance / (corner_variance + total_variance)
        weights.append(weight)
        try:
            variance_file.write(f"{round(gxs[line_number],2)},")
            variance_file.write(f"{round(gx_variance[line_number],2)},")
            variance_file.write(f"{round(gys[line_number],2)},")
            variance_file.write(f"{round(gy_variance[line_number],2)},")
            variance_file.write(f"{round(gx_gy_variance[line_number],2)},{round(weight,2)}\r")
        except:
            pass

    N = 0
    weight_sum = 0
    # lines = dataStr.splitlines(keepends=False)
    first_line = 1
    line_number = 0
    gravity_sum = np.zeros((3,1))
    if dataStr:
        for line in lines:
            columns = line.split(',')
            if len(columns) == NUM_COLS:
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
        if g_var > 0:
            g_std = sqrt(g_var)
        else:
            g_std = 0

        if N > 10:
            xTx_inv = np.linalg.inv(xTx_sum)

            beta_yaw = np.matmul(xTx_inv,x_yaw)
            beta_pitch = np.matmul(xTx_inv,x_pitch)
            beta_roll = np.matmul(xTx_inv,x_roll)
            yaw_var = yaw_sqr_sum - np.vdot(x_yaw, beta_yaw )
            pitch_var = pitch_sqr_sum - np.vdot(x_pitch, beta_pitch )
            roll_var = roll_sqr_sum - np.vdot(x_roll, beta_roll )

            force_stdev = g_std
            gyro_stdev = sqrt((pitch_var+roll_var)/weight_sum)
            gyro_drift = 6000.0*sqrt(beta_pitch[0,0]**2+beta_roll[0,0]**2)

            print("beta yaw = " , beta_yaw , " standard deviation yaw = " , round(sqrt(yaw_var/weight_sum),2) , "drift = " , round(6000.0*beta_yaw[0,0],2) )
            print("beta pitch = " , beta_pitch , " standard deviation pitch = " , round(sqrt(pitch_var/weight_sum),2), "drift = " , round(6000.0*beta_pitch[0,0],2) )
            print("beta roll = " , beta_roll , " standard deviation roll = " , round(sqrt(roll_var/weight_sum),2), "drift = " , round(6000.0*beta_roll[0,0],2) )

            try:

                log_file.write(f"statistical processing tuning parameters:\r")
                log_file.write(f"\rjostle detection weighting parameters, window size = {2*jostle_window+1} samples , corner variance = { corner_variance } ft/sec/sec squared.\r")
                log_file.write(f"\rspeed estimation kalman filter corner rotation rate = {corner_w} radians per second .\r\r")

                log_file.write(f"gyro drift analysis:\r\r")
                log_file.write(f"yaw: slope and offset = {beta_yaw} , stdev = {round(sqrt(yaw_var/weight_sum),2)} degrees , drift = {round(6000.0*beta_yaw[0,0],2)} deg/min\r\r")
                log_file.write(f"pitch: slope and offset = {beta_pitch} , stdev = {round(sqrt(pitch_var/weight_sum),2)} degrees , drift = {round(6000.0*beta_pitch[0,0],2)} deg/min\r\r")
                log_file.write(f"roll: slope and offset = {beta_roll} , stdev = {round(sqrt(roll_var/weight_sum),2)} degrees , drift = {round(6000.0*beta_roll[0,0],2)} deg/min\r\r")
                log_file.write(f"gyro analysis total standard deviation = {round(gyro_stdev,2)} degrees.\r")
                log_file.write(f"gyro rms drift = {round(gyro_drift,2)} degrees per minute.\r")
                log_file.write(f"note: standard deviations refer to how well the data fits a straight line.\r\r")
                log_file.write(f"g_bar = {g_bar}\r")
                log_file.write(f"g_bar_sqr = { g_bar_sqr }\r")
                log_file.write(f"g_sqr_bar = { g_sqr_bar }\r")
                log_file.write(f"g_var = { g_sqr_bar - g_bar_sqr}\r")

            except:
                pass
        else:
            try:
                log_file.write("gyro drift not analyzed, not enough data.\r\r")
            except:
                pass

        gx = gravity_sum[0,0]
        gy = gravity_sum[1,0]
        gz = gravity_sum[2,0]

        try:

            log_file.write("\ranalysis of specific force data:\r\r")
            log_file.write(f"x, y and z weighted average force vector = {round(gravity_sum[0,0]/weight_sum,2)} , {round(gravity_sum[1,0]/weight_sum,2)} , {round(gravity_sum[2,0]/weight_sum,2)} feet per second per second.\r")
            log_file.write(f"square root of the sum of the squares of x, y and z standard deviations = {round(g_std,2)} feet per second per second.\r")

            log_file.write(f"\r>>>>> note: this version of map.py is using statistical weighting of the data points to reduce the standard deviation of the estimate of the parameters. <<<<<<\r\r")
            log_file.write(f"There were {N} data points used, with a sum of weights equal to {round(weight_sum,2)}\r\r")

            if not args.yaw_offset:
                log_file.write(f"computed yaw alignment offset of {yaw_offset} degrees was used.\r")
            else:
                log_file.write(f"yaw alignment offset of {yaw_offset} degrees was specified.\r")

            if not args.pitch_offset:
                pitch_offset = round(degrees(atan2(-gx , sqrt((gy)**2+(gz)**2))),2)
                log_file.write(f"pitch alignment offset of {pitch_offset} degrees was computed.\r")
            else:
                log_file.write(f"pitch alignment offset of {pitch_offset} degrees was specified.\r")


            if not args.roll_offset:
                roll_offset = round(degrees(atan2(gy,gz)),2)
                log_file.write(f"roll alignment offset of {roll_offset} degrees was computed.\r\r")
            else:
                log_file.write(f"roll alignment offset of {roll_offset} degrees was specified.\r\r")

            if args.yaw_drift:
                log_file.write(f"yaw drift of {yaw_drift} degrees per minute was specified.\r")
            else:
                log_file.write(f"default yaw drift of {yaw_drift} degrees per minute was used.\r")

            if args.pitch_drift:
                log_file.write(f"pitch drift {pitch_drift} degrees per minute was specified.\r")
            else:
                if N > 10:
                    pitch_drift = round(6000.0*beta_pitch[0,0],2)
                    log_file.write(f"pitch drift of {pitch_drift} degrees/minute was computed.\r")
                else:
                    log_file.write(f"default pitch drift of {pitch_drift} degrees/minute was used.\r")

            if args.roll_drift:
                log_file.write(f"roll drift of {roll_drift} degrees/minute was specified.\r")
            else:
                if N > 10:
                    roll_drift = round(6000.0*beta_roll[0,0],2)
                    log_file.write(f"roll drift of {roll_drift} degrees/minute was computed.\r")
                else:
                    log_file.write(f"default roll drift of {roll_drift} degrees/minute was used.\r")
            if N < 11:
                summary_log_file.write(f">>>>>> warning <<<<<<< there were only {N} samples used in drift computations.\n")

            summary_log_write_adjustements(pitch_offset,roll_offset,pitch_drift,roll_drift)

        except:
            pass


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

    try:

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

    except:
        pass

    try:
        output_file.write("reprocessed file to account for gyro drift and misalignments.\r\r")
        output_file.write("yaw alignment offset of wolf-pac mounting = "+str(yaw_offset)+" degrees.\r")
        output_file.write("pitch alignment offset of wolf-pac mounting = "+str(pitch_offset)+" degrees.\r")
        output_file.write("roll alignment offset of wolf-pac mounting = "+str(roll_offset)+" degrees.\r" )

        output_file.write("pitch alignment offset of sled with respect to level at first line = "+str(pitch_zero)+" degrees.\r")
        output_file.write("roll alignment offset of sled with respect to level at first line = "+str(roll_zero)+" degrees.\r" )

        output_file.write("yaw gyro bias  = "+str(yaw_drift)+" degrees per minute.\r")
        output_file.write("pitch gyro bias  = "+str(pitch_drift)+" degrees per minute.\r")
        output_file.write("roll gyro bias  = "+str(roll_drift)+" degrees per minute.\r\r")
    except:
        pass

    if args.centrifuge_testing:
        create_ypr_matrix(yaw_offset, pitch_offset , roll_offset)
        first_mat = ypr_mat
        create_ypr_matrix(0.0, 0.0 , 0.0)
        ypr_o_mat = ypr_mat
        ypr_o_mat_transpose = ypr_mat
        print("centrifuge testing.")
    else:
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
    print("gyro_stdev = ",round(gyro_stdev,2))
    print("gyro_drift = ",round(gyro_drift,2))
    print("force_stdev = ",round(force_stdev,2))
    print("weight_sum = ",round(weight_sum,2))
    print("")
    print("")
    print("")
    no_warnings = True
    if gyro_stdev > gyro_stdev_max:
        no_warnings = False
        summary_log_file.write(f">>>*****************************************************<<<\n")
        summary_log_file.write(f"warning: the value of the gyro analysis standard deviation is {round(gyro_stdev,2)} degrees, which is greater than the allowed threshold of {gyro_stdev_max}\n")
        print(">>>*****************************************************<<<")
        print("warning: the value of the gyro analysis standard deviation is ",round(gyro_stdev,2)," degrees, which is greater than the allowed threshold of ",gyro_stdev_max)
    if gyro_drift > gyro_drift_max:
        valid_run = False
        no_warnings = False
        summary_log_file.write(f">>>*****************************************************<<<\n")
        summary_log_file.write(f"warning: the value of the total gyro rms drift is {round(gyro_drift,2)} degrees per minute, which is greater than the allowed threshold of {gyro_drift_max}\n")
        print(">>>*****************************************************<<<")
        print("warning: the value of the total gyro rms drift is ",round(gyro_drift,2)," degrees per minute, which is greater than the allowed threshold of ",gyro_drift_max)
    if force_stdev > force_stdev_max:
        no_warnings = False
        summary_log_file.write(f">>>*****************************************************<<<\n")
        summary_log_file.write(f"warning: the value of the force analysis standard deviation is {round(force_stdev,2)} ft/sec/sec, which is greater than the allowed threshold of {force_stdev_max}\n")
        print(">>>*****************************************************<<<")
        print("warning: the value of the force analysis standard deviation is ",round(force_stdev,2)," ft/sec/sec, which is greater than the allowed threshold of ",force_stdev_max)
    if weight_sum < weights_min:
        valid_run = False
        no_warnings = False
        summary_log_file.write(f">>>*****************************************************<<<\n")
        summary_log_file.write(f"warning: the sum of the analysis weights is {round(weight_sum,2)} , which is less than the allowed threshold of {weights_min}\n")
        print(">>>*****************************************************<<<")
        print("warning: the sum of the analysis weights is ",round(weight_sum,2),", which is less than the allowed threshold of ",weights_min)
    try:
        compare_file.write("x_force_in , x_force_out , y_force_in, y_force_out , z_force_in , z_force_out , yaw_in , yaw_out , pitch_in , pitch_out, roll_in , roll_out\r")
    except:
        pass
    first_line = 1
    line_number = 0

    # lines = dataStr.splitlines(keepends=False)
    if dataStr:
        for line in lines:
            columns = line.split(',')
            if len(columns) == NUM_COLS:
                try:
                    xa_in = float(columns[XA_COL])
                    ya_in = float(columns[YA_COL])
                    za_in = float(columns[ZA_COL])
                    yaw_in = float(columns[YAW_COL])
                    pitch_in = float(columns[PITCH_COL])
                    roll_in = float(columns[ROLL_COL])

                    line_nums.append(line_number)

                    line_number = line_number + 1

                    if line_number > skip_lines:

                        create_ypr_matrix(yaw_in,pitch_in,roll_in)
                        matrix_in = ypr_mat
                        if first_line == 1 or line_number == int(100*start):
                            matrix_in_prev = matrix_in
                            create_ypr_matrix(0.0 , pitch_in , roll_in )
                            matrix_out  = ypr_mat
                            matrix_out_prev = matrix_out
                            #matrix_out = np.matmul(first_mat,ypr_o_mat)
                            #matrix_in_prev = matrix_in
                            #matrix_out_prev = matrix_out
                        else:

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


                        if first_line == 1:
                            first_line = 0
                            heading = yaw_out
                            previous_yaw = yaw_out
                        else:
                            if abs(yaw_out - previous_yaw) < 90:
                                heading = heading + yaw_out - previous_yaw
                            else:
                                if yaw_out - previous_yaw > 0:
                                    heading = heading + yaw_out - previous_yaw - 360
                                else:
                                    heading = heading + yaw_out - previous_yaw + 360
                            previous_yaw = yaw_out
                    else:
                        xa_out = xa_in
                        ya_out = ya_in
                        za_out = za_in
                        heading = yaw_in
                        pitch_out = pitch_in
                        roll_out = roll_in

                    try:

                        output_file.write(str(xa_out)+","+str(ya_out)+","+str(za_out)+",")
                        output_file.write(str(round(heading,2))+","+str(pitch_out)+","+str(roll_out)+",")
                        output_file.write(columns[6]+","+columns[7]+","+columns[8]+","+columns[9]+","+columns[10]+"\r")
                        # output_data.append([xa_out, ya_out, za_out, round(heading,2), pitch_out, roll_out])

                        compare_file.write(f"{xa_in},{xa_out},{ya_in},{ya_out},{za_in},{za_out},{yaw_in},{round(heading,2)},{pitch_in},{pitch_out},{roll_in},{roll_out}\r")
                    except:
                        pass

                    omega_e = np.matmul(matrix_adjusted,omega)
                    omegas_e_x.append(omega_e[0,0])
                    omegas_e_y.append(omega_e[1,0])
                    omegas_e_z.append(omega_e[2,0])

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
                    roll_list.append(roll_out)


                except ValueError:
                    try:
                        output_file.write(line+"\r")
                    except:
                        pass
                    pass
            else:
                try:
                    output_file.write(line+"\r")
                except:
                    pass

    return None

def write_summary_header():
    summary_log_file.write(f"     file_name,")
    summary_log_file.write(f"            ts,")
    summary_log_file.write(f"            po,")
    summary_log_file.write(f"            ro,")
    summary_log_file.write(f"            pd,")
    summary_log_file.write(f"            rd\n")


def run_passes():
    global skip_pass_7_and_8
    global velocity, z_x_cc, input_file, fx_list, fy_list, fz_list, wx_list, wy_list, wz_list
    global gx_list, gy_list, gz_list, heading_list, pitch_list, roll_list, filter_size
    global fx_filt, fy_filt, fz_filt, wx_filt, wy_filt, wz_filt, heading_filt, pitch_filt, roll_filt
    global omegas_e_x, omegas_e_y, omegas_e_z, omegas_e_f_x, omegas_e_f_y, omegas_e_f_z
    global roll_edge_filter_size, roll_edges, yaw_rate_edges
    global debug_file, log_file, marks_file, time_map_100_file, time_map_file, distance_map_file, rabbit_log_file
    global start, elapsed, end, line_nums, g_force, force_out, omega, max_err, feedback_gain
    global gravity_value, z_force_plot_limit, rotation, first_heading_recorded, speed, distance
    global x, y, x_ef, y_ef, args, errors_in, errors_out, acceleration , mark_state, mark_number
    global distance_origin, line_origin, run_end_distance, run_end_time, table_end_distance
    global table_end_time, alignment_accel, previous_line_number, first_heading, valid_run
    global file_base_name, run_time, number_of_marks
    ######################################
    #
    # pass 1 and 2: read input file, estimate offsets and drift,
    # and compensate all data
    #
    ######################################

    read_data(input_file)

    #####################################
    #
    # intermission: apply filters to all data
    #
    #####################################

    fx_filt = mav_filter(fx_list,indices(filter_size))
    fy_filt = mav_filter(fy_list,indices(filter_size))
    fz_filt = mav_filter(fz_list,indices(filter_size))

    wx_filt = mav_filter(wx_list,indices(filter_size))
    wy_filt = mav_filter(wy_list,indices(filter_size))
    wz_filt = mav_filter(wz_list,indices(filter_size))

    heading_filt = mav_filter(heading_list,indices(filter_size))
    pitch_filt = mav_filter(pitch_list,indices(filter_size))
    roll_filt = mav_filter(roll_list,indices(filter_size))

    heading_hf = []
    pitch_hf = []
    roll_hf = []

    fz_hf = []

    scull = []

    for list_index in range(len(heading_filt)):
        heading_hf.append(heading_list[list_index] - heading_filt[list_index])

    for list_index in range(len(pitch_filt)):
        pitch_hf.append(pitch_list[list_index] - pitch_filt[list_index])

    for list_index in range(len(roll_filt)):
        roll_hf.append(roll_list[list_index] - roll_filt[list_index])

    for list_index in range(len(fz_filt)):
        fz_hf.append(fz_list[list_index] - fz_filt[list_index])
        scull.append(radians(fz_hf[list_index]*pitch_hf[list_index]))

    for list_index in range(len(fx_filt)):
        fx_list[list_index] = fx_list[list_index] - scull[list_index]
        fx_filt[list_index] = fx_filt[list_index] - scull[list_index]


    omegas_e_f_x = mav_filter(omegas_e_x,indices(filter_size))
    omegas_e_f_y = mav_filter(omegas_e_y,indices(filter_size))
    omegas_e_f_z = mav_filter(omegas_e_z,indices(filter_size))

    roll_edges = mav_filter(roll_list,indices(roll_edge_filter_size))
    yaw_rate_edges = edge_filter(omegas_e_f_z,indices(filter_size))


    ##################################################################
    #
    #
    #  recompute yaw misalignment
    #
    #
    ################################################################

    A = np.zeros((1,2))
    AT = np.transpose(A)
    ATA = np.matmul(AT,A)
    Y = np.zeros((1,1))
    ATY = np.matmul(AT,Y)

    try :
        log_file.write(f"recomputation of residual yaw offset\r\n")
    except :
        pass

    
    for index in range ( len(pitch_list ) ):
        roll_angle = roll_list[index]
        if abs(roll_angle) > 45 :
            Y[0,0] = pitch_list[index]
            A[0,0] = 1
            A[0,1] = sin(radians(roll_angle))
            AT = np.transpose(A)
            ATA = ATA + np.matmul(AT,A)
            ATY = ATY + np.matmul(AT,Y)

    ATA_INVERSE = np.linalg.inv(ATA)
    cross = np.matmul(ATA_INVERSE,ATY)
    yaw_offset = cross[1,0]

    try :

        log_file.write(f"computing yaw misalignment model\r\n")
        log_file.write(f"ATA={ATA}\r\n")
        log_file.write(f"ATY={ATY}\r\n")
        log_file.write(f"det of ATA = {np.linalg.det(ATA)}\r\n")
        log_file.write(f"ATA inverse = {ATA_INVERSE}\r\n")
        log_file.write(f"cross = {cross}\r\n")
        log_file.write(f"yaw_offset = {yaw_offset}")
    except :
        pass


############################################################
#
#   extra filtering
#
#
#
############################################################
      
    fx_filt_filt = mav_filter(fx_filt , indices(80))
    fx_filt = fx_filt_filt
    fz_filt_filt = mav_filter(fz_filt , indices(80))
    
    wx_filt_filt = mav_filter(wx_filt,indices(80))
    wy_filt_filt = mav_filter(wy_filt,indices(80))
    wz_filt_filt = mav_filter(wz_filt,indices(80))
     
    #######################################
    #
    # pass 3: write data to debug file and
    # take a first cut and speed estimation,
    # and estimate the z to x specific force cross coupling
    # in the process.
    #
    #######################################

    try:
        debug_file.write(f"line,fx_raw,fx_filt,fy_raw,fy_filt,fz_raw,fz_filt,wx_raw,wx_filt,wy_raw,wy_filt,wz_raw,wz_filt,")
        debug_file.write(f"wx_earth,wx_earth_filt,wy_earth,wy_earth_filt,wz_earth,wz_earth_filt,")
        debug_file.write(f"gx,gy,gz,heading,pitch,roll\r")
    except:
        pass


    end = start + elapsed

    error_sum = 0
    acc_sum = 0

    A = np.zeros((1,3))
    AT = np.transpose(A)
    ATA = np.matmul(AT,A)
    Y = np.zeros((1,1))
    ATY = np.matmul(AT,Y)


    for line_number in line_nums:
        try:
            debug_file.write(f"{line_number},")
            debug_file.write(f"{round(fx_list[line_number],2)},{round(fx_filt[line_number],2)},")
            debug_file.write(f"{round(fy_list[line_number],2)},{round(fy_filt[line_number],2)},")
            debug_file.write(f"{round(fz_list[line_number],2)},{round(fz_filt[line_number],2)},")

            debug_file.write(f"{round(wx_list[line_number],2)},{round(wx_filt[line_number],2)},")
            debug_file.write(f"{round(wy_list[line_number],2)},{round(wy_filt[line_number],2)},")
            debug_file.write(f"{round(wz_list[line_number],2)},{round(wz_filt[line_number],2)},")

            debug_file.write(f"{round(omegas_e_x[line_number],2)},{round(omegas_e_f_x[line_number],2)},")
            debug_file.write(f"{round(omegas_e_y[line_number],2)},{round(omegas_e_f_y[line_number],2)},")
            debug_file.write(f"{round(omegas_e_z[line_number],2)},{round(omegas_e_f_z[line_number],2)},")

            debug_file.write(f"{round(gx_list[line_number],2)},")
            debug_file.write(f"{round(gy_list[line_number],2)},")
            debug_file.write(f"{round(gz_list[line_number],2)},")

            debug_file.write(f"{round(heading_list[line_number],2)},")
            debug_file.write(f"{round(pitch_list[line_number],2)},")
            debug_file.write(f"{round(roll_list[line_number],2)}\r")
        except:
            pass

        
        
        if int(100*start) <= line_number <= int(100*end):
            heading = heading_list[line_number]
            pitch_out = pitch_list[line_number]
            roll_out = roll_list[line_number]
            g_force[0,0]=gx_list[line_number]
            g_force[1,0]=gy_list[line_number]
            g_force[2,0]=gz_list[line_number]
            force_out[0,0]=fx_filt[line_number]
            force_out[1,0]=fy_filt[line_number]
            force_out[2,0]=fz_filt_filt[line_number]
            omega[0,0]=wx_filt[line_number]
            omega[1,0]=wy_filt_filt[line_number]
            omega[2,0]=wz_filt[line_number]

            velocity_dot = g_force + force_out

            correction_gain = k_gain(omega[1,0],velocity[0,0],velocity_dot[2,0])
            v_error = k_error(omega[1,0],velocity[0,0],velocity_dot[2,0],correction_gain)

            Y[0,0] = v_error
            A[0,0] = A[0,0]+1.0/100.0
            A[0,1] = A[0,1] + (force_out[2,0]+32.1741)/100.0
            A[0,2] = A[0,2] + ((force_out[2,0]+32.1741)**2)/100.0
            AT = np.transpose(A)
            ATA = ATA + np.matmul(AT,A)
            ATY = ATY + np.matmul(AT,Y)

            velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0]  )/100.0

    ATA_INVERSE = np.linalg.inv(ATA)

    cross_couple_model = np.matmul(ATA_INVERSE,ATY)
    

    try :

        log_file.write(f"\r\n\r\ncomputation force cross couple modele\r\n")                              
        log_file.write(f"ATA={ATA}\r\n")
        log_file.write(f"ATY={ATY}\r\n")
        log_file.write(f"det of ATA = {np.linalg.det(ATA)}\r\n")
        log_file.write(f"ATA inverse = {ATA_INVERSE}\r\n")
        log_file.write(f"model = {cross_couple_model}\r\n")
    except:
        pass

    ######################################
    #
    # pass 4: recompute velocity with with
    # cross coupling taken into acount
    #
    #########################################

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

    for line_number in line_nums:

        if int(100*start) <= line_number <= int(100*end):
            heading = heading_list[line_number]
            pitch_out = pitch_list[line_number]
            roll_out = roll_list[line_number]
            g_force[0,0]=gx_list[line_number]
            g_force[1,0]=gy_list[line_number]
            g_force[2,0]=gz_list[line_number]
            force_out[0,0]=fx_filt[line_number]
            force_out[1,0]=fy_filt[line_number]
            force_out[2,0]=fz_filt_filt[line_number]
            omega[0,0]=wx_filt[line_number]
            omega[1,0]=wy_filt_filt[line_number]
            omega[2,0]=wz_filt[line_number]
            
            velocity_dot = g_force + force_out
            
            correction_gain = k_gain(omega[1,0],velocity[0,0],velocity_dot[2,0])
            
            v_error = k_error(omega[1,0],velocity[0,0],velocity_dot[2,0],correction_gain)

            if v_error > max_err:
                v_error = max_err
            if v_error < -max_err:
                v_error = -max_err

            force_out[0,0] = force_out[0,0] + cross_couple_model[0,0] + cross_couple_model[1,0]*(force_out[2,0]+32.1741)+cross_couple_model[2,0]*(force_out[2,0]+32.1741)**2 + v_error

            velocity_dot[0,0] = g_force[0,0]+force_out[0,0] 
            
            velocity[0,0] = velocity[0,0] + velocity_dot[0,0]/100.0
            
            new_distance = new_distance + velocity[0,0]/100.0

        #errors_in.append(v_error)
        #acceleration.append(velocity_dot[0,0])

    #errors_out = mav_filter(errors_in,indices(20))

    '''

    #################################################################
    #
    # pass 5
    #
    # if a time mark model was not supplied, compute one and save it.
    # if so, compute one and compare it with the supplied model,
    # in order to compute the adustment factor, alignment_accel
    # 
    ################################################################


    mark_state = 0
    mark_number = 1
    distance_origin = 0
    line_origin = int(100*start)
    new_distance = 0
    velocity = np.zeros((3,1))

    try:
        if args.track_marks_file_name:
            marks_file.write("number,ref_number,state,ref_state,distance,ref_distance,time,ref_time,velocity,ref_velocity\r")
            marks_file.write("0,0,0,0,0.0,0.0,0.0,0.0,0.0,0.0\r")
        else:
            marks_file.write("number,state,distance,time,velocity\r")
            marks_file.write("0,0,0.0,0.0,0.0\r")
    except:
        pass

    for line_number in line_nums:

        if int(100*start) <= line_number <= int(100*end):
            heading = heading_list[line_number]
            pitch_out = pitch_list[line_number]
            roll_out = roll_list[line_number]
            g_force[0,0]=gx_list[line_number]
            g_force[1,0]=gy_list[line_number]
            g_force[2,0]=gz_list[line_number]
            force_out[0,0]=fx_filt[line_number]
            force_out[1,0]=fy_filt[line_number]
            force_out[2,0]=fz_filt[line_number]
            omega[0,0]=wx_filt[line_number]
            omega[1,0]=wy_filt[line_number]
            omega[2,0]=wz_filt[line_number]
            omega_e[0,0] = omegas_e_f_x[line_number]
            omega_e[1,0] = omegas_e_f_y[line_number]
            omega_e[2,0] = omegas_e_f_z[line_number]

            velocity_dot = g_force + force_out

            correction_gain = k_gain(omega[1,0],velocity[0,0],velocity_dot[2,0])
            v_error = k_error(omega[1,0],velocity[0,0],velocity_dot[2,0],correction_gain)

            if v_error > max_err:
                v_error = max_err
            if v_error < -max_err:
                v_error = -max_err

            if args.no_kalman:
                velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0]  + (z_x_cc/gravity_value)*(velocity_dot[2,0]**2) )/100.0
            else:
                velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0] + feedback_gain*v_error + (z_x_cc/gravity_value)*(velocity_dot[2,0]**2) )/100.0


            new_distance = new_distance + velocity[0,0]/100.0

            if args.track_marks_file_name:
               update_mark_state_with_tr_mdl(omega[2,0],omega[0,0] , roll_out , heading )
            else:
               update_mark_state_no_tr_mdl(omega[2,0],omega[0,0] , roll_out , heading )

    if args.track_marks_file_name:
        if run_end_time > 0.0:
            alignment_accel = 2.0*((table_end_distance-run_end_distance)/((run_end_time/100.0)**2))
        else:
            alignment_accel = 0.0
        try:
            log_file.write(f"\rrun-table alignment parameters:\r")
            log_file.write(f"run end distance = {run_end_distance}\r")
            log_file.write(f"table end distance = {table_end_distance}\r")
            log_file.write(f"run end time = {run_end_time}\r")
            log_file.write(f"table end time = {table_end_time}\r\r\r")
            log_file.write(f"alignment acceleration = {round(alignment_accel,3)} ft/sec/sec\r\r")
        except:
            pass

    '''

    #########################################################
    #
    #  pass 6 compute and store 100 Hz time map
    #
    #########################################################




    first_heading_recorded = 0
    speed = 0
    distance = 0
    x=0
    y=0
    x_ef=0
    y_ef=0
    velocity = np.zeros((3,1))
    new_distance = 0

    mark_state = 0
    mark_number = 0
    distance_origin = 0
    line_origin = int(100*start)
    global previous_line_number
    previous_line_number = line_origin

    map_line = 0
    map_lines = []
    map_times = []
    map_rolls = []
    map_pitches = []
    map_yaws = []
    map_velocities = []
    map_distances = []
    map_xs = []
    map_ys = []
    map_marks = []
    map_states = []
    map_roll_rates = []
    map_pitch_rates = []
    map_yaw_rates = []
    map_x_accels = []
    map_y_accels = []
    map_z_accels = []

    try:

        if valid_run is True:
            run_name = file_base_name
        else:
            run_name = file_base_name+"?"

        if args.strmlt:

            time_map_100_file.write(f"time__{run_name}")
            time_map_100_file.write(f",mark_number__{run_name}")
            time_map_100_file.write(f",mark_state__{run_name}")

            time_map_100_file.write(f",friction+aero__{run_name}")
            time_map_100_file.write(f",y_force__{run_name}")
            time_map_100_file.write(f",z_force__{run_name}")

            time_map_100_file.write(f",roll__{run_name}")
            time_map_100_file.write(f",pitch__{run_name}")
            time_map_100_file.write(f",-yaw__{run_name}")

            time_map_100_file.write(f",roll_rate__{run_name}")
            time_map_100_file.write(f",pitch_rate__{run_name}")
            time_map_100_file.write(f",yaw_rate__{run_name}")

            #if extra_omegas == True:

            #    time_map_100_file.write(f",total_w_rate_{run_name}")
            #   time_map_100_file.write(f",yaw_rate_earth_frame_{run_name}")

            time_map_100_file.write(f",velocity__{run_name}")
            time_map_100_file.write(f",x-acceleration__{run_name}")
            time_map_100_file.write(f",z-force-filtered__{run_name}")          
            time_map_100_file.write(f",kalman_input__{run_name}")
            time_map_100_file.write(f",distance__{run_name}")
            time_map_100_file.write(f",x__{run_name}")
            time_map_100_file.write(f",y__{run_name}")

            #if sculling_debug == True:

             #   time_map_100_file.write(f",roll_hf_{file_base_name}")
             #   time_map_100_file.write(f",pitch_hf_{file_base_name}")
             #   time_map_100_file.write(f",yaw_hf_{file_base_name}")

             #   time_map_100_file.write(f",sculling_{file_base_name}")

            time_map_100_file.write(f"\n")

        else:

            time_map_100_file.write(f"time__{file_base_name}")
            time_map_100_file.write(f",mark_number__{file_base_name}")
            time_map_100_file.write(f",mark_state__{file_base_name}")

            time_map_100_file.write(f",friction+aero__{file_base_name}")
            time_map_100_file.write(f",y_force__{file_base_name}")
            time_map_100_file.write(f",z_force__{file_base_name}")

            time_map_100_file.write(f",roll__{file_base_name}")
            time_map_100_file.write(f",pitch__{file_base_name}")
            time_map_100_file.write(f",-yaw__{file_base_name}")

            time_map_100_file.write(f",roll_rate__{file_base_name}")
            time_map_100_file.write(f",pitch_rate__{file_base_name}")
            time_map_100_file.write(f",yaw_rate__{file_base_name}")

            #if extra_omegas == True:

            #    time_map_100_file.write(f",total_w_rate_{file_base_name}")
            #   time_map_100_file.write(f",yaw_rate_earth_frame_{file_base_name}")

            time_map_100_file.write(f",velocity__{file_base_name}")
            time_map_100_file.write(f",x-acceleration__{run_name}")          
            time_map_100_file.write(f",z-force-filtered__{run_name}")                     
            time_map_100_file.write(f",kalman_input__{file_base_name}")
            time_map_100_file.write(f",distance__{file_base_name}")
            time_map_100_file.write(f",x__{file_base_name}")
            time_map_100_file.write(f",y__{file_base_name}")

            #if sculling_debug == True:

             #   time_map_100_file.write(f",roll_hf_{file_base_name}")
             #   time_map_100_file.write(f",pitch_hf_{file_base_name}")
             #   time_map_100_file.write(f",yaw_hf_{file_base_name}")

             #   time_map_100_file.write(f",sculling_{file_base_name}")

            time_map_100_file.write(f"\n")



    except:
        pass

    A = np.zeros((1,2))
    AT = np.transpose(A)
    ATA = np.matmul(AT,A)
    Y = np.zeros((1,1))
    ATY = np.matmul(AT,Y)
    ysqr = 0
    N = 0

    for line_number in line_nums:

        if int(100*start) <= line_number <= int(100*end):
            heading = heading_list[line_number]
            pitch_out = pitch_list[line_number]
            roll_out = roll_list[line_number]
            g_force[0,0]=gx_list[line_number]
            g_force[1,0]=gy_list[line_number]
            g_force[2,0]=gz_list[line_number]
            force_out[0,0]=fx_filt[line_number]
            force_out[1,0]=fy_filt[line_number]
            force_out[2,0]=fz_filt_filt[line_number]
            omega[0,0]=wx_filt[line_number]
            omega[1,0]=wy_filt_filt[line_number]
            omega[2,0]=wz_filt[line_number]
            omega_e[0,0] = omegas_e_f_x[line_number]
            omega_e[1,0] = omegas_e_f_y[line_number]
            omega_e[2,0] = omegas_e_f_z[line_number]

            update_timing_mark(omega[2,0],omega[0,0],roll_out,heading)

            map_marks.append(mark_number)
            map_states.append(mark_state)

            if first_heading_recorded == 0:
                first_heading = heading
                first_heading_recorded = 1
            cosine = cos(radians(heading-first_heading+rotation))
            sine = -sin(radians(heading-first_heading+rotation))

            x_ef = x_ef + velocity[0,0]*(cosine/100.0)
            y_ef = y_ef + velocity[0,0]*(sine/100.0)

            velocity_dot = g_force + force_out
            
            correction_gain = k_gain(omega[1,0],velocity[0,0],velocity_dot[2,0])
            
            v_error = k_error(omega[1,0],velocity[0,0],velocity_dot[2,0],correction_gain)

            if v_error > max_err:
                v_error = max_err
            if v_error < -max_err:
                v_error = -max_err

            force_out[0,0] = force_out[0,0] + cross_couple_model[0,0] + cross_couple_model[1,0]*(force_out[2,0]+32.1741)+cross_couple_model[2,0]*(force_out[2,0]+32.1741)**2 + v_error

            velocity_dot[0,0] = g_force[0,0]+force_out[0,0] 
            
            velocity[0,0] = velocity[0,0] + velocity_dot[0,0]/100.0
            
            new_distance = new_distance + velocity[0,0]/100.0

            Y[0,0] = fx_filt[line_number]
            A[0,0] = force_out[2,0]
            A[0,1] = A[0,1] + (velocity[0,0])**2
            AT = np.transpose(A)
            ATA = ATA + np.matmul(AT,A)
            ATY = ATY + np.matmul(AT,Y)
            ysqr = ysqr + (Y[0,0])**2
            N = N + 1
            
            

            #note: in the code below, alignment_accel is used to reconcile the run time marks with the track model time marks

            #if args.no_kalman:
                #velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0]  + (z_x_cc/gravity_value)*(velocity_dot[2,0]**2) + alignment_accel )/100.0
            #else:
                #velocity[0,0] = velocity[0,0] + ( velocity_dot[0,0] + feedback_gain*v_error + (z_x_cc/gravity_value)*(velocity_dot[2,0]**2) + alignment_accel )/100.0


            local_time = ( line_number -  line_origin )/100.0

            if new_distance < table_end_distance:

                try:

                    if args.strmlt:

                       # w_mag = sqrt( (wx_filt[line_number])**2 + (wy_filt[line_number])**2 + (wz_filt[line_number])**2 )

                        time_map_100_file.write(f"{round(( local_time   ), 2)}")
                        time_map_100_file.write(f",{mark_number},{mark_state}")

                        time_map_100_file.write(f" ,{round(( fx_filt[line_number] ),2)}" )
                        time_map_100_file.write(f" ,{round(( fy_filt[line_number] ),2)}" )
                        if fz_filt[line_number] > z_force_plot_limit:
                            time_map_100_file.write(f" ,{round(( fz_filt[line_number] ),2)}" )
                        else:
                            time_map_100_file.write(f" ,{round(( z_force_plot_limit ),2)}" )

                        time_map_100_file.write(f",{round(( roll_out   ), 2)}")
                        time_map_100_file.write(f",{round(( pitch_out   ), 2)}")
                        time_map_100_file.write(f",{round(( -heading   ), 2)}")

                        time_map_100_file.write(f" ,{round(degrees(wx_filt[line_number]),2 )}" )
                        time_map_100_file.write(f" ,{round(degrees(wy_filt[line_number]),2 )}" )
                        time_map_100_file.write(f" ,{round(degrees(wz_filt[line_number]),2 )}" )

                        #if extra_omegas == True:

                        #    time_map_100_file.write(f" ,{round(degrees(w_mag),2 )}" )

                        #    time_map_100_file.write(f" ,{round(degrees(omegas_e_f_z[line_number]),2 )}" )   

                        time_map_100_file.write(f",{round(( velocity[0,0]   ), 2)}")
                        time_map_100_file.write(f",{round(( velocity_dot[0,0]   ), 2)}")
                        time_map_100_file.write(f",{round(( fz_filt_filt[line_number]/ 32.1741  ), 4)}")
                        time_map_100_file.write(f",{round(( v_error   ), 2)}")
                        time_map_100_file.write(f",{round((  new_distance  ), 2)}")
                        time_map_100_file.write(f",{round(( x_ef   ), 2)}")
                        time_map_100_file.write(f",{round(( y_ef   ), 2)}")

                        #if sculling_debug == True:

                        #    time_map_100_file.write(f" ,{round(( roll_hf[line_number] ),2)}" )
                        #    time_map_100_file.write(f" ,{round(( pitch_hf[line_number] ),2)}" )
                        #    time_map_100_file.write(f" ,{round(( heading_hf[line_number] ),2)}" )

                        #    time_map_100_file.write(f" ,{round(( scull[line_number] ),2)}" )

                        time_map_100_file.write(f"\n")

                    else:

                        w_mag = sqrt( (wx_filt[line_number])**2 + (wy_filt[line_number])**2 + (wz_filt[line_number])**2 )

                        time_map_100_file.write(f"{round(( local_time   ), 2)}")
                        time_map_100_file.write(f",{mark_number},{mark_state}")

                        time_map_100_file.write(f" ,{round(( fx_filt[line_number] ),2)}" )
                        time_map_100_file.write(f" ,{round(( fy_filt[line_number] ),2)}" )
                        if fz_filt[line_number] > z_force_plot_limit:
                            time_map_100_file.write(f" ,{round(( fz_filt[line_number] ),2)}" )
                        else:
                            time_map_100_file.write(f" ,{round(( z_force_plot_limit ),2)}" )

                        time_map_100_file.write(f",{round(( roll_out   ), 2)}")
                        time_map_100_file.write(f",{round(( pitch_out   ), 2)}")
                        time_map_100_file.write(f",{round(( -heading   ), 2)}")

                        time_map_100_file.write(f" ,{round(degrees(wx_filt[line_number]),2 )}" )
                        time_map_100_file.write(f" ,{round(degrees(wy_filt[line_number]),2 )}" )
                        time_map_100_file.write(f" ,{round(degrees(wz_filt[line_number]),2 )}" )

                        #if extra_omegas == True:

                        #    time_map_100_file.write(f" ,{round(degrees(w_mag),2 )}" )

                        #    time_map_100_file.write(f" ,{round(degrees(omegas_e_f_z[line_number]),2 )}" )   

                        time_map_100_file.write(f",{round(( velocity[0,0]   ), 2)}")
                        time_map_100_file.write(f",{round(( velocity_dot[0,0]   ), 2)}")
                        time_map_100_file.write(f",{round(( v_error   ), 2)}")
                        time_map_100_file.write(f",{round((  new_distance  ), 2)}")
                        time_map_100_file.write(f",{round(( x_ef   ), 2)}")
                        time_map_100_file.write(f",{round(( y_ef   ), 2)}")

                        #if sculling_debug == True:

                        #    time_map_100_file.write(f" ,{round(( roll_hf[line_number] ),2)}" )
                        #    time_map_100_file.write(f" ,{round(( pitch_hf[line_number] ),2)}" )
                        #    time_map_100_file.write(f" ,{round(( heading_hf[line_number] ),2)}" )

                        #    time_map_100_file.write(f" ,{round(( scull[line_number] ),2)}" )

                        time_map_100_file.write(f"\n")



                except:
                    pass

                map_lines.append(map_line)
                map_line = map_line + 1
                map_times.append(local_time)
                map_rolls.append(roll_out)
                map_pitches.append(pitch_out)
                map_yaws.append(heading)
                map_velocities.append(velocity[0,0])
                map_distances.append(new_distance)
                map_xs.append(x_ef)
                map_ys.append(y_ef)
                map_roll_rates.append( degrees(wx_filt[line_number]) )
                map_pitch_rates.append( degrees(wy_filt[line_number]) )
                map_yaw_rates.append(  degrees(wz_filt[line_number]) )
                map_x_accels.append( ( fx_filt[line_number] ) )
                map_y_accels.append( ( fy_filt[line_number] ) )
                map_z_accels.append( ( fz_filt[line_number] ) )

    ATA_INVERSE = np.linalg.inv(ATA)

    drag_model = np.matmul(ATA_INVERSE,ATY)

    ATYTX = np.matmul(np.transpose(ATY),drag_model)

    if N > 0 :
        sigma_sqr = ( ysqr - ATYTX[0,0] ) / N
    else :
        sigma_sqr = 0
    variance = sqrt (abs(sigma_sqr))

    log_file.write(f"drag model = {drag_model}\n")
    log_file.write(f"friction = {drag_model[0,0]}\n")
    log_file.write(f"aero coef = {drag_model[1,0]}\n")
    log_file.write(f"variance = {variance}\n")

    


#########################################################
#
#  pass 7 compute, store and write time map with 1000 Hz time steps
#
#########################################################

    steps = [ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ]

    if skip_pass_7_and_8 == True :
        return

    try:

        time_map_file.write(f"time,")

        time_map_file.write(f"timing_mark_number,")
        time_map_file.write(f"timing_mark_type,")

        time_map_file.write(f"x_force,")
        time_map_file.write(f"y_force,")
        time_map_file.write(f"z_force,")

        time_map_file.write(f"roll,")
        time_map_file.write(f"pitch,")
        time_map_file.write(f" -yaw,")

        time_map_file.write(f"roll_rate,")
        time_map_file.write(f"pitch_rate,")
        time_map_file.write(f"yaw_rate,")

        time_map_file.write(f"velocity,")
        time_map_file.write(f"distance,")

        time_map_file.write(f"x,")
        time_map_file.write(f"y\r")

    except:
        pass

    map_time_prev = map_times[0]

    map_x_accel_prev = map_x_accels[0]
    map_y_accel_prev = map_y_accels[0]
    map_z_accel_prev = map_z_accels[0]

    map_roll_prev = map_rolls[0]
    map_pitch_prev = map_pitches[0]
    map_yaw_prev = map_yaws[0]

    map_roll_rate_prev = map_roll_rates[0]
    map_pitch_rate_prev = map_pitch_rates[0]
    map_yaw_rate_prev = map_yaw_rates[0]

    map_velocity_prev = map_velocities[0]
    map_distance_prev = map_distances[0]
    map_x_prev = map_xs[0]
    map_y_prev = map_ys[0]

    map_lines_10x = []
    map_times_10x = []
    map_rolls_10x = []
    map_pitches_10x = []
    map_yaws_10x = []
    map_velocities_10x = []
    map_distances_10x = []
    map_xs_10x = []
    map_ys_10x = []
    map_marks_10x = []
    map_states_10x = []

    map_roll_rates_10x = []
    map_pitch_rates_10x = []
    map_yaw_rates_10x = []
    map_x_accels_10x = []
    map_y_accels_10x = []
    map_z_accels_10x = []


    line_10x = 0

    for map_line in map_lines:

        map_time = map_times[map_line]

        map_x_accel = map_x_accels[map_line]
        map_y_accel = map_y_accels[map_line]
        map_z_accel = map_z_accels[map_line]

        map_roll = map_rolls[map_line]
        map_pitch = map_pitches[map_line]
        map_yaw = map_yaws[map_line]

        map_roll_rate = map_roll_rates[map_line]
        map_pitch_rate = map_pitch_rates[map_line]
        map_yaw_rate = map_yaw_rates[map_line]

        map_velocity = map_velocities[map_line]
        map_distance = map_distances[map_line]
        map_x = map_xs[map_line]
        map_y = map_ys[map_line]

        mark_number = map_marks[map_line]
        mark_type = map_states[map_line]


        if map_line > 0:
            for step in steps:
                map_lines_10x.append(line_10x)
                line_10x = line_10x + 1

                weight_prev = (10.0 - float(step))/10.0
                weight_next =  1.0 - weight_prev

                time_10x = ( weight_prev*map_time_prev + weight_next*map_time )

                x_accel_10x = ( weight_prev*map_x_accel_prev + weight_next*map_x_accel )
                y_accel_10x = ( weight_prev*map_y_accel_prev + weight_next*map_y_accel )
                z_accel_10x = ( weight_prev*map_z_accel_prev + weight_next*map_z_accel )

                roll_10x = ( weight_prev*map_roll_prev + weight_next*map_roll )
                pitch_10x = ( weight_prev*map_pitch_prev + weight_next*map_pitch )
                yaw_10x = ( weight_prev*map_yaw_prev + weight_next*map_yaw )

                roll_rate_10x = ( weight_prev*map_roll_rate_prev + weight_next*map_roll_rate  )
                pitch_rate_10x = ( weight_prev*map_pitch_rate_prev + weight_next*map_pitch_rate  )
                yaw_rate_10x = ( weight_prev*map_yaw_rate_prev + weight_next*map_yaw_rate  )

                velocity_10x = ( weight_prev*map_velocity_prev + weight_next*map_velocity )
                distance_10x = ( weight_prev*map_distance_prev + weight_next*map_distance )
                x_10x = ( weight_prev*map_x_prev +  weight_next*map_x)
                y_10x = ( weight_prev*map_y_prev +  weight_next*map_y )

                try:

                    time_map_file.write(f"{  time_10x },")
                    time_map_file.write(f"{mark_number},{mark_type},")

                    time_map_file.write(f"{  round( x_accel_10x , 2 ) },")
                    time_map_file.write(f"{  round( y_accel_10x , 2 )  },")
                    time_map_file.write(f"{  round( z_accel_10x , 2 )  },")

                    time_map_file.write(f"{  round( roll_10x , 2 ) },")
                    time_map_file.write(f"{  round( pitch_10x , 2 )  },")
                    time_map_file.write(f"{  round( -yaw_10x , 2 )  },")

                    time_map_file.write(f"{  round( roll_rate_10x , 2 ) },")
                    time_map_file.write(f"{  round( pitch_rate_10x , 2 )  },")
                    time_map_file.write(f"{  round( yaw_rate_10x , 2 )  },")

                    time_map_file.write(f"{  round( velocity_10x , 2 )  },")
                    time_map_file.write(f"{  round( distance_10x  , 2 )  },")
                    time_map_file.write(f"{  round( x_10x  , 2 ) },")
                    time_map_file.write(f"{  round( y_10x  , 2 ) }\r")
                except: pass

                map_times_10x.append( time_10x )

                map_x_accels_10x.append( x_accel_10x )
                map_y_accels_10x.append( y_accel_10x )
                map_z_accels_10x.append( z_accel_10x )

                map_rolls_10x.append( roll_10x )
                map_pitches_10x.append( pitch_10x )
                map_yaws_10x.append( yaw_10x )

                map_roll_rates_10x.append( roll_rate_10x )
                map_pitch_rates_10x.append( pitch_rate_10x )
                map_yaw_rates_10x.append( yaw_rate_10x )

                map_velocities_10x.append( velocity_10x )
                map_distances_10x.append( distance_10x )
                map_xs_10x.append( x_10x )
                map_ys_10x.append( y_10x  )
                map_marks_10x.append( mark_number )
                map_states_10x.append( mark_type )

            map_time_prev = map_time

            map_x_accel_prev = map_x_accel
            map_y_accel_prev = map_y_accel
            map_z_accel_prev = map_z_accel

            map_roll_prev = map_roll
            map_pitch_prev = map_pitch
            map_yaw_prev = map_yaw

            map_roll_rate_prev = map_roll_rate
            map_pitch_rate_prev = map_pitch_rate
            map_yaw_rate_prev = map_yaw_rate

            map_velocity_prev = map_velocity
            map_distance_prev = map_distance
            map_x_prev = map_x
            map_y_prev = map_y

#########################################################
#
#  pass 8 compute and write distance map
#
#########################################################

    try:

        distance_map_file.write(f"distance,")
        distance_map_file.write(f"time,")
        distance_map_file.write(f"timing_mark_number,")
        distance_map_file.write(f"timing_mark_type,")


        distance_map_file.write(f"x_force,")
        distance_map_file.write(f"y_force,")
        distance_map_file.write(f"z_force,")

        distance_map_file.write(f"roll,")
        distance_map_file.write(f"pitch,")
        distance_map_file.write(f" -yaw,")

        distance_map_file.write(f"roll_rate,")
        distance_map_file.write(f"pitch_rate,")
        distance_map_file.write(f"yaw_rate,")

        distance_map_file.write(f"velocity,")
        distance_map_file.write(f"x,")
        distance_map_file.write(f"y\r")
    except:
        pass

    map_time_sum = 0

    map_x_accel_sum = 0
    map_y_accel_sum = 0
    map_z_accel_sum = 0

    map_roll_sum = 0
    map_pitch_sum = 0
    map_yaw_sum = 0

    map_roll_rate_sum = 0
    map_pitch_rate_sum = 0
    map_yaw_rate_sum = 0

    map_velocity_sum = 0
    map_distance_sum = 0
    map_x_sum = 0
    map_y_sum = 0

    N = 0
    distance_out = 0.2
    for line_number in map_lines_10x:
        time_10x  = map_times_10x[line_number]

        x_accel_10x = map_x_accels_10x[line_number]
        y_accel_10x = map_y_accels_10x[line_number]
        z_accel_10x = map_z_accels_10x[line_number]

        roll_10x  = map_rolls_10x[line_number]
        pitch_10x  = map_pitches_10x[line_number]
        yaw_10x  = map_yaws_10x[line_number]

        roll_rate_10x  = map_roll_rates_10x[line_number]
        pitch_rate_10x  = map_pitch_rates_10x[line_number]
        yaw_rate_10x  = map_yaw_rates_10x[line_number]

        velocity_10x  = map_velocities_10x[line_number]
        distance_10x  = map_distances_10x[line_number]
        x_10x  = map_xs_10x[line_number]
        y_10x  = map_ys_10x[line_number]

        mark_number  = map_marks_10x[line_number]
        mark_type  = map_states_10x[line_number]
        N = N + 1

        map_time_sum = map_time_sum + time_10x

        map_x_accel_sum = map_x_accel_sum + x_accel_10x
        map_y_accel_sum = map_y_accel_sum + y_accel_10x
        map_z_accel_sum = map_z_accel_sum + z_accel_10x

        map_roll_sum = map_roll_sum + roll_10x
        map_pitch_sum = map_pitch_sum + pitch_10x
        map_yaw_sum = map_yaw_sum + yaw_10x

        map_roll_rate_sum = map_roll_rate_sum + roll_rate_10x
        map_pitch_rate_sum = map_pitch_rate_sum + pitch_rate_10x
        map_yaw_rate_sum = map_yaw_rate_sum + yaw_rate_10x


        map_velocity_sum = map_velocity_sum + velocity_10x
        map_x_sum = map_x_sum + x_10x
        map_y_sum = map_y_sum + y_10x

        if ( distance_10x > distance_out ) and ( N > 0):
            try:
                distance_map_file.write(f"{ round( distance_out , 1 ) },")
                distance_map_file.write(f"{(round( ( map_time_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{ mark_number },")
                distance_map_file.write(f"{ mark_type },")

                distance_map_file.write(f"{(round( ( map_x_accel_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( map_y_accel_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( map_z_accel_sum / N ) , 2 ) ) },")

                distance_map_file.write(f"{(round( ( map_roll_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( map_pitch_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( -map_yaw_sum / N ) , 2 ) ) },")

                distance_map_file.write(f"{(round( ( map_roll_rate_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( map_pitch_rate_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( map_yaw_rate_sum / N ) , 2 ) ) },")

                distance_map_file.write(f"{(round( ( map_velocity_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( map_x_sum / N ) , 2 ) ) },")
                distance_map_file.write(f"{(round( ( map_y_sum / N ) , 2 ) ) }\r")
            except:
                pass
            distance_out = distance_out + 0.2

            map_time_sum = 0

            map_x_accel_sum = 0
            map_y_accel_sum = 0
            map_z_accel_sum = 0

            map_roll_sum = 0
            map_pitch_sum = 0
            map_yaw_sum = 0

            map_roll_rate_sum = 0
            map_pitch_rate_sum = 0
            map_yaw_rate_sum = 0

            map_velocity_sum = 0
            map_distance_sum = 0
            map_x_sum = 0
            map_y_sum = 0
            N = 0
    try:
        rabbit_log_file.write(f" {run_time}\n")
    except:
        pass

def build_arg_parser():
    parser = argparse.ArgumentParser(
        prog='map.py',
        description='adjusts for misalignment, computes speed, gyro rates and generates map')
    parser.add_argument('-f', '--filename', help="base name of files")
    parser.add_argument('-y', '--yaw_offset', help="yaw alignment offset of wolf-pac with respect to sled")
    parser.add_argument('-p', '--pitch_offset', help="pitch alignment offset of wolf-pac with respect to sled")
    parser.add_argument('-r', '--roll_offset', help="roll alignment offset of wolf-pac with respect to sled")
    parser.add_argument('-cr', '--rotation', help="map compass orientation rotation")
    parser.add_argument('-s', '--start', help="time in seconds with respect to first data point to start drawing map")
    parser.add_argument('-e', '--elapsed', help="time window in seconds for the map")
    parser.add_argument('-yd', '--yaw_drift', help="yaw gyro drift, deg/min")
    parser.add_argument('-pd', '--pitch_drift', help="pitch gyro drift, deg/min")
    parser.add_argument('-rd', '--roll_drift', help="roll gyro drift, deg/min")
    parser.add_argument('-pz', '--pitch_at_zero', help="actual pitch of the sled at the first data point, degrees")
    parser.add_argument('-rz', '--roll_at_zero', help="actual roll of the sled at the first data point, degrees")
    parser.add_argument('-ct', '--centrifuge_testing', action='store_true', help="centrifuge testing option")
    parser.add_argument('-nk', '--no_kalman', action='store_true', help="turn off kalman filter")
    parser.add_argument('-kg', '--kalman_gain', help="kalman corner gain, default is 1.4")
    parser.add_argument('-nw', '--no_weights', action='store_true',
                        help="no weights: option to use equal weighting to estimate alignment and drift")
    parser.add_argument('-mf', '--track_marks_file_name', help="name of file with marks model of the track")
    parser.add_argument('-all', '--all_files', action='store_true', help="generate all files types")
    parser.add_argument('-bill', '--bill', action='store_true', help="bill's preferred selection")
    parser.add_argument('-bruce', '--bruce', action='store_true', help="bruce's preferred selection")
    parser.add_argument('-yrs', '--yrs', action='store_true', help="use yaw rate for slicing into plotlets.")
    parser.add_argument('-curves', '--curves', help="expected number of curves.")
    parser.add_argument('-zfl', '--zfl', help="z force lower limit, f/s/s.")
    parser.add_argument('-strmlt', '--strmlt', action='store_true', help="preparation for streamlit plotting.")
    parser.add_argument('-log_time', '--log_time', action='store_true', help="log key times during data processing.")
    parser.add_argument('-yaw_min', '--yaw_min', help="minimum change in yaw to detect end of curve.")
    parser.add_argument('-fcn', '--fcn', help="not used, but must be allowed.")
    parser.add_argument('-skip', '--skip', help="not used, but must be allowed.")
    parser.add_argument('-fhs', '--fhs', help="filter half size, window width = 2*fhs+1.")
    return parser


def run_script_from_server(params, input_path, output_paths):
    global args, file_name, file_base_name, number_of_marks, start, elapsed
    global input_file, summary_log_file, output_file, time_map_100_file, log_file
    file_name = params["-f"]
    file_base_name = file_name.split('.')[0]
    number_of_marks = int(2 * int(params["-curves"]))

    # Set up files
    input_file = open(input_path, 'r')
    output_file = open(output_paths[0], "w")         # _adjusted.txt
    summary_log_file = io.StringIO("")               # _summary_log.txt
    time_map_100_file = open(output_paths[1], "w")   # _time_map_100_HZ.csv
    log_file = open(output_paths[2], "w")            # _log.txt

    flat_arg_list = []
    for key, value in params.items():
        flat_arg_list.extend([key, str(value)])
    args = build_arg_parser().parse_args(flat_arg_list)

    start = float(args.start)
    elapsed = float(args.elapsed)

    write_summary_header()
    run_passes()

    input_file.close()
    output_file.close()
    summary_log_file.close()
    time_map_100_file.close()
    log_file.close()




# Set up a processing script subclass wrapper for running from within the Luge server
try:
    from luge.scripts import script_base

    class MapStScript(script_base.ScriptBase):
        OUTPUT_FILE_SUFFIX = ["_adjusted.txt", "_time_map_100_HZ.csv", "_log.txt"]

        def __init__(self, run):
            super().__init__(run)
            self.params = None
            self.valid_run = None

        def set_params(self, params):
            self.params = params

        def run_script(self):
            run_script_from_server(self.params, self.run.get_data_file_path(), self.get_output_file_paths())
            self.valid_run = valid_run

except ImportError:
    MapStScript = None


# Run from command line
if __name__ == "__main__":
    parser = build_arg_parser()
    args = parser.parse_args()
    if args.filename:
        file_name = args.filename
        file_base_name = file_name.split('.')[0]
    else:
        print("you need to supply a file name")
        exit()

    if args.fhs:
        filter_size = int(args.fhs)

    if args.yaw_min:
        yaw_threshold = float(args.yaw_min)

    if args.log_time:
        time_log = open("time_log.txt", "a")
        now = datetime.now()
        time = now.time()
        time_log.write(f"map.py, starting to process {file_name} , time = {time}.\n")

    if args.zfl:
        z_force_plot_limit = float(args.zfl)

    if args.yaw_offset:
        yaw_offset = float(args.yaw_offset)
    if args.pitch_offset:
        pitch_offset = float(args.pitch_offset)
    if args.roll_offset:
        roll_offset = float(args.roll_offset)
    if args.rotation:
        rotation = float(args.rotation)
    if args.start:
        start = float(args.start)
    if args.elapsed:
        elapsed = float(args.elapsed)
    if args.yaw_drift:
        yaw_drift = float(args.yaw_drift)
    if args.pitch_drift:
        pitch_drift = float(args.pitch_drift)
    if args.roll_drift:
        roll_drift = float(args.roll_drift)
    if args.pitch_at_zero:
        pitch_zero = float(args.pitch_at_zero)
    if args.roll_at_zero:
        roll_zero = float(args.roll_at_zero)
    if args.no_kalman:
        max_err = 100.0
    if args.kalman_gain:
        corner_w = float(args.kalman_gain)
    if args.curves:
        number_of_marks = int(2 * int(args.curves))
    # try:
    # summary_log_file = open("summary_log.txt" , "r" )
    # summary_log_file.close()
    # summary_log_file = open("summary_log.txt" , "a" )
    # except:
    summary_log_file = open("summary_log.txt", "w")
    write_summary_header()

    try:
        input_file = open(file_name)
        summary_log_file.write(f"{pad_14(file_base_name)},")
        if start < 30.0:
            summary_log_file.write(f">>>> start time = {start} is too short <<<<< \n")
    except:
        summary_log_file.write(f"unable to open file {file_name} , file was skipped.\n")
        exit()

    if args.all_files:
        skip_pass_7_and_8 = False
        rabbit_log_file = open("rabbit_log.txt", "a")
        rabbit_log_file.write(f"{file_base_name},")

        debug_marks_file = open(file_base_name + "_debug_marks.csv", "w")
        debug_marks_file.write(
            f"mark_number,roll_is_small,opposite_roll_n_rate,valid_roll_peak,minimum_yaw,,roll,yaw,,,minimum yaw = {yaw_threshold}\n")

        variance_file = open(file_base_name + "_variance.csv", "w")
        output_file = open(file_base_name + "_adjusted.txt", "w")
        compare_file = open(file_base_name + "_compare.csv", "w")
        debug_file = open(file_base_name + "_debug.csv", "w")
        time_map_file = open(file_base_name + "_time_map_1000_HZ.csv", "w")
        time_map_100_file = open(file_base_name + "_time_map_100_HZ.csv", "w")
        distance_map_file = open(file_base_name + "_distance_map.csv", "w")
        marks_file = open(file_base_name + "_timing_marks.csv", "w")
        if args.no_weights:
            log_file = open(file_base_name + "_log_no_weights.txt", "w")
        else:
            log_file = open(file_base_name + "_log.txt", "w")
    elif args.bruce:
        skip_pass_7_and_8 = False       
        time_map_100_file = open(file_base_name + "_time_map_100_HZ.csv", "w")
        time_map_file = open(file_base_name + "_time_map_1000_HZ.csv", "w")
        output_file = open(file_base_name + "_adjusted.txt", "w")
        # marks_file = open(file_base_name+".timing_marks.csv" , "w")
        if args.no_weights:
            log_file = open(file_base_name + "_log_no_weights.txt", "w")
        else:
            log_file = open(file_base_name + "_log.txt", "w")
    elif args.bill:
        time_map_100_file = open(file_base_name + "_time_map_100_HZ.csv", "w")
        #time_map_file = open(file_base_name + "_time_map_1000_HZ.csv", "w")
        marks_file = open(file_base_name + ".timing_marks.csv", "w")
        if args.no_weights:
            log_file = open(file_base_name + "_log_no_weights.txt", "w")
        else:
            log_file = open(file_base_name + "_log.txt", "w")
    else:
        output_file = open(file_base_name + "_adjusted.txt", "w")
        time_map_100_file = open(file_base_name + "_time_map_100_HZ.csv", "w")
        if args.no_weights:
            log_file = open(file_base_name + "_log_no_weights.txt", "w")
        else:
            log_file = open(file_base_name + "_log.txt", "w")

    if args.track_marks_file_name:
        track_marks_file_name = args.track_marks_file_name
        try:
            track_marks_file = open(track_marks_file_name)
            try:
                log_file.write(f"File of track curve markers, {track_marks_file_name}, was opened.\r")
            except:
                pass
            read_markers(track_marks_file)
        except:
            try:
                log_file.write(f"File of track curve markers, {track_marks_file_name}, was not found.\r")
            except:
                pass
            pass

    run_passes()
