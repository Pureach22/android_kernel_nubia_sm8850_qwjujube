__int64 __fastcall dp_soc_notify_asserted_soc(
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
  __int64 (*v9)(void); // x8

  if ( !a1 )
  {
    qdf_trace_msg(0x89u, 2u, "%s: %pK: soc is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "dp_soc_notify_asserted_soc", 0);
    return 4;
  }
  v9 = *(__int64 (**)(void))(a1 + 1488);
  if ( !v9 )
    return 4;
  if ( *((_DWORD *)v9 - 1) != -1941278151 )
    __break(0x8228u);
  return v9();
}
