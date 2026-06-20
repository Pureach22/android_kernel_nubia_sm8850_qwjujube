__int64 __fastcall cam_cpas_stop_drv_for_dev(const char **a1)
{
  __int64 result; // x0
  const char *v3; // x6
  unsigned int v4; // w20

  if ( a1 )
  {
    result = rpmh_drv_stop();
    if ( (_DWORD)result )
    {
      v3 = a1[14];
      v4 = result;
      if ( !v3 )
        v3 = *a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_stop_drv_for_dev",
        70,
        "[%s] Failed in DRV stop",
        v3);
      return v4;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_stop_drv_for_dev",
      64,
      "Invalid dev for DRV disable");
    return 4294967274LL;
  }
  return result;
}
