__int64 __fastcall target_if_extract_pdev_spectral_session_chan_info(
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
  __int64 v10; // x0

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 16);
      if ( v10 )
        return wmi_extract_pdev_spectral_session_chan_info(v10);
    }
  }
  qdf_trace_msg(
    0x56u,
    2u,
    "%s: WMI handle is null",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "target_if_extract_pdev_spectral_session_chan_info");
  return 29;
}
