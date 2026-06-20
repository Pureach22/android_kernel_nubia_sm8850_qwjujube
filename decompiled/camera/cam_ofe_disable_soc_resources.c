__int64 __fastcall cam_ofe_disable_soc_resources(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  unsigned int v3; // w19

  result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))cam_soc_util_disable_platform_resource)(
             a1,
             0xFFFFFFFFLL,
             a2,
             0);
  if ( (_DWORD)result )
  {
    v3 = result;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_ofe_disable_soc_resources",
      133,
      "disable platform failed");
    return v3;
  }
  return result;
}
