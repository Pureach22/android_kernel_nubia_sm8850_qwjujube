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
  if ( qword_855E88 )
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
  qword_855E88 = 0;
  dword_855EB4 = 0;
  if ( qword_855E90 )
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
  qword_855E90 = 0;
  dword_855EB8 = 0;
  if ( qword_855E98 )
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
  qword_855E98 = 0;
  dword_855EBC = 0;
  if ( qword_855EA0 )
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
  qword_855EA0 = 0;
  dword_855EC0 = 0;
  if ( qword_855EA8 )
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
  qword_855EA8 = 0;
  dword_855EC4 = 0;
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
