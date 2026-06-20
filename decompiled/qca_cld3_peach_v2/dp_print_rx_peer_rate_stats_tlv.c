__int64 __fastcall dp_print_rx_peer_rate_stats_tlv(unsigned int *a1)
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
  __int64 v12; // x25
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  char *v30; // x20
  char *v31; // x21
  char *v32; // x22
  char *v33; // x23
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned __int16 v85; // w0
  unsigned __int16 v86; // w24
  unsigned __int16 v87; // w24
  unsigned __int16 v88; // w24
  unsigned __int16 v89; // w24
  unsigned __int16 v90; // w24
  unsigned __int16 v91; // w24
  unsigned __int16 v92; // w24
  unsigned __int16 v93; // w24
  unsigned __int16 v94; // w24
  unsigned __int16 v95; // w24
  unsigned __int16 v96; // w24
  __int16 v97; // w0
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  unsigned __int16 v106; // w0
  unsigned __int16 v107; // w24
  unsigned __int16 v108; // w24
  unsigned __int16 v109; // w24
  unsigned __int16 v110; // w24
  unsigned __int16 v111; // w24
  __int16 v112; // w0
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  unsigned __int16 v121; // w0
  unsigned __int16 v122; // w24
  unsigned __int16 v123; // w24
  __int16 v124; // w0
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned __int16 v133; // w0
  unsigned __int16 v134; // w24
  unsigned __int16 v135; // w24
  unsigned __int16 v136; // w24
  unsigned __int16 v137; // w24
  unsigned __int16 v138; // w24
  unsigned __int16 v139; // w24
  unsigned __int16 v140; // w24
  unsigned __int16 v141; // w24
  unsigned __int16 v142; // w24
  unsigned __int16 v143; // w24
  unsigned __int16 v144; // w24
  __int16 v145; // w0
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  unsigned __int16 v154; // w0
  unsigned __int16 v155; // w24
  __int16 v156; // w0
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 v165; // x26
  unsigned __int8 *v166; // x24
  char *v167; // x28
  unsigned __int16 v168; // w25
  unsigned __int16 v169; // w25
  __int16 v170; // w0
  int v171; // t1
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  __int64 v180; // x25
  int *v181; // x24
  char *v182; // x28
  int v183; // w27
  int v184; // w27
  int v185; // w27
  int v186; // w27
  int v187; // w27
  int v188; // w27
  int v189; // w27
  int v190; // w27
  int v191; // w27
  __int16 v192; // w0
  int v193; // t1
  double v194; // d0
  double v195; // d1
  double v196; // d2
  double v197; // d3
  double v198; // d4
  double v199; // d5
  double v200; // d6
  double v201; // d7
  unsigned __int16 v202; // w0
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  unsigned __int16 v211; // w0
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  unsigned __int16 v220; // w0
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  unsigned __int16 v229; // w0
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  int v238; // w26
  int v239; // w26
  int v240; // w26
  int v241; // w26
  __int16 v242; // w0
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  __int64 result; // x0
  unsigned int *v252; // [xsp+10h] [xbp-70h]
  __int64 v253; // [xsp+18h] [xbp-68h]
  __int64 v254; // [xsp+20h] [xbp-60h]
  __int64 v255; // [xsp+28h] [xbp-58h]
  __int64 v256; // [xsp+30h] [xbp-50h]
  __int64 v257; // [xsp+38h] [xbp-48h]
  __int64 v258; // [xsp+40h] [xbp-40h]
  __int64 v259; // [xsp+48h] [xbp-38h]
  __int64 v260; // [xsp+50h] [xbp-30h]
  __int64 v261; // [xsp+58h] [xbp-28h]
  __int64 v262; // [xsp+60h] [xbp-20h]
  __int64 v263; // [xsp+68h] [xbp-18h]
  __int64 v264; // [xsp+70h] [xbp-10h]
  __int64 v265; // [xsp+78h] [xbp-8h]

  v265 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v263 = 0;
  v264 = 0;
  v261 = 0;
  v262 = 0;
  v259 = 0;
  v260 = 0;
  v258 = 0;
  v255 = 0;
  v256 = 0;
  v253 = 0;
  v254 = 0;
  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1303);
  if ( !v2 )
  {
    result = qdf_trace_msg(
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
               "dp_print_rx_peer_rate_stats_tlv");
    goto LABEL_51;
  }
  v11 = (void *)v2;
  v12 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
  v257 = v12;
  if ( v12 )
  {
    v258 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
    if ( v258 )
    {
      v259 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
      if ( v259 )
      {
        v260 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
        if ( v260 )
        {
          v261 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
          if ( v261 )
          {
            v262 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
            if ( v262 )
            {
              v263 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
              if ( v263 )
              {
                v264 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1311);
                if ( v264 )
                {
                  v253 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1319);
                  v21 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1320);
                  v30 = (char *)v21;
                  v31 = nullptr;
                  if ( v253 )
                  {
                    v32 = nullptr;
                    v33 = nullptr;
                    if ( v21 )
                    {
                      v254 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1319);
                      v34 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1320);
                      v31 = (char *)v34;
                      v32 = nullptr;
                      if ( v254 && v34 )
                      {
                        v255 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1319);
                        v35 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1320);
                        v32 = (char *)v35;
                        v33 = nullptr;
                        if ( v255 )
                        {
                          if ( v35 )
                          {
                            v256 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1319);
                            v36 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_peer_rate_stats_tlv", 1320);
                            v33 = (char *)v36;
                            if ( v256 )
                            {
                              if ( v36 )
                              {
                                DP_PRINT_STATS("HTT_RX_PEER_RATE_STATS_TLV:", v22, v23, v24, v25, v26, v27, v28, v29);
                                DP_PRINT_STATS("nsts = %u", v37, v38, v39, v40, v41, v42, v43, v44, a1[1]);
                                DP_PRINT_STATS("rx_ldpc = %u", v45, v46, v47, v48, v49, v50, v51, v52, a1[2]);
                                DP_PRINT_STATS("rts_cnt = %u", v53, v54, v55, v56, v57, v58, v59, v60, a1[3]);
                                DP_PRINT_STATS("rssi_mgmt = %u", v61, v62, v63, v64, v65, v66, v67, v68, a1[4]);
                                DP_PRINT_STATS("rssi_data = %u", v69, v70, v71, v72, v73, v74, v75, v76, a1[5]);
                                DP_PRINT_STATS("rssi_comb = %u", v77, v78, v79, v80, v81, v82, v83, v84, a1[6]);
                                qdf_mem_set(v11, 0x3E8u, 0);
                                v85 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[7]);
                                v86 = v85 + snprintf((char *)v11 + v85, 1000LL - v85, " %u:%u,", 1, a1[8]);
                                v87 = v86 + snprintf((char *)v11 + v86, 1000LL - v86, " %u:%u,", 2, a1[9]);
                                v88 = v87 + snprintf((char *)v11 + v87, 1000LL - v87, " %u:%u,", 3, a1[10]);
                                v89 = v88 + snprintf((char *)v11 + v88, 1000LL - v88, " %u:%u,", 4, a1[11]);
                                v90 = v89 + snprintf((char *)v11 + v89, 1000LL - v89, " %u:%u,", 5, a1[12]);
                                v91 = v90 + snprintf((char *)v11 + v90, 1000LL - v90, " %u:%u,", 6, a1[13]);
                                v92 = v91 + snprintf((char *)v11 + v91, 1000LL - v91, " %u:%u,", 7, a1[14]);
                                v93 = v92 + snprintf((char *)v11 + v92, 1000LL - v92, " %u:%u,", 8, a1[15]);
                                v94 = v93 + snprintf((char *)v11 + v93, 1000LL - v93, " %u:%u,", 9, a1[16]);
                                v95 = v94 + snprintf((char *)v11 + v94, 1000LL - v94, " %u:%u,", 10, a1[17]);
                                v96 = v95 + snprintf((char *)v11 + v95, 1000LL - v95, " %u:%u,", 11, a1[18]);
                                v97 = snprintf((char *)v11 + v96, 1000LL - v96, " %u:%u,", 12, a1[138]);
                                snprintf(
                                  (char *)v11 + (unsigned __int16)(v96 + v97),
                                  1000LL - (unsigned __int16)(v96 + v97),
                                  " %u:%u,",
                                  13,
                                  a1[139]);
                                DP_PRINT_STATS("rx_mcs = %s ", v98, v99, v100, v101, v102, v103, v104, v105, v11);
                                qdf_mem_set(v11, 0x3E8u, 0);
                                v106 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 1, a1[19]);
                                v107 = v106 + snprintf((char *)v11 + v106, 1000LL - v106, " %u:%u,", 2, a1[20]);
                                v108 = v107 + snprintf((char *)v11 + v107, 1000LL - v107, " %u:%u,", 3, a1[21]);
                                v109 = v108 + snprintf((char *)v11 + v108, 1000LL - v108, " %u:%u,", 4, a1[22]);
                                v110 = v109 + snprintf((char *)v11 + v109, 1000LL - v109, " %u:%u,", 5, a1[23]);
                                v111 = v110 + snprintf((char *)v11 + v110, 1000LL - v110, " %u:%u,", 6, a1[24]);
                                v112 = snprintf((char *)v11 + v111, 1000LL - v111, " %u:%u,", 7, a1[25]);
                                snprintf(
                                  (char *)v11 + (unsigned __int16)(v111 + v112),
                                  1000LL - (unsigned __int16)(v111 + v112),
                                  " %u:%u,",
                                  8,
                                  a1[26]);
                                DP_PRINT_STATS("rx_nss = %s ", v113, v114, v115, v116, v117, v118, v119, v120, v11);
                                qdf_mem_set(v11, 0x3E8u, 0);
                                v121 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[27]);
                                v122 = v121 + snprintf((char *)v11 + v121, 1000LL - v121, " %u:%u,", 1, a1[28]);
                                v123 = v122 + snprintf((char *)v11 + v122, 1000LL - v122, " %u:%u,", 2, a1[29]);
                                v124 = snprintf((char *)v11 + v123, 1000LL - v123, " %u:%u,", 3, a1[30]);
                                snprintf(
                                  (char *)v11 + (unsigned __int16)(v123 + v124),
                                  1000LL - (unsigned __int16)(v123 + v124),
                                  " %u:%u,",
                                  4,
                                  a1[31]);
                                DP_PRINT_STATS("rx_dcm = %s ", v125, v126, v127, v128, v129, v130, v131, v132, v11);
                                qdf_mem_set(v11, 0x3E8u, 0);
                                v133 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[32]);
                                v134 = v133 + snprintf((char *)v11 + v133, 1000LL - v133, " %u:%u,", 1, a1[33]);
                                v135 = v134 + snprintf((char *)v11 + v134, 1000LL - v134, " %u:%u,", 2, a1[34]);
                                v136 = v135 + snprintf((char *)v11 + v135, 1000LL - v135, " %u:%u,", 3, a1[35]);
                                v137 = v136 + snprintf((char *)v11 + v136, 1000LL - v136, " %u:%u,", 4, a1[36]);
                                v138 = v137 + snprintf((char *)v11 + v137, 1000LL - v137, " %u:%u,", 5, a1[37]);
                                v139 = v138 + snprintf((char *)v11 + v138, 1000LL - v138, " %u:%u,", 6, a1[38]);
                                v140 = v139 + snprintf((char *)v11 + v139, 1000LL - v139, " %u:%u,", 7, a1[39]);
                                v141 = v140 + snprintf((char *)v11 + v140, 1000LL - v140, " %u:%u,", 8, a1[40]);
                                v142 = v141 + snprintf((char *)v11 + v141, 1000LL - v141, " %u:%u,", 9, a1[41]);
                                v143 = v142 + snprintf((char *)v11 + v142, 1000LL - v142, " %u:%u,", 10, a1[42]);
                                v144 = v143 + snprintf((char *)v11 + v143, 1000LL - v143, " %u:%u,", 11, a1[43]);
                                v145 = snprintf((char *)v11 + v144, 1000LL - v144, " %u:%u,", 12, a1[140]);
                                snprintf(
                                  (char *)v11 + (unsigned __int16)(v144 + v145),
                                  1000LL - (unsigned __int16)(v144 + v145),
                                  " %u:%u,",
                                  13,
                                  a1[141]);
                                DP_PRINT_STATS("rx_stbc = %s ", v146, v147, v148, v149, v150, v151, v152, v153, v11);
                                qdf_mem_set(v11, 0x3E8u, 0);
                                v154 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[44]);
                                v155 = v154 + snprintf((char *)v11 + v154, 1000LL - v154, " %u:%u,", 1, a1[45]);
                                v156 = snprintf((char *)v11 + v155, 1000LL - v155, " %u:%u,", 2, a1[46]);
                                snprintf(
                                  (char *)v11 + (unsigned __int16)(v155 + v156),
                                  1000LL - (unsigned __int16)(v155 + v156),
                                  " %u:%u,",
                                  3,
                                  a1[47]);
                                DP_PRINT_STATS("rx_bw = %s ", v157, v158, v159, v160, v161, v162, v163, v164, v11);
                                v165 = 0;
                                v166 = (unsigned __int8 *)a1 + 223;
                                v252 = a1;
                                do
                                {
                                  qdf_mem_set(v11, 0x3E8u, 0);
                                  v167 = (char *)*(&v257 + v165);
                                  v168 = snprintf(v167, 0x3E8u, " %u:%u,", 0, *(v166 - 3));
                                  v169 = v168 + snprintf(&v167[v168], 1000LL - v168, " %u:%u,", 1, *(v166 - 2));
                                  v170 = snprintf(&v167[v169], 1000LL - v169, " %u:%u,", 2, *(v166 - 1));
                                  v171 = *v166;
                                  v166 += 4;
                                  snprintf(
                                    &v167[(unsigned __int16)(v169 + v170)],
                                    1000LL - (unsigned __int16)(v169 + v170),
                                    " %u:%u,",
                                    3,
                                    v171);
                                  DP_PRINT_STATS(
                                    "rssi_chain[%u] = %s ",
                                    v172,
                                    v173,
                                    v174,
                                    v175,
                                    v176,
                                    v177,
                                    v178,
                                    v179,
                                    (unsigned int)v165++,
                                    v167);
                                }
                                while ( v165 != 8 );
                                v180 = 0;
                                v181 = (int *)(a1 + 74);
                                do
                                {
                                  v182 = (char *)*(&v253 + v180);
                                  v183 = snprintf(v182, 0x3E8u, " %u:%u,", 0, *(v181 - 11));
                                  v184 = v183
                                       + snprintf(
                                           &v182[(unsigned __int16)v183],
                                           1000LL - (unsigned __int16)v183,
                                           " %u:%u,",
                                           1,
                                           *(v181 - 10));
                                  v185 = v184
                                       + snprintf(
                                           &v182[(unsigned __int16)v184],
                                           1000LL - (unsigned __int16)v184,
                                           " %u:%u,",
                                           2,
                                           *(v181 - 9));
                                  v186 = v185
                                       + snprintf(
                                           &v182[(unsigned __int16)v185],
                                           1000LL - (unsigned __int16)v185,
                                           " %u:%u,",
                                           3,
                                           *(v181 - 8));
                                  v187 = v186
                                       + snprintf(
                                           &v182[(unsigned __int16)v186],
                                           1000LL - (unsigned __int16)v186,
                                           " %u:%u,",
                                           4,
                                           *(v181 - 7));
                                  v188 = v187
                                       + snprintf(
                                           &v182[(unsigned __int16)v187],
                                           1000LL - (unsigned __int16)v187,
                                           " %u:%u,",
                                           5,
                                           *(v181 - 6));
                                  v189 = v188
                                       + snprintf(
                                           &v182[(unsigned __int16)v188],
                                           1000LL - (unsigned __int16)v188,
                                           " %u:%u,",
                                           6,
                                           *(v181 - 5));
                                  v190 = v189
                                       + snprintf(
                                           &v182[(unsigned __int16)v189],
                                           1000LL - (unsigned __int16)v189,
                                           " %u:%u,",
                                           7,
                                           *(v181 - 4));
                                  v191 = v190
                                       + snprintf(
                                           &v182[(unsigned __int16)v190],
                                           1000LL - (unsigned __int16)v190,
                                           " %u:%u,",
                                           8,
                                           *(v181 - 3));
                                  LOWORD(v191) = v191
                                               + snprintf(
                                                   &v182[(unsigned __int16)v191],
                                                   1000LL - (unsigned __int16)v191,
                                                   " %u:%u,",
                                                   9,
                                                   *(v181 - 2));
                                  v192 = snprintf(
                                           &v182[(unsigned __int16)v191],
                                           1000LL - (unsigned __int16)v191,
                                           " %u:%u,",
                                           10,
                                           *(v181 - 1));
                                  v193 = *v181;
                                  v181 += 12;
                                  snprintf(
                                    &v182[(unsigned __int16)(v191 + v192)],
                                    1000LL - (unsigned __int16)(v191 + v192),
                                    " %u:%u,",
                                    11,
                                    v193);
                                  DP_PRINT_STATS(
                                    "rx_gi[%u] = %s ",
                                    v194,
                                    v195,
                                    v196,
                                    v197,
                                    v198,
                                    v199,
                                    v200,
                                    v201,
                                    (unsigned int)v180++,
                                    v182);
                                }
                                while ( v180 != 4 );
                                v202 = snprintf(v30, 0x3E8u, " %u:%u,", 0, v252[142]);
                                snprintf(&v30[v202], 1000LL - v202, " %u:%u,", 1, v252[143]);
                                DP_PRINT_STATS(
                                  "rx_gi_ext[%u] = %s ",
                                  v203,
                                  v204,
                                  v205,
                                  v206,
                                  v207,
                                  v208,
                                  v209,
                                  v210,
                                  0,
                                  v30);
                                v211 = snprintf(v31, 0x3E8u, " %u:%u,", 0, v252[144]);
                                snprintf(&v31[v211], 1000LL - v211, " %u:%u,", 1, v252[145]);
                                DP_PRINT_STATS(
                                  "rx_gi_ext[%u] = %s ",
                                  v212,
                                  v213,
                                  v214,
                                  v215,
                                  v216,
                                  v217,
                                  v218,
                                  v219,
                                  1,
                                  v31);
                                v220 = snprintf(v32, 0x3E8u, " %u:%u,", 0, v252[146]);
                                snprintf(&v32[v220], 1000LL - v220, " %u:%u,", 1, v252[147]);
                                DP_PRINT_STATS(
                                  "rx_gi_ext[%u] = %s ",
                                  v221,
                                  v222,
                                  v223,
                                  v224,
                                  v225,
                                  v226,
                                  v227,
                                  v228,
                                  2,
                                  v32);
                                v229 = snprintf(v33, 0x3E8u, " %u:%u,", 0, v252[148]);
                                snprintf(&v33[v229], 1000LL - v229, " %u:%u,", 1, v252[149]);
                                DP_PRINT_STATS(
                                  "rx_gi_ext[%u] = %s ",
                                  v230,
                                  v231,
                                  v232,
                                  v233,
                                  v234,
                                  v235,
                                  v236,
                                  v237,
                                  3,
                                  v33);
                                qdf_mem_set(v11, 0x3E8u, 0);
                                v238 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, v252[48]);
                                v239 = v238
                                     + snprintf(
                                         (char *)v11 + (unsigned __int16)v238,
                                         1000LL - (unsigned __int16)v238,
                                         " %u:%u,",
                                         1,
                                         v252[49]);
                                v240 = v239
                                     + snprintf(
                                         (char *)v11 + (unsigned __int16)v239,
                                         1000LL - (unsigned __int16)v239,
                                         " %u:%u,",
                                         2,
                                         v252[50]);
                                v241 = v240
                                     + snprintf(
                                         (char *)v11 + (unsigned __int16)v240,
                                         1000LL - (unsigned __int16)v240,
                                         " %u:%u,",
                                         3,
                                         v252[51]);
                                LOWORD(v241) = v241
                                             + snprintf(
                                                 (char *)v11 + (unsigned __int16)v241,
                                                 1000LL - (unsigned __int16)v241,
                                                 " %u:%u,",
                                                 4,
                                                 v252[52]);
                                v242 = snprintf(
                                         (char *)v11 + (unsigned __int16)v241,
                                         1000LL - (unsigned __int16)v241,
                                         " %u:%u,",
                                         5,
                                         v252[53]);
                                snprintf(
                                  (char *)v11 + (unsigned __int16)(v241 + v242),
                                  1000LL - (unsigned __int16)(v241 + v242),
                                  " %u:%u,",
                                  6,
                                  v252[54]);
                                DP_PRINT_STATS("rx_pream = %s\n", v243, v244, v245, v246, v247, v248, v249, v250, v11);
                                v12 = v257;
                                if ( !v257 )
                                  goto LABEL_33;
LABEL_25:
                                _qdf_mem_free(v12);
                                if ( v258 )
                                {
                                  _qdf_mem_free(v258);
                                  if ( v259 )
                                  {
                                    _qdf_mem_free(v259);
                                    if ( v260 )
                                    {
                                      _qdf_mem_free(v260);
                                      if ( v261 )
                                      {
                                        _qdf_mem_free(v261);
                                        if ( v262 )
                                        {
                                          _qdf_mem_free(v262);
                                          if ( v263 )
                                          {
                                            _qdf_mem_free(v263);
                                            if ( v264 )
                                              _qdf_mem_free(v264);
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                goto LABEL_33;
                              }
                            }
                          }
                        }
                      }
                      else
                      {
                        v33 = nullptr;
                      }
                    }
                  }
                  else
                  {
                    v32 = nullptr;
                    v33 = nullptr;
                  }
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: Unable to allocate buffer for rx_gi",
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    "dp_print_rx_peer_rate_stats_tlv");
                  goto LABEL_25;
                }
              }
            }
          }
        }
      }
    }
  }
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Unable to allocate buffer for rssi_chain",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "dp_print_rx_peer_rate_stats_tlv");
  v30 = nullptr;
  v31 = nullptr;
  v32 = nullptr;
  v33 = nullptr;
  if ( v12 )
    goto LABEL_25;
LABEL_33:
  if ( v253 )
    _qdf_mem_free(v253);
  if ( v30 )
    _qdf_mem_free((__int64)v30);
  if ( v254 )
    _qdf_mem_free(v254);
  if ( v31 )
    _qdf_mem_free((__int64)v31);
  if ( v255 )
    _qdf_mem_free(v255);
  if ( v32 )
    _qdf_mem_free((__int64)v32);
  if ( v256 )
    _qdf_mem_free(v256);
  if ( v33 )
    _qdf_mem_free((__int64)v33);
  result = _qdf_mem_free((__int64)v11);
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
