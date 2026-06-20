__int64 __fastcall wdi_event_attach(
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
  __int64 v10; // x0

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x890u, "wdi_event_attach", 205);
    *(_QWORD *)(a1 + 56) = v10;
    return 2 * (unsigned int)(v10 == 0);
  }
  else
  {
    qdf_trace_msg(
      0x3Fu,
      2u,
      "Invalid device in %s\nWDI event attach failed",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wdi_event_attach");
    return 0xFFFFFFFFLL;
  }
}
