__int64 __fastcall cdp_txrx_get_pdev_param(
        __int64 result,
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

  if ( !result || !*(_QWORD *)result )
    return qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance:", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_txrx_get_pdev_param");
  v9 = *(_QWORD *)(*(_QWORD *)result + 8LL);
  if ( v9 )
  {
    v10 = *(__int64 (**)(void))(v9 + 104);
    if ( v10 )
    {
      if ( *((_DWORD *)v10 - 1) != 1753033934 )
        __break(0x8228u);
      return v10();
    }
  }
  return result;
}
