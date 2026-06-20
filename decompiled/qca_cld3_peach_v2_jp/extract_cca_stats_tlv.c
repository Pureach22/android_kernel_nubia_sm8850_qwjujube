__int64 __fastcall extract_cca_stats_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _DWORD *a11)
{
  __int64 v11; // x8

  v11 = *(_QWORD *)(a10 + 64);
  if ( !v11 )
    return 4;
  *a11 = *(_DWORD *)(v11 + 4);
  a11[1] = *(_DWORD *)(v11 + 8);
  qdf_trace_msg(0x31u, 8u, "%s: cca stats event processed", a1, a2, a3, a4, a5, a6, a7, a8, "extract_cca_stats_tlv");
  return 0;
}
