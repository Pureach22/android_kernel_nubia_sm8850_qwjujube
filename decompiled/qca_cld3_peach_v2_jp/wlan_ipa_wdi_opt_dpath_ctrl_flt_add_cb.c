__int64 __fastcall wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x28
  int v12; // w2
  int v13; // w3
  int v14; // w4
  int v15; // w5
  int v16; // w6
  int v17; // w7
  const char *v18; // x1
  __int64 result; // x0
  __int64 v20; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w6
  int v31; // w7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x27
  int v41; // w6
  int v42; // w7
  int v43; // w6
  int v44; // w7
  unsigned __int8 *v45; // x26
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  int v54; // w3
  int v55; // w4
  int v56; // w5
  int v57; // w6
  int v58; // w7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  int v67; // w3
  int v68; // w4
  int v69; // w5
  int v70; // w6
  int v71; // w7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  int v80; // w3
  int v81; // w4
  int v82; // w5
  int v83; // w6
  int v84; // w7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  int v93; // w3
  int v94; // w4
  int v95; // w5
  int v96; // w6
  int v97; // w7
  double v98; // d0
  double v99; // d1
  double v100; // d2
  double v101; // d3
  double v102; // d4
  double v103; // d5
  double v104; // d6
  double v105; // d7
  int v106; // w3
  int v107; // w4
  int v108; // w5
  int v109; // w6
  int v110; // w7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  int v119; // w3
  int v120; // w4
  int v121; // w5
  int v122; // w6
  int v123; // w7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  int v132; // w3
  int v133; // w4
  int v134; // w5
  int v135; // w6
  int v136; // w7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  int v145; // w3
  int v146; // w4
  int v147; // w5
  int v148; // w6
  int v149; // w7
  __int64 v150; // x8
  int v151; // w4
  __int16 v152; // w9
  __int64 v153; // x21
  int v154; // w4
  int v155; // w9
  unsigned int v156; // w8
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  int v165; // w4
  int v166; // w5
  int v167; // w6
  int v168; // w7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  unsigned int v177; // w0
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  unsigned int v186; // w20
  const char *v187; // x2
  unsigned int v188; // w22
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  int v197; // w4
  int v198; // w5
  int v199; // w6
  int v200; // w7
  const char *v201; // x1
  int v202; // w2
  int v203; // w3
  int v204; // w3
  int v205; // w4
  int v206; // w5
  int v207; // w6
  int v208; // w7
  int v209; // w6
  int v210; // w7
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  int v219; // w6
  int v220; // w7
  __int64 v221; // x0
  int v222; // w3
  int v223; // w4
  int v224; // w5
  int v225; // w6
  int v226; // w7
  __int64 v227; // x4
  double v228; // d0
  double v229; // d1
  double v230; // d2
  double v231; // d3
  double v232; // d4
  double v233; // d5
  double v234; // d6
  double v235; // d7
  __int64 v236; // x4
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  __int64 v245; // x4
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  char v254; // [xsp+0h] [xbp-20h]
  char v255[8]; // [xsp+0h] [xbp-20h]
  char v256; // [xsp+0h] [xbp-20h]
  char v257; // [xsp+0h] [xbp-20h]
  char v258; // [xsp+0h] [xbp-20h]
  char v259; // [xsp+0h] [xbp-20h]
  char v260; // [xsp+0h] [xbp-20h]
  char v261; // [xsp+0h] [xbp-20h]
  char v262; // [xsp+0h] [xbp-20h]
  char v263; // [xsp+0h] [xbp-20h]
  unsigned int v264; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v265; // [xsp+10h] [xbp-10h] BYREF
  __int16 v266; // [xsp+14h] [xbp-Ch] BYREF
  char v267; // [xsp+16h] [xbp-Ah]
  __int64 v268; // [xsp+18h] [xbp-8h]

  v268 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v264 = 0;
  v265 = 0;
  v267 = 0;
  v266 = 0;
  if ( !a1 || (v10 = a1 + 4096, *(unsigned __int8 *)(a1 + 7513) <= 2u) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: opt_dp_ctrl: Not initialized properly",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb");
    v18 = "opt_dp_ctrl: Not initialized properly";
