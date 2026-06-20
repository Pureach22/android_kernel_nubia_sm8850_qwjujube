__int64 __fastcall dp_display_disable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int *v9; // x25
  __int64 v11; // x23
  int v12; // w21
  __int64 v13; // x0
  unsigned int (*v14)(void); // x8
  __int64 (*v15)(void); // x8
  int v16; // w8
  unsigned int v17; // w20
  __int64 v18; // x21
  unsigned __int64 StatusReg; // x26
  int v20; // w22
  const char *v21; // x0
  int v22; // w6
  int v23; // w7
  int v24; // w21
  int v25; // w20
  const char *v26; // x0
  __int64 v27; // x0
  __int64 v29; // x20
  int v30; // w22
  const char *v31; // x0
  int v32; // w6
  int v33; // w7
  int v34; // w0
  int v35; // w4
  int v36; // w2
  __int64 v37; // x20
  int v38; // w22
  const char *v39; // x0
  int v40; // w7
  __int64 v41; // x0
  __int64 v42; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]
  char vars0b; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 )
  {
    v9 = (int *)(a1 - 1156);
    v11 = *(_QWORD *)(a1 - 1000);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_disable",
      2987,
      8,
      4369,
      *(_DWORD *)(a1 - 1156),
      -1059143953,
      a8,
      vars0);
    mutex_lock(a1 + 560);
    v12 = *v9;
    if ( (*v9 & 0x40) != 0 )
    {
      if ( (v12 & 4) != 0 )
      {
        v13 = a1 - 1168;
        if ( *(_BYTE *)(a1 + 34) == 1 && (*(_BYTE *)(a1 + 72) & 1) == 0 )
        {
          v14 = *(unsigned int (**)(void))(*(_QWORD *)(a1 - 1024) + 112LL);
          if ( *((_DWORD *)v14 - 1) != -339360380 )
            __break(0x8228u);
          if ( v14() )
          {
            if ( !g_dp_display || (v41 = *(_QWORD *)(g_dp_display + 56)) == 0 )
              v41 = 0;
            ipc_log_string(
              v41,
              "[e][%-4d]Cannot turn edp backlight power off\n",
              *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_21C8A8, "dp_display_disable");
          }
          v15 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 1024) + 112LL);
          if ( *((_DWORD *)v15 - 1) != -339360380 )
            __break(0x8228u);
          v16 = v15();
          v13 = a1 - 1168;
          if ( v16 )
          {
            if ( !g_dp_display || (v42 = *(_QWORD *)(g_dp_display + 56)) == 0 )
              v42 = 0;
            ipc_log_string(v42, "[e][%-4d]Cannot turn edp PWM off\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
            printk(&unk_22D747, "dp_display_disable");
            v13 = a1 - 1168;
          }
        }
        dp_display_stream_disable(v13, a2);
        v17 = *v9 & 0xFFFFFDFF;
        *v9 = v17;
        if ( !g_dp_display || (v18 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v18 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        v20 = *(_DWORD *)(StatusReg + 1800);
        v21 = dp_display_state_name(v17);
        ipc_log_string(v18, "[d][%-4d]%s: state (0x%x): %s\n", v20, "remove DP_STATE_HDCP_ABORTED", v17, v21);
        if ( (_drm_debug & 4) != 0 )
        {
          v24 = *v9;
          v25 = *(_DWORD *)(StatusReg + 1800);
          v26 = dp_display_state_name(*v9);
          _drm_dev_dbg(
            0,
            0,
            0,
            "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n",
            v25,
            "remove DP_STATE_HDCP_ABORTED",
            v24,
            v26);
        }
        sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_disable", 3012, 8, *v9, -1059143953, v22, v23, vars0a);
        if ( (*(_QWORD *)(a1 - 960) || *(_QWORD *)(a1 - 952)) && *(_DWORD *)(v11 + 136) != 2 )
          queue_delayed_work_on(32, *(_QWORD *)(a1 + 352), a1 + 360, 62);
        goto LABEL_35;
      }
      if ( !g_dp_display || (v37 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v37 = 0;
      v38 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v39 = dp_display_state_name(v12);
      ipc_log_string(v37, "[e][%-4d]%s: state (0x%x): %s\n", v38, "[not ready]", v12, v39);
      dp_display_state_name(*v9);
      printk(&unk_24548C, "dp_display_disable");
      v34 = sde_dbg_base_evtlog;
      v35 = *v9;
      v36 = 2996;
    }
    else
    {
      if ( !g_dp_display || (v29 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v29 = 0;
      v30 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v31 = dp_display_state_name(v12);
      ipc_log_string(v29, "[e][%-4d]%s: state (0x%x): %s\n", v30, "[not enabled]", v12, v31);
      dp_display_state_name(*v9);
      printk(&unk_24548C, "dp_display_disable");
      v34 = sde_dbg_base_evtlog;
      v35 = *v9;
      v36 = 2991;
    }
    sde_evtlog_log(v34, "dp_display_disable", v36, 8, v35, -1059143953, v32, v33, vars0a);
LABEL_35:
    mutex_unlock(a1 + 560);
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_disable", 3023, 8, 8738, *v9, -1059143953, v40, vars0b);
    return 0;
  }
  if ( !g_dp_display || (v27 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v27 = 0;
  ipc_log_string(v27, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_275B6D, "dp_display_disable");
  return 4294967274LL;
}
