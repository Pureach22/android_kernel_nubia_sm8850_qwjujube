__int64 __fastcall hdd_deinit_adapter(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "hdd_deinit_adapter",
    *(_QWORD *)(a10 + 32) + 296LL);
  hdd_deinit_session(a10);
  return qdf_trace_msg(0x33u, 8u, "%s: exit", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_deinit_adapter");
}
