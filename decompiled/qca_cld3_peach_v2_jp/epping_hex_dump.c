__int64 __fastcall epping_hex_dump(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  qdf_trace_msg(0x33u, 1u, "%s: E, %s", a4, a5, a6, a7, a8, a9, a10, a11, "epping_hex_dump", a3);
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(51, 4, a1, a2);
  return qdf_trace_msg(0x33u, 1u, "%s: X %s", v14, v15, v16, v17, v18, v19, v20, v21, "epping_hex_dump", a3);
}
