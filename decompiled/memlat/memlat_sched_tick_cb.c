__int64 memlat_sched_tick_cb()
{
  __int64 v0; // x20
  __int64 v1; // x19
  __int64 result; // x0
  __int64 v3; // x22
  __int64 v4; // x21

  v0 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
  if ( (unsigned int)v0 >= 0x20 )
  {
    __break(0x5512u);
    return ((__int64 (*)(void))process_raw_ctrs)();
  }
  else
  {
    v1 = *(_QWORD *)((char *)&sampling_stats + _per_cpu_offset[v0]);
    result = ktime_get();
    if ( *(_BYTE *)(memlat_data + 307) == 1 )
    {
      v3 = result;
      v4 = raw_spin_lock_irqsave(v1 + 584);
      if ( v3 - *(_QWORD *)(v1 + 576) + 2000000 >= 1000000LL * *(unsigned int *)(memlat_data + 160) )
      {
        *(_QWORD *)(v1 + 568) = v3;
        *(_BYTE *)(v1 + 560) = 0;
        *(_DWORD *)(v1 + 552) = 0;
        if ( (qcom_pmu_read_all_local(v1 + 456) & 0x80000000) != 0 || !*(_DWORD *)(v1 + 552) )
          printk(&unk_C200);
        else
          process_raw_ctrs(v1);
      }
      return raw_spin_unlock_irqrestore(v1 + 584, v4);
    }
  }
  return result;
}
