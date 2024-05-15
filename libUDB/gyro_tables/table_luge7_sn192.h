

#ifndef TABLE_LUGE7_SN192_H
#define	TABLE_LUGE7_SN192_H

// used in LUGE7_SN192 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14485 )

int16_t residual_offset[] = { -1054 , 1 , 346 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	3561	,	-4217	,	-1555	},
{	3575	,	-4227	,	-1555	},
{	3588	,	-4234	,	-1555	},
{	3598	,	-4241	,	-1554	},
{	3612	,	-4248	,	-1553	},
{	3609	,	-4238	,	-1546	},
{	3621	,	-4244	,	-1544	},
{	3624	,	-4240	,	-1540	},
{	3625	,	-4233	,	-1535	},
{	3636	,	-4233	,	-1529	},
{	3650	,	-4237	,	-1524	},
{	3660	,	-4234	,	-1516	},
{	3674	,	-4234	,	-1509	},
{	3683	,	-4227	,	-1499	},
{	3693	,	-4223	,	-1488	},
{	3699	,	-4213	,	-1477	},
{	3715	,	-4215	,	-1469	},
{	3721	,	-4206	,	-1458	},
{	3733	,	-4202	,	-1449	},
{	3731	,	-4186	,	-1435	},
{	3735	,	-4173	,	-1423	},
{	3737	,	-4159	,	-1412	},
{	3754	,	-4163	,	-1407	},
{	3754	,	-4147	,	-1394	},
{	3763	,	-4143	,	-1385	},
{	3774	,	-4140	,	-1376	},
{	3781	,	-4133	,	-1366	},
{	3792	,	-4128	,	-1356	},
{	3809	,	-4132	,	-1350	},
{	3811	,	-4120	,	-1339	},
{	3813	,	-4108	,	-1327	},
{	3823	,	-4104	,	-1319	},
{	3830	,	-4099	,	-1310	},
{	3836	,	-4090	,	-1301	},
{	3842	,	-4081	,	-1291	},
{	3844	,	-4069	,	-1279	},
{	3857	,	-4067	,	-1271	},
{	3860	,	-4056	,	-1260	},
{	3871	,	-4054	,	-1251	},
{	3875	,	-4042	,	-1239	},
{	3875	,	-4028	,	-1227	},
{	3890	,	-4027	,	-1218	},
{	3903	,	-4027	,	-1210	},
{	3908	,	-4016	,	-1198	},
{	3911	,	-4005	,	-1187	},
{	3914	,	-3993	,	-1175	},
{	3929	,	-3994	,	-1166	},
{	3934	,	-3986	,	-1155	},
{	3944	,	-3982	,	-1146	},
{	3957	,	-3981	,	-1136	},
{	3966	,	-3977	,	-1126	},
{	3976	,	-3974	,	-1117	},
{	3981	,	-3964	,	-1106	},
{	3988	,	-3958	,	-1095	},
{	4004	,	-3962	,	-1087	},
{	4009	,	-3952	,	-1075	},
{	4013	,	-3942	,	-1062	},
{	4028	,	-3942	,	-1054	},
{	4020	,	-3922	,	-1039	},
{	4024	,	-3911	,	-1028	},
{	4036	,	-3908	,	-1020	},
{	4044	,	-3900	,	-1010	},
{	4050	,	-3893	,	-999	},
{	4060	,	-3887	,	-989	},
{	4075	,	-3887	,	-981	},
{	4078	,	-3874	,	-969	},
{	4086	,	-3867	,	-959	},
{	4091	,	-3857	,	-948	},
{	4100	,	-3853	,	-938	},
{	4112	,	-3851	,	-929	},
{	4116	,	-3842	,	-918	},
{	4111	,	-3824	,	-907	},
{	4119	,	-3819	,	-897	},
{	4131	,	-3818	,	-888	},
{	4142	,	-3817	,	-879	},
{	4152	,	-3812	,	-870	},
{	4154	,	-3802	,	-859	},
{	4168	,	-3805	,	-850	},
{	4166	,	-3792	,	-837	},
{	4176	,	-3790	,	-827	},
{	4178	,	-3781	,	-817	},
{	4173	,	-3766	,	-805	},
{	4182	,	-3763	,	-795	},
{	4189	,	-3759	,	-784	},
{	4200	,	-3758	,	-775	},
{	4197	,	-3744	,	-763	},
{	4197	,	-3735	,	-753	},
{	4204	,	-3730	,	-743	},
{	4216	,	-3731	,	-733	},
{	4219	,	-3723	,	-721	},
{	4221	,	-3714	,	-710	},
{	4231	,	-3712	,	-700	},
{	4236	,	-3707	,	-690	},
{	4241	,	-3702	,	-680	},
{	4236	,	-3687	,	-669	},
{	4246	,	-3687	,	-661	},
{	4247	,	-3679	,	-651	},
{	4242	,	-3665	,	-641	},
{	4253	,	-3666	,	-633	},
{	4252	,	-3657	,	-623	},
{	4246	,	-3644	,	-612	},
{	4243	,	-3632	,	-602	},
{	4246	,	-3627	,	-593	},
{	4251	,	-3622	,	-583	},
{	4244	,	-3607	,	-572	},
{	4249	,	-3605	,	-562	},
{	4242	,	-3592	,	-553	},
{	4243	,	-3584	,	-544	},
{	4236	,	-3571	,	-534	},
{	4247	,	-3572	,	-525	},
{	4243	,	-3563	,	-514	},
{	4246	,	-3559	,	-504	},
{	4244	,	-3549	,	-495	},
{	4241	,	-3541	,	-484	},
{	4238	,	-3532	,	-472	},
{	4234	,	-3524	,	-462	},
{	4230	,	-3514	,	-452	},
{	4241	,	-3518	,	-443	},
{	4229	,	-3504	,	-433	},
{	4234	,	-3503	,	-424	},
{	4226	,	-3493	,	-413	},
{	4225	,	-3490	,	-403	},
{	4218	,	-3479	,	-392	},
{	4226	,	-3481	,	-384	},
{	4222	,	-3473	,	-373	},
{	4211	,	-3460	,	-361	},
{	4200	,	-3447	,	-351	},
{	4201	,	-3444	,	-342	},
{	4192	,	-3434	,	-332	},
{	4185	,	-3427	,	-322	},
{	4180	,	-3421	,	-312	},
{	4178	,	-3417	,	-301	},
{	4170	,	-3408	,	-290	},
{	4168	,	-3406	,	-280	},
{	4151	,	-3389	,	-269	},
{	4147	,	-3383	,	-259	},
{	4135	,	-3371	,	-247	},
{	4123	,	-3360	,	-236	},
{	4125	,	-3360	,	-226	},
{	4110	,	-3347	,	-215	},
{	4097	,	-3335	,	-204	},
{	4085	,	-3325	,	-193	},
{	4082	,	-3323	,	-182	},
{	4066	,	-3310	,	-170	},
{	4046	,	-3293	,	-158	},
{	4040	,	-3289	,	-147	},
{	4027	,	-3278	,	-136	},
{	4012	,	-3264	,	-123	},
{	4000	,	-3252	,	-111	},
{	3995	,	-3249	,	-100	},
{	3972	,	-3231	,	-86	},
{	3958	,	-3220	,	-74	},
{	3955	,	-3219	,	-62	},
{	3937	,	-3204	,	-50	},
{	3930	,	-3198	,	-38	},
{	3912	,	-3184	,	-25	},
{	3901	,	-3175	,	-13	},
{	3887	,	-3164	,	-1	},
{	3874	,	-3153	,	11	},
{	3858	,	-3141	,	23	},
{	3839	,	-3127	,	34	},
{	3832	,	-3123	,	46	},
{	3805	,	-3101	,	59	},
{	3794	,	-3093	,	71	},
{	3775	,	-3078	,	83	},
{	3753	,	-3061	,	95	},
{	3729	,	-3040	,	107	},
{	3716	,	-3028	,	118	},
{	3708	,	-3020	,	131	},
{	3685	,	-2998	,	143	},
{	3681	,	-2994	,	156	},
{	3662	,	-2977	,	167	},
{	3650	,	-2965	,	178	},
{	3634	,	-2951	,	191	},
{	3616	,	-2935	,	203	},
{	3606	,	-2926	,	215	},
{	3586	,	-2907	,	226	},
{	3580	,	-2900	,	238	},
{	3571	,	-2890	,	251	},
{	3567	,	-2885	,	262	},
{	3546	,	-2865	,	273	},
{	3543	,	-2860	,	285	},
{	3532	,	-2848	,	296	},
{	3516	,	-2834	,	306	},
{	3515	,	-2833	,	318	},
{	3497	,	-2818	,	328	},
{	3486	,	-2809	,	339	},
{	3470	,	-2795	,	349	},
{	3463	,	-2789	,	359	},
{	3446	,	-2775	,	370	},
{	3435	,	-2767	,	379	},
{	3420	,	-2754	,	389	},
{	3406	,	-2743	,	399	},
{	3394	,	-2733	,	409	},
{	3384	,	-2725	,	419	},
{	3375	,	-2717	,	430	},
{	3358	,	-2704	,	440	},
{	3358	,	-2703	,	451	},
{	3339	,	-2690	,	460	},
{	3328	,	-2683	,	471	},
{	3327	,	-2682	,	483	},
{	3311	,	-2668	,	493	},
{	3304	,	-2661	,	504	},
{	3299	,	-2654	,	514	},
{	3290	,	-2646	,	524	},
{	3279	,	-2635	,	535	},
{	3269	,	-2626	,	545	},
{	3261	,	-2618	,	555	},
{	3255	,	-2613	,	565	},
{	3240	,	-2600	,	575	},
{	3235	,	-2593	,	585	},
{	3224	,	-2581	,	595	},
{	3210	,	-2568	,	605	},
{	3208	,	-2565	,	615	},
{	3197	,	-2554	,	624	},
{	3196	,	-2550	,	635	},
{	3184	,	-2537	,	644	},
{	3175	,	-2525	,	653	},
{	3169	,	-2516	,	664	},
{	3159	,	-2505	,	674	},
{	3153	,	-2498	,	684	},
{	3140	,	-2485	,	694	},
{	3136	,	-2479	,	704	},
{	3132	,	-2473	,	715	},
{	3122	,	-2461	,	723	},
{	3111	,	-2449	,	732	},
{	3104	,	-2439	,	742	},
{	3100	,	-2433	,	754	},
{	3097	,	-2428	,	765	},
{	3082	,	-2414	,	773	},
{	3074	,	-2406	,	783	},
{	3061	,	-2392	,	791	},
{	3049	,	-2380	,	802	},
{	3049	,	-2377	,	815	},
{	3036	,	-2365	,	824	},
{	3028	,	-2356	,	834	},
{	3017	,	-2345	,	844	},
{	3006	,	-2332	,	853	},
{	3002	,	-2326	,	865	},
{	2983	,	-2309	,	873	},
{	2976	,	-2301	,	883	},
{	2971	,	-2295	,	894	},
{	2969	,	-2290	,	906	},
{	2964	,	-2284	,	917	},
{	2952	,	-2271	,	925	},
{	2940	,	-2259	,	934	},
{	2934	,	-2251	,	944	},
{	2922	,	-2239	,	954	},
{	2924	,	-2238	,	967	},
{	2910	,	-2225	,	974	},
{	2903	,	-2218	,	984	},
{	2891	,	-2206	,	991	},
{	2883	,	-2197	,	999	},
{	2877	,	-2191	,	1009	},
{	2868	,	-2182	,	1017	},
{	2851	,	-2168	,	1024	},
{	2849	,	-2164	,	1034	},
{	2843	,	-2156	,	1044	},
{	2833	,	-2147	,	1053	},
{	2827	,	-2139	,	1062	},
{	2821	,	-2132	,	1073	},
{	2812	,	-2123	,	1081	},
{	2803	,	-2112	,	1088	},
{	2796	,	-2105	,	1097	},
{	2792	,	-2097	,	1108	},
{	2777	,	-2082	,	1114	},
{	2777	,	-2078	,	1126	},
{	2769	,	-2068	,	1133	},
{	2765	,	-2061	,	1142	},
{	2759	,	-2052	,	1153	},
{	2751	,	-2042	,	1162	},
{	2741	,	-2031	,	1169	},
{	2739	,	-2025	,	1180	},
{	2732	,	-2015	,	1188	},
{	2721	,	-2002	,	1195	},
{	2715	,	-1993	,	1205	},
{	2700	,	-1977	,	1211	},
{	2684	,	-1960	,	1216	},
{	2679	,	-1950	,	1226	},
{	2671	,	-1940	,	1235	},
{	2666	,	-1932	,	1246	},
{	2651	,	-1918	,	1251	},
{	2643	,	-1906	,	1259	},
{	2631	,	-1892	,	1266	},
{	2617	,	-1877	,	1272	},
{	2606	,	-1862	,	1279	},
{	2596	,	-1848	,	1287	},
{	2588	,	-1837	,	1295	},
{	2579	,	-1825	,	1303	},
{	2570	,	-1812	,	1311	},
{	2565	,	-1802	,	1320	},
{	2552	,	-1788	,	1326	},
{	2541	,	-1773	,	1332	},
{	2535	,	-1763	,	1340	},
{	2530	,	-1754	,	1349	},
{	2525	,	-1746	,	1358	},
{	2520	,	-1737	,	1367	},
{	2507	,	-1723	,	1373	},
{	2504	,	-1717	,	1383	},
{	2495	,	-1704	,	1388	},
{	2491	,	-1700	,	1392	},
{	2489	,	-1696	,	1398	},
{	2492	,	-1697	,	1405	},
{	2484	,	-1689	,	1407	},
{	2479	,	-1683	,	1409	},
{	2477	,	-1680	,	1415	},
{	2468	,	-1672	,	1416	},
{	2459	,	-1664	,	1418	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11878)

