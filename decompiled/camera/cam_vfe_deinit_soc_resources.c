__int64 __fastcall cam_vfe_deinit_soc_resources(__int64 a1)
{
  __int64 v1; // x19
  int v3; // w0
  unsigned int v4; // w20
  __int64 v5; // x1
  const char *v6; // x5
  __int64 v7; // x4

  if ( !a1 )
  {
    v6 = "Error! soc_info NULL";
    v7 = 225;
LABEL_15:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_deinit_soc_resources",
      v7,
      v6);
    return (unsigned int)-19;
  }
  v1 = *(_QWORD *)(a1 + 3296);
  if ( !v1 )
  {
    v6 = "Error! soc_private NULL";
    v7 = 231;
    goto LABEL_15;
  }
  v3 = cam_cpas_unregister_client(*(_DWORD *)v1);
  if ( v3 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_deinit_soc_resources",
      237,
      "CPAS unregistration failed rc=%d",
      v3);
  v4 = cam_soc_util_release_platform_resource(a1);
  if ( v4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_release_platform_resource",
      141,
      "Error! Release platform resource failed rc=%d",
      v4);
    if ( (v4 & 0x80000000) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_deinit_soc_resources",
        242,
        "Error! Release platform resources failed rc=%d",
        v4);
  }
  v5 = *(unsigned int *)(v1 + 12);
  if ( (_DWORD)v5 != -1 )
  {
    v4 = cam_soc_util_put_optional_clk(a1, v5);
    if ( v4 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_deinit_soc_resources",
        249,
        "Error Put dsp clk failed rc=%d",
        v4);
  }
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v1, 0);
  else
    kvfree(v1);
  return v4;
}
