__int64 __fastcall cdp_txrx_stats_request(
        __int64 **a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x8
  __int64 (*v12)(void); // x8

  if ( !a1 || !*a1 || !a11 || (v11 = **a1) == 0 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_txrx_stats_request");
    return 0;
  }
  v12 = *(__int64 (**)(void))(v11 + 520);
  if ( !v12 )
    return 0;
  if ( *((_DWORD *)v12 - 1) != -242941968 )
    __break(0x8228u);
  return v12();
}
