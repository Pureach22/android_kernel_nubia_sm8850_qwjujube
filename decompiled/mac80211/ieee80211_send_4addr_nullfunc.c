__int64 __fastcall ieee80211_send_4addr_nullfunc(__int64 result, __int64 a2)
{
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x9
  __int64 v7; // x0
  int v8; // w9
  __int16 v9; // w10
  __int16 v10; // w10

  if ( *(_DWORD *)(a2 + 4720) == 2 )
  {
    v3 = result;
    result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(result + 104) + 30), 2080);
    if ( result )
    {
      v4 = *(int *)(v3 + 104);
      v5 = result;
      v6 = *(_QWORD *)(result + 224) + v4;
      LODWORD(v4) = *(_DWORD *)(result + 208) + v4;
      *(_QWORD *)(result + 224) = v6;
      *(_DWORD *)(result + 208) = v4;
      v7 = skb_put(result, 30);
      *(_QWORD *)(v7 + 2) = 0;
      *(_QWORD *)(v7 + 10) = 0;
      *(_QWORD *)(v7 + 18) = 0;
      *(_DWORD *)(v7 + 26) = 0;
      *(_WORD *)v7 = 840;
      v8 = *(_DWORD *)(a2 + 4152);
      *(_WORD *)(v7 + 8) = *(_WORD *)(a2 + 4156);
      *(_DWORD *)(v7 + 4) = v8;
      v9 = *(_WORD *)(a2 + 5846);
      *(_DWORD *)(v7 + 10) = *(_DWORD *)(a2 + 5842);
      *(_WORD *)(v7 + 14) = v9;
      v10 = *(_WORD *)(a2 + 4156);
      *(_DWORD *)(v7 + 16) = *(_DWORD *)(a2 + 4152);
      *(_WORD *)(v7 + 20) = v10;
      LOWORD(v8) = *(_WORD *)(a2 + 5846);
      *(_DWORD *)(v7 + 24) = *(_DWORD *)(a2 + 5842);
      *(_WORD *)(v7 + 28) = v8;
      *(_DWORD *)(v5 + 40) |= 0x20010000u;
      return ieee80211_tx_skb_tid(a2, v5, 7, 0xFFFFFFFFLL);
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
