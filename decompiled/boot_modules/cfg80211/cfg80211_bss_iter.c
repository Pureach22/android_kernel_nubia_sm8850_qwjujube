__int64 __fastcall cfg80211_bss_iter(__int64 a1, __int64 *a2, _DWORD *a3, __int64 a4)
{
  __int64 v4; // x23
  _QWORD *i; // x25

  if ( a1 )
  {
    v4 = a1 - 808;
    raw_spin_lock_bh(a1 - 808);
    for ( i = *(_QWORD **)(a1 - 800); i != (_QWORD *)(a1 - 800); i = (_QWORD *)*i )
    {
      if ( !a2 || (cfg80211_is_sub_chan(a2, i[14], 0) & 1) != 0 )
      {
        if ( *(a3 - 1) != 1430070853 )
          __break(0x8234u);
        ((void (__fastcall *)(__int64, _QWORD *, __int64))a3)(a1, i + 14, a4);
      }
    }
    return raw_spin_unlock_bh(v4);
  }
  else
  {
    __break(0x800u);
    return cfg80211_update_assoc_bss_entry(0, a2, a3);
  }
}
