__int64 __fastcall wlan_spectral_psoc_disable(
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
  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 30) & 0x80) != 0 )
    {
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: Spectral feature is disabled",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_spectral_psoc_disable");
      return 39;
    }
    else
    {
      return tgt_spectral_unregister_events(a1, a2, a3, a4, a5, a6, a7, a8, a9);
    }
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_spectral_psoc_disable");
    return 4;
  }
}
