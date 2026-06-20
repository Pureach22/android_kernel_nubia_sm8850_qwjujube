__int64 __fastcall disconnect_work(__int64 a1)
{
  __int64 v1; // x0
  _QWORD *v2; // x20
  char v3; // w21
  __int64 v4; // x0
  _QWORD *i; // x22

  v1 = rtnl_lock(a1);
  if ( !(unsigned int)rtnl_is_locked(v1) && (for_each_rdev_check_rtnl___already_done_3 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_3 = 1;
    _warn_printk(
      "RTNL: assertion failed at %s (%d)\n",
      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
      166);
    __break(0x800u);
  }
  v2 = cfg80211_rdev_list;
  if ( cfg80211_rdev_list == (_UNKNOWN *)&cfg80211_rdev_list )
    goto LABEL_16;
  v3 = 1;
  do
  {
    mutex_lock(v2 + 123);
    for ( i = (_QWORD *)v2[290]; i != v2 + 290; i = (_QWORD *)*i )
    {
      if ( i[8] || (*((_BYTE *)i + 148) & 1) != 0 || cfg80211_beaconing_iface_active((__int64)(i - 2)) )
        v3 = 0;
    }
    v4 = mutex_unlock(v2 + 123);
    v2 = (_QWORD *)*v2;
  }
  while ( v2 != &cfg80211_rdev_list );
  if ( (v3 & 1) != 0 )
LABEL_16:
    v4 = regulatory_hint_disconnect();
  return rtnl_unlock(v4);
}
