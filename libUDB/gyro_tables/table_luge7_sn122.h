

#ifndef TABLE_LUGE7_SN122_H
#define	TABLE_LUGE7_SN122_H

// used in LUGE7_SN122 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14737 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-661	,	-770	,	13	},
{	-658	,	-777	,	13	},
{	-654	,	-780	,	14	},
{	-650	,	-782	,	16	},
{	-646	,	-788	,	17	},
{	-641	,	-790	,	17	},
{	-636	,	-795	,	18	},
{	-631	,	-796	,	19	},
{	-626	,	-797	,	21	},
{	-620	,	-803	,	23	},
{	-615	,	-810	,	25	},
{	-608	,	-818	,	25	},
{	-597	,	-823	,	26	},
{	-585	,	-827	,	26	},
{	-573	,	-832	,	28	},
{	-562	,	-838	,	30	},
{	-550	,	-843	,	30	},
{	-539	,	-847	,	30	},
{	-527	,	-850	,	30	},
{	-517	,	-858	,	30	},
{	-506	,	-862	,	30	},
{	-495	,	-865	,	29	},
{	-485	,	-869	,	30	},
{	-474	,	-870	,	30	},
{	-466	,	-875	,	31	},
{	-456	,	-882	,	30	},
{	-446	,	-890	,	31	},
{	-436	,	-895	,	31	},
{	-425	,	-898	,	31	},
{	-413	,	-903	,	31	},
{	-404	,	-909	,	31	},
{	-394	,	-912	,	31	},
{	-384	,	-917	,	31	},
{	-374	,	-923	,	31	},
{	-365	,	-928	,	31	},
{	-356	,	-931	,	32	},
{	-345	,	-933	,	32	},
{	-336	,	-937	,	31	},
{	-326	,	-940	,	32	},
{	-316	,	-943	,	32	},
{	-306	,	-947	,	32	},
{	-295	,	-951	,	31	},
{	-285	,	-953	,	31	},
{	-275	,	-955	,	30	},
{	-265	,	-956	,	30	},
{	-257	,	-961	,	29	},
{	-248	,	-960	,	30	},
{	-239	,	-962	,	30	},
{	-230	,	-964	,	30	},
{	-220	,	-963	,	29	},
{	-212	,	-964	,	29	},
{	-203	,	-963	,	28	},
{	-194	,	-968	,	28	},
{	-185	,	-968	,	28	},
{	-176	,	-970	,	26	},
{	-167	,	-973	,	26	},
{	-158	,	-976	,	25	},
{	-149	,	-978	,	25	},
{	-141	,	-979	,	25	},
{	-132	,	-979	,	25	},
{	-124	,	-982	,	25	},
{	-116	,	-983	,	24	},
{	-108	,	-980	,	25	},
{	-100	,	-987	,	25	},
{	-92	,	-990	,	26	},
{	-86	,	-995	,	27	},
{	-79	,	-1003	,	27	},
{	-73	,	-1011	,	28	},
{	-67	,	-1019	,	30	},
{	-62	,	-1027	,	32	},
{	-56	,	-1037	,	33	},
{	-52	,	-1047	,	37	},
{	-47	,	-1054	,	39	},
{	-42	,	-1062	,	42	},
{	-38	,	-1074	,	43	},
{	-33	,	-1085	,	44	},
{	-28	,	-1097	,	46	},
{	-23	,	-1107	,	47	},
{	-18	,	-1119	,	49	},
{	-13	,	-1134	,	51	},
{	-9	,	-1143	,	53	},
{	-4	,	-1153	,	54	},
{	2	,	-1163	,	55	},
{	7	,	-1171	,	56	},
{	13	,	-1177	,	57	},
{	18	,	-1186	,	57	},
{	23	,	-1190	,	57	},
{	29	,	-1195	,	58	},
{	35	,	-1201	,	58	},
{	40	,	-1209	,	58	},
{	45	,	-1217	,	59	},
{	49	,	-1221	,	59	},
{	53	,	-1227	,	59	},
{	58	,	-1233	,	59	},
{	62	,	-1240	,	60	},
{	66	,	-1247	,	61	},
{	69	,	-1251	,	62	},
{	72	,	-1259	,	62	},
{	75	,	-1262	,	63	},
{	77	,	-1266	,	62	},
{	79	,	-1270	,	62	},
{	80	,	-1276	,	63	},
{	83	,	-1277	,	63	},
{	85	,	-1284	,	64	},
{	86	,	-1287	,	65	},
{	86	,	-1292	,	65	},
{	87	,	-1293	,	65	},
{	87	,	-1297	,	65	},
{	87	,	-1302	,	65	},
{	86	,	-1304	,	66	},
{	85	,	-1305	,	67	},
{	85	,	-1307	,	69	},
{	83	,	-1307	,	69	},
{	82	,	-1313	,	69	},
{	80	,	-1313	,	70	},
{	78	,	-1316	,	70	},
{	76	,	-1321	,	70	},
{	72	,	-1323	,	71	},
{	69	,	-1323	,	71	},
{	64	,	-1328	,	72	},
{	59	,	-1331	,	73	},
{	54	,	-1333	,	73	},
{	48	,	-1334	,	74	},
{	41	,	-1341	,	74	},
{	34	,	-1340	,	75	},
{	26	,	-1343	,	75	},
{	19	,	-1343	,	75	},
{	11	,	-1343	,	76	},
{	0	,	-1342	,	75	},
{	-10	,	-1341	,	74	},
{	-21	,	-1338	,	74	},
{	-32	,	-1336	,	74	},
{	-44	,	-1336	,	74	},
{	-58	,	-1334	,	74	},
{	-70	,	-1332	,	74	},
{	-83	,	-1332	,	75	},
{	-97	,	-1331	,	75	},
{	-111	,	-1327	,	75	},
{	-124	,	-1322	,	75	},
{	-138	,	-1321	,	75	},
{	-152	,	-1315	,	75	},
{	-166	,	-1314	,	74	},
{	-179	,	-1310	,	74	},
{	-193	,	-1305	,	74	},
{	-208	,	-1304	,	74	},
{	-221	,	-1302	,	74	},
{	-234	,	-1297	,	74	},
{	-247	,	-1297	,	74	},
{	-259	,	-1291	,	73	},
{	-271	,	-1286	,	74	},
{	-283	,	-1280	,	74	},
{	-294	,	-1277	,	74	},
{	-305	,	-1274	,	74	},
{	-316	,	-1268	,	75	},
{	-327	,	-1267	,	75	},
{	-338	,	-1264	,	74	},
{	-348	,	-1261	,	74	},
{	-358	,	-1259	,	74	},
{	-368	,	-1256	,	75	},
{	-376	,	-1251	,	76	},
{	-386	,	-1252	,	76	},
{	-395	,	-1250	,	77	},
{	-405	,	-1248	,	77	},
{	-414	,	-1248	,	77	},
{	-423	,	-1247	,	78	},
{	-430	,	-1245	,	78	},
{	-439	,	-1247	,	78	},
{	-447	,	-1248	,	79	},
{	-456	,	-1250	,	79	},
{	-463	,	-1247	,	79	},
{	-472	,	-1251	,	79	},
{	-479	,	-1247	,	79	},
{	-486	,	-1248	,	79	},
{	-494	,	-1247	,	79	},
{	-501	,	-1249	,	80	},
{	-508	,	-1249	,	80	},
{	-514	,	-1251	,	80	},
{	-521	,	-1253	,	80	},
{	-528	,	-1256	,	80	},
{	-533	,	-1257	,	80	},
{	-539	,	-1257	,	80	},
{	-548	,	-1260	,	79	},
{	-554	,	-1261	,	81	},
{	-562	,	-1263	,	82	},
{	-569	,	-1264	,	82	},
{	-577	,	-1265	,	83	},
{	-584	,	-1267	,	84	},
{	-590	,	-1268	,	84	},
{	-597	,	-1271	,	85	},
{	-604	,	-1272	,	85	},
{	-611	,	-1275	,	86	},
{	-617	,	-1276	,	87	},
{	-624	,	-1278	,	88	},
{	-632	,	-1281	,	88	},
{	-638	,	-1284	,	88	},
{	-644	,	-1284	,	89	},
{	-651	,	-1286	,	90	},
{	-659	,	-1290	,	91	},
{	-664	,	-1288	,	92	},
{	-672	,	-1291	,	93	},
{	-679	,	-1293	,	93	},
{	-687	,	-1297	,	94	},
{	-692	,	-1296	,	94	},
{	-700	,	-1302	,	95	},
{	-707	,	-1303	,	95	},
{	-713	,	-1304	,	95	},
{	-721	,	-1308	,	97	},
{	-728	,	-1311	,	98	},
{	-734	,	-1311	,	98	},
{	-742	,	-1313	,	99	},
{	-749	,	-1314	,	100	},
{	-758	,	-1316	,	101	},
{	-767	,	-1322	,	102	},
{	-775	,	-1326	,	103	},
{	-784	,	-1329	,	104	},
{	-792	,	-1333	,	106	},
{	-802	,	-1341	,	108	},
{	-809	,	-1341	,	110	},
{	-817	,	-1345	,	111	},
{	-825	,	-1351	,	113	},
{	-833	,	-1352	,	114	},
{	-842	,	-1357	,	116	},
{	-851	,	-1360	,	118	},
{	-859	,	-1364	,	120	},
{	-868	,	-1369	,	122	},
{	-879	,	-1376	,	124	},
{	-887	,	-1379	,	125	},
{	-897	,	-1383	,	127	},
{	-905	,	-1385	,	128	},
{	-914	,	-1388	,	129	},
{	-922	,	-1389	,	131	},
{	-929	,	-1390	,	132	},
{	-937	,	-1393	,	134	},
{	-942	,	-1390	,	133	},
{	-950	,	-1394	,	134	},
{	-957	,	-1393	,	134	},
{	-965	,	-1394	,	135	},
{	-972	,	-1395	,	135	},
{	-978	,	-1394	,	136	},
{	-989	,	-1398	,	137	},
{	-995	,	-1398	,	137	},
{	-1003	,	-1396	,	138	},
{	-1011	,	-1396	,	138	},
{	-1021	,	-1398	,	139	},
{	-1032	,	-1403	,	140	},
{	-1040	,	-1401	,	141	},
{	-1047	,	-1400	,	142	},
{	-1054	,	-1400	,	143	},
{	-1066	,	-1406	,	145	},
{	-1075	,	-1409	,	146	},
{	-1086	,	-1414	,	147	},
{	-1097	,	-1418	,	148	},
{	-1104	,	-1418	,	148	},
{	-1116	,	-1422	,	149	},
{	-1127	,	-1427	,	151	},
{	-1136	,	-1431	,	152	},
{	-1142	,	-1431	,	153	},
{	-1150	,	-1434	,	154	},
{	-1159	,	-1439	,	155	},
{	-1167	,	-1442	,	157	},
{	-1178	,	-1450	,	159	},
{	-1184	,	-1449	,	160	},
{	-1194	,	-1457	,	161	},
{	-1205	,	-1462	,	163	},
{	-1213	,	-1466	,	164	},
{	-1220	,	-1468	,	165	},
{	-1229	,	-1473	,	167	},
{	-1234	,	-1472	,	167	},
{	-1242	,	-1478	,	169	},
{	-1251	,	-1481	,	170	},
{	-1258	,	-1483	,	172	},
{	-1263	,	-1482	,	173	},
{	-1272	,	-1486	,	174	},
{	-1282	,	-1489	,	175	},
{	-1292	,	-1494	,	175	},
{	-1299	,	-1496	,	175	},
{	-1307	,	-1498	,	175	},
{	-1313	,	-1495	,	175	},
{	-1320	,	-1495	,	175	},
{	-1329	,	-1496	,	176	},
{	-1339	,	-1500	,	176	},
{	-1351	,	-1507	,	176	},
{	-1357	,	-1505	,	175	},
{	-1365	,	-1505	,	175	},
{	-1377	,	-1511	,	174	},
{	-1389	,	-1513	,	173	},
{	-1399	,	-1515	,	173	},
{	-1410	,	-1520	,	172	},
{	-1420	,	-1523	,	171	},
{	-1430	,	-1526	,	169	},
{	-1440	,	-1530	,	168	},
{	-1452	,	-1531	,	167	},
{	-1463	,	-1534	,	166	},
{	-1475	,	-1539	,	166	},
{	-1482	,	-1538	,	164	},
{	-1495	,	-1545	,	163	},
{	-1502	,	-1543	,	161	},
{	-1510	,	-1544	,	159	},
{	-1519	,	-1544	,	157	},
{	-1532	,	-1548	,	156	},
{	-1540	,	-1547	,	153	},
{	-1550	,	-1549	,	152	},
{	-1554	,	-1545	,	150	},
{	-1564	,	-1548	,	150	},
{	-1574	,	-1549	,	148	},
{	-1582	,	-1549	,	147	},
{	-1591	,	-1551	,	145	},
{	-1599	,	-1550	,	144	},
{	-1611	,	-1556	,	143	},
{	-1617	,	-1554	,	142	},
{	-1627	,	-1555	,	142	},
{	-1637	,	-1559	,	141	},
{	-1642	,	-1557	,	139	},
{	-1652	,	-1560	,	138	},
{	-1661	,	-1560	,	136	},
{	-1669	,	-1560	,	134	},
{	-1678	,	-1562	,	134	},
{	-1689	,	-1566	,	133	},
{	-1698	,	-1567	,	132	},
{	-1707	,	-1570	,	131	},
{	-1720	,	-1576	,	129	},
{	-1725	,	-1575	,	128	},
{	-1736	,	-1579	,	126	},
{	-1742	,	-1579	,	125	},
{	-1750	,	-1579	,	123	},
{	-1758	,	-1580	,	121	},
{	-1769	,	-1581	,	119	},
{	-1776	,	-1580	,	117	},
{	-1788	,	-1583	,	116	},
{	-1802	,	-1588	,	115	},
{	-1815	,	-1591	,	114	},
{	-1823	,	-1590	,	114	},
{	-1834	,	-1592	,	113	},
{	-1848	,	-1596	,	111	},
{	-1857	,	-1595	,	112	},
{	-1866	,	-1595	,	112	},
{	-1879	,	-1596	,	113	},
{	-1891	,	-1598	,	112	},
{	-1902	,	-1598	,	111	},
{	-1916	,	-1601	,	111	},
{	-1929	,	-1603	,	111	},
{	-1943	,	-1607	,	111	},
{	-1957	,	-1609	,	111	},
{	-1971	,	-1614	,	112	},
{	-1979	,	-1615	,	111	},
{	-1989	,	-1617	,	111	},
{	-1999	,	-1620	,	111	},
{	-2007	,	-1621	,	111	},
{	-2020	,	-1628	,	111	},
{	-2028	,	-1631	,	110	},
{	-2033	,	-1630	,	110	},
{	-2047	,	-1638	,	110	},
{	-2056	,	-1641	,	109	},
{	-2070	,	-1650	,	108	},
{	-2073	,	-1648	,	107	},
{	-2084	,	-1652	,	108	},
{	-2097	,	-1657	,	108	},
{	-2106	,	-1661	,	108	},
{	-2116	,	-1666	,	108	},
{	-2125	,	-1671	,	109	},
{	-2131	,	-1674	,	109	},
{	-2145	,	-1680	,	109	},
{	-2156	,	-1686	,	109	},
{	-2167	,	-1691	,	108	},
{	-2177	,	-1694	,	109	},
{	-2186	,	-1698	,	108	},
{	-2202	,	-1705	,	109	},
{	-2214	,	-1712	,	109	},
{	-2227	,	-1718	,	109	},
{	-2238	,	-1721	,	109	},
{	-2245	,	-1723	,	109	},
{	-2258	,	-1728	,	108	},
{	-2274	,	-1737	,	108	},
{	-2283	,	-1742	,	108	},
{	-2298	,	-1750	,	108	},
{	-2309	,	-1756	,	109	},
{	-2321	,	-1761	,	109	},
{	-2335	,	-1769	,	108	},
{	-2345	,	-1774	,	108	},
{	-2357	,	-1780	,	108	},
{	-2372	,	-1788	,	108	},
{	-2386	,	-1797	,	107	},
{	-2407	,	-1808	,	109	},
{	-2418	,	-1814	,	109	},
{	-2428	,	-1820	,	109	},
{	-2439	,	-1826	,	109	},
{	-2454	,	-1836	,	110	},
{	-2474	,	-1850	,	110	},
{	-2491	,	-1860	,	111	},
{	-2502	,	-1866	,	110	},
{	-2516	,	-1873	,	111	},
{	-2531	,	-1882	,	112	},
{	-2543	,	-1890	,	111	},
{	-2562	,	-1900	,	111	},
{	-2578	,	-1909	,	111	},
{	-2604	,	-1925	,	112	},
{	-2626	,	-1938	,	113	},
{	-2640	,	-1945	,	114	},
{	-2659	,	-1955	,	115	},
{	-2673	,	-1962	,	115	},
{	-2695	,	-1975	,	116	},
{	-2722	,	-1990	,	116	},
{	-2743	,	-2001	,	117	},
{	-2764	,	-2012	,	117	},
{	-2778	,	-2019	,	117	},
{	-2798	,	-2029	,	117	},
{	-2823	,	-2042	,	119	},
{	-2844	,	-2053	,	121	},
{	-2860	,	-2060	,	122	},
{	-2886	,	-2072	,	124	},
{	-2905	,	-2080	,	124	},
{	-2929	,	-2092	,	125	},
{	-2945	,	-2097	,	126	},
{	-2961	,	-2104	,	126	},
{	-2983	,	-2114	,	128	},
{	-3003	,	-2123	,	129	},
{	-3025	,	-2135	,	131	},
{	-3039	,	-2140	,	132	},
{	-3055	,	-2147	,	133	},
{	-3079	,	-2160	,	135	},
{	-3100	,	-2171	,	136	},
{	-3116	,	-2179	,	137	},
{	-3140	,	-2191	,	139	},
{	-3152	,	-2198	,	140	},
{	-3173	,	-2211	,	141	},
{	-3192	,	-2222	,	141	},
{	-3205	,	-2231	,	141	},
{	-3224	,	-2243	,	142	},
{	-3231	,	-2248	,	142	},
{	-3253	,	-2263	,	145	},
{	-3276	,	-2279	,	147	},
{	-3291	,	-2290	,	150	},
{	-3307	,	-2303	,	152	},
{	-3323	,	-2315	,	153	},
{	-3339	,	-2327	,	155	},
{	-3358	,	-2342	,	158	},
{	-3364	,	-2348	,	161	},
{	-3374	,	-2359	,	164	},
{	-3384	,	-2370	,	167	},
{	-3391	,	-2383	,	171	},
{	-3396	,	-2392	,	175	},
{	-3397	,	-2399	,	178	},
{	-3408	,	-2416	,	183	},
{	-3414	,	-2428	,	187	},
{	-3412	,	-2438	,	192	},
{	-3416	,	-2453	,	197	},
{	-3408	,	-2463	,	202	},
{	-3398	,	-2472	,	207	},
{	-3384	,	-2481	,	213	},
{	-3371	,	-2494	,	219	},
{	-3342	,	-2506	,	224	},
{	-3313	,	-2516	,	230	},
{	-3264	,	-2519	,	236	},
{	-3225	,	-2531	,	242	},
{	-3180	,	-2545	,	251	},
{	-3129	,	-2556	,	259	},
{	-3067	,	-2566	,	267	},
{	-3005	,	-2578	,	275	},
{	-2918	,	-2580	,	282	},
{	-2882	,	-2581	,	286	},
{	-2849	,	-2586	,	290	},
{	-2812	,	-2590	,	294	},
{	-2773	,	-2594	,	300	},
{	-2726	,	-2595	,	304	},
{	-2674	,	-2597	,	308	},
{	-2624	,	-2604	,	312	},
{	-2563	,	-2602	,	316	}
};

#endif	/* TABLE_LUGE7_SN122_H */

