void __fastcall geni_i3c_se_dump_dbg_regs(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w21
  int v7; // w24
  int v8; // w25
  int v9; // w22
  int v10; // w23
  int v11; // w27
  int v12; // w26
  int v13; // [xsp+8h] [xbp-38h]
  int v14; // [xsp+Ch] [xbp-34h]
  int v15; // [xsp+10h] [xbp-30h]
  int v16; // [xsp+14h] [xbp-2Ch]
  int v17; // [xsp+18h] [xbp-28h]
  int v18; // [xsp+1Ch] [xbp-24h]
  int v19; // [xsp+20h] [xbp-20h]
  int v20; // [xsp+24h] [xbp-1Ch]
  int v21; // [xsp+28h] [xbp-18h]
  int v22; // [xsp+2Ch] [xbp-14h]
  int v23; // [xsp+30h] [xbp-10h]
  int v24; // [xsp+34h] [xbp-Ch]
  int v25; // [xsp+38h] [xbp-8h]
  int v26; // [xsp+3Ch] [xbp-4h]

  v6 = readl_relaxed(a2 + 1536);
  v13 = readl_relaxed(a2 + 1552);
  readl_relaxed(a2 + 1584);
  v26 = readl_relaxed(a2 + 1600);
  v7 = readl_relaxed(a2 + 64);
  v8 = readl_relaxed(a2 + 2312);
  v18 = readl_relaxed(a2 + 3136);
  v15 = readl_relaxed(a2 + 3392);
  v9 = readl_relaxed(a2 + 2052);
  v10 = readl_relaxed(a2 + 2048);
  v19 = readl_relaxed(a2 + 3648);
  v17 = readl_relaxed(a2 + 1540);
  v16 = readl_relaxed(a2 + 3388);
  v14 = readl_relaxed(a2 + 3412);
  v21 = readl_relaxed(a2 + 3132);
  v20 = readl_relaxed(a2 + 3156);
  v24 = readl_relaxed(a2 + 1556);
  v23 = readl_relaxed(a2 + 1604);
  v22 = readl_relaxed(a2 + 3144);
  v11 = readl_relaxed(a2 + 3400);
  v25 = readl_relaxed(a2 + 3120);
  v12 = readl_relaxed(a2 + 3124);
  ipc_log_string(
    a3,
    "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
    "geni_i3c_se_dump_dbg_regs",
    v6,
    v13,
    v7,
    v8);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(a3, "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n", v15, v18, v9, v10);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(a3, "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n", v19, v17, v16, v14);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(a3, "dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n", v21, v20, v26);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(a3, "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n", v22, v11, v24, v23);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
  ipc_log_string(a3, "geni_dma_tx_ptr_l:0x%x, geni_dma_tx_ptr_h:0x%x\n", v25, v12);
  if ( *(_QWORD *)(a1 + 8) )
    i3c_trace_log();
}
