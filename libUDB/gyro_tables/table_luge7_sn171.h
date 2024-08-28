

#ifndef TABLE_LUGE7_SN171_H
#define	TABLE_LUGE7_SN171_H

// used in LUGE7_SN171 partition size 64

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14776 )

int16_t residual_offset[] = { -879 -4*80 +4*19 , 264 +4*117 -4*73 , -239 -4*48 +4*27 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-458	,	-3983	,	158	},
{	-453	,	-3976	,	156	},
{	-448	,	-3981	,	154	},
{	-442	,	-3985	,	153	},
{	-435	,	-3983	,	151	},
{	-428	,	-3977	,	150	},
{	-420	,	-3965	,	148	},
{	-416	,	-3965	,	147	},
{	-410	,	-3963	,	146	},
{	-401	,	-3967	,	143	},
{	-387	,	-3952	,	140	},
{	-375	,	-3938	,	137	},
{	-364	,	-3940	,	135	},
{	-352	,	-3920	,	132	},
{	-339	,	-3908	,	129	},
{	-327	,	-3895	,	126	},
{	-318	,	-3895	,	124	},
{	-306	,	-3878	,	121	},
{	-296	,	-3869	,	119	},
{	-284	,	-3857	,	117	},
{	-275	,	-3839	,	113	},
{	-265	,	-3822	,	111	},
{	-256	,	-3815	,	109	},
{	-249	,	-3811	,	106	},
{	-237	,	-3802	,	103	},
{	-227	,	-3787	,	101	},
{	-215	,	-3776	,	98	},
{	-206	,	-3764	,	95	},
{	-197	,	-3763	,	93	},
{	-186	,	-3746	,	89	},
{	-178	,	-3745	,	87	},
{	-169	,	-3730	,	84	},
{	-161	,	-3724	,	82	},
{	-150	,	-3711	,	77	},
{	-141	,	-3709	,	75	},
{	-131	,	-3702	,	72	},
{	-122	,	-3692	,	69	},
{	-111	,	-3685	,	67	},
{	-103	,	-3679	,	64	},
{	-94	,	-3667	,	61	},
{	-86	,	-3663	,	58	},
{	-79	,	-3652	,	56	},
{	-71	,	-3643	,	53	},
{	-63	,	-3634	,	51	},
{	-54	,	-3627	,	48	},
{	-44	,	-3616	,	45	},
{	-36	,	-3604	,	42	},
{	-25	,	-3594	,	39	},
{	-16	,	-3584	,	35	},
{	-6	,	-3577	,	32	},
{	2	,	-3564	,	30	},
{	12	,	-3554	,	28	},
{	21	,	-3536	,	24	},
{	30	,	-3529	,	21	},
{	38	,	-3521	,	19	},
{	48	,	-3509	,	16	},
{	57	,	-3498	,	13	},
{	68	,	-3489	,	10	},
{	79	,	-3480	,	6	},
{	88	,	-3473	,	4	},
{	98	,	-3466	,	2	},
{	105	,	-3453	,	-1	},
{	112	,	-3446	,	-2	},
{	119	,	-3440	,	-5	},
{	125	,	-3433	,	-8	},
{	131	,	-3424	,	-11	},
{	140	,	-3419	,	-14	},
{	148	,	-3405	,	-17	},
{	156	,	-3395	,	-20	},
{	163	,	-3389	,	-23	},
{	172	,	-3375	,	-25	},
{	182	,	-3361	,	-28	},
{	190	,	-3352	,	-31	},
{	197	,	-3352	,	-33	},
{	205	,	-3334	,	-36	},
{	214	,	-3321	,	-40	},
{	222	,	-3317	,	-43	},
{	229	,	-3310	,	-45	},
{	238	,	-3313	,	-48	},
{	246	,	-3295	,	-52	},
{	255	,	-3286	,	-55	},
{	265	,	-3277	,	-57	},
{	273	,	-3264	,	-59	},
{	280	,	-3251	,	-62	},
{	287	,	-3241	,	-65	},
{	294	,	-3229	,	-67	},
{	304	,	-3229	,	-69	},
{	310	,	-3218	,	-71	},
{	317	,	-3217	,	-73	},
{	326	,	-3207	,	-75	},
{	335	,	-3185	,	-77	},
{	343	,	-3179	,	-80	},
{	352	,	-3174	,	-83	},
{	362	,	-3158	,	-85	},
{	371	,	-3146	,	-88	},
{	383	,	-3132	,	-91	},
{	393	,	-3123	,	-95	},
{	401	,	-3106	,	-98	},
{	410	,	-3095	,	-102	},
{	420	,	-3090	,	-104	},
{	428	,	-3079	,	-107	},
{	439	,	-3076	,	-110	},
{	449	,	-3068	,	-113	},
{	457	,	-3059	,	-116	},
{	465	,	-3051	,	-119	},
{	471	,	-3036	,	-123	},
{	478	,	-3031	,	-126	},
{	483	,	-3022	,	-129	},
{	488	,	-3014	,	-131	},
{	492	,	-3002	,	-134	},
{	495	,	-2990	,	-137	},
{	500	,	-2982	,	-140	},
{	501	,	-2970	,	-143	},
{	503	,	-2959	,	-145	},
{	507	,	-2953	,	-147	},
{	510	,	-2945	,	-149	},
{	513	,	-2934	,	-153	},
{	515	,	-2922	,	-155	},
{	517	,	-2913	,	-158	},
{	519	,	-2906	,	-161	},
{	520	,	-2892	,	-164	},
{	524	,	-2886	,	-167	},
{	526	,	-2876	,	-170	},
{	528	,	-2864	,	-172	},
{	531	,	-2858	,	-175	},
{	533	,	-2844	,	-178	},
{	534	,	-2827	,	-180	},
{	537	,	-2824	,	-184	},
{	536	,	-2813	,	-187	},
{	537	,	-2805	,	-191	},
{	539	,	-2796	,	-195	},
{	538	,	-2786	,	-199	},
{	537	,	-2770	,	-202	},
{	536	,	-2760	,	-205	},
{	537	,	-2756	,	-209	},
{	536	,	-2739	,	-213	},
{	535	,	-2727	,	-216	},
{	534	,	-2710	,	-220	},
{	533	,	-2696	,	-223	},
{	530	,	-2685	,	-227	},
{	528	,	-2676	,	-230	},
{	526	,	-2663	,	-234	},
{	524	,	-2654	,	-238	},
{	524	,	-2646	,	-242	},
{	522	,	-2627	,	-246	},
{	520	,	-2611	,	-248	},
{	516	,	-2593	,	-251	},
{	511	,	-2580	,	-253	},
{	508	,	-2565	,	-256	},
{	504	,	-2549	,	-260	},
{	499	,	-2535	,	-264	},
{	492	,	-2515	,	-267	},
{	483	,	-2500	,	-270	},
{	476	,	-2483	,	-272	},
{	469	,	-2474	,	-276	},
{	459	,	-2450	,	-279	},
{	453	,	-2437	,	-282	},
{	444	,	-2421	,	-286	},
{	436	,	-2409	,	-290	},
{	428	,	-2388	,	-294	},
{	418	,	-2372	,	-299	},
{	408	,	-2359	,	-302	},
{	399	,	-2347	,	-306	},
{	392	,	-2333	,	-310	},
{	385	,	-2317	,	-314	},
{	377	,	-2303	,	-318	},
{	371	,	-2290	,	-322	},
{	363	,	-2272	,	-325	},
{	357	,	-2261	,	-330	},
{	352	,	-2249	,	-334	},
{	345	,	-2234	,	-338	},
{	338	,	-2220	,	-342	},
{	332	,	-2206	,	-345	},
{	328	,	-2194	,	-350	},
{	323	,	-2178	,	-353	},
{	317	,	-2162	,	-356	},
{	312	,	-2149	,	-359	},
{	306	,	-2136	,	-362	},
{	301	,	-2121	,	-366	},
{	297	,	-2106	,	-371	},
{	290	,	-2089	,	-374	},
{	286	,	-2079	,	-379	},
{	282	,	-2063	,	-383	},
{	276	,	-2048	,	-386	},
{	270	,	-2033	,	-389	},
{	266	,	-2021	,	-393	},
{	262	,	-2005	,	-396	},
{	258	,	-1993	,	-401	},
{	253	,	-1977	,	-404	},
{	249	,	-1965	,	-408	},
{	244	,	-1947	,	-411	},
{	237	,	-1930	,	-414	},
{	232	,	-1917	,	-419	},
{	226	,	-1901	,	-424	},
{	222	,	-1886	,	-428	},
{	216	,	-1869	,	-431	},
{	211	,	-1856	,	-434	},
{	206	,	-1839	,	-437	},
{	201	,	-1820	,	-439	},
{	196	,	-1806	,	-442	},
{	191	,	-1794	,	-446	},
{	187	,	-1781	,	-450	},
{	181	,	-1762	,	-451	},
{	176	,	-1747	,	-455	},
{	172	,	-1730	,	-458	},
{	167	,	-1713	,	-461	},
{	163	,	-1700	,	-464	},
{	159	,	-1687	,	-469	},
{	157	,	-1673	,	-474	},
{	153	,	-1655	,	-476	},
{	150	,	-1640	,	-479	},
{	148	,	-1625	,	-482	},
{	146	,	-1610	,	-486	},
{	142	,	-1597	,	-490	},
{	139	,	-1585	,	-494	},
{	136	,	-1572	,	-497	},
{	133	,	-1558	,	-502	},
{	129	,	-1544	,	-505	},
{	128	,	-1527	,	-509	},
{	126	,	-1513	,	-514	},
{	123	,	-1502	,	-518	},
{	119	,	-1489	,	-521	},
{	115	,	-1471	,	-524	},
{	112	,	-1457	,	-528	},
{	108	,	-1440	,	-530	},
{	103	,	-1426	,	-533	},
{	100	,	-1412	,	-538	},
{	98	,	-1399	,	-543	},
{	93	,	-1383	,	-546	},
{	90	,	-1369	,	-550	},
{	88	,	-1353	,	-553	},
{	85	,	-1339	,	-559	},
{	81	,	-1325	,	-563	},
{	78	,	-1310	,	-566	},
{	76	,	-1294	,	-570	},
{	72	,	-1280	,	-574	},
{	69	,	-1261	,	-576	},
{	67	,	-1245	,	-580	},
{	63	,	-1231	,	-585	},
{	60	,	-1217	,	-588	},
{	58	,	-1202	,	-592	},
{	56	,	-1186	,	-596	},
{	53	,	-1171	,	-598	},
{	51	,	-1157	,	-601	},
{	48	,	-1143	,	-604	},
{	45	,	-1128	,	-607	},
{	43	,	-1113	,	-610	},
{	39	,	-1100	,	-614	},
{	36	,	-1085	,	-615	},
{	34	,	-1070	,	-619	},
{	32	,	-1056	,	-623	},
{	28	,	-1043	,	-626	},
{	25	,	-1031	,	-629	},
{	23	,	-1019	,	-634	},
{	19	,	-1004	,	-636	},
{	17	,	-992	,	-640	},
{	15	,	-981	,	-646	},
{	13	,	-966	,	-650	},
{	10	,	-955	,	-654	},
{	8	,	-944	,	-659	},
{	5	,	-929	,	-662	},
{	2	,	-917	,	-665	},
{	-1	,	-907	,	-669	},
{	-4	,	-896	,	-673	},
{	-7	,	-882	,	-675	},
{	-9	,	-870	,	-679	},
{	-12	,	-860	,	-683	},
{	-15	,	-846	,	-685	},
{	-17	,	-835	,	-690	},
{	-19	,	-821	,	-692	},
{	-23	,	-809	,	-695	},
{	-27	,	-797	,	-699	},
{	-29	,	-782	,	-701	},
{	-34	,	-769	,	-703	},
{	-39	,	-758	,	-708	},
{	-43	,	-745	,	-712	},
{	-47	,	-732	,	-714	},
{	-51	,	-721	,	-718	},
{	-54	,	-707	,	-721	},
{	-58	,	-694	,	-725	},
{	-62	,	-681	,	-730	},
{	-65	,	-668	,	-734	},
{	-68	,	-655	,	-738	},
{	-74	,	-641	,	-740	},
{	-78	,	-630	,	-745	},
{	-83	,	-616	,	-747	},
{	-88	,	-604	,	-752	},
{	-92	,	-591	,	-755	},
{	-96	,	-578	,	-758	},
{	-101	,	-566	,	-762	},
{	-105	,	-553	,	-765	},
{	-108	,	-540	,	-767	},
{	-113	,	-526	,	-769	},
{	-117	,	-513	,	-771	},
{	-122	,	-499	,	-774	},
{	-126	,	-486	,	-776	},
{	-130	,	-472	,	-776	},
{	-135	,	-460	,	-778	},
{	-140	,	-447	,	-780	},
{	-144	,	-434	,	-782	},
{	-149	,	-422	,	-786	},
{	-153	,	-408	,	-789	},
{	-155	,	-396	,	-792	},
{	-158	,	-382	,	-794	},
{	-162	,	-368	,	-797	},
{	-165	,	-355	,	-801	},
{	-169	,	-342	,	-804	},
{	-172	,	-329	,	-809	},
{	-175	,	-314	,	-811	},
{	-177	,	-309	,	-813	},
{	-178	,	-302	,	-815	},
{	-179	,	-296	,	-817	},
{	-181	,	-290	,	-819	},
{	-183	,	-283	,	-823	},
{	-184	,	-275	,	-824	},
{	-184	,	-268	,	-827	},
{	-187	,	-261	,	-830	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -12664)

