void __fastcall msm_geni_serial_shutdown(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 v4; // x22
  unsigned __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x0
  int v8; // w21
  _QWORD *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x1
  const char *v13; // x21
  __int64 v14; // x8
  __int64 v15; // x8
  int v16; // w21
  const char *v17; // x22
  __int64 v18; // x8
  unsigned __int64 v19; // x1
  __int64 v20; // x22
  __int64 v21; // x0

  v2 = *(_QWORD *)(a1 + 624);
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: %d\n", "msm_geni_serial_shutdown", 1);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: %d\n");
  v4 = *(_QWORD *)(a1 + 968);
  *(_DWORD *)(a1 + 1516) = 1;
  if ( v4 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v5 = sched_clock(v3);
      ipc_log_string(v4, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_shutdown", v5, v5 / 0x3E8);
      v6 = *(_QWORD *)(a1 + 264);
      if ( !v6 )
        goto LABEL_10;
    }
    else
    {
      v5 = 0;
      v6 = *(_QWORD *)(a1 + 264);
      if ( !v6 )
        goto LABEL_10;
    }
  }
  else
  {
    v5 = -22;
    v6 = *(_QWORD *)(a1 + 264);
    if ( !v6 )
      goto LABEL_10;
  }
  if ( *(_DWORD *)(a1 + 316) == *(__int16 *)(v6 + 74) )
  {
    console_stop();
    v7 = disable_irq(*(unsigned int *)(a1 + 168));
    v8 = 0;
    goto LABEL_75;
  }
