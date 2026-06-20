__int64 __fastcall cam_icp_v1_register_cpas(__int64 *a1, __int64 a2, unsigned int a3)
{
  __int64 v4; // x8
  unsigned int v5; // w20
  _QWORD v7[20]; // [xsp+0h] [xbp-B0h] BYREF
  __int64 v8; // [xsp+A0h] [xbp-10h]
  __int64 v9; // [xsp+A8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  memset(&v7[1], 0, 120);
  v8 = 0;
  v7[17] = v4 + 16;
  v7[18] = 0;
  v7[0] = 7365481;
  v7[19] = cam_icp_v1_cpas_cb;
  v7[16] = a3;
  v5 = cam_cpas_register_client((__int64)v7);
  if ( (v5 & 0x80000000) != 0 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v1_register_cpas",
      80,
      "failed: %d",
      v5);
  else
    *(_DWORD *)(a2 + 56) = v8;
  _ReadStatusReg(SP_EL0);
  return v5;
}
