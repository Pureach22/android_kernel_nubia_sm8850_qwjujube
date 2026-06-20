__int64 __fastcall wiphy_all_share_dfs_chan_state(__int64 *a1)
{
  __int64 result; // x0
  _UNKNOWN **v3; // x21
  __int64 lock; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  int v7; // w25
  int v8; // w26
  __int64 i; // x8
  __int64 v10; // x10
  _DWORD *v11; // x11
  int v12; // w14
  int v13; // w12
  __int64 j; // x13
  __int64 v15; // x14
  __int64 v16; // x17
  __int64 v17; // x15
  int v18; // w16
  __int64 v19; // x12

  if ( !(unsigned int)rtnl_is_locked(a1) && (wiphy_all_share_dfs_chan_state___already_done & 1) == 0 )
  {
    wiphy_all_share_dfs_chan_state___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 3020);
    __break(0x800u);
  }
  result = for_each_rdev_check_rtnl();
  v3 = (_UNKNOWN **)cfg80211_rdev_list;
  if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
  {
    do
    {
      if ( v3 + 123 != (_UNKNOWN **)a1 )
      {
        lock = _rcu_read_lock(result);
        v5 = cfg80211_regdomain;
        v6 = a1[48];
        if ( !v6 )
          v6 = cfg80211_regdomain;
        if ( v3[171] )
          v5 = (__int64)v3[171];
        v7 = *(_DWORD *)(v6 + 24);
        v8 = *(_DWORD *)(v5 + 24);
        result = _rcu_read_unlock(lock);
        if ( v7 == v8 )
        {
          for ( i = 0; i != 6; ++i )
          {
            v10 = a1[i + 41];
            if ( v10 )
            {
              v11 = v3[i + 164];
              if ( v11 )
              {
                v12 = *(_DWORD *)(v10 + 20);
                if ( v12 >= 1 )
                {
                  v13 = v11[5];
                  for ( j = 0; j < v12; ++j )
                  {
                    if ( v13 >= 1 )
                    {
                      v15 = 0;
                      v16 = 0;
                      v17 = *(_QWORD *)v10 + (j << 6);
                      v18 = *(_DWORD *)(v17 + 12);
                      do
                      {
                        if ( (v18 & 8) != 0 && (v18 & 1) == 0 )
                        {
                          result = *(_QWORD *)v11;
                          if ( (*(_DWORD *)(*(_QWORD *)v11 + v15 + 12) & 9) == 8
                            && *(_DWORD *)(result + v15 + 4) == *(_DWORD *)(v17 + 4)
                            && !*(_DWORD *)(v17 + 44) )
                          {
                            v19 = result + v15;
                            result = *(unsigned int *)(result + v15 + 44);
                            *(_DWORD *)(v17 + 44) = result;
                            *(_QWORD *)(v17 + 48) = *(_QWORD *)(v19 + 48);
                            v13 = v11[5];
                          }
                        }
                        ++v16;
                        v15 += 64;
                      }
                      while ( v16 < v13 );
                      v12 = *(_DWORD *)(v10 + 20);
                    }
                  }
                }
              }
            }
          }
        }
      }
      v3 = (_UNKNOWN **)*v3;
    }
    while ( v3 != &cfg80211_rdev_list );
  }
  return result;
}
