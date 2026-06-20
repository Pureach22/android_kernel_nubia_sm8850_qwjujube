__int64 __fastcall cdp_cfg_get(
        __int64 **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  __int64 (*v10)(void); // x8

  if ( !a1 || !*a1 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_cfg_get");
    return 0;
  }
  v9 = **a1;
  if ( !v9 )
    return 0;
  v10 = *(__int64 (**)(void))(v9 + 264);
  if ( !v10 )
    return 0;
  if ( *((_DWORD *)v10 - 1) != -1095293032 )
    __break(0x8228u);
  return v10();
}
