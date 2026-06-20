__int64 __fastcall dp_print_rx_pdev_fw_ring_mpdu_err_tlv_v(_DWORD *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char *v11; // x19
  int v12; // w22
  int v13; // w22
  int v14; // w22
  int v15; // w22
  int v16; // w22
  int v17; // w22
  int v18; // w22
  int v19; // w22
  int v20; // w22
  int v21; // w22
  int v22; // w22
  int v23; // w22
  int v24; // w22
  __int16 v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_fw_ring_mpdu_err_tlv_v", 4358);
  if ( !v2 )
    return qdf_trace_msg(
             0x7Fu,
             2u,
             "%s: Output buffer not allocated",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "dp_print_rx_pdev_fw_ring_mpdu_err_tlv_v");
  v11 = (char *)v2;
  DP_PRINT_STATS("HTT_RX_PDEV_FW_RING_MPDU_ERR_TLV_V:", v3, v4, v5, v6, v7, v8, v9, v10);
  v12 = snprintf(v11, 0x3E8u, " %u:%u,", 0, a1[1]);
  v13 = v12 + snprintf(&v11[(unsigned __int16)v12], 1000LL - (unsigned __int16)v12, " %u:%u,", 1, a1[2]);
  v14 = v13 + snprintf(&v11[(unsigned __int16)v13], 1000LL - (unsigned __int16)v13, " %u:%u,", 2, a1[3]);
  v15 = v14 + snprintf(&v11[(unsigned __int16)v14], 1000LL - (unsigned __int16)v14, " %u:%u,", 3, a1[4]);
  v16 = v15 + snprintf(&v11[(unsigned __int16)v15], 1000LL - (unsigned __int16)v15, " %u:%u,", 4, a1[5]);
  v17 = v16 + snprintf(&v11[(unsigned __int16)v16], 1000LL - (unsigned __int16)v16, " %u:%u,", 5, a1[6]);
  v18 = v17 + snprintf(&v11[(unsigned __int16)v17], 1000LL - (unsigned __int16)v17, " %u:%u,", 6, a1[7]);
  v19 = v18 + snprintf(&v11[(unsigned __int16)v18], 1000LL - (unsigned __int16)v18, " %u:%u,", 7, a1[8]);
  v20 = v19 + snprintf(&v11[(unsigned __int16)v19], 1000LL - (unsigned __int16)v19, " %u:%u,", 8, a1[9]);
  v21 = v20 + snprintf(&v11[(unsigned __int16)v20], 1000LL - (unsigned __int16)v20, " %u:%u,", 9, a1[10]);
  v22 = v21 + snprintf(&v11[(unsigned __int16)v21], 1000LL - (unsigned __int16)v21, " %u:%u,", 10, a1[11]);
  v23 = v22 + snprintf(&v11[(unsigned __int16)v22], 1000LL - (unsigned __int16)v22, " %u:%u,", 11, a1[12]);
  v24 = v23 + snprintf(&v11[(unsigned __int16)v23], 1000LL - (unsigned __int16)v23, " %u:%u,", 12, a1[13]);
  LOWORD(v24) = v24 + snprintf(&v11[(unsigned __int16)v24], 1000LL - (unsigned __int16)v24, " %u:%u,", 13, a1[14]);
  v25 = snprintf(&v11[(unsigned __int16)v24], 1000LL - (unsigned __int16)v24, " %u:%u,", 14, a1[15]);
  snprintf(&v11[(unsigned __int16)(v24 + v25)], 1000LL - (unsigned __int16)(v24 + v25), " %u:%u,", 15, a1[16]);
  DP_PRINT_STATS("fw_ring_mpdu_err = %s\n", v26, v27, v28, v29, v30, v31, v32, v33, v11);
  return _qdf_mem_free((__int64)v11);
}
