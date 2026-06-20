__int64 __fastcall ieee80211_send_smps_action(__int64 a1, int a2, int *a3, int *a4, int a5)
{
  __int64 v5; // x25
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x21
  __int64 v14; // x9
  __int64 v15; // x0
  int v16; // w9
  int *v17; // x8
  int v18; // w9
  int v19; // w10
  char v21; // w8
  unsigned int v22; // w8

  v5 = *(_QWORD *)(a1 + 1616);
  v11 = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v5 + 104) + 27), 2080);
  if ( !v11 )
    return 4294967284LL;
  v12 = *(int *)(v5 + 104);
  v13 = v11;
  v14 = *(_QWORD *)(v11 + 224) + v12;
  LODWORD(v12) = *(_DWORD *)(v11 + 208) + v12;
  *(_QWORD *)(v11 + 224) = v14;
  *(_DWORD *)(v11 + 208) = v12;
  v15 = skb_put(v11, 27);
  v16 = *a3;
  *(_WORD *)(v15 + 8) = *((_WORD *)a3 + 2);
  *(_DWORD *)(v15 + 4) = v16;
  v17 = *(int **)(*(_QWORD *)(a1 + 1608) + 1008LL);
  v18 = *v17;
  LOWORD(v17) = *((_WORD *)v17 + 2);
  *(_DWORD *)(v15 + 10) = v18;
  *(_WORD *)(v15 + 14) = (_WORD)v17;
  LOWORD(v18) = *((_WORD *)a4 + 2);
  v19 = *a4;
  *(_WORD *)v15 = 208;
  *(_WORD *)(v15 + 20) = v18;
  *(_DWORD *)(v15 + 16) = v19;
  *(_WORD *)(v15 + 24) = 263;
  if ( a2 > 1 )
  {
    if ( a2 == 2 )
    {
      v21 = 1;
      goto LABEL_14;
    }
    if ( a2 == 3 )
    {
      v21 = 3;
      goto LABEL_14;
    }
    if ( a2 != 4 )
      goto LABEL_15;
    goto LABEL_11;
  }
  if ( !a2 )
  {
LABEL_11:
    v21 = 0;
    __break(0x800u);
    a2 = 1;
    goto LABEL_14;
  }
  if ( a2 == 1 )
  {
    v21 = 0;
LABEL_14:
    *(_BYTE *)(v15 + 26) = v21;
  }
LABEL_15:
  v22 = (((a5 & ~(a5 >> 31)) << 10) | (a2 << 8)) & 0x1FF00 | *(_DWORD *)(v13 + 44) & 0xFFFE000F | 0x10;
  *(_DWORD *)(v13 + 40) |= 1u;
  *(_DWORD *)(v13 + 44) = v22;
  ieee80211_tx_skb_tid(a1, v13, 7, (unsigned int)a5);
  return 0;
}
