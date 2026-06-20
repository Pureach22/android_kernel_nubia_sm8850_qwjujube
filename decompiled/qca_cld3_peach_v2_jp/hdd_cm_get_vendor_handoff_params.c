__int64 __fastcall hdd_cm_get_vendor_handoff_params(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Received vendor handoff event from FW",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "hdd_cm_get_vendor_handoff_params");
  v11 = osif_request_get(a10);
  if ( v11 )
  {
    v20 = v11;
    osif_request_complete(v11);
    osif_request_put(v20);
    qdf_trace_msg(0x33u, 8u, "%s: exit", v21, v22, v23, v24, v25, v26, v27, v28, "hdd_cm_get_vendor_handoff_params");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid request",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_cm_get_vendor_handoff_params");
    return 16;
  }
}
