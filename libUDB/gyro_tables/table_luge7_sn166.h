

#ifndef TABLE_LUGE7_SN166_H
#define	TABLE_LUGE7_SN166_H

// used in LUGE7_SN166 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14832 )

int16_t residual_offset[] = { -844 - 4*49  ,  540 -4*5, -81 -4*26 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	431	,	-3828	,	-514	},
{	435	,	-3839	,	-511	},
{	440	,	-3845	,	-507	},
{	447	,	-3854	,	-504	},
{	451	,	-3850	,	-500	},
{	457	,	-3853	,	-497	},
{	463	,	-3853	,	-494	},
{	467	,	-3851	,	-491	},
{	472	,	-3854	,	-488	},
{	480	,	-3871	,	-483	},
{	490	,	-3863	,	-475	},
{	498	,	-3858	,	-467	},
{	506	,	-3845	,	-459	},
{	515	,	-3845	,	-452	},
{	524	,	-3849	,	-445	},
{	531	,	-3840	,	-435	},
{	540	,	-3841	,	-427	},
{	549	,	-3841	,	-421	},
{	555	,	-3828	,	-414	},
{	562	,	-3825	,	-409	},
{	566	,	-3809	,	-401	},
{	573	,	-3805	,	-396	},
{	579	,	-3802	,	-390	},
{	583	,	-3794	,	-384	},
{	590	,	-3796	,	-377	},
{	594	,	-3785	,	-371	},
{	601	,	-3779	,	-366	},
{	605	,	-3773	,	-361	},
{	611	,	-3778	,	-358	},
{	615	,	-3773	,	-354	},
{	621	,	-3776	,	-351	},
{	626	,	-3767	,	-346	},
{	633	,	-3765	,	-343	},
{	637	,	-3757	,	-339	},
{	643	,	-3750	,	-334	},
{	649	,	-3749	,	-329	},
{	657	,	-3750	,	-325	},
{	665	,	-3753	,	-322	},
{	670	,	-3752	,	-317	},
{	675	,	-3750	,	-314	},
{	680	,	-3748	,	-310	},
{	684	,	-3736	,	-305	},
{	690	,	-3733	,	-301	},
{	695	,	-3731	,	-297	},
{	700	,	-3726	,	-292	},
{	706	,	-3723	,	-288	},
{	712	,	-3720	,	-283	},
{	716	,	-3711	,	-279	},
{	721	,	-3706	,	-274	},
{	726	,	-3702	,	-271	},
{	731	,	-3695	,	-267	},
{	736	,	-3695	,	-266	},
{	740	,	-3689	,	-263	},
{	744	,	-3678	,	-259	},
{	750	,	-3673	,	-255	},
{	756	,	-3672	,	-253	},
{	761	,	-3663	,	-248	},
{	768	,	-3663	,	-245	},
{	776	,	-3668	,	-242	},
{	779	,	-3663	,	-240	},
{	784	,	-3659	,	-236	},
{	794	,	-3668	,	-234	},
{	797	,	-3659	,	-231	},
{	803	,	-3659	,	-229	},
{	808	,	-3660	,	-227	},
{	814	,	-3656	,	-223	},
{	820	,	-3653	,	-219	},
{	825	,	-3656	,	-216	},
{	831	,	-3656	,	-213	},
{	837	,	-3659	,	-209	},
{	839	,	-3652	,	-206	},
{	844	,	-3648	,	-203	},
{	850	,	-3649	,	-199	},
{	856	,	-3650	,	-195	},
{	860	,	-3645	,	-192	},
{	866	,	-3643	,	-189	},
{	874	,	-3645	,	-184	},
{	880	,	-3643	,	-179	},
{	882	,	-3633	,	-173	},
{	886	,	-3625	,	-168	},
{	893	,	-3634	,	-165	},
{	897	,	-3625	,	-159	},
{	900	,	-3622	,	-156	},
{	904	,	-3623	,	-152	},
{	908	,	-3624	,	-150	},
{	911	,	-3617	,	-146	},
{	919	,	-3627	,	-143	},
{	924	,	-3625	,	-140	},
{	928	,	-3628	,	-137	},
{	929	,	-3619	,	-135	},
{	931	,	-3617	,	-133	},
{	935	,	-3618	,	-130	},
{	935	,	-3606	,	-127	},
{	938	,	-3606	,	-126	},
{	941	,	-3607	,	-125	},
{	945	,	-3607	,	-123	},
{	949	,	-3605	,	-122	},
{	951	,	-3594	,	-119	},
{	958	,	-3599	,	-119	},
{	961	,	-3604	,	-117	},
{	962	,	-3598	,	-116	},
{	966	,	-3595	,	-113	},
{	969	,	-3590	,	-110	},
{	969	,	-3576	,	-107	},
{	974	,	-3581	,	-105	},
{	976	,	-3577	,	-102	},
{	980	,	-3576	,	-99	},
{	985	,	-3581	,	-98	},
{	985	,	-3573	,	-95	},
{	991	,	-3581	,	-93	},
{	992	,	-3577	,	-91	},
{	993	,	-3575	,	-89	},
{	995	,	-3575	,	-87	},
{	994	,	-3573	,	-85	},
{	994	,	-3575	,	-83	},
{	992	,	-3574	,	-82	},
{	995	,	-3572	,	-79	},
{	996	,	-3571	,	-77	},
{	994	,	-3566	,	-78	},
{	992	,	-3566	,	-77	},
{	991	,	-3562	,	-75	},
{	987	,	-3553	,	-72	},
{	984	,	-3549	,	-71	},
{	980	,	-3546	,	-70	},
{	976	,	-3538	,	-68	},
{	974	,	-3538	,	-67	},
{	969	,	-3530	,	-66	},
{	962	,	-3518	,	-64	},
{	958	,	-3517	,	-63	},
{	950	,	-3503	,	-62	},
{	947	,	-3508	,	-61	},
{	939	,	-3494	,	-60	},
{	932	,	-3488	,	-58	},
{	924	,	-3483	,	-57	},
{	917	,	-3475	,	-55	},
{	908	,	-3465	,	-52	},
{	901	,	-3458	,	-49	},
{	893	,	-3458	,	-47	},
{	885	,	-3454	,	-46	},
{	875	,	-3445	,	-44	},
{	864	,	-3437	,	-44	},
{	850	,	-3418	,	-43	},
{	841	,	-3415	,	-41	},
{	828	,	-3401	,	-40	},
{	818	,	-3393	,	-38	},
{	805	,	-3381	,	-35	},
{	794	,	-3378	,	-33	},
{	780	,	-3364	,	-31	},
{	769	,	-3358	,	-30	},
{	756	,	-3342	,	-29	},
{	742	,	-3328	,	-28	},
{	731	,	-3322	,	-26	},
{	718	,	-3314	,	-25	},
{	704	,	-3302	,	-23	},
{	688	,	-3287	,	-24	},
{	672	,	-3274	,	-23	},
{	659	,	-3268	,	-22	},
{	644	,	-3254	,	-20	},
{	633	,	-3246	,	-17	},
{	618	,	-3228	,	-16	},
{	604	,	-3215	,	-13	},
{	592	,	-3211	,	-12	},
{	577	,	-3194	,	-12	},
{	563	,	-3184	,	-12	},
{	550	,	-3178	,	-11	},
{	537	,	-3160	,	-8	},
{	524	,	-3150	,	-7	},
{	511	,	-3141	,	-5	},
{	496	,	-3124	,	-3	},
{	484	,	-3117	,	-1	},
{	470	,	-3103	,	0	},
{	457	,	-3098	,	2	},
{	446	,	-3087	,	5	},
{	432	,	-3067	,	7	},
{	422	,	-3062	,	7	},
{	410	,	-3048	,	9	},
{	399	,	-3045	,	12	},
{	388	,	-3035	,	13	},
{	376	,	-3020	,	15	},
{	365	,	-3010	,	17	},
{	354	,	-2994	,	18	},
{	344	,	-2981	,	21	},
{	334	,	-2976	,	23	},
{	323	,	-2961	,	25	},
{	313	,	-2950	,	26	},
{	303	,	-2941	,	27	},
{	294	,	-2936	,	30	},
{	285	,	-2933	,	31	},
{	276	,	-2919	,	32	},
{	266	,	-2905	,	32	},
{	256	,	-2904	,	33	},
{	247	,	-2892	,	35	},
{	237	,	-2888	,	38	},
{	226	,	-2878	,	38	},
{	216	,	-2871	,	40	},
{	206	,	-2861	,	40	},
{	197	,	-2862	,	40	},
{	186	,	-2849	,	41	},
{	175	,	-2836	,	43	},
{	165	,	-2833	,	43	},
{	156	,	-2826	,	43	},
{	145	,	-2818	,	43	},
{	135	,	-2809	,	44	},
{	125	,	-2793	,	44	},
{	116	,	-2786	,	45	},
{	107	,	-2776	,	46	},
{	99	,	-2767	,	47	},
{	91	,	-2761	,	48	},
{	82	,	-2749	,	49	},
{	73	,	-2735	,	49	},
{	65	,	-2729	,	50	},
{	56	,	-2715	,	50	},
{	49	,	-2712	,	52	},
{	40	,	-2695	,	52	},
{	33	,	-2688	,	52	},
{	24	,	-2679	,	53	},
{	16	,	-2664	,	54	},
{	8	,	-2651	,	56	},
{	0	,	-2641	,	57	},
{	-8	,	-2628	,	58	},
{	-16	,	-2618	,	60	},
{	-24	,	-2602	,	61	},
{	-33	,	-2589	,	62	},
{	-41	,	-2584	,	65	},
{	-48	,	-2565	,	68	},
{	-57	,	-2555	,	69	},
{	-64	,	-2547	,	72	},
{	-71	,	-2534	,	74	},
{	-79	,	-2527	,	77	},
{	-86	,	-2506	,	79	},
{	-94	,	-2500	,	82	},
{	-102	,	-2487	,	85	},
{	-109	,	-2472	,	88	},
{	-117	,	-2462	,	91	},
{	-125	,	-2454	,	94	},
{	-133	,	-2437	,	96	},
{	-141	,	-2429	,	99	},
{	-150	,	-2418	,	102	},
{	-159	,	-2408	,	105	},
{	-167	,	-2396	,	106	},
{	-175	,	-2377	,	109	},
{	-185	,	-2366	,	111	},
{	-192	,	-2347	,	113	},
{	-200	,	-2332	,	115	},
{	-209	,	-2313	,	117	},
{	-215	,	-2299	,	118	},
{	-224	,	-2292	,	121	},
{	-233	,	-2277	,	122	},
{	-241	,	-2266	,	125	},
{	-251	,	-2259	,	128	},
{	-258	,	-2246	,	130	},
{	-267	,	-2232	,	132	},
{	-274	,	-2217	,	135	},
{	-282	,	-2200	,	137	},
{	-291	,	-2189	,	139	},
{	-298	,	-2172	,	141	},
{	-306	,	-2160	,	145	},
{	-314	,	-2151	,	148	},
{	-322	,	-2139	,	149	},
{	-332	,	-2129	,	150	},
{	-341	,	-2119	,	151	},
{	-350	,	-2108	,	153	},
{	-360	,	-2099	,	155	},
{	-369	,	-2088	,	155	},
{	-378	,	-2074	,	157	},
{	-387	,	-2063	,	159	},
{	-396	,	-2049	,	160	},
{	-404	,	-2038	,	160	},
{	-414	,	-2030	,	161	},
{	-422	,	-2019	,	161	},
{	-431	,	-2012	,	162	},
{	-438	,	-1999	,	162	},
{	-448	,	-1991	,	163	},
{	-457	,	-1981	,	164	},
{	-466	,	-1971	,	165	},
{	-474	,	-1960	,	166	},
{	-482	,	-1952	,	167	},
{	-489	,	-1938	,	168	},
{	-497	,	-1929	,	169	},
{	-504	,	-1914	,	170	},
{	-512	,	-1903	,	171	},
{	-520	,	-1894	,	173	},
{	-528	,	-1879	,	173	},
{	-537	,	-1869	,	174	},
{	-546	,	-1863	,	175	},
{	-553	,	-1847	,	176	},
{	-563	,	-1841	,	178	},
{	-572	,	-1831	,	180	},
{	-581	,	-1820	,	182	},
{	-590	,	-1808	,	183	},
{	-599	,	-1796	,	184	},
{	-607	,	-1784	,	185	},
{	-617	,	-1777	,	186	},
{	-628	,	-1767	,	187	},
{	-638	,	-1761	,	188	},
{	-648	,	-1754	,	190	},
{	-657	,	-1744	,	193	},
{	-664	,	-1731	,	195	},
{	-673	,	-1722	,	197	},
{	-681	,	-1712	,	199	},
{	-690	,	-1703	,	200	},
{	-699	,	-1694	,	202	},
{	-704	,	-1691	,	204	},
{	-708	,	-1686	,	204	},
{	-713	,	-1681	,	205	},
{	-717	,	-1674	,	206	},
{	-722	,	-1671	,	206	},
{	-726	,	-1668	,	207	},
{	-730	,	-1665	,	208	},
{	-733	,	-1659	,	209	}
};



