__int64 __fastcall ieee80211_handle_queued_frames(__int64 a1)
{
  __int64 v2; // x21
  __int64 result; // x0
  char v4; // w8
  int v5; // w1

  while ( 1 )
  {
    v2 = skb_dequeue(a1 + 1552);
    if ( !v2 )
    {
      result = skb_dequeue(a1 + 1576);
      v2 = result;
      if ( !result )
        break;
    }
    v4 = *(_BYTE *)(v2 + 128);
    v5 = v4 & 7;
    if ( v5 == 2 )
    {
      *(_BYTE *)(v2 + 128) = v4 & 0xF8;
      ieee80211_tx_status_skb(a1, v2);
    }
    else if ( v5 == 1 )
    {
      *(_BYTE *)(v2 + 128) = v4 & 0xF8;
      ieee80211_rx_napi(a1, 0, v2, 0);
    }
    else
    {
      _warn_printk("mac80211: Packet is of unknown type %d\n", v5);
      __break(0x800u);
      consume_skb(v2);
    }
  }
  return result;
}
