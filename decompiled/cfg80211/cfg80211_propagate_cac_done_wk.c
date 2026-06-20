__int64 __fastcall cfg80211_propagate_cac_done_wk(__int64 a1)
{
  __int64 v2; // x0

  rtnl_lock();
  v2 = regulatory_propagate_dfs_state(a1 + 144, a1 - 32, 2, 1);
  return rtnl_unlock(v2);
}
