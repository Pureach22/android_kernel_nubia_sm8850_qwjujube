__int64 __fastcall nl80211_prepare_wdev_dump(_QWORD *a1, __int64 a2, unsigned int *a3, __int64 a4)
{
  _UNKNOWN **v7; // x0
  __int64 v8; // x9
  __int64 v9; // x0
  __int64 v11; // x22
  _DWORD *v12; // x8
  __int64 v13; // x0
  __int64 v14; // x23
  unsigned int v15; // w19
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 *v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0

  if ( !a1[10] )
  {
    if ( a4 )
    {
      v11 = 0;
    }
    else
    {
      v11 = _kmalloc_cache_noprof(alloc_workqueue, 3520, 2688);
      a4 = v11;
      if ( !v11 )
        return 4294967284LL;
    }
    v12 = (_DWORD *)a1[1];
    if ( *v12 >= (unsigned int)(nl80211_fam + 20) )
    {
      v14 = a4;
      v13 = _nla_parse(
              a4,
              (unsigned int)dword_BF568,
              (char *)v12 + ((nl80211_fam + 7) & 0xFFFFFFFC) + 16,
              *v12 - ((nl80211_fam + 7) & 0xFFFFFFFC) - 16,
              &nl80211_policy,
              0,
              0);
      if ( !(_DWORD)v13 )
      {
        rtnl_lock(v13);
        *(_QWORD *)a3 = _cfg80211_wdev_from_attrs(0, *(void **)(*(_QWORD *)(*a1 + 24LL) + 48LL), v14);
        v16 = kfree(v11);
        v19 = *(__int64 **)a3;
        if ( *(_QWORD *)a3 < 0xFFFFFFFFFFFFF001LL )
        {
          v20 = *v19;
          if ( *v19 )
          {
            *(_QWORD *)a2 = v20 - 992;
            v21 = mutex_lock(v20);
            rtnl_unlock(v21);
            a1[10] = *(_DWORD *)(*(_QWORD *)a2 + 100LL) + 1;
            a1[11] = *(unsigned int *)(*(_QWORD *)a3 + 40LL);
            return 0;
          }
          else
          {
            __break(0x800u);
            return parse_station_flags(0, v17, v18);
          }
        }
        else
        {
          rtnl_unlock(v16);
          return *a3;
        }
      }
    }
    else
    {
      do_trace_netlink_extack("Invalid header length");
      LODWORD(v13) = -22;
    }
    v15 = v13;
    kfree(v11);
    return v15;
  }
  rtnl_lock(a1);
  v7 = wiphy_idx_to_wiphy((unsigned int)(*((_DWORD *)a1 + 20) - 1));
  if ( v7 )
  {
    *(_QWORD *)a2 = v7 - 124;
    *(_QWORD *)a3 = 0;
    v8 = *(_QWORD *)a2 + 2328LL;
    while ( 1 )
    {
      v8 = *(_QWORD *)v8;
      if ( v8 == *(_QWORD *)a2 + 2328LL )
        break;
      if ( a1[11] == *(_DWORD *)(v8 + 24) )
      {
        *(_QWORD *)a3 = v8 - 16;
        if ( v8 == 16 )
          break;
        v9 = mutex_lock(*(_QWORD *)a2 + 992LL);
        rtnl_unlock(v9);
        return 0;
      }
    }
  }
  rtnl_unlock(v7);
  return 4294967277LL;
}
