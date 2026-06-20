__int64 __fastcall dp_display_host_deinit(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w5
  __int64 v9; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  int v12; // w19
  __int64 v13; // x23
  __int64 v14; // x20
  int v15; // w21
  const char *v16; // x0
  int v17; // w6
  int v18; // w7
  __int64 v19; // x0
  unsigned __int64 v20; // x19
  int v21; // w8
  __int64 v22; // x0
  __int64 v23; // t2
  void (__fastcall *v24)(__int64, __int64); // x8
  __int64 v25; // x0
  __int64 v26; // t2
  void (__fastcall *v27)(__int64, __int64); // x8
  __int64 v28; // x20
  void (__fastcall *v29)(_QWORD); // x9
  __int64 v30; // x0
  void (*v31)(void); // x8
  void (*v32)(void); // x8
  __int64 v33; // x8
  unsigned int v34; // w19
  __int64 v35; // x20
  unsigned __int64 v36; // x22
  int v37; // w21
  const char *v38; // x0
  int v39; // w6
  int v40; // w7
  int v41; // w20
  int v42; // w19
  const char *v43; // x0
  __int64 v44; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_DWORD *)(a1 + 1828);
  if ( v8 )
  {
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_host_deinit",
      1256,
      8,
      *(_DWORD *)(a1 + 12),
      v8,
      -1059143953,
      a8,
      vars0);
    if ( !g_dp_display || (v9 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v9 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    result = ipc_log_string(v9, "[d][%-4d]active stream present\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]active stream present\n", *(_DWORD *)(StatusReg + 1800));
  }
  else
  {
    v12 = *(_DWORD *)(a1 + 12);
    v13 = a1;
    if ( (v12 & 2) != 0 )
    {
      if ( (v12 & 4) != 0 )
      {
        if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v19 = 0;
        v20 = _ReadStatusReg(SP_EL0);
        ipc_log_string(v19, "[d][%-4d]dp deinit before unready\n", *(_DWORD *)(v20 + 1800));
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]dp deinit before unready\n", *(_DWORD *)(v20 + 1800));
        dp_display_host_unready(v13);
        a1 = v13;
      }
      v21 = *(_DWORD *)(a1 + 240);
      if ( (*(_DWORD *)(a1 + 312) & v21) != 0 )
      {
        v23 = a1 + 296;
        v22 = *(_QWORD *)(a1 + 296);
        v24 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v23 + 8) + 56LL);
        if ( *((_DWORD *)v24 - 1) != -538254584 )
          __break(0x8228u);
        v24(v22, 1);
        v21 = *(_DWORD *)(v13 + 240);
        a1 = v13;
      }
      if ( (*(_DWORD *)(a1 + 288) & v21) != 0 )
      {
        v26 = a1 + 272;
        v25 = *(_QWORD *)(a1 + 272);
        v27 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v26 + 8) + 56LL);
        if ( *((_DWORD *)v27 - 1) != -538254584 )
          __break(0x8228u);
        v27(v25, 1);
        a1 = v13;
      }
      v28 = a1;
      v29 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 184) + 8LL);
      v30 = *(_QWORD *)(a1 + 184);
      if ( *((_DWORD *)v29 - 1) != 1576769688 )
        __break(0x8229u);
      v29(v30);
      v31 = *(void (**)(void))(*(_QWORD *)(v28 + 128) + 40LL);
      if ( *((_DWORD *)v31 - 1) != -83176264 )
        __break(0x8228u);
      v31();
      v32 = *(void (**)(void))(*(_QWORD *)(v28 + 144) + 40LL);
      if ( *((_DWORD *)v32 - 1) != 139933102 )
        __break(0x8228u);
      v32();
      disable_irq(*(unsigned int *)(v28 + 8));
      **(_DWORD **)(v28 + 160) = 0;
      v33 = g_dp_display;
      v34 = *(_DWORD *)(v28 + 12) & 0xFFFFFFFD;
      *(_DWORD *)(v28 + 12) = v34;
      if ( !v33 || (v35 = *(_QWORD *)(v33 + 56)) == 0 )
        v35 = 0;
      v36 = _ReadStatusReg(SP_EL0);
      v37 = *(_DWORD *)(v36 + 1800);
      v38 = dp_display_state_name(v34);
      ipc_log_string(v35, "[d][%-4d]%s: state (0x%x): %s\n", v37, "remove DP_STATE_INITIALIZED", v34, v38);
      if ( (_drm_debug & 4) != 0 )
      {
        v41 = *(_DWORD *)(v13 + 12);
        v42 = *(_DWORD *)(v36 + 1800);
        v43 = dp_display_state_name(v41);
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
          v42,
          "remove DP_STATE_INITIALIZED",
          v41,
          v43);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_host_deinit",
        1278,
        8,
        *(_DWORD *)(v13 + 12),
        -1059143953,
        v39,
        v40,
        vars0);
      if ( !g_dp_display || (v44 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v44 = 0;
      ipc_log_string(v44, "[i][%-4d][OK]\n", *(_DWORD *)(v36 + 1800));
      if ( (_drm_debug & 4) != 0 )
        return printk(&unk_25D9A9, *(unsigned int *)(v36 + 1800));
      else
        return printk(&unk_26F5AF, "dp_display_host_deinit");
    }
    else
    {
      if ( !g_dp_display || (v14 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v14 = 0;
      v15 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v16 = dp_display_state_name(v12);
      ipc_log_string(v14, "[e][%-4d]%s: state (0x%x): %s\n", v15, "[not initialized]", v12, v16);
      dp_display_state_name(*(_DWORD *)(v13 + 12));
      printk(&unk_24548C, "dp_display_host_deinit");
      return sde_evtlog_log(
               sde_dbg_base_evtlog,
               "dp_display_host_deinit",
               1262,
               8,
               *(_DWORD *)(v13 + 12),
               -1059143953,
               v17,
               v18,
               vars0);
    }
  }
  return result;
}
