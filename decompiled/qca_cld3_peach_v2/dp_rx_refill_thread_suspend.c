__int64 __fastcall dp_rx_refill_thread_suspend(
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
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x4
  unsigned int v21; // w20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x1
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  if ( *(_DWORD *)(a1 + 216) == 3 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: already in suspend state! Ignoring.",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_rx_refill_thread_suspend");
    return 4;
  }
  else
  {
    *(_DWORD *)(a1 + 216) = 2;
    qdf_event_reset(a1 + 88);
    qdf_event_reset(a1 + 48);
    *(_QWORD *)(a1 + 168) |= 4uLL;
    _wake_up(a1 + 176, 1, 1, 0);
    v11 = qdf_wait_single_event(a1 + 48, 0x7D0u);
    if ( v11 )
    {
      if ( v11 == 15 )
        v20 = "timeout out";
      else
        v20 = "failed";
      v21 = v11;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Refill thread %s(%d) while waiting for suspend",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_rx_refill_thread_suspend",
        v20);
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: calling refill thread to resume",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "dp_rx_refill_thread_resume");
      if ( (*(_DWORD *)(a1 + 216) & 0xFFFFFFFE) == 2 )
      {
        *(_QWORD *)(a1 + 168) &= ~4uLL;
        qdf_event_set(a1 + 88, v30);
        *(_DWORD *)(a1 + 216) = 1;
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: resume callback received in %d state ! Ignoring.",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "dp_rx_refill_thread_resume");
      }
      return v21;
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        8u,
        "%s: Refill thread  suspended",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "dp_rx_refill_thread_suspend");
      *(_DWORD *)(a1 + 216) = 3;
      return 0;
    }
  }
}
