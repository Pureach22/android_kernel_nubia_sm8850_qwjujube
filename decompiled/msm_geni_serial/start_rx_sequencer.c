void __fastcall start_rx_sequencer(__int64 a1)
{
  int v2; // w20
  int v3; // w8
  __int64 v4; // x21
  __int64 v5; // x20
  __int64 v6; // x8
  __int64 v7; // x22
  unsigned __int64 v8; // x23
  __int64 v9; // x11
  __int64 v10; // x27
  __int64 v11; // x28
  __int64 v12; // x8
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x21
  unsigned __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x9
  __int64 v19; // x12
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 (*v22)(void); // x9
  unsigned int *v23; // x20
  unsigned int *v24; // x20
  int v25; // w0
  __int64 v26; // x20
  int v27; // w21
  int v28; // w0
  __int64 v29; // x20
  __int64 v30; // x8
  __int64 (*v31)(void); // x8
  unsigned int v32; // w0
  void (*v33)(void); // x8
  int v34; // w0
  void (*v35)(void); // x8

  if ( !*(_DWORD *)(a1 + 1516) )
    return;
  v2 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: geni_status 0x%x\n", "start_rx_sequencer", v2);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: geni_status 0x%x\n");
  v3 = *(_DWORD *)(a1 + 584);
  if ( (v2 & 0x1000) != 0 )
  {
    if ( v3 == 3 )
      return;
    if ( v3 == 2 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s: mapping rx dma GENI: 0x%x\n", "start_rx_sequencer", v2);
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: mapping rx dma GENI: 0x%x\n");
      v23 = *(unsigned int **)(a1 + 16);
      if ( v23 )
      {
        if ( *(_QWORD *)(a1 + 872) )
        {
          writel_relaxed(7u, v23 + 851);
          writel_relaxed(*(_DWORD *)(a1 + 872), v23 + 844);
          writel_relaxed(*(_DWORD *)(a1 + 876), v23 + 845);
          writel_relaxed(0, v23 + 846);
          __dsb(0xFu);
          writel_relaxed(0x800u, v23 + 847);
        }
      }
    }
    msm_geni_serial_stop_rx(a1);
    v3 = *(_DWORD *)(a1 + 584);
    goto LABEL_24;
  }
  if ( v3 != 3 )
  {
LABEL_24:
    if ( v3 == 2 )
    {
      ipc_log_string(*(_QWORD *)(a1 + 960), "%s. mapping rx dma\n", "start_rx_sequencer");
      _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s. mapping rx dma\n");
      v24 = *(unsigned int **)(a1 + 16);
      if ( v24 )
      {
        if ( *(_QWORD *)(a1 + 872) )
        {
          writel_relaxed(7u, v24 + 851);
          writel_relaxed(*(_DWORD *)(a1 + 872), v24 + 844);
          writel_relaxed(*(_DWORD *)(a1 + 876), v24 + 845);
          writel_relaxed(0, v24 + 846);
          __dsb(0xFu);
          writel_relaxed(0x800u, v24 + 847);
        }
      }
    }
    readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 712) + 1584LL));
    writel(0x80000E0u, (unsigned int *)(*(_QWORD *)(a1 + 712) + 1584LL));
    msm_geni_serial_enable_interrupts(a1);
    __dsb(0xFu);
    v25 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
    v26 = *(_QWORD *)(a1 + 960);
    v27 = v25;
    v28 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL));
    ipc_log_string(v26, "%s: geni_status 0x%x, dma_dbg:0x%x\n", "start_rx_sequencer", v27, v28);
    v29 = *(_QWORD *)(a1 + 344);
    readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 3648LL));
    _ftrace_dbg(v29, "%s: geni_status 0x%x, dma_dbg:0x%x\n");
    return;
  }
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: start xfer_rx\n", "start_rx_sequencer");
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: start xfer_rx\n");
  if ( (*(_BYTE *)(a1 + 600) & 1) != 0 )
  {
    v4 = *(_QWORD *)(a1 + 1144);
    v5 = *(_QWORD *)(a1 + 624);
    if ( (unsigned int)msm_geni_allocate_chan(a1) )
    {
      dev_err(*(_QWORD *)(a1 + 344), "%s: Allocation of Channel failed\n", "msm_geni_uart_gsi_xfer_rx");
    }
    else
    {
      sg_init_table(*(_QWORD *)(a1 + 1144) + 400LL, 6);
      v6 = *(_QWORD *)(a1 + 1144);
      v7 = 0;
      v8 = 0;
      v9 = *(_QWORD *)(v6 + 400);
      *(_DWORD *)(v6 + 412) = 16;
      v10 = 464;
      *(_DWORD *)(v6 + 408) = (v6 + 32) & 0xFFF;
      v11 = 96;
      *(_QWORD *)(v6 + 400) = (v9 & 3 | ((unsigned __int64)(((v6 + 32) << 8 >> 8) + 0x8000000000LL) >> 12 << 6))
                            - 0x140000000LL;
      *(_QWORD *)(v4 + 64) = 1;
      *(_QWORD *)(v4 + 72) = 0x20000100000000LL;
      v12 = *(_QWORD *)(a1 + 1144);
      v13 = *(_QWORD *)(v12 + 432);
      *(_DWORD *)(v12 + 440) = (v4 + 64) & 0xFFF;
      *(_DWORD *)(v12 + 444) = 16;
      *(_QWORD *)(v12 + 432) = (v13 & 3 | ((unsigned __int64)(((v4 + 64) << 8 >> 8) + 0x8000000000LL) >> 12 << 6))
                             - 0x140000000LL;
      do
      {
        v14 = a1 + v7;
        if ( !v5 || (v15 = v14 + 880, v14 == -880) )
        {
          *(_QWORD *)(v14 + 832) = -22;
LABEL_30:
          if ( v7 )
          {
            if ( v5 && a1 + v7 != -872 && *(_QWORD *)(a1 + v7 + 824) )
              dma_free_attrs(v5, 2048);
            if ( v8 >= 2 )
            {
              if ( v5 && a1 + v7 != -864 && *(_QWORD *)(a1 + v7 + 816) )
                dma_free_attrs(v5, 2048);
              if ( v8 - 1 >= 2 && v5 && a1 + v7 != -856 && *(_QWORD *)(a1 + v7 + 808) )
                dma_free_attrs(v5, 2048);
            }
          }
          dma_release_channel(*(_QWORD *)(*(_QWORD *)(a1 + 1144) + 8LL));
          dma_release_channel(**(_QWORD **)(a1 + 1144));
          *(_QWORD *)(*(_QWORD *)(a1 + 1144) + 8LL) = 0;
          **(_QWORD **)(a1 + 1144) = 0;
          goto LABEL_46;
        }
        *(_QWORD *)v15 = -1;
        v16 = dma_alloc_attrs(v5, 2048, v14 + 880, 3264, 0);
        *(_QWORD *)(a1 + v7 + 832) = v16;
        if ( !v16 || v16 >= 0xFFFFFFFFFFFFF001LL )
          goto LABEL_30;
        ++v8;
        *(_DWORD *)(*(_QWORD *)(a1 + 1144) + v11) = *(_QWORD *)v15;
        *(_DWORD *)(*(_QWORD *)(a1 + 1144) + v11 + 4) = *(_DWORD *)(v15 + 4);
        *(_DWORD *)(*(_QWORD *)(a1 + 1144) + v11 + 8) = 2048;
        *(_DWORD *)(*(_QWORD *)(a1 + 1144) + v11 + 12) = 1049345;
        v17 = *(_QWORD *)(a1 + 1144);
        v18 = v11 + v17;
        v11 += 16;
        v19 = v17 + 4 * v7;
        v7 += 8;
        *(_QWORD *)(v17 + v10) = (((unsigned __int64)((v18 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL)
                               | *(_QWORD *)(v17 + v10) & 3LL;
        v10 += 32;
        *(_DWORD *)(v19 + 472) = v18 & 0xFFF;
        *(_DWORD *)(v19 + 476) = 16;
      }
      while ( v7 != 32 );
      v20 = *(_QWORD *)(a1 + 1144);
      v21 = *(_QWORD *)(v20 + 8);
      if ( v21 )
      {
        if ( *(_QWORD *)v21 && (v22 = *(__int64 (**)(void))(*(_QWORD *)v21 + 272LL)) != nullptr )
        {
          if ( *((_DWORD *)v22 - 1) != -1221891457 )
            __break(0x8229u);
          v21 = v22();
          v20 = *(_QWORD *)(a1 + 1144);
        }
        else
        {
          v21 = 0;
        }
      }
      *(_QWORD *)(v20 + 600) = v21;
      v30 = *(_QWORD *)(*(_QWORD *)(a1 + 1144) + 600LL);
      if ( v30 )
      {
        *(_QWORD *)(v30 + 40) = msm_geni_uart_gsi_rx_cb;
        *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1144) + 600LL) + 56LL) = *(_QWORD *)(a1 + 1144) + 656LL;
        v31 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(a1 + 1144) + 600LL) + 24LL);
        if ( *((_DWORD *)v31 - 1) != 1188179853 )
          __break(0x8228u);
        v32 = v31();
        if ( (v32 & 0x80000000) == 0 )
        {
          v33 = *(void (**)(void))(**(_QWORD **)(*(_QWORD *)(a1 + 1144) + 8LL) + 360LL);
          if ( *((_DWORD *)v33 - 1) != 905352215 )
            __break(0x8228u);
          v33();
          *(_BYTE *)(a1 + 1337) = 1;
          goto LABEL_55;
        }
        printk(&unk_14AEE, "msm_geni_uart_gsi_xfer_rx", v32);
        v35 = *(void (**)(void))(**(_QWORD **)(*(_QWORD *)(a1 + 1144) + 8LL) + 336LL);
        if ( v35 )
        {
          if ( *((_DWORD *)v35 - 1) != -403578064 )
            __break(0x8228u);
          v35();
        }
      }
      else
      {
        dev_err(*(_QWORD *)(a1 + 344), "%s: Rx desc is failed\n", "msm_geni_uart_gsi_xfer_rx");
        if ( *(_QWORD *)(a1 + 832) )
          dma_free_attrs(v5, 2048);
        if ( a1 != -888 && *(_QWORD *)(a1 + 840) )
          dma_free_attrs(v5, 2048);
        if ( a1 != -896 && *(_QWORD *)(a1 + 848) )
          dma_free_attrs(v5, 2048);
        if ( a1 != -904 && *(_QWORD *)(a1 + 856) )
          dma_free_attrs(v5, 2048);
        dma_release_channel(*(_QWORD *)(*(_QWORD *)(a1 + 1144) + 8LL));
        dma_release_channel(**(_QWORD **)(a1 + 1144));
        *(_QWORD *)(*(_QWORD *)(a1 + 1144) + 8LL) = 0;
        **(_QWORD **)(a1 + 1144) = 0;
        *(_BYTE *)(a1 + 1337) = 0;
      }
    }
  }
  else
  {
    dev_err(*(_QWORD *)(a1 + 344), "%s: Port setup not yet done\n", "msm_geni_uart_gsi_xfer_rx");
  }
LABEL_46:
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: RX xfer is failed\n", "start_rx_sequencer");
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: RX xfer is failed\n");
LABEL_55:
  v34 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 16) + 64LL));
  ipc_log_string(*(_QWORD *)(a1 + 960), "%s: xfer_rx done. geni_status:0x%x\n", "start_rx_sequencer", v34);
  _ftrace_dbg(*(_QWORD *)(a1 + 344), "%s: xfer_rx done. geni_status:0x%x\n");
}
