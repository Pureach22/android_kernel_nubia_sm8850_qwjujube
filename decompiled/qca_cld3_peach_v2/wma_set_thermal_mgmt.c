__int64 __fastcall wma_set_thermal_mgmt(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( a1 )
  {
    result = wmi_unified_set_thermal_mgmt_cmd(*a1);
  }
  else
  {
    qdf_trace_msg(0x36u, 2u, "%s: Invalid input", a2, a3, a4, a5, a6, a7, a8, a9, "wma_set_thermal_mgmt");
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
