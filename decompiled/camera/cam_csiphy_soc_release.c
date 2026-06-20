__int64 __fastcall cam_csiphy_soc_release(__int64 a1)
{
  if ( a1 )
    cam_soc_util_release_platform_resource(a1 + 912);
  else
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x8000,
      1,
      "cam_csiphy_soc_release",
      408,
      "csiphy dev NULL");
  return 0;
}
