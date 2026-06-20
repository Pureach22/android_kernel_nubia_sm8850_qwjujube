__int64 __fastcall epping_disable(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // x19
  _QWORD *context; // x0
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x0
  _QWORD *v20; // x20
  __int64 result; // x0
  const char *v22; // x2

  v8 = g_epping_ctx;
  if ( !g_epping_ctx )
  {
    v22 = "%s: error: epping_ctx  = NULL";
    return qdf_trace_msg(0x33u, 1u, v22, a1, a2, a3, a4, a5, a6, a7, a8, "epping_disable");
  }
  context = _cds_get_context(61, (__int64)"epping_disable", a1, a2, a3, a4, a5, a6, a7, a8);
  if ( !context )
  {
    v22 = "%s: error: hif_ctx = NULL";
    return qdf_trace_msg(0x33u, 1u, v22, a1, a2, a3, a4, a5, a6, a7, a8, "epping_disable");
  }
  v10 = (__int64)context;
  hif_disable_isr((__int64)context);
  hif_reset_soc(v10);
  v19 = _cds_get_context(62, (__int64)"epping_disable", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !v19 )
  {
    v22 = "%s: error: htc_handle = NULL";
    return qdf_trace_msg(0x33u, 1u, v22, a1, a2, a3, a4, a5, a6, a7, a8, "epping_disable");
  }
  v20 = v19;
  htc_stop((__int64)v19);
  epping_cookie_cleanup(v8);
  htc_destroy(v20);
  result = *(_QWORD *)(v8 + 48);
  if ( result )
  {
    result = epping_destroy_adapter();
    *(_QWORD *)(v8 + 48) = 0;
  }
  return result;
}
