__int64 __fastcall ieee80211_stop_rx_ba_session(__int64 a1, unsigned __int16 a2, __int64 a3)
{
  __int64 bss; // x0
  __int64 i; // x8
  unsigned __int64 v14; // x13

  _rcu_read_lock();
  bss = sta_info_get_bss(a1 - 4720, a3);
  if ( bss )
  {
    for ( i = 0; i != 16; ++i )
    {
      if ( ((1LL << i) & a2) != 0 )
      {
        _X12 = (unsigned __int64 *)(bss + 848);
        __asm { PRFM            #0x11, [X12] }
        do
          v14 = __ldxr(_X12);
        while ( __stxr(v14 | (1LL << i), _X12) );
      }
    }
    bss = wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(bss + 72) + 72LL), bss + 880);
  }
  return _rcu_read_unlock(bss);
}
