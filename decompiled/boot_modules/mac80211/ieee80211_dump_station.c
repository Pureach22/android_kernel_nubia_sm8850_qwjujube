__int64 __fastcall ieee80211_dump_station(__int64 a1, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x0
  int v8; // w9

  v7 = sta_info_get_by_idx(a2 + 2688, a3);
  if ( !v7 )
    return 4294967294LL;
  v8 = *(_DWORD *)(v7 + 2688);
  *(_WORD *)(a4 + 4) = *(_WORD *)(v7 + 2692);
  *(_DWORD *)a4 = v8;
  sta_set_sinfo(v7, a5, 1);
  return 0;
}
