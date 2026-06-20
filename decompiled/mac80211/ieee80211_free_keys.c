__int64 __fastcall ieee80211_free_keys(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 result; // x0
  __int64 v6; // x1
  _QWORD *i; // x22
  _QWORD *v8; // x8
  __int64 v9; // x8
  __int64 v10; // x0
  _QWORD *v11; // x21
  __int64 v12; // x22
  _QWORD *v13; // x23
  __int64 lock; // x0
  _QWORD *j; // x8
  _QWORD *k; // x8
  _QWORD v17[3]; // [xsp+8h] [xbp-18h] BYREF

  v17[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 1616);
  v17[0] = v17;
  v17[1] = v17;
  wiphy_delayed_work_cancel(*(_QWORD *)(v4 + 72), a1 + 1536);
  result = ieee80211_free_keys_iface(a1, v17);
  if ( *(_DWORD *)(a1 + 4720) == 3 )
  {
    for ( i = *(_QWORD **)(a1 + 2264); i != (_QWORD *)(a1 + 2264); i = (_QWORD *)*i )
      result = ieee80211_free_keys_iface(i - 283, v17);
  }
  v8 = (_QWORD *)v17[0];
  if ( (_QWORD *)v17[0] != v17 || (a2 & 1) != 0 )
  {
    result = synchronize_net(result);
    v8 = (_QWORD *)v17[0];
  }
  if ( v8 != v17 )
  {
    do
    {
      v11 = (_QWORD *)*v8;
      v10 = (__int64)(v8 - 3);
      if ( *(v8 - 3) )
      {
        v12 = *(v8 - 2);
        if ( *(int *)(v12 + 1528) <= 0 )
          __break(0x800u);
        if ( *(_DWORD *)(v12 + 4720) == 3 )
        {
          v13 = v8 - 3;
          lock = _rcu_read_lock(v10, v6);
          for ( j = *(_QWORD **)(v12 + 2264); j != (_QWORD *)(v12 + 2264); j = (_QWORD *)*j )
            --*((_DWORD *)j - 184);
          _rcu_read_unlock(lock);
          v10 = (__int64)v13;
        }
        --*(_DWORD *)(v12 + 1528);
      }
      result = ieee80211_key_free_common(v10);
      v8 = v11;
    }
    while ( v11 != v17 );
  }
  if ( *(_DWORD *)(a1 + 4720) == 4 )
  {
    v9 = *(_QWORD *)(a1 + 2032);
    if ( v9 && *(_DWORD *)(a1 + 1528) != *(_DWORD *)(v9 - 736) )
LABEL_11:
      __break(0x800u);
  }
  else if ( *(_DWORD *)(a1 + 1528) || *(_DWORD *)(a1 + 1532) )
  {
    goto LABEL_11;
  }
  if ( *(_DWORD *)(a1 + 4720) == 3 )
  {
    for ( k = *(_QWORD **)(a1 + 2264); k != (_QWORD *)(a1 + 2264); k = (_QWORD *)*k )
    {
      if ( *((_DWORD *)k - 184) || *((_DWORD *)k - 183) )
        __break(0x800u);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
