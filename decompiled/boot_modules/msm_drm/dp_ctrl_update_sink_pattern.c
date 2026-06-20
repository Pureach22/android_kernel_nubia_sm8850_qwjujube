__int64 __fastcall dp_ctrl_update_sink_pattern(__int64 a1, unsigned __int8 a2)
{
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v6; // x8
  int v7; // w0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_log_context = get_ipc_log_context(a1);
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(ipc_log_context, "[d][%-4d]sink: pattern=%x\n", *(_DWORD *)(StatusReg + 1800), a2);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]sink: pattern=%x\n", *(_DWORD *)(StatusReg + 1800), a2);
  if ( a2 && a2 != 7 )
    a2 |= 0x20u;
  v6 = *(_QWORD *)(a1 + 136);
  v9[0] = a2;
  v7 = drm_dp_dpcd_write(*(_QWORD *)(v6 + 24), 258, v9, 1);
  _ReadStatusReg(SP_EL0);
  if ( v7 <= 0 )
    return 4294967274LL;
  else
    return 0;
}
