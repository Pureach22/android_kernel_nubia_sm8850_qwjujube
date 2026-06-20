__int64 __fastcall dp_display_send_hpd_notification(__int64 a1)
{
  unsigned int v1; // w21
  int v3; // w19
  int v4; // w8
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x21
  int v7; // w27
  __int64 v8; // x0
  unsigned __int64 v9; // x21
  unsigned int v10; // w21
  void (__fastcall *v12)(__int64, bool); // x8
  int v13; // w8
  __int64 v14; // x9
  int v15; // w22
  __int64 v16; // x23
  unsigned __int64 v17; // x28
  int v18; // w24
  const char *v19; // x0
  int v20; // w6
  int v21; // w7
  int v22; // w23
  int v23; // w22
  const char *v24; // x0
  __int64 v25; // x8
  unsigned int v26; // w22
  __int64 v27; // x23
  int v28; // w24
  const char *v29; // x0
  int v30; // w6
  int v31; // w7
  int v32; // w23
  int v33; // w22
  const char *v34; // x0
  unsigned int v35; // w22
  __int64 v36; // x9
  int v37; // w22
  __int64 v38; // x23
  unsigned __int64 v39; // x28
  int v40; // w24
  const char *v41; // x0
  int v42; // w6
  int v43; // w7
  int v44; // w23
  int v45; // w22
  const char *v46; // x0
  __int64 v47; // x8
  unsigned int v48; // w22
  __int64 v49; // x23
  int v50; // w24
  const char *v51; // x0
  int v52; // w6
  int v53; // w7
  int v54; // w23
  int v55; // w22
  const char *v56; // x0
  void (__fastcall *v57)(__int64, bool); // x8
  __int64 v58; // x21
  unsigned __int64 v59; // x24
  int v60; // w23
  const char *v61; // x0
  int v62; // w6
  int v63; // w7
  int v64; // w22
  int v65; // w21
  const char *v66; // x0
  __int64 v67; // x0
  int v68; // w2
  const char *v69; // x21
  char v70; // [xsp+0h] [xbp-10h]
  char v71; // [xsp+0h] [xbp-10h]
  char v72; // [xsp+0h] [xbp-10h]
  char v73; // [xsp+0h] [xbp-10h]
  char v74; // [xsp+0h] [xbp-10h]

  v1 = *(_DWORD *)(a1 + 12);
  v3 = (v1 >> 3) & 1;
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_send_hpd_notification", 975, 8, 4369, v1, v3, -1059143953, v70);
  v4 = *(_DWORD *)(a1 + 12);
  if ( (v1 & 8) != 0 && (v4 & 0x10) != 0 )
  {
    if ( !g_dp_display || (v5 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v5 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v5, "[d][%-4d]connection notified already, skip notification\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]connection notified already, skip notification\n",
        *(unsigned int *)(StatusReg + 1800));
    goto LABEL_15;
  }
  v7 = v1 & 8;
  if ( (v1 & 8) == 0 && (v4 & 0x20) != 0 )
  {
    if ( !g_dp_display || (v8 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v8 = 0;
    v9 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v8, "[d][%-4d]disonnect notified already, skip notification\n", *(_DWORD *)(v9 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]disonnect notified already, skip notification\n",
        *(unsigned int *)(v9 + 1800));
    goto LABEL_15;
  }
  **(_DWORD **)(a1 + 160) |= 1u;
  *(_DWORD *)(a1 + 64) = 0;
  if ( (*(_BYTE *)(a1 + 1832) & 1) != 0 )
  {
    v12 = *(void (__fastcall **)(__int64, bool))(a1 + 1840);
    *(_BYTE *)(a1 + 1200) = 0;
    if ( !v12 )
      goto LABEL_15;
    if ( *((_DWORD *)v12 - 1) != -538254584 )
      __break(0x8228u);
    v12(a1 + 1168, v7 != 0);
  }
  else
  {
    *(_BYTE *)(a1 + 1200) = (unsigned __int8)(v1 & 8) >> 3;
    if ( (dp_display_send_hpd_event(a1) & 1) == 0 )
      goto LABEL_15;
  }
  v13 = *(_DWORD *)(a1 + 12);
  if ( (v1 & 8) != 0 )
  {
    v14 = g_dp_display;
    v15 = v13 | 0x10;
    *(_DWORD *)(a1 + 12) = v13 | 0x10;
    if ( !v14 || (v16 = *(_QWORD *)(v14 + 56)) == 0 )
      v16 = 0;
    v17 = _ReadStatusReg(SP_EL0);
    v18 = *(_DWORD *)(v17 + 1800);
    v19 = dp_display_state_name(v15);
    ipc_log_string(v16, "[d][%-4d]%s: state (0x%x): %s\n", v18, "add DP_STATE_CONNECT_NOTIFIED", v15, v19);
    if ( (_drm_debug & 4) != 0 )
    {
      v22 = *(_DWORD *)(a1 + 12);
      v23 = *(_DWORD *)(v17 + 1800);
      v24 = dp_display_state_name(v22);
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
        v23,
        "add DP_STATE_CONNECT_NOTIFIED",
        v22,
        v24);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_send_hpd_notification",
      1013,
      8,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v20,
      v21,
      v71);
    v25 = g_dp_display;
    v26 = *(_DWORD *)(a1 + 12) & 0xFFFFFFDF;
    *(_DWORD *)(a1 + 12) = v26;
    if ( !v25 || (v27 = *(_QWORD *)(v25 + 56)) == 0 )
      v27 = 0;
    v28 = *(_DWORD *)(v17 + 1800);
    v29 = dp_display_state_name(v26);
    ipc_log_string(v27, "[d][%-4d]%s: state (0x%x): %s\n", v28, "remove DP_STATE_DISCONNECT_NOTIFIED", v26, v29);
    if ( (_drm_debug & 4) != 0 )
    {
      v32 = *(_DWORD *)(a1 + 12);
      v33 = *(_DWORD *)(v17 + 1800);
      v34 = dp_display_state_name(v32);
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
        v33,
        "remove DP_STATE_DISCONNECT_NOTIFIED",
        v32,
        v34);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_send_hpd_notification",
      1014,
      8,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v30,
      v31,
      v72);
    v35 = *(_DWORD *)(a1 + 12);
    if ( (v35 & 0x800) == 0 )
    {
      if ( (*(_BYTE *)(a1 + 1832) & 1) != 0 )
        goto LABEL_15;
      goto LABEL_49;
    }
LABEL_55:
    if ( !g_dp_display || (v58 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v58 = 0;
    v59 = _ReadStatusReg(SP_EL0);
    v60 = *(_DWORD *)(v59 + 1800);
    v61 = dp_display_state_name(v35);
    ipc_log_string(v58, "[d][%-4d]%s: state (0x%x): %s\n", v60, "[TUI is active, skipping wait]", v35, v61);
    if ( (_drm_debug & 4) != 0 )
    {
      v64 = *(_DWORD *)(a1 + 12);
      v65 = *(_DWORD *)(v59 + 1800);
      v66 = dp_display_state_name(v64);
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
        v65,
        "[TUI is active, skipping wait]",
        v64,
        v66);
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_send_hpd_notification",
      1025,
      8,
      *(_DWORD *)(a1 + 12),
      -1059143953,
      v62,
      v63,
      v73);
    goto LABEL_15;
  }
  v36 = g_dp_display;
  v37 = v13 | 0x20;
  *(_DWORD *)(a1 + 12) = v13 | 0x20;
  if ( !v36 || (v38 = *(_QWORD *)(v36 + 56)) == 0 )
    v38 = 0;
  v39 = _ReadStatusReg(SP_EL0);
  v40 = *(_DWORD *)(v39 + 1800);
  v41 = dp_display_state_name(v37);
  ipc_log_string(v38, "[d][%-4d]%s: state (0x%x): %s\n", v40, "add DP_STATE_DISCONNECT_NOTIFIED", v37, v41);
  if ( (_drm_debug & 4) != 0 )
  {
    v44 = *(_DWORD *)(a1 + 12);
    v45 = *(_DWORD *)(v39 + 1800);
    v46 = dp_display_state_name(v44);
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
      v45,
      "add DP_STATE_DISCONNECT_NOTIFIED",
      v44,
      v46);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_send_hpd_notification",
    1016,
    8,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    v42,
    v43,
    v71);
  v47 = g_dp_display;
  v48 = *(_DWORD *)(a1 + 12) & 0xFFFFFFEF;
  *(_DWORD *)(a1 + 12) = v48;
  if ( !v47 || (v49 = *(_QWORD *)(v47 + 56)) == 0 )
    v49 = 0;
  v50 = *(_DWORD *)(v39 + 1800);
  v51 = dp_display_state_name(v48);
  ipc_log_string(v49, "[d][%-4d]%s: state (0x%x): %s\n", v50, "remove DP_STATE_CONNECT_NOTIFIED", v48, v51);
  if ( (_drm_debug & 4) != 0 )
  {
    v54 = *(_DWORD *)(a1 + 12);
    v55 = *(_DWORD *)(v39 + 1800);
    v56 = dp_display_state_name(v54);
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
      v55,
      "remove DP_STATE_CONNECT_NOTIFIED",
      v54,
      v56);
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_send_hpd_notification",
    1017,
    8,
    *(_DWORD *)(a1 + 12),
    -1059143953,
    v52,
    v53,
    v74);
  v35 = *(_DWORD *)(a1 + 12);
  if ( (v35 & 0x800) != 0 )
    goto LABEL_55;
  if ( (*(_BYTE *)(a1 + 1832) & 1) == 0 )
  {
LABEL_49:
    if ( ((v35 >> 6) & 1) != v3 )
      goto LABEL_50;
LABEL_15:
    v10 = 0;
    goto LABEL_16;
  }
LABEL_50:
  if ( wait_for_completion_timeout(a1 + 64, 1000) )
    goto LABEL_15;
  if ( *(_BYTE *)(a1 + 1832) == 1 )
  {
    v57 = *(void (__fastcall **)(__int64, bool))(a1 + 1840);
    if ( *((_DWORD *)v57 - 1) != -538254584 )
      __break(0x8228u);
    v57(a1 + 1168, v7 != 0);
  }
  else
  {
    dp_display_send_hpd_event(a1);
  }
  if ( wait_for_completion_timeout(a1 + 64, 500) )
    goto LABEL_15;
  if ( !g_dp_display || (v67 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v67 = 0;
  v68 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
  if ( (v1 & 8) != 0 )
    v69 = "connect";
  else
    v69 = "disconnect";
  ipc_log_string(v67, "[w][%-4d]%s timeout\n", v68, v69);
  printk(&unk_21164F, "dp_display_send_hpd_notification");
  v10 = -22;
LABEL_16:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_send_hpd_notification",
    1053,
    8,
    8738,
    *(_DWORD *)(a1 + 12),
    v3,
    v10,
    239);
  return v10;
}
