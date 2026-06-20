__int64 __fastcall dp_bridge_attach(__int64 a1)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  int v4; // w2

  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = *(_DWORD *)(StatusReg + 1800);
  if ( a1 )
  {
    ipc_log_string(ipc_log_context, "[d][%-4d][%d] attached\n", v4, *(_DWORD *)(a1 + 296));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d][%d] attached\n", *(_DWORD *)(StatusReg + 1800), *(_DWORD *)(a1 + 296));
    return 0;
  }
  else
  {
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", v4);
    printk(&unk_21CA0C, "dp_bridge_attach");
    return 4294967274LL;
  }
}
