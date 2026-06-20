__int64 __fastcall cam_cpas_drv_channel_switch_for_dev(const char **a1)
{
  __int64 result; // x0
  const char *v3; // x6
  unsigned int v4; // w20

  if ( a1 )
  {
    result = rpmh_write_sleep_and_wake_no_child();
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
        "cam_cpas_drv_channel_switch_for_dev",
        88,
        "[%s] Failed in DRV channel switch",
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
      "cam_cpas_drv_channel_switch_for_dev",
      82,
      "Invalid dev for DRV channel switch");
    return 4294967274LL;
  }
  return result;
}
