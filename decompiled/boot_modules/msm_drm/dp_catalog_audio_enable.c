__int64 __fastcall dp_catalog_audio_enable(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x20
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  int v5; // w22
  __int64 v6; // x0
  __int64 v7; // x0
  unsigned int v8; // w22
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x23
  _DWORD *v11; // x8
  __int64 result; // x0

  v1 = a1 - 512;
  v2 = *(_QWORD *)(a1 - 488);
  v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 392);
  v5 = *(_DWORD *)(a1 + 8);
  v6 = a1 - 512;
  if ( *((_DWORD *)v3 - 1) != -1879227436 )
    __break(0x8228u);
  v7 = v3(v6, v2, 512);
  if ( v5 )
    v8 = (v7 & 0xFFFFFFFE) + 1;
  else
    v8 = v7 & 0xFFFFFFFE;
  ipc_log_context = get_ipc_log_context(v7);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(ipc_log_context, "[d][%-4d]dp_audio_cfg = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v8);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]dp_audio_cfg = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v8);
  v11 = *(_DWORD **)(a1 - 384);
  if ( *(v11 - 1) != -626862723 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v11)(v1, v2, 512, v8);
  __dsb(0xEu);
  return result;
}
