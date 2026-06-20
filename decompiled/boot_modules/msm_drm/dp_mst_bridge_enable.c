__int64 __fastcall dp_mst_bridge_enable(
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
  int v14; // w0
  int v15; // w5
  __int64 (*v16)(void); // x8
  int v17; // w20
  __int64 v18; // x0
  unsigned __int64 StatusReg; // x23
  int v20; // w2
  int v21; // w3
  __int64 v22; // x8
  int v23; // w4
  int v24; // w7
  __int64 v25; // x8
  int v26; // w5
  char v27; // [xsp+0h] [xbp+0h]
  char v28; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_21CA0C;
    return printk(v9, "dp_mst_bridge_enable");
  }
  v10 = *(_QWORD *)(a1 + 1344);
  if ( !v10 )
  {
    v12 = get_ipc_log_context();
    ipc_log_string(v12, "[e][%-4d]Invalid connector\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v9 = &unk_2344C7;
    return printk(v9, "dp_mst_bridge_enable");
  }
  if ( (_drm_debug & 4) == 0 )
  {
    v14 = sde_dbg_base_evtlog;
LABEL_10:
    v15 = *(_DWORD *)(v10 + 64);
    goto LABEL_11;
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  v10 = *(_QWORD *)(a1 + 1344);
  v14 = sde_dbg_base_evtlog;
  v15 = 0;
  if ( v10 )
    goto LABEL_10;
LABEL_11:
  sde_evtlog_log(v14, "dp_mst_bridge_enable", 975, 8, 4369, v15, -1059143953, a8, v27);
  v16 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 408) + 88LL);
  if ( *((_DWORD *)v16 - 1) != -1533774139 )
    __break(0x8228u);
  v17 = v16();
  v18 = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v20 = *(_DWORD *)(StatusReg + 1800);
  v21 = *(_DWORD *)(a1 + 400);
  if ( v17 )
  {
    ipc_log_string(v18, "[e][%-4d]mst bridge [%d] post enable failed, rc=%d\n", v20, v21, v17);
    return printk(&unk_22035E, "dp_mst_bridge_enable");
  }
  else
  {
    v22 = *(_QWORD *)(a1 + 1344);
    if ( v22 )
      v23 = *(_DWORD *)(v22 + 64);
    else
      v23 = 0;
    ipc_log_string(v18, "[i][%-4d]mst bridge:%d conn:%d post enable complete\n", v20, v21, v23);
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_2685CB, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_21CF2A, "dp_mst_bridge_enable");
    v25 = *(_QWORD *)(a1 + 1344);
    if ( v25 )
      v26 = *(_DWORD *)(v25 + 64);
    else
      v26 = 0;
    return sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_bridge_enable", 988, 8, 8738, v26, -1059143953, v24, v28);
  }
}
