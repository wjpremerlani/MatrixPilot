

#ifndef TABLE_LUGE7_SN107_H
#define	TABLE_LUGE7_SN107_H

// used in LUGE7_SN107

int16_t residual_offset[] = { 1150 -1549 , -684 +186 , 422 -284 } ;

#define STEP_SIZE 64

#define TABLE_ORIGIN  (  -14486 )

const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-2226	,	-393	,	-1062	},
{	-2212	,	-394	,	-1059	},
{	-2197	,	-393	,	-1055	},
{	-2189	,	-393	,	-1055	},
{	-2180	,	-394	,	-1053	},
{	-2170	,	-395	,	-1051	},
{	-2158	,	-394	,	-1048	},
{	-2148	,	-394	,	-1046	},
{	-2139	,	-394	,	-1045	},
{	-2125	,	-395	,	-1044	},
{	-2101	,	-394	,	-1038	},
{	-2088	,	-394	,	-1036	},
{	-2069	,	-392	,	-1031	},
{	-2045	,	-390	,	-1026	},
{	-2030	,	-389	,	-1026	},
{	-2010	,	-389	,	-1022	},
{	-1992	,	-389	,	-1019	},
{	-1971	,	-387	,	-1015	},
{	-1961	,	-387	,	-1015	},
{	-1944	,	-385	,	-1013	},
{	-1924	,	-385	,	-1008	},
{	-1910	,	-384	,	-1007	},
{	-1894	,	-383	,	-1004	},
{	-1883	,	-384	,	-1005	},
{	-1866	,	-383	,	-1002	},
{	-1851	,	-382	,	-999	},
{	-1836	,	-382	,	-997	},
{	-1822	,	-383	,	-995	},
{	-1802	,	-382	,	-990	},
{	-1786	,	-382	,	-987	},
{	-1775	,	-384	,	-987	},
{	-1758	,	-384	,	-983	},
{	-1740	,	-383	,	-978	},
{	-1728	,	-383	,	-978	},
{	-1714	,	-383	,	-975	},
{	-1692	,	-381	,	-969	},
{	-1679	,	-383	,	-965	},
{	-1666	,	-382	,	-963	},
{	-1649	,	-382	,	-959	},
{	-1632	,	-382	,	-955	},
{	-1614	,	-381	,	-949	},
{	-1602	,	-382	,	-948	},
{	-1586	,	-383	,	-944	},
{	-1565	,	-382	,	-937	},
{	-1552	,	-383	,	-936	},
{	-1535	,	-383	,	-933	},
{	-1521	,	-383	,	-930	},
{	-1505	,	-382	,	-926	},
{	-1489	,	-383	,	-924	},
{	-1471	,	-383	,	-919	},
{	-1454	,	-384	,	-916	},
{	-1438	,	-384	,	-913	},
{	-1424	,	-386	,	-911	},
{	-1408	,	-386	,	-907	},
{	-1391	,	-387	,	-902	},
{	-1376	,	-388	,	-899	},
{	-1362	,	-388	,	-897	},
{	-1346	,	-387	,	-893	},
{	-1327	,	-387	,	-887	},
{	-1312	,	-386	,	-885	},
{	-1300	,	-387	,	-884	},
{	-1283	,	-387	,	-878	},
{	-1269	,	-388	,	-875	},
{	-1254	,	-387	,	-871	},
{	-1236	,	-387	,	-866	},
{	-1219	,	-386	,	-861	},
{	-1206	,	-385	,	-857	},
{	-1189	,	-385	,	-853	},
{	-1172	,	-384	,	-848	},
{	-1156	,	-383	,	-844	},
{	-1142	,	-382	,	-843	},
{	-1128	,	-382	,	-841	},
{	-1113	,	-381	,	-837	},
{	-1096	,	-379	,	-833	},
{	-1082	,	-380	,	-831	},
{	-1071	,	-380	,	-832	},
{	-1055	,	-378	,	-828	},
{	-1043	,	-377	,	-826	},
{	-1029	,	-376	,	-824	},
{	-1016	,	-375	,	-822	},
{	-1002	,	-374	,	-822	},
{	-991	,	-374	,	-821	},
{	-980	,	-373	,	-820	},
{	-969	,	-372	,	-819	},
{	-957	,	-370	,	-817	},
{	-946	,	-368	,	-815	},
{	-936	,	-366	,	-814	},
{	-925	,	-364	,	-812	},
{	-917	,	-363	,	-812	},
{	-907	,	-361	,	-810	},
{	-898	,	-358	,	-808	},
{	-890	,	-357	,	-806	},
{	-881	,	-354	,	-801	},
{	-875	,	-355	,	-802	},
{	-866	,	-353	,	-799	},
{	-863	,	-353	,	-800	},
{	-855	,	-351	,	-798	},
{	-851	,	-350	,	-797	},
{	-842	,	-346	,	-793	},
{	-838	,	-345	,	-794	},
{	-834	,	-342	,	-795	},
{	-829	,	-340	,	-793	},
{	-826	,	-339	,	-794	},
{	-822	,	-338	,	-794	},
{	-818	,	-336	,	-793	},
{	-813	,	-333	,	-791	},
{	-810	,	-330	,	-791	},
{	-808	,	-328	,	-792	},
{	-803	,	-324	,	-791	},
{	-802	,	-322	,	-792	},
{	-799	,	-317	,	-790	},
{	-798	,	-314	,	-790	},
{	-795	,	-309	,	-789	},
{	-796	,	-305	,	-790	},
{	-796	,	-301	,	-789	},
{	-797	,	-297	,	-789	},
{	-797	,	-291	,	-785	},
{	-799	,	-285	,	-784	},
{	-802	,	-279	,	-785	},
{	-804	,	-272	,	-783	},
{	-811	,	-266	,	-784	},
{	-813	,	-260	,	-782	},
{	-818	,	-255	,	-782	},
{	-823	,	-249	,	-782	},
{	-830	,	-244	,	-782	},
{	-837	,	-239	,	-782	},
{	-845	,	-233	,	-783	},
{	-856	,	-228	,	-784	},
{	-863	,	-222	,	-784	},
{	-873	,	-216	,	-783	},
{	-883	,	-210	,	-782	},
{	-893	,	-202	,	-782	},
{	-904	,	-195	,	-783	},
{	-919	,	-190	,	-787	},
{	-932	,	-186	,	-787	},
{	-948	,	-179	,	-788	},
{	-963	,	-174	,	-789	},
{	-976	,	-167	,	-787	},
{	-991	,	-160	,	-788	},
{	-1008	,	-151	,	-789	},
{	-1025	,	-142	,	-791	},
{	-1041	,	-134	,	-790	},
{	-1058	,	-124	,	-791	},
{	-1076	,	-114	,	-791	},
{	-1091	,	-103	,	-792	},
{	-1111	,	-92	,	-791	},
{	-1127	,	-81	,	-792	},
{	-1147	,	-71	,	-794	},
{	-1163	,	-60	,	-794	},
{	-1183	,	-49	,	-796	},
{	-1198	,	-37	,	-795	},
{	-1215	,	-24	,	-796	},
{	-1230	,	-13	,	-797	},
{	-1245	,	-1	,	-796	},
{	-1262	,	11	,	-798	},
{	-1276	,	23	,	-798	},
{	-1293	,	35	,	-799	},
{	-1306	,	47	,	-798	},
{	-1322	,	60	,	-799	},
{	-1339	,	72	,	-802	},
{	-1350	,	83	,	-801	},
{	-1363	,	94	,	-801	},
{	-1378	,	107	,	-804	},
{	-1392	,	119	,	-806	},
{	-1400	,	131	,	-804	},
{	-1416	,	144	,	-808	},
{	-1424	,	155	,	-807	},
{	-1433	,	167	,	-807	},
{	-1448	,	179	,	-810	},
{	-1458	,	190	,	-810	},
{	-1469	,	200	,	-812	},
{	-1477	,	210	,	-811	},
{	-1488	,	220	,	-813	},
{	-1501	,	230	,	-815	},
{	-1511	,	240	,	-816	},
{	-1522	,	250	,	-817	},
{	-1531	,	260	,	-818	},
{	-1541	,	269	,	-819	},
{	-1556	,	280	,	-823	},
{	-1565	,	289	,	-823	},
{	-1573	,	297	,	-823	},
{	-1586	,	306	,	-825	},
{	-1597	,	313	,	-826	},
{	-1613	,	322	,	-830	},
{	-1624	,	330	,	-832	},
{	-1635	,	338	,	-833	},
{	-1646	,	347	,	-834	},
{	-1660	,	356	,	-837	},
{	-1671	,	365	,	-838	},
{	-1684	,	374	,	-840	},
{	-1689	,	382	,	-839	},
{	-1705	,	391	,	-842	},
{	-1712	,	398	,	-843	},
{	-1723	,	406	,	-844	},
{	-1738	,	415	,	-847	},
{	-1744	,	423	,	-846	},
{	-1751	,	431	,	-846	},
{	-1765	,	440	,	-849	},
{	-1777	,	448	,	-851	},
{	-1788	,	457	,	-853	},
{	-1794	,	464	,	-851	},
{	-1807	,	473	,	-854	},
{	-1813	,	480	,	-853	},
{	-1823	,	488	,	-853	},
{	-1834	,	496	,	-855	},
{	-1844	,	505	,	-857	},
{	-1855	,	513	,	-858	},
{	-1870	,	522	,	-861	},
{	-1876	,	529	,	-861	},
{	-1894	,	539	,	-865	},
{	-1901	,	546	,	-865	},
{	-1911	,	555	,	-866	},
{	-1926	,	564	,	-870	},
{	-1938	,	572	,	-872	},
{	-1951	,	581	,	-873	},
{	-1960	,	588	,	-874	},
{	-1968	,	596	,	-873	},
{	-1978	,	603	,	-874	},
{	-1991	,	612	,	-876	},
{	-2007	,	621	,	-879	},
{	-2019	,	629	,	-882	},
{	-2029	,	637	,	-882	},
{	-2042	,	644	,	-884	},
{	-2052	,	652	,	-886	},
{	-2061	,	659	,	-887	},
{	-2074	,	667	,	-889	},
{	-2080	,	673	,	-888	},
{	-2097	,	682	,	-892	},
{	-2104	,	688	,	-893	},
{	-2111	,	693	,	-893	},
{	-2123	,	701	,	-895	},
{	-2134	,	708	,	-897	},
{	-2146	,	715	,	-900	},
{	-2161	,	723	,	-903	},
{	-2174	,	731	,	-906	},
{	-2181	,	738	,	-906	},
{	-2189	,	744	,	-907	},
{	-2198	,	751	,	-907	},
{	-2207	,	757	,	-908	},
{	-2220	,	765	,	-911	},
{	-2231	,	772	,	-912	},
{	-2244	,	779	,	-914	},
{	-2258	,	788	,	-917	},
{	-2272	,	796	,	-920	},
{	-2281	,	802	,	-921	},
{	-2298	,	810	,	-925	},
{	-2314	,	819	,	-928	},
{	-2326	,	827	,	-930	},
{	-2336	,	833	,	-931	},
{	-2344	,	838	,	-930	},
{	-2355	,	844	,	-932	},
{	-2365	,	849	,	-933	},
{	-2382	,	856	,	-937	},
{	-2395	,	862	,	-939	},
{	-2405	,	867	,	-940	},
{	-2420	,	873	,	-943	},
{	-2432	,	877	,	-944	},
{	-2448	,	883	,	-947	},
{	-2456	,	886	,	-947	},
{	-2470	,	892	,	-950	},
{	-2481	,	896	,	-950	},
{	-2496	,	899	,	-952	},
{	-2502	,	900	,	-952	},
{	-2509	,	901	,	-951	},
{	-2528	,	905	,	-954	},
{	-2536	,	907	,	-954	},
{	-2554	,	913	,	-958	},
{	-2568	,	918	,	-960	},
{	-2579	,	921	,	-961	},
{	-2595	,	927	,	-964	},
{	-2603	,	930	,	-964	},
{	-2619	,	936	,	-967	},
{	-2635	,	942	,	-971	},
{	-2649	,	949	,	-973	},
{	-2658	,	954	,	-975	},
{	-2670	,	961	,	-977	},
{	-2676	,	965	,	-977	},
{	-2690	,	973	,	-980	},
{	-2697	,	979	,	-981	},
{	-2712	,	988	,	-986	},
{	-2730	,	998	,	-991	},
{	-2738	,	1005	,	-992	},
{	-2751	,	1014	,	-995	},
{	-2760	,	1021	,	-997	},
{	-2763	,	1026	,	-997	},
{	-2786	,	1038	,	-1004	},
{	-2787	,	1042	,	-1002	},
{	-2803	,	1052	,	-1006	},
{	-2817	,	1060	,	-1009	},
{	-2834	,	1069	,	-1013	},
{	-2845	,	1075	,	-1016	},
{	-2860	,	1083	,	-1020	},
{	-2880	,	1092	,	-1026	},
{	-2890	,	1098	,	-1028	},
{	-2902	,	1104	,	-1030	},
{	-2922	,	1113	,	-1035	},
{	-2931	,	1119	,	-1036	},
{	-2948	,	1128	,	-1039	},
{	-2958	,	1133	,	-1040	},
{	-2973	,	1140	,	-1043	},
{	-2988	,	1148	,	-1047	},
{	-3010	,	1159	,	-1052	},
{	-3018	,	1164	,	-1053	},
{	-3039	,	1173	,	-1059	},
{	-3050	,	1178	,	-1061	},
{	-3058	,	1182	,	-1061	},
{	-3068	,	1188	,	-1062	},
{	-3077	,	1193	,	-1063	},
{	-3086	,	1197	,	-1064	},
{	-3100	,	1204	,	-1067	},
{	-3121	,	1214	,	-1072	},
{	-3129	,	1217	,	-1073	},
{	-3142	,	1224	,	-1076	},
{	-3165	,	1233	,	-1082	},
{	-3168	,	1235	,	-1082	},
{	-3184	,	1241	,	-1085	},
{	-3201	,	1247	,	-1089	},
{	-3208	,	1250	,	-1089	},
{	-3220	,	1253	,	-1092	},
{	-3240	,	1260	,	-1096	},
{	-3251	,	1264	,	-1098	},
{	-3273	,	1272	,	-1103	},
{	-3295	,	1280	,	-1108	},
{	-3306	,	1283	,	-1110	},
{	-3325	,	1289	,	-1114	},
{	-3341	,	1294	,	-1116	},
{	-3349	,	1295	,	-1117	},
{	-3355	,	1296	,	-1116	},
{	-3377	,	1302	,	-1120	},
{	-3390	,	1306	,	-1121	},
{	-3395	,	1306	,	-1120	},
{	-3405	,	1307	,	-1120	},
{	-3426	,	1314	,	-1125	},
{	-3437	,	1316	,	-1126	},
{	-3454	,	1319	,	-1128	},
{	-3470	,	1322	,	-1130	},
{	-3486	,	1325	,	-1132	},
{	-3502	,	1328	,	-1134	},
{	-3514	,	1330	,	-1134	},
{	-3523	,	1330	,	-1134	},
{	-3532	,	1330	,	-1134	},
{	-3544	,	1330	,	-1134	},
{	-3569	,	1336	,	-1139	},
{	-3587	,	1338	,	-1140	},
{	-3610	,	1343	,	-1144	},
{	-3628	,	1344	,	-1147	},
{	-3640	,	1343	,	-1146	},
{	-3662	,	1346	,	-1149	},
{	-3681	,	1348	,	-1150	},
{	-3693	,	1346	,	-1149	},
{	-3716	,	1349	,	-1151	},
{	-3735	,	1351	,	-1153	},
{	-3748	,	1349	,	-1152	},
{	-3759	,	1347	,	-1151	},
{	-3774	,	1346	,	-1150	},
{	-3784	,	1343	,	-1149	},
{	-3808	,	1344	,	-1152	},
{	-3832	,	1345	,	-1154	},
{	-3851	,	1345	,	-1155	},
{	-3860	,	1340	,	-1152	},
{	-3872	,	1336	,	-1151	},
{	-3880	,	1330	,	-1147	},
{	-3896	,	1327	,	-1146	},
{	-3914	,	1325	,	-1147	},
{	-3928	,	1321	,	-1145	},
{	-3949	,	1320	,	-1146	},
{	-3967	,	1316	,	-1145	},
{	-3974	,	1309	,	-1142	},
{	-3977	,	1300	,	-1138	},
{	-3985	,	1298	,	-1137	},
{	-3990	,	1294	,	-1136	},
{	-3996	,	1291	,	-1135	},
{	-4009	,	1290	,	-1135	},
{	-4009	,	1285	,	-1132	},
{	-4010	,	1280	,	-1129	},
{	-4017	,	1277	,	-1128	},
{	-4019	,	1272	,	-1125	}
};

