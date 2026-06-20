__int64 __fastcall ieee80211_beacon_connection_loss_work(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v7; // x19

  if ( (*(_BYTE *)(a2 + 69) & 1) != 0 )
  {
    v5 = a2 - 2408;
    printk(&unk_B7AAA, a2 - 768, a2 + 2394, a4);
    result = _ieee80211_disconnect(v5);
    *(_BYTE *)(a2 + 69) &= ~1u;
  }
  else if ( (*(_BYTE *)(a2 + 69) & 2) != 0 )
  {
    v7 = a2 - 2408;
    printk(&unk_B98C4, a2 - 768, a2 + 2394, a4);
    result = _ieee80211_disconnect(v7);
    *(_BYTE *)(a2 + 69) &= ~2u;
  }
  else
  {
    if ( (*(_BYTE *)(a2 + 69) & 8) != 0 )
      ++*(_DWORD *)(a2 + 2072);
    return ieee80211_mgd_probe_ap(a2 - 2408, 1);
  }
  return result;
}
