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
#column_ratios = [ 0.65 , 0.35 ]
column_ratios = [ 0.60 , 0.10, 0.30 ]
fs_column_ratios = [ 0.90 , 0.10 ]
trim_delay = 6.0
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

# the following two values are used to specify color mapping type.
# specify ABSOLUTE_MAP for absolute mapping, SIGNED_MAP for signed mapping
# and -SIGNED_MAP for signed mapping with reversed sign
#
#####################################################################

global ft_to_meter , ftps_to_kph , g_to_fpsps
ft_to_meter = 0.3048
ftps_to_kph = 1.09728
g_to_fpsps = 32.1714

global ABSOLUTE_MAP , SIGNED_MAP , Z_FORCE_MAP
ABSOLUTE_MAP = 0
SIGNED_MAP = 1
Z_FORCE_MAP = 2

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
global x_force_columns, velocity_columns , acceleration_columns , raw_z_columns
global aero_columns , friction_columns , z_force_filtered_columns , distance_columns
global hex_byte
hex_byte = ['0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F']
global colors
colors = []

for msb in range(16) :
    for lsb in range(16) :
        color = "#"+hex_byte[msb]+hex_byte[lsb]+"FF00"
        colors.append(color)

for msb in range(16) :
    for lsb in range(16) :
        color = "#FF"+hex_byte[15-msb]+hex_byte[15-lsb]+"00"
        colors.append(color)

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
distance_columns = []
pitch_columns = []
x_force_columns = []
velocity_columns = []
acceleration_columns = []
raw_z_columns = []
aero_columns = []
friction_columns = []
z_force_filtered_columns = []

debug_file = open("plot_all_log_file.txt" , "w" )
debug_file.write(f"plot all file opened.\n")

def log_column_names() :
    global signal_names , run_names , yaw_columns , yaw_rate_columns , roll_columns , roll_rate_columns
    global z_force_columns , y_force_columns , delta_time_columns , pivot_columns , distance_columns , pitch_columns
    global x_force_columns, velocity_columns , acceleration_columns
    global aero_columns , friction_columns , z_force_filtered_columns

    debug_file.write(f"yaw\n{yaw_columns}\n")
    debug_file.write(f"yaw rate\n{yaw_rate_columns}\n")
    debug_file.write(f"roll\n{roll_columns}\n")
    debug_file.write(f"roll rate\n{roll_rate_columns}\n")
    debug_file.write(f"z_force\n{z_force_columns}\n")
    debug_file.write(f"y_force\n{y_force_columns}\n")
    debug_file.write(f"delta_time\n{delta_time_columns}\n")
    debug_file.write(f"pivot\n{pivot_columns}\n")
    debug_file.write(f"heat\n{heat_columns}\n")
    debug_file.write(f"distance\n{distance_columns}\n")
    debug_file.write(f"pitch\n{pitch_columns}\n")
    debug_file.write(f"x_force\n{x_force_columns}\n")
    debug_file.write(f"velocity\n{velocity_columns}\n")
    debug_file.write(f"acceleration\n{acceleration_columns}\n")
    debug_file.write(f"aero\n{aero_columns}\n")
    debug_file.write(f"friction\n{friction_columns}\n")
    debug_file.write(f"z_force_filtered\n{z_force_filtered_columns}\n")    
    
global number_of_runs

