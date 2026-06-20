__int64 __fastcall swrm_device_wakeup_unvote(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  __int64 v3; // x0
  int v4; // w8
  __int64 result; // x0
  __int64 v6; // x0
  int v7; // w8
  int v8; // w8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 152)) != 0 )
  {
    v2 = *(_QWORD *)(v1 + 8512);
    *(_QWORD *)(v2 + 520) = ktime_get_mono_fast_ns(a1);
    _pm_runtime_suspend(*(_QWORD *)(v1 + 8512), 13);
    mutex_lock(v1 + 8736);
    v3 = *(_QWORD *)(v1 + 15856);
    if ( v3 )
    {
      v4 = *(_DWORD *)(v1 + 15876) - 1;
      *(_DWORD *)(v1 + 15876) = v4;
      if ( v4 < 0 )
      {
        *(_DWORD *)(v1 + 15876) = 0;
      }
      else if ( !v4 )
      {
        digital_cdc_rsc_mgr_hw_vote_disable(v3, *(_QWORD *)(v1 + 8512));
      }
    }
    mutex_unlock(v1 + 8736);
    mutex_lock(v1 + 8736);
    v6 = *(_QWORD *)(v1 + 15848);
    if ( v6 )
    {
      v7 = *(_DWORD *)(v1 + 15872) - 1;
      *(_DWORD *)(v1 + 15872) = v7;
      if ( v7 < 0 )
      {
        *(_DWORD *)(v1 + 15872) = 0;
      }
      else if ( !v7 )
      {
        digital_cdc_rsc_mgr_hw_vote_disable(v6, *(_QWORD *)(v1 + 8512));
      }
    }
    mutex_unlock(v1 + 8736);
    mutex_lock(v1 + 8880);
    v8 = *(_DWORD *)(v1 + 15832) - 1;
    *(_DWORD *)(v1 + 15832) = v8;
    if ( !v8 )
    {
      if ( *(_DWORD *)(v1 + 15800) == 1 )
        *(_DWORD *)(v1 + 15800) = 0;
      cpu_latency_qos_update_request(v1 + 15752, 0xFFFFFFFFLL);
      pm_relax(*(_QWORD *)(v1 + 8512));
    }
    mutex_unlock(v1 + 8880);
    return _wake_up(v1 + 15808, 3, 0, 0);
  }
  else
  {
    result = __ratelimit(&swrm_device_wakeup_unvote__rs, "swrm_device_wakeup_unvote");
    if ( (_DWORD)result )
      return printk(&unk_1079B, "swrm_device_wakeup_unvote");
  }
  return result;
}
