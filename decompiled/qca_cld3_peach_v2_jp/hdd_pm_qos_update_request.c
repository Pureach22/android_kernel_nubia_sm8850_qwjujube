__int64 __fastcall hdd_pm_qos_update_request(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w20
  bool v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  char v15; // w8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x25
  const char *v18; // x2
  __int64 v19; // x4
  __int64 v20; // x5
  __int64 v21; // x6
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x26
  char v24; // w8
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x25

  if ( qdf_cpumask_empty(a2) )
    v4 = 2000000000;
  else
    v4 = 1;
  qdf_cpumask_copy((_QWORD *)(a1 + 6768), a2);
  v5 = qdf_cpumask_empty(a2);
  v14 = a1 + 4208;
  v15 = 0;
  if ( v5 )
  {
    do
    {
      v16 = (unsigned int)(-1LL << v15) & _cpu_present_mask;
      if ( !(_DWORD)v16 )
        break;
      v17 = __clz(__rbit64(v16));
      dev_pm_qos_update_request(v14 + 80LL * (unsigned int)v17, 2000000000);
      v15 = v17 + 1;
    }
    while ( v17 < 0x1F );
    v18 = "%s: Empty mask %*pb: Set latency %u";
    v19 = nr_cpu_ids;
    v20 = a1 + 6768;
    v21 = 2000000000;
  }
  else
  {
    do
    {
      v22 = (unsigned int)(-1LL << v15) & _cpu_possible_mask & ~*(_QWORD *)(a1 + 6768);
      if ( !v22 )
        break;
      v23 = __clz(__rbit64(v22));
      dev_pm_qos_update_request(v14 + 80LL * (unsigned int)v23, 2000000000);
      v15 = v23 + 1;
    }
    while ( v23 < 0x1F );
    v24 = 0;
    do
    {
      v25 = (unsigned int)(-1LL << v24) & *(_DWORD *)(a1 + 6768);
      if ( !(_DWORD)v25 )
        break;
      v26 = __clz(__rbit64(v25));
      dev_pm_qos_update_request(v14 + 80LL * (unsigned int)v26, v4);
      v24 = v26 + 1;
    }
    while ( v26 < 0x1F );
    v18 = "%s: For qos_cpu_mask %*pb set latency %u";
    v19 = nr_cpu_ids;
    v20 = a1 + 6768;
    v21 = v4;
  }
  return qdf_trace_msg(0x33u, 8u, v18, v6, v7, v8, v9, v10, v11, v12, v13, "_hdd_pm_qos_update_request", v19, v20, v21);
}
