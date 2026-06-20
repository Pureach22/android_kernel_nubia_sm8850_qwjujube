__int64 __fastcall swap_pipeline_with_prime_locked(__int64 result, __int64 a2)
{
  unsigned int *v2; // x13
  unsigned __int64 v3; // x13
  unsigned __int64 v4; // x8
  __int64 v5; // x12
  unsigned int *v6; // x9
  unsigned __int64 v7; // x13
  unsigned __int64 v8; // x9
  unsigned int v9; // w9
  unsigned int v10; // w8
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x10
  __int64 v13; // x9
  __int64 v14; // x9
  int v15; // w9
  int v16; // w9
  int v17; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v19; // x8
  unsigned __int64 v26; // x11
  unsigned __int64 v29; // x10

  if ( !result || !a2 )
  {
    if ( result || !a2 )
      return result;
    if ( have_heavy_list )
    {
      v9 = __clz(__rbit64(LODWORD(available_prime_cpus[0])));
      if ( LODWORD(available_prime_cpus[0]) )
        v10 = v9;
      else
        v10 = 32;
      if ( v10 < nr_cpu_ids )
      {
        v11 = *(unsigned int *)(a2 + 364);
        v12 = v11 >> 6;
        v13 = 1LL << v11;
        _X10 = (unsigned __int64 *)&available_gold_cpus[v12];
        __asm { PRFM            #0x11, [X10] }
        do
          v26 = __ldxr(_X10);
        while ( __stxr(v26 & ~v13, _X10) );
        *(_DWORD *)(a2 + 364) = v10;
        v14 = 1LL << v10;
        _X8 = available_prime_cpus;
        __asm { PRFM            #0x11, [X8] }
        do
          v29 = __ldxr((unsigned __int64 *)available_prime_cpus);
        while ( __stxr(v29 & ~v14, (unsigned __int64 *)available_prime_cpus) );
      }
      return result;
    }
    if ( (unsigned int)(num_sched_clusters - 1) < 8 )
    {
      v16 = 63 - __clz(*(unsigned int *)(sched_cluster[num_sched_clusters - 1] + 24));
      if ( *(_DWORD *)(sched_cluster[num_sched_clusters - 1] + 24) )
        v17 = v16;
      else
        v17 = 32;
      *(_DWORD *)(a2 + 364) = v17;
      return result;
    }
LABEL_31:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_sched_pipeline_swapped(0, a2, 0);
      v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v19;
      if ( !v19 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
    return result;
  }
  if ( (_UNKNOWN *)result == &vendor_data_pad )
    v2 = (unsigned int *)&init_task;
  else
    v2 = (unsigned int *)(result - 5184);
  v3 = v2[10];
  if ( (unsigned int)(num_sched_clusters - 1) >= 8 )
    goto LABEL_31;
  v4 = *(_DWORD *)(result + 32) / (unsigned int)walt_scale_demand_divisor;
  v5 = sched_cluster[num_sched_clusters - 1] + 24;
  if ( ((*(_QWORD *)(v5 + ((v3 >> 3) & 0x1FFFFFF8)) >> v3) & 1) == 0 )
    v4 = (unsigned __int16)(70 * ((unsigned int)v4 % 0x64)) / 0x64u + 70LL * ((unsigned int)v4 / 0x64);
  if ( (_UNKNOWN *)a2 == &vendor_data_pad )
    v6 = (unsigned int *)&init_task;
  else
    v6 = (unsigned int *)(a2 - 5184);
  v7 = v6[10];
  v8 = *(_DWORD *)(a2 + 32) / (unsigned int)walt_scale_demand_divisor;
  if ( ((*(_QWORD *)(v5 + ((v7 >> 3) & 0x1FFFFFF8)) >> v7) & 1) != 0 )
  {
    if ( v4 >= v8 )
      return result;
LABEL_24:
    v15 = *(_DWORD *)(a2 + 364);
    *(_DWORD *)(a2 + 364) = *(_DWORD *)(result + 364);
    *(_DWORD *)(result + 364) = v15;
    return result;
  }
  if ( v4 < (unsigned __int16)(70 * ((unsigned int)v8 % 0x64)) / 0x64u
          + 70 * (unsigned __int64)((unsigned int)v8 / 0x64) )
    goto LABEL_24;
  return result;
}
