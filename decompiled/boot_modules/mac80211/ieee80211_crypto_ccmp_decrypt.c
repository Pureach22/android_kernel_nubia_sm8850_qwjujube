__int64 __fastcall ieee80211_crypto_ccmp_decrypt(__int64 a1, unsigned int a2)
{
  __int64 v4; // x19
  __int64 v5; // x24
  unsigned __int16 *v6; // x25
  __int16 v7; // w23
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  int v11; // w20
  int v12; // w8
  __int64 result; // x0
  __int64 v14; // x1
  __int64 v15; // x8
  int v16; // w8
  unsigned int v17; // w8
  unsigned int v18; // w9
  unsigned int v19; // w11
  __int64 v20; // x23
  int v21; // w8
  __int64 v22; // x25
  _BYTE *v23; // x10
  unsigned int v24; // w9
  __int64 v25; // x27
  __int64 v26; // x27
  unsigned int v27; // t1
  unsigned __int64 v28; // x10
  unsigned __int64 v29; // x9
  bool v30; // cf
  _BOOL4 v31; // w9
  int v32; // w10
  int v33; // w9
  unsigned int v34; // w8
  unsigned int v35; // w9
  unsigned int v36; // w8
  __int64 v37; // x1
  int v38; // w8
  int v39; // w9
  unsigned __int16 v40; // w9
  unsigned int v41; // [xsp+0h] [xbp-40h] BYREF
  unsigned __int16 v42; // [xsp+4h] [xbp-3Ch]
  _QWORD v43[2]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v44[5]; // [xsp+18h] [xbp-28h] BYREF

  v44[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 8);
  v42 = 0;
  v5 = *(_QWORD *)(a1 + 56);
  v41 = 0;
  v6 = *(unsigned __int16 **)(v4 + 224);
  v7 = *v6;
  v11 = ieee80211_hdrlen(*v6);
  if ( (v7 & 0xC) != 8 )
  {
    if ( *(_DWORD *)(v4 + 112) < 0x19u )
      goto LABEL_39;
    v16 = v7 & 0xFC;
    if ( v16 != 160 && v16 != 192 )
    {
      if ( v16 != 208 )
        goto LABEL_39;
      if ( (v7 & 0x4000) == 0 )
      {
        v17 = *((unsigned __int8 *)v6 + 24);
        result = 1;
        if ( v17 <= 0x16 && ((1 << v17) & 0x708890) != 0 )
          goto LABEL_40;
        if ( v17 == 127 )
          goto LABEL_40;
      }
    }
  }
  v12 = *(_DWORD *)(v4 + 64);
  result = 65571;
  if ( (v12 & 2) != 0 )
  {
    v18 = *(_DWORD *)(v4 + 112);
    v19 = v18 - *(_DWORD *)(v4 + 116);
    v14 = v11 + 8 - v19;
    if ( v11 + 8 > v19 )
    {
      if ( v18 < v11 + 8 )
        goto LABEL_40;
      if ( !_pskb_pull_tail(v4) )
      {
        result = 65571;
        goto LABEL_40;
      }
      v12 = *(_DWORD *)(v4 + 64);
      result = 65571;
    }
    if ( (v12 & 0x200000) != 0 )
      a2 = 0;
  }
  else
  {
    v14 = *(unsigned int *)(v4 + 116);
    if ( (_DWORD)v14 )
    {
      v15 = _pskb_pull_tail(v4);
      result = 65571;
      if ( !v15 )
      {
        result = 65545;
LABEL_40:
        _ReadStatusReg(SP_EL0);
        return result;
      }
    }
  }
  if ( !*(_QWORD *)(a1 + 40) )
    goto LABEL_40;
  v20 = *(_DWORD *)(v4 + 112) - a2 - v11 - 8;
  if ( (v20 & 0x80000000) != 0 )
    goto LABEL_40;
  v21 = *(_DWORD *)(v4 + 64);
  if ( (v21 & 0x400) != 0 )
  {
LABEL_33:
    v36 = *(_DWORD *)(v4 + 112);
    v37 = v36 - a2;
    if ( v36 > (unsigned int)v37 )
    {
      if ( *(_DWORD *)(v4 + 116) )
      {
        if ( (unsigned int)__pskb_trim(v4, v37) )
        {
          result = 65572;
          goto LABEL_40;
        }
      }
      else
      {
        v38 = *(_DWORD *)(v4 + 224);
        v39 = *(_DWORD *)(v4 + 216);
        *(_DWORD *)(v4 + 112) = v37;
        *(_DWORD *)(v4 + 208) = v37 + v38 - v39;
      }
    }
    memmove((void *)(*(_QWORD *)(v4 + 224) + 8LL), *(const void **)(v4 + 224), v11);
    skb_pull(v4, 8);
LABEL_39:
    result = 1;
    goto LABEL_40;
  }
  v22 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 224LL);
  v23 = (_BYTE *)(*(_QWORD *)(v4 + 224) + v11);
  LOBYTE(v41) = v23[7];
  BYTE1(v41) = v23[6];
  BYTE2(v41) = v23[5];
  HIBYTE(v41) = v23[4];
  LOBYTE(v42) = v23[1];
  v24 = *(_DWORD *)(a1 + 72);
  HIBYTE(v42) = *v23;
  if ( v24 < 0x12 )
  {
    v25 = v5 + 6LL * v24;
    v27 = *(_DWORD *)(v25 + 48);
    v26 = v25 + 48;
    v28 = bswap64(v41 | ((unsigned __int64)v42 << 32));
    v29 = bswap64(v27 | ((unsigned __int64)*(unsigned __int16 *)(v26 + 4) << 32));
    v30 = v28 >= v29;
    v31 = v28 > v29;
    v32 = !v30;
    v33 = v31 - v32;
    if ( v33 < 0 || !(v33 | v21 & 0x400000) )
    {
      result = 65538;
      ++*(_DWORD *)(v5 + 160);
      goto LABEL_40;
    }
    if ( (v21 & 2) == 0 )
    {
      v34 = *(unsigned __int16 *)(v5 + 552);
      memset(v44, 0, 32);
      v43[0] = 0;
      v43[1] = 0;
      ccmp_special_blocks(v4, &v41, v43, v44, (v34 >> 11) & 1);
      if ( (unsigned int)aead_decrypt(
                           *(int **)(v5 + 152),
                           (__int64)v43,
                           (char *)v44 + 2,
                           bswap32(LOWORD(v44[0])) >> 16,
                           *(_QWORD *)(v4 + 224) + v11 + 8LL,
                           v20,
                           *(_QWORD *)(v4 + 224) + *(unsigned int *)(v4 + 112) - a2) )
      {
        result = 65537;
        goto LABEL_40;
      }
    }
    v35 = v41;
    *(_WORD *)(v26 + 4) = v42;
    *(_DWORD *)v26 = v35;
    if ( (*(_BYTE *)(v22 + 1) & 4) != 0 || (*(_WORD *)(v22 + 22) & 0xF) != 0 )
    {
      v40 = v42;
      *(_DWORD *)(a1 + 80) = v41;
      *(_WORD *)(a1 + 84) = v40;
    }
    goto LABEL_33;
  }
  __break(0x5512u);
  return ccmp_special_blocks(65571, v14, v8, v9, v10);
}
