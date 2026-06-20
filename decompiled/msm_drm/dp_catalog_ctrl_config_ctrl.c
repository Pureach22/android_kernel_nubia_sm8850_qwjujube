__int64 __fastcall dp_catalog_ctrl_config_ctrl(__int64 a1, unsigned __int8 a2)
{
  __int64 v2; // x21
  __int64 (__fastcall *v3)(__int64, __int64, __int64); // x8
  __int64 v4; // x22
  __int64 v7; // x0
  int v8; // w0
  _DWORD *v9; // x10
  _DWORD *v10; // x8
  int v11; // w0
  _DWORD *v12; // x8
  int v13; // w19
  __int64 v14; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  __int64 result; // x0
  __int64 v18; // x0

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 - 208);
    v3 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
    v4 = a1 - 232;
    v7 = a1 - 232;
    if ( *((_DWORD *)v3 - 1) != -1879227436 )
      __break(0x8228u);
    v8 = v3(v7, v2, 8);
    v9 = *(_DWORD **)(a1 - 104);
    if ( *(v9 - 1) != -626862723 )
      __break(0x822Au);
    ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))v9)(v4, v2, 8, v8 & 0xFFFFFBCF | (16 * a2 - 16));
    v10 = *(_DWORD **)(a1 - 112);
    if ( *(v10 - 1) != -1879227436 )
      __break(0x8228u);
    v11 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v10)(v4, v2, 0);
    v12 = *(_DWORD **)(a1 - 104);
    v13 = v11;
    if ( *(v12 - 1) != -626862723 )
      __break(0x8228u);
    v14 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))v12)(v4, v2, 0, v11 | 0x2000000u);
    ipc_log_context = get_ipc_log_context(v14);
    StatusReg = _ReadStatusReg(SP_EL0);
    result = ipc_log_string(
               ipc_log_context,
               "[d][%-4d]DP_MAINLINK_CTRL=0x%x\n",
               *(_DWORD *)(StatusReg + 1800),
               v13 | 0x2000000u);
    if ( (_drm_debug & 4) != 0 )
      return _drm_dev_dbg(
               0,
               0,
               0,
               "[msm-dp-debug][%-4d]DP_MAINLINK_CTRL=0x%x\n",
               *(_DWORD *)(StatusReg + 1800),
               v13 | 0x2000000u);
  }
  else
  {
    v18 = get_ipc_log_context(0);
    ipc_log_string(v18, "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    return printk(&unk_275B6D, "dp_catalog_ctrl_config_ctrl");
  }
  return result;
}
