

#ifndef TABLE_LUGE7_SN137_H
#define	TABLE_LUGE7_SN137_H

// used in LUGE7_SN137 partition size 64

#define STEP_SIZE 64

#define X_CROSS_COUPLING 40
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0



#define TABLE_ORIGIN  ( -14552 )

int16_t residual_offset[] = { 701-887 , 643-426 , -277+22 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-937	,	2011	,	798	},
{	-925	,	1997	,	798	},
{	-914	,	1987	,	798	},
{	-903	,	1974	,	797	},
{	-895	,	1967	,	797	},
{	-887	,	1956	,	797	},
{	-881	,	1951	,	798	},
{	-874	,	1942	,	798	},
{	-867	,	1934	,	799	},
{	-831	,	1926	,	800	},
{	-827	,	1901	,	798	},
{	-815	,	1884	,	798	},
{	-804	,	1867	,	798	},
{	-792	,	1843	,	796	},
{	-782	,	1829	,	796	},
{	-770	,	1812	,	794	},
{	-756	,	1788	,	791	},
{	-744	,	1769	,	787	},
{	-735	,	1757	,	785	},
{	-725	,	1741	,	782	},
{	-716	,	1729	,	781	},
{	-705	,	1712	,	779	},
{	-695	,	1701	,	776	},
{	-683	,	1681	,	772	},
{	-672	,	1668	,	769	},
{	-662	,	1653	,	765	},
{	-651	,	1639	,	761	},
{	-640	,	1626	,	759	},
{	-630	,	1615	,	757	},
{	-618	,	1604	,	755	},
{	-608	,	1592	,	750	},
{	-597	,	1579	,	748	},
{	-585	,	1569	,	746	},
{	-575	,	1556	,	741	},
{	-564	,	1546	,	740	},
{	-552	,	1530	,	735	},
{	-541	,	1519	,	733	},
{	-528	,	1506	,	730	},
{	-519	,	1495	,	727	},
{	-508	,	1480	,	725	},
{	-498	,	1471	,	722	},
{	-486	,	1457	,	718	},
{	-474	,	1444	,	715	},
{	-461	,	1430	,	711	},
{	-450	,	1424	,	709	},
{	-438	,	1411	,	704	},
{	-426	,	1396	,	699	},
{	-414	,	1385	,	695	},
{	-404	,	1375	,	691	},
{	-391	,	1359	,	685	},
{	-380	,	1351	,	683	},
{	-369	,	1339	,	678	},
{	-358	,	1333	,	676	},
{	-348	,	1323	,	673	},
{	-338	,	1314	,	668	},
{	-326	,	1302	,	663	},
{	-315	,	1294	,	658	},
{	-303	,	1282	,	653	},
{	-293	,	1275	,	650	},
{	-282	,	1269	,	646	},
{	-272	,	1263	,	644	},
{	-261	,	1252	,	639	},
{	-250	,	1242	,	634	},
{	-241	,	1235	,	632	},
{	-231	,	1227	,	628	},
{	-219	,	1215	,	623	},
{	-209	,	1210	,	620	},
{	-198	,	1198	,	615	},
{	-188	,	1192	,	613	},
{	-178	,	1182	,	608	},
{	-167	,	1173	,	603	},
{	-156	,	1161	,	598	},
{	-147	,	1154	,	594	},
{	-136	,	1142	,	589	},
{	-129	,	1132	,	584	},
{	-119	,	1122	,	580	},
{	-111	,	1109	,	576	},
{	-103	,	1098	,	573	},
{	-94	,	1087	,	570	},
{	-87	,	1078	,	566	},
{	-79	,	1068	,	561	},
{	-72	,	1059	,	558	},
{	-66	,	1050	,	554	},
{	-60	,	1037	,	550	},
{	-54	,	1027	,	547	},
{	-49	,	1013	,	541	},
{	-42	,	1004	,	540	},
{	-36	,	992	,	538	},
{	-32	,	982	,	535	},
{	-27	,	970	,	532	},
{	-23	,	959	,	529	},
{	-17	,	948	,	527	},
{	-14	,	935	,	523	},
{	-11	,	925	,	520	},
{	-7	,	913	,	516	},
{	-5	,	902	,	511	},
{	-2	,	890	,	509	},
{	1	,	876	,	505	},
{	5	,	864	,	501	},
{	8	,	852	,	498	},
{	10	,	840	,	495	},
{	12	,	831	,	491	},
{	14	,	823	,	489	},
{	14	,	808	,	483	},
{	15	,	797	,	478	},
{	16	,	788	,	475	},
{	18	,	776	,	469	},
{	18	,	765	,	465	},
{	18	,	756	,	460	},
{	17	,	746	,	457	},
{	18	,	736	,	452	},
{	18	,	725	,	447	},
{	18	,	714	,	441	},
{	17	,	704	,	435	},
{	15	,	696	,	431	},
{	13	,	686	,	426	},
{	9	,	675	,	420	},
{	6	,	665	,	416	},
{	3	,	654	,	410	},
{	-3	,	644	,	405	},
{	-6	,	636	,	400	},
{	-10	,	625	,	394	},
{	-15	,	615	,	389	},
{	-21	,	609	,	384	},
{	-26	,	600	,	379	},
{	-32	,	592	,	374	},
{	-38	,	583	,	369	},
{	-45	,	573	,	363	},
{	-53	,	566	,	358	},
{	-62	,	559	,	353	},
{	-71	,	551	,	348	},
{	-80	,	544	,	342	},
{	-89	,	538	,	337	},
{	-98	,	530	,	331	},
{	-108	,	525	,	326	},
{	-118	,	518	,	321	},
{	-128	,	512	,	315	},
{	-139	,	506	,	309	},
{	-151	,	502	,	303	},
{	-163	,	498	,	297	},
{	-175	,	493	,	292	},
{	-187	,	490	,	288	},
{	-201	,	488	,	282	},
{	-213	,	485	,	276	},
{	-225	,	483	,	270	},
{	-238	,	480	,	264	},
{	-250	,	478	,	258	},
{	-263	,	476	,	253	},
{	-275	,	472	,	247	},
{	-287	,	467	,	241	},
{	-299	,	464	,	236	},
{	-310	,	460	,	230	},
{	-322	,	458	,	224	},
{	-332	,	453	,	216	},
{	-344	,	449	,	210	},
{	-353	,	444	,	206	},
{	-363	,	438	,	201	},
{	-374	,	433	,	195	},
{	-385	,	428	,	189	},
{	-393	,	423	,	183	},
{	-402	,	416	,	177	},
{	-410	,	411	,	172	},
{	-418	,	404	,	165	},
{	-426	,	398	,	160	},
{	-433	,	391	,	154	},
{	-441	,	386	,	149	},
{	-449	,	382	,	143	},
{	-457	,	377	,	137	},
{	-464	,	371	,	130	},
{	-470	,	364	,	124	},
{	-478	,	359	,	119	},
{	-485	,	352	,	114	},
{	-492	,	346	,	108	},
{	-499	,	340	,	102	},
{	-507	,	336	,	96	},
{	-512	,	329	,	90	},
{	-520	,	324	,	85	},
{	-527	,	319	,	79	},
{	-536	,	314	,	72	},
{	-543	,	310	,	67	},
{	-550	,	303	,	61	},
{	-557	,	298	,	56	},
{	-564	,	291	,	50	},
{	-570	,	283	,	44	},
{	-579	,	278	,	38	},
{	-587	,	273	,	33	},
{	-596	,	268	,	28	},
{	-604	,	262	,	22	},
{	-612	,	257	,	17	},
{	-621	,	251	,	11	},
{	-628	,	244	,	5	},
{	-635	,	236	,	-1	},
{	-644	,	229	,	-7	},
{	-653	,	223	,	-12	},
{	-661	,	216	,	-18	},
{	-670	,	211	,	-24	},
{	-678	,	204	,	-29	},
{	-686	,	198	,	-34	},
{	-694	,	192	,	-39	},
{	-703	,	187	,	-45	},
{	-713	,	183	,	-51	},
{	-720	,	177	,	-57	},
{	-730	,	171	,	-63	},
{	-739	,	165	,	-69	},
{	-748	,	159	,	-74	},
{	-757	,	154	,	-79	},
{	-768	,	150	,	-85	},
{	-776	,	144	,	-91	},
{	-785	,	140	,	-96	},
{	-794	,	136	,	-102	},
{	-803	,	130	,	-108	},
{	-811	,	125	,	-114	},
{	-819	,	121	,	-119	},
{	-828	,	117	,	-124	},
{	-839	,	113	,	-131	},
{	-847	,	110	,	-136	},
{	-857	,	106	,	-142	},
{	-868	,	102	,	-148	},
{	-875	,	97	,	-154	},
{	-882	,	93	,	-159	},
{	-891	,	89	,	-164	},
{	-901	,	84	,	-169	},
{	-912	,	79	,	-176	},
{	-920	,	74	,	-182	},
{	-928	,	70	,	-187	},
{	-939	,	65	,	-193	},
{	-948	,	60	,	-198	},
{	-959	,	56	,	-204	},
{	-971	,	51	,	-209	},
{	-983	,	45	,	-215	},
{	-993	,	40	,	-220	},
{	-1006	,	34	,	-226	},
{	-1019	,	29	,	-231	},
{	-1027	,	23	,	-236	},
{	-1037	,	18	,	-242	},
{	-1050	,	14	,	-248	},
{	-1065	,	10	,	-254	},
{	-1074	,	5	,	-259	},
{	-1086	,	0	,	-265	},
{	-1097	,	-5	,	-270	},
{	-1108	,	-9	,	-276	},
{	-1120	,	-16	,	-281	},
{	-1132	,	-21	,	-287	},
{	-1145	,	-25	,	-293	},
{	-1154	,	-29	,	-297	},
{	-1167	,	-34	,	-303	},
{	-1175	,	-39	,	-308	},
{	-1189	,	-44	,	-314	},
{	-1198	,	-50	,	-320	},
{	-1206	,	-55	,	-325	},
{	-1219	,	-61	,	-331	},
{	-1230	,	-66	,	-336	},
{	-1242	,	-72	,	-342	},
{	-1250	,	-79	,	-347	},
{	-1261	,	-85	,	-352	},
{	-1267	,	-93	,	-357	},
{	-1278	,	-99	,	-362	},
{	-1289	,	-105	,	-368	},
{	-1301	,	-110	,	-374	},
{	-1308	,	-115	,	-379	},
{	-1318	,	-121	,	-383	},
{	-1331	,	-128	,	-389	},
{	-1339	,	-133	,	-394	},
{	-1354	,	-140	,	-401	},
{	-1362	,	-145	,	-406	},
{	-1373	,	-151	,	-411	},
{	-1386	,	-157	,	-417	},
{	-1395	,	-163	,	-421	},
{	-1408	,	-170	,	-426	},
{	-1415	,	-174	,	-430	},
{	-1426	,	-175	,	-437	},
{	-1436	,	-176	,	-443	},
{	-1451	,	-177	,	-451	},
{	-1461	,	-177	,	-457	},
{	-1472	,	-178	,	-464	},
{	-1485	,	-177	,	-471	},
{	-1499	,	-177	,	-478	},
{	-1514	,	-176	,	-486	},
{	-1526	,	-175	,	-494	},
{	-1538	,	-175	,	-501	},
{	-1549	,	-174	,	-508	},
{	-1563	,	-173	,	-516	},
{	-1573	,	-172	,	-523	},
{	-1582	,	-171	,	-530	},
{	-1597	,	-171	,	-539	},
{	-1608	,	-173	,	-547	},
{	-1621	,	-177	,	-556	},
{	-1636	,	-182	,	-564	},
{	-1648	,	-187	,	-571	},
{	-1660	,	-193	,	-578	},
{	-1669	,	-199	,	-584	},
{	-1680	,	-206	,	-590	},
{	-1695	,	-214	,	-597	},
{	-1702	,	-220	,	-602	},
{	-1712	,	-227	,	-608	},
{	-1720	,	-234	,	-613	},
{	-1731	,	-242	,	-620	},
{	-1738	,	-248	,	-626	},
{	-1747	,	-256	,	-632	},
{	-1763	,	-262	,	-640	},
{	-1778	,	-268	,	-648	},
{	-1786	,	-275	,	-653	},
{	-1796	,	-278	,	-658	},
{	-1809	,	-281	,	-664	},
{	-1820	,	-285	,	-670	},
{	-1836	,	-290	,	-678	},
{	-1842	,	-293	,	-682	},
{	-1858	,	-297	,	-689	},
{	-1867	,	-300	,	-694	},
{	-1875	,	-304	,	-699	},
{	-1893	,	-309	,	-708	},
{	-1901	,	-314	,	-712	},
{	-1914	,	-319	,	-719	},
{	-1929	,	-325	,	-726	},
{	-1939	,	-330	,	-732	},
{	-1952	,	-336	,	-738	},
{	-1961	,	-341	,	-742	},
{	-1974	,	-346	,	-748	},
{	-1984	,	-351	,	-754	},
{	-1994	,	-356	,	-759	},
{	-2005	,	-362	,	-764	},
{	-2020	,	-370	,	-771	},
{	-2026	,	-377	,	-775	},
{	-2039	,	-382	,	-781	},
{	-2052	,	-388	,	-787	},
{	-2067	,	-396	,	-794	},
{	-2077	,	-401	,	-799	},
{	-2088	,	-408	,	-804	},
{	-2100	,	-415	,	-811	},
{	-2119	,	-422	,	-818	},
{	-2129	,	-428	,	-822	},
{	-2140	,	-435	,	-827	},
{	-2148	,	-441	,	-830	},
{	-2159	,	-448	,	-834	},
{	-2167	,	-456	,	-838	},
{	-2186	,	-466	,	-845	},
{	-2196	,	-471	,	-849	},
{	-2207	,	-479	,	-854	},
{	-2215	,	-485	,	-858	},
{	-2232	,	-493	,	-864	},
{	-2248	,	-501	,	-869	},
{	-2252	,	-507	,	-870	},
{	-2267	,	-515	,	-875	},
{	-2283	,	-525	,	-881	},
{	-2291	,	-532	,	-882	},
{	-2304	,	-542	,	-887	},
{	-2309	,	-549	,	-889	},
{	-2321	,	-557	,	-893	},
{	-2334	,	-566	,	-896	},
{	-2346	,	-574	,	-900	},
{	-2353	,	-581	,	-902	},
{	-2369	,	-590	,	-907	},
{	-2377	,	-597	,	-908	},
{	-2389	,	-607	,	-912	},
{	-2402	,	-617	,	-916	},
{	-2413	,	-626	,	-919	},
{	-2420	,	-634	,	-920	},
{	-2425	,	-643	,	-921	},
{	-2442	,	-655	,	-927	},
{	-2445	,	-664	,	-928	},
{	-2449	,	-672	,	-928	},
{	-2463	,	-683	,	-933	},
{	-2476	,	-694	,	-937	},
{	-2485	,	-704	,	-939	},
{	-2492	,	-713	,	-940	},
{	-2508	,	-725	,	-945	},
{	-2524	,	-737	,	-950	},
{	-2534	,	-748	,	-953	},
{	-2543	,	-758	,	-955	},
{	-2552	,	-770	,	-958	},
{	-2562	,	-782	,	-961	},
{	-2569	,	-791	,	-962	},
{	-2582	,	-803	,	-965	},
{	-2599	,	-813	,	-970	},
{	-2618	,	-823	,	-975	},
{	-2622	,	-829	,	-975	},
{	-2643	,	-841	,	-980	},
{	-2660	,	-851	,	-985	},
{	-2675	,	-861	,	-989	},
{	-2689	,	-869	,	-992	},
{	-2697	,	-877	,	-992	},
{	-2715	,	-888	,	-997	},
{	-2727	,	-897	,	-999	},
{	-2737	,	-907	,	-1002	},
{	-2754	,	-919	,	-1007	},
{	-2771	,	-931	,	-1011	},
{	-2783	,	-942	,	-1014	},
{	-2794	,	-947	,	-1016	},
{	-2805	,	-953	,	-1019	},
{	-2811	,	-956	,	-1020	},
{	-2813	,	-961	,	-1021	},
{	-2818	,	-967	,	-1022	},
{	-2835	,	-978	,	-1027	},
{	-2834	,	-982	,	-1026	},
{	-2841	,	-990	,	-1028	}
};

