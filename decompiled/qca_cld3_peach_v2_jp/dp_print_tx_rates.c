__int64 __fastcall dp_print_tx_rates(
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
  unsigned int v18; // w3
  int v19; // w0
  int v20; // w20
  int v21; // w0
  int v22; // w21
  int v23; // w21
  int v24; // w21
  int v25; // w21
  unsigned __int8 v26; // w8
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
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned __int64 v99; // x8
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v150; // [xsp+10h] [xbp-30h]
  __int64 v151; // [xsp+18h] [xbp-28h]
  __int64 v152; // [xsp+20h] [xbp-20h]
  __int64 v153; // [xsp+28h] [xbp-18h]
  __int64 v154; // [xsp+30h] [xbp-10h]
  __int64 v155; // [xsp+38h] [xbp-8h]

  v155 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  DP_PRINT_STATS("Tx Rate Info:\n", a2, a3, a4, a5, a6, a7, a8, a9);
  dp_print_common_rates_info((__int64)(a1 + 800), v10, v11, v12, v13, v14, v15, v16, v17);
  v18 = a1[881];
  v153 = 0;
  v154 = 0;
  v151 = 0;
  v152 = 0;
  *(_QWORD *)s = 0;
  v150 = 0;
  v19 = snprintf(s, 0x30u, " %d", v18);
  if ( (unsigned __int8)v19 >= 0x31u
    || (v20 = v19,
        v21 = snprintf(&s[v19 & 0x3F], 48 - (v19 & 0x3Fu), " %d", a1[882]),
        (unsigned __int8)(v21 + v20) > 0x30u)
    || (v22 = v21
            + v20
            + snprintf(&s[(unsigned __int8)(v21 + v20)], 48LL - (unsigned __int8)(v21 + v20), " %d", a1[883]),
        (unsigned __int8)v22 > 0x30u)
    || (v23 = v22 + snprintf(&s[(unsigned __int8)v22], 48LL - (unsigned __int8)v22, " %d", a1[884]),
        (unsigned __int8)v23 > 0x30u)
    || (v24 = v23 + snprintf(&s[(unsigned __int8)v23], 48LL - (unsigned __int8)v23, " %d", a1[885]),
        (unsigned __int8)v24 > 0x30u)
    || (v25 = v24 + snprintf(&s[(unsigned __int8)v24], 48LL - (unsigned __int8)v24, " %d", a1[886]),
        (unsigned __int8)v25 > 0x30u)
    || (v26 = v25 + snprintf(&s[(unsigned __int8)v25], 48LL - (unsigned __int8)v25, " %d", a1[887]), v26 > 0x30u) )
  {
    __break(0x5512u);
  }
  snprintf(&s[v26], 48LL - v26, " %d", a1[888]);
  DP_PRINT_STATS("NSS(1-8) = %s", v27, v28, v29, v30, v31, v32, v33, v34, s);
  DP_PRINT_STATS(
    "SGI = 0.8us %d 0.4us %d 1.6us %d 3.2us %d",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    a1[875],
    a1[876],
    a1[877],
    a1[878]);
  DP_PRINT_STATS(
    "BW Counts = 20MHz %d, 40MHz %d, 80MHz %d, 160MHz %d",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    a1[889],
    a1[890],
    a1[891],
    a1[892]);
  DP_PRINT_STATS("OFDMA = %d", v51, v52, v53, v54, v55, v56, v57, v58, a1[774]);
  DP_PRINT_STATS("STBC = %d", v59, v60, v61, v62, v63, v64, v65, v66, a1[775]);
  DP_PRINT_STATS("LDPC = %d", v67, v68, v69, v70, v71, v72, v73, v74, a1[776]);
  DP_PRINT_STATS("Retries = %d", v75, v76, v77, v78, v79, v80, v81, v82, a1[777]);
  DP_PRINT_STATS("Last ack rssi = %d\n", v83, v84, v85, v86, v87, v88, v89, v90, a1[792]);
  v99 = a1[793];
  if ( (v99 & 0x80) != 0 )
    v99 += 255LL;
  DP_PRINT_STATS("Average ack rssi = %lu\n", v91, v92, v93, v94, v95, v96, v97, v98, v99 >> 8);
  DP_PRINT_STATS(
    "Number of PPDU's with Punctured Preamble = %d",
    v100,
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    a1[880]);
  DP_PRINT_STATS("Aggregation:\n", v108, v109, v110, v111, v112, v113, v114, v115);
  DP_PRINT_STATS("Number of Msdu's Part of Ampdus = %d", v116, v117, v118, v119, v120, v121, v122, v123, a1[957]);
  DP_PRINT_STATS(
    "Number of Msdu's With No Mpdu Level Aggregation : %d",
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    a1[958]);
  DP_PRINT_STATS("Number of Msdu's Part of Amsdu = %d", v132, v133, v134, v135, v136, v137, v138, v139, a1[780]);
  result = DP_PRINT_STATS(
             "Number of Msdu's With No Msdu Level Aggregation = %d",
             v140,
             v141,
             v142,
             v143,
             v144,
             v145,
             v146,
             v147,
             a1[779]);
  _ReadStatusReg(SP_EL0);
  return result;
}
