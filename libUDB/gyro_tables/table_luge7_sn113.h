

#ifndef TABLE_LUGE7_SN113_H
#define	TABLE_LUGE7_SN113_H

// used in LUGE7_SN108 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  (-14470 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


struct gyro_offset_table_entry gyro_offset_table[] = {
{	4096	,	2723	,	-1191	},
{	4084	,	2709	,	-1185	},
{	4082	,	2703	,	-1182	},
{	4086	,	2700	,	-1180	},
{	4081	,	2693	,	-1178	},
{	4088	,	2692	,	-1178	},
{	4097	,	2694	,	-1179	},
{	4089	,	2684	,	-1175	},
{	4092	,	2682	,	-1175	},
{	4103	,	2681	,	-1174	},
{	4104	,	2674	,	-1170	},
{	4097	,	2664	,	-1165	},
{	4090	,	2653	,	-1160	},
{	4097	,	2650	,	-1159	},
{	4088	,	2638	,	-1155	},
{	4097	,	2636	,	-1157	},
{	4094	,	2628	,	-1155	},
{	4080	,	2614	,	-1150	},
{	4093	,	2616	,	-1152	},
{	4093	,	2611	,	-1149	},
{	4087	,	2602	,	-1147	},
{	4089	,	2597	,	-1146	},
{	4075	,	2584	,	-1140	},
{	4066	,	2572	,	-1136	},
{	4076	,	2573	,	-1137	},
{	4065	,	2562	,	-1131	},
{	4060	,	2556	,	-1128	},
{	4054	,	2549	,	-1126	},
{	4063	,	2548	,	-1127	},
{	4058	,	2539	,	-1122	},
{	4050	,	2529	,	-1117	},
{	4060	,	2528	,	-1117	},
{	4046	,	2514	,	-1110	},
{	4048	,	2510	,	-1108	},
{	4042	,	2500	,	-1105	},
{	4041	,	2493	,	-1102	},
{	4034	,	2483	,	-1099	},
{	4032	,	2476	,	-1096	},
{	4023	,	2467	,	-1092	},
{	4030	,	2465	,	-1092	},
{	4028	,	2459	,	-1089	},
{	4024	,	2450	,	-1086	},
{	4023	,	2443	,	-1084	},
{	4017	,	2434	,	-1081	},
{	4018	,	2427	,	-1078	},
{	4009	,	2415	,	-1073	},
{	4019	,	2417	,	-1074	},
{	4013	,	2407	,	-1071	},
{	3992	,	2390	,	-1064	},
{	3998	,	2388	,	-1064	},
{	3996	,	2381	,	-1061	},
{	3998	,	2377	,	-1059	},
{	3982	,	2363	,	-1053	},
{	3982	,	2358	,	-1051	},
{	3979	,	2349	,	-1047	},
{	3981	,	2344	,	-1045	},
{	3980	,	2337	,	-1042	},
{	3974	,	2328	,	-1038	},
{	3962	,	2317	,	-1032	},
{	3962	,	2312	,	-1029	},
{	3951	,	2300	,	-1023	},
{	3948	,	2292	,	-1021	},
{	3947	,	2286	,	-1019	},
{	3938	,	2274	,	-1015	},
{	3936	,	2267	,	-1012	},
{	3942	,	2264	,	-1010	},
{	3939	,	2255	,	-1006	},
{	3932	,	2245	,	-1003	},
{	3933	,	2241	,	-1000	},
{	3931	,	2233	,	-996	},
{	3929	,	2226	,	-992	},
{	3930	,	2220	,	-991	},
{	3923	,	2210	,	-989	},
{	3912	,	2198	,	-985	},
{	3908	,	2190	,	-983	},
{	3906	,	2184	,	-981	},
{	3912	,	2183	,	-981	},
{	3914	,	2178	,	-981	},
{	3903	,	2167	,	-976	},
{	3907	,	2163	,	-974	},
{	3898	,	2153	,	-972	},
{	3893	,	2145	,	-969	},
{	3882	,	2136	,	-965	},
{	3876	,	2127	,	-963	},
{	3876	,	2122	,	-964	},
{	3869	,	2114	,	-963	},
{	3874	,	2112	,	-965	},
{	3877	,	2110	,	-967	},
{	3866	,	2100	,	-964	},
{	3863	,	2095	,	-963	},
{	3863	,	2091	,	-963	},
{	3856	,	2084	,	-961	},
{	3854	,	2080	,	-961	},
{	3836	,	2065	,	-957	},
{	3835	,	2061	,	-957	},
{	3841	,	2061	,	-960	},
{	3825	,	2048	,	-958	},
{	3819	,	2042	,	-957	},
{	3810	,	2032	,	-957	},
{	3813	,	2030	,	-960	},
{	3801	,	2021	,	-957	},
{	3794	,	2014	,	-956	},
{	3783	,	2007	,	-953	},
{	3774	,	1998	,	-952	},
{	3759	,	1988	,	-949	},
{	3753	,	1982	,	-948	},
{	3742	,	1975	,	-946	},
{	3735	,	1970	,	-944	},
{	3730	,	1966	,	-944	},
{	3732	,	1964	,	-944	},
{	3725	,	1958	,	-941	},
{	3714	,	1952	,	-939	},
{	3695	,	1941	,	-934	},
{	3688	,	1937	,	-932	},
{	3679	,	1932	,	-930	},
{	3671	,	1928	,	-929	},
{	3664	,	1925	,	-927	},
{	3656	,	1922	,	-926	},
{	3642	,	1915	,	-923	},
{	3629	,	1909	,	-919	},
{	3618	,	1905	,	-916	},
{	3613	,	1903	,	-915	},
{	3604	,	1900	,	-914	},
{	3597	,	1900	,	-914	},
{	3578	,	1893	,	-911	},
{	3567	,	1890	,	-910	},
{	3542	,	1882	,	-907	},
{	3533	,	1881	,	-909	},
{	3514	,	1877	,	-907	},
{	3509	,	1879	,	-908	},
{	3497	,	1879	,	-907	},
{	3483	,	1879	,	-907	},
{	3477	,	1883	,	-908	},
{	3459	,	1881	,	-907	},
{	3454	,	1886	,	-909	},
{	3437	,	1885	,	-910	},
{	3428	,	1889	,	-913	},
{	3413	,	1893	,	-914	},
{	3391	,	1892	,	-913	},
{	3372	,	1894	,	-911	},
{	3355	,	1896	,	-910	},
{	3344	,	1903	,	-912	},
{	3331	,	1909	,	-913	},
{	3312	,	1912	,	-911	},
{	3295	,	1916	,	-911	},
{	3285	,	1925	,	-913	},
{	3261	,	1926	,	-912	},
{	3243	,	1931	,	-914	},
{	3227	,	1937	,	-914	},
{	3205	,	1939	,	-913	},
{	3187	,	1944	,	-913	},
{	3162	,	1945	,	-911	},
{	3151	,	1955	,	-913	},
{	3126	,	1956	,	-911	},
{	3106	,	1960	,	-910	},
{	3086	,	1964	,	-909	},
{	3073	,	1972	,	-912	},
{	3051	,	1975	,	-911	},
{	3038	,	1982	,	-912	},
{	3011	,	1980	,	-909	},
{	3002	,	1990	,	-912	},
{	2985	,	1994	,	-913	},
{	2964	,	1996	,	-911	},
{	2954	,	2003	,	-914	},
{	2934	,	2004	,	-913	},
{	2917	,	2007	,	-913	},
{	2901	,	2011	,	-913	},
{	2883	,	2013	,	-913	},
{	2873	,	2021	,	-915	},
{	2857	,	2024	,	-914	},
{	2850	,	2033	,	-916	},
{	2833	,	2034	,	-916	},
{	2820	,	2039	,	-917	},
{	2809	,	2044	,	-917	},
{	2804	,	2054	,	-921	},
{	2784	,	2052	,	-920	},
{	2772	,	2056	,	-920	},
{	2755	,	2057	,	-919	},
{	2741	,	2059	,	-919	},
{	2733	,	2065	,	-920	},
{	2712	,	2063	,	-918	},
{	2699	,	2067	,	-917	},
{	2691	,	2074	,	-919	},
{	2678	,	2076	,	-919	},
{	2663	,	2076	,	-918	},
{	2642	,	2074	,	-916	},
{	2624	,	2073	,	-915	},
{	2607	,	2074	,	-914	},
{	2591	,	2075	,	-914	},
{	2578	,	2077	,	-915	},
{	2561	,	2076	,	-914	},
{	2544	,	2077	,	-914	},
{	2528	,	2077	,	-914	},
{	2513	,	2078	,	-914	},
{	2502	,	2082	,	-915	},
{	2488	,	2083	,	-916	},
{	2470	,	2082	,	-916	},
{	2460	,	2086	,	-917	},
{	2450	,	2091	,	-920	},
{	2427	,	2085	,	-917	},
{	2418	,	2091	,	-919	},
{	2404	,	2093	,	-919	},
{	2395	,	2099	,	-921	},
{	2387	,	2107	,	-924	},
{	2373	,	2108	,	-925	},
{	2360	,	2111	,	-926	},
{	2350	,	2117	,	-928	},
{	2334	,	2118	,	-929	},
{	2323	,	2122	,	-930	},
{	2315	,	2130	,	-933	},
{	2309	,	2139	,	-937	},
{	2292	,	2138	,	-938	},
{	2279	,	2140	,	-939	},
{	2267	,	2143	,	-939	},
{	2255	,	2147	,	-940	},
{	2244	,	2152	,	-942	},
{	2230	,	2154	,	-944	},
{	2215	,	2155	,	-944	},
{	2203	,	2158	,	-946	},
{	2184	,	2156	,	-945	},
{	2170	,	2157	,	-945	},
{	2156	,	2159	,	-946	},
{	2145	,	2164	,	-948	},
{	2125	,	2160	,	-946	},
{	2113	,	2163	,	-948	},
{	2095	,	2160	,	-946	},
{	2078	,	2158	,	-944	},
{	2058	,	2152	,	-942	},
{	2048	,	2158	,	-943	},
{	2035	,	2160	,	-944	},
{	2023	,	2164	,	-946	},
{	2007	,	2162	,	-945	},
{	1990	,	2161	,	-944	},
{	1979	,	2165	,	-945	},
{	1966	,	2168	,	-947	},
{	1953	,	2172	,	-948	},
{	1943	,	2177	,	-950	},
{	1932	,	2182	,	-952	},
{	1922	,	2185	,	-955	},
{	1909	,	2186	,	-956	},
{	1897	,	2187	,	-958	},
{	1886	,	2189	,	-960	},
{	1873	,	2189	,	-962	},
{	1865	,	2195	,	-965	},
{	1855	,	2199	,	-967	},
{	1841	,	2199	,	-968	},
{	1826	,	2196	,	-968	},
{	1814	,	2197	,	-969	},
{	1804	,	2201	,	-973	},
{	1791	,	2201	,	-974	},
{	1784	,	2207	,	-978	},
{	1771	,	2207	,	-980	},
{	1761	,	2208	,	-982	},
{	1746	,	2207	,	-983	},
{	1731	,	2204	,	-982	},
{	1717	,	2203	,	-982	},
{	1704	,	2202	,	-982	},
{	1694	,	2204	,	-983	},
{	1680	,	2202	,	-982	},
{	1672	,	2207	,	-985	},
{	1661	,	2208	,	-987	},
{	1651	,	2209	,	-989	},
{	1640	,	2207	,	-990	},
{	1630	,	2207	,	-991	},
{	1620	,	2207	,	-993	},
{	1608	,	2204	,	-992	},
{	1602	,	2210	,	-996	},
{	1590	,	2206	,	-995	},
{	1579	,	2203	,	-994	},
{	1567	,	2198	,	-993	},
{	1558	,	2192	,	-992	},
{	1552	,	2191	,	-992	},
{	1544	,	2187	,	-991	},
{	1536	,	2182	,	-990	},
{	1531	,	2182	,	-991	},
{	1526	,	2181	,	-991	},
{	1517	,	2172	,	-988	},
{	1508	,	2165	,	-986	},
{	1503	,	2162	,	-985	},
{	1495	,	2158	,	-983	},
{	1493	,	2162	,	-985	},
{	1483	,	2154	,	-982	},
{	1476	,	2153	,	-982	},
{	1464	,	2146	,	-979	},
{	1452	,	2140	,	-977	},
{	1446	,	2142	,	-978	},
{	1440	,	2147	,	-980	},
{	1433	,	2152	,	-982	},
{	1421	,	2148	,	-982	},
{	1411	,	2148	,	-983	},
{	1401	,	2154	,	-986	},
{	1384	,	2149	,	-985	},
{	1373	,	2153	,	-987	},
{	1361	,	2158	,	-990	},
{	1344	,	2157	,	-990	},
{	1329	,	2158	,	-991	},
{	1313	,	2158	,	-992	},
{	1299	,	2161	,	-995	},
{	1286	,	2166	,	-998	},
{	1270	,	2166	,	-998	},
{	1255	,	2170	,	-1001	},
{	1244	,	2178	,	-1005	},
{	1227	,	2176	,	-1004	},
{	1212	,	2178	,	-1006	},
{	1195	,	2173	,	-1006	},
{	1180	,	2174	,	-1007	},
{	1167	,	2179	,	-1010	},
{	1154	,	2181	,	-1013	},
{	1143	,	2187	,	-1018	},
{	1125	,	2179	,	-1016	},
{	1110	,	2180	,	-1018	},
{	1096	,	2183	,	-1020	},
{	1080	,	2180	,	-1020	},
{	1067	,	2186	,	-1024	},
{	1050	,	2182	,	-1023	},
{	1033	,	2183	,	-1025	},
{	1021	,	2189	,	-1029	},
{	1004	,	2184	,	-1028	},
{	987	,	2182	,	-1028	},
{	970	,	2180	,	-1029	},
{	954	,	2180	,	-1030	},
{	939	,	2182	,	-1032	},
{	924	,	2185	,	-1034	},
{	909	,	2187	,	-1035	},
{	890	,	2181	,	-1034	},
{	875	,	2182	,	-1035	},
{	860	,	2184	,	-1037	},
{	845	,	2186	,	-1039	},
{	829	,	2185	,	-1040	},
{	814	,	2185	,	-1044	},
{	797	,	2182	,	-1044	},
{	780	,	2180	,	-1045	},
{	765	,	2180	,	-1048	},
{	747	,	2175	,	-1047	},
{	731	,	2174	,	-1049	},
{	716	,	2173	,	-1050	},
{	700	,	2174	,	-1054	},
{	683	,	2166	,	-1053	},
{	669	,	2168	,	-1056	},
{	652	,	2162	,	-1055	},
{	635	,	2159	,	-1057	},
{	622	,	2163	,	-1061	},
{	605	,	2159	,	-1061	},
{	590	,	2156	,	-1061	},
{	576	,	2153	,	-1063	},
{	561	,	2151	,	-1064	},
{	547	,	2152	,	-1065	},
{	533	,	2151	,	-1066	},
{	519	,	2148	,	-1067	},
{	503	,	2141	,	-1066	},
{	490	,	2140	,	-1067	},
{	478	,	2139	,	-1069	},
{	464	,	2134	,	-1070	},
{	452	,	2128	,	-1070	},
{	440	,	2126	,	-1072	},
{	426	,	2116	,	-1071	},
{	414	,	2115	,	-1075	},
{	401	,	2105	,	-1074	},
{	390	,	2098	,	-1074	},
{	379	,	2085	,	-1071	},
{	371	,	2082	,	-1073	},
{	362	,	2071	,	-1071	},
{	357	,	2058	,	-1067	},
{	352	,	2046	,	-1065	},
{	347	,	2040	,	-1064	},
{	344	,	2038	,	-1065	},
{	341	,	2032	,	-1064	},
{	338	,	2025	,	-1063	},
{	336	,	2019	,	-1064	},
{	334	,	2013	,	-1062	},
{	332	,	2006	,	-1060	},
{	331	,	1999	,	-1058	}
};

#endif	/* TABLE_LUGE7_SN113_H */

