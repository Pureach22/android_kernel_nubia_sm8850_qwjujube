__int64 __fastcall cam_cpas_get_rsc_dev_for_drv(unsigned int a1)
{
  __int64 result; // x0

  result = rpmh_get_device("cam_rsc", a1);
  if ( !result )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_rsc_dev_for_drv",
      34,
      "Invalid dev for index: %u",
      a1);
    return 0;
  }
  return result;
}
