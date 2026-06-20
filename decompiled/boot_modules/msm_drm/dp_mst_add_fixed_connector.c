unsigned __int64 __fastcall dp_mst_add_fixed_connector(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  int v14; // w6
  int v15; // w7
  __int64 *v16; // x23
  __int64 v17; // x20
  unsigned int v18; // w23
  unsigned __int64 v19; // x0
  unsigned __int64 v20; // x22
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  int v23; // w7
  __int64 v24; // x0
  unsigned __int64 v25; // x19
  __int64 v27; // x26
  int fixed_port_num; // w22
  __int64 v29; // x26
  void (__fastcall *v30)(__int64 *, unsigned __int64); // x8
  __int64 v31; // x0
  unsigned __int64 v32; // x23
  int v33; // w3
  int v34; // w5
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_add_fixed_connector", 1941, 8, 4369, -1059143953, a7, a8, vars0);
  v16 = *(__int64 **)(a1 + 4088);
  v17 = *v16;
  if ( (*(_BYTE *)(a2 + 9) & 1) != 0 || *(_QWORD *)(a2 + 40) )
  {
    v18 = 2;
    goto LABEL_6;
  }
  mutex_lock(*(_QWORD *)(a2 + 1632) + 800LL);
  v27 = *(_QWORD *)(a2 + 1632);
  fixed_port_num = dp_mst_find_fixed_port_num(*(_QWORD *)(v27 + 904), a2);
  mutex_unlock(v27 + 800);
  if ( !fixed_port_num )
    goto LABEL_33;
  if ( *(_DWORD *)(a1 + 2680) == fixed_port_num )
  {
    v29 = a1 + 1304;
    goto LABEL_22;
  }
  if ( *(_DWORD *)(a1 + 4072) != fixed_port_num )
  {
LABEL_33:
    if ( *(_QWORD *)(a1 + 2688) )
    {
      if ( *(_QWORD *)(a1 + 4080) )
        v18 = 2;
      else
        v18 = 1;
    }
    else
    {
      v18 = 0;
    }
LABEL_6:
    v19 = dp_mst_add_connector((_QWORD *)a1, a2, v10, v11, v12, v13, v14, v15);
    if ( v19 )
    {
      v20 = v19;
      drm_modeset_lock_all(v17);
      *(_DWORD *)(v20 + 2264) = 0;
      if ( v18 <= 1 )
      {
        drm_connector_attach_encoder(v20, *(_QWORD *)(a1 + 1392LL * v18 + 1720));
        if ( !v18 )
          drm_connector_attach_encoder(v20, *(_QWORD *)(a1 + 3112));
      }
      drm_modeset_unlock_all(v17);
      ipc_log_context = get_ipc_log_context();
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(
        ipc_log_context,
        "[d][%-4d]add mst connector:%d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(v20 + 64));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]add mst connector:%d\n",
          *(_DWORD *)(StatusReg + 1800),
          *(_DWORD *)(v20 + 64));
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dp_mst_add_fixed_connector",
        1980,
        8,
        8738,
        *(_DWORD *)(v20 + 64),
        -1059143953,
        v23,
        vars0a);
    }
    else
    {
      v24 = get_ipc_log_context();
      v25 = _ReadStatusReg(SP_EL0);
      ipc_log_string(v24, "[d][%-4d]failed to add connector\n", *(_DWORD *)(v25 + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]failed to add connector\n", *(_DWORD *)(v25 + 1800));
      return 0;
    }
    return v20;
  }
  v29 = a1 + 2696;
LABEL_22:
  v20 = *(_QWORD *)(v29 + 1384);
  *(_QWORD *)(v20 + 2776) = a2;
  v30 = (void (__fastcall *)(__int64 *, unsigned __int64))v16[30];
  if ( *((_DWORD *)v30 - 1) != 1625136867 )
    __break(0x8228u);
  v30(v16, v20);
  *(_BYTE *)(v29 + 1380) = 1;
  v31 = get_ipc_log_context();
  v32 = _ReadStatusReg(SP_EL0);
  if ( v20 )
    v33 = *(_DWORD *)(v20 + 64);
  else
    v33 = -1;
  ipc_log_string(v31, "[d][%-4d]found fixed connector %d\n", *(_DWORD *)(v32 + 1800), v33);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( v20 )
      v34 = *(_DWORD *)(v20 + 64);
    else
      v34 = -1;
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]found fixed connector %d\n", *(_DWORD *)(v32 + 1800), v34);
  }
  if ( !v20 )
    goto LABEL_33;
  return v20;
}
