

#ifndef TABLE_LUGE7_SN135_H
#define	TABLE_LUGE7_SN135_H

// used in LUGE7_SN135 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14625 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-3672	,	2402	,	584	},
{	-3663	,	2396	,	585	},
{	-3666	,	2396	,	585	},
{	-3654	,	2391	,	585	},
{	-3649	,	2389	,	584	},
{	-3656	,	2394	,	586	},
{	-3644	,	2386	,	583	},
{	-3650	,	2392	,	584	},
{	-3641	,	2389	,	581	},
{	-3642	,	2389	,	582	},
{	-3636	,	2388	,	580	},
{	-3628	,	2386	,	578	},
{	-3625	,	2388	,	578	},
{	-3606	,	2379	,	575	},
{	-3600	,	2380	,	572	},
{	-3593	,	2382	,	570	},
{	-3569	,	2372	,	564	},
{	-3560	,	2372	,	561	},
{	-3559	,	2378	,	559	},
{	-3551	,	2381	,	556	},
{	-3546	,	2385	,	553	},
{	-3533	,	2384	,	550	},
{	-3517	,	2381	,	545	},
{	-3514	,	2387	,	544	},
{	-3500	,	2386	,	540	},
{	-3494	,	2390	,	539	},
{	-3494	,	2398	,	538	},
{	-3479	,	2397	,	535	},
{	-3469	,	2399	,	533	},
{	-3459	,	2400	,	530	},
{	-3453	,	2405	,	528	},
{	-3445	,	2411	,	525	},
{	-3430	,	2410	,	522	},
{	-3420	,	2413	,	519	},
{	-3414	,	2419	,	517	},
{	-3396	,	2417	,	513	},
{	-3378	,	2415	,	509	},
{	-3369	,	2418	,	507	},
{	-3366	,	2425	,	505	},
{	-3353	,	2428	,	501	},
{	-3341	,	2430	,	499	},
{	-3326	,	2432	,	496	},
{	-3315	,	2433	,	493	},
{	-3300	,	2434	,	489	},
{	-3297	,	2444	,	487	},
{	-3279	,	2442	,	484	},
{	-3269	,	2446	,	480	},
{	-3260	,	2452	,	478	},
{	-3249	,	2454	,	475	},
{	-3242	,	2461	,	473	},
{	-3231	,	2463	,	470	},
{	-3219	,	2467	,	466	},
{	-3214	,	2474	,	464	},
{	-3205	,	2479	,	462	},
{	-3190	,	2478	,	459	},
{	-3180	,	2483	,	457	},
{	-3170	,	2485	,	455	},
{	-3157	,	2486	,	451	},
{	-3148	,	2490	,	448	},
{	-3138	,	2496	,	446	},
{	-3122	,	2495	,	444	},
{	-3102	,	2490	,	440	},
{	-3102	,	2501	,	438	},
{	-3088	,	2501	,	436	},
{	-3072	,	2501	,	432	},
{	-3068	,	2510	,	430	},
{	-3052	,	2508	,	427	},
{	-3046	,	2514	,	424	},
{	-3028	,	2511	,	421	},
{	-3021	,	2515	,	418	},
{	-3008	,	2515	,	414	},
{	-3001	,	2521	,	412	},
{	-2988	,	2520	,	408	},
{	-2975	,	2521	,	404	},
{	-2966	,	2525	,	401	},
{	-2957	,	2529	,	397	},
{	-2941	,	2526	,	393	},
{	-2933	,	2530	,	390	},
{	-2929	,	2537	,	387	},
{	-2916	,	2536	,	383	},
{	-2913	,	2544	,	379	},
{	-2901	,	2544	,	376	},
{	-2885	,	2540	,	372	},
{	-2878	,	2545	,	370	},
{	-2868	,	2547	,	367	},
{	-2865	,	2554	,	365	},
{	-2847	,	2548	,	361	},
{	-2840	,	2552	,	358	},
{	-2829	,	2552	,	354	},
{	-2824	,	2559	,	351	},
{	-2816	,	2562	,	349	},
{	-2811	,	2566	,	346	},
{	-2805	,	2571	,	344	},
{	-2799	,	2575	,	341	},
{	-2792	,	2576	,	338	},
{	-2777	,	2573	,	334	},
{	-2768	,	2574	,	331	},
{	-2758	,	2574	,	327	},
{	-2753	,	2577	,	324	},
{	-2746	,	2579	,	319	},
{	-2733	,	2577	,	314	},
{	-2729	,	2581	,	310	},
{	-2717	,	2579	,	305	},
{	-2717	,	2587	,	302	},
{	-2707	,	2586	,	298	},
{	-2706	,	2595	,	294	},
{	-2692	,	2590	,	287	},
{	-2685	,	2592	,	283	},
{	-2675	,	2591	,	279	},
{	-2664	,	2590	,	273	},
{	-2658	,	2592	,	268	},
{	-2657	,	2599	,	264	},
{	-2652	,	2603	,	258	},
{	-2638	,	2601	,	253	},
{	-2631	,	2603	,	248	},
{	-2628	,	2611	,	244	},
{	-2615	,	2609	,	240	},
{	-2611	,	2614	,	235	},
{	-2603	,	2615	,	230	},
{	-2601	,	2623	,	226	},
{	-2590	,	2622	,	221	},
{	-2581	,	2624	,	216	},
{	-2572	,	2624	,	211	},
{	-2570	,	2632	,	206	},
{	-2561	,	2632	,	201	},
{	-2559	,	2639	,	197	},
{	-2549	,	2639	,	191	},
{	-2547	,	2646	,	187	},
{	-2533	,	2642	,	180	},
{	-2533	,	2652	,	176	},
{	-2537	,	2663	,	172	},
{	-2531	,	2666	,	166	},
{	-2523	,	2667	,	161	},
{	-2524	,	2677	,	155	},
{	-2522	,	2683	,	148	},
{	-2524	,	2694	,	144	},
{	-2520	,	2698	,	137	},
{	-2522	,	2707	,	132	},
{	-2525	,	2717	,	126	},
{	-2520	,	2719	,	120	},
{	-2517	,	2724	,	115	},
{	-2520	,	2735	,	110	},
{	-2518	,	2739	,	104	},
{	-2521	,	2750	,	99	},
{	-2518	,	2756	,	94	},
{	-2524	,	2769	,	88	},
{	-2518	,	2769	,	82	},
{	-2510	,	2768	,	76	},
{	-2512	,	2779	,	71	},
{	-2516	,	2788	,	65	},
{	-2517	,	2796	,	59	},
{	-2514	,	2800	,	54	},
{	-2508	,	2802	,	48	},
{	-2504	,	2806	,	43	},
{	-2497	,	2808	,	37	},
{	-2499	,	2819	,	32	},
{	-2501	,	2832	,	27	},
{	-2504	,	2843	,	23	},
{	-2504	,	2850	,	18	},
{	-2502	,	2856	,	13	},
{	-2498	,	2860	,	8	},
{	-2497	,	2865	,	3	},
{	-2495	,	2869	,	-2	},
{	-2495	,	2879	,	-7	},
{	-2500	,	2893	,	-13	},
{	-2497	,	2897	,	-18	},
{	-2494	,	2900	,	-23	},
{	-2486	,	2897	,	-28	},
{	-2489	,	2910	,	-34	},
{	-2485	,	2912	,	-38	},
{	-2488	,	2923	,	-43	},
{	-2487	,	2928	,	-48	},
{	-2480	,	2927	,	-53	},
{	-2478	,	2931	,	-60	},
{	-2471	,	2928	,	-65	},
{	-2470	,	2934	,	-71	},
{	-2471	,	2943	,	-78	},
{	-2471	,	2950	,	-84	},
{	-2466	,	2951	,	-90	},
{	-2462	,	2954	,	-95	},
{	-2460	,	2958	,	-100	},
{	-2456	,	2959	,	-104	},
{	-2454	,	2964	,	-110	},
{	-2451	,	2967	,	-115	},
{	-2456	,	2981	,	-121	},
{	-2452	,	2982	,	-125	},
{	-2454	,	2991	,	-130	},
{	-2454	,	2999	,	-135	},
{	-2452	,	3004	,	-139	},
{	-2453	,	3011	,	-144	},
{	-2448	,	3012	,	-148	},
{	-2444	,	3013	,	-152	},
{	-2443	,	3021	,	-158	},
{	-2438	,	3022	,	-162	},
{	-2433	,	3022	,	-167	},
{	-2432	,	3030	,	-173	},
{	-2428	,	3032	,	-178	},
{	-2428	,	3039	,	-184	},
{	-2425	,	3042	,	-189	},
{	-2424	,	3047	,	-194	},
{	-2427	,	3060	,	-200	},
{	-2422	,	3060	,	-205	},
{	-2415	,	3059	,	-209	},
{	-2409	,	3058	,	-215	},
{	-2403	,	3057	,	-220	},
{	-2400	,	3061	,	-226	},
{	-2396	,	3063	,	-232	},
{	-2400	,	3074	,	-238	},
{	-2398	,	3079	,	-244	},
{	-2393	,	3079	,	-249	},
{	-2392	,	3085	,	-254	},
{	-2390	,	3089	,	-258	},
{	-2391	,	3097	,	-262	},
{	-2388	,	3099	,	-266	},
{	-2389	,	3105	,	-271	},
{	-2388	,	3111	,	-276	},
{	-2386	,	3115	,	-281	},
{	-2379	,	3112	,	-285	},
{	-2376	,	3113	,	-290	},
{	-2378	,	3122	,	-295	},
{	-2383	,	3133	,	-300	},
{	-2379	,	3133	,	-306	},
{	-2381	,	3139	,	-310	},
{	-2379	,	3140	,	-315	},
{	-2369	,	3134	,	-319	},
{	-2373	,	3147	,	-325	},
{	-2373	,	3153	,	-331	},
{	-2374	,	3161	,	-337	},
{	-2370	,	3163	,	-343	},
{	-2367	,	3164	,	-348	},
{	-2370	,	3173	,	-354	},
{	-2369	,	3178	,	-359	},
{	-2364	,	3177	,	-364	},
{	-2358	,	3175	,	-369	},
{	-2363	,	3186	,	-375	},
{	-2360	,	3189	,	-379	},
{	-2360	,	3195	,	-384	},
{	-2356	,	3196	,	-388	},
{	-2358	,	3203	,	-392	},
{	-2354	,	3204	,	-396	},
{	-2356	,	3214	,	-402	},
{	-2355	,	3218	,	-406	},
{	-2354	,	3220	,	-410	},
{	-2351	,	3222	,	-414	},
{	-2342	,	3214	,	-416	},
{	-2345	,	3224	,	-420	},
{	-2341	,	3222	,	-424	},
{	-2335	,	3218	,	-427	},
{	-2326	,	3212	,	-430	},
{	-2325	,	3216	,	-434	},
{	-2326	,	3222	,	-438	},
{	-2314	,	3212	,	-440	},
{	-2319	,	3225	,	-445	},
{	-2313	,	3220	,	-449	},
{	-2311	,	3222	,	-452	},
{	-2302	,	3216	,	-456	},
{	-2304	,	3224	,	-460	},
{	-2299	,	3221	,	-462	},
{	-2299	,	3226	,	-465	},
{	-2298	,	3229	,	-469	},
{	-2291	,	3225	,	-470	},
{	-2296	,	3237	,	-474	},
{	-2289	,	3230	,	-477	},
{	-2289	,	3236	,	-480	},
{	-2288	,	3240	,	-483	},
{	-2288	,	3245	,	-485	},
{	-2284	,	3243	,	-487	},
{	-2277	,	3238	,	-489	},
{	-2283	,	3253	,	-494	},
{	-2277	,	3247	,	-496	},
{	-2271	,	3245	,	-498	},
{	-2269	,	3248	,	-502	},
{	-2266	,	3250	,	-506	},
{	-2262	,	3253	,	-510	},
{	-2264	,	3262	,	-516	},
{	-2256	,	3260	,	-519	},
{	-2250	,	3258	,	-523	},
{	-2250	,	3265	,	-529	},
{	-2247	,	3268	,	-534	},
{	-2248	,	3279	,	-541	},
{	-2242	,	3279	,	-545	},
{	-2247	,	3294	,	-553	},
{	-2238	,	3289	,	-557	},
{	-2238	,	3299	,	-564	},
{	-2243	,	3315	,	-572	},
{	-2232	,	3307	,	-576	},
{	-2232	,	3314	,	-582	},
{	-2231	,	3320	,	-587	},
{	-2226	,	3322	,	-593	},
{	-2234	,	3342	,	-601	},
{	-2230	,	3344	,	-605	},
{	-2223	,	3341	,	-610	},
{	-2219	,	3343	,	-614	},
{	-2219	,	3349	,	-621	},
{	-2214	,	3348	,	-625	},
{	-2211	,	3351	,	-630	},
{	-2205	,	3350	,	-634	},
{	-2199	,	3348	,	-638	},
{	-2192	,	3345	,	-642	},
{	-2194	,	3356	,	-648	},
{	-2188	,	3353	,	-652	},
{	-2180	,	3348	,	-655	},
{	-2183	,	3357	,	-661	},
{	-2182	,	3362	,	-665	},
{	-2179	,	3363	,	-670	},
{	-2177	,	3366	,	-674	},
{	-2170	,	3360	,	-677	},
{	-2164	,	3355	,	-680	},
{	-2166	,	3365	,	-685	},
{	-2172	,	3377	,	-691	},
{	-2164	,	3371	,	-692	},
{	-2166	,	3378	,	-696	},
{	-2165	,	3383	,	-700	},
{	-2160	,	3380	,	-702	},
{	-2165	,	3393	,	-709	},
{	-2159	,	3389	,	-711	},
{	-2153	,	3386	,	-713	},
{	-2153	,	3392	,	-717	},
{	-2157	,	3403	,	-722	},
{	-2152	,	3401	,	-724	},
{	-2147	,	3400	,	-727	},
{	-2145	,	3402	,	-729	},
{	-2142	,	3401	,	-731	},
{	-2138	,	3402	,	-734	},
{	-2138	,	3408	,	-737	},
{	-2131	,	3401	,	-738	},
{	-2131	,	3405	,	-741	},
{	-2128	,	3406	,	-744	},
{	-2129	,	3413	,	-748	},
{	-2125	,	3410	,	-749	},
{	-2127	,	3416	,	-752	},
{	-2120	,	3410	,	-753	},
{	-2123	,	3418	,	-756	},
{	-2124	,	3421	,	-758	},
{	-2121	,	3418	,	-760	},
{	-2120	,	3421	,	-762	},
{	-2118	,	3420	,	-764	},
{	-2115	,	3420	,	-766	},
{	-2115	,	3422	,	-768	},
{	-2118	,	3431	,	-772	},
{	-2115	,	3431	,	-773	},
{	-2119	,	3440	,	-777	},
{	-2118	,	3441	,	-779	},
{	-2113	,	3435	,	-779	},
{	-2119	,	3447	,	-783	},
{	-2110	,	3434	,	-782	},
{	-2114	,	3443	,	-785	},
{	-2111	,	3439	,	-786	},
{	-2110	,	3437	,	-787	},
{	-2114	,	3444	,	-790	},
{	-2112	,	3440	,	-791	},
{	-2111	,	3439	,	-791	},
{	-2109	,	3435	,	-791	},
{	-2111	,	3437	,	-793	},
{	-2108	,	3432	,	-793	},
{	-2107	,	3429	,	-793	},
{	-2107	,	3427	,	-794	},
{	-2102	,	3417	,	-793	},
{	-2101	,	3409	,	-793	},
{	-2103	,	3410	,	-794	},
{	-2105	,	3409	,	-795	},
{	-2103	,	3404	,	-795	},
{	-2106	,	3406	,	-797	},
{	-2101	,	3393	,	-795	},
{	-2099	,	3388	,	-794	},
{	-2099	,	3385	,	-795	},
{	-2093	,	3370	,	-793	},
{	-2093	,	3366	,	-792	},
{	-2096	,	3369	,	-793	},
{	-2091	,	3359	,	-791	},
{	-2086	,	3349	,	-790	},
{	-2092	,	3356	,	-793	},
{	-2089	,	3351	,	-793	},
{	-2079	,	3336	,	-791	},
{	-2085	,	3344	,	-794	},
{	-2079	,	3336	,	-794	},
{	-2077	,	3333	,	-795	},
{	-2070	,	3323	,	-793	},
{	-2067	,	3317	,	-792	},
{	-2064	,	3314	,	-791	},
{	-2062	,	3311	,	-791	},
{	-2064	,	3315	,	-793	},
{	-2063	,	3315	,	-793	},
{	-2060	,	3314	,	-793	},
{	-2061	,	3320	,	-796	},
{	-2054	,	3311	,	-796	}
};

#endif	/* TABLE_LUGE7_SN135_H */
