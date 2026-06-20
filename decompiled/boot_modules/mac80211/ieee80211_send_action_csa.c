__int64 __fastcall ieee80211_send_action_csa(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v5; // x22
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 v9; // x9
  __int64 v10; // x0
  int v11; // w8
  __int16 v12; // w9
  __int64 v13; // x22
  int v14; // w8
  unsigned int v15; // w8
  char v16; // w8
  __int64 v18; // x22
  int v19; // w8
  char v20; // w8
  int v21; // w8
  char v22; // w0

  v2 = *(_DWORD *)(a1 + 4720);
  if ( v2 != 7 && v2 != 1 )
    return 4294967201LL;
  v5 = *(_QWORD *)(a1 + 1616);
  v6 = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v5 + 1508) + 47), 2080);
  if ( !v6 )
    return 4294967284LL;
  v7 = *(int *)(v5 + 1508);
  v8 = v6;
  v9 = *(_QWORD *)(v6 + 224) + v7;
  LODWORD(v7) = *(_DWORD *)(v6 + 208) + v7;
  *(_QWORD *)(v6 + 224) = v9;
  *(_DWORD *)(v6 + 208) = v7;
  v10 = skb_put(v6, 26);
  *(_QWORD *)(v10 + 2) = 0;
  *(_WORD *)v10 = 208;
  *(_QWORD *)(v10 + 10) = 0;
  *(_QWORD *)(v10 + 18) = 0;
  *(_WORD *)(v10 + 8) = -1;
  *(_DWORD *)(v10 + 4) = -1;
  v11 = *(_DWORD *)(a1 + 5842);
  *(_WORD *)(v10 + 14) = *(_WORD *)(a1 + 5846);
  *(_DWORD *)(v10 + 10) = v11;
  v12 = *(_WORD *)(a1 + 2350);
  *(_DWORD *)(v10 + 16) = *(_DWORD *)(a1 + 2346);
  *(_WORD *)(v10 + 20) = v12;
  *(_WORD *)(v10 + 24) = 1024;
  v13 = skb_put(v8, 5);
  *(_WORD *)v13 = 805;
  *(_BYTE *)(v13 + 2) = *(_BYTE *)(a2 + 409);
  *(_BYTE *)(v13 + 3) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(*(_QWORD *)a2 + 4LL)));
  *(_BYTE *)(v13 + 4) = *(_BYTE *)(a2 + 410);
  v14 = *(_DWORD *)(a2 + 8);
  if ( v14 != 2 )
  {
    v18 = v13 + 5;
    goto LABEL_15;
  }
  skb_put(v8, 3);
  *(_WORD *)(v13 + 5) = 318;
  v15 = *(_DWORD *)(a2 + 8);
  if ( v15 < 2 )
    goto LABEL_13;
  if ( v15 != 2 )
  {
    __break(0x800u);
LABEL_13:
    v16 = 3;
    goto LABEL_14;
  }
  if ( *(_DWORD *)(a2 + 12) <= *(_DWORD *)(*(_QWORD *)a2 + 4LL) )
    goto LABEL_13;
  v16 = 1;
LABEL_14:
  *(_BYTE *)(v13 + 7) = v16;
  v18 = v13 + 8;
  v14 = *(_DWORD *)(a2 + 8);
LABEL_15:
  if ( (unsigned int)(v14 - 3) <= 2 )
  {
    skb_put(v8, 5);
    *(_WORD *)v18 = 962;
    v19 = *(_DWORD *)(a2 + 8);
    if ( v19 > 4 )
    {
      if ( v19 == 13 )
      {
        __break(0x800u);
      }
      else if ( v19 == 5 )
      {
        v20 = 2;
        goto LABEL_26;
      }
    }
    else
    {
      if ( v19 == 3 )
      {
        v20 = 1;
        goto LABEL_26;
      }
      if ( v19 == 4 )
      {
        v20 = 3;
LABEL_26:
        *(_BYTE *)(v18 + 2) = v20;
        *(_BYTE *)(v18 + 3) = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(a2 + 12)));
        v21 = *(_DWORD *)(a2 + 16);
        if ( v21 )
          v22 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * v21));
        else
          v22 = 0;
        *(_BYTE *)(v18 + 4) = v22;
        goto LABEL_30;
      }
    }
    v20 = 0;
    goto LABEL_26;
  }
LABEL_30:
  ieee80211_tx_skb_tid(a1, v8, 7, -1);
  return 0;
}
