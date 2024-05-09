

#ifndef TABLE_LUGE7_SN194_H
#define	TABLE_LUGE7_SN194_H

// used in LUGE7_SN194 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14667 )

int16_t residual_offset[] = { -712 , 727 , -69 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-157	,	-174	,	287	},
{	-154	,	-177	,	292	},
{	-150	,	-181	,	295	},
{	-147	,	-185	,	299	},
{	-143	,	-190	,	303	},
{	-140	,	-195	,	307	},
{	-137	,	-199	,	309	},
{	-134	,	-204	,	312	},
{	-131	,	-208	,	315	},
{	-125	,	-218	,	321	},
{	-120	,	-227	,	327	},
{	-113	,	-236	,	333	},
{	-107	,	-244	,	338	},
{	-99	,	-252	,	343	},
{	-92	,	-260	,	350	},
{	-84	,	-268	,	354	},
{	-77	,	-277	,	360	},
{	-68	,	-285	,	365	},
{	-61	,	-294	,	370	},
{	-55	,	-303	,	375	},
{	-48	,	-310	,	380	},
{	-42	,	-317	,	384	},
{	-36	,	-324	,	388	},
{	-31	,	-332	,	394	},
{	-24	,	-340	,	399	},
{	-18	,	-346	,	403	},
{	-12	,	-352	,	407	},
{	-5	,	-358	,	412	},
{	0	,	-366	,	417	},
{	7	,	-372	,	423	},
{	14	,	-381	,	429	},
{	19	,	-387	,	433	},
{	23	,	-394	,	439	},
{	29	,	-401	,	444	},
{	34	,	-407	,	448	},
{	40	,	-413	,	450	},
{	45	,	-419	,	454	},
{	51	,	-427	,	459	},
{	56	,	-434	,	464	},
{	62	,	-442	,	469	},
{	67	,	-449	,	473	},
{	72	,	-456	,	478	},
{	77	,	-464	,	483	},
{	82	,	-470	,	486	},
{	88	,	-479	,	490	},
{	94	,	-486	,	495	},
{	100	,	-494	,	498	},
{	106	,	-501	,	502	},
{	112	,	-510	,	508	},
{	120	,	-519	,	511	},
{	125	,	-527	,	515	},
{	132	,	-535	,	519	},
{	137	,	-545	,	527	},
{	143	,	-552	,	531	},
{	150	,	-561	,	535	},
{	155	,	-570	,	539	},
{	162	,	-577	,	543	},
{	168	,	-587	,	548	},
{	175	,	-594	,	550	},
{	181	,	-603	,	553	},
{	188	,	-612	,	557	},
{	194	,	-619	,	562	},
{	199	,	-626	,	564	},
{	204	,	-635	,	568	},
{	210	,	-643	,	572	},
{	214	,	-650	,	576	},
{	217	,	-658	,	580	},
{	222	,	-665	,	583	},
{	227	,	-674	,	589	},
{	233	,	-684	,	592	},
{	238	,	-691	,	596	},
{	242	,	-700	,	601	},
{	247	,	-708	,	604	},
{	251	,	-717	,	607	},
{	257	,	-724	,	610	},
{	263	,	-734	,	615	},
{	267	,	-742	,	619	},
{	272	,	-751	,	624	},
{	277	,	-761	,	628	},
{	281	,	-769	,	632	},
{	287	,	-780	,	637	},
{	290	,	-787	,	639	},
{	295	,	-796	,	643	},
{	301	,	-807	,	647	},
{	307	,	-815	,	650	},
{	311	,	-823	,	651	},
{	315	,	-832	,	655	},
{	320	,	-841	,	659	},
{	325	,	-851	,	664	},
{	330	,	-859	,	667	},
{	335	,	-869	,	671	},
{	339	,	-877	,	676	},
{	343	,	-886	,	679	},
{	348	,	-894	,	683	},
{	352	,	-901	,	683	},
{	356	,	-910	,	686	},
{	361	,	-920	,	688	},
{	363	,	-927	,	690	},
{	368	,	-937	,	694	},
{	371	,	-944	,	696	},
{	374	,	-952	,	698	},
{	376	,	-961	,	701	},
{	380	,	-969	,	704	},
{	381	,	-976	,	707	},
{	384	,	-984	,	708	},
{	386	,	-991	,	708	},
{	389	,	-1000	,	711	},
{	391	,	-1010	,	713	},
{	392	,	-1017	,	714	},
{	394	,	-1023	,	716	},
{	397	,	-1033	,	718	},
{	399	,	-1041	,	723	},
{	399	,	-1048	,	725	},
{	400	,	-1055	,	728	},
{	402	,	-1062	,	731	},
{	403	,	-1070	,	732	},
{	404	,	-1078	,	736	},
{	403	,	-1083	,	737	},
{	404	,	-1092	,	741	},
{	404	,	-1100	,	744	},
{	403	,	-1106	,	746	},
{	403	,	-1115	,	751	},
{	400	,	-1119	,	753	},
{	399	,	-1127	,	756	},
{	396	,	-1130	,	758	},
{	395	,	-1140	,	764	},
{	392	,	-1145	,	768	},
{	388	,	-1149	,	769	},
{	386	,	-1156	,	772	},
{	382	,	-1161	,	775	},
{	378	,	-1167	,	777	},
{	374	,	-1175	,	781	},
{	369	,	-1180	,	785	},
{	364	,	-1186	,	788	},
{	360	,	-1192	,	791	},
{	355	,	-1196	,	792	},
{	349	,	-1201	,	794	},
{	343	,	-1206	,	795	},
{	336	,	-1211	,	798	},
{	330	,	-1218	,	801	},
{	322	,	-1221	,	803	},
{	316	,	-1228	,	806	},
{	309	,	-1232	,	807	},
{	300	,	-1235	,	808	},
{	292	,	-1241	,	811	},
{	283	,	-1243	,	812	},
{	274	,	-1248	,	815	},
{	265	,	-1252	,	818	},
{	254	,	-1252	,	820	},
{	244	,	-1253	,	820	},
{	233	,	-1255	,	822	},
{	223	,	-1257	,	824	},
{	211	,	-1258	,	826	},
{	199	,	-1262	,	830	},
{	188	,	-1264	,	832	},
{	176	,	-1263	,	831	},
{	164	,	-1265	,	834	},
{	152	,	-1266	,	836	},
{	141	,	-1268	,	839	},
{	129	,	-1267	,	840	},
{	117	,	-1271	,	844	},
{	105	,	-1271	,	845	},
{	93	,	-1272	,	846	},
{	81	,	-1270	,	846	},
{	69	,	-1271	,	847	},
{	59	,	-1275	,	849	},
{	48	,	-1277	,	852	},
{	37	,	-1276	,	852	},
{	25	,	-1281	,	856	},
{	14	,	-1283	,	857	},
{	3	,	-1282	,	858	},
{	-8	,	-1285	,	861	},
{	-19	,	-1288	,	864	},
{	-30	,	-1289	,	865	},
{	-40	,	-1293	,	867	},
{	-51	,	-1292	,	865	},
{	-61	,	-1295	,	866	},
{	-72	,	-1299	,	867	},
{	-82	,	-1302	,	869	},
{	-92	,	-1308	,	872	},
{	-101	,	-1313	,	874	},
{	-111	,	-1317	,	875	},
{	-123	,	-1321	,	876	},
{	-133	,	-1324	,	877	},
{	-144	,	-1329	,	879	},
{	-154	,	-1332	,	878	},
{	-163	,	-1336	,	878	},
{	-174	,	-1344	,	880	},
{	-183	,	-1349	,	881	},
{	-193	,	-1356	,	883	},
{	-201	,	-1359	,	883	},
{	-211	,	-1364	,	884	},
{	-221	,	-1370	,	886	},
{	-230	,	-1375	,	887	},
{	-240	,	-1377	,	886	},
{	-250	,	-1382	,	887	},
{	-260	,	-1385	,	888	},
{	-270	,	-1394	,	892	},
{	-279	,	-1396	,	891	},
{	-288	,	-1400	,	892	},
{	-298	,	-1407	,	894	},
{	-309	,	-1417	,	898	},
{	-318	,	-1419	,	898	},
{	-328	,	-1425	,	900	},
{	-337	,	-1428	,	900	},
{	-346	,	-1431	,	901	},
{	-355	,	-1435	,	901	},
{	-364	,	-1442	,	902	},
{	-375	,	-1449	,	904	},
{	-384	,	-1452	,	904	},
{	-394	,	-1457	,	905	},
{	-403	,	-1462	,	905	},
{	-414	,	-1470	,	908	},
{	-421	,	-1472	,	905	},
{	-430	,	-1476	,	904	},
{	-440	,	-1483	,	906	},
{	-448	,	-1486	,	906	},
{	-457	,	-1491	,	906	},
{	-464	,	-1490	,	903	},
{	-473	,	-1499	,	905	},
{	-481	,	-1503	,	904	},
{	-490	,	-1508	,	904	},
{	-497	,	-1512	,	903	},
{	-506	,	-1516	,	903	},
{	-514	,	-1518	,	902	},
{	-521	,	-1518	,	900	},
{	-529	,	-1521	,	899	},
{	-538	,	-1528	,	900	},
{	-546	,	-1530	,	899	},
{	-553	,	-1528	,	895	},
{	-564	,	-1535	,	898	},
{	-572	,	-1537	,	896	},
{	-582	,	-1541	,	897	},
{	-592	,	-1547	,	899	},
{	-601	,	-1550	,	898	},
{	-610	,	-1552	,	898	},
{	-619	,	-1553	,	897	},
{	-628	,	-1556	,	897	},
{	-636	,	-1556	,	895	},
{	-645	,	-1559	,	895	},
{	-655	,	-1563	,	896	},
{	-665	,	-1565	,	896	},
{	-674	,	-1567	,	895	},
{	-685	,	-1572	,	896	},
{	-694	,	-1573	,	895	},
{	-705	,	-1578	,	896	},
{	-716	,	-1584	,	898	},
{	-726	,	-1585	,	896	},
{	-738	,	-1591	,	898	},
{	-748	,	-1592	,	896	},
{	-760	,	-1595	,	894	},
{	-774	,	-1601	,	896	},
{	-785	,	-1605	,	896	},
{	-796	,	-1607	,	895	},
{	-808	,	-1611	,	896	},
{	-822	,	-1619	,	899	},
{	-834	,	-1620	,	898	},
{	-846	,	-1622	,	897	},
{	-859	,	-1627	,	899	},
{	-872	,	-1630	,	899	},
{	-885	,	-1634	,	900	},
{	-897	,	-1635	,	899	},
{	-911	,	-1638	,	900	},
{	-924	,	-1640	,	899	},
{	-938	,	-1644	,	901	},
{	-954	,	-1648	,	902	},
{	-965	,	-1649	,	902	},
{	-976	,	-1648	,	900	},
{	-986	,	-1645	,	897	},
{	-999	,	-1648	,	897	},
{	-1012	,	-1650	,	897	},
{	-1026	,	-1651	,	897	},
{	-1039	,	-1652	,	896	},
{	-1056	,	-1656	,	898	},
{	-1067	,	-1654	,	896	},
{	-1081	,	-1655	,	894	},
{	-1096	,	-1656	,	894	},
{	-1108	,	-1655	,	892	},
{	-1124	,	-1658	,	894	},
{	-1138	,	-1659	,	893	},
{	-1151	,	-1658	,	892	},
{	-1162	,	-1654	,	889	},
{	-1176	,	-1654	,	889	},
{	-1191	,	-1655	,	888	},
{	-1206	,	-1657	,	889	},
{	-1222	,	-1659	,	890	},
{	-1239	,	-1664	,	892	},
{	-1254	,	-1663	,	891	},
{	-1269	,	-1664	,	891	},
{	-1283	,	-1663	,	890	},
{	-1298	,	-1665	,	890	},
{	-1312	,	-1666	,	889	},
{	-1328	,	-1670	,	891	},
{	-1342	,	-1673	,	891	},
{	-1357	,	-1674	,	891	},
{	-1374	,	-1678	,	893	},
{	-1388	,	-1678	,	892	},
{	-1403	,	-1679	,	892	},
{	-1420	,	-1682	,	894	},
{	-1432	,	-1681	,	891	},
{	-1449	,	-1684	,	893	},
{	-1465	,	-1688	,	894	},
{	-1479	,	-1689	,	894	},
{	-1492	,	-1688	,	893	},
{	-1508	,	-1691	,	894	},
{	-1515	,	-1691	,	894	},
{	-1522	,	-1692	,	894	},
{	-1528	,	-1692	,	893	},
{	-1539	,	-1695	,	896	},
{	-1544	,	-1691	,	894	},
{	-1554	,	-1693	,	895	},
{	-1564	,	-1695	,	896	},
{	-1567	,	-1691	,	894	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11762)

