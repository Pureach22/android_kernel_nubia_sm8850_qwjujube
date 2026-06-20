__int64 __fastcall msm_vidc_pools_init(__int64 a1)
{
  __int64 v2; // x9

  *(_DWORD *)(a1 + 2168) = 296;
  *(_QWORD *)(a1 + 2176) = "MSM_MEM_POOL_BUFFER";
  *(_QWORD *)(a1 + 2184) = a1 + 2184;
  *(_QWORD *)(a1 + 2192) = a1 + 2184;
  *(_QWORD *)(a1 + 2200) = a1 + 2200;
  *(_QWORD *)(a1 + 2208) = a1 + 2200;
  *(_DWORD *)(a1 + 2216) = 120;
  *(_QWORD *)(a1 + 2224) = "MSM_MEM_POOL_ALLOC_MAP";
  *(_QWORD *)(a1 + 2232) = a1 + 2232;
  *(_QWORD *)(a1 + 2240) = a1 + 2232;
  *(_QWORD *)(a1 + 2248) = a1 + 2248;
  *(_QWORD *)(a1 + 2256) = a1 + 2248;
  *(_QWORD *)(a1 + 2272) = "MSM_MEM_POOL_TIMESTAMP";
  *(_DWORD *)(a1 + 2264) = 32;
  *(_QWORD *)(a1 + 2280) = a1 + 2280;
  *(_QWORD *)(a1 + 2288) = a1 + 2280;
  *(_QWORD *)(a1 + 2296) = a1 + 2296;
  *(_QWORD *)(a1 + 2304) = a1 + 2296;
  *(_DWORD *)(a1 + 2312) = 32;
  *(_QWORD *)(a1 + 2320) = "MSM_MEM_POOL_DMABUF";
  *(_QWORD *)(a1 + 2328) = a1 + 2328;
  *(_QWORD *)(a1 + 2336) = a1 + 2328;
  *(_QWORD *)(a1 + 2344) = a1 + 2344;
  *(_QWORD *)(a1 + 2352) = a1 + 2344;
  *(_DWORD *)(a1 + 2360) = 1048;
  *(_QWORD *)(a1 + 2368) = "MSM_MEM_POOL_PACKET";
  *(_QWORD *)(a1 + 2376) = a1 + 2376;
  *(_QWORD *)(a1 + 2384) = a1 + 2376;
  *(_QWORD *)(a1 + 2392) = a1 + 2392;
  *(_QWORD *)(a1 + 2400) = a1 + 2392;
  *(_DWORD *)(a1 + 2408) = 24;
  *(_QWORD *)(a1 + 2416) = "MSM_MEM_POOL_BUF_TIMER";
  *(_QWORD *)(a1 + 2424) = a1 + 2424;
  *(_QWORD *)(a1 + 2432) = a1 + 2424;
  *(_QWORD *)(a1 + 2440) = a1 + 2440;
  *(_QWORD *)(a1 + 2448) = a1 + 2440;
  *(_DWORD *)(a1 + 2456) = 64;
  *(_QWORD *)(a1 + 2464) = "MSM_MEM_POOL_BUF_STATS";
  *(_QWORD *)(a1 + 2472) = a1 + 2472;
  *(_QWORD *)(a1 + 2480) = a1 + 2472;
  v2 = a1 + 2488;
  *(_QWORD *)(a1 + 2488) = a1 + 2488;
  *(_QWORD *)(a1 + 2496) = v2;
  return 0;
}
