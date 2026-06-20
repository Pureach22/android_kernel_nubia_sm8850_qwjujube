__int64 __fastcall fwol_flush_callback(
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
  __int64 *v9; // x8

  if ( a1 )
  {
    v9 = *(__int64 **)(a1 + 8);
    *(_QWORD *)(a1 + 8) = 0;
    fwol_release_rx_event(v9, a2, a3, a4, a5, a6, a7, a8, a9);
    return 0;
  }
  else
  {
    qdf_trace_msg(0x66u, 2u, "%s: NULL pointer for eLNA message", a2, a3, a4, a5, a6, a7, a8, a9, "fwol_flush_callback");
    return 4;
  }
}
