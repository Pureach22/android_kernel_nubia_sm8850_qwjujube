__int64 __fastcall dp_telemetry_init(
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
  if ( !*(_DWORD *)(a1 + 28) )
    return _qdf_periodic_work_create(a1 + 3744, (__int64)dp_telemetry_opm_stats_work_handler, a1);
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
    "dp_telemetry_init");
  return 4;
}
