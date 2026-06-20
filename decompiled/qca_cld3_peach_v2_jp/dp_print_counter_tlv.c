__int64 __fastcall dp_print_counter_tlv(__int64 a1)
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
  int v12; // w22
  int v13; // w22
  int v14; // w22
  int v15; // w22
  int v16; // w22
  __int16 v17; // w0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_counter_tlv", 1042);
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
             "dp_print_counter_tlv");
  v11 = (char *)v2;
  DP_PRINT_STATS("HTT_COUNTER_TLV:", v3, v4, v5, v6, v7, v8, v9, v10);
  v12 = snprintf(v11, 0x3E8u, " %u:%u,", 0, *(unsigned __int8 *)(a1 + 4));
  v13 = v12
      + snprintf(
          &v11[(unsigned __int16)v12],
          1000LL - (unsigned __int16)v12,
          " %u:%u,",
          1,
          *(unsigned __int8 *)(a1 + 5));
  v14 = v13
      + snprintf(
          &v11[(unsigned __int16)v13],
          1000LL - (unsigned __int16)v13,
          " %u:%u,",
          2,
          *(unsigned __int8 *)(a1 + 6));
  v15 = v14
      + snprintf(
          &v11[(unsigned __int16)v14],
          1000LL - (unsigned __int16)v14,
          " %u:%u,",
          3,
          *(unsigned __int8 *)(a1 + 7));
  v16 = v15
      + snprintf(
          &v11[(unsigned __int16)v15],
          1000LL - (unsigned __int16)v15,
          " %u:%u,",
          4,
          *(unsigned __int8 *)(a1 + 8));
  LOWORD(v16) = v16
              + snprintf(
                  &v11[(unsigned __int16)v16],
                  1000LL - (unsigned __int16)v16,
                  " %u:%u,",
                  5,
                  *(unsigned __int8 *)(a1 + 9));
  v17 = snprintf(
          &v11[(unsigned __int16)v16],
          1000LL - (unsigned __int16)v16,
          " %u:%u,",
          6,
          *(unsigned __int8 *)(a1 + 10));
  snprintf(
    &v11[(unsigned __int16)(v16 + v17)],
    1000LL - (unsigned __int16)(v16 + v17),
    " %u:%u,",
    7,
    *(unsigned __int8 *)(a1 + 11));
  DP_PRINT_STATS("counter_name = %s ", v18, v19, v20, v21, v22, v23, v24, v25, v11);
  DP_PRINT_STATS("count = %u\n", v26, v27, v28, v29, v30, v31, v32, v33, *(unsigned int *)(a1 + 12));
  return _qdf_mem_free((__int64)v11);
}
