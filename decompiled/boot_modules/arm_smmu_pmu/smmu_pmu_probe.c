__int64 __fastcall smmu_pmu_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x20
  _QWORD *resource; // x21
  __int64 v6; // x0
  __int64 v7; // x22
  const void *v8; // x23
  __int64 v9; // x0
  __int64 v10; // x24
  __int64 v11; // x3
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned int v14; // w0
  __int64 v15; // x0
  int v16; // w8
  int v17; // w9
  __int64 v18; // x0
  unsigned int v19; // w0
  int v20; // w8
  __int64 v21; // x0
  unsigned int v22; // w8
  bool v23; // zf
  unsigned __int64 v24; // x8
  char v25; // w9
  unsigned int v26; // w0
  int v27; // w0
  unsigned int i; // w22
  unsigned int irq; // w0
  unsigned int v30; // w25
  unsigned int v31; // w0
  unsigned int v32; // w8
  unsigned int v33; // w22
  unsigned int v34; // w20
  unsigned int v35; // w21
  _QWORD v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36[0] = 0;
  v2 = devm_kmalloc(a1 + 16, 2536, 3520);
  if ( !v2 )
  {
    result = 4294967284LL;
    goto LABEL_3;
  }
  v4 = v2;
  *(_QWORD *)(v2 + 2192) = &smmu_pmu_attr_grps;
  *(_DWORD *)(v2 + 2252) = -1;
  *(_QWORD *)(v2 + 2264) = smmu_pmu_enable;
  *(_QWORD *)(v2 + 2272) = smmu_pmu_disable;
  *(_QWORD *)(v2 + 2280) = smmu_pmu_event_init;
  *(_QWORD *)(v2 + 2304) = smmu_pmu_event_add;
  *(_QWORD *)(v2 + 2312) = smmu_pmu_event_del;
  *(_QWORD *)(v2 + 2320) = smmu_pmu_event_start;
  *(_QWORD *)(v2 + 2328) = smmu_pmu_event_stop;
  *(_QWORD *)(a1 + 168) = v2;
  *(_QWORD *)(v2 + 2152) = 0;
  *(_QWORD *)(v2 + 2160) = 0;
  *(_QWORD *)(v2 + 2168) = 0;
  *(_QWORD *)(v2 + 2176) = 0;
  *(_QWORD *)(v2 + 2184) = 0;
  *(_QWORD *)(v2 + 2200) = 0;
  *(_QWORD *)(v2 + 2208) = 0;
  *(_QWORD *)(v2 + 2216) = 0;
  *(_QWORD *)(v2 + 2224) = 0;
  *(_QWORD *)(v2 + 2232) = 0;
  *(_QWORD *)(v2 + 2240) = 0;
  *(_DWORD *)(v2 + 2248) = 0;
  *(_QWORD *)(v2 + 2288) = 0;
  *(_QWORD *)(v2 + 2296) = 0;
  *(_QWORD *)(v2 + 2344) = 0;
  *(_QWORD *)(v2 + 2352) = 0;
  *(_QWORD *)(v2 + 2360) = 0;
  *(_QWORD *)(v2 + 2368) = 0;
  *(_QWORD *)(v2 + 2376) = 0;
  *(_QWORD *)(v2 + 2384) = 0;
  *(_QWORD *)(v2 + 2392) = 0;
  *(_QWORD *)(v2 + 2400) = 0;
  *(_QWORD *)(v2 + 2408) = 0;
  *(_QWORD *)(v2 + 2416) = 0;
  *(_QWORD *)(v2 + 2424) = 0;
  *(_QWORD *)(v2 + 2432) = 0;
  *(_QWORD *)(v2 + 2440) = 0;
  *(_QWORD *)(v2 + 2448) = 0;
  *(_QWORD *)(v2 + 2456) = 0;
  *(_QWORD *)(v2 + 2256) = 0;
  *(_QWORD *)(v2 + 2336) = smmu_pmu_event_read;
  resource = (_QWORD *)platform_get_resource(a1, 512, 0);
  v6 = devm_ioremap(a1 + 16);
  if ( !v6 )
  {
    dev_err(a1 + 16, "Can't map SMMU PMU @%pa\n", resource);
LABEL_8:
    result = 0;
    goto LABEL_3;
  }
  v7 = v6;
  v8 = (const void *)platform_get_resource(a1, 512, 1);
  v9 = devm_ioremap(a1 + 16);
  if ( !v9 )
  {
    dev_err(a1 + 16, "Can't map SMMU PMU TCU NS @%pa\n", v8);
    goto LABEL_8;
  }
  v10 = v9;
  dev_err(a1 + 16, "SMMU PMU TCU NS @%pa\n", v8);
  *(_QWORD *)(v4 + 2488) = v7;
  *(_QWORD *)(v4 + 2480) = v7 + 4096;
  *(_QWORD *)(v4 + 2496) = v10;
  v11 = *resource >> 12;
  *(_QWORD *)(v4 + 2504) = *resource;
  v12 = devm_kasprintf(a1 + 16, 3264, "smmu_0_%llx", v11);
  v13 = *(_QWORD *)(v4 + 2480);
  *(_QWORD *)(v4 + 2208) = v12;
  LODWORD(v36[0]) = readl_relaxed(v13 + 3616);
  bitmap_from_arr32(v4 + 2096, v36, 32);
  v14 = platform_irq_count(a1);
  *(_DWORD *)(v4 + 2128) = v14;
  v15 = devm_kmalloc(a1 + 16, 4LL * v14, 3520);
  v16 = *(_DWORD *)(v4 + 2128);
  *(_QWORD *)(v4 + 2136) = v15;
  if ( v16 )
  {
    for ( i = 0; i < v32; ++i )
    {
      irq = platform_get_irq(a1, i);
      if ( (irq & 0x80000000) != 0 )
      {
        dev_err(a1 + 16, "failed to get irq index %d\n", i);
        result = 4294967277LL;
        goto LABEL_3;
      }
      v30 = irq;
      v31 = devm_request_threaded_irq(a1 + 16, irq, smmu_pmu_handle_irq, 0, 65664, "smmu-pmu", v4);
      if ( v31 )
      {
        v34 = v31;
        dev_err(a1 + 16, "Unable to request IRQ %d\n", v30);
        goto LABEL_30;
      }
      *(_DWORD *)(*(_QWORD *)(v4 + 2136) + 4LL * (int)i) = v30;
      v32 = *(_DWORD *)(v4 + 2128);
    }
    *(_DWORD *)(v4 + 2144) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
    if ( v32 )
    {
      v33 = 0;
      do
      {
        if ( (unsigned int)_irq_apply_affinity_hint(
                             *(unsigned int *)(*(_QWORD *)(v4 + 2136) + 4LL * (int)v33),
                             (char *)&cpu_bit_bitmap
                           + 8 * (*(_DWORD *)(v4 + 2144) & 0x3FLL)
                           - (((unsigned __int64)*(unsigned int *)(v4 + 2144) >> 3) & 0x1FFFFFF8)
                           + 8,
                             1) )
          __break(0x800u);
        ++v33;
      }
      while ( v33 < *(_DWORD *)(v4 + 2128) );
    }
  }
  else
  {
    *(_DWORD *)(v4 + 2144) = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
  }
  v17 = (unsigned __int8)readl_relaxed(*(_QWORD *)(v4 + 2480) + 3584LL) + 1;
  v18 = *(_QWORD *)(v4 + 2480) + 3584LL;
  *(_DWORD *)(v4 + 2464) = v17;
  v19 = readl_relaxed(v18);
  v20 = *(_DWORD *)(v4 + 2464);
  *(_QWORD *)(v4 + 2472) = a1;
  *(_DWORD *)(v4 + 2468) = HIBYTE(v19) + 1;
  v21 = *(_QWORD *)(v4 + 2480) + 3584LL;
  *(_QWORD *)(v4 + 2512) = 0xFFFFFFFFFFFFFFFFLL >> -(char)v20;
  v22 = ((unsigned int)readl_relaxed(v21) >> 8) & 0x3F;
  v23 = v22 == 31;
  v24 = 0xFFFFFFFFFFFFFFFFLL >> (v22 ^ 0x3F);
  v25 = v23;
  *(_BYTE *)(v4 + 2528) = v25;
  *(_QWORD *)(v4 + 2520) = v24;
  smmu_pmu_reset(v4);
  v26 = _cpuhp_state_add_instance((unsigned int)cpuhp_state_num, v4, 0);
  if ( !v26 )
  {
    v27 = perf_pmu_register(v4 + 2152, *(_QWORD *)(v4 + 2208), 0xFFFFFFFFLL);
    if ( v27 )
    {
      v35 = v27;
      dev_err(a1 + 16, "Error %d registering SMMU PMU\n", v27);
      _cpuhp_state_remove_instance((unsigned int)cpuhp_state_num, v4, 0);
      result = v35;
      goto LABEL_3;
    }
    dev_info(
      a1 + 16,
      "Registered SMMU PMU @ %pa using %d counters %d counter groups\n",
      resource,
      *(_DWORD *)(v4 + 2464),
      *(_DWORD *)(v4 + 2468));
    goto LABEL_8;
  }
  v34 = v26;
  dev_err(a1 + 16, "Error %d registering hotplug\n", v26);
LABEL_30:
  result = v34;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
