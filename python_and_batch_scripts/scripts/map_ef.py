import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime
import argparse

global use_drift
use_drift = False

def cross_t(a,b):
    return np.transpose(np.cross(np.transpose(a),np.transpose(b)))

global y_mat , p_mat , r_mat
y_mat = np.zeros((3,3))
p_mat = np.zeros((3,3))
r_mat = np.zeros((3,3))

global yaw_offset , pitch_offset , roll_offset
yaw_offset = 0.0
pitch_offset = 0.0
roll_offset = 0.0

global yaw_offset_a , pitch_offset_a , roll_offset_a
yaw_offset_a = 0.0
pitch_offset_a = 0.0
roll_offset_a = 0.0

global yaw_bias , pitch_bias , roll_bias
yaw_bias = 0.0 
pitch_bias = 0.0
roll_bias = 0.0

global yaw_bias_a , pitch_bias_a , roll_bias_a
yaw_bias_a = 0.0 
pitch_bias_a = 0.0
roll_bias_a = 0.0

global yaw_drift , pitch_drift , roll_drift
yaw_drift = 0.0 
pitch_drift = 0.0
roll_drift = 0.0

global yaw_drift_a , pitch_drift_a , roll_drift_a
yaw_drift_a = 0.0 
pitch_drift_a = 0.0
roll_drift_a = 0.0

global cross_coupling
cross_coupling = 0.0

global acc_cal_x , acc_cal_y , acc_cal_z
acc_cal_x = 1.0
acc_cal_y = 1.0
acc_cal_z = 1.0

global acc_off_x , acc_off_y , acc_off_z
global acc_off_x_a , acc_off_y_a , acc_off_z_a

acc_off_x = 0.0
acc_off_y = 0.0
acc_off_z = 0.0

acc_off_x_a = 0.0
acc_off_y_a = 0.0
acc_off_z_a = 0.0

global gyro_cal_x , gyro_cal_y , gyro_cal_z
gyro_cal_x = 1.0
gyro_cal_y = 1.0
gyro_cal_z = 1.0


global column_suffix
column_suffix = "_truth"

global use_gravity
use_gravity = True

def extract_euler(input_matrix) :
    yaw_angle = degrees((atan2(input_matrix[1,0],input_matrix[0,0])))
    pitch_angle = degrees((atan2(-input_matrix[2,0], sqrt((input_matrix[2,1])**2+(input_matrix[2,2])**2))))
    roll_angle = degrees((atan2(input_matrix[2,1],input_matrix[2,2])))
    euler_angles = [ yaw_angle , pitch_angle , roll_angle ]
    return euler_angles

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
    return ypr_mat

def f1(phi_sqr):
    result = 1.0 - phi_sqr/6.0 + phi_sqr*phi_sqr/120.0 - phi_sqr*phi_sqr*phi_sqr/5040.0
    return result

def f2(phi_sqr):
    result = 0.5 -phi_sqr/24.0 + phi_sqr*phi_sqr/720.0 - phi_sqr*phi_sqr*phi_sqr/40320.0
    return result

def f3(phi_sqr):
    result = 1.0/6.0 - phi_sqr/120.0 + phi_sqr*phi_sqr/5040.0 - phi_sqr*phi_sqr*phi_sqr/362880.0
    return result

def matrix_to_matrix_integral(matrix):
    angle_axis = matrix_to_phi(matrix)
    mat_integral = phi_to_matrix_integral(angle_axis)
    return mat_integral

def phi_to_matrix_integral(phi) :
    result = np.zeros((3,3))
    
    phi_sqr = np.vdot(phi,phi)
    f2_value = f2(phi_sqr)
    f3_value = f3(phi_sqr)
    
    result[0,0] = 1.0  + f3_value*(phi[0,0]*phi[0,0]-phi_sqr)
    result[0,1] = -f2_value*phi[2,0] + f3_value*(phi[0,0]*phi[1,0])
    result[0,2] = f2_value*phi[1,0] + f3_value*(phi[0,0]*phi[2,0])

    result[1,1] = 1.0  + f3_value*(phi[1,0]*phi[1,0]-phi_sqr)
    result[1,2] = -f2_value*phi[0,0] + f3_value*(phi[1,0]*phi[2,0])
    result[1,0] = f2_value*phi[2,0] + f3_value*(phi[1,0]*phi[0,0])

    result[2,2] = 1.0  + f3_value*(phi[2,0]*phi[2,0]-phi_sqr)
    result[2,0] = -f2_value*phi[1,0] + f3_value*(phi[2,0]*phi[0,0])
    result[2,1] = f2_value*phi[0,0] + f3_value*(phi[2,0]*phi[1,0])

    return result

