__int64 __fastcall dp_catalog_panel_dhdr_flush(__int64 a1)
{
  __int64 v2; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0

  v2 = dp_catalog_panel_dp_flush(a1, 1);
  ipc_log_context = get_ipc_log_context(v2);
  StatusReg = _ReadStatusReg(SP_EL0);
  result = ipc_log_string(
             ipc_log_context,
             "[d][%-4d]dhdr flush for stream:%d\n",
             *(_DWORD *)(StatusReg + 1800),
             *(_DWORD *)(a1 + 204));
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]dhdr flush for stream:%d\n",
             *(_DWORD *)(StatusReg + 1800),
             *(_DWORD *)(a1 + 204));
  return result;
}
