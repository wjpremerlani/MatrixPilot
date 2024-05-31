

#ifndef TABLE_LUGE7_SN193_H
#define	TABLE_LUGE7_SN193_H

// used in LUGE7_SN193 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14456 )

int16_t residual_offset[] = { -420 -4*13 , 229 +4*77 , -34 -4*45} ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	2275	,	-2324	,	-1781	},
{	2275	,	-2323	,	-1779	},
{	2264	,	-2311	,	-1768	},
{	2262	,	-2314	,	-1767	},
{	2255	,	-2309	,	-1762	},
{	2255	,	-2311	,	-1762	},
{	2255	,	-2313	,	-1762	},
{	2254	,	-2312	,	-1760	},
{	2252	,	-2310	,	-1757	},
{	2253	,	-2311	,	-1756	},
{	2245	,	-2302	,	-1746	},
{	2241	,	-2298	,	-1742	},
{	2233	,	-2291	,	-1734	},
{	2233	,	-2293	,	-1733	},
{	2224	,	-2286	,	-1726	},
{	2219	,	-2278	,	-1719	},
{	2214	,	-2275	,	-1714	},
{	2206	,	-2267	,	-1706	},
{	2198	,	-2261	,	-1699	},
{	2196	,	-2261	,	-1697	},
{	2191	,	-2254	,	-1692	},
{	2185	,	-2247	,	-1685	},
{	2179	,	-2238	,	-1677	},
{	2171	,	-2229	,	-1669	},
{	2164	,	-2220	,	-1663	},
{	2155	,	-2211	,	-1654	},
{	2156	,	-2211	,	-1654	},
{	2149	,	-2202	,	-1647	},
{	2143	,	-2196	,	-1642	},
{	2138	,	-2190	,	-1639	},
{	2131	,	-2181	,	-1633	},
{	2128	,	-2177	,	-1628	},
{	2123	,	-2172	,	-1623	},
{	2117	,	-2164	,	-1615	},
{	2114	,	-2160	,	-1611	},
{	2111	,	-2154	,	-1607	},
{	2108	,	-2149	,	-1602	},
{	2102	,	-2141	,	-1596	},
{	2096	,	-2135	,	-1590	},
{	2088	,	-2127	,	-1585	},
{	2083	,	-2121	,	-1580	},
{	2079	,	-2118	,	-1575	},
{	2076	,	-2113	,	-1571	},
{	2069	,	-2104	,	-1563	},
{	2063	,	-2100	,	-1557	},
{	2054	,	-2086	,	-1547	},
{	2050	,	-2079	,	-1540	},
{	2047	,	-2076	,	-1537	},
{	2040	,	-2069	,	-1531	},
{	2029	,	-2058	,	-1521	},
{	2027	,	-2056	,	-1518	},
{	2024	,	-2050	,	-1513	},
{	2013	,	-2040	,	-1504	},
{	2007	,	-2034	,	-1499	},
{	2002	,	-2026	,	-1492	},
{	2002	,	-2025	,	-1490	},
{	1996	,	-2015	,	-1482	},
{	1993	,	-2014	,	-1480	},
{	1989	,	-2006	,	-1473	},
{	1982	,	-1997	,	-1466	},
{	1975	,	-1987	,	-1458	},
{	1972	,	-1980	,	-1454	},
{	1967	,	-1975	,	-1448	},
{	1959	,	-1967	,	-1441	},
{	1948	,	-1955	,	-1432	},
{	1945	,	-1949	,	-1427	},
{	1943	,	-1943	,	-1423	},
{	1935	,	-1932	,	-1416	},
{	1923	,	-1922	,	-1407	},
{	1923	,	-1919	,	-1405	},
{	1921	,	-1915	,	-1402	},
{	1914	,	-1908	,	-1396	},
{	1907	,	-1899	,	-1388	},
{	1907	,	-1898	,	-1386	},
{	1895	,	-1881	,	-1375	},
{	1889	,	-1871	,	-1368	},
{	1886	,	-1865	,	-1363	},
{	1881	,	-1859	,	-1358	},
{	1876	,	-1852	,	-1351	},
{	1875	,	-1850	,	-1350	},
{	1870	,	-1848	,	-1345	},
{	1861	,	-1839	,	-1337	},
{	1858	,	-1835	,	-1333	},
{	1852	,	-1826	,	-1327	},
{	1846	,	-1822	,	-1321	},
{	1847	,	-1820	,	-1320	},
{	1839	,	-1808	,	-1312	},
{	1827	,	-1793	,	-1302	},
{	1824	,	-1790	,	-1299	},
{	1821	,	-1787	,	-1296	},
{	1814	,	-1778	,	-1290	},
{	1810	,	-1775	,	-1288	},
{	1810	,	-1774	,	-1287	},
{	1804	,	-1772	,	-1285	},
{	1797	,	-1767	,	-1282	},
{	1792	,	-1761	,	-1281	},
{	1784	,	-1751	,	-1277	},
{	1778	,	-1742	,	-1273	},
{	1775	,	-1738	,	-1272	},
{	1766	,	-1728	,	-1268	},
{	1762	,	-1726	,	-1268	},
{	1761	,	-1722	,	-1266	},
{	1751	,	-1711	,	-1261	},
{	1750	,	-1712	,	-1262	},
{	1746	,	-1709	,	-1261	},
{	1742	,	-1703	,	-1260	},
{	1734	,	-1692	,	-1254	},
{	1729	,	-1689	,	-1252	},
{	1727	,	-1686	,	-1253	},
{	1717	,	-1679	,	-1247	},
{	1711	,	-1667	,	-1241	},
{	1703	,	-1657	,	-1235	},
{	1696	,	-1649	,	-1229	},
{	1692	,	-1644	,	-1226	},
{	1688	,	-1638	,	-1223	},
{	1681	,	-1629	,	-1218	},
{	1673	,	-1620	,	-1212	},
{	1667	,	-1614	,	-1209	},
{	1660	,	-1607	,	-1206	},
{	1657	,	-1605	,	-1207	},
{	1650	,	-1597	,	-1202	},
{	1646	,	-1590	,	-1199	},
{	1635	,	-1579	,	-1194	},
{	1633	,	-1577	,	-1194	},
{	1624	,	-1566	,	-1189	},
{	1614	,	-1555	,	-1184	},
{	1609	,	-1549	,	-1182	},
{	1600	,	-1542	,	-1180	},
{	1595	,	-1536	,	-1179	},
{	1589	,	-1531	,	-1178	},
{	1579	,	-1522	,	-1174	},
{	1567	,	-1512	,	-1169	},
{	1564	,	-1509	,	-1171	},
{	1559	,	-1504	,	-1171	},
{	1547	,	-1491	,	-1165	},
{	1537	,	-1481	,	-1163	},
{	1525	,	-1465	,	-1156	},
{	1515	,	-1456	,	-1155	},
{	1506	,	-1448	,	-1153	},
{	1501	,	-1441	,	-1153	},
{	1488	,	-1427	,	-1149	},
{	1478	,	-1416	,	-1147	},
{	1472	,	-1412	,	-1148	},
{	1457	,	-1396	,	-1142	},
{	1450	,	-1389	,	-1144	},
{	1440	,	-1381	,	-1143	},
{	1429	,	-1371	,	-1141	},
{	1419	,	-1362	,	-1142	},
{	1409	,	-1351	,	-1142	},
{	1394	,	-1337	,	-1139	},
{	1378	,	-1321	,	-1135	},
{	1370	,	-1314	,	-1136	},
{	1356	,	-1300	,	-1132	},
{	1345	,	-1291	,	-1133	},
{	1332	,	-1275	,	-1129	},
{	1317	,	-1260	,	-1126	},
{	1303	,	-1246	,	-1123	},
{	1287	,	-1230	,	-1119	},
{	1276	,	-1219	,	-1117	},
{	1259	,	-1199	,	-1113	},
{	1246	,	-1183	,	-1111	},
{	1232	,	-1168	,	-1108	},
{	1215	,	-1151	,	-1104	},
{	1200	,	-1135	,	-1101	},
{	1186	,	-1121	,	-1099	},
{	1175	,	-1109	,	-1098	},
{	1161	,	-1093	,	-1094	},
{	1150	,	-1083	,	-1094	},
{	1134	,	-1067	,	-1090	},
{	1122	,	-1054	,	-1090	},
{	1111	,	-1041	,	-1088	},
{	1099	,	-1028	,	-1086	},
{	1087	,	-1016	,	-1086	},
{	1073	,	-1003	,	-1083	},
{	1063	,	-993	,	-1083	},
{	1049	,	-979	,	-1080	},
{	1036	,	-967	,	-1076	},
{	1026	,	-960	,	-1077	},
{	1012	,	-946	,	-1071	},
{	1004	,	-937	,	-1071	},
{	993	,	-926	,	-1068	},
{	981	,	-912	,	-1066	},
{	970	,	-900	,	-1063	},
{	958	,	-888	,	-1061	},
{	946	,	-874	,	-1058	},
{	936	,	-866	,	-1057	},
{	926	,	-857	,	-1054	},
{	912	,	-843	,	-1047	},
{	901	,	-833	,	-1045	},
{	891	,	-823	,	-1042	},
{	880	,	-813	,	-1038	},
{	868	,	-801	,	-1034	},
{	860	,	-793	,	-1034	},
{	850	,	-784	,	-1033	},
{	837	,	-772	,	-1027	},
{	827	,	-761	,	-1025	},
{	816	,	-751	,	-1023	},
{	805	,	-740	,	-1021	},
{	793	,	-730	,	-1016	},
{	781	,	-719	,	-1013	},
{	771	,	-712	,	-1011	},
{	761	,	-701	,	-1008	},
{	751	,	-689	,	-1006	},
{	741	,	-678	,	-1004	},
{	732	,	-670	,	-1005	},
{	721	,	-658	,	-1004	},
{	711	,	-649	,	-1003	},
{	702	,	-638	,	-1004	},
{	692	,	-629	,	-1003	},
{	682	,	-618	,	-1001	},
{	672	,	-608	,	-1000	},
{	664	,	-599	,	-1001	},
{	655	,	-590	,	-1001	},
{	644	,	-578	,	-998	},
{	636	,	-570	,	-998	},
{	627	,	-559	,	-997	},
{	618	,	-549	,	-997	},
{	609	,	-538	,	-996	},
{	601	,	-529	,	-999	},
{	592	,	-518	,	-998	},
{	582	,	-507	,	-996	},
{	574	,	-498	,	-997	},
{	565	,	-489	,	-995	},
{	556	,	-479	,	-996	},
{	547	,	-470	,	-994	},
{	539	,	-461	,	-995	},
{	530	,	-451	,	-994	},
{	522	,	-443	,	-996	},
{	513	,	-433	,	-994	},
{	505	,	-423	,	-994	},
{	497	,	-415	,	-995	},
{	488	,	-405	,	-994	},
{	479	,	-396	,	-992	},
{	470	,	-385	,	-991	},
{	463	,	-375	,	-991	},
{	454	,	-364	,	-988	},
{	447	,	-354	,	-988	},
{	438	,	-344	,	-988	},
{	429	,	-331	,	-983	},
{	422	,	-321	,	-984	},
{	414	,	-309	,	-981	},
{	406	,	-297	,	-980	},
{	398	,	-285	,	-976	},
{	389	,	-273	,	-974	},
{	379	,	-259	,	-969	},
{	371	,	-248	,	-967	},
{	363	,	-236	,	-965	},
{	355	,	-223	,	-963	},
{	346	,	-211	,	-960	},
{	340	,	-200	,	-962	},
{	332	,	-189	,	-960	},
{	324	,	-178	,	-958	},
{	316	,	-167	,	-957	},
{	308	,	-156	,	-957	},
{	299	,	-145	,	-954	},
{	291	,	-134	,	-955	},
{	282	,	-124	,	-952	},
{	273	,	-114	,	-951	},
{	264	,	-105	,	-950	},
{	255	,	-95	,	-949	},
{	247	,	-85	,	-949	},
{	239	,	-76	,	-951	},
{	230	,	-65	,	-950	},
{	221	,	-54	,	-948	},
{	212	,	-45	,	-950	},
{	204	,	-36	,	-952	},
{	195	,	-25	,	-951	},
{	187	,	-14	,	-952	},
{	178	,	-4	,	-953	},
{	169	,	6	,	-954	},
{	160	,	17	,	-950	},
{	153	,	28	,	-955	},
{	144	,	38	,	-955	},
{	136	,	50	,	-959	},
{	128	,	62	,	-959	},
{	118	,	75	,	-959	},
{	110	,	87	,	-962	},
{	102	,	98	,	-965	},
{	93	,	111	,	-966	},
{	84	,	124	,	-968	},
{	76	,	136	,	-970	},
{	67	,	150	,	-970	},
{	59	,	164	,	-969	},
{	51	,	177	,	-971	},
{	42	,	189	,	-969	},
{	34	,	202	,	-970	},
{	26	,	215	,	-967	},
{	17	,	229	,	-969	},
{	8	,	243	,	-966	},
{	-1	,	257	,	-968	},
{	-10	,	271	,	-966	},
{	-19	,	286	,	-966	},
{	-26	,	298	,	-969	},
{	-34	,	311	,	-968	},
{	-43	,	325	,	-966	},
{	-50	,	337	,	-965	},
{	-59	,	349	,	-967	},
{	-68	,	361	,	-967	},
{	-76	,	373	,	-965	},
{	-85	,	386	,	-967	},
{	-95	,	396	,	-966	},
{	-105	,	408	,	-967	},
{	-115	,	418	,	-965	},
{	-126	,	432	,	-969	},
{	-138	,	442	,	-967	},
{	-143	,	447	,	-968	},
{	-147	,	452	,	-968	},
{	-153	,	457	,	-969	},
{	-157	,	462	,	-968	},
{	-163	,	466	,	-966	},
{	-169	,	473	,	-966	},
{	-174	,	478	,	-967	},
{	-180	,	484	,	-968	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11844)