def build_frames() :
    global signal_names , run_names , yaw_columns , yaw_rate_columns , roll_columns , roll_rate_columns
    global z_force_columns , y_force_columns , delta_time_columns , pivot_columns , distance_columns , pitch_columns , number_of_runs
    global x_force_columns, velocity_columns , acceleration_columns
    global aero_columns , friction_columns , z_force_filtered_columns

    for run_name in run_names :       
        column_name = " -yaw__"+run_name
        yaw_columns.append(column_name)       
        column_name = " yaw_rate__"+run_name
        yaw_rate_columns.append(column_name)        
        column_name = " roll__"+run_name
        roll_columns.append(column_name)       
        column_name = " roll_rate__"+run_name
        roll_rate_columns.append(column_name)
        column_name = " z_force_g__"+run_name
        z_force_columns.append(column_name)
        column_name = " y_force_g__"+run_name
        y_force_columns.append(column_name)
        column_name = " delta_time__"+run_name
        delta_time_columns.append(column_name)
        column_name = " degs_pivot__"+run_name
        pivot_columns.append(column_name)
        column_name = " heat__"+run_name
        heat_columns.append(column_name)
        column_name = " distance__"+run_name
        distance_columns.append(column_name)
        column_name = " pitch__"+run_name
        pitch_columns.append(column_name)

        column_name = " friction+aero__"+run_name
        x_force_columns.append(column_name)
        column_name = " velocity__"+run_name
        velocity_columns.append(column_name)
        column_name = " x-acceleration__"+run_name
        acceleration_columns.append(column_name)
        column_name = " z_force_filtered__"+run_name
        z_force_filtered_columns.append(column_name)
        column_name = " aero__"+run_name
        aero_columns.append(column_name)
        column_name = " friction__"+run_name
        friction_columns.append(column_name)

    number_of_runs = len(delta_time_columns)

    debug_file.write(f"\r\n***************** number of runs = {number_of_runs} *************\r\n")

def factor_labels(column_names) :
    global signal_names , run_names
    for column_name in column_names :
        name_parts = column_name.split('__')
        if len(name_parts) > 1 :
            if name_parts[0] not in signal_names :
                signal_names.append(name_parts[0])
            if name_parts[1] not in run_names :
                run_names.append(name_parts[1])

global map_coloring_df
global plotlets_df

def distance_color(value,min_value,max_value) :
    global colors_df 
    value_range = max_value - min_value 
    if value_range > 0  :
        color_index = int(512.0*((value-min_value)/value_range))
    else :
        color_index = 0
    if color_index > 511 :
        color_index = 511
    if color_index < 0 :
        color_index = 0
    color = colors_df['GYR'][color_index]
    return color

global roll_legend_df , pitch_legend_df , z_force_legend_df , y_force_legend_df

def abs_color(value,value_range ) :
    global colors_df  
    if value_range > 0  :
        color_index = int(512.0*((abs(value))/value_range))
    else :
        color_index = 0
    if color_index > 511 :
        color_index = 511
    if color_index < 0 :
        color_index = 0
    color = colors_df['GYR'][color_index]
    return color

def signed_color(value,value_range ) :
    global colors_df  
    if value_range > 0  :
        color_index = 255+int(256.0*(((value))/value_range))
    else :
        color_index = 255
    if color_index > 511 :
        color_index = 511
    if color_index < 0 :
        color_index = 0
    color = colors_df['GYR'][color_index]
    return color

def zf_color(value, value_max , value_min) :
#note : because signs were flipped on the way in, max and min are swapped
    global colors_df
    value_range = abs(value_max-value_min)
    if value_range > 0 :
        color_index = int(512.0*(((value-value_min))/value_range))
    else :
        color_index = 0
    if color_index > 511 :
        color_index = 511
    if color_index < 0 :
        color_index = 0
    color = colors_df['GYR'][color_index]
    return color

