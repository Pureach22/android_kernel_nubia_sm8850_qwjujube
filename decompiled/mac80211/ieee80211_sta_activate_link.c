__int64 __fastcall ieee80211_sta_activate_link(__int64 a1, __int64 a2)
{
  unsigned int v2; // w24
  int v3; // w20
  __int64 v4; // x26
  unsigned __int16 v6; // w22
  __int64 v7; // x27
  char *v8; // x21
  __int64 v9; // x23
  unsigned __int64 v10; // x25
  __int64 result; // x0
  __int64 v12; // x21
  unsigned int v13; // w22

  if ( (unsigned int)a2 >= 0xF )
  {
    __break(0x5512u);
    return ieee80211_sta_remove_link(a1, a2);
  }
  v2 = a2;
  v3 = *(unsigned __int16 *)(a1 + 2872);
  v4 = 1LL << a2;
  v6 = v3 | (1LL << a2);
  if ( v3 == v6 || (v7 = a1 + 2568, (v8 = *(char **)(a1 + 2568 + 8LL * (unsigned int)a2)) == nullptr) )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  v9 = *(_QWORD *)(a1 + 80);
  _rcu_read_lock(a1, a2);
  v10 = rhltable_lookup((__int64 *)(*(_QWORD *)(v9 + 1616) + 1792LL), v8, (__int64)&link_sta_rht_params);
  _rcu_read_unlock(v10);
  if ( v10 )
    return 4294967182LL;
  *(_WORD *)(a1 + 2872) = v6;
  if ( (*(_QWORD *)(a1 + 216) & 0x100000) != 0 )
  {
    ieee80211_recalc_min_chandef(v9, v2);
    _ieee80211_sta_recalc_aggregates(a1, *(unsigned __int16 *)(*(_QWORD *)(a1 + 80) + 5802LL));
    result = drv_change_sta_links(*(_QWORD *)(v9 + 1616), v9, a1 + 2688, v3, v6);
    if ( (_DWORD)result )
    {
      *(_WORD *)(a1 + 2872) = v3;
      v12 = *(_QWORD *)(v7 + 8LL * v2);
      if ( v12 )
      {
        v13 = result;
        *(_WORD *)(a1 + 2872) = v3 & ~(_WORD)v4;
        *(_QWORD *)(v7 + 8LL * v2) = 0;
        *(_QWORD *)(a1 + 8LL * v2 + 3128) = 0;
        if ( v12 != a1 + 1640 )
        {
          free_percpu(*(_QWORD *)(v12 + 104));
          kvfree_call_rcu(v12 + 1176, v12);
        }
        _ieee80211_sta_recalc_aggregates(a1, *(unsigned __int16 *)(*(_QWORD *)(a1 + 80) + 5802LL));
        return v13;
      }
      else
      {
        __break(0x800u);
      }
      return result;
    }
  }
  else
  {
    __break(0x800u);
  }
  result = rhltable_insert(*(_QWORD *)(v9 + 1616) + 1792LL, v8 + 16, &link_sta_rht_params);
  if ( (_DWORD)result )
  {
    result = 0;
    __break(0x800u);
  }
  return result;
}
