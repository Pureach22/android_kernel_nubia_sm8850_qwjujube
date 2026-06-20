__int64 __fastcall dp_pm_complete(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x22
  int v9; // w7
  _DWORD *v10; // x8
  int v11; // w8
  void (*v12)(void); // x8
  void (*v13)(void); // x8
  unsigned int v14; // w19
  __int64 v15; // x9
  __int64 v16; // x20
  unsigned __int64 StatusReg; // x24
  int v18; // w21
  const char *v19; // x0
  int v20; // w6
  int v21; // w7
  int v22; // w20
  int v23; // w19
  const char *v24; // x0
  int v25; // w7
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0b; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]
  char vars0c; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    v8 = *(_QWORD *)(result + 152);
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_pm_complete", 4381, 8, 4369, -1059143953, a7, a8, vars0);
    mutex_lock(v8 + 1728);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_set_mst_state",
      4290,
      8,
      0,
      *(unsigned __int8 *)(v8 + 1832),
      -1059143953,
      v9,
      vars0b);
    if ( *(_BYTE *)(v8 + 1832) == 1 )
    {
      v10 = *(_DWORD **)(v8 + 1856);
      if ( v10 )
      {
        if ( *(v10 - 1) != -1783855812 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v10)(v8 + 1168, 0);
      }
    }
    v11 = *(_DWORD *)(v8 + 12);
    if ( (v11 & 0x48) == 8 )
    {
      v12 = *(void (**)(void))(*(_QWORD *)(v8 + 160) + 80LL);
      if ( *((_DWORD *)v12 - 1) != 532007358 )
        __break(0x8228u);
      v12();
      v13 = *(void (**)(void))(*(_QWORD *)(v8 + 184) + 32LL);
      if ( *((_DWORD *)v13 - 1) != -1878159161 )
        __break(0x8228u);
      v13();
      v11 = *(_DWORD *)(v8 + 12);
    }
    v14 = v11 & 0xFFFFFF7F;
    v15 = g_dp_display;
    *(_DWORD *)(v8 + 12) = v11 & 0xFFFFFF7F;
    if ( !v15 || (v16 = *(_QWORD *)(v15 + 56)) == 0 )
      v16 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    v18 = *(_DWORD *)(StatusReg + 1800);
    v19 = dp_display_state_name(v14);
    ipc_log_string(v16, "[d][%-4d]%s: state (0x%x): %s\n", v18, "remove DP_STATE_SUSPENDED", v14, v19);
    if ( (_drm_debug & 4) != 0 )
    {
      v22 = *(_DWORD *)(v8 + 12);
      v23 = *(_DWORD *)(StatusReg + 1800);
      v24 = dp_display_state_name(v22);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v23, "remove DP_STATE_SUSPENDED", v22, v24);
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_pm_complete", 4399, 8, *(_DWORD *)(v8 + 12), -1059143953, v20, v21, vars0a);
    mutex_unlock(v8 + 1728);
    return sde_evtlog_log(
             sde_dbg_base_evtlog,
             "dp_pm_complete",
             4401,
             8,
             8738,
             *(_DWORD *)(v8 + 12),
             -1059143953,
             v25,
             vars0c);
  }
  return result;
}
