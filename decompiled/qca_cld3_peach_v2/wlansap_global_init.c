__int64 wlansap_global_init()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7

  if ( (unsigned int)qdf_mutex_create((__int64)&sap_context_lock) )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: failed to init sap_context_lock",
      v0,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      "wlansap_global_init");
    return 5;
  }
  else
  {
    gp_sap_ctx = 0;
    qword_91F040 = 0;
    sap_ctx_ref_count = 0;
    dword_91F06C = 0;
    qword_91F048 = 0;
    qword_91F050 = 0;
    dword_91F070 = 0;
    dword_91F074 = 0;
    qword_91F058 = 0;
    qword_91F060 = 0;
    dword_91F078 = 0;
    dword_91F07C = 0;
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sap global context initialized",
      v0,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      "wlansap_global_init");
    return 0;
  }
}
