__int64 __fastcall _rmnet_map_segment_coal_skb(__int64 a1, __int64 a2, __int64 a3, char a4, char a5)
{
  int v8; // w26
  __int64 v10; // x24
  unsigned int v11; // w28
  int v12; // w8
  __int64 result; // x0
  __int64 v15; // x23
  __int64 v16; // x8
  int v17; // w8
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x8
  __int64 v22; // x13
  __int64 v23; // x10
  unsigned __int64 v24; // x9
  __int64 v25; // x12
  size_t v26; // x25
  __int64 v27; // x11
  __int64 v28; // x20
  __int64 v29; // x27
  int v30; // w21
  __int64 v31; // x26
  __int64 v32; // x24
  void *v33; // x0
  const void *v34; // x1
  int v35; // w9
  int v36; // w11
  __int64 v37; // x1
  int v38; // w8
  __int64 v39; // x8
  __int64 v40; // x9
  int v41; // w10
  __int64 v42; // x8
  _WORD *v43; // x25
  __int16 v44; // w9
  _BOOL4 v45; // w28
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x9
  __int64 v49; // x8
  unsigned int *v50; // x10
  unsigned int v51; // w9
  __int64 v52; // x9
  int v53; // w11
  unsigned int v54; // t1
  unsigned __int64 v55; // t2
  int v56; // w10
  __int64 v57; // x8
  __int64 *v58; // x8
  __int64 v59; // x8
  __int64 v60; // x27
  unsigned int v61; // w24
  __int64 v62; // x8
  unsigned __int64 v63; // t2
  unsigned int v64; // w8
  unsigned __int64 v65; // t2
  unsigned int v66; // w8
  char v67; // [xsp+8h] [xbp-8h]
  char v68; // [xsp+Ch] [xbp-4h]

  v8 = *(unsigned __int8 *)(a2 + 27) * *(unsigned __int16 *)(a2 + 22);
  v10 = *(_QWORD *)(a1 + 16);
  v11 = *(unsigned __int16 *)(a2 + 18) + *(unsigned __int16 *)(a2 + 16);
  if ( *(_DWORD *)(a1 + 116) )
    v12 = 0;
  else
    v12 = *(unsigned __int8 *)(a2 + 27) * *(unsigned __int16 *)(a2 + 22);
  result = _alloc_skb(v12 + v11, 2080, 0, 0xFFFFFFFFLL);
  if ( !result )
    return result;
  v15 = result;
  v16 = *(_QWORD *)(result + 224) + v11;
  *(_DWORD *)(result + 208) += v11;
  *(_QWORD *)(result + 224) = v16;
  v17 = *(_DWORD *)(a1 + 116);
  if ( v17 && *(_DWORD *)(a1 + 112) == v17 )
  {
    v18 = *(_QWORD *)(a1 + 216);
    v19 = *(unsigned int *)(a1 + 212);
    v20 = v18 + v19;
    v21 = *(_QWORD *)(v18 + v19 + 88);
    v22 = v21 & 1;
    if ( !v21 || (v21 & 1) != 0 )
    {
      LODWORD(v26) = *(unsigned __int8 *)(a2 + 27) * *(unsigned __int16 *)(a2 + 22);
      LODWORD(v27) = *(unsigned __int16 *)(a2 + 16);
      LODWORD(v25) = *(unsigned __int16 *)(a2 + 18);
      goto LABEL_15;
    }
    v23 = (v21 << 6) + 0xFFFFD000000000LL;
    v17 = *(_DWORD *)(a1 + 116);
    v24 = (v23 & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + *(unsigned int *)(v20 + 100);
  }
  else
  {
    v24 = *(_QWORD *)(a1 + 224);
  }
  v25 = *(unsigned __int16 *)(a2 + 18);
  v26 = *(unsigned __int8 *)(a2 + 27) * (unsigned int)*(unsigned __int16 *)(a2 + 22);
  v27 = *(unsigned __int16 *)(a2 + 16);
  if ( !v17 )
  {
    v68 = a4;
    v28 = v24 + v27;
    v67 = a5;
    v29 = a3;
    v30 = v8;
    v31 = v10;
    v32 = v25 + *(unsigned __int16 *)(a2 + 20);
    v33 = (void *)skb_put(result, (unsigned int)v26);
    v34 = (const void *)(v28 + v32);
    v10 = v31;
    v8 = v30;
    a3 = v29;
    a5 = v67;
    a4 = v68;
    memcpy(v33, v34, v26);
    goto LABEL_19;
  }
  v18 = *(_QWORD *)(a1 + 216);
  v19 = *(unsigned int *)(a1 + 212);
  v21 = *(_QWORD *)(v18 + v19 + 88);
  v22 = v21 & 1;
LABEL_15:
  v35 = *(_DWORD *)(v18 + v19 + 100);
  v36 = v27 + v25;
  if ( v22 )
    v37 = 0;
  else
    v37 = v21;
  skb_append_pagefrags(result, v37, v36 + (unsigned int)*(unsigned __int16 *)(a2 + 20) + v35, (unsigned int)v26, 17);
  v38 = *(_DWORD *)(v15 + 116) + v26;
  *(_DWORD *)(v15 + 112) += v26;
  *(_DWORD *)(v15 + 116) = v38;
LABEL_19:
  skb_push(v15, *(unsigned __int16 *)(a2 + 18));
  memcpy(*(void **)(v15 + 224), *(const void **)(a2 + 8), *(unsigned __int16 *)(a2 + 18));
  v39 = *(_QWORD *)(v15 + 216);
  v40 = *(_QWORD *)(v15 + 224) - v39;
  *(_WORD *)(v15 + 182) = v40;
  v41 = *(unsigned __int8 *)(a2 + 25);
  if ( v41 == 17 )
  {
    v46 = v39 + (unsigned __int16)v40;
    v43 = (_WORD *)(v46 + 6);
    *(_WORD *)(v46 + 4) = bswap32(*(unsigned __int16 *)(v15 + 112)) >> 16;
    if ( *(_BYTE *)(a2 + 24) == 4 )
    {
      v45 = *v43 == 0;
      goto LABEL_28;
    }
LABEL_26:
    v45 = 0;
    goto LABEL_28;
  }
  if ( v41 != 6 )
  {
    v45 = 0;
    v43 = nullptr;
    goto LABEL_28;
  }
  v42 = v39 + (unsigned __int16)v40;
  v43 = (_WORD *)(v42 + 16);
  v44 = *(_WORD *)(v42 + 12);
  *(_DWORD *)(v42 + 4) = bswap32(bswap32(*(_DWORD *)(v42 + 4)) + *(unsigned __int16 *)(a2 + 20));
  if ( (v44 & 0x900) == 0 || v11 + v8 + *(unsigned __int16 *)(a2 + 20) >= *(_DWORD *)(a1 + 112) )
    goto LABEL_26;
  v45 = 0;
  *(_WORD *)(v42 + 12) = v44 & 0xF6FF;
LABEL_28:
  skb_push(v15, *(unsigned __int16 *)(a2 + 16));
  result = (__int64)memcpy(*(void **)(v15 + 224), *(const void **)a2, *(unsigned __int16 *)(a2 + 16));
  v47 = *(_QWORD *)(v15 + 216);
  v48 = *(_QWORD *)(v15 + 224) - v47;
  *(_WORD *)(v15 + 184) = v48;
  if ( *(_BYTE *)(a2 + 24) == 4 )
  {
    v49 = v47 + (unsigned __int16)v48;
    v50 = (unsigned int *)(v49 + 16);
    *(_WORD *)(v49 + 4) = bswap32(*(unsigned __int8 *)(a2 + 26) + (bswap32(*(unsigned __int16 *)(v49 + 4)) >> 16)) >> 16;
    v51 = *(unsigned __int16 *)(v15 + 112);
    *(_WORD *)(v49 + 10) = 0;
    *(_WORD *)(v49 + 2) = bswap32(v51) >> 16;
    v52 = *(_QWORD *)(v49 + 8) + __CFADD__(*(_QWORD *)(v49 + 8), *(_QWORD *)v49) + *(_QWORD *)v49;
    v53 = (*(_BYTE *)v49 & 0xF) - 3;
    do
    {
      v54 = *v50++;
      --v53;
      v52 += v54;
    }
    while ( v53 > 1 );
    HIDWORD(v55) = (unsigned __int64)(__ROR8__(v52, 32) + v52) >> 32;
    LODWORD(v55) = HIDWORD(v55);
    *(_WORD *)(v49 + 10) = ~(((unsigned int)(v55 >> 16) + HIDWORD(v55)) >> 16);
  }
  else
  {
    *(_WORD *)(v47 + (unsigned __int16)v48 + 4) = bswap32(*(unsigned __int16 *)(v15 + 112) - 40) >> 16;
  }
  if ( (a5 & 1) != 0 || v45 )
  {
    result = rmnet_map_partial_csum(v15, a2);
  }
  else if ( v43 )
  {
    v59 = *(_QWORD *)(v15 + 216);
    v60 = v10;
    v61 = v59 + *(unsigned __int16 *)(v15 + 182) - *(_DWORD *)(v15 + 224);
    v62 = v59 + *(unsigned __int16 *)(v15 + 184);
    if ( *(_BYTE *)(a2 + 24) == 4 )
    {
      HIDWORD(v63) = csum_tcpudp_nofold(
                       *(unsigned int *)(v62 + 12),
                       *(unsigned int *)(v62 + 16),
                       *(_DWORD *)(v15 + 112) - (unsigned int)*(unsigned __int16 *)(a2 + 16),
                       *(unsigned __int8 *)(a2 + 25),
                       0);
      LODWORD(v63) = HIDWORD(v63);
      v64 = ((unsigned int)(v63 >> 16) + HIDWORD(v63)) >> 16;
    }
    else
    {
      LOWORD(v64) = ~(unsigned __int16)csum_ipv6_magic(
                                         v62 + 8,
                                         v62 + 24,
                                         *(_DWORD *)(v15 + 112) - (unsigned int)*(unsigned __int16 *)(a2 + 16),
                                         *(unsigned __int8 *)(a2 + 25),
                                         0);
    }
    *v43 = v64;
    result = skb_checksum(v15, v61, *(_DWORD *)(v15 + 112) - v61, 0);
    HIDWORD(v65) = result;
    LODWORD(v65) = result;
    v10 = v60;
    v66 = 255 - (((unsigned int)(v65 >> 16) + (unsigned int)result) >> 16);
    if ( (unsigned __int16)(255 - (((unsigned int)(v65 >> 16) + (unsigned int)result) >> 16)) < 0x100u )
      LOWORD(v66) = v66 + 1;
    *v43 = v66;
    *(_BYTE *)(v15 + 128) &= 0x9Fu;
  }
  *(_QWORD *)(v15 + 16) = *(_QWORD *)(a1 + 16);
  ++*(_QWORD *)(v10 + 2840);
  if ( *(unsigned __int8 *)(a2 + 27) >= 2u )
  {
    if ( *(_BYTE *)(a2 + 25) == 6 )
    {
      if ( *(_BYTE *)(a2 + 24) == 4 )
        v56 = 1;
      else
        v56 = 16;
    }
    else
    {
      v56 = 0x20000;
    }
    v57 = *(_QWORD *)(v15 + 216) + *(unsigned int *)(v15 + 212);
    *(_DWORD *)(v57 + 24) = v56;
    *(_WORD *)(v57 + 4) = *(_WORD *)(a2 + 22);
    *(_WORD *)(v57 + 6) = *(unsigned __int8 *)(a2 + 27);
  }
  *(_DWORD *)(v15 + 144) = *(_DWORD *)(a1 + 144);
  v58 = *(__int64 **)(a3 + 8);
  *(_QWORD *)v15 = a3;
  *(_QWORD *)(v15 + 8) = v58;
  *(_QWORD *)(a3 + 8) = v15;
  *v58 = v15;
  ++*(_DWORD *)(a3 + 16);
  LOWORD(v58) = *(_WORD *)(a2 + 20);
  *(_BYTE *)(a2 + 26) = a4 + 1;
  *(_BYTE *)(a2 + 27) = 0;
  *(_WORD *)(a2 + 20) = (_WORD)v58 + v8;
  return result;
}
