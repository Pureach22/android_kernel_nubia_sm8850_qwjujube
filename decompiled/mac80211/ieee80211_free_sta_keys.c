void __fastcall ieee80211_free_sta_keys(__int64 a1, __int64 a2)
{
  __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x23
  int v9; // w8
  __int64 v10; // x9
  __int64 lock; // x0
  _QWORD *i; // x8
  __int64 v13; // x20
  __int64 v14; // x21
  __int64 v15; // x19
  __int64 v16; // x0
  __int64 v17; // x1
  __int64 v18; // x22
  int v19; // w8
  __int64 v20; // x9
  __int64 v21; // x0
  _QWORD *j; // x8

  v3 = 0;
  v4 = a2 + 1680;
  do
  {
    v5 = *(_QWORD *)(v4 + 8 * v3);
    if ( v5 )
    {
      v6 = ieee80211_key_replace(
             *(_QWORD *)(v5 + 8),
             nullptr,
             *(_QWORD *)(v5 + 16),
             (*(_WORD *)(v5 + 552) & 8) != 0,
             *(_QWORD *)(v4 + 8 * v3),
             0);
      if ( !*(_QWORD *)v5 )
        goto LABEL_4;
      v8 = *(_QWORD *)(v5 + 8);
      v9 = *(_DWORD *)(v8 + 4720);
      if ( v9 == 2 )
      {
        v10 = *(_QWORD *)(v8 + 1616);
        ++*(_DWORD *)(v8 + 1532);
        wiphy_delayed_work_queue(*(_QWORD *)(v10 + 72), v8 + 1536, 125);
        goto LABEL_4;
      }
      if ( *(int *)(v8 + 1528) <= 0 )
      {
        __break(0x800u);
        if ( *(_DWORD *)(v8 + 4720) == 3 )
          goto LABEL_12;
      }
      else if ( v9 == 3 )
      {
LABEL_12:
        lock = _rcu_read_lock(v6, v7);
        for ( i = *(_QWORD **)(v8 + 2264); i != (_QWORD *)(v8 + 2264); i = (_QWORD *)*i )
          --*((_DWORD *)i - 184);
        _rcu_read_unlock(lock);
      }
      --*(_DWORD *)(v8 + 1528);
LABEL_4:
      ieee80211_key_free_common(v5);
    }
    ++v3;
  }
  while ( v3 != 8 );
  v13 = 0;
  v14 = a2 + 88;
  do
  {
    v15 = *(_QWORD *)(v14 + 8 * v13);
    if ( v15 )
    {
      v16 = ieee80211_key_replace(
              *(_QWORD *)(v15 + 8),
              nullptr,
              *(_QWORD *)(v15 + 16),
              (*(_WORD *)(v15 + 552) & 8) != 0,
              *(_QWORD *)(v14 + 8 * v13),
              0);
      if ( !*(_QWORD *)v15 )
        goto LABEL_20;
      v18 = *(_QWORD *)(v15 + 8);
      v19 = *(_DWORD *)(v18 + 4720);
      if ( v19 == 2 )
      {
        v20 = *(_QWORD *)(v18 + 1616);
        ++*(_DWORD *)(v18 + 1532);
        wiphy_delayed_work_queue(*(_QWORD *)(v20 + 72), v18 + 1536, 125);
        goto LABEL_20;
      }
      if ( *(int *)(v18 + 1528) <= 0 )
      {
        __break(0x800u);
        if ( *(_DWORD *)(v18 + 4720) == 3 )
          goto LABEL_28;
      }
      else if ( v19 == 3 )
      {
LABEL_28:
        v21 = _rcu_read_lock(v16, v17);
        for ( j = *(_QWORD **)(v18 + 2264); j != (_QWORD *)(v18 + 2264); j = (_QWORD *)*j )
          --*((_DWORD *)j - 184);
        _rcu_read_unlock(v21);
      }
      --*(_DWORD *)(v18 + 1528);
LABEL_20:
      ieee80211_key_free_common(v15);
    }
    ++v13;
  }
  while ( v13 != 4 );
}
