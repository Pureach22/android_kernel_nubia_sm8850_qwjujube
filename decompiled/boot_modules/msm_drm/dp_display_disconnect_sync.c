__int64 __fastcall dp_display_disconnect_sync(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v9; // x8
  int v10; // w20
  __int64 v11; // x21
  unsigned __int64 StatusReg; // x24
  int v13; // w22
  const char *v14; // x0
  int v15; // w6
  int v16; // w7
  int v17; // w21
  int v18; // w20
  const char *v19; // x0
  void (*v20)(void); // x8
  void (*v21)(void); // x8
  unsigned int v22; // w20
  __int64 v23; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  __int64 v29; // x6
  int v30; // w7
  char v32; // [xsp+0h] [xbp+0h]
  char v33; // [xsp+0h] [xbp+0h]
  char v34; // [xsp+0h] [xbp+0h]

  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_disconnect_sync",
    1799,
    8,
    4369,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    a8,
    v32);
  v9 = g_dp_display;
  v10 = *(_DWORD *)(a1 + 12) | 0x100;
  *(_DWORD *)(a1 + 12) = v10;
  if ( !v9 || (v11 = *(_QWORD *)(v9 + 56)) == 0 )
    v11 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v13 = *(_DWORD *)(StatusReg + 1800);
  v14 = dp_display_state_name(v10);
  ipc_log_string(v11, "[d][%-4d]%s: state (0x%x): %s\n", v13, "add DP_STATE_ABORTED", v10, v14);
  if ( (_drm_debug & 4) != 0 )
  {
    v17 = *(_DWORD *)(a1 + 12);
    v18 = *(_DWORD *)(StatusReg + 1800);
    v19 = dp_display_state_name(v17);
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v18, "add DP_STATE_ABORTED", v17, v19);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_disconnect_sync",
    1801,
    8,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    v15,
    v16,
    v33);
  v20 = *(void (**)(void))(*(_QWORD *)(a1 + 184) + 32LL);
  if ( *((_DWORD *)v20 - 1) != -1878159161 )
    __break(0x8228u);
  v20();
  v21 = *(void (**)(void))(*(_QWORD *)(a1 + 160) + 80LL);
  if ( *((_DWORD *)v21 - 1) != 532007358 )
    __break(0x8228u);
  v21();
  cancel_work_sync(a1 + 1632);
  cancel_work_sync(a1 + 1664);
  cancel_work_sync(a1 + 1696);
  _flush_workqueue(*(_QWORD *)(a1 + 1520));
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 192) + 160LL) >= 0x2710u )
    v22 = 10000;
  else
    v22 = *(_DWORD *)(*(_QWORD *)(a1 + 192) + 160LL);
  if ( !g_dp_display || (v23 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v23 = 0;
  ipc_log_string(v23, "[i][%-4d]: disconnect delay = %d ms\n", *(_DWORD *)(StatusReg + 1800), v22);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_23B00A, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_21C91B, "dp_display_disconnect_sync");
  msleep(v22);
  dp_display_handle_disconnect(a1, v24, v25, v26, v27, v28, v29, v30);
  return sde_evtlog_log(
           sde_dbg_base_evtlog,
           "dp_display_disconnect_sync",
           1831,
           8,
           8738,
           *(_DWORD *)(a1 + 12),
           v22,
           -1059143953,
           v34);
}
