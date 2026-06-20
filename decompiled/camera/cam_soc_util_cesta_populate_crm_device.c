__int64 cam_soc_util_cesta_populate_crm_device()
{
  __int64 device; // x19
  __int64 result; // x0
  _QWORD v2[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v3[3]; // [xsp+18h] [xbp-18h] BYREF

  v3[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  v3[1] = 0;
  v2[0] = 0;
  v2[1] = 0;
  if ( (debug_bypass_drivers & 8) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_crm_get_device",
      130,
      "Bypass crm get device");
    result = 0;
    cam_cesta_crm_dev = 3735928559LL;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
      ktime_get_real_ts64(v3);
    device = crm_get_device("cam_crm");
    if ( clk_rgltr_bus_ops_profiling == 1 )
      ktime_get_real_ts64(v2);
    cam_cesta_crm_dev = device;
    if ( device )
    {
      result = 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_soc_util_cesta_populate_crm_device",
        642,
        "Failed to get cesta crm dev for %s",
        "cam_crm");
      result = 4294967277LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
