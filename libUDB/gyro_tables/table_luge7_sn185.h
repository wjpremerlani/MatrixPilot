

#ifndef TABLE_LUGE7_SN185_H
#define	TABLE_LUGE7_SN185_H

// used in LUGE7_SN185 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14301 )

int16_t residual_offset[] = { -473 , 466 , -169 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1102	,	-3151	,	-389	},
{	-1096	,	-3156	,	-388	},
{	-1087	,	-3153	,	-385	},
{	-1083	,	-3161	,	-384	},
{	-1075	,	-3156	,	-382	},
{	-1067	,	-3155	,	-378	},
{	-1058	,	-3152	,	-375	},
{	-1050	,	-3149	,	-372	},
{	-1042	,	-3150	,	-369	},
{	-1031	,	-3157	,	-365	},
{	-1019	,	-3161	,	-360	},
{	-1003	,	-3151	,	-354	},
{	-990	,	-3154	,	-349	},
{	-977	,	-3150	,	-342	},
{	-963	,	-3145	,	-336	},
{	-950	,	-3142	,	-332	},
{	-936	,	-3138	,	-327	},
{	-924	,	-3137	,	-320	},
{	-912	,	-3132	,	-313	},
{	-900	,	-3127	,	-308	},
{	-888	,	-3121	,	-301	},
{	-879	,	-3125	,	-297	},
{	-869	,	-3123	,	-292	},
{	-860	,	-3121	,	-287	},
{	-851	,	-3123	,	-283	},
{	-838	,	-3112	,	-277	},
{	-828	,	-3108	,	-273	},
{	-817	,	-3100	,	-267	},
{	-807	,	-3100	,	-262	},
{	-796	,	-3092	,	-257	},
{	-784	,	-3090	,	-253	},
{	-773	,	-3089	,	-249	},
{	-761	,	-3084	,	-245	},
{	-748	,	-3077	,	-240	},
{	-737	,	-3076	,	-237	},
{	-725	,	-3072	,	-234	},
{	-715	,	-3074	,	-229	},
{	-703	,	-3069	,	-225	},
{	-688	,	-3056	,	-220	},
{	-675	,	-3051	,	-216	},
{	-663	,	-3047	,	-212	},
{	-651	,	-3043	,	-207	},
{	-641	,	-3044	,	-203	},
{	-628	,	-3036	,	-198	},
{	-617	,	-3035	,	-195	},
{	-607	,	-3037	,	-191	},
{	-595	,	-3031	,	-187	},
{	-583	,	-3028	,	-184	},
{	-568	,	-3019	,	-178	},
{	-556	,	-3015	,	-173	},
{	-545	,	-3014	,	-169	},
{	-534	,	-3013	,	-165	},
{	-523	,	-3010	,	-160	},
{	-510	,	-3003	,	-155	},
{	-498	,	-2995	,	-151	},
{	-488	,	-2994	,	-146	},
{	-477	,	-2993	,	-142	},
{	-469	,	-2999	,	-137	},
{	-456	,	-2985	,	-133	},
{	-445	,	-2986	,	-128	},
{	-434	,	-2986	,	-124	},
{	-422	,	-2980	,	-119	},
{	-410	,	-2968	,	-113	},
{	-400	,	-2972	,	-107	},
{	-389	,	-2967	,	-102	},
{	-380	,	-2964	,	-99	},
{	-370	,	-2963	,	-94	},
{	-360	,	-2962	,	-90	},
{	-348	,	-2947	,	-85	},
{	-338	,	-2942	,	-80	},
{	-328	,	-2939	,	-77	},
{	-318	,	-2937	,	-72	},
{	-307	,	-2938	,	-67	},
{	-294	,	-2932	,	-63	},
{	-279	,	-2913	,	-59	},
{	-268	,	-2917	,	-56	},
{	-255	,	-2903	,	-53	},
{	-244	,	-2895	,	-49	},
{	-234	,	-2889	,	-47	},
{	-222	,	-2886	,	-43	},
{	-211	,	-2883	,	-41	},
{	-200	,	-2878	,	-37	},
{	-188	,	-2875	,	-33	},
{	-176	,	-2862	,	-30	},
{	-164	,	-2858	,	-25	},
{	-153	,	-2858	,	-23	},
{	-141	,	-2856	,	-19	},
{	-128	,	-2851	,	-15	},
{	-114	,	-2849	,	-12	},
{	-102	,	-2840	,	-9	},
{	-92	,	-2832	,	-5	},
{	-81	,	-2830	,	-3	},
{	-69	,	-2817	,	0	},
{	-59	,	-2820	,	3	},
{	-48	,	-2815	,	6	},
{	-36	,	-2816	,	9	},
{	-26	,	-2811	,	11	},
{	-16	,	-2799	,	13	},
{	-5	,	-2795	,	16	},
{	3	,	-2788	,	19	},
{	12	,	-2784	,	22	},
{	22	,	-2773	,	24	},
{	31	,	-2769	,	28	},
{	40	,	-2766	,	31	},
{	47	,	-2760	,	34	},
{	53	,	-2751	,	36	},
{	59	,	-2745	,	39	},
{	67	,	-2743	,	42	},
{	73	,	-2745	,	46	},
{	78	,	-2745	,	50	},
{	84	,	-2735	,	55	},
{	90	,	-2735	,	58	},
{	96	,	-2730	,	62	},
{	101	,	-2725	,	66	},
{	108	,	-2726	,	72	},
{	112	,	-2726	,	76	},
{	118	,	-2729	,	80	},
{	124	,	-2728	,	84	},
{	128	,	-2721	,	88	},
{	132	,	-2720	,	93	},
{	137	,	-2707	,	96	},
{	142	,	-2703	,	100	},
{	146	,	-2699	,	104	},
{	151	,	-2693	,	108	},
{	154	,	-2693	,	112	},
{	156	,	-2682	,	117	},
{	160	,	-2678	,	120	},
{	165	,	-2673	,	124	},
{	169	,	-2660	,	127	},
{	173	,	-2651	,	130	},
{	175	,	-2643	,	134	},
{	175	,	-2637	,	137	},
{	179	,	-2632	,	140	},
{	180	,	-2619	,	142	},
{	180	,	-2609	,	145	},
{	181	,	-2609	,	148	},
{	181	,	-2595	,	149	},
{	182	,	-2589	,	152	},
{	182	,	-2585	,	155	},
{	181	,	-2578	,	159	},
{	180	,	-2573	,	162	},
{	179	,	-2562	,	166	},
{	177	,	-2554	,	169	},
{	176	,	-2547	,	172	},
{	172	,	-2539	,	176	},
{	169	,	-2532	,	180	},
{	165	,	-2526	,	184	},
{	162	,	-2519	,	186	},
{	160	,	-2504	,	189	},
{	155	,	-2493	,	192	},
{	151	,	-2485	,	195	},
{	147	,	-2473	,	197	},
{	142	,	-2464	,	201	},
{	139	,	-2454	,	203	},
{	134	,	-2445	,	205	},
{	129	,	-2433	,	207	},
{	123	,	-2422	,	209	},
{	118	,	-2410	,	211	},
{	114	,	-2399	,	213	},
{	110	,	-2388	,	214	},
{	104	,	-2373	,	215	},
{	97	,	-2359	,	215	},
{	90	,	-2350	,	217	},
{	82	,	-2337	,	218	},
{	75	,	-2322	,	219	},
{	70	,	-2316	,	222	},
{	63	,	-2300	,	223	},
{	55	,	-2289	,	225	},
{	50	,	-2281	,	227	},
{	45	,	-2264	,	228	},
{	39	,	-2257	,	230	},
{	33	,	-2245	,	233	},
{	27	,	-2235	,	235	},
{	23	,	-2224	,	237	},
{	18	,	-2214	,	238	},
{	13	,	-2201	,	240	},
{	6	,	-2192	,	242	},
{	2	,	-2180	,	243	},
{	-2	,	-2178	,	246	},
{	-5	,	-2164	,	247	},
{	-9	,	-2153	,	248	},
{	-12	,	-2147	,	250	},
{	-16	,	-2135	,	251	},
{	-18	,	-2130	,	253	},
{	-19	,	-2120	,	255	},
{	-22	,	-2107	,	256	},
{	-26	,	-2104	,	258	},
{	-30	,	-2090	,	260	},
{	-33	,	-2079	,	262	},
{	-37	,	-2068	,	263	},
{	-41	,	-2059	,	265	},
{	-45	,	-2047	,	266	},
{	-49	,	-2038	,	268	},
{	-50	,	-2028	,	270	},
{	-52	,	-2023	,	273	},
{	-56	,	-2009	,	275	},
{	-59	,	-2002	,	278	},
{	-61	,	-1998	,	282	},
{	-64	,	-1991	,	285	},
{	-67	,	-1982	,	287	},
{	-71	,	-1973	,	289	},
{	-74	,	-1963	,	290	},
{	-78	,	-1961	,	293	},
{	-81	,	-1949	,	294	},
{	-82	,	-1943	,	297	},
{	-85	,	-1935	,	299	},
{	-87	,	-1931	,	302	},
{	-89	,	-1923	,	304	},
{	-92	,	-1915	,	306	},
{	-94	,	-1907	,	308	},
{	-98	,	-1898	,	309	},
{	-100	,	-1890	,	312	},
{	-102	,	-1883	,	313	},
{	-103	,	-1875	,	314	},
{	-105	,	-1862	,	315	},
{	-109	,	-1858	,	317	},
{	-110	,	-1851	,	318	},
{	-113	,	-1842	,	320	},
{	-115	,	-1836	,	321	},
{	-117	,	-1827	,	323	},
{	-118	,	-1819	,	325	},
{	-121	,	-1812	,	327	},
{	-122	,	-1805	,	328	},
{	-123	,	-1795	,	329	},
{	-125	,	-1787	,	330	},
{	-126	,	-1782	,	332	},
{	-127	,	-1774	,	333	},
{	-128	,	-1766	,	334	},
{	-130	,	-1759	,	336	},
{	-130	,	-1754	,	338	},
{	-131	,	-1746	,	340	},
{	-132	,	-1743	,	342	},
{	-130	,	-1729	,	343	},
{	-130	,	-1722	,	346	},
{	-129	,	-1712	,	348	},
{	-130	,	-1704	,	351	},
{	-129	,	-1693	,	351	},
{	-128	,	-1687	,	354	},
{	-127	,	-1674	,	355	},
{	-127	,	-1668	,	358	},
{	-127	,	-1662	,	360	},
{	-128	,	-1650	,	361	},
{	-128	,	-1640	,	362	},
{	-128	,	-1632	,	364	},
{	-130	,	-1627	,	366	},
{	-130	,	-1620	,	367	},
{	-132	,	-1607	,	367	},
{	-133	,	-1599	,	368	},
{	-134	,	-1591	,	369	},
{	-136	,	-1583	,	370	},
{	-139	,	-1576	,	370	},
{	-141	,	-1568	,	371	},
{	-143	,	-1560	,	371	},
{	-146	,	-1559	,	374	},
{	-150	,	-1551	,	374	},
{	-153	,	-1546	,	375	},
{	-157	,	-1538	,	375	},
{	-163	,	-1532	,	376	},
{	-165	,	-1528	,	378	},
{	-169	,	-1522	,	380	},
{	-173	,	-1517	,	381	},
{	-176	,	-1508	,	383	},
{	-178	,	-1501	,	385	},
{	-181	,	-1493	,	386	},
{	-184	,	-1485	,	388	},
{	-187	,	-1478	,	390	},
{	-190	,	-1468	,	391	},
{	-192	,	-1458	,	392	},
{	-194	,	-1451	,	394	},
{	-197	,	-1443	,	395	},
{	-199	,	-1431	,	396	},
{	-202	,	-1423	,	398	},
{	-206	,	-1414	,	400	},
{	-207	,	-1406	,	401	},
{	-209	,	-1395	,	403	},
{	-212	,	-1387	,	404	},
{	-215	,	-1380	,	406	},
{	-216	,	-1370	,	407	},
{	-219	,	-1365	,	410	},
{	-223	,	-1356	,	412	},
{	-225	,	-1348	,	414	},
{	-228	,	-1343	,	416	},
{	-232	,	-1335	,	417	},
{	-235	,	-1330	,	420	},
{	-238	,	-1324	,	422	},
{	-242	,	-1317	,	424	},
{	-246	,	-1308	,	425	},
{	-250	,	-1302	,	426	},
{	-253	,	-1294	,	427	},
{	-255	,	-1287	,	429	},
{	-258	,	-1281	,	431	},
{	-261	,	-1275	,	434	},
{	-262	,	-1266	,	435	},
{	-265	,	-1260	,	437	},
{	-266	,	-1251	,	439	},
{	-269	,	-1242	,	440	},
{	-270	,	-1233	,	441	},
{	-274	,	-1230	,	443	},
{	-277	,	-1219	,	443	},
{	-279	,	-1211	,	444	},
{	-281	,	-1203	,	445	},
{	-284	,	-1192	,	447	},
{	-286	,	-1184	,	447	},
{	-288	,	-1177	,	449	},
{	-292	,	-1170	,	450	},
{	-295	,	-1159	,	451	},
{	-299	,	-1154	,	453	},
{	-302	,	-1143	,	452	},
{	-306	,	-1136	,	452	},
{	-311	,	-1130	,	454	},
{	-316	,	-1122	,	454	},
{	-319	,	-1119	,	454	},
{	-322	,	-1115	,	454	},
{	-324	,	-1111	,	454	},
{	-327	,	-1104	,	454	},
{	-330	,	-1102	,	455	},
{	-333	,	-1098	,	455	},
{	-336	,	-1095	,	456	},
{	-338	,	-1092	,	455	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11627)

