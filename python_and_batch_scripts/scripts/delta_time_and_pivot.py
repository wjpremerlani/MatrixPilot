import altair as alt
import pandas as pd
#import seaborn as sns
import streamlit as st
import numpy as np
import argparse
import sys

global args

global signal_names , run_names , yaw_columns , yaw_rate_columns , roll_columns , roll_rate_columns
global z_force_columns , y_force_columns , delta_time_columns , pivot_columns

st.set_page_config(layout = "wide")


signal_names = []
run_names = []
yaw_columns = []
yaw_rate_columns = []
roll_columns = []
roll_rate_columns = []
z_force_columns = []
y_force_columns = []
delta_time_columns = []
pivot_columns = []



debug_file = open("dt_and_pivot_log_file.txt" , "w" )
debug_file.write(f"dt_and_pivot log file opened.\n")

def log_column_names() :
    global signal_names , run_names , yaw_columns , yaw_rate_columns , roll_columns , roll_rate_columns
    global z_force_columns , y_force_columns , delta_time_columns , pivot_columns
    debug_file.write(f"yaw\n{yaw_columns}\n")
    debug_file.write(f"yaw rate\n{yaw_rate_columns}\n")
    debug_file.write(f"roll\n{roll_columns}\n")
    debug_file.write(f"roll rate\n{roll_rate_columns}\n")
    debug_file.write(f"z_force\n{z_force_columns}\n")
    debug_file.write(f"y_force\n{y_force_columns}\n")
    debug_file.write(f"delta_time\n{delta_time_columns}\n")
    debug_file.write(f"pivot\n{pivot_columns}\n")
    


def build_frames() :
    global signal_names , run_names , yaw_columns , yaw_rate_columns , roll_columns , roll_rate_columns
    global z_force_columns , y_force_columns , delta_time_columns , pivot_columns
    
    for run_name in run_names :       
        column_name = " -yaw__"+run_name
        yaw_columns.append(column_name)       
        column_name = " yaw_rate__"+run_name
        yaw_rate_columns.append(column_name)        
        column_name = " roll__"+run_name
        roll_columns.append(column_name)       
        column_name = " roll_rate__"+run_name
        roll_rate_columns.append(column_name)
        column_name = " z_force__"+run_name
        z_force_columns.append(column_name)
        column_name = " y_force__"+run_name
        y_force_columns.append(column_name)
        column_name = " delta_time__"+run_name
        delta_time_columns.append(column_name)
        column_name = " degs_pivot__"+run_name
        pivot_columns.append(column_name)

def factor_labels(column_names) :
    global signal_names , run_names
    for column_name in column_names :
        name_parts = column_name.split('__')
        if len(name_parts) > 1 :
            if name_parts[0] not in signal_names :
                signal_names.append(name_parts[0])
            if name_parts[1] not in run_names :
                run_names.append(name_parts[1])

#plotlet_file = st.file_uploader("Select Your plotlet file CSV")

plotlet_file = sys.argv[1]
                
if plotlet_file is not None:
    plotlets_df = pd.read_csv(plotlet_file)
    debug_file.write(f"first row = \n {plotlets_df.columns}\n")
    factor_labels(plotlets_df.columns)
    debug_file.write(f"signals = \n {signal_names}\n")
    debug_file.write(f"runs = \n {run_names}\n")
    build_frames()
    log_column_names()
    curve_list = plotlets_df["curve_number "].unique()
    debug_file.write(f"curve number list:\n{curve_list}\n")

    dtc , pc = st.columns(2)

    with dtc :
        try :
            delta_time_df = plotlets_df[delta_time_columns]
            delta_time_chart = st.line_chart(delta_time_df,y_label = "delta time, seconds")
        except :
            debug_file.write(f"delta time chart failed.\n")

    with pc :

        try :
            pivot_df = plotlets_df[pivot_columns]
            pivot_chart = st.line_chart(pivot_df,y_label = "pivot angle, degrees")
        except :
            debug_file.write(f"pivot angle chart failed.\n")

    debug_file.close()

    curve_number = st.sidebar.selectbox("select a curve number" , curve_list , index=None )

    if curve_number is not None:
        curvelet_df = plotlets_df[plotlets_df["curve_number "] == curve_number  ]
        curvelet_delta_time = curvelet_df[delta_time_columns]
        with dtc :
            curvelet_delta_time_chart = st.line_chart(curvelet_delta_time,y_label = "delta time, seconds")
        curvelet_pivot = curvelet_df[pivot_columns]
        with pc :
            curvelet_pivot_chart = st.line_chart(curvelet_pivot,y_label = "pivot angle, degrees")
        
    else :
        st.stop()
    
else:
    st.stop()

