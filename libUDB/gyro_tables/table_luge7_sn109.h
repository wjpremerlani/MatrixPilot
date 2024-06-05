

#ifndef TABLE_LUGE7_SN109_H
#define	TABLE_LUGE7_SN109_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14827 )

int16_t residual_offset[] = { 215 , -278 , 183 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	2996	,	-1896	,	1487	},
{	3139	,	-1889	,	1478	},
{	3094	,	-1887	,	1467	},
{	3072	,	-1889	,	1464	},
{	3064	,	-1898	,	1466	},
{	3043	,	-1896	,	1460	},
{	3035	,	-1901	,	1459	},
{	3022	,	-1901	,	1455	},
{	3011	,	-1901	,	1452	},
{	3017	,	-1911	,	1451	},
{	3000	,	-1904	,	1438	},
{	2997	,	-1907	,	1434	},
{	2979	,	-1900	,	1422	},
{	2971	,	-1899	,	1414	},
{	2958	,	-1894	,	1404	},
{	2950	,	-1892	,	1395	},
{	2940	,	-1890	,	1388	},
{	2903	,	-1881	,	1375	},
{	2807	,	-1882	,	1370	},
{	2810	,	-1877	,	1364	},
{	2804	,	-1870	,	1355	},
{	2793	,	-1859	,	1344	},
{	2788	,	-1851	,	1336	},
{	2774	,	-1839	,	1322	},
{	2767	,	-1830	,	1313	},
{	2763	,	-1824	,	1304	},
{	2749	,	-1810	,	1291	},
{	2749	,	-1806	,	1286	},
{	2735	,	-1793	,	1273	},
{	2735	,	-1789	,	1267	},
{	2730	,	-1782	,	1257	},
{	2716	,	-1771	,	1245	},
{	2710	,	-1763	,	1236	},
{	2703	,	-1754	,	1226	},
{	2706	,	-1753	,	1219	},
{	2696	,	-1742	,	1208	},
{	2692	,	-1736	,	1200	},
{	2684	,	-1725	,	1189	},
{	2676	,	-1716	,	1179	},
{	2676	,	-1714	,	1173	},
{	2670	,	-1706	,	1164	},
{	2666	,	-1701	,	1156	},
{	2657	,	-1691	,	1146	},
{	2653	,	-1685	,	1139	},
{	2648	,	-1678	,	1129	},
{	2646	,	-1673	,	1123	},
{	2641	,	-1666	,	1114	},
{	2638	,	-1660	,	1106	},
{	2639	,	-1655	,	1100	},
{	2626	,	-1644	,	1088	},
{	2626	,	-1640	,	1081	},
{	2614	,	-1628	,	1070	},
{	2611	,	-1622	,	1062	},
{	2605	,	-1614	,	1053	},
{	2606	,	-1612	,	1047	},
{	2601	,	-1605	,	1038	},
{	2591	,	-1594	,	1026	},
{	2589	,	-1588	,	1019	},
{	2584	,	-1580	,	1010	},
{	2581	,	-1575	,	1001	},
{	2579	,	-1570	,	993	},
{	2566	,	-1558	,	981	},
{	2559	,	-1551	,	970	},
{	2551	,	-1542	,	961	},
{	2545	,	-1535	,	952	},
{	2537	,	-1528	,	942	},
{	2536	,	-1523	,	936	},
{	2522	,	-1512	,	925	},
{	2517	,	-1506	,	917	},
{	2517	,	-1502	,	911	},
{	2512	,	-1496	,	903	},
{	2497	,	-1484	,	891	},
{	2493	,	-1480	,	883	},
{	2487	,	-1473	,	875	},
{	2482	,	-1467	,	866	},
{	2475	,	-1460	,	857	},
{	2464	,	-1451	,	847	},
{	2459	,	-1445	,	839	},
{	2457	,	-1442	,	832	},
{	2454	,	-1435	,	824	},
{	2449	,	-1429	,	816	},
{	2439	,	-1419	,	806	},
{	2433	,	-1413	,	797	},
{	2426	,	-1405	,	789	},
{	2421	,	-1399	,	780	},
{	2419	,	-1394	,	772	},
{	2412	,	-1387	,	761	},
{	2406	,	-1380	,	753	},
{	2408	,	-1377	,	746	},
{	2400	,	-1369	,	737	},
{	2397	,	-1363	,	729	},
{	2387	,	-1353	,	720	},
{	2388	,	-1350	,	713	},
{	2388	,	-1345	,	706	},
{	2382	,	-1338	,	698	},
{	2377	,	-1331	,	691	},
{	2374	,	-1327	,	685	},
{	2369	,	-1320	,	678	},
{	2369	,	-1316	,	672	},
{	2367	,	-1312	,	666	},
{	2362	,	-1306	,	659	},
{	2363	,	-1303	,	654	},
{	2351	,	-1293	,	644	},
{	2342	,	-1284	,	636	},
{	2340	,	-1280	,	630	},
{	2333	,	-1273	,	622	},
{	2326	,	-1267	,	614	},
{	2321	,	-1261	,	607	},
{	2315	,	-1255	,	600	},
{	2302	,	-1246	,	590	},
{	2293	,	-1239	,	583	},
{	2281	,	-1230	,	574	},
{	2274	,	-1224	,	566	},
{	2262	,	-1215	,	557	},
{	2256	,	-1210	,	549	},
{	2243	,	-1201	,	538	},
{	2232	,	-1193	,	529	},
{	2223	,	-1186	,	520	},
{	2212	,	-1177	,	511	},
{	2204	,	-1171	,	504	},
{	2198	,	-1165	,	496	},
{	2181	,	-1154	,	487	},
{	2172	,	-1147	,	478	},
{	2157	,	-1137	,	469	},
{	2145	,	-1129	,	460	},
{	2137	,	-1122	,	452	},
{	2127	,	-1114	,	443	},
{	2116	,	-1105	,	434	},
{	2102	,	-1095	,	425	},
{	2091	,	-1087	,	416	},
{	2080	,	-1078	,	408	},
{	2063	,	-1067	,	398	},
{	2050	,	-1058	,	390	},
{	2037	,	-1049	,	381	},
{	2021	,	-1039	,	373	},
{	2009	,	-1030	,	364	},
{	1992	,	-1020	,	355	},
{	1975	,	-1010	,	347	},
{	1963	,	-1002	,	338	},
{	1947	,	-992	,	329	},
{	1936	,	-984	,	321	},
{	1919	,	-972	,	312	},
{	1900	,	-961	,	303	},
{	1879	,	-948	,	294	},
{	1862	,	-937	,	284	},
{	1845	,	-926	,	276	},
{	1826	,	-914	,	265	},
{	1803	,	-901	,	254	},
{	1786	,	-890	,	245	},
{	1766	,	-877	,	235	},
{	1749	,	-865	,	225	},
{	1733	,	-855	,	215	},
{	1706	,	-838	,	204	},
{	1688	,	-825	,	192	},
{	1665	,	-810	,	180	},
{	1645	,	-797	,	170	},
{	1625	,	-782	,	158	},
{	1600	,	-767	,	147	},
{	1579	,	-752	,	136	},
{	1559	,	-738	,	125	},
{	1540	,	-724	,	114	},
{	1520	,	-709	,	102	},
{	1501	,	-695	,	91	},
{	1477	,	-678	,	81	},
{	1462	,	-664	,	70	},
{	1440	,	-649	,	59	},
{	1422	,	-636	,	49	},
{	1401	,	-620	,	37	},
{	1382	,	-605	,	26	},
{	1365	,	-592	,	15	},
{	1346	,	-578	,	5	},
{	1330	,	-566	,	-5	},
{	1311	,	-551	,	-15	},
{	1291	,	-537	,	-26	},
{	1275	,	-524	,	-35	},
{	1259	,	-512	,	-45	},
{	1244	,	-501	,	-55	},
{	1228	,	-489	,	-64	},
{	1209	,	-476	,	-74	},
{	1194	,	-466	,	-83	},
{	1180	,	-455	,	-93	},
{	1160	,	-444	,	-102	},
{	1147	,	-434	,	-112	},
{	1132	,	-422	,	-122	},
{	1115	,	-411	,	-130	},
{	1099	,	-401	,	-139	},
{	1085	,	-391	,	-148	},
{	1070	,	-381	,	-158	},
{	1054	,	-371	,	-167	},
{	1039	,	-362	,	-176	},
{	1025	,	-353	,	-185	},
{	1010	,	-344	,	-195	},
{	996	,	-335	,	-204	},
{	980	,	-325	,	-214	},
{	964	,	-316	,	-223	},
{	948	,	-307	,	-231	},
{	932	,	-298	,	-241	},
{	918	,	-289	,	-250	},
{	905	,	-282	,	-259	},
{	888	,	-273	,	-268	},
{	874	,	-265	,	-276	},
{	859	,	-256	,	-285	},
{	843	,	-247	,	-293	},
{	830	,	-239	,	-302	},
{	813	,	-230	,	-310	},
{	799	,	-222	,	-319	},
{	784	,	-213	,	-327	},
{	768	,	-205	,	-336	},
{	754	,	-197	,	-344	},
{	737	,	-188	,	-352	},
{	723	,	-180	,	-362	},
{	707	,	-172	,	-371	},
{	694	,	-164	,	-381	},
{	679	,	-155	,	-391	},
{	663	,	-146	,	-400	},
{	648	,	-137	,	-409	},
{	634	,	-129	,	-419	},
{	619	,	-120	,	-429	},
{	604	,	-111	,	-438	},
{	589	,	-104	,	-447	},
{	574	,	-95	,	-458	},
{	561	,	-87	,	-467	},
{	546	,	-78	,	-477	},
{	533	,	-70	,	-486	},
{	518	,	-61	,	-494	},
{	504	,	-53	,	-504	},
{	491	,	-45	,	-513	},
{	477	,	-37	,	-521	},
{	464	,	-29	,	-530	},
{	450	,	-21	,	-540	},
{	435	,	-13	,	-547	},
{	421	,	-5	,	-556	},
{	407	,	2	,	-565	},
{	393	,	10	,	-575	},
{	378	,	18	,	-584	},
{	364	,	25	,	-594	},
{	351	,	34	,	-606	},
{	336	,	41	,	-613	},
{	322	,	48	,	-625	},
{	308	,	56	,	-635	},
{	294	,	63	,	-645	},
{	279	,	71	,	-653	},
{	265	,	78	,	-662	},
{	251	,	85	,	-672	},
{	237	,	93	,	-682	},
{	223	,	100	,	-689	},
{	208	,	107	,	-698	},
{	195	,	115	,	-708	},
{	181	,	122	,	-717	},
{	167	,	130	,	-724	},
{	154	,	137	,	-735	},
{	140	,	144	,	-745	},
{	126	,	151	,	-752	},
{	113	,	158	,	-760	},
{	100	,	165	,	-769	},
{	86	,	172	,	-775	},
{	73	,	179	,	-782	},
{	60	,	186	,	-791	},
{	48	,	193	,	-801	},
{	35	,	200	,	-808	},
{	23	,	206	,	-816	},
{	11	,	212	,	-821	},
{	0	,	218	,	-831	},
{	-12	,	224	,	-837	},
{	-23	,	229	,	-842	},
{	-35	,	235	,	-850	},
{	-46	,	240	,	-859	},
{	-56	,	245	,	-862	},
{	-66	,	249	,	-867	},
{	-75	,	254	,	-873	},
{	-84	,	259	,	-878	},
{	-93	,	263	,	-883	},
{	-102	,	267	,	-887	},
{	-110	,	271	,	-892	},
{	-119	,	275	,	-897	},
{	-127	,	278	,	-900	},
{	-136	,	282	,	-906	},
{	-143	,	285	,	-909	},
{	-152	,	290	,	-919	},
{	-159	,	292	,	-921	},
{	-166	,	296	,	-926	},
{	-176	,	300	,	-934	},
{	-185	,	303	,	-939	},
{	-196	,	308	,	-947	},
{	-206	,	312	,	-954	},
{	-216	,	316	,	-960	},
{	-227	,	320	,	-967	},
{	-240	,	324	,	-974	},
{	-252	,	330	,	-983	},
{	-265	,	335	,	-992	},
{	-278	,	342	,	-1000	},
{	-291	,	347	,	-1008	},
{	-306	,	354	,	-1019	},
{	-319	,	360	,	-1026	},
{	-333	,	366	,	-1036	},
{	-346	,	372	,	-1041	},
{	-362	,	381	,	-1052	},
{	-378	,	389	,	-1062	},
{	-390	,	397	,	-1069	},
{	-404	,	404	,	-1076	},
{	-418	,	411	,	-1085	},
{	-433	,	419	,	-1095	},
{	-447	,	427	,	-1105	},
{	-461	,	434	,	-1113	},
{	-475	,	442	,	-1122	},
{	-489	,	450	,	-1131	},
{	-504	,	459	,	-1143	},
{	-519	,	468	,	-1152	},
{	-532	,	475	,	-1158	},
{	-547	,	483	,	-1167	},
{	-562	,	491	,	-1176	},
{	-578	,	501	,	-1188	},
{	-593	,	508	,	-1196	},
{	-608	,	517	,	-1206	},
{	-622	,	524	,	-1214	},
{	-639	,	532	,	-1225	},
{	-655	,	541	,	-1235	},
{	-668	,	548	,	-1240	},
{	-683	,	557	,	-1248	},
{	-699	,	565	,	-1257	},
{	-715	,	574	,	-1267	},
{	-731	,	582	,	-1275	},
{	-747	,	590	,	-1283	},
{	-762	,	596	,	-1289	},
{	-775	,	603	,	-1295	},
{	-792	,	612	,	-1306	},
{	-806	,	618	,	-1311	},
{	-820	,	625	,	-1318	},
{	-838	,	633	,	-1328	},
{	-856	,	641	,	-1338	},
{	-869	,	646	,	-1342	},
{	-886	,	654	,	-1351	},
{	-902	,	661	,	-1358	},
{	-919	,	669	,	-1369	},
{	-934	,	676	,	-1375	},
{	-951	,	684	,	-1385	},
{	-966	,	690	,	-1391	},
{	-979	,	695	,	-1397	},
{	-995	,	702	,	-1406	},
{	-1012	,	710	,	-1416	},
{	-1026	,	716	,	-1423	},
{	-1042	,	723	,	-1430	},
{	-1056	,	728	,	-1435	},
{	-1074	,	736	,	-1446	},
{	-1090	,	743	,	-1455	},
{	-1100	,	746	,	-1456	},
{	-1113	,	751	,	-1460	},
{	-1131	,	759	,	-1471	},
{	-1144	,	765	,	-1477	},
{	-1156	,	770	,	-1482	},
{	-1168	,	773	,	-1485	},
{	-1185	,	781	,	-1495	},
{	-1198	,	784	,	-1500	},
{	-1211	,	789	,	-1505	},
{	-1227	,	795	,	-1513	},
{	-1240	,	798	,	-1515	},
{	-1250	,	799	,	-1516	},
{	-1263	,	803	,	-1521	},
{	-1276	,	806	,	-1527	},
{	-1288	,	809	,	-1533	},
{	-1299	,	810	,	-1537	},
{	-1312	,	812	,	-1543	},
{	-1322	,	814	,	-1546	},
{	-1333	,	814	,	-1551	},
{	-1343	,	814	,	-1554	},
{	-1350	,	812	,	-1555	},
{	-1359	,	811	,	-1559	},
{	-1364	,	808	,	-1559	},
{	-1365	,	803	,	-1556	},
{	-1365	,	799	,	-1553	},
{	-1363	,	794	,	-1551	},
{	-1364	,	791	,	-1550	},
{	-1364	,	789	,	-1550	},
{	-1367	,	788	,	-1553	},
{	-1369	,	787	,	-1553	},
{	-1369	,	784	,	-1553	},
{	-1369	,	781	,	-1552	},
{	-1366	,	777	,	-1548	},
{	-1359	,	771	,	-1541	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -12162)

