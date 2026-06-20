__int64 __fastcall target_if_pdev_spectral_deinit(
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
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  const char *v23; // x2

  if ( !a1 )
  {
    v23 = "%s: pdev is null";
LABEL_11:
    qdf_trace_msg(0x56u, 2u, v23, a2, a3, a4, a5, a6, a7, a8, a9, "get_target_if_spectral_handle_from_pdev");
    return qdf_trace_msg(
             0x56u,
             2u,
             "%s: SPECTRAL : Module doesn't exist",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20,
             "target_if_pdev_spectral_deinit");
  }
  v9 = *(_QWORD *)(a1 + 80);
  if ( !v9 )
  {
    v23 = "%s: psoc is null";
    goto LABEL_11;
  }
  v10 = *(_QWORD *)(v9 + 2136);
  if ( !v10 )
  {
    v23 = "%s: rx_ops is null";
    goto LABEL_11;
  }
  v11 = *(__int64 (**)(void))(v10 + 256);
  if ( *((_DWORD *)v11 - 1) != 1565325861 )
    __break(0x8228u);
  v12 = v11();
  if ( v12 )
  {
    v21 = v12;
    qdf_trace_msg(0x56u, 4u, "%s: spectral detach", v13, v14, v15, v16, v17, v18, v19, v20, "target_if_spectral_detach");
    hrtimer_cancel(v21 + 2096);
    hrtimer_cancel(v21 + 2192);
    return _qdf_mem_free(v21);
  }
  return qdf_trace_msg(
           0x56u,
           2u,
           "%s: SPECTRAL : Module doesn't exist",
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           v19,
           v20,
           "target_if_pdev_spectral_deinit");
}
