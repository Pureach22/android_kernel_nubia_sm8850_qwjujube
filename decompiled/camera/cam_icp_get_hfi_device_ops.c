__int64 __fastcall cam_icp_get_hfi_device_ops(int a1, _QWORD *a2)
{
  if ( a1 == 1 )
  {
    cam_icp_v2_populate_hfi_ops(a2);
    return 0;
  }
  else if ( a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_get_hfi_device_ops",
      108,
      "Invalid ICP device type: %u",
      a1);
    return 4294967274LL;
  }
  else
  {
    cam_icp_v1_populate_hfi_ops(a2);
    return 0;
  }
}
