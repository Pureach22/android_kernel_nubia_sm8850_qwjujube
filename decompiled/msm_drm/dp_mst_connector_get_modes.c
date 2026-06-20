__int64 __fastcall dp_mst_connector_get_modes(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x24
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 (__fastcall *v13)(__int64, __int64, __int64); // x8
  __int64 v14; // x0
  __int64 ipc_log_context; // x0
  __int64 v16; // x21
  unsigned __int64 v17; // x21
  __int64 v18; // x0
  unsigned __int64 StatusReg; // x20
  int v20; // w20
  __int64 (__fastcall *v21)(__int64, __int64, unsigned __int64); // x8
  __int64 v22; // x0
  unsigned __int64 v23; // x21
  int v24; // w2
  int v25; // w3
  _DWORD *v26; // x0
  _DWORD *v27; // x20
  char v29; // [xsp+0h] [xbp+0h]
  char v30; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a2 + 40);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter:\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_get_modes",
    1289,
    8,
    4369,
    *(_DWORD *)(a1 + 64),
    -1059143953,
    a8,
    v29);
  mutex_lock(v8 + 4184);
  v11 = *(_QWORD *)(a1 + 5008);
  if ( !v11 )
  {
    mutex_unlock(v8 + 4184);
    v12 = *(_QWORD *)(a1 + 2776);
    v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(v8 + 4128) + 80LL);
    if ( *((_DWORD *)v13 - 1) != -1953959394 )
      __break(0x8228u);
    v14 = v13(a1, v8 + 32, v12);
    if ( !v14 )
    {
      ipc_log_context = get_ipc_log_context();
      ipc_log_string(
        ipc_log_context,
        "[w][%-4d]get edid failed. id: %d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(a1 + 64));
      printk(&unk_25A380, "dp_mst_connector_get_modes");
LABEL_12:
      v20 = 0;
      goto LABEL_16;
    }
    v16 = v14;
    mutex_lock(v8 + 4184);
    v11 = v16;
    *(_QWORD *)(a1 + 5008) = v16;
  }
  v17 = drm_edid_duplicate(v11);
  mutex_unlock(v8 + 4184);
  if ( v17 >= 0xFFFFFFFFFFFFF001LL )
  {
    v18 = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      v18,
      "[d][%-4d]edid duplication failed. id: %d\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 64));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dp-debug][%-4d]edid duplication failed. id: %d\n",
        *(_DWORD *)(StatusReg + 1800),
        *(_DWORD *)(a1 + 64));
    goto LABEL_12;
  }
  v21 = *(__int64 (__fastcall **)(__int64, __int64, unsigned __int64))(a2 + 232);
  if ( *((_DWORD *)v21 - 1) != -101845794 )
    __break(0x8228u);
  v20 = v21(a2, a1, v17);
LABEL_16:
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dp_mst_connector_get_modes",
    1325,
    8,
    8738,
    *(_DWORD *)(a1 + 64),
    v20,
    -1059143953,
    v30);
  v22 = get_ipc_log_context();
  v23 = _ReadStatusReg(SP_EL0);
  v24 = *(_DWORD *)(v23 + 1800);
  v25 = *(_DWORD *)(a1 + 64);
  if ( v20 > 0 )
  {
    ipc_log_string(v22, "[i][%-4d]conn:%d has %d modes\n", v24, v25, v20);
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_242560, *(unsigned int *)(v23 + 1800));
    else
      printk(&unk_245C14, "dp_mst_connector_get_modes");
  }
  else
  {
    ipc_log_string(v22, "[w][%-4d]conn:%d has no modes, adding failsafe. rc=%d\n", v24, v25, v20);
    printk(&unk_27CE7A, "dp_mst_connector_get_modes");
    v26 = (_DWORD *)_kmalloc_cache_noprof(_wake_up, 3520, 800);
    if ( v26 )
    {
      v27 = v26;
      init_failsafe_mode(v26);
      return (unsigned int)dp_connector_add_custom_mode(a1, v27);
    }
    else
    {
      return 0;
    }
  }
  return (unsigned int)v20;
}
