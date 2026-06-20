__int64 wlan_cfg80211_sched_scan_stop()
{
  if ( (unsigned int)ucfg_scan_pno_stop() )
    qdf_trace_msg(72, 8, "%s: Failed to disable PNO", "wlan_cfg80211_sched_scan_stop");
  return 0;
}