def phi_to_matrix(phi) :
    result = np.zeros((3,3))
    
    phi_sqr = np.vdot(phi,phi)
    f1_value = f1(phi_sqr)
    f2_value = f2(phi_sqr)
    
    result[0,0] = 1.0  + f2_value*(phi[0,0]*phi[0,0]-phi_sqr)
    result[0,1] = -f1_value*phi[2,0] + f2_value*(phi[0,0]*phi[1,0])
    result[0,2] = f1_value*phi[1,0] + f2_value*(phi[0,0]*phi[2,0])

    result[1,1] = 1.0  + f2_value*(phi[1,0]*phi[1,0]-phi_sqr)
    result[1,2] = -f1_value*phi[0,0] + f2_value*(phi[1,0]*phi[2,0])
    result[1,0] = f1_value*phi[2,0] + f2_value*(phi[1,0]*phi[0,0])

    result[2,2] = 1.0  + f2_value*(phi[2,0]*phi[2,0]-phi_sqr)
    result[2,0] = -f1_value*phi[1,0] + f2_value*(phi[2,0]*phi[0,0])
    result[2,1] = f1_value*phi[0,0] + f2_value*(phi[2,0]*phi[1,0])

    return result

def matrix_to_phi(matrix) :
    result = np.zeros((3,1))
    f1_phi = np.zeros((3,1))
    f1_phi[0,0] = ( matrix[2,1] - matrix[1,2] )/2.0
    f1_phi[1,0] = ( matrix[0,2] - matrix[2,0] )/2.0
    f1_phi[2,0] = ( matrix[1,0] - matrix[0,1] )/2.0
    sin_phi = sqrt(np.vdot(f1_phi,f1_phi))
    cos_phi = (np.trace(matrix)-1.0)/2.0
    phi = np.arctan2(sin_phi,cos_phi)
    f1_val = f1 ( phi*phi )
    result[0,0] = (f1_phi[0,0]/f1_val)
    result[1,0] = (f1_phi[1,0]/f1_val)
    result[2,0] = (f1_phi[2,0]/f1_val)        
    return result

def mat_x_vec(amat,avec):
    aresult = np.zeros((3,3))
    for aindex in range(3) :
        vec2 = np.transpose(amat[:,aindex])
        rcol = np.transpose(np.cross(vec2,np.transpose(avec)))
        aresult[:,aindex]= rcol[:,0]
    return aresult

def vec_x_mat(avec,amat):
    aresult = np.zeros((3,3))
    for aindex in range(3) :
        vec2 = np.transpose(amat[:,aindex])
        rcol = np.transpose(np.cross(np.transpose(avec),vec2))
        aresult[:,aindex]=rcol[:,0]
    return aresult

def write_matrix(matrix_values):
    for column in range(3):
        for row in range(3):
            output_file.write(f"{round(matrix_values[row,column],3)},")

def write_column_names(data_file , column_names , suffix ):
    for column_name in column_names :
        data_file.write(f"{column_name}{suffix},")

def write_columns(data_file , column_values ) :
    for value in column_values :
        data_file.write(f"{round(value,4)},")