int16_t accel_residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{5,-5,7},
{5,-5,6},
{5,-5,6},
{5,-6,5},
{4,-6,5},
{4,-7,4},
{5,-7,10},
{6,-7,16},
{7,-7,15},
{7,-8,14},
{7,-8,13},
{8,-8,13},
{8,-8,13},
{8,-9,13},
{9,-9,13},
{9,-9,13},
{9,-10,12},
{9,-10,12},
{9,-10,13},
{9,-11,13},
{9,-11,13},
{9,-11,12},
{10,-11,12},
{10,-11,12},
{10,-12,12},
{10,-12,12},
{10,-12,12},
{10,-13,12},
{10,-13,12},
{10,-13,12},
{10,-14,12},
{11,-14,12},
{11,-14,12},
{11,-15,12},
{11,-15,12},
{11,-15,11},
{11,-15,11},
{11,-15,11},
{12,-15,11},
{12,-16,11},
{11,-16,9},
{11,-16,9},
{12,-17,10},
{12,-17,11},
{12,-17,10},
{12,-18,10},
{12,-18,10},
{12,-18,10},
{13,-19,10},
{13,-19,10},
{13,-19,9},
{13,-19,9},
{13,-19,10},
{13,-19,9},
{14,-19,9},
{14,-19,9},
{14,-20,9},
{14,-20,9},
{15,-20,9},
{14,-20,9},
{14,-20,9},
{14,-20,9},
{14,-20,9},
{14,-21,9},
{15,-21,9},
{15,-21,9},
{15,-22,9},
{15,-22,9},
{15,-22,9},
{15,-22,9},
{15,-22,9},
{15,-22,9},
{15,-22,9},
{16,-23,9},
{16,-23,9},
{16,-23,8},
{16,-23,8},
{16,-23,9},
{16,-23,9},
{16,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-24,8},
{17,-25,8},
{17,-25,8},
{17,-25,8},
{18,-24,8},
{18,-24,8},
{18,-24,8},
{18,-24,8},
{18,-24,8},
{18,-24,8},
{19,-24,8},
{19,-24,8},
{19,-24,8},
{19,-23,8},
{19,-23,8},
{19,-23,8},
{19,-23,9},
{19,-23,9},
{19,-23,8},
{19,-23,8},
{20,-23,8},
{20,-22,8},
{20,-22,8},
{20,-22,9},
{20,-22,8},
{20,-22,8},
{20,-22,8},
{20,-23,8},
{20,-23,8},
{20,-23,8},
{20,-23,8},
{20,-24,8},
{20,-24,8},
{20,-25,8},
{20,-25,8},
{20,-25,7},
{20,-26,7},
{20,-26,7},
{20,-26,7},
{20,-26,7},
{20,-26,7},
{20,-27,7},
{20,-27,7},
{20,-27,7},
{20,-27,7},
{20,-27,7},
{20,-27,7},
{20,-27,7},
{20,-27,7},
{20,-28,7},
{20,-28,7},
{20,-28,8},
{20,-28,8},
{20,-28,8},
{20,-28,8},
{21,-28,8},
{21,-28,9},
{21,-28,9},
{21,-28,9},
{21,-29,9},
{21,-28,10},
{21,-28,10},
{21,-29,10},
{21,-29,10},
{21,-29,11},
{21,-29,11},
{21,-29,11},
{21,-29,11},
{21,-29,12},
{21,-29,12},
{21,-29,12},
{21,-30,13},
{21,-30,13},
{21,-30,13},
{21,-30,14},
{21,-30,14},
{21,-30,14},
{21,-30,15},
{21,-30,15},
{21,-30,16},
{21,-30,16},
{22,-31,16},
{22,-31,17},
{22,-31,17},
{22,-31,18},
{22,-31,18},
{22,-31,19},
{22,-31,19},
{22,-31,20},
{22,-32,20},
{22,-32,21},
{22,-32,21},
{22,-32,22},
{22,-32,22},
{22,-32,22},
{22,-32,23},
{22,-32,23},
{22,-32,24},
{22,-32,24},
{22,-32,25},
{22,-33,25},
{22,-33,25},
{22,-33,26},
{22,-33,27},
{22,-33,27},
{22,-33,27},
{22,-33,28},
{22,-33,29},
{22,-34,29},
{22,-34,30},
{22,-34,30},
{22,-34,31},
{22,-34,31},
{22,-34,31},
{22,-34,31},
{22,-34,31},
{22,-34,31},
{22,-35,32},
{22,-35,32},
{22,-35,32},
{22,-35,32},
{22,-35,33},
{22,-35,33},
{22,-35,33},
{22,-35,34},
{22,-36,34},
{22,-36,34},
{22,-36,35},
{22,-36,35},
{22,-36,35},
{22,-36,36},
{22,-36,36},
{22,-36,36},
{22,-36,37},
{22,-36,37},
{22,-36,38},
{22,-36,38},
{22,-37,39},
{22,-37,40},
{22,-37,40},
{22,-37,41},
{22,-37,42},
{22,-37,42},
{22,-37,43},
{22,-37,44},
{22,-37,45},
{22,-37,45},
{22,-37,46},
{23,-37,47},
{23,-37,47},
{23,-37,48},
{23,-37,49},
{22,-37,50},
{22,-37,50},
{22,-37,51},
{22,-37,52},
{22,-37,53},
{22,-36,54},
};


#endif	/* TABLE_LUGE7_SN109_H */

