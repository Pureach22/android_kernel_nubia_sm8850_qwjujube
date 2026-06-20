__int64 __fastcall rmnet_map_checksum_downlink_packet(__int64 a1, unsigned __int16 a2)
{
  __int64 v2; // x9
  int v3; // w8
  __int64 v4; // x8
  unsigned __int64 v5; // x10
  __int64 v6; // x11
  unsigned __int64 v7; // x8
  _QWORD *v8; // x8
  __int64 result; // x0
  int v10; // w10
  __int64 v11; // x20
  int v12; // w9
  unsigned __int64 v13; // x19
  __int64 v14; // x9
  __int64 v15; // x10
  int v16; // w9
  unsigned __int64 v17; // x19
  __int64 v18; // x9
  __int64 v19; // x10
  __int64 v20; // x8
  int v21; // w9
  unsigned __int16 *v22; // x21
  int v23; // w9
  __int64 v24; // x10
  unsigned __int64 v25; // x9
  __int64 v26; // x11
  unsigned int v27; // w22
  unsigned int v28; // w0
  __int64 v29; // x3
  unsigned __int16 *v30; // x9
  unsigned int v31; // w8
  unsigned int v32; // w22
  int v33; // w0
  unsigned int v34; // w9
  unsigned int v35; // w10
  unsigned int v36; // w8
  int v37; // w10
  unsigned __int16 v38; // w10
  bool v39; // zf
  __int64 v40; // x3
  char v41; // w11
  __int64 v42; // x10
  _WORD *v43; // x21
  unsigned __int64 v44; // x9
  int v45; // w14
  unsigned int *v46; // x15
  unsigned __int64 v47; // x13
  unsigned int v48; // t1
  unsigned __int64 v49; // x0
  __int64 v50; // x2
  unsigned __int64 v51; // t2
  unsigned int v52; // w13
  unsigned int v53; // w12
  unsigned __int16 v54; // w9
  int v55; // w22
  unsigned __int64 v56; // t2
  unsigned __int16 v57; // w10
  unsigned int v58; // w10
  int v59; // w11
  int v60; // w11

  v2 = *(_QWORD *)(a1 + 16);
  if ( (*(_BYTE *)(v2 + 189) & 1) == 0 )
  {
    v8 = (_QWORD *)(v2 + 2784);
    result = 4294967201LL;
    goto LABEL_56;
  }
  v3 = *(_DWORD *)(a1 + 116);
  if ( v3 && *(_DWORD *)(a1 + 112) == v3 )
  {
    v4 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v5 = 0;
    v6 = *(_QWORD *)(v4 + 88);
    if ( v6 && (v6 & 1) == 0 )
      v5 = (((v6 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + *(unsigned int *)(v4 + 100);
  }
  else
  {
    v5 = *(_QWORD *)(a1 + 224);
  }
  v7 = v5 + a2;
  if ( (*(_BYTE *)(v7 + 1) & 1) != 0 )
  {
    v10 = *(unsigned __int16 *)(a1 + 180);
    v11 = v2 + 2688;
    if ( v10 != 56710 )
    {
      if ( v10 != 8 )
      {
        v8 = (_QWORD *)(v2 + 2752);
        result = 4294967203LL;
        goto LABEL_56;
      }
      v12 = *(_DWORD *)(a1 + 116);
      if ( v12 && *(_DWORD *)(a1 + 112) == v12 )
      {
        v13 = 0;
        v14 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
        v15 = *(_QWORD *)(v14 + 88);
        if ( v15 && (v15 & 1) == 0 )
          v13 = (((v15 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + *(unsigned int *)(v14 + 100);
      }
      else
      {
        v13 = *(_QWORD *)(a1 + 224);
      }
      if ( (*(_WORD *)(v13 + 6) & 0xFF3F) != 0 )
      {
        v20 = 80;
        result = 4294967201LL;
LABEL_55:
        v8 = (_QWORD *)(v11 + v20);
        goto LABEL_56;
      }
      v23 = *(_DWORD *)(a1 + 116);
      if ( v23 && *(_DWORD *)(a1 + 112) == v23 )
      {
        v24 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
        v25 = 0;
        v26 = *(_QWORD *)(v24 + 88);
        if ( v26 && (v26 & 1) == 0 )
          v25 = (((v26 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + *(unsigned int *)(v24 + 100);
      }
      else
      {
        v25 = *(_QWORD *)(a1 + 224);
      }
      v40 = *(unsigned __int8 *)(v13 + 9);
      v41 = *(_BYTE *)v13;
      if ( (_DWORD)v40 == 6 )
      {
        v42 = 16;
      }
      else
      {
        if ( (_DWORD)v40 != 17 )
          goto LABEL_54;
        v42 = 6;
      }
      v43 = (_WORD *)(v25 + 4LL * (v41 & 0xF) + v42);
      if ( v43 )
      {
        if ( (_DWORD)v40 == 17 && !*v43 )
        {
          v20 = 88;
          result = 0;
          goto LABEL_55;
        }
        v44 = *(_QWORD *)(v13 + 8);
        v45 = (v41 & 0xF) - 3;
        v46 = (unsigned int *)(v13 + 16);
        v47 = v44 + __CFADD__(v44, *(_QWORD *)v13) + *(_QWORD *)v13;
        do
        {
          v48 = *v46++;
          --v45;
          v47 += v48;
        }
        while ( v45 > 1 );
        v49 = HIDWORD(v44);
        v50 = (bswap32(*(_QWORD *)v13 >> 16) >> 16) - 4 * (*(_QWORD *)v13 & 0xF);
        HIDWORD(v51) = (__ROR8__(v47, 32) + v47) >> 32;
        LODWORD(v51) = HIDWORD(v51);
        v52 = ((unsigned int)(v51 >> 16) + HIDWORD(v51)) >> 16;
        v53 = -2 - (v52 + (bswap32(*(unsigned __int16 *)(v7 + 6)) >> 16));
        if ( (v52 ^ 0xFFFF) <= (unsigned __int16)v53 )
          v54 = v53;
        else
          v54 = v53 + 1;
        v55 = v54;
        HIDWORD(v56) = csum_tcpudp_nofold(v49, *(unsigned int *)(v13 + 16), v50, v40, 0);
        LODWORD(v56) = HIDWORD(v56);
        v34 = (unsigned __int16)*v43;
        v36 = __rev16(v34);
        v57 = bswap32((v56 >> 16) + HIDWORD(v56));
        v58 = v55 + v57 + ~v36 + ((v55 + (unsigned int)v57) >> 16);
        if ( (unsigned __int16)v58 < (unsigned int)(unsigned __int16)~(_WORD)v36 )
          LOWORD(v58) = v58 + 1;
        v38 = ~(_WORD)v58;
        if ( v38 )
        {
LABEL_42:
          v39 = v38 == v36;
          v20 = 48;
          if ( v39 )
          {
            v20 = 32;
            result = 0;
          }
          else
          {
            result = 4294967274LL;
          }
          goto LABEL_55;
        }
        v59 = *(unsigned __int8 *)(v13 + 9);
        if ( v59 != 6 )
        {
          if ( v59 != 17 )
          {
LABEL_67:
            v38 = 0;
            goto LABEL_42;
          }
          goto LABEL_71;
        }
        goto LABEL_72;
      }
LABEL_54:
      v20 = 72;
      result = 4294967203LL;
      goto LABEL_55;
    }
    v16 = *(_DWORD *)(a1 + 116);
    if ( v16 && *(_DWORD *)(a1 + 112) == v16 )
    {
      v17 = 0;
      v18 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
      v19 = *(_QWORD *)(v18 + 88);
      if ( v19 && (v19 & 1) == 0 )
        v17 = (((v19 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
            + *(unsigned int *)(v18 + 100);
    }
    else
    {
      v17 = *(_QWORD *)(a1 + 224);
    }
    v21 = *(unsigned __int8 *)(v17 + 6);
    if ( v21 == 6 )
    {
      v22 = (unsigned __int16 *)(v17 + 56);
      if ( v17 == -56 )
        goto LABEL_54;
    }
    else
    {
      if ( v21 != 17 )
        goto LABEL_54;
      v22 = (unsigned __int16 *)(v17 + 46);
      if ( v17 == -46 )
        goto LABEL_54;
    }
    v27 = bswap32(~*(unsigned __int16 *)(v7 + 6));
    v28 = ip_compute_csum(v17, 40);
    v29 = *(unsigned __int8 *)(v17 + 6);
    v30 = (unsigned __int16 *)(v17 + 4);
    v31 = bswap32(v28) >> 16;
    if ( (_DWORD)v29 == 17 )
      v30 = (unsigned __int16 *)(v17 + 44);
    v32 = v31 + HIWORD(v27) + ((v31 + HIWORD(v27)) >> 16);
    v33 = csum_ipv6_magic(v17 + 8, v17 + 24, bswap32(*v30) >> 16, v29, 0);
    v34 = *v22;
    v35 = (bswap32(~v33) >> 16) + (unsigned __int16)v32;
    v36 = __rev16(v34);
    v37 = v35 + ~v36 + HIWORD(v35);
    if ( (unsigned __int16)v37 < (unsigned int)(unsigned __int16)~(_WORD)v36 )
      LOWORD(v37) = v37 + 1;
    v38 = ~(_WORD)v37;
    if ( v38 )
      goto LABEL_42;
    v60 = *(unsigned __int8 *)(v17 + 6);
    if ( v60 != 6 )
    {
      if ( v60 != 17 )
        goto LABEL_67;
LABEL_71:
      v38 = -1;
      goto LABEL_42;
    }
LABEL_72:
    if ( v34 == 0xFFFF )
      v38 = -1;
    goto LABEL_42;
  }
  v8 = (_QWORD *)(v2 + 2728);
  result = 4294967274LL;
LABEL_56:
  ++*v8;
  return result;
}
