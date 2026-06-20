__int64 __fastcall dp_display_host_ready(__int64 a1)
{
  int v1; // w20
  unsigned int v3; // w0
  __int64 v4; // x21
  unsigned __int64 StatusReg; // x23
  int v6; // w22
  const char *v7; // x0
  int v8; // w6
  int v9; // w7
  int v10; // w21
  int v11; // w20
  const char *v12; // x0
  void (*v14)(void); // x8
  void (*v15)(void); // x8
  void (*v16)(void); // x8
  void (*v17)(void); // x8
  unsigned int v18; // w23
  __int64 v19; // x8
  int v20; // w20
  __int64 v21; // x21
  unsigned __int64 v22; // x24
  int v23; // w22
  const char *v24; // x0
  int v25; // w6
  int v26; // w7
  int v27; // w21
  int v28; // w20
  const char *v29; // x0
  __int64 v30; // x0
  unsigned int v31; // w24
  __int64 v32; // x20
  int v33; // w22
  int v34; // w21
  const char *v35; // x0
  int v36; // w6
  int v37; // w7
  __int64 (*v38)(void); // x8
  unsigned int v39; // w0
  __int64 v40; // x8
  __int64 (__fastcall *v41)(_QWORD); // x9
  __int64 v42; // x0
  unsigned __int64 v43; // x20
  __int64 (*v44)(void); // x8
  unsigned int v45; // w0
  unsigned int v46; // w20
  __int64 v47; // x0
  unsigned int v48; // w22
  __int64 v49; // x0
  char v50; // [xsp+0h] [xbp+0h]

  v1 = *(_DWORD *)(a1 + 12);
  if ( (v1 & 2) != 0 )
    goto LABEL_4;
  v3 = dp_display_host_init(a1);
  if ( !v3 )
  {
    v1 = *(_DWORD *)(a1 + 12);
LABEL_4:
    if ( (v1 & 4) != 0 )
    {
      if ( !g_dp_display || (v4 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v4 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      v6 = *(_DWORD *)(StatusReg + 1800);
      v7 = dp_display_state_name(v1);
      ipc_log_string(v4, "[d][%-4d]%s: state (0x%x): %s\n", v6, "[already ready]", v1, v7);
      if ( (_drm_debug & 4) != 0 )
      {
        v10 = *(_DWORD *)(a1 + 12);
        v11 = *(_DWORD *)(StatusReg + 1800);
        v12 = dp_display_state_name(v10);
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v11, "[already ready]", v10, v12);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_host_ready",
        1203,
        8,
        *(_DWORD *)(a1 + 12),
        -1059143953,
        v8,
        v9,
        v50);
      return 0;
    }
    v14 = *(void (**)(void))(*(_QWORD *)(a1 + 160) + 80LL);
    if ( *((_DWORD *)v14 - 1) != 532007358 )
      __break(0x8228u);
    v14();
    v15 = *(void (**)(void))(*(_QWORD *)(a1 + 184) + 32LL);
    if ( *((_DWORD *)v15 - 1) != -1878159161 )
      __break(0x8228u);
    v15();
    v16 = *(void (**)(void))(*(_QWORD *)(a1 + 160) + 56LL);
    if ( *((_DWORD *)v16 - 1) != 1808488031 )
      __break(0x8228u);
    v16();
    if ( *(_BYTE *)(a1 + 1202) != 1 || (*(_BYTE *)(a1 + 1241) & 1) != 0 )
      goto LABEL_20;
    v38 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 144) + 112LL);
    if ( *((_DWORD *)v38 - 1) != -339360380 )
      __break(0x8228u);
    v39 = v38();
    if ( v39 )
    {
      v46 = v39;
      if ( !g_dp_display || (v47 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v47 = 0;
      ipc_log_string(v47, "[e][%-4d]Cannot turn edp panel power on", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_23434A, "dp_display_panel_ready");
      v18 = v46;
      goto LABEL_23;
    }
    v40 = *(_QWORD *)(a1 + 152);
    v41 = *(__int64 (__fastcall **)(_QWORD))(v40 + 1176);
    if ( *((_DWORD *)v41 - 1) != -248214294 )
      __break(0x8229u);
    if ( (v41(v40 + 1152) & 1) != 0 )
    {
LABEL_20:
      v17 = *(void (**)(void))(*(_QWORD *)(a1 + 176) + 1008LL);
      if ( *((_DWORD *)v17 - 1) != -362183607 )
        __break(0x8228u);
      v17();
      v18 = 0;
    }
    else
    {
      if ( !g_dp_display || (v42 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v42 = 0;
      v43 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v42, "[e][%-4d]EDP PANEL is not ready yet, powering off panel\n", *(_DWORD *)(v43 + 1800));
      printk(&unk_27C900, "dp_display_panel_ready");
      v44 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 144) + 112LL);
      if ( *((_DWORD *)v44 - 1) != -339360380 )
        __break(0x8228u);
      v45 = v44();
      if ( v45 )
      {
        v48 = v45;
        if ( !g_dp_display || (v49 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v49 = 0;
        ipc_log_string(v49, "[e][%-4d]Cannot turn edp panel power off", *(_DWORD *)(v43 + 1800));
        printk(&unk_21C851, "dp_display_panel_ready");
        v18 = v48;
      }
      else
      {
        v18 = -110;
      }
    }
LABEL_23:
    v19 = g_dp_display;
    v20 = *(_DWORD *)(a1 + 12) | 4;
    *(_DWORD *)(a1 + 12) = v20;
    if ( !v19 || (v21 = *(_QWORD *)(v19 + 56)) == 0 )
      v21 = 0;
    v22 = _ReadStatusReg(SP_EL0);
    v23 = *(_DWORD *)(v22 + 1800);
    v24 = dp_display_state_name(v20);
    ipc_log_string(v21, "[d][%-4d]%s: state (0x%x): %s\n", v23, "add DP_STATE_READY", v20, v24);
    if ( (_drm_debug & 4) != 0 )
    {
      v27 = *(_DWORD *)(a1 + 12);
      v28 = *(_DWORD *)(v22 + 1800);
      v29 = dp_display_state_name(v27);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v28, "add DP_STATE_READY", v27, v29);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_host_ready",
      1229,
      8,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v25,
      v26,
      v50);
    if ( !g_dp_display || (v30 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v30 = 0;
    ipc_log_string(v30, "[i][%-4d][OK]\n", *(_DWORD *)(v22 + 1800));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_25D9A9, *(unsigned int *)(v22 + 1800));
    else
      printk(&unk_26F5AF, "dp_display_host_ready");
    return v18;
  }
  v31 = v3;
  if ( !g_dp_display || (v32 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v32 = 0;
  v33 = *(_DWORD *)(a1 + 12);
  v34 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
  v35 = dp_display_state_name(v33);
  ipc_log_string(v32, "[e][%-4d]%s: state (0x%x): %s\n", v34, "[not initialized]", v33, v35);
  dp_display_state_name(*(_DWORD *)(a1 + 12));
  printk(&unk_24548C, "dp_display_host_ready");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_host_ready",
    1197,
    8,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    v36,
    v37,
    v50);
  return v31;
}
