__int64 __fastcall _cam_icp_v2_power_resume(__int64 a1)
{
  _DWORD *v1; // x22
  unsigned int v2; // w6
  __int64 v3; // x20
  __int64 v4; // x23
  unsigned int v5; // w21
  __int64 v7; // x19
  unsigned int v8; // w0
  __int64 v9; // x0
  __int64 v10; // x20
  __int64 result; // x0
  _QWORD v12[5]; // [xsp+18h] [xbp-28h] BYREF

  v12[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_DWORD **)(a1 + 3680);
  v2 = v1[9];
  if ( (v2 & 0x80000000) != 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "__cam_icp_v2_power_resume",
      536,
      "No reg base idx found for ICP_SYS: %d",
      v2);
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( v2 > 7 )
    goto LABEL_16;
  v3 = a1 + 384;
  v4 = *(_QWORD *)(a1 + 3392);
  v5 = v1[10];
  v7 = *(_QWORD *)(a1 + 384 + 24LL * v2);
  cam_io_w_mb(16, v7);
  if ( *(_DWORD *)(a1 + 116) == 1 )
  {
    v8 = v1[11];
    v12[0] = 0x800000000000001LL;
    v12[1] = 0x4000000;
    v12[2] = 4227858432LL;
    v12[3] = 4227858432LL;
    cam_cpas_set_addr_trans(v8, (__int64)v12);
  }
  v9 = *(unsigned int *)(v4 + 4);
  if ( (_DWORD)v9 )
    cam_io_w_mb(v9, v7 + 16);
  if ( (v5 & 0x80000000) != 0 )
    goto LABEL_13;
  if ( v5 > 7 )
LABEL_16:
    __break(0x5512u);
  v10 = *(_QWORD *)(v3 + 24LL * v5);
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "__cam_icp_v2_power_resume",
      576,
      "domain_cfg0, offset: 0x%x: 0x%x, domain_cfg1, offset: 0x%x: 0x%x",
      0,
      16711935,
      32,
      -16711936);
  cam_io_w_mb(16711935, v10);
  cam_io_w_mb(4278255360LL, v10 + 32);
LABEL_13:
  cam_io_w_mb(512, v7 + 4);
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
