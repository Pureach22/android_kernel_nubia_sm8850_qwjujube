__int64 __fastcall sme_set_vc_mode_config(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  context = _cds_get_context(54, (__int64)"sme_set_vc_mode_config", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    result = wma_set_vc_mode_config(context, a1);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to set Voltage Control config to FW",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "sme_set_vc_mode_config");
  }
  return 16;
}
