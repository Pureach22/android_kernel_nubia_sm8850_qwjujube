__int64 __fastcall cam_icp_v2_test_irq_line(__int64 a1)
{
  __int64 v1; // x21
  unsigned int v3; // w8
  __int64 v4; // x22
  __int64 result; // x0
  unsigned __int8 v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3680);
    v3 = *(_DWORD *)(v1 + 56);
    if ( v3 >= 8 )
    {
      __break(0x5512u);
      JUMPOUT(0x244730);
    }
    *(_DWORD *)(a1 + 56) = 0;
    v4 = *(_QWORD *)(a1 + 24LL * v3 + 384);
    *(_BYTE *)(v1 + 106) = 1;
    ((void (__fastcall *)(__int64, unsigned __int8 *, __int64))cam_icp_v2_hw_init)(a1, v6, 1);
    cam_io_w_mb(8, v4 + *(unsigned int *)(*(_QWORD *)(v1 + 16) + 4LL));
    cam_io_w_mb(8, v4 + *(unsigned int *)(*(_QWORD *)(v1 + 16) + 12LL));
    cam_io_w_mb(1, v4 + *(unsigned int *)(*(_QWORD *)(v1 + 16) + 16LL));
    if ( !cam_common_wait_for_completion_timeout(a1 + 56) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_v2_test_irq_line",
        1340,
        "ICP IRQ verification timed out");
    cam_io_w_mb(0, v4 + *(unsigned int *)(*(_QWORD *)(v1 + 16) + 4LL));
    cam_icp_v2_hw_deinit(a1, v6, 1);
    result = 0;
    *(_BYTE *)(v1 + 106) = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v2_test_irq_line",
      1321,
      "invalid ICP device info");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
