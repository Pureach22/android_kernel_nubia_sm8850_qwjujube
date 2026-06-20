__int64 __fastcall dp_print_rx_rates(
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
  int v10; // w0
  int v11; // w20
  int v12; // w0
  int v13; // w21
  int v14; // w21
  int v15; // w21
  int v16; // w21
  unsigned __int8 v17; // w8
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
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v92; // [xsp+10h] [xbp-30h]
  __int64 v93; // [xsp+18h] [xbp-28h]
  __int64 v94; // [xsp+20h] [xbp-20h]
  __int64 v95; // [xsp+28h] [xbp-18h]
  __int64 v96; // [xsp+30h] [xbp-10h]
  __int64 v97; // [xsp+38h] [xbp-8h]

  v97 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v95 = 0;
  v96 = 0;
  v93 = 0;
  v94 = 0;
  *(_QWORD *)s = 0;
  v92 = 0;
  DP_PRINT_STATS("Rx Rate Info:\n", a2, a3, a4, a5, a6, a7, a8, a9);
  dp_print_common_rates_info(a1 + 1427);
  v10 = snprintf(s, 0x30u, " %d", a1[1507]);
  if ( (unsigned __int8)v10 >= 0x31u
    || (v11 = v10,
        v12 = snprintf(&s[v10 & 0x3F], 48 - (v10 & 0x3Fu), " %d", a1[1508]),
        (unsigned __int8)(v11 + v12) > 0x30u)
    || (v13 = v11
            + v12
            + snprintf(&s[(unsigned __int8)(v11 + v12)], 48LL - (unsigned __int8)(v11 + v12), " %d", a1[1509]),
        (unsigned __int8)v13 > 0x30u)
    || (v14 = v13 + snprintf(&s[(unsigned __int8)v13], 48LL - (unsigned __int8)v13, " %d", a1[1510]),
        (unsigned __int8)v14 > 0x30u)
    || (v15 = v14 + snprintf(&s[(unsigned __int8)v14], 48LL - (unsigned __int8)v14, " %d", a1[1511]),
        (unsigned __int8)v15 > 0x30u)
    || (v16 = v15 + snprintf(&s[(unsigned __int8)v15], 48LL - (unsigned __int8)v15, " %d", a1[1512]),
        (unsigned __int8)v16 > 0x30u)
    || (v17 = v16 + snprintf(&s[(unsigned __int8)v16], 48LL - (unsigned __int8)v16, " %d", a1[1513]), v17 > 0x30u) )
  {
    __break(0x5512u);
  }
  snprintf(&s[v17], 48LL - v17, " %d", a1[1514]);
  DP_PRINT_STATS("NSS(1-8) = %s", v18, v19, v20, v21, v22, v23, v24, v25, s);
  DP_PRINT_STATS(
    "SGI = 0.8us %d 0.4us %d 1.6us %d 3.2us %d",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    a1[1502],
    a1[1503],
    a1[1504],
    a1[1505]);
  DP_PRINT_STATS(
    "BW Counts = 20MHz %d, 40MHz %d, 80MHz %d, 160MHz %d",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    a1[1594],
    a1[1595],
    a1[1596],
    a1[1597]);
  DP_PRINT_STATS(
    "Reception Type =SU: %d MU_MIMO:%d MU_OFDMA:%d MU_OFDMA_MIMO:%d",
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    a1[1423],
    a1[1424],
    a1[1425],
    a1[1426]);
  DP_PRINT_STATS("Aggregation:\n", v50, v51, v52, v53, v54, v55, v56, v57);
  DP_PRINT_STATS("Number of Msdu's Part of Ampdus = %d", v58, v59, v60, v61, v62, v63, v64, v65, a1[1603]);
  DP_PRINT_STATS(
    "Number of Msdu's With No Mpdu Level Aggregation : %d",
    v66,
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    a1[1602]);
  DP_PRINT_STATS("Number of Msdu's Part of Amsdu: %d", v74, v75, v76, v77, v78, v79, v80, v81, a1[1605]);
  result = DP_PRINT_STATS(
             "Number of Msdu's With No Msdu Level Aggregation: %d",
             v82,
             v83,
             v84,
             v85,
             v86,
             v87,
             v88,
             v89,
             a1[1604]);
  _ReadStatusReg(SP_EL0);
  return result;
}
