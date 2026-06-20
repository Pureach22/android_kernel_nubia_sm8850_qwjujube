__int64 __fastcall wlan_cfg80211_tdls_osif_priv_deinit(
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
  __int64 v9; // x19
  __int64 result; // x0

  v9 = *(_QWORD *)(a1 + 680);
  if ( !v9 )
    return qdf_trace_msg(
             0x48u,
             2u,
             "%s: osif_priv is NULL!",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "wlan_cfg80211_tdls_osif_priv_deinit");
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: deinitialize tdls os if layer private structure",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_cfg80211_tdls_osif_priv_deinit");
  result = *(_QWORD *)(v9 + 16);
  if ( result )
    result = _qdf_mem_free(result);
  *(_QWORD *)(v9 + 16) = 0;
  return result;
}