global output_file , suffix
global labels_have_been_written
global log_file
labels_have_been_written = False
def run_test():
    global body_forces , input_matrices
    global output_file , suffix , column_suffix
    global labels_have_been_written
    global args
    
    global yaw_offset , pitch_offset , roll_offset
    global yaw_bias , pitch_bias , roll_bias
    global yaw_drift , pitch_drift , roll_drift
    
    global yaw_offset_a , pitch_offset_a , roll_offset_a
    global yaw_bias_a , pitch_bias_a , roll_bias_a
    global yaw_drift_a , pitch_drift_a , roll_drift_a
    global use_drift , log_file
    global acc_off_x , acc_off_y , acc_off_z
    global acc_off_x , acc_off_y , acc_off_z
    global acc_off_x_a , acc_off_y_a , acc_off_z_a

    file_name_parts = file_name.split('.')
    file_base_name = file_name_parts[0]

    bias_file = open("bias\\"+file_base_name+"_gyro_bias.txt", 'r')

    bias_data = bias_file.read()
    bias_line = bias_data.splitlines(keepends=False)
    bias_columns = bias_line[0].split(',')
    
    yaw_bias = float(bias_columns[0])
    pitch_bias = float(bias_columns[1])
    roll_bias = float(bias_columns[2])
    print()
    print()
    print()
    print("yaw, pitch and roll bias = " , yaw_bias , pitch_bias , roll_bias )
    print()
    print()
    print()


    log_file = open("output\\"+file_name+".log.txt","w")

    log_file.write(f"\n\nFirst pass\n\n")

                    
    orientation = input_matrices[0]
    previous_raw_mat = np.copy(orientation)
    
    
    drift_angle = np.zeros((3,1))
    drift_angle[0] = roll_bias
    drift_angle[1] = pitch_bias
    drift_angle[2] = yaw_bias
    
    drift_angle = np.multiply(drift_angle , 1.0/6000.0)

    print("original orientation = " , input_matrices[0] )
    print("adjusted orientation = " , orientation )
    print("drift_angle = " , drift_angle )

    previous_adj_mat = orientation
    velocity = np.zeros((3,1))

    labels_have_been_written = False

    energy = 0.0

    previous_vmag = 0

    plot_counter = 0

    force_vector = np.zeros((3,1))
    acceleration = np.zeros((3,1))
    velocity = np.zeros((3,1))
    velocity_dot = np.zeros((3,1))
    angle = np.zeros((3,1))
    f3_ef =  np.zeros((3,1))
    
 
    N = 0
    

    gravity = np.zeros((3,1))
    if use_gravity :
        gravity[2,0] = 32.174
    W = np.zeros((3,1))

    error_int_x = 0.
    error_int_y = 0.
    error_int_z = 0.
    
    sum_ysqr = 0

    sum_h_error = 0.

    previous_vmag = 0

    energy = 0.0

    FS = np.zeros((3,1))
    
    for step_no in range(len(body_forces)):

        N = N + 1
        
        time = float(step_no+1)*0.01
        
        drift_angle[0] = roll_bias 
        drift_angle[1] = pitch_bias 
        drift_angle[2] = yaw_bias 
    
        drift_angle = np.multiply(drift_angle , 1.0/6000.0)

        force_vector = body_forces[step_no]
        raw_mat = input_matrices[step_no]
        update_mat = np.matmul(np.transpose(previous_raw_mat),raw_mat)
        previous_raw_mat = raw_mat
        update_angles = matrix_to_phi(update_mat)
        update_angles = update_angles - drift_angle
        update_mat = phi_to_matrix(update_angles)
        rmat = np.matmul( previous_adj_mat, update_mat )
        previous_adj_mat = rmat 
        integral_mat = matrix_to_matrix_integral(update_mat)
        rotation_angle_bf = matrix_to_phi(update_mat)
        rotation_angle_ef = np.matmul(rmat,rotation_angle_bf)
        acceleration = np.matmul(rmat,np.matmul(integral_mat,force_vector))
        #velocity_dot = acceleration
        velocity_dot = np.copy(acceleration)
        velocity_dot[2,0] = velocity_dot[2,0]+32.174 
        velocity = velocity + np.multiply ( velocity_dot , 0.01 )
        velocity_bf = np.matmul(np.transpose(rmat),velocity)
        vel_mag_bf = sqrt(np.vdot(velocity_bf,velocity_bf))
        power = np.vdot(velocity,velocity_dot) - velocity[2,0]*( 32.174 ) 
        energy = energy + power*0.01
        vel_mag = sqrt(np.vdot(velocity,velocity))     
        dvdt = 100.0 * ( vel_mag - previous_vmag )
        previous_vmag = vel_mag 
        acc_mag = sqrt(np.vdot(acceleration,acceleration))

        W = np.multiply(rotation_angle_ef , 100.0)

        FS = FS + np.multiply(acceleration,0.01)
   
        if labels_have_been_written == False :
            if False :
                column_names = [ "acc_x" ,"acc_y" , "acc_z" ,  "acc_mag" ]
            if False :
                column_names = [  "acc_x" ,"acc_y" , "acc_z" ,  "acc_mag" , "vx" , "vy" , "vz" , "vmag" ]
            if True :
                column_names = [ "FS0" , "FS1" , "FS2" , "Vz" , "AccZ" , "energy","vx_b" , "vy_b" , "vz_b" ,  "vmag_b" , "vx_e" , "vy_e" , "vz_e" , "vmag_e" ]
            write_column_names(output_file , column_names , "_raw" )
            output_file.write(f"\n")
            labels_have_been_written = True

        if False :
            column_values = [ acceleration[0,0] ,acceleration[1,0] ,acceleration[2,0] , acc_mag ]
        if False :
            column_values = [ acceleration[0,0] ,acceleration[1,0] ,acceleration[2,0] , acc_mag , velocity[0,0] , velocity[1,0] , velocity[2,0] , vel_mag ]      
        if True :
            column_values = [ FS[0,0] ,FS[1,0] , FS[2,0] , velocity[2,0] , acceleration[2,0] , energy, velocity_bf[0,0] , velocity_bf[1,0] , velocity_bf[2,0] , vel_mag_bf ,velocity[0,0] , velocity[1,0] , velocity[2,0] , vel_mag ]      
        
        write_columns(output_file , column_values )
        output_file.write(f"\n")

        
    if time > 0 :
        dvdtx = velocity[0,0]/time
        dvdty = velocity[1,0]/time
        dvdtz = velocity[2,0]/time

    else :
        dvdtx = 0.0
        dvdty = 0.0
        dvdtz = 0.0

    log_file.write(f"\n\ndvtx, dvdty, dvdtz = {dvdtx},{dvdty},{dvdtz}\n\n\n")
        
            
    orientation = input_matrices[0]
    previous_raw_mat = orientation
    
   
    log_file.write(f"\n\nSecond pass\n\n")

   
    
    drift_angle = np.zeros((3,1))
    drift_angle[0] = roll_bias
    drift_angle[1] = pitch_bias
    drift_angle[2] = yaw_bias

    log_file.write(f"drift bias angle, radians per minute = {drift_angle}\n")

    
    drift_angle = np.multiply(drift_angle , 1.0/6000.0)

    print("original orientation = " , input_matrices[0] )
    print("adjusted orientation = " , orientation )
    print("drift_angle = " , drift_angle )

    
    previous_adj_mat = orientation
    velocity = np.zeros((3,1))

    labels_have_been_written = False

    energy = 0.0

    previous_vmag = 0
    
    for step_no in range(len(body_forces)):

        N = N + 1
        
        time = float(step_no+1)*0.01

        drift_angle[0] = roll_bias 
        drift_angle[1] = pitch_bias
        drift_angle[2] = yaw_bias 

    
        drift_angle = np.multiply(drift_angle , 1.0/6000.0)

        force_vector = body_forces[step_no]
        raw_mat = input_matrices[step_no]
        update_mat = np.matmul(np.transpose(previous_raw_mat),raw_mat)
        previous_raw_mat = raw_mat
        update_angles = matrix_to_phi(update_mat)
        update_angles = update_angles - drift_angle
        update_mat = phi_to_matrix(update_angles)
        rmat = np.matmul( previous_adj_mat, update_mat )
        previous_adj_mat = rmat 
        integral_mat = matrix_to_matrix_integral(update_mat)
        rotation_angle_bf = matrix_to_phi(update_mat)
        rotation_angle_ef = np.matmul(rmat,rotation_angle_bf)
        acceleration = np.matmul(rmat,np.matmul(integral_mat,force_vector))
        #velocity_dot = acceleration
        velocity_dot = np.copy(acceleration)

        
        velocity_dot[0,0] = velocity_dot[0,0] - dvdtx
        velocity_dot[1,0] = velocity_dot[1,0] - dvdty
        velocity_dot[2,0] = velocity_dot[2,0] + 32.174
        
        velocity = velocity + np.multiply ( velocity_dot , 0.01 )
        velocity_bf = np.matmul(np.transpose(rmat),velocity)
        vel_mag_bf = sqrt(np.vdot(velocity_bf,velocity_bf))
        power = np.vdot(velocity,velocity_dot) - velocity[2,0]*( 32.174 ) 
        energy = energy + power*0.01
        vel_mag = sqrt(np.vdot(velocity,velocity))     
        #vel_mag = sqrt(velocity[0,0]*velocity[0,0]+velocity[1,0]*velocity[1,0])
        dvdt = 100.0 * ( vel_mag - previous_vmag )
        previous_vmag = vel_mag 
        acc_mag = sqrt(np.vdot(acceleration,acceleration))
        if labels_have_been_written == False :
            if False :
                column_names = [ "acc_x" ,"acc_y" , "acc_z" ,  "acc_mag" ]
            if False :
                column_names = [ "energy" , "dvdt" ,"acc_x" ,"acc_y" , "acc_z" ,  "acc_mag" , "vx" , "vy" , "vz" , "vmag" ]
            if True :
                column_names = [ "energy" , "vx_b" , "vy_b" , "vz_b" ,  "vmag_b" , "vx_e" , "vy_e" , "vz_e" , "vmag_e" ]
            write_column_names(adjusted_file , column_names , "_adj" )
            adjusted_file.write(f"\n")
            labels_have_been_written = True

        if False :
            column_values = [ acceleration[0,0] ,acceleration[1,0] ,acceleration[2,0] , acc_mag ]
        if False :
            column_values = [ energy , dvdt, acceleration[0,0] ,acceleration[1,0] ,acceleration[2,0] , acc_mag , velocity[0,0] , velocity[1,0] , velocity[2,0] , vel_mag ]      
        if True :
            column_values = [ energy , velocity_bf[0,0] , velocity_bf[1,0] , velocity_bf[2,0] , vel_mag_bf ,velocity[0,0] , velocity[1,0] , velocity[2,0] , vel_mag ]      
        
        write_columns(adjusted_file , column_values )
        adjusted_file.write(f"\n")

                  
    
