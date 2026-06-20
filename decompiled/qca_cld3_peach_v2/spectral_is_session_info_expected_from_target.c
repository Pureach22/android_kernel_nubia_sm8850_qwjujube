__int64 __fastcall spectral_is_session_info_expected_from_target(
        __int64 a1,
        _BYTE *a2,
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
  __int64 v12; // x0
  const char *v14; // x2

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 80);
    if ( v10 )
    {
      v11 = *(_QWORD *)(v10 + 2800);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 16);
        if ( v12 )
        {
          *a2 = wmi_service_enabled(v12, 0x104u, a3, a4, a5, a6, a7, a8, a9, a10) & 1;
          return 0;
        }
      }
      v14 = "%s: wmi handle is null";
    }
    else
    {
      v14 = "%s: psoc is null";
    }
  }
  else
  {
    v14 = "%s: pdev is null";
  }
  qdf_trace_msg(0x56u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "spectral_is_session_info_expected_from_target");
  return 29;
}
