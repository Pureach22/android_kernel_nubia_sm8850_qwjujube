__int64 __fastcall walt_configure_single_thread_pipeline(int a1)
{
  __int64 v2; // x19
  int v3; // w9
  __int64 v4; // x0
  __int64 v5; // x1

  v2 = raw_spin_lock_irqsave(&heavy_lock);
  if ( a1 )
  {
    v3 = have_heavy_list;
    if ( qword_699A8 )
    {
      if ( (*(_DWORD *)(qword_699A8 + 364) & 0x80000000) == 0 )
        v3 = --have_heavy_list;
      *(_DWORD *)(qword_699A8 + 364) = -1;
    }
    if ( qword_699B0 )
    {
      if ( (*(_DWORD *)(qword_699B0 + 364) & 0x80000000) == 0 )
        have_heavy_list = v3 - 1;
      *(_DWORD *)(qword_699B0 + 364) = -1;
    }
  }
  v4 = ((__int64 (__fastcall *)(_QWORD, __int64))pipeline_set_unisolation)(0, 1);
  sysctl_single_thread_pipeline = a1;
  if ( !a1 || !heavy_wts[0] )
    return raw_spin_unlock_irqrestore(&heavy_lock, v2);
  if ( (_DWORD)cpus_for_pipeline )
  {
    if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + (__clz((unsigned int)cpus_for_pipeline) ^ 0x3F))
                                       + 8]
                   + 32LL) == max_possible_cluster_id )
    {
      pipeline_set_unisolation_enable_pipeline_unisolation |= 2u;
      if ( (pipeline_set_unisolation_unisolation_state & 1) == 0 )
      {
        pipeline_set_unisolation_unisolation_state = 1;
        ((void (*)(void))core_ctl_set_cluster_boost)();
      }
    }
    return raw_spin_unlock_irqrestore(&heavy_lock, v2);
  }
  __break(0x5512u);
  return walt_should_kick_upmigrate_1(v4, v5);
}
