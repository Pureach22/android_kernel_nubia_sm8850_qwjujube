__int64 __fastcall dp_print_tx_hwq_difs_latency_stats_tlv_v(unsigned int *a1)
{
  unsigned int v2; // w20
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 v13; // x24
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  int v31; // w22
  int v32; // w0

  v2 = *a1;
  v3 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_hwq_difs_latency_stats_tlv_v", 1590);
  if ( !v3 )
    return qdf_trace_msg(
             0x7Fu,
             2u,
             "%s: Output buffer not allocated",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "dp_print_tx_hwq_difs_latency_stats_tlv_v");
  v12 = v3;
  LODWORD(v13) = (v2 >> 14) & 0x3FF;
  DP_PRINT_STATS("HTT_TX_HWQ_DIFS_LATENCY_STATS_TLV_V:", v4, v5, v6, v7, v8, v9, v10, v11);
  DP_PRINT_STATS("hist_intvl = %u", v14, v15, v16, v17, v18, v19, v20, v21, a1[1]);
  if ( (_DWORD)v13 )
  {
    v30 = 0;
    v31 = 0;
    if ( (unsigned int)v13 >= 0xA )
      v13 = 10;
    else
      v13 = (unsigned int)v13;
    do
    {
      v32 = snprintf((char *)(v12 + (unsigned __int16)v31), 1000LL - (unsigned __int16)v31, " %u:%u,", v30, a1[v30 + 2]);
      ++v30;
      v31 += v32;
    }
    while ( v13 != v30 );
  }
  DP_PRINT_STATS("difs_latency_hist = %s\n", v22, v23, v24, v25, v26, v27, v28, v29, v12);
  return _qdf_mem_free(v12);
}