LABEL_4:
    wlan_ipa_log_message((int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb", (int)v18, v12, v13, v14, v15, v16, v17, v254);
    goto LABEL_5;
  }
  v20 = *a2;
  if ( !lmac_get_htc_hdl(*(_QWORD *)a1, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: HTC Handle is null",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb");
    v18 = "HTC Handle is null";
    goto LABEL_4;
  }
  if ( (*(_BYTE *)(v10 + 3369) & 1) != 0 || *(_BYTE *)(v10 + 3368) == 1 )
  {
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl, reject flt addition while ssr or shutdown",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb");
    v18 = "opt_dp_ctrl, reject flt addition while ssr or shutdown";
    goto LABEL_4;
  }
  *(_QWORD *)v255 = v20;
  *(_DWORD *)(a1 + 8392) += v20;
  if ( !(_DWORD)v20 )
  {
LABEL_32:
    *(_WORD *)(v10 + 3640) = 0;
    *(_BYTE *)(v10 + 3642) = v255[0];
    qdf_event_reset(a1 + 8112);
    qdf_trace_msg(
      0x61u,
      8u,
      "%s: opt_dp_ctrl: op %d, pdev_id %d. num_flts %d",
      v169,
      v170,
      v171,
      v172,
      v173,
      v174,
      v175,
      v176,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
      *(unsigned __int8 *)(v10 + 3641),
      *(unsigned __int8 *)(v10 + 3640),
      *(unsigned int *)v255);
    if ( (*(_BYTE *)(v10 + 3369) & 1) == 0 && (*(_BYTE *)(v10 + 3368) & 1) == 0 )
    {
      cdp_ipa_tx_super_rule_setup(*(_QWORD *)(a1 + 1456));
      v177 = qdf_wait_single_event(a1 + 8112, 0x64u);
      v186 = *(_DWORD *)(a1 + 7740);
      *(_BYTE *)(v10 + 3700) = 0;
      *(_BYTE *)(v10 + 3804) = 0;
      *(_BYTE *)(v10 + 3908) = 0;
      if ( !(v177 | v186) )
      {
        if ( (v266 & 1) != 0 )
          *(_BYTE *)(v10 + 3746) = 1;
        if ( HIBYTE(v266) == 1 )
          *(_BYTE *)(v10 + 3850) = 1;
        result = 0;
        if ( v267 == 1 )
          *(_BYTE *)(v10 + 3954) = 1;
        goto LABEL_6;
      }
      if ( v177 == 15 )
        v187 = "%s: TIMEOUT_OCCURS";
      else
        v187 = "%s: Error on event wait for filter add cb";
      v188 = v177;
      qdf_trace_msg(
        0x61u,
        2u,
        v187,
        v178,
        v179,
        v180,
        v181,
        v182,
        v183,
        v184,
        v185,
        "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
        *(_QWORD *)v255);
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: clean Host DB due to filter add failure, status - %d, resp - %d",
        v189,
        v190,
        v191,
        v192,
        v193,
        v194,
        v195,
        v196,
        "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
        v188,
        v186);
      v201 = "opt_dp_ctrl: clean Host DB due to filter add failure, status - %d, resp - %d";
      v202 = v188;
      v203 = v186;
LABEL_51:
      wlan_ipa_log_message(
        (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
        (int)v201,
        v202,
        v203,
        v197,
        v198,
        v199,
        v200,
        v255[0]);
    }
LABEL_52:
    if ( (unsigned __int8)v266 == 1 )
    {
      *(_BYTE *)(v10 + 3746) = 2;
      *(_BYTE *)(v10 + 3648) = 0;
      qdf_mem_set((void *)(a1 + 7745), 4u, 0);
      qdf_mem_set((void *)(a1 + 7749), 4u, 0);
      qdf_mem_set((void *)(a1 + 7753), 0x10u, 0);
      qdf_mem_set((void *)(a1 + 7769), 0x10u, 0);
      v227 = *(unsigned int *)(a1 + 7792);
      *(_DWORD *)(a1 + 7788) = 0;
      *(_WORD *)(v10 + 3700) = 0;
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: flt cleaned with handle: %u",
        v228,
        v229,
        v230,
        v231,
        v232,
        v233,
        v234,
        v235,
        "dp_ipa_clean_tx_filter_db",
        v227);
    }
    if ( HIBYTE(v266) == 1 )
    {
      *(_BYTE *)(v10 + 3850) = 2;
      *(_BYTE *)(v10 + 3752) = 0;
      qdf_mem_set((void *)(a1 + 7849), 4u, 0);
      qdf_mem_set((void *)(a1 + 7853), 4u, 0);
      qdf_mem_set((void *)(a1 + 7857), 0x10u, 0);
      qdf_mem_set((void *)(a1 + 7873), 0x10u, 0);
      v236 = *(unsigned int *)(a1 + 7896);
      *(_DWORD *)(a1 + 7892) = 0;
      *(_WORD *)(v10 + 3804) = 0;
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: flt cleaned with handle: %u",
        v237,
        v238,
        v239,
        v240,
        v241,
        v242,
        v243,
        v244,
        "dp_ipa_clean_tx_filter_db",
        v236);
    }
    if ( v267 == 1 )
    {
      *(_BYTE *)(v10 + 3954) = 2;
      *(_BYTE *)(v10 + 3856) = 0;
      qdf_mem_set((void *)(a1 + 7953), 4u, 0);
      qdf_mem_set((void *)(a1 + 7957), 4u, 0);
      qdf_mem_set((void *)(a1 + 7961), 0x10u, 0);
      qdf_mem_set((void *)(a1 + 7977), 0x10u, 0);
      v245 = *(unsigned int *)(a1 + 8000);
      *(_DWORD *)(a1 + 7996) = 0;
      *(_WORD *)(v10 + 3908) = 0;
      qdf_trace_msg(
        0x61u,
        8u,
        "%s: opt_dp_ctrl: flt cleaned with handle: %u",
        v246,
        v247,
        v248,
        v249,
        v250,
        v251,
        v252,
        v253,
        "dp_ipa_clean_tx_filter_db",
        v245);
    }
