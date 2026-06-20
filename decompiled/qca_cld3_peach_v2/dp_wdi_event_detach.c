__int64 __fastcall dp_wdi_event_detach(
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
  __int64 v9; // x0

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 95928);
    if ( v9 )
    {
      _qdf_mem_free(v9);
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "Invalid device in %s\nWDI attach failed",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_wdi_event_detach");
  }
  return 4294967274LL;
}
