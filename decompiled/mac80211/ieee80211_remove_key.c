__int64 __fastcall ieee80211_remove_key(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int16 v3; // w10
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 lock; // x0
  _QWORD *i; // x8
  int v8; // w8
  __int64 v9; // x19

  v2 = *(_DWORD *)(a1 - 496);
  if ( (v2 & 1) != 0 )
  {
    v3 = *(_WORD *)(a1 + 16);
    *(_DWORD *)(a1 - 496) = v2 & 0xFFFFFFFE;
    if ( (v3 & 0x184) == 0 )
    {
      v4 = *(_QWORD *)(a1 - 528);
      if ( *(_DWORD *)(v4 + 4720) == 3 )
      {
        v5 = a1;
        lock = _rcu_read_lock(a1, a2);
        for ( i = *(_QWORD **)(v4 + 2264); i != (_QWORD *)(v4 + 2264); i = (_QWORD *)*i )
          ++*((_DWORD *)i - 184);
        _rcu_read_unlock(lock);
        a1 = v5;
      }
      v8 = *(_DWORD *)(v4 + 1528);
      *(_DWORD *)(v4 + 1528) = v8 + 1;
      if ( !v8 )
      {
        v9 = a1;
        synchronize_net(a1);
        a1 = v9;
      }
    }
  }
  return ieee80211_key_free(a1 - 536, 0);
}
