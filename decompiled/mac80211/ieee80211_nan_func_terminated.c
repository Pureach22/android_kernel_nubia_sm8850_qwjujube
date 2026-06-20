_DWORD *__fastcall ieee80211_nan_func_terminated(_DWORD *result, unsigned int a2, unsigned int a3, unsigned int a4)
{
  _DWORD *v4; // x23
  _DWORD *v5; // x22
  __int64 v9; // x0
  __int64 v10; // x25
  __int64 v11; // x26
  __int64 v12; // x0

  if ( *result == 12 )
  {
    v4 = result - 613;
    v5 = result;
    raw_spin_lock_bh(result - 613);
    v9 = idr_find(v5 - 612, (unsigned __int8)a2);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 104);
      v11 = v9;
      idr_remove(v5 - 612, (unsigned __int8)a2);
      raw_spin_unlock_bh(v4);
      cfg80211_free_nan_func(v11);
      v12 = ieee80211_vif_to_wdev(v5);
      return (_DWORD *)cfg80211_nan_func_terminated(v12, a2, a3, v10, a4);
    }
    else
    {
      __break(0x800u);
      return (_DWORD *)raw_spin_unlock_bh(v4);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
