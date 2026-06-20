__int64 __fastcall dp_mst_bridge_attach(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  int v11; // w2
  char v13; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_bridge_attach", 429, 8, 4369, -1059143953, a7, a8, v13);
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v11 = *(_DWORD *)(StatusReg + 1800);
  if ( a1 )
  {
    ipc_log_string(ipc_log_context, "[d][%-4d]mst bridge [%d] attached\n", v11, *(_DWORD *)(a1 + 400));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]mst bridge [%d] attached\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(a1 + 400));
    return 0;
  }
  else
  {
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", v11);
    printk(&unk_21CA0C, "dp_mst_bridge_attach");
    return 4294967274LL;
  }
}
