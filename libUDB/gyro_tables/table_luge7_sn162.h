

#ifndef TABLE_LUGE7_SN162_H
#define	TABLE_LUGE7_SN162_H

// used in LUGE7_SN162 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14678 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	1817	,	892	,	-543	},
{	1807	,	887	,	-538	},
{	1804	,	887	,	-535	},
{	1805	,	886	,	-533	},
{	1804	,	887	,	-530	},
{	1803	,	887	,	-528	},
{	1802	,	889	,	-525	},
{	1801	,	891	,	-524	},
{	1794	,	889	,	-521	},
{	1798	,	893	,	-518	},
{	1790	,	891	,	-511	},
{	1781	,	890	,	-505	},
{	1778	,	891	,	-501	},
{	1769	,	890	,	-494	},
{	1765	,	892	,	-488	},
{	1756	,	890	,	-481	},
{	1751	,	890	,	-476	},
{	1745	,	889	,	-470	},
{	1743	,	891	,	-465	},
{	1738	,	892	,	-460	},
{	1732	,	893	,	-454	},
{	1727	,	893	,	-449	},
{	1718	,	893	,	-443	},
{	1712	,	893	,	-438	},
{	1704	,	891	,	-431	},
{	1702	,	894	,	-428	},
{	1696	,	894	,	-423	},
{	1689	,	895	,	-418	},
{	1684	,	896	,	-413	},
{	1677	,	897	,	-408	},
{	1670	,	898	,	-401	},
{	1664	,	899	,	-397	},
{	1656	,	900	,	-392	},
{	1651	,	902	,	-388	},
{	1643	,	903	,	-382	},
{	1636	,	903	,	-378	},
{	1631	,	906	,	-375	},
{	1624	,	907	,	-371	},
{	1614	,	908	,	-367	},
{	1611	,	911	,	-363	},
{	1605	,	914	,	-359	},
{	1599	,	915	,	-355	},
{	1592	,	916	,	-350	},
{	1580	,	917	,	-346	},
{	1577	,	921	,	-342	},
{	1568	,	922	,	-336	},
{	1559	,	921	,	-331	},
{	1555	,	924	,	-329	},
{	1547	,	925	,	-324	},
{	1541	,	928	,	-321	},
{	1536	,	930	,	-316	},
{	1528	,	931	,	-311	},
{	1526	,	935	,	-307	},
{	1519	,	936	,	-301	},
{	1510	,	939	,	-296	},
{	1503	,	941	,	-290	},
{	1493	,	941	,	-285	},
{	1482	,	940	,	-278	},
{	1477	,	943	,	-274	},
{	1469	,	944	,	-269	},
{	1465	,	948	,	-264	},
{	1455	,	949	,	-258	},
{	1448	,	951	,	-252	},
{	1445	,	956	,	-248	},
{	1436	,	956	,	-242	},
{	1431	,	958	,	-237	},
{	1425	,	959	,	-232	},
{	1418	,	962	,	-228	},
{	1411	,	964	,	-223	},
{	1400	,	964	,	-218	},
{	1392	,	965	,	-214	},
{	1386	,	968	,	-209	},
{	1379	,	969	,	-204	},
{	1373	,	970	,	-200	},
{	1368	,	974	,	-197	},
{	1359	,	975	,	-194	},
{	1354	,	979	,	-189	},
{	1346	,	978	,	-185	},
{	1339	,	978	,	-180	},
{	1332	,	980	,	-176	},
{	1325	,	981	,	-172	},
{	1320	,	985	,	-168	},
{	1312	,	987	,	-164	},
{	1306	,	989	,	-160	},
{	1298	,	989	,	-155	},
{	1292	,	992	,	-152	},
{	1288	,	996	,	-148	},
{	1281	,	998	,	-144	},
{	1276	,	1001	,	-141	},
{	1270	,	1004	,	-139	},
{	1264	,	1007	,	-136	},
{	1260	,	1010	,	-131	},
{	1252	,	1010	,	-127	},
{	1246	,	1014	,	-124	},
{	1241	,	1017	,	-119	},
{	1236	,	1021	,	-115	},
{	1229	,	1022	,	-111	},
{	1223	,	1025	,	-107	},
{	1216	,	1027	,	-104	},
{	1210	,	1031	,	-99	},
{	1203	,	1033	,	-96	},
{	1196	,	1037	,	-93	},
{	1191	,	1043	,	-88	},
{	1183	,	1045	,	-84	},
{	1174	,	1047	,	-80	},
{	1163	,	1046	,	-76	},
{	1156	,	1050	,	-72	},
{	1147	,	1053	,	-67	},
{	1138	,	1054	,	-64	},
{	1132	,	1058	,	-62	},
{	1123	,	1059	,	-57	},
{	1116	,	1062	,	-54	},
{	1107	,	1064	,	-52	},
{	1101	,	1068	,	-50	},
{	1092	,	1070	,	-47	},
{	1083	,	1071	,	-44	},
{	1074	,	1072	,	-41	},
{	1065	,	1073	,	-39	},
{	1057	,	1078	,	-37	},
{	1046	,	1077	,	-34	},
{	1039	,	1081	,	-31	},
{	1030	,	1084	,	-29	},
{	1022	,	1086	,	-26	},
{	1015	,	1091	,	-24	},
{	1008	,	1094	,	-21	},
{	997	,	1095	,	-17	},
{	989	,	1100	,	-13	},
{	979	,	1102	,	-9	},
{	970	,	1106	,	-7	},
{	962	,	1109	,	-4	},
{	950	,	1110	,	-1	},
{	941	,	1114	,	3	},
{	933	,	1119	,	5	},
{	924	,	1124	,	8	},
{	915	,	1129	,	12	},
{	904	,	1133	,	16	},
{	896	,	1137	,	18	},
{	886	,	1140	,	21	},
{	877	,	1143	,	23	},
{	869	,	1149	,	27	},
{	858	,	1152	,	30	},
{	848	,	1157	,	33	},
{	840	,	1165	,	36	},
{	828	,	1167	,	40	},
{	820	,	1173	,	43	},
{	811	,	1179	,	46	},
{	801	,	1187	,	50	},
{	792	,	1195	,	52	},
{	780	,	1201	,	54	},
{	766	,	1203	,	57	},
{	756	,	1211	,	59	},
{	744	,	1216	,	61	},
{	733	,	1223	,	62	},
{	722	,	1232	,	65	},
{	709	,	1237	,	66	},
{	696	,	1244	,	69	},
{	684	,	1251	,	71	},
{	671	,	1257	,	73	},
{	660	,	1264	,	76	},
{	646	,	1268	,	77	},
{	635	,	1277	,	79	},
{	622	,	1284	,	80	},
{	608	,	1291	,	82	},
{	597	,	1299	,	84	},
{	585	,	1305	,	87	},
{	573	,	1311	,	89	},
{	563	,	1320	,	91	},
{	550	,	1323	,	93	},
{	539	,	1333	,	96	},
{	528	,	1338	,	98	},
{	515	,	1340	,	100	},
{	504	,	1346	,	104	},
{	495	,	1356	,	106	},
{	484	,	1363	,	109	},
{	472	,	1365	,	112	},
{	461	,	1373	,	115	},
{	451	,	1380	,	117	},
{	440	,	1384	,	120	},
{	428	,	1391	,	122	},
{	419	,	1399	,	124	},
{	406	,	1399	,	127	},
{	396	,	1407	,	129	},
{	387	,	1417	,	132	},
{	377	,	1422	,	134	},
{	367	,	1431	,	137	},
{	356	,	1433	,	140	},
{	344	,	1440	,	143	},
{	334	,	1445	,	145	},
{	324	,	1455	,	149	},
{	313	,	1458	,	152	},
{	304	,	1469	,	154	},
{	294	,	1479	,	157	},
{	284	,	1485	,	160	},
{	274	,	1489	,	162	},
{	264	,	1494	,	165	},
{	253	,	1502	,	168	},
{	242	,	1506	,	170	},
{	232	,	1514	,	172	},
{	222	,	1519	,	174	},
{	210	,	1524	,	177	},
{	200	,	1528	,	179	},
{	188	,	1532	,	181	},
{	177	,	1539	,	183	},
{	166	,	1542	,	184	},
{	156	,	1549	,	186	},
{	144	,	1554	,	188	},
{	134	,	1561	,	191	},
{	123	,	1563	,	193	},
{	112	,	1566	,	195	},
{	102	,	1571	,	197	},
{	91	,	1579	,	199	},
{	81	,	1588	,	201	},
{	69	,	1590	,	203	},
{	60	,	1591	,	205	},
{	49	,	1599	,	207	},
{	37	,	1606	,	211	},
{	26	,	1608	,	212	},
{	14	,	1618	,	215	},
{	4	,	1621	,	217	},
{	-7	,	1628	,	220	},
{	-18	,	1634	,	222	},
{	-28	,	1638	,	224	},
{	-37	,	1643	,	227	},
{	-48	,	1652	,	230	},
{	-59	,	1657	,	232	},
{	-70	,	1664	,	236	},
{	-82	,	1668	,	238	},
{	-94	,	1672	,	241	},
{	-105	,	1680	,	244	},
{	-116	,	1687	,	246	},
{	-128	,	1699	,	250	},
{	-140	,	1704	,	252	},
{	-151	,	1711	,	255	},
{	-162	,	1716	,	256	},
{	-174	,	1719	,	259	},
{	-187	,	1730	,	263	},
{	-200	,	1738	,	267	},
{	-211	,	1745	,	270	},
{	-222	,	1754	,	275	},
{	-235	,	1762	,	279	},
{	-248	,	1764	,	281	},
{	-260	,	1770	,	284	},
{	-273	,	1780	,	288	},
{	-285	,	1783	,	290	},
{	-298	,	1793	,	293	},
{	-310	,	1800	,	296	},
{	-324	,	1807	,	299	},
{	-336	,	1813	,	302	},
{	-349	,	1819	,	305	},
{	-362	,	1828	,	308	},
{	-373	,	1834	,	312	},
{	-385	,	1841	,	316	},
{	-396	,	1842	,	317	},
{	-408	,	1848	,	320	},
{	-422	,	1859	,	325	},
{	-434	,	1866	,	327	},
{	-445	,	1867	,	328	},
{	-457	,	1872	,	330	},
{	-469	,	1879	,	333	},
{	-481	,	1885	,	336	},
{	-493	,	1892	,	339	},
{	-504	,	1894	,	341	},
{	-516	,	1899	,	344	},
{	-528	,	1902	,	346	},
{	-541	,	1910	,	348	},
{	-552	,	1914	,	351	},
{	-563	,	1914	,	352	},
{	-574	,	1920	,	354	},
{	-585	,	1922	,	355	},
{	-598	,	1930	,	358	},
{	-609	,	1936	,	361	},
{	-619	,	1938	,	362	},
{	-630	,	1940	,	365	},
{	-642	,	1945	,	367	},
{	-653	,	1949	,	370	},
{	-664	,	1955	,	372	},
{	-673	,	1953	,	373	},
{	-683	,	1954	,	374	},
{	-693	,	1957	,	376	},
{	-703	,	1959	,	378	},
{	-712	,	1962	,	381	},
{	-721	,	1963	,	383	},
{	-730	,	1964	,	385	},
{	-740	,	1965	,	386	},
{	-752	,	1969	,	389	},
{	-760	,	1971	,	390	},
{	-769	,	1972	,	392	},
{	-778	,	1972	,	393	},
{	-788	,	1971	,	393	},
{	-798	,	1973	,	394	},
{	-809	,	1978	,	396	},
{	-818	,	1976	,	397	},
{	-829	,	1981	,	399	},
{	-841	,	1986	,	401	},
{	-853	,	1992	,	403	},
{	-867	,	1997	,	405	},
{	-877	,	1997	,	406	},
{	-891	,	2004	,	408	},
{	-903	,	2006	,	410	},
{	-915	,	2006	,	411	},
{	-928	,	2011	,	414	},
{	-943	,	2020	,	417	},
{	-954	,	2024	,	420	},
{	-968	,	2029	,	422	},
{	-982	,	2035	,	425	},
{	-996	,	2041	,	428	},
{	-1011	,	2050	,	431	},
{	-1024	,	2055	,	434	},
{	-1038	,	2061	,	436	},
{	-1051	,	2062	,	439	},
{	-1065	,	2067	,	442	},
{	-1080	,	2076	,	445	},
{	-1092	,	2079	,	448	},
{	-1109	,	2089	,	452	},
{	-1119	,	2088	,	453	},
{	-1135	,	2096	,	457	},
{	-1150	,	2104	,	461	},
{	-1164	,	2110	,	465	},
{	-1174	,	2109	,	467	},
{	-1189	,	2118	,	471	},
{	-1203	,	2121	,	475	},
{	-1214	,	2121	,	478	},
{	-1228	,	2126	,	482	},
{	-1241	,	2128	,	485	},
{	-1253	,	2131	,	488	},
{	-1267	,	2138	,	492	},
{	-1279	,	2140	,	494	},
{	-1291	,	2143	,	497	},
{	-1305	,	2147	,	500	},
{	-1314	,	2144	,	502	},
{	-1325	,	2144	,	504	},
{	-1341	,	2153	,	508	},
{	-1349	,	2149	,	509	},
{	-1359	,	2148	,	510	},
{	-1364	,	2148	,	511	},
{	-1371	,	2150	,	513	},
{	-1377	,	2150	,	513	},
{	-1383	,	2151	,	514	},
{	-1390	,	2153	,	514	},
{	-1396	,	2152	,	514	},
{	-1399	,	2150	,	514	},
{	-1406	,	2150	,	515	}
};

#endif	/* TABLE_LUGE7_SN162_H */

