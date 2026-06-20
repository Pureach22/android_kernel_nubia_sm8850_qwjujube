__int64 __fastcall hdd_trigger_psoc_idle_restart(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x21
  unsigned int v36; // w19

  rtnl_is_locked();
  _qdf_delayed_work_stop_sync();
  qdf_wake_lock_release((__int64)&wlan_wake_lock, 0x15u);
  qdf_trace_msg(0x33u, 8u, "%s: Stopped psoc idle timer", v2, v3, v4, v5, v6, v7, v8, v9, "hdd_psoc_idle_timer_stop");
  if ( *(_DWORD *)(a1 + 1464) == 1 )
  {
    qdf_trace_msg(0x33u, 8u, "Driver modules already Enabled", v10, v11, v12, v13, v14, v15, v16, v17);
    return 0;
  }
  else
  {
    result = hdd_soc_idle_restart_lock();
    if ( !(_DWORD)result )
    {
      if ( *(_DWORD *)(a1 + 6856) )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: request pcie gen speed change to %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "hdd_trigger_psoc_idle_restart");
        if ( (unsigned int)pld_set_pcie_gen_speed(*(_QWORD *)(a1 + 96), *(unsigned int *)(a1 + 6856)) )
        {
          v35 = jiffies;
          if ( hdd_trigger_psoc_idle_restart___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: failed to set pcie gen speed",
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              "hdd_trigger_psoc_idle_restart");
            hdd_trigger_psoc_idle_restart___last_ticks = v35;
          }
        }
        *(_DWORD *)(a1 + 6856) = 0;
      }
      qdf_event_reset(a1 + 6952);
      qdf_mutex_acquire(a1 + 6992);
      *(_BYTE *)(a1 + 6948) = 1;
      qdf_mutex_release(a1 + 6992);
      v36 = pld_idle_restart(*(_QWORD *)(a1 + 96), hdd_psoc_idle_restart);
      hdd_soc_idle_restart_unlock();
      return v36;
    }
  }
  return result;
}
