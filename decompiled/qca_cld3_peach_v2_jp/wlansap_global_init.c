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
    qword_855E88 = 0;
    sap_ctx_ref_count = 0;
    dword_855EB4 = 0;
    qword_855E90 = 0;
    qword_855E98 = 0;
    dword_855EB8 = 0;
    dword_855EBC = 0;
    qword_855EA0 = 0;
    qword_855EA8 = 0;
    dword_855EC0 = 0;
    dword_855EC4 = 0;
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
