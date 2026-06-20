__int64 __fastcall ieee80211_rx_irqsafe(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int64 v10; // x8

  *(_BYTE *)(a2 + 128) = *(_BYTE *)(a2 + 128) & 0xF8 | 1;
  result = skb_queue_tail(a1 + 1552);
  _X9 = (unsigned __int64 *)(a1 + 1520);
  __asm { PRFM            #0x11, [X9] }
  do
    v10 = __ldxr(_X9);
  while ( __stlxr(v10 | 1, _X9) );
  __dmb(0xBu);
  if ( (v10 & 1) == 0 )
    return _tasklet_schedule(a1 + 1512);
  return result;
}
