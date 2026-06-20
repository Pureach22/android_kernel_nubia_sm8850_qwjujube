__int64 __fastcall dp_mst_connector_pre_destroy(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  int v8; // w19
  __int64 v11; // x0
  void (__fastcall *v12)(__int64, __int64); // x8
  int v13; // w7
  char v15; // [xsp+0h] [xbp+0h]
  char v16; // [xsp+0h] [xbp+0h]

  v8 = *(_DWORD *)(a1 + 64);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_connector_pre_destroy", 1681, 8, 4369, v8, -1059143953, a8, v15);
  kfree(*(_QWORD *)(a1 + 5008));
  v11 = *(_QWORD *)(a1 + 2776);
  *(_QWORD *)(a1 + 5008) = 0;
  drm_dp_mst_put_port_malloc(v11);
  v12 = *(void (__fastcall **)(__int64, __int64))(a2 + 224);
  if ( *((_DWORD *)v12 - 1) != 1625136867 )
    __break(0x8228u);
  v12(a2, a1);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]exit:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  return sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_connector_pre_destroy", 1690, 8, 8738, v8, -1059143953, v13, v16);
}
