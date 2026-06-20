__int64 __fastcall ieee80211_tx_skb_tid(__int64 a1, __int64 a2, int a3, int a4)
{
  __int64 lock; // x0
  int v9; // w4
  int **v10; // x8
  __int64 v11; // x0

  lock = _rcu_read_lock(a1, a2);
  if ( *(_WORD *)(a1 + 5800) )
  {
    if ( a4 < 0 )
    {
      LOBYTE(v9) = 0;
    }
    else
    {
      LOBYTE(v9) = 0;
      if ( (((unsigned __int64)*(unsigned __int16 *)(a1 + 5802) >> a4) & 1) == 0 )
        __break(0x800u);
    }
    goto LABEL_9;
  }
  if ( (a4 & 0x80000000) == 0 )
  {
    __break(0x800u);
    v10 = *(int ***)(a1 + 5640);
    if ( v10 )
      goto LABEL_7;
LABEL_12:
    __break(0x800u);
    _rcu_read_unlock(lock);
    return sk_skb_reason_drop(0);
  }
  v10 = *(int ***)(a1 + 5640);
  if ( !v10 )
    goto LABEL_12;
LABEL_7:
  v9 = **v10;
LABEL_9:
  v11 = _ieee80211_tx_skb_tid_band(a1, a2, a3, a4, v9);
  return _rcu_read_unlock(v11);
}
