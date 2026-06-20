__int64 __fastcall dp_print_rx_pdev_rate_ext_stats_tlv(_DWORD *a1)
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
  void *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x21
  unsigned __int16 v21; // w0
  unsigned __int16 v22; // w22
  unsigned __int16 v23; // w22
  unsigned __int16 v24; // w22
  unsigned __int16 v25; // w22
  unsigned __int16 v26; // w22
  unsigned __int16 v27; // w22
  unsigned __int16 v28; // w22
  unsigned __int16 v29; // w22
  unsigned __int16 v30; // w22
  unsigned __int16 v31; // w22
  unsigned __int16 v32; // w22
  unsigned __int16 v33; // w22
  unsigned __int16 v34; // w22
  __int16 v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned __int16 v44; // w0
  unsigned __int16 v45; // w22
  unsigned __int16 v46; // w22
  unsigned __int16 v47; // w22
  unsigned __int16 v48; // w22
  unsigned __int16 v49; // w22
  unsigned __int16 v50; // w22
  unsigned __int16 v51; // w22
  unsigned __int16 v52; // w22
  unsigned __int16 v53; // w22
  unsigned __int16 v54; // w22
  unsigned __int16 v55; // w22
  __int16 v56; // w0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x22
  int *v66; // x27
  void *v67; // x24
  int v68; // w25
  int v69; // w25
  int v70; // w25
  int v71; // w25
  int v72; // w25
  int v73; // w25
  int v74; // w25
  int v75; // w25
  int v76; // w25
  int v77; // w25
  int v78; // w25
  __int16 v79; // w0
  int v80; // t1
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned __int16 v89; // w0
  unsigned __int16 v90; // w22
  unsigned __int16 v91; // w22
  unsigned __int16 v92; // w22
  unsigned __int16 v93; // w22
  unsigned __int16 v94; // w22
  unsigned __int16 v95; // w22
  unsigned __int16 v96; // w22
  unsigned __int16 v97; // w22
  unsigned __int16 v98; // w22
  unsigned __int16 v99; // w22
  unsigned __int16 v100; // w22
  __int16 v101; // w0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x22
  int *v111; // x27
  void *v112; // x24
  int v113; // w25
  int v114; // w25
  int v115; // w25
  int v116; // w25
  int v117; // w25
  int v118; // w25
  int v119; // w25
  int v120; // w25
  int v121; // w25
  int v122; // w25
  int v123; // w25
  __int16 v124; // w0
  int v125; // t1
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  unsigned __int16 v134; // w0
  unsigned __int16 v135; // w22
  unsigned __int16 v136; // w22
  unsigned __int16 v137; // w22
  unsigned __int16 v138; // w22
  unsigned __int16 v139; // w22
  unsigned __int16 v140; // w22
  unsigned __int16 v141; // w22
  unsigned __int16 v142; // w22
  unsigned __int16 v143; // w22
  unsigned __int16 v144; // w22
  unsigned __int16 v145; // w22
  __int16 v146; // w0
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  unsigned __int16 v155; // w0
  unsigned __int16 v156; // w22
  unsigned __int16 v157; // w22
  unsigned __int16 v158; // w22
  unsigned __int16 v159; // w22
  unsigned __int16 v160; // w22
  unsigned __int16 v161; // w22
  unsigned __int16 v162; // w22
  unsigned __int16 v163; // w22
  unsigned __int16 v164; // w22
  unsigned __int16 v165; // w22
  unsigned __int16 v166; // w22
  __int16 v167; // w0
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  unsigned __int16 v176; // w0
  unsigned __int16 v177; // w22
  unsigned __int16 v178; // w22
  unsigned __int16 v179; // w22
  unsigned __int16 v180; // w22
  unsigned __int16 v181; // w22
  unsigned __int16 v182; // w22
  unsigned __int16 v183; // w22
  unsigned __int16 v184; // w22
  unsigned __int16 v185; // w22
  unsigned __int16 v186; // w22
  unsigned __int16 v187; // w22
  __int16 v188; // w0
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  unsigned __int16 v197; // w0
  unsigned __int16 v198; // w22
  unsigned __int16 v199; // w22
  __int16 v200; // w0
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  int v209; // w22
  int v210; // w22
  __int16 v211; // w0
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  __int64 result; // x0
  const char *v221; // x2
  __int64 v222; // [xsp+8h] [xbp-48h]
  __int64 v223; // [xsp+10h] [xbp-40h]
  __int64 v224; // [xsp+18h] [xbp-38h]
  __int64 v225; // [xsp+20h] [xbp-30h]
  __int64 v226; // [xsp+28h] [xbp-28h]
  __int64 v227; // [xsp+30h] [xbp-20h]
  __int64 v228; // [xsp+38h] [xbp-18h]
  __int64 v229; // [xsp+40h] [xbp-10h]
  __int64 v230; // [xsp+48h] [xbp-8h]

  v230 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v228 = 0;
  v229 = 0;
  v227 = 0;
  v224 = 0;
  v225 = 0;
  v222 = 0;
  v223 = 0;
  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3629);
  if ( !v2 )
  {
    result = qdf_trace_msg(
               0x45u,
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
               "dp_print_rx_pdev_rate_ext_stats_tlv");
    goto LABEL_37;
  }
  v11 = (void *)v2;
  v226 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3637);
  if ( !v226 )
  {
    v20 = 0;
    goto LABEL_18;
  }
  v20 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3643);
  v222 = v20;
  if ( v20 )
  {
    v227 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3637);
    if ( !v227 )
      goto LABEL_18;
    v223 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3643);
    if ( v223 )
    {
      v228 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3637);
      if ( !v228 )
        goto LABEL_18;
      v224 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3643);
      if ( v224 )
      {
        v229 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3637);
        if ( v229 )
        {
          v225 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_ext_stats_tlv", 3643);
          if ( v225 )
          {
            qdf_mem_set(v11, 0x3E8u, 0);
            v21 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[19]);
            v22 = v21 + snprintf((char *)v11 + v21, 1000LL - v21, " %u:%u,", 1, a1[20]);
            v23 = v22 + snprintf((char *)v11 + v22, 1000LL - v22, " %u:%u,", 2, a1[21]);
            v24 = v23 + snprintf((char *)v11 + v23, 1000LL - v23, " %u:%u,", 3, a1[22]);
            v25 = v24 + snprintf((char *)v11 + v24, 1000LL - v24, " %u:%u,", 4, a1[23]);
            v26 = v25 + snprintf((char *)v11 + v25, 1000LL - v25, " %u:%u,", 5, a1[24]);
            v27 = v26 + snprintf((char *)v11 + v26, 1000LL - v26, " %u:%u,", 6, a1[25]);
            v28 = v27 + snprintf((char *)v11 + v27, 1000LL - v27, " %u:%u,", 7, a1[26]);
            v29 = v28 + snprintf((char *)v11 + v28, 1000LL - v28, " %u:%u,", 8, a1[27]);
            v30 = v29 + snprintf((char *)v11 + v29, 1000LL - v29, " %u:%u,", 9, a1[28]);
            v31 = v30 + snprintf((char *)v11 + v30, 1000LL - v30, " %u:%u,", 10, a1[29]);
            v32 = v31 + snprintf((char *)v11 + v31, 1000LL - v31, " %u:%u,", 11, a1[30]);
            v33 = v32 + snprintf((char *)v11 + v32, 1000LL - v32, " %u:%u,", 12, a1[31]);
            v34 = v33 + snprintf((char *)v11 + v33, 1000LL - v33, " %u:%u,", 13, a1[32]);
            v35 = snprintf((char *)v11 + v34, 1000LL - v34, " %u:%u,", 14, a1[215]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v34 + v35),
              1000LL - (unsigned __int16)(v34 + v35),
              " %u:%u,",
              15,
              a1[216]);
            DP_PRINT_STATS("rx_mcs_ext = %s ", v36, v37, v38, v39, v40, v41, v42, v43, v11);
            qdf_mem_set(v11, 0x3E8u, 0);
            v44 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[33]);
            v45 = v44 + snprintf((char *)v11 + v44, 1000LL - v44, " %u:%u,", 1, a1[34]);
            v46 = v45 + snprintf((char *)v11 + v45, 1000LL - v45, " %u:%u,", 2, a1[35]);
            v47 = v46 + snprintf((char *)v11 + v46, 1000LL - v46, " %u:%u,", 3, a1[36]);
            v48 = v47 + snprintf((char *)v11 + v47, 1000LL - v47, " %u:%u,", 4, a1[37]);
            v49 = v48 + snprintf((char *)v11 + v48, 1000LL - v48, " %u:%u,", 5, a1[38]);
            v50 = v49 + snprintf((char *)v11 + v49, 1000LL - v49, " %u:%u,", 6, a1[39]);
            v51 = v50 + snprintf((char *)v11 + v50, 1000LL - v50, " %u:%u,", 7, a1[40]);
            v52 = v51 + snprintf((char *)v11 + v51, 1000LL - v51, " %u:%u,", 8, a1[41]);
            v53 = v52 + snprintf((char *)v11 + v52, 1000LL - v52, " %u:%u,", 9, a1[42]);
            v54 = v53 + snprintf((char *)v11 + v53, 1000LL - v53, " %u:%u,", 10, a1[43]);
            v55 = v54 + snprintf((char *)v11 + v54, 1000LL - v54, " %u:%u,", 11, a1[44]);
            v56 = snprintf((char *)v11 + v55, 1000LL - v55, " %u:%u,", 12, a1[45]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v55 + v56),
              1000LL - (unsigned __int16)(v55 + v56),
              " %u:%u,",
              13,
              a1[46]);
            DP_PRINT_STATS("rx_stbc_ext = %s ", v57, v58, v59, v60, v61, v62, v63, v64, v11);
            v65 = 0;
            v66 = a1 + 60;
            do
            {
              v67 = (void *)*(&v226 + v65);
              qdf_mem_set(v67, 0x3E8u, 0);
              v68 = snprintf((char *)v67, 0x3E8u, " %u:%u,", 0, *(v66 - 13));
              v69 = v68
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v68,
                      1000LL - (unsigned __int16)v68,
                      " %u:%u,",
                      1,
                      *(v66 - 12));
              v70 = v69
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v69,
                      1000LL - (unsigned __int16)v69,
                      " %u:%u,",
                      2,
                      *(v66 - 11));
              v71 = v70
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v70,
                      1000LL - (unsigned __int16)v70,
                      " %u:%u,",
                      3,
                      *(v66 - 10));
              v72 = v71
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v71,
                      1000LL - (unsigned __int16)v71,
                      " %u:%u,",
                      4,
                      *(v66 - 9));
              v73 = v72
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v72,
                      1000LL - (unsigned __int16)v72,
                      " %u:%u,",
                      5,
                      *(v66 - 8));
              v74 = v73
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v73,
                      1000LL - (unsigned __int16)v73,
                      " %u:%u,",
                      6,
                      *(v66 - 7));
              v75 = v74
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v74,
                      1000LL - (unsigned __int16)v74,
                      " %u:%u,",
                      7,
                      *(v66 - 6));
              v76 = v75
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v75,
                      1000LL - (unsigned __int16)v75,
                      " %u:%u,",
                      8,
                      *(v66 - 5));
              v77 = v76
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v76,
                      1000LL - (unsigned __int16)v76,
                      " %u:%u,",
                      9,
                      *(v66 - 4));
              v78 = v77
                  + snprintf(
                      (char *)v67 + (unsigned __int16)v77,
                      1000LL - (unsigned __int16)v77,
                      " %u:%u,",
                      10,
                      *(v66 - 3));
              LOWORD(v78) = v78
                          + snprintf(
                              (char *)v67 + (unsigned __int16)v78,
                              1000LL - (unsigned __int16)v78,
                              " %u:%u,",
                              11,
                              *(v66 - 2));
              v79 = snprintf(
                      (char *)v67 + (unsigned __int16)v78,
                      1000LL - (unsigned __int16)v78,
                      " %u:%u,",
                      12,
                      *(v66 - 1));
              v80 = *v66;
              v66 += 14;
              snprintf(
                (char *)v67 + (unsigned __int16)(v78 + v79),
                1000LL - (unsigned __int16)(v78 + v79),
                " %u:%u,",
                13,
                v80);
              DP_PRINT_STATS("rx_gi_ext[%u] = %s ", v81, v82, v83, v84, v85, v86, v87, v88, (unsigned int)v65++, v67);
            }
            while ( v65 != 4 );
            qdf_mem_set(v11, 0x3E8u, 0);
            v89 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[103]);
            v90 = v89 + snprintf((char *)v11 + v89, 1000LL - v89, " %u:%u,", 1, a1[104]);
            v91 = v90 + snprintf((char *)v11 + v90, 1000LL - v90, " %u:%u,", 2, a1[105]);
            v92 = v91 + snprintf((char *)v11 + v91, 1000LL - v91, " %u:%u,", 3, a1[106]);
            v93 = v92 + snprintf((char *)v11 + v92, 1000LL - v92, " %u:%u,", 4, a1[107]);
            v94 = v93 + snprintf((char *)v11 + v93, 1000LL - v93, " %u:%u,", 5, a1[108]);
            v95 = v94 + snprintf((char *)v11 + v94, 1000LL - v94, " %u:%u,", 6, a1[109]);
            v96 = v95 + snprintf((char *)v11 + v95, 1000LL - v95, " %u:%u,", 7, a1[110]);
            v97 = v96 + snprintf((char *)v11 + v96, 1000LL - v96, " %u:%u,", 8, a1[111]);
            v98 = v97 + snprintf((char *)v11 + v97, 1000LL - v97, " %u:%u,", 9, a1[112]);
            v99 = v98 + snprintf((char *)v11 + v98, 1000LL - v98, " %u:%u,", 10, a1[113]);
            v100 = v99 + snprintf((char *)v11 + v99, 1000LL - v99, " %u:%u,", 11, a1[114]);
            v101 = snprintf((char *)v11 + v100, 1000LL - v100, " %u:%u,", 12, a1[115]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v100 + v101),
              1000LL - (unsigned __int16)(v100 + v101),
              " %u:%u,",
              13,
              a1[116]);
            DP_PRINT_STATS("ul_ofdma_rx_mcs_ext = %s", v102, v103, v104, v105, v106, v107, v108, v109, v11);
            v110 = 0;
            v111 = a1 + 130;
            do
            {
              v112 = (void *)*(&v222 + v110);
              qdf_mem_set(v112, 0x3E8u, 0);
              v113 = snprintf((char *)v112, 0x3E8u, " %u:%u,", 0, *(v111 - 13));
              v114 = v113
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v113,
                       1000LL - (unsigned __int16)v113,
                       " %u:%u,",
                       1,
                       *(v111 - 12));
              v115 = v114
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v114,
                       1000LL - (unsigned __int16)v114,
                       " %u:%u,",
                       2,
                       *(v111 - 11));
              v116 = v115
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v115,
                       1000LL - (unsigned __int16)v115,
                       " %u:%u,",
                       3,
                       *(v111 - 10));
              v117 = v116
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v116,
                       1000LL - (unsigned __int16)v116,
                       " %u:%u,",
                       4,
                       *(v111 - 9));
              v118 = v117
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v117,
                       1000LL - (unsigned __int16)v117,
                       " %u:%u,",
                       5,
                       *(v111 - 8));
              v119 = v118
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v118,
                       1000LL - (unsigned __int16)v118,
                       " %u:%u,",
                       6,
                       *(v111 - 7));
              v120 = v119
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v119,
                       1000LL - (unsigned __int16)v119,
                       " %u:%u,",
                       7,
                       *(v111 - 6));
              v121 = v120
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v120,
                       1000LL - (unsigned __int16)v120,
                       " %u:%u,",
                       8,
                       *(v111 - 5));
              v122 = v121
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v121,
                       1000LL - (unsigned __int16)v121,
                       " %u:%u,",
                       9,
                       *(v111 - 4));
              v123 = v122
                   + snprintf(
                       (char *)v112 + (unsigned __int16)v122,
                       1000LL - (unsigned __int16)v122,
                       " %u:%u,",
                       10,
                       *(v111 - 3));
              LOWORD(v123) = v123
                           + snprintf(
                               (char *)v112 + (unsigned __int16)v123,
                               1000LL - (unsigned __int16)v123,
                               " %u:%u,",
                               11,
                               *(v111 - 2));
              v124 = snprintf(
                       (char *)v112 + (unsigned __int16)v123,
                       1000LL - (unsigned __int16)v123,
                       " %u:%u,",
                       12,
                       *(v111 - 1));
              v125 = *v111;
              v111 += 14;
              snprintf(
                (char *)v112 + (unsigned __int16)(v123 + v124),
                1000LL - (unsigned __int16)(v123 + v124),
                " %u:%u,",
                13,
                v125);
              DP_PRINT_STATS(
                "ul_ofdma_rx_gi_ext[%u] = %s ",
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                v132,
                v133,
                (unsigned int)v110++,
                v112);
            }
            while ( v110 != 4 );
            qdf_mem_set(v11, 0x3E8u, 0);
            v134 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[173]);
            v135 = v134 + snprintf((char *)v11 + v134, 1000LL - v134, " %u:%u,", 1, a1[174]);
            v136 = v135 + snprintf((char *)v11 + v135, 1000LL - v135, " %u:%u,", 2, a1[175]);
            v137 = v136 + snprintf((char *)v11 + v136, 1000LL - v136, " %u:%u,", 3, a1[176]);
            v138 = v137 + snprintf((char *)v11 + v137, 1000LL - v137, " %u:%u,", 4, a1[177]);
            v139 = v138 + snprintf((char *)v11 + v138, 1000LL - v138, " %u:%u,", 5, a1[178]);
            v140 = v139 + snprintf((char *)v11 + v139, 1000LL - v139, " %u:%u,", 6, a1[179]);
            v141 = v140 + snprintf((char *)v11 + v140, 1000LL - v140, " %u:%u,", 7, a1[180]);
            v142 = v141 + snprintf((char *)v11 + v141, 1000LL - v141, " %u:%u,", 8, a1[181]);
            v143 = v142 + snprintf((char *)v11 + v142, 1000LL - v142, " %u:%u,", 9, a1[182]);
            v144 = v143 + snprintf((char *)v11 + v143, 1000LL - v143, " %u:%u,", 10, a1[183]);
            v145 = v144 + snprintf((char *)v11 + v144, 1000LL - v144, " %u:%u,", 11, a1[184]);
            v146 = snprintf((char *)v11 + v145, 1000LL - v145, " %u:%u,", 12, a1[185]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v145 + v146),
              1000LL - (unsigned __int16)(v145 + v146),
              " %u:%u,",
              13,
              a1[186]);
            DP_PRINT_STATS("rx_11ax_su_txbf_mcs_ext = %s ", v147, v148, v149, v150, v151, v152, v153, v154, v11);
            qdf_mem_set(v11, 0x3E8u, 0);
            v155 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[187]);
            v156 = v155 + snprintf((char *)v11 + v155, 1000LL - v155, " %u:%u,", 1, a1[188]);
            v157 = v156 + snprintf((char *)v11 + v156, 1000LL - v156, " %u:%u,", 2, a1[189]);
            v158 = v157 + snprintf((char *)v11 + v157, 1000LL - v157, " %u:%u,", 3, a1[190]);
            v159 = v158 + snprintf((char *)v11 + v158, 1000LL - v158, " %u:%u,", 4, a1[191]);
            v160 = v159 + snprintf((char *)v11 + v159, 1000LL - v159, " %u:%u,", 5, a1[192]);
            v161 = v160 + snprintf((char *)v11 + v160, 1000LL - v160, " %u:%u,", 6, a1[193]);
            v162 = v161 + snprintf((char *)v11 + v161, 1000LL - v161, " %u:%u,", 7, a1[194]);
            v163 = v162 + snprintf((char *)v11 + v162, 1000LL - v162, " %u:%u,", 8, a1[195]);
            v164 = v163 + snprintf((char *)v11 + v163, 1000LL - v163, " %u:%u,", 9, a1[196]);
            v165 = v164 + snprintf((char *)v11 + v164, 1000LL - v164, " %u:%u,", 10, a1[197]);
            v166 = v165 + snprintf((char *)v11 + v165, 1000LL - v165, " %u:%u,", 11, a1[198]);
            v167 = snprintf((char *)v11 + v166, 1000LL - v166, " %u:%u,", 12, a1[199]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v166 + v167),
              1000LL - (unsigned __int16)(v166 + v167),
              " %u:%u,",
              13,
              a1[200]);
            DP_PRINT_STATS("rx_11ax_mu_txbf_mcs_ext = %s ", v168, v169, v170, v171, v172, v173, v174, v175, v11);
            qdf_mem_set(v11, 0x3E8u, 0);
            v176 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[201]);
            v177 = v176 + snprintf((char *)v11 + v176, 1000LL - v176, " %u:%u,", 1, a1[202]);
            v178 = v177 + snprintf((char *)v11 + v177, 1000LL - v177, " %u:%u,", 2, a1[203]);
            v179 = v178 + snprintf((char *)v11 + v178, 1000LL - v178, " %u:%u,", 3, a1[204]);
            v180 = v179 + snprintf((char *)v11 + v179, 1000LL - v179, " %u:%u,", 4, a1[205]);
            v181 = v180 + snprintf((char *)v11 + v180, 1000LL - v180, " %u:%u,", 5, a1[206]);
            v182 = v181 + snprintf((char *)v11 + v181, 1000LL - v181, " %u:%u,", 6, a1[207]);
            v183 = v182 + snprintf((char *)v11 + v182, 1000LL - v182, " %u:%u,", 7, a1[208]);
            v184 = v183 + snprintf((char *)v11 + v183, 1000LL - v183, " %u:%u,", 8, a1[209]);
            v185 = v184 + snprintf((char *)v11 + v184, 1000LL - v184, " %u:%u,", 9, a1[210]);
            v186 = v185 + snprintf((char *)v11 + v185, 1000LL - v185, " %u:%u,", 10, a1[211]);
            v187 = v186 + snprintf((char *)v11 + v186, 1000LL - v186, " %u:%u,", 11, a1[212]);
            v188 = snprintf((char *)v11 + v187, 1000LL - v187, " %u:%u,", 12, a1[213]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v187 + v188),
              1000LL - (unsigned __int16)(v187 + v188),
              " %u:%u,",
              13,
              a1[214]);
            DP_PRINT_STATS("rx_11ax_dl_ofdma_mcs_ext = %s ", v189, v190, v191, v192, v193, v194, v195, v196, v11);
            qdf_mem_set(v11, 0x3E8u, 0);
            v197 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[217]);
            v198 = v197 + snprintf((char *)v11 + v197, 1000LL - v197, " %u:%u,", 1, a1[218]);
            v199 = v198 + snprintf((char *)v11 + v198, 1000LL - v198, " %u:%u,", 2, a1[219]);
            v200 = snprintf((char *)v11 + v199, 1000LL - v199, " %u:%u,", 3, a1[220]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v199 + v200),
              1000LL - (unsigned __int16)(v199 + v200),
              " %u:%u,",
              4,
              a1[221]);
            DP_PRINT_STATS("rx_bw_ext = %s ", v201, v202, v203, v204, v205, v206, v207, v208, v11);
            qdf_mem_set(v11, 0x3E8u, 0);
            v209 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[230]);
            v210 = v209
                 + snprintf(
                     (char *)v11 + (unsigned __int16)v209,
                     1000LL - (unsigned __int16)v209,
                     " %u:%u,",
                     1,
                     a1[231]);
            LOWORD(v210) = v210
                         + snprintf(
                             (char *)v11 + (unsigned __int16)v210,
                             1000LL - (unsigned __int16)v210,
                             " %u:%u,",
                             2,
                             a1[232]);
            v211 = snprintf(
                     (char *)v11 + (unsigned __int16)v210,
                     1000LL - (unsigned __int16)v210,
                     " %u:%u,",
                     3,
                     a1[233]);
            snprintf(
              (char *)v11 + (unsigned __int16)(v210 + v211),
              1000LL - (unsigned __int16)(v210 + v211),
              " %u:%u,",
              4,
              a1[234]);
            DP_PRINT_STATS("rx_su_punctured_mode = %s ", v212, v213, v214, v215, v216, v217, v218, v219, v11);
            v20 = v222;
            goto LABEL_20;
          }
          goto LABEL_16;
        }
LABEL_18:
        v221 = "%s: Unable to allocate buffer for rx_gi_ext";
        goto LABEL_19;
      }
    }
  }
LABEL_16:
  v221 = "%s: Unable to allocate buffer for ul_ofdma_rx_gi_ext";
LABEL_19:
  qdf_trace_msg(0x45u, 2u, v221, v12, v13, v14, v15, v16, v17, v18, v19, "dp_print_rx_pdev_rate_ext_stats_tlv");
LABEL_20:
  if ( v20 )
    _qdf_mem_free(v20);
  if ( v226 )
    _qdf_mem_free(v226);
  if ( v223 )
    _qdf_mem_free(v223);
  if ( v227 )
    _qdf_mem_free(v227);
  if ( v224 )
    _qdf_mem_free(v224);
  if ( v228 )
    _qdf_mem_free(v228);
  if ( v225 )
    _qdf_mem_free(v225);
  if ( v229 )
    _qdf_mem_free(v229);
  result = _qdf_mem_free((__int64)v11);
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
