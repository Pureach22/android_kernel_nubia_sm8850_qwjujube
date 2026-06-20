__int64 __fastcall ieee80211_send_deauth_disassoc(
        __int64 result,
        int *a2,
        int *a3,
        __int16 a4,
        __int16 a5,
        char a6,
        __int64 *a7)
{
  __int64 v7; // x22
  int v8; // w9
  int v9; // w8
  int v10; // w9
  __int64 v11; // x19
  __int64 v13; // x8
  __int64 v14; // x21
  __int64 v15; // x9
  __int64 v16; // x0
  __int64 v17; // x9
  __int64 v18; // x11
  __int64 v19; // x10

  v7 = *(_QWORD *)(result + 1616);
  *(_WORD *)a7 = a4;
  *((_WORD *)a7 + 1) = 0;
  *((_WORD *)a7 + 11) = 0;
  v8 = *a2;
  *((_WORD *)a7 + 4) = *((_WORD *)a2 + 2);
  *((_DWORD *)a7 + 1) = v8;
  v9 = *(_DWORD *)(result + 5842);
  *((_WORD *)a7 + 7) = *(_WORD *)(result + 5846);
  *(_DWORD *)((char *)a7 + 10) = v9;
  LOWORD(v9) = *((_WORD *)a3 + 2);
  v10 = *a3;
  *((_WORD *)a7 + 12) = a5;
  *((_WORD *)a7 + 10) = v9;
  *((_DWORD *)a7 + 4) = v10;
  if ( (a6 & 1) != 0 )
  {
    v11 = result;
    result = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v7 + 104) + 26), 2080);
    if ( result )
    {
      v13 = *(int *)(v7 + 104);
      v14 = result;
      v15 = *(_QWORD *)(result + 224) + v13;
      LODWORD(v13) = *(_DWORD *)(result + 208) + v13;
      *(_QWORD *)(result + 224) = v15;
      *(_DWORD *)(result + 208) = v13;
      v16 = skb_put(result, 26);
      v18 = a7[1];
      v17 = a7[2];
      v19 = *a7;
      *(_WORD *)(v16 + 24) = *((_WORD *)a7 + 12);
      *(_QWORD *)(v16 + 8) = v18;
      *(_QWORD *)(v16 + 16) = v17;
      *(_QWORD *)v16 = v19;
      if ( *(_DWORD *)(v11 + 4720) != 2 || (*(_BYTE *)(v11 + 2500) & 0x40) == 0 )
        *(_DWORD *)(v14 + 40) |= 0x10000u;
      return ieee80211_tx_skb_tid(v11, v14, 7, -1);
    }
  }
  return result;
}
