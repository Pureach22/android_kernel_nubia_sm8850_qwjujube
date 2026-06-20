__int64 __fastcall aps_dissect_skb(__int64 a1, __int64 a2)
{
  int v2; // w8
  int v3; // w8
  int v4; // w9
  __int64 *v5; // x19
  char v6; // w8
  unsigned int v7; // w8
  int v8; // w9
  int v9; // w8
  int v10; // w9
  __int64 *v11; // x19
  __int64 v12; // x21
  __int64 v13; // x20
  unsigned int v14; // w0
  __int64 v15; // x11
  __int64 v16; // x11
  int v17; // w9
  int v18; // w10
  unsigned __int16 *v19; // x19
  __int64 result; // x0
  __int64 v21; // x20
  int v22; // w0
  __int64 v23; // x20
  int v24; // w8
  int v25; // w8
  __int64 v26; // [xsp+0h] [xbp-40h]
  __int64 v27; // [xsp+0h] [xbp-40h]
  unsigned __int8 v28; // [xsp+8h] [xbp-38h]
  __int64 v29; // [xsp+10h] [xbp-30h] BYREF
  __int64 v30; // [xsp+18h] [xbp-28h]
  __int64 v31; // [xsp+20h] [xbp-20h]
  __int64 v32; // [xsp+28h] [xbp-18h]
  __int64 v33; // [xsp+30h] [xbp-10h]
  __int64 v34; // [xsp+38h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int16 *)(a1 + 180);
  if ( v2 == 56710 )
  {
    v9 = *(_DWORD *)(a1 + 112);
    v10 = *(_DWORD *)(a1 + 116);
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    v29 = 0;
    if ( v9 - v10 <= 39 )
    {
      if ( !a1 )
        goto LABEL_29;
      v12 = a2;
      v27 = a1;
      v11 = &v29;
      v25 = skb_copy_bits(a1, 0, &v29, 40);
      a1 = v27;
      if ( v25 < 0 )
        goto LABEL_29;
    }
    else
    {
      v11 = *(__int64 **)(a1 + 224);
      v12 = a2;
      if ( !v11 )
        goto LABEL_29;
    }
    v13 = a1;
    v28 = *((_BYTE *)v11 + 6);
    v14 = ipv6_skip_exthdr();
    if ( (v14 & 0x80000000) != 0 )
    {
      result = 4294967282LL;
      goto LABEL_30;
    }
    v7 = v14;
    a2 = v12;
    v8 = v28;
    a1 = v13;
    *(_BYTE *)v12 = 6;
    *(_BYTE *)(v12 + 3) = v28;
    v15 = v11[1];
    *(_QWORD *)(v12 + 12) = v11[2];
    *(_QWORD *)(v12 + 4) = v15;
    v16 = v11[3];
    *(_QWORD *)(v12 + 28) = v11[4];
    *(_QWORD *)(v12 + 20) = v16;
    *(_BYTE *)(v12 + 44) = bswap32(*(_DWORD *)v11 & 0xF00F) >> 20;
    *(_DWORD *)(v12 + 40) = bswap32(*(_DWORD *)v11 & 0xFFFF0F00);
    if ( !*(_BYTE *)(v12 + 1) )
      goto LABEL_15;
  }
  else
  {
    if ( v2 != 8 )
      goto LABEL_29;
    v3 = *(_DWORD *)(a1 + 112);
    v4 = *(_DWORD *)(a1 + 116);
    LODWORD(v31) = 0;
    v29 = 0;
    v30 = 0;
    if ( v3 - v4 <= 19 )
    {
      if ( !a1 )
        goto LABEL_29;
      v23 = a2;
      v26 = a1;
      v5 = &v29;
      v24 = skb_copy_bits(a1, 0, &v29, 20);
      a1 = v26;
      a2 = v23;
      if ( v24 < 0 )
        goto LABEL_29;
    }
    else
    {
      v5 = *(__int64 **)(a1 + 224);
      if ( !v5 )
        goto LABEL_29;
    }
    v6 = *(_BYTE *)v5;
    if ( (*(_BYTE *)v5 & 0xFu) < 5 )
      goto LABEL_29;
    if ( (*((_WORD *)v5 + 3) & 0xFF3F) != 0 )
    {
      *(_BYTE *)(a2 + 1) = 1;
      *(_BYTE *)(a2 + 2) = (*((_WORD *)v5 + 3) & 0xFF1F) == 0;
      v6 = *(_BYTE *)v5;
    }
    v7 = 4 * (v6 & 0xF);
    *(_BYTE *)a2 = 4;
    v8 = *((unsigned __int8 *)v5 + 9);
    *(_BYTE *)(a2 + 3) = v8;
    *(_DWORD *)(a2 + 4) = *((_DWORD *)v5 + 3);
    *(_DWORD *)(a2 + 20) = *((_DWORD *)v5 + 4);
    *(_BYTE *)(a2 + 44) = *((_BYTE *)v5 + 1);
    if ( !*(_BYTE *)(a2 + 1) )
      goto LABEL_15;
  }
  if ( !*(_BYTE *)(a2 + 2) )
  {
LABEL_20:
    result = 0;
    goto LABEL_30;
  }
LABEL_15:
  if ( v8 != 17 && v8 != 6 )
    goto LABEL_20;
  v17 = *(_DWORD *)(a1 + 112);
  v18 = *(_DWORD *)(a1 + 116);
  LODWORD(v29) = 0;
  if ( (int)(v17 - v18 - v7) <= 3 )
  {
    if ( a1 )
    {
      v21 = a2;
      v19 = (unsigned __int16 *)&v29;
      v22 = skb_copy_bits(a1, v7, &v29, 4);
      a2 = v21;
      if ( (v22 & 0x80000000) == 0 )
        goto LABEL_19;
    }
LABEL_29:
    result = 4294967274LL;
    goto LABEL_30;
  }
  v19 = (unsigned __int16 *)(*(_QWORD *)(a1 + 224) + v7);
  if ( !v19 )
    goto LABEL_29;
LABEL_19:
  result = 0;
  *(_WORD *)(a2 + 36) = bswap32(*v19) >> 16;
  *(_WORD *)(a2 + 38) = bswap32(v19[1]) >> 16;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
