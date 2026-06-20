__int64 __fastcall cam_ife_csid_deinit_soc_resources(__int64 a1)
{
  int *v1; // x8
  int v3; // w0
  unsigned int v4; // w19

  v1 = *(int **)(a1 + 3296);
  if ( v1 )
  {
    v3 = cam_cpas_unregister_client(*v1);
    if ( v3 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_deinit_soc_resources",
        150,
        "CPAS unregistration failed rc=%d",
        v3);
    v4 = cam_soc_util_release_platform_resource(a1);
    if ( v4 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        2,
        "cam_ife_csid_deinit_soc_resources",
        155,
        "soc release platform resource fail rc: %d",
        v4);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_deinit_soc_resources",
      144,
      "Error soc_private NULL");
    return (unsigned int)-19;
  }
  return v4;
}
