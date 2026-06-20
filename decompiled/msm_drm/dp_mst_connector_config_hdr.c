__int64 __fastcall dp_mst_connector_config_hdr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  unsigned int v11; // w20
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  char v15; // [xsp+0h] [xbp+0h]
  char v16; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_config_hdr",
    1660,
    8,
    4369,
    *(_DWORD *)(a1 + 64),
    -1059143953,
    a8,
    v15);
  v11 = dp_connector_config_hdr(a1, a2, a3);
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[d][%-4d]mst connector:%d cfg hdr. rc:%d\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)(a1 + 64),
    v11);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst connector:%d cfg hdr. rc:%d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 64),
      v11);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]exit:\n", *(_DWORD *)(StatusReg + 1800));
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_config_hdr",
    1668,
    8,
    8738,
    *(_DWORD *)(a1 + 64),
    v11,
    -1059143953,
    v16);
  return v11;
}
