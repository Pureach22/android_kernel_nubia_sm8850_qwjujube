__int64 __fastcall cam_icp_mgr_process_cmd(unsigned int *a1, _QWORD *a2)
{
  if ( a1 && a2 )
  {
    if ( a1[11037] )
      return 4294967285LL;
    else
      return hfi_write_cmd(a1[39], a2[1]);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_process_cmd",
      2365,
      "Invalid params%pK %pK",
      a2,
      a1);
    return 4294967274LL;
  }
}
