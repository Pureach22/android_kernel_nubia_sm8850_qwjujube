__int64 __fastcall ieee80211_if_remove(_QWORD *a1)
{
  _QWORD *v2; // x8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 result; // x0

  if ( !(unsigned int)rtnl_is_locked() && (ieee80211_if_remove___already_done & 1) == 0 )
  {
    ieee80211_if_remove___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 2228);
    __break(0x800u);
  }
  mutex_lock(a1[202] + 4648LL);
  v2 = (_QWORD *)a1[1];
  if ( (_QWORD *)*v2 == a1 && (v3 = *a1, *(_QWORD **)(*a1 + 8LL) == a1) )
  {
    *(_QWORD *)(v3 + 8) = v2;
    *v2 = v3;
  }
  else
  {
    _list_del_entry_valid_or_report(a1);
  }
  v4 = a1[202];
  a1[1] = 0xDEAD000000000122LL;
  v5 = mutex_unlock(v4 + 4648);
  v6 = a1[732];
  if ( v6 )
    v5 = ieee80211_txq_purge(a1[202], v6 - 232);
  synchronize_rcu(v5);
  result = cfg80211_unregister_wdev(a1 + 2);
  if ( !a1[201] )
  {
    ieee80211_free_keys(a1, 0);
    ieee80211_destroy_frag_cache(a1 + 207);
    ieee80211_vif_set_links(a1, 0, 0);
    ((void (__fastcall *)(_QWORD *))ieee80211_link_stop)(a1 + 452);
    return kfree(a1);
  }
  return result;
}
