void __fastcall stop_tx_sequencer(__int64 a1)
{
  int v2; // w0
  char v3; // w20
  __int64 v4; // x21
  int v5; // w0
  __int64 v6; // x21
  int v7; // w0
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x21
  int v12; // w0
  __int64 v13; // x21
  int v14; // w0
  __int64 v15; // x21
  __int64 v16; // x0
  int v17; // w0
  __int64 v18; // x8
  int v19; // w3
  __int64 v20; // x1
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x20
  int v24; // w0

  v2 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  if ( (v2 & 1) == 0 )
    return;
  if ( *(_DWORD *)(a1 + 584) == 3 )
  {
    queue_work_on(32, *(_QWORD *)(a1 + 1248), a1 + 1216);
    return;
  }
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Start GENI: 0x%x\n", "stop_tx_sequencer", v2);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Start GENI: 0x%x\n");
  *(_BYTE *)(a1 + 1038) = 0;
  *(_BYTE *)(a1 + 1040) = 1;
  *(_DWORD *)(a1 + 1048) = 0;
  v3 = msm_serial_try_disable_interrupts(a1);
  writel_relaxed(4u, (unsigned int *)(*(_QWORD *)(a1 + 712) + 1540LL));
  if ( (geni_wait_for_cmd_done(a1, v3 & 1) & 1) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 984);
    v5 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
    ipc_log_string(v4, "%s: tx_cancel failed 0x%x\n", "stop_tx_sequencer", v5);
    v6 = *(_QWORD *)(a1 + 960);
    v7 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
    ipc_log_string(v6, "%s: tx_cancel failed 0x%x\n", "stop_tx_sequencer", v7);
    v8 = *(_QWORD *)(a1 + 344);
    readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
    _ftrace_dbg(v8, "%s: tx_cancel failed 0x%x\n");
    if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
    {
      v9 = *(_QWORD *)(a1 + 960);
      *(_DWORD *)(a1 + 1120) = 8;
      ipc_log_string(v9, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 8);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
    }
    geni_se_dump_dbg_regs((_QWORD *)a1);
    v10 = *(_QWORD *)(a1 + 712);
    *(_BYTE *)(a1 + 1038) = 0;
    *(_DWORD *)(a1 + 1048) = 0;
    writel_relaxed(2u, (unsigned int *)(v10 + 1540));
    if ( (geni_wait_for_cmd_done(a1, v3 & 1) & 1) != 0 )
    {
      v11 = *(_QWORD *)(a1 + 984);
      v12 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      ipc_log_string(v11, "%s: tx abort failed 0x%x\n", "stop_tx_sequencer", v12);
      v13 = *(_QWORD *)(a1 + 960);
      v14 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      ipc_log_string(v13, "%s: tx abort failed 0x%x\n", "stop_tx_sequencer", v14);
      v15 = *(_QWORD *)(a1 + 344);
      readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
      _ftrace_dbg(v15, "%s: tx abort failed 0x%x\n");
      if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
      {
        v16 = *(_QWORD *)(a1 + 960);
        *(_DWORD *)(a1 + 1120) = 9;
        ipc_log_string(v16, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 9);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
      }
      geni_se_dump_dbg_regs((_QWORD *)a1);
    }
    writel_relaxed(0x80000001, (unsigned int *)(*(_QWORD *)(a1 + 16) + 684LL));
    __dsb(0xFu);
    v17 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 684LL));
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s(): rfr = 0x%x\n", "msm_geni_serial_allow_rx", v17);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s(): rfr = 0x%x\n");
    msm_geni_serial_set_manual_flow(1, a1);
    writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 32LL));
  }
  if ( *(_DWORD *)(a1 + 584) == 2 )
  {
    if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL)) & 1) == 0 )
      goto LABEL_20;
    v18 = *(_QWORD *)(a1 + 16);
    *(_BYTE *)(a1 + 1038) = 0;
    *(_DWORD *)(a1 + 1048) = 0;
    writel_relaxed(1u, (unsigned int *)(v18 + 3160));
    if ( (geni_wait_for_cmd_done(a1, v3 & 1) & 1) != 0 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: tx fsm reset failed\n", "stop_tx_sequencer");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: tx fsm reset failed\n");
      if ( (*(_BYTE *)(a1 + 1036) & 1) != 0 )
        goto LABEL_20;
      v19 = 10;
      *(_DWORD *)(a1 + 1120) = 10;
    }
    else
    {
      if ( (*(_BYTE *)(a1 + 1036) & 1) != 0 )
        goto LABEL_20;
      v19 = 0;
      *(_DWORD *)(a1 + 1120) = 0;
    }
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s uart_error_code %d", "msm_geni_update_uart_error_code", v19);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
LABEL_20:
    v20 = *(_QWORD *)(a1 + 808);
    if ( v20 )
    {
      geni_se_tx_dma_unprep(a1 + 712, v20, *(unsigned int *)(a1 + 816));
      *(_QWORD *)(a1 + 808) = 0;
    }
  }
  msm_geni_serial_enable_interrupts(a1);
  v21 = *(_QWORD *)(a1 + 264);
  *(_BYTE *)(a1 + 1040) = 0;
  *(_DWORD *)(a1 + 816) = 0;
  if ( !v21 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v21 + 74) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s:Removing vote\n", "stop_tx_sequencer");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s:Removing vote\n");
    v23 = *(_QWORD *)(a1 + 344);
    if ( *(_DWORD *)(v23 + 480) )
    {
      if ( (*(_WORD *)(v23 + 488) & 7) == 0 )
      {
        *(_QWORD *)(v23 + 520) = ktime_get_mono_fast_ns(v22);
        _pm_runtime_suspend(*(_QWORD *)(a1 + 344), 13);
      }
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a1 + 952), "%s: Usage Count is already 0\n", "msm_geni_serial_power_off");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Usage Count is already 0\n");
    }
  }
  v24 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: End GENI:0x%x\n", "stop_tx_sequencer", v24);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: End GENI:0x%x\n");
}
