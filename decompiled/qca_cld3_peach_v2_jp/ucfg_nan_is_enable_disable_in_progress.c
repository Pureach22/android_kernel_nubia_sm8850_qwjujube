bool __fastcall ucfg_nan_is_enable_disable_in_progress(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int discovery_state; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w19

  discovery_state = nan_get_discovery_state(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  v18 = discovery_state & 0xFFFFFFFD;
  if ( (discovery_state & 0xFFFFFFFD) == 1 )
    qdf_trace_msg(
      0x53u,
      4u,
      "%s: NAN enable/disable is in progress, state: %u",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "ucfg_nan_is_enable_disable_in_progress",
      discovery_state);
  return v18 == 1;
}
