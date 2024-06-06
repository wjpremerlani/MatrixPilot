

#ifndef TABLE_LUGE7_SN182_H
#define	TABLE_LUGE7_SN182_H

// used in LUGE7_SN182 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14820 )

int16_t residual_offset[] = { -557 , 1117 , -729 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	306	,	1450	,	67	},
{	313	,	1449	,	69	},
{	321	,	1449	,	72	},
{	328	,	1452	,	75	},
{	335	,	1453	,	77	},
{	342	,	1454	,	79	},
{	349	,	1452	,	81	},
{	357	,	1452	,	82	},
{	364	,	1451	,	83	},
{	379	,	1453	,	87	},
{	393	,	1454	,	91	},
{	406	,	1451	,	95	},
{	418	,	1451	,	97	},
{	432	,	1447	,	100	},
{	447	,	1450	,	102	},
{	460	,	1448	,	106	},
{	472	,	1449	,	108	},
{	486	,	1450	,	110	},
{	498	,	1452	,	111	},
{	509	,	1452	,	113	},
{	520	,	1448	,	114	},
{	532	,	1449	,	115	},
{	544	,	1449	,	118	},
{	557	,	1451	,	119	},
{	570	,	1453	,	121	},
{	583	,	1453	,	122	},
{	598	,	1457	,	124	},
{	610	,	1454	,	126	},
{	623	,	1457	,	128	},
{	635	,	1455	,	130	},
{	649	,	1457	,	133	},
{	662	,	1456	,	135	},
{	676	,	1458	,	136	},
{	694	,	1464	,	137	},
{	708	,	1463	,	140	},
{	722	,	1460	,	143	},
{	737	,	1461	,	145	},
{	751	,	1462	,	148	},
{	765	,	1461	,	149	},
{	779	,	1463	,	151	},
{	794	,	1462	,	154	},
{	805	,	1459	,	155	},
{	818	,	1459	,	157	},
{	831	,	1456	,	160	},
{	848	,	1461	,	161	},
{	862	,	1462	,	163	},
{	877	,	1462	,	165	},
{	890	,	1462	,	165	},
{	904	,	1463	,	166	},
{	919	,	1462	,	167	},
{	928	,	1457	,	168	},
{	943	,	1459	,	170	},
{	958	,	1459	,	171	},
{	971	,	1457	,	172	},
{	985	,	1457	,	174	},
{	999	,	1457	,	176	},
{	1014	,	1456	,	176	},
{	1025	,	1453	,	176	},
{	1041	,	1457	,	178	},
{	1056	,	1458	,	180	},
{	1068	,	1455	,	181	},
{	1081	,	1453	,	183	},
{	1093	,	1452	,	184	},
{	1107	,	1451	,	185	},
{	1121	,	1451	,	186	},
{	1132	,	1448	,	186	},
{	1144	,	1450	,	186	},
{	1159	,	1450	,	188	},
{	1172	,	1449	,	189	},
{	1183	,	1449	,	189	},
{	1198	,	1450	,	191	},
{	1212	,	1453	,	192	},
{	1227	,	1453	,	193	},
{	1240	,	1451	,	194	},
{	1253	,	1450	,	195	},
{	1265	,	1446	,	196	},
{	1280	,	1448	,	197	},
{	1293	,	1450	,	198	},
{	1303	,	1447	,	198	},
{	1315	,	1444	,	198	},
{	1327	,	1444	,	198	},
{	1342	,	1444	,	199	},
{	1353	,	1443	,	201	},
{	1369	,	1443	,	204	},
{	1381	,	1442	,	204	},
{	1390	,	1436	,	204	},
{	1407	,	1438	,	205	},
{	1419	,	1438	,	205	},
{	1438	,	1440	,	206	},
{	1448	,	1438	,	205	},
{	1459	,	1437	,	205	},
{	1472	,	1438	,	206	},
{	1483	,	1438	,	205	},
{	1493	,	1437	,	204	},
{	1506	,	1437	,	205	},
{	1515	,	1434	,	204	},
{	1529	,	1436	,	204	},
{	1540	,	1436	,	203	},
{	1550	,	1437	,	203	},
{	1562	,	1437	,	202	},
{	1568	,	1433	,	200	},
{	1581	,	1435	,	200	},
{	1594	,	1437	,	200	},
{	1604	,	1434	,	199	},
{	1617	,	1434	,	199	},
{	1622	,	1429	,	197	},
{	1635	,	1431	,	197	},
{	1646	,	1430	,	197	},
{	1659	,	1430	,	196	},
{	1671	,	1430	,	197	},
{	1682	,	1428	,	197	},
{	1694	,	1427	,	198	},
{	1705	,	1429	,	198	},
{	1713	,	1428	,	197	},
{	1725	,	1430	,	198	},
{	1732	,	1425	,	197	},
{	1742	,	1426	,	198	},
{	1751	,	1425	,	198	},
{	1764	,	1426	,	198	},
{	1772	,	1424	,	198	},
{	1780	,	1424	,	197	},
{	1785	,	1421	,	195	},
{	1791	,	1420	,	196	},
{	1796	,	1417	,	194	},
{	1803	,	1418	,	194	},
{	1812	,	1419	,	194	},
{	1816	,	1417	,	192	},
{	1820	,	1416	,	191	},
{	1824	,	1416	,	188	},
{	1835	,	1418	,	186	},
{	1839	,	1418	,	185	},
{	1843	,	1416	,	183	},
{	1852	,	1421	,	182	},
{	1856	,	1422	,	181	},
{	1865	,	1426	,	180	},
{	1864	,	1424	,	179	},
{	1869	,	1427	,	178	},
{	1872	,	1428	,	176	},
{	1873	,	1428	,	175	},
{	1877	,	1431	,	173	},
{	1883	,	1435	,	173	},
{	1886	,	1436	,	172	},
{	1886	,	1437	,	170	},
{	1890	,	1442	,	170	},
{	1893	,	1447	,	168	},
{	1892	,	1449	,	167	},
{	1888	,	1449	,	166	},
{	1891	,	1456	,	165	},
{	1891	,	1460	,	163	},
{	1887	,	1461	,	162	},
{	1887	,	1464	,	161	},
{	1888	,	1470	,	160	},
{	1886	,	1473	,	158	},
{	1887	,	1480	,	156	},
{	1884	,	1485	,	154	},
{	1886	,	1492	,	153	},
{	1886	,	1499	,	152	},
{	1879	,	1501	,	151	},
{	1875	,	1505	,	149	},
{	1875	,	1513	,	149	},
{	1871	,	1517	,	147	},
{	1868	,	1523	,	146	},
{	1868	,	1531	,	144	},
{	1864	,	1535	,	143	},
{	1867	,	1545	,	142	},
{	1862	,	1547	,	141	},
{	1864	,	1555	,	140	},
{	1862	,	1562	,	139	},
{	1862	,	1569	,	137	},
{	1862	,	1574	,	136	},
{	1861	,	1581	,	135	},
{	1865	,	1589	,	135	},
{	1863	,	1594	,	134	},
{	1857	,	1595	,	132	},
{	1858	,	1600	,	131	},
{	1862	,	1611	,	130	},
{	1858	,	1615	,	128	},
{	1856	,	1618	,	125	},
{	1860	,	1626	,	124	},
{	1856	,	1629	,	122	},
{	1860	,	1639	,	120	},
{	1853	,	1638	,	118	},
{	1856	,	1648	,	117	},
{	1851	,	1649	,	115	},
{	1854	,	1656	,	113	},
{	1846	,	1654	,	110	},
{	1848	,	1663	,	107	},
{	1846	,	1667	,	105	},
{	1838	,	1666	,	103	},
{	1840	,	1673	,	101	},
{	1840	,	1678	,	99	},
{	1838	,	1683	,	97	},
{	1833	,	1684	,	94	},
{	1830	,	1686	,	91	},
{	1835	,	1697	,	89	},
{	1828	,	1696	,	87	},
{	1832	,	1705	,	85	},
{	1831	,	1708	,	83	},
{	1832	,	1713	,	82	},
{	1832	,	1716	,	81	},
{	1838	,	1725	,	79	},
{	1832	,	1724	,	76	},
{	1838	,	1733	,	75	},
{	1833	,	1731	,	74	},
{	1835	,	1736	,	73	},
{	1841	,	1744	,	72	},
{	1841	,	1746	,	71	},
{	1845	,	1752	,	69	},
{	1848	,	1757	,	68	},
{	1848	,	1759	,	66	},
{	1850	,	1762	,	65	},
{	1851	,	1764	,	64	},
{	1855	,	1770	,	63	},
{	1856	,	1772	,	61	},
{	1858	,	1775	,	60	},
{	1859	,	1779	,	58	},
{	1856	,	1777	,	56	},
{	1857	,	1780	,	54	},
{	1861	,	1787	,	52	},
{	1863	,	1789	,	51	},
{	1868	,	1795	,	49	},
{	1866	,	1796	,	48	},
{	1862	,	1796	,	46	},
{	1864	,	1801	,	44	},
{	1862	,	1802	,	42	},
{	1861	,	1805	,	40	},
{	1867	,	1813	,	39	},
{	1871	,	1819	,	38	},
{	1868	,	1819	,	36	},
{	1874	,	1826	,	35	},
{	1870	,	1825	,	33	},
{	1869	,	1826	,	32	},
{	1872	,	1831	,	30	},
{	1879	,	1841	,	29	},
{	1880	,	1846	,	27	},
{	1878	,	1847	,	26	},
{	1873	,	1846	,	25	},
{	1872	,	1849	,	23	},
{	1875	,	1855	,	21	},
{	1875	,	1858	,	20	},
{	1875	,	1862	,	18	},
{	1877	,	1868	,	16	},
{	1877	,	1871	,	15	},
{	1878	,	1875	,	14	},
{	1877	,	1878	,	12	},
{	1878	,	1883	,	11	},
{	1874	,	1882	,	10	},
{	1878	,	1891	,	8	},
{	1883	,	1899	,	7	},
{	1880	,	1899	,	5	},
{	1882	,	1905	,	3	},
{	1878	,	1904	,	2	},
{	1878	,	1907	,	1	},
{	1886	,	1919	,	-1	},
{	1889	,	1925	,	-2	},
{	1884	,	1924	,	-4	},
{	1889	,	1934	,	-5	},
{	1890	,	1938	,	-7	},
{	1891	,	1942	,	-9	},
{	1896	,	1950	,	-11	},
{	1893	,	1951	,	-13	},
{	1897	,	1959	,	-15	},
{	1898	,	1962	,	-17	},
{	1896	,	1963	,	-19	},
{	1897	,	1967	,	-21	},
{	1896	,	1968	,	-24	},
{	1902	,	1978	,	-26	},
{	1897	,	1976	,	-27	},
{	1900	,	1980	,	-29	},
{	1903	,	1987	,	-31	},
{	1899	,	1985	,	-32	},
{	1901	,	1989	,	-34	},
{	1909	,	1999	,	-36	},
{	1909	,	2001	,	-39	},
{	1911	,	2005	,	-41	},
{	1912	,	2008	,	-43	},
{	1911	,	2008	,	-45	},
{	1914	,	2013	,	-47	},
{	1911	,	2012	,	-49	},
{	1913	,	2015	,	-50	},
{	1921	,	2025	,	-52	},
{	1921	,	2026	,	-54	},
{	1924	,	2031	,	-56	},
{	1923	,	2031	,	-57	},
{	1925	,	2034	,	-59	},
{	1927	,	2038	,	-61	},
{	1930	,	2043	,	-63	},
{	1930	,	2045	,	-65	},
{	1929	,	2046	,	-66	},
{	1928	,	2049	,	-69	},
{	1929	,	2053	,	-71	},
{	1927	,	2054	,	-72	},
{	1930	,	2059	,	-74	},
{	1933	,	2065	,	-75	},
{	1932	,	2067	,	-76	},
{	1937	,	2075	,	-77	},
{	1939	,	2080	,	-80	},
{	1940	,	2083	,	-82	},
{	1942	,	2088	,	-83	},
{	1937	,	2086	,	-84	},
{	1937	,	2088	,	-85	},
{	1939	,	2094	,	-87	},
{	1939	,	2098	,	-88	},
{	1938	,	2098	,	-89	},
{	1940	,	2103	,	-90	},
{	1942	,	2107	,	-91	},
{	1942	,	2106	,	-91	},
{	1943	,	2108	,	-91	},
{	1944	,	2109	,	-91	},
{	1940	,	2107	,	-91	},
{	1942	,	2110	,	-92	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -12213)

