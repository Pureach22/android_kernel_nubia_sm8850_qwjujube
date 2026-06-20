__int64 __fastcall dp_mon_set_local_pkt_capture_running(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a1 )
  {
    *(_BYTE *)(a1 + 39317) = a2 & 1;
    qdf_trace_msg(
      0x73u,
      8u,
      "%s: local_pkt_capture_running is set to %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_mon_set_local_pkt_capture_running");
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x73u,
      2u,
      "%s: Invalid monitor pdev",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "dp_mon_set_local_pkt_capture_running");
    return 16;
  }
}
