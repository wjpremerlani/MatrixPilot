import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime
import argparse

def cross_t(a,b):
    return np.transpose(np.cross(np.transpose(a),np.transpose(b)))

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

def run_test():
    plot_file = open("plot_file.csv","w")
    plot_file.write(f"time_secs , rotation_increment_radians , reported_force_ft/sec/sec, x_velocity_ft/sec , y_velocity_ft/sec , velocity_magnitude_ft/sec \n")
    plot_file.write(f"0,0,0\n")
    force_vector = np.zeros((3,1))
    acceleration = np.zeros((3,1))
    velocity = np.zeros((3,1))
    orientation = np.zeros((3,3))
    angle = np.zeros((3,1))
    orientation[0,0]= 1.0
    orientation[1,1]= 1.0
    orientation[2,2]= 1.0

    plot_counter = 0
    
    for step_no in range(1000000):
        time = float(step_no+1)*0.01
        phi = 0.0001*time - ((0.0001)*(0.0001))/200.0
        force =  (time*time/100.0 - (0.0001)*time + 0.0001 )
        force_vector[0,0] = 1.0
        force_vector[1,0] = force
        angle[2,0] = phi
        update_mat = phi_to_matrix(angle)
        integral_mat = matrix_to_matrix_integral(update_mat)
        acceleration = np.matmul(orientation,np.matmul(integral_mat,force_vector))
        velocity[0,0] = velocity[0,0] + 0.01* acceleration[0,0]
        velocity[1,0] = velocity[1,0] + 0.01* acceleration[1,0]
        velocity[2,0] = velocity[2,0] + 0.01* acceleration[2,0]
        vel_mag = sqrt( np.vdot( velocity , velocity ))
        
        orientation = np.matmul(orientation,update_mat)

        if plot_counter == 0 :       
            plot_file.write(f"{round(time,2)},{round(phi,8)},{round(force,2)},{round(velocity[0,0],2)},{round(velocity[1,0],2)},{round(vel_mag,2)}\n")
        plot_counter = plot_counter + 1
        if plot_counter == 100 :
            plot_counter = 0
        
    

def build_arg_parser():
    parser = argparse.ArgumentParser(
        prog='simulation.py',
        description='tests matrix math routines')
    return parser

if __name__ == "__main__":
    parser = build_arg_parser()
    run_test()
