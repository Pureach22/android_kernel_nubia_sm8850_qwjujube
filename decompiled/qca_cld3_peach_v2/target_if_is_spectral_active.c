bool __fastcall target_if_is_spectral_active(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 (*v12)(void); // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 (__fastcall *v17)(_QWORD); // x8
  __int64 v18; // x0
  const char *v19; // x2
  unsigned int v20; // w1
  const char *v21; // x2
  const char *v23; // x2
  unsigned int (*v24)(void); // x8

  if ( !a1 )
  {
    v19 = "%s: pdev is null";
LABEL_16:
    v20 = 2;
LABEL_21:
    qdf_trace_msg(0x56u, v20, v19, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_is_spectral_active");
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    v21 = "%s: psoc is NULL";
LABEL_19:
    qdf_trace_msg(0x56u, 2u, v21, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_spectral_is_feature_disabled_pdev");
LABEL_20:
    v19 = "%s: Spectral feature is disabled";
    v20 = 4;
    goto LABEL_21;
  }
  v11 = *(_QWORD *)(v10 + 2136);
  if ( !v11 )
  {
    v21 = "%s: rx_ops is null";
    goto LABEL_19;
  }
  v12 = *(__int64 (**)(void))(v11 + 304);
  if ( !v12 )
    goto LABEL_20;
  if ( *((_DWORD *)v12 - 1) != -1102235987 )
    __break(0x8228u);
  if ( (v12() & 1) != 0 )
    goto LABEL_20;
  v15 = *(_QWORD *)(a1 + 80);
  if ( !v15 )
  {
    v23 = "%s: psoc is null";
LABEL_26:
    qdf_trace_msg(0x56u, 2u, v23, a3, a4, a5, a6, a7, a8, a9, a10, "get_target_if_spectral_handle_from_pdev");
LABEL_27:
    v19 = "%s: SPECTRAL : Module doesn't exist";
    goto LABEL_16;
  }
  v16 = *(_QWORD *)(v15 + 2136);
  if ( !v16 )
  {
    v23 = "%s: rx_ops is null";
    goto LABEL_26;
  }
  v17 = *(__int64 (__fastcall **)(_QWORD))(v16 + 256);
  if ( *((_DWORD *)v17 - 1) != 1565325861 )
    __break(0x8228u);
  v18 = v17(a1);
  if ( !v18 )
    goto LABEL_27;
  if ( a2 >= 2 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_is_spectral_active",
      a2);
    return 0;
  }
  v24 = *(unsigned int (**)(void))(v18 + 40);
  if ( *((_DWORD *)v24 - 1) != 362784388 )
    __break(0x8228u);
  return v24() != 0;
}
