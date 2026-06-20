__int64 __fastcall ieee80211_send_nullfunc(__int64 a1, __int64 a2, char a3)
{
  __int64 result; // x0
  int v7; // w9
  int v8; // w8

  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, bool))ieee80211_nullfunc_get)(
             a1,
             a2 + 4720,
             0xFFFFFFFFLL,
             (*(_QWORD *)(a1 + 96) & 0x10000000000LL) == 0);
  if ( result )
  {
    if ( (a3 & 1) != 0 )
      **(_WORD **)(result + 224) |= 0x1000u;
    v7 = *(_DWORD *)(result + 40);
    v8 = v7 | 0x12000;
    *(_DWORD *)(result + 40) = v7 | 0x12000;
    if ( (*(_QWORD *)(a1 + 96) & 0x10000) != 0 )
    {
      v8 = v7 | 0x12001;
      *(_DWORD *)(result + 40) = v7 | 0x12001;
    }
    if ( (*(_BYTE *)(a2 + 2500) & 2) != 0 )
      *(_DWORD *)(result + 40) = v8 | 0x20000000;
    return ieee80211_tx_skb_tid(a2, result, 7, 0xFFFFFFFFLL);
  }
  return result;
}
