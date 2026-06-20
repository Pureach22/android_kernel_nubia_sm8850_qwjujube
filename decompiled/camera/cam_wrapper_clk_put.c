__int64 __fastcall cam_wrapper_clk_put(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v4[3]; // [xsp+18h] [xbp-18h] BYREF

  v4[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  v4[1] = 0;
  v3[0] = 0;
  v3[1] = 0;
  if ( (debug_bypass_drivers & 4) != 0 )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               0x20000,
               2,
               "cam_wrapper_clk_put",
               365,
               "Bypass clk put");
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v1 = a1;
      ktime_get_real_ts64(v4);
      a1 = v1;
    }
    result = clk_put(a1);
    if ( clk_rgltr_bus_ops_profiling == 1 )
      result = ktime_get_real_ts64(v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
