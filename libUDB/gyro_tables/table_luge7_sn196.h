

#ifndef TABLE_LUGE7_SN196_H
#define	TABLE_LUGE7_SN196_H

// used in LUGE7_SN196 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  (  -14304 )

int16_t residual_offset[] = { -370 , 384 , -318 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-5335	,	1381	,	304	},
{	-5334	,	1370	,	304	},
{	-5320	,	1359	,	304	},
{	-5306	,	1348	,	304	},
{	-5300	,	1338	,	304	},
{	-5277	,	1324	,	303	},
{	-5282	,	1317	,	304	},
{	-5272	,	1306	,	304	},
{	-5262	,	1296	,	303	},
{	-5252	,	1276	,	302	},
{	-5225	,	1253	,	300	},
{	-5218	,	1237	,	299	},
{	-5181	,	1211	,	296	},
{	-5160	,	1189	,	294	},
{	-5146	,	1170	,	293	},
{	-5139	,	1154	,	292	},
{	-5108	,	1132	,	289	},
{	-5078	,	1112	,	286	},
{	-5055	,	1095	,	283	},
{	-5042	,	1078	,	281	},
{	-5022	,	1058	,	278	},
{	-4996	,	1039	,	276	},
{	-4992	,	1024	,	275	},
{	-4956	,	1003	,	271	},
{	-4931	,	984	,	268	},
{	-4911	,	965	,	265	},
{	-4889	,	946	,	263	},
{	-4875	,	930	,	262	},
{	-4861	,	914	,	261	},
{	-4847	,	898	,	260	},
{	-4813	,	878	,	257	},
{	-4798	,	861	,	256	},
{	-4762	,	840	,	253	},
{	-4743	,	822	,	252	},
{	-4738	,	807	,	251	},
{	-4713	,	790	,	249	},
{	-4688	,	771	,	248	},
{	-4662	,	753	,	246	},
{	-4642	,	737	,	244	},
{	-4625	,	720	,	242	},
{	-4604	,	703	,	239	},
{	-4591	,	687	,	237	},
{	-4569	,	671	,	235	},
{	-4551	,	655	,	234	},
{	-4529	,	638	,	232	},
{	-4496	,	619	,	228	},
{	-4478	,	601	,	226	},
{	-4465	,	584	,	224	},
{	-4437	,	565	,	220	},
{	-4422	,	549	,	218	},
{	-4398	,	531	,	215	},
{	-4365	,	511	,	212	},
{	-4346	,	491	,	209	},
{	-4322	,	472	,	206	},
{	-4310	,	455	,	203	},
{	-4288	,	438	,	200	},
{	-4255	,	417	,	197	},
{	-4244	,	400	,	194	},
{	-4218	,	381	,	193	},
{	-4194	,	363	,	190	},
{	-4179	,	344	,	188	},
{	-4160	,	326	,	185	},
{	-4145	,	309	,	184	},
{	-4122	,	291	,	182	},
{	-4101	,	274	,	179	},
{	-4083	,	255	,	176	},
{	-4069	,	236	,	175	},
{	-4049	,	219	,	173	},
{	-4033	,	202	,	171	},
{	-4011	,	185	,	170	},
{	-3995	,	167	,	168	},
{	-3975	,	149	,	165	},
{	-3966	,	131	,	163	},
{	-3951	,	114	,	160	},
{	-3927	,	95	,	158	},
{	-3908	,	78	,	155	},
{	-3897	,	60	,	153	},
{	-3871	,	42	,	151	},
{	-3862	,	25	,	149	},
{	-3844	,	7	,	146	},
{	-3831	,	-7	,	142	},
{	-3817	,	-24	,	140	},
{	-3796	,	-38	,	137	},
{	-3783	,	-53	,	134	},
{	-3780	,	-69	,	130	},
{	-3764	,	-82	,	128	},
{	-3746	,	-95	,	125	},
{	-3732	,	-107	,	123	},
{	-3718	,	-121	,	120	},
{	-3692	,	-135	,	117	},
{	-3676	,	-149	,	115	},
{	-3665	,	-163	,	112	},
{	-3654	,	-176	,	109	},
{	-3632	,	-188	,	106	},
{	-3624	,	-202	,	103	},
{	-3599	,	-215	,	100	},
{	-3578	,	-227	,	96	},
{	-3563	,	-241	,	93	},
{	-3546	,	-252	,	90	},
{	-3536	,	-265	,	87	},
{	-3511	,	-277	,	85	},
{	-3487	,	-288	,	83	},
{	-3476	,	-303	,	80	},
{	-3460	,	-317	,	76	},
{	-3446	,	-330	,	73	},
{	-3430	,	-344	,	70	},
{	-3420	,	-358	,	66	},
{	-3405	,	-370	,	63	},
{	-3387	,	-383	,	60	},
{	-3375	,	-396	,	56	},
{	-3360	,	-410	,	54	},
{	-3343	,	-423	,	50	},
{	-3330	,	-437	,	48	},
{	-3323	,	-451	,	44	},
{	-3314	,	-467	,	42	},
{	-3298	,	-482	,	40	},
{	-3285	,	-496	,	37	},
{	-3274	,	-511	,	34	},
{	-3264	,	-527	,	31	},
{	-3250	,	-541	,	29	},
{	-3250	,	-558	,	27	},
{	-3234	,	-573	,	23	},
{	-3223	,	-586	,	20	},
{	-3220	,	-601	,	18	},
{	-3205	,	-615	,	15	},
{	-3195	,	-630	,	12	},
{	-3189	,	-645	,	11	},
{	-3186	,	-658	,	7	},
{	-3179	,	-672	,	4	},
{	-3172	,	-685	,	0	},
{	-3167	,	-699	,	-2	},
{	-3150	,	-709	,	-6	},
{	-3144	,	-722	,	-9	},
{	-3137	,	-733	,	-12	},
{	-3136	,	-747	,	-15	},
{	-3132	,	-759	,	-18	},
{	-3122	,	-770	,	-22	},
{	-3110	,	-780	,	-26	},
{	-3106	,	-791	,	-30	},
{	-3098	,	-801	,	-33	},
{	-3088	,	-810	,	-36	},
{	-3093	,	-822	,	-40	},
{	-3087	,	-830	,	-44	},
{	-3085	,	-841	,	-49	},
{	-3076	,	-849	,	-53	},
{	-3068	,	-857	,	-57	},
{	-3070	,	-866	,	-61	},
{	-3059	,	-873	,	-64	},
{	-3057	,	-884	,	-68	},
{	-3058	,	-894	,	-72	},
{	-3058	,	-904	,	-76	},
{	-3056	,	-913	,	-80	},
{	-3049	,	-921	,	-85	},
{	-3045	,	-929	,	-89	},
{	-3045	,	-939	,	-93	},
{	-3044	,	-947	,	-97	},
{	-3043	,	-957	,	-101	},
{	-3044	,	-967	,	-106	},
{	-3036	,	-974	,	-110	},
{	-3040	,	-984	,	-113	},
{	-3030	,	-989	,	-117	},
{	-3033	,	-997	,	-122	},
{	-3027	,	-1004	,	-126	},
{	-3027	,	-1014	,	-131	},
{	-3029	,	-1023	,	-135	},
{	-3024	,	-1028	,	-140	},
{	-3021	,	-1036	,	-145	},
{	-3014	,	-1043	,	-149	},
{	-3008	,	-1048	,	-154	},
{	-3008	,	-1057	,	-159	},
{	-3013	,	-1069	,	-165	},
{	-3006	,	-1075	,	-170	},
{	-3008	,	-1086	,	-174	},
{	-3009	,	-1095	,	-179	},
{	-3000	,	-1100	,	-182	},
{	-2999	,	-1109	,	-187	},
{	-2998	,	-1118	,	-192	},
{	-2994	,	-1127	,	-197	},
{	-2993	,	-1136	,	-201	},
{	-2996	,	-1147	,	-205	},
{	-2990	,	-1156	,	-208	},
{	-2987	,	-1164	,	-212	},
{	-2987	,	-1174	,	-215	},
{	-2992	,	-1187	,	-219	},
{	-2987	,	-1195	,	-223	},
{	-2987	,	-1206	,	-228	},
{	-2982	,	-1215	,	-231	},
{	-2976	,	-1223	,	-234	},
{	-2978	,	-1235	,	-237	},
{	-2975	,	-1246	,	-241	},
{	-2971	,	-1255	,	-245	},
{	-2966	,	-1264	,	-249	},
{	-2963	,	-1275	,	-253	},
{	-2952	,	-1282	,	-257	},
{	-2954	,	-1295	,	-262	},
{	-2947	,	-1305	,	-266	},
{	-2949	,	-1317	,	-270	},
{	-2938	,	-1324	,	-274	},
{	-2931	,	-1332	,	-278	},
{	-2927	,	-1342	,	-283	},
{	-2913	,	-1348	,	-288	},
{	-2920	,	-1363	,	-293	},
{	-2911	,	-1373	,	-297	},
{	-2908	,	-1384	,	-302	},
{	-2901	,	-1392	,	-306	},
{	-2895	,	-1400	,	-311	},
{	-2893	,	-1411	,	-316	},
{	-2890	,	-1420	,	-320	},
{	-2888	,	-1431	,	-324	},
{	-2879	,	-1439	,	-328	},
{	-2881	,	-1452	,	-333	},
{	-2869	,	-1458	,	-337	},
{	-2865	,	-1466	,	-341	},
{	-2856	,	-1475	,	-346	},
{	-2853	,	-1484	,	-351	},
{	-2853	,	-1497	,	-357	},
{	-2850	,	-1507	,	-363	},
{	-2842	,	-1515	,	-368	},
{	-2835	,	-1523	,	-375	},
{	-2829	,	-1531	,	-379	},
{	-2820	,	-1536	,	-384	},
{	-2819	,	-1546	,	-390	},
{	-2817	,	-1556	,	-396	},
{	-2803	,	-1560	,	-401	},
{	-2792	,	-1566	,	-406	},
{	-2796	,	-1578	,	-414	},
{	-2788	,	-1584	,	-419	},
{	-2780	,	-1590	,	-424	},
{	-2782	,	-1601	,	-430	},
{	-2779	,	-1610	,	-434	},
{	-2777	,	-1619	,	-439	},
{	-2770	,	-1625	,	-442	},
{	-2771	,	-1636	,	-447	},
{	-2761	,	-1640	,	-450	},
{	-2765	,	-1651	,	-456	},
{	-2757	,	-1656	,	-458	},
{	-2752	,	-1662	,	-462	},
{	-2751	,	-1671	,	-466	},
{	-2745	,	-1679	,	-470	},
{	-2734	,	-1680	,	-472	},
{	-2735	,	-1691	,	-477	},
{	-2733	,	-1699	,	-482	},
{	-2723	,	-1702	,	-484	},
{	-2722	,	-1711	,	-489	},
{	-2716	,	-1717	,	-493	},
{	-2713	,	-1725	,	-497	},
{	-2706	,	-1730	,	-501	},
{	-2701	,	-1736	,	-505	},
{	-2701	,	-1745	,	-509	},
{	-2695	,	-1750	,	-513	},
{	-2695	,	-1759	,	-517	},
{	-2690	,	-1766	,	-522	},
{	-2689	,	-1776	,	-526	},
{	-2692	,	-1787	,	-530	},
{	-2692	,	-1797	,	-535	},
{	-2691	,	-1805	,	-539	},
{	-2685	,	-1811	,	-543	},
{	-2679	,	-1817	,	-546	},
{	-2684	,	-1829	,	-550	},
{	-2683	,	-1836	,	-554	},
{	-2687	,	-1848	,	-558	},
{	-2684	,	-1854	,	-559	},
{	-2685	,	-1863	,	-564	},
{	-2683	,	-1869	,	-569	},
{	-2681	,	-1876	,	-573	},
{	-2676	,	-1881	,	-578	},
{	-2674	,	-1887	,	-582	},
{	-2670	,	-1892	,	-585	},
{	-2668	,	-1897	,	-589	},
{	-2662	,	-1899	,	-592	},
{	-2653	,	-1899	,	-594	},
{	-2648	,	-1902	,	-598	},
{	-2640	,	-1905	,	-602	},
{	-2647	,	-1916	,	-608	},
{	-2641	,	-1918	,	-611	},
{	-2631	,	-1917	,	-614	},
{	-2622	,	-1918	,	-616	},
{	-2619	,	-1925	,	-623	},
{	-2614	,	-1929	,	-627	},
{	-2597	,	-1925	,	-628	},
{	-2596	,	-1932	,	-632	},
{	-2590	,	-1937	,	-636	},
{	-2585	,	-1941	,	-638	},
{	-2579	,	-1945	,	-642	},
{	-2577	,	-1952	,	-645	},
{	-2572	,	-1955	,	-647	},
{	-2569	,	-1962	,	-651	},
{	-2563	,	-1966	,	-653	},
{	-2559	,	-1970	,	-657	},
{	-2554	,	-1974	,	-661	},
{	-2545	,	-1976	,	-664	},
{	-2545	,	-1983	,	-668	},
{	-2545	,	-1991	,	-672	},
{	-2545	,	-1997	,	-675	},
{	-2530	,	-1993	,	-673	},
{	-2530	,	-2001	,	-677	},
{	-2533	,	-2006	,	-680	},
{	-2532	,	-2009	,	-681	},
{	-2528	,	-2009	,	-682	},
{	-2528	,	-2013	,	-684	},
{	-2522	,	-2012	,	-684	},
{	-2518	,	-2012	,	-686	},
{	-2516	,	-2014	,	-689	},
{	-2510	,	-2013	,	-690	}
};




