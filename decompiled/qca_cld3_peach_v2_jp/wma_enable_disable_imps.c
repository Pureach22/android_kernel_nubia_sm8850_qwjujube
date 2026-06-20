__int64 __fastcall wma_enable_disable_imps(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int a10)
{
  __int64 *context; // x0
  __int64 *v12; // x20
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w21

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_enable_disable_imps", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    v12 = context;
    result = wmi_unified_pdev_param_send(*context);
    if ( (_DWORD)result )
    {
      v22 = result;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Unable to enable/disable:(%d) IMPS",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wma_enable_disable_imps",
        a10);
      result = v22;
    }
    *((_BYTE *)v12 + 3949) = a10 != 0;
  }
  else
  {
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
