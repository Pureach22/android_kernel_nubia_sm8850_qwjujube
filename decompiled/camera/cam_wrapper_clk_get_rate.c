__int64 __fastcall cam_wrapper_clk_get_rate(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  __int64 v3; // x20
  _QWORD v4[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v5[3]; // [xsp+18h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v5[1] = 0;
  v4[0] = 0;
  v4[1] = 0;
  if ( (debug_bypass_drivers & 4) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_clk_get_rate",
      324,
      "Bypass clk get rate");
    result = 19200000;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v1 = a1;
      ktime_get_real_ts64(v5);
      a1 = v1;
    }
    result = clk_get_rate(a1);
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v3 = result;
      ktime_get_real_ts64(v4);
      result = v3;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
