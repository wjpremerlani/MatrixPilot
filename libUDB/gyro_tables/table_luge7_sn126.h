

#ifndef TABLE_LUGE7_SN126_H
#define	TABLE_LUGE7_SN126_H

// used in LUGE7_SN126 partition size 64

#define X_CROSS_COUPLING 15
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14958 )

int16_t residual_offset[] = { 507-211 , 218-9 , -295+298 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	25	,	1922	,	-346	},
{	27	,	1911	,	-343	},
{	29	,	1901	,	-341	},
{	31	,	1898	,	-338	},
{	34	,	1893	,	-335	},
{	35	,	1884	,	-331	},
{	38	,	1875	,	-326	},
{	39	,	1864	,	-322	},
{	41	,	1858	,	-318	},
{	46	,	1854	,	-313	},
{	50	,	1832	,	-305	},
{	54	,	1813	,	-296	},
{	58	,	1798	,	-289	},
{	63	,	1780	,	-280	},
{	69	,	1767	,	-274	},
{	72	,	1749	,	-266	},
{	77	,	1732	,	-258	},
{	82	,	1713	,	-249	},
{	87	,	1698	,	-241	},
{	91	,	1684	,	-232	},
{	95	,	1669	,	-223	},
{	99	,	1651	,	-216	},
{	104	,	1637	,	-207	},
{	107	,	1621	,	-201	},
{	110	,	1610	,	-194	},
{	113	,	1597	,	-187	},
{	116	,	1582	,	-179	},
{	119	,	1570	,	-172	},
{	121	,	1560	,	-166	},
{	125	,	1549	,	-159	},
{	126	,	1535	,	-153	},
{	128	,	1523	,	-146	},
{	131	,	1514	,	-140	},
{	133	,	1498	,	-134	},
{	137	,	1489	,	-128	},
{	138	,	1477	,	-122	},
{	143	,	1468	,	-116	},
{	145	,	1454	,	-111	},
{	148	,	1440	,	-104	},
{	152	,	1430	,	-98	},
{	157	,	1419	,	-91	},
{	162	,	1407	,	-85	},
{	167	,	1394	,	-78	},
{	172	,	1383	,	-70	},
{	176	,	1369	,	-65	},
{	182	,	1357	,	-58	},
{	186	,	1344	,	-53	},
{	191	,	1334	,	-45	},
{	196	,	1319	,	-38	},
{	200	,	1307	,	-31	},
{	205	,	1297	,	-24	},
{	209	,	1284	,	-17	},
{	213	,	1271	,	-9	},
{	216	,	1258	,	-2	},
{	221	,	1247	,	5	},
{	224	,	1236	,	12	},
{	227	,	1221	,	19	},
{	230	,	1211	,	26	},
{	233	,	1199	,	33	},
{	235	,	1186	,	40	},
{	237	,	1171	,	46	},
{	241	,	1163	,	54	},
{	243	,	1147	,	61	},
{	246	,	1135	,	71	},
{	249	,	1121	,	77	},
{	252	,	1108	,	84	},
{	254	,	1095	,	90	},
{	256	,	1081	,	97	},
{	259	,	1071	,	105	},
{	262	,	1059	,	112	},
{	265	,	1045	,	120	},
{	266	,	1028	,	128	},
{	271	,	1018	,	135	},
{	275	,	1006	,	142	},
{	276	,	990	,	149	},
{	280	,	978	,	156	},
{	282	,	964	,	163	},
{	285	,	953	,	168	},
{	287	,	937	,	173	},
{	290	,	927	,	180	},
{	292	,	914	,	184	},
{	294	,	902	,	189	},
{	296	,	890	,	195	},
{	300	,	880	,	201	},
{	302	,	869	,	206	},
{	304	,	854	,	210	},
{	306	,	843	,	216	},
{	307	,	829	,	222	},
{	309	,	819	,	227	},
{	310	,	806	,	231	},
{	312	,	796	,	237	},
{	313	,	786	,	241	},
{	314	,	775	,	245	},
{	317	,	765	,	252	},
{	317	,	752	,	257	},
{	319	,	742	,	262	},
{	320	,	730	,	266	},
{	322	,	717	,	272	},
{	324	,	705	,	279	},
{	326	,	693	,	284	},
{	327	,	680	,	289	},
{	328	,	668	,	293	},
{	329	,	657	,	299	},
{	329	,	644	,	301	},
{	330	,	634	,	305	},
{	331	,	620	,	308	},
{	333	,	610	,	314	},
{	333	,	597	,	320	},
{	335	,	586	,	325	},
{	335	,	573	,	331	},
{	335	,	560	,	334	},
{	335	,	549	,	340	},
{	335	,	536	,	345	},
{	335	,	525	,	351	},
{	334	,	514	,	355	},
{	334	,	502	,	359	},
{	333	,	492	,	364	},
{	332	,	481	,	368	},
{	331	,	470	,	373	},
{	331	,	459	,	379	},
{	329	,	450	,	384	},
{	329	,	438	,	388	},
{	328	,	430	,	394	},
{	327	,	420	,	396	},
{	327	,	410	,	402	},
{	326	,	400	,	407	},
{	326	,	392	,	411	},
{	324	,	382	,	416	},
{	324	,	374	,	421	},
{	324	,	368	,	427	},
{	323	,	361	,	432	},
{	321	,	353	,	437	},
{	320	,	346	,	443	},
{	319	,	340	,	449	},
{	317	,	334	,	455	},
{	315	,	328	,	461	},
{	313	,	322	,	467	},
{	312	,	317	,	474	},
{	309	,	314	,	480	},
{	307	,	309	,	487	},
{	303	,	304	,	494	},
{	300	,	299	,	498	},
{	296	,	295	,	502	},
{	293	,	289	,	506	},
{	290	,	286	,	512	},
{	287	,	282	,	518	},
{	283	,	278	,	523	},
{	279	,	274	,	527	},
{	276	,	271	,	533	},
{	273	,	267	,	538	},
{	268	,	262	,	544	},
{	267	,	257	,	550	},
{	264	,	252	,	556	},
{	261	,	248	,	561	},
{	258	,	243	,	565	},
{	255	,	239	,	570	},
{	252	,	232	,	575	},
{	250	,	227	,	581	},
{	247	,	222	,	586	},
{	245	,	217	,	591	},
{	243	,	212	,	598	},
{	241	,	206	,	604	},
{	239	,	200	,	610	},
{	237	,	192	,	615	},
{	236	,	186	,	622	},
{	234	,	180	,	629	},
{	232	,	173	,	634	},
{	230	,	166	,	638	},
{	226	,	158	,	642	},
{	226	,	152	,	649	},
{	224	,	145	,	653	},
{	223	,	139	,	658	},
{	221	,	131	,	663	},
{	219	,	124	,	669	},
{	218	,	117	,	674	},
{	215	,	110	,	678	},
{	213	,	103	,	683	},
{	212	,	96	,	689	},
{	210	,	89	,	693	},
{	208	,	82	,	696	},
{	208	,	76	,	703	},
{	206	,	68	,	707	},
{	206	,	61	,	713	},
{	205	,	54	,	717	},
{	205	,	47	,	722	},
{	205	,	41	,	729	},
{	203	,	35	,	732	},
{	202	,	29	,	736	},
{	201	,	22	,	743	},
{	200	,	15	,	747	},
{	199	,	9	,	752	},
{	198	,	3	,	754	},
{	198	,	-4	,	762	},
{	198	,	-9	,	769	},
{	197	,	-14	,	772	},
{	196	,	-20	,	776	},
{	194	,	-27	,	781	},
{	193	,	-33	,	786	},
{	191	,	-38	,	789	},
{	189	,	-44	,	792	},
{	188	,	-49	,	796	},
{	185	,	-55	,	801	},
{	183	,	-60	,	805	},
{	181	,	-67	,	812	},
{	178	,	-73	,	817	},
{	176	,	-78	,	819	},
{	175	,	-84	,	824	},
{	172	,	-90	,	829	},
{	171	,	-97	,	834	},
{	169	,	-103	,	837	},
{	167	,	-109	,	842	},
{	165	,	-116	,	847	},
{	164	,	-123	,	854	},
{	162	,	-129	,	856	},
{	160	,	-136	,	861	},
{	158	,	-143	,	867	},
{	158	,	-150	,	870	},
{	156	,	-157	,	873	},
{	155	,	-162	,	879	},
{	153	,	-168	,	883	},
{	152	,	-174	,	884	},
{	150	,	-180	,	888	},
{	148	,	-187	,	893	},
{	146	,	-194	,	897	},
{	144	,	-200	,	901	},
{	141	,	-206	,	906	},
{	139	,	-210	,	910	},
{	137	,	-216	,	914	},
{	134	,	-222	,	917	},
{	131	,	-228	,	922	},
{	129	,	-232	,	926	},
{	127	,	-237	,	927	},
{	124	,	-243	,	930	},
{	121	,	-250	,	936	},
{	118	,	-254	,	939	},
{	116	,	-261	,	942	},
{	114	,	-267	,	947	},
{	111	,	-273	,	951	},
{	109	,	-280	,	957	},
{	107	,	-285	,	959	},
{	105	,	-291	,	963	},
{	103	,	-298	,	969	},
{	101	,	-303	,	971	},
{	98	,	-309	,	975	},
{	96	,	-315	,	977	},
{	94	,	-322	,	982	},
{	92	,	-327	,	983	},
{	89	,	-333	,	988	},
{	87	,	-340	,	991	},
{	85	,	-345	,	993	},
{	83	,	-350	,	996	},
{	82	,	-358	,	1004	},
{	79	,	-363	,	1005	},
{	77	,	-369	,	1007	},
{	75	,	-376	,	1010	},
{	73	,	-382	,	1014	},
{	70	,	-390	,	1018	},
{	68	,	-395	,	1019	},
{	66	,	-401	,	1020	},
{	64	,	-409	,	1026	},
{	61	,	-414	,	1027	},
{	59	,	-421	,	1030	},
{	56	,	-428	,	1033	},
{	53	,	-435	,	1035	},
{	50	,	-441	,	1035	},
{	47	,	-448	,	1037	},
{	44	,	-454	,	1039	},
{	41	,	-460	,	1040	},
{	37	,	-467	,	1041	},
{	35	,	-476	,	1046	},
{	32	,	-478	,	1043	},
{	30	,	-484	,	1044	},
{	27	,	-489	,	1046	},
{	24	,	-492	,	1047	},
{	22	,	-496	,	1049	},
{	20	,	-500	,	1050	},
{	18	,	-504	,	1050	},
{	16	,	-509	,	1052	},
{	14	,	-512	,	1052	},
{	12	,	-516	,	1053	},
{	11	,	-520	,	1055	},
{	10	,	-524	,	1059	},
{	10	,	-526	,	1060	},
{	9	,	-530	,	1065	},
{	8	,	-534	,	1069	},
{	6	,	-535	,	1068	},
{	5	,	-538	,	1071	},
{	4	,	-545	,	1078	},
{	4	,	-549	,	1080	},
{	3	,	-553	,	1081	},
{	3	,	-557	,	1084	},
{	3	,	-562	,	1087	},
{	3	,	-566	,	1088	},
{	2	,	-572	,	1092	},
{	2	,	-577	,	1095	},
{	2	,	-584	,	1101	},
{	2	,	-589	,	1104	},
{	1	,	-594	,	1108	},
{	1	,	-598	,	1109	},
{	1	,	-605	,	1114	},
{	2	,	-611	,	1117	},
{	2	,	-616	,	1117	},
{	2	,	-622	,	1121	},
{	2	,	-626	,	1121	},
{	2	,	-633	,	1126	},
{	2	,	-639	,	1130	},
{	2	,	-644	,	1133	},
{	1	,	-649	,	1136	},
{	0	,	-657	,	1140	},
{	0	,	-665	,	1147	},
{	0	,	-668	,	1147	},
{	0	,	-674	,	1152	},
{	0	,	-679	,	1154	},
{	1	,	-683	,	1156	},
{	1	,	-689	,	1159	},
{	2	,	-696	,	1164	},
{	2	,	-702	,	1167	},
{	3	,	-707	,	1169	},
{	3	,	-713	,	1173	},
{	3	,	-719	,	1176	},
{	3	,	-727	,	1181	},
{	4	,	-733	,	1185	},
{	4	,	-737	,	1185	},
{	5	,	-742	,	1188	},
{	6	,	-748	,	1189	},
{	7	,	-754	,	1192	},
{	7	,	-758	,	1191	},
{	7	,	-766	,	1195	},
{	7	,	-773	,	1198	},
{	8	,	-779	,	1199	},
{	8	,	-785	,	1202	},
{	8	,	-793	,	1206	},
{	8	,	-800	,	1207	},
{	8	,	-808	,	1212	},
{	8	,	-815	,	1214	},
{	8	,	-821	,	1214	},
{	8	,	-829	,	1217	},
{	9	,	-835	,	1218	},
{	9	,	-843	,	1220	},
{	9	,	-852	,	1223	},
{	8	,	-861	,	1224	},
{	7	,	-871	,	1228	},
{	7	,	-878	,	1229	},
{	7	,	-887	,	1230	},
{	6	,	-895	,	1230	},
{	4	,	-902	,	1229	},
{	2	,	-912	,	1232	},
{	0	,	-924	,	1235	},
{	-1	,	-934	,	1235	},
{	-3	,	-943	,	1234	},
{	-4	,	-953	,	1231	},
{	-4	,	-958	,	1232	},
{	-5	,	-964	,	1234	},
{	-6	,	-969	,	1233	},
{	-7	,	-975	,	1235	},
{	-8	,	-978	,	1232	},
{	-10	,	-984	,	1232	},
{	-11	,	-990	,	1231	},
{	-13	,	-995	,	1231	}
};

