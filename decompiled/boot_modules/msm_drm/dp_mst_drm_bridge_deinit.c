__int64 dp_mst_drm_bridge_deinit()
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x19
  __int64 result; // x0

  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  result = ipc_log_string(ipc_log_context, "[d][%-4d]mst bridge deinit\n", *(_DWORD *)(StatusReg + 1800));
  if ( (_drm_debug & 4) != 0 )
    return _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]mst bridge deinit\n", *(_DWORD *)(StatusReg + 1800));
  return result;
}
