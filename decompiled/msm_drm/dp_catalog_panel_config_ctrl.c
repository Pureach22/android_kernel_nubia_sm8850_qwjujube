__int64 __fastcall dp_catalog_panel_config_ctrl(__int64 a1, unsigned int a2)
{
  unsigned int v2; // w8
  __int64 v4; // x21
  unsigned int v6; // w23
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x24
  _DWORD **v9; // x24
  _DWORD *v10; // x8
  __int64 (__fastcall **v11)(__int64, __int64, __int64); // x22
  _DWORD *v12; // x8
  unsigned int v13; // w0
  int v14; // w8
  __int64 v15; // x8
  _DWORD *v16; // x8
  __int64 (__fastcall *v17)(__int64, __int64, __int64); // x8
  int v18; // w0
  _DWORD *v19; // x8
  __int64 ipc_log_context; // x0
  __int64 v22; // x0

  if ( !a1 )
  {
    ipc_log_context = get_ipc_log_context(0);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_panel_config_ctrl");
  }
  v2 = *(_DWORD *)(a1 + 204);
  if ( v2 >= 2 )
  {
    v22 = get_ipc_log_context(a1);
    ipc_log_string(
      v22,
      "[e][%-4d]invalid stream_id:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      *(_DWORD *)(a1 + 204));
    return printk(&unk_272496, "dp_catalog_panel_config_ctrl");
  }
  v4 = *(_QWORD *)(a1 - 552);
  if ( v2 == 1 )
    v6 = 1024;
  else
    v6 = 8;
  v7 = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(v7, "[d][%-4d]DP_CONFIGURATION_CTRL=0x%x\n", *(_DWORD *)(StatusReg + 1800), a2);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]DP_CONFIGURATION_CTRL=0x%x\n", *(_DWORD *)(StatusReg + 1800), a2);
  v9 = (_DWORD **)(a1 - 448);
  v10 = *(_DWORD **)(a1 - 448);
  if ( *(v10 - 1) != -626862723 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v10)(a1 - 576, v4, v6, a2);
  v11 = (__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 456);
  v12 = *(_DWORD **)(a1 - 456);
  if ( *(v12 - 1) != -1879227436 )
    __break(0x8228u);
  v13 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v12)(a1 - 576, v4, 0);
  v14 = *(_DWORD *)(a1 + 204);
  if ( !v14 )
  {
    v15 = -544;
    goto LABEL_16;
  }
  if ( v14 == 1 )
  {
    v15 = -480;
LABEL_16:
    v4 = *(_QWORD *)(a1 + v15);
  }
  v16 = *v9;
  if ( *(*v9 - 1) != -626862723 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v16)(a1 - 576, v4, 136, (v13 >> 8) & 1);
  v17 = *v11;
  if ( *((_DWORD *)*v11 - 1) != -1879227436 )
    __break(0x8228u);
  v18 = v17(a1 - 576, v4, 16);
  v19 = *v9;
  if ( *(*v9 - 1) != -626862723 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v19)(a1 - 576, v4, 16, v18 | 0x100u);
}