int16_t accel_residual_offset[] = { -13 , -1 , -51 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{1,0,0},
{0,0,0},
{0,0,-1},
{0,0,-2},
{0,0,-3},
{0,0,-4},
{0,0,-5},
{0,-1,-6},
{0,-1,-7},
{0,-2,-8},
{0,-2,0},
{1,-1,4},
{1,-1,0},
{2,-2,0},
{2,-2,0},
{2,-3,0},
{2,-3,0},
{2,-3,-1},
{2,-3,-1},
{2,-4,-1},
{2,-4,-1},
{2,-4,-1},
{2,-4,-1},
{2,-4,-1},
{2,-5,-1},
{3,-5,-1},
{2,-6,0},
{2,-6,0},
{2,-6,0},
{2,-6,0},
{2,-6,0},
{2,-6,0},
{2,-7,0},
{2,-7,0},
{2,-7,0},
{2,-8,0},
{2,-8,0},
{2,-8,0},
{2,-8,0},
{2,-9,1},
{2,-9,1},
{2,-9,1},
{2,-9,1},
{2,-9,1},
{2,-9,2},
{2,-10,2},
{3,-10,2},
{2,-11,2},
{2,-11,2},
{2,-11,2},
{3,-11,2},
{2,-11,3},
{2,-12,4},
{2,-12,4},
{2,-12,4},
{3,-12,4},
{3,-12,4},
{3,-13,4},
{3,-13,4},
{3,-13,5},
{3,-13,5},
{2,-13,5},
{2,-13,5},
{3,-14,5},
{3,-14,5},
{2,-14,6},
{2,-14,6},
{2,-15,6},
{2,-15,6},
{3,-15,6},
{3,-15,7},
{3,-15,7},
{3,-15,7},
{3,-15,7},
{3,-15,7},
{3,-15,8},
{3,-16,8},
{2,-16,8},
{2,-16,8},
{3,-16,9},
{2,-16,9},
{2,-16,9},
{3,-17,9},
{3,-17,9},
{3,-16,10},
{3,-16,10},
{3,-17,10},
{3,-17,11},
{3,-17,11},
{3,-17,11},
{3,-17,11},
{3,-17,11},
{3,-16,11},
{3,-16,12},
{3,-17,12},
{3,-17,12},
{3,-16,12},
{3,-16,13},
{3,-16,13},
{3,-16,13},
{3,-16,13},
{3,-16,13},
{3,-15,13},
{3,-15,14},
{3,-15,14},
{3,-15,14},
{3,-15,14},
{3,-15,15},
{3,-15,14},
{3,-15,14},
{3,-15,15},
{3,-15,15},
{3,-15,15},
{3,-15,15},
{3,-15,15},
{3,-16,15},
{3,-16,15},
{3,-16,15},
{3,-16,15},
{2,-16,15},
{2,-17,15},
{2,-17,15},
{2,-17,15},
{2,-17,15},
{2,-17,15},
{2,-17,15},
{2,-18,15},
{2,-18,16},
{2,-18,16},
{2,-18,16},
{2,-18,16},
{2,-18,16},
{2,-18,17},
{2,-19,17},
{1,-19,17},
{1,-19,17},
{1,-19,18},
{1,-19,18},
{1,-19,18},
{1,-19,18},
{1,-19,19},
{1,-19,19},
{1,-19,20},
{1,-19,20},
{1,-20,21},
{1,-20,21},
{1,-20,21},
{1,-20,22},
{1,-20,22},
{1,-20,22},
{1,-20,22},
{1,-21,23},
{0,-21,23},
{0,-21,24},
{0,-21,24},
{0,-21,24},
{0,-21,25},
{0,-21,25},
{0,-22,25},
{0,-22,26},
{0,-22,26},
{0,-22,26},
{0,-22,27},
{0,-22,27},
{0,-22,27},
{0,-23,27},
{0,-23,28},
{0,-23,28},
{0,-23,28},
{0,-24,28},
{0,-24,29},
{0,-24,29},
{0,-24,29},
{0,-24,30},
{0,-25,30},
{0,-25,30},
{0,-25,30},
{0,-25,30},
{0,-25,30},
{-1,-25,31},
{-1,-25,31},
{-1,-25,31},
{-1,-26,31},
{-1,-26,32},
{-1,-26,32},
{-1,-26,32},
{-1,-26,33},
{-1,-26,33},
{-1,-27,33},
{-1,-27,33},
{-1,-27,33},
{-1,-27,33},
{-1,-27,34},
{-1,-27,34},
{-2,-27,34},
{-2,-27,35},
{-2,-28,35},
{-2,-28,35},
{-2,-28,35},
{-2,-28,36},
{-2,-28,36},
{-2,-28,36},
{-2,-29,36},
{-2,-29,37},
{-2,-29,37},
{-2,-29,37},
{-2,-29,37},
{-3,-29,37},
{-2,-29,37},
{-2,-30,38},
{-3,-30,38},
{-3,-30,38},
{-3,-30,38},
{-3,-30,38},
{-3,-30,38},
{-3,-30,38},
{-3,-30,39},
{-3,-30,39},
{-3,-31,39},
{-3,-31,39},
{-3,-31,40},
{-3,-31,40},
{-3,-31,40},
{-3,-31,40},
{-3,-32,40},
{-3,-32,40},
{-3,-32,40},
{-4,-32,41},
{-4,-32,41},
{-3,-32,41},
{-3,-32,41},
{-4,-32,41},
{-4,-32,41},
{-4,-32,42},
{-4,-32,42},
{-4,-33,42},
{-4,-33,42},
{-4,-33,42},
{-4,-33,42},
{-4,-33,43},
{-4,-33,43},
{-4,-33,43},
{-4,-33,43},
{-4,-33,43},
{-4,-33,44},
};


#endif	/* TABLE_LUGE7_SN193_H */

