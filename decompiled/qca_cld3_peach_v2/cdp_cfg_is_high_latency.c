__int64 __fastcall cdp_cfg_is_high_latency(
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
  __int64 v10; // x8
  __int64 (__fastcall *v11)(_QWORD); // x8

  if ( !*(_QWORD *)a1 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", a3, a4, a5, a6, a7, a8, a9, a10, "cdp_cfg_is_high_latency");
    return 0;
  }
  v10 = *(_QWORD *)(*(_QWORD *)a1 + 104LL);
  if ( !v10 )
    return 0;
  v11 = *(__int64 (__fastcall **)(_QWORD))(v10 + 48);
  if ( !v11 )
    return 0;
  if ( *((_DWORD *)v11 - 1) != -298467953 )
    __break(0x8228u);
  return v11(a2);
}
