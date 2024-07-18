

#ifndef TABLE_LUGE7_SN160_H
#define	TABLE_LUGE7_SN160_H

// used in LUGE7_SN160 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14872 )

int16_t residual_offset[] = { 268-242 , 298-193 , 44-77 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1969	,	-4126	,	376	},
{	-1973	,	-4134	,	373	},
{	-1968	,	-4123	,	369	},
{	-1970	,	-4122	,	367	},
{	-1969	,	-4121	,	364	},
{	-1969	,	-4119	,	362	},
{	-1965	,	-4109	,	359	},
{	-1969	,	-4115	,	356	},
{	-1965	,	-4106	,	354	},
{	-1970	,	-4109	,	350	},
{	-1969	,	-4100	,	345	},
{	-1969	,	-4096	,	340	},
{	-1962	,	-4077	,	333	},
{	-1961	,	-4077	,	327	},
{	-1955	,	-4067	,	321	},
{	-1949	,	-4054	,	314	},
{	-1949	,	-4053	,	309	},
{	-1947	,	-4050	,	303	},
{	-1938	,	-4033	,	296	},
{	-1938	,	-4034	,	291	},
{	-1929	,	-4021	,	284	},
{	-1926	,	-4013	,	277	},
{	-1921	,	-4004	,	270	},
{	-1923	,	-4009	,	264	},
{	-1911	,	-3990	,	257	},
{	-1909	,	-3988	,	250	},
{	-1905	,	-3987	,	244	},
{	-1900	,	-3981	,	238	},
{	-1892	,	-3971	,	231	},
{	-1892	,	-3975	,	225	},
{	-1884	,	-3966	,	219	},
{	-1877	,	-3954	,	212	},
{	-1874	,	-3954	,	206	},
{	-1870	,	-3949	,	199	},
{	-1860	,	-3929	,	192	},
{	-1857	,	-3929	,	185	},
{	-1852	,	-3922	,	179	},
{	-1850	,	-3923	,	174	},
{	-1843	,	-3915	,	168	},
{	-1840	,	-3910	,	162	},
{	-1830	,	-3895	,	155	},
{	-1827	,	-3890	,	148	},
{	-1823	,	-3885	,	142	},
{	-1813	,	-3866	,	134	},
{	-1805	,	-3854	,	128	},
{	-1801	,	-3848	,	121	},
{	-1792	,	-3834	,	115	},
{	-1791	,	-3834	,	108	},
{	-1787	,	-3826	,	102	},
{	-1777	,	-3807	,	95	},
{	-1776	,	-3808	,	88	},
{	-1772	,	-3802	,	81	},
{	-1771	,	-3798	,	74	},
{	-1764	,	-3786	,	68	},
{	-1755	,	-3767	,	60	},
{	-1753	,	-3762	,	53	},
{	-1744	,	-3748	,	47	},
{	-1742	,	-3746	,	40	},
{	-1736	,	-3735	,	34	},
{	-1725	,	-3718	,	27	},
{	-1727	,	-3722	,	20	},
{	-1718	,	-3708	,	13	},
{	-1718	,	-3706	,	7	},
{	-1710	,	-3693	,	0	},
{	-1705	,	-3683	,	-7	},
{	-1696	,	-3669	,	-14	},
{	-1695	,	-3667	,	-22	},
{	-1691	,	-3661	,	-29	},
{	-1686	,	-3654	,	-35	},
{	-1674	,	-3630	,	-41	},
{	-1671	,	-3624	,	-48	},
{	-1667	,	-3617	,	-55	},
{	-1660	,	-3605	,	-62	},
{	-1658	,	-3603	,	-69	},
{	-1647	,	-3582	,	-76	},
{	-1647	,	-3582	,	-83	},
{	-1646	,	-3581	,	-89	},
{	-1638	,	-3568	,	-96	},
{	-1635	,	-3561	,	-103	},
{	-1627	,	-3544	,	-109	},
{	-1626	,	-3543	,	-115	},
{	-1618	,	-3526	,	-123	},
{	-1616	,	-3522	,	-131	},
{	-1613	,	-3518	,	-138	},
{	-1603	,	-3499	,	-144	},
{	-1598	,	-3491	,	-150	},
{	-1595	,	-3487	,	-156	},
{	-1589	,	-3474	,	-163	},
{	-1585	,	-3469	,	-169	},
{	-1582	,	-3460	,	-175	},
{	-1577	,	-3451	,	-181	},
{	-1573	,	-3444	,	-187	},
{	-1570	,	-3435	,	-193	},
{	-1568	,	-3430	,	-200	},
{	-1567	,	-3421	,	-205	},
{	-1565	,	-3417	,	-211	},
{	-1563	,	-3410	,	-218	},
{	-1559	,	-3398	,	-224	},
{	-1559	,	-3395	,	-230	},
{	-1562	,	-3397	,	-237	},
{	-1557	,	-3383	,	-243	},
{	-1555	,	-3372	,	-248	},
{	-1558	,	-3374	,	-256	},
{	-1557	,	-3368	,	-263	},
{	-1555	,	-3359	,	-268	},
{	-1553	,	-3351	,	-273	},
{	-1554	,	-3351	,	-280	},
{	-1551	,	-3339	,	-285	},
{	-1557	,	-3346	,	-292	},
{	-1553	,	-3333	,	-298	},
{	-1553	,	-3326	,	-305	},
{	-1551	,	-3317	,	-311	},
{	-1550	,	-3311	,	-318	},
{	-1548	,	-3302	,	-324	},
{	-1546	,	-3293	,	-331	},
{	-1544	,	-3283	,	-337	},
{	-1537	,	-3263	,	-342	},
{	-1535	,	-3256	,	-348	},
{	-1534	,	-3252	,	-355	},
{	-1530	,	-3235	,	-360	},
{	-1527	,	-3224	,	-366	},
{	-1526	,	-3220	,	-373	},
{	-1529	,	-3221	,	-383	},
{	-1523	,	-3203	,	-390	},
{	-1521	,	-3197	,	-399	},
{	-1515	,	-3182	,	-407	},
{	-1513	,	-3173	,	-414	},
{	-1508	,	-3158	,	-421	},
{	-1507	,	-3154	,	-430	},
{	-1505	,	-3144	,	-438	},
{	-1506	,	-3143	,	-448	},
{	-1508	,	-3136	,	-456	},
{	-1506	,	-3127	,	-464	},
{	-1507	,	-3123	,	-474	},
{	-1506	,	-3114	,	-483	},
{	-1507	,	-3104	,	-492	},
{	-1509	,	-3101	,	-502	},
{	-1510	,	-3095	,	-512	},
{	-1510	,	-3082	,	-520	},
{	-1509	,	-3068	,	-528	},
{	-1513	,	-3065	,	-536	},
{	-1517	,	-3058	,	-544	},
{	-1517	,	-3043	,	-551	},
{	-1521	,	-3036	,	-559	},
{	-1525	,	-3030	,	-568	},
{	-1523	,	-3014	,	-574	},
{	-1528	,	-3010	,	-584	},
{	-1525	,	-2989	,	-590	},
{	-1531	,	-2984	,	-599	},
{	-1533	,	-2971	,	-606	},
{	-1534	,	-2957	,	-613	},
{	-1538	,	-2948	,	-621	},
{	-1541	,	-2938	,	-627	},
{	-1539	,	-2917	,	-632	},
{	-1543	,	-2911	,	-640	},
{	-1545	,	-2901	,	-648	},
{	-1548	,	-2891	,	-655	},
{	-1549	,	-2876	,	-661	},
{	-1550	,	-2864	,	-669	},
{	-1554	,	-2857	,	-677	},
{	-1553	,	-2843	,	-684	},
{	-1556	,	-2835	,	-693	},
{	-1559	,	-2824	,	-701	},
{	-1559	,	-2810	,	-707	},
{	-1565	,	-2806	,	-717	},
{	-1564	,	-2790	,	-723	},
{	-1568	,	-2784	,	-732	},
{	-1573	,	-2779	,	-741	},
{	-1575	,	-2769	,	-748	},
{	-1577	,	-2762	,	-756	},
{	-1580	,	-2756	,	-764	},
{	-1580	,	-2743	,	-770	},
{	-1585	,	-2740	,	-779	},
{	-1587	,	-2729	,	-786	},
{	-1588	,	-2717	,	-793	},
{	-1592	,	-2710	,	-800	},
{	-1594	,	-2701	,	-806	},
{	-1598	,	-2691	,	-814	},
{	-1595	,	-2670	,	-819	},
{	-1601	,	-2668	,	-828	},
{	-1603	,	-2661	,	-836	},
{	-1604	,	-2652	,	-842	},
{	-1605	,	-2644	,	-849	},
{	-1610	,	-2642	,	-858	},
{	-1611	,	-2632	,	-864	},
{	-1611	,	-2623	,	-871	},
{	-1614	,	-2615	,	-878	},
{	-1615	,	-2605	,	-885	},
{	-1618	,	-2598	,	-893	},
{	-1618	,	-2586	,	-898	},
{	-1619	,	-2578	,	-905	},
{	-1625	,	-2579	,	-915	},
{	-1622	,	-2564	,	-920	},
{	-1625	,	-2560	,	-930	},
{	-1626	,	-2554	,	-938	},
{	-1628	,	-2549	,	-945	},
{	-1627	,	-2537	,	-951	},
{	-1631	,	-2532	,	-960	},
{	-1631	,	-2521	,	-965	},
{	-1636	,	-2515	,	-974	},
{	-1634	,	-2501	,	-979	},
{	-1634	,	-2490	,	-985	},
{	-1635	,	-2479	,	-992	},
{	-1637	,	-2474	,	-1000	},
{	-1638	,	-2466	,	-1007	},
{	-1641	,	-2460	,	-1015	},
{	-1641	,	-2451	,	-1022	},
{	-1643	,	-2442	,	-1029	},
{	-1641	,	-2427	,	-1035	},
{	-1650	,	-2427	,	-1046	},
{	-1647	,	-2411	,	-1052	},
{	-1651	,	-2407	,	-1061	},
{	-1654	,	-2402	,	-1070	},
{	-1655	,	-2392	,	-1076	},
{	-1655	,	-2382	,	-1083	},
{	-1659	,	-2376	,	-1091	},
{	-1662	,	-2371	,	-1099	},
{	-1662	,	-2361	,	-1106	},
{	-1664	,	-2353	,	-1112	},
{	-1669	,	-2350	,	-1121	},
{	-1670	,	-2338	,	-1126	},
{	-1676	,	-2335	,	-1136	},
{	-1678	,	-2326	,	-1141	},
{	-1682	,	-2321	,	-1148	},
{	-1683	,	-2310	,	-1154	},
{	-1688	,	-2305	,	-1163	},
{	-1688	,	-2295	,	-1168	},
{	-1692	,	-2291	,	-1177	},
{	-1693	,	-2280	,	-1182	},
{	-1699	,	-2277	,	-1190	},
{	-1703	,	-2271	,	-1197	},
{	-1702	,	-2258	,	-1201	},
{	-1709	,	-2252	,	-1209	},
{	-1710	,	-2245	,	-1216	},
{	-1710	,	-2235	,	-1221	},
{	-1712	,	-2229	,	-1228	},
{	-1715	,	-2222	,	-1235	},
{	-1713	,	-2211	,	-1239	},
{	-1716	,	-2202	,	-1246	},
{	-1715	,	-2190	,	-1251	},
{	-1717	,	-2182	,	-1258	},
{	-1720	,	-2175	,	-1266	},
{	-1720	,	-2164	,	-1271	},
{	-1719	,	-2153	,	-1276	},
{	-1721	,	-2145	,	-1282	},
{	-1726	,	-2140	,	-1291	},
{	-1723	,	-2125	,	-1293	},
{	-1724	,	-2116	,	-1299	},
{	-1730	,	-2111	,	-1307	},
{	-1729	,	-2100	,	-1312	},
{	-1730	,	-2090	,	-1317	},
{	-1734	,	-2083	,	-1324	},
{	-1737	,	-2074	,	-1329	},
{	-1738	,	-2066	,	-1335	},
{	-1741	,	-2061	,	-1341	},
{	-1745	,	-2055	,	-1347	},
{	-1747	,	-2047	,	-1353	},
{	-1748	,	-2037	,	-1358	},
{	-1753	,	-2035	,	-1366	},
{	-1759	,	-2030	,	-1374	},
{	-1762	,	-2024	,	-1381	},
{	-1768	,	-2019	,	-1388	},
{	-1772	,	-2014	,	-1395	},
{	-1777	,	-2009	,	-1402	},
{	-1785	,	-2008	,	-1413	},
{	-1785	,	-1999	,	-1417	},
{	-1791	,	-1996	,	-1426	},
{	-1797	,	-1991	,	-1433	},
{	-1803	,	-1987	,	-1440	},
{	-1811	,	-1985	,	-1450	},
{	-1816	,	-1979	,	-1456	},
{	-1822	,	-1973	,	-1464	},
{	-1824	,	-1963	,	-1469	},
{	-1831	,	-1959	,	-1479	},
{	-1836	,	-1952	,	-1486	},
{	-1839	,	-1941	,	-1491	},
{	-1837	,	-1928	,	-1493	},
{	-1843	,	-1922	,	-1500	},
{	-1848	,	-1916	,	-1506	},
{	-1850	,	-1904	,	-1511	},
{	-1855	,	-1898	,	-1518	},
{	-1855	,	-1885	,	-1522	},
{	-1858	,	-1875	,	-1526	},
{	-1860	,	-1865	,	-1531	},
{	-1862	,	-1854	,	-1536	},
{	-1868	,	-1847	,	-1544	},
{	-1867	,	-1833	,	-1546	},
{	-1870	,	-1822	,	-1551	},
{	-1872	,	-1812	,	-1556	},
{	-1876	,	-1803	,	-1563	},
{	-1879	,	-1793	,	-1569	},
{	-1883	,	-1785	,	-1576	},
{	-1887	,	-1777	,	-1581	},
{	-1897	,	-1773	,	-1593	},
{	-1899	,	-1764	,	-1598	},
{	-1903	,	-1753	,	-1604	},
{	-1907	,	-1744	,	-1610	},
{	-1911	,	-1736	,	-1616	},
{	-1917	,	-1729	,	-1624	},
{	-1921	,	-1721	,	-1630	},
{	-1926	,	-1711	,	-1636	},
{	-1932	,	-1703	,	-1642	},
{	-1935	,	-1693	,	-1648	},
{	-1942	,	-1686	,	-1656	},
{	-1946	,	-1676	,	-1661	},
{	-1956	,	-1670	,	-1672	},
{	-1957	,	-1658	,	-1676	},
{	-1964	,	-1651	,	-1685	},
{	-1970	,	-1643	,	-1692	},
{	-1980	,	-1638	,	-1703	},
{	-1980	,	-1626	,	-1706	},
{	-1986	,	-1616	,	-1713	},
{	-1991	,	-1608	,	-1721	},
{	-1990	,	-1595	,	-1723	},
{	-1995	,	-1587	,	-1730	},
{	-1999	,	-1577	,	-1737	},
{	-2010	,	-1574	,	-1749	},
{	-2013	,	-1564	,	-1754	},
{	-2013	,	-1552	,	-1758	},
{	-2020	,	-1545	,	-1766	},
{	-2022	,	-1535	,	-1770	},
{	-2029	,	-1528	,	-1780	},
{	-2033	,	-1518	,	-1786	},
{	-2041	,	-1513	,	-1796	},
{	-2040	,	-1499	,	-1796	},
{	-2043	,	-1488	,	-1800	},
{	-2043	,	-1476	,	-1803	},
{	-2049	,	-1469	,	-1810	},
{	-2054	,	-1460	,	-1816	},
{	-2057	,	-1450	,	-1820	},
{	-2062	,	-1442	,	-1827	},
{	-2068	,	-1433	,	-1834	},
{	-2070	,	-1422	,	-1837	},
{	-2072	,	-1412	,	-1841	},
{	-2077	,	-1405	,	-1848	},
{	-2084	,	-1398	,	-1854	},
{	-2086	,	-1387	,	-1858	},
{	-2093	,	-1380	,	-1866	},
{	-2093	,	-1367	,	-1867	},
{	-2097	,	-1359	,	-1872	},
{	-2103	,	-1350	,	-1879	},
{	-2114	,	-1346	,	-1890	},
{	-2117	,	-1336	,	-1893	},
{	-2124	,	-1328	,	-1900	},
{	-2126	,	-1317	,	-1903	},
{	-2132	,	-1309	,	-1908	},
{	-2136	,	-1300	,	-1913	},
{	-2141	,	-1290	,	-1917	},
{	-2150	,	-1284	,	-1924	},
{	-2155	,	-1280	,	-1929	},
{	-2157	,	-1275	,	-1931	},
{	-2160	,	-1270	,	-1935	},
{	-2163	,	-1264	,	-1938	},
{	-2164	,	-1259	,	-1941	},
{	-2168	,	-1255	,	-1944	},
{	-2176	,	-1254	,	-1951	},
{	-2177	,	-1248	,	-1950	}
};

