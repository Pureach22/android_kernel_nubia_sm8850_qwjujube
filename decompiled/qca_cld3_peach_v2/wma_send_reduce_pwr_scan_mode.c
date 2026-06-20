__int64 __fastcall wma_send_reduce_pwr_scan_mode(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 *context; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_send_reduce_pwr_scan_mode", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    result = wmi_unified_pdev_param_send(*context);
    if ( (_DWORD)result )
    {
      v18 = result;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Unable to send reduce power scan mode",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "wma_send_reduce_pwr_scan_mode");
      result = v18;
    }
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
