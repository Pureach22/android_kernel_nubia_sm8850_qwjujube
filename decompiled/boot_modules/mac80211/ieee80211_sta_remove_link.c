__int64 __fastcall ieee80211_sta_remove_link(__int64 result, unsigned int a2)
{
  __int16 v3; // w3
  __int64 v4; // x21
  __int64 v5; // x1
  __int64 v6; // x19
  __int64 v7; // x23
  __int64 v8; // x20

  v3 = *(_WORD *)(result + 2872);
  v4 = 1LL << a2;
  v5 = *(_QWORD *)(result + 80);
  v6 = result;
  *(_WORD *)(result + 2872) = v3 & ~(_WORD)v4;
  if ( (*(_QWORD *)(result + 216) & 0x100000) != 0 )
  {
    result = drv_change_sta_links(*(_QWORD *)(v5 + 1616), v5, result + 2688, v3, v3 & (unsigned __int16)~(_WORD)v4);
    if ( a2 < 0x10 )
      goto LABEL_3;
LABEL_9:
    __break(0x5512u);
    goto LABEL_10;
  }
  __break(0x800u);
  if ( a2 >= 0x10 )
    goto LABEL_9;
LABEL_3:
  v7 = a2;
  v8 = *(_QWORD *)(v6 + 2568 + 8LL * a2);
  if ( !v8 )
  {
LABEL_10:
    __break(0x800u);
    return result;
  }
  rhltable_remove(*(_QWORD *)(v6 + 72) + 1792LL, v8 + 16, &link_sta_rht_params);
  *(_WORD *)(v6 + 2872) &= ~(_WORD)v4;
  *(_QWORD *)(v6 + 2568 + 8 * v7) = 0;
  *(_QWORD *)(v6 + 8 * v7 + 3128) = 0;
  if ( v8 != v6 + 1640 )
  {
    free_percpu(*(_QWORD *)(v8 + 104));
    kvfree_call_rcu(v8 + 1176, v8);
  }
  return _ieee80211_sta_recalc_aggregates(v6, *(unsigned __int16 *)(*(_QWORD *)(v6 + 80) + 5802LL));
}
