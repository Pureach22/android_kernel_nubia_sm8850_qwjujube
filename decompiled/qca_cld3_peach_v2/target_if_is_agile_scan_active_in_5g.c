void __fastcall target_if_is_agile_scan_active_in_5g(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _BYTE *a11)
{
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  int curr_band; // w0
  const char *v27; // x2
  unsigned int v28; // w1
  const char *v29; // x2
  unsigned int (__fastcall *v30)(__int64, __int64); // x8

  if ( (*a11 & 1) != 0 )
    return;
  if ( !a10 )
  {
    v29 = "%s: pdev is null";
LABEL_14:
    qdf_trace_msg(0x56u, 2u, v29, a1, a2, a3, a4, a5, a6, a7, a8, "get_target_if_spectral_handle_from_pdev");
LABEL_15:
    v27 = "%s: target if spectral handle is NULL";
    v28 = 2;
LABEL_16:
    qdf_trace_msg(0x56u, v28, v27, v17, v18, v19, v20, v21, v22, v23, v24, "target_if_is_agile_scan_active_in_5g");
    return;
  }
  v11 = *(_QWORD *)(a10 + 80);
  if ( !v11 )
  {
    v29 = "%s: psoc is null";
    goto LABEL_14;
  }
  v12 = *(_QWORD *)(v11 + 2136);
  if ( !v12 )
  {
    v29 = "%s: rx_ops is null";
    goto LABEL_14;
  }
  v13 = *(__int64 (__fastcall **)(_QWORD))(v12 + 256);
  if ( *((_DWORD *)v13 - 1) != 1565325861 )
    __break(0x8228u);
  v16 = v13(a10);
  if ( !v16 )
    goto LABEL_15;
  v25 = v16;
  curr_band = target_if_get_curr_band(a10, *(_BYTE *)(v16 + 361), v17, v18, v19, v20, v21, v22, v23, v24);
  if ( curr_band != 1 )
  {
    if ( curr_band != 3 )
      return;
    v27 = "%s: Failed to get current band";
    v28 = 8;
    goto LABEL_16;
  }
  v30 = *(unsigned int (__fastcall **)(__int64, __int64))(v25 + 40);
  if ( *((_DWORD *)v30 - 1) != 362784388 )
    __break(0x8228u);
  if ( v30(v25, 1) )
    *a11 = 1;
}
