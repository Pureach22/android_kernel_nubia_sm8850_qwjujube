__int64 __fastcall dp_print_txrx_soc_stats(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 i; // x22

  if ( !result )
    return qdf_trace_msg(0x45u, 2u, "%s: Invalid access", a2, a3, a4, a5, a6, a7, a8, a9, "dp_print_txrx_soc_stats");
  v9 = result;
  if ( *(_BYTE *)(result + 1120) )
  {
    v10 = *(_QWORD *)(result + 72);
    DP_PRINT_STATS("Tx path Statistics:", a2, a3, a4, a5, a6, a7, a8, a9);
    dp_print_tx_ring_stats(v9, v11, v12, v13, v14, v15, v16, v17, v18);
    DP_PRINT_STATS("Invalid release source: %u", v19, v20, v21, v22, v23, v24, v25, v26, *(unsigned int *)(v9 + 13492));
    DP_PRINT_STATS(
      "Invalid TX desc from completion ring: %u",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      *(unsigned int *)(v9 + 13496));
    DP_PRINT_STATS(
      "Invalid peer on tx path: %llu",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      *(_QWORD *)(*(_QWORD *)(v10 + 8) + 13448LL));
    DP_PRINT_STATS(
      "Tx desc freed in non-completion path: %u",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      *(unsigned int *)(*(_QWORD *)(v10 + 8) + 13532LL));
    DP_PRINT_STATS(
      "Tx desc force freed: %u",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      *(unsigned int *)(*(_QWORD *)(v10 + 8) + 13564LL));
    DP_PRINT_STATS("Rx path statistics:", v59, v60, v61, v62, v63, v64, v65, v66);
    result = dp_print_rx_err_stats((unsigned int *)v9, v10, v67, v68, v69, v70, v71, v72, v73, v74);
    for ( i = 3444; i != 3476; ++i )
    {
      if ( *(_DWORD *)(*(_QWORD *)(v10 + 8) + 4 * i) )
        result = DP_PRINT_STATS("Rxdma error number (%u): %u msdus", a2, a3, a4, a5, a6, a7, a8, a9, i - 3444);
    }
    if ( *(unsigned __int8 *)(v9 + 1120) >= 2u )
    {
      __break(0x5512u);
      return qdf_trace_msg(0x45u, 2u, "%s: Invalid access", a2, a3, a4, a5, a6, a7, a8, a9, "dp_print_txrx_soc_stats");
    }
  }
  return result;
}
