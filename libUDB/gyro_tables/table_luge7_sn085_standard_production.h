

#ifndef TABLE_LUGE7_SN085_H
#define	TABLE_LUGE7_SN085_H

// used in LUGE7_SN085 partition size 64

#define X_CROSS_COUPLING 26
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64

#define TABLE_ORIGIN  (  -14528 )

int16_t residual_offset[] = { (-424 -329 -4*91 + 4*53 ), ( -32 + 685 -4*160 + 4*108 ) , (-256 -377 + 4*89 - 4*65 ) } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	883	,	-1220	,	-332	},
{	879	,	-1213	,	-326	},
{	878	,	-1213	,	-319	},
{	878	,	-1212	,	-314	},
{	878	,	-1211	,	-310	},
{	877	,	-1210	,	-305	},
{	877	,	-1210	,	-301	},
{	878	,	-1210	,	-298	},
{	877	,	-1208	,	-295	},
{	877	,	-1209	,	-286	},
{	876	,	-1207	,	-277	},
{	875	,	-1204	,	-269	},
{	875	,	-1206	,	-261	},
{	873	,	-1203	,	-254	},
{	872	,	-1202	,	-246	},
{	874	,	-1201	,	-240	},
{	873	,	-1197	,	-232	},
{	871	,	-1195	,	-224	},
{	872	,	-1197	,	-216	},
{	871	,	-1194	,	-210	},
{	871	,	-1194	,	-203	},
{	871	,	-1192	,	-195	},
{	871	,	-1190	,	-189	},
{	872	,	-1192	,	-181	},
{	871	,	-1189	,	-173	},
{	870	,	-1187	,	-164	},
{	871	,	-1187	,	-158	},
{	871	,	-1186	,	-149	},
{	872	,	-1187	,	-141	},
{	871	,	-1184	,	-133	},
{	870	,	-1179	,	-124	},
{	872	,	-1179	,	-117	},
{	871	,	-1175	,	-110	},
{	870	,	-1174	,	-102	},
{	869	,	-1170	,	-93	},
{	869	,	-1168	,	-86	},
{	872	,	-1169	,	-78	},
{	870	,	-1165	,	-72	},
{	870	,	-1162	,	-64	},
{	872	,	-1161	,	-57	},
{	872	,	-1155	,	-49	},
{	872	,	-1155	,	-41	},
{	873	,	-1154	,	-34	},
{	874	,	-1149	,	-27	},
{	876	,	-1148	,	-21	},
{	878	,	-1147	,	-15	},
{	879	,	-1143	,	-7	},
{	881	,	-1145	,	-1	},
{	880	,	-1141	,	6	},
{	883	,	-1143	,	14	},
{	886	,	-1142	,	22	},
{	887	,	-1140	,	29	},
{	890	,	-1137	,	37	},
{	890	,	-1133	,	44	},
{	891	,	-1131	,	53	},
{	892	,	-1130	,	59	},
{	891	,	-1125	,	66	},
{	893	,	-1124	,	72	},
{	893	,	-1119	,	78	},
{	896	,	-1117	,	85	},
{	897	,	-1117	,	92	},
{	897	,	-1113	,	98	},
{	898	,	-1111	,	104	},
{	901	,	-1110	,	111	},
{	903	,	-1109	,	116	},
{	904	,	-1107	,	122	},
{	906	,	-1104	,	126	},
{	906	,	-1100	,	131	},
{	907	,	-1097	,	136	},
{	908	,	-1095	,	140	},
{	911	,	-1094	,	146	},
{	917	,	-1095	,	152	},
{	917	,	-1093	,	157	},
{	918	,	-1092	,	164	},
{	921	,	-1093	,	171	},
{	922	,	-1093	,	178	},
{	923	,	-1094	,	184	},
{	923	,	-1092	,	189	},
{	925	,	-1092	,	195	},
{	924	,	-1089	,	201	},
{	924	,	-1089	,	207	},
{	924	,	-1087	,	213	},
{	925	,	-1086	,	219	},
{	926	,	-1082	,	226	},
{	927	,	-1081	,	231	},
{	932	,	-1082	,	234	},
{	937	,	-1083	,	238	},
{	937	,	-1080	,	240	},
{	935	,	-1075	,	241	},
{	937	,	-1073	,	245	},
{	940	,	-1074	,	247	},
{	939	,	-1070	,	248	},
{	941	,	-1069	,	250	},
{	940	,	-1064	,	251	},
{	943	,	-1061	,	254	},
{	941	,	-1057	,	256	},
{	946	,	-1056	,	259	},
{	946	,	-1052	,	261	},
{	947	,	-1048	,	263	},
{	951	,	-1048	,	265	},
{	948	,	-1044	,	267	},
{	948	,	-1042	,	269	},
{	942	,	-1037	,	271	},
{	939	,	-1033	,	275	},
{	936	,	-1032	,	279	},
{	936	,	-1030	,	282	},
{	935	,	-1028	,	285	},
{	933	,	-1025	,	288	},
{	931	,	-1023	,	292	},
{	927	,	-1019	,	295	},
{	927	,	-1020	,	300	},
{	926	,	-1018	,	304	},
{	925	,	-1017	,	307	},
{	922	,	-1015	,	311	},
{	919	,	-1013	,	315	},
{	916	,	-1011	,	320	},
{	911	,	-1007	,	324	},
{	914	,	-1009	,	329	},
{	910	,	-1004	,	332	},
{	911	,	-1006	,	339	},
{	908	,	-1003	,	343	},
{	907	,	-1000	,	349	},
{	905	,	-999	,	354	},
{	903	,	-997	,	360	},
{	902	,	-995	,	368	},
{	899	,	-991	,	373	},
{	900	,	-991	,	378	},
{	896	,	-986	,	382	},
{	891	,	-983	,	387	},
{	890	,	-983	,	394	},
{	885	,	-977	,	398	},
{	884	,	-978	,	402	},
{	882	,	-975	,	405	},
{	881	,	-972	,	407	},
{	876	,	-967	,	410	},
{	874	,	-964	,	414	},
{	871	,	-958	,	416	},
{	867	,	-953	,	418	},
{	863	,	-948	,	419	},
{	859	,	-944	,	420	},
{	856	,	-940	,	422	},
{	851	,	-936	,	422	},
{	848	,	-931	,	423	},
{	843	,	-927	,	423	},
{	840	,	-921	,	424	},
{	838	,	-916	,	425	},
{	835	,	-913	,	425	},
{	832	,	-908	,	427	},
{	828	,	-902	,	430	},
{	821	,	-894	,	432	},
{	818	,	-891	,	435	},
{	812	,	-885	,	436	},
{	809	,	-882	,	439	},
{	803	,	-875	,	440	},
{	799	,	-871	,	442	},
{	796	,	-868	,	446	},
{	791	,	-860	,	447	},
{	786	,	-856	,	449	},
{	780	,	-849	,	450	},
{	776	,	-844	,	452	},
{	770	,	-836	,	454	},
{	764	,	-832	,	457	},
{	757	,	-825	,	457	},
{	749	,	-815	,	458	},
{	747	,	-811	,	459	},
{	738	,	-802	,	457	},
{	734	,	-797	,	459	},
{	727	,	-789	,	459	},
{	720	,	-781	,	460	},
{	713	,	-773	,	459	},
{	707	,	-767	,	461	},
{	700	,	-759	,	461	},
{	693	,	-752	,	462	},
{	689	,	-748	,	465	},
{	681	,	-738	,	464	},
{	678	,	-735	,	468	},
{	670	,	-727	,	468	},
{	666	,	-721	,	470	},
{	661	,	-716	,	472	},
{	656	,	-709	,	475	},
{	651	,	-704	,	477	},
{	644	,	-696	,	479	},
{	637	,	-691	,	481	},
{	631	,	-684	,	483	},
{	625	,	-679	,	485	},
{	620	,	-672	,	487	},
{	614	,	-666	,	489	},
{	609	,	-660	,	492	},
{	604	,	-656	,	494	},
{	597	,	-649	,	493	},
{	591	,	-643	,	495	},
{	586	,	-639	,	499	},
{	578	,	-631	,	499	},
{	574	,	-628	,	502	},
{	567	,	-621	,	503	},
{	561	,	-616	,	505	},
{	551	,	-611	,	505	},
{	543	,	-604	,	505	},
{	538	,	-598	,	507	},
{	533	,	-594	,	509	},
{	526	,	-588	,	511	},
{	520	,	-581	,	512	},
{	514	,	-576	,	514	},
{	509	,	-572	,	517	},
{	502	,	-566	,	519	},
{	495	,	-560	,	520	},
{	491	,	-556	,	524	},
{	485	,	-550	,	525	},
{	476	,	-543	,	525	},
{	471	,	-539	,	528	},
{	464	,	-532	,	530	},
{	460	,	-526	,	532	},
{	453	,	-520	,	534	},
{	450	,	-516	,	538	},
{	446	,	-510	,	539	},
{	440	,	-504	,	538	},
{	435	,	-498	,	539	},
{	429	,	-492	,	540	},
{	424	,	-487	,	540	},
{	420	,	-481	,	541	},
{	414	,	-474	,	540	},
{	409	,	-469	,	541	},
{	403	,	-462	,	541	},
{	397	,	-456	,	541	},
{	392	,	-450	,	541	},
{	388	,	-445	,	543	},
{	380	,	-437	,	541	},
{	374	,	-431	,	540	},
{	368	,	-425	,	541	},
{	363	,	-418	,	540	},
{	358	,	-410	,	538	},
{	352	,	-404	,	538	},
{	346	,	-398	,	539	},
{	340	,	-393	,	540	},
{	334	,	-387	,	541	},
{	329	,	-382	,	542	},
{	324	,	-378	,	543	},
{	316	,	-373	,	545	},
{	311	,	-366	,	545	},
{	305	,	-362	,	545	},
{	298	,	-357	,	546	},
{	292	,	-351	,	547	},
{	288	,	-346	,	547	},
{	285	,	-341	,	547	},
{	280	,	-336	,	548	},
{	273	,	-332	,	548	},
{	270	,	-327	,	550	},
{	266	,	-322	,	550	},
{	261	,	-317	,	550	},
{	258	,	-313	,	552	},
{	253	,	-306	,	552	},
{	250	,	-302	,	554	},
{	245	,	-297	,	555	},
{	240	,	-292	,	554	},
{	238	,	-286	,	554	},
{	234	,	-282	,	556	},
{	231	,	-276	,	557	},
{	228	,	-271	,	556	},
{	225	,	-266	,	558	},
{	221	,	-260	,	556	},
{	217	,	-255	,	557	},
{	213	,	-250	,	557	},
{	212	,	-246	,	557	},
{	207	,	-241	,	556	},
{	203	,	-236	,	556	},
{	200	,	-232	,	556	},
{	196	,	-226	,	554	},
{	192	,	-220	,	554	},
{	188	,	-215	,	552	},
{	184	,	-209	,	551	},
{	179	,	-203	,	552	},
{	175	,	-197	,	550	},
{	170	,	-192	,	549	},
{	166	,	-187	,	550	},
{	161	,	-180	,	548	},
{	157	,	-174	,	546	},
{	152	,	-168	,	548	},
{	145	,	-162	,	549	},
{	141	,	-156	,	548	},
{	135	,	-149	,	549	},
{	129	,	-142	,	550	},
{	123	,	-135	,	550	},
{	117	,	-129	,	552	},
{	110	,	-122	,	551	},
{	104	,	-118	,	552	},
{	98	,	-112	,	553	},
{	92	,	-106	,	553	},
{	87	,	-101	,	551	},
{	80	,	-95	,	551	},
{	74	,	-89	,	550	},
{	68	,	-83	,	550	},
{	62	,	-78	,	550	},
{	56	,	-73	,	550	},
{	51	,	-68	,	548	},
{	46	,	-63	,	545	},
{	40	,	-58	,	544	},
{	34	,	-52	,	543	},
{	28	,	-47	,	542	},
{	21	,	-41	,	542	},
{	16	,	-35	,	542	},
{	11	,	-30	,	543	},
{	5	,	-25	,	541	},
{	0	,	-18	,	540	},
{	-6	,	-12	,	539	},
{	-12	,	-6	,	539	},
{	-17	,	1	,	541	},
{	-23	,	8	,	543	},
{	-29	,	14	,	541	},
{	-35	,	21	,	542	},
{	-41	,	29	,	543	},
{	-47	,	37	,	544	},
{	-53	,	45	,	546	},
{	-59	,	53	,	548	},
{	-65	,	61	,	547	},
{	-71	,	69	,	547	},
{	-76	,	76	,	546	},
{	-83	,	83	,	546	},
{	-90	,	92	,	546	},
{	-96	,	100	,	548	},
{	-103	,	108	,	547	},
{	-109	,	116	,	549	},
{	-115	,	124	,	550	},
{	-122	,	132	,	549	},
{	-128	,	141	,	551	},
{	-135	,	149	,	552	},
{	-141	,	158	,	552	},
{	-147	,	165	,	551	},
{	-153	,	173	,	552	},
{	-156	,	177	,	552	},
{	-159	,	181	,	552	},
{	-163	,	184	,	553	},
{	-165	,	187	,	553	},
{	-169	,	191	,	554	},
{	-172	,	195	,	554	},
{	-174	,	199	,	554	},
{	-177	,	203	,	554	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11750)

