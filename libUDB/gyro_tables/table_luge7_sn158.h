

#ifndef TABLE_LUGE7_SN158_H
#define	TABLE_LUGE7_SN158_H

#define X_CROSS_COUPLING 20
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


// used in LUGE7_SN158 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -15052 )

int16_t residual_offset[] = { 169-305+16 , -88-160+4*93 , 496 -272-4*119} ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1789	,	1031	,	-1377	},
{	-1792	,	1031	,	-1380	},
{	-1789	,	1025	,	-1377	},
{	-1790	,	1022	,	-1378	},
{	-1788	,	1020	,	-1379	},
{	-1783	,	1016	,	-1377	},
{	-1780	,	1013	,	-1377	},
{	-1780	,	1011	,	-1379	},
{	-1777	,	1007	,	-1379	},
{	-1786	,	1008	,	-1388	},
{	-1781	,	1001	,	-1386	},
{	-1777	,	996	,	-1387	},
{	-1770	,	990	,	-1386	},
{	-1768	,	988	,	-1389	},
{	-1762	,	980	,	-1390	},
{	-1758	,	975	,	-1394	},
{	-1753	,	971	,	-1396	},
{	-1744	,	966	,	-1395	},
{	-1739	,	962	,	-1397	},
{	-1736	,	962	,	-1401	},
{	-1729	,	958	,	-1403	},
{	-1724	,	955	,	-1407	},
{	-1722	,	955	,	-1412	},
{	-1717	,	953	,	-1415	},
{	-1710	,	949	,	-1418	},
{	-1707	,	948	,	-1422	},
{	-1701	,	945	,	-1425	},
{	-1696	,	942	,	-1429	},
{	-1691	,	938	,	-1430	},
{	-1685	,	933	,	-1433	},
{	-1677	,	928	,	-1433	},
{	-1670	,	926	,	-1435	},
{	-1666	,	925	,	-1439	},
{	-1657	,	921	,	-1438	},
{	-1657	,	920	,	-1446	},
{	-1648	,	916	,	-1446	},
{	-1641	,	911	,	-1448	},
{	-1640	,	909	,	-1454	},
{	-1634	,	905	,	-1455	},
{	-1625	,	899	,	-1455	},
{	-1624	,	897	,	-1461	},
{	-1619	,	894	,	-1464	},
{	-1610	,	890	,	-1463	},
{	-1607	,	889	,	-1469	},
{	-1597	,	884	,	-1467	},
{	-1596	,	883	,	-1474	},
{	-1588	,	881	,	-1474	},
{	-1584	,	880	,	-1479	},
{	-1580	,	877	,	-1482	},
{	-1573	,	873	,	-1483	},
{	-1570	,	871	,	-1489	},
{	-1564	,	869	,	-1493	},
{	-1557	,	865	,	-1495	},
{	-1553	,	864	,	-1501	},
{	-1544	,	860	,	-1499	},
{	-1539	,	858	,	-1505	},
{	-1539	,	858	,	-1513	},
{	-1529	,	853	,	-1513	},
{	-1524	,	849	,	-1514	},
{	-1522	,	848	,	-1521	},
{	-1516	,	844	,	-1523	},
{	-1513	,	841	,	-1529	},
{	-1503	,	835	,	-1528	},
{	-1502	,	834	,	-1535	},
{	-1497	,	830	,	-1537	},
{	-1493	,	828	,	-1541	},
{	-1491	,	827	,	-1547	},
{	-1487	,	824	,	-1552	},
{	-1478	,	820	,	-1551	},
{	-1477	,	818	,	-1558	},
{	-1469	,	813	,	-1559	},
{	-1467	,	812	,	-1565	},
{	-1460	,	807	,	-1566	},
{	-1454	,	804	,	-1569	},
{	-1449	,	801	,	-1572	},
{	-1445	,	799	,	-1576	},
{	-1439	,	795	,	-1580	},
{	-1434	,	791	,	-1583	},
{	-1424	,	786	,	-1583	},
{	-1423	,	785	,	-1590	},
{	-1415	,	779	,	-1592	},
{	-1410	,	775	,	-1596	},
{	-1404	,	772	,	-1601	},
{	-1396	,	767	,	-1601	},
{	-1390	,	763	,	-1604	},
{	-1384	,	759	,	-1607	},
{	-1380	,	756	,	-1613	},
{	-1375	,	753	,	-1617	},
{	-1366	,	747	,	-1616	},
{	-1360	,	743	,	-1619	},
{	-1353	,	738	,	-1621	},
{	-1350	,	735	,	-1627	},
{	-1346	,	732	,	-1633	},
{	-1340	,	727	,	-1635	},
{	-1334	,	725	,	-1640	},
{	-1333	,	722	,	-1646	},
{	-1324	,	718	,	-1646	},
{	-1321	,	714	,	-1651	},
{	-1317	,	711	,	-1656	},
{	-1313	,	707	,	-1659	},
{	-1310	,	704	,	-1665	},
{	-1304	,	700	,	-1669	},
{	-1298	,	696	,	-1671	},
{	-1292	,	693	,	-1673	},
{	-1289	,	690	,	-1679	},
{	-1284	,	686	,	-1682	},
{	-1282	,	685	,	-1689	},
{	-1276	,	681	,	-1691	},
{	-1272	,	678	,	-1696	},
{	-1267	,	674	,	-1700	},
{	-1263	,	673	,	-1705	},
{	-1256	,	669	,	-1707	},
{	-1250	,	665	,	-1709	},
{	-1249	,	664	,	-1716	},
{	-1247	,	662	,	-1722	},
{	-1244	,	661	,	-1727	},
{	-1234	,	657	,	-1726	},
{	-1233	,	656	,	-1733	},
{	-1232	,	655	,	-1740	},
{	-1230	,	655	,	-1747	},
{	-1225	,	652	,	-1747	},
{	-1222	,	652	,	-1752	},
{	-1221	,	652	,	-1760	},
{	-1216	,	650	,	-1762	},
{	-1215	,	650	,	-1767	},
{	-1212	,	650	,	-1771	},
{	-1209	,	650	,	-1773	},
{	-1209	,	651	,	-1779	},
{	-1207	,	650	,	-1783	},
{	-1206	,	651	,	-1789	},
{	-1205	,	652	,	-1794	},
{	-1199	,	650	,	-1795	},
{	-1195	,	650	,	-1799	},
{	-1198	,	652	,	-1807	},
{	-1193	,	652	,	-1808	},
{	-1190	,	653	,	-1810	},
{	-1190	,	654	,	-1814	},
{	-1191	,	657	,	-1823	},
{	-1190	,	659	,	-1828	},
{	-1192	,	662	,	-1836	},
{	-1192	,	664	,	-1841	},
{	-1191	,	665	,	-1846	},
{	-1189	,	666	,	-1848	},
{	-1189	,	669	,	-1853	},
{	-1186	,	670	,	-1855	},
{	-1189	,	675	,	-1865	},
{	-1188	,	678	,	-1868	},
{	-1185	,	679	,	-1870	},
{	-1187	,	683	,	-1879	},
{	-1189	,	687	,	-1886	},
{	-1186	,	689	,	-1888	},
{	-1188	,	694	,	-1896	},
{	-1189	,	697	,	-1902	},
{	-1189	,	700	,	-1908	},
{	-1192	,	705	,	-1918	},
{	-1192	,	708	,	-1924	},
{	-1190	,	709	,	-1927	},
{	-1190	,	712	,	-1934	},
{	-1191	,	715	,	-1943	},
{	-1195	,	721	,	-1955	},
{	-1196	,	724	,	-1961	},
{	-1198	,	727	,	-1969	},
{	-1194	,	728	,	-1969	},
{	-1196	,	732	,	-1980	},
{	-1195	,	734	,	-1984	},
{	-1197	,	738	,	-1993	},
{	-1194	,	738	,	-1995	},
{	-1198	,	742	,	-2007	},
{	-1197	,	742	,	-2011	},
{	-1198	,	744	,	-2019	},
{	-1198	,	745	,	-2024	},
{	-1197	,	747	,	-2029	},
{	-1195	,	747	,	-2031	},
{	-1197	,	750	,	-2039	},
{	-1196	,	751	,	-2042	},
{	-1197	,	753	,	-2047	},
{	-1196	,	753	,	-2051	},
{	-1199	,	755	,	-2060	},
{	-1199	,	755	,	-2064	},
{	-1201	,	757	,	-2074	},
{	-1203	,	758	,	-2084	},
{	-1204	,	759	,	-2091	},
{	-1203	,	759	,	-2092	},
{	-1206	,	762	,	-2101	},
{	-1204	,	760	,	-2100	},
{	-1206	,	763	,	-2110	},
{	-1207	,	764	,	-2113	},
{	-1209	,	766	,	-2119	},
{	-1210	,	766	,	-2123	},
{	-1212	,	769	,	-2131	},
{	-1209	,	767	,	-2129	},
{	-1215	,	771	,	-2141	},
{	-1217	,	773	,	-2149	},
{	-1218	,	773	,	-2154	},
{	-1218	,	774	,	-2159	},
{	-1220	,	775	,	-2165	},
{	-1220	,	775	,	-2169	},
{	-1216	,	773	,	-2166	},
{	-1223	,	778	,	-2180	},
{	-1223	,	778	,	-2183	},
{	-1225	,	779	,	-2191	},
{	-1227	,	780	,	-2200	},
{	-1229	,	780	,	-2205	},
{	-1230	,	780	,	-2213	},
{	-1232	,	779	,	-2218	},
{	-1233	,	778	,	-2226	},
{	-1233	,	777	,	-2229	},
{	-1240	,	779	,	-2244	},
{	-1238	,	775	,	-2244	},
{	-1238	,	772	,	-2249	},
{	-1236	,	769	,	-2251	},
{	-1235	,	767	,	-2254	},
{	-1234	,	765	,	-2260	},
{	-1238	,	765	,	-2270	},
{	-1238	,	763	,	-2274	},
{	-1237	,	761	,	-2276	},
{	-1239	,	759	,	-2283	},
{	-1240	,	757	,	-2289	},
{	-1241	,	756	,	-2294	},
{	-1238	,	752	,	-2295	},
{	-1239	,	750	,	-2300	},
{	-1240	,	749	,	-2307	},
{	-1242	,	748	,	-2314	},
{	-1244	,	746	,	-2320	},
{	-1242	,	743	,	-2322	},
{	-1245	,	743	,	-2331	},
{	-1248	,	743	,	-2339	},
{	-1250	,	743	,	-2346	},
{	-1250	,	741	,	-2350	},
{	-1251	,	740	,	-2357	},
{	-1250	,	738	,	-2359	},
{	-1257	,	739	,	-2375	},
{	-1255	,	734	,	-2375	},
{	-1257	,	733	,	-2381	},
{	-1256	,	730	,	-2381	},
{	-1259	,	729	,	-2391	},
{	-1261	,	727	,	-2399	},
{	-1259	,	724	,	-2400	},
{	-1262	,	723	,	-2408	},
{	-1262	,	720	,	-2411	},
{	-1263	,	717	,	-2417	},
{	-1262	,	714	,	-2419	},
{	-1262	,	710	,	-2423	},
{	-1263	,	707	,	-2429	},
{	-1263	,	704	,	-2432	},
{	-1267	,	703	,	-2443	},
{	-1268	,	699	,	-2450	},
{	-1269	,	696	,	-2455	},
{	-1266	,	691	,	-2455	},
{	-1272	,	690	,	-2469	},
{	-1271	,	686	,	-2472	},
{	-1274	,	684	,	-2481	},
{	-1271	,	679	,	-2479	},
{	-1274	,	678	,	-2488	},
{	-1277	,	676	,	-2498	},
{	-1280	,	674	,	-2505	},
{	-1278	,	669	,	-2505	},
{	-1283	,	669	,	-2520	},
{	-1285	,	668	,	-2527	},
{	-1288	,	668	,	-2534	},
{	-1288	,	666	,	-2536	},
{	-1289	,	665	,	-2542	},
{	-1290	,	665	,	-2547	},
{	-1290	,	665	,	-2552	},
{	-1291	,	665	,	-2559	},
{	-1290	,	664	,	-2561	},
{	-1292	,	665	,	-2568	},
{	-1293	,	666	,	-2576	},
{	-1297	,	666	,	-2587	},
{	-1301	,	667	,	-2598	},
{	-1302	,	667	,	-2604	},
{	-1302	,	666	,	-2608	},
{	-1301	,	665	,	-2612	},
{	-1306	,	668	,	-2627	},
{	-1305	,	667	,	-2626	},
{	-1307	,	668	,	-2635	},
{	-1304	,	665	,	-2637	},
{	-1305	,	665	,	-2644	},
{	-1308	,	668	,	-2657	},
{	-1308	,	668	,	-2662	},
{	-1309	,	666	,	-2665	},
{	-1310	,	665	,	-2669	},
{	-1312	,	665	,	-2679	},
{	-1311	,	663	,	-2681	},
{	-1315	,	663	,	-2694	},
{	-1313	,	661	,	-2696	},
{	-1313	,	660	,	-2700	},
{	-1313	,	659	,	-2704	},
{	-1315	,	658	,	-2712	},
{	-1313	,	655	,	-2712	},
{	-1313	,	652	,	-2713	},
{	-1315	,	651	,	-2724	},
{	-1315	,	648	,	-2726	},
{	-1316	,	646	,	-2731	},
{	-1319	,	646	,	-2741	},
{	-1316	,	642	,	-2739	},
{	-1320	,	640	,	-2748	},
{	-1321	,	638	,	-2754	},
{	-1324	,	636	,	-2764	},
{	-1327	,	634	,	-2771	},
{	-1327	,	632	,	-2774	},
{	-1324	,	628	,	-2770	},
{	-1328	,	628	,	-2781	},
{	-1327	,	625	,	-2782	},
{	-1331	,	625	,	-2792	},
{	-1333	,	625	,	-2798	},
{	-1336	,	624	,	-2807	},
{	-1336	,	624	,	-2812	},
{	-1332	,	621	,	-2810	},
{	-1334	,	622	,	-2818	},
{	-1337	,	622	,	-2827	},
{	-1335	,	619	,	-2826	},
{	-1339	,	619	,	-2839	},
{	-1339	,	618	,	-2843	},
{	-1339	,	618	,	-2847	},
{	-1339	,	619	,	-2852	},
{	-1338	,	618	,	-2856	},
{	-1342	,	618	,	-2866	},
{	-1345	,	620	,	-2876	},
{	-1344	,	619	,	-2875	},
{	-1349	,	621	,	-2890	},
{	-1347	,	619	,	-2891	},
{	-1348	,	619	,	-2898	},
{	-1350	,	620	,	-2906	},
{	-1349	,	619	,	-2911	},
{	-1351	,	619	,	-2921	},
{	-1348	,	616	,	-2922	},
{	-1349	,	617	,	-2927	},
{	-1347	,	615	,	-2931	},
{	-1348	,	615	,	-2937	},
{	-1346	,	613	,	-2939	},
{	-1346	,	612	,	-2945	},
{	-1347	,	610	,	-2951	},
{	-1347	,	608	,	-2956	},
{	-1343	,	605	,	-2954	},
{	-1344	,	604	,	-2963	},
{	-1344	,	601	,	-2967	},
{	-1344	,	598	,	-2968	},
{	-1346	,	597	,	-2979	},
{	-1346	,	594	,	-2982	},
{	-1344	,	591	,	-2985	},
{	-1343	,	589	,	-2987	},
{	-1343	,	587	,	-2990	},
{	-1345	,	585	,	-2997	},
{	-1344	,	582	,	-2998	},
{	-1344	,	580	,	-3003	},
{	-1345	,	578	,	-3004	},
{	-1348	,	577	,	-3014	},
{	-1350	,	574	,	-3016	},
{	-1350	,	572	,	-3018	},
{	-1351	,	571	,	-3020	},
{	-1351	,	569	,	-3020	},
{	-1350	,	568	,	-3021	},
{	-1351	,	566	,	-3025	},
{	-1351	,	564	,	-3030	},
{	-1349	,	562	,	-3027	},
{	-1350	,	561	,	-3032	},
{	-1351	,	560	,	-3032	},
{	-1353	,	560	,	-3036	},
{	-1354	,	559	,	-3037	},
{	-1356	,	559	,	-3039	},
{	-1358	,	559	,	-3043	},
{	-1363	,	559	,	-3051	},
{	-1361	,	558	,	-3050	},
{	-1357	,	555	,	-3042	}
};

