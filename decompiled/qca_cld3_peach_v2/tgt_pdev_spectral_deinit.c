__int64 __fastcall tgt_pdev_spectral_deinit(
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
  __int64 v10; // x8
  __int64 (*v11)(void); // x8

  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
    return qdf_trace_msg(0x56u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_pdev_spectral_deinit");
  v10 = *(_QWORD *)(v9 + 2128);
  if ( !v10 )
    return qdf_trace_msg(0x56u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_pdev_spectral_deinit");
  v11 = *(__int64 (**)(void))(v10 + 496);
  if ( *((_DWORD *)v11 - 1) != 883436542 )
    __break(0x8228u);
  return v11();
}
