__int64 __fastcall iee80211_tdls_recalc_ht_protection(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w8
  int v4; // w9
  __int64 lock; // x0
  __int64 v6; // x9
  __int64 *v7; // x8
  __int64 *v8; // x9
  int v9; // w20
  int v10; // w8

  if ( *(_DWORD *)(result + 4168) <= 1u )
  {
    v2 = result;
    if ( a2 && *(_BYTE *)(a2 + 2926) == 1 )
    {
      v3 = *(unsigned __int16 *)(result + 4920);
      LOWORD(v4) = v3 | 0x17;
      if ( (v3 | 0x17) == v3 )
        return result;
LABEL_18:
      *(_WORD *)(v2 + 4920) = v4;
      return ieee80211_link_info_change_notify(v2, v2 + 3616, 16);
    }
    lock = _rcu_read_lock(result, a2);
    v6 = *(_QWORD *)(v2 + 1616);
    v7 = *(__int64 **)(v6 + 1616);
    v8 = (__int64 *)(v6 + 1616);
    while ( v7 != v8 )
    {
      if ( *((_BYTE *)v7 + 2712) == 1
        && v7[10] == v2
        && *((_BYTE *)v7 + 204) == 1
        && (v7[27] & 8) != 0
        && (v7[27] & 0x1000) != 0
        && (*((_BYTE *)v7 + 2926) & 1) != 0 )
      {
        v9 = 23;
        goto LABEL_17;
      }
      v7 = (__int64 *)*v7;
    }
    v9 = 0;
LABEL_17:
    result = _rcu_read_unlock(lock);
    v10 = *(unsigned __int16 *)(v2 + 4920);
    v4 = v10 & 0xFFE8 | v9;
    if ( v4 != v10 )
      goto LABEL_18;
  }
  return result;
}