global args
def build_arg_parser():
    global args
    parser = argparse.ArgumentParser(
        prog='simulation.py',
        description='tests matrix math routines')
    parser.add_argument('-b', '--base', action='store_true', help="normal")
    parser.add_argument('-adjust', '--adjust', action='store_true', help="apply adjustments")

    parser.add_argument('-yo ', '--yo',  help="yaw offset, radians")
    parser.add_argument('-po ', '--po',  help="pitch offset, radians")
    parser.add_argument('-ro ', '--ro',  help="roll offset, radians")

    parser.add_argument('-yb ', '--yb',  help="yaw bias, radians per minute")
    parser.add_argument('-pb ', '--pb',  help="pitch bias, radians per minute")
    parser.add_argument('-rb ', '--rb',  help="roll offset, radians per minute")

    parser.add_argument('-yd ', '--yd',  help="yaw drift, radians per minute per minute")
    parser.add_argument('-pd ', '--pd',  help="pitch drift, radians per minute per minute")
    parser.add_argument('-rd ', '--rd',  help="roll drift, radians per minute per minute")

    parser.add_argument('-cs ', '--cs',  help="column name suffix")
    parser.add_argument('-ng ', '--ng',  help='no gravity', action='store_true')

    parser.add_argument('-cc ', '--cc',  help='cross coupling, radians per minute per g')

    parser.add_argument('-gc_x ', '--gc_x',  help='gyro calibration factor x')
    parser.add_argument('-gc_y ', '--gc_y',  help='gyro calibration factor y')
    parser.add_argument('-gc_z ', '--gc_z',  help='gyro calibration factor z')

    parser.add_argument('-ac_x ', '--ac_x',  help='accel calibration factor x')
    parser.add_argument('-ac_y ', '--ac_y',  help='accel calibration factor y')
    parser.add_argument('-ac_z ', '--ac_z',  help='accel calibration factor z')

    parser.add_argument('-ao_x ', '--ao_x',  help='accelerometer offset, gs, x')
    parser.add_argument('-ao_y ', '--ao_y',  help='accelerometer offset, gs, y')
    parser.add_argument('-ao_z ', '--ao_z',  help='accelerometer offset, gs, z')

    parser.add_argument('-f' , '--f' , help='file to be processed')
    parser.add_argument('-s' , '--s' , help='starting time')  
       
    return parser

