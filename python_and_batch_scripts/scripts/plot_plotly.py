global map_height , delta_time_height , curve_number_height 
######################################################################
#
#
#
#   this section is for adjusting the 2 column layout of the heatmap tab
#   heights are in pixels, column ratios are are proportions
#   the map contains two columns
#   the left column is the heat map
#   the right column contains a delta time plot and a curve number
#
#
#   column ratios define the relative widths of left and right columns
#   the square brackets and the comma are required syntax
column_ratios = [ 0.65 , 0.35 ]
#
#   the following define plot heights in pixels
#   map height is for the heat map :
#
map_height = 650
#
#   delta_time_height is for the delta time plot on the heat map
#
delta_time_height = 400
#
#   curve_number_height is for the curve number plot on the heat map
#
curve_number_height = 200
#
#
#######################################################################


plotlet_height = 190
import altair as alt
import pandas as pd
#import seaborn as sns
import streamlit as st
import numpy as np
import argparse
import sys
import plotly

global args

global signal_names , run_names , yaw_columns , yaw_rate_columns , roll_columns , roll_rate_columns
global z_force_columns , y_force_columns , delta_time_columns , pivot_columns


if len (sys.argv) > 1 :
    try :
        slider_name = sys.argv[1]
        st.set_page_config(layout = "wide" , page_title = slider_name )
    except :
        st.set_page_config(layout = "wide")

else :
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

pd.options.plotting.backend = "plotly"

alt.renderers.enable('svg')
                
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
                yaw_chart = st.plotly_chart(plotlets_df[yaw_columns].plot( render_mode = 'svg').update_layout( yaxis_title = "yaw, deg") )
                roll_chart = st.plotly_chart(plotlets_df[roll_columns].plot(render_mode = 'svg' ).update_layout( yaxis_title = "roll, deg") )
                z_force_chart = st.plotly_chart(plotlets_df[z_force_columns].plot(render_mode = 'svg' ).update_layout( yaxis_title = "z force") )
                delta_time_chart = st.plotly_chart(plotlets_df[delta_time_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " dt, sec "))
            
        with all_right :
            if yaw_rate_chart == None :
                yaw_rate_chart = st.plotly_chart(plotlets_df[yaw_rate_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " yaw rate, d/s ") )    
                roll_rate_chart = st.plotly_chart(plotlets_df[roll_rate_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = " roll rate, d/s  ") )     
                y_force_chart = st.plotly_chart(plotlets_df[y_force_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = " y force") )  
                pivot_chart = st.plotly_chart(plotlets_df[pivot_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = " pivot, deg ") )
            else :
                st.stop()

    with curve_data_tab :
        crv_left , crv_right = st.columns(2)

        with crv_left :          
            if curve_number is not None:        
                curvelet_yaw_chart = st.plotly_chart(curvelet_df[yaw_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = "yaw, deg, crv"+str(curve_number)) )                     
                curvelet_roll_chart = st.plotly_chart(curvelet_df[roll_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = "roll, deg, crv"+str(curve_number)) )           
                curvelet_z_force_chart = st.plotly_chart(curvelet_df[z_force_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = "z force, crv"+str(curve_number)) )        
                curvelet_delta_time_chart = st.plotly_chart(curvelet_df[delta_time_columns].plot(render_mode = 'svg').update_layout( yaxis_title = " dt, sec, crv"+str(curve_number))  )                  
            else :
                st.stop()

        with crv_right :       
            if curve_number is not None:           
                curvelet_yaw_rate_chart = st.plotly_chart(curvelet_df[yaw_rate_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " yaw rate, d/s, crv"+str(curve_number)) )
                curvelet_roll_rate_chart = st.plotly_chart(curvelet_df[roll_rate_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " roll rate, d/s, crv"+str(curve_number)) )
                curvelet_y_force_chart = st.plotly_chart(curvelet_df[ y_force_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " y force, curv"+str(curve_number)) )        
                curvelet_pivot_chart = st.plotly_chart(curvelet_df[ pivot_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " pivot, deg, crv"+str(curve_number)) )       
            else :
                st.stop()

    with track_map_tab :
        map_left , map_right = st.columns(column_ratios)
        with map_left :
            if run_number is not None :
                x_name = str(' x__'+run_number)
                y_name = str(' y__'+run_number)
                dis_name = str(' distance__'+run_number)
                heat_name = str(' heat__'+run_number)
                st.write("track map for ",run_number)
                hm_domain = ['red','orange','yellow','green','blue']
                hm_range = ['#FF0000','#FF6E00','#FFF200','#00FF00','#0000FF']
                heat_map_chart = (
                    alt.Chart(plotlets_df[[x_name , y_name , dis_name , heat_name , 'curve_number ']])
                        .mark_circle()
                        .encode(
                        x=x_name,
                        y=y_name,
                        color=alt.Color(heat_name).scale(domain = hm_domain , range = hm_range),
                        size = 'curve_number ' ,
                    )
                    .interactive()
                    .properties(
                        height = map_height ,
                        )
                )
                st.altair_chart(heat_map_chart, use_container_width=True)

            else :
                st.stop()

            with map_right :
          
                curvelet_delta_time_chart_for_heatmap = st.plotly_chart(plotlets_df.plot(render_mode = 'svg' , x = "curve_number "  , y = delta_time_columns )
                                                            .update_layout( yaxis_title = "dt sec" , xaxis_title = "curve" , height = delta_time_height )
                                                            .update_xaxes( showgrid = True , dtick = int(1) )
                                                            .update_yaxes ( showgrid = True )
                                                                        )

                
                left_logo , right_logo = st.columns(2,vertical_alignment = "center")



                with right_logo :
                    try :
                        st.image("luge_image.jpg" )
                    except :
                        pass

                with left_logo :
                    try :
                        st.image("wolf-pac_logo.jpg")
                    except :
                        pass              

                with st.sidebar :
                    st.text("Data Quality")
                for run_name in run_names :
                    with st.sidebar :
                        with st.container() :
                            mark_col , run_col = st.columns([.1 , .9])
                            with run_col :
                                st.text(str(run_name+"\r"))
                            with mark_col :
                                if '?' in run_name :
                                    st.image("red_mark.jpg")
                                else :
                                    st.image("green_mark.jpg")


            

   






