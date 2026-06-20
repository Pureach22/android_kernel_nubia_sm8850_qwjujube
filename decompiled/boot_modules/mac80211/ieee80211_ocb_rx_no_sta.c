__int64 __fastcall ieee80211_ocb_rx_no_sta(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x21
  __int64 result; // x0
  __int64 v7; // x3
  __int64 lock; // x0
  unsigned int **v9; // x8
  __int64 v10; // x22
  _QWORD *v11; // x20
  _QWORD *v12; // x2
  _QWORD *v13; // x1
  __int64 v14; // x0

  v3 = a1[202];
  if ( *(_QWORD *)(v3 + 1608) < 0x80u )
  {
    lock = _rcu_read_lock(a1, a2);
    v9 = (unsigned int **)a1[705];
    if ( v9 )
    {
      v10 = **v9;
      _rcu_read_unlock(lock);
      result = sta_info_alloc(a1, a3, 2080);
      if ( result )
      {
        if ( (unsigned int)v10 >= 6 )
        {
          __break(0x5512u);
          v14 = MEMORY[0xFFFFFFFFFD19F8EC]();
          return ieee80211_ocb_work(v14);
        }
        else
        {
          v11 = (_QWORD *)result;
          *(_DWORD *)(result + 4 * v10 + 2900) = ieee80211_mandatory_rates(*(_QWORD *)(*(_QWORD *)(v3 + 72)
                                                                                     + 8 * v10
                                                                                     + 328));
          raw_spin_lock(a1 + 289);
          v12 = (_QWORD *)a1[290];
          v13 = a1 + 290;
          if ( (_QWORD *)v12[1] != a1 + 290 || v11 == v13 || v12 == v11 )
          {
            _list_add_valid_or_report(v11, v13);
          }
          else
          {
            v12[1] = v11;
            *v11 = v12;
            v11[1] = v13;
            *v13 = v11;
          }
          raw_spin_unlock(a1 + 289);
          return wiphy_work_queue(*(_QWORD *)(v3 + 72), a1 + 245);
        }
      }
    }
    else
    {
      __break(0x800u);
      return _rcu_read_unlock(lock);
    }
  }
  else
  {
    result = net_ratelimit();
    if ( (_DWORD)result )
      return printk(&unk_B7DFC, a1 + 205, a3, v7);
  }
  return result;
}
