void __fastcall dp_set_dump_dp_trace(
        unsigned __int16 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v10 = a1;
  qdf_trace_msg(
    0x45u,
    8u,
    "%s: DUMP_DP_TRACE_LEVEL: %d %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "dp_set_dump_dp_trace",
    a1,
    a2);
  if ( v10 > 1 )
  {
    if ( v10 == 2 )
    {
      qdf_dp_trace_clear_buffer();
    }
    else if ( v10 == 3 )
    {
      qdf_dp_trace_disable_live_mode();
    }
  }
  else if ( v10 )
  {
    qdf_dp_trace_enable_live_mode();
  }
  else
  {
    qdf_dp_trace_dump_all(a2, 0xFFu, v12, v13, v14, v15, v16, v17, v18, v19);
  }
}
