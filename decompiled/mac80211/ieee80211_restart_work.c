__int64 __fastcall ieee80211_restart_work(__int64 a1)
{
  __int64 v2; // x0
  __int64 *i; // x20
  __int64 v4; // x0
  int v5; // w20
  __int64 v6; // x0

  v2 = _flush_workqueue(*(_QWORD *)(a1 - 4688));
  rtnl_lock(v2);
  mutex_lock(*(_QWORD *)(a1 - 5088));
  wiphy_work_flush(*(_QWORD *)(a1 - 5088), 0);
  if ( (*(_QWORD *)(a1 - 464) & 2) != 0 )
  {
    _warn_printk("%s called with hardware scan in progress\n", "ieee80211_restart_work");
    __break(0x800u);
  }
  for ( i = *(__int64 **)(a1 - 544); i != (__int64 *)(a1 - 544); i = (__int64 *)*i )
  {
    if ( *((_DWORD *)i + 1180) == 2 )
    {
      wiphy_work_cancel(*(_QWORD *)(a1 - 5088), i + 304);
      if ( *((_BYTE *)i + 5638) == 1 )
        ieee80211_sta_connection_lost(i, 1, 0);
    }
    wiphy_delayed_work_flush(*(_QWORD *)(a1 - 5088), i + 192);
  }
  ieee80211_scan_cancel(a1 - 5160);
  wiphy_delayed_work_flush(*(_QWORD *)(a1 - 5088), a1 + 32);
  v4 = wiphy_work_flush(*(_QWORD *)(a1 - 5088), a1 + 144);
  synchronize_net(v4);
  v5 = ieee80211_reconfig(a1 - 5160);
  v6 = mutex_unlock(*(_QWORD *)(a1 - 5088));
  if ( v5 )
    v6 = cfg80211_shutdown_all_interfaces(*(_QWORD *)(a1 - 5088));
  return rtnl_unlock(v6);
}
