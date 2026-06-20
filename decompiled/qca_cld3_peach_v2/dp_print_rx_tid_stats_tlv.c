__int64 __fastcall dp_print_rx_tid_stats_tlv(__int64 a1)
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
  char *v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
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
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7

  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_tid_stats_tlv", 1003);
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
             "dp_print_rx_tid_stats_tlv");
  v11 = (char *)v2;
  DP_PRINT_STATS("HTT_RX_TID_STATS_TLV:", v3, v4, v5, v6, v7, v8, v9, v10);
  DP_PRINT_STATS("sw_peer_id__tid_num = %u", v12, v13, v14, v15, v16, v17, v18, v19, *(unsigned int *)(a1 + 4));
  v20 = snprintf(v11, 0x3E8u, " %u:%u,", 0, *(unsigned __int8 *)(a1 + 8));
  v21 = v20
      + snprintf(
          &v11[(unsigned __int16)v20],
          1000LL - (unsigned __int16)v20,
          " %u:%u,",
          1,
          *(unsigned __int8 *)(a1 + 9));
  v22 = v21
      + snprintf(
          &v11[(unsigned __int16)v21],
          1000LL - (unsigned __int16)v21,
          " %u:%u,",
          2,
          *(unsigned __int8 *)(a1 + 10));
  v23 = v22
      + snprintf(
          &v11[(unsigned __int16)v22],
          1000LL - (unsigned __int16)v22,
          " %u:%u,",
          3,
          *(unsigned __int8 *)(a1 + 11));
  v24 = v23
      + snprintf(
          &v11[(unsigned __int16)v23],
          1000LL - (unsigned __int16)v23,
          " %u:%u,",
          4,
          *(unsigned __int8 *)(a1 + 12));
  LOWORD(v24) = v24
              + snprintf(
                  &v11[(unsigned __int16)v24],
                  1000LL - (unsigned __int16)v24,
                  " %u:%u,",
                  5,
                  *(unsigned __int8 *)(a1 + 13));
  v25 = snprintf(
          &v11[(unsigned __int16)v24],
          1000LL - (unsigned __int16)v24,
          " %u:%u,",
          6,
          *(unsigned __int8 *)(a1 + 14));
  snprintf(
    &v11[(unsigned __int16)(v24 + v25)],
    1000LL - (unsigned __int16)(v24 + v25),
    " %u:%u,",
    7,
    *(unsigned __int8 *)(a1 + 15));
  DP_PRINT_STATS("tid_name = %s ", v26, v27, v28, v29, v30, v31, v32, v33, v11);
  DP_PRINT_STATS("dup_in_reorder = %u", v34, v35, v36, v37, v38, v39, v40, v41, *(unsigned int *)(a1 + 16));
  DP_PRINT_STATS("dup_past_outside_window = %u", v42, v43, v44, v45, v46, v47, v48, v49, *(unsigned int *)(a1 + 20));
  DP_PRINT_STATS("dup_past_within_window = %u", v50, v51, v52, v53, v54, v55, v56, v57, *(unsigned int *)(a1 + 24));
  DP_PRINT_STATS("rxdesc_err_decrypt = %u\n", v58, v59, v60, v61, v62, v63, v64, v65, *(unsigned int *)(a1 + 28));
  return _qdf_mem_free((__int64)v11);
}
