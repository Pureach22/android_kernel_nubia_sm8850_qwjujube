__int64 __fastcall sta_rx_agg_session_timer_expired(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x1
  unsigned __int64 v13; // x10

  v2 = *(_QWORD *)(a1 - 8);
  v3 = *(unsigned __int8 *)(a1 + 98);
  v4 = *(_QWORD *)(a1 + 80);
  v5 = _usecs_to_jiffies(*(unsigned __int16 *)(a1 + 96) << 10) + v4;
  if ( jiffies - v5 < 0 )
    return mod_timer(a1, v5);
  _X9 = (unsigned __int64 *)(v2 + 840 + 8 * (v3 >> 6));
  __asm { PRFM            #0x11, [X9] }
  do
    v13 = __ldxr(_X9);
  while ( __stxr(v13 | (1LL << v3), _X9) );
  return wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v2 + 72) + 72LL), v2 + 880);
}