int16_t accel_residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{3,-4,-1},
{3,-4,0},
{2,-4,0},
{2,-4,-1},
{2,-4,-1},
{3,-5,3},
{4,-5,8},
{5,-5,6},
{5,-5,6},
{5,-5,6},
{5,-5,6},
{6,-5,6},
{6,-6,6},
{6,-6,6},
{6,-6,6},
{7,-6,7},
{7,-7,7},
{7,-6,7},
{7,-6,7},
{7,-7,8},
{7,-7,8},
{7,-7,9},
{7,-7,9},
{7,-7,9},
{7,-7,10},
{8,-7,10},
{8,-7,11},
{8,-8,11},
{8,-8,11},
{8,-8,11},
{9,-9,12},
{9,-8,12},
{9,-8,13},
{9,-9,13},
{9,-9,14},
{9,-9,14},
{9,-9,14},
{9,-9,14},
{10,-9,15},
{10,-9,15},
{10,-9,16},
{10,-9,16},
{11,-10,17},
{11,-10,17},
{11,-10,17},
{11,-10,17},
{11,-10,18},
{11,-11,18},
{11,-11,19},
{11,-11,19},
{11,-11,19},
{12,-11,19},
{12,-11,20},
{12,-11,20},
{12,-11,20},
{12,-12,21},
{12,-11,21},
{12,-11,21},
{12,-12,21},
{13,-12,22},
{13,-12,23},
{13,-12,23},
{13,-12,23},
{13,-12,23},
{14,-12,24},
{14,-12,24},
{14,-12,25},
{14,-12,25},
{14,-12,25},
{14,-13,26},
{14,-13,26},
{14,-13,27},
{15,-13,28},
{15,-13,28},
{15,-13,28},
{15,-13,29},
{15,-13,29},
{15,-13,29},
{15,-13,29},
{16,-13,30},
{16,-13,30},
{16,-13,30},
{16,-13,31},
{16,-13,31},
{16,-13,31},
{16,-13,32},
{16,-13,32},
{16,-13,32},
{17,-13,32},
{17,-13,33},
{17,-13,33},
{17,-12,33},
{17,-12,34},
{17,-12,35},
{17,-12,35},
{17,-12,35},
{18,-12,35},
{18,-11,35},
{18,-11,36},
{18,-11,36},
{18,-11,36},
{18,-11,37},
{18,-11,37},
{19,-10,37},
{19,-10,37},
{19,-10,37},
{19,-10,37},
{19,-10,37},
{19,-10,37},
{19,-10,38},
{19,-10,38},
{19,-10,37},
{19,-11,37},
{19,-11,37},
{19,-11,37},
{19,-11,37},
{19,-11,37},
{19,-11,37},
{18,-11,36},
{18,-12,36},
{18,-12,36},
{18,-12,36},
{18,-12,36},
{18,-12,36},
{18,-12,36},
{18,-12,36},
{18,-12,36},
{18,-12,36},
{19,-12,36},
{19,-13,36},
{18,-13,37},
{18,-13,37},
{18,-13,37},
{18,-13,37},
{19,-13,38},
{19,-13,38},
{18,-13,38},
{18,-13,38},
{19,-13,39},
{19,-13,39},
{19,-14,39},
{19,-14,40},
{18,-14,40},
{18,-14,40},
{19,-14,40},
{19,-14,41},
{19,-14,41},
{19,-14,41},
{19,-15,41},
{19,-15,42},
{19,-15,42},
{19,-15,42},
{19,-15,43},
{19,-15,43},
{19,-15,43},
{19,-16,44},
{19,-16,44},
{19,-16,45},
{19,-16,45},
{19,-16,45},
{19,-16,45},
{19,-17,46},
{19,-17,46},
{19,-17,47},
{19,-17,47},
{19,-17,47},
{19,-17,48},
{19,-17,48},
{19,-18,49},
{19,-18,49},
{19,-18,49},
{19,-18,50},
{19,-18,50},
{19,-18,51},
{19,-19,51},
{19,-19,52},
{19,-19,52},
{20,-19,53},
{20,-19,53},
{20,-19,54},
{20,-20,54},
{20,-20,55},
{20,-20,55},
{20,-20,56},
{20,-20,56},
{19,-20,56},
{19,-21,57},
{20,-21,58},
{20,-21,58},
{20,-21,59},
{20,-21,59},
{19,-21,60},
{19,-22,60},
{19,-22,61},
{19,-22,61},
{19,-22,62},
{19,-22,63},
{19,-23,63},
{19,-23,63},
{19,-23,64},
{19,-23,64},
{19,-23,64},
{19,-23,65},
{19,-24,65},
{19,-24,65},
{19,-24,66},
{19,-24,66},
{19,-24,66},
{19,-24,67},
{19,-25,67},
{19,-25,67},
{19,-25,68},
{19,-25,68},
{19,-25,68},
{19,-25,69},
{19,-26,69},
{19,-26,69},
{19,-26,70},
{19,-26,70},
{19,-26,71},
{19,-26,71},
{19,-26,72},
{19,-26,72},
{19,-27,73},
{19,-27,73},
{19,-27,74},
{19,-27,75},
{19,-27,75},
{19,-27,76},
{19,-27,76},
{19,-27,77},
{19,-27,78},
{19,-27,79},
{19,-27,79},
{19,-27,80},
{19,-27,81},
{19,-27,81},
{19,-27,82},
{19,-27,82},
{18,-27,82},
{18,-27,83},
{18,-27,83},
{18,-26,84},
};



#endif	/* TABLE_LUGE7_SN185_H */

