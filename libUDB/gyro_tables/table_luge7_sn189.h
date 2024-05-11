

#ifndef TABLE_LUGE7_SN189_H
#define	TABLE_LUGE7_SN189_H

// used in LUGE7_SN189 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -15019 )

int16_t residual_offset[] = { -535 , 438 , -671 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-207	,	-3779	,	1129	},
{	-203	,	-3763	,	1127	},
{	-198	,	-3780	,	1135	},
{	-194	,	-3781	,	1137	},
{	-189	,	-3787	,	1140	},
{	-185	,	-3786	,	1141	},
{	-180	,	-3793	,	1145	},
{	-176	,	-3788	,	1145	},
{	-172	,	-3789	,	1147	},
{	-166	,	-3804	,	1155	},
{	-157	,	-3805	,	1158	},
{	-149	,	-3818	,	1164	},
{	-141	,	-3814	,	1165	},
{	-131	,	-3804	,	1167	},
{	-122	,	-3805	,	1168	},
{	-112	,	-3805	,	1169	},
{	-103	,	-3811	,	1173	},
{	-92	,	-3808	,	1175	},
{	-83	,	-3821	,	1179	},
{	-74	,	-3810	,	1177	},
{	-66	,	-3816	,	1178	},
{	-58	,	-3804	,	1176	},
{	-50	,	-3807	,	1178	},
{	-42	,	-3797	,	1175	},
{	-34	,	-3799	,	1176	},
{	-25	,	-3796	,	1175	},
{	-18	,	-3793	,	1176	},
{	-9	,	-3793	,	1176	},
{	0	,	-3783	,	1175	},
{	8	,	-3774	,	1174	},
{	16	,	-3776	,	1175	},
{	25	,	-3779	,	1177	},
{	34	,	-3776	,	1177	},
{	41	,	-3764	,	1176	},
{	51	,	-3766	,	1178	},
{	59	,	-3764	,	1180	},
{	68	,	-3759	,	1180	},
{	77	,	-3747	,	1178	},
{	84	,	-3753	,	1180	},
{	93	,	-3747	,	1179	},
{	102	,	-3749	,	1181	},
{	112	,	-3752	,	1182	},
{	120	,	-3747	,	1182	},
{	129	,	-3741	,	1181	},
{	138	,	-3739	,	1183	},
{	147	,	-3734	,	1183	},
{	155	,	-3733	,	1184	},
{	164	,	-3732	,	1183	},
{	172	,	-3727	,	1183	},
{	181	,	-3725	,	1184	},
{	190	,	-3732	,	1187	},
{	196	,	-3721	,	1185	},
{	203	,	-3713	,	1181	},
{	211	,	-3714	,	1183	},
{	220	,	-3714	,	1184	},
{	228	,	-3702	,	1181	},
{	236	,	-3709	,	1185	},
{	243	,	-3701	,	1184	},
{	250	,	-3694	,	1183	},
{	259	,	-3697	,	1184	},
{	268	,	-3696	,	1184	},
{	275	,	-3698	,	1184	},
{	283	,	-3696	,	1184	},
{	291	,	-3694	,	1183	},
{	298	,	-3691	,	1184	},
{	305	,	-3694	,	1185	},
{	312	,	-3688	,	1183	},
{	318	,	-3681	,	1179	},
{	326	,	-3682	,	1178	},
{	336	,	-3688	,	1181	},
{	344	,	-3695	,	1181	},
{	351	,	-3695	,	1180	},
{	358	,	-3700	,	1182	},
{	366	,	-3690	,	1179	},
{	374	,	-3694	,	1180	},
{	383	,	-3699	,	1183	},
{	390	,	-3694	,	1183	},
{	397	,	-3692	,	1182	},
{	404	,	-3690	,	1181	},
{	412	,	-3692	,	1182	},
{	420	,	-3695	,	1183	},
{	428	,	-3694	,	1182	},
{	435	,	-3685	,	1179	},
{	442	,	-3684	,	1177	},
{	449	,	-3682	,	1177	},
{	456	,	-3684	,	1178	},
{	461	,	-3678	,	1175	},
{	469	,	-3669	,	1173	},
{	477	,	-3671	,	1174	},
{	483	,	-3668	,	1172	},
{	491	,	-3675	,	1173	},
{	497	,	-3678	,	1173	},
{	505	,	-3678	,	1172	},
{	511	,	-3679	,	1171	},
{	518	,	-3679	,	1171	},
{	524	,	-3678	,	1170	},
{	529	,	-3673	,	1167	},
{	535	,	-3676	,	1166	},
{	541	,	-3678	,	1166	},
{	547	,	-3677	,	1165	},
{	553	,	-3678	,	1163	},
{	559	,	-3680	,	1163	},
{	564	,	-3676	,	1160	},
{	570	,	-3679	,	1160	},
{	573	,	-3674	,	1158	},
{	577	,	-3669	,	1154	},
{	582	,	-3673	,	1155	},
{	586	,	-3673	,	1154	},
{	590	,	-3666	,	1150	},
{	593	,	-3661	,	1147	},
{	597	,	-3657	,	1145	},
{	601	,	-3658	,	1143	},
{	604	,	-3649	,	1139	},
{	610	,	-3656	,	1140	},
{	613	,	-3649	,	1137	},
{	617	,	-3650	,	1136	},
{	620	,	-3651	,	1133	},
{	623	,	-3647	,	1130	},
{	627	,	-3644	,	1126	},
{	630	,	-3644	,	1125	},
{	633	,	-3642	,	1122	},
{	638	,	-3654	,	1122	},
{	640	,	-3647	,	1119	},
{	643	,	-3643	,	1116	},
{	645	,	-3638	,	1112	},
{	647	,	-3633	,	1108	},
{	650	,	-3630	,	1105	},
{	652	,	-3633	,	1103	},
{	654	,	-3625	,	1099	},
{	657	,	-3631	,	1097	},
{	658	,	-3623	,	1092	},
{	659	,	-3619	,	1088	},
{	658	,	-3611	,	1082	},
{	661	,	-3618	,	1082	},
{	660	,	-3612	,	1078	},
{	661	,	-3616	,	1076	},
{	661	,	-3613	,	1073	},
{	660	,	-3603	,	1068	},
{	659	,	-3595	,	1063	},
{	659	,	-3596	,	1060	},
{	660	,	-3598	,	1058	},
{	658	,	-3592	,	1052	},
{	657	,	-3591	,	1049	},
{	655	,	-3590	,	1046	},
{	653	,	-3586	,	1043	},
{	652	,	-3590	,	1041	},
{	648	,	-3581	,	1036	},
{	646	,	-3585	,	1034	},
{	643	,	-3581	,	1029	},
{	639	,	-3578	,	1025	},
{	633	,	-3561	,	1018	},
{	630	,	-3564	,	1016	},
{	627	,	-3557	,	1010	},
{	622	,	-3549	,	1004	},
{	618	,	-3545	,	1000	},
{	611	,	-3531	,	994	},
{	606	,	-3528	,	990	},
{	600	,	-3519	,	984	},
{	594	,	-3511	,	979	},
{	589	,	-3504	,	974	},
{	585	,	-3501	,	970	},
{	580	,	-3493	,	965	},
{	575	,	-3491	,	961	},
{	569	,	-3482	,	955	},
{	561	,	-3470	,	948	},
{	557	,	-3467	,	945	},
{	551	,	-3463	,	941	},
{	547	,	-3463	,	938	},
{	540	,	-3449	,	932	},
{	535	,	-3445	,	928	},
{	531	,	-3442	,	924	},
{	527	,	-3440	,	921	},
{	522	,	-3436	,	917	},
{	518	,	-3433	,	914	},
{	514	,	-3429	,	910	},
{	511	,	-3422	,	905	},
{	507	,	-3425	,	903	},
{	502	,	-3413	,	897	},
{	498	,	-3402	,	890	},
{	494	,	-3394	,	885	},
{	492	,	-3397	,	882	},
{	489	,	-3391	,	877	},
{	487	,	-3392	,	873	},
{	485	,	-3383	,	867	},
{	483	,	-3378	,	862	},
{	483	,	-3381	,	859	},
{	480	,	-3373	,	853	},
{	479	,	-3370	,	850	},
{	476	,	-3357	,	843	},
{	475	,	-3358	,	839	},
{	473	,	-3348	,	832	},
{	471	,	-3342	,	827	},
{	469	,	-3341	,	824	},
{	465	,	-3330	,	817	},
{	462	,	-3322	,	811	},
{	460	,	-3320	,	807	},
{	456	,	-3316	,	802	},
{	452	,	-3307	,	796	},
{	449	,	-3300	,	790	},
{	445	,	-3290	,	783	},
{	443	,	-3294	,	781	},
{	439	,	-3286	,	775	},
{	434	,	-3277	,	770	},
{	431	,	-3270	,	764	},
{	427	,	-3270	,	760	},
{	424	,	-3266	,	755	},
{	420	,	-3265	,	751	},
{	417	,	-3260	,	746	},
{	412	,	-3252	,	739	},
{	409	,	-3250	,	734	},
{	405	,	-3249	,	730	},
{	402	,	-3246	,	725	},
{	398	,	-3246	,	720	},
{	394	,	-3238	,	714	},
{	391	,	-3235	,	709	},
{	388	,	-3234	,	706	},
{	385	,	-3229	,	701	},
{	381	,	-3222	,	694	},
{	377	,	-3218	,	689	},
{	374	,	-3220	,	685	},
{	371	,	-3228	,	683	},
{	366	,	-3218	,	676	},
{	363	,	-3220	,	672	},
{	359	,	-3214	,	667	},
{	357	,	-3216	,	663	},
{	355	,	-3224	,	661	},
{	351	,	-3217	,	655	},
{	348	,	-3215	,	650	},
{	344	,	-3214	,	645	},
{	342	,	-3220	,	642	},
{	339	,	-3218	,	638	},
{	336	,	-3223	,	634	},
{	333	,	-3215	,	629	},
{	330	,	-3219	,	626	},
{	326	,	-3214	,	622	},
{	325	,	-3221	,	619	},
{	321	,	-3212	,	614	},
{	317	,	-3199	,	608	},
{	315	,	-3203	,	605	},
{	313	,	-3201	,	601	},
{	309	,	-3197	,	596	},
{	307	,	-3193	,	592	},
{	304	,	-3190	,	588	},
{	301	,	-3194	,	585	},
{	297	,	-3193	,	581	},
{	293	,	-3192	,	577	},
{	290	,	-3185	,	573	},
{	286	,	-3183	,	569	},
{	282	,	-3179	,	565	},
{	279	,	-3183	,	562	},
{	277	,	-3180	,	557	},
{	274	,	-3178	,	553	},
{	272	,	-3174	,	549	},
{	270	,	-3175	,	546	},
{	269	,	-3177	,	543	},
{	266	,	-3172	,	538	},
{	263	,	-3174	,	536	},
{	261	,	-3174	,	533	},
{	258	,	-3174	,	531	},
{	254	,	-3169	,	526	},
{	250	,	-3166	,	522	},
{	247	,	-3161	,	518	},
{	245	,	-3159	,	515	},
{	241	,	-3151	,	512	},
{	238	,	-3146	,	508	},
{	236	,	-3144	,	504	},
{	232	,	-3143	,	502	},
{	228	,	-3134	,	498	},
{	224	,	-3135	,	495	},
{	219	,	-3127	,	491	},
{	214	,	-3122	,	488	},
{	210	,	-3119	,	484	},
{	204	,	-3113	,	481	},
{	199	,	-3104	,	476	},
{	195	,	-3102	,	472	},
{	190	,	-3097	,	467	},
{	186	,	-3091	,	463	},
{	182	,	-3084	,	458	},
{	177	,	-3082	,	454	},
{	173	,	-3086	,	451	},
{	170	,	-3086	,	447	},
{	168	,	-3092	,	444	},
{	164	,	-3086	,	440	},
{	161	,	-3088	,	436	},
{	157	,	-3090	,	433	},
{	152	,	-3079	,	428	},
{	148	,	-3083	,	425	},
{	144	,	-3092	,	422	},
{	139	,	-3088	,	419	},
{	136	,	-3090	,	416	},
{	132	,	-3087	,	412	},
{	128	,	-3088	,	408	},
{	122	,	-3091	,	405	},
{	117	,	-3086	,	401	},
{	112	,	-3092	,	399	},
{	108	,	-3101	,	397	},
{	102	,	-3094	,	392	},
{	98	,	-3090	,	389	},
{	93	,	-3090	,	386	},
{	87	,	-3093	,	383	},
{	83	,	-3090	,	380	},
{	79	,	-3089	,	377	},
{	75	,	-3096	,	375	},
{	72	,	-3099	,	372	},
{	68	,	-3087	,	368	},
{	65	,	-3098	,	367	},
{	61	,	-3103	,	364	},
{	57	,	-3104	,	361	},
{	53	,	-3098	,	358	},
{	50	,	-3095	,	355	},
{	47	,	-3101	,	353	},
{	43	,	-3101	,	350	},
{	39	,	-3094	,	346	},
{	36	,	-3095	,	344	},
{	32	,	-3098	,	342	},
{	28	,	-3093	,	339	},
{	24	,	-3084	,	336	},
{	19	,	-3084	,	333	},
{	14	,	-3084	,	331	},
{	8	,	-3078	,	329	},
{	3	,	-3074	,	326	},
{	-2	,	-3074	,	324	},
{	-8	,	-3063	,	322	},
{	-13	,	-3055	,	318	},
{	-20	,	-3061	,	316	},
{	-23	,	-3065	,	316	},
{	-25	,	-3063	,	315	},
{	-28	,	-3062	,	314	},
{	-31	,	-3057	,	314	},
{	-33	,	-3054	,	313	},
{	-35	,	-3052	,	312	},
{	-38	,	-3052	,	312	},
{	-42	,	-3051	,	311	}
};


