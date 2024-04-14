

#ifndef TABLE_LUGE7_SN170_H
#define	TABLE_LUGE7_SN170_H

// used in LUGE7_SN170 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -15184 )

int16_t residual_offset[] = { -512 , 64 , -256 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	1832	,	-1241	,	-1005	},
{	1836	,	-1239	,	-1003	},
{	1836	,	-1236	,	-998	},
{	1845	,	-1237	,	-998	},
{	1849	,	-1234	,	-995	},
{	1853	,	-1231	,	-992	},
{	1858	,	-1231	,	-992	},
{	1862	,	-1229	,	-991	},
{	1867	,	-1228	,	-990	},
{	1883	,	-1230	,	-991	},
{	1892	,	-1227	,	-986	},
{	1899	,	-1221	,	-980	},
{	1906	,	-1215	,	-976	},
{	1916	,	-1212	,	-972	},
{	1927	,	-1210	,	-971	},
{	1940	,	-1209	,	-970	},
{	1954	,	-1210	,	-970	},
{	1963	,	-1205	,	-967	},
{	1973	,	-1202	,	-964	},
{	1988	,	-1202	,	-966	},
{	1994	,	-1196	,	-962	},
{	2007	,	-1195	,	-963	},
{	2016	,	-1191	,	-961	},
{	2028	,	-1188	,	-961	},
{	2038	,	-1186	,	-958	},
{	2047	,	-1183	,	-957	},
{	2054	,	-1176	,	-954	},
{	2063	,	-1172	,	-953	},
{	2073	,	-1170	,	-952	},
{	2082	,	-1167	,	-951	},
{	2092	,	-1166	,	-951	},
{	2101	,	-1163	,	-949	},
{	2111	,	-1159	,	-950	},
{	2118	,	-1155	,	-949	},
{	2125	,	-1152	,	-947	},
{	2132	,	-1148	,	-945	},
{	2140	,	-1143	,	-943	},
{	2149	,	-1142	,	-942	},
{	2157	,	-1140	,	-940	},
{	2165	,	-1138	,	-940	},
{	2175	,	-1135	,	-938	},
{	2184	,	-1133	,	-936	},
{	2196	,	-1132	,	-936	},
{	2202	,	-1129	,	-934	},
{	2215	,	-1129	,	-934	},
{	2223	,	-1125	,	-933	},
{	2232	,	-1123	,	-930	},
{	2236	,	-1119	,	-928	},
{	2243	,	-1115	,	-926	},
{	2246	,	-1110	,	-922	},
{	2252	,	-1106	,	-919	},
{	2261	,	-1104	,	-918	},
{	2269	,	-1101	,	-916	},
{	2279	,	-1100	,	-915	},
{	2284	,	-1096	,	-912	},
{	2294	,	-1094	,	-910	},
{	2302	,	-1093	,	-907	},
{	2307	,	-1088	,	-904	},
{	2311	,	-1083	,	-902	},
{	2316	,	-1079	,	-900	},
{	2331	,	-1080	,	-901	},
{	2334	,	-1075	,	-898	},
{	2337	,	-1071	,	-895	},
{	2343	,	-1067	,	-894	},
{	2356	,	-1067	,	-895	},
{	2362	,	-1062	,	-894	},
{	2373	,	-1062	,	-893	},
{	2383	,	-1062	,	-893	},
{	2398	,	-1061	,	-895	},
{	2409	,	-1061	,	-894	},
{	2412	,	-1056	,	-892	},
{	2421	,	-1055	,	-895	},
{	2422	,	-1049	,	-892	},
{	2436	,	-1048	,	-895	},
{	2440	,	-1043	,	-894	},
{	2453	,	-1043	,	-896	},
{	2461	,	-1041	,	-896	},
{	2467	,	-1038	,	-897	},
{	2477	,	-1037	,	-897	},
{	2483	,	-1035	,	-898	},
{	2495	,	-1035	,	-899	},
{	2499	,	-1031	,	-897	},
{	2514	,	-1033	,	-899	},
{	2522	,	-1030	,	-900	},
{	2534	,	-1029	,	-902	},
{	2532	,	-1023	,	-898	},
{	2540	,	-1020	,	-898	},
{	2549	,	-1019	,	-899	},
{	2556	,	-1015	,	-897	},
{	2569	,	-1014	,	-899	},
{	2571	,	-1011	,	-898	},
{	2584	,	-1011	,	-900	},
{	2591	,	-1009	,	-900	},
{	2599	,	-1006	,	-901	},
{	2605	,	-1003	,	-901	},
{	2610	,	-1000	,	-901	},
{	2617	,	-997	,	-902	},
{	2620	,	-993	,	-900	},
{	2631	,	-991	,	-904	},
{	2628	,	-983	,	-901	},
{	2637	,	-981	,	-903	},
{	2642	,	-978	,	-904	},
{	2650	,	-974	,	-906	},
{	2662	,	-972	,	-910	},
{	2663	,	-968	,	-910	},
{	2677	,	-968	,	-915	},
{	2677	,	-962	,	-916	},
{	2686	,	-959	,	-919	},
{	2691	,	-954	,	-920	},
{	2694	,	-949	,	-922	},
{	2694	,	-942	,	-923	},
{	2694	,	-936	,	-924	},
{	2704	,	-931	,	-927	},
{	2716	,	-929	,	-932	},
{	2717	,	-922	,	-934	},
{	2717	,	-916	,	-934	},
{	2724	,	-912	,	-936	},
{	2722	,	-905	,	-936	},
{	2722	,	-898	,	-938	},
{	2725	,	-894	,	-940	},
{	2723	,	-887	,	-940	},
{	2732	,	-884	,	-944	},
{	2727	,	-876	,	-942	},
{	2733	,	-872	,	-945	},
{	2734	,	-867	,	-945	},
{	2735	,	-863	,	-946	},
{	2740	,	-860	,	-948	},
{	2748	,	-857	,	-951	},
{	2755	,	-854	,	-954	},
{	2749	,	-847	,	-953	},
{	2753	,	-843	,	-954	},
{	2753	,	-838	,	-954	},
{	2756	,	-833	,	-957	},
{	2763	,	-830	,	-961	},
{	2767	,	-826	,	-964	},
{	2767	,	-820	,	-965	},
{	2763	,	-812	,	-964	},
{	2765	,	-805	,	-966	},
{	2763	,	-796	,	-967	},
{	2764	,	-790	,	-970	},
{	2759	,	-782	,	-969	},
{	2761	,	-774	,	-971	},
{	2761	,	-766	,	-973	},
{	2760	,	-759	,	-975	},
{	2756	,	-751	,	-976	},
{	2752	,	-741	,	-976	},
{	2758	,	-736	,	-982	},
{	2749	,	-725	,	-981	},
{	2751	,	-717	,	-985	},
{	2748	,	-710	,	-987	},
{	2745	,	-701	,	-988	},
{	2741	,	-693	,	-990	},
{	2736	,	-684	,	-991	},
{	2737	,	-677	,	-995	},
{	2727	,	-667	,	-995	},
{	2724	,	-658	,	-997	},
{	2725	,	-648	,	-1001	},
{	2722	,	-639	,	-1004	},
{	2717	,	-629	,	-1007	},
{	2709	,	-618	,	-1009	},
{	2704	,	-607	,	-1012	},
{	2699	,	-597	,	-1013	},
{	2699	,	-588	,	-1018	},
{	2689	,	-575	,	-1018	},
{	2694	,	-567	,	-1024	},
{	2684	,	-555	,	-1025	},
{	2676	,	-544	,	-1027	},
{	2664	,	-531	,	-1028	},
{	2661	,	-521	,	-1032	},
{	2655	,	-510	,	-1035	},
{	2653	,	-501	,	-1040	},
{	2649	,	-491	,	-1044	},
{	2644	,	-481	,	-1047	},
{	2636	,	-471	,	-1050	},
{	2635	,	-463	,	-1056	},
{	2627	,	-452	,	-1058	},
{	2626	,	-442	,	-1064	},
{	2615	,	-431	,	-1065	},
{	2611	,	-422	,	-1069	},
{	2602	,	-411	,	-1071	},
{	2601	,	-402	,	-1076	},
{	2590	,	-392	,	-1077	},
{	2588	,	-383	,	-1082	},
{	2585	,	-374	,	-1087	},
{	2585	,	-366	,	-1092	},
{	2581	,	-357	,	-1095	},
{	2575	,	-347	,	-1098	},
{	2574	,	-338	,	-1102	},
{	2574	,	-328	,	-1107	},
{	2569	,	-318	,	-1110	},
{	2564	,	-310	,	-1114	},
{	2555	,	-299	,	-1115	},
{	2555	,	-292	,	-1121	},
{	2549	,	-284	,	-1123	},
{	2552	,	-277	,	-1129	},
{	2547	,	-268	,	-1133	},
{	2546	,	-260	,	-1138	},
{	2534	,	-251	,	-1139	},
{	2535	,	-244	,	-1144	},
{	2529	,	-236	,	-1147	},
{	2531	,	-229	,	-1153	},
{	2521	,	-220	,	-1154	},
{	2520	,	-212	,	-1159	},
{	2526	,	-206	,	-1168	},
{	2518	,	-198	,	-1170	},
{	2513	,	-191	,	-1172	},
{	2510	,	-184	,	-1176	},
{	2510	,	-177	,	-1183	},
{	2513	,	-169	,	-1190	},
{	2505	,	-161	,	-1192	},
{	2500	,	-153	,	-1194	},
{	2492	,	-145	,	-1197	},
{	2490	,	-138	,	-1202	},
{	2483	,	-130	,	-1204	},
{	2488	,	-123	,	-1212	},
{	2478	,	-116	,	-1215	},
{	2476	,	-108	,	-1220	},
{	2465	,	-101	,	-1221	},
{	2466	,	-93	,	-1227	},
{	2458	,	-84	,	-1230	},
{	2452	,	-75	,	-1233	},
{	2447	,	-67	,	-1237	},
{	2445	,	-58	,	-1243	},
{	2442	,	-50	,	-1247	},
{	2434	,	-41	,	-1248	},
{	2431	,	-32	,	-1253	},
{	2427	,	-24	,	-1257	},
{	2429	,	-14	,	-1265	},
{	2424	,	-5	,	-1268	},
{	2423	,	5	,	-1274	},
{	2422	,	16	,	-1280	},
{	2419	,	27	,	-1285	},
{	2417	,	38	,	-1290	},
{	2416	,	48	,	-1296	},
{	2414	,	58	,	-1300	},
{	2411	,	67	,	-1305	},
{	2413	,	77	,	-1312	},
{	2407	,	88	,	-1314	},
{	2403	,	99	,	-1319	},
{	2401	,	109	,	-1325	},
{	2399	,	119	,	-1331	},
{	2399	,	130	,	-1337	},
{	2388	,	139	,	-1338	},
{	2391	,	149	,	-1345	},
{	2387	,	159	,	-1348	},
{	2393	,	170	,	-1358	},
{	2384	,	179	,	-1359	},
{	2381	,	187	,	-1364	},
{	2376	,	196	,	-1368	},
{	2374	,	205	,	-1373	},
{	2372	,	214	,	-1379	},
{	2370	,	223	,	-1385	},
{	2368	,	233	,	-1390	},
{	2359	,	240	,	-1392	},
{	2357	,	248	,	-1397	},
{	2359	,	257	,	-1406	},
{	2352	,	264	,	-1408	},
{	2350	,	273	,	-1413	},
{	2346	,	281	,	-1417	},
{	2349	,	291	,	-1427	},
{	2347	,	300	,	-1434	},
{	2345	,	309	,	-1440	},
{	2338	,	317	,	-1444	},
{	2336	,	326	,	-1450	},
{	2335	,	334	,	-1458	},
{	2331	,	342	,	-1464	},
{	2331	,	351	,	-1472	},
{	2328	,	359	,	-1478	},
{	2333	,	369	,	-1488	},
{	2333	,	377	,	-1497	},
{	2329	,	386	,	-1503	},
{	2329	,	395	,	-1512	},
{	2328	,	404	,	-1519	},
{	2331	,	413	,	-1529	},
{	2325	,	421	,	-1532	},
{	2329	,	430	,	-1543	},
{	2325	,	437	,	-1547	},
{	2320	,	444	,	-1551	},
{	2319	,	451	,	-1557	},
{	2315	,	459	,	-1563	},
{	2318	,	468	,	-1573	},
{	2316	,	475	,	-1578	},
{	2311	,	482	,	-1582	},
{	2311	,	490	,	-1590	},
{	2309	,	498	,	-1595	},
{	2303	,	505	,	-1598	},
{	2300	,	513	,	-1603	},
{	2304	,	522	,	-1614	},
{	2300	,	529	,	-1619	},
{	2291	,	535	,	-1620	},
{	2285	,	543	,	-1624	},
{	2288	,	551	,	-1637	},
{	2283	,	557	,	-1642	},
{	2283	,	567	,	-1651	},
{	2278	,	574	,	-1657	},
{	2277	,	582	,	-1666	},
{	2274	,	590	,	-1672	},
{	2272	,	596	,	-1679	},
{	2272	,	604	,	-1687	},
{	2272	,	613	,	-1696	},
{	2262	,	619	,	-1697	},
{	2267	,	630	,	-1710	},
{	2262	,	637	,	-1716	},
{	2254	,	643	,	-1721	},
{	2247	,	649	,	-1724	},
{	2245	,	658	,	-1732	},
{	2247	,	668	,	-1742	},
{	2242	,	676	,	-1747	},
{	2237	,	684	,	-1750	},
{	2228	,	692	,	-1752	},
{	2226	,	700	,	-1759	},
{	2222	,	709	,	-1763	},
{	2218	,	718	,	-1769	},
{	2214	,	727	,	-1774	},
{	2205	,	735	,	-1775	},
{	2202	,	746	,	-1781	},
{	2199	,	756	,	-1787	},
{	2197	,	766	,	-1793	},
{	2189	,	769	,	-1791	},
{	2188	,	775	,	-1794	},
{	2189	,	781	,	-1796	},
{	2189	,	786	,	-1800	},
{	2186	,	791	,	-1801	},
{	2182	,	796	,	-1801	},
{	2184	,	802	,	-1807	},
{	2179	,	806	,	-1807	}
};

#endif	/* TABLE_LUGE7_SN170_H */

