__int64 __fastcall dp_catalog_audio_config_acr(__int64 a1)
{
  int v1; // w22
  __int64 v2; // x20
  unsigned int v4; // w21
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x23
  _DWORD *v7; // x8

  v1 = *(_DWORD *)(a1 + 8);
  v2 = *(_QWORD *)(a1 - 488);
  v4 = (16 * v1) | 0x80004100;
  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(ipc_log_context, "[d][%-4d]select = 0x%x, acr_ctrl = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v1, v4);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]select = 0x%x, acr_ctrl = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v1, v4);
  v7 = *(_DWORD **)(a1 - 384);
  if ( *(v7 - 1) != -626862723 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v7)(a1 - 512, v2, 528, v4);
}
