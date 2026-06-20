__int64 __fastcall is_wiphy_all_set_reg_flag(__int64 a1)
{
  int v1; // w19
  _UNKNOWN **v2; // x20
  _QWORD *v3; // x9

  v1 = a1;
  if ( !(unsigned int)rtnl_is_locked(a1) && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_2 = 1;
    _warn_printk(
      "RTNL: assertion failed at %s (%d)\n",
      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
      166);
    __break(0x800u);
  }
  v2 = (_UNKNOWN **)cfg80211_rdev_list;
  if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
  {
    do
    {
      mutex_lock(v2 + 123);
      v3 = v2 + 290;
      while ( 1 )
      {
        v3 = (_QWORD *)*v3;
        if ( v3 == v2 + 290 )
          break;
        if ( (*(_DWORD *)(*(v3 - 2) + 104LL) & v1) == 0 )
        {
          mutex_unlock(v2 + 123);
          return 0;
        }
      }
      mutex_unlock(v2 + 123);
      v2 = (_UNKNOWN **)*v2;
    }
    while ( v2 != &cfg80211_rdev_list );
  }
  return 1;
}
