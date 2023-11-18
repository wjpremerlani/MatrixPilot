

#ifndef TABLE_LUGE7_SN144_H
#define	TABLE_LUGE7_SN144_H

// used in LUGE7_SN144 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14943 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-647	,	-950	,	-229	},
{	-643	,	-950	,	-229	},
{	-639	,	-950	,	-227	},
{	-635	,	-950	,	-226	},
{	-631	,	-950	,	-224	},
{	-627	,	-950	,	-224	},
{	-624	,	-950	,	-222	},
{	-621	,	-952	,	-220	},
{	-619	,	-954	,	-219	},
{	-614	,	-961	,	-216	},
{	-605	,	-961	,	-211	},
{	-600	,	-964	,	-208	},
{	-592	,	-964	,	-204	},
{	-587	,	-966	,	-201	},
{	-579	,	-966	,	-198	},
{	-572	,	-970	,	-196	},
{	-565	,	-971	,	-192	},
{	-558	,	-974	,	-188	},
{	-552	,	-977	,	-184	},
{	-547	,	-982	,	-180	},
{	-541	,	-986	,	-177	},
{	-536	,	-991	,	-173	},
{	-531	,	-993	,	-169	},
{	-525	,	-998	,	-166	},
{	-519	,	-1001	,	-164	},
{	-513	,	-1004	,	-160	},
{	-507	,	-1006	,	-157	},
{	-501	,	-1011	,	-155	},
{	-494	,	-1014	,	-151	},
{	-489	,	-1017	,	-149	},
{	-481	,	-1020	,	-146	},
{	-475	,	-1021	,	-141	},
{	-468	,	-1024	,	-139	},
{	-462	,	-1027	,	-137	},
{	-455	,	-1029	,	-133	},
{	-450	,	-1033	,	-131	},
{	-442	,	-1034	,	-127	},
{	-435	,	-1036	,	-125	},
{	-427	,	-1038	,	-122	},
{	-420	,	-1044	,	-119	},
{	-414	,	-1048	,	-116	},
{	-406	,	-1052	,	-111	},
{	-399	,	-1055	,	-108	},
{	-395	,	-1062	,	-105	},
{	-389	,	-1065	,	-102	},
{	-383	,	-1071	,	-100	},
{	-376	,	-1078	,	-97	},
{	-370	,	-1082	,	-94	},
{	-365	,	-1089	,	-92	},
{	-358	,	-1096	,	-89	},
{	-351	,	-1101	,	-86	},
{	-346	,	-1108	,	-84	},
{	-340	,	-1114	,	-81	},
{	-333	,	-1119	,	-78	},
{	-328	,	-1126	,	-74	},
{	-323	,	-1134	,	-71	},
{	-317	,	-1138	,	-68	},
{	-310	,	-1143	,	-65	},
{	-304	,	-1146	,	-62	},
{	-298	,	-1152	,	-59	},
{	-292	,	-1158	,	-57	},
{	-285	,	-1161	,	-53	},
{	-280	,	-1167	,	-50	},
{	-274	,	-1170	,	-46	},
{	-268	,	-1176	,	-43	},
{	-263	,	-1180	,	-39	},
{	-256	,	-1181	,	-35	},
{	-251	,	-1190	,	-32	},
{	-245	,	-1194	,	-28	},
{	-239	,	-1197	,	-25	},
{	-233	,	-1203	,	-23	},
{	-227	,	-1207	,	-21	},
{	-221	,	-1209	,	-18	},
{	-216	,	-1214	,	-15	},
{	-211	,	-1222	,	-12	},
{	-206	,	-1227	,	-10	},
{	-201	,	-1235	,	-7	},
{	-195	,	-1237	,	-4	},
{	-191	,	-1246	,	-2	},
{	-185	,	-1252	,	0	},
{	-180	,	-1260	,	4	},
{	-174	,	-1264	,	6	},
{	-169	,	-1271	,	8	},
{	-165	,	-1276	,	9	},
{	-159	,	-1279	,	13	},
{	-155	,	-1285	,	15	},
{	-150	,	-1291	,	18	},
{	-145	,	-1295	,	21	},
{	-140	,	-1300	,	23	},
{	-136	,	-1305	,	26	},
{	-131	,	-1310	,	28	},
{	-126	,	-1313	,	30	},
{	-123	,	-1318	,	32	},
{	-119	,	-1319	,	35	},
{	-115	,	-1325	,	37	},
{	-112	,	-1328	,	40	},
{	-109	,	-1328	,	43	},
{	-106	,	-1331	,	45	},
{	-102	,	-1336	,	48	},
{	-100	,	-1341	,	51	},
{	-98	,	-1346	,	54	},
{	-97	,	-1353	,	55	},
{	-95	,	-1355	,	57	},
{	-95	,	-1362	,	58	},
{	-97	,	-1368	,	59	},
{	-97	,	-1372	,	61	},
{	-97	,	-1376	,	63	},
{	-97	,	-1380	,	65	},
{	-98	,	-1384	,	67	},
{	-99	,	-1390	,	69	},
{	-99	,	-1394	,	70	},
{	-100	,	-1400	,	72	},
{	-100	,	-1403	,	73	},
{	-102	,	-1412	,	75	},
{	-104	,	-1415	,	77	},
{	-106	,	-1419	,	78	},
{	-107	,	-1421	,	80	},
{	-110	,	-1428	,	81	},
{	-111	,	-1431	,	84	},
{	-114	,	-1437	,	87	},
{	-115	,	-1440	,	90	},
{	-117	,	-1441	,	92	},
{	-119	,	-1447	,	94	},
{	-122	,	-1453	,	96	},
{	-124	,	-1457	,	97	},
{	-127	,	-1461	,	100	},
{	-131	,	-1463	,	102	},
{	-136	,	-1473	,	105	},
{	-140	,	-1471	,	106	},
{	-146	,	-1477	,	108	},
{	-150	,	-1478	,	109	},
{	-155	,	-1478	,	110	},
{	-161	,	-1482	,	112	},
{	-168	,	-1487	,	113	},
{	-174	,	-1487	,	113	},
{	-182	,	-1489	,	115	},
{	-188	,	-1492	,	116	},
{	-196	,	-1494	,	116	},
{	-204	,	-1496	,	118	},
{	-212	,	-1495	,	119	},
{	-221	,	-1495	,	121	},
{	-230	,	-1495	,	122	},
{	-239	,	-1494	,	123	},
{	-249	,	-1495	,	124	},
{	-258	,	-1489	,	124	},
{	-268	,	-1493	,	126	},
{	-276	,	-1490	,	127	},
{	-287	,	-1487	,	127	},
{	-298	,	-1492	,	128	},
{	-307	,	-1491	,	129	},
{	-317	,	-1488	,	130	},
{	-327	,	-1487	,	130	},
{	-337	,	-1484	,	131	},
{	-346	,	-1480	,	131	},
{	-356	,	-1481	,	132	},
{	-365	,	-1482	,	132	},
{	-375	,	-1484	,	133	},
{	-384	,	-1480	,	133	},
{	-393	,	-1482	,	133	},
{	-401	,	-1481	,	134	},
{	-411	,	-1480	,	134	},
{	-419	,	-1480	,	135	},
{	-427	,	-1480	,	136	},
{	-437	,	-1482	,	136	},
{	-445	,	-1483	,	137	},
{	-453	,	-1480	,	138	},
{	-460	,	-1478	,	138	},
{	-468	,	-1479	,	139	},
{	-477	,	-1483	,	140	},
{	-484	,	-1485	,	141	},
{	-492	,	-1486	,	142	},
{	-499	,	-1486	,	143	},
{	-505	,	-1484	,	143	},
{	-512	,	-1481	,	144	},
{	-519	,	-1485	,	146	},
{	-525	,	-1485	,	147	},
{	-532	,	-1486	,	148	},
{	-537	,	-1484	,	148	},
{	-543	,	-1486	,	149	},
{	-549	,	-1486	,	149	},
{	-556	,	-1487	,	150	},
{	-562	,	-1486	,	150	},
{	-567	,	-1487	,	151	},
{	-573	,	-1491	,	153	},
{	-578	,	-1490	,	154	},
{	-583	,	-1490	,	156	},
{	-588	,	-1491	,	157	},
{	-594	,	-1491	,	158	},
{	-598	,	-1488	,	158	},
{	-605	,	-1492	,	160	},
{	-610	,	-1495	,	161	},
{	-614	,	-1491	,	161	},
{	-620	,	-1492	,	162	},
{	-627	,	-1498	,	164	},
{	-632	,	-1498	,	165	},
{	-639	,	-1501	,	167	},
{	-644	,	-1501	,	169	},
{	-649	,	-1502	,	170	},
{	-655	,	-1505	,	171	},
{	-662	,	-1507	,	172	},
{	-667	,	-1506	,	173	},
{	-673	,	-1508	,	174	},
{	-677	,	-1505	,	174	},
{	-684	,	-1509	,	175	},
{	-692	,	-1513	,	176	},
{	-699	,	-1518	,	178	},
{	-705	,	-1521	,	180	},
{	-711	,	-1520	,	180	},
{	-719	,	-1526	,	181	},
{	-725	,	-1528	,	183	},
{	-729	,	-1526	,	183	},
{	-734	,	-1525	,	183	},
{	-740	,	-1527	,	184	},
{	-747	,	-1530	,	185	},
{	-752	,	-1527	,	186	},
{	-759	,	-1530	,	187	},
{	-763	,	-1527	,	187	},
{	-771	,	-1532	,	188	},
{	-777	,	-1532	,	189	},
{	-784	,	-1535	,	190	},
{	-787	,	-1530	,	190	},
{	-793	,	-1529	,	190	},
{	-799	,	-1531	,	190	},
{	-804	,	-1527	,	189	},
{	-811	,	-1531	,	190	},
{	-816	,	-1528	,	190	},
{	-820	,	-1525	,	190	},
{	-827	,	-1527	,	190	},
{	-835	,	-1532	,	192	},
{	-840	,	-1529	,	192	},
{	-847	,	-1532	,	192	},
{	-856	,	-1535	,	193	},
{	-861	,	-1534	,	193	},
{	-868	,	-1537	,	194	},
{	-874	,	-1539	,	195	},
{	-879	,	-1538	,	196	},
{	-884	,	-1536	,	196	},
{	-893	,	-1540	,	197	},
{	-899	,	-1540	,	198	},
{	-905	,	-1538	,	198	},
{	-912	,	-1540	,	200	},
{	-918	,	-1539	,	200	},
{	-926	,	-1541	,	201	},
{	-936	,	-1545	,	203	},
{	-943	,	-1546	,	203	},
{	-949	,	-1545	,	204	},
{	-956	,	-1547	,	204	},
{	-960	,	-1542	,	205	},
{	-965	,	-1541	,	205	},
{	-971	,	-1540	,	205	},
{	-978	,	-1540	,	206	},
{	-984	,	-1538	,	206	},
{	-991	,	-1540	,	207	},
{	-998	,	-1540	,	207	},
{	-1004	,	-1540	,	208	},
{	-1014	,	-1544	,	209	},
{	-1021	,	-1544	,	210	},
{	-1026	,	-1543	,	211	},
{	-1037	,	-1549	,	213	},
{	-1044	,	-1550	,	214	},
{	-1050	,	-1551	,	215	},
{	-1057	,	-1552	,	216	},
{	-1067	,	-1556	,	217	},
{	-1072	,	-1556	,	217	},
{	-1083	,	-1563	,	219	},
{	-1088	,	-1561	,	220	},
{	-1098	,	-1568	,	221	},
{	-1104	,	-1568	,	221	},
{	-1115	,	-1575	,	223	},
{	-1123	,	-1578	,	223	},
{	-1133	,	-1582	,	224	},
{	-1140	,	-1582	,	225	},
{	-1144	,	-1580	,	225	},
{	-1150	,	-1580	,	225	},
{	-1159	,	-1585	,	225	},
{	-1163	,	-1581	,	225	},
{	-1169	,	-1581	,	225	},
{	-1174	,	-1579	,	225	},
{	-1181	,	-1579	,	225	},
{	-1187	,	-1577	,	225	},
{	-1195	,	-1579	,	225	},
{	-1199	,	-1575	,	225	},
{	-1209	,	-1579	,	226	},
{	-1211	,	-1573	,	226	},
{	-1220	,	-1575	,	226	},
{	-1223	,	-1569	,	226	},
{	-1230	,	-1568	,	226	},
{	-1236	,	-1568	,	226	},
{	-1241	,	-1566	,	226	},
{	-1251	,	-1568	,	227	},
{	-1262	,	-1574	,	229	},
{	-1266	,	-1570	,	228	},
{	-1273	,	-1569	,	229	},
{	-1281	,	-1571	,	229	},
{	-1292	,	-1575	,	230	},
{	-1296	,	-1572	,	230	},
{	-1305	,	-1574	,	231	},
{	-1311	,	-1572	,	231	},
{	-1321	,	-1577	,	231	},
{	-1328	,	-1576	,	231	},
{	-1338	,	-1579	,	231	},
{	-1345	,	-1578	,	231	},
{	-1353	,	-1578	,	232	},
{	-1361	,	-1580	,	232	},
{	-1372	,	-1583	,	233	},
{	-1381	,	-1585	,	233	},
{	-1385	,	-1582	,	233	},
{	-1392	,	-1581	,	233	},
{	-1402	,	-1584	,	233	},
{	-1410	,	-1585	,	233	},
{	-1417	,	-1584	,	233	},
{	-1425	,	-1585	,	233	},
{	-1432	,	-1586	,	234	},
{	-1437	,	-1585	,	233	},
{	-1448	,	-1590	,	235	},
{	-1454	,	-1589	,	236	},
{	-1463	,	-1591	,	237	},
{	-1472	,	-1593	,	238	},
{	-1479	,	-1595	,	239	},
{	-1486	,	-1595	,	239	},
{	-1493	,	-1596	,	240	},
{	-1498	,	-1596	,	241	},
{	-1506	,	-1599	,	242	},
{	-1515	,	-1602	,	244	},
{	-1520	,	-1600	,	244	},
{	-1526	,	-1600	,	245	},
{	-1535	,	-1603	,	247	},
{	-1543	,	-1606	,	248	},
{	-1546	,	-1603	,	249	},
{	-1555	,	-1605	,	250	},
{	-1561	,	-1605	,	251	},
{	-1569	,	-1605	,	252	},
{	-1573	,	-1603	,	252	},
{	-1578	,	-1601	,	252	},
{	-1583	,	-1600	,	253	},
{	-1586	,	-1599	,	253	},
{	-1590	,	-1601	,	254	},
{	-1593	,	-1600	,	255	},
{	-1595	,	-1598	,	255	},
{	-1598	,	-1599	,	255	},
{	-1600	,	-1597	,	255	},
{	-1603	,	-1596	,	256	},
{	-1608	,	-1598	,	257	}
};

#endif	/* TABLE_LUGE7_SN144_H */
