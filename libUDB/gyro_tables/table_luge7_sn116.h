

#ifndef TABLE_LUGE7_SN116_H
#define	TABLE_LUGE7_SN116_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  (  -14745 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	2135	,	-237	,	-390	},
{	2141	,	-244	,	-395	},
{	2137	,	-251	,	-398	},
{	2139	,	-258	,	-403	},
{	2140	,	-263	,	-407	},
{	2138	,	-269	,	-412	},
{	2136	,	-273	,	-414	},
{	2138	,	-279	,	-418	},
{	2138	,	-285	,	-420	},
{	2140	,	-297	,	-428	},
{	2136	,	-309	,	-435	},
{	2132	,	-319	,	-441	},
{	2130	,	-329	,	-447	},
{	2126	,	-338	,	-453	},
{	2127	,	-349	,	-461	},
{	2124	,	-360	,	-469	},
{	2114	,	-368	,	-474	},
{	2116	,	-377	,	-480	},
{	2105	,	-383	,	-485	},
{	2101	,	-390	,	-492	},
{	2094	,	-398	,	-499	},
{	2090	,	-406	,	-506	},
{	2087	,	-412	,	-510	},
{	2082	,	-419	,	-516	},
{	2075	,	-425	,	-521	},
{	2070	,	-432	,	-528	},
{	2063	,	-438	,	-534	},
{	2056	,	-444	,	-541	},
{	2057	,	-451	,	-547	},
{	2047	,	-456	,	-552	},
{	2047	,	-464	,	-559	},
{	2042	,	-470	,	-566	},
{	2034	,	-476	,	-571	},
{	2036	,	-484	,	-578	},
{	2025	,	-491	,	-584	},
{	2023	,	-499	,	-590	},
{	2020	,	-508	,	-597	},
{	2016	,	-514	,	-601	},
{	2006	,	-521	,	-605	},
{	1999	,	-531	,	-612	},
{	1995	,	-540	,	-619	},
{	1992	,	-551	,	-627	},
{	1985	,	-558	,	-633	},
{	1980	,	-566	,	-640	},
{	1971	,	-574	,	-645	},
{	1961	,	-583	,	-652	},
{	1959	,	-590	,	-658	},
{	1952	,	-598	,	-665	},
{	1944	,	-606	,	-671	},
{	1942	,	-615	,	-679	},
{	1930	,	-623	,	-685	},
{	1928	,	-634	,	-694	},
{	1920	,	-642	,	-700	},
{	1912	,	-648	,	-706	},
{	1912	,	-658	,	-716	},
{	1907	,	-666	,	-723	},
{	1900	,	-672	,	-728	},
{	1897	,	-681	,	-737	},
{	1887	,	-686	,	-742	},
{	1886	,	-696	,	-750	},
{	1881	,	-704	,	-754	},
{	1875	,	-711	,	-759	},
{	1870	,	-719	,	-765	},
{	1866	,	-729	,	-773	},
{	1863	,	-738	,	-781	},
{	1859	,	-746	,	-785	},
{	1853	,	-754	,	-791	},
{	1848	,	-761	,	-796	},
{	1842	,	-767	,	-800	},
{	1837	,	-775	,	-807	},
{	1835	,	-785	,	-814	},
{	1824	,	-789	,	-817	},
{	1819	,	-797	,	-822	},
{	1818	,	-808	,	-830	},
{	1806	,	-814	,	-834	},
{	1801	,	-823	,	-841	},
{	1787	,	-827	,	-845	},
{	1783	,	-836	,	-854	},
{	1779	,	-844	,	-862	},
{	1774	,	-852	,	-870	},
{	1765	,	-858	,	-874	},
{	1754	,	-864	,	-879	},
{	1745	,	-870	,	-885	},
{	1738	,	-875	,	-890	},
{	1731	,	-882	,	-896	},
{	1724	,	-889	,	-903	},
{	1724	,	-897	,	-910	},
{	1714	,	-902	,	-914	},
{	1711	,	-911	,	-922	},
{	1704	,	-919	,	-929	},
{	1694	,	-924	,	-934	},
{	1690	,	-933	,	-941	},
{	1683	,	-939	,	-947	},
{	1679	,	-948	,	-952	},
{	1670	,	-953	,	-954	},
{	1665	,	-961	,	-961	},
{	1659	,	-970	,	-968	},
{	1653	,	-979	,	-975	},
{	1646	,	-986	,	-979	},
{	1639	,	-995	,	-986	},
{	1631	,	-1003	,	-992	},
{	1625	,	-1013	,	-999	},
{	1613	,	-1017	,	-1001	},
{	1602	,	-1026	,	-1008	},
{	1594	,	-1035	,	-1016	},
{	1582	,	-1041	,	-1021	},
{	1573	,	-1049	,	-1028	},
{	1563	,	-1057	,	-1033	},
{	1553	,	-1063	,	-1037	},
{	1544	,	-1072	,	-1044	},
{	1536	,	-1083	,	-1053	},
{	1526	,	-1091	,	-1060	},
{	1511	,	-1096	,	-1064	},
{	1500	,	-1105	,	-1072	},
{	1486	,	-1112	,	-1077	},
{	1473	,	-1119	,	-1084	},
{	1460	,	-1124	,	-1089	},
{	1448	,	-1132	,	-1095	},
{	1435	,	-1140	,	-1103	},
{	1420	,	-1151	,	-1113	},
{	1403	,	-1153	,	-1116	},
{	1387	,	-1159	,	-1123	},
{	1375	,	-1169	,	-1131	},
{	1358	,	-1175	,	-1137	},
{	1341	,	-1180	,	-1144	},
{	1324	,	-1186	,	-1149	},
{	1307	,	-1192	,	-1157	},
{	1289	,	-1194	,	-1161	},
{	1270	,	-1198	,	-1167	},
{	1252	,	-1202	,	-1173	},
{	1230	,	-1204	,	-1177	},
{	1213	,	-1208	,	-1184	},
{	1193	,	-1211	,	-1190	},
{	1173	,	-1212	,	-1196	},
{	1153	,	-1216	,	-1203	},
{	1129	,	-1214	,	-1205	},
{	1109	,	-1217	,	-1212	},
{	1086	,	-1219	,	-1219	},
{	1064	,	-1220	,	-1224	},
{	1039	,	-1219	,	-1230	},
{	1016	,	-1221	,	-1239	},
{	993	,	-1219	,	-1245	},
{	969	,	-1220	,	-1253	},
{	945	,	-1218	,	-1259	},
{	919	,	-1218	,	-1266	},
{	894	,	-1218	,	-1274	},
{	870	,	-1219	,	-1282	},
{	844	,	-1216	,	-1290	},
{	819	,	-1214	,	-1297	},
{	793	,	-1211	,	-1303	},
{	768	,	-1214	,	-1312	},
{	741	,	-1213	,	-1322	},
{	716	,	-1211	,	-1330	},
{	689	,	-1209	,	-1339	},
{	664	,	-1205	,	-1346	},
{	640	,	-1203	,	-1355	},
{	615	,	-1199	,	-1361	},
{	589	,	-1197	,	-1368	},
{	565	,	-1196	,	-1375	},
{	541	,	-1193	,	-1382	},
{	517	,	-1192	,	-1391	},
{	493	,	-1188	,	-1398	},
{	471	,	-1189	,	-1408	},
{	448	,	-1186	,	-1414	},
{	426	,	-1186	,	-1423	},
{	403	,	-1184	,	-1430	},
{	383	,	-1186	,	-1441	},
{	362	,	-1182	,	-1448	},
{	341	,	-1180	,	-1454	},
{	321	,	-1181	,	-1464	},
{	302	,	-1181	,	-1471	},
{	283	,	-1184	,	-1481	},
{	263	,	-1185	,	-1489	},
{	243	,	-1188	,	-1500	},
{	223	,	-1187	,	-1505	},
{	203	,	-1193	,	-1519	},
{	184	,	-1196	,	-1530	},
{	163	,	-1200	,	-1539	},
{	145	,	-1205	,	-1549	},
{	124	,	-1204	,	-1554	},
{	107	,	-1209	,	-1565	},
{	87	,	-1210	,	-1572	},
{	67	,	-1215	,	-1583	},
{	49	,	-1216	,	-1589	},
{	31	,	-1220	,	-1598	},
{	12	,	-1225	,	-1608	},
{	-6	,	-1229	,	-1617	},
{	-25	,	-1230	,	-1623	},
{	-43	,	-1234	,	-1630	},
{	-62	,	-1237	,	-1639	},
{	-81	,	-1240	,	-1645	},
{	-99	,	-1244	,	-1654	},
{	-117	,	-1244	,	-1658	},
{	-135	,	-1245	,	-1664	},
{	-154	,	-1247	,	-1669	},
{	-172	,	-1249	,	-1677	},
{	-190	,	-1256	,	-1688	},
{	-209	,	-1256	,	-1693	},
{	-227	,	-1260	,	-1701	},
{	-245	,	-1263	,	-1709	},
{	-265	,	-1266	,	-1717	},
{	-285	,	-1271	,	-1725	},
{	-302	,	-1270	,	-1730	},
{	-321	,	-1272	,	-1736	},
{	-339	,	-1272	,	-1740	},
{	-358	,	-1274	,	-1748	},
{	-376	,	-1276	,	-1754	},
{	-393	,	-1276	,	-1759	},
{	-413	,	-1278	,	-1765	},
{	-432	,	-1281	,	-1774	},
{	-450	,	-1282	,	-1780	},
{	-469	,	-1283	,	-1787	},
{	-486	,	-1283	,	-1791	},
{	-505	,	-1286	,	-1800	},
{	-523	,	-1287	,	-1804	},
{	-541	,	-1287	,	-1808	},
{	-561	,	-1291	,	-1816	},
{	-579	,	-1290	,	-1820	},
{	-596	,	-1290	,	-1826	},
{	-615	,	-1292	,	-1833	},
{	-632	,	-1290	,	-1835	},
{	-652	,	-1295	,	-1847	},
{	-670	,	-1296	,	-1854	},
{	-688	,	-1297	,	-1861	},
{	-707	,	-1302	,	-1873	},
{	-725	,	-1302	,	-1878	},
{	-742	,	-1302	,	-1883	},
{	-762	,	-1306	,	-1894	},
{	-778	,	-1304	,	-1895	},
{	-797	,	-1307	,	-1906	},
{	-816	,	-1306	,	-1909	},
{	-835	,	-1309	,	-1918	},
{	-854	,	-1311	,	-1926	},
{	-871	,	-1310	,	-1930	},
{	-888	,	-1311	,	-1937	},
{	-906	,	-1311	,	-1942	},
{	-925	,	-1314	,	-1950	},
{	-945	,	-1316	,	-1959	},
{	-963	,	-1317	,	-1961	},
{	-984	,	-1320	,	-1971	},
{	-1001	,	-1319	,	-1973	},
{	-1022	,	-1319	,	-1979	},
{	-1039	,	-1317	,	-1981	},
{	-1059	,	-1318	,	-1989	},
{	-1076	,	-1317	,	-1992	},
{	-1094	,	-1318	,	-1999	},
{	-1113	,	-1320	,	-2005	},
{	-1129	,	-1319	,	-2008	},
{	-1150	,	-1323	,	-2017	},
{	-1167	,	-1323	,	-2020	},
{	-1187	,	-1327	,	-2028	},
{	-1205	,	-1329	,	-2034	},
{	-1224	,	-1331	,	-2041	},
{	-1241	,	-1330	,	-2044	},
{	-1259	,	-1331	,	-2049	},
{	-1278	,	-1334	,	-2059	},
{	-1290	,	-1330	,	-2056	},
{	-1308	,	-1333	,	-2063	},
{	-1326	,	-1335	,	-2068	},
{	-1347	,	-1341	,	-2077	},
{	-1364	,	-1344	,	-2083	},
{	-1380	,	-1344	,	-2087	},
{	-1398	,	-1348	,	-2093	},
{	-1415	,	-1350	,	-2096	},
{	-1431	,	-1354	,	-2101	},
{	-1447	,	-1357	,	-2105	},
{	-1462	,	-1359	,	-2109	},
{	-1475	,	-1358	,	-2109	},
{	-1490	,	-1361	,	-2113	},
{	-1502	,	-1362	,	-2113	},
{	-1518	,	-1368	,	-2119	},
{	-1533	,	-1375	,	-2125	},
{	-1541	,	-1376	,	-2121	},
{	-1555	,	-1383	,	-2127	},
{	-1570	,	-1390	,	-2133	},
{	-1575	,	-1391	,	-2129	},
{	-1585	,	-1397	,	-2132	},
{	-1594	,	-1403	,	-2131	},
{	-1606	,	-1411	,	-2136	},
{	-1615	,	-1415	,	-2136	},
{	-1628	,	-1421	,	-2139	},
{	-1638	,	-1425	,	-2141	},
{	-1651	,	-1430	,	-2144	},
{	-1665	,	-1437	,	-2149	},
{	-1679	,	-1442	,	-2153	},
{	-1692	,	-1446	,	-2156	},
{	-1706	,	-1451	,	-2160	},
{	-1721	,	-1456	,	-2166	},
{	-1736	,	-1460	,	-2171	},
{	-1752	,	-1461	,	-2174	},
{	-1771	,	-1464	,	-2181	},
{	-1786	,	-1464	,	-2183	},
{	-1808	,	-1468	,	-2192	},
{	-1825	,	-1466	,	-2195	},
{	-1844	,	-1465	,	-2199	},
{	-1860	,	-1462	,	-2201	},
{	-1887	,	-1467	,	-2214	},
{	-1904	,	-1464	,	-2217	},
{	-1926	,	-1465	,	-2225	},
{	-1946	,	-1465	,	-2230	},
{	-1964	,	-1462	,	-2234	},
{	-1985	,	-1463	,	-2241	},
{	-2006	,	-1463	,	-2245	},
{	-2030	,	-1465	,	-2255	},
{	-2049	,	-1463	,	-2260	},
{	-2067	,	-1460	,	-2261	},
{	-2095	,	-1465	,	-2275	},
{	-2117	,	-1466	,	-2282	},
{	-2139	,	-1467	,	-2290	},
{	-2161	,	-1468	,	-2299	},
{	-2185	,	-1470	,	-2309	},
{	-2211	,	-1474	,	-2321	},
{	-2233	,	-1474	,	-2328	},
{	-2253	,	-1474	,	-2334	},
{	-2278	,	-1478	,	-2346	},
{	-2296	,	-1478	,	-2351	},
{	-2316	,	-1477	,	-2356	},
{	-2335	,	-1477	,	-2360	},
{	-2358	,	-1479	,	-2368	},
{	-2377	,	-1479	,	-2375	},
{	-2395	,	-1478	,	-2378	},
{	-2416	,	-1482	,	-2385	},
{	-2437	,	-1484	,	-2392	},
{	-2453	,	-1483	,	-2394	},
{	-2474	,	-1486	,	-2401	},
{	-2500	,	-1492	,	-2414	},
{	-2518	,	-1493	,	-2416	},
{	-2540	,	-1495	,	-2423	},
{	-2555	,	-1494	,	-2422	},
{	-2577	,	-1499	,	-2429	},
{	-2597	,	-1500	,	-2434	},
{	-2614	,	-1501	,	-2438	},
{	-2635	,	-1503	,	-2442	},
{	-2660	,	-1509	,	-2453	},
{	-2682	,	-1513	,	-2462	},
{	-2705	,	-1517	,	-2469	},
{	-2725	,	-1521	,	-2476	},
{	-2747	,	-1524	,	-2483	},
{	-2771	,	-1528	,	-2492	},
{	-2790	,	-1530	,	-2497	},
{	-2817	,	-1538	,	-2509	},
{	-2837	,	-1541	,	-2514	},
{	-2856	,	-1544	,	-2518	},
{	-2877	,	-1549	,	-2525	},
{	-2901	,	-1556	,	-2533	},
{	-2926	,	-1563	,	-2543	},
{	-2955	,	-1572	,	-2557	},
{	-2972	,	-1575	,	-2560	},
{	-2994	,	-1582	,	-2566	},
{	-3021	,	-1591	,	-2577	},
{	-3038	,	-1596	,	-2579	},
{	-3055	,	-1603	,	-2582	},
{	-3073	,	-1609	,	-2586	},
{	-3107	,	-1623	,	-2601	},
{	-3126	,	-1630	,	-2605	},
{	-3137	,	-1633	,	-2602	},
{	-3161	,	-1643	,	-2611	},
{	-3182	,	-1651	,	-2617	},
{	-3200	,	-1659	,	-2620	},
{	-3212	,	-1663	,	-2617	},
{	-3236	,	-1675	,	-2625	},
{	-3247	,	-1681	,	-2624	},
{	-3265	,	-1691	,	-2629	},
{	-3277	,	-1698	,	-2627	},
{	-3295	,	-1708	,	-2631	},
{	-3316	,	-1721	,	-2637	},
{	-3331	,	-1732	,	-2638	},
{	-3344	,	-1740	,	-2638	},
{	-3370	,	-1755	,	-2648	},
{	-3385	,	-1766	,	-2650	},
{	-3393	,	-1774	,	-2646	},
{	-3415	,	-1791	,	-2653	},
{	-3434	,	-1806	,	-2660	},
{	-3452	,	-1821	,	-2664	},
{	-3461	,	-1833	,	-2660	},
{	-3474	,	-1847	,	-2660	},
{	-3499	,	-1868	,	-2667	},
{	-3505	,	-1879	,	-2662	},
{	-3521	,	-1896	,	-2663	},
{	-3534	,	-1912	,	-2662	},
{	-3545	,	-1928	,	-2659	},
{	-3554	,	-1944	,	-2657	},
{	-3569	,	-1964	,	-2658	},
{	-3573	,	-1978	,	-2653	},
{	-3578	,	-1996	,	-2649	},
{	-3580	,	-2013	,	-2643	},
{	-3585	,	-2034	,	-2640	},
{	-3581	,	-2051	,	-2631	},
{	-3581	,	-2059	,	-2627	},
{	-3583	,	-2068	,	-2623	},
{	-3583	,	-2077	,	-2619	},
{	-3585	,	-2087	,	-2617	},
{	-3589	,	-2098	,	-2616	},
{	-3576	,	-2100	,	-2605	},
{	-3580	,	-2114	,	-2606	},
{	-3581	,	-2124	,	-2605	}
};

#endif	/* TABLE_LUGE7_SN116_H */

