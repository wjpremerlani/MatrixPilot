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

    log_file = open(file_name+".log.txt","w")
    
                
    orientation = input_matrices[0]
    orientation_angles = extract_euler(orientation)
    orientation_angles[1] = orientation_angles[1] + degrees(pitch_offset_a + pitch_offset)
    orientation_angles[2] = orientation_angles[2] + degrees(roll_offset_a + roll_offset)
    orientation = create_ypr_matrix(orientation_angles[0],orientation_angles[1],orientation_angles[2])
    
    
    drift_angle = np.zeros((3,1))
    drift_angle[0] = roll_bias_a + roll_bias
    drift_angle[1] = pitch_bias_a + pitch_bias
    drift_angle[2] = yaw_bias_a + yaw_bias
    
    drift_angle = np.multiply(drift_angle , 1.0/6000.0)

    print("original orientation = " , input_matrices[0] )
    print("adjusted orientation = " , orientation )
    print("drift_angle = " , drift_angle )

    previous_raw_mat = orientation
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

    if use_drift :
        Y = np.zeros((3,1))
        A = np.zeros((3,8))
        ATA = np.zeros((8,8))
        ATY = np.zeros((8,1))

    
    else :       
        Y = np.zeros((2,1))
        A = np.zeros((2,5))
        ATA = np.zeros((5,5))
        ATY = np.zeros((5,1))

    E = np.zeros((3,1))
    AO = np.zeros((2,2))
    AB = np.zeros((2,3))
    AD = np.zeros((2,3))
    ACC = np.zeros((2,1))
    #AV = np.zeros((3,2))

    ATAO = np.zeros((2,2))
    ATAB = np.zeros((3,3))
    ATAD = np.zeros((3,3))

    ATYO = np.zeros((2,1))
    ATYB = np.zeros((3,1))
    ATYD = np.zeros((3,1))

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

    previous_matrix = orientation
    previous_raw_mat = orientation
    previous_adj_mat = orientation

    previous_vmag = 0

    energy = 0.0
    
    for step_no in range(len(body_forces)):

        N = N + 1
        
        time = float(step_no+1)*0.01
        
        drift_angle[0] = roll_bias_a + roll_bias + ( roll_drift_a + roll_drift )*(time/60.0)
        drift_angle[1] = pitch_bias_a + pitch_bias + ( pitch_drift_a + pitch_drift )*(time/60.0)
        drift_angle[2] = yaw_bias_a + yaw_bias + ( yaw_drift_a + yaw_drift )*(time/60.0)

    
        drift_angle = np.multiply(drift_angle , 1.0/6000.0)

        force_vector = body_forces[step_no]
        raw_mat = input_matrices[step_no]
        update_mat = np.matmul(np.transpose(previous_raw_mat),raw_mat)
        previous_raw_mat = raw_mat
        update_angles = matrix_to_phi(update_mat)
        update_angles = update_angles + drift_angle
        update_mat = phi_to_matrix(update_angles)
        rmat = np.matmul( previous_adj_mat, update_mat )
        previous_adj_mat = rmat 
        integral_mat = matrix_to_matrix_integral(update_mat)
        rotation_angle_bf = matrix_to_phi(update_mat)
        rotation_angle_ef = np.matmul(rmat,rotation_angle_bf)
        acceleration = np.matmul(rmat,np.matmul(integral_mat,force_vector))
        #velocity_dot = acceleration
        velocity_dot = np.copy(acceleration)
        velocity_dot[2,0] = velocity_dot[2,0]+32.174 + acc_off_z
        velocity = velocity + np.multiply ( velocity_dot , 0.01 )
        velocity_bf = np.matmul(np.transpose(rmat),velocity)
        vel_mag_bf = sqrt(np.vdot(velocity_bf,velocity_bf))
        power = np.vdot(velocity,velocity_dot) - velocity[2,0]*( 32.174 + acc_off_z ) 
        energy = energy + power*0.01
        vel_mag = sqrt(np.vdot(velocity,velocity))     
        dvdt = 100.0 * ( vel_mag - previous_vmag )
        previous_vmag = vel_mag 
        acc_mag = sqrt(np.vdot(acceleration,acceleration))

        W = np.multiply(rotation_angle_ef , 100.0)
        
        
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

        RXFSt = RXFSt + np.multiply( mat_x_vec(RSt,acceleration) , 0.01 )
        
        CXt[:,0] = RSt[:,0]
        CYt[:,0] = RSt[:,1]
        CZt[:,0] = RSt[:,2]

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
        

        
        FS = FS + np.multiply(acceleration,0.01)

        E[:,0] = np.transpose(np.cross(W[:,0],velocity[:,0]))
        E[:,0] = E[:,0] - np.transpose(velocity_dot)
        weight = sqrt (np.vdot(W,W))
        E = np.multiply(E,weight)

        if True :
            CW = np.multiply(np.matmul(CXFS,W),weight)
            AB[0:2,0] = CW[0:2,0]
            
            CW = np.multiply(np.matmul(CYFS,W),weight)
            AB[0:2,1] = CW[0:2,0]

            CW = np.multiply(np.matmul(CZFS,W),weight)
            AB[0:2,2] = CW[0:2,0]                        

        if True :
            CWt = np.multiply(np.matmul(CXFSt,W),weight)
            AD[0:2,0] = CWt[0:2,0]
            
            CWt = np.multiply(np.matmul(CYFSt,W),weight)
            AD[0:2,1] = CWt[0:2,0]

            CWt = np.multiply(np.matmul(CZFSt,W),weight)
            AD[0:2,2] = CW[0:2,0]                         

        if True :
            CWcc = np.multiply(np.matmul(CXFScc,W),weight)
            ACC[0:2,0] = CWcc[0:2,0]
        
        if True :
            
            w_f = np.matmul(np.transpose(W),FS)
            f_w = np.matmul(FS,np.transpose(W))
            AO = np.zeros((2,2))
 
            AO[0,0] = np.multiply(w_f[0,0],weight)
            AO[1,1] = np.multiply(w_f[0,0],weight)
            AO = AO + np.multiply(f_w[0:2,0:2],weight)

            if use_drift :
                Y[:] = E[0:3]
                A[0:2,0:2] = AO[0:2,0:2]
                A[0:2,2:5] = AB[0:2,0:3]
                A[0:2,5:8] = AD[0:2,0:3]
            else :
                Y[0:2,0] = E[0:2,0]
                A[0:2,0:2] = AO[0:2,0:2]
                A[0:2,2:5] = AB[0:2,0:3]

            #print("AO = " , AO )

            ATO = np.transpose(AO)
            ATAO = ATAO + np.matmul(ATO,AO)
            #print("ATYO = " , ATYO )
            #print("ATO = " , ATO )
            #print("ATO*Y = ", np.matmul(ATO,Y))
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

        
     
    if True :

        if True :
            #test each type of error separately
            Yv = np.zeros((2,1))
            Yv[0:2,0]= velocity[0:2,0]
            
            AvO = np.zeros((2,2))
            AvOFS = np.zeros((2,2))
            AvB = np.zeros((2,3))
            AvD = np.zeros((2,3))

            GT = 32.174*time
                           
            AvOFS[0,1]=FS[2,0]
            AvOFS[1,0]= -FS[2,0]
            
            AvO[0,1]= -GT
            AvO[1,0]= GT

            log_file.write(f" AvO =  {AvO}\n")

            log_file.write(f" FS[2,0] = {FS[2,0]}\n")
            
            AvB = RXFS[0:2,0:3]
            AvD = RXFSt[0:2,0:3]
            
            AvOT = np.transpose(AvO)
            AvOFST = np.transpose(AvOFS)
            AvBT = np.transpose(AvB)
            AvDT = np.transpose(AvD)
            
            ATAvO = np.matmul(AvOT,AvO)
            ATAvOFS = np.matmul(AvOFST,AvOFS)
            ATAvB = np.matmul(AvBT,AvB)
            ATAvD = np.matmul(AvDT,AvD)
            
            ATYvO = np.matmul(AvOT,Yv)
            ATYvOFS = np.matmul(AvOFST,Yv)
            ATYvB = np.matmul(AvBT,Yv)
            ATYvD = np.matmul(AvDT,Yv)
            
            try :
                ATAOv_INV = np.linalg.inv(ATAvO)
                log_file.write(f" ATAOv_INV = {ATAOv_INV}\n")
            except :
                print("\n ATAOv_INV not found\n")
                log_file.write(f" ATAOv_INV not found\n")

            try :
                ATAOvFS_INV = np.linalg.inv(ATAvOFS)
                log_file.write(f" ATAOvFS_INV = {ATAOvFS_INV}\n")
            except :
                print("\n ATAOvFS_INV not found\n")
                log_file.write(f" ATAOvFS_INV not found\n")

            try :
                ATABv_INV = np.linalg.inv(ATAvB)
            except :
                print("\nATABv_INV not found\n")
                log_file.write(f"ATABv_INV not found\n")

            try :
                ATADv_INV = np.linalg.inv(ATAvD)
            except :
                print("\nATADv_INV not found\n")
                log_file.write(f"ATADv_INV not found\n")

            try :
            
                XOv = np.matmul(ATAOv_INV, ATYvO)
                XOvFS = np.matmul(ATAOvFS_INV, ATYvOFS)
                
                log_file.write(f" ATYvO = {ATYvO}\n")
                log_file.write(f" XOv =  {XOv}\n")
                log_file.write(f" ATYvOFS = {ATYvOFS}\n")
                log_file.write(f" XOvFS =  {XOvFS}\n")
            except :
                print("\nATAOv_INV or ATAOvFS_INV not found\n")
                log_file.write(f"ATAOv_INV or ATAOvFS_INV not found\n")
           


            log_file.write(f" GT = {GT}\n")

            log_file.write(f" Yv = {Yv}\n")

            
            

            xox = Yv[1,0]/GT
            xoy = -Yv[0,0]/GT

            log_file.write(f" XOv simple = {xox} , {xoy} \n")

            roll_offset_a = -XOv[0,0]
            pitch_offset_a = -XOv[1,0]

            try :

                XBv = np.matmul(ATABv_INV, ATYvB)
                XDv = np.matmul(ATADv_INV, ATYvD)

                ATAO_INV = np.linalg.inv(ATAO)
                ATAB_INV = np.linalg.inv(ATAB)
                ATAD_INV = np.linalg.inv(ATAD)
                
                
                XO = np.matmul(ATAO_INV, ATYO)
                XB = np.matmul(ATAB_INV, ATYB)
                XD = np.matmul(ATAD_INV, ATYD)
            except :
                print("ATABv, ATADv, ATAO, ATAB or ATAD were not invertible\n")

            if False :

                log_file.write(f"ATAO = , {ATAO}\n" )
                log_file.write(f"ATAB = , {ATAB}\n" )
                log_file.write(f"ATAD = , {ATAD}\n" )

                log_file.write(f"ATYO = , {ATYO}\n" )
                log_file.write(f"ATYB = , {ATYB}\n" )
                log_file.write(f"ATYD = , {ATYD}\n" )

                log_file.write(f"ATAO_INV = , {ATAO_INV}\n")
                log_file.write(f"ATAB_INV = , {ATAB_INV}\n")
                log_file.write(f"ATAD_INV = , {ATAD_INV}\n")
                
                
                log_file.write (f" XO =  , {XO}\n" )
                log_file.write (f" XB =  , {XB}\n" )
                log_file.write (f" XD =  , {XD}\n" )
                
                log_file.write (f"final velocity XOv =  , {XOv}\n" )
                log_file.write (f"final velocity XBv =  , {XBv}\n" )
                log_file.write (f"final velocity XDv =  , {XDv}\n" )
         
        acc_off_z = 0.0
        print("acc_off_z = " , acc_off_z )
        if False :
            #constrained regression
            ATAI = np.linalg.inv(ATA)
            X = np.matmul(ATAI,ATY)
            roll_offset_a = - X[0,0]
            pitch_offset_a = - X[1,0]
            roll_bias_a = -X[2,0]
            pitch_bias_a = -X[3,0]
            yaw_bias_a = -X[4,0]
            
            print("first pass, constrained, adjustments = " , X )
            log_file.write(f"\n\nadjustments using only centrifugal estimators:\n")
            log_file.write(f"roll_offset_a = {roll_offset_a}\n")
            log_file.write(f"pitch_offset_a = {pitch_offset_a}\n")
            log_file.write(f"roll_bias_a = {roll_bias_a}\n")
            log_file.write(f"pitch_bias_a = {pitch_bias_a}\n")
            log_file.write(f"yaw_bias_a = {yaw_bias_a}\n")

            Yv = np.zeros((2,1))
            Yv[0:2,0]= velocity[0:2,0]
            sum_ysqrv = np.matmul(np.transpose(Yv),Yv)
            Av = np.zeros((2,5))
            Av[0:2,2:5] = RXFS[0:2,0:3]
            Av[0,1]=FS[2,0]
            Av[1,0]= -FS[2,0]
            ATv = np.transpose(Av)
            
            ATAv = np.matmul(ATv,Av)
            ATYv = np.matmul(ATv,Yv)

            log_file.write(f"Yv = {Yv}\n")


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
            yaw_bias_a = -X[4,0]
         
            log_file.write(f"map.py -f {file_name+'.txt'} ")
            log_file.write(f"-ro {round(roll_offset+roll_offset_a,8)} ")
            log_file.write(f"-po {round(pitch_offset+pitch_offset_a,8)} ")
            log_file.write(f"-rb {round(roll_bias+roll_bias_a,8)} ")
            log_file.write(f"-pb {round(pitch_bias+pitch_bias_a,8)} ")
            log_file.write(f"-yb {round(yaw_bias+yaw_bias_a,8)} ")

            cons_error = np.matmul(Av,X) - Yv

            log_file.write(f"\nconstrained error = {cons_error}\n")
    


        if False :
            #combined regression
            Yv = np.zeros((3,1))
            Yv[0:3,0]= velocity[0:3,0]
            sum_ysqrv = np.matmul(np.transpose(Yv),Yv)
            if use_drift :
                Av = np.zeros((3,8))
                Av[0:3,2:5] = RXFS[0:3,0:3]
                Av[0:3,5:8] = RXFSt[0:3,0:3]              
                Av[0,1]=FS[2,0]
                Av[1,0]= -FS[2,0]
            else :
                Av = np.zeros((3,5))
                Av[0:3,2:5] = RXFS[0:3,0:3]         
                Av[0,1]=FS[2,0]
                Av[1,0]= -FS[2,0]


           
            
            ATv = np.transpose(Av)
            ATAv = np.matmul(ATv,Av)
            ATYv = np.matmul(ATv,Yv)
                       
        if False :
            ATA_INVERSE = np.linalg.inv(ATA + ATAv)
            X = np.matmul(ATA_INVERSE,ATY+ATYv)
            if use_drift :
                roll_offset_a = - X[0,0]
                pitch_offset_a = - X[1,0]
                roll_bias_a = -X[2,0]
                pitch_bias_a = -X[3,0]
                yaw_bias_a = -X[4,0]
                roll_drift_a = -X[5,0]
                pitch_drift_a = -X[6,0]
                yaw_drift_a = -X[7,0]
                sigma_sqr = sum_ysqr +   sum_ysqrv - np.matmul(np.transpose(X),ATY) - np.matmul(np.transpose(X),ATYv)
                std = sqrt( sigma_sqr[0,0]/N)
                print("X = " , X )
                print("sum_ysqr = " , sum_ysqr )
                print("sigma_sqr = " , sigma_sqr )
                print("standard deviation = " , std )

            else :
                roll_offset_a = - X[0,0]
                pitch_offset_a = - X[1,0]
                roll_bias_a = -X[2,0]
                pitch_bias_a = -X[3,0]
                yaw_bias_a = -X[4,0]
                sigma_sqr = sum_ysqr +  np.multiply( sum_ysqrv , float(N))- np.matmul(np.transpose(X),ATY) - np.matmul(np.transpose(X),ATYv)
                std = sqrt( sigma_sqr[0,0]/N)
                print("X = " , X )
                print("sum_ysqr = " , sum_ysqr )
                print("sigma_sqr = " , sigma_sqr )
                print("standard deviation = " , std )
            
        if False :
            print("ATA = " , ATA )
            print("ATY = " , ATY )   
            print("sum of errors x = " , error_int_x )
            print("sum of errors y = " , error_int_y )
            print("last A = " , A )
            print("last Y = " , Y )

            
    orientation = input_matrices[0]
    previous_raw_mat = orientation
    
    orientation_angles = extract_euler(orientation)
    orientation_angles[1] = orientation_angles[1] + degrees(pitch_offset_a + pitch_offset)
    orientation_angles[2] = orientation_angles[2] + degrees(roll_offset_a + roll_offset)
    orientation = create_ypr_matrix(orientation_angles[0],orientation_angles[1],orientation_angles[2])

    log_file.write(f"\n\nSecond pass\n\n")

    log_file.write(f"pitch_offset_a = {pitch_offset_a}\n")
    log_file.write(f"pitch_offset = {pitch_offset}\n")
    log_file.write(f"roll_offset_a = {roll_offset_a}\n")
    log_file.write(f"roll_offset = {roll_offset}\n")
    
    
    drift_angle = np.zeros((3,1))
    drift_angle[0] = roll_bias_a + roll_bias
    drift_angle[1] = pitch_bias_a + pitch_bias
    drift_angle[2] = yaw_bias_a + yaw_bias

    log_file.write(f"drift bias angle, degrees per minute = {drift_angle}\n")

    
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

        drift_angle[0] = roll_bias_a + roll_bias + ( roll_drift_a + roll_drift )*(time/60.0)
        drift_angle[1] = pitch_bias_a + pitch_bias + ( pitch_drift_a + pitch_drift )*(time/60.0)
        drift_angle[2] = yaw_bias_a + yaw_bias + ( yaw_drift_a + yaw_drift )*(time/60.0)

    
        drift_angle = np.multiply(drift_angle , 1.0/6000.0)

        force_vector = body_forces[step_no]
        raw_mat = input_matrices[step_no]
        update_mat = np.matmul(np.transpose(previous_raw_mat),raw_mat)
        previous_raw_mat = raw_mat
        update_angles = matrix_to_phi(update_mat)
        update_angles = update_angles + drift_angle
        update_mat = phi_to_matrix(update_angles)
        rmat = np.matmul( previous_adj_mat, update_mat )
        previous_adj_mat = rmat 
        integral_mat = matrix_to_matrix_integral(update_mat)
        rotation_angle_bf = matrix_to_phi(update_mat)
        rotation_angle_ef = np.matmul(rmat,rotation_angle_bf)
        acceleration = np.matmul(rmat,np.matmul(integral_mat,force_vector))
        #velocity_dot = acceleration
        velocity_dot = np.copy(acceleration)
        velocity_dot[2,0] = velocity_dot[2,0]+32.174 + acc_off_z
        velocity = velocity + np.multiply ( velocity_dot , 0.01 )
        velocity_bf = np.matmul(np.transpose(rmat),velocity)
        vel_mag_bf = sqrt(np.vdot(velocity_bf,velocity_bf))
        power = np.vdot(velocity,velocity_dot) - velocity[2,0]*( 32.174 + acc_off_z ) 
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
            input_file = open(file_name,'r')
            output_file = open(file_name+".raw.csv",'w')
            adjusted_file = open(file_name+".adj.csv",'w')
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
