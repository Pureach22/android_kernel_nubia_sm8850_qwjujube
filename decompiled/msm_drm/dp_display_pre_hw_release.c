__int64 __fastcall dp_display_pre_hw_release(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  int *v9; // x24
  int v10; // w20
  __int64 v11; // x21
  unsigned __int64 StatusReg; // x25
  int v13; // w22
  const char *v14; // x0
  int v15; // w6
  int v16; // w7
  int v17; // w21
  int v18; // w20
  const char *v19; // x0
  __int64 v20; // x8
  __int64 v21; // x8
  int v22; // w6
  int v23; // w7
  char v25; // [xsp+0h] [xbp+0h]
  char v26; // [xsp+0h] [xbp+0h]
  char v27; // [xsp+0h] [xbp+0h]

  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_pre_hw_release", 780, 8, 4369, -1059143953, a7, a8, v25);
  if ( !a1 )
    return 4294967274LL;
  mutex_lock(a1 + 560);
  v9 = (int *)(a1 - 1156);
  v10 = *(_DWORD *)(a1 - 1156) | 0x800;
  *(_DWORD *)(a1 - 1156) = v10;
  if ( !g_dp_display || (v11 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v11 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v13 = *(_DWORD *)(StatusReg + 1800);
  v14 = dp_display_state_name(v10);
  ipc_log_string(v11, "[d][%-4d]%s: state (0x%x): %s\n", v13, "add DP_STATE_TUI_ACTIVE", v10, v14);
  if ( (_drm_debug & 4) != 0 )
  {
    v17 = *v9;
    v18 = *(_DWORD *)(StatusReg + 1800);
    v19 = dp_display_state_name(*v9);
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v18, "add DP_STATE_TUI_ACTIVE", v17, v19);
  }
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_pre_hw_release", 789, 8, *v9, -1059143953, v15, v16, v26);
  cancel_work_sync(a1 + 464);
  cancel_work_sync(a1 + 496);
  cancel_work_sync(a1 + 528);
  _flush_workqueue(*(_QWORD *)(a1 + 352));
  v20 = *(_QWORD *)(a1 - 960);
  if ( v20 && *(_BYTE *)(v20 + 960) == 1 )
    *(_BYTE *)(*(_QWORD *)(v20 + 952) + 8LL) = 1;
  v21 = *(_QWORD *)(a1 - 952);
  if ( v21 )
  {
    if ( *(_BYTE *)(v21 + 960) == 1 )
      *(_BYTE *)(*(_QWORD *)(v21 + 952) + 8LL) = 1;
  }
  disable_irq(*(unsigned int *)(a1 - 1160));
  mutex_unlock(a1 + 560);
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_pre_hw_release", 800, 8, 8738, -1059143953, v22, v23, v27);
  return 0;
}
