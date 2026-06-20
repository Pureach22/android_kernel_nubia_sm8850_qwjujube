__int64 __fastcall update_all_wiphy_regulatory(__int64 a1)
{
  unsigned int v1; // w19
  __int64 is_locked; // x0
  _UNKNOWN **v3; // x21
  __int64 v5; // x0

  v1 = a1;
  is_locked = rtnl_is_locked(a1);
  if ( (_DWORD)is_locked || (update_all_wiphy_regulatory___already_done & 1) != 0 )
  {
    if ( (unsigned int)rtnl_is_locked(is_locked) )
      goto LABEL_6;
  }
  else
  {
    update_all_wiphy_regulatory___already_done = 1;
    v5 = _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 2535);
    __break(0x800u);
    if ( (unsigned int)rtnl_is_locked(v5) )
      goto LABEL_6;
  }
  if ( (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_2 = 1;
    _warn_printk(
      "RTNL: assertion failed at %s (%d)\n",
      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
      166);
    __break(0x800u);
  }
LABEL_6:
  v3 = (_UNKNOWN **)cfg80211_rdev_list;
  if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
  {
    do
    {
      wiphy_update_regulatory(v3 + 123, v1);
      v3 = (_UNKNOWN **)*v3;
    }
    while ( v3 != &cfg80211_rdev_list );
  }
  return mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
}
