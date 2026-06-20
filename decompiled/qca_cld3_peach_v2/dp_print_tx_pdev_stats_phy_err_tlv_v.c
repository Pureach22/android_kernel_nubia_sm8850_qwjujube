__int64 __fastcall dp_print_tx_pdev_stats_phy_err_tlv_v(unsigned int *a1)
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
  __int64 v22; // x20
  int v23; // w22
  int v24; // w0

  v2 = *a1;
  v3 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_stats_phy_err_tlv_v", 734);
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
             "dp_print_tx_pdev_stats_phy_err_tlv_v");
  v12 = v3;
  LODWORD(v13) = (v2 >> 14) & 0x3FF;
  DP_PRINT_STATS("HTT_TX_PDEV_STATS_PHY_ERR_TLV_V:", v4, v5, v6, v7, v8, v9, v10, v11);
  if ( (_DWORD)v13 )
  {
    v22 = 0;
    v23 = 0;
    if ( (unsigned int)v13 >= 0x12 )
      v13 = 18;
    else
      v13 = (unsigned int)v13;
    do
    {
      v24 = snprintf((char *)(v12 + (unsigned __int16)v23), 1000LL - (unsigned __int16)v23, " %u:%u,", v22, a1[v22 + 1]);
      ++v22;
      v23 += v24;
    }
    while ( v13 != v22 );
  }
  DP_PRINT_STATS("phy_errs = %s\n", v14, v15, v16, v17, v18, v19, v20, v21, v12);
  return _qdf_mem_free(v12);
}
