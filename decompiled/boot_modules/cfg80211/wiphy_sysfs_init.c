__int64 wiphy_sysfs_init()
{
  return class_register(&ieee80211_class);
}
