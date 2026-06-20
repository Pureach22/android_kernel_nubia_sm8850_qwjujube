__int64 __fastcall cdp_tx_non_std(
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
  __int64 v9; // x8
  __int64 (*v10)(void); // x8

  if ( !*(_QWORD *)a1 || (v9 = *(_QWORD *)(*(_QWORD *)a1 + 64LL)) == 0 )
  {
    qdf_trace_msg(0x89u, 8u, "%s: invalid instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_tx_non_std");
    return 0;
  }
  v10 = *(__int64 (**)(void))(v9 + 40);
  if ( !v10 )
    return 0;
  if ( *((_DWORD *)v10 - 1) != 1364159566 )
    __break(0x8228u);
  return v10();
}
