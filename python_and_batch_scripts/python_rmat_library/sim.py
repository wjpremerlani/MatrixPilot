import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime
import argparse

def cross_t(a,b):
    return np.transpose(np.cross(np.transpose(a),np.transpose(b)))

global y_mat , p_mat , r_mat
y_mat = np.zeros((3,3))
p_mat = np.zeros((3,3))
r_mat = np.zeros((3,3))


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

    plot_file.write(f"h accel mag , h vel mag , h omega mag , h error , h error sum\n")
    #plot_file.write(f"time_secs , w_vx , w_vy, acc_x , acc_y , x_velocity_ft/sec , y_velocity_ft/sec , z_velocity_ft/sec ,velocity_magnitude_ft/sec \n")
    #plot_file.write(f"0,0,0\n")
    force_vector = np.zeros((3,1))
    acceleration = np.zeros((3,1))
    velocity = np.zeros((3,1))
    angle = np.zeros((3,1))

    if False :
    #base case
        offset = create_ypr_matrix(0.0,0.0,0.0)
        use_gravity = False
        orientation = create_ypr_matrix(0,0,0)
        drift_angle = np.zeros((3,1))

    if True :
    #gravity only
        offset = create_ypr_matrix(0.0,0.0,0.0)
        use_gravity = True
        orientation = create_ypr_matrix(0,0,0)
        drift_angle = np.zeros((3,1))

    if False :
    #orientation offset
        offset = create_ypr_matrix(0.0,0.0,0.0)
        use_gravity = False
        orientation = create_ypr_matrix(20.0,40.0,60.0)
        drift_angle = np.zeros((3,1))

    if False :
    #drift
        use_gravity = False
        offset = create_ypr_matrix(0.0,0.0,0.0)
        orientation = create_ypr_matrix(0,0,0)
        drift_angle = np.zeros((3,1))
        drift_angle[0,0] = radians(1.0/6000.0)
        drift_angle[1,0] = radians(2.0/6000.0)
        drift_angle[2,0] = radians(3.0/6000.0)

    if False :
    #drift and gravity
        use_gravity = True
        offset = create_ypr_matrix(0.0,0.0,0.0)
        orientation = create_ypr_matrix(0,0,0)
        drift_angle = np.zeros((3,1))
        drift_angle[0,0] = radians(1.0/6000.0)
        drift_angle[1,0] = radians(2.0/6000.0)
        drift_angle[2,0] = radians(3.0/6000.0)

    if False :
    #everything
        use_gravity = True
        offset = create_ypr_matrix(0.0,0.0,0.0)
        orientation = create_ypr_matrix(0.0,2.0,0.0)
        drift_angle = np.zeros((3,1))
        drift_angle[0,0] = radians(1.0/6000.0)
        drift_angle[1,0] = radians(2.0/6000.0)
        drift_angle[2,0] = radians(3.0/6000.0)

    if False :
    #gravity and offset
        use_gravity = True
        offset = create_ypr_matrix(0.0,2.0,0.0)
        orientation = np.copy ( offset )
        drift_angle = np.zeros((3,1))

    plot_counter = 0

    Y = np.zeros((2,1))
    A = np.zeros((2,2))
    ATA = np.zeros((2,2))
    ATY = np.zeros((2,1))

    error_int_x = 0.
    error_int_y = 0.
    sum_ysqr = 0

    sum_h_error = 0.
    
    for step_no in range(20000):
        time = float(step_no+1)*0.01
        if time < 100.0 :
            phi = 0.0001*time - ((0.0001)*(0.0001))/200.0
            force =  (time*time/100.0 - (0.0001)*time + 0.0001 )
            force_vector[0,0] = 1.0
            force_vector[1,0] = force
            if use_gravity :
                force_vector[2,0] = -32.2
            else :
                force_vector[2,0] = 0.0
        else :
            phi = 0.01
            force_vector[0,0] = 0.0
            force_vector[1,0] = 100.0
            if use_gravity :
                force_vector[2,0] = -32.2
            else :
                force_vector[2,0] = 0.0
        angle[2,0] = phi

        omega = 100.0 * phi
        
        angle_bf = angle + drift_angle
        update_mat = phi_to_matrix(angle_bf)
        integral_mat = matrix_to_matrix_integral(update_mat)
        acceleration = np.matmul(np.transpose(offset),np.matmul(orientation,np.matmul(integral_mat,force_vector)))
        #acceleration = np.matmul(orientation,np.matmul(integral_mat,force_vector))
        velocity[0,0] = velocity[0,0] + 0.01* acceleration[0,0]
        velocity[1,0] = velocity[1,0] + 0.01* acceleration[1,0]
        if use_gravity :
            velocity[2,0] = velocity[2,0] + 0.01* acceleration[2,0]+0.322
        else :
            velocity[2,0] = velocity[2,0] + 0.01* acceleration[2,0]
        vel_mag = sqrt( np.vdot( velocity , velocity ))
        force_mag = sqrt( np.vdot( force_vector , force_vector ))
        
        orientation = np.matmul(orientation,update_mat)

        vx = velocity[0,0]
        vy = velocity[1,0]
        vz = velocity[2,0]
        wx = 0
        wy = 0
        wz = omega
        weight = sqrt(omega*omega)
        w_vx = wy*vz - wz*vy
        w_vy = wz*vx - wx*vz
        f3_ef = np.copy(force_vector)
        error_x = weight*( w_vx - f3_ef[0,0])
        error_y =  weight*( w_vy - f3_ef[1,0])
        error_int_x = error_int_x + error_x
        error_int_y = error_int_y + error_y

        h_acc_mag = sqrt(force_vector[0,0]*force_vector[0,0]+force_vector[1,0]*force_vector[1,0])

        #h_acc_mag = sqrt(acceleration[0,0]*acceleration[0,0]+acceleration[1,0]*acceleration[1,0])
        h_vel_mag = sqrt(velocity[0,0]*velocity[0,0]+velocity[1,0]*velocity[1,0])
        h_w_mag = weight

        h_error = weight*h_vel_mag - h_acc_mag
        sum_h_error = sum_h_error + h_error
        

        
        if False : 

            Y[0,0] = error_x
            Y[1,0] = error_y

            if use_gravity :
                A[0,0] = weight*(wy*vy+wz*vz-time*32.2*wz)
                A[0,1] = -weight*vx*wy
                A[1,0] = -weight*vy*wx
                A[1,1] = weight*(wx*vx+wz*vz-time*32.2*wz)
            else :
                A[0,0] = weight*(wy*vy+wz*vz)
                A[0,1] = -weight*vx*wy
                A[1,0] = -weight*vy*wx
                A[1,1] = weight*(wx*vx+wz*vz)     

            AT = np.transpose(A)

            ATA = ATA + np.matmul(AT,A)
            ATY = ATY + np.matmul(AT,Y)

            sum_ysqr = sum_ysqr + np.matmul(np.transpose(Y),Y)

       
        plot_file.write(f"{round(h_acc_mag,2)},{round(h_vel_mag,2)},{round(h_w_mag,2)},{round(h_error,2)},{round(sum_h_error,2)}\n")
        #plot_file.write(f"{round(time,2)},{round(omega*velocity[0,0],2)},{round(omega*velocity[1,0],2)},{round(-acceleration[0,0],2)},{round(acceleration[1,0],2)},{round(velocity[0,0],2)},{round(velocity[1,0],2)},{round(velocity[2,0],2)},{round(vel_mag,2)}\n")
        
    if False :
        ATA_INVERSE = np.linalg.inv(ATA)
        X = np.matmul(ATA_INVERSE,ATY)
        sigma_sqr = sum_ysqr - np.matmul(np.transpose(X),ATY)
        print("offsets = " , X )
        print(" sigma_sqr = " , sigma_sqr )
        print("ATA = " , ATA )
        print("ATY = " , ATY )
        print("ATA_INVERSE = " , ATA_INVERSE )
        print("sum of errors x = " , error_int_x )
        print("sum of errors y = " , error_int_y )
       
    

def build_arg_parser():
    parser = argparse.ArgumentParser(
        prog='simulation.py',
        description='tests matrix math routines')
    return parser

if __name__ == "__main__":
    parser = build_arg_parser()
    run_test()
