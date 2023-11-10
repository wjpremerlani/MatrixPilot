

#ifndef TABLE_LUGE7_SN128_H
#define	TABLE_LUGE7_SN128_H

// used in LUGE7_SN128 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14746 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-2316	,	-152	,	386	},
{	-2307	,	-154	,	386	},
{	-2305	,	-157	,	387	},
{	-2295	,	-160	,	386	},
{	-2289	,	-164	,	387	},
{	-2283	,	-167	,	387	},
{	-2282	,	-170	,	388	},
{	-2278	,	-172	,	389	},
{	-2271	,	-175	,	389	},
{	-2267	,	-181	,	392	},
{	-2260	,	-189	,	393	},
{	-2242	,	-195	,	396	},
{	-2233	,	-200	,	398	},
{	-2219	,	-205	,	398	},
{	-2209	,	-210	,	400	},
{	-2199	,	-216	,	403	},
{	-2189	,	-222	,	404	},
{	-2183	,	-229	,	406	},
{	-2179	,	-237	,	409	},
{	-2167	,	-243	,	411	},
{	-2158	,	-249	,	413	},
{	-2152	,	-256	,	415	},
{	-2144	,	-262	,	416	},
{	-2131	,	-269	,	418	},
{	-2124	,	-277	,	421	},
{	-2114	,	-283	,	422	},
{	-2103	,	-290	,	421	},
{	-2096	,	-298	,	424	},
{	-2086	,	-303	,	423	},
{	-2077	,	-311	,	424	},
{	-2067	,	-318	,	426	},
{	-2058	,	-325	,	426	},
{	-2053	,	-332	,	427	},
{	-2042	,	-338	,	427	},
{	-2034	,	-344	,	427	},
{	-2024	,	-350	,	427	},
{	-2018	,	-357	,	427	},
{	-2013	,	-365	,	428	},
{	-1999	,	-370	,	426	},
{	-1994	,	-376	,	427	},
{	-1984	,	-381	,	427	},
{	-1972	,	-387	,	426	},
{	-1969	,	-395	,	428	},
{	-1961	,	-401	,	429	},
{	-1952	,	-407	,	429	},
{	-1944	,	-414	,	429	},
{	-1938	,	-421	,	430	},
{	-1927	,	-427	,	430	},
{	-1921	,	-433	,	431	},
{	-1910	,	-438	,	430	},
{	-1905	,	-445	,	431	},
{	-1891	,	-450	,	429	},
{	-1882	,	-455	,	428	},
{	-1875	,	-462	,	428	},
{	-1863	,	-465	,	428	},
{	-1860	,	-471	,	430	},
{	-1849	,	-476	,	430	},
{	-1839	,	-481	,	430	},
{	-1831	,	-486	,	430	},
{	-1820	,	-491	,	430	},
{	-1813	,	-497	,	431	},
{	-1802	,	-502	,	431	},
{	-1794	,	-508	,	432	},
{	-1784	,	-513	,	433	},
{	-1778	,	-518	,	434	},
{	-1770	,	-523	,	433	},
{	-1760	,	-529	,	434	},
{	-1755	,	-535	,	435	},
{	-1750	,	-541	,	436	},
{	-1741	,	-547	,	438	},
{	-1732	,	-552	,	437	},
{	-1728	,	-560	,	441	},
{	-1719	,	-566	,	441	},
{	-1708	,	-572	,	440	},
{	-1705	,	-579	,	441	},
{	-1699	,	-584	,	441	},
{	-1695	,	-590	,	441	},
{	-1686	,	-594	,	441	},
{	-1679	,	-598	,	439	},
{	-1677	,	-605	,	441	},
{	-1669	,	-609	,	441	},
{	-1661	,	-614	,	439	},
{	-1657	,	-619	,	440	},
{	-1650	,	-623	,	439	},
{	-1642	,	-628	,	438	},
{	-1635	,	-633	,	439	},
{	-1629	,	-637	,	438	},
{	-1620	,	-639	,	438	},
{	-1611	,	-641	,	436	},
{	-1605	,	-646	,	435	},
{	-1604	,	-650	,	434	},
{	-1601	,	-655	,	434	},
{	-1592	,	-658	,	431	},
{	-1586	,	-663	,	430	},
{	-1585	,	-668	,	428	},
{	-1579	,	-672	,	425	},
{	-1572	,	-673	,	421	},
{	-1567	,	-677	,	418	},
{	-1565	,	-682	,	416	},
{	-1558	,	-684	,	412	},
{	-1553	,	-688	,	409	},
{	-1549	,	-691	,	407	},
{	-1544	,	-694	,	403	},
{	-1540	,	-699	,	402	},
{	-1536	,	-704	,	401	},
{	-1534	,	-709	,	400	},
{	-1531	,	-713	,	398	},
{	-1527	,	-717	,	397	},
{	-1522	,	-721	,	395	},
{	-1519	,	-726	,	394	},
{	-1519	,	-730	,	393	},
{	-1511	,	-733	,	393	},
{	-1509	,	-737	,	393	},
{	-1506	,	-741	,	392	},
{	-1504	,	-744	,	392	},
{	-1504	,	-749	,	393	},
{	-1502	,	-753	,	392	},
{	-1501	,	-756	,	392	},
{	-1497	,	-756	,	389	},
{	-1499	,	-760	,	389	},
{	-1498	,	-763	,	388	},
{	-1499	,	-766	,	386	},
{	-1497	,	-768	,	383	},
{	-1494	,	-769	,	381	},
{	-1491	,	-770	,	378	},
{	-1490	,	-772	,	376	},
{	-1489	,	-773	,	374	},
{	-1485	,	-774	,	372	},
{	-1487	,	-775	,	370	},
{	-1489	,	-776	,	368	},
{	-1490	,	-778	,	367	},
{	-1492	,	-779	,	366	},
{	-1492	,	-778	,	361	},
{	-1496	,	-778	,	359	},
{	-1497	,	-776	,	357	},
{	-1503	,	-777	,	358	},
{	-1506	,	-775	,	356	},
{	-1512	,	-774	,	354	},
{	-1515	,	-772	,	351	},
{	-1519	,	-770	,	350	},
{	-1526	,	-769	,	348	},
{	-1536	,	-769	,	349	},
{	-1542	,	-766	,	347	},
{	-1551	,	-765	,	347	},
{	-1557	,	-762	,	345	},
{	-1565	,	-762	,	345	},
{	-1567	,	-758	,	344	},
{	-1578	,	-758	,	344	},
{	-1581	,	-756	,	343	},
{	-1587	,	-755	,	343	},
{	-1595	,	-755	,	344	},
{	-1600	,	-754	,	343	},
{	-1609	,	-755	,	343	},
{	-1613	,	-754	,	342	},
{	-1616	,	-754	,	342	},
{	-1623	,	-753	,	341	},
{	-1632	,	-754	,	341	},
{	-1636	,	-753	,	341	},
{	-1638	,	-750	,	338	},
{	-1640	,	-749	,	337	},
{	-1641	,	-746	,	334	},
{	-1649	,	-747	,	333	},
{	-1648	,	-745	,	329	},
{	-1656	,	-746	,	329	},
{	-1660	,	-744	,	327	},
{	-1665	,	-744	,	324	},
{	-1671	,	-743	,	323	},
{	-1670	,	-740	,	322	},
{	-1674	,	-740	,	319	},
{	-1674	,	-738	,	316	},
{	-1674	,	-737	,	312	},
{	-1678	,	-737	,	310	},
{	-1678	,	-737	,	307	},
{	-1682	,	-740	,	306	},
{	-1684	,	-740	,	304	},
{	-1687	,	-742	,	303	},
{	-1690	,	-743	,	301	},
{	-1697	,	-746	,	301	},
{	-1697	,	-747	,	299	},
{	-1703	,	-748	,	298	},
{	-1701	,	-749	,	296	},
{	-1704	,	-751	,	294	},
{	-1703	,	-753	,	293	},
{	-1704	,	-755	,	291	},
{	-1710	,	-761	,	289	},
{	-1714	,	-764	,	289	},
{	-1713	,	-765	,	286	},
{	-1719	,	-770	,	286	},
{	-1723	,	-774	,	284	},
{	-1729	,	-778	,	284	},
{	-1727	,	-779	,	282	},
{	-1730	,	-784	,	281	},
{	-1737	,	-788	,	281	},
{	-1741	,	-791	,	279	},
{	-1742	,	-795	,	278	},
{	-1741	,	-797	,	276	},
{	-1743	,	-801	,	275	},
{	-1751	,	-808	,	275	},
{	-1752	,	-809	,	272	},
{	-1758	,	-812	,	271	},
{	-1762	,	-816	,	270	},
{	-1763	,	-819	,	269	},
{	-1768	,	-823	,	266	},
{	-1774	,	-829	,	266	},
{	-1777	,	-831	,	264	},
{	-1779	,	-833	,	262	},
{	-1776	,	-833	,	260	},
{	-1784	,	-838	,	260	},
{	-1788	,	-840	,	259	},
{	-1787	,	-841	,	256	},
{	-1791	,	-846	,	256	},
{	-1796	,	-849	,	255	},
{	-1806	,	-855	,	254	},
{	-1807	,	-856	,	253	},
{	-1806	,	-857	,	251	},
{	-1812	,	-862	,	251	},
{	-1817	,	-867	,	250	},
{	-1821	,	-869	,	248	},
{	-1821	,	-871	,	246	},
{	-1826	,	-875	,	246	},
{	-1825	,	-875	,	245	},
{	-1829	,	-880	,	244	},
{	-1835	,	-885	,	244	},
{	-1840	,	-889	,	244	},
{	-1838	,	-889	,	242	},
{	-1841	,	-893	,	241	},
{	-1845	,	-897	,	240	},
{	-1848	,	-900	,	238	},
{	-1847	,	-903	,	236	},
{	-1849	,	-906	,	234	},
{	-1854	,	-911	,	233	},
{	-1861	,	-916	,	234	},
{	-1862	,	-918	,	232	},
{	-1859	,	-920	,	231	},
{	-1867	,	-927	,	231	},
{	-1868	,	-930	,	230	},
{	-1873	,	-936	,	228	},
{	-1877	,	-940	,	227	},
{	-1879	,	-943	,	227	},
{	-1883	,	-948	,	226	},
{	-1887	,	-953	,	225	},
{	-1893	,	-958	,	224	},
{	-1898	,	-963	,	223	},
{	-1904	,	-969	,	223	},
{	-1909	,	-973	,	221	},
{	-1916	,	-979	,	221	},
{	-1917	,	-984	,	221	},
{	-1921	,	-990	,	222	},
{	-1924	,	-995	,	221	},
{	-1925	,	-999	,	220	},
{	-1933	,	-1006	,	221	},
{	-1931	,	-1008	,	219	},
{	-1938	,	-1014	,	219	},
{	-1940	,	-1019	,	219	},
{	-1946	,	-1026	,	219	},
{	-1947	,	-1030	,	218	},
{	-1949	,	-1035	,	218	},
{	-1954	,	-1042	,	217	},
{	-1955	,	-1048	,	216	},
{	-1959	,	-1053	,	217	},
{	-1960	,	-1058	,	216	},
{	-1966	,	-1066	,	216	},
{	-1970	,	-1072	,	217	},
{	-1974	,	-1076	,	217	},
{	-1982	,	-1083	,	218	},
{	-1987	,	-1089	,	218	},
{	-1993	,	-1095	,	217	},
{	-1996	,	-1099	,	217	},
{	-2003	,	-1106	,	218	},
{	-2007	,	-1112	,	217	},
{	-2011	,	-1115	,	217	},
{	-2021	,	-1122	,	219	},
{	-2029	,	-1128	,	220	},
{	-2033	,	-1133	,	221	},
{	-2036	,	-1136	,	221	},
{	-2040	,	-1140	,	222	},
{	-2048	,	-1146	,	221	},
{	-2053	,	-1151	,	222	},
{	-2052	,	-1152	,	223	},
{	-2058	,	-1157	,	224	},
{	-2064	,	-1162	,	224	},
{	-2062	,	-1163	,	223	},
{	-2066	,	-1168	,	224	},
{	-2072	,	-1175	,	226	},
{	-2082	,	-1182	,	227	},
{	-2085	,	-1187	,	228	},
{	-2090	,	-1193	,	229	},
{	-2096	,	-1197	,	230	},
{	-2096	,	-1201	,	230	},
{	-2107	,	-1209	,	230	},
{	-2114	,	-1215	,	230	},
{	-2123	,	-1222	,	231	},
{	-2137	,	-1231	,	233	},
{	-2136	,	-1234	,	233	},
{	-2144	,	-1240	,	234	},
{	-2155	,	-1249	,	235	},
{	-2154	,	-1251	,	235	},
{	-2165	,	-1259	,	236	},
{	-2175	,	-1267	,	237	},
{	-2182	,	-1272	,	236	},
{	-2193	,	-1280	,	236	},
{	-2196	,	-1283	,	235	},
{	-2206	,	-1288	,	235	},
{	-2214	,	-1294	,	235	},
{	-2219	,	-1298	,	236	},
{	-2228	,	-1305	,	236	},
{	-2228	,	-1306	,	236	},
{	-2231	,	-1308	,	236	},
{	-2240	,	-1314	,	235	},
{	-2244	,	-1319	,	235	},
{	-2255	,	-1325	,	235	},
{	-2259	,	-1329	,	235	},
{	-2265	,	-1333	,	234	},
{	-2272	,	-1339	,	233	},
{	-2277	,	-1344	,	233	},
{	-2285	,	-1349	,	233	},
{	-2293	,	-1356	,	233	},
{	-2296	,	-1359	,	233	},
{	-2302	,	-1363	,	233	},
{	-2304	,	-1367	,	235	},
{	-2314	,	-1375	,	235	},
{	-2321	,	-1380	,	235	},
{	-2326	,	-1384	,	235	},
{	-2337	,	-1392	,	236	},
{	-2344	,	-1398	,	237	},
{	-2351	,	-1405	,	238	},
{	-2358	,	-1409	,	238	},
{	-2365	,	-1414	,	240	},
{	-2377	,	-1422	,	242	},
{	-2385	,	-1427	,	243	},
{	-2395	,	-1433	,	244	},
{	-2399	,	-1437	,	244	},
{	-2407	,	-1442	,	244	},
{	-2412	,	-1445	,	244	},
{	-2421	,	-1451	,	246	},
{	-2429	,	-1457	,	247	},
{	-2433	,	-1460	,	246	},
{	-2437	,	-1462	,	246	},
{	-2448	,	-1468	,	246	},
{	-2451	,	-1470	,	246	},
{	-2453	,	-1472	,	245	},
{	-2463	,	-1478	,	244	},
{	-2461	,	-1475	,	242	},
{	-2469	,	-1479	,	242	},
{	-2476	,	-1484	,	242	},
{	-2481	,	-1486	,	240	},
{	-2490	,	-1492	,	239	},
{	-2493	,	-1493	,	237	},
{	-2500	,	-1497	,	236	},
{	-2500	,	-1496	,	234	},
{	-2507	,	-1501	,	234	},
{	-2509	,	-1502	,	232	},
{	-2517	,	-1507	,	231	},
{	-2530	,	-1514	,	231	},
{	-2531	,	-1515	,	229	},
{	-2534	,	-1517	,	227	},
{	-2548	,	-1526	,	227	},
{	-2556	,	-1531	,	226	},
{	-2560	,	-1535	,	225	},
{	-2571	,	-1542	,	225	},
{	-2570	,	-1543	,	223	},
{	-2578	,	-1548	,	220	},
{	-2577	,	-1549	,	218	},
{	-2582	,	-1554	,	216	},
{	-2591	,	-1562	,	215	},
{	-2594	,	-1566	,	214	},
{	-2603	,	-1574	,	213	},
{	-2618	,	-1585	,	211	},
{	-2623	,	-1591	,	209	},
{	-2629	,	-1596	,	206	},
{	-2630	,	-1601	,	203	},
{	-2643	,	-1612	,	201	},
{	-2655	,	-1624	,	198	},
{	-2657	,	-1629	,	195	},
{	-2661	,	-1636	,	191	},
{	-2671	,	-1649	,	189	},
{	-2679	,	-1661	,	186	},
{	-2686	,	-1672	,	184	},
{	-2693	,	-1686	,	181	},
{	-2705	,	-1701	,	179	},
{	-2711	,	-1714	,	176	},
{	-2723	,	-1730	,	174	},
{	-2732	,	-1745	,	172	},
{	-2735	,	-1755	,	170	},
{	-2734	,	-1765	,	168	},
{	-2740	,	-1773	,	167	},
{	-2744	,	-1782	,	165	},
{	-2750	,	-1790	,	164	},
{	-2751	,	-1797	,	163	},
{	-2749	,	-1802	,	163	},
{	-2753	,	-1811	,	162	},
{	-2763	,	-1824	,	163	},
{	-2762	,	-1829	,	162	}
};

#endif	/* TABLE_LUGE7_SN128_H */

