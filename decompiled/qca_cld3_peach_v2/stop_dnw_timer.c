__int64 __fastcall stop_dnw_timer(
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

  if ( a1 )
  {
    if ( *(_BYTE *)(a1 + 10) == 1 && (unsigned int)qdf_mc_timer_get_current_state(a1 + 32) == 21 )
    {
      qdf_mc_timer_stop(a1 + 32);
      *(_BYTE *)(a1 + 10) = 0;
      qdf_mc_timer_destroy(a1 + 32);
      qdf_trace_msg(0x98u, 8u, "%s: dnw timer stopped", v10, v11, v12, v13, v14, v15, v16, v17, "stop_dnw_timer");
      return 0;
    }
    else
    {
      qdf_trace_msg(0x98u, 8u, "%s: timer isn't running", a2, a3, a4, a5, a6, a7, a8, a9, "stop_dnw_timer");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x98u, 2u, "%s: NULL dnw_pdev_info", a2, a3, a4, a5, a6, a7, a8, a9, "stop_dnw_timer");
    return 4;
  }
}
