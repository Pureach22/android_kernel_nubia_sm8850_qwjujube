__int64 __fastcall dp_set_cfr_rcc(
        __int64 result,
        char a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8

  if ( a2 )
    return qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "dp_set_cfr_rcc", v11, v12);
  v13 = *(_QWORD *)(result + 72);
  if ( !v13 )
    return qdf_trace_msg(0x45u, 2u, "%s: pdev is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "dp_set_cfr_rcc", v11, v12);
  *(_BYTE *)(v13 + 95040) = a3 & 1;
  return result;
}
