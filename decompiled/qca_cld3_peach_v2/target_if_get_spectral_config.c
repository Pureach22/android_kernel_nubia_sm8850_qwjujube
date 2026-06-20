__int64 __fastcall target_if_get_spectral_config(
        __int64 a1,
        void *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  const char *v25; // x2
  __int64 v27; // x21
  _DWORD *v28; // x8

  if ( !a1 )
  {
    v25 = "%s: pdev is null";
LABEL_12:
    qdf_trace_msg(0x56u, 2u, v25, a4, a5, a6, a7, a8, a9, a10, a11, "get_target_if_spectral_handle_from_pdev");
LABEL_13:
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: SPECTRAL : Module doesn't exist",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_get_spectral_config");
    return 16;
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v25 = "%s: psoc is null";
    goto LABEL_12;
  }
  v12 = *(_QWORD *)(v11 + 2136);
  if ( !v12 )
  {
    v25 = "%s: rx_ops is null";
    goto LABEL_12;
  }
  v13 = *(__int64 (**)(void))(v12 + 256);
  if ( *((_DWORD *)v13 - 1) != 1565325861 )
    __break(0x8228u);
  v16 = v13();
  if ( !v16 )
    goto LABEL_13;
  if ( a3 >= 2 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "target_if_get_spectral_config",
      a3);
    return 16;
  }
  v27 = v16;
  qdf_mem_set(a2, 0x50u, 0);
  v28 = *(_DWORD **)(v27 + 104);
  if ( *(v28 - 1) != 2051770554 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, void *, _QWORD))v28)(v27, a2, a3);
  return 0;
}
