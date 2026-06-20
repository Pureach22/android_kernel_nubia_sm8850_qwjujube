__int64 __fastcall dp_mst_connector_detect(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v10; // x21
  __int64 v12; // x3
  __int64 (__fastcall *v13)(__int64, __int64, __int64, __int64); // x8
  unsigned int v14; // w21
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x24
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v10 = *(_QWORD *)(*(_QWORD *)(a1 + 2760) + 40LL);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_connector_detect", 1227, 8, 4369, -1059143953, a7, a8, vars0);
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 2768) + 980LL) & 1) != 0 )
    return 2;
  v12 = *(_QWORD *)(a1 + 2776);
  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)(v10 + 4128) + 72LL);
  if ( *((_DWORD *)v13 - 1) != -1710947264 )
    __break(0x8228u);
  v14 = v13(a1, a2, v10 + 32, v12);
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[i][%-4d]conn:%d status:%d\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)(a1 + 64),
    v14);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_253170, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_26522D, "dp_mst_connector_detect");
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_detect",
    1238,
    8,
    8738,
    *(_DWORD *)(a1 + 64),
    v14,
    -1059143953,
    vars0a);
  return v14;
}
