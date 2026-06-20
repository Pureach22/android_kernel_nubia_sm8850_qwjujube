__int64 __fastcall edp_config_vco_rate_4nm(__int64 a1, __int64 a2)
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
  unsigned int v15; // w25
  __int64 v16; // x26
  int v17; // w0
  __int64 v18; // x21
  __int64 v19; // x0
  int v20; // w7
  __int64 v21; // x0
  int v22; // w7
  __int64 v23; // x0
  int v24; // w7
  int *v25; // x21
  __int64 v26; // x0
  int v27; // w7
  __int64 v28; // x0
  int v29; // w7
  __int64 v30; // x0
  int v31; // w7
  __int64 v32; // x0
  int v33; // w7
  __int64 v34; // x0
  int v35; // w7
  __int64 v36; // x0
  int v37; // w7
  __int64 v38; // x0
  int v39; // w7
  __int64 v40; // x0
  int v41; // w7
  __int64 v42; // x0
  int v43; // w7
  __int64 v44; // x0
  int v45; // w7
  __int64 v46; // x0
  int v47; // w7
  __int64 v48; // x0
  int v49; // w7
  __int64 v50; // x0
  int v51; // w7
  __int64 v52; // x0
  int v53; // w7
  __int64 v54; // x0
  int v55; // w7
  __int64 v56; // x0
  int v57; // w7
  __int64 v58; // x0
  int v59; // w7
  __int64 v60; // x0
  int v61; // w7
  __int64 v62; // x0
  int v63; // w7
  __int64 v64; // x0
  int v65; // w7
  __int64 v66; // x0
  int v67; // w7
  __int64 v68; // x0
  int v69; // w7
  __int64 v70; // x0
  int v71; // w7
  __int64 v72; // x0
  int v73; // w7
  __int64 v74; // x0
  int v75; // w7
  __int64 v76; // x0
  int v77; // w7
  __int64 v78; // x0
  int v79; // w7
  __int64 v80; // x0
  int v81; // w7
  __int64 v82; // x0
  int v83; // w7
  __int64 v84; // x0
  int v85; // w7
  __int64 v86; // x0
  int v87; // w7
  __int64 v88; // x0
  int v89; // w7
  __int64 v90; // x0
  int v91; // w7
  __int64 v92; // x0
  int v93; // w7
  __int64 v94; // x0
  int v95; // w7
  __int64 v96; // x0
  int v97; // w7
  __int64 v98; // x0
  int v99; // w7
  __int64 v100; // x0
  int v101; // w7
  __int64 v102; // x0
  int v103; // w7
  __int64 v104; // x0
  int v105; // w7
  __int64 v106; // x0
  int v107; // w7
  __int64 v108; // x0
  int v109; // w7
  __int64 v110; // x0
  int v111; // w7
  __int64 v112; // x0
  int v113; // w7
  __int64 v114; // x0
  int v115; // w7
  __int64 v116; // x0
  int v117; // w7
  __int64 v118; // x0
  int v119; // w7
  __int64 v120; // x0
  int v121; // w7
  unsigned int v123; // w21
  unsigned int v124; // w20
  int v125; // w21
  __int64 v126; // x0
  __int64 v127; // x0
  int v128; // w7
  __int64 v129; // x0
  __int64 v130; // x0
  void *v131; // x0
  __int64 v132; // x0
  char v133; // [xsp+0h] [xbp-10h]
  char v134; // [xsp+0h] [xbp-10h]
  char v135; // [xsp+0h] [xbp-10h]
  char v136; // [xsp+0h] [xbp-10h]
  char v137; // [xsp+0h] [xbp-10h]
  char v138; // [xsp+0h] [xbp-10h]
  char v139; // [xsp+0h] [xbp-10h]
  char v140; // [xsp+0h] [xbp-10h]
  char v141; // [xsp+0h] [xbp-10h]
  char v142; // [xsp+0h] [xbp-10h]
  char v143; // [xsp+0h] [xbp-10h]
  char v144; // [xsp+0h] [xbp-10h]
  char v145; // [xsp+0h] [xbp-10h]
  char v146; // [xsp+0h] [xbp-10h]
  char v147; // [xsp+0h] [xbp-10h]
  char v148; // [xsp+0h] [xbp-10h]
  char v149; // [xsp+0h] [xbp-10h]
  char v150; // [xsp+0h] [xbp-10h]
  char v151; // [xsp+0h] [xbp-10h]
  char v152; // [xsp+0h] [xbp-10h]
  char v153; // [xsp+0h] [xbp-10h]
  char v154; // [xsp+0h] [xbp-10h]
  char v155; // [xsp+0h] [xbp-10h]
  char v156; // [xsp+0h] [xbp-10h]
  char v157; // [xsp+0h] [xbp-10h]
  char v158; // [xsp+0h] [xbp-10h]
  char v159; // [xsp+0h] [xbp-10h]
  char v160; // [xsp+0h] [xbp-10h]
  char v161; // [xsp+0h] [xbp-10h]
  char v162; // [xsp+0h] [xbp-10h]
  char v163; // [xsp+0h] [xbp-10h]
  char v164; // [xsp+0h] [xbp-10h]
  char v165; // [xsp+0h] [xbp-10h]
  char v166; // [xsp+0h] [xbp-10h]
  char v167; // [xsp+0h] [xbp-10h]
  char v168; // [xsp+0h] [xbp-10h]
  char v169; // [xsp+0h] [xbp-10h]
  char v170; // [xsp+0h] [xbp-10h]
  char v171; // [xsp+0h] [xbp-10h]
  char v172; // [xsp+0h] [xbp-10h]
  char v173; // [xsp+0h] [xbp-10h]
  char v174; // [xsp+0h] [xbp-10h]
  char v175; // [xsp+0h] [xbp-10h]
  char v176; // [xsp+0h] [xbp-10h]
  char v177; // [xsp+0h] [xbp-10h]
  char v178; // [xsp+0h] [xbp-10h]
  char v179; // [xsp+0h] [xbp-10h]
  char v180; // [xsp+0h] [xbp-10h]
  char v181; // [xsp+0h] [xbp-10h]
  char v182; // [xsp+0h] [xbp-10h]
  char v183; // [xsp+0h] [xbp-10h]
  char v184; // [xsp+0h] [xbp-10h]
  char v185; // [xsp+0h] [xbp-10h]

  v4 = readl_relaxed_5(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 48) + 344LL) + 24LL) + 204LL);
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
      goto LABEL_145;
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
LABEL_145:
      ipc_log_string(v7, "[e][%-4d]unsupported rate %ld\n", v8, a2);
      printk(&unk_2618EB, "edp_vco_pll_init_db_4nm");
      v132 = get_ipc_log_context();
      ipc_log_string(v132, "[e][%-4d]VCO Init DB failed\n", *v6);
      v131 = &unk_22D9D2;
      goto LABEL_146;
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
    "[d][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL,
    125);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL,
      125);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    237,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28,
    125,
    -1059143953,
    v12,
    v133);
  writel_relaxed_5(125, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL);
  v13 = get_ipc_log_context();
  ipc_log_string(
    v13,
    "[d][%-4d]DP_PHY_MODE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 32LL,
    252);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_MODE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 32LL,
      252);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    238,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 32,
    252,
    -1059143953,
    v14,
    v134);
  writel_relaxed_5(252, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 32LL);
  __dsb(0xEu);
  v15 = *(_DWORD *)(a1 + 60);
  if ( v15 > 3 )
  {
    v130 = get_ipc_log_context();
    ipc_log_string(v130, "[e][%-4d]link rate not set\n", *v6);
    v131 = &unk_22A22C;
LABEL_146:
    printk(v131, "edp_config_vco_rate_4nm");
    return 4294967274LL;
  }
  v16 = *(_QWORD *)(a1 + 64);
  v17 = readl_5(*(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 464LL);
  if ( (v17 & 0x80) != 0 )
  {
LABEL_21:
    if ( (v17 & 0x80) != 0 )
      goto LABEL_22;
    goto LABEL_135;
  }
  v18 = 105001;
  while ( 1 )
  {
    v18 -= 5001;
    if ( v18 < 0 )
      break;
    _const_udelay(21475);
    __yield();
    v17 = readl_5(*(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 464LL);
    if ( (v17 & 0x80) != 0 )
      goto LABEL_21;
  }
  v17 = readl_5(*(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 464LL);
  if ( (v17 & 0x80) == 0 )
  {
LABEL_135:
    v125 = v17;
    v126 = get_ipc_log_context();
    ipc_log_string(v126, "[e][%-4d]refgen not ready. Status=%x\n", *v6, v125);
    printk(&unk_268427, "edp_config_vco_rate_4nm");
  }
LABEL_22:
  v19 = get_ipc_log_context();
  ipc_log_string(
    v19,
    "[d][%-4d]TXn_LDO_CONFIG, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 132LL,
    145);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_LDO_CONFIG, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 132LL,
      145);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    256,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 132,
    145,
    -1059143953,
    v20,
    v135);
  writel_relaxed_5(145, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 132LL);
  v21 = get_ipc_log_context();
  ipc_log_string(
    v21,
    "[d][%-4d]TXn_LDO_CONFIG, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 132LL,
    145);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_LDO_CONFIG, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 132LL,
      145);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    257,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 132,
    145,
    -1059143953,
    v22,
    v136);
  writel_relaxed_5(145, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 132LL);
  v23 = get_ipc_log_context();
  ipc_log_string(
    v23,
    "[d][%-4d]TXn_LANE_MODE_1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 100LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_LANE_MODE_1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 100LL,
      0);
  v25 = (int *)(v16 + 88LL * v15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    258,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 100,
    0,
    -1059143953,
    v24,
    v137);
  writel_relaxed_5(0, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 100LL);
  v26 = get_ipc_log_context();
  ipc_log_string(
    v26,
    "[d][%-4d]TXn_LANE_MODE_1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 100LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_LANE_MODE_1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 100LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    259,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 100,
    0,
    -1059143953,
    v27,
    v138);
  writel_relaxed_5(0, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 100LL);
  if ( *(_BYTE *)(a1 + 32) == 1 )
  {
    v28 = get_ipc_log_context();
    ipc_log_string(
      v28,
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
      "edp_config_vco_rate_4nm",
      262,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 192,
      1,
      -1059143953,
      v29,
      v139);
    writel_relaxed_5(1, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 192LL);
    v30 = get_ipc_log_context();
    ipc_log_string(
      v30,
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
      "edp_config_vco_rate_4nm",
      263,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 196,
      0,
      -1059143953,
      v31,
      v140);
    writel_relaxed_5(0, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 196LL);
    v32 = get_ipc_log_context();
    ipc_log_string(
      v32,
      "[d][%-4d]QSERDES_COM_SSC_PER1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204LL,
      v25[13]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_PER1, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204LL,
        v25[13]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "edp_config_vco_rate_4nm",
      264,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204,
      v25[13],
      -1059143953,
      v33,
      v141);
    writel_relaxed_5((unsigned int)v25[13], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 204LL);
    v34 = get_ipc_log_context();
    ipc_log_string(
      v34,
      "[d][%-4d]QSERDES_COM_SSC_PER2, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208LL,
      v25[14]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_PER2, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208LL,
        v25[14]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "edp_config_vco_rate_4nm",
      265,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208,
      v25[14],
      -1059143953,
      v35,
      v142);
    writel_relaxed_5((unsigned int)v25[14], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 208LL);
    v36 = get_ipc_log_context();
    ipc_log_string(
      v36,
      "[d][%-4d]QSERDES_COM_SSC_STEP_SIZE1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96LL,
      v25[11]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_STEP_SIZE1_MODE0, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96LL,
        v25[11]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "edp_config_vco_rate_4nm",
      267,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96,
      v25[11],
      -1059143953,
      v37,
      v143);
    writel_relaxed_5((unsigned int)v25[11], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 96LL);
    v38 = get_ipc_log_context();
    ipc_log_string(
      v38,
      "[d][%-4d]QSERDES_COM_SSC_STEP_SIZE2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100LL,
      v25[12]);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]QSERDES_COM_SSC_STEP_SIZE2_MODE0, addr=0x%llx, val=0x%x\n",
        *v6,
        *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100LL,
        v25[12]);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "edp_config_vco_rate_4nm",
      269,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100,
      v25[12],
      -1059143953,
      v39,
      v144);
    writel_relaxed_5((unsigned int)v25[12], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 100LL);
  }
  v40 = get_ipc_log_context();
  ipc_log_string(
    v40,
    "[d][%-4d]QSERDES_COM_SVS_MODE_CLK_SEL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380LL,
    1);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_SVS_MODE_CLK_SEL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380LL,
      1);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    272,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380,
    1,
    -1059143953,
    v41,
    v139);
  writel_relaxed_5(1, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 380LL);
  v42 = get_ipc_log_context();
  ipc_log_string(
    v42,
    "[d][%-4d]QSERDES_COM_SYSCLK_EN_SEL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272LL,
    11);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_SYSCLK_EN_SEL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272LL,
      11);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    273,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272,
    11,
    -1059143953,
    v43,
    v145);
  writel_relaxed_5(11, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 272LL);
  v44 = get_ipc_log_context();
  ipc_log_string(
    v44,
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
    "edp_config_vco_rate_4nm",
    274,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 228,
    2,
    -1059143953,
    v45,
    v146);
  writel_relaxed_5(2, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 228LL);
  v46 = get_ipc_log_context();
  ipc_log_string(
    v46,
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
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    275,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 224,
    12,
    -1059143953,
    v47,
    v147);
  writel_relaxed_5(12, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 224LL);
  v48 = get_ipc_log_context();
  ipc_log_string(
    v48,
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
    "edp_config_vco_rate_4nm",
    276,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 232,
    6,
    -1059143953,
    v49,
    v148);
  writel_relaxed_5(6, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 232LL);
  v50 = get_ipc_log_context();
  ipc_log_string(
    v50,
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
    "edp_config_vco_rate_4nm",
    277,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 356,
    48,
    -1059143953,
    v51,
    v149);
  writel_relaxed_5(48, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 356LL);
  v52 = get_ipc_log_context();
  ipc_log_string(
    v52,
    "[d][%-4d]QSERDES_COM_HSCLK_SEL_1, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60LL,
    *v25);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_HSCLK_SEL_1, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60LL,
      *v25);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    279,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60,
    *v25,
    -1059143953,
    v53,
    v150);
  writel_relaxed_5((unsigned int)*v25, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 60LL);
  v54 = get_ipc_log_context();
  ipc_log_string(
    v54,
    "[d][%-4d]QSERDES_COM_PLL_IVCO, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244LL,
    v25[17]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_PLL_IVCO, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244LL,
      v25[17]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    280,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244,
    v25[17],
    -1059143953,
    v55,
    v151);
  writel_relaxed_5((unsigned int)v25[17], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 244LL);
  v56 = get_ipc_log_context();
  ipc_log_string(
    v56,
    "[d][%-4d]QSERDES_COM_LOCK_CMP_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288LL,
    v25[3]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_LOCK_CMP_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288LL,
      v25[3]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    282,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288,
    v25[3],
    -1059143953,
    v57,
    v152);
  writel_relaxed_5((unsigned int)v25[3], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 288LL);
  v58 = get_ipc_log_context();
  ipc_log_string(
    v58,
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
    "edp_config_vco_rate_4nm",
    283,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 120,
    54,
    -1059143953,
    v59,
    v153);
  writel_relaxed_5(54, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 120LL);
  v60 = get_ipc_log_context();
  ipc_log_string(
    v60,
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
    "edp_config_vco_rate_4nm",
    284,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 116,
    22,
    -1059143953,
    v61,
    v154);
  writel_relaxed_5(22, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 116LL);
  v62 = get_ipc_log_context();
  ipc_log_string(
    v62,
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
    "edp_config_vco_rate_4nm",
    285,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 112,
    6,
    -1059143953,
    v63,
    v155);
  writel_relaxed_5(6, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 112LL);
  v64 = get_ipc_log_context();
  ipc_log_string(
    v64,
    "[d][%-4d]QSERDES_COM_DEC_START_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136LL,
    v25[5]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DEC_START_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136LL,
      v25[5]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    287,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136,
    v25[5],
    -1059143953,
    v65,
    v156);
  writel_relaxed_5((unsigned int)v25[5], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 136LL);
  v66 = get_ipc_log_context();
  ipc_log_string(
    v66,
    "[d][%-4d]QSERDES_COM_DIV_FRAC_START1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144LL,
    v25[6]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DIV_FRAC_START1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144LL,
      v25[6]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    289,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144,
    v25[6],
    -1059143953,
    v67,
    v157);
  writel_relaxed_5((unsigned int)v25[6], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 144LL);
  v68 = get_ipc_log_context();
  ipc_log_string(
    v68,
    "[d][%-4d]QSERDES_COM_DIV_FRAC_START2_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148LL,
    v25[7]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DIV_FRAC_START2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148LL,
      v25[7]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    291,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148,
    v25[7],
    -1059143953,
    v69,
    v158);
  writel_relaxed_5((unsigned int)v25[7], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 148LL);
  v70 = get_ipc_log_context();
  ipc_log_string(
    v70,
    "[d][%-4d]QSERDES_COM_DIV_FRAC_START3_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152LL,
    v25[8]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_DIV_FRAC_START3_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152LL,
      v25[8]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    293,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152,
    v25[8],
    -1059143953,
    v71,
    v159);
  writel_relaxed_5((unsigned int)v25[8], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 152LL);
  v72 = get_ipc_log_context();
  ipc_log_string(
    v72,
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
    "edp_config_vco_rate_4nm",
    295,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 372,
    18,
    -1059143953,
    v73,
    v160);
  writel_relaxed_5(18, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 372LL);
  v74 = get_ipc_log_context();
  ipc_log_string(
    v74,
    "[d][%-4d]QSERDES_COM_INTEGLOOP_GAIN0_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160LL,
    v25[1]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_INTEGLOOP_GAIN0_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160LL,
      v25[1]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    298,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160,
    v25[1],
    -1059143953,
    v75,
    v161);
  writel_relaxed_5((unsigned int)v25[1], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 160LL);
  v76 = get_ipc_log_context();
  ipc_log_string(
    v76,
    "[d][%-4d]QSERDES_COM_INTEGLOOP_GAIN1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164LL,
    v25[2]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_INTEGLOOP_GAIN1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164LL,
      v25[2]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    300,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164,
    v25[2],
    -1059143953,
    v77,
    v162);
  writel_relaxed_5((unsigned int)v25[2], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 164LL);
  v78 = get_ipc_log_context();
  ipc_log_string(
    v78,
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
    "edp_config_vco_rate_4nm",
    302,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 320,
    0,
    -1059143953,
    v79,
    v163);
  writel_relaxed_5(0, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 320LL);
  v80 = get_ipc_log_context();
  ipc_log_string(
    v80,
    "[d][%-4d]QSERDES_COM_LOCK_CMP1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128LL,
    v25[9]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_LOCK_CMP1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128LL,
      v25[9]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    304,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128,
    v25[9],
    -1059143953,
    v81,
    v164);
  writel_relaxed_5((unsigned int)v25[9], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 128LL);
  v82 = get_ipc_log_context();
  ipc_log_string(
    v82,
    "[d][%-4d]QSERDES_COM_LOCK_CMP2_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132LL,
    v25[10]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_LOCK_CMP2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132LL,
      v25[10]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    306,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132,
    v25[10],
    -1059143953,
    v83,
    v165);
  writel_relaxed_5((unsigned int)v25[10], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 132LL);
  __dsb(0xEu);
  v84 = get_ipc_log_context();
  ipc_log_string(
    v84,
    "[d][%-4d]QSERDES_COM_BG_TIMER, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188LL,
    v25[18]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_BG_TIMER, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188LL,
      v25[18]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    310,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188,
    v25[18],
    -1059143953,
    v85,
    v166);
  writel_relaxed_5((unsigned int)v25[18], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 188LL);
  v86 = get_ipc_log_context();
  ipc_log_string(
    v86,
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
    "edp_config_vco_rate_4nm",
    311,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 124,
    20,
    -1059143953,
    v87,
    v167);
  writel_relaxed_5(20, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 124LL);
  v88 = get_ipc_log_context();
  ipc_log_string(
    v88,
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
    "edp_config_vco_rate_4nm",
    312,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 316,
    0,
    -1059143953,
    v89,
    v168);
  writel_relaxed_5(0, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 316LL);
  v90 = get_ipc_log_context();
  ipc_log_string(
    v90,
    "[d][%-4d]QSERDES_COM_BIAS_EN_CLKBUFLR_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220LL,
    23);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_BIAS_EN_CLKBUFLR_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220LL,
      23);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    314,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220,
    23,
    -1059143953,
    v91,
    v169);
  writel_relaxed_5(23, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 220LL);
  v92 = get_ipc_log_context();
  ipc_log_string(
    v92,
    "[d][%-4d]QSERDES_COM_CORE_CLK_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368LL,
    v25[19]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CORE_CLK_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368LL,
      v25[19]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    315,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368,
    v25[19],
    -1059143953,
    v93,
    v170);
  writel_relaxed_5((unsigned int)v25[19], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 368LL);
  __dsb(0xEu);
  v94 = get_ipc_log_context();
  ipc_log_string(
    v94,
    "[d][%-4d]QSERDES_COM_CODE1_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88LL,
    v25[15]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CODE1_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88LL,
      v25[15]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    320,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88,
    v25[15],
    -1059143953,
    v95,
    v171);
  writel_relaxed_5((unsigned int)v25[15], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 88LL);
  v96 = get_ipc_log_context();
  ipc_log_string(
    v96,
    "[d][%-4d]QSERDES_COM_CODE2_MODE0, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92LL,
    v25[16]);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_CODE2_MODE0, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92LL,
      v25[16]);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    323,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92,
    v25[16],
    -1059143953,
    v97,
    v172);
  writel_relaxed_5((unsigned int)v25[16], *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 92LL);
  v98 = get_ipc_log_context();
  ipc_log_string(
    v98,
    "[d][%-4d]DP_PHY_TX0_TX1_LANE_CTL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 124LL,
    5);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_TX0_TX1_LANE_CTL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 124LL,
      5);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    326,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 124,
    5,
    -1059143953,
    v99,
    v173);
  writel_relaxed_5(5, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 124LL);
  v100 = get_ipc_log_context();
  ipc_log_string(
    v100,
    "[d][%-4d]DP_PHY_TX2_TX3_LANE_CTL, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 160LL,
    5);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_TX2_TX3_LANE_CTL, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 160LL,
      5);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    327,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 160,
    5,
    -1059143953,
    v101,
    v174);
  writel_relaxed_5(5, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 160LL);
  v102 = get_ipc_log_context();
  ipc_log_string(
    v102,
    "[d][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84LL,
    3);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84LL,
      3);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    330,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84,
    3,
    -1059143953,
    v103,
    v175);
  writel_relaxed_5(3, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84LL);
  v104 = get_ipc_log_context();
  ipc_log_string(
    v104,
    "[d][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL),
    15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL),
      15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    331,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL),
    15,
    -1059143953,
    v105,
    v176);
  writel_relaxed_5(15, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL));
  v106 = get_ipc_log_context();
  ipc_log_string(
    v106,
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
    "edp_config_vco_rate_4nm",
    332,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 28,
    3,
    -1059143953,
    v107,
    v177);
  writel_relaxed_5(3, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 28LL);
  v108 = get_ipc_log_context();
  ipc_log_string(
    v108,
    "[d][%-4d]TXn_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 120LL,
    1);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 120LL,
      1);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    333,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 120,
    1,
    -1059143953,
    v109,
    v178);
  writel_relaxed_5(1, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 120LL);
  v110 = get_ipc_log_context();
  ipc_log_string(
    v110,
    "[d][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 40LL,
    4);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 40LL,
      4);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    334,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 40,
    4,
    -1059143953,
    v111,
    v179);
  writel_relaxed_5(4, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 40LL);
  v112 = get_ipc_log_context();
  ipc_log_string(
    v112,
    "[d][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84LL,
    3);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84LL,
      3);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    337,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84,
    3,
    -1059143953,
    v113,
    v180);
  writel_relaxed_5(3, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84LL);
  v114 = get_ipc_log_context();
  ipc_log_string(
    v114,
    "[d][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL),
    15);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_CLKBUF_ENABLE, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL),
      15);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    338,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL),
    15,
    -1059143953,
    v115,
    v181);
  writel_relaxed_5(15, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL));
  v116 = get_ipc_log_context();
  ipc_log_string(
    v116,
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
    "edp_config_vco_rate_4nm",
    339,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 28,
    3,
    -1059143953,
    v117,
    v182);
  writel_relaxed_5(3, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 28LL);
  v118 = get_ipc_log_context();
  ipc_log_string(
    v118,
    "[d][%-4d]TXn_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 120LL,
    1);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TRAN_DRVR_EMP_EN, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 120LL,
      1);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    340,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 120,
    1,
    -1059143953,
    v119,
    v183);
  writel_relaxed_5(1, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 120LL);
  v120 = get_ipc_log_context();
  ipc_log_string(
    v120,
    "[d][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 40LL,
    4);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_BAND, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 40LL,
      4);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_config_vco_rate_4nm",
    341,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 40,
    4,
    -1059143953,
    v121,
    v184);
  writel_relaxed_5(4, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 40LL);
  __dsb(0xEu);
  if ( (readl_relaxed_5(*(_QWORD *)(*(_QWORD *)(a1 + 376) + 24LL)) & 0x80000000) == 0 )
    return 4294967274LL;
  v123 = readl_relaxed_5(*(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 116LL) & 0xFFFFFFFC;
  if ( a2 > 5399999 )
  {
    if ( a2 == 5400000 )
    {
      v123 |= 2u;
      v124 = 4;
    }
    else
    {
      v124 = 6;
    }
  }
  else
  {
    v123 |= 1u;
    v124 = 2;
  }
  v127 = get_ipc_log_context();
  ipc_log_string(
    v127,
    "[d][%-4d]EDP_PHY_VCO_DIV, addr=0x%llx, val=0x%x\n",
    *v6,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 116LL,
    v123);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]EDP_PHY_VCO_DIV, addr=0x%llx, val=0x%x\n",
      *v6,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 116LL,
      v123);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "set_vco_div",
    168,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 116,
    v123,
    -1059143953,
    v128,
    v185);
  writel_relaxed_5(v123, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 116LL);
  __dsb(0xEu);
  clk_set_rate(***(_QWORD ***)(a1 + 384), *(_QWORD *)(a1 + 8) / 0xAuLL);
  clk_set_rate(*(_QWORD *)(**(_QWORD **)(a1 + 384) + 8LL), *(_QWORD *)(a1 + 8) / (unsigned __int64)v124);
  v129 = get_ipc_log_context();
  ipc_log_string(
    v129,
    "[d][%-4d]val=%#x div=%x link_clk rate=%lu vco_div_clk rate=%lu\n",
    *v6,
    v123,
    v124,
    *(_QWORD *)(a1 + 8) / 0xAuLL,
    *(_QWORD *)(a1 + 8) / (unsigned __int64)v124);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]val=%#x div=%x link_clk rate=%lu vco_div_clk rate=%lu\n",
      *v6,
      v123,
      v124,
      *(_QWORD *)(a1 + 8) / 0xAuLL,
      *(_QWORD *)(a1 + 8) / (unsigned __int64)v124);
  return 0;
}
