__int64 __fastcall dp_link_process_request(__int64 a1)
{
  _DWORD *v1; // x24
  int v2; // w8
  int *v3; // x21
  _DWORD *v5; // x20
  __int64 v6; // x8
  unsigned int *v7; // x25
  __int64 v8; // x0
  unsigned int v9; // w8
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x22
  __int64 link_status; // x0
  __int64 v13; // x8
  __int64 period; // x0
  unsigned int v15; // w22
  __int64 v16; // x8
  __int64 v17; // x0
  unsigned int v18; // w22
  __int64 v19; // x0
  unsigned __int64 v20; // x23
  const char *v21; // x3
  __int64 v22; // x8
  __int64 v23; // x0
  int v24; // w22
  __int64 v25; // x0
  __int64 v26; // x3
  unsigned __int64 v27; // x8
  const char *v28; // x4
  unsigned int *v29; // x26
  __int64 v30; // x5
  const char *v31; // x6
  __int64 v32; // x0
  unsigned __int64 v33; // x23
  const char *v34; // x5
  __int64 v35; // x0
  char v36; // w22
  __int64 v37; // x0
  __int64 v38; // x0
  int v39; // w22
  __int64 v40; // x0
  int v41; // w3
  const char *v42; // x4
  __int64 ipc_log_context; // x0
  __int64 result; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  int v47; // w5
  const char *v48; // x6
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x8
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x8
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x8
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x8
  __int64 v62; // x0
  int v63; // w9
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x8
  __int64 v68; // x0
  int v69; // w9
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x8
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x8
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x8
  __int64 v86; // x0
  __int64 v87; // x23
  int v88; // w22
  __int64 v89; // x0
  __int64 v90; // x8
  __int64 v91; // x0
  int v92; // w22
  __int64 v93; // x0
  const char *v94; // x8
  const char *v95; // x22
  int v96; // w22
  __int64 v97; // x0
  int v98; // w22
  __int64 v99; // x0
  int v100; // w22
  __int64 v101; // x0
  int v102; // w22
  __int64 v103; // x0
  int v104; // w22
  __int64 v105; // x0
  int v106; // w22
  __int64 v107; // x0
  int v108; // w22
  __int64 v109; // x0
  unsigned int v110; // w22
  __int64 v111; // x0
  int v112; // w8
  __int64 v113; // x0
  void *v114; // x0
  const char *v115; // x1
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x0
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x0
  __int64 v131; // x0
  __int64 v132; // x0
  __int64 v133; // x0
  __int64 v134; // x0
  __int64 v135; // x0
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x0
  __int64 v139; // x0
  __int64 v140; // x0
  __int64 v141; // x0
  __int64 v142; // x0
  __int64 v143; // x0
  __int64 v144; // x0
  __int64 v145; // x0
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x0
  __int64 v149; // x0
  int v150; // w9
  __int64 v151; // x0
  unsigned __int64 v152; // x23
  char v153; // w20
  __int64 v154; // x0
  char v155; // w22
  __int64 v156; // x0
  int v157; // w21
  int v158; // w20
  __int64 v159; // x0
  __int64 v160; // x2
  __int64 v161; // x0
  int v162; // w4
  int v163; // w5
  unsigned __int64 v164; // x20
  int v165; // w9
  unsigned int v166; // w20
  unsigned int v167; // w21
  __int64 v168; // x0
  unsigned __int64 v169; // x22
  __int64 v170; // x0
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x0
  int v174; // w4
  int v175; // w5
  __int64 v176; // x9
  const char *v177; // x8
  const char *v178; // x3
  int v179; // w9
  const char *v180; // x5
  __int64 v181; // x0
  __int64 v182; // x9
  const char *v183; // x8
  const char *v184; // x5
  int v185; // w9
  const char *v186; // x7
  __int64 v187; // x0
  __int64 v188; // x0
  __int64 v189; // x0
  __int64 v190; // x0
  __int64 v191; // x0
  __int64 v192; // x0
  int v193; // w8
  int v194; // w9
  __int64 v195; // x0
  __int64 v196; // x0
  __int64 v197; // x0
  void *v198; // x0
  unsigned int v199; // w21
  __int64 v200; // x0
  __int64 v201; // x0
  __int64 v202; // x0
  __int64 v203; // x0
  __int64 v204; // x0
  __int64 v205; // x8
  const char *v206; // x6
  int v207; // w6
  int v208; // w7
  __int64 v209; // x0
  __int64 v210; // x0
  unsigned int v211; // w26
  int v212; // w23
  int v213; // w20
  __int64 v214; // x0
  __int64 v215; // x0
  int v216; // w21
  int v217; // w24
  int v218; // w27
  unsigned int v219; // w25
  __int64 v220; // x0
  __int64 v221; // x0
  __int64 v222; // x0
  __int64 v223; // x0
  __int64 v224; // x0
  __int64 v225; // x0
  __int64 v226; // x0
  __int64 v227; // x0
  __int64 v228; // x0
  __int64 v229; // x0
  __int64 v230; // x0
  __int64 v231; // x0
  __int64 v232; // x8
  const char *v233; // x8
  __int64 v234; // x0
  int v235; // w8
  unsigned __int64 v236; // x20
  const char *v237; // x3
  __int64 v238; // x0
  unsigned int v239; // [xsp+8h] [xbp-18h]
  _BYTE v240[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v241[4]; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int8 v242[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v243; // [xsp+18h] [xbp-8h]

  v243 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_275B6D, "dp_link_process_request");
    result = 4294967274LL;
    goto LABEL_291;
  }
  *(_QWORD *)(a1 + 16) = 0;
  v1 = (_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 20) = -1;
  v3 = (int *)(a1 + 8);
  v2 = *(_DWORD *)(a1 + 8);
  *(_QWORD *)(a1 + 208) = 0;
  *(_DWORD *)(a1 - 24) = v2;
  v5 = (_DWORD *)(a1 - 24);
  v6 = *(_QWORD *)(a1 - 8);
  *(_DWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  *(_QWORD *)a1 = 0;
  *(_QWORD *)(a1 + 84) = 0;
  *(_QWORD *)(a1 + 92) = 0;
  *(_QWORD *)(a1 + 100) = 0;
  *(_QWORD *)(a1 + 108) = 0;
  *(_QWORD *)(a1 + 116) = 0;
  *(_QWORD *)(a1 + 76) = 0;
  v7 = (unsigned int *)(a1 + 76);
  v8 = drm_dp_dpcd_read(*(_QWORD *)(v6 + 24), 512, a1 + 8, 1);
  if ( (int)v8 <= 0 )
  {
    v45 = get_ipc_log_context(v8);
    ipc_log_string(v45, "[e][%-4d]failed to read sink count\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_25600A, "dp_link_parse_sink_count");
  }
  else
  {
    v9 = *(_DWORD *)(a1 + 8);
    *(_BYTE *)(a1 + 12) = (v9 & 0x40) != 0;
    *(_DWORD *)(a1 + 8) = v9 & 0x3F | (((v9 >> 7) & 1) << 6);
    v10 = get_ipc_log_context(v8);
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v10,
      "[d][%-4d]sink_count = 0x%x, cp_ready = 0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 8),
      *(unsigned __int8 *)(a1 + 12));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]sink_count = 0x%x, cp_ready = 0x%x\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(a1 + 8),
        *(unsigned __int8 *)(a1 + 12));
  }
  link_status = drm_dp_dpcd_read_link_status(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL), a1 + 220);
  if ( (int)link_status <= 5 )
  {
    v46 = get_ipc_log_context(link_status);
    ipc_log_string(v46, "[e][%-4d]DP link status read failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_218756, "dp_link_parse_sink_status_field");
  }
  v13 = *(_QWORD *)(a1 - 8);
  v240[0] = 0;
  period = drm_dp_dpcd_read(*(_QWORD *)(v13 + 24), 513, v240, 1);
  if ( !(_DWORD)period )
    goto LABEL_145;
  if ( (v240[0] & 2) == 0 )
    goto LABEL_163;
  period = drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL), 536, v240, 1);
  if ( !(_DWORD)period )
  {
LABEL_145:
    v113 = get_ipc_log_context(period);
    ipc_log_string(v113, "[e][%-4d]aux read failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v114 = &unk_23AB77;
    v115 = "dp_link_parse_request";
LABEL_161:
    period = printk(v114, v115);
    goto LABEL_162;
  }
  v15 = v240[0];
  if ( (v240[0] > 0x22u || ((1LL << v240[0]) & 0x500000116LL) == 0) && v240[0] != 96 )
  {
    v32 = get_ipc_log_context(period);
    v33 = _ReadStatusReg(SP_EL0);
    period = ipc_log_string(v32, "[d][%-4d]link 0x%x not supported\n", *(_DWORD *)(v33 + 1800), v15);
    if ( (_drm_debug & 4) != 0 )
      period = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]link 0x%x not supported\n", *(_DWORD *)(v33 + 1800), v15);
    goto LABEL_143;
  }
  *(_DWORD *)(a1 + 208) = v240[0];
  if ( v15 != 8 )
  {
    period = 0;
    if ( v15 != 1 )
      goto LABEL_18;
    goto LABEL_17;
  }
  v16 = *(_QWORD *)(a1 - 8);
  v242[0] = 0;
  v17 = drm_dp_dpcd_read(*(_QWORD *)(v16 + 24), 584, v242, 1);
  if ( (int)v17 <= 0 )
  {
    v128 = get_ipc_log_context(v17);
    ipc_log_string(v128, "[e][%-4d]failed to read phy link pattern\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v114 = &unk_233EDA;
    v115 = "dp_link_parse_phy_test_params";
    goto LABEL_161;
  }
  v18 = v242[0];
  *(_DWORD *)(a1 + 120) = v242[0];
  v19 = get_ipc_log_context(v17);
  v20 = _ReadStatusReg(SP_EL0);
  if ( v18 > 7 )
    v21 = "unknown";
  else
    v21 = off_280F88[v18];
  period = ipc_log_string(v19, "[d][%-4d]phy_test_pattern_sel = %s\n", *(_DWORD *)(v20 + 1800), v21);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v18 > 7 )
      v34 = "unknown";
    else
      v34 = off_280F88[v18];
    period = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]phy_test_pattern_sel = %s\n", *(_DWORD *)(v20 + 1800), v34);
  }
  if ( v18 >= 6 && v18 != 7 )
    goto LABEL_162;
  period = dp_link_parse_link_training_params(v5);
  v15 = *(_DWORD *)(a1 + 208);
  if ( v15 == 1 )
  {
LABEL_17:
    period = dp_link_parse_link_training_params(v5);
    v15 = *(_DWORD *)(a1 + 208);
  }
