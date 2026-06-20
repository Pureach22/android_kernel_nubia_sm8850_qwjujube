__int64 __fastcall cam_sfe_deinit_soc_resources(__int64 a1)
{
  int *v1; // x19
  int v3; // w0
  unsigned int v4; // w20
  const char *v5; // x5
  __int64 v6; // x4

  if ( !a1 )
  {
    v5 = "Error soc_info NULL";
    v6 = 150;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_deinit_soc_resources",
      v6,
      v5);
    return (unsigned int)-19;
  }
  v1 = *(int **)(a1 + 3296);
  if ( !v1 )
  {
    v5 = "Error! soc_private NULL";
    v6 = 156;
    goto LABEL_12;
  }
  v3 = cam_cpas_unregister_client(*v1);
  if ( v3 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_deinit_soc_resources",
      162,
      "CPAS unregistration failed rc=%d",
      v3);
  v4 = cam_soc_util_release_platform_resource(a1);
  if ( v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_release_platform_resource",
      76,
      "Error Release platform resource failed rc=%d",
      v4);
    if ( (v4 & 0x80000000) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_deinit_soc_resources",
        167,
        "Error Release platform resources failed rc=%d",
        v4);
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v1, 0);
  else
    kvfree(v1);
  return v4;
}
