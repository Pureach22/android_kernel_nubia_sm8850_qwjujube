void __fastcall ieee80211_free_key_list(__int64 a1, _QWORD **a2)
{
  _QWORD *v2; // x8
  __int64 v4; // x0
  _QWORD *v5; // x20
  __int64 v6; // x21
  _QWORD *v7; // x22
  __int64 lock; // x0
  _QWORD *i; // x8

  v2 = *a2;
  if ( *a2 != a2 )
  {
    do
    {
      v5 = (_QWORD *)*v2;
      v4 = (__int64)(v2 - 3);
      if ( *(v2 - 3) )
      {
        v6 = *(v2 - 2);
        if ( *(int *)(v6 + 1528) <= 0 )
          __break(0x800u);
        if ( *(_DWORD *)(v6 + 4720) == 3 )
        {
          v7 = v2 - 3;
          lock = _rcu_read_lock(v4, a2);
          for ( i = *(_QWORD **)(v6 + 2264); i != (_QWORD *)(v6 + 2264); i = (_QWORD *)*i )
            --*((_DWORD *)i - 184);
          _rcu_read_unlock(lock);
          v4 = (__int64)v7;
        }
        --*(_DWORD *)(v6 + 1528);
      }
      ieee80211_key_free_common(v4);
      v2 = v5;
    }
    while ( v5 != a2 );
  }
}
