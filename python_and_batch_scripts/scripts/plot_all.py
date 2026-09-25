global map_height , delta_time_height , curve_number_height
######################################################################
#
#
#
#   this section is for setting all the heights of the plots
#   heights are in pixels
#
#
# map height is for the heat map :
#
map_height = 500
#
# delta_time_height is for the delta time plot on the heat map
#
delta_time_height = 125
#
# curve_number_height is for the curve number plot on the heat map
#
curve_number_height = 75
#
# plotlet_height is for all other plots
#
plotlet_height = 190
#
#
#
#######################################################################




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
heat_columns = []



debug_file = open("plot_all_log_file.txt" , "w" )
debug_file.write(f"plot all file opened.\n")

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
    debug_file.write(f"heat\n{heat_columns}\n")

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
        column_name = " heat__"+run_name
        heat_columns.append(column_name)

def factor_labels(column_names) :
    global signal_names , run_names
    for column_name in column_names :
        name_parts = column_name.split('__')
        if len(name_parts) > 1 :
            if name_parts[0] not in signal_names :
                signal_names.append(name_parts[0])
            if name_parts[1] not in run_names :
                run_names.append(name_parts[1])


                
plotlet_file = st.sidebar.file_uploader("select a file")

track_map_tab , all_data_tab , curve_data_tab  = st.tabs(["  track_map  " , "  all_data  " , "   curve_data  " ])

#plotlet_file = sys.argv[1]

global yaw_chart , roll_chart , z_force_chart , delta_time_chart , yaw_rate_chart , roll_rate_chart , y_force_chart , pivot_chart
yaw_chart = None
roll_chart = None
z_force_chart = None
delta_time_chart = None
yaw_rate_chart = None
roll_rate_chart = None
y_force_chart = None
pivot_chart = None
                
if plotlet_file is not None:
    plotlets_df = pd.read_csv(plotlet_file)
    debug_file.write(f"first row = \n {plotlets_df.columns}\n")
    factor_labels(plotlets_df.columns)
    debug_file.write(f"signals = \n {signal_names}\n")
    debug_file.write(f"runs = \n {run_names}\n")
    build_frames()
    log_column_names()
    curve_list = plotlets_df["curve_number "].unique()
    debug_file.write(f"curve number list = \n{curve_list}\n")
    debug_file.write(f"run names list = \n{run_names}\n")

    debug_file.close()

    yaw_chart = None
    roll_chart = None
    z_force_chart = None
    delta_time_chart = None
    yaw_rate_chart = None
    roll_rate_chart = None
    y_force_chart = None
    pivot_chart = None

    
    curve_number = st.sidebar.selectbox("select a curve" , curve_list )    
    run_number = st.sidebar.selectbox("select a run" , run_names )

    if curve_number is not None :
        curvelet_df = plotlets_df[plotlets_df["curve_number "] == curve_number ]    
    
    with all_data_tab :
        
        all_left , all_right = st.columns(2)
        with all_left :
            
            if yaw_chart == None :
                yaw_chart = st.line_chart(plotlets_df, y=yaw_columns, y_label = "yaw deg" , height = plotlet_height )
            if roll_chart == None :
                roll_chart = st.line_chart(plotlets_df,y=roll_columns,y_label = "roll deg" , height = plotlet_height )
            if z_force_chart == None :
                z_force_chart = st.line_chart(plotlets_df,y=z_force_columns,y_label = "z force" , height = plotlet_height )
            if delta_time_chart == None :
                delta_time_chart = st.line_chart(plotlets_df,y=delta_time_columns,y_label = "dt sec", height = plotlet_height )
            

        with all_right :

            if yaw_rate_chart == None :     
                yaw_rate_chart = st.line_chart(plotlets_df,y=yaw_rate_columns,y_label = "yaw rt d/s" , height = plotlet_height )    
            if roll_rate_chart == None : 
                roll_rate_chart = st.line_chart(plotlets_df,y=roll_rate_columns,y_label = "roll rt d/s" , height =  plotlet_height )     
            if y_force_chart == None : 
                y_force_chart = st.line_chart(plotlets_df,y=y_force_columns,y_label = "y force" , height = plotlet_height ) 
            if pivot_chart == None : 
                pivot_chart = st.line_chart(plotlets_df,y=pivot_columns , y_label = "pvt deg" , height =  plotlet_height )
            



    with curve_data_tab :
        crv_left , crv_right = st.columns(2)
        with crv_left :

            
            if curve_number is not None:        
                curvelet_yaw_chart = st.line_chart(curvelet_df,y=yaw_columns,y_label = "yaw deg crv"+str(curve_number) , height = plotlet_height )                     
                curvelet_roll_chart = st.line_chart(curvelet_df, y = roll_columns , y_label = "roll deg crv"+str(curve_number) , height = plotlet_height )           
                curvelet_z_force_chart = st.line_chart(curvelet_df,y=z_force_columns , y_label = "z frc crv"+str(curve_number) , height = plotlet_height )        
                curvelet_delta_time_chart = st.line_chart(curvelet_df,y=delta_time_columns, y_label = "dt sec crv"+str(curve_number) , height =  plotlet_height )
                  
            else :
                st.stop()


        with crv_right :
        
            if curve_number is not None:
            
                curvelet_yaw_rate_chart = st.line_chart(curvelet_df,y=yaw_rate_columns,y_label = "yaw rt d/s crv"+str(curve_number) , height =  plotlet_height )
                curvelet_roll_rate_chart = st.line_chart(curvelet_df,y = roll_rate_columns , y_label = "roll rt d/s crv"+str(curve_number) , height = plotlet_height )
                curvelet_y_force_chart = st.line_chart(curvelet_df,y= y_force_columns ,y_label = "y frc, crv"+str(curve_number) , height = plotlet_height )        
                curvelet_pivot_chart = st.line_chart(curvelet_df,y= pivot_columns  , y_label = "pvt deg crv"+str(curve_number) , height =  plotlet_height )
        
            else :
                st.stop()

    with track_map_tab :
        if run_number is not None :

            x_name = str(' x__'+run_number)
            y_name = str(' y__'+run_number)
            dis_name = str(' distance__'+run_number)
            heat_name = str(' heat__'+run_number)
            st.write("track map for ",run_number)
            hm_domain = ['red','orange','yellow','green','blue']
            hm_range = ['#FF0000','#FF6E00','#FFF200','#00FF00','#0000FF']
            heat_map_chart = (
                alt.Chart(plotlets_df)
                    .mark_circle()
                    .encode(
                    x=x_name,
                    y=y_name,
                    color=alt.Color(heat_name).scale(domain = hm_domain , range = hm_range),
                    size = 'curve_number ' ,
                )
                .interactive()
                .properties(
                    height = map_height
                    )
            )
            st.altair_chart(heat_map_chart, use_container_width=True)

            try :            
                delta_time_chart_hm = st.line_chart(plotlets_df, y = delta_time_columns , y_label = "dt sec" , height = delta_time_height )
            except :
                pass
  
            cn_chart = st.line_chart(plotlets_df,y= "curve_number " ,y_label = "curve" , height = curve_number_height )

            
        else:
            st.stop()

   






