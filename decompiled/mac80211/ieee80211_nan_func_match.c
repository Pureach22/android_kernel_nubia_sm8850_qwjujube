_DWORD *__fastcall ieee80211_nan_func_match(_DWORD *result, __int64 a2, unsigned int a3)
{
  _DWORD *v3; // x22
  _DWORD *v4; // x21
  __int64 v7; // x0
  __int64 v8; // x0

  if ( *result == 12 )
  {
    v3 = result - 613;
    v4 = result;
    raw_spin_lock_bh(result - 613);
    v7 = idr_find(v4 - 612, *(unsigned __int8 *)(a2 + 4));
    if ( v7 )
    {
      *(_QWORD *)(a2 + 32) = *(_QWORD *)(v7 + 104);
      raw_spin_unlock_bh(v3);
      v8 = ieee80211_vif_to_wdev(v4);
      return (_DWORD *)cfg80211_nan_match(v8, a2, a3);
    }
    else
    {
      __break(0x800u);
      return (_DWORD *)raw_spin_unlock_bh(v3);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
