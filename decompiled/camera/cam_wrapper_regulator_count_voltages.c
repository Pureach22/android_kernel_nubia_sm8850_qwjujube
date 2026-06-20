__int64 __fastcall cam_wrapper_regulator_count_voltages(__int64 a1)
{
  __int64 v1; // x21
  __int64 result; // x0
  unsigned int v3; // w20
  _QWORD v4[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v5[3]; // [xsp+18h] [xbp-18h] BYREF

  v5[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v5[1] = 0;
  v4[0] = 0;
  v4[1] = 0;
  if ( (debug_bypass_drivers & 1) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_regulator_count_voltages",
      550,
      "Bypass regulator count voltages");
    result = 0;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v1 = a1;
      ktime_get_real_ts64(v5);
      a1 = v1;
    }
    result = regulator_count_voltages(a1);
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
