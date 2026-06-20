__int64 __fastcall cds_sched_close(
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

  qdf_trace_msg(0x38u, 8u, "%s: invoked", a1, a2, a3, a4, a5, a6, a7, a8, "cds_sched_close");
  if ( gp_cds_sched_context )
  {
    gp_cds_sched_context = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(0x38u, 2u, "%s: !gp_cds_sched_context", v8, v9, v10, v11, v12, v13, v14, v15, "cds_sched_close");
    return 16;
  }
}
