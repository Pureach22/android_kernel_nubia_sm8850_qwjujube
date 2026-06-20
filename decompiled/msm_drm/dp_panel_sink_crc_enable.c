__int64 __fastcall dp_panel_sink_crc_enable(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x19
  __int64 ipc_log_context; // x0
  void *v8; // x0
  __int64 v9; // x19
  __int64 v10; // x0
  _BYTE v11[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 88) & 2) == 0 )
    goto LABEL_5;
  v1 = *(_QWORD *)(a1 + 1192);
  v11[0] = 0;
  v2 = *(_QWORD *)(v1 + 24);
  v3 = drm_dp_dpcd_read(v2, 624, v11, 1);
  if ( v3 != 1 )
  {
    v6 = v3;
    ipc_log_context = get_ipc_log_context(v3);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to read CRC cap, ret:%zd\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v6);
    v8 = &unk_237483;
LABEL_9:
    printk(v8, "dp_panel_sink_crc_enable");
    result = 4294967291LL;
    goto LABEL_6;
  }
  v12[0] = v11[0] | 1;
  v4 = drm_dp_dpcd_write(v2, 624, v12, 1);
  if ( v4 != 1 )
  {
    v9 = v4;
    v10 = get_ipc_log_context(v4);
    ipc_log_string(v10, "[e][%-4d]failed to enable Sink CRC, ret:%zd\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800), v9);
    v8 = &unk_267AA9;
    goto LABEL_9;
  }
  drm_dp_dpcd_read(v2, 624, v11, 1);
LABEL_5:
  result = 0;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
