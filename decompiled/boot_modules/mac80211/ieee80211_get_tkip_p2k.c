__int64 __fastcall ieee80211_get_tkip_p2k(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned __int16 *v3; // x22
  __int64 v6; // x20
  unsigned __int8 *v7; // x8
  unsigned int v8; // w22
  int v9; // w24
  int v10; // w25

  v3 = *(unsigned __int16 **)(a2 + 224);
  v6 = a1 - 488;
  v7 = (unsigned __int8 *)v3 + (unsigned int)ieee80211_hdrlen(*v3);
  v8 = *((_DWORD *)v7 + 1);
  v9 = v7[2];
  v10 = *v7;
  raw_spin_lock(v6);
  if ( *(_DWORD *)(a1 - 472) != v8 || !*(_DWORD *)(a1 - 468) )
    tkip_mixing_phase1(a1 + 20, a1 - 484, (unsigned __int16 *)(*(_QWORD *)(a1 - 528) + 5842LL), v8);
  tkip_mixing_phase2(a1 + 20, a1 - 484, v9 | (unsigned int)(v10 << 8), a3);
  return raw_spin_unlock(v6);
}
