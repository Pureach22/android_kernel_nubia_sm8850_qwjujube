__int64 __fastcall rmnet_map_deaggregate(__int64 a1, __int64 a2)
{
  int v2; // w8
  unsigned __int16 *v3; // x21
  __int64 v4; // x8
  __int64 v5; // x9
  int v6; // w9
  int v7; // w10
  unsigned int v8; // w11
  unsigned int v9; // w19
  _DWORD *v10; // x10
  __int64 v11; // x20
  __int64 v12; // x22
  __int64 v13; // x21
  __int64 v14; // x23
  __int64 v15; // x0
  __int64 v16; // x1
  unsigned int v17; // w8
  __int64 v18; // x0
  int v19; // w9
  unsigned int v20; // w8
  unsigned int v21; // w9
  __int64 v22; // x9

  v2 = *(_DWORD *)(a1 + 116);
  if ( !v2 || *(_DWORD *)(a1 + 112) != v2 )
  {
    v3 = *(unsigned __int16 **)(a1 + 224);
    v6 = *(_DWORD *)(a1 + 112);
    if ( v6 )
      goto LABEL_7;
    return 0;
  }
  v3 = nullptr;
  v4 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
  v5 = *(_QWORD *)(v4 + 88);
  if ( v5 && (v5 & 1) == 0 )
    v3 = (unsigned __int16 *)((((v5 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                            + *(unsigned int *)(v4 + 100));
  v6 = *(_DWORD *)(a1 + 112);
  if ( !v6 )
    return 0;
LABEL_7:
  v7 = *(_DWORD *)(a2 + 8);
  v8 = __rev16(v3[1]);
  if ( (v7 & 4) != 0 )
  {
    v10 = nullptr;
    v9 = v8 + 12;
  }
  else
  {
    v9 = v8 + 4;
    if ( (v7 & 0x20) == 0 || *(char *)v3 < 0 )
    {
      v10 = nullptr;
    }
    else
    {
      v9 = v8 + 8;
      v10 = v3 + 2;
    }
  }
  v11 = 0;
  if ( (int)(v6 - v9) >= 0 && v3[1] )
  {
    if ( v10 && (*v10 & 0xFE) == 2 )
      return a1;
    if ( *(_DWORD *)(a1 + 116) )
    {
      v12 = a1;
      v13 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
      v14 = *(_QWORD *)(v13 + 88);
      v15 = _alloc_skb(32, 2080, 0, 0xFFFFFFFFLL);
      v11 = v15;
      if ( !v15 )
        return v11;
      if ( (v14 & 1) != 0 )
        v16 = 0;
      else
        v16 = v14;
      skb_append_pagefrags(v15, v16, *(unsigned int *)(v13 + 100), v9, 17);
      v17 = *(_DWORD *)(v11 + 116) + v9;
      *(_DWORD *)(v11 + 112) += v9;
      *(_DWORD *)(v11 + 116) = v17;
    }
    else
    {
      v12 = a1;
      v18 = _alloc_skb(v9 + 64, 2080, 0, 0xFFFFFFFFLL);
      v11 = v18;
      if ( !v18 )
        return v11;
      v19 = *(_DWORD *)(v18 + 208) + 32;
      *(_QWORD *)(v18 + 224) += 32LL;
      *(_DWORD *)(v18 + 208) = v19;
      skb_put(v18, v9);
      memcpy(*(void **)(v11 + 224), v3, v9);
    }
    *(_DWORD *)(v11 + 144) = *(_DWORD *)(v12 + 144);
    v20 = *(_DWORD *)(v12 + 112);
    v21 = v20 - *(_DWORD *)(v12 + 116);
    if ( v9 <= v21 )
    {
LABEL_29:
      v22 = *(_QWORD *)(v12 + 224);
      *(_DWORD *)(v12 + 112) = v20 - v9;
      *(_QWORD *)(v12 + 224) = v22 + v9;
      return v11;
    }
    if ( v20 >= v9 && _pskb_pull_tail(v12, v9 - v21) )
    {
      v20 = *(_DWORD *)(v12 + 112);
      goto LABEL_29;
    }
  }
  return v11;
}
