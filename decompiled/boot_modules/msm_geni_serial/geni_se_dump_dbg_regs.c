__int64 __fastcall geni_se_dump_dbg_regs(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x21
  int v4; // w22
  int v5; // w23
  int v6; // w25
  int v7; // w20
  int v8; // w24
  int v9; // w27
  int v10; // w26
  int v12; // [xsp+Ch] [xbp-C4h]
  int v13; // [xsp+10h] [xbp-C0h]
  int v14; // [xsp+14h] [xbp-BCh]
  int v15; // [xsp+18h] [xbp-B8h]
  int v16; // [xsp+1Ch] [xbp-B4h]
  int v17; // [xsp+20h] [xbp-B0h]
  int v18; // [xsp+24h] [xbp-ACh]
  int v19; // [xsp+28h] [xbp-A8h]
  int v20; // [xsp+2Ch] [xbp-A4h]
  int v21; // [xsp+30h] [xbp-A0h]
  int v22; // [xsp+34h] [xbp-9Ch]
  int v23; // [xsp+38h] [xbp-98h]
  int v24; // [xsp+3Ch] [xbp-94h]
  int v25; // [xsp+40h] [xbp-90h]
  int v26; // [xsp+44h] [xbp-8Ch]
  int v27; // [xsp+48h] [xbp-88h]
  int v28; // [xsp+4Ch] [xbp-84h]
  int v29; // [xsp+50h] [xbp-80h]
  int v30; // [xsp+54h] [xbp-7Ch]
  int v31; // [xsp+58h] [xbp-78h]
  int v32; // [xsp+5Ch] [xbp-74h]
  int v33; // [xsp+60h] [xbp-70h]
  int v34; // [xsp+64h] [xbp-6Ch]
  int v35; // [xsp+68h] [xbp-68h]
  int v36; // [xsp+6Ch] [xbp-64h]
  int v37; // [xsp+70h] [xbp-60h]
  int v38; // [xsp+74h] [xbp-5Ch]
  int v39; // [xsp+78h] [xbp-58h]
  int v40; // [xsp+7Ch] [xbp-54h]
  int v41; // [xsp+80h] [xbp-50h]
  int v42; // [xsp+84h] [xbp-4Ch]
  int v43; // [xsp+88h] [xbp-48h]
  int v44; // [xsp+8Ch] [xbp-44h]
  int v45; // [xsp+90h] [xbp-40h]
  int v46; // [xsp+94h] [xbp-3Ch]
  int v47; // [xsp+98h] [xbp-38h]
  int v48; // [xsp+9Ch] [xbp-34h]
  int v49; // [xsp+A0h] [xbp-30h]
  int v50; // [xsp+A4h] [xbp-2Ch]
  int v51; // [xsp+A8h] [xbp-28h]
  int v52; // [xsp+ACh] [xbp-24h]
  int v53; // [xsp+B0h] [xbp-20h]
  int v54; // [xsp+B4h] [xbp-1Ch]
  int v55; // [xsp+B8h] [xbp-18h]
  int v56; // [xsp+BCh] [xbp-14h]
  int v57; // [xsp+C0h] [xbp-10h]
  int v58; // [xsp+C4h] [xbp-Ch]

  v1 = a1[43];
  v2 = a1[2];
  if ( *(_DWORD *)(v1 + 500) && (*(_WORD *)(v1 + 488) & 7) == 0 )
  {
    ipc_log_string(a1[120], "%s: Device is not in active state, Return\n", "geni_se_dump_dbg_regs");
    return _ftrace_dbg(a1[43], "%s: Device is not in active state, Return\n", "geni_se_dump_dbg_regs");
  }
  else
  {
    v4 = readl_relaxed(v2 + 1536);
    v5 = readl_relaxed(v2 + 1552);
    readl_relaxed(v2 + 1584);
    v58 = readl_relaxed(v2 + 1600);
    v6 = readl_relaxed(v2 + 64);
    v7 = readl_relaxed(v2 + 2312);
    v21 = readl_relaxed(v2 + 3136);
    v13 = readl_relaxed(v2 + 3392);
    v8 = readl_relaxed(v2 + 2052);
    v9 = readl_relaxed(v2 + 2048);
    v20 = readl_relaxed(v2 + 3648);
    v15 = readl_relaxed(v2 + 1540);
    v12 = readl_relaxed(v2 + 3388);
    v10 = readl_relaxed(v2 + 3412);
    v22 = readl_relaxed(v2 + 3132);
    v16 = readl_relaxed(v2 + 3156);
    v47 = readl_relaxed(v2 + 1556);
    v37 = readl_relaxed(v2 + 1604);
    v19 = readl_relaxed(v2 + 3144);
    v14 = readl_relaxed(v2 + 3400);
    v44 = readl_relaxed(v2 + 72);
    v34 = readl_relaxed(v2 + 76);
    v26 = readl_relaxed(v2 + 556);
    v17 = readl_relaxed(v2 + 576);
    v46 = readl_relaxed(v2 + 584);
    v36 = readl_relaxed(v2 + 604);
    v28 = readl_relaxed(v2 + 640);
    v18 = readl_relaxed(v2 + 616);
    v49 = readl_relaxed(v2 + 620);
    v40 = readl_relaxed(v2 + 624);
    v30 = readl_relaxed(v2 + 652);
    v23 = readl_relaxed(v2 + 660);
    v51 = readl_relaxed(v2 + 676);
    v42 = readl_relaxed(v2 + 680);
    v32 = readl_relaxed(v2 + 684);
    v24 = readl_relaxed(v2 + 2060);
    v53 = readl_relaxed(v2 + 2064);
    v43 = readl_relaxed(v2 + 2068);
    v33 = readl_relaxed(v2 + 16);
    v25 = readl_relaxed(v2 + 1572);
    v54 = readl_relaxed(v2 + 1576);
    v45 = readl_relaxed(v2 + 3412);
    v35 = readl_relaxed(v2 + 2320);
    v27 = readl_relaxed(v2 + 2324);
    v55 = readl_relaxed(v2 + 3120);
    v48 = readl_relaxed(v2 + 3124);
    v39 = readl_relaxed(v2 + 3128);
    v29 = readl_relaxed(v2 + 3164);
    v56 = readl_relaxed(v2 + 3376);
    v50 = readl_relaxed(v2 + 3380);
    v41 = readl_relaxed(v2 + 3384);
    v31 = readl_relaxed(v2 + 3420);
    v57 = readl_relaxed(v2 + 4);
    v52 = readl_relaxed(v2 + 96);
    v38 = readl_relaxed(v2 + 100);
    ipc_log_string(
      a1[120],
      "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
      "geni_se_dump_dbg_regs",
      v4,
      v5,
      v6,
      v7);
    _ftrace_dbg(
      a1[43],
      "%s: m_cmd0:0x%x, m_irq_status:0x%x, geni_status:0x%x, geni_ios:0x%x\n",
      "geni_se_dump_dbg_regs",
      v4,
      v5,
      v6,
      v7);
    ipc_log_string(a1[120], "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n", v13, v21, v8, v9);
    _ftrace_dbg(a1[43], "dma_rx_irq:0x%x, dma_tx_irq:0x%x, rx_fifo_sts:0x%x, tx_fifo_sts:0x%x\n", v13, v21, v8, v9);
    ipc_log_string(a1[120], "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n", v20, v15, v12, v10);
    _ftrace_dbg(a1[43], "se_dma_dbg:0x%x, m_cmd_ctrl:0x%x, dma_rxlen:0x%x, dma_rxlen_in:0x%x\n", v20, v15, v12, v10);
    ipc_log_string(a1[120], "dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n", v22, v16, v58);
    _ftrace_dbg(a1[43], "dma_txlen:0x%x, dma_txlen_in:0x%x s_irq_status:0x%x\n", v22, v16, v58);
    ipc_log_string(
      a1[120],
      "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
      v19,
      v14,
      v47,
      v37);
    _ftrace_dbg(
      a1[43],
      "dma_txirq_en:0x%x, dma_rxirq_en:0x%x geni_m_irq_en:0x%x geni_s_irq_en:0x%x\n",
      v19,
      v14,
      v47,
      v37);
    ipc_log_string(
      a1[120],
      "ser_m_clk_cfg:0x%x, ser_s_clk_cfg:0x%x loopback_cfg:0x%x io_macro_ctrl:0x%x\n",
      v44,
      v34,
      v26,
      v17);
    _ftrace_dbg(
      a1[43],
      "ser_m_clk_cfg:0x%x, ser_s_clk_cfg:0x%x loopback_cfg:0x%x io_macro_ctrl:0x%x\n",
      v44,
      v34,
      v26,
      v17);
    ipc_log_string(a1[120], "io3_val:0x%x, tx_trans_cfg:0x%x rx_trans_cfg:0x%x tx_word_len:0x%x\n", v46, v36, v28, v18);
    _ftrace_dbg(a1[43], "io3_val:0x%x, tx_trans_cfg:0x%x rx_trans_cfg:0x%x tx_word_len:0x%x\n", v46, v36, v28, v18);
    ipc_log_string(
      a1[120],
      "stop_bit_len:0x%x, tx_trans_len:0x%x rx_word_len:0x%x rx_stale_cnt:0x%x\n",
      v49,
      v40,
      v30,
      v23);
    _ftrace_dbg(a1[43], "stop_bit_len:0x%x, tx_trans_len:0x%x rx_word_len:0x%x rx_stale_cnt:0x%x\n", v49, v40, v30, v23);
    ipc_log_string(
      a1[120],
      "tx_parity_cfg:0x%x, rx_parity_cfg:0x%x manual_rfr:0x%x tx_watermark:0x%x\n",
      v51,
      v42,
      v32,
      v24);
    _ftrace_dbg(
      a1[43],
      "tx_parity_cfg:0x%x, rx_parity_cfg:0x%x manual_rfr:0x%x tx_watermark:0x%x\n",
      v51,
      v42,
      v32,
      v24);
    ipc_log_string(
      a1[120],
      "rx_watermark:0x%x, rx_watermark_rfr:0x%x se_geni_general_cfg:0x%x m_cmd_err:0x%x\n",
      v53,
      v43,
      v33,
      v25);
    _ftrace_dbg(
      a1[43],
      "rx_watermark:0x%x, rx_watermark_rfr:0x%x se_geni_general_cfg:0x%x m_cmd_err:0x%x\n",
      v53,
      v43,
      v33,
      v25);
    ipc_log_string(a1[120], "m_fw_err:0x%x, rx_len_in:0x%x m_gp_length:0x%x s_gp_length:0x%x\n", v54, v45, v35, v27);
    _ftrace_dbg(a1[43], "m_fw_err:0x%x, rx_len_in:0x%x m_gp_length:0x%x s_gp_length:0x%x\n", v54, v45, v35, v27);
    ipc_log_string(
      a1[120],
      "dma_tx_ptr_l:0x%x, dma_tx_ptr_h:0x%x dma_tx_attr:0x%x dma_tx_max_burst_size:0x%x\n",
      v55,
      v48,
      v39,
      v29);
    _ftrace_dbg(
      a1[43],
      "dma_tx_ptr_l:0x%x, dma_tx_ptr_h:0x%x dma_tx_attr:0x%x dma_tx_max_burst_size:0x%x\n",
      v55,
      v48,
      v39,
      v29);
    ipc_log_string(
      a1[120],
      "dma_rx_ptr_l:0x%x, dma_rx_ptr_h:0x%x dma_rx_attr:0x%x dma_rx_max_burst_size:0x%x\n",
      v56,
      v50,
      v41,
      v31);
    _ftrace_dbg(
      a1[43],
      "dma_rx_ptr_l:0x%x, dma_rx_ptr_h:0x%x dma_rx_attr:0x%x dma_rx_max_burst_size:0x%x\n",
      v56,
      v50,
      v41,
      v31);
    ipc_log_string(a1[120], "dma_if_en:0x%x, geni_clk_ctrl:0x%x fifo_if_disable:0x%x\n", v57, v52, v38);
    return _ftrace_dbg(a1[43], "dma_if_en:0x%x, geni_clk_ctrl:0x%x fifo_if_disable:0x%x\n", v57, v52, v38);
  }
}
