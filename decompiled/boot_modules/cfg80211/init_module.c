__int64 init_module()
{
  unsigned int v0; // w19

  v0 = register_pernet_device(&cfg80211_pernet_ops);
  if ( !v0 )
  {
    v0 = wiphy_sysfs_init();
    if ( !v0 )
    {
      v0 = register_netdevice_notifier(&cfg80211_netdev_notifier);
      if ( !v0 )
      {
        v0 = nl80211_init();
        if ( !v0 )
        {
          ieee80211_debugfs_dir = debugfs_create_dir("ieee80211", 0);
          v0 = regulatory_init();
          if ( !v0 )
          {
            cfg80211_wq = alloc_workqueue("cfg80211", 131082, 1);
            if ( cfg80211_wq )
              return 0;
            regulatory_exit();
            v0 = -12;
          }
          debugfs_remove(ieee80211_debugfs_dir);
          nl80211_exit();
        }
        unregister_netdevice_notifier(&cfg80211_netdev_notifier);
      }
      wiphy_sysfs_exit();
    }
    unregister_pernet_device(&cfg80211_pernet_ops);
  }
  return v0;
}
