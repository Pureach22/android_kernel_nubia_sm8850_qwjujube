__int64 __fastcall target_if_process_spectral_report(
        __int64 a1,
        __int64 a2,
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
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 (__fastcall *v24)(__int64, __int64); // x8
  const char *v26; // x2

  if ( !a1 )
  {
    v26 = "%s: pdev is null";
LABEL_13:
    qdf_trace_msg(0x56u, 2u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "get_target_if_spectral_handle_from_pdev");
LABEL_14:
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: SPECTRAL : Module doesn't exist",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "target_if_process_spectral_report");
    return 0xFFFFFFFFLL;
  }
  v10 = *(_QWORD *)(a1 + 80);
  if ( !v10 )
  {
    v26 = "%s: psoc is null";
    goto LABEL_13;
  }
  v11 = *(_QWORD *)(v10 + 2136);
  if ( !v11 )
  {
    v26 = "%s: rx_ops is null";
    goto LABEL_13;
  }
  v12 = *(__int64 (**)(void))(v11 + 256);
  if ( *((_DWORD *)v12 - 1) != 1565325861 )
    __break(0x8228u);
  v15 = v12();
  if ( !v15 )
    goto LABEL_14;
  v24 = *(__int64 (__fastcall **)(__int64, __int64))(v15 + 160);
  if ( *((_DWORD *)v24 - 1) != 1690999366 )
    __break(0x8228u);
  return v24(a1, a2);
}
