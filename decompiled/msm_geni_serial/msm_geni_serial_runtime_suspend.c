__int64 __fastcall msm_geni_serial_runtime_suspend(__int64 a1)
{
  __int64 v1; // x19
  int v3; // w0
  __int64 v4; // x0
  __int64 v5; // x22
  unsigned __int64 v6; // x21
  int v7; // w0
  int v8; // w0
  int v9; // w0
  int v11; // w0
  int v12; // w22
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned int v15; // w23
  __int64 v16; // x22
  __int64 v17; // x0
  unsigned int v18; // w21

  v1 = *(_QWORD *)(a1 + 152);
  v3 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 16) + 64LL));
  ipc_log_string(*(_QWORD *)(v1 + 952), "%s: Start geni_status : 0x%x\n", "msm_geni_serial_runtime_suspend", v3);
  _ftrace_dbg(a1, "%s: Start geni_status : 0x%x\n");
  v5 = *(_QWORD *)(v1 + 968);
  if ( v5 )
  {
    if ( *(_DWORD *)(v1 + 916) )
    {
      v6 = sched_clock(v4);
      ipc_log_string(v5, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_serial_runtime_suspend", v6, v6 / 0x3E8);
      if ( !*(_BYTE *)(v1 + 924) )
        goto LABEL_10;
    }
    else
    {
      v6 = 0;
      if ( !*(_BYTE *)(v1 + 924) )
        goto LABEL_10;
    }
  }
  else
  {
    v6 = -22;
    if ( !*(_BYTE *)(v1 + 924) )
      goto LABEL_10;
  }
  if ( *(_DWORD *)(v1 + 920) )
    msm_geni_serial_set_manual_flow(0, v1);
LABEL_10:
  if ( *(_DWORD *)(v1 + 1516) == 2 )
  {
    v7 = wait_for_transfers_inflight(v1);
    if ( v7 )
    {
      ipc_log_string(
        *(_QWORD *)(v1 + 960),
        "%s: wait_for_transfer_inflight return ret:%d\n",
        "msm_geni_serial_runtime_suspend",
        v7);
      _ftrace_dbg(a1, "%s: wait_for_transfer_inflight return ret:%d\n");
      if ( *(_BYTE *)(v1 + 924) && *(_DWORD *)(v1 + 920) )
      {
LABEL_18:
        writel_relaxed(0x80000001, (unsigned int *)(*(_QWORD *)(v1 + 16) + 684LL));
        __dsb(0xFu);
        v9 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 16) + 684LL));
        ipc_log_string(*(_QWORD *)(v1 + 960), "%s(): rfr = 0x%x\n", "msm_geni_serial_allow_rx", v9);
        _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s(): rfr = 0x%x\n");
        msm_geni_serial_set_manual_flow(1, v1);
        return 4294967280LL;
      }
      return 4294967280LL;
    }
  }
  v8 = stop_rx_sequencer(v1);
  if ( v8 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 952), "%s: stop rx failed %d\n", "msm_geni_serial_runtime_suspend", v8);
    _ftrace_dbg(a1, "%s: stop rx failed %d\n");
    if ( *(_BYTE *)(v1 + 924) && *(_DWORD *)(v1 + 920) )
      goto LABEL_18;
    return 4294967280LL;
  }
  if ( (readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 16) + 64LL)) & 1) != 0 )
    stop_tx_sequencer(v1);
  disable_irq(*(unsigned int *)(v1 + 168));
  if ( *(_BYTE *)(v1 + 924) && *(_DWORD *)(v1 + 920) && *(_DWORD *)(v1 + 1516) == 2 )
  {
    writel_relaxed(0x80000001, (unsigned int *)(*(_QWORD *)(v1 + 16) + 684LL));
    __dsb(0xFu);
    v11 = readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 16) + 684LL));
    ipc_log_string(*(_QWORD *)(v1 + 960), "%s(): rfr = 0x%x\n", "msm_geni_serial_allow_rx", v11);
    _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s(): rfr = 0x%x\n");
    msm_geni_serial_set_manual_flow(1, v1);
  }
  v12 = 0;
  while ( *(_DWORD *)(v1 + 1332) )
  {
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    _const_udelay(4295000);
    if ( ++v12 == 11 )
    {
      ipc_log_string(*(_QWORD *)(v1 + 952), "%s: return, stop_rx_seq busy\n", "msm_geni_serial_runtime_suspend");
      _ftrace_dbg(a1, "%s: return, stop_rx_seq busy\n");
      enable_irq(*(unsigned int *)(v1 + 168));
      return 4294967280LL;
    }
  }
  if ( v12 )
  {
    ipc_log_string(*(_QWORD *)(v1 + 952), "%s: count=%d\n", "msm_geni_serial_runtime_suspend", v12);
    _ftrace_dbg(a1, "%s: count=%d\n");
  }
  ipc_log_string(
    *(_QWORD *)(v1 + 960),
    "%s: enable:%d ser_clk_cfg:%lu\n",
    "msm_geni_enable_disable_se_clk",
    0,
    *(_QWORD *)(v1 + 1128));
  _ftrace_dbg(*(_QWORD *)(v1 + 344), "%s: enable:%d ser_clk_cfg:%lu\n");
  writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(v1 + 16) + 72LL));
  writel_relaxed(1u, (unsigned int *)(*(_QWORD *)(v1 + 16) + 76LL));
  readl_relaxed((unsigned int *)(*(_QWORD *)(v1 + 16) + 72LL));
  v13 = msm_geni_serial_resources_off(v1);
  if ( (_DWORD)v13 )
  {
    v18 = v13;
    dev_err(a1, "%s: Error ret %d\n", "msm_geni_serial_runtime_suspend", v13);
    msm_geni_update_uart_error_code(v1, 6);
    return v18;
  }
  else
  {
    if ( *(_DWORD *)(v1 + 1516) == 2
      && (v13 = *(unsigned int *)(v1 + 920), (int)v13 >= 1)
      && *(_QWORD *)(*(_QWORD *)(v1 + 208) + 152LL) )
    {
      *(_DWORD *)(v1 + 1344) = 0;
      enable_irq(v13);
      v14 = *(unsigned int *)(v1 + 920);
      *(_BYTE *)(v1 + 1042) = 1;
      v13 = irq_set_irq_wake(v14, 1);
      v15 = 0;
      if ( (_DWORD)v13 )
      {
        v15 = v13;
        v13 = dev_err(a1, "%s:Failed to set IRQ wake:%d\n", "msm_geni_serial_runtime_suspend", v13);
      }
    }
    else
    {
      v15 = 0;
    }
    v16 = *(_QWORD *)(v1 + 968);
    if ( v16 && v6 && *(_DWORD *)(v1 + 916) )
    {
      v17 = sched_clock(v13);
      ipc_log_string(
        v16,
        "%s:took %llu nsec(%llu usec)\n",
        "msm_geni_serial_runtime_suspend",
        v17 - v6,
        (v17 - v6) / 0x3E8);
    }
    ipc_log_string(*(_QWORD *)(v1 + 952), "%s: End %d\n", "msm_geni_serial_runtime_suspend", v15);
    _ftrace_dbg(a1, "%s: End %d\n");
    _pm_relax(*(_QWORD *)(v1 + 928));
    return v15;
  }
}
