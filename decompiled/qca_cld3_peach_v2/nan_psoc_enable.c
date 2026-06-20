__int64 nan_psoc_enable()
{
  double v0; // d0
  double v1; // d1
  double v2; // d2
  double v3; // d3
  double v4; // d4
  double v5; // d5
  double v6; // d6
  double v7; // d7

  if ( (unsigned int)target_if_nan_register_events() )
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: target_if_nan_register_events failed",
      v0,
      v1,
      v2,
      v3,
      v4,
      v5,
      v6,
      v7,
      "nan_psoc_enable");
  return 0;
}
