__int64 __fastcall cam_wrapper_clk_round_rate(__int64 a1, __int64 a2)
{
  __int64 v3; // x22
  _QWORD v5[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v6[3]; // [xsp+18h] [xbp-18h] BYREF

  v6[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0;
  v6[1] = 0;
  v5[0] = 0;
  v5[1] = 0;
  if ( (debug_bypass_drivers & 4) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_clk_round_rate",
      303,
      "Bypass clk round rate");
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v3 = a1;
      ktime_get_real_ts64(v6);
      a1 = v3;
    }
    a2 = clk_round_rate(a1, a2);
    if ( clk_rgltr_bus_ops_profiling == 1 )
      ktime_get_real_ts64(v5);
  }
  _ReadStatusReg(SP_EL0);
  return a2;
}
