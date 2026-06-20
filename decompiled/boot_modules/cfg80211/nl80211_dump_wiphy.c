__int64 __fastcall nl80211_dump_wiphy(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v5; // x0
  __int64 is_locked; // x0
  _QWORD *v7; // x23
  int v8; // w24
  int v9; // w0
  __int64 v10; // x0
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 v14; // x0

  v2 = *(_QWORD *)(a2 + 80);
  v5 = rtnl_lock(a1);
  if ( !v2 )
  {
    v2 = _kmalloc_cache_noprof(timer_delete, 3520, 56);
    if ( !v2 )
    {
      rtnl_unlock(0);
      return 4294967284LL;
    }
    *(_QWORD *)v2 = -1;
    v10 = ((__int64 (__fastcall *)(__int64, __int64, __int64))nl80211_dump_wiphy_parse)(a1, a2, v2);
    if ( (_DWORD)v10 )
    {
      v11 = v10;
      v12 = kfree(v2);
      rtnl_unlock(v12);
      return v11;
    }
    *(_QWORD *)(a2 + 80) = v2;
    is_locked = rtnl_is_locked(v10);
    if ( (_DWORD)is_locked )
      goto LABEL_5;
    goto LABEL_3;
  }
  is_locked = rtnl_is_locked(v5);
  if ( !(_DWORD)is_locked )
  {
LABEL_3:
    if ( (for_each_rdev_check_rtnl___already_done_1 & 1) == 0 )
    {
      for_each_rdev_check_rtnl___already_done_1 = 1;
      is_locked = _warn_printk(
                    "RTNL: assertion failed at %s (%d)\n",
                    "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
                    166);
      __break(0x800u);
    }
  }
LABEL_5:
  v7 = cfg80211_rdev_list;
  if ( cfg80211_rdev_list == (_UNKNOWN *)&cfg80211_rdev_list )
  {
    v8 = 0;
    goto LABEL_30;
  }
  v8 = 0;
  while ( 1 )
  {
    if ( v7[292] != *(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL) )
      goto LABEL_8;
    if ( *(_QWORD *)(v2 + 8) < v8 + 1 && (*(_QWORD *)v2 == -1 || *(_QWORD *)v2 == *((_DWORD *)v7 + 23)) )
      break;
    ++v8;
LABEL_8:
    v7 = (_QWORD *)*v7;
    if ( v7 == &cfg80211_rdev_list )
      goto LABEL_30;
  }
  mutex_lock(v7 + 123);
  while ( 1 )
  {
    v9 = nl80211_send_wiphy(
           (__int64)(v7 - 1),
           3u,
           a1,
           *(_DWORD *)(*(_QWORD *)a2 + 52LL),
           *(_DWORD *)(*(_QWORD *)(a2 + 8) + 8LL),
           2u,
           v2);
    if ( v9 < 0 )
      break;
    if ( *(__int64 *)(v2 + 16) <= 0 )
    {
      ++v8;
      goto LABEL_29;
    }
  }
  if ( (v9 == -90 || v9 == -105)
    && !*(_DWORD *)(a1 + 112)
    && (*(_BYTE *)(v2 + 48) & 1) == 0
    && *(_DWORD *)(a2 + 60) <= 0xFFFu )
  {
    *(_DWORD *)(a2 + 60) = 4096;
    *(_QWORD *)(v2 + 16) = 0;
    v14 = mutex_unlock(v7 + 123);
    rtnl_unlock(v14);
    return 1;
  }
LABEL_29:
  is_locked = mutex_unlock(v7 + 123);
LABEL_30:
  rtnl_unlock(is_locked);
  *(_QWORD *)(v2 + 8) = v8;
  return *(unsigned int *)(a1 + 112);
}
