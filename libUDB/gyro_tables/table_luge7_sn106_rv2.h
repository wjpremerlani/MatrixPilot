

#ifndef TABLE_LUGE7_SN106_H
#define	TABLE_LUGE7_SN106_H

// used in LUGE7_SN106 partition size 64

#define STEP_SIZE 64

int16_t residual_offset[] = { 0 , 0 , 0 } ;

#define TABLE_ORIGIN  ( -14413 )

struct gyro_offset_table_entry gyro_offset_table[] = {
{	1655	,	-754	,	1369	},
{	1653	,	-753	,	1371	},
{	1647	,	-752	,	1369	},
{	1643	,	-752	,	1369	},
{	1642	,	-753	,	1369	},
{	1641	,	-756	,	1374	},
{	1635	,	-756	,	1373	},
{	1630	,	-756	,	1372	},
{	1627	,	-755	,	1372	},
{	1623	,	-753	,	1369	},
{	1617	,	-751	,	1365	},
{	1617	,	-751	,	1366	},
{	1616	,	-751	,	1365	},
{	1612	,	-750	,	1363	},
{	1607	,	-747	,	1360	},
{	1604	,	-746	,	1358	},
{	1597	,	-743	,	1352	},
{	1593	,	-742	,	1351	},
{	1590	,	-741	,	1350	},
{	1588	,	-740	,	1348	},
{	1585	,	-739	,	1345	},
{	1580	,	-737	,	1341	},
{	1575	,	-735	,	1337	},
{	1573	,	-732	,	1335	},
{	1572	,	-729	,	1334	},
{	1569	,	-726	,	1331	},
{	1564	,	-724	,	1326	},
{	1558	,	-720	,	1320	},
{	1556	,	-719	,	1318	},
{	1550	,	-716	,	1315	},
{	1547	,	-714	,	1313	},
{	1544	,	-711	,	1313	},
{	1538	,	-709	,	1309	},
{	1533	,	-706	,	1306	},
{	1529	,	-705	,	1302	},
{	1526	,	-702	,	1300	},
{	1523	,	-701	,	1299	},
{	1516	,	-699	,	1295	},
{	1512	,	-697	,	1291	},
{	1508	,	-695	,	1289	},
{	1505	,	-695	,	1285	},
{	1505	,	-695	,	1284	},
{	1500	,	-695	,	1280	},
{	1497	,	-695	,	1278	},
{	1496	,	-695	,	1277	},
{	1492	,	-693	,	1274	},
{	1488	,	-690	,	1270	},
{	1486	,	-689	,	1270	},
{	1483	,	-688	,	1267	},
{	1476	,	-684	,	1263	},
{	1471	,	-683	,	1260	},
{	1467	,	-681	,	1258	},
{	1465	,	-680	,	1257	},
{	1462	,	-678	,	1254	},
{	1458	,	-677	,	1251	},
{	1455	,	-676	,	1249	},
{	1450	,	-674	,	1243	},
{	1446	,	-674	,	1240	},
{	1443	,	-673	,	1236	},
{	1439	,	-671	,	1234	},
{	1435	,	-669	,	1231	},
{	1430	,	-666	,	1228	},
{	1423	,	-663	,	1223	},
{	1420	,	-661	,	1222	},
{	1416	,	-659	,	1219	},
{	1414	,	-659	,	1218	},
{	1409	,	-656	,	1214	},
{	1408	,	-656	,	1214	},
{	1404	,	-655	,	1211	},
{	1402	,	-654	,	1207	},
{	1398	,	-653	,	1203	},
{	1396	,	-655	,	1201	},
{	1391	,	-655	,	1196	},
{	1387	,	-654	,	1191	},
{	1383	,	-654	,	1188	},
{	1380	,	-655	,	1186	},
{	1374	,	-654	,	1181	},
{	1368	,	-655	,	1176	},
{	1365	,	-656	,	1175	},
{	1363	,	-658	,	1172	},
{	1357	,	-657	,	1168	},
{	1352	,	-657	,	1163	},
{	1350	,	-658	,	1161	},
{	1344	,	-657	,	1156	},
{	1340	,	-657	,	1152	},
{	1338	,	-657	,	1148	},
{	1334	,	-656	,	1144	},
{	1332	,	-657	,	1140	},
{	1327	,	-654	,	1134	},
{	1323	,	-654	,	1130	},
{	1321	,	-654	,	1127	},
{	1319	,	-655	,	1126	},
{	1318	,	-655	,	1123	},
{	1315	,	-653	,	1119	},
{	1312	,	-653	,	1116	},
{	1311	,	-652	,	1114	},
{	1307	,	-649	,	1109	},
{	1306	,	-648	,	1107	},
{	1303	,	-645	,	1104	},
{	1299	,	-643	,	1100	},
{	1295	,	-640	,	1094	},
{	1290	,	-638	,	1090	},
{	1284	,	-634	,	1085	},
{	1280	,	-632	,	1082	},
{	1275	,	-628	,	1078	},
{	1270	,	-625	,	1075	},
{	1262	,	-621	,	1068	},
{	1259	,	-620	,	1064	},
{	1255	,	-617	,	1059	},
{	1248	,	-614	,	1056	},
{	1241	,	-611	,	1050	},
{	1237	,	-610	,	1046	},
{	1230	,	-606	,	1040	},
{	1223	,	-604	,	1034	},
{	1218	,	-602	,	1030	},
{	1215	,	-600	,	1029	},
{	1208	,	-598	,	1025	},
{	1200	,	-595	,	1020	},
{	1194	,	-592	,	1015	},
{	1189	,	-591	,	1010	},
{	1183	,	-589	,	1006	},
{	1177	,	-586	,	1002	},
{	1169	,	-583	,	997	},
{	1161	,	-581	,	990	},
{	1153	,	-577	,	984	},
{	1146	,	-573	,	979	},
{	1139	,	-570	,	974	},
{	1131	,	-567	,	969	},
{	1123	,	-562	,	965	},
{	1115	,	-558	,	959	},
{	1106	,	-554	,	955	},
{	1099	,	-551	,	950	},
{	1090	,	-547	,	946	},
{	1082	,	-542	,	940	},
{	1073	,	-538	,	936	},
{	1064	,	-534	,	930	},
{	1055	,	-530	,	925	},
{	1045	,	-526	,	919	},
{	1035	,	-522	,	912	},
{	1025	,	-517	,	904	},
{	1015	,	-511	,	897	},
{	1006	,	-507	,	892	},
{	996	,	-502	,	885	},
{	984	,	-495	,	878	},
{	974	,	-490	,	870	},
{	964	,	-483	,	864	},
{	953	,	-476	,	857	},
{	942	,	-469	,	850	},
{	931	,	-462	,	845	},
{	920	,	-456	,	839	},
{	909	,	-448	,	832	},
{	898	,	-442	,	825	},
{	888	,	-436	,	818	},
{	877	,	-428	,	812	},
{	866	,	-422	,	805	},
{	856	,	-416	,	798	},
{	846	,	-410	,	792	},
{	836	,	-405	,	784	},
{	826	,	-400	,	776	},
{	816	,	-394	,	769	},
{	806	,	-388	,	761	},
{	797	,	-382	,	753	},
{	787	,	-377	,	745	},
{	777	,	-371	,	737	},
{	768	,	-365	,	730	},
{	759	,	-359	,	724	},
{	749	,	-353	,	719	},
{	740	,	-346	,	713	},
{	731	,	-340	,	707	},
{	722	,	-335	,	701	},
{	712	,	-330	,	696	},
{	705	,	-325	,	690	},
{	696	,	-320	,	684	},
{	689	,	-314	,	677	},
{	681	,	-308	,	669	},
{	673	,	-304	,	662	},
{	666	,	-299	,	655	},
{	660	,	-295	,	647	},
{	652	,	-290	,	639	},
{	644	,	-284	,	631	},
{	636	,	-279	,	624	},
{	628	,	-274	,	617	},
{	620	,	-269	,	611	},
{	613	,	-265	,	604	},
{	606	,	-261	,	597	},
{	598	,	-257	,	589	},
{	588	,	-252	,	583	},
{	581	,	-248	,	577	},
{	574	,	-244	,	572	},
{	567	,	-238	,	566	},
{	560	,	-233	,	560	},
{	552	,	-229	,	554	},
{	543	,	-224	,	548	},
{	535	,	-220	,	542	},
{	527	,	-216	,	537	},
{	519	,	-212	,	531	},
{	511	,	-209	,	524	},
{	502	,	-205	,	517	},
{	494	,	-202	,	509	},
{	487	,	-200	,	503	},
{	479	,	-196	,	496	},
{	472	,	-193	,	490	},
{	463	,	-189	,	483	},
{	455	,	-184	,	477	},
{	449	,	-180	,	470	},
{	441	,	-175	,	464	},
{	434	,	-171	,	458	},
{	426	,	-167	,	453	},
{	417	,	-161	,	446	},
{	411	,	-158	,	440	},
{	404	,	-154	,	433	},
{	399	,	-150	,	426	},
{	392	,	-146	,	420	},
{	384	,	-140	,	414	},
{	378	,	-137	,	409	},
{	370	,	-132	,	403	},
{	361	,	-126	,	396	},
{	355	,	-124	,	391	},
{	349	,	-119	,	386	},
{	342	,	-115	,	380	},
{	333	,	-111	,	375	},
{	325	,	-107	,	369	},
{	318	,	-103	,	363	},
{	309	,	-98	,	356	},
{	302	,	-94	,	350	},
{	295	,	-90	,	344	},
{	286	,	-84	,	338	},
{	277	,	-78	,	331	},
{	268	,	-73	,	325	},
{	263	,	-69	,	320	},
{	256	,	-65	,	316	},
{	250	,	-62	,	311	},
{	244	,	-59	,	306	},
{	238	,	-56	,	301	},
{	232	,	-52	,	297	},
{	225	,	-47	,	292	},
{	218	,	-43	,	287	},
{	212	,	-38	,	281	},
{	203	,	-32	,	275	},
{	194	,	-27	,	267	},
{	186	,	-21	,	261	},
{	178	,	-16	,	255	},
{	169	,	-11	,	249	},
{	161	,	-8	,	242	},
{	153	,	-3	,	235	},
{	147	,	2	,	230	},
{	139	,	7	,	224	},
{	132	,	11	,	219	},
{	125	,	16	,	214	},
{	119	,	22	,	209	},
{	113	,	27	,	205	},
{	108	,	32	,	201	},
{	100	,	39	,	196	},
{	95	,	42	,	192	},
{	87	,	46	,	186	},
{	83	,	49	,	182	},
{	75	,	54	,	176	},
{	67	,	58	,	170	},
{	62	,	60	,	165	},
{	57	,	62	,	161	},
{	51	,	65	,	156	},
{	48	,	66	,	153	},
{	42	,	71	,	148	},
{	37	,	74	,	145	},
{	30	,	79	,	139	},
{	26	,	82	,	135	},
{	23	,	85	,	132	},
{	18	,	90	,	128	},
{	10	,	94	,	122	},
{	4	,	99	,	116	},
{	-3	,	106	,	110	},
{	-10	,	112	,	104	},
{	-16	,	116	,	99	},
{	-21	,	120	,	95	},
{	-28	,	125	,	89	},
{	-31	,	127	,	85	},
{	-37	,	131	,	80	},
{	-41	,	134	,	77	},
{	-46	,	138	,	71	},
{	-50	,	139	,	68	},
{	-54	,	141	,	63	},
{	-57	,	142	,	59	},
{	-60	,	144	,	56	},
{	-62	,	146	,	53	},
{	-68	,	150	,	46	},
{	-73	,	153	,	42	},
{	-75	,	154	,	39	},
{	-74	,	154	,	38	},
{	-77	,	157	,	34	},
{	-78	,	159	,	32	},
{	-79	,	162	,	29	},
{	-76	,	163	,	28	},
{	-67	,	161	,	31	},
{	-64	,	161	,	31	},
{	-60	,	160	,	32	},
{	-59	,	161	,	31	},
{	-56	,	162	,	31	}
};

#endif	/* TABLE_LUGE7_SN106_H */

