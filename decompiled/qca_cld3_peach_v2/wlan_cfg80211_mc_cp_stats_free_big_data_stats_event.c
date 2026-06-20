__int64 __fastcall wlan_cfg80211_mc_cp_stats_free_big_data_stats_event(__int64 result)
{
  if ( result )
    return _qdf_mem_free(result);
  return result;
}
