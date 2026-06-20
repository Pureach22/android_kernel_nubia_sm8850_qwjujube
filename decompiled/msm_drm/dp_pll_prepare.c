__int64 __fastcall dp_pll_prepare(__int64 a1)
{
  unsigned int v2; // w0
  __int64 v3; // x0
  __int64 v4; // x8
  unsigned __int64 StatusReg; // x20
  int v6; // w7
  __int64 v7; // x0
  int v8; // w7
  __int64 v9; // x0
  int v10; // w7
  __int64 v11; // x0
  int v12; // w7
  __int64 v13; // x0
  int v14; // w7
  __int64 v15; // x0
  int v16; // w7
  __int64 v17; // x0
  __int64 v19; // x0
  __int64 ipc_log_context; // x0
  unsigned int v21; // w19
  __int64 v22; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]
  char vars0b; // [xsp+0h] [xbp+0h]
  char vars0c; // [xsp+0h] [xbp+0h]
  char vars0d; // [xsp+0h] [xbp+0h]
  char vars0e; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameters\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_26189D, "dp_pll_prepare");
    return 4294967274LL;
  }
  if ( *(_DWORD *)a1 == 1 && *(_QWORD *)(a1 + 8) == 8100000 )
  {
    v2 = dp_regulator_enable_5nm(*(_QWORD *)(a1 + 320), 1);
    if ( (v2 & 0x80000000) != 0 )
    {
      v21 = v2;
      v22 = get_ipc_log_context();
      ipc_log_string(v22, "[e][%-4d]enable pll power failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_2489D2, "dp_pll_prepare");
      return v21;
    }
  }
  **(_DWORD **)(a1 + 336) &= ~0x2000u;
  v3 = get_ipc_log_context();
  v4 = *(_QWORD *)(a1 + 344);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v3,
    "[d][%-4d]DP_PHY_CFG, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(v4 + 24) + 16LL,
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
    "dp_pll_enable_5nm",
    451,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    1,
    -1059143953,
    v6,
    vars0);
  writel_relaxed_1(1, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v7 = get_ipc_log_context();
  ipc_log_string(
    v7,
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
    "dp_pll_enable_5nm",
    452,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    5,
    -1059143953,
    v8,
    vars0a);
  writel_relaxed_1(5, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v9 = get_ipc_log_context();
  ipc_log_string(
    v9,
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
    "dp_pll_enable_5nm",
    453,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    1,
    -1059143953,
    v10,
    vars0b);
  writel_relaxed_1(1, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v11 = get_ipc_log_context();
  ipc_log_string(
    v11,
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
    "dp_pll_enable_5nm",
    454,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    9,
    -1059143953,
    v12,
    vars0c);
  writel_relaxed_1(9, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  v13 = get_ipc_log_context();
  ipc_log_string(
    v13,
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
    "dp_pll_enable_5nm",
    455,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 156,
    32,
    -1059143953,
    v14,
    vars0d);
  writel_relaxed_1(32, *(_QWORD *)(*(_QWORD *)(a1 + 352) + 24LL) + 156LL);
  __dsb(0xEu);
  if ( (dp_5nm_pll_get_status(a1, 0) & 1) == 0
    || (dp_5nm_pll_get_status(a1, 1) & 1) == 0
    || (dp_5nm_pll_get_status(a1, 2) & 1) == 0 )
  {
    goto LABEL_25;
  }
  v15 = get_ipc_log_context();
  ipc_log_string(
    v15,
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
    "dp_pll_enable_5nm",
    473,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16,
    25,
    -1059143953,
    v16,
    vars0e);
  writel_relaxed_1(25, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 16LL);
  __dsb(0xEu);
  if ( (dp_5nm_pll_get_status(a1, 4) & 1) == 0 || (dp_5nm_pll_get_status(a1, 3) & 1) == 0 )
  {
LABEL_25:
    v19 = get_ipc_log_context();
    ipc_log_string(
      v19,
      "[e][%-4d]ndx=%d failed to enable dp pll\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 16));
    printk(&unk_21CC58, "dp_pll_prepare");
    return 4294967274LL;
  }
  **(_DWORD **)(a1 + 336) |= 0x2000u;
  v17 = get_ipc_log_context();
  ipc_log_string(v17, "[d][%-4d]PLL is locked\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]PLL is locked\n", *(_DWORD *)(StatusReg + 1800));
  return 0;
}
