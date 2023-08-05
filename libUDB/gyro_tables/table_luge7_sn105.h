

#ifndef TABLE_LUGE7_SN105_H
#define	TABLE_LUGE7_SN105_H

// used in LUGE7_SN105 partition size 64

#define STEP_SIZE 64

int16_t residual_offset[] = { 0 , 0 , 0 } ;

#define TABLE_ORIGIN  (-14374 + 256  )

struct gyro_offset_table_entry gyro_offset_table[] = {
{	2799	,	-1132	,	-1603	},
{	2790	,	-1131	,	-1594	},
{	2795	,	-1137	,	-1594	},
{	2788	,	-1138	,	-1588	},
{	2787	,	-1140	,	-1586	},
{	2788	,	-1142	,	-1584	},
{	2789	,	-1147	,	-1581	},
{	2794	,	-1152	,	-1581	},
{	2787	,	-1153	,	-1577	},
{	2794	,	-1158	,	-1578	},
{	2798	,	-1162	,	-1579	},
{	2786	,	-1158	,	-1571	},
{	2789	,	-1161	,	-1572	},
{	2789	,	-1164	,	-1571	},
{	2795	,	-1170	,	-1573	},
{	2793	,	-1171	,	-1571	},
{	2784	,	-1170	,	-1566	},
{	2784	,	-1171	,	-1564	},
{	2781	,	-1173	,	-1562	},
{	2781	,	-1177	,	-1560	},
{	2786	,	-1183	,	-1560	},
{	2779	,	-1183	,	-1557	},
{	2773	,	-1183	,	-1553	},
{	2767	,	-1183	,	-1549	},
{	2775	,	-1190	,	-1552	},
{	2778	,	-1195	,	-1550	},
{	2772	,	-1196	,	-1545	},
{	2770	,	-1197	,	-1542	},
{	2763	,	-1196	,	-1538	},
{	2764	,	-1199	,	-1537	},
{	2762	,	-1201	,	-1534	},
{	2761	,	-1204	,	-1531	},
{	2760	,	-1207	,	-1530	},
{	2758	,	-1208	,	-1527	},
{	2757	,	-1211	,	-1527	},
{	2762	,	-1216	,	-1529	},
{	2756	,	-1218	,	-1526	},
{	2762	,	-1225	,	-1529	},
{	2761	,	-1230	,	-1530	},
{	2762	,	-1235	,	-1532	},
{	2761	,	-1239	,	-1531	},
{	2769	,	-1244	,	-1534	},
{	2769	,	-1248	,	-1535	},
{	2766	,	-1249	,	-1533	},
{	2763	,	-1253	,	-1531	},
{	2767	,	-1258	,	-1533	},
{	2758	,	-1258	,	-1528	},
{	2752	,	-1257	,	-1524	},
{	2751	,	-1260	,	-1522	},
{	2750	,	-1264	,	-1523	},
{	2749	,	-1269	,	-1522	},
{	2746	,	-1272	,	-1518	},
{	2745	,	-1274	,	-1516	},
{	2744	,	-1275	,	-1513	},
{	2739	,	-1275	,	-1509	},
{	2741	,	-1277	,	-1508	},
{	2738	,	-1278	,	-1503	},
{	2737	,	-1279	,	-1501	},
{	2739	,	-1280	,	-1497	},
{	2730	,	-1276	,	-1488	},
{	2720	,	-1273	,	-1481	},
{	2722	,	-1277	,	-1482	},
{	2724	,	-1281	,	-1483	},
{	2724	,	-1284	,	-1480	},
{	2721	,	-1284	,	-1477	},
{	2719	,	-1283	,	-1475	},
{	2722	,	-1288	,	-1475	},
{	2720	,	-1290	,	-1473	},
{	2721	,	-1293	,	-1473	},
{	2724	,	-1297	,	-1473	},
{	2718	,	-1296	,	-1468	},
{	2717	,	-1299	,	-1466	},
{	2711	,	-1299	,	-1463	},
{	2711	,	-1302	,	-1464	},
{	2711	,	-1305	,	-1462	},
{	2705	,	-1303	,	-1460	},
{	2708	,	-1308	,	-1462	},
{	2705	,	-1310	,	-1461	},
{	2698	,	-1310	,	-1459	},
{	2698	,	-1311	,	-1458	},
{	2688	,	-1309	,	-1454	},
{	2694	,	-1314	,	-1457	},
{	2691	,	-1316	,	-1454	},
{	2692	,	-1320	,	-1454	},
{	2694	,	-1324	,	-1454	},
{	2686	,	-1322	,	-1450	},
{	2686	,	-1326	,	-1450	},
{	2685	,	-1328	,	-1448	},
{	2687	,	-1334	,	-1450	},
{	2695	,	-1341	,	-1454	},
{	2695	,	-1345	,	-1454	},
{	2700	,	-1351	,	-1457	},
{	2704	,	-1355	,	-1460	},
{	2694	,	-1353	,	-1457	},
{	2691	,	-1355	,	-1456	},
{	2692	,	-1358	,	-1457	},
{	2692	,	-1363	,	-1459	},
{	2687	,	-1363	,	-1457	},
{	2680	,	-1363	,	-1455	},
{	2675	,	-1364	,	-1454	},
{	2671	,	-1367	,	-1454	},
{	2660	,	-1365	,	-1449	},
{	2658	,	-1368	,	-1451	},
{	2654	,	-1371	,	-1451	},
{	2650	,	-1374	,	-1451	},
{	2647	,	-1373	,	-1449	},
{	2639	,	-1373	,	-1448	},
{	2634	,	-1375	,	-1447	},
{	2629	,	-1376	,	-1444	},
{	2615	,	-1370	,	-1438	},
{	2613	,	-1374	,	-1440	},
{	2614	,	-1379	,	-1439	},
{	2613	,	-1383	,	-1441	},
{	2608	,	-1384	,	-1440	},
{	2607	,	-1391	,	-1443	},
{	2606	,	-1394	,	-1444	},
{	2602	,	-1395	,	-1443	},
{	2595	,	-1395	,	-1442	},
{	2589	,	-1398	,	-1442	},
{	2586	,	-1400	,	-1441	},
{	2578	,	-1399	,	-1440	},
{	2573	,	-1400	,	-1441	},
{	2560	,	-1396	,	-1438	},
{	2544	,	-1390	,	-1432	},
{	2537	,	-1390	,	-1432	},
{	2527	,	-1390	,	-1431	},
{	2517	,	-1388	,	-1430	},
{	2509	,	-1388	,	-1429	},
{	2496	,	-1384	,	-1429	},
{	2489	,	-1386	,	-1431	},
{	2473	,	-1381	,	-1428	},
{	2466	,	-1380	,	-1427	},
{	2458	,	-1379	,	-1427	},
{	2451	,	-1381	,	-1428	},
{	2441	,	-1380	,	-1427	},
{	2426	,	-1376	,	-1425	},
{	2414	,	-1373	,	-1424	},
{	2403	,	-1370	,	-1423	},
{	2383	,	-1361	,	-1416	},
{	2370	,	-1357	,	-1414	},
{	2358	,	-1356	,	-1413	},
{	2343	,	-1351	,	-1413	},
{	2325	,	-1345	,	-1412	},
{	2308	,	-1340	,	-1412	},
{	2298	,	-1339	,	-1414	},
{	2284	,	-1335	,	-1413	},
{	2268	,	-1331	,	-1412	},
{	2259	,	-1333	,	-1417	},
{	2246	,	-1331	,	-1418	},
{	2231	,	-1325	,	-1417	},
{	2219	,	-1324	,	-1419	},
{	2207	,	-1322	,	-1420	},
{	2191	,	-1313	,	-1416	},
{	2179	,	-1310	,	-1415	},
{	2170	,	-1309	,	-1419	},
{	2159	,	-1308	,	-1420	},
{	2145	,	-1302	,	-1419	},
{	2132	,	-1299	,	-1418	},
{	2122	,	-1300	,	-1421	},
{	2110	,	-1297	,	-1419	},
{	2098	,	-1293	,	-1416	},
{	2089	,	-1295	,	-1419	},
{	2077	,	-1291	,	-1417	},
{	2062	,	-1285	,	-1413	},
{	2051	,	-1282	,	-1413	},
{	2039	,	-1278	,	-1410	},
{	2029	,	-1274	,	-1410	},
{	2018	,	-1269	,	-1408	},
{	2008	,	-1268	,	-1410	},
{	1996	,	-1265	,	-1408	},
{	1983	,	-1260	,	-1405	},
{	1974	,	-1260	,	-1406	},
{	1966	,	-1262	,	-1409	},
{	1955	,	-1261	,	-1409	},
{	1947	,	-1264	,	-1413	},
{	1940	,	-1265	,	-1414	},
{	1932	,	-1268	,	-1415	},
{	1921	,	-1264	,	-1413	},
{	1913	,	-1265	,	-1415	},
{	1906	,	-1265	,	-1415	},
{	1896	,	-1265	,	-1416	},
{	1885	,	-1260	,	-1413	},
{	1877	,	-1263	,	-1416	},
{	1865	,	-1258	,	-1411	},
{	1855	,	-1258	,	-1412	},
{	1844	,	-1255	,	-1410	},
{	1833	,	-1254	,	-1410	},
{	1823	,	-1252	,	-1409	},
{	1814	,	-1253	,	-1410	},
{	1803	,	-1252	,	-1409	},
{	1794	,	-1254	,	-1411	},
{	1783	,	-1252	,	-1409	},
{	1775	,	-1256	,	-1412	},
{	1764	,	-1252	,	-1408	},
{	1754	,	-1255	,	-1410	},
{	1744	,	-1256	,	-1410	},
{	1736	,	-1260	,	-1413	},
{	1725	,	-1257	,	-1412	},
{	1715	,	-1260	,	-1413	},
{	1704	,	-1259	,	-1413	},
{	1692	,	-1255	,	-1410	},
{	1681	,	-1252	,	-1409	},
{	1673	,	-1254	,	-1412	},
{	1662	,	-1249	,	-1410	},
{	1652	,	-1246	,	-1409	},
{	1640	,	-1243	,	-1407	},
{	1630	,	-1242	,	-1409	},
{	1620	,	-1241	,	-1410	},
{	1610	,	-1240	,	-1411	},
{	1602	,	-1240	,	-1414	},
{	1594	,	-1240	,	-1416	},
{	1584	,	-1241	,	-1419	},
{	1574	,	-1243	,	-1421	},
{	1566	,	-1247	,	-1426	},
{	1556	,	-1245	,	-1425	},
{	1548	,	-1248	,	-1428	},
{	1538	,	-1242	,	-1424	},
{	1530	,	-1239	,	-1423	},
{	1521	,	-1240	,	-1424	},
{	1511	,	-1241	,	-1426	},
{	1501	,	-1240	,	-1426	},
{	1492	,	-1241	,	-1429	},
{	1482	,	-1238	,	-1428	},
{	1474	,	-1238	,	-1430	},
{	1463	,	-1233	,	-1426	},
{	1455	,	-1232	,	-1426	},
{	1445	,	-1234	,	-1428	},
{	1436	,	-1233	,	-1427	},
{	1427	,	-1233	,	-1427	},
{	1417	,	-1227	,	-1422	},
{	1408	,	-1223	,	-1417	},
{	1398	,	-1220	,	-1414	},
{	1389	,	-1219	,	-1413	},
{	1380	,	-1219	,	-1413	},
{	1369	,	-1222	,	-1416	},
{	1360	,	-1225	,	-1420	},
{	1351	,	-1225	,	-1421	},
{	1340	,	-1221	,	-1417	},
{	1332	,	-1222	,	-1419	},
{	1323	,	-1221	,	-1419	},
{	1313	,	-1224	,	-1422	},
{	1305	,	-1225	,	-1424	},
{	1297	,	-1225	,	-1425	},
{	1289	,	-1222	,	-1423	},
{	1281	,	-1218	,	-1418	},
{	1271	,	-1218	,	-1419	},
{	1264	,	-1219	,	-1420	},
{	1255	,	-1219	,	-1421	},
{	1247	,	-1220	,	-1421	},
{	1240	,	-1217	,	-1420	},
{	1233	,	-1214	,	-1418	},
{	1223	,	-1217	,	-1422	},
{	1213	,	-1219	,	-1425	},
{	1203	,	-1220	,	-1428	},
{	1195	,	-1218	,	-1428	},
{	1188	,	-1215	,	-1427	},
{	1178	,	-1216	,	-1429	},
{	1170	,	-1215	,	-1431	},
{	1161	,	-1214	,	-1430	},
{	1152	,	-1213	,	-1433	},
{	1146	,	-1207	,	-1430	},
{	1139	,	-1202	,	-1426	},
{	1130	,	-1200	,	-1426	},
{	1123	,	-1196	,	-1425	},
{	1113	,	-1197	,	-1427	},
{	1103	,	-1195	,	-1428	},
{	1095	,	-1190	,	-1427	},
{	1085	,	-1188	,	-1427	},
{	1076	,	-1185	,	-1425	},
{	1066	,	-1182	,	-1424	},
{	1055	,	-1182	,	-1425	},
{	1044	,	-1181	,	-1425	},
{	1033	,	-1180	,	-1426	},
{	1020	,	-1178	,	-1429	},
{	1012	,	-1172	,	-1425	},
{	1000	,	-1173	,	-1428	},
{	989	,	-1172	,	-1430	},
{	980	,	-1170	,	-1431	},
{	970	,	-1169	,	-1432	},
{	959	,	-1168	,	-1434	},
{	951	,	-1164	,	-1433	},
{	944	,	-1160	,	-1432	},
{	939	,	-1155	,	-1428	},
{	930	,	-1155	,	-1429	},
{	920	,	-1153	,	-1430	},
{	909	,	-1152	,	-1431	},
{	897	,	-1153	,	-1435	},
{	889	,	-1150	,	-1435	},
{	881	,	-1147	,	-1434	},
{	869	,	-1147	,	-1437	},
{	860	,	-1146	,	-1438	},
{	848	,	-1144	,	-1440	},
{	839	,	-1143	,	-1441	},
{	832	,	-1138	,	-1439	},
{	824	,	-1134	,	-1438	},
{	814	,	-1133	,	-1438	},
{	801	,	-1133	,	-1440	},
{	792	,	-1131	,	-1440	},
{	781	,	-1129	,	-1441	},
{	771	,	-1127	,	-1442	},
{	759	,	-1129	,	-1445	},
{	748	,	-1127	,	-1444	},
{	734	,	-1129	,	-1447	},
{	720	,	-1129	,	-1449	},
{	713	,	-1124	,	-1446	},
{	702	,	-1122	,	-1448	},
{	691	,	-1120	,	-1448	},
{	682	,	-1116	,	-1447	},
{	670	,	-1114	,	-1449	},
{	660	,	-1111	,	-1448	},
{	652	,	-1108	,	-1448	},
{	642	,	-1105	,	-1449	},
{	635	,	-1101	,	-1448	},
{	624	,	-1101	,	-1450	},
{	615	,	-1099	,	-1451	},
{	602	,	-1099	,	-1452	},
{	597	,	-1096	,	-1450	},
{	582	,	-1098	,	-1454	},
{	576	,	-1095	,	-1452	},
{	560	,	-1096	,	-1456	},
{	547	,	-1095	,	-1456	},
{	536	,	-1094	,	-1458	},
{	527	,	-1092	,	-1457	},
{	520	,	-1088	,	-1454	},
{	514	,	-1085	,	-1452	},
{	500	,	-1085	,	-1454	},
{	489	,	-1084	,	-1453	},
{	475	,	-1084	,	-1454	},
{	470	,	-1081	,	-1451	},
{	467	,	-1075	,	-1447	},
{	462	,	-1071	,	-1444	},
{	448	,	-1072	,	-1445	},
{	433	,	-1074	,	-1448	},
{	424	,	-1072	,	-1446	},
{	411	,	-1071	,	-1448	},
{	405	,	-1068	,	-1446	},
{	399	,	-1065	,	-1445	},
{	387	,	-1065	,	-1447	},
{	377	,	-1066	,	-1446	},
{	364	,	-1067	,	-1448	},
{	358	,	-1064	,	-1445	},
{	350	,	-1062	,	-1444	},
{	337	,	-1063	,	-1446	},
{	327	,	-1064	,	-1446	},
{	313	,	-1065	,	-1449	},
{	302	,	-1066	,	-1451	},
{	290	,	-1068	,	-1453	},
{	280	,	-1068	,	-1454	},
{	273	,	-1067	,	-1454	},
{	257	,	-1070	,	-1459	},
{	252	,	-1069	,	-1458	},
{	238	,	-1071	,	-1460	},
{	230	,	-1069	,	-1459	},
{	221	,	-1069	,	-1458	},
{	212	,	-1069	,	-1457	},
{	204	,	-1067	,	-1455	},
{	189	,	-1069	,	-1458	},
{	179	,	-1070	,	-1459	},
{	174	,	-1067	,	-1456	},
{	160	,	-1070	,	-1458	},
{	154	,	-1069	,	-1457	},
{	147	,	-1068	,	-1455	},
{	141	,	-1067	,	-1453	},
{	132	,	-1068	,	-1453	},
{	124	,	-1069	,	-1451	},
{	121	,	-1068	,	-1449	},
{	103	,	-1072	,	-1451	},
{	84	,	-1077	,	-1453	},
{	71	,	-1078	,	-1453	},
{	59	,	-1080	,	-1454	},
{	47	,	-1083	,	-1455	},
{	40	,	-1084	,	-1454	},
{	32	,	-1085	,	-1452	},
{	19	,	-1087	,	-1453	},
{	-2	,	-1093	,	-1455	},
{	-6	,	-1094	,	-1453	},
{	-13	,	-1096	,	-1452	},
{	-18	,	-1098	,	-1451	},
{	-32	,	-1104	,	-1451	},
{	-47	,	-1108	,	-1453	},
{	-65	,	-1116	,	-1457	},
{	-78	,	-1121	,	-1459	},
{	-92	,	-1128	,	-1461	},
{	-103	,	-1133	,	-1463	},
{	-115	,	-1139	,	-1464	},
{	-118	,	-1142	,	-1462	},
{	-131	,	-1148	,	-1464	},
{	-137	,	-1152	,	-1463	},
{	-142	,	-1156	,	-1462	},
{	-143	,	-1159	,	-1460	},
{	-160	,	-1169	,	-1464	},
{	-171	,	-1176	,	-1465	},
{	-177	,	-1182	,	-1465	},
{	-178	,	-1187	,	-1463	},
{	-189	,	-1195	,	-1465	},
{	-186	,	-1199	,	-1463	}
};

#endif	/* TABLE_LUGE7_SN105_H */

