__int64 __fastcall wma_set_idle_ps_config(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMA Set Idle Ps Config [1:set 0:clear] val %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_set_idle_ps_config",
    a2);
  if ( (unsigned int)wmi_unified_pdev_param_send(*(_QWORD *)a1) )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Fail to Set Idle Ps Config %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_set_idle_ps_config",
      a2);
    result = 16;
  }
  else
  {
    *(_BYTE *)(a1 + 3949) = a2 != 0;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Successfully Set Idle Ps Config %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "wma_set_idle_ps_config",
      a2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