def generate_coloring(signal_name , columns , type_of_coloring ) :
    global ABSOLUTE_MAP , SIGNED_MAP , Z_FORCE_MAP , plotlets_df
    gap = 10
    first_color_map = True
    max_list = []
    min_list = []
    series_list = []
    run_index = 0
    for col in columns :
        value_max = max(plotlets_df[col])
        max_list.append(value_max)
        value_min = min(plotlets_df[col])
        min_list.append(value_min)
    value_max = max(max_list)
    value_min = min(min_list)
    value_range = max(abs(value_max),abs(value_min))
    
    for col in columns :
        color_list = []
        prev_curve_number = plotlets_df["curve_number "][0]
        gap_count = 0
        for row_index in plotlets_df[col].index :
            this_curve_number = plotlets_df["curve_number "][row_index]
            if this_curve_number != prev_curve_number :
                gap_count = gap
                prev_curve_number = this_curve_number
            if gap_count > 0 :
                gap_count = gap_count - 1
                color_list.append('#000000')
            else :
                row = plotlets_df[col][row_index]
                if type_of_coloring == Z_FORCE_MAP :
                    color_list.append(str(zf_color(-row,-value_min,-value_max)))
                elif type_of_coloring == ABSOLUTE_MAP :
                    color_list.append(str(abs_color(row,value_range)))
                else :
                    if type_of_coloring > 0 :
                        color_list.append(str(signed_color(row,value_range)))
                    else :
                        color_list.append(str(signed_color(-row,value_range)))
                
        list_size = len(color_list)
        list_index = list(range(list_size))
        color_series = pd.Series(color_list, name = str(signal_name+"_color__"+run_names[run_index]) )
        new_color_df = pd.DataFrame(color_series)
        new_color_df.index = list_index
        debug_file.write(f" {signal_name} df = {new_color_df}\r\n")
        if first_color_map == True :
            map_coloring_df = new_color_df
            first_color_map = False
        else :
            map_coloring_df = map_coloring_df.join(new_color_df)
        run_index = run_index + 1
    plotlets_df = plotlets_df.join(map_coloring_df)
    debug_file.write(f"{signal_name}_max_list = {max_list}\r\n")
    debug_file.write(f"{signal_name}_min_list = {min_list}\r\n")
    debug_file.write(f"{signal_name} range = {value_range}\r\n")
    debug_file.write(f"{signal_name} coloring data frame = {map_coloring_df}\r\n")

    value_list = []
    color_list = []
    x_list = []
    if type_of_coloring == Z_FORCE_MAP:
        value_range = abs(value_max-value_min)
        for index in list(range(512)):
            value = -value_max + (value_range/512.0)*float(index)
            color = colors_df['GYR'][index]
            value_list.append(value)
            color_list.append(color)
            x_list.append(0.0)
    elif type_of_coloring == ABSOLUTE_MAP :
        for index in list(range(512)) :
            value = (value_range/512.0)*float(index)
            color = colors_df['GYR'][index]
            value_list.append(value)
            color_list.append(color)
            x_list.append(0.0)
    else :
        for index in list(range(512)) :
            if type_of_coloring > 0  :
                value = (value_range/256.0)*float(index) - value_range
            else :
                value = (-value_range/256.0)*float(index) + value_range
            color = colors_df['GYR'][index]
            value_list.append(value)
            color_list.append(color)
            x_list.append(0.0)
    y_values = pd.Series(value_list , name = str(signal_name))
    legend_df = pd.DataFrame(y_values)
    legend_df.index = list(range(512))
    color_values = pd.Series(color_list , name = "color_value")
    color_values_df = pd.DataFrame(color_values)
    color_values_df.index = list(range(512))
    x_values = pd.Series(x_list , name = "|")
    x_values_df = pd.DataFrame(x_values )
    x_values_df.index = list(range(512))
    legend_df = legend_df.join(color_values_df).join(x_values_df)
    debug_file.write(f"{signal_name} legend = \r\n {legend_df}\r\n")
    return legend_df

def generate_distance_coloring() :
    global distance_columns , plotlets_df , run_names , map_coloring_df
    first_color_map = True
    d_max_list = []
    d_min_list = []
    series_list = []
    run_index = 0
    for d_col in distance_columns :
        d_max = max(plotlets_df[d_col])
        d_max_list.append(d_max)
        d_min = min(plotlets_df[d_col])
        d_min_list.append(d_min)
        color_list = []
        for row in plotlets_df[d_col] :
            color_list.append(str(distance_color(row,d_min,d_max)))
        list_size = len(color_list)
        list_index = list(range(list_size))
        d_c_series = pd.Series(color_list, name = str("distance_color__"+run_names[run_index]) )
        new_color_df = pd.DataFrame(d_c_series)
        new_color_df.index = list_index
        debug_file.write(f" new df = {new_color_df}\r\n")
        if first_color_map == True :
            map_coloring_df = new_color_df
            first_color_map = False
        else :
            map_coloring_df = map_coloring_df.join(new_color_df)
        run_index = run_index + 1
    plotlets_df = plotlets_df.join(map_coloring_df)
    debug_file.write(f"d_max_list = {d_max_list}\r\n")
    debug_file.write(f"d_min_list = {d_min_list}\r\n")
    debug_file.write(f"distance coloring data frame = {map_coloring_df}\r\n")
    #debug_file.write(f"plotlets_df = {plotlets_df}\r\n")   

