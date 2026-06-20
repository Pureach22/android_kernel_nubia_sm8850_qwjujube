__int64 __fastcall cam_icp_soc_resources_disable(__int64 a1)
{
  unsigned int v1; // w19

  v1 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
         a1,
         0xFFFFFFFFLL,
         1,
         1);
  if ( v1 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_soc_resources_disable",
      285,
      "failed to disable soc resources rc=%d",
      v1);
  return v1;
}
