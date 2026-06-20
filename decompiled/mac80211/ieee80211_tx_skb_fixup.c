unsigned __int64 __fastcall ieee80211_tx_skb_fixup(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x9
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x20
  int v6; // w8
  int v7; // w9
  __int16 v8; // w12
  __int16 v9; // w8
  __int64 v10; // x9

  v2 = a1;
  v3 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  if ( !*(_WORD *)(v3 + 4) )
  {
    if ( !*(_DWORD *)(a1 + 116)
      || ((a2 & 0x40) != 0 || !*(_QWORD *)(v3 + 8)) && ((a2 & 1) != 0 || !*(_BYTE *)(v3 + 2))
      || _pskb_pull_tail(a1) )
    {
      if ( (~*(unsigned __int8 *)(v2 + 128) & 0x60) != 0
        || ((v6 = *(_DWORD *)(v2 + 224),
             v7 = *(_DWORD *)(v2 + 216),
             v8 = v7 - v6,
             v9 = v6 - v7,
             (*(_DWORD *)(v2 + 129) & 0x4000) != 0)
          ? (v10 = 174)
          : (v10 = 182),
            *(_WORD *)(v2 + v10) = *(_WORD *)(v2 + 140) + v8 + v9,
            !(unsigned int)skb_csum_hwoffload_help(v2)) )
      {
        *(_QWORD *)v2 = 0;
        return v2;
      }
    }
    goto LABEL_16;
  }
  v4 = _skb_gso_segment(a1, a2, 1);
  if ( v4 )
  {
    if ( v4 <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = v4;
      consume_skb(v2);
      return v5;
    }
LABEL_16:
    sk_skb_reason_drop(0);
    return 0;
  }
  return v2;
}
