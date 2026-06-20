unsigned __int64 __fastcall dp_mst_add_connector(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  _QWORD *v10; // x23
  __int64 v11; // x20
  unsigned __int64 v12; // x0
  unsigned __int64 v13; // x19
  _DWORD *v14; // x8
  void (__fastcall *v15)(_QWORD); // x8
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x20
  int v18; // w7
  __int64 ipc_log_context; // x0
  __int64 v20; // x0
  char v22; // [xsp+0h] [xbp+0h]
  char v23; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_add_connector", 1736, 8, 4369, -1059143953, a7, a8, v22);
  v10 = (_QWORD *)a1[511];
  v11 = *v10;
  drm_modeset_lock_all(*v10);
  v12 = sde_connector_init(v11, a1[215], 0, v10, &dp_mst_add_connector_dp_mst_connector_ops, 1, 10, 0);
  if ( !v12 || (v13 = v12, v12 >= 0xFFFFFFFFFFFFF001LL) )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]mst sde_connector_init failed\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_268612, "dp_mst_add_connector");
LABEL_16:
    drm_modeset_unlock_all(v11);
    return 0;
  }
  v14 = (_DWORD *)v10[27];
  if ( *(v14 - 1) != 1625136867 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_QWORD *, unsigned __int64))v14)(v10, v12) )
  {
    v20 = get_ipc_log_context();
    ipc_log_string(v20, "[e][%-4d]mst connector install failed\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_2568A7, "dp_mst_add_connector");
    sde_connector_destroy(v13);
    goto LABEL_16;
  }
  *(_QWORD *)(v13 + 2776) = a2;
  drm_dp_mst_get_port_malloc(a2);
  v15 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v13 + 416) + 8LL);
  if ( v15 )
  {
    if ( *((_DWORD *)v15 - 1) != -767843333 )
      __break(0x8228u);
    v15(v13);
  }
  drm_connector_attach_encoder(v13, a1[389]);
  drm_object_attach_property(v13 + 64, *(_QWORD *)(v11 + 1128), 0);
  drm_object_attach_property(v13 + 64, *(_QWORD *)(v11 + 1136), 0);
  drm_modeset_unlock_all(v11);
  v16 = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v16, "[i][%-4d]add mst connector id:%d\n", *(_DWORD *)(StatusReg + 1800), *(_DWORD *)(v13 + 64));
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_27CF1F, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_23477E, "dp_mst_add_connector");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_add_connector",
    1789,
    8,
    4369,
    *(_DWORD *)(v13 + 64),
    -1059143953,
    v18,
    v23);
  return v13;
}
