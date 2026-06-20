__int64 __fastcall cfg80211_bss_flush(__int64 a1, int a2, int a3, _OWORD *a4, size_t a5)
{
  __int128 v5; // q29
  __int128 v6; // q31
  __int64 v7; // x19
  __int64 v9; // x23
  __int64 *v10; // x1
  int v11; // w24
  __int64 *v12; // x25

  if ( a1 )
  {
    v7 = a1 - 808;
    raw_spin_lock_bh(a1 - 808);
    v9 = jiffies;
    v10 = *(__int64 **)(a1 - 800);
    if ( v10 != (__int64 *)(a1 - 800) )
    {
      v11 = 0;
      do
      {
        v12 = (__int64 *)*v10;
        if ( !*((_DWORD *)v10 + 20) && v10[8] - v9 < 0 )
          v11 |= _cfg80211_unlink_bss(a1 - 992);
        v10 = v12;
      }
      while ( v12 != (__int64 *)(a1 - 800) );
      if ( (v11 & 1) != 0 )
        ++*(_DWORD *)(a1 - 776);
    }
    return raw_spin_unlock_bh(v7);
  }
  else
  {
    __break(0x800u);
    a4[47] = v5;
    a4[48] = v6;
    return cfg80211_find_elem_match(0, a2, a3, a4, a5);
  }
}
