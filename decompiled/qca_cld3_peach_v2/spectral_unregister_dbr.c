__int64 __fastcall spectral_unregister_dbr(
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
    if ( (~*(_DWORD *)(a1 + 16) & 0x1F0) != 0 )
      return tgt_spectral_unregister_to_dbr(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: pdev is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_spectral_is_feature_disabled_pdev");
  }
  qdf_trace_msg(
    0x56u,
    4u,
    "%s: spectral feature is disabled",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "spectral_unregister_dbr");
  return 39;
}