LABEL_18:
  if ( (v15 > 0x22 || ((1LL << v15) & 0x500000004LL) == 0) && v15 != 96 )
    goto LABEL_142;
  v22 = *(_QWORD *)(a1 - 8);
  v241[0] = 0;
  v23 = drm_dp_dpcd_read(*(_QWORD *)(v22 + 24), 545, v241, 1);
  if ( (int)v23 <= 0 )
  {
    v116 = get_ipc_log_context(v23);
    ipc_log_string(v116, "[e][%-4d]failed to read link video pattern\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v114 = &unk_267BF8;
LABEL_160:
    v115 = "dp_link_parse_video_pattern_params";
    goto LABEL_161;
  }
  v24 = v241[0];
  if ( v241[0] >= 4u )
  {
    v117 = get_ipc_log_context(v23);
    ipc_log_string(
      v117,
      "[e][%-4d]invalid link video pattern = 0x%x\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v24);
    v114 = &unk_275EE4;
LABEL_294:
    v115 = "dp_link_parse_video_pattern_params";
    goto LABEL_161;
  }
  *v1 = v241[0];
  v25 = get_ipc_log_context(v23);
  v26 = (unsigned int)*v1;
  v27 = _ReadStatusReg(SP_EL0);
  v28 = "unknown";
  if ( (unsigned int)v26 <= 3 )
    v28 = off_280FC8[v26];
  v29 = (unsigned int *)(v27 + 1800);
  ipc_log_string(v25, "[d][%-4d]link video pattern = 0x%x (%s)\n", *(_DWORD *)(v27 + 1800), v26, v28);
  if ( (_drm_debug & 4) != 0 )
  {
    v30 = (unsigned int)*v1;
    if ( (unsigned int)v30 > 3 )
      v31 = "unknown";
    else
      v31 = off_280FC8[v30];
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]link video pattern = 0x%x (%s)\n", *v29, v30, v31);
  }
  v35 = drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL), 562, v241, 1);
  if ( (int)v35 <= 0 )
  {
    v118 = get_ipc_log_context(v35);
    ipc_log_string(v118, "[e][%-4d]failed to read link bit depth\n", *v29);
    v114 = &unk_23750B;
    goto LABEL_160;
  }
  v36 = v241[0];
  *(_DWORD *)(a1 + 24) = (v241[0] >> 3) & 1;
  v37 = get_ipc_log_context(v35);
  v38 = ipc_log_string(v37, "[d][%-4d]link dynamic range = 0x%x (%s)\n", *v29);
  if ( (_drm_debug & 4) != 0 )
    v38 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]link dynamic range = 0x%x (%s)\n", *v29);
  v39 = v36 & 0xE0;
  if ( v39 && v39 != 32 && v39 != 64 )
  {
    v238 = get_ipc_log_context(v38);
    ipc_log_string(v238, "[e][%-4d]invalid link bit depth = 0x%x\n", *v29, v39);
    v114 = &unk_2560E4;
    goto LABEL_294;
  }
  *(_DWORD *)(a1 + 20) = v39;
  v40 = get_ipc_log_context(v38);
  v41 = *(_DWORD *)(a1 + 20);
  if ( v41 )
  {
    if ( v41 == 64 )
    {
      v42 = "DP_TEST_BIT_DEPTH_10";
    }
    else if ( v41 == 32 )
    {
      v42 = "DP_TEST_BIT_DEPTH_8";
    }
    else
    {
      v42 = "unknown";
    }
  }
  else
  {
    v42 = "DP_TEST_BIT_DEPTH_6";
  }
  ipc_log_string(v40, "[d][%-4d]link bit depth = 0x%x (%s)\n", *v29, v41, v42);
  if ( (_drm_debug & 4) != 0 )
  {
    v47 = *(_DWORD *)(a1 + 20);
    if ( v47 )
    {
      if ( v47 == 64 )
      {
        v48 = "DP_TEST_BIT_DEPTH_10";
      }
      else if ( v47 == 32 )
      {
        v48 = "DP_TEST_BIT_DEPTH_8";
      }
      else
      {
        v48 = "unknown";
      }
    }
    else
    {
      v48 = "DP_TEST_BIT_DEPTH_6";
    }
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]link bit depth = 0x%x (%s)\n", *v29, v47, v48);
  }
  v49 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v50 = drm_dp_dpcd_read(*(_QWORD *)(v49 + 24), 546, v242, 2);
  if ( (int)v50 <= 1 )
  {
    v119 = get_ipc_log_context(v50);
    ipc_log_string(v119, "[e][%-4d]failed to read 0x%x\n", *v29, 546);
    v120 = printk(&unk_2484D5, "dp_link_parse_timing_params1");
    v121 = get_ipc_log_context(v120);
    ipc_log_string(v121, "[e][%-4d]failed to parse test_h_total (DP_TEST_H_TOTAL_HI)\n", *v29);
    v114 = &unk_24845E;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 28) = __rev16(*(unsigned __int16 *)v242);
  v51 = get_ipc_log_context(v50);
  ipc_log_string(v51, "[d][%-4d]TEST_H_TOTAL = %d\n", *v29, *(_DWORD *)(a1 + 28));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_H_TOTAL = %d\n", *v29, *(_DWORD *)(a1 + 28));
  v52 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v53 = drm_dp_dpcd_read(*(_QWORD *)(v52 + 24), 548, v242, 2);
  if ( (int)v53 <= 1 )
  {
    v122 = get_ipc_log_context(v53);
    ipc_log_string(v122, "[e][%-4d]failed to read 0x%x\n", *v29, 548);
    v123 = printk(&unk_2484D5, "dp_link_parse_timing_params1");
    v124 = get_ipc_log_context(v123);
    ipc_log_string(v124, "[e][%-4d]failed to parse test_v_total (DP_TEST_V_TOTAL_HI)\n", *v29);
    v114 = &unk_211228;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 32) = __rev16(*(unsigned __int16 *)v242);
  v54 = get_ipc_log_context(v53);
  ipc_log_string(v54, "[d][%-4d]TEST_V_TOTAL = %d\n", *v29, *(_DWORD *)(a1 + 32));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_V_TOTAL = %d\n", *v29, *(_DWORD *)(a1 + 32));
  v55 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v56 = drm_dp_dpcd_read(*(_QWORD *)(v55 + 24), 550, v242, 2);
  if ( (int)v56 <= 1 )
  {
    v125 = get_ipc_log_context(v56);
    ipc_log_string(v125, "[e][%-4d]failed to read 0x%x\n", *v29, 550);
    v126 = printk(&unk_2484D5, "dp_link_parse_timing_params1");
    v127 = get_ipc_log_context(v126);
    ipc_log_string(v127, "[e][%-4d]failed to parse test_h_start (DP_TEST_H_START_HI)\n", *v29);
    v114 = &unk_223277;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 36) = __rev16(*(unsigned __int16 *)v242);
  v57 = get_ipc_log_context(v56);
  ipc_log_string(v57, "[d][%-4d]TEST_H_START = %d\n", *v29, *(_DWORD *)(a1 + 36));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_H_START = %d\n", *v29, *(_DWORD *)(a1 + 36));
  v58 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v59 = drm_dp_dpcd_read(*(_QWORD *)(v58 + 24), 552, v242, 2);
  if ( (int)v59 <= 1 )
  {
    v129 = get_ipc_log_context(v59);
    ipc_log_string(v129, "[e][%-4d]failed to read 0x%x\n", *v29, 552);
    v130 = printk(&unk_2484D5, "dp_link_parse_timing_params1");
    v131 = get_ipc_log_context(v130);
    ipc_log_string(v131, "[e][%-4d]failed to parse test_v_start (DP_TEST_V_START_HI)\n", *v29);
    v114 = &unk_24B768;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 40) = __rev16(*(unsigned __int16 *)v242);
  v60 = get_ipc_log_context(v59);
  ipc_log_string(v60, "[d][%-4d]TEST_V_START = %d\n", *v29, *(_DWORD *)(a1 + 40));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_V_START = %d\n", *v29, *(_DWORD *)(a1 + 40));
  v61 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v62 = drm_dp_dpcd_read(*(_QWORD *)(v61 + 24), 554, v242, 2);
  if ( (int)v62 <= 1 )
  {
    v132 = get_ipc_log_context(v62);
    ipc_log_string(v132, "[e][%-4d]failed to read 0x%x\n", *v29, 554);
    v133 = printk(&unk_2484D5, "dp_link_parse_timing_params2");
    v134 = get_ipc_log_context(v133);
    ipc_log_string(v134, "[e][%-4d]failed to parse (DP_TEST_HSYNC_HI)\n", *v29);
    v114 = &unk_26F200;
    goto LABEL_160;
  }
  v63 = v242[1] | ((v242[0] & 0x7F) << 8);
  *(_DWORD *)(a1 + 44) = v242[0] >> 7;
  *(_DWORD *)(a1 + 48) = v63;
  v64 = get_ipc_log_context(v62);
  v65 = ipc_log_string(v64, "[d][%-4d]TEST_HSYNC_POL = %d\n", *v29, *(_DWORD *)(a1 + 44));
  if ( (_drm_debug & 4) != 0 )
    v65 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_HSYNC_POL = %d\n", *v29, *(_DWORD *)(a1 + 44));
  v66 = get_ipc_log_context(v65);
  ipc_log_string(v66, "[d][%-4d]TEST_HSYNC_WIDTH = %d\n", *v29, *(_DWORD *)(a1 + 48));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_HSYNC_WIDTH = %d\n", *v29, *(_DWORD *)(a1 + 48));
  v67 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v68 = drm_dp_dpcd_read(*(_QWORD *)(v67 + 24), 556, v242, 2);
  if ( (int)v68 <= 1 )
  {
    v135 = get_ipc_log_context(v68);
    ipc_log_string(v135, "[e][%-4d]failed to read 0x%x\n", *v29, 556);
    v136 = printk(&unk_2484D5, "dp_link_parse_timing_params2");
    v137 = get_ipc_log_context(v136);
    ipc_log_string(v137, "[e][%-4d]failed to parse (DP_TEST_VSYNC_HI)\n", *v29);
    v114 = &unk_21C1F4;
    goto LABEL_160;
  }
  v69 = v242[1] | ((v242[0] & 0x7F) << 8);
  *(_DWORD *)(a1 + 52) = v242[0] >> 7;
  *(_DWORD *)(a1 + 56) = v69;
  v70 = get_ipc_log_context(v68);
  v71 = ipc_log_string(v70, "[d][%-4d]TEST_VSYNC_POL = %d\n", *v29, *(_DWORD *)(a1 + 52));
  if ( (_drm_debug & 4) != 0 )
    v71 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_VSYNC_POL = %d\n", *v29, *(_DWORD *)(a1 + 52));
  v72 = get_ipc_log_context(v71);
  ipc_log_string(v72, "[d][%-4d]TEST_VSYNC_WIDTH = %d\n", *v29, *(_DWORD *)(a1 + 56));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_VSYNC_WIDTH = %d\n", *v29, *(_DWORD *)(a1 + 56));
  v73 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v74 = drm_dp_dpcd_read(*(_QWORD *)(v73 + 24), 558, v242, 2);
  if ( (int)v74 <= 1 )
  {
    v138 = get_ipc_log_context(v74);
    ipc_log_string(v138, "[e][%-4d]failed to read 0x%x\n", *v29, 558);
    v139 = printk(&unk_2484D5, "dp_link_parse_timing_params1");
    v140 = get_ipc_log_context(v139);
    ipc_log_string(v140, "[e][%-4d]failed to parse test_h_width (DP_TEST_H_WIDTH_HI)\n", *v29);
    v114 = &unk_2232C6;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 60) = __rev16(*(unsigned __int16 *)v242);
  v75 = get_ipc_log_context(v74);
  ipc_log_string(v75, "[d][%-4d]TEST_H_WIDTH = %d\n", *v29, *(_DWORD *)(a1 + 60));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_H_WIDTH = %d\n", *v29, *(_DWORD *)(a1 + 60));
  v76 = *(_QWORD *)(a1 - 8);
  *(_WORD *)v242 = 0;
  v77 = drm_dp_dpcd_read(*(_QWORD *)(v76 + 24), 560, v242, 2);
  if ( (int)v77 <= 1 )
  {
    v141 = get_ipc_log_context(v77);
    ipc_log_string(v141, "[e][%-4d]failed to read 0x%x\n", *v29, 560);
    v142 = printk(&unk_2484D5, "dp_link_parse_timing_params1");
    v143 = get_ipc_log_context(v142);
    ipc_log_string(v143, "[e][%-4d]failed to parse test_v_height (DP_TEST_V_HEIGHT_HI)\n", *v29);
    v114 = &unk_2187DC;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 64) = __rev16(*(unsigned __int16 *)v242);
  v78 = get_ipc_log_context(v77);
  ipc_log_string(v78, "[d][%-4d]TEST_V_HEIGHT = %d\n", *v29, *(_DWORD *)(a1 + 64));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_V_HEIGHT = %d\n", *v29, *(_DWORD *)(a1 + 64));
  v79 = *(_QWORD *)(a1 - 8);
  v242[0] = 0;
  v80 = drm_dp_dpcd_read(*(_QWORD *)(v79 + 24), 563, v242, 1);
  if ( (int)v80 <= 0 )
  {
    v144 = get_ipc_log_context(v80);
    ipc_log_string(v144, "[e][%-4d]failed to read 0x%x\n", *v29, 563);
    v145 = printk(&unk_2484D5, "dp_link_parse_timing_params3");
    *(_DWORD *)(a1 + 68) &= 1u;
    v146 = get_ipc_log_context(v145);
    ipc_log_string(v146, "[e][%-4d]failed to parse test_rr_d (DP_TEST_MISC1)\n", *v29);
    v114 = &unk_233F73;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 68) = v242[0] & 1;
  v81 = get_ipc_log_context(v80);
  ipc_log_string(v81, "[d][%-4d]TEST_REFRESH_DENOMINATOR = %d\n", *v29, *(_DWORD *)(a1 + 68));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_REFRESH_DENOMINATOR = %d\n", *v29, *(_DWORD *)(a1 + 68));
  v82 = *(_QWORD *)(a1 - 8);
  v242[0] = 0;
  v83 = drm_dp_dpcd_read(*(_QWORD *)(v82 + 24), 564, v242, 1);
  if ( (int)v83 <= 0 )
  {
    v147 = get_ipc_log_context(v83);
    ipc_log_string(v147, "[e][%-4d]failed to read 0x%x\n", *v29, 564);
    v148 = printk(&unk_2484D5, "dp_link_parse_timing_params3");
    v149 = get_ipc_log_context(v148);
    ipc_log_string(v149, "[e][%-4d]failed to parse test_rr_n (DP_TEST_REFRESH_RATE_NUMERATOR)\n", *v29);
    v114 = &unk_223315;
    goto LABEL_160;
  }
  *(_DWORD *)(a1 + 72) = v242[0];
  v84 = get_ipc_log_context(v83);
  ipc_log_string(v84, "[d][%-4d]TEST_REFRESH_NUMERATOR = %d\n", *v29, *(_DWORD *)(a1 + 72));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]TEST_REFRESH_NUMERATOR = %d\n", *v29, *(_DWORD *)(a1 + 72));
  v85 = *(_QWORD *)(a1 - 8);
  v242[0] = 0;
  v86 = drm_dp_dpcd_read(*(_QWORD *)(v85 + 24), 625, v242, 1);
  if ( (int)v86 <= 0 )
  {
    v209 = get_ipc_log_context(v86);
    ipc_log_string(v209, "[e][%-4d]failed to read link audio mode data\n", *v29);
    v114 = &unk_226551;
    v115 = "dp_link_parse_audio_mode";
    goto LABEL_161;
  }
  v87 = v242[0] & 0xF;
  if ( (v242[0] & 0xFu) >= 7 )
  {
    v210 = get_ipc_log_context(v86);
    ipc_log_string(v210, "[e][%-4d]sampling rate (0x%x) greater than max (0x%x)\n", *v29, v87, 6);
    period = printk(&unk_25267B, "dp_link_parse_audio_mode");
    goto LABEL_162;
  }
  v88 = (v242[0] >> 4) + 1;
  if ( (v242[0] & 0x80) != 0 )
  {
    v229 = get_ipc_log_context(v86);
    ipc_log_string(v229, "[e][%-4d]channel_count (0x%x) greater than max (0x%x)\n", *v29, v88, 8);
    period = printk(&unk_21882D, "dp_link_parse_audio_mode");
    goto LABEL_162;
  }
  *(_DWORD *)(a1 + 76) = v87;
  *(_DWORD *)(a1 + 80) = v88;
  v89 = get_ipc_log_context(v86);
  ipc_log_string(v89, "[d][%-4d]sampling_rate = %s, channel_count = 0x%x\n", *v29, off_280FE8[v87], v88);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]sampling_rate = %s, channel_count = 0x%x\n",
      *v29,
      off_280FE8[(unsigned int)v87],
      v88);
  v90 = *(_QWORD *)(a1 - 8);
  v242[0] = 0;
  v91 = drm_dp_dpcd_read(*(_QWORD *)(v90 + 24), 626, v242, 1);
  if ( (int)v91 <= 0 )
  {
    v230 = get_ipc_log_context(v91);
    ipc_log_string(v230, "[e][%-4d]failed to read link audio mode data\n", *v29);
    v114 = &unk_226551;
    v115 = "dp_link_parse_audio_pattern_type";
    goto LABEL_161;
  }
  v92 = v242[0];
  if ( v242[0] >= 2u )
  {
    v231 = get_ipc_log_context(v91);
    ipc_log_string(v231, "[e][%-4d]invalid audio pattern type = 0x%x\n", *v29, v92);
    v114 = &unk_24B80A;
    v115 = "dp_link_parse_audio_pattern_type";
    goto LABEL_161;
  }
  *(_DWORD *)(a1 + 84) = v242[0];
  v93 = get_ipc_log_context(v91);
  v94 = "AUDIO_TEST_PATTERN_SAWTOOTH";
  if ( v92 != 1 )
    v94 = "unknown";
  if ( v92 )
    v95 = v94;
  else
    v95 = "AUDIO_TEST_PATTERN_OPERATOR_DEFINED";
  ipc_log_string(v93, "[d][%-4d]audio pattern type = %s\n", *v29, v95);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]audio pattern type = %s\n", *v29, v95);
  period = dp_link_get_period(v5, 627);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  v96 = period;
  *(_DWORD *)(a1 + 88) = period;
  v97 = get_ipc_log_context(period);
  ipc_log_string(v97, "[d][%-4d]test_audio_period_ch_1 = 0x%x\n", *v29, v96);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_1 = 0x%x\n", *v29, v96);
  period = dp_link_get_period(v5, 628);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  v98 = period;
  *(_DWORD *)(a1 + 92) = period;
  v99 = get_ipc_log_context(period);
  ipc_log_string(v99, "[d][%-4d]test_audio_period_ch_2 = 0x%x\n", *v29, v98);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_2 = 0x%x\n", *v29, v98);
  period = dp_link_get_period(v5, 629);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  v100 = period;
  *(_DWORD *)(a1 + 96) = period;
  v101 = get_ipc_log_context(period);
  ipc_log_string(v101, "[d][%-4d]test_audio_period_ch_3 = 0x%x\n", *v29, v100);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_3 = 0x%x\n", *v29, v100);
  period = dp_link_get_period(v5, 630);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  v102 = period;
  *(_DWORD *)(a1 + 100) = period;
  v103 = get_ipc_log_context(period);
  ipc_log_string(v103, "[d][%-4d]test_audio_period_ch_4 = 0x%x\n", *v29, v102);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_4 = 0x%x\n", *v29, v102);
  period = dp_link_get_period(v5, 631);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  v104 = period;
  *(_DWORD *)(a1 + 104) = period;
  v105 = get_ipc_log_context(period);
  ipc_log_string(v105, "[d][%-4d]test_audio_period_ch_5 = 0x%x\n", *v29, v104);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_5 = 0x%x\n", *v29, v104);
  period = dp_link_get_period(v5, 632);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  v106 = period;
  *(_DWORD *)(a1 + 108) = period;
  v107 = get_ipc_log_context(period);
  ipc_log_string(v107, "[d][%-4d]test_audio_period_ch_6 = 0x%x\n", *v29, v106);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_6 = 0x%x\n", *v29, v106);
  period = dp_link_get_period(v5, 633);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  v108 = period;
  *(_DWORD *)(a1 + 112) = period;
  v109 = get_ipc_log_context(period);
  ipc_log_string(v109, "[d][%-4d]test_audio_period_ch_7 = 0x%x\n", *v29, v108);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_7 = 0x%x\n", *v29, v108);
  period = dp_link_get_period(v5, 634);
  if ( (_DWORD)period == -22 )
    goto LABEL_162;
  *(_DWORD *)(a1 + 116) = period;
  v110 = period;
  v111 = get_ipc_log_context(period);
  ipc_log_string(v111, "[d][%-4d]test_audio_period_ch_8 = 0x%x\n", *v29, v110);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]test_audio_period_ch_8 = 0x%x\n", *v29, v110);
  period = v110;
