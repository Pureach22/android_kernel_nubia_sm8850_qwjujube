__int64 ieee80211_iface_init()
{
  return register_netdevice_notifier(&mac80211_netdev_notifier);
}