#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -15796)

int16_t accel_residual_offset[] = { 3 , 50 , -17 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-4,5,-2},
{-4,4,-2},
{-4,4,-3},
{-5,3,-5},
{-5,2,-6},
{-5,2,-7},
{-6,2,-8},
{-6,2,-9},
{-6,1,-10},
{-5,1,-10},
{-6,0,-11},
{-6,0,-12},
{-6,0,-12},
{-6,0,-12},
{-6,0,-13},
{-6,0,-13},
{-6,0,-14},
{-6,0,-14},
{-6,0,-14},
{-6,0,-15},
{-6,0,-15},
{-6,0,-15},
{-7,-1,-15},
{-6,-1,-15},
{-6,-1,-16},
{-6,-1,-16},
{-5,-1,-10},
{-4,-1,-5},
{-4,-1,-7},
{-4,-1,-9},
{-3,-1,-10},
{-3,-1,-10},
{-3,-1,-10},
{-3,-1,-10},
{-3,-1,-10},
{-2,-2,-10},
{-2,-2,-10},
{-2,-2,-10},
{-2,-2,-10},
{-2,-2,-10},
{-2,-2,-10},
{-1,-2,-10},
{-1,-2,-10},
{-2,-2,-10},
{-2,-2,-10},
{-1,-2,-10},
{-1,-2,-10},
{-1,-2,-10},
{-1,-2,-10},
{-1,-2,-10},
{-1,-3,-10},
{-1,-3,-11},
{-1,-3,-11},
{-1,-3,-11},
{-1,-3,-11},
{-1,-3,-11},
{0,-3,-11},
{0,-3,-11},
{0,-3,-11},
{0,-3,-11},
{0,-3,-11},
{0,-4,-11},
{0,-4,-11},
{0,-4,-11},
{0,-4,-11},
{0,-4,-11},
{0,-4,-11},
{0,-5,-12},
{0,-5,-12},
{0,-5,-12},
{0,-6,-12},
{0,-6,-12},
{0,-6,-13},
{0,-6,-13},
{0,-6,-13},
{0,-6,-13},
{0,-7,-13},
{0,-7,-13},
{0,-7,-13},
{0,-7,-13},
{0,-7,-14},
{0,-7,-14},
{0,-8,-14},
{0,-8,-14},
{0,-8,-14},
{0,-9,-14},
{0,-9,-14},
{0,-9,-14},
{0,-9,-14},
{0,-9,-15},
{0,-10,-15},
{0,-10,-15},
{0,-10,-15},
{0,-10,-15},
{0,-10,-15},
{0,-11,-15},
{0,-11,-15},
{0,-11,-15},
{0,-11,-15},
{0,-12,-15},
{0,-12,-15},
{0,-12,-16},
{0,-12,-16},
{0,-12,-16},
{0,-12,-16},
{0,-13,-16},
{0,-13,-16},
{0,-13,-17},
{0,-13,-17},
{0,-13,-17},
{0,-13,-17},
{0,-13,-17},
{0,-13,-17},
{0,-13,-17},
{0,-13,-17},
{0,-13,-17},
{0,-13,-18},
{0,-13,-18},
{0,-13,-18},
{0,-13,-18},
{0,-14,-18},
{0,-13,-18},
{0,-13,-18},
{0,-14,-18},
{0,-13,-18},
{0,-13,-18},
{0,-14,-18},
{0,-14,-19},
{0,-14,-19},
{1,-14,-19},
{1,-14,-19},
{1,-14,-19},
{1,-14,-19},
{1,-14,-19},
{1,-14,-19},
{1,-14,-19},
{1,-14,-20},
{1,-14,-20},
{1,-14,-20},
{1,-14,-20},
{1,-15,-20},
{1,-14,-20},
{1,-14,-20},
{1,-15,-20},
{1,-15,-20},
{1,-15,-20},
{2,-15,-20},
{2,-15,-20},
{2,-15,-19},
{2,-15,-19},
{2,-15,-20},
{2,-16,-19},
{2,-16,-19},
{2,-16,-19},
{2,-16,-19},
{2,-16,-19},
{2,-17,-19},
{2,-17,-19},
{2,-17,-19},
{3,-17,-19},
{2,-17,-19},
{2,-17,-19},
{2,-18,-19},
{2,-18,-19},
{3,-18,-19},
{3,-19,-19},
{3,-19,-19},
{3,-19,-19},
{3,-19,-19},
{3,-20,-20},
{3,-20,-20},
{3,-20,-20},
{3,-20,-20},
{3,-21,-20},
{3,-21,-20},
{3,-21,-20},
{3,-21,-20},
{3,-22,-20},
{4,-22,-21},
{4,-22,-21},
{4,-22,-21},
{4,-23,-21},
{4,-23,-21},
{4,-23,-21},
{4,-23,-21},
{4,-23,-21},
{4,-24,-20},
{4,-24,-20},
{4,-24,-20},
{4,-24,-20},
{4,-25,-20},
{4,-25,-20},
{5,-25,-20},
{5,-25,-20},
{5,-25,-20},
{5,-26,-20},
{5,-26,-20},
{5,-26,-20},
{5,-26,-19},
{5,-26,-19},
{5,-27,-19},
{5,-27,-19},
{5,-27,-19},
{5,-27,-19},
{5,-27,-18},
{5,-27,-18},
{5,-28,-18},
{5,-28,-18},
{5,-28,-18},
{5,-28,-18},
{6,-29,-18},
{6,-29,-18},
{6,-29,-17},
{6,-29,-17},
{6,-29,-17},
{6,-29,-17},
{6,-29,-17},
{6,-30,-16},
{6,-30,-16},
{6,-30,-16},
{6,-30,-16},
{7,-30,-16},
{7,-30,-15},
{7,-31,-15},
{7,-31,-15},
{7,-31,-15},
{7,-31,-15},
{7,-31,-15},
{7,-31,-15},
{8,-31,-15},
{8,-31,-14},
{8,-31,-14},
{8,-31,-14},
{8,-31,-14},
{8,-31,-14},
{8,-31,-13},
{9,-31,-13},
{9,-31,-13},
{9,-31,-13},
{9,-31,-13},
{9,-31,-12},
{9,-31,-12},
{10,-31,-12},
{10,-31,-12},
{10,-31,-12},
{10,-31,-12},
{10,-31,-11},
{10,-31,-11},
{10,-31,-11},
{10,-31,-11},
{11,-31,-11},
{11,-30,-11},
{11,-30,-11},
{11,-30,-10},
{11,-30,-10},
{11,-30,-10},
{11,-30,-10},
{11,-30,-10},
{12,-30,-9},
{12,-30,-9},
{12,-29,-9},
{12,-29,-9},
{12,-30,-9},
{12,-30,-8},
{12,-30,-8},
{12,-30,-8},
{12,-30,-8},
{12,-30,-8},
{13,-30,-8},
{13,-30,-7},
{13,-30,-7},
{13,-30,-7},
{13,-31,-7},
{13,-31,-6},
{14,-31,-6},
{14,-31,-6},
{14,-31,-5},
{14,-31,-5},
{15,-31,-5},
{15,-31,-5},
{15,-32,-5},
{15,-32,-4},
{15,-32,-4},
{15,-33,-3},
{15,-33,-3},
{16,-33,-2},
{16,-33,-2},
{16,-33,-2},
{16,-34,-1},
{16,-34,-1},
{16,-34,-1},
{16,-35,0},
{17,-35,0},
{17,-35,0},
{17,-35,0},
{17,-36,0},
{17,-36,0},
{17,-36,1},
{17,-37,1},
{17,-37,1},
{17,-37,2},
{17,-38,3},
{16,-38,3},
{16,-38,4},
{16,-39,5},
};


#endif	/* TABLE_LUGE7_SN166_H */

