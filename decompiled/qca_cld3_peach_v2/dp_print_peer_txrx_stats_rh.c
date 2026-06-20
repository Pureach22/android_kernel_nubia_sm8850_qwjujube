__int64 __fastcall dp_print_peer_txrx_stats_rh(
        unsigned int *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7

  if ( a2 )
    return DP_PRINT_STATS(
             "BW Counts = 20MHZ %d 40MHZ %d 80MHZ %d 160MHZ %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a1[993],
             a1[994],
             a1[995],
             a1[996]);
  DP_PRINT_STATS(
    "BW Counts = 20MHZ %d 40MHZ %d 80MHZ %d 160MHZ %d\n",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a1[170],
    a1[171],
    a1[172],
    a1[173]);
  DP_PRINT_STATS("RU Locations", v12, v13, v14, v15, v16, v17, v18, v19);
  DP_PRINT_STATS(
    "%s: MSDUs Success = %d MPDUs Success = %d MPDUs Tried = %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "RU_26",
    a1[342],
    a1[343],
    a1[344]);
  DP_PRINT_STATS(
    "%s: MSDUs Success = %d MPDUs Success = %d MPDUs Tried = %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "RU_52",
    a1[345],
    a1[346],
    a1[347]);
  DP_PRINT_STATS(
    "%s: MSDUs Success = %d MPDUs Success = %d MPDUs Tried = %d",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "RU_106",
    a1[351],
    a1[352],
    a1[353]);
  DP_PRINT_STATS(
    "%s: MSDUs Success = %d MPDUs Success = %d MPDUs Tried = %d",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    "RU_242",
    a1[357],
    a1[358],
    a1[359]);
  DP_PRINT_STATS(
    "%s: MSDUs Success = %d MPDUs Success = %d MPDUs Tried = %d",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "RU_484",
    a1[360],
    a1[361],
    a1[362]);
  return DP_PRINT_STATS(
           "%s: MSDUs Success = %d MPDUs Success = %d MPDUs Tried = %d",
           v60,
           v61,
           v62,
           v63,
           v64,
           v65,
           v66,
           v67,
           "RU_996",
           a1[366],
           a1[367],
           a1[368]);
}