#endif	/* TABLE_LUGE7_SN137_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11156)

int16_t accel_residual_offset[] = { -17+2,-33+3,-88-4 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{9,4,0},
{9,4,0},
{9,4,0},
{9,4,-1},
{8,4,-2},
{8,3,1},
{10,2,10},
{11,2,11},
{11,2,9},
{11,2,9},
{11,2,9},
{11,1,9},
{12,1,9},
{12,1,10},
{13,1,11},
{12,1,11},
{12,0,12},
{12,0,12},
{13,0,12},
{13,0,13},
{13,0,14},
{13,0,14},
{13,0,14},
{13,0,15},
{13,0,15},
{13,-1,16},
{13,-1,16},
{14,-1,16},
{13,-1,16},
{13,-1,16},
{14,-2,17},
{14,-2,17},
{14,-2,17},
{14,-2,17},
{14,-3,17},
{14,-2,17},
{14,-2,18},
{14,-3,18},
{14,-3,18},
{14,-4,18},
{14,-4,18},
{14,-4,18},
{14,-4,18},
{14,-4,18},
{15,-4,18},
{15,-4,18},
{14,-4,18},
{14,-5,19},
{15,-5,19},
{15,-5,19},
{15,-5,19},
{15,-6,19},
{15,-6,19},
{15,-6,19},
{15,-6,19},
{15,-6,20},
{15,-6,20},
{15,-6,20},
{15,-6,21},
{15,-7,21},
{16,-7,21},
{16,-7,21},
{16,-7,22},
{16,-7,22},
{16,-7,22},
{16,-7,23},
{16,-7,23},
{16,-7,23},
{16,-7,24},
{16,-7,24},
{16,-7,24},
{16,-7,25},
{16,-7,25},
{16,-7,25},
{17,-7,26},
{17,-7,26},
{17,-7,26},
{17,-7,27},
{17,-7,27},
{17,-7,27},
{17,-6,27},
{17,-6,27},
{17,-6,28},
{17,-6,29},
{17,-6,29},
{17,-6,29},
{17,-5,30},
{17,-5,30},
{18,-5,31},
{17,-5,31},
{17,-5,31},
{18,-4,32},
{18,-4,32},
{18,-4,32},
{18,-4,33},
{18,-4,33},
{18,-4,33},
{18,-4,33},
{18,-5,33},
{17,-5,34},
{17,-5,34},
{18,-5,34},
{18,-5,35},
{18,-5,35},
{18,-6,35},
{18,-6,35},
{18,-6,35},
{18,-6,35},
{18,-6,35},
{18,-6,36},
{18,-6,36},
{18,-7,37},
{18,-7,37},
{18,-7,37},
{18,-7,37},
{18,-7,38},
{18,-7,38},
{18,-7,38},
{18,-7,39},
{18,-7,39},
{18,-7,39},
{18,-7,40},
{19,-7,40},
{19,-7,40},
{19,-7,41},
{19,-7,41},
{19,-7,41},
{19,-7,42},
{19,-7,42},
{19,-7,42},
{19,-7,43},
{19,-7,43},
{19,-7,44},
{19,-7,44},
{19,-7,44},
{19,-7,45},
{19,-7,46},
{19,-7,46},
{19,-7,46},
{19,-7,47},
{19,-8,48},
{19,-8,48},
{19,-8,48},
{19,-8,49},
{19,-8,49},
{19,-8,50},
{19,-8,50},
{19,-8,51},
{19,-8,51},
{19,-8,52},
{19,-8,52},
{19,-8,53},
{19,-8,53},
{19,-8,54},
{19,-8,54},
{20,-8,55},
{20,-8,56},
{20,-8,56},
{20,-8,56},
{20,-8,57},
{20,-8,57},
{20,-8,58},
{20,-8,58},
{20,-8,59},
{20,-8,59},
{20,-8,60},
{20,-8,60},
{20,-8,61},
{20,-8,61},
{20,-8,62},
{20,-9,62},
{20,-9,63},
{20,-9,64},
{20,-9,64},
{20,-9,65},
{20,-9,65},
{20,-9,66},
{20,-9,66},
{20,-9,67},
{20,-9,68},
{20,-9,68},
{20,-9,69},
{20,-9,70},
{20,-9,70},
{20,-9,71},
{21,-9,72},
{21,-10,72},
{21,-10,73},
{21,-10,74},
{21,-10,75},
{21,-10,76},
{21,-10,76},
{21,-10,76},
{21,-10,76},
{21,-10,77},
{21,-10,77},
{21,-10,77},
{21,-10,78},
{21,-11,78},
{21,-11,78},
{21,-11,79},
{21,-11,79},
{21,-11,80},
{21,-11,80},
{21,-11,80},
{21,-11,81},
{21,-11,81},
{21,-11,82},
{21,-11,82},
{20,-11,83},
{20,-11,83},
{20,-11,84},
{20,-11,84},
{20,-11,85},
{20,-11,86},
{21,-11,86},
{21,-11,87},
{21,-11,88},
{21,-11,88},
{20,-11,89},
{20,-11,90},
{20,-11,91},
{20,-11,92},
{20,-10,92},
{20,-10,93},
{21,-10,94},
{21,-10,95},
{20,-10,96},
{20,-10,97},
{20,-9,98},
{20,-9,99},
{20,-9,100},
{20,-9,100},
{20,-9,101},
{20,-9,100},
{20,-9,100},
{20,-9,100},
{19,-9,100},
{19,-9,100},
{19,-9,100},
{19,-9,99},
{20,-10,98},
{20,-10,98},
{20,-10,98},
{20,-10,97},
{19,-10,97},
{19,-10,97},
{19,-11,98},
{19,-10,97},
{20,-10,97},
{20,-11,97},
{19,-11,97},
{19,-11,97},
{20,-11,97},
{20,-11,97},
{19,-11,98},
{19,-11,98},
{20,-11,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,98},
{20,-12,99},
{20,-12,99},
{20,-12,99},
{20,-12,99},
{20,-13,99},
{20,-13,99},
{20,-13,99},
{20,-13,99},
{20,-13,99},
{20,-13,99},
{20,-13,100},
{21,-13,100},
};



