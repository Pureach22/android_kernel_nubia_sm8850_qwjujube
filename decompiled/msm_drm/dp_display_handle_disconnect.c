__int64 __fastcall dp_display_handle_disconnect(
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
  unsigned int v10; // w20
  __int64 v11; // x21
  unsigned __int64 StatusReg; // x25
  int v13; // w22
  const char *v14; // x0
  int v15; // w6
  int v16; // w7
  unsigned int v17; // w21
  int v18; // w20
  const char *v19; // x0
  __int64 v20; // x0
  _DWORD *v21; // x8
  __int64 v22; // x0
  __int64 v23; // x9
  __int64 v24; // x8
  __int64 v25; // x0
  unsigned int v26; // w20
  void (*v27)(void); // x8
  void (*v28)(void); // x8
  void (*v29)(void); // x8
  int v30; // w7
  int v31; // w5
  __int64 v32; // x21
  void (__fastcall *v33)(_QWORD); // x8
  __int64 v34; // x0
  __int64 v35; // x21
  void (*v36)(void); // x8
  void (*v37)(void); // x8
  _DWORD *v38; // x8
  __int64 v39; // x21
  void (*v40)(void); // x8
  void (*v41)(void); // x8
  _DWORD *v42; // x8
  __int64 v43; // x8
  unsigned int v44; // w21
  __int64 v45; // x22
  int v46; // w23
  const char *v47; // x0
  int v48; // w6
  int v49; // w7
  unsigned int v50; // w22
  int v51; // w21
  const char *v52; // x0
  void (*v53)(void); // x8
  int v54; // w7
  int v55; // w7
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]
  char vars0b; // [xsp+0h] [xbp+0h]
  char vars0c; // [xsp+0h] [xbp+0h]

  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_handle_disconnect",
    1773,
    8,
    4369,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    a8,
    vars0);
  v9 = g_dp_display;
  v10 = *(_DWORD *)(a1 + 12) & 0xFFFFFFF7;
  *(_DWORD *)(a1 + 12) = v10;
  if ( !v9 || (v11 = *(_QWORD *)(v9 + 56)) == 0 )
    v11 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v13 = *(_DWORD *)(StatusReg + 1800);
  v14 = (const char *)dp_display_state_name(v10);
  ipc_log_string(v11, "[d][%-4d]%s: state (0x%x): %s\n", v13, "remove DP_STATE_CONNECTED", v10, v14);
  if ( (_drm_debug & 4) != 0 )
  {
    v17 = *(_DWORD *)(a1 + 12);
    v18 = *(_DWORD *)(StatusReg + 1800);
    v19 = (const char *)dp_display_state_name(v17);
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v18, "remove DP_STATE_CONNECTED", v17, v19);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_process_hpd_low",
    1493,
    8,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    v15,
    v16,
    vars0a);
  *(_BYTE *)(a1 + 1888) = 0;
  dp_audio_enable(a1, 0);
  if ( *(_BYTE *)(a1 + 1832) == 1 )
  {
    if ( !g_dp_display || (v20 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v20 = 0;
    ipc_log_string(v20, "[d][%-4d]mst_hpd_low work\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst_hpd_low work\n", *(_DWORD *)(StatusReg + 1800));
    if ( (*(_BYTE *)(a1 + 12) & 0x50) != 0 )
      dp_display_send_hpd_notification(a1);
    if ( *(_BYTE *)(a1 + 1832) == 1 )
    {
      v21 = *(_DWORD **)(a1 + 1864);
      if ( v21 )
      {
        if ( *(v21 - 1) != -1297827279 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v21)(a1 + 1168, 0);
      }
      if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v22 = 0;
      ipc_log_string(v22, "[d][%-4d]mst_mgr_state: %d\n", *(_DWORD *)(StatusReg + 1800), 0);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst_mgr_state: %d\n", *(_DWORD *)(StatusReg + 1800), 0);
    }
    v23 = *(_QWORD *)(a1 + 176);
    v24 = g_dp_display;
    *(_BYTE *)(a1 + 1832) = 0;
    *(_BYTE *)(v23 + 971) = 0;
    if ( !v24 || (v25 = *(_QWORD *)(v24 + 56)) == 0 )
      v25 = 0;
    ipc_log_string(
      v25,
      "[d][%-4d]mst_hpd_low. mst_active:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(unsigned __int8 *)(a1 + 1832));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]mst_hpd_low. mst_active:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(unsigned __int8 *)(a1 + 1832));
  }
  else if ( (*(_BYTE *)(a1 + 12) & 0x50) != 0 )
  {
    v26 = dp_display_send_hpd_notification(a1);
    goto LABEL_32;
  }
  v26 = 0;
LABEL_32:
  mutex_lock(a1 + 1728);
  if ( !*(_DWORD *)(a1 + 1828) )
  {
    v27 = *(void (**)(void))(*(_QWORD *)(a1 + 184) + 24LL);
    if ( *((_DWORD *)v27 - 1) != 1576769688 )
      __break(0x8228u);
    v27();
  }
  mutex_unlock(a1 + 1728);
  *(_BYTE *)(*(_QWORD *)(a1 + 176) + 872LL) = 0;
  if ( v26 )
  {
    v28 = *(void (**)(void))(*(_QWORD *)(a1 + 184) + 32LL);
    if ( *((_DWORD *)v28 - 1) != -1878159161 )
      __break(0x8228u);
    v28();
    v29 = *(void (**)(void))(*(_QWORD *)(a1 + 160) + 80LL);
    if ( *((_DWORD *)v29 - 1) != 532007358 )
      __break(0x8228u);
    v29();
  }
  mutex_lock(a1 + 1728);
  v31 = *(_DWORD *)(a1 + 12);
  if ( (v31 & 0x40) != 0 )
  {
    v32 = *(_QWORD *)(a1 + 168);
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_clean", 1732, 8, 4369, v31, -1059143953, v30, vars0b);
    if ( (*(_BYTE *)(a1 + 13) & 8) != 0 )
    {
      if ( !g_dp_display || (v57 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v57 = 0;
      ipc_log_string(v57, "[w][%-4d]TUI is active\n", *(_DWORD *)(StatusReg + 1800));
      printk(&unk_26F583, "dp_display_clean");
    }
    else
    {
      if ( *(_DWORD *)(*(_QWORD *)(a1 + 168) + 140LL) && *(_QWORD *)(a1 + 232) && *(_DWORD *)(v32 + 136) )
      {
        cancel_delayed_work_sync(a1 + 1528);
        v33 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 232) + 80LL);
        if ( v33 )
        {
          v34 = *(_QWORD *)(a1 + 224);
          if ( *((_DWORD *)v33 - 1) != 251140989 )
            __break(0x8228u);
          v33(v34);
        }
        dp_display_update_hdcp_status(a1, 1);
      }
      v35 = *(_QWORD *)(a1 + 208);
      if ( v35 )
      {
        if ( *(_BYTE *)(v35 + 960) == 1 )
        {
          v36 = *(void (**)(void))(*(_QWORD *)(v35 + 952) + 24LL);
          if ( *((_DWORD *)v36 - 1) != 91663063 )
            __break(0x8228u);
          v36();
        }
        if ( *(_DWORD *)(a1 + 1828) )
        {
          v37 = *(void (**)(void))(*(_QWORD *)(a1 + 184) + 88LL);
          if ( *((_DWORD *)v37 - 1) != 1909714074 )
            __break(0x8228u);
          v37();
        }
        else
        {
          if ( !g_dp_display || (v58 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v58 = 0;
          ipc_log_string(v58, "[w][%-4d]streams already disabled cnt=%d\n", *(_DWORD *)(StatusReg + 1800), 0);
          printk(&unk_2762CA, "dp_display_stream_pre_disable");
        }
        dp_display_stream_disable(a1, v35);
        mutex_lock(a1 + 1776);
        *(_DWORD *)(a1 + 1884) -= *(_DWORD *)(v35 + 936);
        *(_DWORD *)(v35 + 936) = 0;
        mutex_unlock(a1 + 1776);
        v38 = *(_DWORD **)(v35 + 1016);
        if ( *(v38 - 1) != -511227187 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v38)(v35, 0);
      }
      v39 = *(_QWORD *)(a1 + 216);
      if ( v39 )
      {
        if ( *(_BYTE *)(v39 + 960) == 1 )
        {
          v40 = *(void (**)(void))(*(_QWORD *)(v39 + 952) + 24LL);
          if ( *((_DWORD *)v40 - 1) != 91663063 )
            __break(0x8228u);
          v40();
        }
        if ( *(_DWORD *)(a1 + 1828) )
        {
          v41 = *(void (**)(void))(*(_QWORD *)(a1 + 184) + 88LL);
          if ( *((_DWORD *)v41 - 1) != 1909714074 )
            __break(0x8228u);
          v41();
        }
        else
        {
          if ( !g_dp_display || (v59 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v59 = 0;
          ipc_log_string(v59, "[w][%-4d]streams already disabled cnt=%d\n", *(_DWORD *)(StatusReg + 1800), 0);
          printk(&unk_2762CA, "dp_display_stream_pre_disable");
        }
        dp_display_stream_disable(a1, v39);
        mutex_lock(a1 + 1776);
        *(_DWORD *)(a1 + 1884) -= *(_DWORD *)(v39 + 936);
        *(_DWORD *)(v39 + 936) = 0;
        mutex_unlock(a1 + 1776);
        v42 = *(_DWORD **)(v39 + 1016);
        if ( *(v42 - 1) != -511227187 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v42)(v39, 0);
      }
      v43 = g_dp_display;
      v44 = *(_DWORD *)(a1 + 12) & 0xFFFFFFB7;
      *(_DWORD *)(a1 + 12) = v44;
      if ( !v43 || (v45 = *(_QWORD *)(v43 + 56)) == 0 )
        v45 = 0;
      v46 = *(_DWORD *)(StatusReg + 1800);
      v47 = (const char *)dp_display_state_name(v44);
      ipc_log_string(
        v45,
        "[d][%-4d]%s: state (0x%x): %s\n",
        v46,
        "remove DP_STATE_ENABLED | DP_STATE_CONNECTED",
        v44,
        v47);
      if ( (_drm_debug & 4) != 0 )
      {
        v50 = *(_DWORD *)(a1 + 12);
        v51 = *(_DWORD *)(StatusReg + 1800);
        v52 = (const char *)dp_display_state_name(v50);
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
          v51,
          "remove DP_STATE_ENABLED | DP_STATE_CONNECTED",
          v50,
          v52);
      }
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_clean",
        1763,
        8,
        *(_DWORD *)(a1 + 12),
        -1059143953,
        v48,
        v49,
        vars0b);
      v53 = *(void (**)(void))(*(_QWORD *)(a1 + 184) + 24LL);
      if ( *((_DWORD *)v53 - 1) != 1576769688 )
        __break(0x8228u);
      v53();
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_clean",
        1766,
        8,
        8738,
        *(_DWORD *)(a1 + 12),
        -1059143953,
        v54,
        vars0c);
    }
  }
  dp_display_host_unready(a1);
  *(_DWORD *)(a1 + 1884) = 0;
  mutex_unlock(a1 + 1728);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_handle_disconnect",
    1791,
    8,
    8738,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    v55,
    vars0b);
  return v26;
}
