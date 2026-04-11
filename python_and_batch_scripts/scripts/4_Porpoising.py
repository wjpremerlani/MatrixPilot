

import altair as alt
import pandas as pd
import streamlit as st
import numpy as np
import argparse
import sys
import plotly

global args

global signal_names, run_names
global fz_columns
global delta_yaw_columns
global delta_pitch_columns
global delta_roll_columns
global delta_fx_columns
global delta_fy_columns
global delta_fz_columns
global delta_velocity_columns

signal_names = []
run_names = []
fz_columns = []
delta_yaw_columns = []
delta_pitch_columns = []
delta_roll_columns = []
delta_fx_columns = []
delta_fy_columns = []
delta_fz_columns = []
delta_velocity_columns = []

st.set_page_config(layout="wide")


st.markdown("""
    <style>
        .stAppDeployButton {display:none;}
        .block-container {
            padding-top: 3rem;
            padding-bottom: 0rem;
            padding-left: 5rem;
            padding-right: 5rem;
        }
    </style>
""", unsafe_allow_html=True)


# debug_file = open("plot_all_log_file.txt" , "w" )
# debug_file.write(f"plot all file opened.\n")

global number_of_runs


def build_frames():
    global signal_names, run_names
    global fz_columns
    global delta_yaw_columns
    global delta_pitch_columns
    global delta_roll_columns
    global delta_fx_columns
    global delta_fy_columns
    global delta_fz_columns
    global delta_velocity_columns

    for run_name in run_names:
        column_name = " fz__" + run_name
        fz_columns.append(column_name)
        column_name = " delta_yaw__" + run_name
        delta_yaw_columns.append(column_name)
        column_name = " delta_pitch__" + run_name
        delta_pitch_columns.append(column_name)
        column_name = " delta_roll__" + run_name
        delta_roll_columns.append(column_name)
        column_name = " delta_fx__" + run_name
        delta_fx_columns.append(column_name)
        column_name = " delta_fy__" + run_name
        delta_fy_columns.append(column_name)
        column_name = " delta_fz__" + run_name
        delta_fz_columns.append(column_name)
        column_name = " delta_velocity__" + run_name
        delta_velocity_columns.append(column_name)
  
    number_of_runs = len(delta_velocity_columns)

    # debug_file.write(f"\r\n***************** number of runs = {number_of_runs} *************\r\n")


def factor_labels(column_names):
    global signal_names, run_names
    for column_name in column_names:
        name_parts = column_name.split('__')
        if len(name_parts) > 1:
            if name_parts[0] not in signal_names:
                signal_names.append(name_parts[0])
            if name_parts[1] not in run_names:
                run_names.append(name_parts[1])


global map_coloring_df
global plotlets_df

pd.options.plotting.backend = "plotly"

alt.renderers.enable('svg')


plotlet_file = st.sidebar.file_uploader("select a file")

fz_tab, delta_angle_tab , delta_force_tab , delta_velocity_tab  = st.tabs(["   fz  ", "  delta angles " , "  delta_forces " , "  delta_velocity   "])

# plotlet_file = sys.argv[1]

global fz_chart
global delta_yaw_chart
global delta_pitch_chart
global delta_roll_chart
global delta_fx_chart
global delta_fy_chart
global delta_fz_chart
global delta_velocity_chart

fz_chart = None
delta_yaw_chart = None
delta_pitch_chart = None
delta_roll_chart = None
delta_fx_chart = None
delta_fy_chart = None
delta_fz_chart = None
delta_velocity_chart = None




global colors_df


# debug_file.write(f" colors_df['GYR'] = {colors_df['GYR']}\r\n\r\n")


