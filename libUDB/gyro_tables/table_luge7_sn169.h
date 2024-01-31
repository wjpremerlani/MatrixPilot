

#ifndef TABLE_LUGE7_SN169_H
#define	TABLE_LUGE7_SN169_H

// used in LUGE7_SN169 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14931 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-153	,	-1567	,	1223	},
{	-148	,	-1572	,	1227	},
{	-141	,	-1575	,	1227	},
{	-134	,	-1574	,	1224	},
{	-128	,	-1569	,	1219	},
{	-123	,	-1573	,	1221	},
{	-117	,	-1571	,	1219	},
{	-112	,	-1569	,	1216	},
{	-108	,	-1567	,	1213	},
{	-99	,	-1571	,	1211	},
{	-89	,	-1570	,	1207	},
{	-79	,	-1571	,	1204	},
{	-70	,	-1568	,	1201	},
{	-61	,	-1566	,	1196	},
{	-51	,	-1569	,	1196	},
{	-42	,	-1564	,	1190	},
{	-31	,	-1563	,	1186	},
{	-21	,	-1566	,	1187	},
{	-13	,	-1560	,	1179	},
{	-5	,	-1557	,	1175	},
{	2	,	-1557	,	1173	},
{	9	,	-1556	,	1169	},
{	17	,	-1552	,	1164	},
{	25	,	-1554	,	1163	},
{	32	,	-1550	,	1159	},
{	41	,	-1551	,	1157	},
{	49	,	-1548	,	1153	},
{	57	,	-1547	,	1151	},
{	65	,	-1545	,	1148	},
{	74	,	-1544	,	1145	},
{	84	,	-1545	,	1145	},
{	93	,	-1543	,	1140	},
{	103	,	-1543	,	1138	},
{	110	,	-1541	,	1135	},
{	119	,	-1536	,	1128	},
{	127	,	-1538	,	1127	},
{	135	,	-1537	,	1122	},
{	144	,	-1536	,	1118	},
{	155	,	-1542	,	1119	},
{	163	,	-1540	,	1114	},
{	171	,	-1540	,	1109	},
{	180	,	-1546	,	1108	},
{	188	,	-1544	,	1104	},
{	195	,	-1548	,	1101	},
{	204	,	-1549	,	1097	},
{	212	,	-1550	,	1093	},
{	220	,	-1554	,	1090	},
{	227	,	-1552	,	1084	},
{	234	,	-1555	,	1081	},
{	242	,	-1558	,	1079	},
{	249	,	-1559	,	1075	},
{	257	,	-1564	,	1072	},
{	267	,	-1567	,	1069	},
{	276	,	-1571	,	1067	},
{	283	,	-1572	,	1062	},
{	290	,	-1574	,	1058	},
{	296	,	-1577	,	1056	},
{	304	,	-1580	,	1054	},
{	311	,	-1577	,	1047	},
{	319	,	-1584	,	1046	},
{	327	,	-1585	,	1041	},
{	335	,	-1589	,	1038	},
{	343	,	-1594	,	1037	},
{	350	,	-1593	,	1031	},
{	358	,	-1598	,	1030	},
{	366	,	-1599	,	1026	},
{	371	,	-1600	,	1020	},
{	379	,	-1604	,	1016	},
{	386	,	-1608	,	1015	},
{	393	,	-1613	,	1013	},
{	399	,	-1615	,	1010	},
{	407	,	-1621	,	1009	},
{	415	,	-1620	,	1004	},
{	424	,	-1625	,	1001	},
{	432	,	-1627	,	998	},
{	440	,	-1634	,	997	},
{	448	,	-1638	,	996	},
{	456	,	-1642	,	994	},
{	462	,	-1642	,	989	},
{	468	,	-1647	,	986	},
{	474	,	-1651	,	984	},
{	482	,	-1657	,	984	},
{	490	,	-1660	,	980	},
{	498	,	-1663	,	978	},
{	507	,	-1668	,	977	},
{	515	,	-1669	,	974	},
{	523	,	-1671	,	970	},
{	529	,	-1672	,	966	},
{	536	,	-1671	,	962	},
{	543	,	-1676	,	960	},
{	550	,	-1679	,	959	},
{	558	,	-1682	,	956	},
{	566	,	-1686	,	953	},
{	572	,	-1684	,	948	},
{	581	,	-1692	,	948	},
{	589	,	-1697	,	947	},
{	597	,	-1695	,	942	},
{	605	,	-1701	,	942	},
{	612	,	-1700	,	938	},
{	619	,	-1704	,	938	},
{	626	,	-1708	,	937	},
{	632	,	-1709	,	936	},
{	638	,	-1714	,	934	},
{	643	,	-1714	,	932	},
{	649	,	-1718	,	929	},
{	654	,	-1720	,	928	},
{	659	,	-1723	,	926	},
{	664	,	-1725	,	923	},
{	668	,	-1726	,	920	},
{	671	,	-1727	,	917	},
{	676	,	-1730	,	915	},
{	676	,	-1727	,	910	},
{	680	,	-1732	,	909	},
{	682	,	-1734	,	908	},
{	684	,	-1733	,	904	},
{	684	,	-1733	,	901	},
{	686	,	-1736	,	899	},
{	686	,	-1735	,	895	},
{	688	,	-1736	,	890	},
{	687	,	-1734	,	887	},
{	689	,	-1734	,	885	},
{	689	,	-1734	,	882	},
{	692	,	-1739	,	881	},
{	693	,	-1741	,	878	},
{	693	,	-1739	,	873	},
{	695	,	-1741	,	872	},
{	694	,	-1741	,	870	},
{	694	,	-1742	,	867	},
{	694	,	-1744	,	865	},
{	691	,	-1737	,	859	},
{	693	,	-1740	,	856	},
{	690	,	-1736	,	852	},
{	690	,	-1737	,	849	},
{	687	,	-1734	,	845	},
{	687	,	-1737	,	844	},
{	683	,	-1735	,	841	},
{	680	,	-1733	,	838	},
{	676	,	-1734	,	836	},
{	674	,	-1734	,	834	},
{	669	,	-1732	,	830	},
{	665	,	-1731	,	828	},
{	661	,	-1730	,	827	},
{	656	,	-1726	,	823	},
{	651	,	-1727	,	821	},
{	646	,	-1724	,	818	},
{	641	,	-1722	,	815	},
{	635	,	-1720	,	813	},
{	628	,	-1717	,	811	},
{	622	,	-1716	,	809	},
{	615	,	-1712	,	806	},
{	611	,	-1714	,	805	},
{	603	,	-1705	,	800	},
{	598	,	-1706	,	799	},
{	592	,	-1702	,	795	},
{	585	,	-1697	,	791	},
{	577	,	-1696	,	789	},
{	570	,	-1688	,	785	},
{	561	,	-1681	,	782	},
{	553	,	-1678	,	780	},
{	545	,	-1674	,	779	},
{	535	,	-1666	,	775	},
{	527	,	-1659	,	772	},
{	517	,	-1651	,	768	},
{	510	,	-1650	,	768	},
{	502	,	-1644	,	765	},
{	496	,	-1640	,	762	},
{	490	,	-1638	,	761	},
{	478	,	-1626	,	757	},
{	473	,	-1626	,	758	},
{	463	,	-1616	,	753	},
{	457	,	-1612	,	752	},
{	451	,	-1607	,	749	},
{	445	,	-1600	,	746	},
{	438	,	-1593	,	743	},
{	433	,	-1591	,	742	},
{	427	,	-1585	,	739	},
{	422	,	-1579	,	735	},
{	418	,	-1575	,	733	},
{	414	,	-1573	,	731	},
{	410	,	-1570	,	728	},
{	407	,	-1568	,	726	},
{	402	,	-1562	,	721	},
{	397	,	-1559	,	720	},
{	392	,	-1556	,	718	},
{	390	,	-1555	,	716	},
{	384	,	-1548	,	711	},
{	380	,	-1544	,	709	},
{	376	,	-1541	,	706	},
{	371	,	-1538	,	704	},
{	366	,	-1534	,	701	},
{	364	,	-1536	,	700	},
{	358	,	-1530	,	696	},
{	355	,	-1524	,	691	},
{	352	,	-1525	,	690	},
{	348	,	-1520	,	687	},
{	344	,	-1516	,	684	},
{	342	,	-1515	,	683	},
{	337	,	-1505	,	677	},
{	334	,	-1505	,	676	},
{	330	,	-1503	,	674	},
{	325	,	-1495	,	668	},
{	322	,	-1493	,	665	},
{	318	,	-1492	,	663	},
{	314	,	-1490	,	661	},
{	309	,	-1486	,	658	},
{	305	,	-1484	,	655	},
{	302	,	-1480	,	652	},
{	297	,	-1472	,	646	},
{	295	,	-1472	,	644	},
{	290	,	-1470	,	643	},
{	286	,	-1467	,	639	},
{	281	,	-1463	,	635	},
{	277	,	-1462	,	633	},
{	272	,	-1456	,	628	},
{	269	,	-1459	,	628	},
{	265	,	-1453	,	623	},
{	261	,	-1447	,	617	},
{	258	,	-1446	,	615	},
{	255	,	-1442	,	611	},
{	253	,	-1438	,	606	},
{	251	,	-1433	,	600	},
{	250	,	-1431	,	597	},
{	247	,	-1424	,	592	},
{	243	,	-1420	,	588	},
{	241	,	-1418	,	586	},
{	236	,	-1412	,	582	},
{	234	,	-1409	,	579	},
{	232	,	-1402	,	575	},
{	230	,	-1399	,	572	},
{	227	,	-1393	,	567	},
{	226	,	-1393	,	565	},
{	223	,	-1383	,	559	},
{	220	,	-1380	,	556	},
{	219	,	-1378	,	554	},
{	216	,	-1370	,	549	},
{	212	,	-1364	,	545	},
{	209	,	-1358	,	541	},
{	205	,	-1351	,	537	},
{	201	,	-1348	,	535	},
{	198	,	-1345	,	532	},
{	195	,	-1343	,	530	},
{	191	,	-1337	,	525	},
{	188	,	-1332	,	522	},
{	184	,	-1327	,	517	},
{	179	,	-1323	,	515	},
{	175	,	-1316	,	510	},
{	170	,	-1309	,	507	},
{	166	,	-1302	,	504	},
{	163	,	-1299	,	502	},
{	159	,	-1295	,	501	},
{	155	,	-1286	,	496	},
{	151	,	-1284	,	494	},
{	147	,	-1279	,	491	},
{	144	,	-1278	,	490	},
{	141	,	-1272	,	487	},
{	138	,	-1266	,	483	},
{	135	,	-1262	,	480	},
{	132	,	-1256	,	476	},
{	130	,	-1254	,	473	},
{	128	,	-1248	,	468	},
{	125	,	-1244	,	465	},
{	122	,	-1238	,	461	},
{	119	,	-1234	,	458	},
{	117	,	-1232	,	456	},
{	113	,	-1227	,	452	},
{	110	,	-1221	,	448	},
{	108	,	-1216	,	444	},
{	105	,	-1216	,	442	},
{	102	,	-1210	,	438	},
{	101	,	-1207	,	435	},
{	99	,	-1203	,	431	},
{	96	,	-1204	,	428	},
{	93	,	-1202	,	425	},
{	90	,	-1197	,	422	},
{	87	,	-1194	,	420	},
{	85	,	-1190	,	415	},
{	80	,	-1186	,	413	},
{	76	,	-1180	,	409	},
{	73	,	-1180	,	406	},
{	70	,	-1178	,	402	},
{	67	,	-1174	,	399	},
{	64	,	-1169	,	395	},
{	61	,	-1165	,	391	},
{	58	,	-1161	,	387	},
{	55	,	-1156	,	383	},
{	51	,	-1152	,	379	},
{	47	,	-1145	,	374	},
{	42	,	-1140	,	370	},
{	38	,	-1134	,	366	},
{	34	,	-1127	,	361	},
{	31	,	-1124	,	358	},
{	28	,	-1118	,	353	},
{	24	,	-1112	,	349	},
{	21	,	-1107	,	345	},
{	18	,	-1105	,	342	},
{	16	,	-1099	,	338	},
{	13	,	-1095	,	335	},
{	10	,	-1087	,	330	},
{	6	,	-1084	,	327	},
{	3	,	-1080	,	324	},
{	1	,	-1074	,	319	},
{	-2	,	-1066	,	314	},
{	-5	,	-1061	,	311	},
{	-8	,	-1060	,	308	},
{	-12	,	-1054	,	304	},
{	-15	,	-1049	,	301	},
{	-18	,	-1044	,	298	},
{	-22	,	-1038	,	293	},
{	-26	,	-1032	,	290	},
{	-30	,	-1025	,	287	},
{	-35	,	-1023	,	284	},
{	-36	,	-1018	,	282	},
{	-38	,	-1014	,	280	},
{	-41	,	-1009	,	277	},
{	-43	,	-1009	,	276	},
{	-44	,	-1005	,	273	},
{	-46	,	-1002	,	272	},
{	-50	,	-1000	,	271	},
{	-54	,	-1000	,	271	}
};

#endif	/* TABLE_LUGE7_SN169_H */
