__int64 __fastcall dp_display_mmrm_callback(__int64 a1)
{
  __int64 v2; // x20
  int *v3; // x22
  unsigned int v4; // w20
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x23
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v2 = **(_QWORD **)(a1 + 24);
  v3 = (int *)(v2 - 1156);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_mmrm_callback",
    2228,
    8,
    4369,
    *(_DWORD *)(v2 - 1156),
    *(_DWORD *)a1,
    -1059143953,
    vars0);
  if ( *(_DWORD *)a1 != 1 )
  {
    v4 = 0;
LABEL_10:
    v6 = g_dp_display;
    if ( g_dp_display )
      goto LABEL_11;
    goto LABEL_14;
  }
  if ( (*v3 & 0x140) == 0x40 )
  {
    v4 = dp_display_handle_disconnect(v2 - 1168);
    if ( v4 )
    {
      if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v5 = 0;
      ipc_log_string(
        v5,
        "[e][%-4d]mmrm callback error reducing clk, ret:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        v4);
      printk(&unk_21C6DC, "dp_display_mmrm_callback");
      v6 = g_dp_display;
      if ( !g_dp_display )
        goto LABEL_14;
LABEL_11:
      v7 = *(_QWORD *)(v6 + 56);
      if ( v7 )
        goto LABEL_15;
      goto LABEL_14;
    }
    goto LABEL_10;
  }
  v4 = 0;
  v6 = g_dp_display;
  if ( g_dp_display )
    goto LABEL_11;
LABEL_14:
  v7 = 0;
LABEL_15:
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v7, "[d][%-4d]mmrm callback handled, state: 0x%x rc:%d\n", *(_DWORD *)(StatusReg + 1800), *v3, v4);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mmrm callback handled, state: 0x%x rc:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *v3,
      v4);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_mmrm_callback",
    2238,
    8,
    8738,
    *v3,
    *(_DWORD *)a1,
    -1059143953,
    vars0a);
  return v4;
}
