__int64 __fastcall wlan_serialization_timer_destroy(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 && *a1 )
  {
    timer_delete_sync(a1 + 1);
    *a1 = 0;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x4Cu,
      8u,
      "%s: Invalid ser_timer",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_serialization_timer_destroy");
    return 16;
  }
}
