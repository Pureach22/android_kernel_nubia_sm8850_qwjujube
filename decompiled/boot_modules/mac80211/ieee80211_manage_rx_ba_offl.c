__int64 __fastcall ieee80211_manage_rx_ba_offl(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 bss; // x0
  unsigned __int64 v14; // x10

  _rcu_read_lock();
  bss = sta_info_get_bss(a1 - 4720, a2);
  if ( bss )
  {
    _X9 = (unsigned __int64 *)(bss + 856 + 8LL * (a3 >> 6));
    __asm { PRFM            #0x11, [X9] }
    do
      v14 = __ldxr(_X9);
    while ( __stxr(v14 | (1LL << a3), _X9) );
    bss = wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(bss + 72) + 72LL), bss + 880);
  }
  return _rcu_read_unlock(bss);
}