int16_t accel_residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-2,-6,2},
{-2,-6,2},
{-2,-7,3},
{-2,-7,2},
{-2,-7,1},
{-3,-7,1},
{-2,-7,0},
{-2,-7,0},
{-2,-7,0},
{-1,-7,6},
{0,-7,12},
{0,-7,10},
{0,-8,8},
{0,-8,7},
{0,-8,7},
{0,-8,7},
{0,-8,7},
{0,-8,8},
{0,-8,7},
{0,-8,7},
{0,-9,7},
{1,-9,8},
{0,-9,8},
{0,-9,8},
{1,-9,9},
{1,-9,9},
{2,-9,9},
{1,-9,9},
{1,-9,10},
{2,-9,10},
{2,-9,10},
{2,-9,11},
{2,-9,11},
{2,-9,11},
{2,-9,11},
{2,-10,11},
{2,-10,12},
{3,-10,12},
{3,-10,12},
{3,-10,13},
{3,-10,13},
{3,-10,13},
{3,-10,13},
{3,-10,13},
{3,-11,14},
{3,-10,14},
{3,-10,15},
{4,-10,15},
{4,-10,15},
{4,-10,16},
{4,-10,16},
{4,-10,16},
{4,-11,17},
{5,-11,17},
{5,-11,17},
{5,-10,17},
{5,-10,17},
{5,-11,18},
{5,-11,18},
{6,-11,18},
{5,-11,19},
{5,-11,19},
{5,-11,19},
{5,-11,19},
{6,-11,20},
{5,-11,20},
{5,-11,20},
{6,-11,21},
{6,-11,21},
{6,-11,22},
{6,-11,22},
{5,-9,22},
{5,-8,23},
{6,-10,23},
{7,-11,23},
{7,-11,24},
{7,-11,24},
{7,-11,24},
{7,-11,24},
{7,-11,25},
{7,-10,25},
{7,-10,25},
{7,-10,25},
{7,-10,26},
{8,-10,26},
{8,-10,26},
{8,-10,27},
{8,-9,27},
{8,-9,27},
{8,-9,28},
{8,-8,28},
{8,-7,28},
{8,-8,28},
{9,-7,28},
{9,-7,29},
{9,-6,29},
{9,-6,29},
{9,-5,30},
{9,-5,30},
{9,-5,30},
{9,-4,30},
{9,-4,30},
{10,-4,30},
{9,-3,30},
{9,-3,30},
{9,-2,31},
{9,-2,31},
{9,-3,31},
{9,-3,31},
{9,-3,31},
{9,-3,31},
{9,-3,31},
{9,-3,30},
{9,-3,30},
{9,-3,30},
{9,-3,30},
{9,-3,30},
{9,-3,31},
{9,-3,31},
{9,-3,31},
{9,-3,31},
{9,-3,31},
{9,-3,31},
{9,-3,32},
{9,-3,32},
{9,-3,33},
{9,-3,33},
{9,-3,33},
{9,-3,34},
{9,-3,34},
{9,-3,35},
{9,-3,35},
{9,-3,36},
{9,-3,36},
{9,-3,37},
{9,-3,37},
{9,-3,38},
{9,-3,38},
{9,-3,39},
{9,-3,39},
{9,-3,40},
{10,-3,40},
{10,-3,41},
{9,-3,42},
{9,-3,42},
{10,-3,42},
{10,-3,43},
{10,-3,44},
{10,-3,44},
{10,-3,45},
{10,-3,45},
{10,-3,46},
{10,-3,46},
{10,-3,47},
{10,-3,48},
{10,-3,48},
{10,-3,49},
{10,-3,49},
{10,-4,50},
{10,-4,51},
{10,-4,51},
{10,-4,52},
{10,-4,52},
{10,-4,52},
{10,-5,53},
{10,-5,54},
{11,-5,54},
{11,-5,54},
{11,-5,55},
{11,-5,55},
{11,-5,56},
{11,-5,56},
{11,-5,57},
{11,-5,57},
{11,-6,58},
{11,-6,58},
{11,-6,58},
{11,-6,59},
{11,-6,59},
{11,-6,60},
{11,-6,60},
{11,-7,60},
{11,-7,61},
{11,-7,61},
{11,-7,61},
{11,-7,62},
{11,-7,62},
{11,-8,63},
{11,-8,63},
{11,-8,63},
{11,-8,64},
{11,-8,64},
{11,-9,64},
{11,-9,65},
{11,-9,65},
{11,-9,65},
{11,-9,66},
{12,-9,66},
{12,-10,66},
{12,-10,67},
{12,-10,67},
{12,-10,67},
{12,-10,68},
{12,-10,68},
{12,-10,69},
{12,-11,69},
{12,-11,70},
{12,-11,70},
{12,-11,70},
{12,-11,71},
{12,-11,71},
{13,-11,71},
{13,-12,72},
{13,-12,72},
{13,-12,72},
{13,-12,73},
{13,-12,73},
{13,-12,74},
{13,-13,74},
{13,-13,74},
{13,-13,75},
{13,-13,75},
{13,-13,75},
{13,-14,75},
{13,-14,76},
{13,-14,76},
{13,-14,77},
{13,-14,77},
{13,-14,77},
{13,-14,77},
{13,-14,78},
{13,-15,78},
{13,-15,78},
{13,-15,79},
{13,-15,79},
{13,-15,79},
{13,-15,80},
{13,-15,80},
{13,-15,81},
{13,-15,81},
{13,-15,82},
{13,-15,82},
{13,-15,83},
{13,-14,83},
{13,-14,84},
};




#endif	/* TABLE_LUGE7_SN194_H */

