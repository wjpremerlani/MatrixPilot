

#ifndef TABLE_LUGE7_SN186_H
#define	TABLE_LUGE7_SN186_H

// used in LUGE7_SN186 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14894 )

int16_t residual_offset[] = { -459 -4*38 , -4 +4*31, -103 -4*21} ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1783	,	1593	,	-72	},
{	-1781	,	1589	,	-72	},
{	-1772	,	1577	,	-72	},
{	-1764	,	1566	,	-73	},
{	-1762	,	1563	,	-72	},
{	-1753	,	1552	,	-73	},
{	-1750	,	1547	,	-74	},
{	-1749	,	1543	,	-75	},
{	-1743	,	1535	,	-76	},
{	-1739	,	1523	,	-76	},
{	-1729	,	1506	,	-77	},
{	-1719	,	1491	,	-78	},
{	-1711	,	1478	,	-80	},
{	-1705	,	1465	,	-82	},
{	-1699	,	1453	,	-83	},
{	-1686	,	1434	,	-84	},
{	-1677	,	1419	,	-85	},
{	-1670	,	1406	,	-86	},
{	-1661	,	1390	,	-87	},
{	-1654	,	1376	,	-88	},
{	-1652	,	1365	,	-90	},
{	-1642	,	1346	,	-92	},
{	-1638	,	1335	,	-94	},
{	-1630	,	1318	,	-95	},
{	-1620	,	1298	,	-97	},
{	-1613	,	1281	,	-99	},
{	-1609	,	1267	,	-100	},
{	-1603	,	1255	,	-103	},
{	-1602	,	1242	,	-105	},
{	-1591	,	1224	,	-107	},
{	-1583	,	1208	,	-109	},
{	-1573	,	1192	,	-111	},
{	-1570	,	1181	,	-113	},
{	-1564	,	1167	,	-115	},
{	-1556	,	1150	,	-116	},
{	-1548	,	1134	,	-118	},
{	-1541	,	1119	,	-120	},
{	-1534	,	1104	,	-122	},
{	-1527	,	1090	,	-124	},
{	-1522	,	1076	,	-126	},
{	-1515	,	1063	,	-129	},
{	-1507	,	1049	,	-131	},
{	-1501	,	1037	,	-132	},
{	-1493	,	1021	,	-133	},
{	-1486	,	1006	,	-135	},
{	-1477	,	989	,	-137	},
{	-1470	,	975	,	-139	},
{	-1465	,	961	,	-141	},
{	-1457	,	943	,	-142	},
{	-1449	,	927	,	-143	},
{	-1442	,	912	,	-145	},
{	-1433	,	895	,	-147	},
{	-1427	,	881	,	-149	},
{	-1423	,	868	,	-152	},
{	-1413	,	851	,	-154	},
{	-1406	,	834	,	-156	},
{	-1396	,	816	,	-158	},
{	-1389	,	799	,	-158	},
{	-1387	,	785	,	-159	},
{	-1379	,	768	,	-162	},
{	-1371	,	753	,	-164	},
{	-1361	,	735	,	-166	},
{	-1354	,	719	,	-168	},
{	-1346	,	704	,	-171	},
{	-1335	,	686	,	-172	},
{	-1332	,	674	,	-173	},
{	-1325	,	658	,	-175	},
{	-1318	,	643	,	-177	},
{	-1311	,	629	,	-178	},
{	-1306	,	614	,	-180	},
{	-1295	,	597	,	-180	},
{	-1291	,	583	,	-183	},
{	-1284	,	567	,	-183	},
{	-1279	,	553	,	-184	},
{	-1273	,	537	,	-185	},
{	-1261	,	520	,	-186	},
{	-1253	,	505	,	-186	},
{	-1249	,	489	,	-187	},
{	-1243	,	474	,	-189	},
{	-1237	,	458	,	-190	},
{	-1229	,	442	,	-191	},
{	-1224	,	427	,	-192	},
{	-1215	,	410	,	-192	},
{	-1208	,	394	,	-195	},
{	-1204	,	379	,	-196	},
{	-1196	,	361	,	-198	},
{	-1189	,	345	,	-200	},
{	-1186	,	329	,	-202	},
{	-1177	,	312	,	-202	},
{	-1175	,	297	,	-205	},
{	-1168	,	280	,	-207	},
{	-1161	,	266	,	-210	},
{	-1157	,	249	,	-213	},
{	-1153	,	234	,	-215	},
{	-1147	,	217	,	-218	},
{	-1142	,	202	,	-220	},
{	-1138	,	187	,	-221	},
{	-1134	,	172	,	-223	},
{	-1130	,	157	,	-224	},
{	-1125	,	141	,	-226	},
{	-1123	,	127	,	-228	},
{	-1117	,	111	,	-230	},
{	-1118	,	97	,	-232	},
{	-1112	,	83	,	-233	},
{	-1107	,	68	,	-235	},
{	-1103	,	54	,	-237	},
{	-1097	,	41	,	-238	},
{	-1092	,	26	,	-239	},
{	-1090	,	11	,	-241	},
{	-1089	,	-2	,	-243	},
{	-1085	,	-17	,	-244	},
{	-1084	,	-30	,	-247	},
{	-1082	,	-45	,	-250	},
{	-1078	,	-60	,	-252	},
{	-1075	,	-74	,	-253	},
{	-1074	,	-89	,	-257	},
{	-1069	,	-102	,	-260	},
{	-1065	,	-116	,	-263	},
{	-1061	,	-130	,	-266	},
{	-1057	,	-145	,	-269	},
{	-1055	,	-159	,	-272	},
{	-1055	,	-173	,	-274	},
{	-1052	,	-187	,	-277	},
{	-1051	,	-202	,	-280	},
{	-1052	,	-216	,	-284	},
{	-1049	,	-229	,	-286	},
{	-1049	,	-243	,	-290	},
{	-1047	,	-255	,	-294	},
{	-1043	,	-268	,	-295	},
{	-1043	,	-281	,	-297	},
{	-1041	,	-294	,	-299	},
{	-1041	,	-307	,	-302	},
{	-1038	,	-319	,	-303	},
{	-1041	,	-333	,	-306	},
{	-1038	,	-347	,	-309	},
{	-1040	,	-360	,	-312	},
{	-1038	,	-372	,	-313	},
{	-1041	,	-384	,	-316	},
{	-1041	,	-396	,	-317	},
{	-1045	,	-409	,	-321	},
{	-1044	,	-419	,	-323	},
{	-1044	,	-430	,	-326	},
{	-1049	,	-445	,	-330	},
{	-1049	,	-458	,	-332	},
{	-1049	,	-470	,	-334	},
{	-1053	,	-482	,	-337	},
{	-1056	,	-495	,	-341	},
{	-1057	,	-506	,	-344	},
{	-1060	,	-519	,	-348	},
{	-1066	,	-531	,	-352	},
{	-1069	,	-542	,	-355	},
{	-1076	,	-554	,	-359	},
{	-1079	,	-564	,	-362	},
{	-1085	,	-575	,	-366	},
{	-1087	,	-585	,	-369	},
{	-1092	,	-594	,	-374	},
{	-1094	,	-603	,	-376	},
{	-1102	,	-615	,	-380	},
{	-1109	,	-626	,	-384	},
{	-1112	,	-632	,	-386	},
{	-1116	,	-641	,	-389	},
{	-1126	,	-651	,	-393	},
{	-1130	,	-658	,	-395	},
{	-1135	,	-667	,	-398	},
{	-1146	,	-677	,	-403	},
{	-1150	,	-683	,	-405	},
{	-1157	,	-690	,	-408	},
{	-1162	,	-696	,	-411	},
{	-1168	,	-705	,	-413	},
{	-1174	,	-713	,	-416	},
{	-1180	,	-722	,	-418	},
{	-1187	,	-732	,	-422	},
{	-1195	,	-741	,	-425	},
{	-1202	,	-749	,	-427	},
{	-1208	,	-757	,	-431	},
{	-1212	,	-763	,	-434	},
{	-1217	,	-770	,	-436	},
{	-1223	,	-778	,	-438	},
{	-1229	,	-787	,	-441	},
{	-1236	,	-798	,	-444	},
{	-1240	,	-806	,	-447	},
{	-1245	,	-815	,	-449	},
{	-1253	,	-824	,	-452	},
{	-1256	,	-832	,	-455	},
{	-1263	,	-843	,	-459	},
{	-1268	,	-852	,	-462	},
{	-1275	,	-861	,	-464	},
{	-1281	,	-871	,	-467	},
{	-1286	,	-881	,	-471	},
{	-1292	,	-892	,	-473	},
{	-1295	,	-902	,	-477	},
{	-1299	,	-911	,	-480	},
{	-1302	,	-922	,	-483	},
{	-1306	,	-932	,	-487	},
{	-1310	,	-942	,	-490	},
{	-1314	,	-950	,	-494	},
{	-1318	,	-959	,	-499	},
{	-1325	,	-971	,	-504	},
{	-1327	,	-980	,	-508	},
{	-1329	,	-990	,	-513	},
{	-1334	,	-1001	,	-517	},
{	-1338	,	-1012	,	-520	},
{	-1342	,	-1022	,	-524	},
{	-1344	,	-1031	,	-528	},
{	-1348	,	-1043	,	-534	},
{	-1351	,	-1053	,	-539	},
{	-1351	,	-1061	,	-543	},
{	-1358	,	-1073	,	-548	},
{	-1364	,	-1085	,	-553	},
{	-1369	,	-1096	,	-557	},
{	-1376	,	-1109	,	-562	},
{	-1379	,	-1120	,	-565	},
{	-1380	,	-1130	,	-569	},
{	-1385	,	-1140	,	-573	},
{	-1388	,	-1150	,	-577	},
{	-1392	,	-1159	,	-580	},
{	-1396	,	-1168	,	-584	},
{	-1402	,	-1176	,	-588	},
{	-1407	,	-1183	,	-592	},
{	-1413	,	-1192	,	-596	},
{	-1419	,	-1201	,	-601	},
{	-1422	,	-1207	,	-603	},
{	-1426	,	-1213	,	-606	},
{	-1428	,	-1220	,	-608	},
{	-1433	,	-1230	,	-612	},
{	-1435	,	-1236	,	-614	},
{	-1439	,	-1243	,	-617	},
{	-1440	,	-1247	,	-619	},
{	-1444	,	-1255	,	-624	},
{	-1449	,	-1263	,	-627	},
{	-1453	,	-1271	,	-630	},
{	-1455	,	-1277	,	-632	},
{	-1457	,	-1283	,	-634	},
{	-1461	,	-1293	,	-637	},
{	-1463	,	-1303	,	-639	},
{	-1468	,	-1315	,	-643	},
{	-1468	,	-1323	,	-644	},
{	-1473	,	-1334	,	-648	},
{	-1476	,	-1341	,	-650	},
{	-1482	,	-1353	,	-654	},
{	-1491	,	-1367	,	-659	},
{	-1492	,	-1372	,	-660	},
{	-1497	,	-1381	,	-663	},
{	-1500	,	-1389	,	-666	},
{	-1506	,	-1399	,	-670	},
{	-1512	,	-1412	,	-674	},
{	-1519	,	-1423	,	-678	},
{	-1521	,	-1431	,	-682	},
{	-1524	,	-1441	,	-685	},
{	-1531	,	-1453	,	-689	},
{	-1534	,	-1461	,	-693	},
{	-1535	,	-1468	,	-695	},
{	-1537	,	-1476	,	-698	},
{	-1542	,	-1486	,	-703	},
{	-1545	,	-1495	,	-705	},
{	-1553	,	-1508	,	-711	},
{	-1552	,	-1514	,	-713	},
{	-1550	,	-1519	,	-713	},
{	-1556	,	-1529	,	-717	},
{	-1558	,	-1537	,	-721	},
{	-1562	,	-1547	,	-724	},
{	-1563	,	-1555	,	-727	},
{	-1567	,	-1563	,	-731	},
{	-1571	,	-1571	,	-735	},
{	-1575	,	-1579	,	-738	},
{	-1576	,	-1585	,	-740	},
{	-1580	,	-1594	,	-743	},
{	-1586	,	-1604	,	-748	},
{	-1593	,	-1617	,	-754	},
{	-1598	,	-1626	,	-758	},
{	-1597	,	-1631	,	-760	},
{	-1603	,	-1641	,	-765	},
{	-1601	,	-1645	,	-767	},
{	-1608	,	-1657	,	-771	},
{	-1615	,	-1668	,	-776	},
{	-1615	,	-1675	,	-778	},
{	-1617	,	-1684	,	-782	},
{	-1620	,	-1694	,	-786	},
{	-1626	,	-1703	,	-790	},
{	-1625	,	-1708	,	-792	},
{	-1626	,	-1716	,	-795	},
{	-1630	,	-1727	,	-799	},
{	-1634	,	-1735	,	-802	},
{	-1639	,	-1746	,	-807	},
{	-1640	,	-1753	,	-809	},
{	-1643	,	-1762	,	-813	},
{	-1642	,	-1765	,	-814	},
{	-1652	,	-1779	,	-820	},
{	-1650	,	-1783	,	-821	},
{	-1659	,	-1795	,	-826	},
{	-1660	,	-1799	,	-829	},
{	-1662	,	-1808	,	-832	},
{	-1670	,	-1820	,	-838	},
{	-1675	,	-1826	,	-841	},
{	-1683	,	-1835	,	-846	},
{	-1689	,	-1844	,	-849	},
{	-1696	,	-1853	,	-853	},
{	-1700	,	-1859	,	-855	},
{	-1701	,	-1861	,	-855	},
{	-1709	,	-1874	,	-860	},
{	-1713	,	-1883	,	-863	},
{	-1720	,	-1893	,	-867	},
{	-1721	,	-1897	,	-868	},
{	-1731	,	-1910	,	-874	},
{	-1730	,	-1914	,	-874	},
{	-1741	,	-1928	,	-878	},
{	-1742	,	-1932	,	-878	},
{	-1747	,	-1940	,	-880	},
{	-1752	,	-1948	,	-883	},
{	-1757	,	-1958	,	-885	},
{	-1761	,	-1967	,	-887	},
{	-1764	,	-1975	,	-889	},
{	-1769	,	-1985	,	-892	},
{	-1774	,	-1995	,	-892	},
{	-1779	,	-2006	,	-894	},
{	-1790	,	-2020	,	-897	},
{	-1796	,	-2028	,	-897	},
{	-1800	,	-2035	,	-897	},
{	-1810	,	-2047	,	-899	},
{	-1819	,	-2057	,	-899	},
{	-1826	,	-2066	,	-899	},
{	-1831	,	-2072	,	-898	},
{	-1832	,	-2074	,	-897	},
{	-1836	,	-2081	,	-898	},
{	-1843	,	-2089	,	-900	},
{	-1847	,	-2094	,	-900	},
{	-1850	,	-2095	,	-898	},
{	-1858	,	-2103	,	-899	},
{	-1861	,	-2107	,	-897	},
{	-1864	,	-2110	,	-894	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -12481)

