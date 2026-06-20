__int64 __fastcall cam_icp_v2_set_hfi_handle(__int64 a1, _DWORD *a2, int a3)
{
  const char *v4; // x6
  const char *v5; // x7

  if ( a1 && a2 )
  {
    if ( a3 == 4 )
    {
      *(_DWORD *)(a1 + 52) = *a2;
      return 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v2_set_hfi_handle",
      1133,
      "Invalid set hfi handle command arg size:%u",
      a3);
  }
  else
  {
    if ( a1 )
      v4 = "Non-NULL";
    else
      v4 = "NULL";
    if ( a2 )
      v5 = "Non-NULL";
    else
      v5 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_v2_set_hfi_handle",
      1127,
      "Core info is %s and args is %s",
      v4,
      v5);
  }
  return 4294967274LL;
}
