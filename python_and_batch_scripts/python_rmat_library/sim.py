import numpy as np
from math import sin, cos, atan2, sqrt, radians, degrees
from datetime import datetime
import argparse

def cross_t(a,b):
    return np.transpose(np.cross(np.transpose(a),np.transpose(b)))

global nvrws
nvrws = 3

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
acc_off_x = 0.0
acc_off_y = 0.0
acc_off_z = 0.0

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
            plot_file.write(f"{round(matrix_values[row,column],3)},")

def write_column_names(data_file , column_names , suffix ):
    for column_name in column_names :
        data_file.write(f"{column_name}{suffix},")

def write_columns(data_file , column_values ) :
    for value in column_values :
        data_file.write(f"{round(value,4)},")

global plot_file , suffix
global labels_have_been_written
global log_file
labels_have_been_written = False
def run_test():
    global plot_file , suffix , column_suffix
    global labels_have_been_written
    global args
    global yaw_offset_a , pitch_offset_a , roll_offset_a
    global yaw_bias_a , pitch_bias_a , roll_bias_a
    global yaw_drift_a , pitch_drift_a , roll_drift_a
    global log_file
    global nvrws

    file_list = open("cases.txt","a")
    log_file = open("results_log.txt" , "a")

    if args.adjust :
        if args.cs :
            suffix = str(column_suffix)
            suffix_a = str(column_suffix)
        else :
            suffix_a = "_drift"
        adj_file = open(suffix_a+".adj.csv","w")
        file_list.write(f"{suffix_a}.adj.csv\n")
    
    if args.base :
        plot_file = open("truth.csv","w")
        file_list.write(f"truth.csv\n")
        if args.cs :
            suffix = str("_truth_"+column_suffix)
        else:
            suffix = "_truth"       
    elif args.adjust :
        plot_file = open("test_case.csv","w")     
        file_list.write(f"test_case.csv\n")                         
        if args.cs :
            suffix = str("_test_"+column_suffix)
        else:
            suffix = "_test"
    else :
        
        if args.cs :
            suffix = str(column_suffix)
        else:
            suffix = "_drift"
        plot_file = open(suffix+".csv","w")
        file_list.write(f"{suffix}.csv\n")


    if args.base :
    #base case
        orientation = create_ypr_matrix(0.0,0.0,0.0)
        drift_angle = np.zeros((3,1))
    else:
        orientation = create_ypr_matrix(degrees(yaw_offset+yaw_offset_a),degrees(pitch_offset+pitch_offset_a),degrees(roll_offset+roll_offset_a))
        drift_angle = np.zeros((3,1))
        drift_angle[0,0]=(roll_bias+roll_bias_a)/6000.0
        drift_angle[1,0]=(pitch_bias+pitch_bias_a)/6000.0
        drift_angle[2,0]=(yaw_bias+yaw_bias_a)/6000.0
        

    plot_counter = 0

    force_vector = np.zeros((3,1))
    acceleration = np.zeros((3,1))
    velocity = np.zeros((3,1))
    angle = np.zeros((3,1))
    f3_ef =  np.zeros((3,1))
    
    FS = np.zeros((3,1))
    FST = np.zeros((3,1))
    
    RS = np.zeros((3,3))
    RSt = np.zeros((3,3))
    RScc = np.zeros((3,3))
    RXFS = np.zeros((3,3))
    RXFSt = np.zeros((3,3))
    
    
    CX = np.zeros((3,1))
    CY = np.zeros((3,1))
    CZ = np.zeros((3,1))

    CXt = np.zeros((3,1))
    CYt = np.zeros((3,1))
    CZt = np.zeros((3,1))
    CXcc = np.zeros((3,1))
    

    CW = np.zeros((3,1))
    CWt = np.zeros((3,1))
    CWcc = np.zeros((3,1))
    
    CXF = np.zeros((3,3))
    CYF = np.zeros((3,3))
    CZF = np.zeros((3,3))
    
    CXFt = np.zeros((3,3))
    CYFt = np.zeros((3,3))
    CZFt = np.zeros((3,3))
    CXFcc = np.zeros((3,3))
    
    CXFS = np.zeros((3,3))
    CYFS = np.zeros((3,3))
    CZFS = np.zeros((3,3))

    CXFSt = np.zeros((3,3))
    CYFSt = np.zeros((3,3))
    CZFSt = np.zeros((3,3))
    CXFScc = np.zeros((3,3))
    
    Y = np.zeros((3,1))
    A = np.zeros((3,6))
    ATA = np.zeros((6,6))
    ATY = np.zeros((6,1))

    ATAO = np.zeros((3,3))
    ATAB = np.zeros((3,3))
    ATAD = np.zeros((3,3))

    ATYO = np.zeros((3,1))
    ATYB = np.zeros((3,1))
    ATYD = np.zeros((3,1))

    E = np.zeros((3,1))
    AO = np.zeros((3,3))
    AB = np.zeros((3,3))
    AD = np.zeros((3,3))
    ACC = np.zeros((3,1))
    #AV = np.zeros((3,2))

    N = 0
    

    gravity = np.zeros((3,1))
    if use_gravity :
        gravity[2,0] = 32.2
    W = np.zeros((3,1))

    error_int_x = 0.
    error_int_y = 0.
    error_int_z = 0.
    
    sum_ysqr = 0

    sum_h_error = 0.
    
    for step_no in range(25000):

        N = N + 1
        
        time = float(step_no+1)*0.01

        drift_angle[0,0]=roll_bias/6000.0 + time*(roll_drift/(6000.0*60.0))
        drift_angle[1,0]=pitch_bias/6000.0 + time*(pitch_drift/(6000.0*60.0))
        drift_angle[2,0]=yaw_bias/6000.0 + time*(yaw_drift/(6000.0*60.0))
        
        if time < 100.0 :
            phi = 0.0001*time - ((0.0001)*(0.0001))/200.0
            force =  (time*time/100.0 - (0.0001)*time + 0.0001 )
            force_vector[0,0] = 1.0
            force_vector[1,0] = force
            if use_gravity :
                force_vector[2,0] = -32.2
            else :
                force_vector[2,0] = 0.0
        elif 100.0 <=  time < 150.0 :
            phi = 0.01
            force_vector[0,0] = 0.0
            force_vector[1,0] = 100.0
            if use_gravity :
                force_vector[2,0] = -32.2
            else :
                force_vector[2,0] = 0.0
        else :
            tt = time - 150.0
            phi = 0.01 - 0.0001*tt + (.0001)*(.0001)/200.0
            force = 100.0 + 0.0001/300 - tt*(2.0+0.0001) + tt*tt/100.0
            force_vector[0,0] = -1.0
            force_vector[1,0] = force
            if use_gravity :
                force_vector[2,0] = -32.2
            else :
                force_vector[2,0] = 0.0

        force_vector[0,0] = (force_vector[0,0]+acc_off_x*32.2)*acc_cal_x
        force_vector[1,0] = (force_vector[1,0]+acc_off_y*32.2)*acc_cal_y
        force_vector[2,0] = (force_vector[2,0]+acc_off_z*32.2)*acc_cal_z
        
        angle[2,0] = phi
        angle[0,0] = cross_coupling*force_vector[1,0]/(6000.0*32.2)
        angle[0,0] = angle[0,0]*gyro_cal_x
        angle[1,0] = angle[1,0]*gyro_cal_y
        angle[2,0] = angle[2,0]*gyro_cal_z
        
        omega = 100.0 * phi
        
        angle_bf = angle + drift_angle
        update_mat = phi_to_matrix(angle_bf)
        integral_mat = matrix_to_matrix_integral(update_mat)
        acceleration = np.matmul(orientation,np.matmul(integral_mat,force_vector))
        velocity_dot = np.copy(acceleration)
        if use_gravity :
            velocity_dot[2,0] = velocity_dot[2,0] + 32.2
        
        velocity[0,0] = velocity[0,0] + 0.01* velocity_dot[0,0]
        velocity[1,0] = velocity[1,0] + 0.01* velocity_dot[1,0]
        velocity[2,0] = velocity[2,0] + 0.01* velocity_dot[2,0]

        velocity_bf = np.matmul(np.transpose(orientation),velocity)
        
        vel_mag = sqrt( np.vdot( velocity , velocity ))
        force_mag = sqrt( np.vdot( force_vector , force_vector ))
        
        orientation = np.matmul(orientation,update_mat)
        RS = RS + np.multiply(orientation , 1.0/6000.0 )
        CX[:,0] = RS[:,0]
        CY[:,0] = RS[:,1]
        CZ[:,0] = RS[:,2]

        CXF = np.multiply(np.matmul(CX,np.transpose(acceleration)), 0.01)
        CYF = np.multiply(np.matmul(CY,np.transpose(acceleration)), 0.01)
        CZF = np.multiply(np.matmul(CZ,np.transpose(acceleration)), 0.01)

        RXFS = RXFS + np.multiply( mat_x_vec(RS,acceleration) , 0.01 )
        
        CXFS = CXFS + CXF - np.transpose(CXF)
        CYFS = CYFS + CYF - np.transpose(CYF)
        CZFS = CZFS + CZF - np.transpose(CZF)

        RSt = RSt + np.multiply(orientation , (time/60.0)/6000.0 )
        CXt[:,0] = RSt[:,0]
        CYt[:,0] = RSt[:,1]
        CZt[:,0] = RSt[:,2]

        RXFSt = RXFSt + np.multiply( mat_x_vec(RSt,acceleration) , 0.01 )

        RScc = RScc + np.multiply(orientation , (force_vector[1,0]/32.2)/6000.0 )
        CXcc[:,0] = RScc[:,0]

        CXFt = np.multiply(np.matmul(CXt,np.transpose(acceleration)), 0.01)
        CYFt = np.multiply(np.matmul(CYt,np.transpose(acceleration)), 0.01)
        CZFt = np.multiply(np.matmul(CZt,np.transpose(acceleration)), 0.01)
        CXFcc = np.multiply(np.matmul(CXcc,np.transpose(acceleration)), 0.01)
        
        
        CXFSt = CXFSt + CXFt - np.transpose(CXFt)
        CYFSt = CYFSt + CYFt - np.transpose(CYFt)
        CZFSt = CZFSt + CZFt - np.transpose(CZFt)
        CXFScc = CXFScc + CXFcc - np.transpose(CXFcc)
        

        W[2,0] = omega
        FS = FS + np.multiply(acceleration,0.01)

        vx = velocity[0,0]
        vy = velocity[1,0]
        vz = velocity[2,0]
        wx = 0.0
        wy = 0.0
        wz = omega
        weight = sqrt(omega*omega)
        w_vx = wy*vz - wz*vy
        w_vy = wz*vx - wx*vz
        w_vz = wx*vy - wy*vx
        f3_ef = force_vector
        error_x = weight*( w_vx - acceleration[0,0])
        error_y =  weight*( w_vy - acceleration[1,0])
        error_z = weight*( w_vz - acceleration[2,0])
        error_int_x = error_int_x + error_x
        error_int_y = error_int_y + error_y
        error_int_z = error_int_z + error_z
        
        #h_acc_mag = sqrt(force_vector[0,0]*force_vector[0,0]+force_vector[1,0]*force_vector[1,0])

        h_acc_mag = sqrt(acceleration[0,0]*acceleration[0,0]+acceleration[1,0]*acceleration[1,0])
        h_vel_mag = sqrt(velocity[0,0]*velocity[0,0]+velocity[1,0]*velocity[1,0])
        h_w_mag = weight

        WV = h_w_mag*h_vel_mag

        h_error = WV - h_acc_mag
        sum_h_error = sum_h_error + h_error

        E[:,0] = np.transpose(np.cross(W[:,0],velocity[:,0]))
        E[:,0] = E[:,0] - np.transpose(velocity_dot)           
        E = np.multiply(E,weight)

        if True :
            CW = np.multiply(np.matmul(CXFS,W),weight)
            AB[:,0] = CW[:,0]
            
            CW = np.multiply(np.matmul(CYFS,W),weight)
            AB[:,1] = CW[:,0]

            CW = np.multiply(np.matmul(CZFS,W),weight)
            AB[:,2] = CW[:,0]                        

        if True :
            CWt = np.multiply(np.matmul(CXFSt,W),weight)
            AD[:,0] = CWt[:,0]
            
            CWt = np.multiply(np.matmul(CYFSt,W),weight)
            AD[:,1] = CWt[:,0]

            CWt = np.multiply(np.matmul(CZFSt,W),weight)
            AD[:,2] = CW[:,0]                         

        if True :
            CWcc = np.multiply(np.matmul(CXFScc,W),weight)
            ACC[:,0] = CWcc[:,0]
        
        if True :
            
            w_f = np.matmul(np.transpose(W),FS)
            f_w = np.matmul(FS,np.transpose(W))
            
            AO[0,0] = w_f[0,0]
            AO[1,1] = w_f[0,0]
            AO = AO + f_w[:,:]
            
            AO = np.multiply(AO,weight)
            
            Y[:] = E[0:3]
            A[0:3,0:2] = AO[0:3,0:2]
            A[0:3,2:4] = AB[0:3,0:2]
            A[0:3,4:6] = AD[0:3,0:2]

            ATO = np.transpose(AO)
            ATAO = ATAO + np.matmul(ATO,AO)
            ATYO = ATYO + np.matmul(ATO,Y)

            ATB = np.transpose(AB)
            ATAB = ATAB + np.matmul(ATB,AB)
            ATYB = ATYB + np.matmul(ATB,Y)

            ATD = np.transpose(AD)
            ATAD = ATAD + np.matmul(ATD,AD)
            ATYD = ATYD + np.matmul(ATD,Y)      
                   
            AT = np.transpose(A)
            ATA = ATA + np.matmul(AT,A)
            ATY = ATY + np.matmul(AT,Y)         
            sum_ysqr = sum_ysqr + np.matmul(np.transpose(Y),Y) 
    
        if labels_have_been_written == False :
            if False :
                column_names = [ "h_accel_mag" , "h_vel mag" , "h_omega_mag" , "WV"  ]
            if False :
                column_names = [ "x_velocity ft/sec", "y_velocity ft/sec", "z_velocity ft/sec" , "velocity magnitude ft/sec" , "acc_x " , "acc_y" , "acc_z" , "err_x" , "err_y" , "err_z" ,  "err_int_x" , "err_int_y" , "err_int_z" ]
            if False :
                column_names = [ "v_mag " , "rxx" ,  "ryx" ,  "rzx" ,  "rxy" , "ryy" ,  "rzy" ,   "rxz" ,  "ryz" ,  "rzz"  ]
            if True :
                column_names = [ "vx_b" , "vy_b" , "vz_b" , "vx_e" , "vy_e" , "vz_e" , "vmag" ]
            write_column_names(plot_file , column_names , "_gyro_corrupted" )
            plot_file.write(f"\n")
            labels_have_been_written = True

        if False :
            column_values = [ h_acc_mag,h_vel_mag, h_w_mag, WV , h_error, sum_h_error ]
        if False :
            column_values = [  velocity[0,0] , velocity[1,0] , velocity[2,0] , vel_mag , acceleration[0,0] , acceleration[1,0] , acceleration[2,0] , error_x , error_y , error_z , error_int_x , error_int_y , error_int_z  ]
        if False :
            column_values = [ vel_mag ]
            write_columns(plot_file , column_values )
            write_matrix(CXFS)
        if True :
            column_values = [ velocity_bf[0,0] , velocity_bf[1,0] , velocity_bf[2,0] ,velocity[0,0] , velocity[1,0] , velocity[2,0] , vel_mag ]
            write_columns(plot_file , column_values )
        plot_file.write(f"\n")
     
    if True :
        if False :
            Yv = np.zeros((3,1))
            Yv[0:3,0]= velocity[0:3,0]
            
            AvO = np.zeros((3,2))
            AvB = np.zeros((3,2))
            AvD = np.zeros((3,2))
                           
            AvO[0,1]=FS[2,0]
            AvO[1,0]= -FS[2,0]
            
            AvB = RXFS[0:3,0:2]
            AvD = RXFSt[0:3,0:2]
            
            AvOT = np.transpose(AvO)
            AvBT = np.transpose(AvB)
            AvDT = np.transpose(AvD)
            
            ATAvO = np.matmul(AvOT,AvO)
            ATAvB = np.matmul(AvBT,AvB)
            ATAvD = np.matmul(AvDT,AvD)
            
            ATYvO = np.matmul(AvOT,Yv)
            ATYvB = np.matmul(AvBT,Yv)
            ATYvD = np.matmul(AvDT,Yv)
            

            ATAOv_INV = np.linalg.inv(ATAvO)
            ATABv_INV = np.linalg.inv(ATAvB)
            ATADv_INV = np.linalg.inv(ATAvD)
            
            
            XOv = np.matmul(ATAOv_INV, ATYvO)
            XBv = np.matmul(ATABv_INV, ATYvB)
            XDv = np.matmul(ATADv_INV, ATYvD)

            ATAO_INV = np.linalg.inv(ATAO)
            ATAB_INV = np.linalg.inv(ATAB)
            ATAD_INV = np.linalg.inv(ATAD)
            
            
            XO = np.matmul(ATAO_INV, ATYO)
            XB = np.matmul(ATAB_INV, ATYB)
            XD = np.matmul(ATAD_INV, ATYD)

            

            log_file.write(f"\n\n\nNext run.\n\n")

            log_file.write(f"roll offset =  , {roll_offset}\n" )
            log_file.write(f"pitch offset =  , {pitch_offset}\n" )
            log_file.write(f"roll bias =  , {roll_bias}\n" )
            log_file.write(f"pitch bias =  , {pitch_bias}\n" )
            log_file.write(f"roll drift =  , {roll_drift}\n" )
            log_file.write(f"pitch drift =  , {pitch_drift}\n" )
                
            log_file.write (f"\n")

            
            log_file.write (f"final velocity XO =  , {XO}\n" )
            log_file.write (f"final velocity XB =  , {XB}\n" )
            log_file.write (f"final velocity XD =  , {XD}\n" )
            
            log_file.write (f"final velocity XOv =  , {XOv}\n" )
            log_file.write (f"final velocity XBv =  , {XBv}\n" )
            log_file.write (f"final velocity XDv =  , {XDv}\n" )
            
        if args.constrain :

            log_file.write(f"roll_offset = {roll_offset}\n")
            log_file.write(f"pitch_offset = {pitch_offset}\n")
            log_file.write(f"roll_bias = {roll_bias}\n")
            log_file.write(f"pitch_bias = {pitch_bias}\n")
            log_file.write(f"roll_drift = {roll_drift}\n")
            log_file.write(f"pitch_drift = {pitch_drift}\n")

            ATAI = np.linalg.inv(ATA)
            X = np.matmul(ATAI,ATY)
            roll_offset_a = - X[0,0]
            pitch_offset_a = - X[1,0]
            roll_bias_a = -X[2,0]
            pitch_bias_a = -X[3,0]
            roll_drift_a = -X[4,0]
            pitch_drift_a = -X[5,0]

            print("first pass, constrained, adjustments = " , X )
            log_file.write(f"\n\nadjustments using only centrifugal estimators:\n")
            log_file.write(f"roll_offset_a = {roll_offset_a}\n")
            log_file.write(f"pitch_offset_a = {pitch_offset_a}\n")
            log_file.write(f"roll_bias_a = {roll_bias_a}\n")
            log_file.write(f"pitch_bias_a = {pitch_bias_a}\n")
            log_file.write(f"roll_drift_a = {roll_drift_a}\n")
            log_file.write(f"pitch_drift_a = {pitch_drift_a}\n")   

            
            Yv = np.zeros((nvrws,1))
            Yv[0:nvrws,0]= velocity[0:nvrws,0]
            sum_ysqrv = np.matmul(np.transpose(Yv),Yv)
            Av = np.zeros((nvrws,6))
            Av[0:nvrws,2:4] = RXFS[0:nvrws,0:2]
            Av[0:nvrws,4:6] = RXFSt[0:nvrws,0:2]
            Av[0,1]=FS[2,0]
            Av[1,0]= -FS[2,0]
            ATv = np.transpose(Av)
            
            ATAv = np.matmul(ATv,Av)
            ATYv = np.matmul(ATv,Yv)

            cons_error = np.matmul(Av,X)-Yv
            print("first pass constraint error = " , cons_error )
            log_file.write(f"first pass constraint error =  , {cons_error}\n")
            
            AvATAIAvT = np.matmul(np.matmul(Av,ATAI),ATv)
            print("AvATAIAvT = " , AvATAIAvT )
            log_file.write(f"AvATAIAvT = , {AvATAIAvT}\n")
            
            AvATAIAvTI = np.linalg.inv(AvATAIAvT)
            print("AvATAIAvTI = " , AvATAIAvTI )
            log_file.write(f"AvATAIAvTI = , {AvATAIAvTI}\n")

            X = X - np.matmul(ATAI,np.matmul(ATv,np.matmul(AvATAIAvTI,cons_error)))
            print("constrained X = " , X )
            log_file.write(f"constrained X = {X}\n")
            roll_offset_a = - X[0,0]
            pitch_offset_a = - X[1,0]
            roll_bias_a = -X[2,0]
            pitch_bias_a = -X[3,0]
            roll_drift_a = -X[4,0]
            pitch_drift_a = -X[5,0]
            log_file.write(f"\n\n")
            log_file.write(f"sim.py -adjust -constrain ")
            log_file.write(f"-ro {round(roll_offset+roll_offset_a,8)} ")
            log_file.write(f"-po {round(pitch_offset+pitch_offset_a,8)} ")
            log_file.write(f"-rb {round(roll_bias+roll_bias_a,8)} ")
            log_file.write(f"-pb {round(pitch_bias+pitch_bias_a,8)} ")
            log_file.write(f"-rd {round(roll_drift+roll_drift_a,8)} ")
            log_file.write(f"-pd {round(pitch_drift+pitch_drift_a,8)}\n\n")
            
            
            
            
            #sigma_sqr = sum_ysqr +   sum_ysqrv  - np.matmul(np.transpose(X),ATY) - np.matmul(np.transpose(X),ATYv)
            #std = sqrt( sigma_sqr[0,0] )
            
        else :
            Yv = np.zeros((nvrws,1))
            Yv[0:nvrws,0]= velocity[0:nvrws,0]
            sum_ysqrv = np.matmul(np.transpose(Yv),Yv)
            Av = np.zeros((nvrws,6))
            Av[0:nvrws,2:4] = RXFS[0:nvrws,0:2]
            Av[0:nvrws,4:6] = RXFSt[0:nvrws,0:2]
            Av[0,1]=FS[2,0]
            Av[1,0]= -FS[2,0]
            ATv = np.transpose(Av)
            ATAv = np.matmul(ATv,Av)
            ATYv = np.matmul(ATv,Yv)
            
            ATA_INVERSE = np.linalg.inv(ATA + ATAv)
            X = np.matmul(ATA_INVERSE,ATY+ATYv)
            roll_offset_a = - X[0,0]
            pitch_offset_a = - X[1,0]
            roll_bias_a = -X[2,0]
            pitch_bias_a = -X[3,0]
            roll_drift_a = -X[4,0]
            pitch_drift_a = -X[5,0]
            
            log_file.write(f"\n\nadjustments using combined unconstrained estimators:\n")

            log_file.write(f"roll_offset = {roll_offset}\n")
            log_file.write(f"pitch_offset = {pitch_offset}\n")
            log_file.write(f"roll_bias = {roll_bias}\n")
            log_file.write(f"pitch_bias = {pitch_bias}\n")
            log_file.write(f"roll_drift = {roll_drift}\n")
            log_file.write(f"pitch_drift = {pitch_drift}\n")          
                      
            log_file.write(f"roll_offset_a = {roll_offset_a}\n")
            log_file.write(f"pitch_offset_a = {pitch_offset_a}\n")
            log_file.write(f"roll_bias_a = {roll_bias_a}\n")
            log_file.write(f"pitch_bias_a = {pitch_bias_a}\n")
            log_file.write(f"roll_drift_a = {roll_drift_a}\n")
            log_file.write(f"pitch_drift_a = {pitch_drift_a}\n")
                                                   
            
            #sigma_sqr = sum_ysqr +   sum_ysqrv  - np.matmul(np.transpose(X),ATY) - np.matmul(np.transpose(X),ATYv)
            #std = sqrt( sigma_sqr[0,0] )
        
    if args.adjust :
        labels_have_been_written = False  
        orientation = create_ypr_matrix(degrees(yaw_offset+yaw_offset_a),degrees(pitch_offset+pitch_offset_a),degrees(roll_offset+roll_offset_a))
        drift_angle = np.zeros((3,1))
        print("roll offset = " , roll_offset )
        print("roll_offset adjustment = " , roll_offset_a )
        print("pitch offset = " , pitch_offset )
        print("pitch offset_adjustment = " , pitch_offset_a )  
        print("roll bias = " , roll_bias )
        print("roll bias adjustment = " , roll_bias_a )
        print("pitch bias = " , pitch_bias )
        print("pitch bias adjustment = " , pitch_bias_a)
        print("roll drift = " , roll_drift )
        print("roll drift adjustment = " , roll_drift_a )
        print("pitch drift = " , pitch_drift )
        print("pitch drift adjustment = " , pitch_drift_a)
        
        
        drift_angle[0,0]=(roll_bias+roll_bias_a)/6000.0
        drift_angle[1,0]=(pitch_bias+pitch_bias_a)/6000.0
        drift_angle[2,0]=(yaw_bias+yaw_bias_a)/6000.0   
        plot_counter = 0
        force_vector = np.zeros((3,1))
        acceleration = np.zeros((3,1))
        velocity = np.zeros((3,1))
        angle = np.zeros((3,1))  
        gravity = np.zeros((3,1))
        if use_gravity :
            gravity[2,0] = 32.2
        W = np.zeros((3,1))  
        for step_no in range(25000):       
            time = float(step_no+1)*0.01
            drift_angle[0,0]=(roll_bias+roll_bias_a)/6000.0 + time*((roll_drift+roll_drift_a)/(6000.0*60.0))
            drift_angle[1,0]=(pitch_bias+pitch_bias_a)/6000.0 + time*((pitch_drift+pitch_drift_a)/(6000.0*60.0))
            drift_angle[2,0]=(yaw_bias+yaw_bias_a)/6000.0 + time*((yaw_drift+yaw_drift_a)/(6000.0*60.0))
             
            if time < 100.0 :
                phi = 0.0001*time - ((0.0001)*(0.0001))/200.0
                force =  (time*time/100.0 - (0.0001)*time + 0.0001 )
                force_vector[0,0] = 1.0
                force_vector[1,0] = force
                if use_gravity :
                    force_vector[2,0] = -32.2
                else :
                    force_vector[2,0] = 0.0
            elif 100.0 <=  time < 150.0 :
                phi = 0.01
                force_vector[0,0] = 0.0
                force_vector[1,0] = 100.0
                if use_gravity :
                    force_vector[2,0] = -32.2
                else :
                    force_vector[2,0] = 0.0
            else :
                tt = time - 150.0
                phi = 0.01 - 0.0001*tt + (.0001)*(.0001)/200.0
                force = 100.0 + 0.0001/300 - tt*(2.0+0.0001) + tt*tt/100.0
                force_vector[0,0] = -1.0
                force_vector[1,0] = force
                if use_gravity :
                    force_vector[2,0] = -32.2
                else :
                    force_vector[2,0] = 0.0
                        
            force_vector[0,0] = (force_vector[0,0]+acc_off_x*32.2)*acc_cal_x
            force_vector[1,0] = (force_vector[1,0]+acc_off_y*32.2)*acc_cal_y
            force_vector[2,0] = (force_vector[2,0]+acc_off_z*32.2)*acc_cal_z       
            angle[2,0] = phi
            angle[0,0] = cross_coupling*force_vector[1,0]/(6000.0*32.2)
            angle[0,0] = angle[0,0]*gyro_cal_x
            angle[1,0] = angle[1,0]*gyro_cal_y
            angle[2,0] = angle[2,0]*gyro_cal_z       
            omega = 100.0 * phi       
            angle_bf = angle + drift_angle
            update_mat = phi_to_matrix(angle_bf)
            integral_mat = matrix_to_matrix_integral(update_mat)
            acceleration = np.matmul(orientation,np.matmul(integral_mat,force_vector))
            velocity[0,0] = velocity[0,0] + 0.01* acceleration[0,0]
            velocity[1,0] = velocity[1,0] + 0.01* acceleration[1,0]
            if use_gravity :
                velocity[2,0] = velocity[2,0] + 0.01* acceleration[2,0]+0.322
            else :
                velocity[2,0] = velocity[2,0] + 0.01* acceleration[2,0]
            velocity_bf = np.matmul(np.transpose(orientation),velocity)
            vel_mag = sqrt( np.vdot( velocity , velocity ))       
            orientation = np.matmul(orientation,update_mat)       
            vx = velocity[0,0]
            vy = velocity[1,0]
            vz = velocity[2,0]
            wx = 0.0
            wy = 0.0
            wz = omega
            w_vx = wy*vz - wz*vy
            w_vy = wz*vx - wx*vz
            w_vz = wx*vy - wy*vx
            f3_ef = np.copy(force_vector)       
            if labels_have_been_written == False :
                if True :
                    column_names = ["vx_b" , "vy_b" , "vz_b" ,  "vx_e" , "vy_e" , "vz_e" , "vmag" ]
                write_column_names(adj_file , column_names , "adj."+suffix)
                adj_file.write(f"\n")
                labels_have_been_written = True
            if True :
                column_values = [ velocity_bf[0,0] , velocity_bf[1,0] , velocity_bf[2,0] , velocity[0,0] , velocity[1,0] , velocity[2,0] , vel_mag ]     
                write_columns(adj_file , column_values )
            adj_file.write(f"\n")

            
    
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

    parser.add_argument('-yb ', '--yb',  help="yaw offset, radians per minute")
    parser.add_argument('-pb ', '--pb',  help="pitch offset, radians per minute")
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

    parser.add_argument('-rws ' , '--rws', help = 'number of rows to be used in velocity contstraint')

    parser.add_argument('-constrain ', '--constrain',  action='store_true', help='use constrained regression')
    
    
       
    return parser

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
        suffix = column_suffix
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
    if args.rws :
        nvrws = int(args.rws)
    else :
        nvrws = 3
    
    
    run_test()
