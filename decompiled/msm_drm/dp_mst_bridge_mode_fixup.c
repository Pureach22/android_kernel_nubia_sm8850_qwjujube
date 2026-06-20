__int64 __fastcall dp_mst_bridge_mode_fixup(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w7
  __int64 v7; // x8
  int v8; // w5
  __int64 v9; // x22
  unsigned __int64 private_obj_state; // x0
  __int64 v11; // x1
  unsigned __int64 v12; // x22
  __int64 v13; // x23
  _DWORD *v14; // x8
  void (__fastcall *v15)(__int64, __int64); // x8
  __int64 v16; // x1
  __int64 v17; // x0
  unsigned __int64 StatusReg; // x21
  __int64 result; // x0
  __int64 ipc_log_context; // x0
  void *v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  char v24; // [xsp+0h] [xbp-330h]
  _DWORD s[200]; // [xsp+8h] [xbp-328h] BYREF
  __int64 v26; // [xsp+328h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]enter\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  if ( !a1 || !a2 || !a3 )
  {
    ipc_log_context = get_ipc_log_context();
    ipc_log_string(ipc_log_context, "[e][%-4d]Invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v21 = &unk_21CA0C;
LABEL_24:
    printk(v21, "dp_mst_bridge_mode_fixup");
    result = 0;
    goto LABEL_20;
  }
  v7 = *(_QWORD *)(a1 + 1344);
  if ( v7 )
    v8 = *(_DWORD *)(v7 + 64);
  else
    v8 = 0;
  sde_evtlog_log(sde_dbg_base_evtlog, "dp_mst_bridge_mode_fixup", 463, 8, 4369, v8, -1059143953, v6, v24);
  v9 = *(_QWORD *)(a2 + 184);
  if ( (mutex_is_locked(*(_QWORD *)(a1 + 104) + 480LL) & 1) == 0 )
    __break(0x800u);
  private_obj_state = drm_atomic_get_private_obj_state(v9, a1 + 296);
  if ( private_obj_state >= 0xFFFFFFFFFFFFF001LL )
  {
    v22 = get_ipc_log_context();
    ipc_log_string(v22, "[e][%-4d]invalid bridge state\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v21 = &unk_2191FA;
    goto LABEL_24;
  }
  v11 = *(_QWORD *)(private_obj_state + 24);
  v12 = private_obj_state;
  if ( !v11 )
  {
    v23 = get_ipc_log_context();
    ipc_log_string(v23, "[e][%-4d]Invalid dp_panel\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v21 = &unk_248981;
    goto LABEL_24;
  }
  v13 = *(_QWORD *)(a1 + 408);
  v14 = *(_DWORD **)(v13 + 272);
  if ( *(v14 - 1) != 271107547 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, __int64, _DWORD *))v14)(v13, v11, a2, s);
  v15 = *(void (__fastcall **)(__int64, __int64))(v13 + 304);
  v16 = *(_QWORD *)(v12 + 24);
  if ( *((_DWORD *)v15 - 1) != -250558756 )
    __break(0x8228u);
  v15(v13, v16);
  convert_to_drm_mode(s, a3);
  v17 = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v17,
    "[d][%-4d]mst bridge [%d] mode:%s fixup\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)(a1 + 400),
    (const char *)(a2 + 80));
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mst bridge [%d] mode:%s fixup\n",
      *(_DWORD *)(StatusReg + 1800),
      *(_DWORD *)(a1 + 400),
      (const char *)(a2 + 80));
  result = 1;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
