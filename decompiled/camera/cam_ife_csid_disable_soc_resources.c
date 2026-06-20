__int64 __fastcall cam_ife_csid_disable_soc_resources(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x1
  unsigned int v3; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 3296);
    if ( *(_BYTE *)(a1 + 3200) == 1 && (*(_BYTE *)(v1 + 12) & 1) == 0 )
      v2 = *(unsigned int *)(a1 + 20);
    else
      v2 = 0xFFFFFFFFLL;
    if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
                         a1,
                         v2,
                         1,
                         1) )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_disable_soc_resources",
        232,
        "Disable platform failed");
    v3 = cam_cpas_stop(*(_DWORD *)v1);
    if ( v3 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_disable_soc_resources",
        236,
        "Error CPAS stop failed rc=%d",
        v3);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_disable_soc_resources",
      223,
      "Error Invalid params");
    return (unsigned int)-22;
  }
  return v3;
}
