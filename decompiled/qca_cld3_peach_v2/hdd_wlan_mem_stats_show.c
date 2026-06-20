__int64 __fastcall hdd_wlan_mem_stats_show(
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
  int v25; // w0
  int v26; // w0
  __int64 v28[2]; // [xsp+0h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_wlan_mem_stats_show", a1, a2, a3, a4, a5, a6, a7, a8);
  v28[0] = 0;
  v21 = _wlan_hdd_validate_context(
          (__int64)context,
          (__int64)"hdd_wlan_mem_stats_show",
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
    v21 = _osif_psoc_sync_op_start(context[12], v28, (__int64)"hdd_wlan_mem_stats_show");
    if ( !v21 )
    {
      v22 = qdf_dma_mem_stats_read();
      v23 = qdf_heap_mem_stats_read();
      v24 = qdf_skb_total_mem_stats_read();
      v25 = qdf_skb_max_mem_stats_read();
      scnprintf(a11, 4096, "DMA = %d HEAP = %d SKB = %d SKB_MAX = %d\n", v22, v23, v24, v25);
      v21 = v26;
      if ( v28[0] )
        _osif_psoc_sync_op_stop(v28[0], (__int64)"hdd_wlan_mem_stats_show");
    }
  }
  _ReadStatusReg(SP_EL0);
  return v21;
}
