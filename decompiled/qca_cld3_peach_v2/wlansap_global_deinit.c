__int64 __fastcall wlansap_global_deinit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  if ( gp_sap_ctx )
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: we could be leaking context:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlansap_global_deinit",
      0);
  gp_sap_ctx = 0;
  sap_ctx_ref_count = 0;
  if ( qword_91F040 )
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: we could be leaking context:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlansap_global_deinit",
      1);
  qword_91F040 = 0;
  dword_91F06C = 0;
  if ( qword_91F048 )
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: we could be leaking context:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlansap_global_deinit",
      2);
  qword_91F048 = 0;
  dword_91F070 = 0;
  if ( qword_91F050 )
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: we could be leaking context:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlansap_global_deinit",
      3);
  qword_91F050 = 0;
  dword_91F074 = 0;
  if ( qword_91F058 )
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: we could be leaking context:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlansap_global_deinit",
      4);
  qword_91F058 = 0;
  dword_91F078 = 0;
  if ( qword_91F060 )
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: we could be leaking context:%d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wlansap_global_deinit",
      5);
  qword_91F060 = 0;
  dword_91F07C = 0;
  if ( (unsigned int)qdf_mutex_destroy((__int64)&sap_context_lock) )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: failed to destroy sap_context_lock",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlansap_global_deinit");
    return 5;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sap global context deinitialized",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wlansap_global_deinit");
    return 0;
  }
}
