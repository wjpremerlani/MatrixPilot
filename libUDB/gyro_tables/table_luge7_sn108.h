

#ifndef TABLE_LUGE7_SN108_H
#define	TABLE_LUGE7_SN108_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14289 )

int16_t residual_offset[] = { 1836 + 86, -642 -11 , 1038 - 11 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1761	,	1512	,	-434	},
{	-1752	,	1503	,	-434	},
{	-1748	,	1499	,	-433	},
{	-1745	,	1496	,	-434	},
{	-1741	,	1492	,	-435	},
{	-1733	,	1483	,	-434	},
{	-1727	,	1478	,	-435	},
{	-1725	,	1476	,	-436	},
{	-1719	,	1471	,	-438	},
{	-1710	,	1460	,	-439	},
{	-1705	,	1454	,	-442	},
{	-1698	,	1446	,	-445	},
{	-1683	,	1434	,	-447	},
{	-1672	,	1422	,	-448	},
{	-1662	,	1412	,	-450	},
{	-1650	,	1403	,	-453	},
{	-1641	,	1395	,	-456	},
{	-1634	,	1389	,	-459	},
{	-1627	,	1382	,	-462	},
{	-1616	,	1372	,	-464	},
{	-1604	,	1362	,	-466	},
{	-1594	,	1354	,	-469	},
{	-1584	,	1348	,	-472	},
{	-1580	,	1343	,	-475	},
{	-1567	,	1332	,	-478	},
{	-1558	,	1324	,	-482	},
{	-1550	,	1316	,	-485	},
{	-1536	,	1304	,	-486	},
{	-1531	,	1301	,	-490	},
{	-1522	,	1293	,	-491	},
{	-1514	,	1287	,	-495	},
{	-1505	,	1281	,	-499	},
{	-1497	,	1273	,	-502	},
{	-1485	,	1265	,	-505	},
{	-1478	,	1259	,	-509	},
{	-1468	,	1253	,	-512	},
{	-1459	,	1246	,	-515	},
{	-1451	,	1240	,	-520	},
{	-1444	,	1236	,	-523	},
{	-1437	,	1230	,	-526	},
{	-1426	,	1222	,	-529	},
{	-1420	,	1216	,	-533	},
{	-1411	,	1210	,	-536	},
{	-1404	,	1207	,	-540	},
{	-1397	,	1202	,	-544	},
{	-1382	,	1192	,	-547	},
{	-1374	,	1187	,	-552	},
{	-1361	,	1177	,	-555	},
{	-1351	,	1169	,	-558	},
{	-1341	,	1161	,	-560	},
{	-1332	,	1155	,	-564	},
{	-1320	,	1146	,	-568	},
{	-1310	,	1139	,	-572	},
{	-1304	,	1134	,	-578	},
{	-1291	,	1123	,	-580	},
{	-1279	,	1114	,	-583	},
{	-1271	,	1106	,	-588	},
{	-1259	,	1096	,	-591	},
{	-1250	,	1090	,	-595	},
{	-1239	,	1081	,	-598	},
{	-1229	,	1072	,	-600	},
{	-1220	,	1064	,	-602	},
{	-1216	,	1059	,	-607	},
{	-1205	,	1051	,	-611	},
{	-1196	,	1044	,	-614	},
{	-1188	,	1036	,	-617	},
{	-1181	,	1032	,	-622	},
{	-1169	,	1022	,	-624	},
{	-1161	,	1014	,	-628	},
{	-1150	,	1005	,	-629	},
{	-1141	,	997	,	-632	},
{	-1132	,	990	,	-636	},
{	-1123	,	981	,	-640	},
{	-1116	,	975	,	-645	},
{	-1107	,	967	,	-648	},
{	-1096	,	957	,	-650	},
{	-1089	,	950	,	-653	},
{	-1080	,	943	,	-658	},
{	-1070	,	934	,	-660	},
{	-1058	,	924	,	-662	},
{	-1050	,	917	,	-665	},
{	-1045	,	912	,	-669	},
{	-1039	,	906	,	-672	},
{	-1029	,	897	,	-672	},
{	-1023	,	892	,	-677	},
{	-1012	,	885	,	-679	},
{	-1008	,	880	,	-684	},
{	-999	,	873	,	-686	},
{	-993	,	868	,	-688	},
{	-987	,	862	,	-692	},
{	-978	,	855	,	-694	},
{	-972	,	851	,	-698	},
{	-964	,	846	,	-700	},
{	-958	,	842	,	-706	},
{	-951	,	836	,	-708	},
{	-946	,	831	,	-712	},
{	-941	,	828	,	-717	},
{	-935	,	822	,	-720	},
{	-926	,	815	,	-723	},
{	-919	,	808	,	-727	},
{	-913	,	801	,	-731	},
{	-907	,	794	,	-734	},
{	-903	,	789	,	-737	},
{	-895	,	782	,	-740	},
{	-892	,	777	,	-746	},
{	-887	,	769	,	-749	},
{	-883	,	764	,	-753	},
{	-877	,	757	,	-754	},
{	-873	,	751	,	-758	},
{	-870	,	743	,	-759	},
{	-866	,	736	,	-763	},
{	-863	,	730	,	-766	},
{	-859	,	725	,	-769	},
{	-854	,	716	,	-771	},
{	-853	,	711	,	-776	},
{	-849	,	705	,	-777	},
{	-848	,	700	,	-781	},
{	-847	,	696	,	-786	},
{	-845	,	691	,	-788	},
{	-842	,	684	,	-789	},
{	-843	,	680	,	-793	},
{	-842	,	673	,	-794	},
{	-843	,	671	,	-800	},
{	-842	,	666	,	-801	},
{	-845	,	663	,	-806	},
{	-844	,	658	,	-808	},
{	-846	,	657	,	-813	},
{	-847	,	653	,	-814	},
{	-846	,	649	,	-816	},
{	-850	,	647	,	-820	},
{	-854	,	647	,	-825	},
{	-855	,	643	,	-826	},
{	-858	,	640	,	-829	},
{	-860	,	639	,	-831	},
{	-863	,	636	,	-834	},
{	-869	,	636	,	-839	},
{	-876	,	637	,	-845	},
{	-878	,	636	,	-848	},
{	-883	,	636	,	-851	},
{	-888	,	636	,	-856	},
{	-893	,	637	,	-861	},
{	-898	,	637	,	-865	},
{	-904	,	637	,	-870	},
{	-911	,	638	,	-875	},
{	-918	,	639	,	-878	},
{	-925	,	640	,	-883	},
{	-932	,	641	,	-887	},
{	-938	,	640	,	-890	},
{	-949	,	644	,	-896	},
{	-956	,	646	,	-901	},
{	-966	,	649	,	-907	},
{	-976	,	652	,	-914	},
{	-984	,	654	,	-917	},
{	-991	,	655	,	-922	},
{	-1001	,	658	,	-928	},
{	-1010	,	661	,	-933	},
{	-1017	,	662	,	-937	},
{	-1028	,	666	,	-943	},
{	-1037	,	669	,	-948	},
{	-1045	,	672	,	-953	},
{	-1051	,	674	,	-956	},
{	-1056	,	675	,	-960	},
{	-1063	,	678	,	-966	},
{	-1070	,	681	,	-971	},
{	-1076	,	685	,	-978	},
{	-1081	,	686	,	-981	},
{	-1091	,	691	,	-989	},
{	-1094	,	692	,	-993	},
{	-1098	,	693	,	-998	},
{	-1103	,	694	,	-1002	},
{	-1109	,	697	,	-1008	},
{	-1114	,	701	,	-1014	},
{	-1117	,	701	,	-1018	},
{	-1122	,	705	,	-1024	},
{	-1124	,	705	,	-1027	},
{	-1127	,	705	,	-1031	},
{	-1132	,	707	,	-1037	},
{	-1135	,	708	,	-1042	},
{	-1142	,	711	,	-1051	},
{	-1149	,	714	,	-1058	},
{	-1149	,	712	,	-1059	},
{	-1154	,	713	,	-1064	},
{	-1155	,	714	,	-1068	},
{	-1158	,	714	,	-1073	},
{	-1161	,	715	,	-1079	},
{	-1166	,	716	,	-1084	},
{	-1171	,	719	,	-1092	},
{	-1171	,	716	,	-1093	},
{	-1173	,	716	,	-1097	},
{	-1177	,	717	,	-1102	},
{	-1181	,	718	,	-1108	},
{	-1185	,	720	,	-1114	},
{	-1190	,	722	,	-1122	},
{	-1193	,	722	,	-1125	},
{	-1197	,	723	,	-1130	},
{	-1200	,	723	,	-1133	},
{	-1204	,	723	,	-1137	},
{	-1209	,	725	,	-1143	},
{	-1211	,	725	,	-1146	},
{	-1218	,	727	,	-1153	},
{	-1220	,	725	,	-1154	},
{	-1227	,	727	,	-1161	},
{	-1229	,	726	,	-1162	},
{	-1233	,	727	,	-1164	},
{	-1240	,	729	,	-1171	},
{	-1246	,	730	,	-1175	},
{	-1252	,	732	,	-1181	},
{	-1255	,	731	,	-1183	},
{	-1259	,	731	,	-1186	},
{	-1264	,	731	,	-1189	},
{	-1267	,	732	,	-1194	},
{	-1273	,	733	,	-1198	},
{	-1279	,	734	,	-1203	},
{	-1282	,	734	,	-1207	},
{	-1286	,	735	,	-1210	},
{	-1291	,	735	,	-1214	},
{	-1293	,	734	,	-1217	},
{	-1301	,	734	,	-1223	},
{	-1304	,	733	,	-1226	},
{	-1311	,	736	,	-1233	},
{	-1316	,	736	,	-1237	},
{	-1322	,	738	,	-1242	},
{	-1325	,	737	,	-1244	},
{	-1329	,	737	,	-1246	},
{	-1331	,	737	,	-1248	},
{	-1337	,	739	,	-1254	},
{	-1341	,	739	,	-1256	},
{	-1344	,	740	,	-1259	},
{	-1350	,	742	,	-1265	},
{	-1353	,	742	,	-1270	},
{	-1356	,	742	,	-1272	},
{	-1361	,	743	,	-1279	},
{	-1363	,	743	,	-1282	},
{	-1371	,	745	,	-1289	},
{	-1374	,	747	,	-1295	},
{	-1378	,	750	,	-1300	},
{	-1383	,	751	,	-1306	},
{	-1386	,	752	,	-1311	},
{	-1388	,	752	,	-1315	},
{	-1392	,	754	,	-1322	},
{	-1397	,	756	,	-1330	},
{	-1399	,	756	,	-1334	},
{	-1404	,	758	,	-1341	},
{	-1405	,	758	,	-1344	},
{	-1407	,	758	,	-1348	},
{	-1410	,	759	,	-1353	},
{	-1410	,	759	,	-1355	},
{	-1413	,	759	,	-1360	},
{	-1421	,	762	,	-1368	},
{	-1427	,	764	,	-1374	},
{	-1431	,	764	,	-1378	},
{	-1432	,	762	,	-1378	},
{	-1432	,	760	,	-1378	},
{	-1434	,	760	,	-1382	},
{	-1439	,	761	,	-1388	},
{	-1443	,	761	,	-1392	},
{	-1446	,	760	,	-1394	},
{	-1449	,	759	,	-1397	},
{	-1457	,	762	,	-1406	},
{	-1457	,	760	,	-1405	},
{	-1461	,	759	,	-1408	},
{	-1467	,	760	,	-1414	},
{	-1470	,	759	,	-1415	},
{	-1472	,	757	,	-1417	},
{	-1479	,	759	,	-1423	},
{	-1476	,	754	,	-1420	},
{	-1481	,	755	,	-1425	},
{	-1483	,	755	,	-1427	},
{	-1489	,	756	,	-1434	},
{	-1496	,	758	,	-1442	},
{	-1497	,	757	,	-1442	},
{	-1496	,	754	,	-1442	},
{	-1497	,	754	,	-1443	},
{	-1502	,	754	,	-1449	},
{	-1504	,	753	,	-1452	},
{	-1505	,	753	,	-1454	},
{	-1510	,	753	,	-1460	},
{	-1512	,	753	,	-1463	},
{	-1514	,	753	,	-1466	},
{	-1518	,	754	,	-1472	},
{	-1528	,	757	,	-1481	},
{	-1530	,	757	,	-1485	},
{	-1536	,	759	,	-1493	},
{	-1540	,	759	,	-1498	},
{	-1540	,	758	,	-1500	},
{	-1543	,	758	,	-1504	},
{	-1547	,	759	,	-1509	},
{	-1552	,	759	,	-1515	},
{	-1557	,	760	,	-1521	},
{	-1561	,	761	,	-1526	},
{	-1563	,	761	,	-1528	},
{	-1567	,	762	,	-1533	},
{	-1571	,	762	,	-1537	},
{	-1572	,	761	,	-1540	},
{	-1577	,	762	,	-1545	},
{	-1579	,	761	,	-1547	},
{	-1581	,	760	,	-1549	},
{	-1585	,	760	,	-1554	},
{	-1587	,	759	,	-1557	},
{	-1586	,	758	,	-1557	},
{	-1589	,	758	,	-1561	},
{	-1598	,	761	,	-1570	},
{	-1599	,	760	,	-1572	},
{	-1601	,	759	,	-1574	},
{	-1603	,	759	,	-1577	},
{	-1611	,	761	,	-1584	},
{	-1616	,	760	,	-1588	},
{	-1619	,	760	,	-1591	},
{	-1624	,	761	,	-1598	},
{	-1625	,	760	,	-1601	},
{	-1629	,	760	,	-1606	},
{	-1631	,	759	,	-1609	},
{	-1636	,	760	,	-1616	},
{	-1644	,	762	,	-1626	},
{	-1647	,	763	,	-1631	},
{	-1652	,	764	,	-1637	},
{	-1657	,	765	,	-1643	},
{	-1661	,	765	,	-1649	},
{	-1658	,	762	,	-1648	},
{	-1663	,	762	,	-1653	},
{	-1667	,	762	,	-1660	},
{	-1672	,	762	,	-1667	},
{	-1673	,	761	,	-1670	},
{	-1674	,	761	,	-1675	},
{	-1677	,	761	,	-1679	},
{	-1679	,	760	,	-1681	},
{	-1682	,	760	,	-1685	},
{	-1688	,	760	,	-1691	},
{	-1693	,	761	,	-1695	},
{	-1698	,	761	,	-1701	},
{	-1702	,	761	,	-1705	},
{	-1703	,	760	,	-1707	},
{	-1706	,	758	,	-1708	},
{	-1708	,	757	,	-1712	},
{	-1711	,	756	,	-1714	},
{	-1716	,	757	,	-1720	},
{	-1721	,	757	,	-1725	},
{	-1726	,	756	,	-1728	},
{	-1728	,	755	,	-1729	},
{	-1736	,	756	,	-1736	},
{	-1737	,	754	,	-1737	},
{	-1745	,	754	,	-1744	},
{	-1747	,	753	,	-1747	},
{	-1749	,	751	,	-1749	},
{	-1754	,	750	,	-1754	},
{	-1762	,	750	,	-1761	},
{	-1763	,	747	,	-1759	},
{	-1764	,	745	,	-1760	},
{	-1766	,	741	,	-1760	},
{	-1771	,	740	,	-1763	},
{	-1777	,	738	,	-1767	},
{	-1780	,	736	,	-1768	},
{	-1781	,	733	,	-1767	},
{	-1786	,	731	,	-1769	},
{	-1788	,	728	,	-1769	},
{	-1793	,	726	,	-1772	},
{	-1794	,	723	,	-1771	},
{	-1800	,	721	,	-1775	},
{	-1796	,	716	,	-1772	},
{	-1794	,	710	,	-1769	},
{	-1800	,	708	,	-1774	},
{	-1799	,	705	,	-1772	},
{	-1797	,	703	,	-1769	},
{	-1799	,	702	,	-1772	},
{	-1799	,	699	,	-1769	},
{	-1801	,	698	,	-1772	},
{	-1800	,	696	,	-1771	},
{	-1801	,	694	,	-1771	},
{	-1799	,	691	,	-1770	}
};

