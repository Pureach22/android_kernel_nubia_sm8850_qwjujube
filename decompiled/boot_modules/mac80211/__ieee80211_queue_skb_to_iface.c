__int64 __fastcall _ieee80211_queue_skb_to_iface(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x0
  char v7; // w8
  __int64 result; // x0

  v5 = a1 + 1984;
  v7 = *(_BYTE *)(a4 + 86) & 0xFE;
  if ( a2 >= 0 )
    v7 = *(_BYTE *)(a4 + 86) & 0xE0 | (2 * (a2 & 0xF)) | 1;
  *(_BYTE *)(a4 + 86) = v7;
  skb_queue_tail(v5);
  result = wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 1960);
  if ( a3 )
    ++*(_QWORD *)(a3 + 1752);
  return result;
}
