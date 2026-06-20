__int64 __fastcall cfg80211_dev_check_name(__int64 a1, const char *a2)
{
  __int64 result; // x0
  size_t v5; // x0
  int v6; // w9
  int v7; // w8
  __int64 v8; // x11
  bool v9; // cc
  _UNKNOWN **v10; // x21
  const char *v11; // x1
  int v12; // [xsp+0h] [xbp-10h] BYREF
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = -1;
  v13 = 0;
  if ( !(unsigned int)rtnl_is_locked(a1) && (cfg80211_dev_check_name___already_done & 1) == 0 )
  {
    cfg80211_dev_check_name___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/core.c", 98);
    __break(0x800u);
  }
  if ( strlen(a2) > 0x40 )
    goto LABEL_5;
  sscanf(a2, "phy%d%n", &v13, &v12);
  v5 = strlen(a2);
  if ( v5 != v12 )
    goto LABEL_12;
  v6 = v13;
  if ( v13 == *(_DWORD *)(a1 + 100) )
    goto LABEL_12;
  v7 = 0;
  do
  {
    v8 = 1717986919LL * v6;
    ++v7;
    v9 = (unsigned int)(v6 + 9) > 0x12;
    v6 /= 10;
  }
  while ( v9 );
  v13 = (v8 >> 34) + ((unsigned __int64)v8 >> 63);
  if ( v7 + 3LL == v5 )
  {
LABEL_5:
    result = 4294967274LL;
  }
  else
  {
LABEL_12:
    if ( !(unsigned int)rtnl_is_locked(v5) && (for_each_rdev_check_rtnl___already_done_0 & 1) == 0 )
    {
      for_each_rdev_check_rtnl___already_done_0 = 1;
      _warn_printk(
        "RTNL: assertion failed at %s (%d)\n",
        "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
        166);
      __break(0x800u);
    }
    v10 = &cfg80211_rdev_list;
    while ( 1 )
    {
      v10 = (_UNKNOWN **)*v10;
      if ( v10 == &cfg80211_rdev_list )
        break;
      v11 = (const char *)v10[186];
      if ( !v11 )
        v11 = (const char *)v10[172];
      if ( !strcmp(a2, v11) )
        goto LABEL_5;
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