#endif	/* TABLE_LUGE7_SN108_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -10976)

int16_t accel_residual_offset[] = { -12 , -4 , -16 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-2,3,-1},
{-2,3,-1},
{-2,3,-1},
{-2,2,0},
{-2,2,0},
{-2,2,0},
{-1,1,8},
{0,1,14},
{0,1,11},
{0,1,11},
{0,1,12},
{0,0,13},
{0,0,13},
{0,0,13},
{0,0,13},
{0,0,14},
{0,0,14},
{1,0,14},
{1,-1,14},
{1,-1,14},
{1,-2,15},
{1,-2,15},
{1,-2,15},
{1,-3,15},
{1,-3,15},
{1,-3,15},
{1,-4,15},
{1,-4,16},
{2,-4,16},
{2,-4,16},
{2,-5,16},
{2,-5,16},
{2,-6,16},
{2,-6,16},
{2,-6,16},
{2,-6,16},
{2,-6,16},
{2,-7,16},
{2,-7,17},
{2,-7,17},
{2,-7,17},
{2,-7,17},
{2,-7,17},
{3,-7,17},
{3,-8,17},
{3,-8,17},
{3,-8,18},
{3,-8,18},
{3,-8,18},
{3,-9,18},
{3,-9,19},
{3,-9,19},
{3,-10,19},
{3,-10,19},
{3,-10,20},
{3,-10,20},
{4,-10,20},
{4,-10,20},
{4,-10,21},
{4,-11,21},
{4,-11,21},
{4,-11,22},
{4,-11,22},
{4,-11,22},
{5,-11,23},
{5,-12,23},
{5,-12,23},
{5,-12,23},
{5,-12,23},
{5,-12,23},
{5,-12,23},
{5,-13,23},
{5,-13,24},
{5,-13,24},
{5,-13,24},
{5,-13,25},
{6,-13,25},
{6,-13,25},
{5,-13,26},
{5,-13,26},
{6,-13,27},
{6,-13,27},
{6,-13,27},
{7,-13,27},
{6,-13,27},
{6,-13,28},
{7,-13,28},
{7,-12,28},
{7,-12,29},
{7,-13,29},
{7,-13,29},
{7,-13,29},
{7,-12,30},
{7,-12,30},
{7,-12,30},
{7,-12,31},
{7,-12,31},
{7,-12,32},
{7,-12,32},
{7,-12,32},
{7,-12,32},
{7,-12,33},
{7,-12,33},
{7,-12,33},
{7,-12,34},
{7,-12,34},
{7,-13,35},
{7,-13,35},
{6,-13,35},
{6,-14,35},
{6,-14,35},
{6,-14,35},
{6,-14,35},
{6,-15,36},
{6,-15,36},
{6,-15,36},
{6,-16,36},
{6,-16,36},
{6,-16,36},
{6,-16,37},
{6,-16,37},
{6,-17,37},
{6,-17,37},
{6,-17,38},
{6,-17,38},
{6,-18,38},
{6,-18,38},
{6,-18,39},
{6,-18,39},
{6,-18,40},
{6,-18,40},
{6,-18,40},
{6,-18,41},
{6,-18,41},
{6,-19,41},
{6,-19,42},
{6,-19,42},
{6,-19,43},
{6,-19,43},
{6,-20,44},
{6,-20,44},
{6,-20,45},
{6,-20,45},
{6,-20,45},
{6,-20,46},
{6,-20,46},
{6,-21,47},
{6,-21,47},
{6,-21,48},
{6,-21,49},
{6,-21,49},
{6,-21,49},
{6,-21,50},
{6,-21,51},
{6,-21,51},
{6,-22,52},
{6,-22,52},
{6,-22,53},
{6,-22,54},
{6,-22,54},
{6,-22,55},
{6,-22,55},
{6,-22,56},
{6,-23,56},
{6,-23,57},
{6,-23,58},
{6,-23,58},
{6,-23,59},
{6,-23,59},
{6,-23,60},
{6,-23,60},
{6,-23,61},
{6,-24,62},
{6,-24,63},
{6,-24,63},
{6,-24,64},
{6,-24,65},
{6,-24,65},
{6,-24,66},
{6,-24,67},
{6,-25,68},
{6,-25,68},
{6,-25,69},
{6,-25,69},
{6,-25,70},
{6,-25,71},
{6,-25,71},
{6,-25,72},
{6,-26,73},
{6,-26,73},
{6,-26,74},
{6,-26,75},
{6,-26,76},
{6,-26,77},
{6,-26,77},
{6,-26,78},
{6,-27,79},
{6,-27,80},
{6,-27,80},
{6,-27,80},
{6,-27,80},
{6,-28,80},
{6,-28,81},
{6,-28,81},
{6,-28,81},
{6,-28,82},
{6,-28,82},
{6,-28,82},
{6,-28,83},
{6,-28,83},
{6,-29,83},
{7,-29,84},
{7,-29,84},
{6,-29,85},
{6,-29,85},
{6,-29,85},
{6,-29,86},
{6,-29,86},
{6,-29,87},
{6,-29,87},
{6,-29,88},
{6,-29,88},
{6,-29,89},
{6,-29,90},
{6,-29,91},
{6,-29,91},
{6,-29,92},
{6,-29,93},
{6,-29,94},
{6,-29,94},
{6,-29,95},
{6,-29,97},
{6,-29,98},
{6,-29,98},
{6,-29,99},
{5,-28,100},
};


