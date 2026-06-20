__int64 __fastcall dp_mst_bridge_post_disable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 ipc_log_context; // x0
  void *v9; // x0
  __int64 v10; // x8
  __int64 v12; // x0
  int v14; // w19
  __int64 v15; // x21
  __int64 v16; // x1
  __int64 (__fastcall *v17)(__int64, __int64); // x8
  int v18; // w0
  int v19; // w22
  __int64 v20; // x0
  unsigned __int64 StatusReg; // x25
  __int64 (__fastcall *v22)(__int64, __int64); // x8
  __int64 v23; // x1
  int v24; // w0
  int v25; // w21
  __int64 v26; // x0
  unsigned __int64 v27; // x25
  __int64 v28; // x0
  unsigned __int64 v29; // x21
  int v30; // w7
  char v31; // [xsp+0h] [xbp+0h]
  char v32; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_21CA0C;
    return printk(v9, "dp_mst_bridge_post_disable");
  }
  v10 = *(_QWORD *)(a1 + 1344);
  if ( !v10 )
  {
    v12 = get_ipc_log_context();
    ipc_log_string(v12, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_2344C7;
    return printk(v9, "dp_mst_bridge_post_disable");
  }
  v14 = *(_DWORD *)(v10 + 64);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_bridge_post_disable", 1056, 8, 4369, v14, -1059143953, a8, v31);
  v15 = *(_QWORD *)(a1 + 408);
  v16 = *(_QWORD *)(a1 + 1352);
  v17 = *(__int64 (__fastcall **)(__int64, __int64))(v15 + 104);
  if ( *((_DWORD *)v17 - 1) != -1533774139 )
    __break(0x8228u);
  v18 = v17(v15, v16);
  if ( v18 )
  {
    v19 = v18;
    v20 = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v20,
      "[i][%-4d]bridge:%d conn:%d display disable failed, rc=%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 400),
      v14,
      v19);
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_26857F, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_2766F0, "dp_mst_bridge_post_disable");
  }
  v22 = *(__int64 (__fastcall **)(__int64, __int64))(v15 + 144);
  v23 = *(_QWORD *)(a1 + 1352);
  if ( *((_DWORD *)v22 - 1) != -1533774139 )
    __break(0x8228u);
  v24 = v22(v15, v23);
  if ( v24 )
  {
    v25 = v24;
    v26 = get_ipc_log_context();
    v27 = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v26,
      "[i][%-4d]bridge:%d conn:%d display unprepare failed, rc=%d\n",
      *(_DWORD *)(v27 + 1800),
      *(_DWORD *)(a1 + 400),
      v14,
      v25);
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_23ECB2, *(unsigned int *)(v27 + 1800));
    else
      printk(&unk_226CFD, "dp_mst_bridge_post_disable");
  }
  *(_QWORD *)(a1 + 1344) = 0;
  *(_QWORD *)(a1 + 1352) = 0;
  v28 = get_ipc_log_context();
  v29 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v28,
    "[i][%-4d]mst bridge:%d conn:%d post disable complete\n",
    *(_DWORD *)(v29 + 1800),
    *(_DWORD *)(a1 + 400),
    v14);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_23ED00, *(unsigned int *)(v29 + 1800));
  else
    printk(&unk_27315E, "dp_mst_bridge_post_disable");
  return sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_bridge_post_disable", 1076, 8, 8738, v14, -1059143953, v30, v32);
}
