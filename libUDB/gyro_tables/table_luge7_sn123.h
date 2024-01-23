

#ifndef TABLE_LUGE7_SN123_H
#define	TABLE_LUGE7_SN123_H

// used in LUGE7_SN123 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14421 )

int16_t residual_offset[] = { 382 , -148 , 47 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1009	,	1074	,	56	},
{	-1009	,	1065	,	62	},
{	-1012	,	1059	,	67	},
{	-1014	,	1055	,	72	},
{	-1016	,	1047	,	77	},
{	-1017	,	1041	,	81	},
{	-1020	,	1037	,	85	},
{	-1021	,	1030	,	89	},
{	-1022	,	1023	,	93	},
{	-1024	,	1015	,	102	},
{	-1022	,	1001	,	113	},
{	-1024	,	990	,	121	},
{	-1027	,	980	,	128	},
{	-1030	,	969	,	135	},
{	-1034	,	962	,	141	},
{	-1035	,	950	,	147	},
{	-1038	,	941	,	153	},
{	-1044	,	935	,	158	},
{	-1046	,	928	,	163	},
{	-1051	,	923	,	168	},
{	-1052	,	913	,	173	},
{	-1053	,	906	,	178	},
{	-1055	,	899	,	182	},
{	-1057	,	893	,	188	},
{	-1057	,	887	,	192	},
{	-1057	,	880	,	196	},
{	-1060	,	876	,	200	},
{	-1060	,	869	,	204	},
{	-1060	,	862	,	206	},
{	-1063	,	856	,	210	},
{	-1063	,	849	,	213	},
{	-1063	,	841	,	218	},
{	-1063	,	835	,	222	},
{	-1065	,	830	,	226	},
{	-1066	,	823	,	230	},
{	-1066	,	816	,	233	},
{	-1064	,	807	,	237	},
{	-1065	,	801	,	241	},
{	-1068	,	796	,	245	},
{	-1069	,	789	,	250	},
{	-1068	,	781	,	252	},
{	-1070	,	775	,	257	},
{	-1072	,	770	,	261	},
{	-1069	,	760	,	265	},
{	-1070	,	754	,	270	},
{	-1070	,	746	,	275	},
{	-1068	,	737	,	278	},
{	-1071	,	731	,	283	},
{	-1070	,	723	,	287	},
{	-1069	,	715	,	292	},
{	-1067	,	705	,	294	},
{	-1065	,	697	,	298	},
{	-1067	,	690	,	302	},
{	-1066	,	682	,	305	},
{	-1068	,	676	,	310	},
{	-1065	,	667	,	314	},
{	-1065	,	659	,	317	},
{	-1064	,	651	,	322	},
{	-1062	,	643	,	325	},
{	-1063	,	635	,	330	},
{	-1064	,	629	,	333	},
{	-1061	,	620	,	334	},
{	-1062	,	614	,	338	},
{	-1064	,	608	,	342	},
{	-1062	,	601	,	345	},
{	-1064	,	595	,	349	},
{	-1064	,	590	,	351	},
{	-1066	,	586	,	356	},
{	-1064	,	579	,	358	},
{	-1062	,	573	,	361	},
{	-1061	,	568	,	363	},
{	-1058	,	561	,	365	},
{	-1057	,	555	,	366	},
{	-1058	,	551	,	370	},
{	-1054	,	545	,	371	},
{	-1055	,	541	,	375	},
{	-1054	,	536	,	377	},
{	-1051	,	530	,	380	},
{	-1052	,	527	,	384	},
{	-1051	,	523	,	386	},
{	-1050	,	520	,	389	},
{	-1049	,	516	,	391	},
{	-1046	,	510	,	392	},
{	-1047	,	507	,	395	},
{	-1044	,	501	,	397	},
{	-1047	,	498	,	401	},
{	-1045	,	493	,	404	},
{	-1045	,	490	,	408	},
{	-1046	,	488	,	412	},
{	-1046	,	487	,	416	},
{	-1043	,	483	,	416	},
{	-1046	,	482	,	419	},
{	-1045	,	476	,	419	},
{	-1043	,	470	,	418	},
{	-1045	,	470	,	420	},
{	-1044	,	466	,	420	},
{	-1043	,	463	,	422	},
{	-1044	,	462	,	423	},
{	-1043	,	459	,	423	},
{	-1041	,	457	,	424	},
{	-1040	,	454	,	425	},
{	-1040	,	452	,	425	},
{	-1040	,	449	,	424	},
{	-1040	,	448	,	423	},
{	-1038	,	444	,	423	},
{	-1039	,	440	,	421	},
{	-1037	,	435	,	420	},
{	-1037	,	433	,	421	},
{	-1038	,	429	,	422	},
{	-1037	,	428	,	422	},
{	-1037	,	427	,	423	},
{	-1038	,	424	,	423	},
{	-1040	,	421	,	423	},
{	-1040	,	418	,	423	},
{	-1041	,	414	,	423	},
{	-1043	,	409	,	423	},
{	-1047	,	406	,	424	},
{	-1047	,	401	,	423	},
{	-1051	,	398	,	426	},
{	-1049	,	393	,	426	},
{	-1053	,	390	,	427	},
{	-1054	,	387	,	427	},
{	-1052	,	382	,	427	},
{	-1055	,	379	,	428	},
{	-1058	,	375	,	428	},
{	-1061	,	371	,	427	},
{	-1063	,	369	,	429	},
{	-1066	,	364	,	430	},
{	-1067	,	359	,	431	},
{	-1073	,	356	,	432	},
{	-1077	,	351	,	432	},
{	-1083	,	349	,	433	},
{	-1085	,	345	,	433	},
{	-1091	,	342	,	435	},
{	-1096	,	340	,	435	},
{	-1101	,	337	,	435	},
{	-1106	,	335	,	434	},
{	-1111	,	332	,	435	},
{	-1120	,	330	,	437	},
{	-1125	,	327	,	437	},
{	-1134	,	325	,	439	},
{	-1138	,	322	,	439	},
{	-1142	,	320	,	439	},
{	-1150	,	318	,	439	},
{	-1159	,	316	,	440	},
{	-1166	,	316	,	441	},
{	-1168	,	313	,	441	},
{	-1176	,	311	,	442	},
{	-1181	,	309	,	443	},
{	-1189	,	308	,	443	},
{	-1194	,	306	,	443	},
{	-1201	,	305	,	444	},
{	-1207	,	304	,	443	},
{	-1216	,	304	,	445	},
{	-1222	,	302	,	444	},
{	-1227	,	301	,	442	},
{	-1236	,	301	,	443	},
{	-1240	,	299	,	442	},
{	-1249	,	299	,	442	},
{	-1257	,	298	,	443	},
{	-1265	,	297	,	443	},
{	-1273	,	297	,	443	},
{	-1277	,	295	,	441	},
{	-1289	,	295	,	443	},
{	-1294	,	294	,	442	},
{	-1301	,	294	,	442	},
{	-1309	,	293	,	443	},
{	-1315	,	293	,	444	},
{	-1324	,	292	,	444	},
{	-1329	,	290	,	446	},
{	-1337	,	288	,	446	},
{	-1341	,	287	,	446	},
{	-1347	,	286	,	446	},
{	-1351	,	284	,	445	},
{	-1355	,	283	,	444	},
{	-1363	,	283	,	445	},
{	-1365	,	281	,	443	},
{	-1371	,	280	,	444	},
{	-1371	,	278	,	441	},
{	-1379	,	277	,	442	},
{	-1378	,	275	,	440	},
{	-1386	,	275	,	439	},
{	-1388	,	273	,	437	},
{	-1394	,	272	,	437	},
{	-1402	,	270	,	436	},
{	-1401	,	268	,	434	},
{	-1407	,	268	,	432	},
{	-1410	,	266	,	431	},
{	-1416	,	264	,	432	},
{	-1417	,	261	,	431	},
{	-1421	,	258	,	432	},
{	-1427	,	256	,	432	},
{	-1430	,	254	,	431	},
{	-1434	,	251	,	432	},
{	-1438	,	249	,	431	},
{	-1446	,	248	,	431	},
{	-1451	,	245	,	432	},
{	-1456	,	243	,	431	},
{	-1456	,	240	,	431	},
{	-1462	,	237	,	432	},
{	-1463	,	235	,	430	},
{	-1466	,	233	,	430	},
{	-1471	,	230	,	430	},
{	-1476	,	227	,	430	},
{	-1478	,	224	,	428	},
{	-1483	,	223	,	428	},
{	-1492	,	221	,	428	},
{	-1498	,	219	,	428	},
{	-1504	,	217	,	428	},
{	-1507	,	215	,	427	},
{	-1517	,	213	,	428	},
{	-1521	,	210	,	428	},
{	-1524	,	207	,	427	},
{	-1530	,	205	,	427	},
{	-1534	,	203	,	427	},
{	-1543	,	201	,	428	},
{	-1545	,	199	,	426	},
{	-1550	,	197	,	425	},
{	-1554	,	195	,	425	},
{	-1559	,	192	,	425	},
{	-1562	,	191	,	423	},
{	-1567	,	189	,	423	},
{	-1573	,	187	,	422	},
{	-1573	,	185	,	419	},
{	-1578	,	184	,	418	},
{	-1585	,	182	,	418	},
{	-1589	,	180	,	418	},
{	-1591	,	178	,	416	},
{	-1594	,	176	,	414	},
{	-1596	,	175	,	413	},
{	-1601	,	174	,	412	},
{	-1611	,	173	,	411	},
{	-1614	,	171	,	409	},
{	-1619	,	169	,	409	},
{	-1627	,	167	,	408	},
{	-1628	,	165	,	405	},
{	-1636	,	163	,	404	},
{	-1642	,	161	,	404	},
{	-1648	,	159	,	403	},
{	-1654	,	158	,	402	},
{	-1661	,	156	,	401	},
{	-1666	,	153	,	400	},
{	-1667	,	152	,	398	},
{	-1671	,	150	,	396	},
{	-1679	,	148	,	396	},
{	-1687	,	147	,	395	},
{	-1694	,	144	,	394	},
{	-1696	,	142	,	392	},
{	-1697	,	139	,	390	},
{	-1702	,	138	,	389	},
{	-1710	,	136	,	388	},
{	-1711	,	134	,	386	},
{	-1718	,	132	,	385	},
{	-1723	,	130	,	384	},
{	-1725	,	128	,	382	},
{	-1733	,	126	,	382	},
{	-1734	,	123	,	379	},
{	-1737	,	121	,	377	},
{	-1742	,	120	,	374	},
{	-1752	,	117	,	373	},
{	-1755	,	115	,	370	},
{	-1757	,	113	,	367	},
{	-1757	,	111	,	364	},
{	-1769	,	110	,	363	},
{	-1774	,	108	,	360	},
{	-1783	,	107	,	359	},
{	-1785	,	106	,	356	},
{	-1792	,	104	,	354	},
{	-1799	,	102	,	352	},
{	-1807	,	101	,	351	},
{	-1811	,	99	,	348	},
{	-1820	,	99	,	346	},
{	-1820	,	97	,	342	},
{	-1826	,	96	,	340	},
{	-1836	,	95	,	339	},
{	-1840	,	93	,	337	},
{	-1843	,	92	,	335	},
{	-1852	,	91	,	334	},
{	-1857	,	89	,	331	},
{	-1868	,	87	,	331	},
{	-1867	,	85	,	329	},
{	-1876	,	83	,	328	},
{	-1878	,	80	,	325	},
{	-1885	,	78	,	324	},
{	-1888	,	76	,	321	},
{	-1894	,	73	,	320	},
{	-1902	,	71	,	318	},
{	-1911	,	69	,	317	},
{	-1912	,	67	,	315	},
{	-1923	,	65	,	314	},
{	-1933	,	62	,	312	},
{	-1937	,	60	,	311	},
{	-1942	,	58	,	310	},
{	-1953	,	55	,	308	},
{	-1957	,	54	,	306	},
{	-1966	,	52	,	304	},
{	-1969	,	49	,	302	},
{	-1983	,	48	,	301	},
{	-1985	,	47	,	299	},
{	-1996	,	44	,	298	},
{	-2008	,	43	,	297	},
{	-2012	,	41	,	295	},
{	-2019	,	39	,	293	},
{	-2022	,	37	,	290	},
{	-2029	,	36	,	289	},
{	-2043	,	34	,	288	},
{	-2046	,	31	,	286	},
{	-2056	,	28	,	285	},
{	-2062	,	26	,	283	},
{	-2073	,	24	,	282	},
{	-2078	,	21	,	281	},
{	-2086	,	18	,	281	},
{	-2095	,	16	,	279	},
{	-2108	,	15	,	277	},
{	-2111	,	13	,	275	},
{	-2126	,	11	,	275	},
{	-2131	,	9	,	273	},
{	-2131	,	7	,	271	},
{	-2145	,	5	,	271	},
{	-2153	,	4	,	269	},
{	-2160	,	1	,	268	},
{	-2166	,	-1	,	267	},
{	-2172	,	-4	,	266	},
{	-2185	,	-6	,	265	},
{	-2195	,	-9	,	265	},
{	-2202	,	-13	,	264	},
{	-2213	,	-17	,	262	},
{	-2221	,	-21	,	261	},
{	-2232	,	-25	,	260	},
{	-2236	,	-30	,	259	},
{	-2238	,	-35	,	258	},
{	-2247	,	-40	,	257	},
{	-2250	,	-46	,	256	},
{	-2257	,	-51	,	255	},
{	-2266	,	-58	,	255	},
{	-2277	,	-65	,	255	},
{	-2282	,	-72	,	255	},
{	-2291	,	-79	,	254	},
{	-2304	,	-86	,	254	},
{	-2308	,	-94	,	253	},
{	-2314	,	-102	,	253	},
{	-2321	,	-109	,	252	},
{	-2334	,	-116	,	252	},
{	-2339	,	-122	,	250	},
{	-2347	,	-128	,	250	},
{	-2351	,	-135	,	248	},
{	-2355	,	-141	,	248	},
{	-2361	,	-149	,	247	},
{	-2368	,	-156	,	246	},
{	-2375	,	-164	,	245	},
{	-2382	,	-171	,	245	},
{	-2389	,	-178	,	244	},
{	-2389	,	-186	,	243	},
{	-2398	,	-195	,	243	},
{	-2403	,	-202	,	242	},
{	-2410	,	-211	,	242	},
{	-2419	,	-219	,	241	},
{	-2422	,	-227	,	240	},
{	-2420	,	-236	,	239	},
{	-2425	,	-245	,	238	},
{	-2425	,	-255	,	238	},
{	-2421	,	-264	,	238	},
{	-2430	,	-275	,	238	},
{	-2434	,	-286	,	239	},
{	-2436	,	-296	,	239	},
{	-2439	,	-307	,	239	},
{	-2432	,	-317	,	239	},
{	-2431	,	-327	,	240	},
{	-2430	,	-338	,	240	},
{	-2424	,	-348	,	241	},
{	-2413	,	-358	,	243	},
{	-2414	,	-364	,	243	},
{	-2405	,	-369	,	243	},
{	-2398	,	-374	,	243	},
{	-2396	,	-378	,	243	},
{	-2394	,	-383	,	244	},
{	-2385	,	-388	,	244	},
{	-2383	,	-394	,	245	},
{	-2387	,	-400	,	247	}
};

#endif	/* TABLE_LUGE7_SN123_H */

