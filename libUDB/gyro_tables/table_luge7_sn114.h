

#ifndef TABLE_LUGE7_SN114_H
#define	TABLE_LUGE7_SN114_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14598 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1859	,	-856	,	37	},
{	-1864	,	-856	,	39	},
{	-1860	,	-851	,	42	},
{	-1855	,	-847	,	43	},
{	-1846	,	-841	,	46	},
{	-1842	,	-837	,	49	},
{	-1834	,	-831	,	52	},
{	-1830	,	-827	,	55	},
{	-1825	,	-822	,	58	},
{	-1827	,	-820	,	64	},
{	-1809	,	-810	,	69	},
{	-1796	,	-802	,	73	},
{	-1787	,	-795	,	78	},
{	-1771	,	-782	,	82	},
{	-1757	,	-769	,	85	},
{	-1747	,	-759	,	89	},
{	-1741	,	-751	,	92	},
{	-1728	,	-742	,	96	},
{	-1711	,	-731	,	102	},
{	-1699	,	-722	,	106	},
{	-1689	,	-714	,	112	},
{	-1680	,	-706	,	116	},
{	-1666	,	-695	,	121	},
{	-1653	,	-687	,	125	},
{	-1639	,	-678	,	129	},
{	-1626	,	-668	,	133	},
{	-1613	,	-659	,	138	},
{	-1600	,	-649	,	142	},
{	-1589	,	-638	,	148	},
{	-1572	,	-626	,	153	},
{	-1557	,	-616	,	158	},
{	-1547	,	-607	,	165	},
{	-1534	,	-598	,	169	},
{	-1519	,	-587	,	175	},
{	-1508	,	-577	,	179	},
{	-1495	,	-568	,	184	},
{	-1482	,	-558	,	188	},
{	-1470	,	-548	,	192	},
{	-1454	,	-537	,	196	},
{	-1445	,	-529	,	200	},
{	-1434	,	-518	,	205	},
{	-1422	,	-508	,	210	},
{	-1410	,	-497	,	214	},
{	-1399	,	-487	,	217	},
{	-1392	,	-478	,	221	},
{	-1378	,	-468	,	225	},
{	-1365	,	-458	,	228	},
{	-1359	,	-449	,	232	},
{	-1348	,	-439	,	235	},
{	-1338	,	-429	,	239	},
{	-1322	,	-417	,	242	},
{	-1314	,	-408	,	247	},
{	-1303	,	-398	,	251	},
{	-1293	,	-388	,	254	},
{	-1280	,	-376	,	257	},
{	-1270	,	-366	,	259	},
{	-1258	,	-355	,	262	},
{	-1248	,	-345	,	267	},
{	-1235	,	-334	,	270	},
{	-1224	,	-325	,	273	},
{	-1212	,	-314	,	277	},
{	-1199	,	-303	,	281	},
{	-1188	,	-292	,	285	},
{	-1180	,	-283	,	290	},
{	-1166	,	-272	,	293	},
{	-1156	,	-263	,	297	},
{	-1147	,	-252	,	302	},
{	-1138	,	-243	,	304	},
{	-1127	,	-232	,	308	},
{	-1117	,	-221	,	311	},
{	-1106	,	-210	,	316	},
{	-1096	,	-200	,	321	},
{	-1087	,	-190	,	326	},
{	-1076	,	-180	,	329	},
{	-1067	,	-169	,	332	},
{	-1058	,	-160	,	336	},
{	-1048	,	-149	,	339	},
{	-1038	,	-140	,	343	},
{	-1029	,	-130	,	347	},
{	-1019	,	-119	,	350	},
{	-1009	,	-109	,	354	},
{	-1002	,	-99	,	358	},
{	-994	,	-89	,	362	},
{	-983	,	-80	,	365	},
{	-977	,	-70	,	369	},
{	-967	,	-60	,	372	},
{	-958	,	-51	,	376	},
{	-952	,	-42	,	379	},
{	-943	,	-33	,	381	},
{	-936	,	-25	,	383	},
{	-931	,	-14	,	386	},
{	-922	,	-6	,	388	},
{	-918	,	3	,	391	},
{	-914	,	10	,	395	},
{	-909	,	17	,	397	},
{	-902	,	24	,	397	},
{	-899	,	30	,	399	},
{	-892	,	38	,	400	},
{	-890	,	45	,	402	},
{	-885	,	51	,	403	},
{	-881	,	59	,	406	},
{	-877	,	66	,	407	},
{	-875	,	74	,	411	},
{	-870	,	81	,	412	},
{	-867	,	87	,	414	},
{	-862	,	94	,	416	},
{	-861	,	102	,	420	},
{	-855	,	108	,	421	},
{	-852	,	116	,	423	},
{	-847	,	125	,	426	},
{	-843	,	134	,	429	},
{	-837	,	143	,	431	},
{	-835	,	152	,	435	},
{	-830	,	161	,	437	},
{	-830	,	170	,	440	},
{	-825	,	178	,	441	},
{	-821	,	187	,	445	},
{	-819	,	198	,	447	},
{	-819	,	208	,	452	},
{	-815	,	218	,	454	},
{	-814	,	228	,	457	},
{	-814	,	239	,	460	},
{	-815	,	250	,	463	},
{	-813	,	260	,	464	},
{	-813	,	271	,	466	},
{	-814	,	283	,	469	},
{	-817	,	294	,	472	},
{	-819	,	304	,	473	},
{	-822	,	316	,	476	},
{	-825	,	328	,	478	},
{	-830	,	339	,	480	},
{	-832	,	352	,	482	},
{	-838	,	365	,	484	},
{	-842	,	378	,	485	},
{	-847	,	390	,	485	},
{	-853	,	402	,	486	},
{	-859	,	414	,	487	},
{	-867	,	427	,	488	},
{	-871	,	439	,	489	},
{	-878	,	452	,	489	},
{	-887	,	465	,	492	},
{	-898	,	480	,	494	},
{	-908	,	493	,	493	},
{	-917	,	506	,	494	},
{	-928	,	521	,	496	},
{	-938	,	536	,	497	},
{	-947	,	549	,	497	},
{	-957	,	562	,	499	},
{	-966	,	576	,	499	},
{	-978	,	591	,	501	},
{	-990	,	606	,	502	},
{	-1002	,	622	,	504	},
{	-1011	,	636	,	504	},
{	-1023	,	652	,	506	},
{	-1031	,	665	,	505	},
{	-1042	,	681	,	507	},
{	-1052	,	696	,	508	},
{	-1062	,	713	,	509	},
{	-1070	,	727	,	510	},
{	-1077	,	740	,	511	},
{	-1084	,	754	,	512	},
{	-1091	,	768	,	512	},
{	-1099	,	783	,	513	},
{	-1106	,	797	,	513	},
{	-1114	,	813	,	516	},
{	-1120	,	827	,	517	},
{	-1129	,	843	,	519	},
{	-1132	,	855	,	520	},
{	-1137	,	869	,	522	},
{	-1143	,	884	,	523	},
{	-1147	,	897	,	525	},
{	-1155	,	915	,	528	},
{	-1161	,	928	,	530	},
{	-1166	,	942	,	531	},
{	-1170	,	954	,	532	},
{	-1177	,	969	,	535	},
{	-1183	,	982	,	537	},
{	-1188	,	996	,	540	},
{	-1194	,	1010	,	543	},
{	-1199	,	1024	,	544	},
{	-1204	,	1038	,	547	},
{	-1209	,	1052	,	549	},
{	-1215	,	1064	,	552	},
{	-1215	,	1073	,	551	},
{	-1223	,	1087	,	554	},
{	-1229	,	1099	,	556	},
{	-1234	,	1111	,	557	},
{	-1237	,	1121	,	558	},
{	-1241	,	1131	,	559	},
{	-1247	,	1145	,	562	},
{	-1250	,	1156	,	562	},
{	-1254	,	1166	,	564	},
{	-1257	,	1178	,	565	},
{	-1260	,	1187	,	564	},
{	-1265	,	1199	,	566	},
{	-1271	,	1210	,	568	},
{	-1272	,	1219	,	569	},
{	-1275	,	1228	,	570	},
{	-1278	,	1238	,	570	},
{	-1282	,	1249	,	573	},
{	-1289	,	1262	,	576	},
{	-1293	,	1273	,	576	},
{	-1295	,	1281	,	577	},
{	-1299	,	1291	,	579	},
{	-1307	,	1306	,	582	},
{	-1310	,	1315	,	583	},
{	-1314	,	1325	,	585	},
{	-1319	,	1335	,	587	},
{	-1324	,	1346	,	589	},
{	-1328	,	1356	,	591	},
{	-1336	,	1372	,	594	},
{	-1338	,	1380	,	594	},
{	-1339	,	1388	,	594	},
{	-1346	,	1401	,	596	},
{	-1351	,	1412	,	598	},
{	-1357	,	1421	,	599	},
{	-1364	,	1433	,	601	},
{	-1370	,	1444	,	602	},
{	-1374	,	1452	,	604	},
{	-1382	,	1465	,	606	},
{	-1384	,	1472	,	607	},
{	-1389	,	1482	,	608	},
{	-1394	,	1492	,	610	},
{	-1399	,	1502	,	611	},
{	-1403	,	1510	,	612	},
{	-1410	,	1520	,	614	},
{	-1414	,	1527	,	614	},
{	-1421	,	1535	,	615	},
{	-1426	,	1544	,	617	},
{	-1432	,	1553	,	617	},
{	-1437	,	1561	,	619	},
{	-1446	,	1573	,	621	},
{	-1449	,	1579	,	621	},
{	-1453	,	1588	,	621	},
{	-1457	,	1596	,	622	},
{	-1463	,	1605	,	623	},
{	-1468	,	1613	,	624	},
{	-1477	,	1626	,	626	},
{	-1479	,	1630	,	625	},
{	-1487	,	1641	,	627	},
{	-1491	,	1648	,	627	},
{	-1500	,	1661	,	630	},
{	-1505	,	1670	,	631	},
{	-1514	,	1682	,	634	},
{	-1520	,	1692	,	636	},
{	-1525	,	1700	,	637	},
{	-1532	,	1709	,	638	},
{	-1538	,	1715	,	639	},
{	-1540	,	1718	,	638	},
{	-1547	,	1729	,	640	},
{	-1553	,	1737	,	641	},
{	-1555	,	1740	,	640	},
{	-1563	,	1750	,	642	},
{	-1567	,	1757	,	643	},
{	-1570	,	1762	,	644	},
{	-1578	,	1772	,	645	},
{	-1580	,	1775	,	644	},
{	-1587	,	1783	,	645	},
{	-1590	,	1787	,	645	},
{	-1596	,	1792	,	646	},
{	-1600	,	1794	,	645	},
{	-1604	,	1798	,	645	},
{	-1611	,	1810	,	647	},
{	-1615	,	1814	,	648	},
{	-1622	,	1823	,	650	},
{	-1631	,	1831	,	652	},
{	-1637	,	1837	,	654	},
{	-1643	,	1841	,	655	},
{	-1655	,	1853	,	658	},
{	-1662	,	1858	,	659	},
{	-1670	,	1863	,	661	},
{	-1679	,	1870	,	663	},
{	-1690	,	1878	,	667	},
{	-1698	,	1883	,	669	},
{	-1701	,	1883	,	670	},
{	-1711	,	1890	,	672	},
{	-1716	,	1893	,	673	},
{	-1724	,	1899	,	675	},
{	-1732	,	1902	,	677	},
{	-1739	,	1902	,	678	},
{	-1752	,	1909	,	681	},
{	-1758	,	1907	,	680	},
{	-1765	,	1908	,	681	},
{	-1770	,	1907	,	680	},
{	-1776	,	1907	,	681	},
{	-1783	,	1909	,	681	},
{	-1791	,	1912	,	682	},
{	-1795	,	1912	,	681	},
{	-1804	,	1919	,	683	},
{	-1807	,	1918	,	682	},
{	-1818	,	1927	,	684	},
{	-1830	,	1936	,	686	},
{	-1838	,	1941	,	687	},
{	-1845	,	1948	,	687	},
{	-1857	,	1957	,	688	},
{	-1865	,	1965	,	690	},
{	-1871	,	1971	,	690	},
{	-1876	,	1976	,	690	},
{	-1885	,	1987	,	693	},
{	-1893	,	1997	,	694	},
{	-1898	,	2004	,	695	},
{	-1909	,	2017	,	697	},
{	-1912	,	2021	,	698	},
{	-1919	,	2029	,	699	},
{	-1931	,	2042	,	701	},
{	-1933	,	2046	,	700	},
{	-1937	,	2052	,	701	},
{	-1943	,	2058	,	701	},
{	-1947	,	2064	,	703	},
{	-1951	,	2069	,	703	},
{	-1959	,	2078	,	706	},
{	-1964	,	2085	,	707	},
{	-1968	,	2089	,	708	},
{	-1972	,	2096	,	709	},
{	-1977	,	2101	,	709	},
{	-1978	,	2104	,	708	},
{	-1984	,	2112	,	710	},
{	-1995	,	2125	,	714	},
{	-1995	,	2126	,	713	},
{	-2004	,	2137	,	716	},
{	-2010	,	2145	,	718	},
{	-2016	,	2150	,	718	},
{	-2022	,	2155	,	720	},
{	-2032	,	2165	,	722	},
{	-2035	,	2168	,	723	},
{	-2041	,	2175	,	723	},
{	-2046	,	2180	,	724	},
{	-2054	,	2188	,	725	},
{	-2055	,	2188	,	725	},
{	-2066	,	2198	,	728	},
{	-2072	,	2203	,	729	},
{	-2081	,	2211	,	732	},
{	-2090	,	2219	,	735	},
{	-2093	,	2221	,	735	},
{	-2100	,	2225	,	736	},
{	-2114	,	2238	,	740	},
{	-2118	,	2239	,	740	},
{	-2123	,	2240	,	741	},
{	-2132	,	2246	,	744	},
{	-2144	,	2255	,	747	},
{	-2154	,	2261	,	750	},
{	-2168	,	2272	,	753	},
{	-2174	,	2274	,	755	},
{	-2182	,	2279	,	757	},
{	-2191	,	2285	,	759	},
{	-2204	,	2293	,	762	},
{	-2207	,	2291	,	762	},
{	-2216	,	2294	,	763	},
{	-2228	,	2301	,	766	},
{	-2236	,	2303	,	767	},
{	-2249	,	2310	,	770	},
{	-2253	,	2307	,	769	},
{	-2262	,	2308	,	770	},
{	-2276	,	2313	,	773	},
{	-2282	,	2310	,	774	},
{	-2286	,	2306	,	774	},
{	-2286	,	2296	,	773	},
{	-2294	,	2296	,	775	},
{	-2291	,	2282	,	773	},
{	-2297	,	2282	,	774	},
{	-2303	,	2282	,	775	},
{	-2302	,	2276	,	774	},
{	-2303	,	2271	,	774	},
{	-2308	,	2270	,	774	},
{	-2314	,	2272	,	777	},
{	-2309	,	2261	,	774	},
{	-2313	,	2258	,	776	}
};

#endif	/* TABLE_LUGE7_SN114_H */
