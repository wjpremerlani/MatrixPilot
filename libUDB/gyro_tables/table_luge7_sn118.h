

#ifndef TABLE_LUGE7_SN118_H
#define	TABLE_LUGE7_SN118_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14574 )

int16_t residual_offset[] = { 716 , -237 , -196 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-830	,	851	,	-759	},
{	-823	,	841	,	-754	},
{	-817	,	835	,	-753	},
{	-813	,	830	,	-754	},
{	-805	,	822	,	-751	},
{	-798	,	813	,	-749	},
{	-790	,	803	,	-746	},
{	-783	,	795	,	-744	},
{	-775	,	787	,	-742	},
{	-767	,	775	,	-744	},
{	-753	,	759	,	-739	},
{	-742	,	744	,	-737	},
{	-728	,	728	,	-731	},
{	-715	,	712	,	-727	},
{	-702	,	695	,	-723	},
{	-689	,	679	,	-717	},
{	-676	,	665	,	-716	},
{	-661	,	648	,	-710	},
{	-650	,	634	,	-708	},
{	-636	,	617	,	-703	},
{	-621	,	599	,	-697	},
{	-609	,	585	,	-694	},
{	-598	,	569	,	-690	},
{	-587	,	555	,	-687	},
{	-575	,	540	,	-683	},
{	-564	,	525	,	-679	},
{	-552	,	511	,	-675	},
{	-540	,	496	,	-671	},
{	-526	,	480	,	-664	},
{	-515	,	466	,	-662	},
{	-503	,	451	,	-657	},
{	-490	,	436	,	-651	},
{	-479	,	421	,	-648	},
{	-466	,	405	,	-644	},
{	-455	,	390	,	-642	},
{	-442	,	375	,	-636	},
{	-432	,	362	,	-633	},
{	-420	,	346	,	-629	},
{	-409	,	331	,	-627	},
{	-397	,	317	,	-623	},
{	-387	,	303	,	-620	},
{	-377	,	289	,	-617	},
{	-366	,	275	,	-613	},
{	-355	,	258	,	-607	},
{	-344	,	244	,	-603	},
{	-334	,	230	,	-601	},
{	-323	,	215	,	-597	},
{	-312	,	199	,	-595	},
{	-302	,	185	,	-592	},
{	-289	,	170	,	-589	},
{	-277	,	154	,	-584	},
{	-267	,	140	,	-582	},
{	-258	,	126	,	-580	},
{	-246	,	111	,	-577	},
{	-239	,	98	,	-576	},
{	-227	,	83	,	-570	},
{	-217	,	69	,	-568	},
{	-206	,	53	,	-565	},
{	-194	,	38	,	-563	},
{	-184	,	23	,	-560	},
{	-172	,	9	,	-558	},
{	-161	,	-6	,	-556	},
{	-151	,	-20	,	-553	},
{	-141	,	-34	,	-550	},
{	-130	,	-47	,	-547	},
{	-120	,	-61	,	-545	},
{	-111	,	-75	,	-543	},
{	-101	,	-88	,	-540	},
{	-90	,	-103	,	-536	},
{	-79	,	-118	,	-532	},
{	-69	,	-133	,	-528	},
{	-57	,	-148	,	-524	},
{	-47	,	-162	,	-521	},
{	-36	,	-178	,	-519	},
{	-25	,	-192	,	-516	},
{	-14	,	-207	,	-512	},
{	-4	,	-219	,	-509	},
{	7	,	-232	,	-505	},
{	17	,	-246	,	-504	},
{	28	,	-260	,	-501	},
{	38	,	-273	,	-496	},
{	48	,	-287	,	-494	},
{	58	,	-300	,	-491	},
{	69	,	-314	,	-487	},
{	78	,	-326	,	-486	},
{	87	,	-339	,	-483	},
{	96	,	-352	,	-481	},
{	104	,	-365	,	-479	},
{	113	,	-378	,	-476	},
{	121	,	-390	,	-474	},
{	128	,	-401	,	-471	},
{	135	,	-412	,	-467	},
{	141	,	-423	,	-463	},
{	146	,	-436	,	-461	},
{	149	,	-447	,	-457	},
{	153	,	-458	,	-453	},
{	158	,	-469	,	-450	},
{	162	,	-481	,	-449	},
{	166	,	-492	,	-445	},
{	171	,	-503	,	-442	},
{	174	,	-514	,	-440	},
{	178	,	-525	,	-436	},
{	182	,	-537	,	-435	},
{	184	,	-548	,	-432	},
{	188	,	-556	,	-428	},
{	190	,	-565	,	-425	},
{	194	,	-576	,	-422	},
{	198	,	-587	,	-422	},
{	202	,	-596	,	-419	},
{	207	,	-609	,	-419	},
{	211	,	-618	,	-416	},
{	218	,	-630	,	-415	},
{	223	,	-640	,	-414	},
{	229	,	-653	,	-413	},
{	234	,	-663	,	-410	},
{	238	,	-673	,	-408	},
{	244	,	-685	,	-406	},
{	249	,	-694	,	-404	},
{	252	,	-706	,	-404	},
{	256	,	-715	,	-400	},
{	261	,	-726	,	-399	},
{	265	,	-738	,	-399	},
{	269	,	-749	,	-398	},
{	272	,	-760	,	-398	},
{	276	,	-770	,	-395	},
{	278	,	-781	,	-394	},
{	280	,	-788	,	-391	},
{	281	,	-797	,	-390	},
{	282	,	-806	,	-388	},
{	283	,	-816	,	-388	},
{	283	,	-819	,	-384	},
{	283	,	-828	,	-384	},
{	283	,	-836	,	-384	},
{	280	,	-841	,	-382	},
{	279	,	-849	,	-383	},
{	276	,	-855	,	-381	},
{	273	,	-861	,	-381	},
{	270	,	-865	,	-379	},
{	267	,	-871	,	-377	},
{	263	,	-878	,	-374	},
{	258	,	-882	,	-371	},
{	252	,	-887	,	-369	},
{	245	,	-891	,	-367	},
{	239	,	-895	,	-365	},
{	233	,	-902	,	-364	},
{	225	,	-905	,	-361	},
{	217	,	-908	,	-359	},
{	210	,	-915	,	-358	},
{	201	,	-920	,	-356	},
{	192	,	-923	,	-353	},
{	184	,	-928	,	-352	},
{	175	,	-932	,	-349	},
{	167	,	-934	,	-348	},
{	158	,	-940	,	-347	},
{	149	,	-944	,	-347	},
{	139	,	-945	,	-345	},
{	130	,	-947	,	-344	},
{	120	,	-949	,	-342	},
{	110	,	-950	,	-339	},
{	103	,	-953	,	-338	},
{	94	,	-959	,	-337	},
{	85	,	-958	,	-333	},
{	77	,	-962	,	-331	},
{	68	,	-965	,	-329	},
{	60	,	-968	,	-327	},
{	51	,	-969	,	-325	},
{	43	,	-974	,	-324	},
{	37	,	-976	,	-321	},
{	30	,	-979	,	-320	},
{	22	,	-982	,	-318	},
{	15	,	-984	,	-315	},
{	8	,	-989	,	-312	},
{	2	,	-994	,	-311	},
{	-5	,	-998	,	-308	},
{	-11	,	-1001	,	-308	},
{	-16	,	-1006	,	-307	},
{	-22	,	-1009	,	-306	},
{	-28	,	-1012	,	-304	},
{	-33	,	-1018	,	-304	},
{	-39	,	-1023	,	-302	},
{	-43	,	-1029	,	-301	},
{	-48	,	-1030	,	-300	},
{	-52	,	-1036	,	-299	},
{	-57	,	-1038	,	-298	},
{	-63	,	-1043	,	-297	},
{	-69	,	-1048	,	-296	},
{	-73	,	-1054	,	-293	},
{	-78	,	-1057	,	-291	},
{	-82	,	-1062	,	-290	},
{	-86	,	-1067	,	-288	},
{	-90	,	-1071	,	-286	},
{	-95	,	-1081	,	-283	},
{	-100	,	-1087	,	-281	},
{	-105	,	-1097	,	-279	},
{	-109	,	-1104	,	-277	},
{	-114	,	-1112	,	-276	},
{	-119	,	-1118	,	-274	},
{	-124	,	-1124	,	-272	},
{	-129	,	-1134	,	-272	},
{	-134	,	-1140	,	-270	},
{	-139	,	-1149	,	-268	},
{	-143	,	-1156	,	-266	},
{	-147	,	-1163	,	-263	},
{	-151	,	-1170	,	-262	},
{	-155	,	-1179	,	-261	},
{	-160	,	-1184	,	-258	},
{	-165	,	-1192	,	-258	},
{	-170	,	-1201	,	-255	},
{	-175	,	-1205	,	-254	},
{	-179	,	-1213	,	-252	},
{	-183	,	-1215	,	-251	},
{	-188	,	-1223	,	-250	},
{	-192	,	-1227	,	-247	},
{	-197	,	-1238	,	-246	},
{	-202	,	-1244	,	-244	},
{	-207	,	-1251	,	-242	},
{	-213	,	-1258	,	-240	},
{	-218	,	-1263	,	-239	},
{	-223	,	-1270	,	-237	},
{	-229	,	-1276	,	-237	},
{	-233	,	-1282	,	-234	},
{	-239	,	-1291	,	-232	},
{	-244	,	-1296	,	-230	},
{	-248	,	-1302	,	-228	},
{	-253	,	-1308	,	-228	},
{	-258	,	-1317	,	-226	},
{	-263	,	-1323	,	-225	},
{	-269	,	-1329	,	-223	},
{	-273	,	-1335	,	-221	},
{	-278	,	-1343	,	-221	},
{	-283	,	-1349	,	-219	},
{	-287	,	-1353	,	-218	},
{	-292	,	-1359	,	-216	},
{	-296	,	-1366	,	-214	},
{	-300	,	-1373	,	-213	},
{	-306	,	-1384	,	-212	},
{	-311	,	-1390	,	-209	},
{	-316	,	-1395	,	-207	},
{	-322	,	-1400	,	-205	},
{	-327	,	-1408	,	-204	},
{	-334	,	-1415	,	-202	},
{	-340	,	-1424	,	-201	},
{	-345	,	-1429	,	-201	},
{	-351	,	-1437	,	-200	},
{	-359	,	-1449	,	-199	},
{	-365	,	-1454	,	-198	},
{	-371	,	-1459	,	-197	},
{	-377	,	-1463	,	-195	},
{	-383	,	-1472	,	-195	},
{	-388	,	-1475	,	-194	},
{	-395	,	-1481	,	-193	},
{	-402	,	-1486	,	-192	},
{	-408	,	-1494	,	-191	},
{	-414	,	-1498	,	-190	},
{	-421	,	-1506	,	-189	},
{	-427	,	-1514	,	-188	},
{	-434	,	-1526	,	-188	},
{	-440	,	-1531	,	-187	},
{	-446	,	-1536	,	-186	},
{	-452	,	-1543	,	-184	},
{	-456	,	-1547	,	-183	},
{	-460	,	-1549	,	-181	},
{	-467	,	-1559	,	-180	},
{	-473	,	-1567	,	-179	},
{	-479	,	-1575	,	-178	},
{	-487	,	-1585	,	-177	},
{	-494	,	-1597	,	-177	},
{	-501	,	-1605	,	-176	},
{	-507	,	-1615	,	-175	},
{	-514	,	-1622	,	-174	},
{	-522	,	-1635	,	-173	},
{	-528	,	-1642	,	-173	},
{	-535	,	-1651	,	-172	},
{	-540	,	-1655	,	-171	},
{	-548	,	-1669	,	-171	},
{	-553	,	-1675	,	-170	},
{	-561	,	-1687	,	-170	},
{	-571	,	-1701	,	-170	},
{	-580	,	-1715	,	-170	},
{	-586	,	-1721	,	-169	},
{	-593	,	-1732	,	-169	},
{	-600	,	-1743	,	-168	},
{	-606	,	-1752	,	-169	},
{	-612	,	-1760	,	-168	},
{	-619	,	-1775	,	-168	},
{	-626	,	-1785	,	-166	},
{	-631	,	-1793	,	-165	},
{	-637	,	-1804	,	-164	},
{	-644	,	-1816	,	-164	},
{	-651	,	-1826	,	-163	},
{	-658	,	-1838	,	-162	},
{	-663	,	-1842	,	-161	},
{	-672	,	-1856	,	-161	},
{	-677	,	-1861	,	-160	},
{	-683	,	-1867	,	-159	},
{	-690	,	-1875	,	-159	},
{	-697	,	-1885	,	-159	},
{	-704	,	-1895	,	-160	},
{	-710	,	-1903	,	-159	},
{	-717	,	-1910	,	-158	},
{	-723	,	-1915	,	-157	},
{	-730	,	-1923	,	-156	},
{	-735	,	-1928	,	-156	},
{	-743	,	-1937	,	-156	},
{	-748	,	-1940	,	-156	},
{	-755	,	-1948	,	-156	},
{	-762	,	-1958	,	-156	},
{	-771	,	-1970	,	-156	},
{	-779	,	-1981	,	-157	},
{	-782	,	-1984	,	-157	},
{	-791	,	-1996	,	-157	},
{	-796	,	-2004	,	-156	},
{	-804	,	-2015	,	-155	},
{	-812	,	-2026	,	-155	},
{	-818	,	-2031	,	-154	},
{	-823	,	-2035	,	-153	},
{	-829	,	-2042	,	-152	},
{	-837	,	-2054	,	-151	},
{	-842	,	-2057	,	-150	},
{	-850	,	-2067	,	-149	},
{	-857	,	-2076	,	-148	},
{	-864	,	-2085	,	-147	},
{	-870	,	-2092	,	-147	},
{	-874	,	-2092	,	-146	},
{	-879	,	-2098	,	-145	},
{	-883	,	-2101	,	-143	},
{	-894	,	-2115	,	-142	},
{	-901	,	-2121	,	-141	},
{	-909	,	-2131	,	-141	},
{	-913	,	-2132	,	-140	},
{	-920	,	-2142	,	-140	},
{	-927	,	-2151	,	-139	},
{	-935	,	-2161	,	-138	},
{	-942	,	-2169	,	-137	},
{	-949	,	-2173	,	-137	},
{	-958	,	-2184	,	-137	},
{	-967	,	-2195	,	-138	},
{	-974	,	-2201	,	-137	},
{	-983	,	-2211	,	-137	},
{	-992	,	-2221	,	-137	},
{	-1002	,	-2232	,	-137	},
{	-1008	,	-2234	,	-136	},
{	-1021	,	-2253	,	-137	},
{	-1026	,	-2257	,	-136	},
{	-1035	,	-2268	,	-137	},
{	-1042	,	-2275	,	-136	},
{	-1049	,	-2282	,	-136	},
{	-1059	,	-2293	,	-137	},
{	-1067	,	-2302	,	-136	},
{	-1073	,	-2307	,	-136	},
{	-1083	,	-2321	,	-136	},
{	-1093	,	-2335	,	-136	},
{	-1099	,	-2341	,	-136	},
{	-1106	,	-2349	,	-135	},
{	-1116	,	-2363	,	-136	},
{	-1123	,	-2372	,	-135	},
{	-1133	,	-2387	,	-136	},
{	-1139	,	-2394	,	-135	},
{	-1152	,	-2415	,	-136	},
{	-1155	,	-2416	,	-135	},
{	-1166	,	-2432	,	-135	},
{	-1173	,	-2441	,	-135	},
{	-1180	,	-2451	,	-135	},
{	-1188	,	-2465	,	-135	},
{	-1194	,	-2475	,	-134	},
{	-1203	,	-2491	,	-134	},
{	-1209	,	-2504	,	-135	},
{	-1215	,	-2519	,	-136	},
{	-1219	,	-2531	,	-136	},
{	-1224	,	-2541	,	-137	},
{	-1226	,	-2546	,	-137	},
{	-1228	,	-2550	,	-137	},
{	-1231	,	-2557	,	-137	},
{	-1231	,	-2558	,	-137	},
{	-1237	,	-2571	,	-138	},
{	-1235	,	-2570	,	-137	},
{	-1241	,	-2585	,	-138	}
};

#endif	/* TABLE_LUGE7_SN118_H */

