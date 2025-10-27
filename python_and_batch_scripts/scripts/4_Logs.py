import django_integration as di
from LugeServer.settings import SERVER_SPORT_NAME
import streamlit as st
import luge.models as models

st.set_page_config(page_title=f"WolfPac {SERVER_SPORT_NAME} Data Manager", layout="wide")
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

if not di.authenticate():
    st.stop()
(run_coll_group, run_coll) = di.get_current_collection()

if run_coll_group:
    run_colls = run_coll_group.runcollection_set.all()
    run_colls = [rc for rc in run_colls if rc.runs.count()]
    if len(run_colls) > 1:
        display_vals = {rc.pk: rc.slider.name if rc.slider else "Runs" for rc in run_colls}
        options = display_vals.keys()
        st.session_state["run_coll_id"] = run_coll.pk if run_coll else list(display_vals.keys())[0]

        def coll_changed():
            if st.session_state.get('run_coll_id'):
                run_coll = models.RunCollection.objects.get(pk=st.session_state['run_coll_id'])
                if run_coll:
                    st.session_state['run_coll_id'] = run_coll.pk
                    if 's_run_names' in st.session_state:
                        del st.session_state['s_run_names']
                    if 'old_run_names' in st.session_state:
                        del st.session_state['old_run_names']

        st.sidebar.pills("Choose a Slider Collection",
                         options,
                         format_func=lambda v: display_vals[v],
                         key='run_coll_id',
                         on_change=coll_changed)

with st.sidebar:
    col1, col2, = st.columns(2, gap=None)
    col3, col4 = st.columns(2, gap=None)
    with col1:
        if st.button("⬅Colls", use_container_width=True):
            di.go_to_collections()
    with col2:
        if st.button("⬅Runs", use_container_width=True):
            di.go_to_runs()
    with col3:
        if st.button("⟳Refresh", use_container_width=True):
            di.refresh()
    with col4:
        if st.button("⟳Reproc.", use_container_width=True):
            di.reprocess()

# Show Logs
if run_coll:
    coll = run_coll.get_collection()
    if coll:
        coll_id = coll.pk
        log_path = f"../../run_data/collections/{coll_id}/filelist_merge_list_log.txt"
        log_file = open(log_path)
        if log_file:
            st.write("<b>filelist_merge_list_log.txt</b>", unsafe_allow_html=True)
            st.code(log_file.read())

        plots_log_path = f"../../run_data/collections/{coll_id}/filelist_merge_list_plots_log.txt"
        plots_log_file = open(plots_log_path)
        if plots_log_file:
            st.write("<b>filelist_merge_list_plots_log.txt</b>", unsafe_allow_html=True)
            st.code(plots_log_file.read())
