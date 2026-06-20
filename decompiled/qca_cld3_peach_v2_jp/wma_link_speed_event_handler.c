__int64 __fastcall wma_link_speed_event_handler(
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
  if ( a10 )
  {
    if ( (unsigned int)wma_send_link_speed(*(_DWORD *)(*(_QWORD *)a10 + 12LL), a1, a2, a3, a4, a5, a6, a7, a8) )
      return 4294967274LL;
    else
      return 0;
  }
  else
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid linkspeed event",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "wma_link_speed_event_handler");
    return 4294967274LL;
  }
}
