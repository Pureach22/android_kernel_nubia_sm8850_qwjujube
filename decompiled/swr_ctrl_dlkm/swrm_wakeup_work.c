__int64 __fastcall swrm_wakeup_work(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w23
  char v4; // w8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x20
  int v8; // w8

  v1 = a1 - 15712;
  if ( a1 == 15712 || !*(_QWORD *)(a1 - 7200) )
    return printk(&unk_10AC2, "swrm_wakeup_work");
  mutex_lock(a1 - 6976);
  v3 = *(unsigned __int8 *)(a1 + 36);
  mutex_unlock(a1 - 6976);
  if ( v3 == 1 )
  {
    v4 = swrm_lock_sleep(v1);
    v5 = *(_QWORD *)(a1 - 7200);
    if ( (v4 & 1) != 0 )
    {
      v6 = _pm_runtime_resume(v5, 4);
      v7 = *(_QWORD *)(a1 - 7200);
      *(_QWORD *)(v7 + 520) = ktime_get_mono_fast_ns(v6);
      _pm_runtime_suspend(*(_QWORD *)(a1 - 7200), 13);
      mutex_lock(a1 - 6832);
      v8 = *(_DWORD *)(a1 + 120) - 1;
      *(_DWORD *)(a1 + 120) = v8;
      if ( !v8 )
      {
        if ( *(_DWORD *)(a1 + 88) == 1 )
          *(_DWORD *)(a1 + 88) = 0;
        cpu_latency_qos_update_request(a1 + 40, 0xFFFFFFFFLL);
        pm_relax(*(_QWORD *)(a1 - 7200));
      }
      mutex_unlock(a1 - 6832);
      _wake_up(a1 + 96, 3, 0, 0);
    }
    else
    {
      dev_err(v5, "%s Failed to hold suspend\n", "swrm_wakeup_work");
    }
  }
  return pm_relax(*(_QWORD *)(a1 - 7200));
}
