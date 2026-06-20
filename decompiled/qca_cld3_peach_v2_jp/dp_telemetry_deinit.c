__int64 __fastcall dp_telemetry_deinit(
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
  if ( *(_DWORD *)(a1 + 28) )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: stats not supported in device mode: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_telemetry_deinit");
    return 4;
  }
  else
  {
    _qdf_periodic_work_destroy(a1 + 3744);
    return 0;
  }
}
