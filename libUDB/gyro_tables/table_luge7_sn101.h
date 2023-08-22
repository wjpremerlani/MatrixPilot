

#ifndef TABLE_LUGE7_SN101_H
#define	TABLE_LUGE7_SN101_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14089 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1062	,	-2136	,	923	},
{	-1061	,	-2131	,	914	},
{	-1068	,	-2139	,	914	},
{	-1069	,	-2137	,	908	},
{	-1072	,	-2140	,	905	},
{	-1077	,	-2147	,	901	},
{	-1078	,	-2147	,	896	},
{	-1080	,	-2147	,	891	},
{	-1084	,	-2147	,	887	},
{	-1092	,	-2158	,	883	},
{	-1097	,	-2158	,	873	},
{	-1102	,	-2159	,	866	},
{	-1110	,	-2164	,	857	},
{	-1113	,	-2161	,	845	},
{	-1117	,	-2163	,	838	},
{	-1123	,	-2166	,	830	},
{	-1127	,	-2164	,	821	},
{	-1132	,	-2168	,	815	},
{	-1141	,	-2176	,	811	},
{	-1145	,	-2175	,	801	},
{	-1150	,	-2178	,	794	},
{	-1152	,	-2176	,	785	},
{	-1155	,	-2172	,	776	},
{	-1161	,	-2176	,	769	},
{	-1166	,	-2179	,	763	},
{	-1172	,	-2184	,	756	},
{	-1176	,	-2184	,	748	},
{	-1182	,	-2188	,	742	},
{	-1186	,	-2190	,	734	},
{	-1186	,	-2182	,	724	},
{	-1190	,	-2187	,	719	},
{	-1195	,	-2191	,	711	},
{	-1198	,	-2192	,	702	},
{	-1203	,	-2198	,	696	},
{	-1204	,	-2192	,	686	},
{	-1207	,	-2192	,	677	},
{	-1211	,	-2195	,	670	},
{	-1215	,	-2198	,	662	},
{	-1220	,	-2201	,	656	},
{	-1225	,	-2205	,	649	},
{	-1228	,	-2206	,	641	},
{	-1229	,	-2205	,	631	},
{	-1233	,	-2209	,	626	},
{	-1237	,	-2212	,	621	},
{	-1240	,	-2215	,	612	},
{	-1240	,	-2213	,	604	},
{	-1247	,	-2223	,	597	},
{	-1252	,	-2228	,	590	},
{	-1254	,	-2229	,	581	},
{	-1258	,	-2232	,	576	},
{	-1258	,	-2228	,	567	},
{	-1266	,	-2240	,	562	},
{	-1266	,	-2241	,	555	},
{	-1267	,	-2241	,	548	},
{	-1273	,	-2249	,	542	},
{	-1274	,	-2251	,	534	},
{	-1279	,	-2256	,	528	},
{	-1282	,	-2259	,	522	},
{	-1288	,	-2269	,	516	},
{	-1290	,	-2270	,	506	},
{	-1293	,	-2274	,	497	},
{	-1297	,	-2280	,	492	},
{	-1301	,	-2285	,	487	},
{	-1303	,	-2287	,	480	},
{	-1307	,	-2292	,	473	},
{	-1309	,	-2295	,	467	},
{	-1311	,	-2298	,	459	},
{	-1314	,	-2303	,	452	},
{	-1316	,	-2303	,	443	},
{	-1320	,	-2310	,	434	},
{	-1326	,	-2317	,	428	},
{	-1327	,	-2319	,	419	},
{	-1334	,	-2328	,	413	},
{	-1337	,	-2330	,	405	},
{	-1337	,	-2330	,	396	},
{	-1341	,	-2335	,	389	},
{	-1345	,	-2340	,	381	},
{	-1347	,	-2344	,	374	},
{	-1348	,	-2343	,	366	},
{	-1354	,	-2349	,	357	},
{	-1356	,	-2353	,	350	},
{	-1361	,	-2357	,	341	},
{	-1366	,	-2364	,	334	},
{	-1372	,	-2371	,	328	},
{	-1378	,	-2381	,	322	},
{	-1377	,	-2378	,	315	},
{	-1380	,	-2381	,	308	},
{	-1382	,	-2383	,	300	},
{	-1382	,	-2381	,	294	},
{	-1383	,	-2382	,	287	},
{	-1384	,	-2386	,	280	},
{	-1388	,	-2390	,	273	},
{	-1390	,	-2392	,	266	},
{	-1389	,	-2390	,	258	},
{	-1394	,	-2395	,	251	},
{	-1397	,	-2400	,	243	},
{	-1398	,	-2402	,	237	},
{	-1399	,	-2403	,	229	},
{	-1398	,	-2401	,	222	},
{	-1400	,	-2401	,	214	},
{	-1402	,	-2404	,	207	},
{	-1404	,	-2406	,	200	},
{	-1412	,	-2417	,	193	},
{	-1416	,	-2422	,	187	},
{	-1418	,	-2423	,	180	},
{	-1421	,	-2426	,	173	},
{	-1426	,	-2430	,	166	},
{	-1432	,	-2434	,	158	},
{	-1437	,	-2438	,	152	},
{	-1439	,	-2437	,	146	},
{	-1449	,	-2446	,	140	},
{	-1453	,	-2445	,	133	},
{	-1459	,	-2449	,	127	},
{	-1464	,	-2451	,	120	},
{	-1472	,	-2453	,	117	},
{	-1479	,	-2457	,	111	},
{	-1488	,	-2462	,	106	},
{	-1492	,	-2460	,	99	},
{	-1498	,	-2458	,	92	},
{	-1503	,	-2455	,	84	},
{	-1511	,	-2456	,	78	},
{	-1519	,	-2457	,	71	},
{	-1526	,	-2456	,	64	},
{	-1537	,	-2459	,	57	},
{	-1541	,	-2454	,	51	},
{	-1549	,	-2454	,	44	},
{	-1560	,	-2458	,	36	},
{	-1565	,	-2452	,	30	},
{	-1574	,	-2452	,	22	},
{	-1583	,	-2450	,	15	},
{	-1591	,	-2446	,	8	},
{	-1604	,	-2449	,	-3	},
{	-1614	,	-2446	,	-10	},
{	-1621	,	-2439	,	-17	},
{	-1634	,	-2439	,	-26	},
{	-1645	,	-2438	,	-33	},
{	-1658	,	-2436	,	-40	},
{	-1668	,	-2431	,	-48	},
{	-1680	,	-2427	,	-55	},
{	-1697	,	-2429	,	-63	},
{	-1709	,	-2425	,	-71	},
{	-1722	,	-2419	,	-78	},
{	-1739	,	-2418	,	-85	},
{	-1752	,	-2410	,	-92	},
{	-1769	,	-2407	,	-100	},
{	-1786	,	-2406	,	-107	},
{	-1799	,	-2396	,	-115	},
{	-1818	,	-2395	,	-123	},
{	-1833	,	-2388	,	-131	},
{	-1849	,	-2381	,	-139	},
{	-1862	,	-2374	,	-148	},
{	-1878	,	-2365	,	-155	},
{	-1897	,	-2362	,	-164	},
{	-1909	,	-2350	,	-171	},
{	-1930	,	-2349	,	-179	},
{	-1945	,	-2342	,	-187	},
{	-1956	,	-2330	,	-194	},
{	-1968	,	-2318	,	-203	},
{	-1983	,	-2312	,	-212	},
{	-1998	,	-2303	,	-221	},
{	-2009	,	-2293	,	-230	},
{	-2026	,	-2287	,	-239	},
{	-2034	,	-2272	,	-246	},
{	-2052	,	-2270	,	-254	},
{	-2062	,	-2260	,	-262	},
{	-2072	,	-2250	,	-270	},
{	-2082	,	-2240	,	-276	},
{	-2098	,	-2237	,	-284	},
{	-2113	,	-2233	,	-292	},
{	-2123	,	-2223	,	-300	},
{	-2136	,	-2220	,	-307	},
{	-2144	,	-2207	,	-316	},
{	-2157	,	-2202	,	-324	},
{	-2175	,	-2202	,	-333	},
{	-2188	,	-2197	,	-341	},
{	-2206	,	-2198	,	-351	},
{	-2215	,	-2191	,	-360	},
{	-2229	,	-2189	,	-369	},
{	-2234	,	-2178	,	-374	},
{	-2245	,	-2174	,	-382	},
{	-2255	,	-2170	,	-390	},
{	-2270	,	-2169	,	-398	},
{	-2281	,	-2164	,	-405	},
{	-2295	,	-2163	,	-414	},
{	-2303	,	-2157	,	-422	},
{	-2314	,	-2153	,	-429	},
{	-2321	,	-2147	,	-435	},
{	-2342	,	-2151	,	-445	},
{	-2351	,	-2147	,	-453	},
{	-2366	,	-2146	,	-461	},
{	-2370	,	-2137	,	-468	},
{	-2381	,	-2135	,	-474	},
{	-2393	,	-2132	,	-481	},
{	-2408	,	-2132	,	-489	},
{	-2417	,	-2128	,	-496	},
{	-2435	,	-2130	,	-505	},
{	-2448	,	-2128	,	-513	},
{	-2457	,	-2124	,	-521	},
{	-2469	,	-2120	,	-529	},
{	-2481	,	-2118	,	-536	},
{	-2489	,	-2112	,	-544	},
{	-2506	,	-2113	,	-552	},
{	-2520	,	-2112	,	-561	},
{	-2534	,	-2111	,	-570	},
{	-2542	,	-2105	,	-577	},
{	-2549	,	-2097	,	-583	},
{	-2563	,	-2097	,	-591	},
{	-2574	,	-2093	,	-599	},
{	-2589	,	-2093	,	-608	},
{	-2595	,	-2087	,	-615	},
{	-2605	,	-2082	,	-622	},
{	-2619	,	-2081	,	-630	},
{	-2625	,	-2074	,	-636	},
{	-2637	,	-2072	,	-644	},
{	-2654	,	-2073	,	-654	},
{	-2665	,	-2070	,	-663	},
{	-2679	,	-2068	,	-672	},
{	-2691	,	-2067	,	-680	},
{	-2699	,	-2062	,	-688	},
{	-2711	,	-2059	,	-696	},
{	-2725	,	-2059	,	-705	},
{	-2731	,	-2052	,	-711	},
{	-2752	,	-2057	,	-723	},
{	-2760	,	-2051	,	-731	},
{	-2775	,	-2052	,	-741	},
{	-2789	,	-2050	,	-750	},
{	-2802	,	-2047	,	-757	},
{	-2817	,	-2046	,	-766	},
{	-2828	,	-2042	,	-775	},
{	-2842	,	-2042	,	-783	},
{	-2859	,	-2042	,	-793	},
{	-2866	,	-2036	,	-800	},
{	-2878	,	-2033	,	-807	},
{	-2884	,	-2027	,	-814	},
{	-2898	,	-2026	,	-823	},
{	-2914	,	-2026	,	-832	},
{	-2924	,	-2022	,	-841	},
{	-2932	,	-2017	,	-848	},
{	-2949	,	-2018	,	-858	},
{	-2957	,	-2012	,	-865	},
{	-2967	,	-2010	,	-874	},
{	-2979	,	-2008	,	-883	},
{	-2987	,	-2003	,	-890	},
{	-3000	,	-2003	,	-899	},
{	-3009	,	-1999	,	-907	},
{	-3017	,	-1996	,	-915	},
{	-3030	,	-1996	,	-924	},
{	-3033	,	-1990	,	-930	},
{	-3043	,	-1988	,	-937	},
{	-3054	,	-1987	,	-945	},
{	-3066	,	-1988	,	-954	},
{	-3073	,	-1984	,	-960	},
{	-3081	,	-1981	,	-967	},
{	-3091	,	-1980	,	-973	},
{	-3105	,	-1982	,	-982	},
{	-3120	,	-1985	,	-992	},
{	-3128	,	-1984	,	-998	},
{	-3137	,	-1983	,	-1005	},
{	-3143	,	-1980	,	-1010	},
{	-3147	,	-1978	,	-1015	},
{	-3150	,	-1975	,	-1019	},
{	-3151	,	-1972	,	-1023	},
{	-3168	,	-1979	,	-1032	},
{	-3174	,	-1979	,	-1038	},
{	-3190	,	-1985	,	-1046	},
{	-3197	,	-1987	,	-1053	},
{	-3207	,	-1992	,	-1060	},
{	-3221	,	-2000	,	-1068	},
{	-3228	,	-2003	,	-1074	},
{	-3237	,	-2008	,	-1081	},
{	-3240	,	-2010	,	-1086	},
{	-3245	,	-2013	,	-1091	},
{	-3243	,	-2012	,	-1093	},
{	-3254	,	-2019	,	-1099	},
{	-3254	,	-2020	,	-1100	},
{	-3266	,	-2029	,	-1107	},
{	-3283	,	-2037	,	-1111	},
{	-3291	,	-2036	,	-1110	},
{	-3310	,	-2042	,	-1111	},
{	-3314	,	-2038	,	-1109	},
{	-3328	,	-2039	,	-1111	},
{	-3343	,	-2041	,	-1112	},
{	-3354	,	-2040	,	-1113	},
{	-3368	,	-2040	,	-1114	},
{	-3373	,	-2034	,	-1113	},
{	-3387	,	-2033	,	-1114	},
{	-3397	,	-2029	,	-1114	},
{	-3410	,	-2026	,	-1116	},
{	-3419	,	-2021	,	-1116	},
{	-3433	,	-2017	,	-1118	},
{	-3451	,	-2015	,	-1122	},
{	-3470	,	-2012	,	-1128	},
{	-3482	,	-2005	,	-1130	},
{	-3495	,	-2001	,	-1137	},
{	-3507	,	-2000	,	-1146	},
{	-3518	,	-1998	,	-1154	},
{	-3530	,	-1995	,	-1162	},
{	-3538	,	-1990	,	-1168	},
{	-3539	,	-1983	,	-1173	},
{	-3548	,	-1978	,	-1180	},
{	-3554	,	-1972	,	-1188	},
{	-3571	,	-1971	,	-1198	},
{	-3589	,	-1972	,	-1208	},
{	-3604	,	-1971	,	-1217	},
{	-3613	,	-1967	,	-1224	},
{	-3634	,	-1970	,	-1236	},
{	-3642	,	-1965	,	-1245	},
{	-3652	,	-1962	,	-1253	},
{	-3662	,	-1958	,	-1261	},
{	-3684	,	-1962	,	-1274	},
{	-3690	,	-1957	,	-1280	},
{	-3705	,	-1957	,	-1291	},
{	-3723	,	-1958	,	-1302	},
{	-3730	,	-1953	,	-1309	},
{	-3741	,	-1952	,	-1319	},
{	-3759	,	-1953	,	-1330	},
{	-3775	,	-1954	,	-1341	},
{	-3785	,	-1951	,	-1348	},
{	-3792	,	-1948	,	-1355	},
{	-3797	,	-1944	,	-1361	},
{	-3811	,	-1944	,	-1370	},
{	-3826	,	-1945	,	-1378	},
{	-3828	,	-1938	,	-1382	},
{	-3843	,	-1939	,	-1391	},
{	-3850	,	-1936	,	-1397	},
{	-3859	,	-1935	,	-1403	},
{	-3862	,	-1930	,	-1408	},
{	-3870	,	-1928	,	-1414	},
{	-3879	,	-1926	,	-1420	},
{	-3876	,	-1919	,	-1422	},
{	-3897	,	-1924	,	-1433	},
{	-3902	,	-1921	,	-1437	},
{	-3913	,	-1921	,	-1444	},
{	-3929	,	-1925	,	-1453	},
{	-3937	,	-1924	,	-1459	},
{	-3954	,	-1928	,	-1467	},
{	-3974	,	-1934	,	-1478	},
{	-3976	,	-1931	,	-1482	},
{	-3990	,	-1934	,	-1491	},
{	-4010	,	-1940	,	-1500	},
{	-4023	,	-1943	,	-1507	},
{	-4036	,	-1945	,	-1513	},
{	-4057	,	-1953	,	-1522	},
{	-4065	,	-1953	,	-1526	},
{	-4084	,	-1959	,	-1533	},
{	-4095	,	-1962	,	-1538	},
{	-4116	,	-1971	,	-1547	},
{	-4128	,	-1975	,	-1552	},
{	-4142	,	-1980	,	-1559	},
{	-4146	,	-1981	,	-1561	},
{	-4158	,	-1985	,	-1566	},
{	-4176	,	-1993	,	-1573	},
{	-4177	,	-1994	,	-1575	},
{	-4183	,	-1996	,	-1577	},
{	-4208	,	-2008	,	-1587	},
{	-4221	,	-2014	,	-1593	},
{	-4228	,	-2017	,	-1595	},
{	-4231	,	-2019	,	-1595	},
{	-4248	,	-2029	,	-1602	},
{	-4251	,	-2032	,	-1603	},
{	-4272	,	-2044	,	-1612	},
{	-4276	,	-2048	,	-1613	},
{	-4286	,	-2058	,	-1618	},
{	-4290	,	-2064	,	-1619	},
{	-4288	,	-2069	,	-1618	},
{	-4291	,	-2076	,	-1618	},
{	-4293	,	-2084	,	-1617	},
{	-4293	,	-2086	,	-1617	},
{	-4292	,	-2089	,	-1616	},
{	-4305	,	-2097	,	-1620	},
{	-4306	,	-2100	,	-1619	},
{	-4293	,	-2097	,	-1613	},
{	-4290	,	-2100	,	-1611	},
{	-4288	,	-2104	,	-1609	},
{	-4300	,	-2115	,	-1614	}
};

#endif	/* TABLE_LUGE7_SN101_H */

