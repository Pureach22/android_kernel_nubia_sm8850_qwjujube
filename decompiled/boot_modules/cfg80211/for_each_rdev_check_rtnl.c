__int64 __fastcall for_each_rdev_check_rtnl(__int64 a1)
{
  __int64 result; // x0

  result = rtnl_is_locked(a1);
  if ( !(_DWORD)result && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_2 = 1;
    result = _warn_printk(
               "RTNL: assertion failed at %s (%d)\n",
               "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
               166);
    __break(0x800u);
  }
  return result;
}
