__int64 __fastcall cam_cpas_soc_disable_resources(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // w19

  v3 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD))cam_soc_util_disable_platform_resource)(
         a1,
         0xFFFFFFFFLL,
         a2,
         a3);
  if ( v3 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_soc_disable_resources",
      2047,
      "disable platform failed, rc=%d",
      v3);
  return v3;
}
