__int64 __fastcall spectral_register_dbr(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  if ( a1 )
  {
    if ( (~*(_DWORD *)(a1 + 16) & 0x1F0) != 0 )
      return tgt_spectral_register_to_dbr(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: pdev is NULL!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_spectral_is_feature_disabled_pdev");
  }
  qdf_trace_msg(0x56u, 4u, "%s: spectral feature is disabled", a3, a4, a5, a6, a7, a8, a9, a10, "spectral_register_dbr");
  return 39;
}
