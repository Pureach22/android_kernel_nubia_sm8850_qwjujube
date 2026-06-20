__int64 __fastcall cfg80211_sinfo_alloc_tid_stats(__int64 a1, int a2)
{
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 result; // x0

  v3 = 1;
  if ( (a2 & 0x10) == 0 )
    v3 = 2;
  if ( (a2 & 0x400010) != 0 )
    v4 = v3;
  else
    v4 = 0;
  v5 = _kmalloc_cache_noprof(kmalloc_caches[14 * v4 + 11], a2 | 0x100u, 1496);
  if ( v5 )
    result = 0;
  else
    result = 4294967284LL;
  *(_QWORD *)(a1 + 200) = v5;
  return result;
}
