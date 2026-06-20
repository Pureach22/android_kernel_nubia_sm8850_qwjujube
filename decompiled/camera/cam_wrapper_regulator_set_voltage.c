__int64 __fastcall cam_wrapper_regulator_set_voltage(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  unsigned int v4; // w22
  unsigned int v5; // w23
  __int64 result; // x0
  unsigned int v7; // w20
  _QWORD v8[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v9[3]; // [xsp+18h] [xbp-18h] BYREF

  v9[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v9[1] = 0;
  v8[0] = 0;
  v8[1] = 0;
  if ( (debug_bypass_drivers & 1) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_regulator_set_voltage",
      528,
      "Bypass regulator set voltage");
    result = 0;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v3 = a1;
      v4 = a3;
      v5 = a2;
      ktime_get_real_ts64(v9);
      a1 = v3;
      a2 = v5;
      a3 = v4;
    }
    result = regulator_set_voltage(a1, a2, a3);
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v7 = result;
      ktime_get_real_ts64(v8);
      result = v7;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
