__int64 __fastcall wma_register_roaming_callbacks(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7

  context = _cds_get_context(54, (__int64)"wma_register_roaming_callbacks", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
    return 16;
  context[387] = a1;
  context[388] = a2;
  context[389] = a3;
  context[390] = a4;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Registered roam synch callbacks with WMA successfully",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wma_register_roaming_callbacks");
  return 0;
}
