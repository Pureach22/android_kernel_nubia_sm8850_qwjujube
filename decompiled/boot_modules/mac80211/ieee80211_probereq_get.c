__int64 __fastcall ieee80211_probereq_get(__int64 a1, int *a2, const void *a3, size_t a4, int a5)
{
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x0
  __int16 v14; // w9
  int v15; // w10
  _BYTE *v16; // x0

  v9 = _netdev_alloc_skb(0, (unsigned int)(a4 + a5 + *(_DWORD *)(a1 + 104) + 26), 2080);
  v10 = v9;
  if ( v9 )
  {
    v11 = *(int *)(a1 + 104);
    v12 = *(_QWORD *)(v9 + 224) + v11;
    LODWORD(v11) = *(_DWORD *)(v9 + 208) + v11;
    *(_QWORD *)(v9 + 224) = v12;
    *(_DWORD *)(v9 + 208) = v11;
    v13 = skb_put(v9, 24);
    *(_QWORD *)(v13 + 2) = 0;
    *(_WORD *)v13 = 64;
    *(_QWORD *)(v13 + 10) = 0;
    *(_QWORD *)(v13 + 16) = 0;
    *(_WORD *)(v13 + 8) = -1;
    *(_DWORD *)(v13 + 4) = -1;
    v14 = *((_WORD *)a2 + 2);
    v15 = *a2;
    *(_DWORD *)(v13 + 16) = -1;
    *(_WORD *)(v13 + 20) = -1;
    *(_WORD *)(v13 + 14) = v14;
    *(_DWORD *)(v13 + 10) = v15;
    v16 = (_BYTE *)skb_put(v10, (unsigned int)(a4 + 2));
    *v16 = 0;
    v16[1] = a4;
    if ( a4 )
      memcpy(v16 + 2, a3, a4);
  }
  return v10;
}
