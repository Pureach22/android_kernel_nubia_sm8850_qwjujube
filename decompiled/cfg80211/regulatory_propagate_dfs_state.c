__int64 __fastcall regulatory_propagate_dfs_state(__int64 *a1, __int64 *a2, int a3, unsigned int a4)
{
  __int64 result; // x0
  _UNKNOWN **v8; // x28
  __int64 lock; // x0
  __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w19
  int v13; // w20
  __int64 v14; // x2
  unsigned __int16 *i; // x20
  unsigned int v16; // w8
  unsigned __int64 v17; // x25
  __int64 v18; // x27
  bool v19; // w9
  __int64 v20; // x0
  __int64 v21; // x1
  _DWORD *v22; // x8
  bool v23; // cc
  unsigned int v24; // [xsp+18h] [xbp-8h]

  if ( !(unsigned int)rtnl_is_locked(a1) && (regulatory_propagate_dfs_state___already_done & 1) == 0 )
  {
    regulatory_propagate_dfs_state___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/reg.c", 4268);
    __break(0x800u);
  }
  result = cfg80211_chandef_valid(a2);
  if ( (result & 1) != 0 )
  {
    result = rtnl_is_locked(result);
    if ( !(_DWORD)result && (for_each_rdev_check_rtnl___already_done_2 & 1) == 0 )
    {
      for_each_rdev_check_rtnl___already_done_2 = 1;
      result = _warn_printk(
                 "RTNL: assertion failed at %s (%d)\n",
                 "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
                 166);
      __break(0x800u);
    }
    v8 = (_UNKNOWN **)cfg80211_rdev_list;
    if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
    {
      _ReadStatusReg(SP_EL0);
      v24 = a4;
      do
      {
        if ( v8 + 123 != (_UNKNOWN **)a1 )
        {
          lock = _rcu_read_lock(result);
          v10 = cfg80211_regdomain;
          v11 = a1[48];
          if ( !v11 )
            v11 = cfg80211_regdomain;
          if ( v8[171] )
            v10 = (__int64)v8[171];
          v12 = *(_DWORD *)(v11 + 24);
          v13 = *(_DWORD *)(v10 + 24);
          result = _rcu_read_unlock(lock);
          if ( v12 == v13 )
          {
            result = ieee80211_get_channel_khz(v8 + 123, (unsigned int)(1000 * *(_DWORD *)(*a2 + 4)));
            if ( result )
            {
              cfg80211_set_dfs_state((__int64)(v8 + 123), (__int64)a2, a3);
              if ( a4 <= 1 )
              {
                cfg80211_sched_dfs_chan_update((__int64)(v8 - 1));
                for ( i = (unsigned __int16 *)v8[290]; i != (unsigned __int16 *)(v8 + 290); i = *(unsigned __int16 **)i )
                {
                  v16 = i[728];
                  v17 = 0;
                  v18 = 212;
                  v19 = i[728] == 0;
                  do
                  {
                    if ( (v19 || ((v16 >> v17) & 1) != 0) && LOBYTE(i[v18]) == 1 )
                    {
                      v20 = wdev_chandef((__int64)(i - 8), (unsigned int)v17, v14);
                      if ( v20 )
                      {
                        if ( !cfg80211_chandef_dfs_usable((__int64)(v8 + 123), v20) )
                        {
                          v21 = *((_QWORD *)i + 2);
                          v22 = *((_DWORD **)*(v8 - 1) + 86);
                          if ( v22 )
                          {
                            if ( *(v22 - 1) != -822248057 )
                              __break(0x8228u);
                            ((void (__fastcall *)(_UNKNOWN **, __int64, _QWORD))v22)(v8 + 123, v21, (unsigned int)v17);
                          }
                        }
                      }
                    }
                    v16 = i[728];
                    if ( !i[728] )
                      break;
                    v19 = 0;
                    v23 = v17++ > 0xD;
                    v18 += 36;
                  }
                  while ( !v23 );
                }
              }
              a4 = v24;
              result = ((__int64 (__fastcall *)(_UNKNOWN **, __int64 *, _QWORD, _QWORD, __int64))nl80211_radar_notify)(
                         v8 - 1,
                         a2,
                         v24,
                         0,
                         3264);
            }
          }
        }
        v8 = (_UNKNOWN **)*v8;
      }
      while ( v8 != &cfg80211_rdev_list );
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
