

#ifndef TABLE_LUGE7_SN173_H
#define	TABLE_LUGE7_SN173_H

// used in LUGE7_SN173 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14615 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1814	,	-1405	,	-425	},
{	-1798	,	-1396	,	-422	},
{	-1796	,	-1397	,	-423	},
{	-1790	,	-1395	,	-423	},
{	-1782	,	-1392	,	-422	},
{	-1776	,	-1391	,	-422	},
{	-1773	,	-1391	,	-423	},
{	-1767	,	-1390	,	-423	},
{	-1762	,	-1389	,	-423	},
{	-1760	,	-1393	,	-423	},
{	-1747	,	-1389	,	-422	},
{	-1738	,	-1386	,	-423	},
{	-1729	,	-1384	,	-423	},
{	-1718	,	-1380	,	-421	},
{	-1703	,	-1375	,	-420	},
{	-1695	,	-1372	,	-419	},
{	-1683	,	-1369	,	-419	},
{	-1667	,	-1363	,	-417	},
{	-1663	,	-1365	,	-419	},
{	-1646	,	-1358	,	-417	},
{	-1634	,	-1355	,	-416	},
{	-1626	,	-1354	,	-416	},
{	-1615	,	-1352	,	-414	},
{	-1600	,	-1345	,	-412	},
{	-1590	,	-1342	,	-411	},
{	-1578	,	-1336	,	-411	},
{	-1568	,	-1336	,	-411	},
{	-1555	,	-1332	,	-410	},
{	-1542	,	-1327	,	-408	},
{	-1525	,	-1319	,	-406	},
{	-1514	,	-1318	,	-408	},
{	-1502	,	-1314	,	-407	},
{	-1488	,	-1310	,	-407	},
{	-1471	,	-1304	,	-406	},
{	-1462	,	-1302	,	-406	},
{	-1449	,	-1298	,	-406	},
{	-1442	,	-1297	,	-407	},
{	-1432	,	-1294	,	-406	},
{	-1421	,	-1290	,	-406	},
{	-1410	,	-1287	,	-407	},
{	-1403	,	-1288	,	-408	},
{	-1388	,	-1283	,	-408	},
{	-1377	,	-1282	,	-409	},
{	-1365	,	-1277	,	-408	},
{	-1356	,	-1275	,	-409	},
{	-1344	,	-1271	,	-408	},
{	-1335	,	-1269	,	-409	},
{	-1323	,	-1267	,	-409	},
{	-1311	,	-1263	,	-409	},
{	-1298	,	-1259	,	-408	},
{	-1290	,	-1259	,	-408	},
{	-1275	,	-1254	,	-408	},
{	-1267	,	-1254	,	-408	},
{	-1253	,	-1249	,	-407	},
{	-1240	,	-1246	,	-406	},
{	-1225	,	-1243	,	-406	},
{	-1213	,	-1240	,	-406	},
{	-1199	,	-1236	,	-405	},
{	-1189	,	-1234	,	-405	},
{	-1179	,	-1235	,	-406	},
{	-1165	,	-1231	,	-405	},
{	-1151	,	-1228	,	-404	},
{	-1143	,	-1230	,	-405	},
{	-1131	,	-1227	,	-404	},
{	-1118	,	-1222	,	-404	},
{	-1109	,	-1223	,	-405	},
{	-1097	,	-1219	,	-406	},
{	-1086	,	-1217	,	-405	},
{	-1075	,	-1215	,	-405	},
{	-1063	,	-1210	,	-404	},
{	-1054	,	-1210	,	-405	},
{	-1043	,	-1209	,	-406	},
{	-1035	,	-1206	,	-405	},
{	-1027	,	-1206	,	-406	},
{	-1016	,	-1203	,	-405	},
{	-1005	,	-1201	,	-404	},
{	-990	,	-1195	,	-403	},
{	-982	,	-1196	,	-405	},
{	-972	,	-1195	,	-406	},
{	-962	,	-1192	,	-406	},
{	-954	,	-1191	,	-407	},
{	-944	,	-1190	,	-407	},
{	-935	,	-1189	,	-407	},
{	-926	,	-1188	,	-406	},
{	-917	,	-1189	,	-406	},
{	-909	,	-1189	,	-405	},
{	-900	,	-1188	,	-407	},
{	-890	,	-1188	,	-408	},
{	-884	,	-1190	,	-409	},
{	-876	,	-1190	,	-410	},
{	-864	,	-1187	,	-410	},
{	-856	,	-1186	,	-409	},
{	-849	,	-1188	,	-411	},
{	-843	,	-1188	,	-411	},
{	-833	,	-1187	,	-410	},
{	-826	,	-1187	,	-409	},
{	-817	,	-1186	,	-408	},
{	-808	,	-1185	,	-407	},
{	-802	,	-1188	,	-408	},
{	-793	,	-1189	,	-408	},
{	-786	,	-1191	,	-409	},
{	-779	,	-1191	,	-409	},
{	-771	,	-1191	,	-409	},
{	-763	,	-1191	,	-408	},
{	-756	,	-1190	,	-407	},
{	-747	,	-1188	,	-404	},
{	-740	,	-1188	,	-403	},
{	-734	,	-1189	,	-402	},
{	-729	,	-1192	,	-402	},
{	-720	,	-1188	,	-399	},
{	-717	,	-1191	,	-399	},
{	-713	,	-1192	,	-398	},
{	-707	,	-1191	,	-396	},
{	-702	,	-1194	,	-395	},
{	-696	,	-1194	,	-394	},
{	-692	,	-1193	,	-392	},
{	-686	,	-1190	,	-389	},
{	-684	,	-1192	,	-388	},
{	-680	,	-1193	,	-386	},
{	-675	,	-1192	,	-384	},
{	-671	,	-1193	,	-383	},
{	-667	,	-1194	,	-383	},
{	-662	,	-1195	,	-383	},
{	-659	,	-1195	,	-383	},
{	-654	,	-1193	,	-382	},
{	-649	,	-1191	,	-380	},
{	-648	,	-1193	,	-380	},
{	-644	,	-1191	,	-379	},
{	-643	,	-1193	,	-379	},
{	-639	,	-1192	,	-379	},
{	-636	,	-1191	,	-379	},
{	-634	,	-1189	,	-378	},
{	-632	,	-1191	,	-378	},
{	-630	,	-1190	,	-377	},
{	-627	,	-1185	,	-376	},
{	-626	,	-1184	,	-376	},
{	-627	,	-1184	,	-375	},
{	-627	,	-1181	,	-374	},
{	-626	,	-1177	,	-372	},
{	-627	,	-1178	,	-372	},
{	-627	,	-1175	,	-371	},
{	-629	,	-1176	,	-371	},
{	-630	,	-1176	,	-371	},
{	-630	,	-1173	,	-371	},
{	-632	,	-1172	,	-372	},
{	-632	,	-1167	,	-372	},
{	-634	,	-1165	,	-371	},
{	-637	,	-1163	,	-372	},
{	-642	,	-1163	,	-373	},
{	-644	,	-1159	,	-373	},
{	-648	,	-1156	,	-371	},
{	-653	,	-1155	,	-372	},
{	-657	,	-1151	,	-373	},
{	-660	,	-1147	,	-373	},
{	-663	,	-1144	,	-372	},
{	-671	,	-1144	,	-374	},
{	-674	,	-1137	,	-373	},
{	-679	,	-1132	,	-373	},
{	-684	,	-1126	,	-373	},
{	-689	,	-1120	,	-372	},
{	-696	,	-1116	,	-372	},
{	-700	,	-1111	,	-370	},
{	-706	,	-1105	,	-369	},
{	-713	,	-1099	,	-370	},
{	-719	,	-1092	,	-369	},
{	-727	,	-1087	,	-370	},
{	-733	,	-1080	,	-371	},
{	-740	,	-1076	,	-375	},
{	-746	,	-1069	,	-374	},
{	-750	,	-1061	,	-373	},
{	-758	,	-1057	,	-373	},
{	-766	,	-1053	,	-375	},
{	-768	,	-1042	,	-374	},
{	-775	,	-1039	,	-374	},
{	-780	,	-1033	,	-373	},
{	-786	,	-1028	,	-372	},
{	-793	,	-1025	,	-373	},
{	-797	,	-1017	,	-372	},
{	-801	,	-1011	,	-371	},
{	-804	,	-1005	,	-371	},
{	-808	,	-1003	,	-371	},
{	-811	,	-996	,	-369	},
{	-814	,	-993	,	-368	},
{	-819	,	-991	,	-367	},
{	-822	,	-987	,	-366	},
{	-826	,	-983	,	-366	},
{	-831	,	-982	,	-366	},
{	-835	,	-977	,	-366	},
{	-837	,	-973	,	-365	},
{	-842	,	-969	,	-365	},
{	-848	,	-966	,	-365	},
{	-852	,	-963	,	-365	},
{	-855	,	-960	,	-365	},
{	-858	,	-954	,	-365	},
{	-862	,	-952	,	-365	},
{	-867	,	-949	,	-365	},
{	-874	,	-949	,	-366	},
{	-878	,	-946	,	-365	},
{	-886	,	-946	,	-366	},
{	-888	,	-942	,	-365	},
{	-890	,	-936	,	-363	},
{	-895	,	-934	,	-364	},
{	-898	,	-930	,	-363	},
{	-903	,	-927	,	-364	},
{	-906	,	-924	,	-364	},
{	-911	,	-923	,	-365	},
{	-916	,	-922	,	-366	},
{	-919	,	-917	,	-366	},
{	-924	,	-915	,	-368	},
{	-929	,	-913	,	-370	},
{	-934	,	-912	,	-371	},
{	-939	,	-910	,	-372	},
{	-944	,	-907	,	-373	},
{	-945	,	-901	,	-373	},
{	-949	,	-897	,	-374	},
{	-950	,	-892	,	-372	},
{	-956	,	-890	,	-373	},
{	-965	,	-889	,	-375	},
{	-966	,	-884	,	-374	},
{	-971	,	-882	,	-374	},
{	-973	,	-877	,	-374	},
{	-977	,	-874	,	-374	},
{	-981	,	-869	,	-374	},
{	-986	,	-866	,	-374	},
{	-989	,	-862	,	-374	},
{	-993	,	-858	,	-373	},
{	-998	,	-854	,	-372	},
{	-1000	,	-849	,	-371	},
{	-1005	,	-845	,	-372	},
{	-1009	,	-842	,	-371	},
{	-1015	,	-840	,	-371	},
{	-1020	,	-837	,	-371	},
{	-1024	,	-833	,	-371	},
{	-1025	,	-827	,	-372	},
{	-1026	,	-822	,	-370	},
{	-1032	,	-819	,	-371	},
{	-1035	,	-814	,	-371	},
{	-1041	,	-812	,	-370	},
{	-1045	,	-808	,	-369	},
{	-1050	,	-805	,	-367	},
{	-1052	,	-800	,	-365	},
{	-1054	,	-795	,	-365	},
{	-1061	,	-794	,	-364	},
{	-1065	,	-789	,	-364	},
{	-1072	,	-788	,	-364	},
{	-1075	,	-782	,	-363	},
{	-1081	,	-779	,	-363	},
{	-1082	,	-772	,	-362	},
{	-1087	,	-769	,	-361	},
{	-1093	,	-765	,	-361	},
{	-1099	,	-761	,	-358	},
{	-1104	,	-757	,	-357	},
{	-1108	,	-753	,	-356	},
{	-1116	,	-751	,	-356	},
{	-1120	,	-745	,	-356	},
{	-1124	,	-740	,	-356	},
{	-1126	,	-735	,	-355	},
{	-1133	,	-732	,	-355	},
{	-1138	,	-729	,	-354	},
{	-1141	,	-722	,	-352	},
{	-1142	,	-717	,	-349	},
{	-1147	,	-712	,	-349	},
{	-1154	,	-710	,	-348	},
{	-1154	,	-704	,	-346	},
{	-1163	,	-702	,	-346	},
{	-1167	,	-697	,	-346	},
{	-1171	,	-694	,	-346	},
{	-1178	,	-691	,	-346	},
{	-1180	,	-687	,	-345	},
{	-1184	,	-684	,	-344	},
{	-1185	,	-679	,	-343	},
{	-1189	,	-676	,	-343	},
{	-1196	,	-673	,	-342	},
{	-1202	,	-670	,	-343	},
{	-1206	,	-667	,	-342	},
{	-1212	,	-664	,	-342	},
{	-1220	,	-662	,	-343	},
{	-1228	,	-659	,	-343	},
{	-1232	,	-655	,	-343	},
{	-1237	,	-651	,	-342	},
{	-1246	,	-649	,	-344	},
{	-1250	,	-645	,	-343	},
{	-1253	,	-640	,	-341	},
{	-1257	,	-635	,	-340	},
{	-1264	,	-630	,	-340	},
{	-1274	,	-628	,	-341	},
{	-1280	,	-623	,	-340	},
{	-1289	,	-619	,	-340	},
{	-1297	,	-615	,	-340	},
{	-1304	,	-610	,	-339	},
{	-1310	,	-606	,	-339	},
{	-1317	,	-599	,	-338	},
{	-1325	,	-595	,	-337	},
{	-1332	,	-590	,	-336	},
{	-1338	,	-586	,	-336	},
{	-1347	,	-582	,	-335	},
{	-1355	,	-577	,	-334	},
{	-1361	,	-572	,	-333	},
{	-1366	,	-567	,	-333	},
{	-1376	,	-563	,	-334	},
{	-1385	,	-560	,	-335	},
{	-1389	,	-554	,	-334	},
{	-1395	,	-548	,	-334	},
{	-1401	,	-542	,	-334	},
{	-1409	,	-537	,	-335	},
{	-1418	,	-532	,	-335	},
{	-1420	,	-529	,	-335	},
{	-1425	,	-527	,	-335	},
{	-1429	,	-525	,	-335	},
{	-1432	,	-523	,	-336	},
{	-1433	,	-519	,	-337	},
{	-1438	,	-516	,	-338	},
{	-1438	,	-512	,	-338	},
{	-1440	,	-509	,	-341	}
};

#endif	/* TABLE_LUGE7_SN173_H */

