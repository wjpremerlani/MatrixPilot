import django_integration as di
from LugeServer.settings import SERVER_SPORT_NAME
import streamlit as st

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

if st.sidebar.button("⬅&nbsp;Collections"):
    di.go_to_collections()
if st.sidebar.button("⬅&nbsp;Runs"):
    di.go_to_runs()

if not di.authenticate():
    st.stop()

# Get collection id from the url query string
coll_id = st.query_params.get("coll_id")
try:
    coll_id = int(coll_id)
except:
    pass

if coll_id:
    st.session_state["coll_id"] = coll_id
else:
    coll_id = st.session_state.get("coll_id")

# Show Logs
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