#endif	/* TABLE_LUGE7_SN107_H */



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11910)

int16_t accel_residual_offset[] = { 0 , 0 , 0 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-1,1,-1},
{-1,1,-1},
{-1,1,-1},
{-1,0,-3},
{-1,0,-4},
{-1,0,0},
{0,0,4},
{0,0,2},
{0,0,1},
{0,0,1},
{0,0,0},
{1,0,0},
{1,-1,0},
{1,-1,0},
{1,-1,0},
{1,-1,1},
{2,-1,1},
{2,-1,1},
{2,-2,2},
{3,-2,2},
{3,-3,2},
{3,-3,2},
{4,-3,3},
{4,-3,3},
{4,-3,3},
{4,-3,3},
{4,-3,4},
{5,-3,4},
{5,-4,4},
{5,-4,5},
{6,-4,5},
{6,-4,6},
{7,-4,6},
{7,-5,6},
{7,-5,7},
{7,-5,7},
{8,-5,8},
{8,-5,8},
{9,-5,8},
{9,-5,9},
{9,-6,9},
{10,-6,10},
{10,-6,10},
{10,-6,10},
{10,-6,11},
{11,-7,11},
{11,-7,11},
{11,-7,12},
{11,-7,12},
{12,-7,12},
{12,-7,12},
{12,-8,12},
{12,-8,12},
{12,-8,13},
{12,-8,13},
{13,-8,13},
{13,-9,13},
{13,-8,13},
{13,-8,13},
{14,-9,14},
{14,-9,14},
{14,-9,14},
{14,-9,14},
{14,-9,15},
{14,-9,15},
{14,-9,15},
{15,-9,15},
{15,-10,15},
{15,-10,15},
{15,-10,15},
{16,-10,16},
{16,-10,16},
{16,-10,16},
{16,-11,16},
{16,-11,16},
{17,-10,16},
{17,-10,17},
{17,-10,17},
{18,-10,17},
{18,-10,17},
{18,-10,17},
{18,-11,17},
{19,-11,18},
{19,-11,18},
{19,-11,18},
{19,-11,18},
{20,-11,18},
{20,-11,18},
{20,-11,18},
{20,-11,18},
{20,-10,18},
{20,-10,18},
{21,-10,19},
{21,-10,19},
{21,-10,19},
{22,-10,19},
{22,-10,19},
{22,-10,19},
{22,-9,19},
{22,-9,19},
{23,-9,19},
{23,-9,20},
{23,-9,20},
{23,-8,20},
{23,-8,20},
{23,-9,20},
{24,-9,20},
{24,-9,20},
{24,-9,20},
{24,-9,20},
{24,-9,20},
{24,-9,20},
{24,-9,19},
{24,-10,19},
{24,-10,19},
{24,-10,19},
{24,-10,19},
{24,-11,19},
{24,-11,19},
{24,-11,18},
{24,-12,18},
{25,-12,19},
{25,-12,19},
{25,-12,19},
{25,-12,19},
{25,-12,19},
{25,-13,19},
{25,-13,19},
{25,-13,19},
{26,-13,19},
{26,-13,19},
{26,-14,19},
{26,-13,19},
{26,-13,19},
{26,-13,19},
{26,-14,19},
{26,-14,19},
{27,-14,20},
{27,-14,20},
{27,-14,20},
{27,-14,20},
{27,-14,20},
{27,-14,20},
{27,-15,20},
{28,-15,20},
{28,-15,20},
{28,-15,21},
{28,-15,21},
{28,-15,21},
{28,-15,21},
{28,-16,21},
{29,-16,22},
{29,-16,22},
{29,-16,22},
{29,-16,22},
{29,-16,22},
{29,-16,22},
{30,-17,23},
{30,-17,23},
{30,-17,23},
{30,-17,23},
{30,-17,24},
{30,-17,24},
{31,-17,24},
{31,-18,24},
{31,-18,25},
{31,-18,25},
{31,-18,25},
{31,-18,25},
{31,-18,26},
{31,-18,26},
{32,-18,26},
{32,-18,27},
{32,-18,27},
{32,-18,27},
{32,-19,28},
{32,-19,28},
{33,-19,28},
{33,-19,29},
{33,-19,29},
{33,-19,30},
{33,-19,30},
{33,-20,30},
{33,-20,31},
{33,-20,31},
{33,-20,31},
{34,-20,32},
{34,-20,32},
{34,-20,33},
{34,-20,33},
{34,-21,34},
{34,-21,34},
{34,-21,35},
{34,-21,35},
{35,-21,36},
{35,-21,36},
{35,-22,37},
{35,-22,37},
{35,-22,38},
{36,-22,39},
{36,-22,39},
{36,-22,39},
{36,-22,39},
{36,-22,39},
{36,-22,39},
{36,-23,39},
{37,-23,40},
{37,-23,40},
{37,-23,40},
{37,-23,40},
{37,-23,40},
{37,-24,41},
{37,-24,41},
{37,-24,41},
{37,-24,42},
{37,-24,42},
{37,-24,42},
{37,-24,42},
{38,-24,43},
{38,-25,43},
{38,-25,43},
{38,-25,44},
{38,-25,44},
{38,-25,44},
{38,-25,45},
{39,-25,45},
{39,-25,46},
{39,-25,46},
{39,-25,47},
{39,-26,47},
{39,-26,48},
{39,-26,48},
{39,-26,49},
{39,-26,49},
{39,-26,50},
{39,-26,50},
{39,-26,51},
{39,-26,52},
{39,-26,53},
{39,-26,54},
{39,-25,55},
{39,-25,55},
{39,-25,56},
{39,-25,56},
{38,-24,57},
};



