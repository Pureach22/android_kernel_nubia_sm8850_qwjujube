__int64 __fastcall get_target_if_spectral_handle_from_pdev(
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
  const char *v13; // x2

  if ( !a1 )
  {
    v13 = "%s: pdev is null";
LABEL_10:
    qdf_trace_msg(0x56u, 2u, v13, a2, a3, a4, a5, a6, a7, a8, a9, "get_target_if_spectral_handle_from_pdev");
    return 0;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v13 = "%s: psoc is null";
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(v9 + 2136);
  if ( !v10 )
  {
    v13 = "%s: rx_ops is null";
    goto LABEL_10;
  }
  v11 = *(__int64 (**)(void))(v10 + 256);
  if ( *((_DWORD *)v11 - 1) != 1565325861 )
    __break(0x8228u);
  return v11();
}
