__int64 __fastcall dp_bus_bw_compute_timer_stop(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  qdf_trace_msg(0x45u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "dp_bus_bw_compute_timer_stop");
  _dp_bus_bw_compute_timer_stop(a1);
  return qdf_trace_msg(0x45u, 8u, "%s: exit", v10, v11, v12, v13, v14, v15, v16, v17, "dp_bus_bw_compute_timer_stop");
}
