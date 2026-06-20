void *__fastcall reset_regdomains(__int64 a1, unsigned __int64 a2)
{
  char v3; // w19
  void *result; // x0
  void *v5; // x1

  v3 = a1;
  if ( !(unsigned int)rtnl_is_locked(a1) && (reset_regdomains___already_done & 1) == 0 )
  {
    reset_regdomains___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 328);
    __break(0x800u);
  }
  result = cfg80211_world_regdom;
  if ( (_UNKNOWN *)cfg80211_regdomain == cfg80211_world_regdom )
    v5 = nullptr;
  else
    v5 = (void *)cfg80211_regdomain;
  if ( cfg80211_world_regdom == &world_regdom )
  {
    result = nullptr;
    cfg80211_world_regdom = nullptr;
  }
  if ( v5 != &world_regdom && v5 )
  {
    kvfree_call_rcu(v5, v5);
    result = cfg80211_world_regdom;
  }
  if ( result )
    result = (void *)kvfree_call_rcu(result, result);
  cfg80211_world_regdom = &world_regdom;
  atomic_store(a2, (unsigned __int64 *)&cfg80211_regdomain);
  if ( (v3 & 1) != 0 && last_request != &core_request_world )
  {
    result = last_request;
    if ( last_request )
      result = (void *)kvfree_call_rcu(last_request, last_request);
    atomic_store((unsigned __int64)&core_request_world, (unsigned __int64 *)&last_request);
  }
  return result;
}
