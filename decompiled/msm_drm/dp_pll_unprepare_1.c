__int64 __fastcall dp_pll_unprepare_1(__int64 a1)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  unsigned __int64 StatusReg; // x21
  int v7; // w7
  __int64 ipc_log_context; // x0
  char v10; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_211A0D, "dp_pll_unprepare");
    return (unsigned int)-22;
  }
  if ( *(_DWORD *)a1 >= 7u && *(_QWORD *)(a1 + 8) == 8100000 )
  {
    v2 = dp_regulator_enable_3nm(*(_QWORD *)(a1 + 320), 0);
    if ( (v2 & 0x80000000) != 0 )
    {
      v3 = get_ipc_log_context();
      ipc_log_string(v3, "[e][%-4d]disable pll power failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_24BEE9, "dp_pll_unprepare");
      return v2;
    }
  }
  else
  {
    v2 = 0;
  }
  v4 = get_ipc_log_context();
  v5 = *(_QWORD *)(a1 + 344);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v4,
    "[d][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_QWORD *)(v5 + 24) + 24LL,
    2);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL,
      2);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_pll_disable_3nm",
    491,
    4,
    *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24,
    2,
    -1059143953,
    v7,
    v10);
  writel_relaxed_3(2, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 24LL);
  __dsb(0xEu);
  *(_QWORD *)(a1 + 8) = 0;
  return v2;
}
