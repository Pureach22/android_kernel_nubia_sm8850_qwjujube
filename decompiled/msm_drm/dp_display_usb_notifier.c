__int64 __fastcall dp_display_usb_notifier(__int64 a1, __int64 a2)
{
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x25
  int v7; // w20
  __int64 v8; // x21
  int v9; // w22
  const char *v10; // x0
  int v11; // w6
  int v12; // w7
  int v13; // w21
  int v14; // w20
  const char *v15; // x0
  void (*v16)(void); // x8
  void (*v17)(void); // x8
  char v18; // [xsp+0h] [xbp+0h]
  char v19; // [xsp+0h] [xbp+0h]

  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_usb_notifier",
    2187,
    8,
    *(_DWORD *)(a1 - 4452),
    **(unsigned __int8 **)(a1 - 4272),
    a2,
    -1059143953,
    v18);
  if ( !a2 && **(_BYTE **)(a1 - 4272) == 1 )
  {
    if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v5 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v5, "[w][%-4d]usb disconnected during simulation\n", *(_DWORD *)(StatusReg + 1800));
    printk(&unk_23B041, "dp_display_usb_notifier");
    v7 = *(_DWORD *)(a1 - 4452) | 0x100;
    *(_DWORD *)(a1 - 4452) = v7;
    if ( !g_dp_display || (v8 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v8 = 0;
    v9 = *(_DWORD *)(StatusReg + 1800);
    v10 = dp_display_state_name(v7);
    ipc_log_string(v8, "[d][%-4d]%s: state (0x%x): %s\n", v9, "add DP_STATE_ABORTED", v7, v10);
    if ( (_drm_debug & 4) != 0 )
    {
      v13 = *(_DWORD *)(a1 - 4452);
      v14 = *(_DWORD *)(StatusReg + 1800);
      v15 = dp_display_state_name(v13);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v14, "add DP_STATE_ABORTED", v13, v15);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_usb_notifier",
      2190,
      8,
      *(_DWORD *)(a1 - 4452),
      -1059143953,
      v11,
      v12,
      v19);
    v16 = *(void (**)(void))(*(_QWORD *)(a1 - 4280) + 32LL);
    if ( *((_DWORD *)v16 - 1) != -1878159161 )
      __break(0x8228u);
    v16();
    v17 = *(void (**)(void))(*(_QWORD *)(a1 - 4304) + 80LL);
    if ( *((_DWORD *)v17 - 1) != 532007358 )
      __break(0x8228u);
    v17();
    queue_work_on(32, *(_QWORD *)(a1 - 2944), a1 - 2768);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_usb_notifier",
    2197,
    8,
    8738,
    *(_DWORD *)(a1 - 4452),
    0,
    -1059143953,
    v19);
  return 0;
}
