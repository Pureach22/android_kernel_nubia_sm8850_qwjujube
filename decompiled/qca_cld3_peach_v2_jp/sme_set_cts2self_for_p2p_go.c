__int64 __fastcall sme_set_cts2self_for_p2p_go(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x0
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  context = _cds_get_context(54, (__int64)"sme_set_cts2self_for_p2p_go", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( context )
  {
    result = wma_set_cts2self_for_p2p_go(context, 1);
    if ( !(_DWORD)result )
      return result;
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Failed to set cts2self for p2p GO to firmware",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "sme_set_cts2self_for_p2p_go");
  }
  return 16;
}
