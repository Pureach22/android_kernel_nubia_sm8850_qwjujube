__int64 nl80211_init()
{
  unsigned int v0; // w19

  v0 = genl_register_family(&nl80211_fam);
  if ( !v0 )
  {
    v0 = netlink_register_notifier(&nl80211_netlink_notifier);
    if ( v0 )
      genl_unregister_family(&nl80211_fam);
  }
  return v0;
}
