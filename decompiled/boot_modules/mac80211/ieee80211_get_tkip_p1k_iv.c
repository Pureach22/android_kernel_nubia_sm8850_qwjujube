__int64 __fastcall ieee80211_get_tkip_p1k_iv(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 *v5; // x21
  __int64 v8; // x9

  v3 = a1 - 488;
  v5 = (__int64 *)(a1 - 484);
  raw_spin_lock_bh(a1 - 488);
  if ( *(_DWORD *)(a1 - 472) != a2 || !*(_DWORD *)(a1 - 468) )
    tkip_mixing_phase1(a1 + 20, v5, *(_QWORD *)(a1 - 528) + 5842LL, a2);
  v8 = *v5;
  *(_WORD *)(a3 + 8) = *((_WORD *)v5 + 4);
  *(_QWORD *)a3 = v8;
  return raw_spin_unlock_bh(v3);
}