int16_t accel_residual_offset[] = { 3 , -11 , -170 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-8,1,-2},
{-8,0,-3},
{-8,0,-5},
{-8,0,-6},
{-8,0,-7},
{-8,0,-8},
{-8,0,-9},
{-8,0,-10},
{-9,0,-10},
{-8,0,-11},
{-8,-1,-12},
{-7,-2,-6},
{-6,-2,0},
{-5,-2,-2},
{-4,-2,-4},
{-4,-2,-5},
{-4,-3,-5},
{-4,-3,-5},
{-4,-3,-6},
{-4,-4,-5},
{-4,-4,-5},
{-3,-4,-5},
{-3,-4,-5},
{-3,-5,-5},
{-3,-5,-5},
{-3,-5,-4},
{-3,-6,-4},
{-2,-6,-4},
{-2,-6,-4},
{-2,-6,-3},
{-2,-7,-3},
{-2,-7,-3},
{-2,-7,-3},
{-2,-8,-2},
{-2,-8,-2},
{-2,-8,-1},
{-1,-8,-1},
{-1,-9,0},
{-1,-9,0},
{-1,-9,0},
{-1,-9,0},
{0,-9,0},
{0,-10,0},
{0,-11,0},
{0,-11,0},
{0,-10,0},
{0,-11,1},
{0,-11,1},
{0,-11,1},
{0,-12,1},
{0,-12,2},
{0,-13,2},
{0,-13,3},
{0,-13,3},
{1,-13,3},
{0,-14,3},
{0,-13,4},
{0,-13,4},
{1,-14,4},
{1,-14,4},
{1,-14,5},
{2,-14,5},
{2,-15,5},
{2,-15,5},
{2,-15,6},
{2,-15,6},
{2,-16,6},
{2,-16,7},
{2,-16,7},
{2,-16,8},
{2,-16,8},
{3,-16,8},
{3,-16,8},
{3,-17,9},
{3,-17,9},
{3,-18,9},
{3,-18,10},
{3,-18,10},
{4,-18,10},
{4,-18,10},
{4,-18,11},
{5,-19,11},
{5,-19,12},
{5,-19,12},
{5,-19,12},
{5,-19,12},
{5,-19,12},
{5,-19,13},
{5,-19,13},
{6,-19,13},
{6,-19,14},
{6,-20,14},
{6,-20,14},
{6,-19,15},
{7,-19,15},
{7,-20,15},
{7,-19,15},
{8,-19,16},
{8,-20,16},
{8,-19,16},
{8,-19,17},
{8,-19,17},
{8,-19,17},
{8,-19,18},
{9,-19,18},
{9,-19,18},
{9,-19,19},
{9,-19,19},
{9,-19,19},
{9,-19,19},
{10,-19,19},
{10,-19,19},
{10,-19,19},
{10,-19,19},
{10,-19,19},
{10,-19,19},
{10,-19,19},
{10,-19,19},
{10,-20,20},
{11,-20,19},
{11,-20,19},
{11,-20,19},
{11,-20,19},
{11,-21,19},
{12,-21,19},
{12,-21,20},
{12,-22,20},
{12,-22,20},
{12,-22,20},
{13,-22,20},
{13,-22,21},
{13,-22,21},
{14,-22,21},
{14,-22,21},
{14,-23,22},
{15,-23,22},
{15,-23,23},
{15,-23,24},
{15,-23,24},
{15,-23,24},
{15,-23,25},
{16,-24,25},
{16,-24,26},
{16,-24,26},
{16,-24,27},
{17,-24,27},
{17,-25,28},
{17,-25,28},
{17,-25,28},
{17,-25,28},
{18,-25,29},
{18,-25,29},
{18,-25,30},
{19,-26,30},
{19,-26,30},
{19,-26,31},
{20,-26,31},
{20,-26,32},
{20,-26,32},
{20,-26,32},
{21,-27,33},
{21,-27,33},
{22,-27,34},
{22,-27,34},
{22,-27,34},
{22,-28,35},
{22,-28,35},
{23,-28,36},
{23,-28,36},
{23,-28,36},
{24,-28,36},
{24,-28,37},
{25,-29,37},
{25,-29,37},
{25,-29,38},
{25,-29,38},
{26,-30,38},
{26,-30,39},
{26,-30,39},
{26,-30,39},
{26,-30,40},
{26,-30,40},
{26,-31,40},
{26,-31,41},
{26,-31,41},
{26,-31,41},
{26,-31,41},
{26,-32,41},
{26,-32,42},
{26,-32,42},
{26,-32,42},
{26,-32,42},
{26,-33,42},
{26,-33,43},
{26,-33,43},
{26,-33,43},
{27,-33,43},
{27,-33,44},
{27,-34,44},
{28,-34,44},
{28,-34,44},
{28,-34,45},
{28,-34,45},
{29,-34,45},
{29,-34,45},
{29,-35,45},
{29,-35,46},
{30,-35,46},
{30,-35,46},
{30,-35,46},
{30,-36,46},
{31,-36,46},
{31,-36,46},
{31,-37,46},
{31,-37,46},
{31,-37,46},
{32,-37,46},
{32,-37,46},
{32,-37,46},
{33,-38,46},
{33,-38,46},
{33,-38,45},
{34,-38,45},
{34,-38,45},
{34,-38,45},
{35,-38,45},
{35,-38,45},
{35,-38,45},
{35,-38,45},
{35,-38,45},
{36,-38,45},
{36,-38,46},
{36,-38,46},
{37,-38,46},
{37,-38,45},
{37,-38,45},
{37,-38,45},
{37,-39,45},
{37,-39,45},
{38,-39,46},
{38,-39,45},
{38,-39,45},
{38,-39,46},
{39,-39,46},
{39,-39,46},
{39,-39,46},
{39,-38,46},
{40,-38,46},
{40,-38,46},
{40,-38,46},
{40,-38,47},
{40,-38,47},
{41,-38,47},
{41,-38,47},
{41,-37,48},
{41,-37,48},
{41,-37,48},
{42,-37,48},
{42,-37,49},
{42,-36,49},
};


#endif	/* TABLE_LUGE7_SN171_H */