int16_t accel_residual_offset[] = {  -23 +3 , -21 -9, -71 -12 } ; 

//3,-9,-12


const struct gyro_offset_table_entry accel_offset_table[] = {
{0,-2,0},
{0,-2,0},
{0,-2,-1},
{0,-2,-2},
{0,-2,-3},
{0,-3,-5},
{0,-3,0},
{2,-2,4},
{3,-2,2},
{3,-3,0},
{3,-3,0},
{4,-3,0},
{4,-3,0},
{4,-4,-1},
{4,-3,-1},
{5,-3,-1},
{5,-4,-1},
{5,-4,-1},
{5,-4,0},
{5,-4,0},
{6,-4,0},
{6,-5,0},
{6,-5,0},
{6,-5,0},
{7,-5,0},
{8,-5,0},
{7,-6,0},
{7,-6,0},
{8,-6,1},
{8,-6,1},
{8,-6,1},
{8,-7,1},
{8,-7,1},
{9,-7,2},
{9,-7,2},
{9,-7,3},
{10,-8,3},
{9,-7,3},
{9,-7,4},
{9,-8,4},
{10,-8,4},
{10,-8,4},
{11,-9,5},
{11,-9,6},
{11,-9,6},
{11,-9,7},
{11,-9,7},
{12,-9,7},
{12,-9,7},
{12,-9,7},
{12,-9,8},
{13,-9,8},
{13,-9,8},
{12,-9,8},
{12,-9,9},
{13,-9,9},
{13,-9,9},
{13,-9,9},
{14,-9,10},
{14,-9,11},
{14,-10,11},
{14,-10,11},
{14,-10,12},
{15,-10,12},
{15,-10,12},
{15,-10,13},
{15,-10,13},
{15,-10,13},
{15,-10,14},
{16,-10,14},
{17,-10,14},
{16,-10,15},
{16,-10,15},
{17,-10,16},
{17,-10,16},
{17,-10,16},
{17,-10,17},
{17,-10,17},
{18,-10,17},
{18,-10,18},
{18,-10,18},
{18,-10,19},
{18,-10,19},
{19,-10,19},
{19,-10,20},
{19,-10,20},
{19,-10,20},
{19,-10,21},
{20,-10,22},
{20,-10,22},
{20,-10,22},
{20,-10,22},
{20,-9,23},
{20,-9,23},
{20,-9,23},
{20,-9,24},
{21,-8,24},
{21,-8,25},
{21,-7,25},
{21,-7,25},
{21,-6,26},
{21,-6,26},
{21,-6,26},
{21,-6,26},
{21,-5,27},
{21,-5,27},
{22,-6,28},
{22,-6,28},
{21,-6,28},
{21,-6,28},
{21,-6,28},
{21,-6,29},
{21,-7,28},
{21,-7,28},
{21,-7,28},
{21,-8,28},
{21,-8,28},
{21,-8,29},
{21,-8,29},
{21,-8,29},
{21,-9,29},
{21,-9,29},
{21,-9,29},
{21,-9,29},
{21,-9,29},
{21,-9,30},
{22,-10,30},
{22,-9,31},
{22,-9,31},
{22,-10,32},
{22,-10,32},
{22,-10,32},
{22,-10,33},
{22,-10,33},
{22,-10,33},
{22,-10,34},
{22,-10,34},
{22,-10,35},
{22,-10,35},
{22,-10,36},
{22,-10,36},
{22,-10,37},
{22,-11,37},
{22,-10,38},
{22,-10,38},
{22,-11,39},
{22,-11,39},
{22,-11,40},
{22,-11,40},
{22,-11,41},
{22,-11,41},
{22,-11,42},
{22,-11,42},
{22,-11,43},
{22,-11,43},
{22,-11,44},
{22,-11,44},
{22,-11,45},
{22,-11,45},
{22,-12,46},
{22,-12,46},
{23,-12,47},
{23,-12,48},
{23,-12,48},
{22,-12,48},
{22,-12,49},
{22,-12,49},
{22,-12,50},
{22,-13,50},
{22,-13,51},
{23,-13,51},
{23,-13,51},
{23,-13,52},
{23,-13,52},
{23,-13,53},
{23,-13,53},
{23,-14,53},
{23,-14,54},
{23,-14,54},
{23,-14,54},
{23,-14,54},
{23,-14,55},
{23,-15,55},
{23,-15,56},
{23,-15,56},
{23,-15,56},
{23,-15,57},
{23,-15,57},
{23,-15,57},
{23,-15,57},
{23,-15,58},
{23,-16,58},
{22,-16,58},
{22,-16,59},
{22,-16,59},
{22,-16,59},
{22,-16,59},
{22,-16,60},
{22,-16,60},
{23,-16,60},
{22,-17,61},
{22,-17,61},
{22,-17,62},
{22,-17,62},
{22,-17,62},
{22,-17,62},
{22,-17,63},
{22,-18,63},
{22,-18,63},
{22,-18,64},
{22,-18,64},
{22,-18,64},
{22,-18,64},
{22,-18,65},
{22,-19,65},
{22,-19,65},
{22,-19,65},
{21,-19,66},
{21,-20,66},
{21,-20,66},
{21,-20,66},
{21,-20,66},
{21,-20,67},
{21,-21,67},
{21,-21,67},
{21,-21,67},
{21,-21,68},
{21,-21,68},
{21,-21,68},
{21,-21,68},
{21,-21,69},
{21,-21,69},
{21,-21,69},
{21,-21,69},
{21,-21,69},
{21,-21,70},
{21,-21,70},
{21,-20,70},
{20,-20,71},
{20,-20,71},
{20,-19,72},
{20,-19,73},
};




#endif	/* TABLE_LUGE7_SN085_H */

