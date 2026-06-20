__int64 __fastcall sap_acs_set_puncture_support(
        __int64 result,
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
  unsigned int v11; // w9
  const char *v12; // x3

  if ( !result || !a2 )
  {
    v12 = "sap_acs_set_puncture_support";
    return qdf_trace_msg(0x39u, 2u, "%s: Invalid parameters", a3, a4, a5, a6, a7, a8, a9, a10, v12);
  }
  v10 = *(_QWORD *)(result + 1544);
  if ( !v10 )
  {
    v12 = "sap_acs_is_puncture_applicable";
    return qdf_trace_msg(0x39u, 2u, "%s: Invalid parameters", a3, a4, a5, a6, a7, a8, a9, a10, v12);
  }
  v11 = *(unsigned __int16 *)(v10 + 42);
  if ( v11 <= 7 && ((1 << v11) & 0x9C) != 0 && *(_BYTE *)(v10 + 584) == 1 )
    *(_BYTE *)(a2 + 20) = 1;
  return result;
}
