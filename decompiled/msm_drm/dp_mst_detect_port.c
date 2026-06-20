__int64 __fastcall dp_mst_detect_port(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v4; // w20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22

  if ( *(_BYTE *)(a3 + 4204) == 1 )
    v4 = drm_dp_mst_detect_port(a1, a2, a3);
  else
    v4 = 2;
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[d][%-4d]mst port status: %d, session state: %d\n",
    *(_DWORD *)(StatusReg + 1800),
    v4,
    *(unsigned __int8 *)(a3 + 4204));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst port status: %d, session state: %d\n",
      *(_DWORD *)(StatusReg + 1800),
      v4,
      *(unsigned __int8 *)(a3 + 4204));
  return v4;
}
