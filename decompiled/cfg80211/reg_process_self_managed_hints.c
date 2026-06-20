__int64 __fastcall reg_process_self_managed_hints(__int64 a1)
{
  __int64 is_locked; // x0
  _UNKNOWN **v2; // x20
  __int64 v4; // x0

  is_locked = rtnl_is_locked(a1);
  if ( (_DWORD)is_locked || (reg_process_self_managed_hints___already_done & 1) != 0 )
  {
    if ( (unsigned int)rtnl_is_locked(is_locked) )
      goto LABEL_6;
  }
  else
  {
    reg_process_self_managed_hints___already_done = 1;
    v4 = _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 3206);
    __break(0x800u);
    if ( (unsigned int)rtnl_is_locked(v4) )
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
  v2 = (_UNKNOWN **)cfg80211_rdev_list;
  if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
  {
    do
    {
      mutex_lock(v2 + 123);
      reg_process_self_managed_hint((__int64)(v2 + 123));
      mutex_unlock(v2 + 123);
      v2 = (_UNKNOWN **)*v2;
    }
    while ( v2 != &cfg80211_rdev_list );
  }
  return mod_delayed_work_on(32, system_power_efficient_wq, &reg_check_chans, 15000);
}
