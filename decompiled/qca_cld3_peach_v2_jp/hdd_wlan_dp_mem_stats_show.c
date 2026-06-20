__int64 __fastcall hdd_wlan_dp_mem_stats_show(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  _QWORD *context; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w20
  int v22; // w20
  int v23; // w21
  int v24; // w22
  int v25; // w23
  int v26; // w24
  int v27; // w25
  int v28; // w26
  int v29; // w27
  int v30; // w28
  int v31; // w0
  int v32; // w0
  __int64 v34[2]; // [xsp+30h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_wlan_dp_mem_stats_show", a1, a2, a3, a4, a5, a6, a7, a8);
  v34[0] = 0;
  v21 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_wlan_dp_mem_stats_show",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20);
  if ( !v21 )
  {
    v21 = _osif_psoc_sync_op_start(context[12], v34, (__int64)"hdd_wlan_dp_mem_stats_show");
    if ( !v21 )
    {
      v22 = qdf_dp_tx_skb_mem_stats_read();
      v23 = qdf_dp_tx_skb_max_mem_stats_read();
      v24 = qdf_dp_rx_skb_mem_stats_read();
      v25 = qdf_dp_rx_skb_max_mem_stats_read();
      v26 = qdf_mem_dp_tx_skb_cnt_read();
      v27 = qdf_mem_dp_tx_skb_max_cnt_read();
      v28 = qdf_mem_dp_rx_skb_cnt_read();
      v29 = qdf_mem_dp_rx_skb_max_cnt_read();
      v30 = qdf_mem_tx_desc_cnt_read();
      v31 = qdf_mem_tx_desc_max_read();
      scnprintf(
        a11,
        4096,
        "TX_NBUF_MEM = %d MAX_TX_NBUF_MEM = %d RX_NBUF_MEM = %d MAX_RX_NBUF_MEM = %d TX_NBUF_CNT = %d MAX_TX_NBUF_CNT = %"
        "d RX_NBUF_CNT = %d MAX_RX_NBUF_CNT = %d PENDING_TX_DESCS = %d MAX_PENDING_TX_DESCS = %d\n",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31);
      v21 = v32;
      if ( v34[0] )
        _osif_psoc_sync_op_stop(v34[0], (__int64)"hdd_wlan_dp_mem_stats_show");
    }
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
