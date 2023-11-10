

#ifndef TABLE_LUGE7_SN132_H
#define	TABLE_LUGE7_SN132_H

// used in LUGE7_SN132 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  (  -14340 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-819	,	2918	,	-798	},
{	-814	,	2917	,	-797	},
{	-808	,	2907	,	-794	},
{	-803	,	2904	,	-792	},
{	-799	,	2902	,	-793	},
{	-793	,	2891	,	-789	},
{	-789	,	2889	,	-788	},
{	-784	,	2885	,	-786	},
{	-779	,	2884	,	-785	},
{	-769	,	2872	,	-782	},
{	-760	,	2865	,	-780	},
{	-751	,	2857	,	-776	},
{	-740	,	2840	,	-771	},
{	-729	,	2830	,	-768	},
{	-719	,	2820	,	-765	},
{	-710	,	2817	,	-765	},
{	-698	,	2805	,	-763	},
{	-689	,	2801	,	-762	},
{	-679	,	2788	,	-759	},
{	-669	,	2779	,	-757	},
{	-661	,	2773	,	-757	},
{	-651	,	2760	,	-752	},
{	-642	,	2754	,	-752	},
{	-633	,	2744	,	-749	},
{	-622	,	2732	,	-747	},
{	-613	,	2722	,	-747	},
{	-605	,	2717	,	-746	},
{	-595	,	2706	,	-745	},
{	-587	,	2699	,	-745	},
{	-579	,	2695	,	-746	},
{	-571	,	2683	,	-745	},
{	-562	,	2681	,	-745	},
{	-553	,	2671	,	-745	},
{	-543	,	2659	,	-742	},
{	-534	,	2647	,	-741	},
{	-526	,	2639	,	-741	},
{	-518	,	2634	,	-742	},
{	-510	,	2623	,	-740	},
{	-502	,	2620	,	-741	},
{	-494	,	2612	,	-741	},
{	-486	,	2605	,	-742	},
{	-480	,	2598	,	-741	},
{	-473	,	2583	,	-739	},
{	-466	,	2577	,	-740	},
{	-460	,	2571	,	-740	},
{	-452	,	2560	,	-737	},
{	-446	,	2556	,	-737	},
{	-439	,	2548	,	-737	},
{	-432	,	2533	,	-734	},
{	-425	,	2522	,	-734	},
{	-420	,	2518	,	-738	},
{	-413	,	2502	,	-736	},
{	-408	,	2497	,	-737	},
{	-401	,	2486	,	-737	},
{	-395	,	2479	,	-738	},
{	-388	,	2465	,	-738	},
{	-381	,	2453	,	-736	},
{	-374	,	2445	,	-737	},
{	-368	,	2434	,	-737	},
{	-362	,	2429	,	-739	},
{	-355	,	2415	,	-736	},
{	-347	,	2400	,	-735	},
{	-340	,	2393	,	-736	},
{	-332	,	2376	,	-734	},
{	-326	,	2369	,	-735	},
{	-318	,	2364	,	-737	},
{	-312	,	2357	,	-738	},
{	-304	,	2341	,	-734	},
{	-297	,	2333	,	-734	},
{	-289	,	2319	,	-733	},
{	-283	,	2311	,	-732	},
{	-276	,	2298	,	-731	},
{	-269	,	2291	,	-731	},
{	-261	,	2282	,	-732	},
{	-254	,	2274	,	-733	},
{	-247	,	2266	,	-733	},
{	-241	,	2258	,	-734	},
{	-235	,	2252	,	-735	},
{	-230	,	2246	,	-735	},
{	-225	,	2231	,	-734	},
{	-220	,	2225	,	-736	},
{	-215	,	2217	,	-737	},
{	-210	,	2206	,	-738	},
{	-204	,	2193	,	-738	},
{	-201	,	2186	,	-739	},
{	-198	,	2183	,	-740	},
{	-196	,	2173	,	-740	},
{	-194	,	2166	,	-741	},
{	-191	,	2156	,	-740	},
{	-189	,	2150	,	-741	},
{	-188	,	2146	,	-743	},
{	-187	,	2134	,	-743	},
{	-186	,	2122	,	-741	},
{	-183	,	2116	,	-742	},
{	-182	,	2107	,	-742	},
{	-181	,	2096	,	-742	},
{	-180	,	2095	,	-744	},
{	-179	,	2088	,	-744	},
{	-178	,	2076	,	-742	},
{	-179	,	2065	,	-740	},
{	-180	,	2060	,	-740	},
{	-181	,	2058	,	-743	},
{	-180	,	2043	,	-741	},
{	-180	,	2041	,	-742	},
{	-179	,	2031	,	-742	},
{	-179	,	2027	,	-744	},
{	-179	,	2015	,	-744	},
{	-179	,	2008	,	-744	},
{	-180	,	2003	,	-745	},
{	-182	,	2002	,	-748	},
{	-185	,	1992	,	-748	},
{	-187	,	1989	,	-749	},
{	-190	,	1988	,	-753	},
{	-193	,	1981	,	-754	},
{	-196	,	1974	,	-755	},
{	-200	,	1973	,	-758	},
{	-204	,	1974	,	-762	},
{	-208	,	1971	,	-764	},
{	-212	,	1964	,	-765	},
{	-217	,	1963	,	-767	},
{	-222	,	1961	,	-770	},
{	-227	,	1959	,	-772	},
{	-234	,	1954	,	-773	},
{	-242	,	1956	,	-776	},
{	-250	,	1954	,	-778	},
{	-258	,	1948	,	-779	},
{	-268	,	1950	,	-782	},
{	-277	,	1946	,	-783	},
{	-286	,	1944	,	-784	},
{	-294	,	1938	,	-783	},
{	-305	,	1940	,	-787	},
{	-317	,	1943	,	-790	},
{	-328	,	1938	,	-791	},
{	-338	,	1933	,	-791	},
{	-351	,	1933	,	-794	},
{	-362	,	1930	,	-794	},
{	-374	,	1931	,	-797	},
{	-386	,	1929	,	-798	},
{	-399	,	1931	,	-801	},
{	-413	,	1934	,	-803	},
{	-424	,	1929	,	-803	},
{	-438	,	1931	,	-804	},
{	-450	,	1929	,	-805	},
{	-463	,	1931	,	-807	},
{	-476	,	1936	,	-812	},
{	-489	,	1937	,	-815	},
{	-503	,	1941	,	-818	},
{	-515	,	1938	,	-818	},
{	-525	,	1933	,	-818	},
{	-539	,	1939	,	-822	},
{	-553	,	1946	,	-826	},
{	-565	,	1942	,	-827	},
{	-578	,	1944	,	-830	},
{	-591	,	1946	,	-832	},
{	-602	,	1941	,	-832	},
{	-612	,	1937	,	-833	},
{	-622	,	1934	,	-834	},
{	-635	,	1941	,	-838	},
{	-645	,	1935	,	-839	},
{	-657	,	1938	,	-842	},
{	-667	,	1934	,	-842	},
{	-676	,	1931	,	-843	},
{	-687	,	1933	,	-846	},
{	-696	,	1929	,	-847	},
{	-709	,	1933	,	-851	},
{	-719	,	1937	,	-854	},
{	-728	,	1933	,	-854	},
{	-735	,	1925	,	-854	},
{	-743	,	1923	,	-855	},
{	-753	,	1923	,	-858	},
{	-762	,	1923	,	-861	},
{	-772	,	1924	,	-864	},
{	-784	,	1929	,	-869	},
{	-792	,	1927	,	-870	},
{	-800	,	1922	,	-870	},
{	-810	,	1921	,	-872	},
{	-818	,	1918	,	-873	},
{	-829	,	1918	,	-877	},
{	-836	,	1914	,	-878	},
{	-845	,	1911	,	-881	},
{	-855	,	1910	,	-883	},
{	-862	,	1903	,	-884	},
{	-873	,	1903	,	-888	},
{	-884	,	1903	,	-890	},
{	-892	,	1900	,	-891	},
{	-903	,	1898	,	-894	},
{	-912	,	1893	,	-895	},
{	-922	,	1891	,	-898	},
{	-930	,	1884	,	-899	},
{	-941	,	1882	,	-901	},
{	-952	,	1881	,	-905	},
{	-963	,	1880	,	-909	},
{	-971	,	1876	,	-911	},
{	-983	,	1876	,	-915	},
{	-994	,	1874	,	-919	},
{	-1006	,	1873	,	-922	},
{	-1016	,	1867	,	-924	},
{	-1026	,	1863	,	-926	},
{	-1037	,	1859	,	-928	},
{	-1045	,	1851	,	-927	},
{	-1054	,	1844	,	-929	},
{	-1065	,	1842	,	-932	},
{	-1076	,	1840	,	-935	},
{	-1086	,	1839	,	-940	},
{	-1094	,	1832	,	-941	},
{	-1108	,	1837	,	-946	},
{	-1114	,	1826	,	-945	},
{	-1126	,	1826	,	-949	},
{	-1133	,	1819	,	-948	},
{	-1149	,	1823	,	-955	},
{	-1159	,	1819	,	-957	},
{	-1168	,	1813	,	-958	},
{	-1177	,	1807	,	-958	},
{	-1187	,	1805	,	-961	},
{	-1200	,	1806	,	-964	},
{	-1209	,	1803	,	-966	},
{	-1221	,	1802	,	-970	},
{	-1230	,	1799	,	-973	},
{	-1241	,	1797	,	-975	},
{	-1251	,	1795	,	-977	},
{	-1264	,	1793	,	-980	},
{	-1278	,	1793	,	-983	},
{	-1288	,	1787	,	-984	},
{	-1301	,	1786	,	-987	},
{	-1309	,	1778	,	-987	},
{	-1324	,	1779	,	-993	},
{	-1331	,	1770	,	-993	},
{	-1341	,	1765	,	-996	},
{	-1352	,	1761	,	-997	},
{	-1367	,	1761	,	-1001	},
{	-1379	,	1757	,	-1004	},
{	-1390	,	1753	,	-1006	},
{	-1406	,	1753	,	-1011	},
{	-1417	,	1748	,	-1014	},
{	-1432	,	1748	,	-1018	},
{	-1445	,	1745	,	-1021	},
{	-1460	,	1742	,	-1026	},
{	-1470	,	1736	,	-1027	},
{	-1484	,	1734	,	-1030	},
{	-1499	,	1732	,	-1035	},
{	-1513	,	1731	,	-1040	},
{	-1527	,	1729	,	-1044	},
{	-1540	,	1726	,	-1047	},
{	-1555	,	1726	,	-1052	},
{	-1569	,	1723	,	-1055	},
{	-1580	,	1720	,	-1057	},
{	-1592	,	1716	,	-1060	},
{	-1604	,	1713	,	-1064	},
{	-1616	,	1708	,	-1066	},
{	-1627	,	1705	,	-1070	},
{	-1640	,	1702	,	-1073	},
{	-1653	,	1698	,	-1076	},
{	-1665	,	1693	,	-1078	},
{	-1676	,	1689	,	-1079	},
{	-1692	,	1688	,	-1083	},
{	-1701	,	1680	,	-1083	},
{	-1716	,	1679	,	-1087	},
{	-1729	,	1677	,	-1091	},
{	-1744	,	1677	,	-1095	},
{	-1755	,	1673	,	-1097	},
{	-1765	,	1666	,	-1097	},
{	-1785	,	1671	,	-1104	},
{	-1797	,	1669	,	-1107	},
{	-1807	,	1666	,	-1108	},
{	-1824	,	1668	,	-1114	},
{	-1836	,	1665	,	-1116	},
{	-1846	,	1660	,	-1118	},
{	-1859	,	1659	,	-1122	},
{	-1872	,	1657	,	-1125	},
{	-1886	,	1658	,	-1128	},
{	-1895	,	1655	,	-1130	},
{	-1905	,	1652	,	-1132	},
{	-1916	,	1652	,	-1135	},
{	-1925	,	1648	,	-1137	},
{	-1937	,	1647	,	-1140	},
{	-1944	,	1642	,	-1140	},
{	-1958	,	1643	,	-1145	},
{	-1970	,	1643	,	-1148	},
{	-1976	,	1638	,	-1148	},
{	-1991	,	1638	,	-1153	},
{	-2004	,	1639	,	-1157	},
{	-2015	,	1636	,	-1160	},
{	-2030	,	1637	,	-1165	},
{	-2045	,	1639	,	-1169	},
{	-2058	,	1639	,	-1172	},
{	-2069	,	1637	,	-1174	},
{	-2083	,	1637	,	-1178	},
{	-2098	,	1638	,	-1184	},
{	-2112	,	1636	,	-1187	},
{	-2128	,	1638	,	-1194	},
{	-2138	,	1633	,	-1195	},
{	-2149	,	1629	,	-1197	},
{	-2161	,	1627	,	-1200	},
{	-2170	,	1624	,	-1201	},
{	-2187	,	1626	,	-1206	},
{	-2194	,	1620	,	-1206	},
{	-2206	,	1618	,	-1208	},
{	-2220	,	1618	,	-1212	},
{	-2237	,	1619	,	-1217	},
{	-2244	,	1614	,	-1216	},
{	-2257	,	1612	,	-1218	},
{	-2268	,	1610	,	-1220	},
{	-2280	,	1608	,	-1222	},
{	-2291	,	1605	,	-1223	},
{	-2301	,	1604	,	-1224	},
{	-2313	,	1606	,	-1227	},
{	-2323	,	1604	,	-1229	},
{	-2340	,	1609	,	-1235	},
{	-2350	,	1608	,	-1236	},
{	-2372	,	1614	,	-1243	},
{	-2378	,	1608	,	-1242	},
{	-2394	,	1611	,	-1246	},
{	-2406	,	1612	,	-1248	},
{	-2416	,	1610	,	-1249	},
{	-2428	,	1609	,	-1251	},
{	-2431	,	1603	,	-1249	},
{	-2446	,	1607	,	-1254	},
{	-2456	,	1607	,	-1256	},
{	-2466	,	1606	,	-1258	},
{	-2479	,	1607	,	-1261	},
{	-2494	,	1609	,	-1265	},
{	-2501	,	1605	,	-1265	},
{	-2517	,	1604	,	-1270	},
{	-2527	,	1601	,	-1271	},
{	-2537	,	1599	,	-1272	},
{	-2550	,	1598	,	-1274	},
{	-2554	,	1590	,	-1272	},
{	-2571	,	1592	,	-1276	},
{	-2573	,	1584	,	-1273	},
{	-2591	,	1584	,	-1279	},
{	-2602	,	1583	,	-1281	},
{	-2616	,	1582	,	-1284	},
{	-2629	,	1580	,	-1285	},
{	-2644	,	1579	,	-1288	},
{	-2655	,	1574	,	-1288	},
{	-2667	,	1573	,	-1290	},
{	-2678	,	1570	,	-1291	},
{	-2685	,	1564	,	-1291	},
{	-2700	,	1564	,	-1293	},
{	-2709	,	1561	,	-1293	},
{	-2721	,	1560	,	-1295	},
{	-2728	,	1554	,	-1294	},
{	-2742	,	1553	,	-1296	},
{	-2759	,	1554	,	-1300	},
{	-2773	,	1554	,	-1303	},
{	-2789	,	1554	,	-1308	},
{	-2795	,	1548	,	-1306	},
{	-2815	,	1550	,	-1311	},
{	-2821	,	1544	,	-1310	},
{	-2840	,	1546	,	-1315	},
{	-2844	,	1538	,	-1312	},
{	-2864	,	1539	,	-1317	},
{	-2880	,	1538	,	-1320	},
{	-2893	,	1535	,	-1322	},
{	-2913	,	1536	,	-1327	},
{	-2928	,	1535	,	-1330	},
{	-2939	,	1531	,	-1331	},
{	-2952	,	1529	,	-1333	},
{	-2971	,	1529	,	-1337	},
{	-2989	,	1530	,	-1341	},
{	-2996	,	1524	,	-1340	},
{	-3013	,	1523	,	-1343	},
{	-3024	,	1521	,	-1343	},
{	-3041	,	1522	,	-1347	},
{	-3047	,	1516	,	-1345	},
{	-3066	,	1517	,	-1348	},
{	-3081	,	1515	,	-1350	},
{	-3099	,	1516	,	-1353	},
{	-3107	,	1512	,	-1352	},
{	-3118	,	1509	,	-1354	},
{	-3135	,	1508	,	-1357	},
{	-3146	,	1505	,	-1357	},
{	-3165	,	1505	,	-1361	},
{	-3180	,	1503	,	-1363	},
{	-3193	,	1501	,	-1365	},
{	-3206	,	1498	,	-1366	},
{	-3213	,	1491	,	-1366	},
{	-3229	,	1488	,	-1370	},
{	-3245	,	1483	,	-1374	},
{	-3255	,	1476	,	-1376	},
{	-3278	,	1475	,	-1383	},
{	-3287	,	1469	,	-1385	},
{	-3298	,	1463	,	-1389	},
{	-3306	,	1455	,	-1391	},
{	-3317	,	1448	,	-1396	},
{	-3326	,	1446	,	-1400	},
{	-3333	,	1443	,	-1401	},
{	-3337	,	1438	,	-1402	},
{	-3341	,	1434	,	-1403	},
{	-3342	,	1428	,	-1404	},
{	-3348	,	1423	,	-1406	},
{	-3355	,	1419	,	-1409	},
{	-3358	,	1413	,	-1411	}
};

#endif	/* TABLE_LUGE7_SN132_H */

