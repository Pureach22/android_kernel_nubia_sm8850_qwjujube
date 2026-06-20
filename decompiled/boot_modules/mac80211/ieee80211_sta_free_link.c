__int64 __fastcall ieee80211_sta_free_link(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v3; // x9
  __int64 v4; // x20

  if ( (*(_QWORD *)(result + 216) & 0x100000) != 0 )
  {
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
  v2 = *(_QWORD *)(result + 2568 + 8LL * a2);
  if ( !v2 )
  {
LABEL_10:
    __break(0x800u);
    return result;
  }
  v3 = 8LL * a2;
  *(_WORD *)(result + 2872) &= ~(unsigned __int16)(1LL << a2);
  *(_QWORD *)(result + 2568 + v3) = 0;
  *(_QWORD *)(result + v3 + 3128) = 0;
  if ( v2 != result + 1640 )
  {
    v4 = result;
    free_percpu(*(_QWORD *)(v2 + 104));
    kvfree_call_rcu(v2 + 1176, v2);
    result = v4;
  }
  return _ieee80211_sta_recalc_aggregates(result, *(unsigned __int16 *)(*(_QWORD *)(result + 80) + 5802LL));
}
