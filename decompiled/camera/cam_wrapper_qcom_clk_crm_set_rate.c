__int64 __fastcall cam_wrapper_qcom_clk_crm_set_rate(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4)
{
  __int64 v7; // x24
  __int64 result; // x0
  unsigned int v9; // w20
  _QWORD v10[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v11[3]; // [xsp+18h] [xbp-18h] BYREF

  v11[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v11[1] = 0;
  v10[0] = 0;
  v10[1] = 0;
  if ( (debug_bypass_drivers & 8) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_wrapper_qcom_clk_crm_set_rate",
      178,
      "Bypass qcom clk crm set rate");
    result = 0;
  }
  else
  {
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v7 = a1;
      ktime_get_real_ts64(v11);
      a1 = v7;
    }
    result = qcom_clk_crm_set_rate(a1, 0, a2, a3, a4);
    if ( clk_rgltr_bus_ops_profiling == 1 )
    {
      v9 = result;
      ktime_get_real_ts64(v10);
      result = v9;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
