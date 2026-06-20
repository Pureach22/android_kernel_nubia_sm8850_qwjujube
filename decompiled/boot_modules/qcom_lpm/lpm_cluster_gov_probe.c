__int64 __fastcall lpm_cluster_gov_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // x0
  __int64 v6; // x8
  unsigned int v7; // w0
  unsigned int v8; // w19
  _UNKNOWN **v10; // x0
  _QWORD *v11; // x1
  __int64 v12; // x8

  v1 = a1 + 16;
  v2 = *(_QWORD *)(a1 + 760);
  v3 = devm_kmalloc(a1 + 16, 416, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = (_QWORD *)v3;
  if ( (of_property_read_variable_u32_array(v2, "qcom,pred-prem-cnt", v3 + 32, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)v4 + 8) = 3;
  if ( (of_property_read_variable_u32_array(v2, "qcom,sample-invalid-time", (char *)v4 + 28, 1, 0) & 0x80000000) != 0 )
    *((_DWORD *)v4 + 7) = 40000;
  *((_BYTE *)v4 + 409) = of_find_property(v2, "qcom,use-cluster-bias-timer", 0) != 0;
  v5 = _devm_alloc_percpu(v1, 8, 8);
  v4[43] = v5;
  if ( !v5 )
    return 4294967284LL;
  *((_DWORD *)v4 + 100) = 0;
  v4[44] = 0x7FFFFFFFFFFFFFFFLL;
  *v4 = v1;
  v4[46] = 0;
  *((_BYTE *)v4 + 404) = 0;
  *((_DWORD *)v4 + 5) = -1;
  pm_runtime_enable(v1);
  hrtimer_init(v4 + 33, 1, 1);
  v6 = *(_QWORD *)(*v4 + 592LL);
  v4[26] = cluster_power_cb;
  *((_DWORD *)v4 + 56) = 0x7FFFFFFF;
  v4[20] = v6 - 912;
  *(_DWORD *)(v6 + 520) |= 0x40u;
  v7 = dev_pm_genpd_add_notifier(*v4, v4 + 26);
  if ( v7 )
  {
    v8 = v7;
    _pm_runtime_disable(v1, 1);
    return v8;
  }
  else if ( (unsigned int)create_cluster_sysfs_nodes(v4) )
  {
    _pm_runtime_disable(v1, 1);
    return 0;
  }
  else
  {
    v10 = (_UNKNOWN **)(v4 + 48);
    v11 = off_568;
    if ( v4 + 48 == &cluster_dev_list || off_568 == v10 || *off_568 != (_UNKNOWN *)&cluster_dev_list )
      goto LABEL_25;
    off_568 = (_UNKNOWN **)(v4 + 48);
    v4[48] = &cluster_dev_list;
    v4[49] = v11;
    *v11 = v10;
    while ( 1 )
    {
      v12 = v4[20];
      *((_BYTE *)v4 + 405) = 1;
      if ( !*(_DWORD *)(v12 + 1456) )
        break;
      *((_BYTE *)v4 + 376) = 1;
      if ( *(_DWORD *)(v12 + 1456) <= 1u )
        break;
      *((_BYTE *)v4 + 377) = 1;
      if ( *(_DWORD *)(v12 + 1456) < 3u )
        break;
      *((_BYTE *)v4 + 378) = 1;
      if ( *(_DWORD *)(v12 + 1456) < 4u )
        break;
      *((_BYTE *)v4 + 379) = 1;
      if ( *(_DWORD *)(v12 + 1456) <= 4u )
        break;
      __break(0x5512u);
LABEL_25:
      _list_add_valid_or_report();
    }
    if ( (lpm_cluster_gov_probe_gov_ops_registered & 1) == 0 )
    {
      register_cluster_governor_ops(&gov_ops);
      lpm_cluster_gov_probe_gov_ops_registered = 1;
    }
    return 0;
  }
}
