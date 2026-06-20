__int64 delete_events()
{
  __int64 result; // x0
  __int64 v1; // x1
  char v2; // w8
  unsigned __int64 v3; // x8
  unsigned __int64 v4; // x25
  __int64 v5; // x26
  __int64 v6; // x0
  char v7; // w8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x23
  __int64 v10; // x24
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x25
  __int64 *v13; // x26

  if ( cpuhp_state >= 1 )
    _cpuhp_remove_state();
  tracepoint_probe_unregister(&_tracepoint_android_vh_cpu_idle_enter, qcom_pmu_idle_enter_notif, 0);
  tracepoint_probe_unregister(&_tracepoint_android_vh_cpu_idle_exit, qcom_pmu_idle_exit_notif, 0);
  result = cpu_pm_unregister_notifier(&memlat_event_pm_nb);
  v2 = 0;
  do
  {
    v3 = (unsigned int)(-1LL << v2) & _cpu_possible_mask;
    if ( !(_DWORD)v3 )
      break;
    v4 = __clz(__rbit64(v3));
    v5 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v4]);
    v6 = raw_spin_lock_irqsave(v5 + 336);
    *(_WORD *)v5 = 257;
    *(_BYTE *)(v5 + 2) = 1;
    result = raw_spin_unlock_irqrestore(v5 + 336, v6);
    v2 = v4 + 1;
  }
  while ( v4 < 0x1F );
  v7 = 0;
  do
  {
    v8 = (unsigned int)(-1LL << v7) & _cpu_possible_mask;
    if ( !(_DWORD)v8 )
      break;
    v9 = __clz(__rbit64(v8));
    v10 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v9]);
    if ( *(int *)(v10 + 332) >= 1 )
    {
      do
        result = _const_udelay(42950);
      while ( *(int *)(v10 + 332) > 0 );
    }
    v11 = *(unsigned int *)(v10 + 328);
    if ( (_DWORD)v11 )
    {
      v12 = 0;
      v13 = (__int64 *)(v10 + 16);
      while ( v12 != 9 )
      {
        if ( *((_DWORD *)v13 - 2) )
        {
          result = *v13;
          if ( *v13 )
          {
            result = perf_event_release_kernel();
            *v13 = 0;
            v11 = *(unsigned int *)(v10 + 328);
          }
        }
        ++v12;
        v13 += 5;
        if ( v12 >= v11 )
          goto LABEL_7;
      }
      __break(0x5512u);
      return writel_relaxed(result, v1);
    }
LABEL_7:
    v7 = v9 + 1;
  }
  while ( v9 < 0x1F );
  return result;
}
