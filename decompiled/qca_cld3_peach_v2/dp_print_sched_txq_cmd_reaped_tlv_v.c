__int64 __fastcall dp_print_sched_txq_cmd_reaped_tlv_v(unsigned int *a1)
{
  unsigned int v2; // w21
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  char *v12; // x19
  int v13; // w22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int16 v22; // w0
  unsigned __int16 v23; // w21
  __int16 v24; // w0
  unsigned __int16 v25; // w21
  __int16 v26; // w0

  v2 = *a1;
  v3 = _qdf_mem_malloc(0x3E8u, "dp_print_sched_txq_cmd_reaped_tlv_v", 2400);
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
             "dp_print_sched_txq_cmd_reaped_tlv_v");
  v12 = (char *)v3;
  v13 = (v2 >> 14) & 0x3FF;
  DP_PRINT_STATS("HTT_SCHED_TXQ_CMD_REAPED_TLV_V:", v4, v5, v6, v7, v8, v9, v10, v11);
  if ( v13 )
  {
    v22 = snprintf(v12, 0x3E8u, " %u:%u,", 0, a1[1]);
    if ( v13 != 1 )
    {
      v23 = v22;
      v24 = snprintf(&v12[v22], 1000LL - v22, " %u:%u,", 1, a1[2]);
      if ( v13 != 2 )
      {
        v25 = v23 + v24;
        v26 = snprintf(&v12[v25], 1000LL - v25, " %u:%u,", 2, a1[3]);
        if ( v13 != 3 )
          snprintf(&v12[(unsigned __int16)(v25 + v26)], 1000LL - (unsigned __int16)(v25 + v26), " %u:%u,", 3, a1[4]);
      }
    }
  }
  DP_PRINT_STATS("sched_cmd_reaped = %s\n", v14, v15, v16, v17, v18, v19, v20, v21, v12);
  return _qdf_mem_free((__int64)v12);
}
