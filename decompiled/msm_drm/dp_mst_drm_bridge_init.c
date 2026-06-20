__int64 __fastcall dp_mst_drm_bridge_init(_QWORD *a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v4; // x19
  int v5; // w22
  __int64 v6; // x23
  __int64 v7; // x21
  unsigned int v8; // w0
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x0
  unsigned __int64 v12; // x24
  _DWORD *v13; // x8
  __int64 v14; // x1
  int v15; // w6
  int v16; // w7
  __int64 v18; // x22
  __int64 v19; // x23
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x22
  _DWORD *v22; // x8
  __int64 v23; // x0
  int v24; // w7
  unsigned int v25; // w19
  __int64 v26; // x0
  __int64 ipc_log_context; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v32; // x25
  __int64 v33; // x0
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v2 = a1[5];
  if ( (*(_BYTE *)(v2 + 1740) & 1) != 0 )
  {
    if ( *(_BYTE *)(v2 + 3132) == 1 )
    {
      ipc_log_context = get_ipc_log_context();
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]mst supports only %d bridges\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        2);
      printk(&unk_22DB10, "dp_mst_drm_bridge_init");
      return 4294967283LL;
    }
    v4 = v2 + 2728;
    v5 = 1;
  }
  else
  {
    v5 = 0;
    v4 = v2 + 1336;
  }
  *(_QWORD *)(v4 + 416) = a2;
  *(_BYTE *)(v4 + 404) = 1;
  *(_DWORD *)(v4 + 400) = v5;
  v6 = *a1;
  *(_QWORD *)(v4 + 408) = a1;
  *(_QWORD *)(v4 + 168) = &dp_mst_bridge_ops;
  *(_QWORD *)(v4 + 112) = a2;
  v7 = *(_QWORD *)(v6 + 56);
  v8 = drm_bridge_attach(a2, v4, 0, 0);
  if ( v8 )
  {
    v25 = v8;
    v26 = get_ipc_log_context();
    ipc_log_string(v26, "[e][%-4d]failed to attach bridge, rc=%d\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v25);
    printk(&unk_252DBD, "dp_mst_drm_bridge_init");
    return v25;
  }
  v9 = *(unsigned int *)(v7 + 3928);
  *(_DWORD *)(v7 + 3928) = v9 + 1;
  if ( (unsigned int)v9 > 0xF )
  {
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v32 = *(_QWORD *)(StatusReg + 80);
    v33 = _drm_debug;
    *(_QWORD *)(StatusReg + 80) = &dp_mst_drm_bridge_init__alloc_tag;
    v10 = _kmalloc_cache_noprof(v33, 3520, 40);
    *(_QWORD *)(StatusReg + 80) = v32;
    if ( !v10 )
      return 4294967284LL;
  }
  else
  {
    *(_QWORD *)(v7 + 8 * v9 + 3936) = v4;
    v10 = _kmalloc_cache_noprof(_drm_debug, 3520, 40);
    if ( !v10 )
      return 4294967284LL;
  }
  drm_atomic_private_obj_init(v6, v4 + 296, v10, dp_mst_bridge_state_funcs);
  v11 = get_ipc_log_context();
  v12 = _ReadStatusReg(SP_EL0);
  ipc_log_string(v11, "[d][%-4d]mst drm bridge init. bridge id:%d\n", *(_DWORD *)(v12 + 1800), v5);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst drm bridge init. bridge id:%d\n", *(_DWORD *)(v12 + 1800), v5);
  v13 = (_DWORD *)a1[31];
  v14 = *(unsigned int *)(v4 + 400);
  if ( *(v13 - 1) != 1152305411 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_QWORD *, __int64, __int64))v13)(a1, v14, v4 + 1376) )
    return 0;
  v18 = *(_QWORD *)(v4 + 416);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(v12 + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_drm_fixed_connector_init", 2031, 8, 4369, -1059143953, v15, v16, vars0);
  v19 = *a1;
  v20 = sde_connector_init(*a1, v18, 0, a1, dp_mst_drm_fixed_connector_init_dp_mst_connector_ops, 1, 10, 0);
  if ( !v20 || (v21 = v20, v20 >= 0xFFFFFFFFFFFFF001LL) )
  {
    v28 = get_ipc_log_context();
    ipc_log_string(v28, "[e][%-4d]mst sde_connector_init failed\n", *(_DWORD *)(v12 + 1800));
    printk(&unk_268612, "dp_mst_drm_fixed_connector_init");
LABEL_28:
    *(_QWORD *)(v4 + 1384) = 0;
    v30 = get_ipc_log_context();
    ipc_log_string(v30, "[e][%-4d]failed to create fixed connector\n", *(_DWORD *)(v12 + 1800));
    printk(&unk_2766B2, "dp_mst_drm_bridge_init");
    kfree(v10);
    return 4294967284LL;
  }
  v22 = (_DWORD *)a1[27];
  if ( *(v22 - 1) != 1625136867 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_QWORD *, unsigned __int64))v22)(a1, v20) )
  {
    v29 = get_ipc_log_context();
    ipc_log_string(v29, "[e][%-4d]mst connector install failed\n", *(_DWORD *)(v12 + 1800));
    printk(&unk_2568A7, "dp_mst_drm_fixed_connector_init");
    sde_connector_destroy(v21);
    goto LABEL_28;
  }
  drm_object_attach_property(v21 + 64, *(_QWORD *)(v19 + 1128), 0);
  drm_object_attach_property(v21 + 64, *(_QWORD *)(v19 + 1136), 0);
  v23 = get_ipc_log_context();
  ipc_log_string(v23, "[d][%-4d]add mst fixed connector:%d\n", *(_DWORD *)(v12 + 1800), *(_DWORD *)(v21 + 64));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]add mst fixed connector:%d\n",
      *(_DWORD *)(v12 + 1800),
      *(_DWORD *)(v21 + 64));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_drm_fixed_connector_init",
    2061,
    8,
    8738,
    *(_DWORD *)(v21 + 64),
    -1059143953,
    v24,
    vars0a);
  *(_QWORD *)(v4 + 1384) = v21;
  return 0;
}
