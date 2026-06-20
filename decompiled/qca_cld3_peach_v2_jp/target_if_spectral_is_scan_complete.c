__int64 __fastcall target_if_spectral_is_scan_complete(
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
  __int64 result; // x0
  __int64 v13; // x20
  __int64 v14; // x8
  char v15; // w8
  __int64 v16; // x20

  if ( !a1 )
  {
    v13 = jiffies;
    if ( target_if_spectral_is_scan_complete___last_ticks - jiffies + 125 < 0 )
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
        "target_if_spectral_is_scan_complete");
      target_if_spectral_is_scan_complete___last_ticks = v13;
      return 4;
    }
    return 4;
  }
  if ( a2 >= 2 )
  {
    v11 = jiffies;
    if ( target_if_spectral_is_scan_complete___last_ticks_55 - jiffies + 125 < 0 )
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
        "target_if_spectral_is_scan_complete",
        a2);
      target_if_spectral_is_scan_complete___last_ticks_55 = v11;
      return 4;
    }
    return 4;
  }
  if ( a3 )
  {
    v14 = a1 + 16LL * a2;
    if ( *(_BYTE *)(v14 + 1468) == 1 )
      v15 = *(_BYTE *)(v14 + 1480);
    else
      v15 = 0;
    result = 0;
    *a3 = v15;
  }
  else
  {
    v16 = jiffies;
    if ( target_if_spectral_is_scan_complete___last_ticks_56 - jiffies + 125 >= 0 )
      return 4;
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
      "target_if_spectral_is_scan_complete",
      a2);
    target_if_spectral_is_scan_complete___last_ticks_56 = v16;
    return 4;
  }
  return result;
}