LABEL_5:
    result = 49;
LABEL_6:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
    a2[4],
    a2[40],
    *((unsigned __int16 *)a2 + 21),
    *((unsigned __int16 *)a2 + 22));
  wlan_ipa_log_message(
    (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
    (int)"opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
    a2[4],
    a2[40],
    *((unsigned __int16 *)a2 + 21),
    *((unsigned __int16 *)a2 + 22),
    v30,
    v31,
    v20);
  v40 = *(_QWORD *)v255;
  if ( *(_DWORD *)v255 == 1
    || (qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          a2[52],
          a2[88],
          *((unsigned __int16 *)a2 + 45),
          *((unsigned __int16 *)a2 + 46)),
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
          a2[52],
          a2[88],
          *((unsigned __int16 *)a2 + 45),
          *((unsigned __int16 *)a2 + 46),
          v41,
          v42,
          v255[0]),
        (_DWORD)v40 == 2)
    || (qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          a2[100],
          a2[136],
          *((unsigned __int16 *)a2 + 69),
          *((unsigned __int16 *)a2 + 70)),
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
          a2[100],
          a2[136],
          *((unsigned __int16 *)a2 + 69),
          *((unsigned __int16 *)a2 + 70),
          v43,
          v44,
          v255[0]),
        (_DWORD)v40 == 3) )
  {
    v45 = a2 + 24;
    while ( 1 )
    {
      if ( *(_BYTE *)(v10 + 3701) == 1 )
      {
        if ( *(_BYTE *)(v10 + 3805) == 1 )
        {
          if ( *(_BYTE *)(v10 + 3909) == 1 )
          {
            qdf_trace_msg(
              0x61u,
              2u,
              "%s: Wrong TX flt count %d, flt already installed = %d",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
              *(unsigned int *)v255,
              3);
            v201 = "Wrong TX flt count %d, flt already installed = %d";
            v202 = *(_DWORD *)v255;
            v203 = 3;
            goto LABEL_51;
          }
          v150 = 2;
          v151 = *(v45 - 20);
          if ( !*(v45 - 20) )
          {
LABEL_28:
            v152 = 8;
            goto LABEL_29;
          }
        }
        else
        {
          v150 = 1;
          v151 = *(v45 - 20);
          if ( !*(v45 - 20) )
            goto LABEL_28;
        }
      }
      else
      {
        v150 = 0;
        v151 = *(v45 - 20);
        if ( !*(v45 - 20) )
          goto LABEL_28;
      }
      if ( v151 != 1 )
      {
        qdf_trace_msg(
          0x61u,
          2u,
          "%s: Wrong IPA version %d",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb");
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"Wrong IPA version %d",
          *(v45 - 20),
          v204,
          v205,
          v206,
          v207,
          v208,
          v255[0]);
        goto LABEL_52;
      }
      v152 = -8826;
LABEL_29:
      v153 = a1 + 7744 + 104LL * (unsigned int)v150;
      *(_WORD *)(v153 + 42) = v152;
      *((_DWORD *)v45 + 6) = v150 | 0x10;
      *(_BYTE *)v153 = 1;
      v154 = *(unsigned __int16 *)(v153 + 42);
      v155 = *((_DWORD *)v45 + 6);
      *(_WORD *)(v153 + 52) = 257;
      *(_BYTE *)((unsigned __int64)&v266 | v150) = 1;
      *(_DWORD *)(v153 + 48) = v155;
      *(_WORD *)(v153 + 44) = *((_WORD *)v45 + 9);
      *(_WORD *)(v153 + 46) = *((_WORD *)v45 + 10);
      LOBYTE(v155) = v45[16];
      *(_BYTE *)(v153 + 98) = 0;
      *(_BYTE *)(v153 + 41) = v155;
      if ( v154 == 56710 )
      {
        v265 = bswap32(*((_DWORD *)v45 - 4));
        qdf_mem_copy((void *)(v153 + 9), &v265, 4u);
        v265 = bswap32(*((_DWORD *)v45 - 3));
        qdf_mem_copy((void *)(v153 + 13), &v265, 4u);
        v265 = bswap32(*((_DWORD *)v45 - 2));
        qdf_mem_copy((void *)(v153 + 17), &v265, 4u);
        v265 = bswap32(*((_DWORD *)v45 - 1));
        qdf_mem_copy((void *)(v153 + 21), &v265, 4u);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 9));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          *(_DWORD *)(v153 + 9),
          v54,
          v55,
          v56,
          v57,
          v58,
          v255[0]);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 13));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          *(_DWORD *)(v153 + 13),
          v67,
          v68,
          v69,
          v70,
          v71,
          v256);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 17));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          *(_DWORD *)(v153 + 17),
          v80,
          v81,
          v82,
          v83,
          v84,
          v257);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 21));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 src stored in DB 0x%x",
          *(_DWORD *)(v153 + 21),
          v93,
          v94,
          v95,
          v96,
          v97,
          v258);
        v264 = bswap32(*(_DWORD *)v45);
        qdf_mem_copy((void *)(v153 + 25), &v264, 4u);
        v264 = bswap32(*((_DWORD *)v45 + 1));
        qdf_mem_copy((void *)(v153 + 29), &v264, 4u);
        v264 = bswap32(*((_DWORD *)v45 + 2));
        qdf_mem_copy((void *)(v153 + 33), &v264, 4u);
        v264 = bswap32(*((_DWORD *)v45 + 3));
        qdf_mem_copy((void *)(v153 + 37), &v264, 4u);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 25));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          *(_DWORD *)(v153 + 25),
          v106,
          v107,
          v108,
          v109,
          v110,
          v259);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          v117,
          v118,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 29));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          *(_DWORD *)(v153 + 29),
          v119,
          v120,
          v121,
          v122,
          v123,
          v260);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 33));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          *(_DWORD *)(v153 + 33),
          v132,
          v133,
          v134,
          v135,
          v136,
          v261);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          *(unsigned int *)(v153 + 37));
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: ipv6 dest stored in DB 0x%x",
          *(_DWORD *)(v153 + 37),
          v145,
          v146,
          v147,
          v148,
          v149,
          v262);
      }
      else
      {
        if ( v154 != 8 )
        {
          qdf_trace_msg(
            0x61u,
            2u,
            "%s: Wrong IP version %u",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb");
          goto LABEL_52;
        }
        v156 = bswap32(*((_DWORD *)v45 - 4));
        v264 = bswap32(*((_DWORD *)v45 - 3));
        v265 = v156;
        qdf_mem_copy((void *)(v153 + 1), &v265, 4u);
        qdf_mem_copy((void *)(v153 + 5), &v264, 4u);
        qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: src IPV4 stored in DB 0x%x, dst IPV4 stored in DB 0x%x",
          v157,
          v158,
          v159,
          v160,
          v161,
          v162,
          v163,
          v164,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          v265,
          v264);
        wlan_ipa_log_message(
          (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          (int)"opt_dp_ctrl: src IPV4 stored in DB 0x%x, dst IPV4 stored in DB 0x%x",
          v265,
          v264,
          v165,
          v166,
          v167,
          v168,
          v255[0]);
      }
      --v40;
      v45 += 48;
      if ( !v40 )
        goto LABEL_32;
    }
  }
  qdf_trace_msg(
    0x61u,
    8u,
    "%s: opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
    a2[148],
    a2[184],
    *((unsigned __int16 *)a2 + 93),
    *((unsigned __int16 *)a2 + 94));
  wlan_ipa_log_message(
    (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
    (int)"opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
    a2[148],
    a2[184],
    *((unsigned __int16 *)a2 + 93),
    *((unsigned __int16 *)a2 + 94),
    v209,
    v210,
    v255[0]);
  if ( (_DWORD)v40 == 4
    || (qdf_trace_msg(
          0x61u,
          8u,
          "%s: opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
          v211,
          v212,
          v213,
          v214,
          v215,
          v216,
          v217,
          v218,
          "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
          a2[196],
          a2[232],
          *((unsigned __int16 *)a2 + 117),
          *((unsigned __int16 *)a2 + 118)),
        v221 = wlan_ipa_log_message(
                 (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
                 (int)"opt_dp_ctrl: version: %u, protocol: %u, sport: %u, dport: %u",
                 a2[196],
                 a2[232],
                 *((unsigned __int16 *)a2 + 117),
                 *((unsigned __int16 *)a2 + 118),
                 v219,
                 v220,
                 v263),
        (_DWORD)v40 == 5) )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: Wrong count of TX flt coming from IPA %d",
      v211,
      v212,
      v213,
      v214,
      v215,
      v216,
      v217,
      v218,
      "wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
      (unsigned int)v40);
    wlan_ipa_log_message(
      (int)"wlan_ipa_wdi_opt_dpath_ctrl_flt_add_cb",
      (int)"Wrong count of TX flt coming from IPA %d",
      v40,
      v222,
      v223,
      v224,
      v225,
      v226,
      v263);
    goto LABEL_5;
  }
  __break(0x5512u);
  return cdp_ipa_tx_super_rule_setup(v221);
}
