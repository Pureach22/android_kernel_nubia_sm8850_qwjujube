__int64 __fastcall ieee80211_sta_last_active(__int64 a1)
{
  __int64 v1; // x9
  __int64 v2; // x8
  char v3; // w13
  unsigned __int64 v4; // x13
  unsigned __int64 v5; // x13
  bool v6; // cf
  __int64 v7; // x9
  __int64 v8; // x8

  v1 = *(_QWORD *)(a1 + 1744);
  v2 = a1 + 1752;
  if ( v1 )
  {
    v3 = 0;
    do
    {
      v4 = _cpu_possible_mask & (unsigned __int64)(-1LL << v3);
      if ( !v4 )
        break;
      v5 = __clz(__rbit64(v4));
      if ( (__int64)(*(_QWORD *)(v2 + 8) - *(_QWORD *)(_per_cpu_offset[v5] + v1 + 8)) < 0 )
        v2 = _per_cpu_offset[v5] + v1;
      v6 = v5 >= 0x1F;
      v3 = v5 + 1;
    }
    while ( !v6 );
  }
  v7 = *(_QWORD *)(a1 + 2304);
  v8 = *(_QWORD *)(v2 + 8);
  if ( v7 - v8 < 0 || v7 == 0 )
    return v8;
  else
    return *(_QWORD *)(a1 + 2304);
}
