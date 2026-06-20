__int64 __fastcall cfg80211_ref_bss(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x8

  if ( result )
  {
    if ( a2 )
    {
      v3 = result - 808;
      raw_spin_lock_bh(result - 808);
      v4 = *(_QWORD *)(a2 + 32);
      ++*(_QWORD *)(a2 - 40);
      if ( v4 )
        ++*(_QWORD *)(v4 - 40);
      v5 = *(_QWORD *)(a2 + 40);
      if ( v5 )
        ++*(_QWORD *)(v5 - 40);
      return raw_spin_unlock_bh(v3);
    }
  }
  else
  {
    __break(0x800u);
    return cfg80211_put_bss(0, a2);
  }
  return result;
}
