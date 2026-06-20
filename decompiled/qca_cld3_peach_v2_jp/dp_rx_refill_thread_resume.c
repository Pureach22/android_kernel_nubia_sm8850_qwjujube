__int64 __fastcall dp_rx_refill_thread_resume(
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
  __int64 v10; // x1
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  qdf_trace_msg(
    0x45u,
    8u,
    "%s: calling refill thread to resume",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_rx_refill_thread_resume");
  if ( (*(_DWORD *)(a1 + 216) & 0xFFFFFFFE) == 2 )
  {
    *(_QWORD *)(a1 + 168) &= ~4uLL;
    qdf_event_set(a1 + 88, v10);
    *(_DWORD *)(a1 + 216) = 1;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: resume callback received in %d state ! Ignoring.",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "dp_rx_refill_thread_resume");
    return 4;
  }
}
