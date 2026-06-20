__int64 __fastcall cfg80211_pernet_exit(void *a1)
{
  __int64 v2; // x0
  __int64 is_locked; // x0
  _UNKNOWN **v4; // x22

  v2 = rtnl_lock(a1);
  is_locked = rtnl_is_locked(v2);
  if ( !(_DWORD)is_locked && (for_each_rdev_check_rtnl___already_done_0 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_0 = 1;
    is_locked = _warn_printk(
                  "RTNL: assertion failed at %s (%d)\n",
                  "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
                  166);
    __break(0x800u);
  }
  v4 = (_UNKNOWN **)cfg80211_rdev_list;
  if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
  {
    do
    {
      if ( v4[292] == a1 )
      {
        is_locked = cfg80211_switch_netns((__int64)(v4 - 1), (unsigned __int64)&init_net);
        if ( (_DWORD)is_locked )
          __break(0x800u);
      }
      v4 = (_UNKNOWN **)*v4;
    }
    while ( v4 != &cfg80211_rdev_list );
  }
  return rtnl_unlock(is_locked);
}
