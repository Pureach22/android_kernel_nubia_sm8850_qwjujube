__int64 __fastcall target_if_spectral_dump_fft(
        unsigned __int8 *a1,
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x22
  unsigned int v29; // t1

  qdf_trace_msg(
    0x56u,
    8u,
    "%s: SPECTRAL : FFT Length is 0x%x (%d)",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_spectral_dump_fft",
    a2,
    a2);
  qdf_trace_msg(0x56u, 8u, "%s: fft_data # ", v12, v13, v14, v15, v16, v17, v18, v19, "target_if_spectral_dump_fft");
  if ( (int)a2 >= 1 )
  {
    v28 = a2;
    do
    {
      v29 = *a1++;
      qdf_trace_msg(0x56u, 8u, "%s: %d ", v20, v21, v22, v23, v24, v25, v26, v27, "target_if_spectral_dump_fft", v29);
      --v28;
    }
    while ( v28 );
  }
  qdf_trace_msg(0x56u, 8u, "%s: \n", v20, v21, v22, v23, v24, v25, v26, v27, "target_if_spectral_dump_fft");
  return 0;
}