LABEL_142:
  if ( (_DWORD)period )
  {
LABEL_162:
    *(_DWORD *)(a1 + 4) = 2;
LABEL_163:
    v112 = *(_DWORD *)(a1 + 208);
    if ( v112 == 4 )
      goto LABEL_270;
    goto LABEL_164;
  }
LABEL_143:
  v112 = *(_DWORD *)(a1 + 208);
  if ( v112 == 4 )
  {
    *(_DWORD *)(a1 + 4) = 4;
    goto LABEL_270;
  }
  *(_DWORD *)(a1 + 4) = 1;
LABEL_164:
  if ( (*(_BYTE *)(a1 + 222) & 0x40) != 0 )
  {
    v150 = *v3;
    goto LABEL_180;
  }
  v150 = *v3;
  if ( *v5 != *v3 )
  {
LABEL_180:
    *v5 = v150;
    v112 = 512;
    goto LABEL_270;
  }
  if ( v112 == 1 )
  {
    v161 = get_ipc_log_context(period);
    v162 = *(_DWORD *)(a1 + 212);
    v163 = *(_DWORD *)(a1 + 216);
    v164 = _ReadStatusReg(SP_EL0);
    period = ipc_log_string(
               v161,
               "[d][%-4d]%s link rate = 0x%x, lane count = 0x%x\n",
               *(_DWORD *)(v164 + 1800),
               "DP_TEST_LINK_TRAINING",
               v162,
               v163);
    if ( (_drm_debug & 4) != 0 )
      period = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]%s link rate = 0x%x, lane count = 0x%x\n",
                 *(_DWORD *)(v164 + 1800),
                 "DP_TEST_LINK_TRAINING",
                 *(_DWORD *)(a1 + 212),
                 *(_DWORD *)(a1 + 216));
    v165 = *(_DWORD *)(a1 + 212);
    *(_DWORD *)(a1 + 128) = *(_DWORD *)(a1 + 216);
    *(_DWORD *)(a1 + 132) = v165;
    v112 = 1;