#define ACCEL_TABLE


#define ACCEL_TABLE_ORIGIN ( -11603)

int16_t accel_residual_offset[] = { -39 , -33 , -59 } ; 

const struct gyro_offset_table_entry accel_offset_table[] = {
{-2,1,-1},
{-1,0,-1},
{-2,0,-1},
{-2,1,-2},
{-2,0,-3},
{-1,0,-4},
{-1,0,-5},
{-2,0,-5},
{-1,0,1},
{0,0,6},
{0,-1,4},
{0,-1,2},
{0,-1,1},
{0,-1,1},
{0,-2,0},
{0,-2,0},
{0,-2,0},
{0,-2,0},
{1,-2,0},
{1,-2,0},
{1,-3,0},
{1,-3,0},
{1,-3,0},
{1,-3,0},
{1,-4,0},
{1,-4,0},
{1,-4,1},
{1,-5,1},
{1,-5,1},
{1,-5,1},
{2,-5,2},
{2,-5,2},
{2,-6,2},
{2,-6,2},
{3,-6,2},
{2,-6,2},
{2,-7,2},
{3,-7,3},
{3,-7,2},
{3,-8,2},
{3,-8,3},
{3,-8,4},
{3,-8,4},
{3,-8,4},
{3,-8,4},
{3,-9,4},
{3,-9,4},
{4,-10,4},
{3,-10,4},
{3,-10,5},
{3,-10,5},
{4,-11,5},
{5,-10,6},
{5,-10,6},
{5,-11,6},
{6,-12,6},
{6,-12,6},
{7,-12,6},
{7,-13,6},
{7,-13,7},
{7,-13,7},
{7,-13,7},
{7,-13,7},
{7,-14,7},
{7,-14,7},
{7,-14,8},
{7,-14,8},
{7,-14,8},
{8,-14,8},
{8,-14,9},
{7,-15,9},
{7,-15,9},
{8,-15,9},
{8,-15,9},
{8,-15,9},
{9,-16,10},
{9,-16,10},
{9,-16,10},
{9,-16,10},
{9,-16,10},
{9,-16,10},
{9,-17,10},
{9,-17,11},
{9,-17,11},
{9,-17,11},
{8,-16,11},
{9,-16,11},
{10,-17,12},
{10,-17,12},
{10,-17,12},
{10,-16,12},
{10,-16,12},
{10,-17,12},
{10,-16,12},
{10,-16,12},
{10,-16,13},
{10,-16,13},
{11,-16,13},
{10,-15,13},
{10,-15,13},
{11,-15,13},
{11,-15,14},
{11,-15,14},
{11,-15,14},
{11,-15,14},
{11,-15,14},
{11,-15,14},
{10,-14,15},
{10,-14,15},
{10,-14,15},
{10,-15,15},
{10,-15,15},
{10,-16,15},
{10,-16,15},
{10,-16,15},
{10,-17,15},
{10,-17,16},
{10,-17,16},
{10,-17,16},
{10,-17,16},
{10,-18,16},
{10,-18,16},
{10,-18,16},
{10,-18,16},
{10,-18,17},
{10,-18,17},
{10,-18,17},
{10,-18,18},
{10,-18,18},
{10,-18,18},
{10,-19,19},
{10,-19,19},
{10,-18,19},
{10,-18,20},
{10,-19,20},
{10,-19,21},
{10,-19,21},
{10,-19,21},
{10,-19,21},
{10,-19,22},
{10,-19,22},
{10,-20,22},
{11,-20,23},
{11,-20,23},
{11,-20,24},
{11,-20,24},
{11,-20,25},
{11,-20,25},
{10,-21,26},
{10,-21,26},
{11,-21,26},
{11,-21,27},
{11,-21,27},
{11,-21,28},
{11,-21,28},
{11,-21,28},
{11,-22,29},
{11,-22,29},
{11,-22,30},
{11,-22,30},
{11,-22,30},
{11,-22,31},
{11,-22,31},
{11,-22,32},
{11,-23,32},
{11,-23,32},
{11,-23,33},
{11,-23,33},
{11,-23,33},
{11,-23,34},
{11,-24,34},
{11,-24,34},
{11,-24,34},
{11,-24,35},
{11,-24,35},
{11,-24,35},
{11,-24,35},
{12,-25,36},
{12,-25,36},
{12,-25,36},
{12,-25,36},
{12,-25,36},
{12,-25,37},
{12,-25,37},
{12,-26,37},
{12,-26,37},
{12,-26,37},
{12,-26,38},
{12,-26,38},
{13,-26,38},
{13,-26,38},
{13,-26,38},
{13,-27,38},
{13,-27,39},
{13,-26,39},
{13,-26,39},
{13,-27,39},
{13,-27,39},
{13,-27,39},
{13,-27,39},
{13,-27,39},
{13,-27,39},
{14,-28,39},
{14,-28,39},
{14,-28,39},
{14,-28,40},
{14,-28,40},
{14,-28,40},
{14,-28,40},
{14,-28,40},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,41},
{14,-29,42},
{15,-29,42},
{15,-29,42},
{15,-29,42},
{15,-29,42},
{15,-29,42},
{15,-29,43},
{15,-29,43},
{15,-29,43},
{15,-29,43},
{15,-29,43},
{15,-29,43},
{15,-29,44},
{15,-29,44},
{15,-29,44},
{15,-29,44},
{16,-29,45},
{16,-28,45},
{16,-28,46},
{16,-28,46},
{16,-28,47},
{15,-28,47},
{15,-27,48},
{15,-26,50},
};



#endif	/* TABLE_LUGE7_SN196_H */

