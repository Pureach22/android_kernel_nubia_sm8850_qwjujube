__int64 __fastcall dp_link_power_down(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w19
  __int64 ipc_log_context; // x0
  int v8; // w19
  __int64 v9; // x0
  _BYTE v10[4]; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *a2 < 0x11u )
    goto LABEL_4;
  v10[0] = 0;
  v3 = drm_dp_dpcd_read(a1, 1536, v10, 1);
  if ( (_DWORD)v3 != 1 )
  {
    v6 = v3;
    ipc_log_context = get_ipc_log_context(v3);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to read sink power when powering down, ret:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v6);
    printk(&unk_233E5A, "dp_link_power_down");
LABEL_8:
    result = 4294967291LL;
    goto LABEL_5;
  }
  v10[0] = v10[0] & 0xFC | 2;
  v11[0] = v10[0];
  v4 = drm_dp_dpcd_write(a1, 1536, v11, 1);
  if ( (_DWORD)v4 != 1 )
  {
    v8 = v4;
    v9 = get_ipc_log_context(v4);
    ipc_log_string(
      v9,
      "[e][%-4d]failed to power down[0x%x] sink, ret:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v10[0],
      v8);
    printk(&unk_214D18, "dp_link_power_down");
    goto LABEL_8;
  }
LABEL_4:
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
