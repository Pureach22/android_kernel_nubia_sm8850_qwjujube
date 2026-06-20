unsigned __int64 __fastcall rearrange_pipeline_preferred_cpus(unsigned __int64 result)
{
  unsigned int v1; // w21
  __int64 v2; // x0
  int v3; // w10
  int v4; // w11
  unsigned int v5; // w3
  int v6; // w14
  unsigned int v7; // w13
  unsigned int v8; // w15
  __int64 v9; // x8
  int v10; // w16
  char *v11; // x20
  __int64 v12; // x19
  unsigned int v13; // w9
  __int64 v14; // x17
  __int64 v15; // x1
  __int64 v16; // x21
  unsigned int v17; // w30
  unsigned int v18; // w3
  bool v19; // zf
  unsigned __int64 v20; // x3
  unsigned int *v21; // x24
  unsigned __int64 v22; // x24
  unsigned __int64 v23; // x30
  unsigned int v24; // w8
  __int64 v25; // x20
  __int64 v26; // [xsp+8h] [xbp-8h]

  if ( sysctl_sched_heavy_nr || sysctl_sched_pipeline_util_thres || num_sched_clusters < 2 )
    return result;
  v1 = 0;
  if ( !pipeline_nr || sched_boost_type )
    goto LABEL_60;
  if ( delay_rearrange_last_rearrange_ns_0
    && delay_rearrange_last_rearrange_ns_0
     + (unsigned int)dword_DAF0 * (unsigned __int64)(unsigned int)sched_ravg_window > result )
  {
    v1 = 0;
    goto LABEL_60;
  }
  delay_rearrange_last_rearrange_ns_0 = result;
  v2 = raw_spin_lock_irqsave(&pipeline_lock);
  v3 = cpus_for_pipeline;
  v4 = _cpu_online_mask;
  v5 = rearrange_pipeline_preferred_cpus_assign_cpu;
  v6 = max_possible_cluster_id;
  v7 = nr_cpu_ids;
  v8 = walt_scale_demand_divisor;
  v26 = v2;
  v9 = 0;
  v10 = __clz(__rbit64((unsigned int)cpus_for_pipeline & _cpu_online_mask));
  v11 = nullptr;
  v12 = 0;
  v13 = 0;
  if ( ((unsigned int)cpus_for_pipeline & _cpu_online_mask) == 0 )
    v10 = 32;
  v14 = (unsigned int)(num_sched_clusters - 1);
  v15 = 0xFFFFFFFFLL;
  while ( 1 )
  {
    v16 = pipeline_wts[v9];
    if ( !v16 )
      goto LABEL_13;
    if ( *(_QWORD *)(v16 + 240) )
      break;
    *(_DWORD *)(v16 + 364) = -1;
LABEL_20:
    v18 = v5 + 1;
    if ( v18 > 0x1F )
    {
      v5 = 32;
    }
    else
    {
      v20 = (unsigned int)(-1LL << v18) & v3 & v4;
      v19 = v20 == 0;
      v5 = __clz(__rbit64(v20));
      if ( v19 )
        v5 = 32;
    }
    if ( v7 <= v5 )
      v5 = v10;
    rearrange_pipeline_preferred_cpus_assign_cpu = v5;
    if ( v5 >= v7 )
    {
      *(_DWORD *)(v16 + 364) = -1;
    }
    else
    {
      v17 = v5;
      *(_DWORD *)(v16 + 364) = v5;
      if ( (v5 & 0x80000000) == 0 )
        goto LABEL_27;
    }
LABEL_13:
    if ( ++v9 == 8 )
    {
      if ( pipeline_nr > 2 )
      {
        swap_pipeline_with_prime_locked(v12, (__int64)v11);
      }
      else
      {
        if ( !v12 )
        {
LABEL_56:
          if ( (is_prime_worthy(v11, v15) & 1) != 0 )
          {
            swap_pipeline_with_prime_locked(0, (__int64)v11);
            v1 = 1;
          }
          else
          {
            v1 = 0;
          }
          goto LABEL_59;
        }
        if ( (is_prime_worthy((char *)v12, 0xFFFFFFFFLL) & 1) == 0 )
        {
          if ( (unsigned int)(rearrange_pipeline_preferred_cpus_assign_cpu + 1) > 0x1F )
          {
            v24 = 32;
          }
          else if ( ((unsigned int)(-1LL << ((unsigned __int8)rearrange_pipeline_preferred_cpus_assign_cpu + 1))
                   & (unsigned int)cpus_for_pipeline
                   & _cpu_online_mask) != 0 )
          {
            v24 = __clz(
                    __rbit64(
                      (unsigned int)(-1LL << ((unsigned __int8)rearrange_pipeline_preferred_cpus_assign_cpu + 1))
                    & (unsigned int)cpus_for_pipeline
                    & _cpu_online_mask));
          }
          else
          {
            v24 = 32;
          }
          rearrange_pipeline_preferred_cpus_assign_cpu = v24;
          if ( v24 >= nr_cpu_ids )
          {
            v24 = __clz(__rbit64((unsigned int)cpus_for_pipeline & _cpu_online_mask));
            if ( ((unsigned int)cpus_for_pipeline & _cpu_online_mask) == 0 )
              v24 = 32;
            rearrange_pipeline_preferred_cpus_assign_cpu = v24;
          }
          if ( v24 >= nr_cpu_ids )
            v24 = -1;
          *(_DWORD *)(v12 + 364) = v24;
          goto LABEL_56;
        }
      }
      v1 = 1;
      goto LABEL_59;
    }
  }
  v17 = *(_DWORD *)(v16 + 364);
  if ( v17 == -1 )
    goto LABEL_20;
  if ( (v17 & 0x80000000) != 0 )
    goto LABEL_13;
LABEL_27:
  if ( v17 >= v7 )
    goto LABEL_13;
  if ( v17 >= 0x20 )
    goto LABEL_64;
  if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v17) + 8] + 32LL) == v6 )
  {
    v12 = v16;
    goto LABEL_13;
  }
  v21 = (unsigned int *)(v16 - 5184);
  if ( (_UNKNOWN *)v16 == &vendor_data_pad )
    v21 = (unsigned int *)&init_task;
  v22 = v21[10];
  if ( (unsigned int)v14 < 8 )
  {
    v23 = *(_DWORD *)(v16 + 32) / v8;
    if ( ((*(_QWORD *)(sched_cluster[v14] + ((v22 >> 3) & 0x1FFFFFF8) + 24) >> v22) & 1) == 0 )
      v23 = (unsigned __int16)(70 * ((unsigned int)v23 % 0x64)) / 0x64u + 70LL * ((unsigned int)v23 / 0x64);
    if ( v23 > v13 )
    {
      v13 = v23;
      v11 = (char *)v16;
    }
    goto LABEL_13;
  }
LABEL_64:
  __break(0x5512u);
  v25 = 0;
  v1 = 1;
  _ReadStatusReg(SP_EL0);
  do
    ++v25;
  while ( v25 != 8 );
LABEL_59:
  result = raw_spin_unlock_irqrestore(&pipeline_lock, v26);
LABEL_60:
  if ( (unsigned __int8)rearrange_pipeline_preferred_cpus_last_set_unisolation != v1 )
  {
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD))pipeline_set_unisolation)(v1, 0);
    rearrange_pipeline_preferred_cpus_last_set_unisolation = v1;
  }
  return result;
}