LABEL_270:
    *(_DWORD *)a1 |= v112;
    v234 = get_ipc_log_context(period);
    v235 = *(_DWORD *)a1;
    v236 = _ReadStatusReg(SP_EL0);
    if ( v235 <= 7 )
    {
      switch ( v235 )
      {
        case 1:
          v237 = "DP_TEST_LINK_TRAINING";
          goto LABEL_287;
        case 2:
          v237 = "DP_TEST_LINK_VIDEO_PATTERN";
          goto LABEL_287;
        case 4:
          v237 = "DP_TEST_LINK_EDID_READ";
          goto LABEL_287;
      }
    }
    else if ( v235 > 127 )
    {
      if ( v235 == 128 )
      {
        v237 = "DP_LINK_STATUS_UPDATED";
        goto LABEL_287;
      }
      if ( v235 == 512 )
      {
        v237 = "DS_PORT_STATUS_CHANGED";
        goto LABEL_287;
      }
    }
    else
    {
      if ( v235 == 8 )
      {
        v237 = "DP_TEST_LINK_PHY_TEST_PATTERN";
        goto LABEL_287;
      }
      if ( v235 == 32 )
      {
        v237 = "DP_TEST_LINK_AUDIO_PATTERN";
LABEL_287:
        ipc_log_string(v234, "[i][%-4d]event: %s\n", *(_DWORD *)(v236 + 1800), v237);
        if ( (_drm_debug & 4) != 0 )
          printk(&unk_2483ED, *(unsigned int *)(v236 + 1800));
        else
          printk(&unk_27C4FB, "dp_link_process_request");
        result = 0;
        goto LABEL_291;
      }
    }
    v237 = "unknown";
    goto LABEL_287;
  }
  if ( (v112 & 8) != 0 )
  {
    v167 = *(_DWORD *)(a1 + 212);
    v166 = *(_DWORD *)(a1 + 216);
    if ( v167 > 0x1E || ((1 << v167) & 0x40100440) == 0 || v166 > 4 || ((1 << v166) & 0x16) == 0 )
    {
      v190 = get_ipc_log_context(period);
      v152 = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        v190,
        "[e][%-4d]Invalid params: link rate = 0x%x, lane count = 0x%x\n",
        *(_DWORD *)(v152 + 1800),
        v167,
        v166);
      printk(&unk_252708, "dp_link_process_phy_test_pattern_request");
      goto LABEL_170;
    }
    v168 = get_ipc_log_context(period);
    v169 = _ReadStatusReg(SP_EL0);
    v170 = ipc_log_string(v168, "[d][%-4d]start\n", *(_DWORD *)(v169 + 1800));
    if ( (_drm_debug & 4) != 0 )
      v170 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]start\n", *(_DWORD *)(v169 + 1800));
    v171 = get_ipc_log_context(v170);
    ipc_log_string(
      v171,
      "[i][%-4d]Current: bw_code = 0x%x, lane count = 0x%x\n",
      *(_DWORD *)(v169 + 1800),
      *(_DWORD *)(a1 + 132),
      *(_DWORD *)(a1 + 128));
    if ( (_drm_debug & 4) != 0 )
      v172 = printk(&unk_230B96, *(unsigned int *)(v169 + 1800));
    else
      v172 = printk(&unk_234030, "dp_link_process_phy_test_pattern_request");
    v191 = get_ipc_log_context(v172);
    ipc_log_string(
      v191,
      "[i][%-4d]Requested: bw_code = 0x%x, lane count = 0x%x\n",
      *(_DWORD *)(v169 + 1800),
      v167,
      v166);
    if ( (_drm_debug & 4) != 0 )
      v192 = printk(&unk_21C2C2, *(unsigned int *)(v169 + 1800));
    else
      v192 = printk(&unk_245067, "dp_link_process_phy_test_pattern_request");
    v194 = *(_DWORD *)(a1 + 212);
    v193 = *(_DWORD *)(a1 + 216);
    v242[0] = 0;
    *(_DWORD *)(a1 + 128) = v193;
    *(_DWORD *)(a1 + 132) = v194;
    v195 = get_ipc_log_context(v192);
    ipc_log_string(v195, "[d][%-4d]\n", *(_DWORD *)(v169 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]\n", *(_DWORD *)(v169 + 1800));
    v196 = drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL), 518, v242, 1);
    if ( (int)v196 > 0 )
    {
      v199 = v242[0];
      v200 = get_ipc_log_context(v196);
      ipc_log_string(v200, "[d][%-4d]lanes 0/1 (Byte 0x206): 0x%x\n", *(_DWORD *)(v169 + 1800), v199);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]lanes 0/1 (Byte 0x206): 0x%x\n", *(_DWORD *)(v169 + 1800), v199);
      v201 = drm_dp_dpcd_read(*(_QWORD *)(*(_QWORD *)(a1 - 8) + 24LL), 519, v242, 1);
      if ( (int)v201 > 0 )
      {
        v211 = v242[0];
        v212 = (v199 >> 4) & 3;
        v213 = v199 & 3;
        v239 = v199 >> 6;
        v214 = get_ipc_log_context(v201);
        v215 = ipc_log_string(v214, "[d][%-4d]lanes 2/3 (Byte 0x207): 0x%x\n", *(_DWORD *)(v169 + 1800), v211);
        if ( (_drm_debug & 4) != 0 )
          v215 = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]lanes 2/3 (Byte 0x207): 0x%x\n",
                   *(_DWORD *)(v169 + 1800),
                   v211);
        v216 = (v199 >> 2) & 3;
        v217 = (v211 >> 2) & 3;
        v218 = (v211 >> 4) & 3;
        v219 = v211 >> 6;
        v220 = get_ipc_log_context(v215);
        v221 = ipc_log_string(
                 v220,
                 "[d][%-4d]vx: 0=%d, 1=%d, 2=%d, 3=%d\n",
                 *(_DWORD *)(v169 + 1800),
                 v213,
                 v212,
                 v211 & 3,
                 v218);
        if ( (_drm_debug & 4) != 0 )
          v221 = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]vx: 0=%d, 1=%d, 2=%d, 3=%d\n",
                   *(_DWORD *)(v169 + 1800),
                   v213,
                   v212,
                   v211 & 3,
                   v218);
        v222 = get_ipc_log_context(v221);
        v223 = ipc_log_string(
                 v222,
                 "[d][%-4d]px: 0=%d, 1=%d, 2=%d, 3=%d\n",
                 *(_DWORD *)(v169 + 1800),
                 v216,
                 v239,
                 v217,
                 v219);
        if ( (_drm_debug & 4) != 0 )
          v223 = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]px: 0=%d, 1=%d, 2=%d, 3=%d\n",
                   *(_DWORD *)(v169 + 1800),
                   v216,
                   v239,
                   v217,
                   v219);
        v224 = get_ipc_log_context(v223);
        v225 = ipc_log_string(
                 v224,
                 "[d][%-4d]Current: v_level = 0x%x, p_level = 0x%x\n",
                 *(_DWORD *)(v169 + 1800),
                 *(unsigned __int8 *)(a1 + 124),
                 *(unsigned __int8 *)(a1 + 125));
        if ( (_drm_debug & 4) != 0 )
          v225 = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]Current: v_level = 0x%x, p_level = 0x%x\n",
                   *(_DWORD *)(v169 + 1800),
                   *(unsigned __int8 *)(a1 + 124),
                   *(unsigned __int8 *)(a1 + 125));
        v226 = get_ipc_log_context(v225);
        v227 = ipc_log_string(
                 v226,
                 "[d][%-4d]Requested: v_level = 0x%x, p_level = 0x%x\n",
                 *(_DWORD *)(v169 + 1800),
                 v213,
                 v216);
        if ( (_drm_debug & 4) != 0 )
          v227 = _drm_dev_dbg(
                   0,
                   0,
                   0,
                   "[msm-dp-debug][%-4d]Requested: v_level = 0x%x, p_level = 0x%x\n",
                   *(_DWORD *)(v169 + 1800),
                   v213,
                   v216);
        *(_BYTE *)(a1 + 124) = v213;
        *(_BYTE *)(a1 + 125) = v216;
        v228 = get_ipc_log_context(v227);
        v203 = ipc_log_string(v228, "[d][%-4d]Success\n", *(_DWORD *)(v169 + 1800));
        if ( (_drm_debug & 4) != 0 )
          v203 = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]Success\n", *(_DWORD *)(v169 + 1800));
        goto LABEL_231;
      }
      v202 = get_ipc_log_context(v201);
      ipc_log_string(v202, "[e][%-4d]failed reading lanes 2/3\n", *(_DWORD *)(v169 + 1800));
      v198 = &unk_26F25E;
    }
    else
    {
      v197 = get_ipc_log_context(v196);
      ipc_log_string(v197, "[e][%-4d]failed reading lanes 0/1\n", *(_DWORD *)(v169 + 1800));
      v198 = &unk_22D2D0;
    }
    v203 = printk(v198, "dp_link_parse_vx_px");
