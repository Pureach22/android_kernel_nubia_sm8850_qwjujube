__int64 freq_qos_request_init()
{
  char v0; // w8
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned int v5; // w0
  __int64 result; // x0
  void *v7; // x8
  unsigned int v8; // w20
  char v9; // w8
  unsigned int v10; // w26
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x27
  __int64 v13; // x9
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x10

  v0 = 0;
  while ( 1 )
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_present_mask;
    if ( !(_DWORD)v1 )
      return 0;
    v2 = __clz(__rbit64(v1));
    v3 = cpufreq_cpu_get((unsigned int)v2);
    if ( !v3 )
    {
      printk(&unk_BA3C, "freq_qos_request_init", (unsigned int)v2);
      result = 4294967285LL;
      goto LABEL_13;
    }
    v4 = v3;
    *(_DWORD *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[v2]) = 0;
    v5 = freq_qos_add_request(v3 + 144, (char *)&qos_req_min + _per_cpu_offset[v2], 1, 0);
    if ( (v5 & 0x80000000) != 0 )
    {
      v7 = &unk_BCC6;
      goto LABEL_12;
    }
    *(_DWORD *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[v2] + 4) = 0x7FFFFFFF;
    v5 = freq_qos_add_request(v4 + 144, (char *)&qos_req_max + _per_cpu_offset[v2], 2, 0x7FFFFFFF);
    if ( (v5 & 0x80000000) != 0 )
      break;
    cpufreq_cpu_put(v4);
    v0 = v2 + 1;
    if ( v2 > 0x1E )
      return 0;
  }
  v7 = &unk_BB09;
LABEL_12:
  v8 = v5;
  printk(v7, "freq_qos_request_init", v5);
  cpufreq_cpu_put(v4);
  result = v8;
LABEL_13:
  v9 = 0;
  v10 = result;
  do
  {
    v11 = (unsigned int)(-1LL << v9) & _cpu_present_mask;
    if ( !(_DWORD)v11 )
      break;
    v12 = __clz(__rbit64(v11));
    v13 = _per_cpu_offset[v12];
    if ( (char *)&qos_req_min + v13 )
    {
      v14 = *(_QWORD *)((char *)&qos_req_min + v13 + 48);
      if ( v14 )
      {
        if ( v14 <= 0xFFFFFFFFFFFFF000LL )
        {
          freq_qos_remove_request((char *)&qos_req_min + v13);
          v13 = _per_cpu_offset[v12];
          result = v10;
        }
      }
    }
    if ( (char *)&qos_req_max + v13 )
    {
      v15 = *(_QWORD *)((char *)&qos_req_max + v13 + 48);
      if ( v15 )
      {
        if ( v15 <= 0xFFFFFFFFFFFFF000LL )
        {
          freq_qos_remove_request((char *)&qos_req_max + v13);
          v13 = _per_cpu_offset[v12];
          result = v10;
        }
      }
    }
    *(_DWORD *)((char *)&msm_perf_cpu_stats + v13) = 0;
    *(_DWORD *)((char *)&msm_perf_cpu_stats + _per_cpu_offset[v12] + 4) = 0x7FFFFFFF;
    v9 = v12 + 1;
  }
  while ( v12 < 0x1F );
  return result;
}
