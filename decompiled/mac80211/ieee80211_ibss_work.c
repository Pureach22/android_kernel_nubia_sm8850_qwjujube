__int64 __fastcall ieee80211_ibss_work(__int64 result)
{
  __int64 v1; // x19
  _QWORD *v2; // x20
  _QWORD **v3; // x21
  _QWORD *v4; // x8
  __int64 v5; // x9
  __int64 v6; // x0
  __int64 v7; // x1
  int v8; // w8
  __int64 v9; // x20
  __int64 lock; // x0
  _QWORD *v11; // x21
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x8
  __int64 *v15; // x20
  __int64 *v16; // x22
  __int64 *v17; // x24
  __int64 v18; // x22
  _QWORD *v19; // x20
  _QWORD *i; // x22
  __int64 v21; // x1
  __int64 v22; // x9
  __int64 v23; // x21
  __int64 bss; // x0
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 v27; // x0
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x21
  unsigned int v31; // w0
  __int64 v32; // [xsp+8h] [xbp-48h] BYREF
  __int64 v33; // [xsp+10h] [xbp-40h]
  __int64 v34; // [xsp+18h] [xbp-38h]
  __int64 v35; // [xsp+20h] [xbp-30h]
  __int64 v36; // [xsp+28h] [xbp-28h]
  __int64 v37; // [xsp+30h] [xbp-20h]
  __int64 v38; // [xsp+38h] [xbp-18h]
  __int64 v39; // [xsp+40h] [xbp-10h]
  __int64 v40; // [xsp+48h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(result + 2384) )
    goto LABEL_51;
  v1 = result;
  raw_spin_lock_bh(result + 2500);
  v2 = *(_QWORD **)(v1 + 2504);
  v3 = (_QWORD **)(v1 + 2504);
  if ( v2 != (_QWORD *)(v1 + 2504) )
  {
    do
    {
      v4 = (_QWORD *)v2[1];
      if ( (_QWORD *)*v4 == v2 && (v5 = *v2, *(_QWORD **)(*v2 + 8LL) == v2) )
      {
        *(_QWORD *)(v5 + 8) = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v2);
      }
      *v2 = 0xDEAD000000000100LL;
      v2[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_bh(v1 + 2500);
      v6 = ieee80211_ibss_finish_sta(v2);
      _rcu_read_unlock(v6);
      raw_spin_lock_bh(v1 + 2500);
      v2 = *v3;
    }
    while ( *v3 != v3 );
  }
  result = raw_spin_unlock_bh(v1 + 2500);
  v8 = *(_DWORD *)(v1 + 2520);
  if ( v8 != 1 )
  {
    if ( v8 )
    {
      __break(0x800u);
      goto LABEL_51;
    }
    v9 = *(_QWORD *)(v1 + 1616);
    lock = _rcu_read_lock(result, v7);
    v11 = *(_QWORD **)(v9 + 1616);
    if ( v11 != (_QWORD *)(v9 + 1616) )
    {
      while ( 1 )
      {
        lock = ieee80211_sta_last_active(v11);
        if ( v11[10] == v1 && jiffies - lock - 7500 < 0 )
          break;
        v11 = (_QWORD *)*v11;
        if ( v11 == (_QWORD *)(v9 + 1616) )
          goto LABEL_35;
      }
LABEL_33:
      result = _rcu_read_unlock(lock);
      goto LABEL_51;
    }
LABEL_35:
    _rcu_read_unlock(lock);
    v21 = 0;
    if ( *(_BYTE *)(v1 + 2340) )
      v22 = v1 + 2346;
    else
      v22 = 0;
    if ( *(_BYTE *)(v1 + 2341) == 1 )
      v21 = *(_QWORD *)(v1 + 2400);
    if ( *(_DWORD *)(v1 + 2346) | *(unsigned __int16 *)(v1 + 2350) )
      v23 = v1 + 2346;
    else
      v23 = v22;
    bss = _cfg80211_get_bss(
            *(_QWORD *)(v9 + 72),
            v21,
            v23,
            v1 + 2352,
            *(unsigned __int8 *)(v1 + 2384),
            2,
            *(unsigned __int8 *)(v1 + 2342) ^ 1u,
            1);
    if ( bss )
    {
      v30 = bss;
      printk(&unk_BBEF8, v1 + 1640, bss + 72, v26);
      ieee80211_sta_join_ibss(v1, v30 + 96);
      result = ieee80211_rx_bss_put(v9, v30 + 96);
      goto LABEL_51;
    }
    if ( *(_BYTE *)(v1 + 2340) == 1 && *(_BYTE *)(v1 + 2341) == 1 )
    {
      printk(&unk_BBBB7, v1 + 1640, v23, v26);
      result = ieee80211_sta_create_ibss(v1);
      goto LABEL_51;
    }
    if ( *(_QWORD *)(v1 + 2328) - jiffies + 500LL >= 0 )
    {
      if ( *(_QWORD *)(v1 + 2432) - jiffies + 1750LL < 0 )
        ieee80211_sta_create_ibss(v1);
      v27 = round_jiffies(jiffies + 500LL);
      result = mod_timer(v1 + 2264, v27);
      goto LABEL_51;
    }
    v38 = 0;
    v39 = 0;
    v36 = 0;
    v37 = 0;
    v34 = 0;
    v35 = 0;
    v32 = 0;
    v33 = 0;
    printk(&unk_BAEC6, v1 + 1640, v25, v26);
    if ( *(_BYTE *)(v1 + 2341) == 1 )
    {
      v31 = ieee80211_ibss_setup_scan_channels(*(_QWORD *)(v9 + 72), v1 + 2400, &v32);
      result = ieee80211_request_ibss_scan(v1, v1 + 2352, *(unsigned __int8 *)(v1 + 2384), &v32, v31);
      goto LABEL_51;
    }
LABEL_56:
    result = ieee80211_request_ibss_scan(v1, v1 + 2352, *(unsigned __int8 *)(v1 + 2384), 0, 0);
    goto LABEL_51;
  }
  v12 = round_jiffies(jiffies + 7500LL);
  result = mod_timer(v1 + 2264, v12);
  v14 = *(_QWORD *)(v1 + 1616);
  v15 = *(__int64 **)(v14 + 1616);
  v16 = (__int64 *)(v14 + 1616);
  if ( v15 != (__int64 *)(v14 + 1616) )
  {
    do
    {
      v17 = (__int64 *)*v15;
      result = ieee80211_sta_last_active(v15);
      if ( v15[10] == v1 && (result - jiffies + 15000 < 0 || result - jiffies + 2500 < 0 && *((_DWORD *)v15 + 52) != 4) )
      {
        LOWORD(v35) = 0;
        v33 = 0;
        v34 = 0;
        v32 = 0;
        ieee80211_send_deauth_disassoc(v1, v15 + 336, v1 + 2346, 192, 3, 1, &v32);
        result = _sta_info_destroy(v15);
        if ( (_DWORD)result )
          __break(0x800u);
      }
      v15 = v17;
    }
    while ( v17 != v16 );
  }
  if ( jiffies - *(_QWORD *)(v1 + 2328) - 7500LL >= 0 )
  {
    v18 = *(_QWORD *)(v1 + 1616);
    lock = _rcu_read_lock(result, v13);
    v19 = *(_QWORD **)(v18 + 1616);
    for ( i = (_QWORD *)(v18 + 1616); v19 != i; v19 = (_QWORD *)*v19 )
    {
      lock = ieee80211_sta_last_active(v19);
      if ( v19[10] == v1 && jiffies - lock - 7500 < 0 )
        goto LABEL_33;
    }
    result = _rcu_read_unlock(lock);
    if ( (*(_BYTE *)(v1 + 2341) & 1) != 0 )
      goto LABEL_51;
    printk(&unk_BA295, v1 + 1640, v28, v29);
    goto LABEL_56;
  }
LABEL_51:
  _ReadStatusReg(SP_EL0);
  return result;
}
