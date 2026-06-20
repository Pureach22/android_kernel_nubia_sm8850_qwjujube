__int64 __fastcall ieee80211_reenable_keys(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x19
  _QWORD *i; // x8
  _QWORD *v5; // x10
  _QWORD *v6; // x20
  _QWORD *v7; // x21
  _QWORD **v8; // x22
  int v9; // w8
  __int64 lock; // x0
  _QWORD *j; // x8

  v2 = *(_DWORD *)(result + 4720);
  v3 = result;
  *(_QWORD *)(result + 1528) = 0;
  if ( v2 == 3 )
  {
    for ( i = *(_QWORD **)(result + 2264); i != (_QWORD *)(result + 2264); *v5 = 0 )
    {
      v5 = i - 92;
      i = (_QWORD *)*i;
    }
  }
  if ( (*(_QWORD *)(result + 1632) & 1) != 0 )
  {
    v6 = *(_QWORD **)(result + 1512);
    v7 = (_QWORD *)(result + 1512);
    if ( v6 != (_QWORD *)(result + 1512) )
    {
      v8 = (_QWORD **)(result + 2264);
      do
      {
        if ( *(_DWORD *)(v3 + 4720) == 3 )
        {
          lock = _rcu_read_lock(result, a2);
          for ( j = *v8; j != v8; j = (_QWORD *)*j )
            ++*((_DWORD *)j - 184);
          result = _rcu_read_unlock(lock);
        }
        v9 = *(_DWORD *)(v3 + 1528);
        *(_DWORD *)(v3 + 1528) = v9 + 1;
        if ( !v9 )
          synchronize_net(result);
        result = ieee80211_key_enable_hw_accel(v6 - 3);
        v6 = (_QWORD *)*v6;
      }
      while ( v6 != v7 );
    }
  }
  return result;
}
