__int64 __fastcall dp_print_tx_ring_stats(
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
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x1

  if ( *(_BYTE *)(result + 7153) )
  {
    v9 = result;
    DP_PRINT_STATS("Enqueue to SW2TCL%u: %u", a2, a3, a4, a5, a6, a7, a8, a9, 1, *(unsigned int *)(result + 13424));
    result = DP_PRINT_STATS(
               "TX completions reaped from ring %u: %u",
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               0,
               *(unsigned int *)(v9 + 13544));
    if ( *(unsigned __int8 *)(v9 + 7153) > 1u )
    {
      DP_PRINT_STATS(
        "Enqueue to SW2TCL%u: %u",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        2,
        *(unsigned int *)(v9 + 13428));
      result = DP_PRINT_STATS(
                 "TX completions reaped from ring %u: %u",
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 1,
                 *(unsigned int *)(v9 + 13548));
      if ( *(unsigned __int8 *)(v9 + 7153) >= 3u )
      {
        DP_PRINT_STATS(
          "Enqueue to SW2TCL%u: %u",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          3,
          *(unsigned int *)(v9 + 13432));
        result = DP_PRINT_STATS(
                   "TX completions reaped from ring %u: %u",
                   v42,
                   v43,
                   v44,
                   v45,
                   v46,
                   v47,
                   v48,
                   v49,
                   2,
                   *(unsigned int *)(v9 + 13552));
        if ( *(unsigned __int8 *)(v9 + 7153) >= 4u )
        {
          DP_PRINT_STATS(
            "Enqueue to SW2TCL%u: %u",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            4,
            *(unsigned int *)(v9 + 13436));
          result = DP_PRINT_STATS(
                     "TX completions reaped from ring %u: %u",
                     v58,
                     v59,
                     v60,
                     v61,
                     v62,
                     v63,
                     v64,
                     v65,
                     3,
                     *(unsigned int *)(v9 + 13556));
          if ( *(unsigned __int8 *)(v9 + 7153) >= 5u )
          {
            DP_PRINT_STATS(
              "Enqueue to SW2TCL%u: %u",
              v66,
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              5,
              *(unsigned int *)(v9 + 13440));
            result = DP_PRINT_STATS(
                       "TX completions reaped from ring %u: %u",
                       v74,
                       v75,
                       v76,
                       v77,
                       v78,
                       v79,
                       v80,
                       v81,
                       4,
                       *(unsigned int *)(v9 + 13560));
            if ( *(unsigned __int8 *)(v9 + 7153) > 5u )
            {
              __break(0x5512u);
              return dp_print_rx_err_stats(result, v82);
            }
          }
        }
      }
    }
  }
  return result;
}
