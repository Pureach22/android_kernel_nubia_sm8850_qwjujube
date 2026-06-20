void __fastcall geni_i2c_se_dump_dbg_regs(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w23
  int v7; // w28
  int v8; // w27
  int v9; // w24
  int v10; // w22
  int v11; // w25
  int v12; // w26
  int v13; // [xsp+0h] [xbp-70h]
  int v14; // [xsp+4h] [xbp-6Ch]
  int v15; // [xsp+8h] [xbp-68h]
  int v16; // [xsp+Ch] [xbp-64h]
  int v17; // [xsp+10h] [xbp-60h]
  int v18; // [xsp+14h] [xbp-5Ch]
  int v19; // [xsp+18h] [xbp-58h]
  int v20; // [xsp+1Ch] [xbp-54h]
  int v21; // [xsp+20h] [xbp-50h]
  int v22; // [xsp+24h] [xbp-4Ch]
  int v23; // [xsp+28h] [xbp-48h]
  int v24; // [xsp+2Ch] [xbp-44h]
  int v25; // [xsp+30h] [xbp-40h]
  int v26; // [xsp+34h] [xbp-3Ch]
  int v27; // [xsp+38h] [xbp-38h]
  int v28; // [xsp+3Ch] [xbp-34h]
  int v29; // [xsp+40h] [xbp-30h]
  int v30; // [xsp+44h] [xbp-2Ch]
  int v31; // [xsp+48h] [xbp-28h]
  int v32; // [xsp+4Ch] [xbp-24h]
  int v33; // [xsp+50h] [xbp-20h]
  int v34; // [xsp+54h] [xbp-1Ch]
  int v35; // [xsp+58h] [xbp-18h]
  int v36; // [xsp+5Ch] [xbp-14h]
  int v37; // [xsp+60h] [xbp-10h]
  int v38; // [xsp+64h] [xbp-Ch]
  int v39; // [xsp+68h] [xbp-8h]
  int v40; // [xsp+6Ch] [xbp-4h]

  v6 = readl_relaxed(a2 + 1536);
  v7 = readl_relaxed(a2 + 1552);
  readl_relaxed(a2 + 1584);
  v35 = readl_relaxed(a2 + 1600);
  v13 = readl_relaxed(a2 + 64);
  v8 = readl_relaxed(a2 + 2312);
  v22 = readl_relaxed(a2 + 3136);
  v17 = readl_relaxed(a2 + 3392);
  v15 = readl_relaxed(a2 + 2052);
  v14 = readl_relaxed(a2 + 2048);
  v9 = readl_relaxed(a2 + 3648);
  v21 = readl_relaxed(a2 + 1540);
  v20 = readl_relaxed(a2 + 3388);
  v16 = readl_relaxed(a2 + 3412);
  v25 = readl_relaxed(a2 + 3132);
  v18 = readl_relaxed(a2 + 3156);
  v27 = readl_relaxed(a2 + 1556);
  v26 = readl_relaxed(a2 + 1604);
  v19 = readl_relaxed(a2 + 3144);
  v10 = readl_relaxed(a2 + 3400);
  v28 = readl_relaxed(a2 + 16);
  v39 = readl_relaxed(a2 + 36);
  v31 = readl_relaxed(a2 + 96);
  v30 = readl_relaxed(a2 + 100);
  v29 = readl_relaxed(a2 + 116);
  v40 = readl_relaxed(a2 + 124);
  v11 = readl_relaxed(a2 + 1556);
  v33 = readl_relaxed(a2 + 3128);
  v32 = readl_relaxed(a2 + 3136);
  v36 = readl_relaxed(a2 + 3384);
  v23 = readl_relaxed(a2 + 3392);
  v34 = readl_relaxed(a2 + 3608);
  v12 = readl_relaxed(a2 + 3612);
  v38 = readl_relaxed(a2 + 3616);
  v37 = readl_relaxed(a2 + 3632);
  v24 = readl_relaxed(a2 + 3648);
  ipc_log_string(
    a3,
    "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
    "geni_i2c_se_dump_dbg_regs",
    v6,
    v7,
    v13,
    v8);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(a3, "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n", v17, v22, v15, v14);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(a3, "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n", v9, v21, v20, v16);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(a3, "dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n", v25, v18, v35);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(a3, "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n", v19, v10, v27, v26);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(a3, "geni_dma_tx_irq_en:0x%x, geni_dma_rx_irq_en:0x%x, geni_general_cfg:0x%x\n", v19, v10, v28);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(a3, "geni_clk_ctrl_ro:0x%x, fifo_if_disable_ro:0x%x, geni_fw_multilock_msa_ro:0x%x\n", v31, v30, v29);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(
    a3,
    "m_irq_en:0x%x, se_dma_tx_attr:0x%x se_dma_tx_irq_stat:0x%x, geni_output_ctrl:0x%x\n",
    v11,
    v33,
    v32,
    v39);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(
    a3,
    "se_dma_rx_attr:0x%x, se_dma_rx_irq_stat:0x%x se_gsi_event_en:0x%x se_irq_en:0x%x\n",
    v36,
    v23,
    v34,
    v12);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
  ipc_log_string(
    a3,
    "dma_if_en_ro:0x%x, dma_general_cfg:0x%x dma_debug_reg0:0x%x\n, geni_clk_sel:0x%x",
    v38,
    v37,
    v24,
    v40);
  if ( *(_QWORD *)(a1 + 8) )
    i2c_trace_log();
}
