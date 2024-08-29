

#ifndef TABLE_LUGE7_SN178_H
#define	TABLE_LUGE7_SN178_H

// used in LUGE7_SN178 partition size 64


#define X_CROSS_COUPLING 60
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14896 )

int16_t residual_offset[] = { -1332 -4*130 , 81 , -141 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	3286	,	-2065	,	-165	},
{	3289	,	-2067	,	-167	},
{	3288	,	-2068	,	-169	},
{	3293	,	-2071	,	-171	},
{	3284	,	-2065	,	-173	},
{	3285	,	-2066	,	-175	},
{	3285	,	-2067	,	-177	},
{	3286	,	-2068	,	-179	},
{	3287	,	-2069	,	-182	},
{	3289	,	-2073	,	-187	},
{	3296	,	-2076	,	-190	},
{	3307	,	-2080	,	-195	},
{	3300	,	-2076	,	-199	},
{	3302	,	-2078	,	-203	},
{	3300	,	-2078	,	-208	},
{	3307	,	-2084	,	-213	},
{	3309	,	-2084	,	-218	},
{	3310	,	-2085	,	-222	},
{	3309	,	-2086	,	-226	},
{	3309	,	-2087	,	-230	},
{	3313	,	-2091	,	-236	},
{	3318	,	-2096	,	-241	},
{	3323	,	-2100	,	-246	},
{	3324	,	-2101	,	-250	},
{	3329	,	-2105	,	-255	},
{	3326	,	-2104	,	-259	},
{	3331	,	-2107	,	-264	},
{	3333	,	-2112	,	-270	},
{	3319	,	-2108	,	-274	},
{	3328	,	-2117	,	-279	},
{	3325	,	-2117	,	-284	},
{	3327	,	-2120	,	-289	},
{	3318	,	-2115	,	-294	},
{	3324	,	-2123	,	-299	},
{	3329	,	-2128	,	-305	},
{	3329	,	-2130	,	-311	},
{	3328	,	-2130	,	-315	},
{	3326	,	-2131	,	-320	},
{	3331	,	-2136	,	-325	},
{	3323	,	-2134	,	-328	},
{	3325	,	-2139	,	-333	},
{	3326	,	-2142	,	-338	},
{	3331	,	-2149	,	-344	},
{	3325	,	-2148	,	-348	},
{	3326	,	-2152	,	-353	},
{	3333	,	-2158	,	-358	},
{	3326	,	-2156	,	-362	},
{	3332	,	-2162	,	-367	},
{	3328	,	-2161	,	-372	},
{	3330	,	-2163	,	-376	},
{	3328	,	-2164	,	-379	},
{	3322	,	-2163	,	-383	},
{	3321	,	-2164	,	-388	},
{	3323	,	-2170	,	-392	},
{	3322	,	-2172	,	-397	},
{	3314	,	-2169	,	-402	},
{	3321	,	-2175	,	-408	},
{	3323	,	-2178	,	-413	},
{	3316	,	-2175	,	-418	},
{	3319	,	-2180	,	-423	},
{	3316	,	-2181	,	-428	},
{	3312	,	-2182	,	-433	},
{	3314	,	-2187	,	-438	},
{	3309	,	-2187	,	-443	},
{	3311	,	-2191	,	-447	},
{	3309	,	-2193	,	-452	},
{	3310	,	-2198	,	-458	},
{	3307	,	-2199	,	-463	},
{	3311	,	-2202	,	-468	},
{	3308	,	-2204	,	-473	},
{	3306	,	-2205	,	-478	},
{	3302	,	-2205	,	-482	},
{	3303	,	-2210	,	-487	},
{	3296	,	-2208	,	-491	},
{	3288	,	-2207	,	-494	},
{	3289	,	-2212	,	-500	},
{	3281	,	-2210	,	-504	},
{	3289	,	-2219	,	-510	},
{	3288	,	-2221	,	-515	},
{	3277	,	-2217	,	-519	},
{	3283	,	-2225	,	-524	},
{	3274	,	-2222	,	-529	},
{	3269	,	-2223	,	-532	},
{	3266	,	-2225	,	-537	},
{	3272	,	-2233	,	-544	},
{	3267	,	-2235	,	-548	},
{	3268	,	-2240	,	-554	},
{	3265	,	-2244	,	-558	},
{	3259	,	-2246	,	-563	},
{	3257	,	-2250	,	-568	},
{	3261	,	-2257	,	-573	},
{	3259	,	-2260	,	-579	},
{	3261	,	-2267	,	-585	},
{	3257	,	-2271	,	-588	},
{	3253	,	-2273	,	-592	},
{	3253	,	-2278	,	-597	},
{	3256	,	-2286	,	-603	},
{	3250	,	-2288	,	-606	},
{	3249	,	-2293	,	-611	},
{	3250	,	-2300	,	-616	},
{	3246	,	-2303	,	-619	},
{	3236	,	-2303	,	-622	},
{	3233	,	-2307	,	-626	},
{	3228	,	-2311	,	-629	},
{	3224	,	-2315	,	-634	},
{	3227	,	-2323	,	-639	},
{	3223	,	-2327	,	-643	},
{	3214	,	-2327	,	-646	},
{	3208	,	-2331	,	-650	},
{	3197	,	-2331	,	-652	},
{	3191	,	-2335	,	-657	},
{	3185	,	-2340	,	-661	},
{	3173	,	-2340	,	-665	},
{	3167	,	-2343	,	-668	},
{	3157	,	-2345	,	-673	},
{	3159	,	-2355	,	-679	},
{	3145	,	-2352	,	-683	},
{	3138	,	-2358	,	-689	},
{	3137	,	-2368	,	-695	},
{	3119	,	-2365	,	-699	},
{	3110	,	-2368	,	-704	},
{	3097	,	-2369	,	-708	},
{	3087	,	-2372	,	-713	},
{	3071	,	-2372	,	-717	},
{	3064	,	-2378	,	-725	},
{	3050	,	-2379	,	-729	},
{	3041	,	-2383	,	-735	},
{	3024	,	-2382	,	-739	},
{	3006	,	-2379	,	-743	},
{	2993	,	-2380	,	-748	},
{	2980	,	-2382	,	-754	},
{	2965	,	-2382	,	-759	},
{	2941	,	-2377	,	-763	},
{	2930	,	-2382	,	-768	},
{	2917	,	-2385	,	-774	},
{	2892	,	-2378	,	-777	},
{	2877	,	-2379	,	-783	},
{	2864	,	-2382	,	-789	},
{	2845	,	-2381	,	-792	},
{	2823	,	-2377	,	-796	},
{	2809	,	-2379	,	-803	},
{	2787	,	-2375	,	-806	},
{	2773	,	-2377	,	-812	},
{	2746	,	-2369	,	-815	},
{	2733	,	-2374	,	-823	},
{	2710	,	-2369	,	-827	},
{	2691	,	-2368	,	-833	},
{	2667	,	-2363	,	-838	},
{	2645	,	-2361	,	-844	},
{	2621	,	-2356	,	-849	},
{	2599	,	-2353	,	-855	},
{	2568	,	-2341	,	-858	},
{	2544	,	-2335	,	-863	},
{	2527	,	-2335	,	-871	},
{	2498	,	-2325	,	-875	},
{	2478	,	-2322	,	-883	},
{	2459	,	-2322	,	-891	},
{	2431	,	-2314	,	-896	},
{	2404	,	-2305	,	-901	},
{	2377	,	-2296	,	-906	},
{	2359	,	-2297	,	-916	},
{	2333	,	-2287	,	-920	},
{	2312	,	-2282	,	-926	},
{	2291	,	-2279	,	-934	},
{	2266	,	-2272	,	-940	},
{	2243	,	-2264	,	-946	},
{	2224	,	-2263	,	-954	},
{	2204	,	-2259	,	-962	},
{	2184	,	-2256	,	-970	},
{	2166	,	-2254	,	-977	},
{	2143	,	-2249	,	-983	},
{	2122	,	-2245	,	-990	},
{	2105	,	-2244	,	-998	},
{	2078	,	-2234	,	-1001	},
{	2062	,	-2233	,	-1008	},
{	2045	,	-2232	,	-1015	},
{	2023	,	-2226	,	-1020	},
{	2002	,	-2221	,	-1025	},
{	1980	,	-2216	,	-1029	},
{	1968	,	-2221	,	-1040	},
{	1942	,	-2211	,	-1042	},
{	1924	,	-2209	,	-1047	},
{	1906	,	-2208	,	-1053	},
{	1883	,	-2199	,	-1057	},
{	1864	,	-2196	,	-1062	},
{	1844	,	-2191	,	-1064	},
{	1825	,	-2189	,	-1070	},
{	1803	,	-2181	,	-1074	},
{	1785	,	-2178	,	-1079	},
{	1760	,	-2168	,	-1081	},
{	1744	,	-2167	,	-1088	},
{	1723	,	-2163	,	-1093	},
{	1707	,	-2163	,	-1101	},
{	1690	,	-2159	,	-1107	},
{	1670	,	-2154	,	-1112	},
{	1652	,	-2151	,	-1119	},
{	1627	,	-2140	,	-1121	},
{	1613	,	-2141	,	-1130	},
{	1591	,	-2135	,	-1134	},
{	1571	,	-2129	,	-1140	},
{	1553	,	-2127	,	-1147	},
{	1536	,	-2127	,	-1155	},
{	1519	,	-2124	,	-1163	},
{	1497	,	-2115	,	-1167	},
{	1480	,	-2114	,	-1174	},
{	1462	,	-2110	,	-1180	},
{	1445	,	-2109	,	-1187	},
{	1424	,	-2102	,	-1191	},
{	1407	,	-2099	,	-1198	},
{	1384	,	-2088	,	-1199	},
{	1370	,	-2090	,	-1207	},
{	1353	,	-2088	,	-1214	},
{	1334	,	-2083	,	-1220	},
{	1318	,	-2082	,	-1227	},
{	1297	,	-2075	,	-1231	},
{	1282	,	-2075	,	-1239	},
{	1268	,	-2076	,	-1248	},
{	1252	,	-2072	,	-1254	},
{	1233	,	-2065	,	-1257	},
{	1216	,	-2062	,	-1264	},
{	1199	,	-2057	,	-1268	},
{	1182	,	-2053	,	-1274	},
{	1169	,	-2054	,	-1283	},
{	1151	,	-2047	,	-1288	},
{	1137	,	-2048	,	-1297	},
{	1117	,	-2038	,	-1298	},
{	1106	,	-2042	,	-1309	},
{	1087	,	-2035	,	-1313	},
{	1071	,	-2032	,	-1321	},
{	1056	,	-2029	,	-1327	},
{	1038	,	-2025	,	-1332	},
{	1023	,	-2022	,	-1338	},
{	1005	,	-2017	,	-1344	},
{	988	,	-2011	,	-1347	},
{	970	,	-2006	,	-1352	},
{	953	,	-2003	,	-1359	},
{	936	,	-2002	,	-1366	},
{	921	,	-2002	,	-1373	},
{	901	,	-1993	,	-1375	},
{	883	,	-1989	,	-1382	},
{	866	,	-1988	,	-1389	},
{	848	,	-1981	,	-1392	},
{	832	,	-1979	,	-1399	},
{	814	,	-1975	,	-1406	},
{	796	,	-1969	,	-1410	},
{	777	,	-1965	,	-1415	},
{	762	,	-1967	,	-1424	},
{	743	,	-1962	,	-1429	},
{	726	,	-1960	,	-1436	},
{	711	,	-1961	,	-1445	},
{	693	,	-1956	,	-1449	},
{	678	,	-1956	,	-1458	},
{	660	,	-1953	,	-1464	},
{	642	,	-1946	,	-1467	},
{	626	,	-1948	,	-1476	},
{	610	,	-1946	,	-1482	},
{	592	,	-1940	,	-1485	},
{	577	,	-1942	,	-1494	},
{	562	,	-1943	,	-1501	},
{	546	,	-1941	,	-1506	},
{	529	,	-1940	,	-1512	},
{	515	,	-1945	,	-1523	},
{	497	,	-1940	,	-1526	},
{	480	,	-1933	,	-1529	},
{	464	,	-1931	,	-1535	},
{	448	,	-1932	,	-1543	},
{	430	,	-1928	,	-1548	},
{	414	,	-1927	,	-1555	},
{	396	,	-1923	,	-1558	},
{	379	,	-1920	,	-1562	},
{	362	,	-1922	,	-1570	},
{	344	,	-1914	,	-1571	},
{	328	,	-1918	,	-1582	},
{	312	,	-1919	,	-1590	},
{	294	,	-1914	,	-1593	},
{	276	,	-1908	,	-1597	},
{	259	,	-1912	,	-1608	},
{	240	,	-1908	,	-1613	},
{	221	,	-1906	,	-1620	},
{	203	,	-1908	,	-1628	},
{	185	,	-1909	,	-1636	},
{	168	,	-1910	,	-1643	},
{	149	,	-1908	,	-1647	},
{	131	,	-1902	,	-1649	},
{	112	,	-1904	,	-1658	},
{	94	,	-1905	,	-1664	},
{	75	,	-1905	,	-1672	},
{	56	,	-1904	,	-1677	},
{	38	,	-1905	,	-1684	},
{	19	,	-1898	,	-1684	},
{	0	,	-1897	,	-1689	},
{	-20	,	-1899	,	-1697	},
{	-38	,	-1901	,	-1705	},
{	-56	,	-1897	,	-1706	},
{	-76	,	-1899	,	-1712	},
{	-95	,	-1898	,	-1717	},
{	-113	,	-1895	,	-1720	},
{	-131	,	-1898	,	-1728	},
{	-149	,	-1895	,	-1731	},
{	-167	,	-1895	,	-1736	},
{	-186	,	-1900	,	-1746	},
{	-203	,	-1896	,	-1747	},
{	-221	,	-1895	,	-1751	},
{	-239	,	-1893	,	-1755	},
{	-258	,	-1897	,	-1764	},
{	-276	,	-1902	,	-1774	},
{	-285	,	-1907	,	-1782	},
{	-294	,	-1905	,	-1783	},
{	-303	,	-1905	,	-1785	},
{	-312	,	-1905	,	-1788	},
{	-321	,	-1910	,	-1795	},
{	-329	,	-1907	,	-1795	},
{	-337	,	-1905	,	-1796	},
{	-347	,	-1909	,	-1803	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11978)

