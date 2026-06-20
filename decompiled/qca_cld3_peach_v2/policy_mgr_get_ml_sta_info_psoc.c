__int64 __fastcall policy_mgr_get_ml_sta_info_psoc(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
        __int64 a4,
        __int64 a5,
        _BYTE *a6,
        __int64 a7,
        __int64 a8)
{
  _QWORD *context; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  context = (_QWORD *)policy_mgr_get_context(a1);
  if ( context )
    return policy_mgr_get_ml_sta_info(context, a2, a3, a4, a5, a6, a7, a8);
  else
    return qdf_trace_msg(
             0x4Fu,
             2u,
             "%s: Invalid pm_ctx",
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "policy_mgr_get_ml_sta_info_psoc");
}
