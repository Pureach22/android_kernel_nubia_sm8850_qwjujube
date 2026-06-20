__int64 __fastcall dp_display_post_enable(
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
  int v11; // w21
  __int64 v12; // x8
  void (__fastcall *v13)(_QWORD); // x8
  _DWORD *v14; // x8
  unsigned int (*v15)(void); // x8
  void (*v16)(void); // x8
  __int64 v17; // x0
  unsigned __int64 v18; // x20
  __int64 v19; // x20
  unsigned __int64 StatusReg; // x23
  int v21; // w22
  const char *v22; // x0
  int v23; // w6
  int v24; // w7
  int v25; // w21
  int v26; // w20
  const char *v27; // x0
  int v28; // w0
  int v29; // w4
  int v30; // w2
  int v31; // w7
  __int64 v33; // x20
  int v34; // w22
  const char *v35; // x0
  __int64 v36; // x0
  __int64 v37; // x20
  int v38; // w22
  const char *v39; // x0
  __int64 v40; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( a1 && a2 )
  {
    v9 = (int *)(a1 - 1156);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dp_display_post_enable",
      2828,
      8,
      4369,
      *(_DWORD *)(a1 - 1156),
      -1059143953,
      a8,
      vars0);
    mutex_lock(a1 + 560);
    v11 = *v9;
    if ( (*v9 & 0x40) != 0 )
    {
      if ( (v11 & 0x100) != 0 )
      {
        if ( !g_dp_display || (v19 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v19 = 0;
        StatusReg = _ReadStatusReg(SP_EL0);
        v21 = *(_DWORD *)(StatusReg + 1800);
        v22 = dp_display_state_name(v11);
        ipc_log_string(v19, "[d][%-4d]%s: state (0x%x): %s\n", v21, "[aborted]", v11, v22);
        if ( (_drm_debug & 4) != 0 )
        {
          v25 = *v9;
          v26 = *(_DWORD *)(StatusReg + 1800);
          v27 = dp_display_state_name(*v9);
          _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]%s: state (0x%x): %s\n", v26, "[aborted]", v25, v27);
        }
        v28 = sde_dbg_base_evtlog;
        v29 = *v9;
        v30 = 2846;
      }
      else
      {
        if ( (v11 & 8) != 0 )
        {
          v12 = *(_QWORD *)(a1 - 1040);
          if ( (*(_BYTE *)(v12 + 8) & 1) != 0
            && ((*(_BYTE *)(*(_QWORD *)(a1 - 992) + 5LL) & 1) == 0 || *(_DWORD *)(*(_QWORD *)(a1 - 1000) + 8LL))
            && (v11 & 4) != 0
            && (*(_BYTE *)(v12 + 10) & 1) != 0 )
          {
            v13 = *(void (__fastcall **)(_QWORD))(a2 + 1088);
            if ( *((_DWORD *)v13 - 1) != -362183607 )
              __break(0x8228u);
            v13(a2);
            v14 = *(_DWORD **)(a2 + 1064);
            if ( *(v14 - 1) != 335021814 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, __int64))v14)(a2, 0, 0, 0, 1);
            if ( *(_BYTE *)(a1 + 34) == 1 && (*(_BYTE *)(a1 + 72) & 1) == 0 )
            {
              v15 = *(unsigned int (**)(void))(*(_QWORD *)(a1 - 1024) + 112LL);
              if ( *((_DWORD *)v15 - 1) != -339360380 )
                __break(0x8228u);
              if ( v15() )
              {
                if ( !g_dp_display || (v40 = *(_QWORD *)(g_dp_display + 56)) == 0 )
                  v40 = 0;
                ipc_log_string(
                  v40,
                  "[e][%-4d]Cannot turn edp backlight power on",
                  *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
                printk(&unk_22D708, "dp_display_post_enable");
              }
            }
            cancel_delayed_work_sync(a1 + 360);
            queue_delayed_work_on(32, *(_QWORD *)(a1 + 352), a1 + 360, 250);
            if ( *(_BYTE *)(a2 + 960) == 1 )
            {
              *(_DWORD *)(*(_QWORD *)(a2 + 952) + 4LL) = *(_DWORD *)(*(_QWORD *)(a1 - 1000) + 132LL);
              **(_DWORD **)(a2 + 952) = *(_DWORD *)(*(_QWORD *)(a1 - 1000) + 128LL);
              v16 = *(void (**)(void))(*(_QWORD *)(a2 + 952) + 16LL);
              if ( *((_DWORD *)v16 - 1) != -1116566212 )
                __break(0x8228u);
              v16();
            }
            **(_DWORD **)(a1 - 1008) &= ~0x100u;
            **(_DWORD **)(a1 - 1008) |= 0x80u;
            complete_all(a1 - 1104);
            if ( !g_dp_display || (v17 = *(_QWORD *)(g_dp_display + 56)) == 0 )
              v17 = 0;
            v18 = _ReadStatusReg(SP_EL0);
            ipc_log_string(v17, "[d][%-4d]display post enable complete. state: 0x%x\n", *(_DWORD *)(v18 + 1800), *v9);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(
                0,
                0,
                0,
                "[msm-dp-debug][%-4d]display post enable complete. state: 0x%x\n",
                *(_DWORD *)(v18 + 1800),
                *v9);
            goto LABEL_36;
          }
        }
        if ( !g_dp_display || (v33 = *(_QWORD *)(g_dp_display + 56)) == 0 )
          v33 = 0;
        v34 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
        v35 = dp_display_state_name(v11);
        ipc_log_string(v33, "[e][%-4d]%s: state (0x%x): %s\n", v34, "[not ready]", v11, v35);
        dp_display_state_name(*v9);
        printk(&unk_24548C, "dp_display_post_enable");
        v28 = sde_dbg_base_evtlog;
        v29 = *v9;
        v30 = 2851;
      }
    }
    else
    {
      if ( !g_dp_display || (v37 = *(_QWORD *)(g_dp_display + 56)) == 0 )
        v37 = 0;
      v38 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v39 = dp_display_state_name(v11);
      ipc_log_string(v37, "[e][%-4d]%s: state (0x%x): %s\n", v38, "[not enabled]", v11, v39);
      dp_display_state_name(*v9);
      printk(&unk_24548C, "dp_display_post_enable");
      v28 = sde_dbg_base_evtlog;
      v29 = *v9;
      v30 = 2836;
    }
    sde_evtlog_log(v28, "dp_display_post_enable", v30, 8, v29, -1059143953, v23, v24, vars0a);
LABEL_36:
    mutex_unlock(a1 + 560);
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_post_enable", 2878, 8, 8738, *v9, -1059143953, v31, vars0a);
    return 0;
  }
  if ( !g_dp_display || (v36 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v36 = 0;
  ipc_log_string(v36, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_275B6D, "dp_display_post_enable");
  return 4294967274LL;
}
