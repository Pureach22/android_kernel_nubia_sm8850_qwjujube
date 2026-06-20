__int64 __fastcall ieee80211_start_tx_ba_cb(__int64 result, unsigned int a2, __int64 a3)
{
  __int64 v3; // x8
  unsigned __int64 v10; // x9

  v3 = *(_QWORD *)(*(_QWORD *)(result + 80) + 1616LL);
  _X10 = (unsigned __int64 *)(a3 + 128);
  __asm { PRFM            #0x11, [X10] }
  do
    v10 = __ldxr(_X10);
  while ( __stlxr(v10 | 1, _X10) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
  {
    __break(0x800u);
  }
  else if ( (*(_QWORD *)(a3 + 128) & 8) == 0 && (*(_QWORD *)(a3 + 128) & 0x20) == 0 )
  {
    if ( (*(_QWORD *)(a3 + 128) & 0x100) != 0 )
    {
      if ( (*(_QWORD *)(a3 + 128) & 2) != 0 )
        return ieee80211_agg_tx_operational(v3, result, a2);
    }
    else
    {
      return ieee80211_send_addba_with_timeout(result, a3);
    }
  }
  return result;
}
