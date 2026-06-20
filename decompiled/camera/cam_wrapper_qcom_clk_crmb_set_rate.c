__int64 __fastcall cam_wrapper_qcom_clk_crmb_set_rate(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 v9; // x24
  unsigned int v10; // w25
  unsigned int v11; // w26
  __int64 result; // x0
  unsigned int v13; // w20
  _QWORD v14[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v15[3]; // [xsp+18h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v15[1] = 0;
  v14[0] = 0;
  v14[1] = 0;
  if ( (debug_bypass_drivers & 8) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_qcom_clk_crmb_set_rate",
      204,
      "Bypass qcom clk crmb set rate");
    result = 0;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v9 = a1;
      v10 = a3;
      v11 = a2;
      ktime_get_real_ts64(v15);
      a1 = v9;
      a2 = v11;
      a3 = v10;
    }
    result = qcom_clk_crmb_set_rate(a1, a2, a3, 0, a4, a5, a6);
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v13 = result;
      ktime_get_real_ts64(v14);
      result = v13;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
