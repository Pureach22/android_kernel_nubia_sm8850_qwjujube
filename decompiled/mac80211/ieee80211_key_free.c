__int64 __fastcall ieee80211_key_free(__int64 result, char a2)
{
  unsigned __int64 v2; // x19
  __int64 v3; // x0
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x21
  __int64 v8; // x9
  __int64 lock; // x0
  _QWORD *i; // x8

  if ( result )
  {
    v2 = result;
    v3 = *(_QWORD *)(result + 8);
    if ( v3 )
      v3 = ieee80211_key_replace(v3, nullptr, *(_QWORD *)(v2 + 16), (*(_WORD *)(v2 + 552) & 8) != 0, v2, 0);
    v5 = synchronize_net(v3);
    if ( *(_QWORD *)v2 )
    {
      v7 = *(_QWORD *)(v2 + 8);
      if ( (a2 & 1) != 0 )
      {
        v8 = *(_QWORD *)(v7 + 1616);
        ++*(_DWORD *)(v7 + 1532);
        wiphy_delayed_work_queue(*(_QWORD *)(v8 + 72), v7 + 1536, 125);
      }
      else
      {
        if ( *(int *)(v7 + 1528) <= 0 )
          __break(0x800u);
        if ( *(_DWORD *)(v7 + 4720) == 3 )
        {
          lock = _rcu_read_lock(v5, v6);
          for ( i = *(_QWORD **)(v7 + 2264); i != (_QWORD *)(v7 + 2264); i = (_QWORD *)*i )
            --*((_DWORD *)i - 184);
          _rcu_read_unlock(lock);
        }
        --*(_DWORD *)(v7 + 1528);
      }
    }
    return ieee80211_key_free_common(v2);
  }
  return result;
}
