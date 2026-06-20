__int64 __fastcall cfg80211_any_wiphy_oper_chan(__int64 a1, __int64 a2)
{
  _UNKNOWN **i; // x22
  char *v6; // x24
  char *v7; // x25
  char is_sub_chan; // w21
  __int64 v9; // x8
  int v10; // w9
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x10
  _DWORD *v13; // x11
  bool v14; // cf
  __int64 *v15; // x21
  unsigned __int64 v16; // x26
  bool v17; // cc

  if ( (unsigned int)rtnl_is_locked() || (cfg80211_any_wiphy_oper_chan___already_done & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 12) & 8) == 0 )
      return 0;
  }
  else
  {
    cfg80211_any_wiphy_oper_chan___already_done = 1;
    _warn_printk("RTNL: assertion failed at %s (%d)\n", "../soc-repo/net/wireless/chan.c", 975);
    __break(0x800u);
    if ( (*(_BYTE *)(a2 + 12) & 8) == 0 )
      return 0;
  }
  if ( !(unsigned int)rtnl_is_locked() && (for_each_rdev_check_rtnl___already_done & 1) == 0 )
  {
    for_each_rdev_check_rtnl___already_done = 1;
    _warn_printk(
      "RTNL: assertion failed at %s (%d)\n",
      "/proc/self/cwd/bazel-out/k8-fastbuild/bin/soc-repo/net/wireless/core.h",
      166);
    __break(0x800u);
  }
  for ( i = (_UNKNOWN **)cfg80211_rdev_list; ; i = (_UNKNOWN **)*i )
  {
    if ( i == &cfg80211_rdev_list )
      return 0;
    if ( (reg_dfs_domain_same(a1, i + 123) & 1) == 0 )
      continue;
    mutex_lock(i + 123);
    v6 = (char *)i[290];
    v7 = (char *)(i + 290);
    if ( v6 != (char *)(i + 290) )
    {
      do
      {
        while ( 1 )
        {
          v10 = *((_DWORD *)v6 - 2);
          if ( v10 > 4 )
            break;
          if ( !v10 )
            goto LABEL_42;
          if ( v10 == 1 )
          {
            if ( !v6[340] )
              goto LABEL_21;
            v9 = 288;
            goto LABEL_20;
          }
          if ( v10 != 3 )
            goto LABEL_21;
LABEL_34:
          v11 = *((unsigned __int16 *)v6 + 728);
          v12 = 0;
          v13 = v6 + 384;
          while ( *((_WORD *)v6 + 728) && ((v11 >> v12) & 1) == 0 || !*v13 )
          {
            if ( *((_WORD *)v6 + 728) )
            {
              v14 = v12++ >= 0xE;
              v13 += 18;
              if ( !v14 )
                continue;
            }
            goto LABEL_21;
          }
          if ( *((_WORD *)v6 + 728) && (v11 & 1) == 0 )
            goto LABEL_52;
          if ( (cfg80211_is_sub_chan((__int64 *)v6 + 49, a2, 0) & 1) != 0 )
          {
LABEL_60:
            mutex_unlock(i + 123);
            return 1;
          }
          LODWORD(v11) = *((unsigned __int16 *)v6 + 728);
          if ( *((_WORD *)v6 + 728) )
          {
LABEL_52:
            v15 = (__int64 *)(v6 + 464);
            v16 = 1;
            do
            {
              if ( (((unsigned int)v11 >> v16) & 1) != 0 )
              {
                if ( (cfg80211_is_sub_chan(v15, a2, 0) & 1) != 0 )
                  goto LABEL_60;
                LODWORD(v11) = *((unsigned __int16 *)v6 + 728);
              }
              if ( !(_DWORD)v11 )
                break;
              v17 = v16++ > 0xD;
              v15 += 9;
            }
            while ( !v17 );
          }
LABEL_21:
          v6 = *(char **)v6;
          if ( v6 == v7 )
            goto LABEL_15;
        }
        if ( v10 > 8 )
        {
          if ( v10 == 13 )
            goto LABEL_42;
          if ( v10 != 9 )
            goto LABEL_21;
          goto LABEL_34;
        }
        if ( v10 != 5 )
        {
          if ( v10 != 7 || !v6[368] )
            goto LABEL_21;
          v9 = 320;
LABEL_20:
          if ( (cfg80211_is_sub_chan((__int64 *)&v6[v9 - 16], a2, 0) & 1) != 0 )
            goto LABEL_60;
          goto LABEL_21;
        }
LABEL_42:
        __break(0x800u);
        v6 = *(char **)v6;
      }
      while ( v6 != v7 );
    }
LABEL_15:
    if ( !i[58] || (cfg80211_chandef_valid((__int64 *)i + 59) & 1) == 0 )
    {
      mutex_unlock(i + 123);
      continue;
    }
    is_sub_chan = cfg80211_is_sub_chan((__int64 *)i + 59, a2, 0);
    mutex_unlock(i + 123);
    if ( (is_sub_chan & 1) != 0 )
      break;
  }
  return 1;
}
