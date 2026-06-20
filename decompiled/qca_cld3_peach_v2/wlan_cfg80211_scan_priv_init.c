__int64 __fastcall wlan_cfg80211_scan_priv_init(__int64 a1)
{
  __int16 v2; // w0
  __int64 v3; // x21
  __int16 v4; // w20
  __int64 v5; // x0
  __int64 v6; // x21

  v2 = wlan_scan_register_requester(*(_QWORD *)(a1 + 80), "CFG", wlan_cfg80211_scan_done_callback, 0);
  v3 = *(_QWORD *)(a1 + 24);
  v4 = v2;
  v5 = _qdf_mem_malloc(360, "wlan_cfg80211_scan_priv_init", 1312);
  if ( !v5 )
    return 2;
  *(_QWORD *)(v3 + 16) = v5;
  v6 = v5;
  *(_WORD *)(v5 + 88) = v4;
  *(_QWORD *)v5 = v5;
  *(_QWORD *)(v5 + 8) = v5;
  *(_QWORD *)(v5 + 16) = 0x800000000LL;
  qdf_mutex_create(v5 + 24, "wlan_cfg80211_scan_priv_init", 1320);
  _qdf_wake_lock_create(v6 + 104, "scan_wake_lock", "wlan_cfg80211_scan_priv_init", 1321);
  *(_DWORD *)(v6 + 304) = 0;
  qdf_event_create(v6 + 312);
  wlan_scan_register_cached_scan_ev_handler(a1);
  return 0;
}
