__int64 *__fastcall ieee80211_ibss_disconnect(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x20
  __int64 bss; // x0
  __int64 v5; // x22
  _QWORD *v6; // x22
  _QWORD **v7; // x23
  _QWORD *v8; // x8
  __int64 v9; // x9
  __int64 v10; // x1
  unsigned __int64 v18; // x10

  v1 = a1 + 2346;
  v2 = *(_QWORD *)(a1 + 1616);
  if ( *(_DWORD *)(a1 + 2346) | *(unsigned __int16 *)(a1 + 2350) )
  {
    bss = _cfg80211_get_bss(
            *(_QWORD *)(v2 + 72),
            *(_QWORD *)(a1 + 2400),
            v1,
            a1 + 2352,
            *(unsigned __int8 *)(a1 + 2384),
            2,
            *(unsigned __int8 *)(a1 + 2342) ^ 1u,
            1);
    if ( bss )
    {
      v5 = bss;
      cfg80211_unlink_bss(*(_QWORD *)(v2 + 72), bss);
      cfg80211_put_bss(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), v5);
    }
  }
  *(_DWORD *)(a1 + 2520) = 0;
  _sta_info_flush(a1, 0, 0xFFFFFFFFLL);
  raw_spin_lock_bh(a1 + 2500);
  v6 = *(_QWORD **)(a1 + 2504);
  v7 = (_QWORD **)(a1 + 2504);
  if ( v6 != (_QWORD *)(a1 + 2504) )
  {
    do
    {
      v8 = (_QWORD *)v6[1];
      if ( (_QWORD *)*v8 == v6 && (v9 = *v6, *(_QWORD **)(*v6 + 8LL) == v6) )
      {
        *(_QWORD *)(v9 + 8) = v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v6);
      }
      *v6 = 0xDEAD000000000100LL;
      v6[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_bh(a1 + 2500);
      sta_info_free(v2, v6);
      raw_spin_lock_bh(a1 + 2500);
      v6 = *v7;
    }
    while ( *v7 != v7 );
  }
  raw_spin_unlock_bh(a1 + 2500);
  netif_carrier_off(*(_QWORD *)(a1 + 1608));
  v10 = *(_QWORD *)(a1 + 2440);
  *(_BYTE *)(v1 + 2510) = 0;
  *(_WORD *)(v1 + 2383) = 0;
  *(_QWORD *)(a1 + 4792) = 0;
  *(_QWORD *)(a1 + 2440) = 0;
  if ( v10 )
    kvfree_call_rcu(v10 + 56, v10);
  _X8 = (unsigned __int64 *)(a1 + 1632);
  __asm { PRFM            #0x11, [X8] }
  do
    v18 = __ldxr(_X8);
  while ( __stxr(v18 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
  ieee80211_bss_info_change_notify(a1, 2560);
  drv_leave_ibss(v2, a1);
  return ieee80211_link_release_channel((__int64 *)(a1 + 3616));
}
