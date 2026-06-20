_UNKNOWN **__fastcall cfg80211_rdev_by_wiphy_idx(int a1)
{
  __int64 v2; // x0
  _UNKNOWN **v3; // x9
  __int64 v5; // x0

  v2 = ((__int64 (*)(void))rtnl_is_locked)();
  if ( (_DWORD)v2 || (cfg80211_rdev_by_wiphy_idx___already_done & 1) != 0 )
  {
    if ( !(unsigned int)rtnl_is_locked(v2) )
      goto LABEL_4;
  }
  else
  {
    cfg80211_rdev_by_wiphy_idx___already_done = 1;
    v5 = _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 61);
    __break(0x800u);
    if ( !(unsigned int)rtnl_is_locked(v5) )
    {
LABEL_4:
      if ( (for_each_rdev_check_rtnl___already_done_0 & 1) == 0 )
      {
        for_each_rdev_check_rtnl___already_done_0 = 1;
        _warn_printk(
          "RTNL: assertion failed at %s (%d)\n",
          "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
          166);
        __break(0x800u);
      }
    }
  }
  v3 = &cfg80211_rdev_list;
  while ( 1 )
  {
    v3 = (_UNKNOWN **)*v3;
    if ( v3 == &cfg80211_rdev_list )
      break;
    if ( *((_DWORD *)v3 + 23) == a1 )
      return v3 - 1;
  }
  return nullptr;
}
