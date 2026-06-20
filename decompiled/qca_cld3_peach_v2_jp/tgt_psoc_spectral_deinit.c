__int64 __fastcall tgt_psoc_spectral_deinit(
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
  const char *v12; // x2

  if ( !a1 )
  {
    v12 = "%s: psoc is null";
    return qdf_trace_msg(0x56u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_psoc_spectral_deinit");
  }
  v9 = *(_QWORD *)(a1 + 2128);
  if ( !v9 )
  {
    v12 = "%s: tx_ops is NULL";
    return qdf_trace_msg(0x56u, 2u, v12, a2, a3, a4, a5, a6, a7, a8, a9, "tgt_psoc_spectral_deinit");
  }
  v10 = *(__int64 (**)(void))(v9 + 512);
  if ( *((_DWORD *)v10 - 1) != 1588979751 )
    __break(0x8228u);
  return v10();
}
