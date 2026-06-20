__int64 __fastcall os_if_wifi_pos_populate_caps(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w0

  if ( a1 && a2 )
  {
    v10 = wifi_pos_populate_caps();
    return qdf_status_to_os_return(v10);
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: psoc or caps buffer is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "os_if_wifi_pos_populate_caps");
    return 4294967274LL;
  }
}
