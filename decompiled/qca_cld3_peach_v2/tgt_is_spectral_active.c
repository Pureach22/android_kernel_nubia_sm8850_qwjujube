__int64 __fastcall tgt_is_spectral_active(
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
  char v12; // w0

  v9 = *(_QWORD *)(a1 + 80);
  if ( v9 && (v10 = *(_QWORD *)(v9 + 2128)) != 0 )
  {
    v11 = *(__int64 (**)(void))(v10 + 552);
    if ( *((_DWORD *)v11 - 1) != -907325943 )
      __break(0x8228u);
    v12 = v11();
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: tx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "tgt_is_spectral_active");
    v12 = 0;
  }
  return v12 & 1;
}
