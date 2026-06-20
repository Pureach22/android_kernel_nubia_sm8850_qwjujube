__int64 __fastcall dp_display_mst_install(
        __int64 a1,
        _QWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int *v9; // x22
  _QWORD *v11; // x8
  __int64 v12; // x9
  __int64 *v13; // x8
  __int64 v14; // x10
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x8
  __int64 v18; // x0
  unsigned __int64 StatusReg; // x19
  int v20; // w7
  __int64 v22; // x0
  unsigned __int64 v23; // x19
  __int64 v24; // x0
  void *v25; // x0
  __int64 v26; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( !a1 || !a2 )
  {
    if ( !g_dp_display || (v26 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v26 = 0;
    ipc_log_string(v26, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v25 = &unk_275B6D;
    goto LABEL_26;
  }
  v9 = (int *)(a1 - 1156);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_display_mst_install",
    3641,
    8,
    4369,
    *(_DWORD *)(a1 - 1156),
    -1059143953,
    a8,
    vars0);
  v11 = (_QWORD *)a2[1];
  if ( !*v11 || !v11[1] )
  {
    if ( !g_dp_display || (v24 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v24 = 0;
    ipc_log_string(v24, "[e][%-4d]invalid mst cbs\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v25 = &unk_27982A;
LABEL_26:
    printk(v25, "dp_display_mst_install");
    return 4294967274LL;
  }
  v12 = *(_QWORD *)(a1 - 1032);
  *(_QWORD *)(a1 + 40) = *a2;
  if ( (*(_BYTE *)(v12 + 724) & 1) != 0 )
  {
    v13 = (__int64 *)a2[1];
    v14 = v13[3];
    v15 = v13[1];
    v16 = v13[2];
    *(_QWORD *)(a1 + 704) = v13[4];
    *(_QWORD *)(a1 + 696) = v14;
    *(_QWORD *)(a1 + 688) = v16;
    *(_QWORD *)(a1 + 680) = v15;
    v17 = *v13;
    *(_BYTE *)(a1 + 665) = 1;
    *(_QWORD *)(a1 + 672) = v17;
    if ( !g_dp_display || (v18 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v18 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v18, "[d][%-4d]dp mst drm installed\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]dp mst drm installed\n", *(_DWORD *)(StatusReg + 1800));
    sde_evtlog_log(sde_dbg_base_evtlog, "dp_display_mst_install", 3659, 8, 8738, *v9, -1059143953, v20, vars0a);
    return 0;
  }
  else
  {
    if ( !g_dp_display || (v22 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v22 = 0;
    v23 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v22, "[d][%-4d]mst not enabled\n", *(_DWORD *)(v23 + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst not enabled\n", *(_DWORD *)(v23 + 1800));
    return 0xFFFFFFFFLL;
  }
}
