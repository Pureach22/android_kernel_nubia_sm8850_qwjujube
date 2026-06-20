__int64 __fastcall cfg80211_destroy_iface_wk(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x0

  v1 = a1 - 664;
  rtnl_lock();
  v2 = cfg80211_destroy_ifaces(v1);
  return rtnl_unlock(v2);
}
