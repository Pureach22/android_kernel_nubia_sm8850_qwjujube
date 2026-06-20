unsigned __int64 __fastcall ieee80211_find_sta(unsigned __int64 result, const void *a2)
{
  unsigned __int64 v2; // x20
  __int64 v4; // x21
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x19
  __int64 v7; // x10
  __int64 v8; // x10

  if ( result )
  {
    v2 = result;
    v4 = *(_QWORD *)(result - 3104);
    _rcu_read_lock(result, a2);
    v5 = rhltable_lookup((__int64 *)(v4 + 1632), a2, (__int64)&sta_rht_params);
    if ( v5 )
    {
      v6 = v5;
      while ( 1 )
      {
        v7 = *(_QWORD *)(v6 + 32);
        if ( v7 == v2 - 4720 )
          break;
        v8 = *(_QWORD *)(v7 + 2032);
        if ( v8 )
        {
          if ( v8 == *(_QWORD *)(v2 - 2688) )
            break;
        }
        v6 = *(_QWORD *)(v6 + 8);
        if ( !v6 )
          goto LABEL_12;
      }
      _rcu_read_unlock(v5);
      if ( v6 != 48 )
      {
        if ( *(_BYTE *)(v6 + 156) )
          return v6 + 2640;
        else
          return 0;
      }
    }
    else
    {
LABEL_12:
      _rcu_read_unlock(v5);
    }
    return 0;
  }
  return result;
}
