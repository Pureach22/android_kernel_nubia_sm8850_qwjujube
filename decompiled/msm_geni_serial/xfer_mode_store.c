__int64 __fastcall xfer_mode_store(__int64 a1, __int64 a2, const char *a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v7; // x8
  unsigned int v9; // w21
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x22
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x21

  v4 = *(_QWORD *)(a1 + 152);
  v7 = *(_QWORD *)(v4 + 264);
  if ( v7 && *(_DWORD *)(v4 + 316) == *(__int16 *)(v7 + 74) )
    return -95;
  if ( strnstr(a3, "FIFO", 4) )
  {
    v9 = 1;
  }
  else
  {
    if ( !strnstr(a3, "SE_DMA", 6) )
    {
      dev_err(a1, "%s: Invalid input %s\n", "xfer_mode_store", a3);
      return -22;
    }
    v9 = 2;
  }
  if ( v9 != *(_DWORD *)(v4 + 584) )
  {
    msm_geni_serial_power_on((_QWORD *)v4);
    v10 = *(_QWORD *)(v4 + 264);
    if ( v10 && *(_DWORD *)(v4 + 316) == *(__int16 *)(v10 + 74)
      || (v11 = *(_QWORD *)(v4 + 344), !*(_DWORD *)(v11 + 500))
      || (*(_WORD *)(v11 + 488) & 7) != 0 )
    {
      stop_tx_sequencer(v4);
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v4 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_stop_tx");
      _ftrace_dbg(*(_QWORD *)(v4 + 344), "%s.Device is not in active state.\n");
    }
    msm_geni_serial_stop_rx(v4);
    v12 = raw_spin_lock_irqsave(v4);
    *(_DWORD *)(v4 + 584) = v9;
    geni_se_select_mode(v4 + 712, v9);
    raw_spin_unlock_irqrestore(v4, v12);
    v13 = *(_QWORD *)(v4 + 264);
    if ( v13 && *(_DWORD *)(v4 + 316) == *(__int16 *)(v13 + 74)
      || (v14 = *(_QWORD *)(v4 + 344), !*(_DWORD *)(v14 + 500))
      || (*(_WORD *)(v14 + 488) & 7) != 0 )
    {
      start_rx_sequencer(v4);
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v4 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_start_rx");
      _ftrace_dbg(*(_QWORD *)(v4 + 344), "%s.Device is not in active state.\n");
    }
    v16 = *(_QWORD *)(v4 + 344);
    if ( *(_DWORD *)(v16 + 480) )
    {
      if ( (*(_WORD *)(v16 + 488) & 7) == 0 )
      {
        *(_QWORD *)(v16 + 520) = ktime_get_mono_fast_ns(v15);
        _pm_runtime_suspend(*(_QWORD *)(v4 + 344), 13);
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(v4 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
      _ftrace_dbg(*(_QWORD *)(v4 + 344), "%s: Usage Count is already 0\n");
    }
  }
  return a4;
}
