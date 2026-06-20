__int64 __fastcall dp_mst_init(_QWORD *a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  _DWORD *v4; // x9
  __int64 v5; // x20
  _DWORD *v6; // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0
  __int64 v10; // x0
  void *v11; // x0
  __int64 v12; // x8
  unsigned int v13; // w22
  unsigned int v14; // w0
  _DWORD *v15; // x9
  __int64 v16; // x0
  unsigned __int64 v17; // x19
  unsigned int v18; // w19
  __int64 v19; // x0
  _QWORD v20[3]; // [xsp+8h] [xbp-18h] BYREF

  v20[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v1 = *a1;
    v3 = devm_kmalloc(*(_QWORD *)(*a1 + 8LL), 4240, 3520);
    if ( !v3 )
    {
      result = 4294967284LL;
      goto LABEL_12;
    }
    v4 = (_DWORD *)a1[25];
    v5 = v3;
    v20[0] = v3;
    v20[1] = dp_mst_display_cbs;
    if ( *(v4 - 1) != -1731819938 )
      __break(0x8229u);
    ((void (__fastcall *)(_QWORD *, _QWORD *))v4)(a1, v20);
    v6 = (_DWORD *)a1[32];
    if ( *(v6 - 1) != -1592518158 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v6)(a1, v5 + 8);
    if ( (*(_BYTE *)(v5 + 8) & 1) == 0 )
    {
      ipc_log_context = get_ipc_log_context();
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(ipc_log_context, "[d][%-4d]mst not supported\n", *(_DWORD *)(StatusReg + 1800));
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst not supported\n", *(_DWORD *)(StatusReg + 1800));
      goto LABEL_10;
    }
    *(_QWORD *)(v5 + 4128) = &drm_dp_mst_fw_helper_ops;
    memset((void *)(v5 + 32), 0, 0x518u);
    v12 = a1[2];
    *(_QWORD *)(v5 + 144) = &dp_mst_drm_cbs;
    v13 = *(_DWORD *)(v12 + 64);
    *(_QWORD *)(v5 + 4120) = a1;
    _mutex_init(v5 + 4136, "&dp_mst->mst_lock", &dp_mst_init___key);
    _mutex_init(v5 + 4184, "&dp_mst->edid_lock", &dp_mst_init___key_26);
    v14 = drm_dp_mst_topology_mgr_init(
            v5 + 32,
            v1,
            *(_QWORD *)(v5 + 24),
            *(unsigned int *)(v5 + 16),
            *(unsigned int *)(v5 + 12),
            v13);
    if ( v14 )
    {
      v18 = v14;
      v19 = get_ipc_log_context();
      ipc_log_string(
        v19,
        "[e][%-4d]dp drm mst topology manager init failed\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
      printk(&unk_26FA1D, "dp_mst_init");
      result = v18;
      goto LABEL_12;
    }
    v15 = (_DWORD *)a1[31];
    *(_BYTE *)v5 = 1;
    if ( *(v15 - 1) != 1152305411 )
      __break(0x8229u);
    if ( !((unsigned int (__fastcall *)(_QWORD *, _QWORD, _QWORD))v15)(a1, 0, 0) )
      *(_QWORD *)(v5 + 144) = &dp_mst_fixed_drm_cbs;
    v16 = get_ipc_log_context();
    v17 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v16, "[i][%-4d]dp drm mst topology manager init completed\n", *(_DWORD *)(v17 + 1800));
    if ( (_drm_debug & 4) != 0 )
    {
      printk(&unk_2619CA, *(unsigned int *)(v17 + 1800));
      goto LABEL_10;
    }
    v11 = &unk_223AD3;
  }
  else
  {
    v10 = get_ipc_log_context();
    ipc_log_string(v10, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v11 = &unk_24B695;
  }
  printk(v11, "dp_mst_init");
LABEL_10:
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
