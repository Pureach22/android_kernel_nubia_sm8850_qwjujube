__int64 __fastcall ieee80211_process_measurement_req(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  char v5; // w23
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x21
  __int64 v9; // x9
  __int64 v10; // x0
  __int64 v11; // x22
  __int16 v12; // w10
  int v13; // w8
  int v14; // w9
  char v15; // w8

  v2 = *(_QWORD *)(a1 + 1616);
  v5 = *(_BYTE *)(a2 + 26);
  result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v2 + 104) + 53), 2080);
  if ( result )
  {
    v7 = *(int *)(v2 + 104);
    v8 = result;
    v9 = *(_QWORD *)(result + 224) + v7;
    LODWORD(v7) = *(_DWORD *)(result + 208) + v7;
    *(_QWORD *)(result + 224) = v9;
    *(_DWORD *)(result + 208) = v7;
    v10 = skb_put(result, 24);
    *(_QWORD *)(v10 + 8) = 0;
    *(_QWORD *)(v10 + 16) = 0;
    v11 = v10;
    *(_QWORD *)v10 = 0;
    v12 = *(_WORD *)(a2 + 14);
    *(_DWORD *)(v10 + 4) = *(_DWORD *)(a2 + 10);
    *(_WORD *)(v10 + 8) = v12;
    v13 = *(_DWORD *)(a1 + 5842);
    *(_WORD *)(v10 + 14) = *(_WORD *)(a1 + 5846);
    *(_DWORD *)(v10 + 10) = v13;
    v14 = *(_DWORD *)(a2 + 16);
    *(_WORD *)(v10 + 20) = *(_WORD *)(a2 + 20);
    *(_DWORD *)(v10 + 16) = v14;
    *(_WORD *)v10 = 208;
    skb_put(v8, 8);
    *(_BYTE *)(v11 + 26) = v5;
    *(_WORD *)(v11 + 24) = 256;
    *(_DWORD *)(v11 + 27) = 807;
    *(_BYTE *)(v11 + 31) = 0;
    v15 = *(_BYTE *)(a2 + 29);
    *(_BYTE *)(v11 + 30) = 4;
    *(_BYTE *)(v11 + 29) = v15;
    *(_BYTE *)(v11 + 31) = *(_BYTE *)(a2 + 31);
    return ieee80211_tx_skb_tid(a1, v8, 7, 0xFFFFFFFFLL);
  }
  return result;
}
