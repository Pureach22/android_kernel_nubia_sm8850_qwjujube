__int64 __fastcall ieee80211_send_bar(__int64 a1, __int64 a2, unsigned __int16 a3, __int16 a4)
{
  __int64 v6; // x23
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x23
  __int64 v12; // x9
  __int64 v13; // x0
  __int16 v14; // w9
  int v15; // w8
  __int16 v16; // w10

  v6 = *(_QWORD *)(a1 - 3104);
  result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v6 + 104) + 20), 2080);
  if ( result )
  {
    v10 = *(int *)(v6 + 104);
    v11 = result;
    v12 = *(_QWORD *)(result + 224) + v10;
    LODWORD(v10) = *(_DWORD *)(result + 208) + v10;
    *(_QWORD *)(result + 224) = v12;
    *(_DWORD *)(result + 208) = v10;
    v13 = skb_put(result, 20);
    *(_QWORD *)(v13 + 2) = 0;
    *(_QWORD *)(v13 + 10) = 0;
    *(_WORD *)(v13 + 18) = 0;
    *(_WORD *)v13 = 132;
    v14 = *(_WORD *)(a2 + 4);
    *(_DWORD *)(v13 + 4) = *(_DWORD *)a2;
    *(_WORD *)(v13 + 8) = v14;
    v15 = *(_DWORD *)(a1 + 1122);
    v16 = *(_WORD *)(a1 + 1126);
    *(_WORD *)(v13 + 18) = a4;
    *(_DWORD *)(v13 + 10) = v15;
    *(_WORD *)(v13 + 14) = v16;
    *(_WORD *)(v13 + 16) = (a3 << 12) | 4;
    *(_DWORD *)(v11 + 40) |= 0x10001u;
    return ieee80211_tx_skb_tid(a1 - 4720, v11, a3, 0xFFFFFFFFLL);
  }
  return result;
}