int16_t accel_residual_offset[] = { 17 , -47 , -4 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{1,-5,2},
{0,-5,1},
{0,-5,0},
{0,-5,0},
{0,-5,-1},
{0,-6,-2},
{0,-6,-4},
{0,-6,-5},
{0,-6,-6},
{1,-6,1},
{2,-6,5},
{2,-6,0},
{2,-6,0},
{2,-7,-1},
{2,-7,-2},
{2,-7,-3},
{2,-7,-3},
{3,-7,-4},
{2,-7,-5},
{2,-8,-6},
{2,-8,-6},
{2,-8,-6},
{3,-9,-6},
{3,-9,-7},
{2,-9,-7},
{2,-9,-7},
{3,-9,-8},
{3,-9,-8},
{3,-9,-8},
{3,-9,-9},
{3,-10,-9},
{4,-10,-9},
{4,-10,-9},
{3,-10,-10},
{3,-10,-10},
{3,-10,-11},
{3,-10,-10},
{3,-10,-10},
{3,-10,-10},
{4,-10,-10},
{4,-11,-11},
{3,-11,-11},
{3,-11,-11},
{4,-11,-12},
{4,-11,-12},
{4,-11,-12},
{4,-12,-12},
{4,-11,-12},
{4,-11,-12},
{4,-12,-13},
{4,-12,-13},
{4,-12,-13},
{4,-12,-14},
{4,-12,-14},
{4,-12,-14},
{4,-12,-14},
{4,-13,-14},
{5,-13,-15},
{5,-12,-15},
{4,-12,-15},
{4,-13,-15},
{4,-13,-16},
{4,-13,-15},
{4,-13,-15},
{4,-14,-15},
{4,-13,-15},
{4,-13,-16},
{4,-14,-16},
{4,-14,-16},
{4,-14,-16},
{4,-13,-17},
{4,-13,-17},
{4,-14,-17},
{4,-14,-17},
{4,-14,-17},
{4,-14,-17},
{4,-14,-18},
{4,-14,-18},
{4,-14,-18},
{4,-14,-19},
{5,-14,-19},
{5,-14,-19},
{5,-14,-19},
{5,-14,-19},
{5,-14,-19},
{5,-14,-19},
{5,-14,-19},
{5,-14,-19},
{5,-13,-19},
{5,-13,-20},
{5,-13,-20},
{5,-13,-20},
{5,-13,-21},
{5,-13,-21},
{5,-12,-21},
{5,-12,-21},
{5,-12,-21},
{5,-12,-22},
{5,-12,-22},
{5,-11,-22},
{5,-11,-22},
{5,-11,-23},
{4,-11,-23},
{4,-11,-23},
{4,-10,-23},
{4,-10,-23},
{4,-10,-24},
{4,-10,-24},
{4,-10,-24},
{4,-10,-24},
{4,-10,-25},
{3,-10,-25},
{3,-10,-26},
{3,-10,-26},
{3,-10,-26},
{3,-11,-27},
{3,-11,-27},
{3,-11,-27},
{3,-11,-28},
{2,-11,-28},
{2,-11,-28},
{2,-11,-28},
{2,-11,-29},
{2,-11,-29},
{2,-11,-29},
{2,-11,-29},
{2,-11,-29},
{1,-11,-29},
{1,-12,-29},
{2,-11,-29},
{2,-11,-29},
{1,-11,-29},
{1,-11,-28},
{1,-11,-28},
{1,-11,-28},
{1,-11,-28},
{1,-12,-28},
{1,-11,-28},
{1,-11,-28},
{1,-11,-28},
{1,-11,-27},
{1,-11,-27},
{1,-12,-27},
{1,-12,-27},
{1,-12,-27},
{0,-11,-26},
{0,-11,-26},
{0,-11,-26},
{0,-11,-26},
{0,-11,-26},
{0,-11,-25},
{0,-12,-25},
{0,-12,-25},
{0,-12,-25},
{0,-12,-25},
{0,-12,-25},
{0,-12,-24},
{0,-12,-24},
{0,-12,-24},
{0,-12,-24},
{0,-12,-24},
{0,-12,-24},
{0,-12,-24},
{0,-12,-24},
{0,-12,-23},
{0,-12,-23},
{0,-12,-23},
{-1,-12,-23},
{-1,-12,-23},
{-1,-12,-23},
{-1,-12,-23},
{-1,-12,-23},
{-1,-12,-23},
{-1,-13,-23},
{-1,-13,-22},
{-1,-13,-22},
{-1,-13,-22},
{-1,-13,-22},
{-1,-13,-22},
{-1,-13,-22},
{-1,-13,-22},
{-2,-13,-22},
{-2,-13,-22},
{-2,-13,-22},
{-2,-13,-22},
{-2,-14,-22},
{-2,-14,-22},
{-2,-14,-22},
{-2,-14,-22},
{-2,-14,-22},
{-2,-14,-22},
{-3,-14,-22},
{-3,-14,-22},
{-3,-14,-22},
{-3,-14,-22},
{-3,-14,-22},
{-3,-14,-22},
{-3,-14,-22},
{-3,-15,-22},
{-3,-14,-23},
{-3,-14,-23},
{-3,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-23},
{-4,-15,-24},
{-4,-15,-24},
{-4,-15,-24},
{-4,-15,-24},
{-5,-15,-24},
{-5,-15,-24},
{-5,-16,-24},
{-5,-16,-24},
{-5,-16,-24},
{-5,-16,-24},
{-5,-16,-24},
{-5,-16,-24},
{-5,-16,-24},
{-5,-16,-25},
{-6,-16,-25},
{-6,-16,-25},
{-6,-16,-25},
{-6,-16,-25},
{-6,-16,-25},
{-6,-16,-25},
{-6,-16,-25},
{-6,-16,-25},
{-7,-16,-25},
{-7,-16,-25},
{-7,-16,-25},
{-7,-16,-25},
{-7,-16,-25},
{-7,-16,-25},
{-7,-15,-25},
};


#endif	/* TABLE_LUGE7_SN192_H */

