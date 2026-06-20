__int64 __fastcall dp_link_configure(__int64 a1, __int64 a2)
{
  char v4; // w0
  int v5; // w8
  char v6; // w9
  __int64 v7; // x0
  __int64 result; // x0
  int v9; // w19
  __int64 ipc_log_context; // x0
  char v11[4]; // [xsp+0h] [xbp-10h] BYREF
  char v12; // [xsp+4h] [xbp-Ch] BYREF
  char v13; // [xsp+5h] [xbp-Bh]
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = drm_dp_link_rate_to_bw_code(*(unsigned int *)(a2 + 4));
  v5 = *(_DWORD *)(a2 + 8);
  v6 = *(_BYTE *)(a2 + 16);
  v12 = v4;
  v13 = v5;
  if ( (v6 & 1) != 0 )
    v13 = v5 | 0x80;
  v7 = drm_dp_dpcd_write(a1, 256, &v12, 2);
  if ( (_DWORD)v7 == 2 )
  {
    result = drm_dp_dpcd_read(a1, 1, &v12, 1);
    if ( (result & 0x80000000) == 0 )
    {
      if ( !v12 )
      {
        v11[0] = 6;
        drm_dp_dpcd_write(a1, 277, v11, 1);
      }
      result = 0;
    }
  }
  else
  {
    v9 = v7;
    ipc_log_context = get_ipc_log_context(v7);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to configure link, ret:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v9);
    printk(&unk_259921, "dp_link_configure");
    result = 4294967291LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