int16_t accel_residual_offset[] = { -4 , -58 , -121 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{0,-3,4},
{0,-3,4},
{-1,-3,3},
{-1,-3,1},
{0,-3,0},
{0,-3,0},
{0,-2,0},
{0,-2,0},
{0,-3,-1},
{-1,-3,-1},
{-1,-2,-2},
{0,-2,6},
{2,-3,11},
{2,-3,7},
{2,-3,6},
{2,-2,6},
{3,-2,6},
{3,-2,6},
{3,-3,6},
{3,-3,6},
{4,-3,6},
{3,-2,6},
{3,-2,6},
{4,-2,6},
{4,-2,7},
{5,-2,7},
{5,-2,8},
{5,-2,8},
{5,-2,8},
{5,-2,8},
{5,-2,8},
{5,-2,9},
{5,-2,9},
{5,-3,10},
{5,-2,10},
{6,-2,10},
{6,-2,11},
{6,-2,11},
{7,-2,11},
{7,-1,12},
{7,-1,12},
{8,-2,12},
{8,-2,12},
{8,-2,13},
{8,-2,13},
{8,-1,14},
{8,-1,14},
{8,-1,14},
{9,-1,15},
{8,-1,15},
{8,-2,15},
{9,-2,16},
{9,-2,16},
{9,-2,16},
{10,-2,16},
{10,-2,17},
{10,-2,17},
{10,-2,17},
{11,-1,18},
{10,-1,18},
{10,-1,18},
{11,-1,18},
{11,-1,19},
{11,-1,19},
{12,-1,19},
{12,-1,19},
{12,-1,20},
{12,-1,20},
{12,-1,20},
{12,-1,21},
{12,-1,21},
{13,-1,21},
{13,-1,21},
{13,-1,22},
{13,-1,22},
{13,-1,23},
{14,-1,23},
{14,-1,23},
{14,-1,24},
{14,-1,24},
{14,0,24},
{14,0,24},
{14,0,25},
{14,0,25},
{14,0,26},
{15,0,26},
{15,0,26},
{15,0,27},
{15,0,27},
{16,0,27},
{16,0,27},
{16,0,27},
{16,0,28},
{16,0,28},
{16,1,29},
{17,1,29},
{17,1,29},
{17,1,30},
{17,1,30},
{17,2,30},
{17,2,30},
{18,2,30},
{18,3,31},
{18,3,31},
{18,3,31},
{18,4,31},
{18,4,32},
{18,4,32},
{18,5,32},
{19,5,33},
{19,5,33},
{19,5,33},
{19,5,33},
{19,5,33},
{19,5,33},
{19,6,33},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,34},
{19,5,35},
{19,5,35},
{19,5,35},
{19,5,35},
{19,5,36},
{19,5,36},
{19,5,36},
{19,5,37},
{19,5,37},
{19,5,37},
{19,5,38},
{19,5,38},
{19,5,38},
{19,5,39},
{19,5,39},
{19,5,39},
{19,4,39},
{19,4,40},
{19,4,40},
{19,4,41},
{19,4,41},
{19,4,41},
{19,4,41},
{19,4,42},
{19,4,42},
{19,4,42},
{19,4,43},
{19,4,43},
{19,4,43},
{19,3,43},
{19,3,44},
{19,3,44},
{19,3,44},
{19,3,45},
{19,3,45},
{19,3,46},
{19,2,46},
{19,2,46},
{20,2,46},
{20,2,46},
{20,2,47},
{20,1,47},
{20,1,47},
{20,1,48},
{20,1,48},
{20,1,48},
{20,1,48},
{20,1,49},
{20,0,49},
{20,0,49},
{20,0,49},
{20,0,50},
{20,0,50},
{20,0,50},
{19,0,50},
{19,0,51},
{19,0,51},
{19,0,51},
{19,0,51},
{19,0,51},
{19,-1,52},
{19,-1,52},
{19,-1,52},
{20,-1,52},
{20,-1,52},
{20,-2,52},
{19,-2,53},
{19,-2,53},
{19,-2,53},
{19,-2,53},
{19,-2,53},
{19,-3,53},
{19,-3,54},
{19,-3,54},
{19,-3,54},
{19,-3,54},
{19,-4,54},
{19,-4,54},
{19,-5,54},
{19,-5,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-7,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-7,54},
{19,-7,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-7,54},
{19,-7,54},
{19,-7,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,54},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,53},
{19,-6,54},
{18,-6,54},
{18,-6,54},
{18,-5,54},
{18,-5,54},
{18,-5,54},
};



#endif	/* TABLE_LUGE7_SN186_H */

