

#ifndef TABLE_LUGE7_SN130_H
#define	TABLE_LUGE7_SN130_H

// used in LUGE7_SN130 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -15030 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	283	,	-1043	,	952	},
{	286	,	-1051	,	955	},
{	286	,	-1052	,	951	},
{	287	,	-1059	,	953	},
{	289	,	-1065	,	954	},
{	289	,	-1071	,	955	},
{	291	,	-1075	,	955	},
{	292	,	-1080	,	954	},
{	294	,	-1084	,	953	},
{	296	,	-1095	,	957	},
{	299	,	-1104	,	956	},
{	302	,	-1114	,	958	},
{	306	,	-1122	,	958	},
{	309	,	-1130	,	956	},
{	310	,	-1136	,	954	},
{	311	,	-1145	,	952	},
{	313	,	-1153	,	951	},
{	315	,	-1162	,	951	},
{	316	,	-1168	,	950	},
{	321	,	-1179	,	954	},
{	322	,	-1185	,	951	},
{	322	,	-1192	,	949	},
{	326	,	-1200	,	948	},
{	328	,	-1207	,	948	},
{	330	,	-1213	,	946	},
{	331	,	-1222	,	948	},
{	334	,	-1231	,	948	},
{	334	,	-1239	,	949	},
{	336	,	-1247	,	948	},
{	336	,	-1257	,	948	},
{	338	,	-1266	,	948	},
{	341	,	-1274	,	947	},
{	342	,	-1281	,	946	},
{	345	,	-1290	,	946	},
{	346	,	-1297	,	944	},
{	348	,	-1308	,	944	},
{	347	,	-1314	,	941	},
{	350	,	-1324	,	942	},
{	351	,	-1334	,	942	},
{	352	,	-1339	,	938	},
{	353	,	-1348	,	935	},
{	356	,	-1359	,	935	},
{	357	,	-1370	,	934	},
{	358	,	-1378	,	932	},
{	361	,	-1387	,	930	},
{	364	,	-1396	,	928	},
{	365	,	-1403	,	925	},
{	367	,	-1413	,	923	},
{	368	,	-1422	,	922	},
{	370	,	-1431	,	920	},
{	371	,	-1437	,	918	},
{	373	,	-1445	,	916	},
{	374	,	-1452	,	912	},
{	375	,	-1463	,	911	},
{	377	,	-1473	,	908	},
{	380	,	-1481	,	906	},
{	383	,	-1490	,	905	},
{	385	,	-1499	,	905	},
{	386	,	-1503	,	902	},
{	387	,	-1511	,	899	},
{	388	,	-1516	,	897	},
{	391	,	-1525	,	896	},
{	391	,	-1531	,	892	},
{	393	,	-1541	,	893	},
{	396	,	-1548	,	892	},
{	398	,	-1556	,	890	},
{	400	,	-1563	,	889	},
{	403	,	-1571	,	887	},
{	405	,	-1581	,	885	},
{	407	,	-1586	,	881	},
{	410	,	-1596	,	880	},
{	413	,	-1601	,	876	},
{	414	,	-1608	,	873	},
{	416	,	-1618	,	873	},
{	417	,	-1623	,	869	},
{	419	,	-1635	,	869	},
{	420	,	-1640	,	865	},
{	422	,	-1650	,	863	},
{	423	,	-1657	,	861	},
{	426	,	-1668	,	860	},
{	429	,	-1676	,	857	},
{	430	,	-1684	,	853	},
{	432	,	-1694	,	852	},
{	435	,	-1706	,	850	},
{	436	,	-1714	,	847	},
{	436	,	-1720	,	843	},
{	439	,	-1733	,	843	},
{	439	,	-1740	,	840	},
{	440	,	-1750	,	839	},
{	441	,	-1759	,	837	},
{	441	,	-1766	,	834	},
{	442	,	-1772	,	830	},
{	444	,	-1783	,	828	},
{	445	,	-1790	,	825	},
{	447	,	-1799	,	822	},
{	446	,	-1804	,	817	},
{	447	,	-1809	,	813	},
{	446	,	-1814	,	809	},
{	447	,	-1824	,	807	},
{	448	,	-1833	,	805	},
{	446	,	-1840	,	800	},
{	445	,	-1847	,	796	},
{	445	,	-1855	,	794	},
{	444	,	-1863	,	790	},
{	442	,	-1866	,	786	},
{	441	,	-1870	,	781	},
{	439	,	-1878	,	778	},
{	439	,	-1886	,	775	},
{	438	,	-1897	,	773	},
{	435	,	-1902	,	768	},
{	433	,	-1907	,	765	},
{	430	,	-1912	,	761	},
{	429	,	-1921	,	759	},
{	427	,	-1932	,	758	},
{	424	,	-1938	,	755	},
{	421	,	-1939	,	750	},
{	419	,	-1944	,	745	},
{	417	,	-1948	,	741	},
{	415	,	-1958	,	739	},
{	413	,	-1962	,	735	},
{	411	,	-1968	,	733	},
{	410	,	-1977	,	730	},
{	407	,	-1984	,	726	},
{	404	,	-1989	,	722	},
{	401	,	-1995	,	718	},
{	400	,	-2005	,	717	},
{	397	,	-2014	,	714	},
{	392	,	-2020	,	711	},
{	389	,	-2023	,	707	},
{	385	,	-2027	,	702	},
{	380	,	-2032	,	698	},
{	376	,	-2034	,	693	},
{	371	,	-2042	,	690	},
{	365	,	-2050	,	688	},
{	359	,	-2057	,	685	},
{	354	,	-2059	,	681	},
{	348	,	-2063	,	678	},
{	341	,	-2067	,	674	},
{	333	,	-2068	,	670	},
{	327	,	-2075	,	667	},
{	318	,	-2076	,	662	},
{	311	,	-2075	,	658	},
{	301	,	-2076	,	652	},
{	294	,	-2076	,	647	},
{	287	,	-2083	,	643	},
{	279	,	-2087	,	639	},
{	271	,	-2088	,	634	},
{	263	,	-2092	,	630	},
{	255	,	-2095	,	626	},
{	248	,	-2101	,	622	},
{	239	,	-2098	,	615	},
{	231	,	-2094	,	608	},
{	222	,	-2094	,	602	},
{	215	,	-2098	,	597	},
{	206	,	-2096	,	591	},
{	199	,	-2100	,	587	},
{	192	,	-2097	,	580	},
{	186	,	-2103	,	577	},
{	178	,	-2106	,	572	},
{	172	,	-2106	,	567	},
{	164	,	-2103	,	560	},
{	157	,	-2100	,	555	},
{	151	,	-2102	,	551	},
{	145	,	-2107	,	547	},
{	138	,	-2104	,	541	},
{	132	,	-2109	,	537	},
{	126	,	-2111	,	533	},
{	122	,	-2116	,	530	},
{	117	,	-2126	,	528	},
{	112	,	-2131	,	524	},
{	107	,	-2134	,	519	},
{	103	,	-2143	,	516	},
{	99	,	-2143	,	510	},
{	94	,	-2153	,	507	},
{	90	,	-2153	,	502	},
{	87	,	-2159	,	498	},
{	82	,	-2161	,	494	},
{	78	,	-2169	,	490	},
{	75	,	-2179	,	486	},
{	72	,	-2183	,	480	},
{	68	,	-2188	,	475	},
{	63	,	-2193	,	471	},
{	59	,	-2201	,	466	},
{	55	,	-2204	,	459	},
{	50	,	-2207	,	453	},
{	46	,	-2208	,	447	},
{	42	,	-2213	,	443	},
{	37	,	-2217	,	438	},
{	32	,	-2222	,	434	},
{	27	,	-2224	,	429	},
{	24	,	-2227	,	423	},
{	19	,	-2232	,	418	},
{	13	,	-2236	,	413	},
{	9	,	-2244	,	408	},
{	4	,	-2253	,	405	},
{	0	,	-2257	,	400	},
{	-4	,	-2269	,	398	},
{	-8	,	-2270	,	393	},
{	-12	,	-2276	,	388	},
{	-15	,	-2281	,	384	},
{	-20	,	-2285	,	379	},
{	-23	,	-2288	,	374	},
{	-28	,	-2293	,	370	},
{	-31	,	-2297	,	365	},
{	-34	,	-2309	,	362	},
{	-39	,	-2310	,	357	},
{	-42	,	-2316	,	353	},
{	-47	,	-2318	,	348	},
{	-51	,	-2323	,	343	},
{	-55	,	-2330	,	339	},
{	-59	,	-2335	,	334	},
{	-62	,	-2342	,	331	},
{	-66	,	-2345	,	326	},
{	-71	,	-2346	,	320	},
{	-75	,	-2353	,	316	},
{	-79	,	-2359	,	311	},
{	-84	,	-2361	,	306	},
{	-87	,	-2361	,	301	},
{	-91	,	-2373	,	297	},
{	-95	,	-2380	,	293	},
{	-99	,	-2383	,	288	},
{	-104	,	-2386	,	282	},
{	-107	,	-2392	,	277	},
{	-112	,	-2398	,	273	},
{	-117	,	-2401	,	268	},
{	-121	,	-2411	,	264	},
{	-125	,	-2418	,	261	},
{	-129	,	-2419	,	256	},
{	-134	,	-2417	,	251	},
{	-139	,	-2426	,	246	},
{	-143	,	-2428	,	241	},
{	-148	,	-2436	,	237	},
{	-153	,	-2444	,	234	},
{	-158	,	-2448	,	230	},
{	-164	,	-2464	,	227	},
{	-169	,	-2459	,	221	},
{	-173	,	-2464	,	217	},
{	-178	,	-2471	,	214	},
{	-183	,	-2475	,	210	},
{	-188	,	-2478	,	205	},
{	-193	,	-2489	,	201	},
{	-198	,	-2495	,	197	},
{	-203	,	-2501	,	193	},
{	-208	,	-2500	,	188	},
{	-213	,	-2506	,	183	},
{	-218	,	-2510	,	179	},
{	-222	,	-2510	,	175	},
{	-227	,	-2520	,	171	},
{	-232	,	-2521	,	167	},
{	-236	,	-2518	,	161	},
{	-241	,	-2528	,	159	},
{	-245	,	-2524	,	154	},
{	-251	,	-2536	,	151	},
{	-256	,	-2545	,	148	},
{	-261	,	-2549	,	145	},
{	-267	,	-2555	,	142	},
{	-272	,	-2563	,	139	},
{	-274	,	-2567	,	138	},
{	-278	,	-2573	,	136	},
{	-280	,	-2572	,	134	},
{	-284	,	-2582	,	131	},
{	-287	,	-2589	,	129	},
{	-290	,	-2597	,	127	},
{	-294	,	-2609	,	124	},
{	-297	,	-2608	,	121	},
{	-302	,	-2615	,	117	},
{	-307	,	-2626	,	114	},
{	-310	,	-2627	,	110	},
{	-314	,	-2632	,	106	},
{	-318	,	-2632	,	102	},
{	-321	,	-2633	,	98	},
{	-325	,	-2641	,	94	},
{	-328	,	-2641	,	90	},
{	-332	,	-2641	,	85	},
{	-338	,	-2639	,	78	},
{	-344	,	-2643	,	74	},
{	-351	,	-2648	,	69	},
{	-357	,	-2649	,	63	},
{	-363	,	-2650	,	58	},
{	-369	,	-2653	,	52	},
{	-376	,	-2652	,	46	},
{	-382	,	-2661	,	41	},
{	-388	,	-2663	,	37	},
{	-394	,	-2666	,	31	},
{	-400	,	-2671	,	26	},
{	-408	,	-2679	,	21	},
{	-414	,	-2685	,	16	},
{	-421	,	-2686	,	10	},
{	-426	,	-2685	,	5	},
{	-433	,	-2692	,	1	},
{	-439	,	-2696	,	-4	},
{	-445	,	-2705	,	-8	},
{	-452	,	-2713	,	-13	},
{	-458	,	-2715	,	-18	},
{	-463	,	-2723	,	-22	},
{	-471	,	-2733	,	-26	},
{	-478	,	-2742	,	-30	},
{	-484	,	-2745	,	-34	},
{	-490	,	-2744	,	-37	},
{	-496	,	-2752	,	-42	},
{	-503	,	-2757	,	-45	},
{	-510	,	-2762	,	-48	},
{	-516	,	-2766	,	-52	},
{	-524	,	-2772	,	-55	},
{	-531	,	-2779	,	-58	},
{	-539	,	-2790	,	-61	},
{	-545	,	-2796	,	-64	},
{	-552	,	-2801	,	-67	},
{	-559	,	-2810	,	-70	},
{	-565	,	-2811	,	-73	},
{	-574	,	-2825	,	-76	},
{	-580	,	-2826	,	-79	},
{	-586	,	-2830	,	-82	},
{	-594	,	-2838	,	-84	},
{	-601	,	-2847	,	-86	},
{	-609	,	-2862	,	-88	},
{	-615	,	-2864	,	-90	},
{	-622	,	-2874	,	-92	},
{	-627	,	-2877	,	-93	},
{	-634	,	-2889	,	-95	},
{	-639	,	-2892	,	-96	},
{	-645	,	-2898	,	-98	},
{	-651	,	-2902	,	-99	},
{	-656	,	-2905	,	-100	},
{	-663	,	-2915	,	-100	},
{	-669	,	-2917	,	-102	},
{	-678	,	-2933	,	-103	},
{	-684	,	-2938	,	-103	},
{	-691	,	-2947	,	-103	},
{	-697	,	-2954	,	-104	},
{	-704	,	-2963	,	-105	},
{	-709	,	-2966	,	-106	},
{	-715	,	-2973	,	-106	},
{	-724	,	-2990	,	-106	},
{	-730	,	-2992	,	-106	},
{	-739	,	-3012	,	-106	},
{	-745	,	-3014	,	-106	},
{	-753	,	-3031	,	-106	},
{	-760	,	-3041	,	-105	},
{	-768	,	-3057	,	-104	},
{	-777	,	-3073	,	-104	},
{	-783	,	-3084	,	-103	},
{	-790	,	-3096	,	-102	},
{	-796	,	-3107	,	-101	},
{	-803	,	-3116	,	-101	},
{	-810	,	-3130	,	-101	},
{	-817	,	-3144	,	-100	},
{	-822	,	-3149	,	-100	},
{	-831	,	-3167	,	-100	},
{	-838	,	-3177	,	-99	},
{	-845	,	-3191	,	-99	},
{	-851	,	-3202	,	-98	},
{	-859	,	-3219	,	-98	},
{	-866	,	-3232	,	-98	},
{	-873	,	-3242	,	-98	},
{	-883	,	-3263	,	-98	},
{	-891	,	-3277	,	-98	},
{	-896	,	-3285	,	-96	},
{	-903	,	-3300	,	-95	},
{	-909	,	-3315	,	-94	},
{	-916	,	-3329	,	-93	},
{	-922	,	-3342	,	-92	},
{	-927	,	-3352	,	-91	},
{	-935	,	-3374	,	-90	},
{	-940	,	-3387	,	-88	},
{	-944	,	-3396	,	-87	},
{	-953	,	-3419	,	-87	},
{	-959	,	-3427	,	-87	},
{	-968	,	-3447	,	-89	},
{	-974	,	-3455	,	-90	},
{	-982	,	-3467	,	-92	},
{	-990	,	-3484	,	-94	},
{	-994	,	-3491	,	-95	},
{	-1001	,	-3505	,	-98	},
{	-1011	,	-3523	,	-102	},
{	-1019	,	-3536	,	-105	},
{	-1027	,	-3548	,	-109	},
{	-1032	,	-3552	,	-112	},
{	-1037	,	-3561	,	-113	},
{	-1044	,	-3573	,	-116	},
{	-1046	,	-3570	,	-118	},
{	-1052	,	-3579	,	-121	},
{	-1060	,	-3594	,	-124	},
{	-1063	,	-3589	,	-128	},
{	-1067	,	-3596	,	-130	},
{	-1069	,	-3600	,	-131	}
};

#endif	/* TABLE_LUGE7_SN130_H */
