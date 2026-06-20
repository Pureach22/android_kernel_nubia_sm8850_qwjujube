__int64 __fastcall dp_regulator_enable_4nm(__int64 a1, char a2)
{
  unsigned int v2; // w8
  __int64 v3; // x0
  const char *v4; // x20
  unsigned int v5; // w19
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  int v8; // w2

  v2 = *(_DWORD *)(a1 + 304);
  v3 = *(_QWORD *)(a1 + 312);
  if ( (a2 & 1) != 0 )
    v4 = "enable";
  else
    v4 = "disable";
  v5 = msm_dss_enable_vreg(v3, v2, a2 & 1);
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v8 = *(_DWORD *)(StatusReg + 1800);
  if ( v5 )
  {
    ipc_log_string(ipc_log_context, "[e][%-4d]failed to '%s' vregs for %s\n", v8, v4, "DP_PLL_PM");
    printk(&unk_2480B0, "dp_regulator_enable_4nm");
  }
  else
  {
    ipc_log_string(ipc_log_context, "[d][%-4d]success: '%s' vregs for %s\n", v8, v4, "DP_PLL_PM");
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]success: '%s' vregs for %s\n",
        *(_DWORD *)(StatusReg + 1800),
        v4,
        "DP_PLL_PM");
  }
  return v5;
}
