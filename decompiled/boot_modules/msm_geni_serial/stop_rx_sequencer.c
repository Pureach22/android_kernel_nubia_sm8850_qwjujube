__int64 __fastcall stop_rx_sequencer(__int64 a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  int v4; // w20
  __int64 v5; // x1
  __int64 v6; // x8
  unsigned int v7; // w8
  __int64 v8; // x21
  unsigned int v9; // w21
  __int64 v10; // x8
  bool v11; // w0
  __int64 v12; // x9
  bool v13; // w20
  bool v14; // w22
  int v15; // w21
  __int64 v16; // x24
  unsigned int v17; // w26
  int v18; // w0
  __int64 v19; // x24
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x8
  int v23; // w0
  __int64 v24; // x8
  bool v25; // w21
  unsigned int v26; // w22
  int v27; // w21
  unsigned int v28; // w22
  int v29; // w23
  __int64 v30; // x8
  __int64 v31; // x8
  __int64 v32; // x8
  int v33; // w0
  __int64 v34; // x20
  int v35; // w21
  int v36; // w0
  __int64 v37; // x20
  __int64 v38; // x20
  __int64 v39; // x0
  __int64 mono_fast_ns; // x8
  __int64 v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 960);
  v41[0] = 0;
  ipc_log_string(v2, "%s %d\n", "stop_rx_sequencer", 1);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s %d\n");
  if ( *(_DWORD *)(a1 + 1332) )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: already in progress, return\n", "stop_rx_sequencer");
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: already in progress, return\n");
    result = 4294967280LL;
    goto LABEL_45;
  }
  *(_DWORD *)(a1 + 1332) = 1;
  v4 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  if ( (v4 & 0x1000) == 0 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 960), "%s: RX is Inactive, geni_sts: 0x%x\n", "stop_rx_sequencer", v4);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: RX is Inactive, geni_sts: 0x%x\n");
    *(_DWORD *)(a1 + 1332) = 0;
    complete(a1 + 1264);
    result = 0;
    goto LABEL_45;
  }
  if ( *(_BYTE *)(a1 + 1136) == 1 )
  {
    if ( (*(_BYTE *)(a1 + 600) & 1) != 0 || (*(_BYTE *)(a1 + 1337) & 1) != 0 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Queue Rx Work\n", "stop_rx_sequencer");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Queue Rx Work\n");
      v5 = *(_QWORD *)(a1 + 1256);
      *(_DWORD *)(a1 + 1264) = 0;
      queue_work_on(32, v5, a1 + 1184);
      result = 0;
    }
    else
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Port setup not yet done\n", "stop_rx_sequencer");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Port setup not yet done\n");
      result = 0;
      *(_DWORD *)(a1 + 1332) = 0;
    }
    goto LABEL_45;
  }
  v6 = *(_QWORD *)(a1 + 264);
  if ( !v6 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v6 + 74) )
  {
    msm_geni_serial_set_manual_flow(0, a1);
    v7 = 2 * (0x9896800u / *(_DWORD *)(a1 + 1000));
    if ( v7 >= 0x251C )
      v7 = 9500;
    v8 = v7 + 500;
    ipc_log_string(*(_QWORD *)(a1 + 960), "stale_delay = %d usecs\n", (unsigned int)v8);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "stale_delay = %d usecs\n");
    _udelay(v8);
    if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3392LL)) )
    {
      v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 1600LL));
      writel_relaxed(v9, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1608LL));
      geni_se_dump_dbg_regs((_QWORD *)a1);
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Interrupt delay\n", "stop_rx_sequencer");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Interrupt delay\n");
      handle_rx_dma_xfer(v9, a1);
      v10 = *(_QWORD *)(a1 + 344);
      if ( (*(_WORD *)(v10 + 488) & 7) == 0 && !*(_DWORD *)(a1 + 1004) )
      {
        ipc_log_string(
          *(_QWORD *)(a1 + 960),
          "%s: Abort Stop Rx, extend the PM timer, usage_count:%d\n",
          "stop_rx_sequencer",
          *(_DWORD *)(v10 + 480));
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Abort Stop Rx, extend the PM timer, usage_count:%d\n");
        v38 = *(_QWORD *)(a1 + 344);
        mono_fast_ns = ktime_get_mono_fast_ns(v39);
        result = 4294967280LL;
        *(_QWORD *)(v38 + 520) = mono_fast_ns;
        *(_DWORD *)(a1 + 1332) = 0;
        goto LABEL_45;
      }
    }
  }
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: Start 0x%x\n", "stop_rx_sequencer", v4);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: Start 0x%x\n");
  v11 = msm_serial_try_disable_interrupts(a1);
  v12 = *(_QWORD *)(a1 + 712);
  v13 = v11;
  *(_BYTE *)(a1 + 1039) = 0;
  *(_BYTE *)(a1 + 1041) = 1;
  *(_DWORD *)(a1 + 1080) = 0;
  writel_relaxed(4u, (unsigned int *)(v12 + 1588));
  __dsb(0xFu);
  v14 = geni_wait_for_cmd_done(a1, v13);
  v15 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  v16 = *(_QWORD *)(a1 + 960);
  v17 = v15 & 0x1000;
  v18 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL));
  ipc_log_string(v16, "%s: geni_status 0x%x, dma_dbg:0x%x\n", "stop_rx_sequencer", v15, v18);
  v19 = *(_QWORD *)(a1 + 344);
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL));
  _ftrace_dbg(v19, "%s: geni_status 0x%x, dma_dbg:0x%x\n");
  if ( !v14 && (v15 & 0x1000) == 0 )
    goto LABEL_39;
  ipc_log_string(
    *(_QWORD *)(a1 + 960),
    "%s cancel failed timeout:%d is_rx_active:%d 0x%x\n",
    "stop_rx_sequencer",
    v14,
    v17 >> 12,
    v15);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s cancel failed timeout:%d is_rx_active:%d 0x%x\n");
  ipc_log_string(
    *(_QWORD *)(a1 + 984),
    "%s cancel failed timeout:%d is_rx_active:%d 0x%x\n",
    "stop_rx_sequencer",
    v14,
    v17 >> 12,
    v15);
  if ( (*(_BYTE *)(a1 + 1036) & 1) == 0 )
  {
    v20 = *(_QWORD *)(a1 + 960);
    *(_DWORD *)(a1 + 1120) = 11;
    ipc_log_string(v20, "%s uart_error_code %d", "msm_geni_update_uart_error_code", 11);
    _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s uart_error_code %d");
  }
  geni_se_dump_dbg_regs((_QWORD *)a1);
  v21 = *(_QWORD *)(a1 + 264);
  if ( !v21 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v21 + 74) || (v15 & 0x1000) != 0 )
  {
    v22 = *(_QWORD *)(a1 + 16);
    *(_BYTE *)(a1 + 1039) = 0;
    v23 = readl_relaxed((unsigned int *)(v22 + 1600));
    if ( (v23 & 0x10) != 0 )
    {
      v27 = v23;
      writel_relaxed(0x10u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 1608LL));
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s Cancel Command succeeded 0x%x\n", "stop_rx_sequencer", v27);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s Cancel Command succeeded 0x%x\n");
    }
    else
    {
      v24 = *(_QWORD *)(a1 + 712);
      *(_DWORD *)(a1 + 1080) = 0;
      writel_relaxed(2u, (unsigned int *)(v24 + 1588));
      __dsb(0xFu);
      v25 = geni_wait_for_cmd_done(a1, v13);
      v26 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL)) & 0x1000;
      if ( v25 || v26 )
      {
        v28 = v26 >> 12;
        v29 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
        ipc_log_string(
          *(_QWORD *)(a1 + 960),
          "%s abort fail timeout:%d is_rx_active:%d 0x%x\n",
          "stop_rx_sequencer",
          v25,
          v28,
          v29);
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s abort fail timeout:%d is_rx_active:%d 0x%x\n");
        ipc_log_string(
          *(_QWORD *)(a1 + 984),
          "%s abort fail timeout:%d is_rx_active:%d 0x%x\n",
          "stop_rx_sequencer",
          v25,
          v28,
          v29);
        msm_geni_update_uart_error_code(a1, 12);
        geni_se_dump_dbg_regs((_QWORD *)a1);
      }
      else
      {
        msm_geni_update_uart_error_code(a1, 0);
      }
      v30 = *(_QWORD *)(a1 + 264);
      if ( (!v30 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v30 + 74)) && (*(_BYTE *)(a1 + 1008) & 1) == 0 )
        msm_geni_serial_allow_rx((_QWORD *)a1);
      writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(a1 + 16) + 32LL));
      if ( *(_DWORD *)(a1 + 584) != 2 )
        goto LABEL_39;
      v31 = *(_QWORD *)(a1 + 16);
      *(_BYTE *)(a1 + 1039) = 0;
      *(_DWORD *)(a1 + 1080) = 0;
      writel_relaxed(1u, (unsigned int *)(v31 + 3416));
      if ( geni_wait_for_cmd_done(a1, v13) )
      {
        ipc_log_string(*(_QWORD *)(a1 + 960), "%s: rx fsm reset failed\n", "stop_rx_sequencer");
        _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: rx fsm reset failed\n");
        msm_geni_update_uart_error_code(a1, 13);
        geni_se_dump_dbg_regs((_QWORD *)a1);
        goto LABEL_39;
      }
    }
    msm_geni_update_uart_error_code(a1, 0);
LABEL_39:
    msm_geni_serial_enable_interrupts(a1);
    *(_BYTE *)(a1 + 1041) = 0;
    goto LABEL_40;
  }
  msm_geni_serial_handle_isr(a1, v41, 1);
LABEL_40:
  v32 = *(_QWORD *)(a1 + 264);
  if ( (!v32 || *(_DWORD *)(a1 + 316) != *(__int16 *)(v32 + 74)) && (*(_BYTE *)(a1 + 1008) & 1) == 0 )
    msm_geni_serial_set_manual_flow(1, a1);
  v33 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  v34 = *(_QWORD *)(a1 + 960);
  v35 = v33;
  v36 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL));
  ipc_log_string(v34, "%s: End geni_status : 0x%x dma_dbg:0x%x\n", "stop_rx_sequencer", v35, v36);
  v37 = *(_QWORD *)(a1 + 344);
  readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL));
  _ftrace_dbg(v37, "%s: End geni_status : 0x%x dma_dbg:0x%x\n");
  complete(a1 + 1264);
  *(_DWORD *)(a1 + 1332) = 0;
  result = (v35 << 19 >> 31) & 0xFFFFFFF0;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}
