

#ifndef TABLE_LUGE7_SN172_H
#define	TABLE_LUGE7_SN172_H

// used in LUGE7_SN172 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14872 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-1201	,	-154	,	-467	},
{	-1198	,	-155	,	-465	},
{	-1192	,	-155	,	-462	},
{	-1190	,	-155	,	-461	},
{	-1185	,	-155	,	-458	},
{	-1183	,	-154	,	-456	},
{	-1177	,	-153	,	-454	},
{	-1177	,	-153	,	-453	},
{	-1171	,	-151	,	-450	},
{	-1170	,	-151	,	-449	},
{	-1161	,	-151	,	-444	},
{	-1155	,	-149	,	-439	},
{	-1144	,	-147	,	-435	},
{	-1135	,	-145	,	-431	},
{	-1130	,	-144	,	-429	},
{	-1123	,	-141	,	-425	},
{	-1114	,	-138	,	-419	},
{	-1106	,	-136	,	-416	},
{	-1097	,	-132	,	-411	},
{	-1092	,	-130	,	-408	},
{	-1085	,	-128	,	-403	},
{	-1080	,	-125	,	-400	},
{	-1072	,	-122	,	-396	},
{	-1068	,	-120	,	-392	},
{	-1055	,	-117	,	-387	},
{	-1051	,	-115	,	-384	},
{	-1042	,	-113	,	-379	},
{	-1034	,	-110	,	-374	},
{	-1026	,	-108	,	-371	},
{	-1022	,	-106	,	-368	},
{	-1017	,	-104	,	-365	},
{	-1008	,	-101	,	-360	},
{	-1002	,	-98	,	-356	},
{	-997	,	-96	,	-354	},
{	-992	,	-94	,	-352	},
{	-989	,	-92	,	-349	},
{	-980	,	-89	,	-346	},
{	-974	,	-87	,	-342	},
{	-965	,	-85	,	-337	},
{	-959	,	-82	,	-334	},
{	-949	,	-80	,	-330	},
{	-946	,	-79	,	-329	},
{	-939	,	-78	,	-326	},
{	-934	,	-76	,	-324	},
{	-928	,	-75	,	-321	},
{	-921	,	-73	,	-319	},
{	-913	,	-70	,	-315	},
{	-904	,	-69	,	-310	},
{	-899	,	-68	,	-308	},
{	-890	,	-66	,	-305	},
{	-883	,	-64	,	-301	},
{	-873	,	-62	,	-297	},
{	-863	,	-62	,	-293	},
{	-856	,	-60	,	-291	},
{	-846	,	-58	,	-288	},
{	-841	,	-57	,	-286	},
{	-833	,	-56	,	-283	},
{	-828	,	-54	,	-281	},
{	-820	,	-52	,	-277	},
{	-813	,	-49	,	-274	},
{	-805	,	-47	,	-271	},
{	-796	,	-45	,	-268	},
{	-790	,	-43	,	-265	},
{	-782	,	-41	,	-262	},
{	-776	,	-38	,	-260	},
{	-767	,	-36	,	-257	},
{	-760	,	-34	,	-254	},
{	-751	,	-32	,	-251	},
{	-746	,	-29	,	-249	},
{	-739	,	-27	,	-248	},
{	-731	,	-25	,	-245	},
{	-725	,	-22	,	-243	},
{	-718	,	-21	,	-240	},
{	-710	,	-19	,	-237	},
{	-701	,	-17	,	-234	},
{	-693	,	-15	,	-232	},
{	-687	,	-13	,	-230	},
{	-682	,	-13	,	-228	},
{	-677	,	-11	,	-226	},
{	-671	,	-10	,	-224	},
{	-664	,	-9	,	-221	},
{	-659	,	-8	,	-218	},
{	-653	,	-7	,	-216	},
{	-647	,	-7	,	-212	},
{	-642	,	-5	,	-210	},
{	-636	,	-6	,	-208	},
{	-631	,	-5	,	-206	},
{	-626	,	-5	,	-204	},
{	-619	,	-4	,	-202	},
{	-612	,	-2	,	-200	},
{	-605	,	-2	,	-198	},
{	-600	,	0	,	-197	},
{	-593	,	1	,	-195	},
{	-583	,	1	,	-193	},
{	-575	,	2	,	-191	},
{	-566	,	2	,	-188	},
{	-558	,	3	,	-187	},
{	-551	,	4	,	-186	},
{	-542	,	5	,	-185	},
{	-537	,	5	,	-184	},
{	-532	,	6	,	-184	},
{	-528	,	7	,	-183	},
{	-522	,	9	,	-181	},
{	-516	,	9	,	-179	},
{	-512	,	11	,	-177	},
{	-507	,	12	,	-175	},
{	-502	,	13	,	-174	},
{	-499	,	14	,	-173	},
{	-494	,	15	,	-172	},
{	-490	,	15	,	-171	},
{	-487	,	16	,	-170	},
{	-484	,	18	,	-169	},
{	-480	,	20	,	-167	},
{	-477	,	22	,	-166	},
{	-474	,	22	,	-164	},
{	-471	,	23	,	-163	},
{	-466	,	25	,	-160	},
{	-460	,	27	,	-159	},
{	-454	,	28	,	-158	},
{	-450	,	29	,	-156	},
{	-446	,	31	,	-154	},
{	-443	,	32	,	-154	},
{	-439	,	33	,	-153	},
{	-436	,	34	,	-151	},
{	-432	,	36	,	-149	},
{	-428	,	38	,	-149	},
{	-425	,	40	,	-146	},
{	-422	,	42	,	-145	},
{	-418	,	44	,	-142	},
{	-416	,	47	,	-140	},
{	-414	,	48	,	-139	},
{	-411	,	51	,	-137	},
{	-408	,	54	,	-135	},
{	-407	,	57	,	-134	},
{	-404	,	60	,	-132	},
{	-403	,	64	,	-130	},
{	-401	,	66	,	-129	},
{	-397	,	70	,	-128	},
{	-395	,	73	,	-128	},
{	-394	,	77	,	-127	},
{	-392	,	81	,	-126	},
{	-392	,	84	,	-125	},
{	-391	,	88	,	-123	},
{	-391	,	93	,	-122	},
{	-392	,	96	,	-122	},
{	-393	,	100	,	-121	},
{	-393	,	105	,	-122	},
{	-393	,	109	,	-121	},
{	-394	,	116	,	-120	},
{	-394	,	121	,	-120	},
{	-394	,	125	,	-121	},
{	-395	,	131	,	-122	},
{	-396	,	136	,	-122	},
{	-399	,	142	,	-123	},
{	-402	,	148	,	-123	},
{	-404	,	155	,	-122	},
{	-405	,	162	,	-122	},
{	-408	,	169	,	-122	},
{	-410	,	176	,	-122	},
{	-412	,	183	,	-121	},
{	-414	,	191	,	-121	},
{	-415	,	199	,	-120	},
{	-418	,	207	,	-120	},
{	-422	,	214	,	-120	},
{	-425	,	222	,	-119	},
{	-429	,	228	,	-119	},
{	-432	,	235	,	-119	},
{	-434	,	243	,	-117	},
{	-439	,	251	,	-116	},
{	-443	,	257	,	-116	},
{	-444	,	263	,	-115	},
{	-447	,	271	,	-114	},
{	-449	,	278	,	-112	},
{	-453	,	285	,	-112	},
{	-456	,	290	,	-112	},
{	-460	,	296	,	-112	},
{	-464	,	302	,	-113	},
{	-469	,	309	,	-113	},
{	-473	,	315	,	-113	},
{	-474	,	320	,	-113	},
{	-477	,	328	,	-112	},
{	-479	,	333	,	-114	},
{	-482	,	340	,	-114	},
{	-484	,	346	,	-115	},
{	-488	,	352	,	-114	},
{	-488	,	356	,	-114	},
{	-490	,	363	,	-113	},
{	-491	,	369	,	-113	},
{	-492	,	373	,	-113	},
{	-493	,	379	,	-114	},
{	-494	,	384	,	-114	},
{	-494	,	391	,	-113	},
{	-495	,	397	,	-113	},
{	-496	,	403	,	-113	},
{	-495	,	407	,	-113	},
{	-498	,	414	,	-114	},
{	-500	,	420	,	-114	},
{	-502	,	425	,	-115	},
{	-503	,	430	,	-115	},
{	-505	,	436	,	-115	},
{	-505	,	442	,	-115	},
{	-505	,	448	,	-116	},
{	-506	,	454	,	-117	},
{	-506	,	459	,	-117	},
{	-508	,	465	,	-116	},
{	-509	,	470	,	-116	},
{	-510	,	476	,	-115	},
{	-510	,	482	,	-115	},
{	-513	,	488	,	-116	},
{	-514	,	493	,	-117	},
{	-515	,	498	,	-118	},
{	-514	,	504	,	-117	},
{	-511	,	508	,	-117	},
{	-512	,	514	,	-118	},
{	-512	,	519	,	-118	},
{	-513	,	525	,	-117	},
{	-511	,	528	,	-117	},
{	-513	,	534	,	-117	},
{	-515	,	539	,	-117	},
{	-515	,	543	,	-118	},
{	-516	,	550	,	-118	},
{	-514	,	554	,	-120	},
{	-516	,	560	,	-122	},
{	-515	,	563	,	-123	},
{	-515	,	567	,	-124	},
{	-516	,	573	,	-125	},
{	-516	,	577	,	-126	},
{	-515	,	581	,	-125	},
{	-517	,	586	,	-127	},
{	-518	,	592	,	-128	},
{	-517	,	595	,	-128	},
{	-516	,	600	,	-128	},
{	-514	,	604	,	-128	},
{	-515	,	609	,	-130	},
{	-515	,	613	,	-131	},
{	-514	,	618	,	-133	},
{	-514	,	622	,	-134	},
{	-515	,	628	,	-135	},
{	-517	,	633	,	-136	},
{	-517	,	638	,	-136	},
{	-519	,	646	,	-137	},
{	-521	,	651	,	-138	},
{	-520	,	654	,	-138	},
{	-521	,	661	,	-140	},
{	-522	,	667	,	-141	},
{	-524	,	674	,	-142	},
{	-525	,	679	,	-144	},
{	-528	,	687	,	-144	},
{	-529	,	692	,	-145	},
{	-531	,	699	,	-147	},
{	-532	,	706	,	-148	},
{	-533	,	713	,	-149	},
{	-534	,	718	,	-149	},
{	-536	,	725	,	-151	},
{	-538	,	732	,	-152	},
{	-538	,	738	,	-153	},
{	-540	,	745	,	-154	},
{	-540	,	751	,	-155	},
{	-541	,	758	,	-157	},
{	-542	,	766	,	-158	},
{	-543	,	772	,	-159	},
{	-545	,	780	,	-161	},
{	-544	,	784	,	-162	},
{	-546	,	793	,	-163	},
{	-547	,	800	,	-166	},
{	-549	,	809	,	-168	},
{	-551	,	815	,	-170	},
{	-554	,	824	,	-171	},
{	-555	,	831	,	-172	},
{	-559	,	842	,	-174	},
{	-558	,	848	,	-176	},
{	-557	,	854	,	-177	},
{	-560	,	863	,	-178	},
{	-559	,	869	,	-180	},
{	-561	,	877	,	-181	},
{	-562	,	883	,	-182	},
{	-566	,	892	,	-183	},
{	-568	,	901	,	-184	},
{	-569	,	909	,	-184	},
{	-570	,	917	,	-185	},
{	-571	,	925	,	-184	},
{	-572	,	931	,	-185	},
{	-573	,	938	,	-186	},
{	-574	,	945	,	-187	},
{	-573	,	952	,	-187	},
{	-574	,	959	,	-188	},
{	-576	,	965	,	-188	},
{	-579	,	975	,	-188	},
{	-581	,	981	,	-188	},
{	-584	,	989	,	-189	},
{	-588	,	997	,	-191	},
{	-590	,	1005	,	-191	},
{	-592	,	1013	,	-191	},
{	-592	,	1019	,	-192	},
{	-594	,	1027	,	-194	},
{	-596	,	1034	,	-195	},
{	-598	,	1043	,	-196	},
{	-600	,	1051	,	-199	},
{	-602	,	1060	,	-201	},
{	-603	,	1068	,	-202	},
{	-605	,	1076	,	-203	},
{	-606	,	1084	,	-206	},
{	-610	,	1094	,	-207	},
{	-611	,	1100	,	-208	},
{	-611	,	1107	,	-209	},
{	-611	,	1113	,	-210	},
{	-613	,	1122	,	-212	},
{	-613	,	1126	,	-212	},
{	-613	,	1129	,	-213	},
{	-614	,	1134	,	-214	},
{	-615	,	1139	,	-215	},
{	-615	,	1142	,	-216	},
{	-615	,	1144	,	-216	},
{	-616	,	1148	,	-217	},
{	-615	,	1150	,	-217	}
};

#endif	/* TABLE_LUGE7_SN172_H */

