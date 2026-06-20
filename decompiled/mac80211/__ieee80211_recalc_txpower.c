__int64 __fastcall _ieee80211_recalc_txpower(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  __int64 *v4; // x8
  int v5; // w9
  __int64 v6; // x8
  int v7; // w8
  __int64 v8; // t2
  int v9; // w9
  __int64 v11; // t2
  int v12; // w20
  int v13; // w8
  int v14; // w10
  bool v15; // zf
  int v16; // w8
  int v17; // w11
  int v18; // w8
  __int64 v19; // x0

  lock = _rcu_read_lock(a1, a2);
  v4 = *(__int64 **)(a1 + 5640);
  if ( !v4 )
  {
    _rcu_read_unlock(lock);
    return 0;
  }
  v5 = *((_DWORD *)v4 + 2);
  v6 = *v4;
  if ( v5 == 7 )
  {
    v11 = v6 + 20;
    v7 = *(_DWORD *)(v6 + 20);
    v9 = *(_DWORD *)(v11 + 4) - 3;
  }
  else
  {
    if ( v5 != 6 )
    {
      v12 = *(_DWORD *)(v6 + 20);
      goto LABEL_11;
    }
    v8 = v6 + 20;
    v7 = *(_DWORD *)(v6 + 20);
    v9 = *(_DWORD *)(v8 + 4) - 6;
  }
  if ( v9 >= v7 )
    v12 = v7;
  else
    v12 = v9;
LABEL_11:
  _rcu_read_unlock(lock);
  v13 = *(_DWORD *)(a1 + 4064);
  if ( v12 >= v13 )
    v14 = *(_DWORD *)(a1 + 4064);
  else
    v14 = v12;
  v15 = v13 == 0x80000000;
  v16 = *(_DWORD *)(a1 + 4068);
  if ( v15 )
    v14 = v12;
  if ( v14 >= v16 )
    v17 = *(_DWORD *)(a1 + 4068);
  else
    v17 = v14;
  if ( v16 == 0x80000000 )
    v18 = v14;
  else
    v18 = v17;
  if ( v18 == *(_DWORD *)(a1 + 5036) )
    return 0;
  v19 = *(_QWORD *)(a1 + 1616);
  *(_DWORD *)(a1 + 5036) = v18;
  ieee80211_hw_config(v19, 0);
  return 1;
}
