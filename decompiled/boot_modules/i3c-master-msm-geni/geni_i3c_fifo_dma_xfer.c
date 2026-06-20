__int64 __fastcall geni_i3c_fifo_dma_xfer(__int64 *a1, _DWORD *a2)
{
  __int64 *v3; // x23
  unsigned int v5; // w21
  __int64 v6; // x20
  __int64 v7; // x8
  __int64 v8; // x23
  int v9; // w24
  int v10; // w25
  int v11; // w0
  const char *v12; // x2
  unsigned int v13; // w23
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x0
  __int64 v17; // x23
  int v18; // w24
  int v19; // w25
  int v20; // w0
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x9
  const char *v26; // x2
  __int64 v27; // x1
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x0
  __int64 v31; // x24
  const char *v32; // x2
  __int64 v33; // x2
  __int64 v34; // x3
  __int64 v35; // x0
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 v38; // x0
  int v39; // w2
  __int64 v41; // x24
  const char *v42; // x2
  __int64 v43; // x2
  __int64 v44; // x3
  __int64 v45; // x0
  __int64 v46; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v47[2]; // [xsp+10h] [xbp-10h] BYREF

  v3 = a1 + 2560;
  v47[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *((_DWORD *)a1 + 638) = 0;
  v5 = *((_DWORD *)a1 + 5318);
  v6 = *((unsigned int *)a1 + 5319);
  v46 = 0;
  v47[0] = 0;
  ((void (*)(void))geni_se_select_mode)();
  v7 = *a1;
  *((_DWORD *)a1 + 26) = 0;
  *((_DWORD *)v3 + 200) = 0;
  if ( v5 == 1 )
  {
    writel_relaxed(v6, (unsigned int *)(v7 + 624));
    writel(a2[2] & 0x7FFFFFF | ((unsigned __int8)a2[1] << 27), *a1 + 1536);
    v8 = a1[316];
    v9 = a2[1];
    v10 = a2[2];
    v11 = readl_relaxed((unsigned int *)(*a1 + 1536));
    ipc_log_string(v8, "I3C cmd:0x%x param:0x%x READ len:%d, m_cmd: 0x%x\n", v9, v10, v6, v11);
    if ( a1[1] )
    {
      readl_relaxed((unsigned int *)(*a1 + 1536));
      i3c_trace_log();
    }
    if ( *a2 == 2 )
    {
      v13 = geni_se_rx_dma_prep(a1, a1[2658], v6, &v46);
      if ( v13 )
      {
        ipc_log_string(a1[316], "DMA Err:%d FIFO mode enabled\n", v13);
        v16 = a1[1];
        if ( v16 )
          dev_err(v16, "DMA Err:%d FIFO mode enabled\n", v13);
        else
          printk(&unk_13268, v13, v14, v15);
        if ( a1[1] )
          i3c_trace_log();
        *a2 = 1;
        geni_se_select_mode(a1, 1);
      }
    }
    else
    {
      v13 = 0;
    }
  }
  else
  {
    writel_relaxed(v6, (unsigned int *)(v7 + 620));
    writel(a2[2] & 0x7FFFFFF | ((unsigned __int8)a2[1] << 27), *a1 + 1536);
    v17 = a1[316];
    v18 = a2[1];
    v19 = a2[2];
    v20 = readl_relaxed((unsigned int *)(*a1 + 1536));
    ipc_log_string(v17, "I3C cmd:0x%x param:0x%x WRITE len:%d, m_cmd: 0x%x\n", v18, v19, v6, v20);
    if ( a1[1] )
    {
      readl_relaxed((unsigned int *)(*a1 + 1536));
      i3c_trace_log();
    }
    if ( *a2 == 2 )
    {
      v13 = geni_se_tx_dma_prep(a1, a1[2658], v6, v47);
      if ( v13 )
      {
        ipc_log_string(a1[316], "DMA Err:%d FIFO mode enabled\n", v13);
        v23 = a1[1];
        if ( v23 )
          dev_err(v23, "DMA Err:%d FIFO mode enabled\n", v13);
        else
          printk(&unk_13268, v13, v21, v22);
        if ( a1[1] )
          i3c_trace_log();
        *a2 = 1;
        geni_se_select_mode(a1, 1);
      }
    }
    else
    {
      v13 = 0;
    }
    if ( *a2 == 1 && (_DWORD)v6 )
      writel_relaxed(1u, (unsigned int *)(*a1 + 2060));
  }
  if ( !(unsigned int)wait_for_completion_timeout(a1 + 319, &print_fmt_i3c_log_info[2], v12) )
  {
    ipc_log_string(a1[316], "wait_for_completion timed out\n");
    v30 = a1[1];
    if ( v30 )
      dev_err(v30, "wait_for_completion timed out\n");
    else
      printk(&unk_14DD3, v27, v28, v29);
    if ( a1[1] )
      i3c_trace_log();
    geni_i3c_err(a1, 9);
    *((_DWORD *)a1 + 638) = 0;
    a1[2658] = 0;
    a1[2659] = 0;
    *((_DWORD *)a1 + 5320) = 0;
    v31 = raw_spin_lock_irqsave((char *)a1 + 21244);
    writel_relaxed(4u, (unsigned int *)(*a1 + 1540));
    raw_spin_unlock_irqrestore((char *)a1 + 21244, v31);
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 319, &print_fmt_i3c_log_info[2], v32) )
    {
      ipc_log_string(a1[316], "%s:Cancel failed: Aborting\n", "geni_i3c_fifo_dma_xfer");
      v35 = a1[1];
      if ( v35 )
        dev_err(v35, "%s:Cancel failed: Aborting\n", "geni_i3c_fifo_dma_xfer");
      else
        printk(&unk_1287C, "geni_i3c_fifo_dma_xfer", v33, v34);
      if ( a1[1] )
        i3c_trace_log();
      geni_i3c_dump_dbg_regs(a1);
      *((_DWORD *)a1 + 638) = 0;
      v41 = raw_spin_lock_irqsave((char *)a1 + 21244);
      writel_relaxed(2u, (unsigned int *)(*a1 + 1540));
      raw_spin_unlock_irqrestore((char *)a1 + 21244, v41);
      if ( !(unsigned int)wait_for_completion_timeout(a1 + 319, &print_fmt_i3c_log_info[2], v42) )
      {
        ipc_log_string(a1[316], "%s:Abort Failed\n", "geni_i3c_fifo_dma_xfer");
        v45 = a1[1];
        if ( v45 )
          dev_err(v45, "%s:Abort Failed\n", "geni_i3c_fifo_dma_xfer");
        else
          printk(&unk_1400B, "geni_i3c_fifo_dma_xfer", v43, v44);
        if ( a1[1] )
          i3c_trace_log();
        geni_i3c_dump_dbg_regs(a1);
      }
    }
  }
  if ( *a2 == 2 )
  {
    if ( !*((_DWORD *)a1 + 26) )
      goto LABEL_25;
    v24 = *a1;
    v25 = 3160;
    *((_DWORD *)a1 + 638) = 0;
    if ( v5 == 1 )
      v25 = 3416;
    writel_relaxed(1u, (unsigned int *)(v24 + v25));
    if ( !(unsigned int)wait_for_completion_timeout(a1 + 319, &print_fmt_i3c_log_info[2], v26) )
    {
      ipc_log_string(a1[316], "Timeout:FSM Reset, rnw:%d\n", v5);
      v38 = a1[1];
      if ( v38 )
        dev_err(v38, "Timeout:FSM Reset, rnw:%d\n", v5);
      else
        printk(&unk_129F0, v5, v36, v37);
      if ( a1[1] )
        i3c_trace_log();
      geni_i3c_dump_dbg_regs(a1);
      if ( v5 == 1 )
        goto LABEL_26;
    }
    else
    {
LABEL_25:
      if ( v5 == 1 )
      {
LABEL_26:
        geni_se_rx_dma_unprep(a1, v46, v6);
        goto LABEL_42;
      }
    }
    geni_se_tx_dma_unprep(a1, v47[0], v6);
  }
LABEL_42:
  v39 = *((_DWORD *)a1 + 26);
  if ( v39 == -16 )
  {
    v13 = 3;
  }
  else
  {
    if ( !v39 )
      goto LABEL_48;
    v13 = *((_DWORD *)a1 + 26);
  }
  ipc_log_string(a1[316], "I3C transaction error:%d\n", v39);
  if ( a1[1] )
    i3c_trace_log();
LABEL_48:
  *((_DWORD *)a1 + 26) = 0;
  a1[2658] = 0;
  a1[2659] = 0;
  _ReadStatusReg(SP_EL0);
  *((_DWORD *)a1 + 5320) = 0;
  return v13;
}
