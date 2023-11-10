

#ifndef TABLE_LUGE7_SN125_H
#define	TABLE_LUGE7_SN125_H

// used in LUGE7_SN125 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14502 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-3226	,	-1305	,	-479	},
{	-3234	,	-1315	,	-480	},
{	-3224	,	-1317	,	-479	},
{	-3211	,	-1320	,	-477	},
{	-3209	,	-1326	,	-478	},
{	-3197	,	-1328	,	-478	},
{	-3199	,	-1335	,	-478	},
{	-3189	,	-1337	,	-477	},
{	-3184	,	-1342	,	-478	},
{	-3174	,	-1351	,	-478	},
{	-3159	,	-1359	,	-476	},
{	-3143	,	-1364	,	-474	},
{	-3138	,	-1376	,	-475	},
{	-3117	,	-1378	,	-473	},
{	-3098	,	-1384	,	-470	},
{	-3089	,	-1394	,	-470	},
{	-3075	,	-1402	,	-468	},
{	-3056	,	-1409	,	-466	},
{	-3036	,	-1414	,	-464	},
{	-3021	,	-1423	,	-462	},
{	-3007	,	-1430	,	-462	},
{	-2994	,	-1439	,	-461	},
{	-2983	,	-1447	,	-459	},
{	-2959	,	-1451	,	-455	},
{	-2946	,	-1460	,	-454	},
{	-2927	,	-1465	,	-451	},
{	-2913	,	-1473	,	-448	},
{	-2905	,	-1485	,	-448	},
{	-2889	,	-1492	,	-446	},
{	-2870	,	-1499	,	-444	},
{	-2858	,	-1508	,	-442	},
{	-2844	,	-1516	,	-441	},
{	-2828	,	-1523	,	-438	},
{	-2817	,	-1533	,	-437	},
{	-2801	,	-1539	,	-434	},
{	-2785	,	-1546	,	-433	},
{	-2775	,	-1557	,	-432	},
{	-2764	,	-1564	,	-430	},
{	-2744	,	-1569	,	-427	},
{	-2732	,	-1579	,	-425	},
{	-2721	,	-1590	,	-425	},
{	-2710	,	-1600	,	-424	},
{	-2696	,	-1607	,	-421	},
{	-2686	,	-1617	,	-419	},
{	-2668	,	-1624	,	-417	},
{	-2654	,	-1632	,	-414	},
{	-2639	,	-1638	,	-413	},
{	-2627	,	-1647	,	-411	},
{	-2618	,	-1657	,	-410	},
{	-2596	,	-1661	,	-407	},
{	-2584	,	-1668	,	-405	},
{	-2578	,	-1681	,	-405	},
{	-2567	,	-1691	,	-404	},
{	-2548	,	-1694	,	-401	},
{	-2537	,	-1703	,	-399	},
{	-2528	,	-1711	,	-398	},
{	-2514	,	-1719	,	-396	},
{	-2499	,	-1725	,	-394	},
{	-2487	,	-1734	,	-393	},
{	-2477	,	-1744	,	-391	},
{	-2462	,	-1751	,	-389	},
{	-2454	,	-1762	,	-387	},
{	-2436	,	-1765	,	-385	},
{	-2429	,	-1779	,	-384	},
{	-2416	,	-1789	,	-383	},
{	-2410	,	-1801	,	-381	},
{	-2403	,	-1814	,	-380	},
{	-2392	,	-1825	,	-379	},
{	-2374	,	-1830	,	-375	},
{	-2360	,	-1836	,	-373	},
{	-2352	,	-1848	,	-371	},
{	-2341	,	-1859	,	-369	},
{	-2324	,	-1865	,	-367	},
{	-2316	,	-1877	,	-366	},
{	-2304	,	-1885	,	-364	},
{	-2290	,	-1891	,	-361	},
{	-2280	,	-1900	,	-360	},
{	-2273	,	-1912	,	-359	},
{	-2260	,	-1919	,	-357	},
{	-2255	,	-1932	,	-357	},
{	-2241	,	-1937	,	-354	},
{	-2232	,	-1946	,	-352	},
{	-2220	,	-1951	,	-351	},
{	-2212	,	-1960	,	-350	},
{	-2198	,	-1964	,	-348	},
{	-2192	,	-1973	,	-347	},
{	-2181	,	-1980	,	-345	},
{	-2175	,	-1991	,	-344	},
{	-2166	,	-1998	,	-343	},
{	-2164	,	-2014	,	-342	},
{	-2152	,	-2018	,	-340	},
{	-2145	,	-2028	,	-338	},
{	-2140	,	-2036	,	-336	},
{	-2135	,	-2047	,	-335	},
{	-2129	,	-2056	,	-335	},
{	-2118	,	-2060	,	-333	},
{	-2112	,	-2069	,	-331	},
{	-2106	,	-2077	,	-329	},
{	-2095	,	-2080	,	-327	},
{	-2092	,	-2090	,	-325	},
{	-2088	,	-2100	,	-324	},
{	-2083	,	-2108	,	-323	},
{	-2076	,	-2113	,	-320	},
{	-2075	,	-2124	,	-318	},
{	-2071	,	-2131	,	-316	},
{	-2064	,	-2135	,	-313	},
{	-2058	,	-2139	,	-310	},
{	-2051	,	-2143	,	-308	},
{	-2050	,	-2152	,	-306	},
{	-2048	,	-2162	,	-305	},
{	-2040	,	-2164	,	-303	},
{	-2032	,	-2167	,	-300	},
{	-2034	,	-2179	,	-299	},
{	-2029	,	-2185	,	-297	},
{	-2026	,	-2190	,	-295	},
{	-2026	,	-2200	,	-294	},
{	-2018	,	-2200	,	-292	},
{	-2017	,	-2209	,	-290	},
{	-2017	,	-2216	,	-288	},
{	-2017	,	-2224	,	-287	},
{	-2013	,	-2227	,	-286	},
{	-2009	,	-2231	,	-285	},
{	-2010	,	-2238	,	-283	},
{	-2008	,	-2241	,	-282	},
{	-2010	,	-2247	,	-281	},
{	-2010	,	-2250	,	-280	},
{	-2011	,	-2255	,	-279	},
{	-2014	,	-2261	,	-278	},
{	-2017	,	-2267	,	-277	},
{	-2019	,	-2272	,	-275	},
{	-2020	,	-2272	,	-274	},
{	-2027	,	-2281	,	-273	},
{	-2030	,	-2283	,	-272	},
{	-2040	,	-2293	,	-271	},
{	-2042	,	-2293	,	-269	},
{	-2052	,	-2302	,	-268	},
{	-2052	,	-2300	,	-267	},
{	-2061	,	-2305	,	-266	},
{	-2071	,	-2309	,	-265	},
{	-2079	,	-2310	,	-263	},
{	-2086	,	-2313	,	-262	},
{	-2100	,	-2320	,	-261	},
{	-2107	,	-2322	,	-259	},
{	-2117	,	-2324	,	-257	},
{	-2123	,	-2323	,	-256	},
{	-2136	,	-2328	,	-253	},
{	-2143	,	-2326	,	-252	},
{	-2158	,	-2333	,	-251	},
{	-2161	,	-2327	,	-249	},
{	-2174	,	-2332	,	-248	},
{	-2177	,	-2327	,	-246	},
{	-2183	,	-2325	,	-244	},
{	-2193	,	-2329	,	-244	},
{	-2203	,	-2331	,	-242	},
{	-2214	,	-2336	,	-242	},
{	-2218	,	-2336	,	-239	},
{	-2225	,	-2340	,	-238	},
{	-2235	,	-2344	,	-237	},
{	-2236	,	-2340	,	-235	},
{	-2240	,	-2341	,	-234	},
{	-2243	,	-2340	,	-233	},
{	-2251	,	-2344	,	-231	},
{	-2256	,	-2345	,	-231	},
{	-2264	,	-2350	,	-231	},
{	-2266	,	-2350	,	-230	},
{	-2272	,	-2354	,	-229	},
{	-2273	,	-2352	,	-226	},
{	-2283	,	-2359	,	-226	},
{	-2291	,	-2365	,	-225	},
{	-2291	,	-2362	,	-223	},
{	-2298	,	-2367	,	-223	},
{	-2297	,	-2366	,	-221	},
{	-2308	,	-2376	,	-220	},
{	-2313	,	-2378	,	-220	},
{	-2317	,	-2381	,	-219	},
{	-2323	,	-2388	,	-219	},
{	-2324	,	-2388	,	-218	},
{	-2333	,	-2397	,	-216	},
{	-2335	,	-2398	,	-215	},
{	-2336	,	-2399	,	-214	},
{	-2340	,	-2403	,	-213	},
{	-2345	,	-2407	,	-211	},
{	-2350	,	-2411	,	-209	},
{	-2359	,	-2421	,	-209	},
{	-2361	,	-2424	,	-208	},
{	-2361	,	-2423	,	-206	},
{	-2364	,	-2427	,	-205	},
{	-2371	,	-2433	,	-203	},
{	-2375	,	-2437	,	-203	},
{	-2370	,	-2431	,	-200	},
{	-2377	,	-2438	,	-199	},
{	-2379	,	-2440	,	-198	},
{	-2386	,	-2447	,	-197	},
{	-2394	,	-2455	,	-195	},
{	-2393	,	-2453	,	-194	},
{	-2397	,	-2457	,	-193	},
{	-2400	,	-2460	,	-192	},
{	-2403	,	-2462	,	-190	},
{	-2406	,	-2464	,	-189	},
{	-2416	,	-2474	,	-188	},
{	-2416	,	-2475	,	-187	},
{	-2420	,	-2478	,	-186	},
{	-2428	,	-2486	,	-186	},
{	-2436	,	-2492	,	-184	},
{	-2444	,	-2499	,	-183	},
{	-2445	,	-2498	,	-182	},
{	-2458	,	-2509	,	-182	},
{	-2468	,	-2517	,	-181	},
{	-2475	,	-2523	,	-180	},
{	-2481	,	-2527	,	-178	},
{	-2487	,	-2532	,	-178	},
{	-2500	,	-2543	,	-177	},
{	-2506	,	-2548	,	-176	},
{	-2515	,	-2555	,	-176	},
{	-2525	,	-2564	,	-175	},
{	-2528	,	-2567	,	-174	},
{	-2533	,	-2570	,	-173	},
{	-2539	,	-2575	,	-173	},
{	-2551	,	-2585	,	-172	},
{	-2558	,	-2589	,	-171	},
{	-2566	,	-2596	,	-170	},
{	-2568	,	-2596	,	-170	},
{	-2579	,	-2605	,	-169	},
{	-2586	,	-2610	,	-167	},
{	-2587	,	-2609	,	-165	},
{	-2595	,	-2615	,	-164	},
{	-2594	,	-2611	,	-163	},
{	-2607	,	-2621	,	-162	},
{	-2604	,	-2616	,	-161	},
{	-2622	,	-2631	,	-161	},
{	-2626	,	-2632	,	-158	},
{	-2629	,	-2631	,	-156	},
{	-2637	,	-2635	,	-156	},
{	-2642	,	-2636	,	-154	},
{	-2653	,	-2643	,	-153	},
{	-2657	,	-2642	,	-151	},
{	-2663	,	-2644	,	-150	},
{	-2672	,	-2649	,	-148	},
{	-2676	,	-2650	,	-147	},
{	-2685	,	-2655	,	-146	},
{	-2687	,	-2654	,	-145	},
{	-2688	,	-2652	,	-143	},
{	-2699	,	-2658	,	-143	},
{	-2709	,	-2664	,	-142	},
{	-2715	,	-2665	,	-142	},
{	-2723	,	-2670	,	-141	},
{	-2727	,	-2669	,	-140	},
{	-2734	,	-2674	,	-139	},
{	-2748	,	-2685	,	-139	},
{	-2761	,	-2694	,	-139	},
{	-2769	,	-2697	,	-138	},
{	-2774	,	-2700	,	-137	},
{	-2780	,	-2704	,	-137	},
{	-2792	,	-2712	,	-137	},
{	-2794	,	-2713	,	-137	},
{	-2803	,	-2718	,	-136	},
{	-2809	,	-2722	,	-135	},
{	-2822	,	-2732	,	-135	},
{	-2838	,	-2744	,	-135	},
{	-2837	,	-2741	,	-134	},
{	-2845	,	-2749	,	-134	},
{	-2853	,	-2755	,	-133	},
{	-2870	,	-2768	,	-132	},
{	-2874	,	-2770	,	-131	},
{	-2880	,	-2774	,	-131	},
{	-2880	,	-2772	,	-129	},
{	-2888	,	-2777	,	-128	},
{	-2892	,	-2779	,	-126	},
{	-2899	,	-2785	,	-125	},
{	-2908	,	-2790	,	-124	},
{	-2914	,	-2794	,	-122	},
{	-2926	,	-2805	,	-121	},
{	-2940	,	-2816	,	-120	},
{	-2953	,	-2827	,	-117	},
{	-2960	,	-2831	,	-115	},
{	-2962	,	-2833	,	-114	},
{	-2987	,	-2857	,	-113	},
{	-2999	,	-2867	,	-111	},
{	-3013	,	-2879	,	-108	},
{	-3017	,	-2882	,	-105	},
{	-3032	,	-2896	,	-104	},
{	-3043	,	-2907	,	-102	},
{	-3058	,	-2921	,	-100	},
{	-3064	,	-2927	,	-97	},
{	-3084	,	-2947	,	-95	},
{	-3094	,	-2957	,	-93	},
{	-3111	,	-2975	,	-91	},
{	-3118	,	-2982	,	-89	},
{	-3136	,	-2999	,	-87	},
{	-3147	,	-3010	,	-85	},
{	-3155	,	-3015	,	-83	},
{	-3165	,	-3024	,	-82	},
{	-3180	,	-3036	,	-81	},
{	-3177	,	-3029	,	-79	},
{	-3182	,	-3030	,	-78	},
{	-3186	,	-3031	,	-76	},
{	-3200	,	-3040	,	-75	},
{	-3208	,	-3042	,	-73	},
{	-3216	,	-3044	,	-72	},
{	-3221	,	-3044	,	-71	},
{	-3232	,	-3048	,	-70	},
{	-3232	,	-3041	,	-69	},
{	-3245	,	-3045	,	-69	},
{	-3250	,	-3042	,	-68	},
{	-3264	,	-3048	,	-67	},
{	-3257	,	-3034	,	-66	},
{	-3266	,	-3034	,	-65	},
{	-3280	,	-3041	,	-64	},
{	-3285	,	-3039	,	-63	},
{	-3295	,	-3041	,	-61	},
{	-3307	,	-3049	,	-60	},
{	-3321	,	-3055	,	-59	},
{	-3327	,	-3055	,	-58	},
{	-3334	,	-3057	,	-57	},
{	-3337	,	-3054	,	-57	},
{	-3352	,	-3064	,	-56	},
{	-3372	,	-3079	,	-55	},
{	-3377	,	-3079	,	-55	},
{	-3395	,	-3092	,	-54	},
{	-3398	,	-3091	,	-53	},
{	-3406	,	-3094	,	-52	},
{	-3416	,	-3099	,	-51	},
{	-3434	,	-3112	,	-51	},
{	-3446	,	-3121	,	-51	},
{	-3451	,	-3122	,	-50	},
{	-3466	,	-3130	,	-50	},
{	-3469	,	-3129	,	-49	},
{	-3482	,	-3135	,	-48	},
{	-3487	,	-3138	,	-47	},
{	-3504	,	-3149	,	-47	},
{	-3515	,	-3155	,	-46	},
{	-3522	,	-3158	,	-44	},
{	-3535	,	-3167	,	-43	},
{	-3534	,	-3162	,	-43	},
{	-3558	,	-3179	,	-42	},
{	-3562	,	-3180	,	-41	},
{	-3576	,	-3190	,	-40	},
{	-3591	,	-3201	,	-39	},
{	-3601	,	-3206	,	-38	},
{	-3610	,	-3211	,	-37	},
{	-3615	,	-3211	,	-37	},
{	-3633	,	-3223	,	-35	},
{	-3645	,	-3232	,	-33	},
{	-3666	,	-3247	,	-32	},
{	-3665	,	-3244	,	-31	},
{	-3681	,	-3254	,	-30	},
{	-3687	,	-3256	,	-28	},
{	-3692	,	-3257	,	-26	},
{	-3711	,	-3271	,	-25	},
{	-3720	,	-3276	,	-24	},
{	-3728	,	-3279	,	-23	},
{	-3732	,	-3279	,	-21	},
{	-3746	,	-3289	,	-20	},
{	-3747	,	-3286	,	-19	},
{	-3759	,	-3293	,	-18	},
{	-3767	,	-3297	,	-17	},
{	-3777	,	-3303	,	-16	},
{	-3788	,	-3310	,	-14	},
{	-3786	,	-3305	,	-13	},
{	-3792	,	-3307	,	-12	},
{	-3791	,	-3304	,	-11	},
{	-3807	,	-3317	,	-11	},
{	-3816	,	-3322	,	-10	},
{	-3824	,	-3329	,	-9	},
{	-3845	,	-3345	,	-8	},
{	-3850	,	-3346	,	-7	},
{	-3847	,	-3342	,	-6	},
{	-3864	,	-3355	,	-4	},
{	-3876	,	-3363	,	-3	},
{	-3876	,	-3361	,	0	},
{	-3891	,	-3372	,	1	},
{	-3889	,	-3367	,	2	},
{	-3892	,	-3368	,	4	},
{	-3896	,	-3368	,	6	},
{	-3904	,	-3373	,	9	},
{	-3916	,	-3381	,	11	},
{	-3923	,	-3386	,	12	},
{	-3939	,	-3398	,	14	},
{	-3937	,	-3394	,	17	},
{	-3944	,	-3398	,	20	},
{	-3955	,	-3405	,	22	},
{	-3948	,	-3397	,	24	},
{	-3947	,	-3396	,	27	},
{	-3961	,	-3407	,	29	},
{	-3961	,	-3407	,	32	},
{	-3964	,	-3411	,	35	},
{	-3969	,	-3416	,	35	},
{	-3971	,	-3418	,	37	},
{	-3979	,	-3425	,	39	},
{	-3986	,	-3430	,	40	},
{	-3990	,	-3435	,	42	},
{	-3988	,	-3433	,	43	},
{	-3987	,	-3434	,	44	},
{	-3988	,	-3435	,	46	}
};

#endif	/* TABLE_LUGE7_SN125_H */