int16_t accel_residual_offset[] = { -3 , 29 , -54 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-1,0,2},
{-1,0,2},
{-1,0,2},
{-1,-1,2},
{-2,-2,1},
{-2,-2,0},
{-1,-3,5},
{0,-3,10},
{0,-4,9},
{0,-4,8},
{0,-5,8},
{0,-5,8},
{0,-6,8},
{0,-6,8},
{1,-7,9},
{1,-7,9},
{1,-7,9},
{2,-8,9},
{3,-9,10},
{3,-10,10},
{2,-10,11},
{2,-11,11},
{2,-11,11},
{2,-12,11},
{2,-12,12},
{2,-13,12},
{3,-14,12},
{3,-14,12},
{3,-14,13},
{3,-15,13},
{3,-16,13},
{3,-16,14},
{3,-17,14},
{4,-17,14},
{4,-18,15},
{4,-18,15},
{4,-19,15},
{4,-19,15},
{4,-20,15},
{4,-20,16},
{4,-21,16},
{4,-21,16},
{4,-22,16},
{4,-22,17},
{5,-23,17},
{5,-23,18},
{5,-24,18},
{5,-25,18},
{5,-25,19},
{5,-25,19},
{5,-25,19},
{5,-26,19},
{5,-27,19},
{5,-27,19},
{5,-28,20},
{5,-28,20},
{5,-28,20},
{6,-29,20},
{6,-29,21},
{5,-30,21},
{5,-30,21},
{6,-30,22},
{6,-31,22},
{6,-31,23},
{6,-32,23},
{6,-32,23},
{6,-33,23},
{6,-33,24},
{6,-34,25},
{6,-34,25},
{6,-34,25},
{6,-35,25},
{7,-35,26},
{7,-36,26},
{7,-36,26},
{7,-36,26},
{7,-37,26},
{7,-37,27},
{7,-38,27},
{7,-38,27},
{7,-38,27},
{7,-39,27},
{7,-39,28},
{7,-39,28},
{7,-40,28},
{7,-40,29},
{7,-40,29},
{7,-41,29},
{7,-41,29},
{7,-41,29},
{7,-42,30},
{7,-42,30},
{8,-42,30},
{8,-42,30},
{8,-42,30},
{8,-42,30},
{8,-43,30},
{8,-43,30},
{8,-43,30},
{8,-43,30},
{8,-44,30},
{8,-43,30},
{8,-43,29},
{8,-44,29},
{8,-44,29},
{8,-44,29},
{8,-45,28},
{8,-45,28},
{7,-45,27},
{7,-46,27},
{8,-46,27},
{8,-47,26},
{8,-48,26},
{8,-48,25},
{7,-48,25},
{7,-49,24},
{7,-49,24},
{7,-50,24},
{7,-51,23},
{7,-51,23},
{7,-52,23},
{7,-52,22},
{7,-52,22},
{7,-53,22},
{7,-54,22},
{7,-54,22},
{7,-54,22},
{7,-55,22},
{7,-55,22},
{7,-55,22},
{7,-56,22},
{7,-56,23},
{7,-56,23},
{7,-57,23},
{7,-57,23},
{7,-58,24},
{6,-58,24},
{6,-59,24},
{6,-59,24},
{6,-60,24},
{6,-60,24},
{6,-60,24},
{6,-61,24},
{6,-61,25},
{6,-61,25},
{6,-62,25},
{6,-62,25},
{6,-63,25},
{6,-63,26},
{6,-64,26},
{6,-64,26},
{6,-64,26},
{6,-65,26},
{6,-65,27},
{5,-66,27},
{5,-66,27},
{5,-67,27},
{5,-67,27},
{5,-68,28},
{5,-68,28},
{5,-69,28},
{5,-69,28},
{5,-70,29},
{5,-70,29},
{5,-70,29},
{5,-71,30},
{5,-71,30},
{5,-72,30},
{5,-72,30},
{5,-73,31},
{5,-73,31},
{5,-73,31},
{5,-74,32},
{5,-75,32},
{5,-75,32},
{5,-75,33},
{5,-76,33},
{5,-76,33},
{5,-77,33},
{4,-77,34},
{4,-78,34},
{4,-78,34},
{4,-79,34},
{4,-79,35},
{4,-80,35},
{4,-80,35},
{4,-80,35},
{4,-81,35},
{4,-81,35},
{4,-82,35},
{4,-82,35},
{4,-83,35},
{4,-83,35},
{4,-84,35},
{3,-84,35},
{3,-85,35},
{3,-85,35},
{3,-85,36},
{3,-86,36},
{3,-86,36},
{3,-87,36},
{3,-87,36},
{3,-88,36},
{3,-88,36},
{3,-89,36},
{3,-89,37},
{3,-89,37},
{3,-90,37},
{3,-91,37},
{3,-91,37},
{3,-92,37},
{2,-92,37},
{2,-92,37},
{2,-93,38},
{2,-93,38},
{2,-93,38},
{2,-94,38},
{2,-94,38},
{2,-95,39},
{2,-95,39},
{2,-95,39},
{2,-96,40},
{2,-96,40},
{2,-97,41},
{2,-97,42},
{2,-97,42},
{2,-98,43},
{1,-98,43},
{1,-99,44},
{1,-99,44},
{1,-99,45},
{1,-99,45},
{0,-99,46},
{0,-99,47},
{0,-100,47},
{0,-100,48},
{0,-100,49},
};



#endif	/* TABLE_LUGE7_SN178_H */

