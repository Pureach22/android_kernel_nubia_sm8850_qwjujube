__int64 __fastcall dp_wdi_event_attach(
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
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( a1 )
  {
    v10 = _qdf_mem_malloc(0x890u, "dp_wdi_event_attach", 254);
    *(_QWORD *)(a1 + 95032) = v10;
    if ( v10 )
      return 0;
    qdf_trace_msg(0x45u, 2u, "Insufficient memory for the WDI event lists", v11, v12, v13, v14, v15, v16, v17, v18);
  }
  else
  {
    qdf_trace_msg(
      0x45u,
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
      "dp_wdi_event_attach");
  }
  return 4294967274LL;
}
