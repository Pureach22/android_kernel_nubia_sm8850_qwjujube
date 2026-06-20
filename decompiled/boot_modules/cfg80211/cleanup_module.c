__int64 cleanup_module()
{
  debugfs_remove(ieee80211_debugfs_dir);
  nl80211_exit();
  unregister_netdevice_notifier(&cfg80211_netdev_notifier);
  wiphy_sysfs_exit();
  regulatory_exit();
  unregister_pernet_device(&cfg80211_pernet_ops);
  return destroy_workqueue(cfg80211_wq);
}
