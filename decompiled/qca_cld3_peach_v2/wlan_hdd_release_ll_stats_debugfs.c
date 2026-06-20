__int64 wlan_hdd_release_ll_stats_debugfs()
{
  mutex_lock(&llstats_mutex);
  _qdf_mem_free(ll_stats_1);
  ll_stats_1 = 0;
  ll_stats_0 = 0;
  mutex_unlock(&llstats_mutex);
  return 0;
}
