__int64 __fastcall dp_print_stats_tx_sched_cmn_tlv(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7

  DP_PRINT_STATS("HTT_STATS_TX_SCHED_CMN_TLV:", a2, a3, a4, a5, a6, a7, a8, a9);
  DP_PRINT_STATS("mac_id__word = %u", v10, v11, v12, v13, v14, v15, v16, v17, *(unsigned int *)(a1 + 4));
  return DP_PRINT_STATS("current_timestamp = %u\n", v18, v19, v20, v21, v22, v23, v24, v25, *(unsigned int *)(a1 + 8));
}
