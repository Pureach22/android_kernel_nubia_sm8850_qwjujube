__int64 __fastcall cam_isp_hw_mgr_deinit(const char *a1)
{
  size_t v2; // x0
  __int64 result; // x0
  size_t v4; // x0

  v2 = strlen(a1);
  if ( strnstr(a1, "ife", v2) )
    return cam_ife_hw_mgr_deinit();
  v4 = strlen(a1);
  result = strnstr(a1, "tfe", v4);
  if ( !result )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             8,
             1,
             "cam_isp_hw_mgr_deinit",
             38,
             "Invalid ISP hw type :%s",
             a1);
  return result;
}
