__int64 __fastcall ieee80211_del_virtual_monitor(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x0

  if ( !(unsigned int)rtnl_is_locked() && (ieee80211_del_virtual_monitor___already_done & 1) == 0 )
  {
    ieee80211_del_virtual_monitor___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/mac80211/iface.c", 1196);
    __break(0x800u);
  }
  mutex_lock(a1 + 4648);
  v2 = *(_QWORD *)(a1 + 5384);
  if ( !v2 )
    return mutex_unlock(a1 + 4648);
  *(_QWORD *)(a1 + 5384) = 0;
  v3 = mutex_unlock(a1 + 4648);
  synchronize_net(v3);
  ieee80211_link_release_channel((__int64 *)(v2 + 3616));
  if ( (*(_QWORD *)(a1 + 96) & 0x1000) != 0 )
    drv_remove_interface(a1, v2);
  return kfree(v2);
}
