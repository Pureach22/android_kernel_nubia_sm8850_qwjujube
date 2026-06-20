__int64 nl80211_exit()
{
  netlink_unregister_notifier(&nl80211_netlink_notifier);
  return genl_unregister_family(&nl80211_fam);
}
