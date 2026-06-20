_UNKNOWN **__fastcall wiphy_idx_to_wiphy(__int64 a1)
{
  int v1; // w19
  __int64 is_locked; // x0
  __int64 v3; // x0
  _UNKNOWN **v4; // x9
  _UNKNOWN **v5; // x8
  __int64 v7; // x0

  v1 = a1;
  is_locked = rtnl_is_locked(a1);
  if ( (_DWORD)is_locked || (wiphy_idx_to_wiphy___already_done & 1) != 0 )
  {
    v3 = rtnl_is_locked(is_locked);
    if ( !(_DWORD)v3 )
      goto LABEL_4;
  }
  else
  {
    wiphy_idx_to_wiphy___already_done = 1;
    v7 = _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 84);
    __break(0x800u);
    v3 = rtnl_is_locked(v7);
    if ( !(_DWORD)v3 )
    {
LABEL_4:
      if ( (cfg80211_rdev_by_wiphy_idx___already_done & 1) == 0 )
      {
        cfg80211_rdev_by_wiphy_idx___already_done = 1;
        v3 = _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 61);
        __break(0x800u);
      }
    }
  }
  if ( !(unsigned int)rtnl_is_locked(v3) && (for_each_rdev_check_rtnl___already_done_0 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_0 = 1;
    _warn_printk(
      "RTNL: assertion failed at %s (%d)\n",
      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
      166);
    __break(0x800u);
  }
  v4 = &cfg80211_rdev_list;
  while ( 1 )
  {
    v4 = (_UNKNOWN **)*v4;
    if ( v4 == &cfg80211_rdev_list )
      break;
    if ( *((_DWORD *)v4 + 23) == v1 )
    {
      v5 = v4 - 1;
      goto LABEL_14;
    }
  }
  v5 = nullptr;
LABEL_14:
  if ( v5 )
    return v5 + 124;
  else
    return nullptr;
}
