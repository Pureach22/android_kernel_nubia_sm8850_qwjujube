__int64 __fastcall dp_link_probe(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x0
  int v5; // w0
  char v6; // w8
  int v7; // w9
  int v9; // w20
  __int64 ipc_log_context; // x0
  __int16 v11; // [xsp+4h] [xbp-Ch] BYREF
  char v12; // [xsp+6h] [xbp-Ah]
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_QWORD *)(a2 + 16) = 0;
  v12 = 0;
  v11 = 0;
  v3 = drm_dp_dpcd_read(a1, 0, &v11, 3);
  if ( (int)v3 <= 2 )
  {
    v9 = v3;
    ipc_log_context = get_ipc_log_context(v3);
    ipc_log_string(
      ipc_log_context,
      "[e][%-4d]failed to probe link, ret:%d\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      v9);
    printk(&unk_23E4B8, "dp_link_probe");
  }
  v4 = HIBYTE(v11);
  *(_BYTE *)a2 = v11;
  v5 = drm_dp_bw_code_to_link_rate(v4);
  v6 = v12;
  v7 = v12 & 0x1F;
  *(_DWORD *)(a2 + 4) = v5;
  *(_DWORD *)(a2 + 8) = v7;
  if ( v6 < 0 )
    *(_QWORD *)(a2 + 16) |= 1uLL;
  _ReadStatusReg(SP_EL0);
  return 0;
}
