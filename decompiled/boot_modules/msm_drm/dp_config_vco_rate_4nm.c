__int64 __fastcall dp_config_vco_rate_4nm(__int64 a1, __int64 a2)
{
  int v4; // w21
  __int64 ipc_log_context; // x0
  int *v6; // x22
  __int64 v7; // x0
  int v8; // w2
  __int64 v9; // x21
  int v10; // w24
  __int64 v11; // x0
  int v12; // w7
  __int64 v13; // x0
  int v14; // w7
  int v15; // w0
  int v16; // w2
  __int64 v17; // x8
  int v18; // w5
  unsigned int v19; // w21
  int v20; // w21
  __int64 v21; // x0
  int v22; // w2
  __int64 v23; // x3
  unsigned int v24; // w21
  __int64 v25; // x25
  __int64 v26; // x0
  int v27; // w7
  __int64 v28; // x0
  int v29; // w7
  __int64 v30; // x0
  int v31; // w7
  __int64 v32; // x0
  int v33; // w7
  int *v34; // x25
  __int64 v35; // x0
  int v36; // w7
  __int64 v37; // x0
  int v38; // w7
  __int64 v39; // x0
  int v40; // w7
  __int64 v41; // x0
  int v42; // w7
  __int64 v43; // x0
  int v44; // w7
  __int64 v45; // x0
  int v46; // w7
  __int64 v47; // x0
  int v48; // w7
  __int64 v49; // x0
  int v50; // w7
  __int64 v51; // x0
  int v52; // w7
  __int64 v53; // x0
  int v54; // w7
  __int64 v55; // x0
  int v56; // w7
  __int64 v57; // x0
  int v58; // w7
  __int64 v59; // x0
  int v60; // w7
  __int64 v61; // x0
  int v62; // w7
  __int64 v63; // x0
  int v64; // w7
  __int64 v65; // x0
  int v66; // w7
  __int64 v67; // x0
  int v68; // w7
  __int64 v69; // x0
  int v70; // w7
  __int64 v71; // x0
  int v72; // w7
  __int64 v73; // x0
  int v74; // w7
  __int64 v75; // x0
  int v76; // w7
  __int64 v77; // x0
  int v78; // w7
  int v79; // w21
  __int64 v80; // x0
  int v81; // w2
  __int64 v82; // x3
  int v83; // w7
  int v84; // w0
  int v85; // w2
  __int64 v86; // x8
  int v87; // w5
  unsigned int v88; // w21
  __int64 v89; // x0
  int v90; // w7
  __int64 v91; // x0
  int v92; // w7
  __int64 v93; // x0
  int v94; // w7
  __int64 v95; // x0
  int v96; // w7
  __int64 v97; // x0
  int v98; // w7
  __int64 v99; // x0
  int v100; // w7
  __int64 v101; // x0
  int v102; // w7
  __int64 v103; // x0
  int v104; // w7
  __int64 v105; // x0
  int v106; // w7
  int v107; // w21
  __int64 v108; // x0
  int v109; // w2
  __int64 v110; // x3
  int v111; // w7
  int v112; // w0
  int v113; // w2
  __int64 v114; // x8
  int v115; // w5
  unsigned int v116; // w21
  __int64 v117; // x0
  int v118; // w7
  __int64 v119; // x0
  int v120; // w7
  __int64 v121; // x0
  int v122; // w7
  __int64 v123; // x0
  int v124; // w7
  __int64 v125; // x0
  int v126; // w7
  __int64 v127; // x0
  int v128; // w7
  __int64 v129; // x0
  int v130; // w7
  __int64 v131; // x0
  int v132; // w7
  __int64 v133; // x0
  int v134; // w7
  __int64 v135; // x0
  int v136; // w7
  __int64 v137; // x0
  int v138; // w7
  __int64 v139; // x0
  int v140; // w7
  __int64 v141; // x0
  int v142; // w7
  __int64 v143; // x0
  int v144; // w7
  __int64 v145; // x0
  int v146; // w7
  __int64 v147; // x0
  int v148; // w7
  __int64 v149; // x0
  int v150; // w7
  __int64 v151; // x0
  int v152; // w7
  __int64 v153; // x0
  int v154; // w7
  __int64 v155; // x0
  int v156; // w7
  __int64 v157; // x0
  int v158; // w7
  __int64 v159; // x0
  int v160; // w7
  __int64 v161; // x0
  int v162; // w7
  __int64 v163; // x0
  int v164; // w7
  __int64 v165; // x0
  int v166; // w7
  __int64 v167; // x0
  int v168; // w7
  unsigned int v170; // w21
  unsigned int v171; // w20
  __int64 v172; // x0
  int v173; // w7
  __int64 v174; // x0
  __int64 v175; // x0
  void *v176; // x0
  __int64 v177; // x0
  char v178; // [xsp+0h] [xbp-10h]
  char v179; // [xsp+0h] [xbp-10h]
  char v180; // [xsp+0h] [xbp-10h]
  char v181; // [xsp+0h] [xbp-10h]
  char v182; // [xsp+0h] [xbp-10h]
  char v183; // [xsp+0h] [xbp-10h]
  char v184; // [xsp+0h] [xbp-10h]
  char v185; // [xsp+0h] [xbp-10h]
  char v186; // [xsp+0h] [xbp-10h]
  char v187; // [xsp+0h] [xbp-10h]
  char v188; // [xsp+0h] [xbp-10h]
  char v189; // [xsp+0h] [xbp-10h]
  char v190; // [xsp+0h] [xbp-10h]
  char v191; // [xsp+0h] [xbp-10h]
  char v192; // [xsp+0h] [xbp-10h]
  char v193; // [xsp+0h] [xbp-10h]
  char v194; // [xsp+0h] [xbp-10h]
  char v195; // [xsp+0h] [xbp-10h]
  char v196; // [xsp+0h] [xbp-10h]
  char v197; // [xsp+0h] [xbp-10h]
  char v198; // [xsp+0h] [xbp-10h]
  char v199; // [xsp+0h] [xbp-10h]
  char v200; // [xsp+0h] [xbp-10h]
  char v201; // [xsp+0h] [xbp-10h]
  char v202; // [xsp+0h] [xbp-10h]
  char v203; // [xsp+0h] [xbp-10h]
  char v204; // [xsp+0h] [xbp-10h]
  char v205; // [xsp+0h] [xbp-10h]
  char v206; // [xsp+0h] [xbp-10h]
  char v207; // [xsp+0h] [xbp-10h]
  char v208; // [xsp+0h] [xbp-10h]
  char v209; // [xsp+0h] [xbp-10h]
  char v210; // [xsp+0h] [xbp-10h]
  char v211; // [xsp+0h] [xbp-10h]
  char v212; // [xsp+0h] [xbp-10h]
  char v213; // [xsp+0h] [xbp-10h]
  char v214; // [xsp+0h] [xbp-10h]
  char v215; // [xsp+0h] [xbp-10h]
  char v216; // [xsp+0h] [xbp-10h]
  char v217; // [xsp+0h] [xbp-10h]
  char v218; // [xsp+0h] [xbp-10h]
  char v219; // [xsp+0h] [xbp-10h]
  char v220; // [xsp+0h] [xbp-10h]
  char v221; // [xsp+0h] [xbp-10h]
  char v222; // [xsp+0h] [xbp-10h]
  char v223; // [xsp+0h] [xbp-10h]
  char v224; // [xsp+0h] [xbp-10h]
  char v225; // [xsp+0h] [xbp-10h]
  char v226; // [xsp+0h] [xbp-10h]
  char v227; // [xsp+0h] [xbp-10h]
  char v228; // [xsp+0h] [xbp-10h]
  char v229; // [xsp+0h] [xbp-10h]
  char v230; // [xsp+0h] [xbp-10h]
  char v231; // [xsp+0h] [xbp-10h]
  char v232; // [xsp+0h] [xbp-10h]
  char v233; // [xsp+0h] [xbp-10h]
  char v234; // [xsp+0h] [xbp-10h]
  char v235; // [xsp+0h] [xbp-10h]
  char v236; // [xsp+0h] [xbp-10h]
  char v237; // [xsp+0h] [xbp-10h]
  char v238; // [xsp+0h] [xbp-10h]
  char v239; // [xsp+0h] [xbp-10h]
  char v240; // [xsp+0h] [xbp-10h]
  char v241; // [xsp+0h] [xbp-10h]
  char v242; // [xsp+0h] [xbp-10h]

  v4 = readl_relaxed_2((unsigned int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 48) + 344LL) + 24LL) + 200LL));
  *(_BYTE *)(a1 + 56) = v4 & 0xF;
  *(_BYTE *)(a1 + 57) = (unsigned __int8)v4 >> 4;
  ipc_log_context = get_ipc_log_context();
  v6 = (int *)(_ReadStatusReg(SP_EL0) + 1800);
  ipc_log_string(
    ipc_log_context,
    "[d][%-4d]spare_value=0x%x, ln_cnt=0x%x, orientation=0x%x\n",
    *v6,
    v4,
    *(unsigned __int8 *)(a1 + 56),
    *(unsigned __int8 *)(a1 + 57));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]spare_value=0x%x, ln_cnt=0x%x, orientation=0x%x\n",
      *v6,
      v4,
      *(unsigned __int8 *)(a1 + 56),
      *(unsigned __int8 *)(a1 + 57));
  v7 = get_ipc_log_context();
  v8 = *v6;
  if ( a2 > 5399999 )
  {
    if ( a2 != 5400000 )
    {
      if ( a2 == 8100000 )
      {
        v9 = 8100000;
        ipc_log_string(v7, "[d][%-4d]VCO rate: %ld\n", v8, 8100000);
        v10 = 3;
        if ( (_drm_debug & 4) == 0 )
          goto LABEL_12;
        goto LABEL_11;
      }
      goto LABEL_181;
    }
    v9 = 10800000;
    ipc_log_string(v7, "[d][%-4d]VCO rate: %ld\n", v8, 10800000);
    v10 = 2;
    if ( (_drm_debug & 4) != 0 )
      goto LABEL_11;
  }
  else
  {
    if ( a2 != 1620000 )
    {
      if ( a2 == 2700000 )
      {
        v9 = 10800000;
        ipc_log_string(v7, "[d][%-4d]VCO rate: %ld\n", v8, 10800000);
        v10 = 1;
        if ( (_drm_debug & 4) == 0 )
          goto LABEL_12;
LABEL_11:
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]VCO rate: %ld\n", *v6, v9);
        goto LABEL_12;
      }
LABEL_181:
      ipc_log_string(v7, "[e][%-4d]unsupported rate %ld\n", v8, a2);
      printk(&unk_2618EB, "dp_vco_pll_init_db_4nm");
      v177 = get_ipc_log_context();
      ipc_log_string(v177, "[e][%-4d]VCO Init DB failed\n", *v6);
      v176 = &unk_22D9D2;
      goto LABEL_182;
    }
    v9 = 9720000;
    ipc_log_string(v7, "[d][%-4d]VCO rate: %ld\n", v8, 9720000);
    v10 = 0;
    if ( (_drm_debug & 4) != 0 )
      goto LABEL_11;
  }
