__int64 __fastcall cam_icp_soc_resources_deinit(__int64 a1)
{
  unsigned int v1; // w19

  v1 = cam_soc_util_release_platform_resource(a1);
  if ( v1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_soc_resources_deinit",
      262,
      "release of soc platform resource failed rc=%d",
      v1);
  return v1;
}
