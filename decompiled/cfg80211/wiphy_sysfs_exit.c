__int64 wiphy_sysfs_exit()
{
  return class_unregister(&ieee80211_class);
}
