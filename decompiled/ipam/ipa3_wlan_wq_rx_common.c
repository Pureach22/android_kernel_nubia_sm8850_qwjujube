__int64 __fastcall ipa3_wlan_wq_rx_common(__int64 a1, __int64 a2)
{
  __int64 v2; // x2
  int v4; // w8
  __int64 v5; // x2
  _DWORD *v6; // t1
  int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x0
  _DWORD *v10; // x9

  v2 = *(_QWORD *)(a2 + 8);
  --*(_DWORD *)a1;
  v4 = *(unsigned __int16 *)(a2 + 20);
  if ( *(_WORD *)(a2 + 20) )
    *(_DWORD *)(v2 + 40) = v4;
  else
    v4 = *(_DWORD *)(v2 + 40);
  v6 = *(_DWORD **)(v2 + 16);
  v5 = v2 + 16;
  v6[52] = v4 + v6[56] - v6[54];
  v7 = *(_DWORD *)(v5 + 24);
  v6[28] = v7;
  v6[58] = v7 + 248;
  ++*(_DWORD *)(*(_QWORD *)(a1 + 1624) + 436LL);
  if ( *(_DWORD *)a1 > 5u )
  {
    ++*(_DWORD *)(*(_QWORD *)(a1 + 1624) + 440LL);
    v8 = *(_QWORD *)(a1 + 1624);
    v9 = *(_QWORD *)(v8 + 368);
    v10 = *(_DWORD **)(v8 + 376);
    if ( *(v10 - 1) != 420538815 )
      __break(0x8229u);
    ((void (__fastcall *)(__int64, _QWORD))v10)(v9, 0);
  }
  else
  {
    ipa_free_skb((_QWORD *)v5);
    ++*(_DWORD *)(*(_QWORD *)(a1 + 1624) + 444LL);
  }
  return ipa3_replenish_wlan_rx_cache(a1);
}
