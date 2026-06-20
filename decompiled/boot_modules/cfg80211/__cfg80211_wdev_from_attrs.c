__int64 __fastcall _cfg80211_wdev_from_attrs(__int64 a1, void *a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x19
  int v5; // w21
  void *v6; // x24
  __int64 v7; // x22
  __int64 v8; // x1
  int v9; // w22
  int v10; // w23
  __int64 *i; // x8
  __int64 v12; // x10
  __int64 result; // x0
  __int64 is_locked; // x0
  _UNKNOWN **j; // x9
  _QWORD *v16; // x10
  __int64 v17; // x12
  __int64 v18; // x10
  __int64 v19; // x0
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a3 + 24);
  v4 = *(_QWORD *)(a3 + 1224);
  if ( !(v3 | v4) )
  {
    result = -22;
    goto LABEL_43;
  }
  if ( v3 )
  {
    v5 = *(_DWORD *)(v3 + 4);
    v6 = a2;
    if ( v4 )
      goto LABEL_4;
  }
  else
  {
    v5 = -1;
    v6 = a2;
    if ( v4 )
    {
LABEL_4:
      v7 = a1;
      v8 = *(_QWORD *)(a3 + 1224);
      v20[0] = 0;
      nla_memcpy(v20, v8, 8);
      a1 = v7;
      v9 = v20[0];
      v10 = HIDWORD(v20[0]);
      if ( a1 )
        goto LABEL_5;
      goto LABEL_18;
    }
  }
  v9 = 0;
  v10 = -1;
  if ( a1 )
  {
LABEL_5:
    for ( i = *(__int64 **)(a1 + 2328); i != (__int64 *)(a1 + 2328); i = (__int64 *)*i )
    {
      if ( v3 && (v12 = i[2]) != 0 && *(_DWORD *)(v12 + 224) == v5 || v4 && *((_DWORD *)i + 6) == v9 )
      {
        result = (__int64)(i - 2);
        if ( i != &qword_10 )
          goto LABEL_43;
        break;
      }
    }
    result = -19;
    goto LABEL_43;
  }
LABEL_18:
  is_locked = rtnl_is_locked(a1);
  if ( (_DWORD)is_locked || (_cfg80211_wdev_from_attrs___already_done & 1) != 0 )
  {
    if ( (unsigned int)rtnl_is_locked(is_locked) )
      goto LABEL_23;
  }
  else
  {
    _cfg80211_wdev_from_attrs___already_done = 1;
    v19 = _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/nl80211.c", 107);
    __break(0x800u);
    if ( (unsigned int)rtnl_is_locked(v19) )
      goto LABEL_23;
  }
  if ( (for_each_rdev_check_rtnl___already_done_1 & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done_1 = 1;
    _warn_printk(
      "RTNL: assertion failed at %s (%d)\n",
      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
      166);
    __break(0x800u);
  }
LABEL_23:
  for ( j = (_UNKNOWN **)cfg80211_rdev_list; j != &cfg80211_rdev_list; j = (_UNKNOWN **)*j )
  {
    if ( j[292] == v6 && (!v4 || *((_DWORD *)j + 23) == v10) )
    {
      v16 = j[290];
      if ( v16 != j + 290 )
      {
        while ( 1 )
        {
          if ( v3 )
          {
            v17 = v16[2];
            if ( v17 )
            {
              if ( *(_DWORD *)(v17 + 224) == v5 )
                break;
            }
          }
          if ( v4 && *((_DWORD *)v16 + 6) == v9 )
            break;
          v16 = (_QWORD *)*v16;
          if ( v16 == j + 290 )
            goto LABEL_24;
        }
        v18 = (__int64)(v16 - 2);
        if ( v18 )
          goto LABEL_40;
      }
    }
LABEL_24:
    ;
  }
  v18 = 0;
LABEL_40:
  if ( v18 )
    result = v18;
  else
    result = -19;
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return result;
}
