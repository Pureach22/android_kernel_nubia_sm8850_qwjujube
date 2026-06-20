__int64 __fastcall dp_display_host_init(__int64 a1)
{
  int v1; // w20
  __int64 v3; // x21
  unsigned __int64 StatusReg; // x23
  int v5; // w22
  const char *v6; // x0
  int v7; // w6
  int v8; // w7
  int v9; // w21
  int v10; // w20
  const char *v11; // x0
  __int64 (*v13)(void); // x8
  unsigned int v14; // w0
  void (*v15)(void); // x8
  __int64 (**v16)(void); // x0
  __int64 (*v17)(void); // x8
  unsigned int v18; // w0
  __int64 v19; // x8
  int v20; // w20
  __int64 v21; // x21
  unsigned __int64 v22; // x23
  int v23; // w22
  const char *v24; // x0
  int v25; // w6
  int v26; // w7
  int v27; // w21
  int v28; // w20
  const char *v29; // x0
  __int64 v30; // x0
  unsigned int v31; // w21
  __int64 v32; // x0
  int v33; // w7
  unsigned int v34; // w21
  __int64 v35; // x0
  int v36; // w7
  void (*v37)(void); // x8
  void (*v38)(void); // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v1 = *(_DWORD *)(a1 + 12);
  if ( (v1 & 2) != 0 )
  {
    if ( !g_dp_display || (v3 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v3 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    v5 = *(_DWORD *)(StatusReg + 1800);
    v6 = dp_display_state_name(v1);
    ipc_log_string(v3, "[d][%-4d]%s: state (0x%x): %s\n", v5, "[already initialized]", v1, v6);
    if ( (_drm_debug & 4) != 0 )
    {
      v9 = *(_DWORD *)(a1 + 12);
      v10 = *(_DWORD *)(StatusReg + 1800);
      v11 = dp_display_state_name(v9);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v10, "[already initialized]", v9, v11);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_host_init",
      1125,
      8,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v7,
      v8,
      vars0);
    return 0;
  }
  v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 144) + 32LL);
  if ( *((_DWORD *)v13 - 1) != -1916719280 )
    __break(0x8228u);
  v14 = v13();
  if ( v14 )
  {
    v31 = v14;
    if ( !g_dp_display || (v32 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v32 = 0;
    ipc_log_string(v32, "[w][%-4d]Power init failed.\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_230E94, "dp_display_host_init");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_host_init",
      1137,
      8,
      13107,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v33,
      vars0);
    return v31;
  }
  else
  {
    v15 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 32LL);
    if ( *((_DWORD *)v15 - 1) != -83176264 )
      __break(0x8228u);
    v15();
    v16 = *(__int64 (***)(void))(a1 + 184);
    v17 = *v16;
    if ( *((_DWORD *)*v16 - 1) != 280655681 )
      __break(0x8228u);
    v18 = v17();
    if ( !v18 )
    {
      enable_irq(*(unsigned int *)(a1 + 8));
      dp_display_abort_hdcp(a1, 0);
      v19 = g_dp_display;
      v20 = *(_DWORD *)(a1 + 12) | 2;
      *(_DWORD *)(a1 + 12) = v20;
      if ( !v19 || (v21 = *(_QWORD *)(v19 + 56)) == 0 )
        v21 = 0;
      v22 = _ReadStatusReg(SP_EL0);
      v23 = *(_DWORD *)(v22 + 1800);
      v24 = dp_display_state_name(v20);
      ipc_log_string(v21, "[d][%-4d]%s: state (0x%x): %s\n", v23, "add DP_STATE_INITIALIZED", v20, v24);
      if ( (_drm_debug & 4) != 0 )
      {
        v27 = *(_DWORD *)(a1 + 12);
        v28 = *(_DWORD *)(v22 + 1800);
        v29 = dp_display_state_name(v27);
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v28, "add DP_STATE_INITIALIZED", v27, v29);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_host_init",
        1152,
        8,
        *(_DWORD *)(a1 + 12),
        -1059143953,
        v25,
        v26,
        vars0);
      if ( !g_dp_display || (v30 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v30 = 0;
      ipc_log_string(v30, "[i][%-4d][OK]\n", *(_DWORD *)(v22 + 1800));
      if ( (_drm_debug & 4) != 0 )
        printk(&unk_25D9A9, *(unsigned int *)(v22 + 1800));
      else
        printk(&unk_26F5AF, "dp_display_host_init");
      return 0;
    }
    v34 = v18;
    if ( !g_dp_display || (v35 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v35 = 0;
    ipc_log_string(v35, "[w][%-4d]Ctrl init Failed.\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_23E83F, "dp_display_host_init");
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_host_init",
      1145,
      8,
      17476,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v36,
      vars0);
    v37 = *(void (**)(void))(*(_QWORD *)(a1 + 128) + 40LL);
    if ( *((_DWORD *)v37 - 1) != -83176264 )
      __break(0x8228u);
    v37();
    v38 = *(void (**)(void))(*(_QWORD *)(a1 + 144) + 40LL);
    if ( *((_DWORD *)v38 - 1) != 139933102 )
      __break(0x8228u);
    v38();
    return v34;
  }
}
