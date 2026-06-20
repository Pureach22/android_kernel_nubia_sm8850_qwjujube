__int64 __fastcall hdd_tx_latency_register_cb(
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
  __int64 v10; // x8
  __int64 (__fastcall *v11)(__int64, __int64 (__fastcall *)()); // x8

  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Register tx latency callback",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_tx_latency_register_cb");
  if ( !a1 )
    return 16;
  if ( !*(_QWORD *)a1 )
    return 16;
  v10 = *(_QWORD *)(*(_QWORD *)a1 + 32LL);
  if ( !v10 )
    return 16;
  v11 = *(__int64 (__fastcall **)(__int64, __int64 (__fastcall *)()))(v10 + 368);
  if ( !v11 )
    return 16;
  if ( *((_DWORD *)v11 - 1) != -896362998 )
    __break(0x8228u);
  return v11(a1, hdd_tx_latency_stats_cb);
}
