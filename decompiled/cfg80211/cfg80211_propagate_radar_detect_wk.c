__int64 __fastcall cfg80211_propagate_radar_detect_wk(__int64 a1)
{
  __int64 v2; // x0

  rtnl_lock();
  v2 = regulatory_propagate_dfs_state(a1 + 208, a1 - 32, 1, 0);
  return rtnl_unlock(v2);
}