LABEL_10:
  if ( !*(_DWORD *)(a1 + 1004) )
    msm_geni_serial_power_on(a1);
  if ( *(_DWORD *)(a1 + 584) == 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Stop Rx Engine\n", "msm_geni_serial_shutdown");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Stop Rx Engine\n");
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 1264, 25) )
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Timeout for Rx reset\n", "msm_geni_serial_shutdown");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Timeout for Rx reset\n");
    }
    v9 = *(_QWORD **)(a1 + 1144);
    if ( v9[1] )
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s:GSI DMA-Rx ch\n", "msm_geni_serial_shutdown");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:GSI DMA-Rx ch\n");
      if ( a1 != -880 && *(_QWORD *)(a1 + 832) && v2 )
        dma_free_attrs(v2, 2048);
      if ( a1 != -888 && *(_QWORD *)(a1 + 840) && v2 )
        dma_free_attrs(v2, 2048);
      if ( a1 != -896 && *(_QWORD *)(a1 + 848) && v2 )
        dma_free_attrs(v2, 2048);
      if ( a1 != -904 && *(_QWORD *)(a1 + 856) && v2 )
        dma_free_attrs(v2, 2048);
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s:Unmap buf done\n", "msm_geni_serial_shutdown");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:Unmap buf done\n");
      v9 = *(_QWORD **)(a1 + 1144);
    }
    if ( !*v9 )
      goto LABEL_50;
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s:GSI DMA-Tx ch\n", "msm_geni_serial_shutdown");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:GSI DMA-Tx ch\n");
    v10 = *(_QWORD *)(a1 + 264);
    if ( v10 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v10 + 74)
      || (v11 = *(_QWORD *)(a1 + 344), !*(_DWORD *)(v11 + 500))
      || (*(_WORD *)(v11 + 488) & 7) != 0 )
    {
      stop_tx_sequencer(a1);
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_stop_tx");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.Device is not in active state.\n");
    }
    v12 = *(_QWORD *)(a1 + 808);
    if ( v12 == -1 )
      goto LABEL_42;
    if ( v12 )
    {
      dma_unmap_page_attrs(v2, v12, *(unsigned int *)(a1 + 816), 1, 0);
LABEL_42:
      v13 = "%s:Unmap buf done\n";
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s:Unmap buf done\n", "msm_geni_serial_shutdown");
LABEL_49:
      _ftrace_dbg(*(_QWORD *)(a1 + 344), v13);
    }
  }
  else
  {
    v14 = *(_QWORD *)(a1 + 264);
    if ( !v14 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v14 + 74) )
    {
      v15 = *(_QWORD *)(a1 + 344);
      if ( *(_DWORD *)(v15 + 500) )
      {
        if ( (*(_WORD *)(v15 + 488) & 7) == 0 )
        {
          v13 = "%s.Device is not in active state.\n";
          ipc_log_string(*(_QWORD *)(a1 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_stop_tx");
          goto LABEL_49;
        }
      }
    }
    stop_tx_sequencer(a1);
  }
LABEL_50:
  if ( *(_BYTE *)(a1 + 1336) == 1 )
    disable_irq(*(unsigned int *)(a1 + 168));
  if ( *(_DWORD *)(a1 + 1004) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 952), "%s: IOCTL vote present. Resetting ioctl count\n", "msm_geni_serial_shutdown");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: IOCTL vote present. Resetting ioctl count\n");
    *(_DWORD *)(a1 + 1004) = 0;
  }
  v7 = *(_QWORD *)(a1 + 344);
  if ( (*(_WORD *)(v7 + 488) & 7) != 0 )
  {
    v8 = 0;
  }
  else
  {
    v7 = _pm_runtime_suspend(v7, 4);
    v8 = v7;
    if ( (v7 & 0x80000000) != 0 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 952), "%s: Failed to suspend ret=%d\n", "msm_geni_serial_shutdown", v7);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Failed to suspend ret=%d\n");
      if ( v8 == -16 )
      {
        v16 = 0;
        v17 = "%s Uport not active\n";
        do
        {
          while ( 1 )
          {
            ipc_log_string(
              *(_QWORD *)(a1 + 952),
              "%s: Failed to suspend ret:%d retry:%d\n",
              "msm_geni_serial_shutdown",
              -16,
              v16);
            _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Failed to suspend ret:%d retry:%d\n");
            usleep_range_state(45000, 50000, 2);
            v18 = *(_QWORD *)(a1 + 344);
            if ( *(_DWORD *)(v18 + 500) )
              break;
            if ( ++v16 == 51 )
              goto LABEL_64;
          }
          if ( (*(_WORD *)(v18 + 488) & 7) == 0 )
          {
            v8 = 0;
            goto LABEL_68;
          }
          ++v16;
        }
        while ( v16 != 51 );
        if ( (*(_WORD *)(v18 + 488) & 7) != 0 )
        {
LABEL_64:
          v8 = -16;
          v17 = "%s Error! Unable to put uport to Suspend\n";
          ipc_log_string(
            *(_QWORD *)(a1 + 952),
            "%s Error! Unable to put uport to Suspend\n",
            "msm_geni_serial_shutdown");
          goto LABEL_69;
        }
        v8 = -16;
        v17 = "%s Uport not active\n";
LABEL_68:
        ipc_log_string(*(_QWORD *)(a1 + 952), "%s Uport not active\n", "msm_geni_serial_shutdown");
LABEL_69:
        _ftrace_dbg(*(_QWORD *)(a1 + 344), v17);
      }
    }
  }
  v19 = *(_QWORD *)(a1 + 680);
  if ( v19 )
  {
    if ( v19 <= 0xFFFFFFFFFFFFF000LL )
    {
      v7 = pinctrl_select_state(*(_QWORD *)(a1 + 672), v19);
      v8 = v7;
      if ( (_DWORD)v7 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Error %d pinctrl_select_state\n", "msm_geni_serial_shutdown", v7);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Error %d pinctrl_select_state\n");
      }
    }
  }
  *(_DWORD *)(a1 + 1120) = 0;
  *(_DWORD *)(a1 + 1496) = 0;
  *(_QWORD *)(a1 + 1504) = 0;
  *(_DWORD *)(a1 + 1328) = 0;
LABEL_75:
  v20 = *(_QWORD *)(a1 + 968);
  *(_DWORD *)(a1 + 1516) = 0;
  if ( v20 && v5 && *(_DWORD *)(a1 + 916) )
  {
    v21 = sched_clock(v7);
    ipc_log_string(v20, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_shutdown", v21 - v5, (v21 - v5) / 0x3E8);
  }
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: End %d\n", "msm_geni_serial_shutdown", v8);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: End %d\n");
}
