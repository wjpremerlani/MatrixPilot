

#ifndef TABLE_LUGE7_SN115_H
#define	TABLE_LUGE7_SN115_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14588 )

int16_t residual_offset[] = { 251 , 32 , -201 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-2665	,	-1507	,	-769	},
{	-2647	,	-1505	,	-763	},
{	-2636	,	-1509	,	-760	},
{	-2629	,	-1515	,	-756	},
{	-2616	,	-1516	,	-752	},
{	-2602	,	-1516	,	-747	},
{	-2588	,	-1516	,	-741	},
{	-2579	,	-1518	,	-737	},
{	-2563	,	-1516	,	-730	},
{	-2560	,	-1527	,	-727	},
{	-2531	,	-1522	,	-715	},
{	-2504	,	-1523	,	-706	},
{	-2486	,	-1526	,	-698	},
{	-2460	,	-1527	,	-687	},
{	-2437	,	-1529	,	-682	},
{	-2414	,	-1530	,	-672	},
{	-2390	,	-1529	,	-660	},
{	-2369	,	-1528	,	-648	},
{	-2347	,	-1524	,	-638	},
{	-2330	,	-1525	,	-628	},
{	-2306	,	-1521	,	-617	},
{	-2285	,	-1519	,	-607	},
{	-2265	,	-1518	,	-597	},
{	-2249	,	-1518	,	-589	},
{	-2228	,	-1516	,	-579	},
{	-2214	,	-1518	,	-570	},
{	-2192	,	-1514	,	-559	},
{	-2177	,	-1515	,	-550	},
{	-2157	,	-1510	,	-539	},
{	-2135	,	-1507	,	-529	},
{	-2117	,	-1506	,	-519	},
{	-2092	,	-1505	,	-511	},
{	-2068	,	-1502	,	-501	},
{	-2051	,	-1503	,	-493	},
{	-2026	,	-1498	,	-482	},
{	-2007	,	-1500	,	-474	},
{	-1984	,	-1496	,	-463	},
{	-1962	,	-1493	,	-453	},
{	-1940	,	-1490	,	-443	},
{	-1923	,	-1491	,	-433	},
{	-1900	,	-1486	,	-423	},
{	-1878	,	-1482	,	-412	},
{	-1858	,	-1482	,	-403	},
{	-1836	,	-1479	,	-392	},
{	-1815	,	-1475	,	-382	},
{	-1794	,	-1471	,	-371	},
{	-1773	,	-1468	,	-360	},
{	-1756	,	-1469	,	-351	},
{	-1736	,	-1462	,	-339	},
{	-1723	,	-1463	,	-329	},
{	-1703	,	-1460	,	-319	},
{	-1684	,	-1454	,	-308	},
{	-1668	,	-1455	,	-299	},
{	-1645	,	-1449	,	-289	},
{	-1629	,	-1450	,	-280	},
{	-1613	,	-1449	,	-270	},
{	-1591	,	-1445	,	-260	},
{	-1571	,	-1442	,	-249	},
{	-1553	,	-1439	,	-240	},
{	-1532	,	-1435	,	-231	},
{	-1516	,	-1434	,	-222	},
{	-1496	,	-1430	,	-211	},
{	-1479	,	-1427	,	-201	},
{	-1458	,	-1421	,	-192	},
{	-1439	,	-1418	,	-181	},
{	-1422	,	-1415	,	-172	},
{	-1400	,	-1408	,	-162	},
{	-1382	,	-1404	,	-152	},
{	-1366	,	-1406	,	-143	},
{	-1346	,	-1400	,	-133	},
{	-1329	,	-1396	,	-123	},
{	-1309	,	-1391	,	-112	},
{	-1291	,	-1387	,	-102	},
{	-1273	,	-1382	,	-93	},
{	-1257	,	-1380	,	-86	},
{	-1240	,	-1377	,	-76	},
{	-1221	,	-1373	,	-67	},
{	-1201	,	-1368	,	-57	},
{	-1185	,	-1367	,	-47	},
{	-1168	,	-1366	,	-39	},
{	-1153	,	-1368	,	-31	},
{	-1132	,	-1362	,	-23	},
{	-1115	,	-1359	,	-14	},
{	-1099	,	-1358	,	-6	},
{	-1081	,	-1355	,	2	},
{	-1063	,	-1349	,	10	},
{	-1052	,	-1350	,	19	},
{	-1036	,	-1348	,	27	},
{	-1020	,	-1344	,	34	},
{	-1006	,	-1344	,	40	},
{	-993	,	-1346	,	46	},
{	-979	,	-1345	,	52	},
{	-965	,	-1343	,	57	},
{	-953	,	-1344	,	62	},
{	-943	,	-1344	,	67	},
{	-931	,	-1342	,	71	},
{	-922	,	-1343	,	76	},
{	-909	,	-1339	,	82	},
{	-900	,	-1341	,	87	},
{	-889	,	-1342	,	93	},
{	-880	,	-1342	,	98	},
{	-870	,	-1341	,	105	},
{	-859	,	-1340	,	110	},
{	-849	,	-1339	,	115	},
{	-842	,	-1340	,	121	},
{	-834	,	-1340	,	128	},
{	-824	,	-1337	,	133	},
{	-814	,	-1331	,	141	},
{	-805	,	-1328	,	149	},
{	-796	,	-1326	,	157	},
{	-786	,	-1321	,	165	},
{	-776	,	-1318	,	173	},
{	-766	,	-1314	,	180	},
{	-755	,	-1310	,	188	},
{	-745	,	-1306	,	195	},
{	-737	,	-1305	,	203	},
{	-728	,	-1300	,	209	},
{	-720	,	-1296	,	218	},
{	-714	,	-1293	,	226	},
{	-708	,	-1294	,	234	},
{	-700	,	-1287	,	240	},
{	-692	,	-1281	,	246	},
{	-687	,	-1277	,	252	},
{	-684	,	-1275	,	260	},
{	-681	,	-1275	,	265	},
{	-679	,	-1272	,	271	},
{	-676	,	-1266	,	278	},
{	-674	,	-1262	,	283	},
{	-672	,	-1259	,	290	},
{	-672	,	-1258	,	297	},
{	-672	,	-1251	,	303	},
{	-673	,	-1248	,	309	},
{	-673	,	-1237	,	314	},
{	-676	,	-1232	,	321	},
{	-676	,	-1225	,	325	},
{	-679	,	-1220	,	331	},
{	-681	,	-1210	,	336	},
{	-685	,	-1206	,	342	},
{	-690	,	-1201	,	348	},
{	-694	,	-1192	,	353	},
{	-699	,	-1184	,	359	},
{	-706	,	-1174	,	366	},
{	-712	,	-1166	,	374	},
{	-718	,	-1157	,	379	},
{	-726	,	-1146	,	387	},
{	-735	,	-1139	,	395	},
{	-742	,	-1125	,	401	},
{	-750	,	-1118	,	407	},
{	-759	,	-1107	,	415	},
{	-768	,	-1099	,	422	},
{	-774	,	-1088	,	428	},
{	-784	,	-1080	,	436	},
{	-789	,	-1066	,	441	},
{	-797	,	-1057	,	448	},
{	-804	,	-1044	,	455	},
{	-809	,	-1031	,	461	},
{	-816	,	-1021	,	468	},
{	-823	,	-1008	,	474	},
{	-827	,	-996	,	480	},
{	-833	,	-984	,	486	},
{	-838	,	-974	,	494	},
{	-841	,	-962	,	498	},
{	-844	,	-949	,	503	},
{	-850	,	-940	,	510	},
{	-853	,	-927	,	517	},
{	-856	,	-916	,	524	},
{	-860	,	-904	,	530	},
{	-863	,	-892	,	537	},
{	-865	,	-882	,	543	},
{	-869	,	-872	,	551	},
{	-871	,	-860	,	555	},
{	-874	,	-850	,	562	},
{	-878	,	-842	,	568	},
{	-881	,	-833	,	575	},
{	-883	,	-824	,	583	},
{	-886	,	-815	,	590	},
{	-886	,	-804	,	593	},
{	-886	,	-795	,	598	},
{	-890	,	-789	,	605	},
{	-890	,	-778	,	610	},
{	-889	,	-768	,	614	},
{	-893	,	-758	,	621	},
{	-895	,	-749	,	629	},
{	-895	,	-738	,	633	},
{	-898	,	-730	,	640	},
{	-901	,	-722	,	648	},
{	-902	,	-712	,	654	},
{	-905	,	-704	,	662	},
{	-906	,	-696	,	670	},
{	-906	,	-686	,	674	},
{	-908	,	-678	,	680	},
{	-908	,	-668	,	684	},
{	-908	,	-660	,	690	},
{	-911	,	-653	,	700	},
{	-915	,	-646	,	710	},
{	-918	,	-637	,	719	},
{	-919	,	-628	,	727	},
{	-922	,	-619	,	735	},
{	-922	,	-611	,	740	},
{	-922	,	-602	,	745	},
{	-923	,	-597	,	751	},
{	-924	,	-591	,	756	},
{	-925	,	-583	,	761	},
{	-926	,	-577	,	764	},
{	-926	,	-570	,	767	},
{	-928	,	-563	,	771	},
{	-931	,	-557	,	779	},
{	-931	,	-548	,	783	},
{	-935	,	-540	,	789	},
{	-939	,	-534	,	795	},
{	-939	,	-525	,	798	},
{	-941	,	-518	,	800	},
{	-939	,	-510	,	801	},
{	-942	,	-503	,	804	},
{	-945	,	-496	,	808	},
{	-949	,	-491	,	813	},
{	-952	,	-484	,	817	},
{	-957	,	-477	,	822	},
{	-960	,	-468	,	827	},
{	-963	,	-459	,	831	},
{	-969	,	-451	,	839	},
{	-974	,	-444	,	845	},
{	-976	,	-435	,	848	},
{	-980	,	-427	,	853	},
{	-984	,	-420	,	858	},
{	-987	,	-411	,	864	},
{	-989	,	-401	,	870	},
{	-994	,	-391	,	877	},
{	-997	,	-382	,	884	},
{	-1003	,	-373	,	892	},
{	-1006	,	-363	,	898	},
{	-1010	,	-354	,	904	},
{	-1013	,	-346	,	909	},
{	-1016	,	-338	,	914	},
{	-1017	,	-329	,	919	},
{	-1019	,	-320	,	924	},
{	-1022	,	-313	,	931	},
{	-1023	,	-304	,	935	},
{	-1026	,	-295	,	942	},
{	-1028	,	-287	,	950	},
{	-1030	,	-278	,	955	},
{	-1034	,	-270	,	962	},
{	-1036	,	-262	,	966	},
{	-1037	,	-255	,	968	},
{	-1039	,	-248	,	972	},
{	-1041	,	-240	,	977	},
{	-1043	,	-234	,	980	},
{	-1047	,	-228	,	985	},
{	-1049	,	-220	,	990	},
{	-1053	,	-210	,	997	},
{	-1056	,	-201	,	1003	},
{	-1062	,	-193	,	1011	},
{	-1065	,	-186	,	1015	},
{	-1068	,	-179	,	1019	},
{	-1072	,	-172	,	1023	},
{	-1077	,	-165	,	1029	},
{	-1079	,	-158	,	1033	},
{	-1083	,	-151	,	1039	},
{	-1087	,	-144	,	1044	},
{	-1091	,	-135	,	1051	},
{	-1095	,	-128	,	1056	},
{	-1101	,	-122	,	1063	},
{	-1104	,	-117	,	1066	},
{	-1109	,	-113	,	1071	},
{	-1114	,	-106	,	1075	},
{	-1118	,	-101	,	1078	},
{	-1123	,	-98	,	1083	},
{	-1129	,	-95	,	1087	},
{	-1132	,	-92	,	1088	},
{	-1139	,	-88	,	1091	},
{	-1144	,	-86	,	1093	},
{	-1152	,	-82	,	1099	},
{	-1157	,	-78	,	1102	},
{	-1166	,	-77	,	1107	},
{	-1175	,	-75	,	1111	},
{	-1182	,	-73	,	1113	},
{	-1192	,	-74	,	1115	},
{	-1200	,	-75	,	1117	},
{	-1208	,	-75	,	1118	},
{	-1216	,	-77	,	1122	},
{	-1225	,	-77	,	1125	},
{	-1232	,	-79	,	1127	},
{	-1244	,	-83	,	1133	},
{	-1251	,	-85	,	1134	},
{	-1257	,	-86	,	1135	},
{	-1264	,	-89	,	1136	},
{	-1271	,	-88	,	1140	},
{	-1281	,	-87	,	1146	},
{	-1284	,	-86	,	1147	},
{	-1290	,	-85	,	1152	},
{	-1295	,	-83	,	1154	},
{	-1300	,	-82	,	1156	},
{	-1302	,	-80	,	1157	},
{	-1304	,	-76	,	1159	},
{	-1312	,	-72	,	1167	},
{	-1313	,	-66	,	1169	},
{	-1319	,	-59	,	1175	},
{	-1319	,	-51	,	1179	},
{	-1321	,	-43	,	1185	},
{	-1322	,	-33	,	1190	},
{	-1320	,	-25	,	1191	},
{	-1325	,	-17	,	1197	},
{	-1331	,	-7	,	1206	},
{	-1335	,	1	,	1213	},
{	-1335	,	10	,	1216	},
{	-1339	,	18	,	1220	},
{	-1341	,	27	,	1223	},
{	-1345	,	37	,	1229	},
{	-1347	,	47	,	1236	},
{	-1352	,	57	,	1245	},
{	-1356	,	67	,	1253	},
{	-1356	,	76	,	1256	},
{	-1360	,	83	,	1261	},
{	-1362	,	92	,	1265	},
{	-1368	,	100	,	1272	},
{	-1373	,	107	,	1275	},
{	-1374	,	114	,	1277	},
{	-1378	,	121	,	1282	},
{	-1385	,	130	,	1289	},
{	-1385	,	138	,	1291	},
{	-1391	,	146	,	1297	},
{	-1397	,	153	,	1303	},
{	-1399	,	160	,	1306	},
{	-1406	,	168	,	1314	},
{	-1409	,	175	,	1318	},
{	-1415	,	183	,	1323	},
{	-1419	,	190	,	1326	},
{	-1422	,	197	,	1330	},
{	-1426	,	204	,	1335	},
{	-1431	,	211	,	1340	},
{	-1436	,	218	,	1345	},
{	-1442	,	226	,	1352	},
{	-1450	,	234	,	1358	},
{	-1455	,	241	,	1364	},
{	-1462	,	249	,	1373	},
{	-1464	,	256	,	1378	},
{	-1472	,	265	,	1387	},
{	-1477	,	273	,	1393	},
{	-1482	,	279	,	1399	},
{	-1492	,	287	,	1410	},
{	-1494	,	292	,	1412	},
{	-1500	,	297	,	1418	},
{	-1507	,	303	,	1424	},
{	-1519	,	309	,	1434	},
{	-1528	,	314	,	1442	},
{	-1536	,	321	,	1448	},
{	-1545	,	327	,	1456	},
{	-1551	,	330	,	1459	},
{	-1557	,	334	,	1463	},
{	-1566	,	340	,	1469	},
{	-1576	,	343	,	1473	},
{	-1585	,	346	,	1476	},
{	-1593	,	350	,	1479	},
{	-1601	,	352	,	1480	},
{	-1609	,	356	,	1483	},
{	-1618	,	360	,	1487	},
{	-1627	,	362	,	1490	},
{	-1637	,	366	,	1495	},
{	-1649	,	369	,	1500	},
{	-1658	,	371	,	1503	},
{	-1664	,	373	,	1503	},
{	-1675	,	374	,	1508	},
{	-1685	,	375	,	1512	},
{	-1692	,	375	,	1512	},
{	-1708	,	378	,	1523	},
{	-1719	,	377	,	1527	},
{	-1730	,	376	,	1532	},
{	-1742	,	375	,	1537	},
{	-1751	,	371	,	1540	},
{	-1765	,	367	,	1548	},
{	-1777	,	361	,	1554	},
{	-1791	,	353	,	1562	},
{	-1799	,	342	,	1565	},
{	-1807	,	332	,	1568	},
{	-1816	,	320	,	1572	},
{	-1819	,	308	,	1572	},
{	-1824	,	302	,	1575	},
{	-1829	,	297	,	1577	},
{	-1832	,	291	,	1577	},
{	-1837	,	284	,	1579	},
{	-1846	,	279	,	1585	},
{	-1845	,	268	,	1580	},
{	-1849	,	260	,	1584	},
{	-1850	,	250	,	1583	}
};

