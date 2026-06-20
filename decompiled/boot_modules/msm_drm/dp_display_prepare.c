__int64 __fastcall dp_display_prepare(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int *v8; // x26
  int v10; // w21
  unsigned int v11; // w0
  unsigned int v12; // w21
  __int64 v13; // x23
  unsigned __int64 StatusReg; // x27
  int v15; // w24
  const char *v16; // x0
  int v17; // w6
  int v18; // w7
  int v19; // w23
  int v20; // w21
  const char *v21; // x0
  __int64 v22; // x8
  unsigned int v23; // w0
  void (*v24)(void); // x8
  __int64 (*v25)(void); // x9
  unsigned int v26; // w21
  __int64 v27; // x20
  unsigned __int64 v28; // x23
  int v29; // w22
  const char *v30; // x0
  int v31; // w6
  int v32; // w7
  int v33; // w21
  int v34; // w20
  const char *v35; // x0
  int v36; // w0
  int v37; // w4
  int v38; // w2
  __int64 v40; // x0
  void *v41; // x0
  __int64 v42; // x20
  int v43; // w22
  const char *v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x20
  int v48; // w22
  const char *v49; // x0
  __int64 v50; // x20
  int v51; // w23
  int v52; // w22
  const char *v53; // x0
  int v54; // w6
  int v55; // w7
  char v56; // [xsp+0h] [xbp+0h]
  char v57; // [xsp+0h] [xbp+0h]

  if ( !a1 || !a2 )
  {
    if ( !g_dp_display || (v40 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v40 = 0;
    ipc_log_string(v40, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v41 = &unk_275B6D;
    goto LABEL_48;
  }
  if ( !*(_QWORD *)(a2 + 944) )
  {
    if ( !g_dp_display || (v45 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v45 = 0;
    ipc_log_string(v45, "[e][%-4d]invalid connector input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v41 = &unk_22D77C;
LABEL_48:
    printk(v41, "dp_display_prepare");
    return (unsigned int)-22;
  }
  v8 = (int *)(a1 - 1156);
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_prepare", 2601, 8, 4369, *(_DWORD *)(a1 - 1156), -1059143953, a8, v56);
  mutex_lock(a1 + 560);
  v10 = *v8;
  if ( (~*v8 & 0x401) == 0 )
  {
    v11 = dp_display_host_init(a1 - 1168);
    if ( v11 )
    {
      v26 = v11;
      if ( !g_dp_display || (v46 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v46 = 0;
      ipc_log_string(v46, "[e][%-4d]Host init failed.\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_23E882, "dp_display_prepare");
      goto LABEL_34;
    }
    v12 = *v8 & 0xFFFFFBFF;
    *v8 = v12;
    if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v13 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    v15 = *(_DWORD *)(StatusReg + 1800);
    v16 = dp_display_state_name(v12);
    ipc_log_string(v13, "[d][%-4d]%s: state (0x%x): %s\n", v15, "remove DP_STATE_SRC_PWRDN", v12, v16);
    if ( (_drm_debug & 4) != 0 )
    {
      v19 = *v8;
      v20 = *(_DWORD *)(StatusReg + 1800);
      v21 = dp_display_state_name(*v8);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v20, "remove DP_STATE_SRC_PWRDN", v19, v21);
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_prepare", 2631, 8, *v8, -1059143953, v17, v18, v57);
    v10 = *v8;
  }
  if ( (v10 & 0x100) != 0 )
  {
    if ( !g_dp_display || (v27 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v27 = 0;
    v28 = _ReadStatusReg(SP_EL0);
    v29 = *(_DWORD *)(v28 + 1800);
    v30 = dp_display_state_name(v10);
    ipc_log_string(v27, "[d][%-4d]%s: state (0x%x): %s\n", v29, "[aborted]", v10, v30);
    if ( (_drm_debug & 4) != 0 )
    {
      v33 = *v8;
      v34 = *(_DWORD *)(v28 + 1800);
      v35 = dp_display_state_name(*v8);
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v34, "[aborted]", v33, v35);
    }
    v36 = sde_dbg_base_evtlog;
    v37 = *v8;
    v38 = 2640;
  }
  else if ( (v10 & 0x40) != 0 )
  {
    if ( !g_dp_display || (v47 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v47 = 0;
    v48 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    v49 = dp_display_state_name(v10);
    ipc_log_string(v47, "[w][%-4d]%s: state (0x%x): %s\n", v48, "[already enabled]", v10, v49);
    dp_display_state_name(*v8);
    printk(&unk_245441, "dp_display_prepare");
    v36 = sde_dbg_base_evtlog;
    v37 = *v8;
    v38 = 2649;
  }
  else
  {
    if ( (v10 & 8) != 0 )
    {
      v22 = *(_QWORD *)(a1 - 1040);
      if ( (*(_BYTE *)(v22 + 8) & 1) != 0
        && ((*(_BYTE *)(*(_QWORD *)(a1 - 992) + 5LL) & 1) == 0 || *(_DWORD *)(*(_QWORD *)(a1 - 1000) + 8LL))
        && (*(_BYTE *)(v22 + 10) & 1) != 0 )
      {
        v23 = dp_display_host_ready(a1 - 1168);
        if ( v23 )
        {
          v26 = v23;
          if ( !g_dp_display || (v50 = *(_QWORD *)(g_dp_display + 56)) == 0 )
            v50 = 0;
          v51 = *v8;
          v52 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
          v53 = dp_display_state_name(v51);
          ipc_log_string(v50, "[e][%-4d]%s: state (0x%x): %s\n", v52, "[ready failed]", v51, v53);
          dp_display_state_name(*v8);
          printk(&unk_24548C, "dp_display_prepare");
          sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_prepare", 2661, 8, *v8, -1059143953, v54, v55, v57);
        }
        else
        {
          if ( *(_BYTE *)(*(_QWORD *)(a1 - 976) + 1LL) == 1 )
          {
            v24 = *(void (**)(void))(*(_QWORD *)(a1 - 1000) + 192LL);
            if ( *((_DWORD *)v24 - 1) != -187382708 )
              __break(0x8228u);
            v24();
            *(_BYTE *)(*(_QWORD *)(a1 - 976) + 1LL) = 0;
          }
          v25 = *(__int64 (**)(void))(*(_QWORD *)(a1 - 984) + 16LL);
          if ( *((_DWORD *)v25 - 1) != -849684263 )
            __break(0x8229u);
          v26 = v25();
        }
        goto LABEL_34;
      }
    }
    if ( !g_dp_display || (v42 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v42 = 0;
    v43 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
    v44 = dp_display_state_name(v10);
    ipc_log_string(v42, "[e][%-4d]%s: state (0x%x): %s\n", v43, "[not ready]", v10, v44);
    dp_display_state_name(*v8);
    printk(&unk_24548C, "dp_display_prepare");
    v36 = sde_dbg_base_evtlog;
    v37 = *v8;
    v38 = 2654;
  }
  sde_evtlog_log(v36, "dp_display_prepare", v38, 8, v37, -1059143953, v31, v32, v57);
  v26 = 0;
LABEL_34:
  mutex_unlock(a1 + 560);
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_prepare", 2694, 8, 8738, *v8, v26, -1059143953, v57);
  return v26;
}
