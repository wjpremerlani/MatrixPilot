

#ifndef TABLE_LUGE7_SN188_H
#define	TABLE_LUGE7_SN188_H

// used in LUGE7_SN188 partition size 64

#define X_CROSS_COUPLING 0
#define Y_CROSS_COUPLING 0
#define Z_CROSS_COUPLING 0


#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14518 )

int16_t residual_offset[] = { -1224 -4*145, -592 -20*4 , 95 -4*12 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	4261	,	-2892	,	491	},
{	4261	,	-2892	,	491	},
{	4257	,	-2888	,	492	},
{	4266	,	-2894	,	493	},
{	4263	,	-2893	,	493	},
{	4259	,	-2890	,	493	},
{	4264	,	-2894	,	494	},
{	4259	,	-2891	,	493	},
{	4265	,	-2895	,	495	},
{	4281	,	-2906	,	498	},
{	4278	,	-2904	,	500	},
{	4279	,	-2906	,	500	},
{	4282	,	-2908	,	501	},
{	4270	,	-2898	,	500	},
{	4276	,	-2901	,	500	},
{	4268	,	-2895	,	500	},
{	4271	,	-2895	,	500	},
{	4273	,	-2896	,	501	},
{	4275	,	-2897	,	502	},
{	4274	,	-2897	,	502	},
{	4266	,	-2891	,	502	},
{	4270	,	-2892	,	503	},
{	4277	,	-2897	,	504	},
{	4271	,	-2891	,	503	},
{	4272	,	-2890	,	504	},
{	4261	,	-2881	,	502	},
{	4270	,	-2886	,	503	},
{	4266	,	-2883	,	503	},
{	4261	,	-2877	,	501	},
{	4258	,	-2873	,	501	},
{	4266	,	-2878	,	502	},
{	4265	,	-2875	,	501	},
{	4266	,	-2874	,	501	},
{	4269	,	-2874	,	501	},
{	4266	,	-2869	,	500	},
{	4261	,	-2864	,	498	},
{	4270	,	-2869	,	498	},
{	4273	,	-2868	,	500	},
{	4275	,	-2869	,	499	},
{	4279	,	-2869	,	500	},
{	4271	,	-2864	,	499	},
{	4277	,	-2868	,	500	},
{	4288	,	-2875	,	501	},
{	4274	,	-2866	,	501	},
{	4275	,	-2867	,	500	},
{	4276	,	-2869	,	501	},
{	4270	,	-2865	,	498	},
{	4264	,	-2861	,	498	},
{	4268	,	-2864	,	498	},
{	4268	,	-2865	,	497	},
{	4261	,	-2862	,	496	},
{	4253	,	-2859	,	496	},
{	4252	,	-2861	,	496	},
{	4249	,	-2859	,	496	},
{	4241	,	-2856	,	494	},
{	4238	,	-2854	,	493	},
{	4235	,	-2854	,	493	},
{	4237	,	-2857	,	492	},
{	4228	,	-2852	,	490	},
{	4221	,	-2849	,	489	},
{	4224	,	-2851	,	487	},
{	4228	,	-2856	,	487	},
{	4216	,	-2849	,	485	},
{	4224	,	-2857	,	487	},
{	4222	,	-2857	,	486	},
{	4212	,	-2851	,	484	},
{	4204	,	-2847	,	483	},
{	4203	,	-2847	,	483	},
{	4211	,	-2853	,	482	},
{	4207	,	-2850	,	482	},
{	4194	,	-2842	,	480	},
{	4204	,	-2850	,	479	},
{	4195	,	-2845	,	478	},
{	4192	,	-2844	,	476	},
{	4186	,	-2840	,	475	},
{	4193	,	-2845	,	475	},
{	4188	,	-2844	,	474	},
{	4191	,	-2848	,	474	},
{	4181	,	-2843	,	472	},
{	4185	,	-2846	,	473	},
{	4176	,	-2840	,	470	},
{	4172	,	-2840	,	468	},
{	4163	,	-2837	,	466	},
{	4167	,	-2842	,	465	},
{	4164	,	-2844	,	463	},
{	4155	,	-2840	,	462	},
{	4155	,	-2843	,	461	},
{	4158	,	-2849	,	459	},
{	4150	,	-2847	,	457	},
{	4145	,	-2847	,	455	},
{	4139	,	-2847	,	452	},
{	4136	,	-2848	,	451	},
{	4132	,	-2850	,	449	},
{	4134	,	-2856	,	447	},
{	4116	,	-2847	,	444	},
{	4116	,	-2851	,	442	},
{	4107	,	-2848	,	438	},
{	4105	,	-2851	,	436	},
{	4109	,	-2858	,	435	},
{	4104	,	-2857	,	432	},
{	4099	,	-2856	,	430	},
{	4097	,	-2858	,	428	},
{	4086	,	-2853	,	424	},
{	4077	,	-2850	,	420	},
{	4070	,	-2848	,	419	},
{	4064	,	-2848	,	417	},
{	4054	,	-2844	,	414	},
{	4047	,	-2843	,	413	},
{	4044	,	-2845	,	411	},
{	4030	,	-2839	,	407	},
{	4017	,	-2835	,	405	},
{	4015	,	-2838	,	403	},
{	4015	,	-2840	,	403	},
{	4011	,	-2841	,	403	},
{	4000	,	-2837	,	401	},
{	3988	,	-2833	,	399	},
{	3988	,	-2839	,	398	},
{	3984	,	-2842	,	395	},
{	3965	,	-2835	,	391	},
{	3965	,	-2841	,	390	},
{	3952	,	-2837	,	388	},
{	3943	,	-2837	,	386	},
{	3934	,	-2836	,	384	},
{	3930	,	-2838	,	383	},
{	3918	,	-2837	,	380	},
{	3915	,	-2841	,	379	},
{	3901	,	-2836	,	377	},
{	3892	,	-2835	,	375	},
{	3882	,	-2835	,	373	},
{	3859	,	-2826	,	369	},
{	3844	,	-2824	,	366	},
{	3829	,	-2820	,	364	},
{	3809	,	-2814	,	362	},
{	3794	,	-2810	,	359	},
{	3774	,	-2804	,	358	},
{	3766	,	-2804	,	356	},
{	3752	,	-2803	,	353	},
{	3736	,	-2800	,	350	},
{	3722	,	-2797	,	347	},
{	3698	,	-2789	,	342	},
{	3678	,	-2784	,	338	},
{	3662	,	-2780	,	335	},
{	3643	,	-2777	,	332	},
{	3625	,	-2773	,	328	},
{	3606	,	-2769	,	325	},
{	3586	,	-2762	,	320	},
{	3579	,	-2766	,	318	},
{	3560	,	-2761	,	314	},
{	3537	,	-2754	,	309	},
{	3522	,	-2754	,	305	},
{	3495	,	-2744	,	301	},
{	3476	,	-2740	,	297	},
{	3450	,	-2731	,	292	},
{	3419	,	-2718	,	287	},
{	3403	,	-2716	,	284	},
{	3383	,	-2713	,	280	},
{	3363	,	-2708	,	277	},
{	3340	,	-2700	,	272	},
{	3315	,	-2693	,	268	},
{	3288	,	-2682	,	261	},
{	3274	,	-2681	,	257	},
{	3243	,	-2667	,	251	},
{	3225	,	-2664	,	246	},
{	3199	,	-2655	,	241	},
{	3176	,	-2646	,	236	},
{	3161	,	-2644	,	231	},
{	3146	,	-2640	,	227	},
{	3127	,	-2634	,	223	},
{	3110	,	-2629	,	219	},
{	3096	,	-2627	,	215	},
{	3081	,	-2624	,	211	},
{	3064	,	-2620	,	208	},
{	3041	,	-2611	,	203	},
{	3029	,	-2611	,	199	},
{	3018	,	-2612	,	195	},
{	2995	,	-2602	,	190	},
{	2980	,	-2600	,	186	},
{	2955	,	-2590	,	183	},
{	2944	,	-2590	,	179	},
{	2923	,	-2583	,	175	},
{	2897	,	-2571	,	171	},
{	2887	,	-2574	,	166	},
{	2871	,	-2570	,	163	},
{	2847	,	-2561	,	157	},
{	2828	,	-2555	,	153	},
{	2810	,	-2550	,	149	},
{	2794	,	-2546	,	145	},
{	2775	,	-2540	,	140	},
{	2759	,	-2538	,	136	},
{	2737	,	-2530	,	131	},
{	2718	,	-2524	,	127	},
{	2702	,	-2520	,	123	},
{	2684	,	-2516	,	119	},
{	2668	,	-2512	,	115	},
{	2654	,	-2510	,	110	},
{	2633	,	-2502	,	105	},
{	2619	,	-2501	,	101	},
{	2609	,	-2505	,	96	},
{	2592	,	-2501	,	91	},
{	2574	,	-2496	,	86	},
{	2556	,	-2491	,	82	},
{	2546	,	-2494	,	77	},
{	2523	,	-2485	,	71	},
{	2501	,	-2478	,	65	},
{	2487	,	-2478	,	60	},
{	2474	,	-2477	,	54	},
{	2461	,	-2475	,	50	},
{	2442	,	-2469	,	44	},
{	2421	,	-2460	,	39	},
{	2411	,	-2461	,	34	},
{	2396	,	-2459	,	30	},
{	2382	,	-2457	,	25	},
{	2369	,	-2455	,	21	},
{	2354	,	-2452	,	16	},
{	2332	,	-2440	,	12	},
{	2315	,	-2434	,	8	},
{	2304	,	-2435	,	3	},
{	2289	,	-2432	,	-2	},
{	2273	,	-2427	,	-7	},
{	2260	,	-2427	,	-11	},
{	2248	,	-2427	,	-16	},
{	2227	,	-2418	,	-21	},
{	2204	,	-2407	,	-25	},
{	2196	,	-2411	,	-30	},
{	2181	,	-2408	,	-36	},
{	2167	,	-2407	,	-42	},
{	2151	,	-2405	,	-48	},
{	2136	,	-2402	,	-54	},
{	2119	,	-2398	,	-59	},
{	2104	,	-2395	,	-65	},
{	2086	,	-2389	,	-70	},
{	2073	,	-2389	,	-76	},
{	2055	,	-2383	,	-82	},
{	2038	,	-2377	,	-86	},
{	2023	,	-2376	,	-91	},
{	2007	,	-2373	,	-96	},
{	1993	,	-2374	,	-101	},
{	1977	,	-2370	,	-107	},
{	1963	,	-2371	,	-112	},
{	1951	,	-2373	,	-117	},
{	1934	,	-2369	,	-122	},
{	1917	,	-2366	,	-126	},
{	1902	,	-2363	,	-130	},
{	1885	,	-2359	,	-133	},
{	1867	,	-2356	,	-138	},
{	1849	,	-2351	,	-141	},
{	1837	,	-2353	,	-145	},
{	1821	,	-2351	,	-149	},
{	1809	,	-2355	,	-153	},
{	1798	,	-2358	,	-157	},
{	1783	,	-2358	,	-162	},
{	1769	,	-2358	,	-165	},
{	1754	,	-2356	,	-168	},
{	1740	,	-2353	,	-172	},
{	1728	,	-2354	,	-176	},
{	1715	,	-2353	,	-180	},
{	1705	,	-2357	,	-184	},
{	1687	,	-2353	,	-188	},
{	1674	,	-2355	,	-192	},
{	1659	,	-2355	,	-196	},
{	1643	,	-2353	,	-200	},
{	1628	,	-2351	,	-205	},
{	1614	,	-2351	,	-210	},
{	1596	,	-2348	,	-215	},
{	1584	,	-2352	,	-219	},
{	1569	,	-2352	,	-224	},
{	1549	,	-2346	,	-228	},
{	1534	,	-2346	,	-233	},
{	1514	,	-2341	,	-238	},
{	1498	,	-2343	,	-243	},
{	1481	,	-2342	,	-248	},
{	1467	,	-2346	,	-254	},
{	1453	,	-2348	,	-259	},
{	1433	,	-2341	,	-264	},
{	1414	,	-2337	,	-269	},
{	1397	,	-2337	,	-274	},
{	1382	,	-2339	,	-280	},
{	1365	,	-2339	,	-285	},
{	1349	,	-2339	,	-290	},
{	1334	,	-2342	,	-295	},
{	1317	,	-2340	,	-299	},
{	1300	,	-2340	,	-305	},
{	1283	,	-2340	,	-310	},
{	1267	,	-2340	,	-315	},
{	1248	,	-2340	,	-321	},
{	1234	,	-2342	,	-326	},
{	1216	,	-2338	,	-330	},
{	1200	,	-2342	,	-335	},
{	1183	,	-2344	,	-339	},
{	1163	,	-2340	,	-343	},
{	1144	,	-2338	,	-348	},
{	1128	,	-2339	,	-353	},
{	1108	,	-2338	,	-357	},
{	1091	,	-2340	,	-362	},
{	1072	,	-2339	,	-367	},
{	1054	,	-2342	,	-372	},
{	1037	,	-2343	,	-377	},
{	1020	,	-2345	,	-382	},
{	1000	,	-2345	,	-387	},
{	979	,	-2338	,	-391	},
{	963	,	-2344	,	-396	},
{	943	,	-2345	,	-401	},
{	923	,	-2344	,	-405	},
{	904	,	-2345	,	-410	},
{	883	,	-2341	,	-415	},
{	863	,	-2339	,	-419	},
{	846	,	-2340	,	-424	},
{	830	,	-2346	,	-430	},
{	812	,	-2347	,	-435	},
{	796	,	-2349	,	-439	},
{	778	,	-2350	,	-444	},
{	762	,	-2350	,	-448	},
{	744	,	-2348	,	-452	},
{	728	,	-2351	,	-457	},
{	713	,	-2356	,	-462	},
{	694	,	-2352	,	-465	},
{	677	,	-2354	,	-470	},
{	658	,	-2351	,	-474	},
{	642	,	-2353	,	-478	},
{	628	,	-2358	,	-484	},
{	611	,	-2357	,	-487	},
{	593	,	-2356	,	-491	},
{	575	,	-2351	,	-493	},
{	557	,	-2358	,	-499	},
{	539	,	-2354	,	-501	},
{	531	,	-2356	,	-504	},
{	522	,	-2355	,	-505	},
{	514	,	-2353	,	-506	},
{	505	,	-2356	,	-508	},
{	496	,	-2357	,	-511	},
{	485	,	-2354	,	-512	},
{	474	,	-2349	,	-513	},
{	466	,	-2354	,	-516	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11896)

