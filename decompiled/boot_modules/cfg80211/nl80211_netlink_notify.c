__int64 __fastcall nl80211_netlink_notify(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 lock; // x0
  _QWORD *v5; // x22
  _QWORD *v7; // x9
  _QWORD *v8; // x0
  _QWORD *i; // x26
  _QWORD *v10; // x26
  char *v11; // x2
  int v12; // w8
  __int64 *v13; // x8
  int v14; // w10
  _QWORD *v15; // x9

  if ( a2 != 1 )
    return 0;
  if ( *(_DWORD *)(a3 + 12) != 16 )
    return 0;
  lock = _rcu_read_lock(a1);
  v5 = cfg80211_rdev_list;
  if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
  {
    while ( 1 )
    {
      for ( i = (_QWORD *)v5[30]; i != v5 + 30; i = (_QWORD *)*i )
      {
        if ( *((_DWORD *)i - 2) == *(_DWORD *)(a3 + 8) )
        {
          *((_BYTE *)i - 4) = 1;
          wiphy_work_queue((__int64)(v5 + 123), v5 + 86);
        }
      }
      v10 = (_QWORD *)v5[290];
      if ( v10 != v5 + 290 )
        break;
LABEL_23:
      raw_spin_lock_bh(v5 + 19);
      v13 = (__int64 *)v5[17];
      while ( v13 != v5 + 17 )
      {
        v14 = *((_DWORD *)v13 + 4);
        v8 = v13;
        v13 = (__int64 *)*v13;
        if ( v14 == *(_DWORD *)(a3 + 8) )
        {
          v15 = (_QWORD *)v8[1];
          if ( (_QWORD *)*v15 == v8 && (_QWORD *)v13[1] == v8 )
          {
            v13[1] = (__int64)v15;
            *v15 = v13;
          }
          else
          {
            _list_del_entry_valid_or_report(v8);
            v8 = v7;
          }
          *v8 = 0xDEAD000000000100LL;
          v8[1] = 0xDEAD000000000122LL;
          kfree(v8);
          break;
        }
      }
      lock = raw_spin_unlock_bh(v5 + 19);
      v5 = (_QWORD *)*v5;
      if ( v5 == &cfg80211_rdev_list )
        goto LABEL_29;
    }
    while ( 1 )
    {
      cfg80211_mlme_unregister_socket(v10 - 2, *(_DWORD *)(a3 + 8));
      v12 = *(_DWORD *)(a3 + 8);
      if ( *((_DWORD *)v10 + 40) == v12 )
      {
        *((_BYTE *)v10 + 164) = 1;
        v11 = (char *)(v5 + 82);
      }
      else
      {
        if ( *((_DWORD *)v10 + 21) != v12 )
          goto LABEL_19;
        v11 = (char *)(v10 + 11);
      }
      queue_work_on(32, system_wq, v11);
LABEL_19:
      cfg80211_release_pmsr(v10 - 2, *(unsigned int *)(a3 + 8));
      v10 = (_QWORD *)*v10;
      if ( v10 == v5 + 290 )
        goto LABEL_23;
    }
  }
LABEL_29:
  _rcu_read_unlock(lock);
  regulatory_netlink_notify(*(unsigned int *)(a3 + 8));
  return 1;
}