#define ACCEL_TABLE

#define ACCEL_TABLE_ORIGIN ( -12332)

int16_t accel_residual_offset[] = { -25 , -3 , 7 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{4,4,1},
{4,4,0},
{4,4,0},
{4,3,-1},
{4,2,-3},
{4,2,-4},
{4,1,-5},
{4,1,-1},
{4,1,3},
{5,0,2},
{6,0,0},
{6,0,-1},
{6,0,-1},
{6,0,-2},
{6,-1,-3},
{7,-1,-3},
{6,-1,-3},
{6,-2,-4},
{6,-3,-4},
{6,-3,-4},
{6,-4,-4},
{6,-4,-4},
{7,-4,-5},
{7,-4,-5},
{7,-5,-5},
{7,-6,-5},
{7,-7,-5},
{7,-7,-5},
{7,-7,-5},
{7,-7,-5},
{7,-7,-5},
{7,-8,-5},
{7,-8,-5},
{8,-9,-5},
{7,-10,-5},
{7,-10,-5},
{8,-10,-5},
{7,-10,-5},
{7,-11,-4},
{7,-11,-4},
{7,-11,-4},
{7,-12,-5},
{8,-12,-5},
{8,-13,-4},
{7,-13,-4},
{7,-14,-4},
{8,-14,-4},
{8,-14,-4},
{8,-15,-4},
{8,-15,-4},
{8,-16,-4},
{8,-16,-4},
{8,-16,-4},
{8,-17,-4},
{9,-17,-4},
{9,-17,-4},
{9,-17,-4},
{9,-18,-4},
{9,-18,-4},
{9,-18,-4},
{9,-19,-4},
{9,-19,-4},
{9,-19,-4},
{9,-20,-4},
{9,-20,-4},
{9,-20,-3},
{9,-21,-3},
{9,-21,-3},
{9,-21,-3},
{10,-22,-3},
{10,-22,-3},
{10,-23,-3},
{10,-23,-3},
{10,-23,-3},
{10,-23,-3},
{10,-23,-3},
{10,-23,-3},
{10,-24,-3},
{10,-24,-3},
{10,-25,-3},
{10,-25,-2},
{10,-25,-2},
{10,-26,-3},
{10,-26,-2},
{10,-26,-2},
{10,-26,-3},
{11,-26,-3},
{11,-26,-3},
{11,-27,-2},
{11,-27,-2},
{11,-27,-2},
{11,-27,-2},
{11,-27,-2},
{11,-27,-2},
{11,-27,-2},
{11,-27,-2},
{12,-27,-2},
{12,-27,-2},
{12,-27,-2},
{12,-27,-2},
{12,-27,-2},
{12,-27,-2},
{12,-27,-2},
{12,-27,-2},
{13,-27,-2},
{13,-26,-2},
{13,-26,-2},
{13,-26,-2},
{13,-26,-2},
{12,-26,-2},
{12,-26,-2},
{12,-27,-2},
{12,-27,-3},
{12,-27,-3},
{12,-28,-3},
{12,-28,-4},
{12,-28,-4},
{12,-29,-4},
{12,-29,-5},
{11,-30,-5},
{11,-30,-5},
{11,-31,-6},
{11,-31,-6},
{11,-31,-6},
{11,-31,-7},
{11,-32,-7},
{12,-32,-7},
{11,-32,-7},
{11,-32,-7},
{11,-33,-7},
{11,-33,-7},
{11,-33,-7},
{11,-33,-7},
{11,-33,-7},
{11,-34,-6},
{11,-34,-6},
{11,-34,-6},
{11,-35,-6},
{11,-35,-6},
{11,-35,-6},
{11,-35,-6},
{11,-35,-5},
{11,-35,-5},
{11,-36,-5},
{11,-36,-4},
{11,-36,-4},
{11,-36,-4},
{11,-36,-4},
{11,-36,-3},
{11,-37,-3},
{11,-37,-3},
{11,-37,-3},
{11,-37,-2},
{11,-38,-2},
{11,-38,-2},
{11,-38,-1},
{11,-38,-1},
{11,-39,-1},
{11,-39,0},
{11,-39,0},
{11,-39,0},
{12,-39,0},
{12,-40,0},
{12,-40,0},
{12,-40,0},
{12,-41,0},
{12,-41,0},
{12,-41,0},
{12,-41,0},
{11,-41,1},
{11,-42,1},
{11,-42,1},
{11,-42,2},
{11,-42,2},
{11,-43,2},
{12,-43,2},
{12,-43,3},
{12,-43,3},
{12,-44,3},
{12,-44,3},
{12,-44,4},
{11,-44,4},
{11,-45,4},
{11,-45,4},
{11,-45,4},
{11,-45,5},
{11,-46,5},
{11,-46,5},
{11,-46,5},
{11,-46,5},
{11,-47,6},
{11,-47,6},
{11,-47,6},
{11,-47,6},
{11,-48,6},
{11,-48,7},
{11,-48,7},
{11,-48,7},
{11,-49,7},
{11,-49,7},
{11,-49,7},
{11,-49,8},
{11,-49,8},
{11,-50,8},
{11,-50,8},
{11,-50,8},
{11,-50,9},
{11,-51,9},
{11,-51,9},
{11,-51,9},
{11,-51,10},
{11,-51,10},
{11,-52,10},
{11,-52,10},
{11,-52,11},
{11,-53,11},
{11,-53,11},
{11,-53,11},
{11,-54,12},
{11,-54,12},
{11,-54,12},
{11,-54,12},
{11,-54,13},
{11,-54,13},
{11,-55,13},
{11,-55,13},
{11,-55,14},
{11,-55,14},
{11,-55,14},
{11,-55,14},
{11,-55,15},
{11,-55,15},
{11,-55,16},
{11,-55,16},
{11,-55,17},
{11,-55,17},
{11,-55,18},
{11,-55,18},
{11,-55,19},
{11,-54,19},
{11,-53,20},
};



#endif	/* TABLE_LUGE7_SN189_H */

