__int64 __fastcall dp_display_edp_detect(__int64 a1)
{
  char v1; // w29
  __int64 v4; // x20
  unsigned int v5; // w0
  __int64 v6; // x9
  unsigned int v7; // w8
  unsigned int v8; // w0
  __int64 v9; // x26
  void (*v10)(void); // x8
  __int64 (*v11)(void); // x9
  unsigned int v12; // w0
  unsigned int v13; // w25
  int *v14; // x23
  unsigned int v15; // w20
  __int64 v16; // x21
  unsigned __int64 StatusReg; // x24
  int v18; // w22
  const char *v19; // x0
  int v20; // w6
  int v21; // w7
  int v22; // w21
  int v23; // w20
  const char *v24; // x0
  int v25; // w20
  __int64 v26; // x21
  int v27; // w22
  const char *v28; // x0
  int v29; // w6
  int v30; // w7
  int v31; // w21
  int v32; // w20
  const char *v33; // x0
  int v34; // w20
  __int64 v35; // x21
  int v36; // w22
  const char *v37; // x0
  int v38; // w6
  int v39; // w7
  int v40; // w21
  int v41; // w20
  const char *v42; // x0
  void (*v43)(void); // x8
  void (*v44)(void); // x8
  int v45; // w20
  __int64 v46; // x21
  int v47; // w22
  const char *v48; // x0
  int v49; // w6
  int v50; // w7
  int v51; // w21
  int v52; // w20
  const char *v53; // x0
  unsigned int v54; // w20
  __int64 v55; // x21
  int v56; // w22
  const char *v57; // x0
  int v58; // w6
  int v59; // w7
  int v60; // w21
  int v61; // w20
  const char *v62; // x0
  void (*v63)(void); // x8
  __int64 v64; // x0
  __int64 v65; // x21
  int v66; // w22
  int v67; // w23
  const char *v68; // x0
  int v69; // w6
  int v70; // w7
  char v71; // [xsp+0h] [xbp-60h]
  char v72; // [xsp+0h] [xbp-60h]
  char v73; // [xsp+0h] [xbp-60h]
  char v74; // [xsp+0h] [xbp-60h]

  if ( (*(_BYTE *)(a1 + 32) & 1) != 0 )
    return 0;
  v4 = a1 - 1168;
  mutex_lock(a1 + 560);
  v5 = dp_display_host_init(v4);
  if ( v5 )
  {
    v13 = v5;
    if ( !g_dp_display || (v64 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v64 = 0;
    ipc_log_string(v64, "[e][%-4d]Host init Failed", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_21FE95, "dp_display_edp_detect");
  }
  else
  {
    v6 = *(_QWORD *)(a1 - 1040);
    *(_BYTE *)(a1 + 32) = 1;
    *(_BYTE *)(v6 + 8) = 1;
    *(_BYTE *)(*(_QWORD *)(a1 - 1040) + 10LL) = 1;
    v7 = *(_DWORD *)(*(_QWORD *)(a1 - 1032) + 704LL);
    if ( v7 >= *(_DWORD *)(*(_QWORD *)(a1 - 976) + 8LL) )
      v7 = *(_DWORD *)(*(_QWORD *)(a1 - 976) + 8LL);
    *(_DWORD *)(a1 + 36) = v7;
    v8 = dp_display_host_ready(v4);
    if ( v8 )
    {
      v13 = v8;
      if ( !g_dp_display || (v65 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v65 = 0;
      v66 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v67 = *(_DWORD *)(a1 - 1156);
      v68 = dp_display_state_name(v67);
      ipc_log_string(v65, "[e][%-4d]%s: state (0x%x): %s\n", v66, "[ready failed]", v67, v68);
      dp_display_state_name(*(_DWORD *)(a1 - 1156));
      printk(&unk_24548C, "dp_display_edp_detect");
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_display_edp_detect",
        4049,
        8,
        *(_DWORD *)(a1 - 1156),
        -1059143953,
        v69,
        v70,
        v1);
      dp_display_host_deinit(v4);
    }
    else
    {
      v9 = a1 - 992;
      v10 = *(void (**)(void))(*(_QWORD *)(a1 - 1000) + 192LL);
      if ( *((_DWORD *)v10 - 1) != -187382708 )
        __break(0x8228u);
      v10();
      *(_BYTE *)(*(_QWORD *)(a1 - 976) + 1LL) = 0;
      v11 = *(__int64 (**)(void))(*(_QWORD *)v9 + 1032LL);
      if ( *((_DWORD *)v11 - 1) != -571023790 )
        __break(0x8229u);
      v12 = v11();
      if ( v12 == -110 )
      {
        v13 = -110;
      }
      else
      {
        v13 = v12;
        if ( v12 != -107 )
        {
          v14 = (int *)(a1 - 1156);
          v15 = *(_DWORD *)(a1 - 1156) & 0xFFFFFEFF;
          *(_DWORD *)(a1 - 1156) = v15;
          if ( !g_dp_display || (v16 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v16 = 0;
          StatusReg = _ReadStatusReg(SP_EL0);
          v18 = *(_DWORD *)(StatusReg + 1800);
          v19 = dp_display_state_name(v15);
          ipc_log_string(v16, "[d][%-4d]%s: state (0x%x): %s\n", v18, "remove DP_STATE_ABORTED", v15, v19);
          if ( (_drm_debug & 4) != 0 )
          {
            v22 = *v14;
            v23 = *(_DWORD *)(StatusReg + 1800);
            v24 = dp_display_state_name(*v14);
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
              v23,
              "remove DP_STATE_ABORTED",
              v22,
              v24);
          }
          sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_edp_detect", 4063, 8, *v14, -1059143953, v20, v21, v1);
          v25 = *v14 | 1;
          *v14 = v25;
          if ( !g_dp_display || (v26 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v26 = 0;
          v27 = *(_DWORD *)(StatusReg + 1800);
          v28 = dp_display_state_name(v25);
          ipc_log_string(v26, "[d][%-4d]%s: state (0x%x): %s\n", v27, "add DP_STATE_CONFIGURED", v25, v28);
          if ( (_drm_debug & 4) != 0 )
          {
            v31 = *v14;
            v32 = *(_DWORD *)(StatusReg + 1800);
            v33 = dp_display_state_name(*v14);
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
              v32,
              "add DP_STATE_CONFIGURED",
              v31,
              v33);
          }
          sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_edp_detect", 4064, 8, *v14, -1059143953, v29, v30, v71);
          v34 = *v14 | 8;
          *v14 = v34;
          if ( !g_dp_display || (v35 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v35 = 0;
          v36 = *(_DWORD *)(StatusReg + 1800);
          v37 = dp_display_state_name(v34);
          ipc_log_string(v35, "[d][%-4d]%s: state (0x%x): %s\n", v36, "add DP_STATE_CONNECTED", v34, v37);
          if ( (_drm_debug & 4) != 0 )
          {
            v40 = *v14;
            v41 = *(_DWORD *)(StatusReg + 1800);
            v42 = dp_display_state_name(*v14);
            _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v41, "add DP_STATE_CONNECTED", v40, v42);
          }
          sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_edp_detect", 4065, 8, *v14, -1059143953, v38, v39, v72);
          v43 = *(void (**)(void))(*(_QWORD *)(a1 - 1000) + 152LL);
          if ( *((_DWORD *)v43 - 1) != -1720141962 )
            __break(0x8228u);
          v43();
          v44 = *(void (**)(void))(*(_QWORD *)v9 + 1056LL);
          if ( *((_DWORD *)v44 - 1) != -219911483 )
            __break(0x8228u);
          v44();
          v45 = *v14 | 0x10;
          *v14 = v45;
          if ( !g_dp_display || (v46 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v46 = 0;
          v47 = *(_DWORD *)(StatusReg + 1800);
          v48 = dp_display_state_name(v45);
          ipc_log_string(v46, "[d][%-4d]%s: state (0x%x): %s\n", v47, "add DP_STATE_CONNECT_NOTIFIED", v45, v48);
          if ( (_drm_debug & 4) != 0 )
          {
            v51 = *v14;
            v52 = *(_DWORD *)(StatusReg + 1800);
            v53 = dp_display_state_name(*v14);
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
              v52,
              "add DP_STATE_CONNECT_NOTIFIED",
              v51,
              v53);
          }
          sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_edp_detect", 4070, 8, *v14, -1059143953, v49, v50, v73);
          v54 = *v14 & 0xFFFFFFDF;
          *v14 = v54;
          if ( !g_dp_display || (v55 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v55 = 0;
          v56 = *(_DWORD *)(StatusReg + 1800);
          v57 = dp_display_state_name(v54);
          ipc_log_string(v55, "[d][%-4d]%s: state (0x%x): %s\n", v56, "remove DP_STATE_DISCONNECT_NOTIFIED", v54, v57);
          if ( (_drm_debug & 4) != 0 )
          {
            v60 = *v14;
            v61 = *(_DWORD *)(StatusReg + 1800);
            v62 = dp_display_state_name(*v14);
            _drm_dev_dbg(
              0,
              0,
              0,
              "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
              v61,
              "remove DP_STATE_DISCONNECT_NOTIFIED",
              v60,
              v62);
          }
          sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_edp_detect", 4071, 8, *v14, -1059143953, v58, v59, v74);
          v63 = *(void (**)(void))(*(_QWORD *)(a1 - 1024) + 112LL);
          if ( *((_DWORD *)v63 - 1) != -339360380 )
            __break(0x8228u);
          v63();
        }
      }
    }
  }
  mutex_unlock(a1 + 560);
  return v13;
}
