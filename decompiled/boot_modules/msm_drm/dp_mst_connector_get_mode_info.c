__int64 __fastcall dp_mst_connector_get_mode_info(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        _DWORD *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v13; // w7
  unsigned int mode_info; // w20
  char v16; // [xsp+0h] [xbp+0h]
  char v17; // [xsp+0h] [xbp+0h]

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_get_mode_info",
    1429,
    8,
    4369,
    *(_DWORD *)(a1 + 64),
    -1059143953,
    a8,
    v16);
  mode_info = dp_connector_get_mode_info(a1, a2, 0, a4, a5, a6);
  if ( (_drm_debug & 4) != 0 )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst connector:%d get mode info. rc:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 64),
      mode_info);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]exit:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_get_mode_info",
    1438,
    8,
    8738,
    *(_DWORD *)(a1 + 64),
    -1059143953,
    v13,
    v17);
  return mode_info;
}
