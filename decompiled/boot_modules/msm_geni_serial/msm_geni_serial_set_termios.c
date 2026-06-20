void __fastcall msm_geni_serial_set_termios(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x23
  unsigned __int64 v7; // x20
  __int64 v8; // x8
  int v9; // w0
  __int64 v10; // x8
  unsigned int baud_rate; // w22
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 started; // x0
  __int64 v15; // x8
  __int64 v16; // x20
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x21
  __int64 v20; // x0

  v3 = *(_QWORD *)(a1 + 968);
  if ( v3 )
  {
    if ( *(_DWORD *)(a1 + 916) )
    {
      v7 = sched_clock(a1);
      ipc_log_string(v3, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_set_termios", v7, v7 / 0x3E8);
      v8 = *(_QWORD *)(a1 + 264);
      if ( !v8 )
        goto LABEL_9;
    }
    else
    {
      v7 = 0;
      v8 = *(_QWORD *)(a1 + 264);
      if ( !v8 )
        goto LABEL_9;
    }
LABEL_8:
    if ( *(_DWORD *)(a1 + 316) == *(__int16 *)(v8 + 74) )
      goto LABEL_11;
    goto LABEL_9;
  }
  v7 = -22;
  v8 = *(_QWORD *)(a1 + 264);
  if ( v8 )
    goto LABEL_8;
LABEL_9:
  v9 = msm_geni_serial_power_on(a1);
  if ( v9 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Failed to vote clock on:%d\n", "msm_geni_serial_set_termios", v9);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Failed to vote clock on:%d\n");
    return;
  }
LABEL_11:
  if ( *(_QWORD *)(a1 + 1248) )
    _flush_workqueue();
  if ( *(_QWORD *)(a1 + 1256) )
    _flush_workqueue();
  *(_DWORD *)(a1 + 1264) = 0;
  msm_geni_serial_stop_rx(a1);
  v10 = *(_QWORD *)(a1 + 264);
  if ( (!v10 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v10 + 74)) && !wait_for_completion_timeout(a1 + 1264, 25) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s:Timeout for stop_rx\n", "msm_geni_serial_set_termios");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:Timeout for stop_rx\n");
  }
  baud_rate = uart_get_baud_rate(a1, a2, a3, 300, 8000000);
  *(_DWORD *)(a1 + 1000) = baud_rate;
  if ( !(unsigned int)msm_geni_serial_config_baud_rate(a1, a2, baud_rate) )
  {
    v17 = *(_QWORD *)(a1 + 264);
    if ( !v17 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v17 + 74) )
      *(_QWORD *)(a1 + 1504) = a2;
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: baud %d\n", "msm_geni_serial_set_termios", baud_rate);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: baud %d\n");
    v19 = *(_QWORD *)(a1 + 968);
    if ( v19 && v7 && *(_DWORD *)(a1 + 916) )
    {
      v20 = sched_clock(v18);
      ipc_log_string(v19, "%s:took %llu nsec(%llu usec)\n", "msm_geni_serial_set_termios", v20 - v7, (v20 - v7) / 0x3E8);
    }
  }
  v12 = *(_QWORD *)(a1 + 264);
  if ( v12 && *(_DWORD *)(a1 + 316) == *(__int16 *)(v12 + 74)
    || (v13 = *(_QWORD *)(a1 + 344), !*(_DWORD *)(v13 + 500))
    || (*(_WORD *)(v13 + 488) & 7) != 0 )
  {
    started = start_rx_sequencer(a1);
    v15 = *(_QWORD *)(a1 + 264);
    if ( v15 )
      goto LABEL_25;
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s.Device is not in active state.\n", "msm_geni_serial_start_rx");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s.Device is not in active state.\n");
    v15 = *(_QWORD *)(a1 + 264);
    if ( v15 )
    {
LABEL_25:
      if ( *(_DWORD *)(a1 + 316) == *(__int16 *)(v15 + 74) )
        return;
    }
  }
  v16 = *(_QWORD *)(a1 + 344);
  if ( *(_DWORD *)(v16 + 480) )
  {
    if ( (*(_WORD *)(v16 + 488) & 7) == 0 )
    {
      *(_QWORD *)(v16 + 520) = ktime_get_mono_fast_ns(started);
      _pm_runtime_suspend(*(_QWORD *)(a1 + 344), 13);
    }
  }
  else
  {
    ipc_log_string(*(_QWORD *)(a1 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Usage Count is already 0\n");
  }
}
