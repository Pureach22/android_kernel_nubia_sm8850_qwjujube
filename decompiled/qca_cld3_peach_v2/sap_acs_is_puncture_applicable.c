__int64 __fastcall sap_acs_is_puncture_applicable(
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
  __int64 v9; // x29
  __int64 v10; // x30
  unsigned int v11; // w9
  char v12; // w8

  if ( a1 )
  {
    v11 = *(unsigned __int16 *)(a1 + 42);
    v12 = 0;
    if ( v11 <= 7 && ((1 << v11) & 0x9C) != 0 )
      v12 = *(_BYTE *)(a1 + 584);
    return v12 & 1;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: Invalid parameters",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "sap_acs_is_puncture_applicable",
      v9,
      v10);
    return 0;
  }
}