int16_t accel_residual_offset[] = { -22 , -34 , -63 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{4,-3,-1},
{4,-3,-1},
{4,-2,-2},
{3,-2,-3},
{3,-3,-4},
{3,-3,0},
{5,-3,4},
{6,-3,2},
{6,-3,2},
{5,-4,2},
{5,-4,1},
{6,-4,1},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-4,0},
{6,-5,0},
{6,-4,0},
{6,-4,0},
{6,-5,0},
{6,-5,0},
{7,-5,0},
{6,-5,0},
{6,-6,-1},
{6,-6,-1},
{6,-6,-1},
{6,-6,-1},
{6,-5,-1},
{7,-5,-1},
{6,-6,-1},
{6,-6,-1},
{6,-6,-2},
{6,-6,-2},
{6,-5,-2},
{6,-5,-2},
{6,-6,-2},
{6,-6,-2},
{6,-6,-2},
{6,-6,-2},
{6,-6,-2},
{6,-6,-2},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-3},
{6,-6,-4},
{5,-6,-4},
{5,-6,-4},
{6,-6,-4},
{6,-6,-4},
{6,-6,-4},
{6,-6,-4},
{6,-6,-4},
{6,-6,-4},
{5,-6,-4},
{5,-6,-4},
{5,-6,-4},
{5,-6,-3},
{6,-6,-3},
{5,-6,-3},
{5,-6,-3},
{5,-5,-3},
{5,-5,-3},
{5,-5,-3},
{5,-5,-3},
{5,-5,-3},
{5,-4,-4},
{5,-4,-3},
{5,-4,-3},
{5,-4,-3},
{4,-4,-4},
{4,-4,-4},
{4,-4,-4},
{4,-4,-4},
{4,-3,-3},
{4,-3,-3},
{4,-3,-3},
{4,-3,-3},
{4,-2,-3},
{4,-2,-3},
{4,-1,-3},
{4,-1,-3},
{4,0,-3},
{3,0,-3},
{3,0,-3},
{3,0,-3},
{3,0,-3},
{3,0,-3},
{3,0,-3},
{3,1,-3},
{3,1,-3},
{2,2,-3},
{2,2,-3},
{2,2,-3},
{2,2,-3},
{2,2,-3},
{2,3,-3},
{1,3,-3},
{1,3,-3},
{1,3,-4},
{1,3,-4},
{0,3,-4},
{0,3,-4},
{0,3,-5},
{0,3,-5},
{0,4,-5},
{0,4,-6},
{0,3,-6},
{0,3,-6},
{-1,3,-7},
{-1,3,-7},
{-1,4,-7},
{-1,4,-7},
{-1,4,-7},
{-1,4,-8},
{-2,4,-8},
{-2,4,-8},
{-2,4,-8},
{-2,5,-8},
{-2,5,-8},
{-3,5,-8},
{-3,5,-8},
{-3,5,-8},
{-3,5,-7},
{-4,5,-7},
{-4,6,-7},
{-4,6,-7},
{-4,6,-7},
{-4,6,-7},
{-5,6,-6},
{-5,6,-6},
{-5,6,-6},
{-5,6,-6},
{-5,6,-6},
{-6,7,-6},
{-6,7,-6},
{-6,7,-6},
{-6,7,-5},
{-6,7,-5},
{-7,7,-5},
{-7,7,-5},
{-7,7,-5},
{-7,7,-5},
{-8,7,-5},
{-8,8,-5},
{-8,8,-5},
{-8,8,-4},
{-8,8,-4},
{-9,8,-4},
{-9,8,-4},
{-9,8,-4},
{-9,8,-3},
{-9,8,-3},
{-10,8,-3},
{-10,8,-2},
{-10,8,-2},
{-10,8,-2},
{-11,8,-2},
{-11,9,-1},
{-11,9,-1},
{-11,9,-1},
{-11,9,-1},
{-11,9,0},
{-12,9,0},
{-12,9,0},
{-12,9,0},
{-12,9,0},
{-13,9,0},
{-13,9,0},
{-13,9,0},
{-13,9,0},
{-13,9,1},
{-13,9,1},
{-14,9,1},
{-14,9,2},
{-14,9,2},
{-14,9,2},
{-14,9,3},
{-14,9,3},
{-15,9,3},
{-15,9,3},
{-15,10,3},
{-15,10,3},
{-15,10,3},
{-16,10,3},
{-16,10,4},
{-16,10,4},
{-16,10,4},
{-16,10,4},
{-16,10,4},
{-17,10,4},
{-17,10,4},
{-17,10,4},
{-17,10,4},
{-17,10,4},
{-18,10,5},
{-18,10,5},
{-18,10,5},
{-18,10,5},
{-18,10,5},
{-18,10,5},
{-18,10,6},
{-19,10,6},
{-19,10,6},
{-19,10,6},
{-19,10,7},
{-19,10,7},
{-19,10,8},
{-20,10,8},
{-20,10,9},
{-20,10,9},
{-20,10,9},
{-20,11,10},
{-21,11,11},
{-21,11,12},
{-21,11,12},
{-21,11,13},
{-21,11,13},
{-22,11,14},
{-22,11,14},
{-22,11,15},
{-22,11,16},
{-22,12,17},
{-23,12,17},
{-23,12,18},
{-23,12,19},
{-23,12,20},
{-24,13,22},
{-24,13,23},
};



#endif	/* TABLE_LUGE7_SN182_H */

