__int64 __fastcall dp_print_ring_stats(unsigned __int8 *a1)
{
  __int64 v2; // x22
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
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
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
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
  __int64 v148; // x0
  unsigned int v149; // w8
  __int64 v150; // x21
  unsigned int v151; // w20
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  __int64 v168; // x8
  __int64 v169; // x20
  unsigned int v170; // w21
  __int64 v171; // x0
  unsigned int v172; // w20
  __int64 v173; // x21
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  unsigned int i; // w23
  __int64 v191; // x25
  int v192; // w26
  unsigned __int8 v193; // w8
  __int64 v194; // x0
  __int64 v195; // x25
  __int64 v196; // x26
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  __int64 v213; // x21
  unsigned int v214; // w20
  unsigned int j; // w24
  unsigned int v216; // w8
  __int64 v217; // x25
  int v218; // w26
  __int64 v219; // x8
  __int64 v220; // x8
  void (__fastcall *v221)(_QWORD); // x8
  const char *v222; // x2

  v2 = *((_QWORD *)a1 + 1);
  result = hif_rtpm_get(2u, 5u);
  if ( !(_DWORD)result )
  {
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 1912LL,
      0xBu,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6352LL,
      1u,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6432LL,
      2u,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6512LL,
      3u,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6592LL,
      4u,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6672LL,
      0xDu,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      v51);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 7160LL,
      6u,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 7240LL,
      7u,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 7720LL,
      0xCu,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 5712LL,
      0,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 5792LL,
      0,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      v91);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 5872LL,
      0,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      v98,
      v99);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 5952LL,
      0,
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6032LL,
      0,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6112LL,
      0,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6192LL,
      0,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      *((_QWORD *)a1 + 1) + 6272LL,
      0,
      v132,
      v133,
      v134,
      v135,
      v136,
      v137,
      v138,
      v139);
    v148 = *((_QWORD *)a1 + 1);
    if ( *(_BYTE *)(v148 + 7153) )
    {
      dp_print_ring_stat_from_hal(v148, v148 + 6752, 5u, v140, v141, v142, v143, v144, v145, v146, v147);
      v148 = *((_QWORD *)a1 + 1);
      v149 = *(unsigned __int8 *)(v148 + 7153);
      if ( v149 > 1 )
      {
        dp_print_ring_stat_from_hal(v148, v148 + 6832, 5u, v140, v141, v142, v143, v144, v145, v146, v147);
        v148 = *((_QWORD *)a1 + 1);
        v149 = *(unsigned __int8 *)(v148 + 7153);
        if ( v149 >= 3 )
        {
          dp_print_ring_stat_from_hal(v148, v148 + 6912, 5u, v140, v141, v142, v143, v144, v145, v146, v147);
          v148 = *((_QWORD *)a1 + 1);
          v149 = *(unsigned __int8 *)(v148 + 7153);
          if ( v149 >= 4 )
          {
            dp_print_ring_stat_from_hal(v148, v148 + 6992, 5u, v140, v141, v142, v143, v144, v145, v146, v147);
            v148 = *((_QWORD *)a1 + 1);
            v149 = *(unsigned __int8 *)(v148 + 7153);
            if ( v149 >= 5 )
            {
              dp_print_ring_stat_from_hal(v148, v148 + 7072, 5u, v140, v141, v142, v143, v144, v145, v146, v147);
              v148 = *((_QWORD *)a1 + 1);
              v149 = *(unsigned __int8 *)(v148 + 7153);
              if ( v149 >= 6 )
              {
                dp_print_ring_stat_from_hal(v148, v148 + 7152, 5u, v140, v141, v142, v143, v144, v145, v146, v147);
                v148 = *((_QWORD *)a1 + 1);
                v149 = *(unsigned __int8 *)(v148 + 7153);
                if ( v149 > 6 )
                  goto LABEL_64;
              }
            }
          }
        }
      }
      if ( v149 )
      {
        dp_print_ring_stat_from_hal(v148, v148 + 7320, 0xDu, v140, v141, v142, v143, v144, v145, v146, v147);
        v148 = *((_QWORD *)a1 + 1);
        if ( *(unsigned __int8 *)(v148 + 7153) > 1u )
        {
          dp_print_ring_stat_from_hal(v148, v148 + 7400, 0xDu, v140, v141, v142, v143, v144, v145, v146, v147);
          v148 = *((_QWORD *)a1 + 1);
          if ( *(unsigned __int8 *)(v148 + 7153) >= 3u )
          {
            dp_print_ring_stat_from_hal(v148, v148 + 7480, 0xDu, v140, v141, v142, v143, v144, v145, v146, v147);
            v148 = *((_QWORD *)a1 + 1);
            if ( *(unsigned __int8 *)(v148 + 7153) >= 4u )
            {
              dp_print_ring_stat_from_hal(v148, v148 + 7560, 0xDu, v140, v141, v142, v143, v144, v145, v146, v147);
              v148 = *((_QWORD *)a1 + 1);
              if ( *(unsigned __int8 *)(v148 + 7153) >= 5u )
              {
                dp_print_ring_stat_from_hal(v148, v148 + 7640, 0xDu, v140, v141, v142, v143, v144, v145, v146, v147);
                v148 = *((_QWORD *)a1 + 1);
                if ( *(unsigned __int8 *)(v148 + 7153) >= 6u )
                {
                  dp_print_ring_stat_from_hal(v148, v148 + 7720, 0xDu, v140, v141, v142, v143, v144, v145, v146, v147);
                  v148 = *((_QWORD *)a1 + 1);
                  if ( *(unsigned __int8 *)(v148 + 7153) > 6u )
                    goto LABEL_64;
                }
              }
            }
          }
        }
      }
    }
    if ( (*(_BYTE *)(v148 + 20040) & 2) != 0 )
    {
      if ( *(_BYTE *)(v148 + 20065) )
      {
        dp_print_ring_stat_from_hal(v148, v148 + 80, 0xEu, v140, v141, v142, v143, v144, v145, v146, v147);
        v148 = *((_QWORD *)a1 + 1);
        if ( *(unsigned __int8 *)(v148 + 20065) > 1u )
        {
          dp_print_ring_stat_from_hal(v148, v148 + 160, 0xEu, v140, v141, v142, v143, v144, v145, v146, v147);
          v148 = *((_QWORD *)a1 + 1);
          if ( *(unsigned __int8 *)(v148 + 20065) > 2u )
            goto LABEL_64;
        }
      }
    }
    else
    {
      v150 = v148;
      v151 = *a1;
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v148 + 40)) )
      {
        if ( v151 )
          goto LABEL_64;
        v151 = *(unsigned __int8 *)(*(_QWORD *)(v150 + 72) + 1LL);
      }
      if ( v151 > 1 )
        goto LABEL_64;
      dp_print_ring_stat_from_hal(
        *((_QWORD *)a1 + 1),
        *((_QWORD *)a1 + 1) + 80LL * v151 + 80,
        0xEu,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147);
      v148 = *((_QWORD *)a1 + 1);
    }
    dp_print_ring_stat_from_hal(v148, v148 + 18488, 0xEu, v140, v141, v142, v143, v144, v145, v146, v147);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      (__int64)(a1 + 112),
      0xEu,
      v152,
      v153,
      v154,
      v155,
      v156,
      v157,
      v158,
      v159);
    dp_print_ring_stat_from_hal(
      *((_QWORD *)a1 + 1),
      (__int64)(a1 + 192),
      0xEu,
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      v167);
    v168 = *(_QWORD *)(v2 + 40);
    if ( *(_BYTE *)(v168 + 808) )
    {
      v169 = *((_QWORD *)a1 + 1);
      v170 = *a1;
      if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v169 + 40)) )
      {
        if ( v170 )
          goto LABEL_64;
        v170 = *(unsigned __int8 *)(*(_QWORD *)(v169 + 72) + 1LL);
      }
      v171 = *((_QWORD *)a1 + 1);
      if ( (*(_BYTE *)(*(_QWORD *)(v171 + 40) + 633LL) & 1) != 0 )
      {
        if ( v170 > 2 )
          goto LABEL_64;
        v172 = v170;
        v173 = 80LL * v170;
        dp_print_ring_stat_from_hal(v171, v171 + v173 + 480, 0x10u, v140, v141, v142, v143, v144, v145, v146, v147);
        dp_print_ring_stat_from_hal(
          *((_QWORD *)a1 + 1),
          *((_QWORD *)a1 + 1) + v173 + 640,
          0x12u,
          v174,
          v175,
          v176,
          v177,
          v178,
          v179,
          v180,
          v181);
        dp_print_ring_stat_from_hal(
          *((_QWORD *)a1 + 1),
          *((_QWORD *)a1 + 1) + v173 + 160,
          0x13u,
          v182,
          v183,
          v184,
          v185,
          v186,
          v187,
          v188,
          v189);
        v171 = *((_QWORD *)a1 + 1);
      }
      else
      {
        if ( v170 > 2 )
          goto LABEL_64;
        v172 = v170;
      }
      dp_print_ring_stat_from_hal(v171, v171 + 80LL * v172 + 800, 0x11u, v140, v141, v142, v143, v144, v145, v146, v147);
      v168 = *(_QWORD *)(v2 + 40);
      if ( *(unsigned __int8 *)(v168 + 808) >= 2u )
      {
        for ( i = 1; i < *(unsigned __int8 *)(v168 + 808); ++i )
        {
          v191 = *((_QWORD *)a1 + 1);
          v192 = *a1;
          if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v191 + 40)) )
          {
            if ( v192 )
              goto LABEL_64;
            v193 = *(_BYTE *)(*(_QWORD *)(v191 + 72) + 1LL);
          }
          else if ( v192 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Both mac_id and pdev_id cannot be non zero",
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              v146,
              v147,
              "dp_get_lmac_id_for_pdev_id");
            v193 = 0;
          }
          else
          {
            v193 = i;
          }
          v194 = *((_QWORD *)a1 + 1);
          if ( *(_BYTE *)(*(_QWORD *)(v194 + 40) + 633LL) == 1 )
          {
            if ( v193 >= 3u )
              goto LABEL_64;
            v195 = v193 & 3;
            v196 = (16 * v195) | (v195 << 6);
            dp_print_ring_stat_from_hal(v194, v194 + v196 + 480, 0x10u, v140, v141, v142, v143, v144, v145, v146, v147);
            dp_print_ring_stat_from_hal(
              *((_QWORD *)a1 + 1),
              *((_QWORD *)a1 + 1) + v196 + 640,
              0x12u,
              v197,
              v198,
              v199,
              v200,
              v201,
              v202,
              v203,
              v204);
            dp_print_ring_stat_from_hal(
              *((_QWORD *)a1 + 1),
              *((_QWORD *)a1 + 1) + v196 + 160,
              0x13u,
              v205,
              v206,
              v207,
              v208,
              v209,
              v210,
              v211,
              v212);
            v194 = *((_QWORD *)a1 + 1);
          }
          else
          {
            if ( v193 > 2u )
              goto LABEL_64;
            LODWORD(v195) = v193 & 3;
          }
          dp_print_ring_stat_from_hal(
            v194,
            v194 + 80LL * (unsigned int)v195 + 800,
            0x11u,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147);
          v168 = *(_QWORD *)(v2 + 40);
        }
      }
    }
    if ( (*(_BYTE *)(v2 + 20064) & 1) != 0 || !*(_BYTE *)(v168 + 804) )
      goto LABEL_65;
    v213 = *((_QWORD *)a1 + 1);
    v214 = *a1;
    if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v213 + 40)) )
    {
      if ( v214 )
        goto LABEL_64;
      v214 = *(unsigned __int8 *)(*(_QWORD *)(v213 + 72) + 1LL);
    }
    if ( v214 <= 2 )
    {
      dp_print_ring_stat_from_hal(
        *((_QWORD *)a1 + 1),
        *((_QWORD *)a1 + 1) + 80LL * v214 + 320,
        0xFu,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147);
      if ( *(unsigned __int8 *)(*(_QWORD *)(v2 + 40) + 804LL) >= 2u )
      {
        for ( j = 1; j < *(unsigned __int8 *)(*(_QWORD *)(v2 + 40) + 804LL); ++j )
        {
          v217 = *((_QWORD *)a1 + 1);
          v218 = *a1;
          if ( (unsigned int)wlan_cfg_per_pdev_lmac_ring(*(_QWORD *)(v217 + 40)) )
          {
            if ( v218 )
              goto LABEL_64;
            v216 = *(unsigned __int8 *)(*(_QWORD *)(v217 + 72) + 1LL);
            if ( v216 > 2 )
              goto LABEL_64;
          }
          else if ( v218 )
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: Both mac_id and pdev_id cannot be non zero",
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              v146,
              v147,
              "dp_get_lmac_id_for_pdev_id");
            v216 = 0;
          }
          else
          {
            v216 = j;
            if ( j > 2 )
              goto LABEL_64;
          }
          dp_print_ring_stat_from_hal(
            *((_QWORD *)a1 + 1),
            *((_QWORD *)a1 + 1) + 80LL * v216 + 320,
            0xFu,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147);
        }
      }
LABEL_65:
      v219 = *(_QWORD *)(*((_QWORD *)a1 + 1) + 20056LL);
      if ( v219 )
      {
        v220 = *(_QWORD *)(v219 + 416);
        if ( v220 )
        {
          v221 = *(void (__fastcall **)(_QWORD))(v220 + 280);
          if ( v221 )
          {
            if ( *((_DWORD *)v221 - 1) != -1557217772 )
              __break(0x8228u);
            v221(a1);
            return hif_rtpm_put(4, 5u);
          }
        }
        v222 = "%s: callback not registered";
      }
      else
      {
        v222 = "%s: monitor soc is NULL";
      }
      qdf_trace_msg(
        0x92u,
        8u,
        v222,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        v147,
        "dp_print_txmon_ring_stat_from_hal");
      return hif_rtpm_put(4, 5u);
    }
LABEL_64:
    __break(0x5512u);
    goto LABEL_65;
  }
  return result;
}
