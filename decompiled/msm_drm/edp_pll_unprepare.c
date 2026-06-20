__int64 __fastcall edp_pll_unprepare(__int64 a1)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  int v4; // w2
  int v5; // w7
  __int64 result; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(_DWORD *)(StatusReg + 1800);
  if ( a1 )
  {
    ipc_log_string(
      ipc_log_context,
      "[d][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
      v4,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL,
      2);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]DP_PHY_PD_CTL, addr=0x%llx, val=0x%x\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL,
        2);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "edp_pll_disable_5nm",
      531,
      4,
      *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28,
      2,
      -1059143953,
      v5,
      vars0);
    writel_relaxed_4(2, *(_QWORD *)(*(_QWORD *)(a1 + 344) + 24LL) + 28LL);
    __dsb(0xEu);
    result = 0;
    *(_QWORD *)(a1 + 8) = 0;
  }
  else
  {
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input parameter\n", v4);
    printk(&unk_211A0D, "edp_pll_unprepare");
    return 4294967274LL;
  }
  return result;
}
