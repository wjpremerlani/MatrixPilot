

#ifndef TABLE_LUGE7_SN154_H
#define	TABLE_LUGE7_SN154_H

// used in LUGE7_SN154 partition size 64

#define STEP_SIZE 64

#define TABLE_ORIGIN  ( -14823 )

int16_t residual_offset[] = { 0 , 0 , 0 } ;


const struct gyro_offset_table_entry gyro_offset_table[] = {
{	-3080	,	4628	,	-5066	},
{	-3071	,	4620	,	-5060	},
{	-3062	,	4613	,	-5055	},
{	-3053	,	4605	,	-5048	},
{	-3042	,	4595	,	-5038	},
{	-3046	,	4606	,	-5053	},
{	-3041	,	4603	,	-5051	},
{	-3031	,	4595	,	-5043	},
{	-3026	,	4591	,	-5042	},
{	-3042	,	4625	,	-5084	},
{	-3026	,	4609	,	-5072	},
{	-3017	,	4606	,	-5072	},
{	-3007	,	4598	,	-5067	},
{	-2998	,	4592	,	-5066	},
{	-2993	,	4593	,	-5072	},
{	-2979	,	4579	,	-5062	},
{	-2974	,	4578	,	-5065	},
{	-2953	,	4551	,	-5042	},
{	-2941	,	4540	,	-5034	},
{	-2943	,	4549	,	-5049	},
{	-2933	,	4539	,	-5043	},
{	-2929	,	4541	,	-5050	},
{	-2918	,	4531	,	-5043	},
{	-2909	,	4522	,	-5039	},
{	-2904	,	4518	,	-5041	},
{	-2895	,	4515	,	-5042	},
{	-2882	,	4501	,	-5034	},
{	-2876	,	4500	,	-5036	},
{	-2868	,	4495	,	-5037	},
{	-2855	,	4484	,	-5030	},
{	-2846	,	4477	,	-5028	},
{	-2832	,	4463	,	-5017	},
{	-2827	,	4463	,	-5022	},
{	-2821	,	4460	,	-5026	},
{	-2813	,	4458	,	-5029	},
{	-2808	,	4456	,	-5034	},
{	-2796	,	4444	,	-5028	},
{	-2788	,	4440	,	-5029	},
{	-2776	,	4429	,	-5023	},
{	-2764	,	4418	,	-5017	},
{	-2754	,	4410	,	-5014	},
{	-2750	,	4413	,	-5024	},
{	-2741	,	4402	,	-5018	},
{	-2728	,	4387	,	-5006	},
{	-2722	,	4382	,	-5008	},
{	-2705	,	4362	,	-4989	},
{	-2704	,	4367	,	-5001	},
{	-2697	,	4363	,	-5001	},
{	-2684	,	4345	,	-4987	},
{	-2679	,	4343	,	-4992	},
{	-2666	,	4328	,	-4980	},
{	-2659	,	4323	,	-4980	},
{	-2651	,	4317	,	-4978	},
{	-2638	,	4301	,	-4967	},
{	-2635	,	4302	,	-4975	},
{	-2628	,	4296	,	-4975	},
{	-2615	,	4279	,	-4962	},
{	-2611	,	4276	,	-4966	},
{	-2600	,	4264	,	-4958	},
{	-2593	,	4260	,	-4960	},
{	-2586	,	4256	,	-4963	},
{	-2574	,	4244	,	-4956	},
{	-2572	,	4245	,	-4966	},
{	-2558	,	4231	,	-4955	},
{	-2545	,	4215	,	-4945	},
{	-2538	,	4211	,	-4947	},
{	-2530	,	4203	,	-4944	},
{	-2526	,	4204	,	-4951	},
{	-2512	,	4186	,	-4938	},
{	-2507	,	4183	,	-4940	},
{	-2500	,	4177	,	-4938	},
{	-2493	,	4170	,	-4938	},
{	-2486	,	4162	,	-4934	},
{	-2482	,	4161	,	-4940	},
{	-2471	,	4148	,	-4931	},
{	-2463	,	4139	,	-4926	},
{	-2455	,	4132	,	-4924	},
{	-2452	,	4131	,	-4930	},
{	-2446	,	4123	,	-4928	},
{	-2436	,	4113	,	-4923	},
{	-2428	,	4101	,	-4917	},
{	-2426	,	4101	,	-4924	},
{	-2422	,	4099	,	-4929	},
{	-2414	,	4089	,	-4924	},
{	-2401	,	4071	,	-4909	},
{	-2396	,	4068	,	-4912	},
{	-2391	,	4062	,	-4913	},
{	-2383	,	4053	,	-4910	},
{	-2374	,	4042	,	-4903	},
{	-2371	,	4041	,	-4910	},
{	-2364	,	4030	,	-4904	},
{	-2366	,	4036	,	-4921	},
{	-2362	,	4033	,	-4924	},
{	-2355	,	4023	,	-4919	},
{	-2347	,	4013	,	-4912	},
{	-2340	,	4002	,	-4904	},
{	-2335	,	3996	,	-4903	},
{	-2338	,	4004	,	-4919	},
{	-2329	,	3990	,	-4907	},
{	-2326	,	3985	,	-4908	},
{	-2322	,	3981	,	-4910	},
{	-2323	,	3984	,	-4920	},
{	-2320	,	3977	,	-4920	},
{	-2314	,	3968	,	-4916	},
{	-2314	,	3969	,	-4922	},
{	-2309	,	3960	,	-4917	},
{	-2302	,	3950	,	-4911	},
{	-2301	,	3949	,	-4916	},
{	-2289	,	3930	,	-4898	},
{	-2287	,	3926	,	-4899	},
{	-2285	,	3925	,	-4903	},
{	-2282	,	3920	,	-4903	},
{	-2280	,	3918	,	-4907	},
{	-2276	,	3911	,	-4906	},
{	-2267	,	3895	,	-4894	},
{	-2264	,	3890	,	-4894	},
{	-2255	,	3877	,	-4884	},
{	-2251	,	3870	,	-4882	},
{	-2243	,	3857	,	-4871	},
{	-2244	,	3858	,	-4878	},
{	-2236	,	3845	,	-4868	},
{	-2228	,	3833	,	-4858	},
{	-2230	,	3835	,	-4866	},
{	-2229	,	3834	,	-4869	},
{	-2224	,	3826	,	-4865	},
{	-2223	,	3825	,	-4868	},
{	-2217	,	3813	,	-4857	},
{	-2215	,	3806	,	-4854	},
{	-2210	,	3796	,	-4846	},
{	-2212	,	3796	,	-4851	},
{	-2214	,	3800	,	-4859	},
{	-2209	,	3789	,	-4849	},
{	-2214	,	3796	,	-4861	},
{	-2217	,	3799	,	-4866	},
{	-2210	,	3788	,	-4853	},
{	-2209	,	3785	,	-4851	},
{	-2206	,	3779	,	-4844	},
{	-2208	,	3782	,	-4848	},
{	-2210	,	3783	,	-4851	},
{	-2207	,	3777	,	-4845	},
{	-2206	,	3772	,	-4840	},
{	-2207	,	3770	,	-4838	},
{	-2210	,	3775	,	-4844	},
{	-2209	,	3773	,	-4842	},
{	-2205	,	3766	,	-4832	},
{	-2211	,	3775	,	-4844	},
{	-2206	,	3766	,	-4830	},
{	-2203	,	3756	,	-4817	},
{	-2211	,	3768	,	-4830	},
{	-2203	,	3754	,	-4812	},
{	-2205	,	3757	,	-4815	},
{	-2206	,	3756	,	-4813	},
{	-2213	,	3764	,	-4822	},
{	-2211	,	3760	,	-4817	},
{	-2211	,	3760	,	-4816	},
{	-2212	,	3759	,	-4813	},
{	-2209	,	3755	,	-4806	},
{	-2211	,	3756	,	-4806	},
{	-2214	,	3761	,	-4812	},
{	-2209	,	3752	,	-4798	},
{	-2212	,	3756	,	-4803	},
{	-2216	,	3761	,	-4809	},
{	-2213	,	3756	,	-4803	},
{	-2213	,	3756	,	-4802	},
{	-2212	,	3754	,	-4799	},
{	-2210	,	3750	,	-4794	},
{	-2215	,	3759	,	-4804	},
{	-2211	,	3751	,	-4794	},
{	-2220	,	3764	,	-4813	},
{	-2213	,	3751	,	-4799	},
{	-2218	,	3759	,	-4810	},
{	-2217	,	3753	,	-4806	},
{	-2220	,	3755	,	-4811	},
{	-2226	,	3762	,	-4824	},
{	-2230	,	3764	,	-4831	},
{	-2224	,	3752	,	-4817	},
{	-2229	,	3755	,	-4825	},
{	-2232	,	3754	,	-4829	},
{	-2231	,	3747	,	-4823	},
{	-2233	,	3744	,	-4823	},
{	-2237	,	3745	,	-4829	},
{	-2242	,	3750	,	-4838	},
{	-2247	,	3751	,	-4844	},
{	-2243	,	3740	,	-4834	},
{	-2248	,	3742	,	-4840	},
{	-2242	,	3727	,	-4824	},
{	-2245	,	3727	,	-4828	},
{	-2247	,	3726	,	-4828	},
{	-2247	,	3724	,	-4827	},
{	-2242	,	3713	,	-4815	},
{	-2241	,	3709	,	-4811	},
{	-2234	,	3694	,	-4794	},
{	-2238	,	3697	,	-4800	},
{	-2239	,	3696	,	-4801	},
{	-2239	,	3692	,	-4799	},
{	-2244	,	3699	,	-4810	},
{	-2241	,	3692	,	-4805	},
{	-2242	,	3692	,	-4806	},
{	-2241	,	3686	,	-4804	},
{	-2240	,	3682	,	-4801	},
{	-2240	,	3680	,	-4801	},
{	-2240	,	3677	,	-4801	},
{	-2241	,	3676	,	-4803	},
{	-2244	,	3677	,	-4808	},
{	-2239	,	3664	,	-4796	},
{	-2244	,	3670	,	-4808	},
{	-2247	,	3669	,	-4811	},
{	-2245	,	3663	,	-4807	},
{	-2250	,	3668	,	-4818	},
{	-2256	,	3672	,	-4829	},
{	-2252	,	3664	,	-4823	},
{	-2247	,	3652	,	-4812	},
{	-2246	,	3648	,	-4810	},
{	-2246	,	3645	,	-4809	},
{	-2244	,	3639	,	-4806	},
{	-2245	,	3636	,	-4806	},
{	-2240	,	3626	,	-4798	},
{	-2244	,	3630	,	-4806	},
{	-2242	,	3623	,	-4802	},
{	-2240	,	3617	,	-4797	},
{	-2238	,	3610	,	-4792	},
{	-2239	,	3609	,	-4795	},
{	-2239	,	3605	,	-4794	},
{	-2235	,	3597	,	-4787	},
{	-2237	,	3599	,	-4792	},
{	-2236	,	3592	,	-4787	},
{	-2230	,	3578	,	-4773	},
{	-2236	,	3585	,	-4784	},
{	-2238	,	3585	,	-4790	},
{	-2235	,	3576	,	-4782	},
{	-2236	,	3573	,	-4783	},
{	-2236	,	3569	,	-4782	},
{	-2231	,	3558	,	-4772	},
{	-2233	,	3554	,	-4773	},
{	-2237	,	3555	,	-4780	},
{	-2237	,	3550	,	-4778	},
{	-2236	,	3544	,	-4776	},
{	-2236	,	3539	,	-4775	},
{	-2233	,	3531	,	-4768	},
{	-2227	,	3515	,	-4753	},
{	-2233	,	3517	,	-4762	},
{	-2231	,	3505	,	-4754	},
{	-2231	,	3499	,	-4751	},
{	-2234	,	3497	,	-4755	},
{	-2234	,	3489	,	-4751	},
{	-2236	,	3484	,	-4750	},
{	-2240	,	3481	,	-4753	},
{	-2238	,	3470	,	-4745	},
{	-2241	,	3467	,	-4746	},
{	-2245	,	3466	,	-4751	},
{	-2247	,	3460	,	-4750	},
{	-2242	,	3444	,	-4736	},
{	-2247	,	3445	,	-4744	},
{	-2252	,	3445	,	-4752	},
{	-2252	,	3437	,	-4748	},
{	-2256	,	3434	,	-4751	},
{	-2261	,	3436	,	-4760	},
{	-2261	,	3426	,	-4755	},
{	-2261	,	3419	,	-4751	},
{	-2266	,	3416	,	-4755	},
{	-2274	,	3419	,	-4769	},
{	-2277	,	3413	,	-4769	},
{	-2278	,	3406	,	-4768	},
{	-2279	,	3398	,	-4766	},
{	-2284	,	3399	,	-4773	},
{	-2286	,	3393	,	-4775	},
{	-2288	,	3388	,	-4776	},
{	-2290	,	3383	,	-4776	},
{	-2292	,	3379	,	-4776	},
{	-2290	,	3368	,	-4768	},
{	-2292	,	3364	,	-4769	},
{	-2301	,	3370	,	-4783	},
{	-2302	,	3365	,	-4783	},
{	-2306	,	3364	,	-4788	},
{	-2305	,	3357	,	-4784	},
{	-2311	,	3359	,	-4793	},
{	-2311	,	3353	,	-4791	},
{	-2308	,	3344	,	-4781	},
{	-2307	,	3338	,	-4777	},
{	-2305	,	3331	,	-4773	},
{	-2307	,	3327	,	-4771	},
{	-2305	,	3318	,	-4766	},
{	-2305	,	3311	,	-4761	},
{	-2304	,	3304	,	-4756	},
{	-2311	,	3306	,	-4765	},
{	-2316	,	3305	,	-4770	},
{	-2324	,	3308	,	-4780	},
{	-2323	,	3297	,	-4772	},
{	-2324	,	3290	,	-4767	},
{	-2325	,	3282	,	-4763	},
{	-2326	,	3273	,	-4758	},
{	-2331	,	3272	,	-4762	},
{	-2338	,	3273	,	-4771	},
{	-2345	,	3274	,	-4779	},
{	-2348	,	3269	,	-4780	},
{	-2346	,	3258	,	-4770	},
{	-2356	,	3262	,	-4783	},
{	-2357	,	3256	,	-4781	},
{	-2367	,	3261	,	-4794	},
{	-2366	,	3252	,	-4789	},
{	-2373	,	3253	,	-4796	},
{	-2372	,	3246	,	-4792	},
{	-2371	,	3237	,	-4786	},
{	-2373	,	3233	,	-4786	},
{	-2377	,	3231	,	-4791	},
{	-2377	,	3224	,	-4788	},
{	-2381	,	3223	,	-4793	},
{	-2380	,	3216	,	-4789	},
{	-2383	,	3214	,	-4793	},
{	-2373	,	3195	,	-4772	},
{	-2370	,	3186	,	-4765	},
{	-2371	,	3183	,	-4766	},
{	-2374	,	3183	,	-4771	},
{	-2367	,	3170	,	-4758	},
{	-2367	,	3165	,	-4759	},
{	-2360	,	3152	,	-4746	},
{	-2360	,	3149	,	-4748	},
{	-2356	,	3140	,	-4741	},
{	-2352	,	3129	,	-4732	},
{	-2356	,	3129	,	-4739	},
{	-2349	,	3116	,	-4727	},
{	-2347	,	3108	,	-4721	},
{	-2350	,	3107	,	-4725	},
{	-2353	,	3105	,	-4729	},
{	-2350	,	3098	,	-4724	},
{	-2346	,	3087	,	-4716	},
{	-2353	,	3090	,	-4727	},
{	-2347	,	3077	,	-4714	},
{	-2346	,	3069	,	-4709	},
{	-2345	,	3063	,	-4706	},
{	-2348	,	3060	,	-4707	},
{	-2352	,	3060	,	-4713	},
{	-2359	,	3062	,	-4722	},
{	-2361	,	3056	,	-4720	},
{	-2369	,	3060	,	-4730	},
{	-2371	,	3055	,	-4728	},
{	-2371	,	3049	,	-4723	},
{	-2374	,	3047	,	-4724	},
{	-2378	,	3045	,	-4726	},
{	-2374	,	3034	,	-4715	},
{	-2375	,	3029	,	-4712	},
{	-2380	,	3029	,	-4716	},
{	-2385	,	3027	,	-4718	},
{	-2387	,	3023	,	-4716	},
{	-2391	,	3020	,	-4717	},
{	-2392	,	3013	,	-4713	},
{	-2400	,	3014	,	-4720	},
{	-2402	,	3008	,	-4718	},
{	-2406	,	3005	,	-4717	},
{	-2407	,	2998	,	-4712	},
{	-2411	,	2999	,	-4716	},
{	-2409	,	2992	,	-4707	},
{	-2412	,	2994	,	-4712	},
{	-2412	,	2989	,	-4708	},
{	-2416	,	2990	,	-4713	},
{	-2416	,	2985	,	-4709	},
{	-2424	,	2989	,	-4719	},
{	-2424	,	2985	,	-4714	}
};

#endif	/* TABLE_LUGE7_SN154_H */
