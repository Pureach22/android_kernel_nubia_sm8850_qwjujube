__int64 __fastcall cam_sfe_disable_soc_resources(__int64 a1)
{
  int *v1; // x19
  __int64 v2; // x1
  unsigned int v3; // w19
  int v4; // w0

  if ( a1 )
  {
    v1 = *(int **)(a1 + 3296);
    if ( *(_BYTE *)(a1 + 3200) == 1 )
      v2 = *(unsigned int *)(a1 + 20);
    else
      v2 = 0xFFFFFFFFLL;
    v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
           a1,
           v2,
           1,
           1);
    if ( v4 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_disable_soc_resources",
        258,
        "Disable platform failed rc=%d",
        v4);
    v3 = cam_cpas_stop(*v1);
    if ( v3 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_disable_soc_resources",
        262,
        "CPAS stop failed rc=%d",
        v3);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_disable_soc_resources",
      248,
      "Invalid params");
    return (unsigned int)-22;
  }
  return v3;
}