LABEL_231:
    v204 = get_ipc_log_context(v203);
    period = ipc_log_string(v204, "[d][%-4d]end\n", *(_DWORD *)(v169 + 1800));
    if ( (_drm_debug & 4) != 0 )
      period = _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]end\n", *(_DWORD *)(v169 + 1800));
    v112 = 8;
    goto LABEL_270;
  }
  v151 = get_ipc_log_context(period);
  v152 = _ReadStatusReg(SP_EL0);
  ipc_log_string(v151, "[d][%-4d]no phy test\n", *(_DWORD *)(v152 + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]no phy test\n", *(_DWORD *)(v152 + 1800));
LABEL_170:
  v153 = drm_dp_channel_eq_ok(a1 + 220, *(unsigned int *)(a1 + 128));
  v154 = drm_dp_clock_recovery_ok(a1 + 220, *(unsigned int *)(a1 + 128));
  v155 = v154;
  v156 = get_ipc_log_context(v154);
  v157 = v153 & 1;
  period = ipc_log_string(
             v156,
             "[d][%-4d]channel_eq_done = %d, clock_recovery_done = %d\n",
             *(_DWORD *)(v152 + 1800),
             v157,
             v155 & 1);
  if ( (_drm_debug & 4) != 0 )
    period = _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dp-debug][%-4d]channel_eq_done = %d, clock_recovery_done = %d\n",
               *(_DWORD *)(v152 + 1800),
               v157,
               v155 & 1);
  v112 = 128;
  if ( (v153 & 1) == 0 || (v155 & 1) == 0 )
    goto LABEL_270;
  v158 = *(_DWORD *)(a1 + 208);
  if ( (v158 & 0x42) == 2 )
  {
    v173 = get_ipc_log_context(period);
    v174 = *(_DWORD *)(a1 + 20);
    if ( v174 )
    {
      if ( v174 == 64 )
      {
        v175 = 30;
      }
      else if ( v174 == 32 )
      {
        v175 = 24;
      }
      else
      {
        v175 = 0;
      }
    }
    else
    {
      v175 = 18;
    }
    v205 = (unsigned int)*v1;
    if ( (unsigned int)v205 > 3 )
      v206 = "unknown";
    else
      v206 = off_280FC8[v205];
    period = ipc_log_string(
               v173,
               "[d][%-4d]%s: bit depth=%d(%d bpp) pattern=%s\n",
               *(_DWORD *)(v152 + 1800),
               "DP_TEST_LINK_VIDEO_PATTERN",
               v174,
               v175,
               v206);
    if ( (_drm_debug & 4) != 0 )
    {
      v207 = *(_DWORD *)(a1 + 20);
      if ( v207 )
      {
        if ( v207 == 64 )
        {
          v208 = 30;
        }
        else if ( v207 == 32 )
        {
          v208 = 24;
        }
        else
        {
          v208 = 0;
        }
      }
      else
      {
        v208 = 18;
      }
      v232 = (unsigned int)*v1;
      if ( (unsigned int)v232 > 3 )
        v233 = "unknown";
      else
        v233 = off_280FC8[v232];
      period = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]%s: bit depth=%d(%d bpp) pattern=%s\n",
                 *(_DWORD *)(v152 + 1800),
                 "DP_TEST_LINK_VIDEO_PATTERN",
                 v207,
                 v208,
                 v233);
    }
    v112 = 2;
    goto LABEL_270;
  }
  v159 = get_ipc_log_context(period);
  v160 = *(unsigned int *)(v152 + 1800);
  if ( (v158 & 0x20) != 0 )
  {
    v176 = *v7;
    v177 = "unknown";
    v178 = "unknown";
    if ( (unsigned int)v176 <= 6 )
      v178 = off_280FE8[v176];
    v179 = *(_DWORD *)(a1 + 84);
    if ( v179 == 1 )
      v177 = "AUDIO_TEST_PATTERN_SAWTOOTH";
    if ( v179 )
      v180 = v177;
    else
      v180 = "AUDIO_TEST_PATTERN_OPERATOR_DEFINED";
    v181 = ipc_log_string(
             v159,
             "[d][%-4d]sampling_rate=%s, channel_count=%d, pattern_type=%s\n",
             v160,
             v178,
             *(unsigned int *)(a1 + 80),
             v180);
    if ( (_drm_debug & 4) != 0 )
    {
      v182 = *v7;
      v183 = "unknown";
      v184 = "unknown";
      if ( (unsigned int)v182 <= 6 )
        v184 = off_280FE8[v182];
      v185 = *(_DWORD *)(a1 + 84);
      if ( v185 == 1 )
        v183 = "AUDIO_TEST_PATTERN_SAWTOOTH";
      if ( v185 )
        v186 = v183;
      else
        v186 = "AUDIO_TEST_PATTERN_OPERATOR_DEFINED";
      v181 = _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dp-debug][%-4d]sampling_rate=%s, channel_count=%d, pattern_type=%s\n",
               *(unsigned int *)(v152 + 1800),
               v184,
               *(unsigned int *)(a1 + 80),
               v186);
    }
    v187 = get_ipc_log_context(v181);
    v188 = ipc_log_string(
             v187,
             "[d][%-4d]audio_period: ch1=0x%x, ch2=0x%x, ch3=0x%x, ch4=0x%x\n",
             *(_DWORD *)(v152 + 1800),
             *(_DWORD *)(a1 + 88),
             *(_DWORD *)(a1 + 92),
             *(_DWORD *)(a1 + 96),
             *(_DWORD *)(a1 + 100));
    if ( (_drm_debug & 4) != 0 )
      v188 = _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dp-debug][%-4d]audio_period: ch1=0x%x, ch2=0x%x, ch3=0x%x, ch4=0x%x\n",
               *(_DWORD *)(v152 + 1800),
               *(_DWORD *)(a1 + 88),
               *(_DWORD *)(a1 + 92),
               *(_DWORD *)(a1 + 96),
               *(_DWORD *)(a1 + 100));
    v189 = get_ipc_log_context(v188);
    period = ipc_log_string(
               v189,
               "[d][%-4d]audio_period: ch5=0x%x, ch6=0x%x, ch7=0x%x, ch8=0x%x\n",
               *(_DWORD *)(v152 + 1800),
               *(_DWORD *)(a1 + 104),
               *(_DWORD *)(a1 + 108),
               *(_DWORD *)(a1 + 112),
               *(_DWORD *)(a1 + 116));
    if ( (_drm_debug & 4) != 0 )
      period = _drm_dev_dbg(
                 0,
                 0,
                 0,
                 "[msm-dp-debug][%-4d]audio_period: ch5=0x%x, ch6=0x%x, ch7=0x%x, ch8=0x%x\n",
                 *(_DWORD *)(v152 + 1800),
                 *(_DWORD *)(a1 + 104),
                 *(_DWORD *)(a1 + 108),
                 *(_DWORD *)(a1 + 112),
                 *(_DWORD *)(a1 + 116));
    v112 = 32;
    goto LABEL_270;
  }
  ipc_log_string(v159, "[d][%-4d]no test requested\n", v160);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]no test requested\n", *(_DWORD *)(v152 + 1800));
  result = 4294967274LL;
LABEL_291:
  _ReadStatusReg(SP_EL0);
  return result;
}
