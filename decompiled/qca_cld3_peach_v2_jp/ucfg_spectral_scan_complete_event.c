__int64 __fastcall ucfg_spectral_scan_complete_event(
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
    return wlan_cfg80211_spectral_scan_complete_event();
  qdf_trace_msg(0x56u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "ucfg_spectral_scan_complete_event");
  return 4;
}
