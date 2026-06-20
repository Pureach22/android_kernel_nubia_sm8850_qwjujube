__int64 ieee80211_iface_exit()
{
  return unregister_netdevice_notifier(&mac80211_netdev_notifier);
}
