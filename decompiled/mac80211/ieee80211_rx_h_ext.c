__int64 __fastcall ieee80211_rx_h_ext(__int64 a1)
{
  __int64 v1; // x1
  __int64 v2; // x20
  int v3; // w8
  __int64 v4; // x19
  char v5; // w9
  char v6; // w8
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 8);
  if ( (~**(unsigned __int16 **)(v1 + 224) & 0xC) != 0 )
    return 1;
  v2 = *(_QWORD *)(a1 + 24);
  if ( *(_DWORD *)(v2 + 4720) != 2 )
    return 0x20000;
  v3 = *(_DWORD *)(a1 + 76);
  v4 = *(_QWORD *)(a1 + 40);
  v5 = *(_BYTE *)(v1 + 86);
  *(_WORD *)(v1 + 180) = 0;
  if ( v3 < 0 )
    v6 = v5 & 0xFE;
  else
    v6 = v5 & 0xE0 | (2 * (v3 & 0xF)) | 1;
  *(_BYTE *)(v1 + 86) = v6;
  skb_queue_tail(v2 + 1984);
  wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v2 + 1616) + 72LL), v2 + 1960);
  result = 0;
  if ( v4 )
    ++*(_QWORD *)(v4 + 1752);
  return result;
}
