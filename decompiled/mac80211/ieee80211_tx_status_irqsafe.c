__int64 __fastcall ieee80211_tx_status_irqsafe(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v4; // x0
  __int64 result; // x0
  int v6; // w8
  int v7; // w22
  __int64 v8; // x21
  unsigned __int64 v15; // x8

  v2 = a1 + 1576;
  if ( (*(_DWORD *)(a2 + 40) & 1) != 0 )
    v4 = a1 + 1552;
  else
    v4 = a1 + 1576;
  *(_BYTE *)(a2 + 128) = *(_BYTE *)(a2 + 128) & 0xF8 | 2;
  result = skb_queue_tail(v4);
  v6 = *(_DWORD *)(a1 + 1592) + *(_DWORD *)(a1 + 1568);
  if ( v6 >= 129 )
  {
    v7 = v6 + 1;
    do
    {
      result = skb_dequeue(v2);
      if ( !result )
        break;
      v8 = result;
      ieee80211_report_used_skb(a1, result, 1, 0);
      result = dev_kfree_skb_any_reason(v8, 2);
      --v7;
    }
    while ( v7 > 129 );
  }
  _X9 = (unsigned __int64 *)(a1 + 1520);
  __asm { PRFM            #0x11, [X9] }
  do
    v15 = __ldxr(_X9);
  while ( __stlxr(v15 | 1, _X9) );
  __dmb(0xBu);
  if ( (v15 & 1) == 0 )
    return _tasklet_schedule(a1 + 1512);
  return result;
}