if plotlet_file is not None:
    plotlets_df = pd.read_csv(plotlet_file)
    # debug_file.write(f"first row = \n {plotlets_df.columns}\n")
    factor_labels(plotlets_df.columns)
    # debug_file.write(f"signals = \n {signal_names}\n")
    # debug_file.write(f"runs = \n {run_names}\n")
    build_frames()

    with fz_tab :
        if fz_chart == None:
            fz_chart = st.plotly_chart(plotlets_df[fz_columns].plot(render_mode='svg').update_layout(
                yaxis_title="normal force ft/sec/sec"),use_container_width = True )
        

    with delta_angle_tab :
        if delta_yaw_chart == None:
            delta_yaw_chart = st.plotly_chart(plotlets_df[delta_yaw_columns].plot(render_mode='svg').update_layout(
                yaxis_title="delta yaw, degs"),use_container_width = True )
            delta_pitch_chart = st.plotly_chart(plotlets_df[delta_pitch_columns].plot(render_mode='svg').update_layout(
                yaxis_title="delta pitch, degs"),use_container_width = True )
            delta_roll_chart = st.plotly_chart(plotlets_df[delta_roll_columns].plot(render_mode='svg').update_layout(
                yaxis_title="delta roll, degs"),use_container_width = True )     
        
    with delta_force_tab :
        if delta_fx_chart == None:
            delta_fx_chart = st.plotly_chart(plotlets_df[delta_fx_columns].plot(render_mode='svg').update_layout(
                yaxis_title="delta fx, ft/s/s"),use_container_width = True )
            delta_fy_chart = st.plotly_chart(plotlets_df[delta_fy_columns].plot(render_mode='svg').update_layout(
                yaxis_title="delta fy, ft/s/s"),use_container_width = True )
            delta_fz_chart = st.plotly_chart(plotlets_df[delta_fz_columns].plot(render_mode='svg').update_layout(
                yaxis_title="delta fz, ft/s/s"),use_container_width = True )
            

    with delta_velocity_tab :
        if delta_velocity_chart == None:
            delta_velocity_chart = st.plotly_chart(plotlets_df[delta_velocity_columns].plot(render_mode='svg').update_layout(
                yaxis_title="delta velocity, ft/sec"),use_container_width = True )
            

    

    # debug_file.write(f"generating color, pass number {ngen} \r\n")
    # debug_file.flush()
    
    # yaw_rate_df = generate_coloring("yaw_rate", " yaw_rate" , ABSOLUTE_MAP )
    # roll_rate_df = generate_coloring("roll_rate", " roll_rate" , ABSOLUTE_MAP )
    # pivot_df = generate_coloring("pivot", " degs_pivot" , SIGNED_MAP )
    # friction_df = generate_coloring("friction+aero", " friction+aero" , ABSOLUTE_MAP)
    # velocity_df = generate_coloring("velocity", " velocity" , ABSOLUTE_MAP)
    # acceleration_df = generate_coloring("x-acceleration", " x-acceleration" , -SIGNED_MAP)
    # z_force_df = generate_coloring("z_force", " z_force_g" , Z_FORCE_MAP)
    # roll_df = generate_coloring("roll" , " roll" , ABSOLUTE_MAP )
    # pitch_df = generate_coloring("pitch" , " pitch" , SIGNED_MAP )
    # y_force_df = generate_coloring("y_force" , " y_force_g" , SIGNED_MAP )
    # delta_time_df = generate_coloring("delta_time" , " delta_time" , ABSOLUTE_MAP )

    # debug_file.write(f"curve number list = \n{curve_list}\n")
    # debug_file.write(f"run names list = \n{run_names}\n")

    # debug_file.close()

   
    # curve_number = st.sidebar.pills("select a curve" , curve_list, , default=curve_list[0] )
    #run_number = st.sidebar.pills("select a run for a friction+aero scatter plot", s_run_names, default=s_run_names[0] if len(s_run_names) else None)
    # color_map = st.sidebar.pills("select variable to heat map" , [  " z_force" , " roll" , " roll_rate" ," pitch" , " yaw_rate" ," y_force" , " delta_time" , " pivot" , " friction+aero" , " velocity" , " x-acceleration" ], default=" z_force" )

    
    # if curve_number is not None :
    # curvelet_df = plotlets_df[plotlets_df["curve_number "] == curve_number ]

   
    