NUM_COLS  = 11

XA_COL = 0
YA_COL = 1
ZA_COL = 2
YAW_COL = 3
PITCH_COL = 4
ROLL_COL = 5

global body_forces , input_matrices

body_forces = []
input_matrices = []

def read_data( data_file ) :
    global body_forces , input_matrices
    input_data = data_file.read()
    lines = input_data.splitlines(keepends=False)
    line_number = 0
    for line in lines :
        columns = line.split(',')
        if ( len(columns) == NUM_COLS ) or  ( len(columns) == NUM_COLS +1 ):
            line_number = line_number+1
            if line_number >= starting_line :
                xa_in = float(columns[XA_COL])
                ya_in = float(columns[YA_COL])
                za_in = float(columns[ZA_COL])
                yaw_in = float(columns[YAW_COL])
                pitch_in = float(columns[PITCH_COL])
                roll_in = float(columns[ROLL_COL])
                body_force = np.zeros((3,1))
                body_force[0,0] = xa_in
                body_force[1,0] = ya_in
                body_force[2,0] = za_in
                body_forces.append(body_force)
                input_matrix = create_ypr_matrix(yaw_in,pitch_in,roll_in)
                input_matrices.append(input_matrix)


if __name__ == "__main__":


    parser = build_arg_parser()
    args = parser.parse_args()
    if args.yo:
        yaw_offset = float(args.yo)
    if args.po:
        pitch_offset = float(args.po)
    if args.ro:
        roll_offset = float(args.ro)

    if args.yb:
        yaw_bias = float(args.yb)
    if args.pb:
        pitch_bias = float(args.pb)
    if args.rb:
        roll_bias = float(args.rb)

    if args.yd:
        yaw_drift = float(args.yd)
    if args.pd:
        pitch_drift = float(args.pd)
    if args.rd:
        roll_drift = float(args.rd)

    if args.cs:
        column_suffix = str(args.cs)
    if args.ng:
        use_gravity = False
    if args.cc :
        cross_coupling = float(args.cc)

    if args.gc_x :
        gyro_cal_x = float(args.gc_x)
    if args.gc_y :
        gyro_cal_y = float(args.gc_y)
    if args.gc_z :
        gyro_cal_z = float(args.gc_z)

    if args.ac_x :
        acc_cal_x = float(args.ac_x)
    if args.ac_y :
        acc_cal_y = float(args.ac_y)
    if args.ac_z :
        acc_cal_z = float(args.ac_z)

    if args.ao_x :
        acc_off_x = float(args.ao_x)
    if args.ao_y :
        acc_off_y = float(args.ao_y)
    if args.ao_z :
        acc_off_z = float(args.ao_z)

    if args.f :
        file_name = args.f
        print("file name = " , file_name )
        try :
            input_file = open("runs\\"+file_name,'r')
            output_file = open("output\\"+file_name+".raw.csv",'w')
            adjusted_file = open("output\\"+file_name+".adj.csv",'w')
        except :
            print("either unable to open input file or output file is in use.")
            exit()
    else :
        print("no file was specified")
        exit()
    if args.s :
        starting_line = int(100.0*float(args.s))
        print("starting line = " , starting_line )
    else :
        print("no starting time was specified")
        exit()
    read_data(input_file)
    run_test()
