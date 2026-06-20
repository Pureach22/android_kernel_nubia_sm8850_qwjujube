__int64 __fastcall ieee80211_send_teardown_neg_ttlm(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x9
  __int64 v7; // x0
  __int16 v8; // w9
  __int16 v9; // w9
  __int16 v10; // w9
  unsigned int v11; // w9

  v2 = *(_QWORD *)(a1 - 3104);
  result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v2 + 104) + 26), 2080);
  if ( result )
  {
    v4 = *(int *)(v2 + 104);
    v5 = result;
    v6 = *(_QWORD *)(result + 224) + v4;
    LODWORD(v4) = *(_DWORD *)(result + 208) + v4;
    *(_QWORD *)(result + 224) = v6;
    *(_DWORD *)(result + 208) = v4;
    v7 = skb_put(result, 26);
    *(_QWORD *)(v7 + 2) = 0;
    *(_QWORD *)(v7 + 10) = 0;
    *(_QWORD *)(v7 + 18) = 0;
    *(_WORD *)v7 = 208;
    v8 = *(_WORD *)(a1 + 86);
    *(_DWORD *)(v7 + 4) = *(_DWORD *)(a1 + 82);
    *(_WORD *)(v7 + 8) = v8;
    v9 = *(_WORD *)(a1 + 1126);
    *(_DWORD *)(v7 + 10) = *(_DWORD *)(a1 + 1122);
    *(_WORD *)(v7 + 14) = v9;
    v10 = *(_WORD *)(a1 + 86);
    *(_DWORD *)(v7 + 16) = *(_DWORD *)(a1 + 82);
    *(_WORD *)(v7 + 20) = v10;
    *(_WORD *)(v7 + 24) = 549;
    v11 = *(_DWORD *)(v5 + 44) & 0xFFFE000F | 0x20;
    *(_DWORD *)(v5 + 40) |= 1u;
    *(_DWORD *)(v5 + 44) = v11;
    return ieee80211_tx_skb_tid(a1 - 4720, v5, 7, 0xFFFFFFFFLL);
  }
  return result;
}
