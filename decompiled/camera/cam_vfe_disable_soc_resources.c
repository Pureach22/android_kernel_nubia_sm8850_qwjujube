__int64 __fastcall cam_vfe_disable_soc_resources(__int64 a1)
{
  unsigned int v1; // w19
  int *v2; // x20
  unsigned int v3; // w0
  const char *v4; // x5
  __int64 v5; // x4

  if ( a1 )
  {
    v2 = *(int **)(a1 + 3296);
    v3 = ((__int64 (*)(void))cam_soc_util_disable_platform_resource)();
    if ( v3 )
    {
      v1 = v3;
      v4 = "Disable platform failed rc=%d";
      v5 = 395;
    }
    else
    {
      v1 = cam_cpas_stop(*v2);
      if ( !v1 )
        return v1;
      v4 = "Error! CPAS stop failed rc=%d";
      v5 = 401;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_disable_soc_resources",
      v5,
      v4,
      v1);
    return v1;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_disable_soc_resources",
    385,
    "Error! Invalid params");
  return (unsigned int)-22;
}
