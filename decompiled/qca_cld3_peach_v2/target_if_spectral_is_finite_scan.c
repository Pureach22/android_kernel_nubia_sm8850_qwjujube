__int64 __fastcall target_if_spectral_is_finite_scan(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  __int64 v12; // x20
  __int64 v14; // x20

  if ( a1 )
  {
    if ( a2 < 2 )
    {
      if ( a3 )
      {
        *a3 = *(_BYTE *)(a1 + 16LL * a2 + 1468);
        return 0;
      }
      v14 = jiffies;
      if ( target_if_spectral_is_finite_scan___last_ticks_53 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Invalid pointer",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "target_if_spectral_is_finite_scan",
          a2);
        target_if_spectral_is_finite_scan___last_ticks_53 = v14;
      }
    }
    else
    {
      v11 = jiffies;
      if ( target_if_spectral_is_finite_scan___last_ticks_51 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: invalid spectral mode %d",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          "target_if_spectral_is_finite_scan",
          a2);
        target_if_spectral_is_finite_scan___last_ticks_51 = v11;
      }
    }
  }
  else
  {
    v12 = jiffies;
    if ( target_if_spectral_is_finite_scan___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: target if spectral object is null",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "target_if_spectral_is_finite_scan");
      target_if_spectral_is_finite_scan___last_ticks = v12;
    }
  }
  return 4;
}
