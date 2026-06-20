__int64 __fastcall target_if_spectral_wmi_extract_pdev_sscan_fft_bin_index(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x8
  __int64 v12; // x0
  const char *v14; // x2

  if ( a11 )
  {
    if ( a1 )
    {
      v11 = *(_QWORD *)(a1 + 2800);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 16);
        if ( v12 )
          return wmi_extract_pdev_sscan_fft_bin_index(v12);
      }
    }
    v14 = "%s: WMI handle is null";
  }
  else
  {
    v14 = "%s: Spectral FFT bin markers is null";
  }
  qdf_trace_msg(
    0x56u,
    2u,
    v14,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "target_if_spectral_wmi_extract_pdev_sscan_fft_bin_index");
  return 4;
}
