__int64 __fastcall ieee80211_mlo_multicast_tx(__int64 a1, __int64 a2)
{
  unsigned __int64 v4; // x21
  unsigned __int64 v6; // x21
  unsigned __int64 v7; // x22
  __int64 v8; // x0
  __int64 v9; // x0

  v4 = *(unsigned __int16 *)(a1 + 8490);
  if ( (unsigned int)_sw_hweight16(v4) == 1 )
    return _ieee80211_subif_start_xmit(
             a2,
             *(_QWORD *)(a1 + 4296),
             0,
             ((unsigned int)__clz(__rbit64(v4)) << 28) | 0x200,
             0);
  v6 = v4 & 0x7FFF;
  if ( v6 )
  {
    v7 = __clz(__rbit64(v6));
    v8 = skb_copy(a2, 2080);
    if ( v8 )
      _ieee80211_subif_start_xmit(v8, *(_QWORD *)(a1 + 4296), 0, ((_DWORD)v7 << 28) | 0x200, 0);
    if ( v7 <= 0xD )
    {
      do
      {
        if ( (v6 & (-2LL << v7)) == 0 )
          break;
        v7 = __clz(__rbit64(v6 & (-2LL << v7)));
        v9 = skb_copy(a2, 2080);
        if ( v9 )
          _ieee80211_subif_start_xmit(v9, *(_QWORD *)(a1 + 4296), 0, (_DWORD)v7 << 28, 0);
      }
      while ( v7 < 0xE );
    }
  }
  return sk_skb_reason_drop(0);
}
