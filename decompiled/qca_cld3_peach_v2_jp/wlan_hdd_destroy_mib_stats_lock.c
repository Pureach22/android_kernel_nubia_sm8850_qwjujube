__int64 wlan_hdd_destroy_mib_stats_lock()
{
  return qdf_mutex_destroy((__int64)&mibstats_lock);
}
