__int64 __fastcall wlan_cfg80211_scan_priv_deinit(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x22
  __int64 v4; // x20
  __int64 v5; // x8

  v1 = *(_QWORD *)(a1 + 80);
  v2 = *(_QWORD *)(a1 + 24);
  wlan_cfg80211_cleanup_scan_queue();
  v4 = *(_QWORD *)(v2 + 16);
  ((void (__fastcall *)(__int64))wlan_scan_deregister_cached_scan_ev_handler)(a1);
  v5 = *(_QWORD *)(v4 + 352);
  if ( v5 )
  {
    _qdf_mem_free(*(_QWORD *)(v5 + 16));
    _qdf_mem_free(*(_QWORD *)(*(_QWORD *)(v4 + 352) + 24LL));
    _qdf_mem_free(*(_QWORD *)(v4 + 352));
    *(_QWORD *)(v4 + 352) = 0;
  }
  qdf_event_destroy(v4 + 312);
  *(_DWORD *)(v4 + 304) = 0;
  _qdf_wake_lock_destroy(v4 + 104, "wlan_cfg80211_scan_priv_deinit", 1341);
  qdf_mutex_destroy(v4 + 24);
  if ( *(_DWORD *)(v4 + 16) )
    qdf_trace_msg(51, 2, "%s: list length not equal to zero", "qdf_list_destroy");
  wlan_scan_unregister_requester(v1, *(unsigned __int16 *)(v4 + 88));
  *(_QWORD *)(v2 + 16) = 0;
  _qdf_mem_free(v4);
  return 0;
}
