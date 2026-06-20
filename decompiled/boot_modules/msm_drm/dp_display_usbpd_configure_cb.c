__int64 __fastcall dp_display_usbpd_configure_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  unsigned int v9; // w20
  unsigned int v10; // w8
  __int64 v12; // x0
  __int64 (*v13)(void); // x8
  int v14; // w21
  unsigned __int64 StatusReg; // x25
  __int64 v16; // x1
  _DWORD *v17; // x8
  unsigned int v18; // w0
  unsigned int v19; // w20
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  void *v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned __int64 v26; // x20
  int v27; // w7
  __int64 v28; // x9
  _DWORD *v29; // x8
  __int64 v30; // x1
  int v31; // w20
  __int64 v32; // x8
  unsigned int v33; // w20
  __int64 v34; // x21
  unsigned __int64 v35; // x23
  int v36; // w22
  const char *v37; // x0
  int v38; // w6
  int v39; // w7
  int v40; // w21
  int v41; // w20
  const char *v42; // x0
  __int64 v43; // x8
  int v44; // w20
  __int64 v45; // x21
  int v46; // w22
  const char *v47; // x0
  int v48; // w6
  int v49; // w7
  int v50; // w21
  int v51; // w20
  const char *v52; // x0
  unsigned int v53; // w0
  __int64 v54; // x21
  unsigned __int64 v55; // x23
  int v56; // w22
  const char *v57; // x0
  int v58; // w6
  int v59; // w7
  int v60; // w21
  int v61; // w20
  const char *v62; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  _QWORD v66[2]; // [xsp+0h] [xbp-20h] BYREF
  int v67; // [xsp+10h] [xbp-10h]
  int v68; // [xsp+14h] [xbp-Ch]
  __int64 v69; // [xsp+18h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    if ( !g_dp_display || (v21 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v21 = 0;
    ipc_log_string(v21, "[e][%-4d]invalid dev\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_24218F, "dp_display_usbpd_configure_cb");
    v19 = -22;
    goto LABEL_74;
  }
  v8 = *(_QWORD *)(a1 + 152);
  if ( !v8 )
  {
    if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v22 = 0;
    ipc_log_string(v22, "[e][%-4d]no driver data found\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v23 = &unk_26F6F4;
    goto LABEL_38;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v8 + 1168) + 936LL) & 1) == 0 )
  {
    v9 = 0;
    do
    {
      usleep_range_state(1000, 1100, 2);
      v10 = v9 + 1;
      if ( (*(_BYTE *)(*(_QWORD *)(v8 + 1168) + 936LL) & 1) != 0 )
        break;
    }
    while ( v9++ < 0x270F );
    if ( v10 == 10000 )
    {
      if ( !g_dp_display || (v24 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v24 = 0;
      ipc_log_string(v24, "[e][%-4d]driver is not loaded\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      v23 = &unk_26BD63;
LABEL_38:
      printk(v23, "dp_display_usbpd_configure_cb");
      v19 = -19;
      goto LABEL_74;
    }
  }
  if ( (**(_BYTE **)(v8 + 192) & 1) != 0 )
    goto LABEL_52;
  if ( (*(_BYTE *)(v8 + 1825) & 1) != 0 )
    goto LABEL_52;
  if ( (*(_BYTE *)(*(_QWORD *)(v8 + 136) + 732LL) & 1) != 0 )
    goto LABEL_52;
  if ( !*(_QWORD *)(v8 + 32) )
    goto LABEL_52;
  v12 = *(_QWORD *)(v8 + 160);
  v13 = *(__int64 (**)(void))(v12 + 96);
  if ( !v13 )
    goto LABEL_52;
  if ( (*(_BYTE *)(v8 + 40) & 1) == 0 && *(_QWORD *)(v12 + 104) )
  {
    v66[1] = 0;
    v68 = 0;
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_init_aux_switch", 1534, 8, 4369, -1059143953, a7, a8, v66[0]);
    v14 = 0;
    v66[0] = dp_display_aux_switch_callback;
    StatusReg = _ReadStatusReg(SP_EL0);
    v67 = 0;
    while ( 1 )
    {
      v16 = *(_QWORD *)(v8 + 32);
      v17 = *(_DWORD **)(*(_QWORD *)(v8 + 160) + 104LL);
      if ( *(v17 - 1) != -1668605521 )
        __break(0x8228u);
      v18 = ((__int64 (__fastcall *)(_QWORD *, __int64))v17)(v66, v16);
      if ( !v18 )
        break;
      v19 = v18;
      if ( !g_dp_display || (v20 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v20 = 0;
      ipc_log_string(
        v20,
        "[d][%-4d]failed to register notifier retry=%d rc=%d\n",
        *(_DWORD *)(StatusReg + 1800),
        v14,
        v19);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]failed to register notifier retry=%d rc=%d\n",
          *(_DWORD *)(StatusReg + 1800),
          v14,
          v19);
      msleep(100);
      if ( ++v14 == 50 )
      {
        if ( !g_dp_display || (v65 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v65 = 0;
        ipc_log_string(v65, "[w][%-4d]Failed to register fsa notifier\n", *(_DWORD *)(StatusReg + 1800));
        printk(&unk_2797EC, "dp_display_init_aux_switch");
        *(_BYTE *)(v8 + 40) = 0;
        goto LABEL_74;
      }
    }
    if ( !g_dp_display || (v25 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v25 = 0;
    v26 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v25, "[d][%-4d]registered notifier successfully\n", *(_DWORD *)(v26 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]registered notifier successfully\n", *(_DWORD *)(v26 + 1800));
    v28 = *(_QWORD *)(v8 + 160);
    *(_BYTE *)(v8 + 40) = 1;
    v29 = *(_DWORD **)(v28 + 112);
    if ( v29 )
    {
      v30 = *(_QWORD *)(v8 + 32);
      if ( *(v29 - 1) != -1668605521 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, __int64))v29)(v66, v30);
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_init_aux_switch", 1564, 8, 8738, 0, -1059143953, v27, v66[0]);
    v13 = *(__int64 (**)(void))(*(_QWORD *)(v8 + 160) + 96LL);
  }
  if ( *((_DWORD *)v13 - 1) != 1205381171 )
    __break(0x8228u);
  v19 = v13();
  if ( !v19 )
  {
LABEL_52:
    mutex_lock(v8 + 1728);
    v31 = *(_DWORD *)(v8 + 12);
    if ( (v31 & 0x800) != 0 )
    {
      if ( !g_dp_display || (v54 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v54 = 0;
      v55 = _ReadStatusReg(SP_EL0);
      v56 = *(_DWORD *)(v55 + 1800);
      v57 = dp_display_state_name(v31);
      ipc_log_string(v54, "[d][%-4d]%s: state (0x%x): %s\n", v56, "[TUI is active]", v31, v57);
      if ( (_drm_debug & 4) != 0 )
      {
        v60 = *(_DWORD *)(v8 + 12);
        v61 = *(_DWORD *)(v55 + 1800);
        v62 = dp_display_state_name(v60);
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v61, "[TUI is active]", v60, v62);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_usbpd_configure_cb",
        1618,
        8,
        *(_DWORD *)(v8 + 12),
        -1059143953,
        v58,
        v59,
        v66[0]);
      goto LABEL_73;
    }
    v32 = g_dp_display;
    v33 = v31 & 0xFFFFF6FF;
    *(_DWORD *)(v8 + 12) = v33;
    if ( !v32 || (v34 = *(_QWORD *)(v32 + 56)) == 0 )
      v34 = 0;
    v35 = _ReadStatusReg(SP_EL0);
    v36 = *(_DWORD *)(v35 + 1800);
    v37 = dp_display_state_name(v33);
    ipc_log_string(v34, "[d][%-4d]%s: state (0x%x): %s\n", v36, "remove DP_STATE_ABORTED", v33, v37);
    if ( (_drm_debug & 4) != 0 )
    {
      v40 = *(_DWORD *)(v8 + 12);
      v41 = *(_DWORD *)(v35 + 1800);
      v42 = dp_display_state_name(v40);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v41, "remove DP_STATE_ABORTED", v40, v42);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_usbpd_configure_cb",
      1623,
      8,
      *(_DWORD *)(v8 + 12),
      -1059143953,
      v38,
      v39,
      v66[0]);
    v43 = g_dp_display;
    v44 = *(_DWORD *)(v8 + 12) | 1;
    *(_DWORD *)(v8 + 12) = v44;
    if ( !v43 || (v45 = *(_QWORD *)(v43 + 56)) == 0 )
      v45 = 0;
    v46 = *(_DWORD *)(v35 + 1800);
    v47 = dp_display_state_name(v44);
    ipc_log_string(v45, "[d][%-4d]%s: state (0x%x): %s\n", v46, "add DP_STATE_CONFIGURED", v44, v47);
    if ( (_drm_debug & 4) != 0 )
    {
      v50 = *(_DWORD *)(v8 + 12);
      v51 = *(_DWORD *)(v35 + 1800);
      v52 = dp_display_state_name(v50);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v51, "add DP_STATE_CONFIGURED", v50, v52);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_usbpd_configure_cb",
      1624,
      8,
      *(_DWORD *)(v8 + 12),
      -1059143953,
      v48,
      v49,
      v66[0]);
    v53 = dp_display_host_init(v8);
    if ( !v53 )
    {
      if ( *(_BYTE *)(*(_QWORD *)(v8 + 128) + 8LL) == 1 )
        queue_work_on(32, *(_QWORD *)(v8 + 1520), v8 + 1632);
      else
        *(_BYTE *)(v8 + 1888) = 1;
LABEL_73:
      mutex_unlock(v8 + 1728);
      v19 = 0;
      goto LABEL_74;
    }
    v19 = v53;
    if ( !g_dp_display || (v64 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v64 = 0;
    ipc_log_string(v64, "[e][%-4d]Host init Failed", *(_DWORD *)(v35 + 1800));
    printk(&unk_21FE95, "dp_display_usbpd_configure_cb");
    mutex_unlock(v8 + 1728);
  }
LABEL_74:
  _ReadStatusReg(SP_EL0);
  return v19;
}
