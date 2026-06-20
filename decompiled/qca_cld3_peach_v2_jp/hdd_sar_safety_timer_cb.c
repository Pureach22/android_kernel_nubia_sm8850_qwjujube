__int64 __fastcall hdd_sar_safety_timer_cb(
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

  qdf_trace_msg(0x33u, 8u, "Sar safety timer expires", a2, a3, a4, a5, a6, a7, a8, a9);
  return hdd_configure_sar_index(a1, *(_DWORD *)(*(_QWORD *)(a1 + 104) + 164LL), v10, v11, v12, v13, v14, v15, v16, v17);
}