LABEL_12:
  *(_DWORD *)(a1 + 60) = v10;
  v11 = get_ipc_log_context();
  ipc_log_string(
    v11,
    "[d][%-4d]DP_PHY_CFG_1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20LL,
    15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG_1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20LL,
      15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    251,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20,
    15,
    -1059143953,
    v12,
    v178);
  writel_relaxed_2(15, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20LL);
  if ( *(_BYTE *)(a1 + 56) == 4 )
  {
    v13 = get_ipc_log_context();
    ipc_log_string(
      v13,
      "[d][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL,
      125);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL,
        125);
    v15 = sde_dbg_base_evtlog;
    v16 = 259;
    v17 = *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL);
    v18 = 125;
    v19 = 125;
  }
  else
  {
    v20 = *(unsigned __int8 *)(a1 + 57);
    v21 = get_ipc_log_context();
    v22 = *v6;
    v23 = *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL;
    if ( v20 == 2 )
    {
      ipc_log_string(v21, "[d][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n", v22, v23, 109);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
          *v6,
          *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL,
          109);
      v15 = sde_dbg_base_evtlog;
      v16 = 255;
      v17 = *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL);
      v18 = 109;
      v19 = 109;
    }
    else
    {
      ipc_log_string(v21, "[d][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n", v22, v23, 117);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
          *v6,
          *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL,
          117);
      v15 = sde_dbg_base_evtlog;
      v16 = 257;
      v17 = *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL);
      v18 = 117;
      v19 = 117;
    }
  }
  sde_evtlog_log(v15, "dp_config_vco_rate_4nm", v16, 4, v17 + 24, v18, -1059143953, v14, v179);
  writel_relaxed_2(v19, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL);
  v24 = *(_DWORD *)(a1 + 60);
  if ( v24 > 3 )
  {
    v175 = get_ipc_log_context();
    ipc_log_string(v175, "[e][%-4d]link rate not set\n", *v6);
    v176 = &unk_22A22C;
LABEL_182:
    printk(v176, "dp_config_vco_rate_4nm");
    return 4294967274LL;
  }
  v25 = *(_QWORD *)(a1 + 64);
  __dsb(0xEu);
  v26 = get_ipc_log_context();
  ipc_log_string(
    v26,
    "[d][%-4d]QSERDES_COM_SVS_MODE_CLK_SEL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380LL,
    21);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_SVS_MODE_CLK_SEL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380LL,
      21);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    272,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380,
    21,
    -1059143953,
    v27,
    v180);
  writel_relaxed_2(21, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380LL);
  v28 = get_ipc_log_context();
  ipc_log_string(
    v28,
    "[d][%-4d]QSERDES_COM_SYSCLK_EN_SEL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272LL,
    59);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_SYSCLK_EN_SEL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272LL,
      59);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    273,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272,
    59,
    -1059143953,
    v29,
    v181);
  writel_relaxed_2(59, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272LL);
  v30 = get_ipc_log_context();
  ipc_log_string(
    v30,
    "[d][%-4d]QSERDES_COM_SYS_CLK_CTRL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 228LL,
    2);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_SYS_CLK_CTRL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 228LL,
      2);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    274,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 228,
    2,
    -1059143953,
    v31,
    v182);
  writel_relaxed_2(2, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 228LL);
  v32 = get_ipc_log_context();
  ipc_log_string(
    v32,
    "[d][%-4d]QSERDES_COM_CLK_ENABLE1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 224LL,
    12);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CLK_ENABLE1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 224LL,
      12);
  v34 = (int *)(v25 + 88LL * v24);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    275,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 224,
    12,
    -1059143953,
    v33,
    v183);
  writel_relaxed_2(12, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 224LL);
  v35 = get_ipc_log_context();
  ipc_log_string(
    v35,
    "[d][%-4d]QSERDES_COM_SYSCLK_BUF_ENABLE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 232LL,
    6);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_SYSCLK_BUF_ENABLE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 232LL,
      6);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    276,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 232,
    6,
    -1059143953,
    v36,
    v184);
  writel_relaxed_2(6, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 232LL);
  v37 = get_ipc_log_context();
  ipc_log_string(
    v37,
    "[d][%-4d]QSERDES_COM_CLK_SEL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 356LL,
    48);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CLK_SEL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 356LL,
      48);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    277,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 356,
    48,
    -1059143953,
    v38,
    v185);
  writel_relaxed_2(48, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 356LL);
  __dsb(0xEu);
  v39 = get_ipc_log_context();
  ipc_log_string(
    v39,
    "[d][%-4d]QSERDES_COM_PLL_IVCO, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244LL,
    v34[17]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_PLL_IVCO, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244LL,
      v34[17]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    282,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244,
    v34[17],
    -1059143953,
    v40,
    v186);
  writel_relaxed_2((unsigned int)v34[17], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244LL);
  v41 = get_ipc_log_context();
  ipc_log_string(
    v41,
    "[d][%-4d]QSERDES_COM_PLL_CCTRL_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 120LL,
    54);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_PLL_CCTRL_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 120LL,
      54);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    283,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 120,
    54,
    -1059143953,
    v42,
    v187);
  writel_relaxed_2(54, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 120LL);
  v43 = get_ipc_log_context();
  ipc_log_string(
    v43,
    "[d][%-4d]QSERDES_COM_PLL_RCTRL_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 116LL,
    22);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_PLL_RCTRL_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 116LL,
      22);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    284,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 116,
    22,
    -1059143953,
    v44,
    v188);
  writel_relaxed_2(22, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 116LL);
  v45 = get_ipc_log_context();
  ipc_log_string(
    v45,
    "[d][%-4d]QSERDES_COM_CP_CTRL_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 112LL,
    6);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CP_CTRL_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 112LL,
      6);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    285,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 112,
    6,
    -1059143953,
    v46,
    v189);
  writel_relaxed_2(6, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 112LL);
  __dsb(0xEu);
  v47 = get_ipc_log_context();
  ipc_log_string(
    v47,
    "[d][%-4d]QSERDES_COM_HSCLK_SEL_1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60LL,
    *v34);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_HSCLK_SEL_1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60LL,
      *v34);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    290,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60,
    *v34,
    -1059143953,
    v48,
    v190);
  writel_relaxed_2((unsigned int)*v34, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60LL);
  v49 = get_ipc_log_context();
  ipc_log_string(
    v49,
    "[d][%-4d]QSERDES_COM_DEC_START_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136LL,
    v34[5]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DEC_START_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136LL,
      v34[5]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    291,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136,
    v34[5],
    -1059143953,
    v50,
    v191);
  writel_relaxed_2((unsigned int)v34[5], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136LL);
  v51 = get_ipc_log_context();
  ipc_log_string(
    v51,
    "[d][%-4d]QSERDES_COM_DIV_FRAC_START1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144LL,
    v34[6]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DIV_FRAC_START1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144LL,
      v34[6]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    293,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144,
    v34[6],
    -1059143953,
    v52,
    v192);
  writel_relaxed_2((unsigned int)v34[6], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144LL);
  v53 = get_ipc_log_context();
  ipc_log_string(
    v53,
    "[d][%-4d]QSERDES_COM_DIV_FRAC_START2_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148LL,
    v34[7]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DIV_FRAC_START2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148LL,
      v34[7]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    295,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148,
    v34[7],
    -1059143953,
    v54,
    v193);
  writel_relaxed_2((unsigned int)v34[7], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148LL);
  v55 = get_ipc_log_context();
  ipc_log_string(
    v55,
    "[d][%-4d]QSERDES_COM_DIV_FRAC_START3_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152LL,
    v34[8]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DIV_FRAC_START3_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152LL,
      v34[8]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    297,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152,
    v34[8],
    -1059143953,
    v56,
    v194);
  writel_relaxed_2((unsigned int)v34[8], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152LL);
  v57 = get_ipc_log_context();
  ipc_log_string(
    v57,
    "[d][%-4d]QSERDES_COM_LOCK_CMP1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128LL,
    v34[9]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_LOCK_CMP1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128LL,
      v34[9]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    298,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128,
    v34[9],
    -1059143953,
    v58,
    v195);
  writel_relaxed_2((unsigned int)v34[9], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128LL);
  v59 = get_ipc_log_context();
  ipc_log_string(
    v59,
    "[d][%-4d]QSERDES_COM_LOCK_CMP2_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132LL,
    v34[10]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_LOCK_CMP2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132LL,
      v34[10]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    299,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132,
    v34[10],
    -1059143953,
    v60,
    v196);
  writel_relaxed_2((unsigned int)v34[10], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132LL);
  v61 = get_ipc_log_context();
  ipc_log_string(
    v61,
    "[d][%-4d]QSERDES_COM_LOCK_CMP_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288LL,
    v34[3]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_LOCK_CMP_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288LL,
      v34[3]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    300,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288,
    v34[3],
    -1059143953,
    v62,
    v197);
  writel_relaxed_2((unsigned int)v34[3], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288LL);
  v63 = get_ipc_log_context();
  ipc_log_string(
    v63,
    "[d][%-4d]DP_PHY_VCO_DIV, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112LL,
    v34[4]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_VCO_DIV, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112LL,
      v34[4]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    301,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112,
    v34[4],
    -1059143953,
    v64,
    v198);
  writel_relaxed_2((unsigned int)v34[4], *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112LL);
  __dsb(0xEu);
  v65 = get_ipc_log_context();
  ipc_log_string(
    v65,
    "[d][%-4d]QSERDES_COM_CMN_CONFIG_1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 372LL,
    18);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CMN_CONFIG_1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 372LL,
      18);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    305,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 372,
    18,
    -1059143953,
    v66,
    v199);
  writel_relaxed_2(18, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 372LL);
  v67 = get_ipc_log_context();
  ipc_log_string(
    v67,
    "[d][%-4d]QSERDES_COM_INTEGLOOP_GAIN0_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160LL,
    v34[1]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_INTEGLOOP_GAIN0_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160LL,
      v34[1]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    307,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160,
    v34[1],
    -1059143953,
    v68,
    v200);
  writel_relaxed_2((unsigned int)v34[1], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160LL);
  v69 = get_ipc_log_context();
  ipc_log_string(
    v69,
    "[d][%-4d]QSERDES_COM_INTEGLOOP_GAIN1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164LL,
    v34[2]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_INTEGLOOP_GAIN1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164LL,
      v34[2]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    309,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164,
    v34[2],
    -1059143953,
    v70,
    v201);
  writel_relaxed_2((unsigned int)v34[2], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164LL);
  v71 = get_ipc_log_context();
  ipc_log_string(
    v71,
    "[d][%-4d]QSERDES_COM_VCO_TUNE_MAP, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 320LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_VCO_TUNE_MAP, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 320LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    310,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 320,
    0,
    -1059143953,
    v72,
    v202);
  writel_relaxed_2(0, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 320LL);
  __dsb(0xEu);
  v73 = get_ipc_log_context();
  ipc_log_string(
    v73,
    "[d][%-4d]QSERDES_COM_BG_TIMER, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188LL,
    v34[18]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_BG_TIMER, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188LL,
      v34[18]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    314,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188,
    v34[18],
    -1059143953,
    v74,
    v203);
  writel_relaxed_2((unsigned int)v34[18], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188LL);
  v75 = get_ipc_log_context();
  ipc_log_string(
    v75,
    "[d][%-4d]QSERDES_COM_CORECLK_DIV_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 124LL,
    20);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CORECLK_DIV_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 124LL,
      20);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    315,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 124,
    20,
    -1059143953,
    v76,
    v204);
  writel_relaxed_2(20, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 124LL);
  v77 = get_ipc_log_context();
  ipc_log_string(
    v77,
    "[d][%-4d]QSERDES_COM_VCO_TUNE_CTRL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 316LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_VCO_TUNE_CTRL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 316LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    316,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 316,
    0,
    -1059143953,
    v78,
    v205);
  writel_relaxed_2(0, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 316LL);
  v79 = *(unsigned __int8 *)(a1 + 33);
  v80 = get_ipc_log_context();
  v81 = *v6;
  v82 = *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220LL;
  if ( v79 == 1 )
  {
    ipc_log_string(v80, "[d][%-4d]QSERDES_COM_BIAS_EN_CLKBUFLR_EN, addr=0x%llx, val=0x%x\n", v81, v82, 31);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_BIAS_EN_CLKBUFLR_EN, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220LL,
        31);
    v84 = sde_dbg_base_evtlog;
    v85 = 319;
    v86 = *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL);
    v87 = 31;
    v88 = 31;
  }
  else
  {
    ipc_log_string(v80, "[d][%-4d]QSERDES_COM_BIAS_EN_CLKBUFLR_EN, addr=0x%llx, val=0x%x\n", v81, v82, 23);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_BIAS_EN_CLKBUFLR_EN, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220LL,
        23);
    v84 = sde_dbg_base_evtlog;
    v85 = 321;
    v86 = *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL);
    v87 = 23;
    v88 = 23;
  }
  sde_evtlog_log(v84, "dp_config_vco_rate_4nm", v85, 4, v86 + 220, v87, -1059143953, v83, v206);
  writel_relaxed_2(v88, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220LL);
  v89 = get_ipc_log_context();
  ipc_log_string(
    v89,
    "[d][%-4d]QSERDES_COM_CORE_CLK_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368LL,
    v34[19]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CORE_CLK_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368LL,
      v34[19]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    323,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368,
    v34[19],
    -1059143953,
    v90,
    v207);
  writel_relaxed_2((unsigned int)v34[19], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368LL);
  v91 = get_ipc_log_context();
  ipc_log_string(
    v91,
    "[d][%-4d]QSERDES_COM_BIN_VCOCAL_CMP_CODE1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88LL,
    v34[15]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_BIN_VCOCAL_CMP_CODE1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88LL,
      v34[15]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    325,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88,
    v34[15],
    -1059143953,
    v92,
    v208);
  writel_relaxed_2((unsigned int)v34[15], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88LL);
  v93 = get_ipc_log_context();
  ipc_log_string(
    v93,
    "[d][%-4d]QSERDES_COM_BIN_VCOCAL_CMP_CODE2_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92LL,
    v34[16]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_BIN_VCOCAL_CMP_CODE2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92LL,
      v34[16]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    327,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92,
    v34[16],
    -1059143953,
    v94,
    v209);
  writel_relaxed_2((unsigned int)v34[16], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92LL);
  __dsb(0xEu);
  if ( *(_BYTE *)(a1 + 32) == 1 )
  {
    v95 = get_ipc_log_context();
    ipc_log_string(
      v95,
      "[d][%-4d]QSERDES_COM_SSC_EN_CENTER, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 192LL,
      1);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_EN_CENTER, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 192LL,
        1);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_config_vco_rate_4nm",
      332,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 192,
      1,
      -1059143953,
      v96,
      v210);
    writel_relaxed_2(1, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 192LL);
    v97 = get_ipc_log_context();
    ipc_log_string(
      v97,
      "[d][%-4d]QSERDES_COM_SSC_ADJ_PER1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 196LL,
      0);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_ADJ_PER1, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 196LL,
        0);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_config_vco_rate_4nm",
      333,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 196,
      0,
      -1059143953,
      v98,
      v211);
    writel_relaxed_2(0, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 196LL);
    v99 = get_ipc_log_context();
    ipc_log_string(
      v99,
      "[d][%-4d]QSERDES_COM_SSC_PER1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204LL,
      v34[13]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_PER1, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204LL,
        v34[13]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_config_vco_rate_4nm",
      334,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204,
      v34[13],
      -1059143953,
      v100,
      v212);
    writel_relaxed_2((unsigned int)v34[13], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204LL);
    v101 = get_ipc_log_context();
    ipc_log_string(
      v101,
      "[d][%-4d]QSERDES_COM_SSC_PER2, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208LL,
      v34[14]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_PER2, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208LL,
        v34[14]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_config_vco_rate_4nm",
      335,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208,
      v34[14],
      -1059143953,
      v102,
      v213);
    writel_relaxed_2((unsigned int)v34[14], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208LL);
    v103 = get_ipc_log_context();
    ipc_log_string(
      v103,
      "[d][%-4d]QSERDES_COM_SSC_STEP_SIZE1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96LL,
      v34[11]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_STEP_SIZE1_MODE0, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96LL,
        v34[11]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_config_vco_rate_4nm",
      337,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96,
      v34[11],
      -1059143953,
      v104,
      v214);
    writel_relaxed_2((unsigned int)v34[11], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96LL);
    v105 = get_ipc_log_context();
    ipc_log_string(
      v105,
      "[d][%-4d]QSERDES_COM_SSC_STEP_SIZE2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100LL,
      v34[12]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_STEP_SIZE2_MODE0, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100LL,
        v34[12]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_config_vco_rate_4nm",
      339,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100,
      v34[12],
      -1059143953,
      v106,
      v215);
    writel_relaxed_2((unsigned int)v34[12], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100LL);
  }
  v107 = *(unsigned __int8 *)(a1 + 57);
  v108 = get_ipc_log_context();
  v109 = *v6;
  v110 = *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL;
  if ( v107 == 2 )
  {
    ipc_log_string(v108, "[d][%-4d]DP_PHY_MODE, addr=0x%llx, val=0x%x\n", v109, v110, 76);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]DP_PHY_MODE, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL,
        76);
    v112 = sde_dbg_base_evtlog;
    v113 = 343;
    v114 = *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL);
    v115 = 76;
    v116 = 76;
  }
  else
  {
    ipc_log_string(v108, "[d][%-4d]DP_PHY_MODE, addr=0x%llx, val=0x%x\n", v109, v110, 92);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]DP_PHY_MODE, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL,
        92);
    v112 = sde_dbg_base_evtlog;
    v113 = 345;
    v114 = *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL);
    v115 = 92;
    v116 = 92;
  }
  sde_evtlog_log(v112, "dp_config_vco_rate_4nm", v113, 4, v114 + 28, v115, -1059143953, v111, v210);
  writel_relaxed_2(v116, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL);
  v117 = get_ipc_log_context();
  ipc_log_string(
    v117,
    "[d][%-4d]DP_PHY_AUX_CFG1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 36LL,
    19);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_AUX_CFG1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 36LL,
      19);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    347,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 36,
    19,
    -1059143953,
    v118,
    v216);
  writel_relaxed_2(19, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 36LL);
  v119 = get_ipc_log_context();
  ipc_log_string(
    v119,
    "[d][%-4d]DP_PHY_AUX_CFG2, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 40LL,
    164);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_AUX_CFG2, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 40LL,
      164);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    348,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 40,
    164,
    -1059143953,
    v120,
    v217);
  writel_relaxed_2(164, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 40LL);
  __dsb(0xEu);
  v121 = get_ipc_log_context();
  ipc_log_string(
    v121,
    "[d][%-4d]DP_PHY_TX0_TX1_LANE_CTL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 120LL,
    5);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_TX0_TX1_LANE_CTL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 120LL,
      5);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    353,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 120,
    5,
    -1059143953,
    v122,
    v218);
  writel_relaxed_2(5, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 120LL);
  v123 = get_ipc_log_context();
  ipc_log_string(
    v123,
    "[d][%-4d]DP_VMODE_CTRL1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 200LL,
    64);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_VMODE_CTRL1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 200LL,
      64);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    354,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 200,
    64,
    -1059143953,
    v124,
    v219);
  writel_relaxed_2(64, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 200LL);
  v125 = get_ipc_log_context();
  ipc_log_string(
    v125,
    "[d][%-4d]TXn_PRE_STALL_LDO_BOOST_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 32LL,
    48);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_PRE_STALL_LDO_BOOST_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 32LL,
      48);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    355,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 32,
    48,
    -1059143953,
    v126,
    v220);
  writel_relaxed_2(48, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 32LL);
  v127 = get_ipc_log_context();
  ipc_log_string(
    v127,
    "[d][%-4d]TXn_INTERFACE_SELECT, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 44LL,
    59);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_INTERFACE_SELECT, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 44LL,
      59);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    356,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 44,
    59,
    -1059143953,
    v128,
    v221);
  writel_relaxed_2(59, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 44LL);
  v129 = get_ipc_log_context();
  ipc_log_string(
    v129,
    "[d][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 8LL,
    15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 8LL,
      15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    357,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 8,
    15,
    -1059143953,
    v130,
    v222);
  writel_relaxed_2(15, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 8LL);
  v131 = get_ipc_log_context();
  ipc_log_string(
    v131,
    "[d][%-4d]TXn_RESET_TSYNC_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 28LL,
    3);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RESET_TSYNC_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 28LL,
      3);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    358,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 28,
    3,
    -1059143953,
    v132,
    v223);
  writel_relaxed_2(3, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 28LL);
  v133 = get_ipc_log_context();
  ipc_log_string(
    v133,
    "[d][%-4d]DP_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 192LL,
    15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 192LL,
      15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    359,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 192,
    15,
    -1059143953,
    v134,
    v224);
  writel_relaxed_2(15, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 192LL);
  v135 = get_ipc_log_context();
  ipc_log_string(
    v135,
    "[d][%-4d]TXn_PARRATE_REC_DETECT_IDLE_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 96LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_PARRATE_REC_DETECT_IDLE_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 96LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    360,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 96,
    0,
    -1059143953,
    v136,
    v225);
  writel_relaxed_2(0, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 96LL);
  v137 = get_ipc_log_context();
  ipc_log_string(
    v137,
    "[d][%-4d]DP_TX_INTERFACE_MODE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 196LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_TX_INTERFACE_MODE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 196LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    361,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 196,
    0,
    -1059143953,
    v138,
    v226);
  writel_relaxed_2(0, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 196LL);
  v139 = get_ipc_log_context();
  ipc_log_string(
    v139,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_TX, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 60LL,
    v34[20]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_TX, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 60LL,
      v34[20]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    362,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 60,
    v34[20],
    -1059143953,
    v140,
    v227);
  writel_relaxed_2((unsigned int)v34[20], *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 60LL);
  v141 = get_ipc_log_context();
  ipc_log_string(
    v141,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_RX, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 64LL,
    v34[21]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_RX, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 64LL,
      v34[21]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    363,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 64,
    v34[21],
    -1059143953,
    v142,
    v228);
  writel_relaxed_2((unsigned int)v34[21], *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 64LL);
  v143 = get_ipc_log_context();
  ipc_log_string(
    v143,
    "[d][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 36LL,
    4);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 36LL,
      4);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    364,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 36,
    4,
    -1059143953,
    v144,
    v229);
  writel_relaxed_2(4, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 36LL);
  __dsb(0xEu);
  v145 = get_ipc_log_context();
  ipc_log_string(
    v145,
    "[d][%-4d]DP_PHY_TX2_TX3_LANE_CTL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 156LL,
    5);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_TX2_TX3_LANE_CTL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 156LL,
      5);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    369,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 156,
    5,
    -1059143953,
    v146,
    v230);
  writel_relaxed_2(5, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 156LL);
  v147 = get_ipc_log_context();
  ipc_log_string(
    v147,
    "[d][%-4d]DP_VMODE_CTRL1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 200LL,
    64);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_VMODE_CTRL1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 200LL,
      64);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    370,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 200,
    64,
    -1059143953,
    v148,
    v231);
  writel_relaxed_2(64, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 200LL);
  v149 = get_ipc_log_context();
  ipc_log_string(
    v149,
    "[d][%-4d]TXn_PRE_STALL_LDO_BOOST_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 32LL,
    48);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_PRE_STALL_LDO_BOOST_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 32LL,
      48);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    371,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 32,
    48,
    -1059143953,
    v150,
    v232);
  writel_relaxed_2(48, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 32LL);
  v151 = get_ipc_log_context();
  ipc_log_string(
    v151,
    "[d][%-4d]TXn_INTERFACE_SELECT, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 44LL,
    59);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_INTERFACE_SELECT, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 44LL,
      59);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    372,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 44,
    59,
    -1059143953,
    v152,
    v233);
  writel_relaxed_2(59, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 44LL);
  v153 = get_ipc_log_context();
  ipc_log_string(
    v153,
    "[d][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 8LL,
    15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 8LL,
      15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    373,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 8,
    15,
    -1059143953,
    v154,
    v234);
  writel_relaxed_2(15, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 8LL);
  v155 = get_ipc_log_context();
  ipc_log_string(
    v155,
    "[d][%-4d]TXn_RESET_TSYNC_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 28LL,
    3);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RESET_TSYNC_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 28LL,
      3);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    374,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 28,
    3,
    -1059143953,
    v156,
    v235);
  writel_relaxed_2(3, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 28LL);
  v157 = get_ipc_log_context();
  ipc_log_string(
    v157,
    "[d][%-4d]DP_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 192LL,
    15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 192LL,
      15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    375,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 192,
    15,
    -1059143953,
    v158,
    v236);
  writel_relaxed_2(15, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 192LL);
  v159 = get_ipc_log_context();
  ipc_log_string(
    v159,
    "[d][%-4d]TXn_PARRATE_REC_DETECT_IDLE_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 96LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_PARRATE_REC_DETECT_IDLE_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 96LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    376,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 96,
    0,
    -1059143953,
    v160,
    v237);
  writel_relaxed_2(0, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 96LL);
  v161 = get_ipc_log_context();
  ipc_log_string(
    v161,
    "[d][%-4d]DP_TX_INTERFACE_MODE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 196LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_TX_INTERFACE_MODE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 196LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    377,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 196,
    0,
    -1059143953,
    v162,
    v238);
  writel_relaxed_2(0, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 196LL);
  v163 = get_ipc_log_context();
  ipc_log_string(
    v163,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_TX, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 60LL,
    v34[20]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_TX, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 60LL,
      v34[20]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    378,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 60,
    v34[20],
    -1059143953,
    v164,
    v239);
  writel_relaxed_2((unsigned int)v34[20], *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 60LL);
  v165 = get_ipc_log_context();
  ipc_log_string(
    v165,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_RX, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 64LL,
    v34[21]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_RX, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 64LL,
      v34[21]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    379,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 64,
    v34[21],
    -1059143953,
    v166,
    v240);
  writel_relaxed_2((unsigned int)v34[21], *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 64LL);
  v167 = get_ipc_log_context();
  ipc_log_string(
    v167,
    "[d][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 36LL,
    4);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 36LL,
      4);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_config_vco_rate_4nm",
    380,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 36,
    4,
    -1059143953,
    v168,
    v241);
  writel_relaxed_2(4, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 36LL);
  __dsb(0xEu);
  if ( (readl_relaxed_2(*(unsigned int **)(*(_QWORD *)(a1 + 376) + 24LL)) & 0x80000000) == 0 )
    return 4294967274LL;
  v170 = readl_relaxed_2((unsigned int *)(*(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112LL)) & 0xFFFFFFFC;
  if ( a2 > 5399999 )
  {
    if ( a2 == 5400000 )
    {
      v170 |= 2u;
      v171 = 4;
    }
    else
    {
      v171 = 6;
    }
  }
  else
  {
    v170 |= 1u;
    v171 = 2;
  }
  v172 = get_ipc_log_context();
  ipc_log_string(
    v172,
    "[d][%-4d]DP_PHY_VCO_DIV, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112LL,
    v170);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_VCO_DIV, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112LL,
      v170);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "set_vco_div",
    183,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112,
    v170,
    -1059143953,
    v173,
    v242);
  writel_relaxed_2(v170, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 112LL);
  __dsb(0xEu);
  clk_set_rate(***(_QWORD ***)(a1 + 384), *(_QWORD *)(a1 + 8) / 0xAuLL);
  clk_set_rate(*(_QWORD *)(**(_QWORD **)(a1 + 384) + 8LL), *(_QWORD *)(a1 + 8) / (unsigned __int64)v171);
  v174 = get_ipc_log_context();
  ipc_log_string(
    v174,
    "[d][%-4d]val=%#x div=%x link_clk rate=%lu vco_div_clk rate=%lu\n",
    *v6,
    v170,
    v171,
    *(_QWORD *)(a1 + 8) / 0xAuLL,
    *(_QWORD *)(a1 + 8) / (unsigned __int64)v171);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]val=%#x div=%x link_clk rate=%lu vco_div_clk rate=%lu\n",
      *v6,
      v170,
      v171,
      *(_QWORD *)(a1 + 8) / 0xAuLL,
      *(_QWORD *)(a1 + 8) / (unsigned __int64)v171);
  return 0;
}
