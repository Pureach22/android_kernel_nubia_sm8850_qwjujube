__int64 __fastcall cam_wrapper_regulator_set_load(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned int v3; // w22
  __int64 result; // x0
  unsigned int v5; // w20
  _QWORD v6[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v7[3]; // [xsp+18h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = 0;
  v7[1] = 0;
  v6[0] = 0;
  v6[1] = 0;
  if ( (debug_bypass_drivers & 1) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_regulator_set_load",
      572,
      "Bypass regulator set load");
    result = 0;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v2 = a1;
      v3 = a2;
      ktime_get_real_ts64(v7);
      a1 = v2;
      a2 = v3;
    }
    result = regulator_set_load(a1, a2);
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v5 = result;
      ktime_get_real_ts64(v6);
      result = v5;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
