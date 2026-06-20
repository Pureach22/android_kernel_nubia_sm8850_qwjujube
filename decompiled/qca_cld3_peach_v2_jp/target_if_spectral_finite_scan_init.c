__int64 __fastcall target_if_spectral_finite_scan_init(
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
  __int64 v10; // x4
  const char *v11; // x2
  const char *v12; // x3
  __int64 v13; // x9
  __int64 v14; // x12
  int v15; // w10
  int v16; // w11
  unsigned int v17; // w9
  int v18; // w10
  __int64 v19; // x8
  __int64 v20; // x3
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  v10 = *(unsigned int *)(a1 + 4LL * a2 + 1184);
  if ( (unsigned int)v10 >= 8 )
  {
    v11 = "%s: Invalid channel width %d";
    v12 = "target_if_spectral_get_num_detectors";
LABEL_10:
    qdf_trace_msg(0x56u, 2u, v11, a3, a4, a5, a6, a7, a8, a9, a10, v12);
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Failed to get number of detectors",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "target_if_spectral_finite_scan_init");
    return 16;
  }
  if ( (unsigned int)v10 >= 5 )
  {
    v11 = "%s: Unsupported channel width %d";
    v12 = "target_if_spectral_get_num_detectors_for_higher_bws";
    goto LABEL_10;
  }
  v13 = a1 + 80LL * a2;
  v14 = a1 + 16LL * a2;
  v15 = *(_DWORD *)(a1 + 4 * v10 + 208);
  *(_BYTE *)(v14 + 1468) = 1;
  v16 = *(unsigned __int16 *)(v13 + 646);
  v17 = *(_DWORD *)(v13 + 716);
  *(_BYTE *)(v14 + 1480) = 0;
  v18 = v15 * v16;
  *(_DWORD *)(v14 + 1476) = v18;
  *(_DWORD *)(v14 + 1472) = v18;
  if ( v17 )
  {
    v19 = a1 + 96LL * a2;
    if ( *(_DWORD *)(v19 + 2160) == 1 )
      v20 = 5;
    else
      v20 = 1;
    hrtimer_start_range_ns(v19 + 2096, 1000LL * v17, 0, v20);
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      4u,
      "%s: Timer is not started as timeout value is set to 0",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_spectral_scan_start_timer");
  }
  return 0;
}
