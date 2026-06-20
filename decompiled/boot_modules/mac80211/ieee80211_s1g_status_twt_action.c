__int64 __fastcall ieee80211_s1g_status_twt_action(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  __int64 v6; // x22
  unsigned int v7; // w20
  __int64 v8; // x21
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x9
  __int64 v12; // x0
  int v13; // w9
  __int16 v14; // w10
  int v15; // w8

  v2 = *(_QWORD *)(a2 + 224);
  result = sta_info_get_bss(a1, v2 + 4);
  if ( result && *(_BYTE *)(v2 + 25) == 6 )
  {
    v6 = *(_QWORD *)(a2 + 224);
    v7 = (*(unsigned __int16 *)(v6 + 30) >> 7) & 7;
    drv_twt_teardown_request(*(_QWORD *)(a1 + 1616), a1, result + 2688, v7);
    v8 = *(_QWORD *)(a1 + 1616);
    result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v8 + 104) + 27), 2080);
    if ( result )
    {
      v9 = *(int *)(v8 + 104);
      v10 = result;
      v11 = *(_QWORD *)(result + 224) + v9;
      LODWORD(v9) = *(_DWORD *)(result + 208) + v9;
      *(_QWORD *)(result + 224) = v11;
      *(_DWORD *)(result + 208) = v9;
      v12 = skb_put(result, 27);
      *(_QWORD *)(v12 + 2) = 0;
      *(_QWORD *)(v12 + 10) = 0;
      *(_QWORD *)(v12 + 18) = 0;
      *(_BYTE *)(v12 + 26) = 0;
      *(_WORD *)v12 = 208;
      v13 = *(_DWORD *)(v6 + 10);
      *(_WORD *)(v12 + 8) = *(_WORD *)(v6 + 14);
      *(_DWORD *)(v12 + 4) = v13;
      v14 = *(_WORD *)(a1 + 5846);
      *(_DWORD *)(v12 + 10) = *(_DWORD *)(a1 + 5842);
      *(_WORD *)(v12 + 14) = v14;
      v15 = *(_DWORD *)(a1 + 5842);
      LOWORD(v13) = *(_WORD *)(a1 + 5846);
      *(_BYTE *)(v12 + 26) = v7;
      *(_DWORD *)(v12 + 16) = v15;
      *(_WORD *)(v12 + 20) = v13;
      *(_WORD *)(v12 + 24) = 1814;
      *(_DWORD *)(v10 + 40) |= 0x10001u;
      return ieee80211_tx_skb_tid(a1, v10, 7, 0xFFFFFFFFLL);
    }
  }
  return result;
}