pd.options.plotting.backend = "plotly"

alt.renderers.enable('svg')
                
plotlet_file = st.sidebar.file_uploader("select a file")

track_map_tab , all_data_tab , curve_data_tab , friction_tab , friction_scatter_tab = st.tabs(["  track_map  " , "  all_data  " , "   curve_data  "  , "   friction+aero  " , "  friction_scatter "])

#plotlet_file = sys.argv[1]

global yaw_chart , roll_chart , z_force_chart , delta_time_chart , yaw_rate_chart , roll_rate_chart , y_force_chart , pivot_chart
global friction_chart , velocity_chart , acceleration_chart , curvelet_delta_time_chart_for_heatmap , raw_z_chart
global friction_scatter_chart 
yaw_chart = None
roll_chart = None
z_force_chart = None
delta_time_chart = None
yaw_rate_chart = None
roll_rate_chart = None
y_force_chart = None
pivot_chart = None
aero_friction_chart = None
velocity_chart = None
acceleration_chart = None
curvelet_delta_time_chart_for_heatmap = None
raw_z_chart = None
aero_chart = None
friction_chart = None
friction_scatter_chart = None

global colors_df

colors_df = pd.read_csv("palettes.txt")
color_index = list(range(512))
colors_df.index = color_index

debug_file.write(f" colors_df['GYR'] = {colors_df['GYR']}\r\n\r\n")
          