int16_t accel_residual_offset[] = { 10 , -11 , -15 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{0,-1,1},
{0,0,0},
{0,0,0},
{0,-1,0},
{0,-1,-1},
{0,-2,-2},
{0,-3,-4},
{0,-3,-5},
{0,-3,1},
{0,-3,5},
{0,-3,2},
{1,-3,0},
{1,-3,0},
{1,-3,0},
{1,-4,-1},
{1,-4,-1},
{1,-4,-1},
{1,-4,-2},
{1,-5,-2},
{1,-5,-2},
{1,-6,-3},
{1,-6,-3},
{1,-6,-3},
{1,-6,-3},
{1,-6,-3},
{1,-7,-3},
{1,-7,-3},
{2,-7,-3},
{1,-8,-3},
{1,-8,-3},
{1,-8,-3},
{1,-9,-3},
{1,-9,-4},
{1,-9,-3},
{2,-9,-3},
{2,-10,-3},
{1,-10,-4},
{1,-10,-4},
{1,-10,-4},
{1,-10,-4},
{0,-9,-4},
{1,-10,-4},
{2,-11,-4},
{2,-11,-4},
{2,-11,-4},
{2,-11,-4},
{2,-12,-4},
{2,-12,-4},
{2,-12,-4},
{2,-13,-4},
{2,-13,-4},
{2,-13,-4},
{2,-13,-4},
{2,-14,-4},
{3,-14,-4},
{2,-14,-4},
{2,-14,-4},
{3,-15,-4},
{3,-15,-4},
{2,-15,-4},
{2,-16,-4},
{2,-16,-4},
{2,-16,-4},
{2,-17,-4},
{3,-17,-4},
{2,-17,-4},
{2,-17,-4},
{3,-17,-4},
{2,-18,-4},
{2,-18,-4},
{2,-18,-4},
{2,-18,-5},
{2,-18,-4},
{3,-19,-4},
{3,-19,-4},
{3,-19,-5},
{3,-20,-5},
{3,-20,-5},
{3,-20,-5},
{3,-20,-5},
{3,-21,-5},
{3,-20,-5},
{2,-20,-5},
{2,-20,-5},
{3,-21,-5},
{3,-21,-5},
{3,-21,-5},
{3,-21,-5},
{3,-21,-5},
{3,-22,-5},
{3,-22,-5},
{3,-22,-5},
{3,-22,-5},
{3,-22,-5},
{3,-21,-5},
{3,-21,-5},
{3,-21,-6},
{3,-21,-6},
{3,-21,-6},
{3,-21,-6},
{3,-21,-6},
{3,-21,-6},
{3,-21,-6},
{3,-20,-7},
{3,-20,-7},
{3,-20,-7},
{3,-20,-7},
{3,-20,-7},
{2,-20,-8},
{2,-21,-8},
{2,-21,-8},
{2,-22,-9},
{2,-22,-9},
{2,-22,-9},
{2,-22,-9},
{2,-23,-10},
{2,-23,-10},
{2,-23,-10},
{1,-24,-10},
{1,-24,-10},
{1,-24,-11},
{1,-24,-11},
{1,-25,-11},
{1,-25,-11},
{1,-25,-11},
{1,-25,-11},
{1,-25,-11},
{0,-26,-11},
{0,-26,-11},
{0,-26,-11},
{0,-26,-11},
{0,-27,-11},
{0,-27,-10},
{0,-27,-10},
{0,-27,-10},
{0,-27,-10},
{0,-28,-10},
{0,-28,-9},
{0,-28,-9},
{0,-28,-9},
{0,-28,-9},
{0,-29,-9},
{0,-29,-8},
{0,-29,-8},
{0,-29,-7},
{0,-29,-7},
{0,-30,-7},
{0,-30,-6},
{0,-30,-6},
{0,-30,-6},
{-1,-30,-6},
{-1,-31,-5},
{-1,-31,-5},
{-1,-31,-5},
{-1,-31,-4},
{-1,-31,-4},
{-1,-32,-4},
{-1,-32,-3},
{-1,-32,-3},
{-1,-32,-2},
{-1,-33,-2},
{-1,-33,-2},
{-1,-33,-1},
{-2,-33,-1},
{-2,-34,0},
{-2,-34,0},
{-2,-34,0},
{-2,-34,0},
{-2,-34,0},
{-2,-35,0},
{-2,-35,1},
{-2,-35,1},
{-3,-36,1},
{-3,-36,2},
{-3,-36,2},
{-3,-36,2},
{-3,-37,3},
{-3,-37,3},
{-3,-37,4},
{-3,-37,4},
{-3,-38,4},
{-3,-38,5},
{-3,-38,5},
{-4,-38,6},
{-4,-39,6},
{-4,-39,6},
{-4,-39,7},
{-4,-39,7},
{-4,-40,7},
{-4,-40,8},
{-5,-40,8},
{-5,-40,9},
{-5,-41,9},
{-5,-41,9},
{-5,-41,10},
{-5,-41,10},
{-5,-42,10},
{-5,-42,11},
{-5,-42,11},
{-5,-42,11},
{-5,-42,12},
{-5,-43,12},
{-5,-43,12},
{-5,-43,13},
{-5,-43,13},
{-6,-43,14},
{-6,-43,14},
{-6,-43,14},
{-6,-44,15},
{-6,-44,15},
{-6,-44,15},
{-6,-45,15},
{-6,-45,16},
{-6,-45,16},
{-6,-45,16},
{-6,-45,17},
{-6,-46,17},
{-6,-46,17},
{-7,-46,17},
{-7,-46,18},
{-7,-47,18},
{-7,-47,18},
{-7,-47,19},
{-7,-47,19},
{-7,-47,20},
{-7,-48,20},
{-7,-48,20},
{-7,-48,20},
{-8,-48,21},
{-8,-48,21},
{-8,-48,22},
{-8,-49,22},
{-8,-49,22},
{-8,-49,23},
{-8,-49,23},
{-8,-50,24},
{-8,-50,24},
{-8,-50,24},
{-9,-50,25},
{-9,-50,25},
{-9,-50,26},
{-9,-50,26},
{-9,-50,27},
};



#endif	/* TABLE_LUGE7_SN188_H */