#endif	/* TABLE_LUGE7_SN158_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -10284)

int16_t accel_residual_offset[] = { 11-2,-53-5,-72 } ; 

//-2,-5,0

const struct gyro_offset_table_entry accel_offset_table[] = {
{0,5,-2},
{0,5,-2},
{0,5,9},
{1,5,18},
{1,5,15},
{1,5,14},
{1,4,14},
{2,4,15},
{2,4,16},
{2,4,16},
{2,3,17},
{3,3,17},
{2,4,18},
{2,3,19},
{3,3,20},
{3,3,20},
{3,3,22},
{3,2,23},
{2,2,23},
{2,1,24},
{2,1,26},
{3,2,26},
{3,2,26},
{3,2,27},
{3,2,27},
{3,1,28},
{4,1,29},
{4,1,29},
{3,1,29},
{3,0,30},
{4,0,31},
{3,0,32},
{3,0,33},
{4,0,33},
{4,0,33},
{4,0,34},
{4,0,35},
{4,0,36},
{4,0,36},
{4,0,36},
{4,0,37},
{4,0,37},
{4,0,38},
{4,0,38},
{4,0,38},
{5,0,39},
{5,0,39},
{5,0,40},
{5,0,41},
{5,0,41},
{5,0,41},
{5,0,42},
{4,0,43},
{4,0,43},
{5,0,44},
{5,0,45},
{5,0,45},
{5,0,45},
{5,0,46},
{5,0,46},
{5,0,47},
{5,0,47},
{5,0,48},
{5,0,49},
{5,1,49},
{5,1,50},
{5,1,51},
{5,1,51},
{5,1,52},
{5,1,52},
{5,1,53},
{5,2,53},
{5,2,53},
{5,2,53},
{5,2,54},
{4,1,54},
{4,1,54},
{5,1,54},
{5,1,55},
{4,1,55},
{4,1,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,55},
{4,0,56},
{4,0,56},
{4,0,56},
{4,0,56},
{4,0,57},
{4,0,57},
{4,0,57},
{4,-1,58},
{4,0,58},
{4,0,58},
{4,0,58},
{4,0,59},
{4,0,59},
{4,-1,60},
{4,-1,60},
{4,-1,60},
{4,-1,61},
{4,-1,61},
{4,-1,62},
{4,-1,62},
{4,-1,62},
{4,-1,63},
{4,-1,63},
{4,-1,63},
{4,-1,64},
{4,-1,64},
{4,-1,65},
{4,-1,65},
{4,-1,66},
{4,-1,66},
{4,-1,67},
{4,-2,67},
{4,-2,67},
{4,-2,68},
{4,-2,68},
{4,-2,69},
{4,-2,69},
{4,-2,69},
{4,-2,70},
{4,-2,71},
{4,-2,71},
{3,-2,72},
{3,-2,72},
{4,-3,72},
{4,-3,73},
{4,-3,73},
{4,-3,74},
{4,-3,74},
{4,-3,75},
{3,-3,76},
{3,-3,76},
{3,-3,77},
{3,-3,77},
{3,-3,78},
{3,-3,79},
{3,-4,79},
{3,-4,80},
{3,-3,80},
{3,-3,81},
{4,-4,82},
{3,-4,82},
{3,-4,83},
{3,-4,84},
{3,-4,84},
{3,-4,85},
{3,-4,86},
{3,-4,86},
{3,-5,87},
{3,-5,87},
{3,-5,87},
{3,-5,88},
{3,-5,88},
{3,-5,89},
{3,-5,89},
{3,-5,89},
{3,-5,90},
{3,-5,90},
{3,-6,91},
{3,-6,91},
{3,-6,92},
{3,-6,92},
{3,-6,92},
{3,-6,93},
{3,-6,94},
{3,-6,94},
{3,-6,95},
{3,-7,95},
{3,-7,96},
{3,-7,96},
{3,-7,97},
{3,-7,97},
{3,-7,97},
{3,-7,98},
{3,-7,98},
{3,-7,99},
{2,-8,100},
{2,-8,101},
{2,-8,101},
{2,-8,102},
{2,-8,103},
{2,-8,103},
{2,-8,104},
{2,-8,104},
{2,-8,105},
{2,-8,105},
{2,-8,106},
{2,-8,107},
{2,-8,108},
{2,-8,108},
{2,-8,109},
{2,-8,110},
{2,-8,110},
{2,-8,111},
{2,-8,112},
{1,-8,113},
{1,-8,114},
{1,-8,115},
{1,-8,116},
{1,-8,117},
{1,-7,118},
};



