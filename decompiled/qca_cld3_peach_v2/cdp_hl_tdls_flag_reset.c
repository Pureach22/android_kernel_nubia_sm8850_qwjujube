__int64 __fastcall cdp_hl_tdls_flag_reset(
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

  if ( !*(_QWORD *)result )
    return qdf_trace_msg(0x45u, 1u, "%s invalid instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_hl_tdls_flag_reset");
  v9 = *(_QWORD *)(*(_QWORD *)result + 64LL);
  if ( !v9 )
    return qdf_trace_msg(0x45u, 1u, "%s invalid instance", a2, a3, a4, a5, a6, a7, a8, a9, "cdp_hl_tdls_flag_reset");
  v10 = *(__int64 (**)(void))(v9 + 32);
  if ( v10 )
  {
    if ( *((_DWORD *)v10 - 1) != 1944199495 )
      __break(0x8228u);
    return v10();
  }
  return result;
}
