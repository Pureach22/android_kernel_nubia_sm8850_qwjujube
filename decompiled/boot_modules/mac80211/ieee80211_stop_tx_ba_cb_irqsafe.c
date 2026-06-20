__int64 __fastcall ieee80211_stop_tx_ba_cb_irqsafe(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 v5; // x22
  __int64 lock; // x0
  __int64 v8; // x8
  unsigned __int64 v16; // x9

  v5 = *(_QWORD *)(a1 - 3104);
  lock = _rcu_read_lock();
  if ( a3 <= 0xFu )
  {
    lock = sta_info_get_bss(a1 - 4720, a2);
    if ( lock )
    {
      v8 = *(_QWORD *)(lock + 8LL * a3 + 904);
      if ( v8 )
      {
        _X8 = (unsigned __int64 *)(v8 + 128);
        __asm { PRFM            #0x11, [X8] }
        do
          v16 = __ldxr(_X8);
        while ( __stxr(v16 | 0x80, _X8) );
        lock = wiphy_work_queue(*(_QWORD *)(v5 + 72), lock + 880);
      }
      else
      {
        __break(0x800u);
      }
    }
  }
  return _rcu_read_unlock(lock);
}
