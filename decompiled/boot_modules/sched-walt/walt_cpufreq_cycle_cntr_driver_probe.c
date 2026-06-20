__int64 __fastcall walt_cpufreq_cycle_cntr_driver_probe(__int64 a1)
{
  __int64 v1; // x26
  unsigned int v3; // w9
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0
  unsigned int v7; // w22
  __int64 resource; // x0
  const void *v9; // x24
  __int64 v10; // x0
  __int64 v11; // x23
  unsigned int *match_data; // x0
  __int64 v13; // x8
  __int64 *v14; // x8
  char v15; // w13
  int v16; // w9
  unsigned __int64 v17; // x13
  unsigned __int64 v18; // x13
  char *v19; // x14
  bool v20; // cf
  __int64 v21; // [xsp+8h] [xbp-58h] BYREF
  __int64 v22; // [xsp+10h] [xbp-50h]
  __int64 v23; // [xsp+18h] [xbp-48h]
  __int64 v24; // [xsp+20h] [xbp-40h]
  __int64 v25; // [xsp+28h] [xbp-38h]
  __int64 v26; // [xsp+30h] [xbp-30h]
  __int64 v27; // [xsp+38h] [xbp-28h]
  __int64 v28; // [xsp+40h] [xbp-20h]
  __int64 v29; // [xsp+48h] [xbp-18h]
  __int64 v30; // [xsp+50h] [xbp-10h]
  __int64 v31; // [xsp+58h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v1 = cluster_head;
  if ( (__int64 *)cluster_head == &cluster_head )
  {
    result = 4294967277LL;
LABEL_15:
    if ( !walt_get_cycle_counts_cb )
    {
      v15 = 0;
      v16 = _cpu_possible_mask;
      do
      {
        v17 = (unsigned int)(-1LL << v15) & v16;
        if ( !(_DWORD)v17 )
          break;
        v18 = __clz(__rbit64(v17));
        if ( ((16 * v18) | 0xC) > 0x200 )
          goto LABEL_28;
        v19 = (char *)&walt_cpufreq_counter + 16 * v18;
        v20 = v18 >= 0x1F;
        v15 = v18 + 1;
        *((_DWORD *)v19 + 3) = 0;
      }
      while ( !v20 );
      walt_get_cycle_counts_cb = walt_cpufreq_get_cpu_cycle_counter;
      use_cycle_counter = 1;
      complete(&walt_get_cycle_counts_cb_completion);
      result = 0;
    }
  }
  else
  {
    while ( 1 )
    {
      v3 = __clz(__rbit64(*(unsigned int *)(v1 + 16)));
      if ( *(_DWORD *)(v1 + 16) )
        v4 = v3;
      else
        v4 = 32;
      v5 = of_cpu_device_node_get(v4);
      if ( !v5 )
      {
        result = 4294967274LL;
        goto LABEL_23;
      }
      result = _of_parse_phandle_with_args(v5, "qcom,freq-domain", "#freq-domain-cells", 0xFFFFFFFFLL, 0, &v21);
      if ( (_DWORD)result )
        goto LABEL_23;
      v7 = HIDWORD(v22);
      resource = platform_get_resource(a1, 512, HIDWORD(v22));
      if ( !resource )
      {
        dev_err(a1 + 16, "failed to get mem resource %d\n", v7);
        goto LABEL_27;
      }
      v9 = (const void *)resource;
      v10 = devm_ioremap(a1 + 16);
      if ( !v10 )
      {
        dev_err(a1 + 16, "failed to map resource %pR\n", v9);
        result = 4294967284LL;
        goto LABEL_23;
      }
      v11 = v10;
      match_data = (unsigned int *)of_device_get_match_data(a1 + 16);
      v13 = *(unsigned int *)(v1 + 24);
      if ( (unsigned int)v13 > 3 )
        goto LABEL_29;
      if ( ((16 * v13) | 8uLL) > 0x40 )
      {
LABEL_28:
        __break(1u);
LABEL_29:
        __break(0x5512u);
      }
      v14 = (__int64 *)((char *)&cpufreq_data + 16 * v13);
      *v14 = v11;
      v14[1] = (__int64)match_data;
      if ( (readl_relaxed((unsigned int *)(v11 + *match_data)) & 1) == 0 )
        break;
      v1 = *(_QWORD *)v1;
      if ( (__int64 *)v1 == &cluster_head )
      {
        result = 0;
        goto LABEL_15;
      }
    }
    dev_err(a1 + 16, "Domain-%d cpufreq hardware not enabled\n", v7);
LABEL_27:
    result = 4294967277LL;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
