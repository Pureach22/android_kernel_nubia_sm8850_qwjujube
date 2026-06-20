__int64 __fastcall cam_isp_hw_mgr_init(const char *a1, __int64 a2, __int64 a3, unsigned int a4)
{
  size_t v8; // x0
  size_t v9; // x0
  size_t v11; // x0

  v8 = strlen(a1);
  if ( strnstr(a1, "ife", v8) )
    return cam_ife_hw_mgr_init(a2, a3, a4);
  v9 = strlen(a1);
  if ( strnstr(a1, "mc_tfe", v9) )
    return cam_ife_hw_mgr_init(a2, a3, a4);
  v11 = strlen(a1);
  if ( !strnstr(a1, "tfe", v11) )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_hw_mgr_init",
      24,
      "Invalid ISP hw type :%s",
      a1);
  return 4294967274LL;
}