#endif	/* TABLE_LUGE7_SN160_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11223)

int16_t accel_residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-3,5,-6},
{-3,5,-6},
{-3,4,-1},
{-1,4,4},
{-1,4,4},
{-1,3,4},
{0,3,4},
{0,3,2},
{0,3,1},
{0,2,1},
{0,2,2},
{0,1,2},
{0,1,3},
{0,1,2},
{0,1,2},
{0,0,2},
{0,0,2},
{0,0,3},
{0,0,3},
{0,0,3},
{0,0,4},
{0,0,4},
{0,-1,4},
{0,-1,5},
{0,-2,5},
{1,-2,5},
{1,-2,5},
{1,-2,6},
{1,-3,6},
{1,-3,6},
{1,-3,6},
{1,-4,7},
{2,-4,7},
{2,-4,8},
{2,-5,8},
{2,-5,8},
{3,-5,9},
{3,-6,9},
{3,-6,9},
{3,-6,9},
{3,-6,10},
{3,-7,10},
{3,-7,10},
{3,-7,10},
{3,-8,11},
{3,-8,11},
{3,-8,11},
{3,-8,11},
{3,-8,11},
{4,-8,11},
{4,-9,12},
{4,-9,12},
{4,-9,12},
{5,-10,12},
{4,-10,13},
{4,-10,13},
{5,-11,13},
{5,-11,13},
{5,-11,14},
{5,-11,15},
{5,-12,15},
{5,-12,15},
{5,-12,16},
{5,-12,16},
{5,-12,16},
{5,-12,16},
{6,-13,16},
{5,-13,17},
{5,-13,17},
{6,-13,17},
{6,-13,17},
{6,-13,17},
{6,-13,17},
{6,-13,18},
{6,-13,18},
{6,-14,18},
{7,-13,18},
{7,-13,18},
{7,-14,19},
{7,-13,19},
{7,-13,19},
{7,-13,19},
{7,-13,20},
{7,-14,20},
{7,-14,20},
{7,-13,20},
{7,-13,20},
{7,-13,20},
{7,-13,20},
{7,-13,20},
{7,-13,20},
{7,-13,20},
{7,-13,20},
{7,-13,20},
{7,-14,20},
{7,-14,20},
{7,-14,20},
{7,-14,20},
{7,-14,19},
{7,-14,19},
{7,-15,19},
{7,-15,19},
{7,-16,19},
{7,-16,19},
{7,-16,18},
{7,-16,18},
{7,-16,18},
{7,-17,18},
{7,-17,18},
{7,-17,18},
{7,-17,18},
{7,-17,18},
{7,-18,18},
{7,-18,18},
{7,-18,18},
{7,-18,18},
{7,-18,19},
{7,-18,19},
{7,-18,19},
{8,-18,19},
{8,-19,19},
{7,-19,19},
{7,-19,19},
{7,-19,19},
{7,-19,20},
{7,-19,20},
{8,-20,20},
{7,-20,20},
{7,-20,20},
{7,-20,21},
{7,-20,21},
{7,-20,21},
{7,-21,21},
{8,-21,21},
{8,-21,22},
{8,-21,22},
{8,-21,22},
{8,-21,22},
{8,-21,22},
{8,-21,22},
{8,-22,23},
{8,-22,23},
{8,-22,23},
{8,-22,23},
{8,-22,24},
{8,-22,24},
{8,-23,24},
{8,-23,24},
{8,-23,25},
{8,-23,25},
{8,-23,25},
{8,-23,25},
{8,-23,26},
{8,-23,26},
{8,-24,26},
{8,-24,27},
{8,-24,27},
{8,-24,27},
{8,-24,27},
{8,-25,28},
{8,-25,28},
{8,-25,28},
{8,-25,28},
{8,-25,29},
{8,-25,29},
{8,-26,29},
{8,-26,29},
{8,-26,30},
{8,-26,30},
{8,-26,30},
{8,-26,31},
{8,-26,31},
{8,-27,31},
{8,-27,31},
{9,-27,32},
{8,-27,32},
{8,-28,32},
{8,-28,33},
{8,-28,33},
{8,-28,33},
{8,-28,34},
{8,-28,34},
{8,-29,34},
{8,-29,35},
{8,-29,35},
{8,-29,36},
{8,-29,36},
{8,-29,36},
{9,-30,37},
{9,-30,37},
{9,-30,37},
{9,-30,38},
{9,-30,38},
{9,-30,38},
{9,-31,38},
{9,-31,39},
{9,-31,39},
{9,-31,40},
{9,-32,40},
{9,-32,40},
{9,-32,40},
{9,-32,41},
{9,-32,41},
{9,-33,41},
{9,-33,42},
{9,-33,42},
{9,-33,42},
{9,-33,43},
{9,-33,43},
{9,-34,44},
{9,-34,44},
{9,-34,45},
{9,-34,45},
{9,-34,46},
{9,-34,46},
{9,-34,47},
{9,-34,47},
{9,-34,48},
{9,-34,49},
{9,-34,49},
{9,-35,50},
{9,-35,50},
{9,-35,51},
{9,-35,52},
{9,-35,53},
{9,-35,54},
{9,-34,55},
{8,-34,56},
{8,-34,57},
{8,-34,59},
{8,-33,60},
};