#endif	/* TABLE_LUGE7_SN126_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -10954)

int16_t accel_residual_offset[] = { -18,-7,-109 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-2,-3,6},
{-2,-3,6},
{-1,-4,14},
{0,-4,21},
{0,-5,19},
{0,-5,19},
{0,-5,19},
{0,-6,19},
{0,-7,19},
{1,-7,20},
{1,-7,20},
{1,-8,21},
{1,-8,21},
{1,-9,21},
{1,-9,22},
{2,-9,22},
{2,-10,23},
{2,-10,23},
{2,-11,23},
{2,-11,23},
{2,-11,23},
{2,-12,24},
{2,-12,24},
{2,-13,24},
{3,-13,24},
{3,-13,25},
{3,-14,25},
{3,-14,25},
{3,-15,25},
{3,-15,25},
{3,-16,25},
{3,-16,26},
{3,-16,25},
{4,-16,25},
{4,-17,26},
{4,-17,26},
{4,-17,26},
{4,-18,26},
{4,-18,26},
{4,-18,26},
{4,-19,26},
{4,-19,26},
{4,-19,26},
{4,-19,27},
{5,-20,27},
{5,-20,27},
{5,-20,27},
{5,-21,27},
{5,-21,27},
{5,-21,28},
{5,-21,29},
{5,-21,29},
{5,-22,29},
{5,-22,30},
{6,-22,30},
{6,-22,30},
{6,-23,30},
{6,-23,31},
{6,-23,31},
{6,-23,31},
{6,-24,31},
{6,-24,31},
{7,-24,31},
{7,-24,32},
{7,-25,32},
{7,-25,32},
{7,-25,33},
{7,-25,33},
{8,-25,33},
{8,-25,34},
{8,-25,34},
{8,-25,35},
{8,-25,35},
{8,-25,35},
{8,-25,35},
{8,-25,36},
{8,-25,36},
{8,-25,36},
{9,-25,36},
{9,-25,37},
{8,-25,37},
{8,-25,38},
{8,-25,39},
{8,-25,39},
{8,-25,39},
{8,-25,39},
{9,-25,40},
{9,-25,41},
{9,-25,41},
{8,-25,41},
{8,-25,41},
{9,-25,41},
{9,-25,41},
{9,-26,41},
{8,-26,42},
{8,-27,42},
{9,-27,42},
{9,-27,42},
{9,-28,42},
{8,-28,42},
{8,-28,42},
{9,-28,42},
{9,-29,43},
{9,-29,43},
{9,-29,43},
{9,-29,43},
{9,-29,44},
{9,-30,44},
{9,-30,44},
{9,-30,45},
{9,-30,45},
{9,-31,45},
{9,-31,45},
{9,-31,46},
{9,-31,46},
{9,-32,47},
{9,-32,47},
{9,-32,47},
{9,-32,48},
{9,-32,48},
{10,-33,49},
{10,-33,49},
{10,-33,50},
{10,-33,50},
{10,-33,50},
{10,-33,50},
{10,-34,51},
{10,-34,52},
{10,-34,52},
{10,-34,53},
{10,-34,53},
{10,-35,53},
{11,-35,53},
{11,-35,54},
{11,-35,54},
{11,-35,55},
{11,-36,55},
{11,-36,56},
{11,-36,56},
{11,-36,56},
{11,-37,57},
{11,-37,57},
{11,-37,58},
{11,-37,58},
{12,-37,59},
{12,-37,59},
{12,-38,59},
{12,-38,60},
{12,-38,60},
{12,-38,61},
{12,-39,61},
{13,-39,62},
{13,-39,62},
{13,-39,63},
{13,-40,63},
{13,-40,64},
{13,-40,64},
{13,-40,65},
{13,-40,65},
{13,-41,66},
{14,-41,66},
{14,-41,67},
{14,-41,67},
{14,-41,68},
{14,-42,69},
{14,-42,69},
{14,-42,70},
{15,-42,70},
{15,-42,71},
{15,-43,72},
{15,-43,72},
{15,-43,73},
{15,-43,73},
{15,-43,74},
{16,-44,75},
{16,-44,75},
{16,-44,76},
{16,-44,77},
{16,-44,77},
{16,-44,78},
{16,-45,79},
{16,-45,80},
{16,-45,81},
{17,-45,82},
{17,-46,83},
{17,-46,83},
{17,-46,84},
{17,-46,84},
{17,-47,84},
{17,-47,85},
{17,-47,85},
{17,-47,85},
{18,-48,86},
{18,-48,86},
{18,-48,86},
{18,-48,87},
{18,-48,87},
{18,-48,88},
{18,-49,88},
{18,-49,88},
{18,-49,89},
{18,-50,89},
{19,-50,90},
{18,-50,90},
{18,-50,91},
{18,-50,91},
{18,-51,92},
{19,-51,92},
{19,-51,93},
{19,-51,93},
{19,-51,94},
{19,-51,95},
{19,-51,95},
{19,-52,96},
{19,-52,97},
{19,-52,97},
{19,-52,98},
{19,-52,98},
{19,-52,99},
{19,-52,100},
{19,-52,101},
{19,-52,102},
{19,-52,103},
{19,-52,104},
{19,-52,105},
{19,-52,106},
{18,-52,105},
{18,-52,103},
{19,-53,102},
{19,-53,102},
{19,-53,102},
{19,-53,102},
{19,-54,102},
{19,-54,102},
{19,-54,101},
{19,-54,101},
{19,-55,101},
{19,-55,101},
{19,-55,101},
{20,-55,101},
{20,-56,101},
{20,-56,101},
{20,-56,101},
{20,-56,101},
{20,-57,101},
{21,-57,101},
{20,-57,102},
{20,-57,102},
{21,-58,103},
{21,-58,103},
{21,-58,103},
{21,-58,103},
{21,-59,103},
{22,-59,103},
{22,-59,103},
{22,-59,103},
{22,-59,103},
{22,-59,103},
{22,-60,103},
{23,-60,103},
{23,-60,103},
{23,-60,104},
{24,-60,106},
{25,-60,105},
{25,-60,102},
{25,-61,100},
{25,-61,100},
{25,-61,100},
{25,-61,100},
{25,-61,100},
{25,-62,100},
{25,-62,100},
{25,-63,101},
{26,-63,101},
{26,-63,101},
{25,-63,101},
{25,-64,102},
{26,-64,103},
{26,-64,104},
{26,-64,104},
};