#endif	/* TABLE_LUGE7_SN115_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -10589)

int16_t accel_residual_offset[] = { 18 , -37 , -105 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-4,1,1},
{-4,0,1},
{-4,0,1},
{-4,0,2},
{-3,0,11},
{-1,0,18},
{-1,0,15},
{-1,0,14},
{0,0,14},
{0,0,14},
{-1,0,14},
{-1,-1,14},
{0,-1,14},
{0,-1,15},
{0,-1,15},
{0,-1,15},
{0,-2,16},
{0,-3,16},
{0,-2,16},
{0,-2,17},
{0,-3,17},
{0,-3,18},
{0,-3,18},
{0,-4,18},
{0,-4,19},
{0,-4,19},
{0,-4,19},
{0,-4,19},
{0,-5,20},
{0,-5,20},
{0,-5,20},
{0,-5,20},
{0,-6,21},
{0,-6,21},
{0,-6,21},
{0,-6,21},
{0,-6,21},
{0,-6,22},
{0,-7,22},
{0,-7,22},
{0,-7,22},
{0,-7,22},
{0,-7,22},
{0,-7,22},
{1,-7,23},
{1,-8,23},
{1,-8,23},
{1,-8,24},
{1,-8,24},
{1,-8,24},
{1,-8,24},
{1,-8,24},
{1,-9,25},
{1,-9,25},
{1,-9,25},
{1,-9,26},
{1,-9,26},
{1,-9,26},
{1,-9,27},
{1,-9,27},
{1,-9,27},
{1,-9,27},
{1,-9,28},
{1,-9,28},
{1,-9,29},
{1,-9,29},
{1,-9,29},
{1,-9,30},
{1,-9,30},
{1,-9,31},
{1,-9,31},
{1,-9,32},
{1,-9,32},
{1,-9,33},
{1,-9,33},
{1,-8,33},
{1,-8,34},
{1,-8,34},
{2,-8,34},
{2,-8,35},
{2,-7,35},
{1,-7,36},
{1,-7,36},
{2,-6,37},
{1,-6,37},
{1,-6,38},
{1,-6,39},
{2,-6,39},
{2,-6,39},
{2,-6,40},
{1,-6,40},
{1,-6,41},
{1,-6,42},
{1,-6,42},
{1,-6,43},
{1,-6,43},
{1,-6,44},
{0,-6,44},
{0,-7,45},
{0,-7,45},
{0,-7,46},
{0,-7,46},
{0,-7,46},
{0,-8,46},
{0,-7,47},
{0,-7,47},
{0,-8,48},
{0,-8,48},
{0,-8,49},
{0,-8,49},
{0,-8,49},
{0,-8,49},
{0,-8,50},
{0,-8,50},
{0,-8,51},
{0,-8,51},
{0,-8,52},
{0,-8,52},
{0,-8,53},
{0,-8,53},
{0,-8,54},
{0,-9,54},
{0,-9,55},
{0,-9,55},
{0,-9,56},
{0,-9,56},
{-1,-9,57},
{-1,-9,58},
{-1,-9,58},
{-1,-9,59},
{-1,-9,59},
{-1,-9,60},
{-1,-9,60},
{-1,-9,61},
{-1,-9,61},
{-1,-9,62},
{-1,-10,63},
{-1,-10,63},
{-1,-10,64},
{-1,-10,64},
{-2,-10,65},
{-2,-10,65},
{-2,-10,66},
{-2,-10,67},
{-2,-10,67},
{-2,-10,68},
{-2,-10,68},
{-2,-10,69},
{-2,-10,70},
{-2,-10,71},
{-2,-10,71},
{-3,-11,72},
{-3,-11,73},
{-3,-11,73},
{-3,-11,74},
{-3,-11,75},
{-3,-11,75},
{-3,-11,76},
{-3,-11,77},
{-3,-11,78},
{-3,-11,78},
{-3,-12,79},
{-3,-12,80},
{-3,-12,81},
{-3,-12,81},
{-3,-12,82},
{-3,-12,83},
{-3,-12,84},
{-4,-12,84},
{-4,-12,85},
{-4,-12,86},
{-4,-13,87},
{-4,-13,88},
{-4,-13,89},
{-4,-13,90},
{-4,-13,91},
{-4,-13,91},
{-4,-13,92},
{-4,-13,93},
{-4,-13,94},
{-4,-14,95},
{-4,-13,95},
{-4,-13,96},
{-4,-14,97},
{-4,-14,97},
{-4,-14,98},
{-4,-14,98},
{-4,-14,99},
{-4,-14,99},
{-5,-14,100},
{-5,-14,100},
{-5,-14,101},
{-5,-14,101},
{-5,-14,102},
{-5,-15,103},
{-5,-15,103},
{-5,-15,104},
{-5,-15,104},
{-5,-15,105},
{-5,-15,106},
{-5,-15,107},
{-5,-15,107},
{-5,-15,108},
{-5,-16,108},
{-6,-16,109},
{-6,-16,110},
{-6,-16,110},
{-6,-16,111},
{-6,-16,112},
{-6,-16,113},
{-6,-16,113},
{-6,-16,114},
{-6,-16,115},
{-6,-16,116},
{-6,-16,116},
{-6,-16,117},
{-6,-16,118},
{-7,-16,119},
{-7,-16,120},
{-7,-16,121},
{-7,-16,122},
{-7,-16,122},
{-7,-16,123},
};



