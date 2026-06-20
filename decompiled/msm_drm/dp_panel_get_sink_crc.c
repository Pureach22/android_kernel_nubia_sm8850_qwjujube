__int64 __fastcall dp_panel_get_sink_crc(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  int v5; // w9
  __int64 result; // x0
  int v7; // w19
  __int64 ipc_log_context; // x0
  _DWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 1192);
  memset(v9, 0, 6);
  v4 = drm_dp_dpcd_read(*(_QWORD *)(v3 + 24), 576, v9, 6);
  if ( (_DWORD)v4 == 6 )
  {
    v5 = *(_DWORD *)((char *)v9 + 2);
    result = 0;
    *(_WORD *)a2 = v9[0];
    *(_DWORD *)(a2 + 2) = v5;
  }
  else
  {
    v7 = v4;
    ipc_log_context = get_ipc_log_context(v4);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to read sink CRC, ret:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v7);
    printk(&unk_2309F4, "dp_panel_get_sink_crc");
    result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
