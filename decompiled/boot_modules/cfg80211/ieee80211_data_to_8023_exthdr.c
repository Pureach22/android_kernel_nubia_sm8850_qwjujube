__int64 __fastcall ieee80211_data_to_8023_exthdr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int8 a5,
        char a6)
{
  unsigned __int16 *v6; // x8
  unsigned int v7; // w9
  int v8; // w12
  int v10; // w11
  unsigned int v11; // w21
  __int64 result; // x0
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x10
  unsigned __int16 *v16; // x12
  int v17; // w9
  char *v18; // x8
  int v19; // w22
  unsigned __int16 v20; // w23
  int v21; // w24
  int v22; // w25
  int v24; // w9
  unsigned int v25; // w26
  unsigned int v26; // w8
  int v27; // w9
  unsigned int v28; // w8
  unsigned int v29; // w9
  __int64 v30; // x9
  _QWORD v31[2]; // [xsp+0h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int16 **)(a1 + 224);
  v31[0] = 0;
  v7 = *v6;
  if ( (v7 & 0x4C) != 8 )
    goto LABEL_11;
  if ( (v7 & 0x300) == 0x300 )
    v8 = 30;
  else
    v8 = 24;
  if ( (v7 & 0x8000u) == 0 )
    v10 = 2;
  else
    v10 = 6;
  if ( (~v7 & 0x88) != 0 )
    v10 = 0;
  v11 = v8 + v10 + a5;
  if ( *(_DWORD *)(a1 + 112) < v11 )
  {
LABEL_11:
    result = 0xFFFFFFFFLL;
    goto LABEL_52;
  }
  v13 = 16;
  v14 = 2;
  if ( (v7 & 0x100) != 0 )
    v14 = 8;
  if ( (v7 & 0x200) == 0 )
    v13 = 10;
  v15 = 24;
  if ( (v7 & 0x300) != 0x300 )
    v15 = v13;
  v16 = &v6[v14];
  v17 = (v7 >> 8) & 3;
  v18 = (char *)v6 + v15;
  v19 = *(_DWORD *)v16;
  v20 = v16[2];
  v21 = *(_DWORD *)v18;
  v22 = *((unsigned __int16 *)v18 + 2);
  if ( v17 <= 1 )
  {
    if ( v17 )
    {
      result = 0xFFFFFFFFLL;
      if ( a4 > 9 )
        goto LABEL_52;
      v24 = 536;
    }
    else
    {
      result = 0xFFFFFFFFLL;
      if ( a4 > 0xB )
        goto LABEL_52;
      v24 = 2054;
    }
    goto LABEL_32;
  }
  if ( v17 != 2 )
  {
    result = 0xFFFFFFFFLL;
    if ( a4 > 7 )
      goto LABEL_52;
    v24 = 148;
LABEL_32:
    if ( ((1 << a4) & v24) == 0 )
      goto LABEL_52;
    goto LABEL_33;
  }
  result = 0xFFFFFFFFLL;
  if ( a4 > 8
    || ((1 << a4) & 0x184) == 0
    || (v19 & 1) != 0 && !(*(_DWORD *)a3 ^ v21 | *(unsigned __int16 *)(a3 + 4) ^ v22) )
  {
    goto LABEL_52;
  }
LABEL_33:
  if ( a4 == 7 || (a6 & 1) != 0 || (unsigned int)skb_copy_bits(a1, v11, v31, 8) )
    goto LABEL_53;
  if ( LODWORD(v31[0]) ^ 0x3AAAA | WORD2(v31[0])
    || (LOWORD(v25) = HIWORD(v31[0]), HIWORD(v31[0]) == 62336)
    || HIWORD(v31[0]) == 14209 )
  {
    if ( !(LODWORD(v31[0]) ^ 0x3AAAA | WORD2(v31[0]) ^ 0xF800) )
    {
      LOWORD(v25) = HIWORD(v31[0]);
      goto LABEL_39;
    }
LABEL_53:
    v25 = bswap32(*(_DWORD *)(a1 + 112) - v11) >> 16;
    goto LABEL_47;
  }
LABEL_39:
  v26 = *(unsigned __int8 *)(a1 + 128);
  v11 += 8;
  v27 = (v26 >> 5) & 3;
  if ( v27 == 3 )
  {
    if ( *(_DWORD *)(a1 + 216) - *(_DWORD *)(a1 + 224) + *(unsigned __int16 *)(a1 + 140) < 0 )
      *(_BYTE *)(a1 + 128) = v26 & 0x9F;
  }
  else if ( v27 == 2 )
  {
    *(_DWORD *)(a1 + 140) = -(int)csum_partial(v31, 8, (unsigned int)-*(_DWORD *)(a1 + 140));
  }
LABEL_47:
  v28 = *(_DWORD *)(a1 + 112);
  v29 = v28 - *(_DWORD *)(a1 + 116);
  if ( v11 > v29 )
  {
    if ( v28 < v11 || !_pskb_pull_tail(a1, v11 - v29) )
      goto LABEL_49;
    v28 = *(_DWORD *)(a1 + 112);
  }
  v30 = *(_QWORD *)(a1 + 224);
  *(_DWORD *)(a1 + 112) = v28 - v11;
  *(_QWORD *)(a1 + 224) = v30 + v11;
LABEL_49:
  if ( !a2 )
    a2 = skb_push(a1, 14);
  result = 0;
  *(_DWORD *)a2 = v19;
  *(_WORD *)(a2 + 4) = v20;
  *(_DWORD *)(a2 + 6) = v21;
  *(_WORD *)(a2 + 10) = v22;
  *(_WORD *)(a2 + 12) = v25;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}
