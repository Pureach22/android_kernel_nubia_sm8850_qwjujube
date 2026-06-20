__int64 __fastcall ieee80211_ibss_csa_beacon(__int64 a1, __int64 a2, _QWORD *a3)
{
  int v4; // w24
  __int64 bss; // x0
  __int64 v8; // x1
  __int64 v9; // x22
  __int64 lock; // x0
  __int64 v11; // x23
  __int64 v12; // x22
  __int64 v13; // x3
  unsigned __int64 v14; // x0

  v4 = *(unsigned __int8 *)(a1 + 2342);
  bss = _cfg80211_get_bss(
          *(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL),
          *(_QWORD *)(a1 + 2400),
          a1 + 2346,
          a1 + 2352,
          *(unsigned __int8 *)(a1 + 2384),
          2,
          v4 ^ 1u,
          1);
  if ( !bss )
    return 4294967274LL;
  v9 = bss;
  lock = _rcu_read_lock(bss, v8);
  v11 = **(_QWORD **)(v9 + 8);
  _rcu_read_unlock(lock);
  cfg80211_put_bss(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), v9);
  v12 = *(_QWORD *)(a1 + 2440);
  if ( v4 )
    v13 = 18;
  else
    v13 = 2;
  v14 = ieee80211_ibss_build_presp(
          a1,
          *(unsigned __int16 *)(a1 + 4858),
          *(unsigned int *)(a1 + 4880),
          v13,
          v11,
          a1 + 2400,
          0,
          a2);
  if ( !v14 )
    return 4294967284LL;
  atomic_store(v14, (unsigned __int64 *)(a1 + 2440));
  if ( v12 )
    kvfree_call_rcu(v12 + 56, v12);
  *a3 |= 0x100uLL;
  return 0;
}
