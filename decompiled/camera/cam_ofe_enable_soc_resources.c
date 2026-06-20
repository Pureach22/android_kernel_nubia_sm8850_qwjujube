__int64 __fastcall cam_ofe_enable_soc_resources(__int64 a1)
{
  __int64 result; // x0
  unsigned int v2; // w19

  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, _QWORD))cam_soc_util_enable_platform_resource)(
             a1,
             0xFFFFFFFFLL,
             1,
             5,
             0);
  if ( (_DWORD)result )
  {
    v2 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_ofe_enable_soc_resources",
      120,
      "enable platform failed");
    return v2;
  }
  return result;
}
