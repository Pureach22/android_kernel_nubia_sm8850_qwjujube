__int64 __fastcall dp_print_tx_hwq_mu_mimo_sch_stats_tlv(
        unsigned int *a1,
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
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  DP_PRINT_STATS("HTT_TX_HWQ_MU_MIMO_SCH_STATS_TLV:", a2, a3, a4, a5, a6, a7, a8, a9);
  DP_PRINT_STATS("mu_mimo_sch_posted = %u", v10, v11, v12, v13, v14, v15, v16, v17, a1[1]);
  DP_PRINT_STATS("mu_mimo_sch_failed = %u", v18, v19, v20, v21, v22, v23, v24, v25, a1[2]);
  return DP_PRINT_STATS("mu_mimo_ppdu_posted = %u\n", v26, v27, v28, v29, v30, v31, v32, v33, a1[3]);
}
