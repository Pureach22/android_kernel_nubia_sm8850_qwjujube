__int64 __fastcall target_if_spectral_direct_dma_support(
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
  __int64 v12; // x0
  char v13; // w8
  const char *v14; // x2
  const char *v15; // x2

  if ( !a1 )
  {
    v14 = "%s: pdev is NULL!";
LABEL_13:
    qdf_trace_msg(0x56u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_spectral_direct_dma_support");
    v13 = 0;
    return v13 & 1;
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v15 = "%s: psoc is null";
LABEL_11:
    qdf_trace_msg(0x56u, 2u, v15, a2, a3, a4, a5, a6, a7, a8, a9, "get_target_if_spectral_handle_from_pdev");
LABEL_12:
    v14 = "%s: Spectral LMAC object is NULL";
    goto LABEL_13;
  }
  v10 = *(_QWORD *)(v9 + 2136);
  if ( !v10 )
  {
    v15 = "%s: rx_ops is null";
    goto LABEL_11;
  }
  v11 = *(__int64 (**)(void))(v10 + 256);
  if ( *((_DWORD *)v11 - 1) != 1565325861 )
    __break(0x8228u);
  v12 = v11();
  if ( !v12 )
    goto LABEL_12;
  v13 = *(_BYTE *)(v12 + 1386);
  return v13 & 1;
}
