__int64 __fastcall tgt_cfr_validate_period(
        __int64 a1,
        unsigned int a2,
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
  __int64 (*v11)(void); // x8
  int v13; // w0
  __int64 v14; // x4
  const char *v15; // x2
  __int64 result; // x0
  char v17; // w8
  unsigned __int64 v18; // t2
  unsigned __int64 v19; // t2

  if ( !a1 || (v10 = *(_QWORD *)(a1 + 2128)) == 0 )
  {
    qdf_trace_msg(0x6Au, 2u, "%s: tx_ops is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_cfr_get_target_type");
LABEL_10:
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: cfr period validation fail due to invalid target type",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "tgt_cfr_validate_period");
    return 0;
  }
  v11 = *(__int64 (**)(void))(v10 + 1736);
  if ( !v11 )
    goto LABEL_10;
  if ( *((_DWORD *)v11 - 1) != 1468042957 )
    __break(0x8228u);
  v13 = v11();
  if ( !v13 )
    goto LABEL_10;
  v14 = a2;
  if ( a2 >= 0x927C1 )
  {
    v15 = "%s: Invalid period value: %d\n";
LABEL_19:
    qdf_trace_msg(0x6Au, 2u, v15, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_cfr_validate_period", v14);
    return 0;
  }
  v17 = v13 - 24;
  if ( (unsigned int)(v13 - 24) >= 0x12 )
  {
    HIDWORD(v19) = -858993459 * a2;
    LODWORD(v19) = -858993459 * a2;
    if ( (unsigned int)(v19 >> 1) < 0x1999999A )
      return 1;
    goto LABEL_18;
  }
  result = 1;
  HIDWORD(v18) = -858993459 * a2;
  LODWORD(v18) = -858993459 * a2;
  if ( (unsigned int)(v18 >> 1) >= 0x1999999A && ((0x28927u >> v17) & 1) == 0 )
  {
LABEL_18:
    v15 = "%s: Invalid period value. Value must be mod of %d";
    v14 = 10;
    goto LABEL_19;
  }
  return result;
}
