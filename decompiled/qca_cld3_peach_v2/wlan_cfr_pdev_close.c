__int64 __fastcall wlan_cfr_pdev_close(
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
    if ( (*(_BYTE *)(a1 + 16) & 1) != 0 )
      return cfr_streamfs_remove(a1);
  }
  else
  {
    qdf_trace_msg(0x6Au, 2u, "%s: PDEV is NULL!", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_is_feature_disabled");
  }
  qdf_trace_msg(0x6Au, 2u, "%s: cfr is disabled", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfr_pdev_close");
  return 39;
}
