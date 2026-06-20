__int64 __fastcall dp_catalog_ctrl_mainlink_levels(__int64 a1, char a2)
{
  __int64 v2; // x19
  __int64 v4; // x21
  int v5; // w22
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x24
  __int64 (__fastcall *v8)(__int64, __int64, __int64); // x8
  __int64 v9; // x0
  int v10; // w24
  __int64 v11; // x0
  unsigned __int64 v12; // x25
  _DWORD *v13; // x8

  v2 = *(_QWORD *)(a1 - 208);
  v4 = a1 - 232;
  switch ( a2 )
  {
    case 1:
      v5 = 14;
      break;
    case 4:
      v5 = 5;
      break;
    case 2:
      v5 = 8;
      break;
    default:
      ipc_log_context = get_ipc_log_context(a1);
      StatusReg = _ReadStatusReg(SP_EL0);
      v5 = 14;
      ipc_log_string(
        ipc_log_context,
        "[d][%-4d]setting the default safe_to_exit_level = %u\n",
        *(_DWORD *)(StatusReg + 1800),
        14);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(
          0,
          0,
          0,
          "[msm-dp-debug][%-4d]setting the default safe_to_exit_level = %u\n",
          *(_DWORD *)(StatusReg + 1800),
          14);
      break;
  }
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 - 112);
  if ( *((_DWORD *)v8 - 1) != -1879227436 )
    __break(0x8228u);
  v9 = v8(v4, v2, 68);
  v10 = v9 & 0xFE0;
  v11 = get_ipc_log_context(v9);
  v12 = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    v11,
    "[d][%-4d]mainlink_level = 0x%x, safe_to_exit_level = 0x%x\n",
    *(_DWORD *)(v12 + 1800),
    v10 | v5,
    v5);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dp-debug][%-4d]mainlink_level = 0x%x, safe_to_exit_level = 0x%x\n",
      *(_DWORD *)(v12 + 1800),
      v10 | v5,
      v5);
  v13 = *(_DWORD **)(a1 - 104);
  if ( *(v13 - 1) != -626862723 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))v13)(v4, v2, 68, v10 | (unsigned int)v5);
}
