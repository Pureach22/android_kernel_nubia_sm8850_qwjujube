__int64 __fastcall ieee80211_send_pspoll(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = ieee80211_pspoll_get(a1, a2 + 4720);
  if ( result )
  {
    **(_WORD **)(result + 224) |= 0x1000u;
    *(_DWORD *)(result + 40) |= 0x10000u;
    return ieee80211_tx_skb_tid(a2, result, 7, 0xFFFFFFFFLL);
  }
  return result;
}