if plotlet_file is not None:
    plotlets_df = pd.read_csv(plotlet_file)
    debug_file.write(f"first row = \n {plotlets_df.columns}\n")
    factor_labels(plotlets_df.columns)
    debug_file.write(f"signals = \n {signal_names}\n")
    debug_file.write(f"runs = \n {run_names}\n")
    build_frames()
    log_column_names()

    plotlets_df[aero_columns] = plotlets_df[aero_columns].div(g_to_fpsps)
    plotlets_df[x_force_columns] = plotlets_df[x_force_columns].div(g_to_fpsps)
    plotlets_df[acceleration_columns] = plotlets_df[acceleration_columns].div(g_to_fpsps)
    plotlets_df[friction_columns] = plotlets_df[friction_columns].div(g_to_fpsps)
    plotlets_df[velocity_columns] = plotlets_df[velocity_columns].mul(ftps_to_kph)
    plotlets_df[distance_columns] = plotlets_df[distance_columns].mul(ft_to_meter)
         
    distance_df = generate_coloring("distance", distance_columns , ABSOLUTE_MAP )
    yaw_rate_df = generate_coloring("yaw_rate", yaw_rate_columns , ABSOLUTE_MAP )
    roll_rate_df = generate_coloring("roll_rate", roll_rate_columns , ABSOLUTE_MAP )
    pivot_df = generate_coloring("pivot", pivot_columns , SIGNED_MAP )
    friction_df = generate_coloring("friction+aero", x_force_columns , ABSOLUTE_MAP)
    velocity_df = generate_coloring("velocity", velocity_columns , ABSOLUTE_MAP)
    acceleration_df = generate_coloring("x-acceleration", acceleration_columns , -SIGNED_MAP)
    z_force_df = generate_coloring("z_force", z_force_columns , Z_FORCE_MAP)
    roll_df = generate_coloring("roll" , roll_columns , ABSOLUTE_MAP )
    pitch_df = generate_coloring("pitch" , pitch_columns , SIGNED_MAP )
    y_force_df = generate_coloring("y_force" , y_force_columns , SIGNED_MAP )
    delta_time_df = generate_coloring("delta_time" , delta_time_columns , ABSOLUTE_MAP )
  
    curve_list = plotlets_df["curve_number "].unique()
    debug_file.write(f"curve number list = \n{curve_list}\n")
    debug_file.write(f"run names list = \n{run_names}\n")

    debug_file.close()
    
    s_run_names = st.sidebar.multiselect("select a set of runs for plotting", options= run_names , default = run_names )
    curve_number = st.sidebar.selectbox("select a curve" , curve_list )    
    run_number = st.sidebar.selectbox("select a run to heat map" , s_run_names )
    color_map = st.sidebar.selectbox("select variable to heat map" , [  " z_force" , " roll" , " roll_rate" ," pitch" , " yaw_rate" ," y_force" , " delta_time" , " pivot" , " friction+aero" , " velocity" , " x-acceleration" ] )

    s_yaw_columns = []
    s_yaw_rate_columns = []
    s_roll_columns = []
    s_roll_rate_columns = []
    s_z_force_columns = []
    s_y_force_columns = []
    s_delta_time_columns = []
    s_pivot_columns = []
    heat_columns = []
    distance_columns = []
    s_pitch_columns = []
    s_x_force_columns= []
    s_velocity_columns = []
    s_acceleration_columns = []
    s_raw_z_columns = []
    s_aero_columns = []
    s_friction_columns = []
    
    for run_name in s_run_names :       
        column_name = " -yaw__"+run_name
        s_yaw_columns.append(column_name)       
        column_name = " yaw_rate__"+run_name
        s_yaw_rate_columns.append(column_name)        
        column_name = " roll__"+run_name
        s_roll_columns.append(column_name)       
        column_name = " roll_rate__"+run_name
        s_roll_rate_columns.append(column_name)
        column_name = " z_force_g__"+run_name
        s_z_force_columns.append(column_name)
        column_name = " y_force_g__"+run_name
        s_y_force_columns.append(column_name)
        column_name = " delta_time__"+run_name
        s_delta_time_columns.append(column_name)
        column_name = " degs_pivot__"+run_name
        s_pivot_columns.append(column_name)
        column_name = " heat__"+run_name
        heat_columns.append(column_name)
        column_name = " distance__"+run_name
        distance_columns.append(column_name)
        column_name = " pitch__"+run_name
        s_pitch_columns.append(column_name)
        column_name = " friction+aero__"+run_name
        s_x_force_columns.append(column_name)
        column_name = " velocity__"+run_name
        s_velocity_columns.append(column_name)
        column_name = " x-acceleration__"+run_name
        s_acceleration_columns.append(column_name)
        column_name = " z_force_filtered__"+run_name
        s_raw_z_columns.append(column_name)
        column_name = " aero__"+run_name
        s_aero_columns.append(column_name)
        column_name = " friction__"+run_name
        s_friction_columns.append(column_name)

    if curve_number is not None :
        curvelet_df = plotlets_df[plotlets_df["curve_number "] == curve_number ]    

    with friction_scatter_tab :
        fs_map_left , fs_map_right = st.columns(fs_column_ratios)
                    
        with fs_map_right :
            fs_y_name = "distance"
            fs_y_title = "distance , meters"
            fs_legend_chart = (
                alt.Chart(distance_df[[fs_y_name , "|" , "color_value" ]])
                    .mark_square()
                        .encode(
                        alt.X('|').axis(labels=False,title = None),
                        alt.Y(fs_y_name).axis(title = fs_y_title),
                        color = alt.Color("color_value").scale(None)
                )
                .interactive()
                .properties(
                    height = map_height ,
                    )
            )
            st.altair_chart(fs_legend_chart , use_container_width=True )

        with fs_map_left :
            if run_number is not None :
                z_force_name = str(' z_force_filtered__'+run_number)
                friction_name = str(' friction+aero__'+run_number)
                distance_coloring_name = str('distance_color__'+run_number)
                scatter_df = plotlets_df[[z_force_name , friction_name , distance_coloring_name ]]
                st.write("friction plus aero scatter plot for ",run_number)
                friction_scatter_chart = (
                    alt.Chart(scatter_df[scatter_df.index > int(100.0*trim_delay ) ])
                        .mark_circle()
                        .encode(
                        alt.X(z_force_name).title("z force, g's"),
                        alt.Y(friction_name).title("estimated friction plus aero, g's"),
                        color = alt.Color(distance_coloring_name).scale(None)
                    )
                    .interactive()
                    .properties(
                        height = map_height ,
                        )
                )
                st.altair_chart(friction_scatter_chart, use_container_width=True)

            else :
                st.stop()

    with friction_tab :
        if friction_chart == None :
            aero_friction_chart = st.plotly_chart(plotlets_df[s_x_force_columns].plot( render_mode = 'svg').update_layout( yaxis_title = "estimated friction+aero, g's") )
            aero_chart = st.plotly_chart(plotlets_df[s_aero_columns].plot( render_mode = 'svg').update_layout( yaxis_title = "estimated aero, g's") )
            friction_chart = st.plotly_chart(plotlets_df[s_friction_columns].plot( render_mode = 'svg').update_layout( yaxis_title = "estimated friction, g's") )
            acceleration_chart = st.plotly_chart(plotlets_df[s_acceleration_columns].plot( render_mode = 'svg').update_layout( yaxis_title = "estimated acceleration, g's") )
            velocity_chart = st.plotly_chart(plotlets_df[s_velocity_columns].plot( render_mode = 'svg').update_layout( yaxis_title = "estimated velocity, kilometers per hour") )          
            
    with all_data_tab :
        all_left , all_right = st.columns(2)

        with all_left :          
            if yaw_chart == None :
                yaw_chart = st.plotly_chart(plotlets_df[s_yaw_columns].plot( render_mode = 'svg').update_layout( yaxis_title = "yaw, deg") )
                roll_chart = st.plotly_chart(plotlets_df[s_roll_columns].plot(render_mode = 'svg' ).update_layout( yaxis_title = "roll, deg") )
                z_force_chart = st.plotly_chart(plotlets_df[s_z_force_columns].plot(render_mode = 'svg' ).update_layout( yaxis_title = "z force, g's") )
                delta_time_chart = st.plotly_chart(plotlets_df[s_delta_time_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " dt, sec "))
            else :
                st.stop()
            
        with all_right :
            if yaw_rate_chart == None :
                yaw_rate_chart = st.plotly_chart(plotlets_df[s_yaw_rate_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " yaw rate, d/s ") )    
                roll_rate_chart = st.plotly_chart(plotlets_df[s_roll_rate_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = " roll rate, d/s  ") )     
                y_force_chart = st.plotly_chart(plotlets_df[s_y_force_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = " y force, g's") )  
                pivot_chart = st.plotly_chart(plotlets_df[s_pivot_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = " pivot, deg ") )
            else :
                st.stop()

    with curve_data_tab :
        crv_left , crv_right = st.columns(2)

        with crv_left :          
            if curve_number is not None:        
                curvelet_yaw_chart = st.plotly_chart(curvelet_df[s_yaw_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = "yaw, deg, crv"+str(curve_number)) )                     
                curvelet_roll_chart = st.plotly_chart(curvelet_df[s_roll_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = "roll, deg, crv"+str(curve_number)) )           
                curvelet_z_force_chart = st.plotly_chart(curvelet_df[s_z_force_columns].plot( render_mode = 'svg'  ).update_layout( yaxis_title = "z force, g's, crv"+str(curve_number)) )        
                curvelet_delta_time_chart = st.plotly_chart(curvelet_df[s_delta_time_columns].plot(render_mode = 'svg').update_layout( yaxis_title = " dt, sec, crv"+str(curve_number))  )                  
            else :
                st.stop()

        with crv_right :       
            if curve_number is not None:           
                curvelet_yaw_rate_chart = st.plotly_chart(curvelet_df[s_yaw_rate_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " yaw rate, d/s, crv"+str(curve_number)) )
                curvelet_roll_rate_chart = st.plotly_chart(curvelet_df[s_roll_rate_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " roll rate, d/s, crv"+str(curve_number)) )
                curvelet_y_force_chart = st.plotly_chart(curvelet_df[ s_y_force_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " y force, g's, curv"+str(curve_number)) )        
                curvelet_pivot_chart = st.plotly_chart(curvelet_df[ s_pivot_columns].plot(render_mode = 'svg'  ).update_layout( yaxis_title = " pivot, deg, crv"+str(curve_number)) )       
            else :
                st.stop()

    with track_map_tab :
        map_left , map_center, map_right = st.columns(column_ratios)
        with map_center:
            if color_map == ' pitch':
                legend_df = pitch_df
                y_name = "pitch"
                y_title = "pitch angle, degrees"
            elif color_map == ' y_force':
                legend_df = y_force_df
                y_name = "y_force"
                y_title = "y force, g's"
            elif color_map == ' z_force':
                legend_df = z_force_df
                y_name = "z_force"
                y_title = "z force, g's"
            elif color_map == ' delta_time':
                legend_df = delta_time_df
                y_name = "delta_time"
                y_title = "delta time, seconds"
            elif color_map == ' yaw_rate' :
                legend_df = yaw_rate_df
                y_name = "yaw_rate"
                y_title = "absolute yaw rate, degrees per second"
            elif color_map == ' roll_rate' :
                legend_df = roll_rate_df
                y_name = "roll_rate"
                y_title = "absolute roll rate, degrees per second"
            elif color_map == ' pivot' :
                legend_df = pivot_df
                y_name = "pivot"
                y_title = "pivot angle, degrees"
            elif color_map == ' friction+aero' :
                legend_df = friction_df
                y_name = "friction+aero"
                y_title = "friction+aero, g's"
            elif color_map == ' velocity' :
                legend_df = velocity_df
                y_name = "velocity"
                y_title = "velocity, kph"
            elif color_map == ' x-acceleration' :
                legend_df = acceleration_df
                y_name = "x-acceleration"
                y_title = "x-acceleration, g's"
            elif color_map == ' roll' :
                legend_df = roll_df
                y_name = "roll"
                y_title = "absolute roll angle, degrees"
            legend_chart = (
                alt.Chart(legend_df[[y_name , "|" , "color_value" ]])
                    .mark_square()
                        .encode(
                        alt.X('|').axis(labels=False,title = None),
                        alt.Y(y_name).axis(title = y_title),
                        color = alt.Color("color_value").scale(None)
                )
                .interactive()
                .properties(
                    height = map_height ,
                    )
            )
            st.altair_chart(legend_chart , use_container_width=True )
            
        with map_left :
            if run_number is not None :
                x_name = str(' x__'+run_number)
                y_name = str(' y__'+run_number)
                if color_map == ' pitch' :
                    coloring_name = str('pitch_color__'+run_number)
                elif color_map == ' roll':
                    coloring_name = str('roll_color__'+run_number)
                elif color_map == ' delta_time' :
                    coloring_name = str('delta_time_color__'+run_number)
                elif color_map == ' yaw_rate' :
                    coloring_name = str('yaw_rate_color__'+run_number)
                elif color_map == ' roll_rate' :
                    coloring_name = str('roll_rate_color__'+run_number)
                elif color_map == ' pivot' :
                    coloring_name = str('pivot_color__'+run_number)
                elif color_map == ' friction+aero' :
                    coloring_name = str('friction+aero_color__'+run_number)
                elif color_map == ' velocity' :
                    coloring_name = str('velocity_color__'+run_number)
                elif color_map == ' x-acceleration' :
                    coloring_name = str('x-acceleration_color__'+run_number)
                elif color_map == ' z_force' :
                    coloring_name = str('z_force_color__'+run_number)
                elif color_map == ' y_force' :
                    coloring_name = str('y_force_color__'+run_number)
                st.write("track map for ",run_number)
                heat_map_chart = (
                    alt.Chart(plotlets_df[[x_name , y_name , coloring_name ]])
                        .mark_circle()
                        .encode(
                        x=x_name,
                        y=y_name,
                        color = alt.Color(coloring_name).scale(None)
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

                if curvelet_delta_time_chart_for_heatmap == None :
          
                    curvelet_delta_time_chart_for_heatmap = st.plotly_chart(plotlets_df.plot(render_mode = 'svg' , x = "curve_number "  , y = delta_time_columns )
                                                            .update_layout( yaxis_title = "dt sec" , xaxis_title = "curve" , height = delta_time_height )
                                                            .update_xaxes( showgrid = True , dtick = int(1) )
                                                            .update_yaxes ( showgrid = True )
                                                                        )
                else :
                    st.stop()
            
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


            

   






