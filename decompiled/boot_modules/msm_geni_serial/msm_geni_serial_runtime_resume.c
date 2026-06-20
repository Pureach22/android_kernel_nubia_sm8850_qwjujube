__int64 __fastcall msm_geni_serial_runtime_resume(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned __int64 v5; // x22
  int v6; // w0
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x23
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x23
  __int64 v13; // x22
  unsigned __int64 v14; // x21
  __int64 v15; // x8
  int v16; // w0
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 started; // x0
  __int64 v21; // x8
  __int64 v22; // x22
  __int64 v23; // x0
  __int64 v24; // x22
  __int64 v25; // x0

  v1 = *(_QWORD *)(a1 + 152);
  ipc_log_string(*(_QWORD *)(v1 + 952), "%s: Start %d\n", "msm_geni_serial_runtime_resume", 1);
  _ftrace_dbg(a1, "%s: Start %d\n");
  v4 = *(_QWORD *)(v1 + 968);
  if ( v4 )
  {
    if ( *(_DWORD *)(v1 + 916) )
    {
      v5 = sched_clock(v3);
      ipc_log_string(v4, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_runtime_resume", v5, v5 / 0x3E8);
    }
    else
    {
      v5 = 0;
    }
  }
  else
  {
    v5 = -22;
  }
  _pm_relax(*(_QWORD *)(v1 + 928));
  _pm_stay_awake(*(_QWORD *)(v1 + 928));
  if ( *(int *)(v1 + 920) >= 1 && *(_BYTE *)(v1 + 1042) == 1 && *(_QWORD *)(*(_QWORD *)(v1 + 208) + 152LL) )
  {
    v6 = irq_set_irq_wake();
    if ( v6 )
      dev_err(a1, "%s:Failed to unset IRQ wake:%d\n", "msm_geni_serial_runtime_resume", v6);
    disable_irq(*(unsigned int *)(v1 + 920));
    *(_BYTE *)(v1 + 1042) = 0;
  }
  ipc_log_string(*(_QWORD *)(v1 + 952), "%s: Enabling Resources\n", "msm_geni_serial_runtime_resume");
  _ftrace_dbg(a1, "%s: Enabling Resources\n");
  v7 = msm_geni_serial_resources_on(v1);
  if ( v7 )
  {
    dev_err(a1, "%s: Error ret %d\n", "msm_geni_serial_runtime_resume", v7);
    if ( (*(_BYTE *)(v1 + 1036) & 1) == 0 )
    {
      v23 = *(_QWORD *)(v1 + 960);
      *(_DWORD *)(v1 + 1120) = 5;
      ipc_log_string(v23, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 5);
      _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s uart_error_code %d");
    }
    _pm_relax(*(_QWORD *)(v1 + 928));
  }
  else
  {
    ipc_log_string(
      *(_QWORD *)(v1 + 960),
      "%s: enable:%d ser_clk_cfg:%lu\n",
      "msm_geni_enable_disable_se_clk",
      1,
      *(_QWORD *)(v1 + 1128));
    _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: enable:%d ser_clk_cfg:%lu\n");
    writel_relaxed(*(_DWORD *)(v1 + 1128), (unsigned int *)(*(_QWORD *)(v1 + 16) + 72LL));
    writel_relaxed(*(_DWORD *)(v1 + 1128), (unsigned int *)(*(_QWORD *)(v1 + 16) + 76LL));
    readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 16) + 72LL));
    if ( *(_DWORD *)(v1 + 1516) == 2 )
      start_rx_sequencer(v1);
    if ( *(_BYTE *)(v1 + 1512) == 1 )
      msm_geni_serial_port_setup(v1);
    __dsb(0xFu);
    v8 = enable_irq(*(unsigned int *)(v1 + 168));
    v9 = *(_QWORD *)(v1 + 968);
    if ( v9 && v5 && *(_DWORD *)(v1 + 916) )
    {
      v10 = sched_clock(v8);
      ipc_log_string(
        v9,
        "%s:took %llu nsec(%llu usec)\n",
        "msm_geni_serial_runtime_resume",
        v10 - v5,
        (v10 - v5) / 0x3E8);
    }
    ipc_log_string(*(_QWORD *)(v1 + 952), "%s: End %d\n", "msm_geni_serial_runtime_resume", 0);
    _ftrace_dbg(a1, "%s: End %d\n");
    if ( *(_BYTE *)(v1 + 1512) == 1 )
    {
      v12 = *(_QWORD *)(v1 + 968);
      v13 = *(_QWORD *)(v1 + 1504);
      if ( v12 )
      {
        if ( *(_DWORD *)(v1 + 916) )
        {
          v14 = sched_clock(v11);
          ipc_log_string(
            v12,
            "%s:start at %llu nsec(%llu usec)\n",
            "msm_geni_serial_reconfigure_baud_rate",
            v14,
            v14 / 0x3E8);
          if ( !v13 )
            goto LABEL_61;
        }
        else
        {
          v14 = 0;
          if ( !v13 )
          {
LABEL_61:
            *(_BYTE *)(v1 + 1512) = 0;
            return v7;
          }
        }
      }
      else
      {
        v14 = -22;
        if ( !v13 )
          goto LABEL_61;
      }
      ipc_log_string(*(_QWORD *)(v1 + 960), "%s: start %d\n", "msm_geni_serial_reconfigure_baud_rate", 1);
      _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: start %d\n");
      v15 = *(_QWORD *)(v1 + 264);
      if ( !v15 || *(_DWORD *)(v1 + 316) != *(__int16 *)(v15 + 74) )
      {
        v16 = msm_geni_serial_power_on((_QWORD *)v1);
        if ( v16 )
        {
          ipc_log_string(
            *(_QWORD *)(v1 + 960),
            "%s: Failed to vote clock on:%d\n",
            "msm_geni_serial_reconfigure_baud_rate",
            v16);
          _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: Failed to vote clock on:%d\n");
          goto LABEL_61;
        }
      }
      if ( *(_QWORD *)(v1 + 1248) )
        _flush_workqueue();
      if ( *(_QWORD *)(v1 + 1256) )
        _flush_workqueue();
      *(_DWORD *)(v1 + 1264) = 0;
      msm_geni_serial_stop_rx(v1);
      v17 = *(_QWORD *)(v1 + 264);
      if ( (!v17 || *(_DWORD *)(v1 + 316) != *(__int16 *)(v17 + 74)) && !wait_for_completion_timeout(v1 + 1264, 25) )
      {
        ipc_log_string(*(_QWORD *)(v1 + 960), "%s:Timeout for stop_rx\n", "msm_geni_serial_reconfigure_baud_rate");
        _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s:Timeout for stop_rx\n");
      }
      if ( (unsigned int)msm_geni_serial_config_baud_rate(v1, v13, *(unsigned int *)(v1 + 1000)) )
      {
        v18 = *(_QWORD *)(v1 + 264);
        if ( !v18 )
          goto LABEL_46;
      }
      else
      {
        ipc_log_string(
          *(_QWORD *)(v1 + 960),
          "%s: baud %d\n",
          "msm_geni_serial_reconfigure_baud_rate",
          *(_DWORD *)(v1 + 1000));
        _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: baud %d\n");
        v18 = *(_QWORD *)(v1 + 264);
        if ( !v18 )
        {
LABEL_46:
          v19 = *(_QWORD *)(v1 + 344);
          if ( *(_DWORD *)(v19 + 500) && (*(_WORD *)(v19 + 488) & 7) == 0 )
          {
            ipc_log_string(*(_QWORD *)(v1 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_start_rx");
            _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s.Device is not in active state.\n");
            v21 = *(_QWORD *)(v1 + 264);
            if ( !v21 )
              goto LABEL_50;
            goto LABEL_49;
          }
LABEL_48:
          started = start_rx_sequencer(v1);
          v21 = *(_QWORD *)(v1 + 264);
          if ( !v21 )
            goto LABEL_50;
LABEL_49:
          if ( *(_DWORD *)(v1 + 316) == *(__int16 *)(v21 + 74) )
          {
LABEL_57:
            v24 = *(_QWORD *)(v1 + 968);
            if ( v24 && v14 && *(_DWORD *)(v1 + 916) )
            {
              v25 = sched_clock(started);
              ipc_log_string(
                v24,
                "%s:took %llu nsec(%llu usec)\n",
                "msm_geni_serial_reconfigure_baud_rate",
                v25 - v14,
                (v25 - v14) / 0x3E8);
            }
            goto LABEL_61;
          }
LABEL_50:
          v22 = *(_QWORD *)(v1 + 344);
          if ( *(_DWORD *)(v22 + 480) )
          {
            if ( (*(_WORD *)(v22 + 488) & 7) == 0 )
            {
              *(_QWORD *)(v22 + 520) = ktime_get_mono_fast_ns(started);
              started = _pm_runtime_suspend(*(_QWORD *)(v1 + 344), 13);
            }
          }
          else
          {
            ipc_log_string(*(_QWORD *)(v1 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
            _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: Usage Count is already 0\n");
          }
          goto LABEL_57;
        }
      }
      if ( *(_DWORD *)(v1 + 316) == *(__int16 *)(v18 + 74) )
        goto LABEL_48;
      goto LABEL_46;
    }
  }
  return v7;
}
