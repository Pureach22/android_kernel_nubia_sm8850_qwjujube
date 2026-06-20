__int64 __fastcall ieee80211_strip_8023_mesh_hdr(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  unsigned int v4; // w9
  bool v5; // zf
  unsigned int v6; // w8
  int v7; // w11
  __int64 v8; // x21
  __int64 v9; // x20
  __int64 v10; // x8
  __int64 v11; // x9
  int v12; // w11
  int v13; // w10
  int v14; // w12
  int v15; // w9
  __int16 v16; // w9
  int v17; // w8
  int v18; // w9
  __int64 v19; // x8
  unsigned int v20; // w8
  unsigned int v21; // w9
  __int64 v22; // x9
  _QWORD *v23; // x8
  __int64 v24; // x10
  _QWORD v25[3]; // [xsp+8h] [xbp-18h] BYREF

  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v25, 0, 15);
  result = skb_copy_bits(a1, 0, v25, 15);
  if ( !(_DWORD)result )
  {
    v3 = BYTE6(v25[1]) & 3;
    if ( v3 == 1 )
      v4 = 12;
    else
      v4 = 6;
    v5 = v3 == 2;
    v6 = *(_DWORD *)(a1 + 112);
    v7 = *(_DWORD *)(a1 + 116);
    if ( v5 )
      v8 = 18;
    else
      v8 = v4;
    v9 = v8 + 14;
    if ( (int)v8 + 22 <= v6 - v7 || v6 >= (int)v8 + 22 && _pskb_pull_tail(a1, (_DWORD)v8 + 22 - (v6 - v7)) )
    {
      v10 = *(_QWORD *)(a1 + 224);
      v11 = v10 + v9;
      v12 = *(unsigned __int16 *)(v10 + v9 + 4);
      v13 = *(_DWORD *)(v10 + v9) ^ 0x3AAAA;
      if ( !(v13 | v12) )
      {
        v14 = *(unsigned __int16 *)(v11 + 6);
        if ( v14 != 62336 && v14 != 14209 )
          goto LABEL_17;
      }
      if ( !(v13 | v12 ^ 0xF800) )
      {
        LOWORD(v14) = *(_WORD *)(v11 + 6);
LABEL_17:
        WORD2(v25[1]) = v14;
        LODWORD(v8) = v8 + 8;
LABEL_18:
        v15 = BYTE6(v25[1]) & 3;
        if ( v15 == 2 )
        {
          v18 = *(_DWORD *)(v10 + 28);
          v19 = *(_QWORD *)(v10 + 20);
          LODWORD(v25[1]) = v18;
          v25[0] = v19;
        }
        else if ( v15 == 1 )
        {
          v16 = *(_WORD *)(v10 + 24);
          v17 = *(_DWORD *)(v10 + 20);
          WORD1(v25[1]) = v16;
          *(_DWORD *)((char *)v25 + 6) = v17;
        }
        v20 = *(_DWORD *)(a1 + 112);
        v21 = v20 - *(_DWORD *)(a1 + 116);
        if ( (unsigned int)v8 > v21 )
        {
          if ( v20 < (unsigned int)v8 || !_pskb_pull_tail(a1, (unsigned int)v8 - v21) )
            goto LABEL_25;
          v20 = *(_DWORD *)(a1 + 112);
        }
        v22 = *(_QWORD *)(a1 + 224);
        *(_DWORD *)(a1 + 112) = v20 - v8;
        *(_QWORD *)(a1 + 224) = v22 + (unsigned int)v8;
LABEL_25:
        v23 = *(_QWORD **)(a1 + 224);
        result = 0;
        v24 = v25[0];
        *(_QWORD *)((char *)v23 + 6) = *(_QWORD *)((char *)v25 + 6);
        *v23 = v24;
        goto LABEL_26;
      }
    }
    if ( (pskb_may_pull(a1, (unsigned int)v9) & 1) != 0 )
    {
      v10 = *(_QWORD *)(a1 + 224);
      WORD2(v25[1]) = bswap32(*(_DWORD *)(a1 + 112) - v9) >> 16;
      goto LABEL_18;
    }
    result = 4294967274LL;
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
