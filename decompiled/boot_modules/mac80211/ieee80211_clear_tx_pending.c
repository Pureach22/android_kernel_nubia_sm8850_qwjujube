__int64 __fastcall ieee80211_clear_tx_pending(__int64 result)
{
  __int64 v1; // x19
  unsigned __int64 v2; // x21
  __int64 v3; // x22

  if ( *(_WORD *)(result + 128) )
  {
    v1 = result;
    v2 = 0;
    v3 = result + 2000;
    while ( v2 != 17 )
    {
      while ( 1 )
      {
        result = skb_dequeue(v3 + 24 * v2);
        if ( !result )
          break;
        result = ieee80211_free_txskb(v1, result);
        if ( v2 >= 0x11 )
          goto LABEL_7;
      }
      if ( ++v2 >= *(unsigned __int16 *)(v1 + 128) )
        return result;
    }
LABEL_7:
    __break(0x5512u);
  }
  return result;
}
