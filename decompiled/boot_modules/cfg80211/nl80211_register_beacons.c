__int64 __fastcall nl80211_register_beacons(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x20
  __int64 *v6; // x1
  __int64 *v7; // x8
  __int64 v8; // x2

  v2 = *(_QWORD *)(a2 + 48);
  if ( (*(_BYTE *)(v2 + 1094) & 4) == 0 )
    return 4294967201LL;
  v5 = _kmalloc_cache_noprof(mod_timer, 3520, 24);
  if ( !v5 )
    return 4294967284LL;
  raw_spin_lock_bh(v2 + 160);
  v6 = (__int64 *)(v2 + 144);
  v7 = (__int64 *)(v2 + 144);
  while ( 1 )
  {
    v7 = (__int64 *)*v7;
    if ( v7 == v6 )
      break;
    if ( *((_DWORD *)v7 + 4) == *(_DWORD *)(a2 + 4) )
    {
      raw_spin_unlock_bh(v2 + 160);
      kfree(v5);
      return 4294967182LL;
    }
  }
  *(_DWORD *)(v5 + 16) = *(_DWORD *)(a2 + 4);
  v8 = *v6;
  if ( *(__int64 **)(*v6 + 8) != v6 || (__int64 *)v5 == v6 || v8 == v5 )
  {
    _list_add_valid_or_report(v5, v6);
  }
  else
  {
    *(_QWORD *)(v8 + 8) = v5;
    *(_QWORD *)v5 = v8;
    *(_QWORD *)(v5 + 8) = v6;
    *v6 = v5;
  }
  raw_spin_unlock_bh(v2 + 160);
  return 0;
}
