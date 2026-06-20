__int64 __fastcall dp_catalog_audio_config_sdp(__int64 result)
{
  unsigned int v1; // w8
  __int64 v2; // x21
  bool v3; // zf
  _DWORD **v4; // x25
  __int64 v5; // x19
  _DWORD *v6; // x8
  int v7; // w23
  __int64 v8; // x20
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x0
  int v12; // w22
  __int64 v13; // x0
  unsigned __int64 StatusReg; // x24
  _DWORD **v15; // x27
  _DWORD *v16; // x8
  _DWORD *v17; // x8
  __int64 v18; // x0
  int v19; // w21
  __int64 v20; // x0
  _DWORD *v21; // x8
  __int64 ipc_log_context; // x0

  if ( result )
  {
    v1 = *(_DWORD *)(result + 12);
    v2 = result;
    if ( v1 >= 2 )
    {
      ipc_log_context = get_ipc_log_context(result);
      ipc_log_string(
        ipc_log_context,
        "[e][%-4d]invalid stream id:%d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        *(_DWORD *)(v2 + 12));
      return printk(&unk_26EFE9, "dp_catalog_audio_config_sdp");
    }
    else
    {
      v3 = v1 == 1;
      v4 = (_DWORD **)(result - 392);
      v5 = *(_QWORD *)(result - 488);
      v6 = *(_DWORD **)(result - 392);
      if ( v3 )
        v7 = 696;
      else
        v7 = 0;
      v8 = result - 512;
      v9 = result - 512;
      v10 = *(_QWORD *)(v2 - 488);
      if ( *(v6 - 1) != -1879227436 )
        __break(0x8228u);
      v11 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(v9, v10, (unsigned int)(v7 + 552));
      v12 = v11;
      v13 = get_ipc_log_context(v11);
      StatusReg = _ReadStatusReg(SP_EL0);
      ipc_log_string(v13, "[d][%-4d]sdp_cfg = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v12 | 0x100066);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]sdp_cfg = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v12 | 0x100066);
      v15 = (_DWORD **)(v2 - 384);
      v16 = *(_DWORD **)(v2 - 384);
      if ( *(v16 - 1) != -626862723 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v16)(
        v2 - 512,
        v5,
        (unsigned int)(v7 + 552),
        v12 | 0x100066u);
      v17 = *v4;
      if ( *(*v4 - 1) != -1879227436 )
        __break(0x8228u);
      v18 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v17)(v2 - 512, v5, (unsigned int)(v7 + 556));
      v19 = v18;
      v20 = get_ipc_log_context(v18);
      ipc_log_string(v20, "[d][%-4d]sdp_cfg2 = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v19 & 0xFFFFFFFC);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]sdp_cfg2 = 0x%x\n", *(_DWORD *)(StatusReg + 1800), v19 & 0xFFFFFFFC);
      v21 = *v15;
      if ( *(*v15 - 1) != -626862723 )
        __break(0x8228u);
      return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v21)(
               v8,
               v5,
               (unsigned int)(v7 + 556),
               v19 & 0xFFFFFFFC);
    }
  }
  return result;
}
