__int64 __fastcall sta_link_apply_parameters(__int64 unlock, __int64 a2, int a3, __int64 a4)
{
  int v4; // w8
  __int64 v5; // x20
  __int64 v7; // x11
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x11
  char v11; // w12
  _QWORD *v12; // x24
  __int64 v13; // x21
  unsigned int v14; // w8
  __int64 v16; // x26
  __int64 v18; // x22
  __int64 lock; // x0
  unsigned int **v20; // x8
  __int64 v21; // x27
  __int64 v22; // x22
  int *v23; // x8
  __int16 v24; // w9
  int v25; // w8
  __int64 v26; // x9
  __int64 v27; // x8
  __int16 v28; // w10
  int v29; // w8
  __int64 v30; // x2
  __int64 v31; // x2
  __int64 v32; // x2

  v4 = *(_DWORD *)(a4 + 8);
  if ( v4 >= 15 )
    goto LABEL_49;
  v5 = *(_QWORD *)(a2 + 80);
  v7 = 8LL * (v4 & (unsigned int)~(v4 >> 31));
  v8 = *(_QWORD *)(a4 + 16);
  v9 = v5 + v7;
  v10 = a2 + v7;
  if ( v8
    || (*(_BYTE *)(a4 + 84) & 1) != 0
    || *(_BYTE *)(a4 + 32)
    || *(_QWORD *)(a4 + 40)
    || *(_QWORD *)(a4 + 48)
    || *(_QWORD *)(a4 + 64)
    || *(_QWORD *)(a4 + 96) )
  {
    v11 = 1;
  }
  else
  {
    v11 = *(_BYTE *)(a4 + 57);
  }
  v12 = *(_QWORD **)(v9 + 4568);
  v13 = *(_QWORD *)(v10 + 2568);
  if ( a3 == 1 )
  {
    if ( !((v4 >= 0) | v11 & 1) )
      return 0;
  }
  else if ( !a3 && !v8 )
  {
    return (unsigned int)-22;
  }
  v14 = -22;
  if ( !v12 || !v13 )
    return v14;
  v16 = unlock;
  v18 = *(_QWORD *)(*v12 + 1616LL);
  lock = _rcu_read_lock(unlock, a2);
  v20 = *(unsigned int ***)(v12[118] + 832LL);
  if ( !v20 )
  {
    _rcu_read_unlock(lock);
    return (unsigned int)-22;
  }
  v21 = **v20;
  unlock = _rcu_read_unlock(lock);
  if ( (unsigned int)v21 >= 6 )
    goto LABEL_49;
  v22 = *(_QWORD *)(*(_QWORD *)(v18 + 72) + 8 * v21 + 328);
  if ( !v22 )
    return (unsigned int)-22;
  v23 = *(int **)(a4 + 16);
  unlock = v16;
  if ( !v23 )
    goto LABEL_27;
  if ( !a3 )
  {
    v24 = *((_WORD *)v23 + 2);
    v25 = *v23;
    *(_WORD *)(v13 + 4) = v24;
    v26 = *(_QWORD *)(v13 + 920);
    *(_DWORD *)v13 = v25;
    v27 = *(_QWORD *)(a4 + 16);
    v28 = *(_WORD *)(v27 + 4);
    LODWORD(v27) = *(_DWORD *)v27;
    *(_WORD *)(v26 + 12) = v28;
    *(_DWORD *)(v26 + 8) = v27;
    goto LABEL_27;
  }
  if ( *v23 ^ *(_DWORD *)v13 | *((unsigned __int16 *)v23 + 2) ^ *(unsigned __int16 *)(v13 + 4) )
    return (unsigned int)-22;
LABEL_27:
  if ( *(_BYTE *)(a4 + 84) == 1 )
  {
    v29 = *(_DWORD *)(a4 + 80);
    *(_DWORD *)(*(_QWORD *)(v13 + 920) + 240LL) = v29;
    if ( v29 == 1 )
      *(_WORD *)(*(_QWORD *)(v13 + 920) + 236LL) = *(_WORD *)(a4 + 76);
    unlock = drv_sta_set_txpwr(v16, v5, a2);
    v14 = unlock;
    if ( (_DWORD)unlock )
      return v14;
  }
  if ( !*(_QWORD *)(a4 + 24) || !*(_BYTE *)(a4 + 32) )
    goto LABEL_35;
  if ( *(_DWORD *)(v22 + 16) <= 6u )
  {
    ieee80211_parse_bitrates(*(unsigned int *)(v12[118] + 144LL), v22);
LABEL_35:
    v30 = *(_QWORD *)(a4 + 40);
    if ( v30 )
      ieee80211_ht_cap_ie_to_sta_ht_cap(v5, v22, v30, v13);
    v31 = *(_QWORD *)(a4 + 48);
    if ( v31 )
      ieee80211_vht_cap_ie_to_sta_vht_cap(v5, v22, v31, 0, v13);
    v32 = *(_QWORD *)(a4 + 64);
    if ( v32 )
    {
      ieee80211_he_cap_ie_to_sta_he_cap(v5, v22, v32, *(unsigned __int8 *)(a4 + 72), *(_QWORD *)(a4 + 88), v13);
      if ( *(_QWORD *)(a4 + 64) )
      {
        if ( *(_QWORD *)(a4 + 96) )
          ieee80211_eht_cap_ie_to_sta_eht_cap(v5, v22);
      }
    }
    if ( *(_BYTE *)(a4 + 57) == 1 )
      _ieee80211_vht_handle_opmode(v5, v13, *(unsigned __int8 *)(a4 + 56), *(unsigned int *)(v22 + 16));
    ieee80211_sta_init_nss(v13);
    return 0;
  }
LABEL_49:
  __break(0x5512u);
  return local_bh_enable_0(unlock);
}
