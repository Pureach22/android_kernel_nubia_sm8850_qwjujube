__int64 __fastcall dp_display_unprepare(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int *v9; // x26
  __int64 v11; // x9
  unsigned int v12; // w21
  _DWORD *v13; // x8
  int v14; // w7
  void (*v16)(void); // x9
  void (*v17)(void); // x8
  int v18; // w21
  __int64 v19; // x22
  unsigned __int64 StatusReg; // x24
  int v21; // w23
  const char *v22; // x0
  int v23; // w6
  int v24; // w7
  int v25; // w22
  int v26; // w21
  const char *v27; // x0
  unsigned int (*v28)(void); // x8
  __int64 v29; // x0
  unsigned int v30; // w22
  __int64 v31; // x23
  unsigned __int64 v32; // x27
  int v33; // w24
  const char *v34; // x0
  int v35; // w6
  int v36; // w7
  int v37; // w23
  int v38; // w22
  const char *v39; // x0
  __int64 v40; // x0
  __int64 v41; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 )
  {
    v9 = (int *)(a1 - 1156);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_unprepare",
      3086,
      8,
      4369,
      *(_DWORD *)(a1 - 1156),
      -1059143953,
      a8,
      vars0);
    mutex_lock(a1 + 560);
    v11 = *(_QWORD *)(a1 - 1040);
    if ( *(_BYTE *)(v11 + 8) == 1
      && (*v9 & 8) != 0
      && ((*(_BYTE *)(*(_QWORD *)(a1 - 992) + 5LL) & 1) == 0 || *(_DWORD *)(*(_QWORD *)(a1 - 1000) + 8LL))
      && *(_BYTE *)(v11 + 10) == 1
      && ((*v9 & 0x80) != 0 || *(_BYTE *)(a1 + 664) != 1) )
    {
      v12 = 1;
      if ( *(_DWORD *)(a1 + 660) )
        goto LABEL_11;
      v16 = *(void (**)(void))(*(_QWORD *)(a1 - 1000) + 192LL);
      if ( *((_DWORD *)v16 - 1) != -187382708 )
        __break(0x8229u);
      v16();
      *(_BYTE *)(*(_QWORD *)(a1 - 976) + 1LL) = 1;
      v17 = *(void (**)(void))(*(_QWORD *)(a1 - 984) + 24LL);
      if ( *((_DWORD *)v17 - 1) != 1576769688 )
        __break(0x8228u);
      v17();
      dp_display_host_unready(a1 - 1168);
      dp_display_host_deinit(a1 - 1168);
      v18 = *v9 | 0x400;
      *v9 = v18;
      if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v19 = 0;
      StatusReg = _ReadStatusReg(SP_EL0);
      v21 = *(_DWORD *)(StatusReg + 1800);
      v22 = dp_display_state_name(v18);
      ipc_log_string(v19, "[d][%-4d]%s: state (0x%x): %s\n", v21, "add DP_STATE_SRC_PWRDN", v18, v22);
      if ( (_drm_debug & 4) != 0 )
      {
        v25 = *v9;
        v26 = *(_DWORD *)(StatusReg + 1800);
        v27 = dp_display_state_name(*v9);
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v26, "add DP_STATE_SRC_PWRDN", v25, v27);
      }
      sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_unprepare", 3112, 8, *v9, -1059143953, v23, v24, vars0a);
      v12 = 1;
    }
    else
    {
      v12 = 0;
      if ( *(_DWORD *)(a1 + 660) )
      {
LABEL_11:
        mutex_lock(a1 + 608);
        *(_DWORD *)(a1 + 716) -= *(_DWORD *)(a2 + 936);
        *(_DWORD *)(a2 + 936) = 0;
        mutex_unlock(a1 + 608);
        v13 = *(_DWORD **)(a2 + 1016);
        if ( *(v13 - 1) != -511227187 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v13)(a2, v12);
        mutex_unlock(a1 + 560);
        sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_unprepare", 3136, 8, 8738, *v9, -1059143953, v14, vars0a);
        return 0;
      }
    }
    if ( *(_BYTE *)(a1 + 34) == 1 && (*(_BYTE *)(a1 + 73) & 1) == 0 )
    {
      v28 = *(unsigned int (**)(void))(*(_QWORD *)(a1 - 1024) + 112LL);
      if ( *((_DWORD *)v28 - 1) != -339360380 )
        __break(0x8228u);
      if ( v28() )
      {
        if ( !g_dp_display || (v29 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v29 = 0;
        ipc_log_string(v29, "[e][%-4d]Cannot turn edp panel power off\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
        printk(&unk_252C50, "dp_display_unprepare");
      }
    }
    v30 = *v9 & 0xFFFFFFBF;
    *v9 = v30;
    if ( !g_dp_display || (v31 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v31 = 0;
    v32 = _ReadStatusReg(SP_EL0);
    v33 = *(_DWORD *)(v32 + 1800);
    v34 = dp_display_state_name(v30);
    ipc_log_string(v31, "[d][%-4d]%s: state (0x%x): %s\n", v33, "remove DP_STATE_ENABLED", v30, v34);
    if ( (_drm_debug & 4) != 0 )
    {
      v37 = *v9;
      v38 = *(_DWORD *)(v32 + 1800);
      v39 = dp_display_state_name(*v9);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v38, "remove DP_STATE_ENABLED", v37, v39);
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_unprepare", 3120, 8, *v9, -1059143953, v35, v36, vars0a);
    **(_DWORD **)(a1 - 1008) &= ~0x80u;
    **(_DWORD **)(a1 - 1008) |= 0x100u;
    complete_all(a1 - 1104);
    if ( !g_dp_display || (v40 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v40 = 0;
    ipc_log_string(v40, "[i][%-4d][OK]\n", *(_DWORD *)(v32 + 1800));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_25D9A9, *(unsigned int *)(v32 + 1800));
    else
      printk(&unk_26F5AF, "dp_display_unprepare");
    goto LABEL_11;
  }
  if ( !g_dp_display || (v41 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v41 = 0;
  ipc_log_string(v41, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_275B6D, "dp_display_unprepare");
  return 4294967274LL;
}
