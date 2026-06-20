__int64 __fastcall edp_pll_prepare(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x8
  unsigned __int64 StatusReg; // x25
  int v5; // w7
  __int64 v6; // x0
  int v7; // w7
  __int64 v8; // x0
  int v9; // w7
  __int64 v10; // x0
  int v11; // w7
  __int64 v12; // x0
  int v13; // w7
  __int64 v14; // x0
  int v15; // w7
  unsigned int v16; // w20
  unsigned int v17; // w21
  unsigned int v18; // w24
  unsigned int v19; // w23
  unsigned int v20; // w22
  __int64 v21; // x0
  int v22; // w7
  __int64 v23; // x0
  int v24; // w7
  __int64 v25; // x0
  int v26; // w7
  __int64 v27; // x0
  int v28; // w7
  __int64 v29; // x0
  int v30; // w7
  __int64 v31; // x0
  int v32; // w7
  __int64 v33; // x0
  int v34; // w7
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
  __int64 v61; // x0
  __int64 ipc_log_context; // x0
  char v63; // [xsp+0h] [xbp+0h]
  char v64; // [xsp+0h] [xbp+0h]
  char v65; // [xsp+0h] [xbp+0h]
  char v66; // [xsp+0h] [xbp+0h]
  char v67; // [xsp+0h] [xbp+0h]
  char v68; // [xsp+0h] [xbp+0h]
  char v69; // [xsp+0h] [xbp+0h]
  char v70; // [xsp+0h] [xbp+0h]
  char v71; // [xsp+0h] [xbp+0h]
  char v72; // [xsp+0h] [xbp+0h]
  char v73; // [xsp+0h] [xbp+0h]
  char v74; // [xsp+0h] [xbp+0h]
  char v75; // [xsp+0h] [xbp+0h]
  char v76; // [xsp+0h] [xbp+0h]
  char v77; // [xsp+0h] [xbp+0h]
  char v78; // [xsp+0h] [xbp+0h]
  char v79; // [xsp+0h] [xbp+0h]
  char v80; // [xsp+0h] [xbp+0h]
  char v81; // [xsp+0h] [xbp+0h]
  char v82; // [xsp+0h] [xbp+0h]
  char v83; // [xsp+0h] [xbp+0h]
  char v84; // [xsp+0h] [xbp+0h]
  char v85; // [xsp+0h] [xbp+0h]
  char v86; // [xsp+0h] [xbp+0h]
  char v87; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26189D, "edp_pll_prepare");
    return 4294967274LL;
  }
  **(_DWORD **)(a1 + 336) &= ~0x2000u;
  v2 = get_ipc_log_context();
  v3 = *(_QWORD *)(a1 + 344);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v2,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(v3 + 24) + 16LL,
    1);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
      1);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    424,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    1,
    -1059143953,
    v5,
    v63);
  writel_relaxed_4(1, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v6 = get_ipc_log_context();
  ipc_log_string(
    v6,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
    5);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
      5);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    425,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    5,
    -1059143953,
    v7,
    v64);
  writel_relaxed_4(5, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v8 = get_ipc_log_context();
  ipc_log_string(
    v8,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
    1);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
      1);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    426,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    1,
    -1059143953,
    v9,
    v65);
  writel_relaxed_4(1, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v10 = get_ipc_log_context();
  ipc_log_string(
    v10,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
    9);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
      9);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    427,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    9,
    -1059143953,
    v11,
    v66);
  writel_relaxed_4(9, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v12 = get_ipc_log_context();
  ipc_log_string(
    v12,
    "[d][%-4d]QSERDES_COM_RESETSM_CNTRL, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 156LL,
    32);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]QSERDES_COM_RESETSM_CNTRL, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 156LL,
      32);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    428,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 156,
    32,
    -1059143953,
    v13,
    v67);
  writel_relaxed_4(32, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 156LL);
  __dsb(0xEu);
  if ( (edp_5nm_pll_get_status(a1, 0) & 1) == 0
    || (edp_5nm_pll_get_status(a1, 1) & 1) == 0
    || (edp_5nm_pll_get_status(a1, 2) & 1) == 0 )
  {
    goto LABEL_67;
  }
  v14 = get_ipc_log_context();
  ipc_log_string(
    v14,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
    25);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
      25);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    446,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    25,
    -1059143953,
    v15,
    v68);
  writel_relaxed_4(25, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  __dsb(0xEu);
  v16 = *(unsigned __int8 *)(a1 + 56);
  if ( v16 == 1 )
  {
    v17 = 0;
    v18 = 6;
    v19 = 7;
    v20 = 1;
  }
  else
  {
    if ( v16 == 2 )
    {
      v17 = 0;
      v18 = 4;
      v19 = 7;
      v16 = 3;
    }
    else
    {
      v17 = 3;
      v19 = 4;
      v16 = 15;
      v18 = 4;
    }
    v20 = 3;
  }
  v21 = get_ipc_log_context();
  ipc_log_string(
    v21,
    "[d][%-4d]TXn_HIGHZ_DRVR_EN, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 88LL,
    v18);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_HIGHZ_DRVR_EN, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 88LL,
      v18);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    470,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 88,
    v18,
    -1059143953,
    v22,
    v69);
  writel_relaxed_4(v18, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 88LL);
  v23 = get_ipc_log_context();
  ipc_log_string(
    v23,
    "[d][%-4d]TXn_TX_POL_INV, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 92LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_POL_INV, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 92LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    471,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 92,
    0,
    -1059143953,
    v24,
    v70);
  writel_relaxed_4(0, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 92LL);
  v25 = get_ipc_log_context();
  ipc_log_string(
    v25,
    "[d][%-4d]TXn_HIGHZ_DRVR_EN, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 88LL,
    v19);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_HIGHZ_DRVR_EN, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 88LL,
      v19);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    472,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 88,
    v19,
    -1059143953,
    v26,
    v71);
  writel_relaxed_4(v19, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 88LL);
  v27 = get_ipc_log_context();
  ipc_log_string(
    v27,
    "[d][%-4d]TXn_TX_POL_INV, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 92LL,
    0);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_POL_INV, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 92LL,
      0);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    473,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 92,
    0,
    -1059143953,
    v28,
    v72);
  writel_relaxed_4(0, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 92LL);
  v29 = get_ipc_log_context();
  ipc_log_string(
    v29,
    "[d][%-4d]TXn_TX_DRV_LVL_OFFSET, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 24LL,
    16);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_DRV_LVL_OFFSET, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 24LL,
      16);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    474,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 24,
    16,
    -1059143953,
    v30,
    v73);
  writel_relaxed_4(16, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 24LL);
  v31 = get_ipc_log_context();
  ipc_log_string(
    v31,
    "[d][%-4d]TXn_TX_DRV_LVL_OFFSET, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 24LL,
    16);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_DRV_LVL_OFFSET, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 24LL,
      16);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    475,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 24,
    16,
    -1059143953,
    v32,
    v74);
  writel_relaxed_4(16, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 24LL);
  v33 = get_ipc_log_context();
  ipc_log_string(
    v33,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_TX0, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 68LL,
    17);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_TX0, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 68LL,
      17);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    477,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 68,
    17,
    -1059143953,
    v34,
    v75);
  writel_relaxed_4(17, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 68LL);
  v35 = get_ipc_log_context();
  ipc_log_string(
    v35,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_TX1, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 72LL,
    17);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_TX1, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 72LL,
      17);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    479,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 72,
    17,
    -1059143953,
    v36,
    v76);
  writel_relaxed_4(17, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 72LL);
  v37 = get_ipc_log_context();
  ipc_log_string(
    v37,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_TX0, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 68LL,
    17);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_TX0, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 68LL,
      17);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    481,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 68,
    17,
    -1059143953,
    v38,
    v77);
  writel_relaxed_4(17, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 68LL);
  v39 = get_ipc_log_context();
  ipc_log_string(
    v39,
    "[d][%-4d]TXn_RES_CODE_LANE_OFFSET_TX1, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 72LL,
    17);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_RES_CODE_LANE_OFFSET_TX1, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 72LL,
      17);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    483,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 72,
    17,
    -1059143953,
    v40,
    v78);
  writel_relaxed_4(17, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 72LL);
  v41 = get_ipc_log_context();
  ipc_log_string(
    v41,
    "[d][%-4d]TXn_TX_EMP_POST1_LVL, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 4LL,
    16);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_EMP_POST1_LVL, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 4LL,
      16);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    485,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 4,
    16,
    -1059143953,
    v42,
    v79);
  writel_relaxed_4(16, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 4LL);
  v43 = get_ipc_log_context();
  ipc_log_string(
    v43,
    "[d][%-4d]TXn_TX_EMP_POST1_LVL, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 4LL,
    16);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_EMP_POST1_LVL, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 4LL,
      16);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    486,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 4,
    16,
    -1059143953,
    v44,
    v80);
  writel_relaxed_4(16, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 4LL);
  v45 = get_ipc_log_context();
  ipc_log_string(
    v45,
    "[d][%-4d]TXn_TX_DRV_LVL, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 20LL,
    31);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_DRV_LVL, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 20LL,
      31);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    487,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 20,
    31,
    -1059143953,
    v46,
    v81);
  writel_relaxed_4(31, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 20LL);
  v47 = get_ipc_log_context();
  ipc_log_string(
    v47,
    "[d][%-4d]TXn_TX_DRV_LVL, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 20LL,
    31);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TX_DRV_LVL, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 20LL,
      31);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    488,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 20,
    31,
    -1059143953,
    v48,
    v82);
  writel_relaxed_4(31, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 20LL);
  __dsb(0xEu);
  v49 = get_ipc_log_context();
  ipc_log_string(
    v49,
    "[d][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84LL,
    v20);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84LL,
      v20);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    494,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84,
    v20,
    -1059143953,
    v50,
    v83);
  writel_relaxed_4(v20, *(_QWORD *)(*(_QWORD *)(a1 + 360) + 24LL) + 84LL);
  v51 = get_ipc_log_context();
  ipc_log_string(
    v51,
    "[d][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84LL,
    v17);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]TXn_TRANSCEIVER_BIAS_EN, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84LL,
      v17);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    496,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84,
    v17,
    -1059143953,
    v52,
    v84);
  writel_relaxed_4(v17, *(_QWORD *)(*(_QWORD *)(a1 + 368) + 24LL) + 84LL);
  v53 = get_ipc_log_context();
  ipc_log_string(
    v53,
    "[d][%-4d]DP_PHY_CFG_1, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20LL,
    v16);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG_1, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20LL,
      v16);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    497,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20,
    v16,
    -1059143953,
    v54,
    v85);
  writel_relaxed_4(v16, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 20LL);
  if ( (edp_5nm_pll_get_status(a1, 3) & 1) == 0 )
    goto LABEL_67;
  v55 = get_ipc_log_context();
  ipc_log_string(
    v55,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
    24);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
      24);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    504,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    24,
    -1059143953,
    v56,
    v86);
  writel_relaxed_4(24, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  _const_udelay(429500);
  v57 = get_ipc_log_context();
  ipc_log_string(
    v57,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
    25);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL,
      25);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "edp_pll_enable_5nm",
    507,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    25,
    -1059143953,
    v58,
    v87);
  writel_relaxed_4(25, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  __dsb(0xEu);
  if ( (edp_5nm_pll_get_status(a1, 4) & 1) == 0 || (edp_5nm_pll_get_status(a1, 3) & 1) == 0 )
  {
LABEL_67:
    v61 = get_ipc_log_context();
    ipc_log_string(
      v61,
      "[e][%-4d]ndx=%d failed to enable dp pll\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 16));
    printk(&unk_21CC58, "edp_pll_prepare");
    return 4294967274LL;
  }
  **(_DWORD **)(a1 + 336) |= 0x2000u;
  v59 = get_ipc_log_context();
  ipc_log_string(v59, "[d][%-4d]PLL is locked\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]PLL is locked\n", *(_DWORD *)(StatusReg + 1800));
  return 0;
}
