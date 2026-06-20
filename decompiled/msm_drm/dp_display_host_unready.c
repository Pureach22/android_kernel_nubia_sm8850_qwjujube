__int64 __fastcall dp_display_host_unready(__int64 a1)
{
  unsigned int v1; // w20
  __int64 v3; // x21
  int v4; // w22
  const char *v5; // x0
  int v6; // w6
  int v7; // w7
  int v8; // w4
  int v9; // w0
  int v10; // w2
  __int64 v11; // x21
  int v12; // w22
  const char *v13; // x0
  unsigned int v15; // w20
  __int64 v16; // x8
  __int64 v17; // x21
  unsigned __int64 StatusReg; // x23
  int v19; // w22
  const char *v20; // x0
  int v21; // w6
  int v22; // w7
  unsigned int v23; // w21
  int v24; // w20
  const char *v25; // x0
  void (*v26)(void); // x8
  __int64 v27; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *(_DWORD *)(a1 + 12);
  if ( (v1 & 2) == 0 )
  {
    if ( !g_dp_display || (v3 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v3 = 0;
    v4 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    v5 = (const char *)dp_display_state_name(v1);
    ipc_log_string(v3, "[w][%-4d]%s: state (0x%x): %s\n", v4, "[not initialized]", v1, v5);
    dp_display_state_name(*(unsigned int *)(a1 + 12));
    printk(&unk_245441, "dp_display_host_unready");
    v8 = *(_DWORD *)(a1 + 12);
    v9 = sde_dbg_base_evtlog;
    v10 = 1238;
    return sde_evtlog_log(v9, "dp_display_host_unready", v10, 8, v8, -1059143953, v6, v7, vars0);
  }
  if ( (v1 & 4) == 0 )
  {
    if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v11 = 0;
    v12 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    v13 = (const char *)dp_display_state_name(v1);
    ipc_log_string(v11, "[e][%-4d]%s: state (0x%x): %s\n", v12, "[not ready]", v1, v13);
    dp_display_state_name(*(unsigned int *)(a1 + 12));
    printk(&unk_24548C, "dp_display_host_unready");
    v8 = *(_DWORD *)(a1 + 12);
    v9 = sde_dbg_base_evtlog;
    v10 = 1243;
    return sde_evtlog_log(v9, "dp_display_host_unready", v10, 8, v8, -1059143953, v6, v7, vars0);
  }
  v15 = v1 & 0xFFFFFFFB;
  v16 = g_dp_display;
  *(_DWORD *)(a1 + 12) = v15;
  if ( !v16 || (v17 = *(_QWORD *)(v16 + 56)) == 0 )
    v17 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v19 = *(_DWORD *)(StatusReg + 1800);
  v20 = (const char *)dp_display_state_name(v15);
  ipc_log_string(v17, "[d][%-4d]%s: state (0x%x): %s\n", v19, "remove DP_STATE_READY", v15, v20);
  if ( (_drm_debug & 4) != 0 )
  {
    v23 = *(_DWORD *)(a1 + 12);
    v24 = *(_DWORD *)(StatusReg + 1800);
    v25 = (const char *)dp_display_state_name(v23);
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v24, "remove DP_STATE_READY", v23, v25);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_host_unready",
    1247,
    8,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    v21,
    v22,
    vars0);
  v26 = *(void (**)(void))(*(_QWORD *)(a1 + 160) + 64LL);
  if ( *((_DWORD *)v26 - 1) != 268977780 )
    __break(0x8228u);
  v26();
  if ( !g_dp_display || (v27 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v27 = 0;
  ipc_log_string(v27, "[i][%-4d][OK]\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    return printk(&unk_25D9A9, *(unsigned int *)(StatusReg + 1800));
  else
    return printk(&unk_26F5AF, "dp_display_host_unready");
}
