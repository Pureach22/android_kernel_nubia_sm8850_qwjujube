__int64 __fastcall hdd_is_ap_active(
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
  __int64 v10; // x29
  __int64 v11; // x30

  if ( a1 )
    return *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 257LL) & 1;
  qdf_trace_msg(0x33u, 2u, "%s: hdd_ctx is null", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_is_ap_active", v10, v11);
  return 0;
}
