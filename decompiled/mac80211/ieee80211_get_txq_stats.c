__int64 __fastcall ieee80211_get_txq_stats(
        _DWORD *a1,
        __int64 a2,
        int *a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  int v7; // s8
  __int64 v11; // x0
  __int64 v12; // x1
  int *lock; // x0
  __int64 v14; // x8

  if ( a1 )
  {
    v11 = raw_spin_lock_bh(a1 + 444);
    lock = (int *)_rcu_read_lock(v11, v12);
    if ( a2 )
    {
      v14 = *(_QWORD *)(a2 + 5840);
      if ( v14 )
      {
        lock = ieee80211_fill_txq_stats(a3, (_DWORD *)(v14 - 232));
        LODWORD(a2) = 0;
      }
      else
      {
        LODWORD(a2) = 1;
      }
    }
    else
    {
      *a3 |= 0x9C6u;
      a3[2] = a1[450];
      a3[1] = a1[448];
      a3[6] = a1[451];
      a3[7] = a1[452];
      a3[8] = a1[453];
      a3[11] = a1[445];
    }
    _rcu_read_unlock(lock);
    raw_spin_unlock_bh(a1 + 444);
    return (unsigned int)a2;
  }
  else
  {
    __break(0x800u);
    *(_DWORD *)(a7 + 14064) = v7;
    return ieee80211_get_ftm_responder_stats();
  }
}
