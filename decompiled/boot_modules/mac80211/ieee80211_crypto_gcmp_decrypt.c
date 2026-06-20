__int64 __fastcall ieee80211_crypto_gcmp_decrypt(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x23
  unsigned __int16 *v4; // x24
  __int16 v5; // w22
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  int v9; // w20
  unsigned int v10; // w8
  __int64 result; // x0
  __int64 v12; // x1
  int v13; // w24
  int v14; // w8
  unsigned int v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w11
  __int64 v18; // x22
  int v19; // w8
  __int64 v20; // x25
  _BYTE *v21; // x10
  unsigned int v22; // w9
  __int64 v23; // x27
  __int64 v24; // x27
  unsigned int v25; // t1
  unsigned __int64 v26; // x10
  unsigned __int64 v27; // x9
  bool v28; // cf
  _BOOL4 v29; // w9
  int v30; // w10
  int v31; // w9
  unsigned int v32; // w8
  unsigned int v33; // w9
  unsigned int v34; // w8
  __int64 v35; // x1
  int v36; // w8
  int v37; // w9
  unsigned __int16 v38; // w9
  unsigned int v39; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int16 v40; // [xsp+4h] [xbp-3Ch]
  _QWORD v41[2]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v42[5]; // [xsp+18h] [xbp-28h] BYREF

  v42[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 8);
  v40 = 0;
  v3 = *(_QWORD *)(a1 + 56);
  v39 = 0;
  v4 = *(unsigned __int16 **)(v2 + 224);
  v5 = *v4;
  v9 = ieee80211_hdrlen(*v4);
  if ( (v5 & 0xC) != 8 )
  {
    if ( *(_DWORD *)(v2 + 112) < 0x19u )
      goto LABEL_41;
    v14 = v5 & 0xFC;
    if ( v14 != 160 && v14 != 192 )
    {
      if ( v14 != 208 )
        goto LABEL_41;
      if ( (v5 & 0x4000) == 0 )
      {
        v15 = *((unsigned __int8 *)v4 + 24);
        result = 1;
        if ( v15 <= 0x16 && ((1 << v15) & 0x708890) != 0 )
          goto LABEL_42;
        if ( v15 == 127 )
          goto LABEL_42;
      }
    }
  }
  v10 = *(_DWORD *)(v2 + 64);
  result = 65573;
  if ( (v10 & 2) != 0 )
  {
    v16 = *(_DWORD *)(v2 + 112);
    v17 = v16 - *(_DWORD *)(v2 + 116);
    v12 = v9 + 8 - v17;
    if ( v9 + 8 > v17 )
    {
      if ( v16 < v9 + 8 )
        goto LABEL_42;
      if ( !_pskb_pull_tail(v2) )
      {
        result = 65573;
        goto LABEL_42;
      }
      v10 = *(_DWORD *)(v2 + 64);
      result = 65573;
    }
    v13 = ~(v10 >> 17) & 0x10;
    if ( !*(_QWORD *)(a1 + 40) )
      goto LABEL_42;
  }
  else
  {
    v12 = *(unsigned int *)(v2 + 116);
    if ( (_DWORD)v12 )
    {
      if ( !_pskb_pull_tail(v2) )
      {
        result = 65545;
        goto LABEL_42;
      }
      v13 = 16;
      result = 65573;
      if ( !*(_QWORD *)(a1 + 40) )
        goto LABEL_42;
    }
    else
    {
      v13 = 16;
      if ( !*(_QWORD *)(a1 + 40) )
      {
LABEL_42:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
  }
  v18 = (unsigned int)(*(_DWORD *)(v2 + 112) - v13 - v9 - 8);
  if ( (v18 & 0x80000000) != 0 )
    goto LABEL_42;
  v19 = *(_DWORD *)(v2 + 64);
  if ( (v19 & 0x400) != 0 )
  {
LABEL_35:
    v34 = *(_DWORD *)(v2 + 112);
    v35 = v34 - v13;
    if ( v34 > (unsigned int)v35 )
    {
      if ( *(_DWORD *)(v2 + 116) )
      {
        if ( (unsigned int)__pskb_trim(v2, v35) )
        {
          result = 65574;
          goto LABEL_42;
        }
      }
      else
      {
        v36 = *(_DWORD *)(v2 + 224);
        v37 = *(_DWORD *)(v2 + 216);
        *(_DWORD *)(v2 + 112) = v35;
        *(_DWORD *)(v2 + 208) = v35 + v36 - v37;
      }
    }
    memmove((void *)(*(_QWORD *)(v2 + 224) + 8LL), *(const void **)(v2 + 224), v9);
    skb_pull(v2, 8);
LABEL_41:
    result = 1;
    goto LABEL_42;
  }
  v20 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 224LL);
  v21 = (_BYTE *)(*(_QWORD *)(v2 + 224) + v9);
  LOBYTE(v39) = v21[7];
  BYTE1(v39) = v21[6];
  BYTE2(v39) = v21[5];
  HIBYTE(v39) = v21[4];
  LOBYTE(v40) = v21[1];
  v22 = *(_DWORD *)(a1 + 72);
  HIBYTE(v40) = *v21;
  if ( v22 < 0x12 )
  {
    v23 = v3 + 6LL * v22;
    v25 = *(_DWORD *)(v23 + 48);
    v24 = v23 + 48;
    v26 = bswap64(v39 | ((unsigned __int64)v40 << 32));
    v27 = bswap64(v25 | ((unsigned __int64)*(unsigned __int16 *)(v24 + 4) << 32));
    v28 = v26 >= v27;
    v29 = v26 > v27;
    v30 = !v28;
    v31 = v29 - v30;
    if ( v31 < 0 || !(v31 | v19 & 0x400000) )
    {
      result = 65538;
      ++*(_DWORD *)(v3 + 160);
      goto LABEL_42;
    }
    if ( (v19 & 2) == 0 )
    {
      v32 = *(unsigned __int16 *)(v3 + 552);
      memset(v42, 0, 32);
      v41[0] = 0;
      v41[1] = 0;
      gcmp_special_blocks(v2, &v39, v41, v42, (v32 >> 11) & 1);
      if ( (unsigned int)aead_decrypt(
                           *(int **)(v3 + 152),
                           (__int64)v41,
                           (char *)v42 + 2,
                           bswap32(LOWORD(v42[0])) >> 16,
                           *(_QWORD *)(v2 + 224) + v9 + 8LL,
                           v18,
                           *(_QWORD *)(v2 + 224) + *(unsigned int *)(v2 + 112) - 16LL) )
      {
        result = 65537;
        goto LABEL_42;
      }
    }
    v33 = v39;
    *(_WORD *)(v24 + 4) = v40;
    *(_DWORD *)v24 = v33;
    if ( (*(_BYTE *)(v20 + 1) & 4) != 0 || (*(_WORD *)(v20 + 22) & 0xF) != 0 )
    {
      v38 = v40;
      *(_DWORD *)(a1 + 80) = v39;
      *(_WORD *)(a1 + 84) = v38;
    }
    goto LABEL_35;
  }
  __break(0x5512u);
  return gcmp_special_blocks(65573, v12, v6, v7, v8);
}
