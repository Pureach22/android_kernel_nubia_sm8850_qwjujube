__int64 __fastcall ieee80211_ocb_leave(__int64 a1)
{
  __int64 v1; // x20
  _QWORD *v3; // x21
  _QWORD **v4; // x22
  _QWORD *v5; // x8
  __int64 v6; // x9
  unsigned __int64 v14; // x10

  v1 = *(_QWORD *)(a1 + 1616);
  *(_BYTE *)(a1 + 2336) = 0;
  _sta_info_flush(a1, 0, 0xFFFFFFFFLL);
  raw_spin_lock_bh(a1 + 2312);
  v3 = *(_QWORD **)(a1 + 2320);
  v4 = (_QWORD **)(a1 + 2320);
  if ( v3 != (_QWORD *)(a1 + 2320) )
  {
    do
    {
      v5 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v5 == v3 && (v6 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v6 + 8) = v5;
        *v5 = v6;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      raw_spin_unlock_bh(a1 + 2312);
      sta_info_free(v1, v3);
      raw_spin_lock_bh(a1 + 2312);
      v3 = *v4;
    }
    while ( *v4 != v4 );
  }
  raw_spin_unlock_bh(a1 + 2312);
  netif_carrier_off(*(_QWORD *)(a1 + 1608));
  _X8 = (unsigned __int64 *)(a1 + 1632);
  __asm { PRFM            #0x11, [X8] }
  do
    v14 = __ldxr(_X8);
  while ( __stxr(v14 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
  ieee80211_bss_info_change_notify(a1, 0x400000);
  ieee80211_link_release_channel((__int64 *)(a1 + 3616));
  skb_queue_purge_reason(a1 + 1984, 85);
  timer_delete_sync(a1 + 2264);
  return 0;
}
