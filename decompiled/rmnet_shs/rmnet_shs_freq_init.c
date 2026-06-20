__int64 rmnet_shs_freq_init()
{
  char v0; // w8
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x19
  __int64 v3; // x27
  __int64 v4; // x0
  unsigned int v5; // w0
  __int64 v6; // x27
  __int64 v7; // x0
  char v8; // w8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  __int64 v11; // x12
  bool v12; // cf
  char v13; // w10
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x10
  __int64 v16; // x12
  bool v17; // cc
  char v19; // w12
  unsigned __int64 v20; // x12
  unsigned __int64 v21; // x12
  __int64 v22; // x14
  char v23; // w12
  unsigned __int64 v24; // x12
  unsigned __int64 v25; // x12
  __int64 v26; // x14
  void *v27; // x0
  void *v28; // x8
  unsigned int v29; // w19

  shs_cpu_boosts_0 = pcpu_alloc_noprof(8, 4, 0, 3264);
  if ( !shs_cpu_boosts_0 )
    return 4294967284LL;
  shs_pb_cpu_boosts_0 = pcpu_alloc_noprof(8, 4, 0, 3264);
  if ( !shs_pb_cpu_boosts_0 )
  {
    free_percpu(shs_cpu_boosts_0);
    return 4294967284LL;
  }
  if ( !shs_boost_wq )
  {
    shs_boost_wq = alloc_workqueue("shs_boost_wq", 16, 0);
    if ( !shs_boost_wq )
    {
      v19 = 0;
      do
      {
        v20 = (unsigned int)(-1LL << v19) & _cpu_possible_mask;
        if ( !(_DWORD)v20 )
          break;
        v21 = __clz(__rbit64(v20));
        v22 = _per_cpu_offset[v21];
        v12 = v21 >= 0x1F;
        v19 = v21 + 1;
        *(_QWORD *)(v22 + shs_cpu_boosts_0) = 0x7FFFFFFF00000000LL;
      }
      while ( !v12 );
      v23 = 0;
      do
      {
        v24 = (unsigned int)(-1LL << v23) & _cpu_possible_mask;
        if ( !(_DWORD)v24 )
          break;
        v25 = __clz(__rbit64(v24));
        v26 = _per_cpu_offset[v25];
        v12 = v25 >= 0x1F;
        v23 = v25 + 1;
        *(_QWORD *)(v26 + shs_pb_cpu_boosts_0) = 0x7FFFFFFF00000000LL;
      }
      while ( !v12 );
      free_percpu(shs_cpu_boosts_0);
      free_percpu(shs_pb_cpu_boosts_0);
      if ( shs_boost_wq )
      {
        destroy_workqueue();
        shs_boost_wq = 0;
      }
      return 4294967284LL;
    }
  }
  v0 = 0;
  while ( 1 )
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
    {
LABEL_12:
      boost_cpu = 0xFFFFFFFE00000LL;
      v8 = 0;
      qword_15D90 = (__int64)&qword_15D90;
      qword_15D98 = (__int64)&qword_15D90;
      qword_15DA0 = (__int64)shs_update_cpu_policy;
      pb_boost_worker = 0xFFFFFFFE00000LL;
      qword_15DB8 = (__int64)&qword_15DB8;
      qword_15DC0 = (__int64)&qword_15DB8;
      qword_15DC8 = (__int64)shs_update_pb_cpu_policy;
      do
      {
        v9 = (unsigned int)(-1LL << v8) & _cpu_possible_mask;
        if ( !(_DWORD)v9 )
          break;
        v10 = __clz(__rbit64(v9));
        v11 = _per_cpu_offset[v10];
        v12 = v10 >= 0x1F;
        v8 = v10 + 1;
        *(_QWORD *)(v11 + shs_cpu_boosts_0) = 0x7FFFFFFF00000000LL;
      }
      while ( !v12 );
      v13 = 0;
      do
      {
        v14 = (unsigned int)(-1LL << v13) & _cpu_possible_mask;
        if ( !(_DWORD)v14 )
          break;
        v15 = __clz(__rbit64(v14));
        v16 = _per_cpu_offset[v15];
        v17 = v15 > 0x1E;
        v13 = v15 + 1;
        *(_QWORD *)(v16 + shs_pb_cpu_boosts_0) = 0x7FFFFFFF00000000LL;
      }
      while ( !v17 );
      return 0;
    }
    v2 = __clz(__rbit64(v1));
    v3 = _per_cpu_offset[v2];
    v4 = cpufreq_cpu_get((unsigned int)v2);
    if ( !v4 )
    {
      v27 = &unk_15418;
LABEL_37:
      printk(v27);
      return 4294967293LL;
    }
    v5 = freq_qos_add_request(v4 + 144, (char *)&boost_req + v3, 1, 0);
    if ( (v5 & 0x80000000) != 0 )
    {
      v28 = &unk_1594C;
      goto LABEL_39;
    }
    v6 = _per_cpu_offset[v2];
    v7 = cpufreq_cpu_get((unsigned int)v2);
    if ( !v7 )
    {
      v27 = &unk_15B3D;
      goto LABEL_37;
    }
    v5 = freq_qos_add_request(v7 + 144, (char *)&pb_boost_req + v6, 1, 0);
    if ( (v5 & 0x80000000) != 0 )
      break;
    v0 = v2 + 1;
    if ( v2 > 0x1E )
      goto LABEL_12;
  }
  v28 = &unk_15604;
LABEL_39:
  v29 = v5;
  printk(v28);
  return v29;
}
