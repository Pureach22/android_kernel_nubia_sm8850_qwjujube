__int64 __fastcall hdd_cm_napi_serialize_control(
        char a1,
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  context = _cds_get_context(51, (__int64)"hdd_cm_napi_serialize_control", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( context )
  {
    if ( (a1 & 1) == 0 )
      hdd_init_scan_reject_params(context);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: hdd_ctx is NULL",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "hdd_cm_napi_serialize_control");
    return 4;
  }
}
