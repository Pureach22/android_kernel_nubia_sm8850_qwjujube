__int64 __fastcall hdd_softap_sta_disassoc(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0

  result = qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_softap_sta_disassoc");
  if ( (*a2 & 1) == 0 )
    return wlansap_disassoc_sta(*(_QWORD *)(*(_QWORD *)(a1 + 52832) + 272LL), a2);
  return result;
}
