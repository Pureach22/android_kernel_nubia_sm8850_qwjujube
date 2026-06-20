__int64 __fastcall rmnet_frag_deliver(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  int v6; // w9
  unsigned int v7; // w28
  __int64 v8; // x0
  __int64 v9; // x20
  int v10; // w9
  __int64 v11; // x0
  int v12; // w8
  __int64 *v13; // x28
  __int64 *v14; // x22
  __int64 v15; // x27
  __int64 *v16; // x20
  unsigned int v17; // w23
  __int64 v18; // x24
  __int64 v19; // x0
  __int64 *v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  unsigned int v23; // w9
  unsigned int v30; // w9
  int v31; // w8
  int v32; // w8
  __int64 v33; // x9
  unsigned __int64 v34; // x8
  __int64 v35; // x10
  __int16 v36; // w9
  unsigned int v37; // w12
  unsigned __int16 v38; // w9
  int v39; // w8
  __int64 v40; // x8
  unsigned __int64 v41; // x9
  __int64 v42; // x10
  int v43; // w8
  __int64 v44; // x8
  unsigned __int64 v45; // x9
  __int64 v46; // x10
  unsigned int v47; // w8
  __int64 v48; // x22
  unsigned int v49; // w23
  unsigned int *v50; // x10
  int v51; // w12
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x9
  int v54; // w11
  unsigned int v55; // t1
  __int64 v56; // x1
  unsigned __int64 v57; // t2
  unsigned int v58; // w8
  int v59; // w8
  __int64 v60; // x8
  unsigned int v61; // w9
  unsigned int v62; // w22
  __int64 v63; // x8
  __int16 v64; // w10
  unsigned int v65; // w9
  unsigned __int16 v66; // w11
  unsigned int v67; // w12
  unsigned __int16 v68; // w11
  unsigned __int16 v69; // w10
  unsigned __int64 v70; // t2
  unsigned int v71; // w0
  __int64 *v72; // x26
  __int64 v73; // x23
  unsigned int v74; // w8
  unsigned int v75; // w27
  unsigned int v76; // w22
  unsigned int v77; // w10
  unsigned int v78; // w11
  __int64 v79; // x10
  unsigned __int64 v80; // x9
  size_t v81; // x24
  _WORD *v82; // x0
  char v83; // w8
  int v84; // w9
  int v85; // w8
  int v86; // w9
  int v87; // w10
  __int64 v88; // x8
  __int64 result; // x0
  __int64 v90; // x20
  __int64 v91; // x23
  unsigned __int64 v92; // t2
  unsigned int v93; // w8

  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(a1 + 81) & 2) == 0 )
  {
    v4 = _alloc_skb(288, 2080, 0, 0xFFFFFFFFLL);
    if ( !v4 )
      goto LABEL_108;
    v5 = v4;
    v6 = *(_DWORD *)(v4 + 208) + 32;
    *(_QWORD *)(v4 + 224) += 32LL;
    *(_DWORD *)(v4 + 208) = v6;
    goto LABEL_10;
  }
  v7 = (unsigned __int16)(*(_WORD *)(a1 + 76) + *(_WORD *)(a1 + 74));
  v8 = _alloc_skb(v7 + 32, 2080, 0, 0xFFFFFFFFLL);
  if ( !v8 )
    goto LABEL_108;
  v5 = v8;
  v9 = a2;
  v10 = *(_DWORD *)(v8 + 208) + 32;
  *(_QWORD *)(v8 + 224) += 32LL;
  *(_DWORD *)(v8 + 208) = v10;
  v11 = skb_put();
  if ( *(_DWORD *)(a1 + 48) >= v7 )
  {
    if ( v7 )
    {
      v72 = *(__int64 **)(a1 + 16);
      if ( v72 != (__int64 *)(a1 + 16) )
      {
        v73 = v11;
        v74 = 0;
        v75 = 0;
        v76 = v7;
        do
        {
          v77 = *((_DWORD *)v72 + 6);
          if ( v74 >= v77 )
          {
            v74 -= v77;
          }
          else
          {
            v78 = v77 - v74;
            v79 = v72[2];
            v80 = 0;
            if ( v76 >= v78 )
              v81 = v78;
            else
              v81 = v76;
            if ( v79 && (v79 & 1) == 0 )
              v80 = (((v79 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                  + *((unsigned int *)v72 + 7);
            memcpy((void *)(v73 + v75), (const void *)(v80 + v74), v81);
            v74 = 0;
            v75 += v81;
            v76 -= v81;
          }
          v72 = (__int64 *)*v72;
        }
        while ( v72 != (__int64 *)(a1 + 16) && v76 );
      }
    }
  }
  v12 = *(_DWORD *)(v5 + 224) - *(_DWORD *)(v5 + 216);
  *(_WORD *)(v5 + 184) = *(_WORD *)(v5 + 224) - *(_WORD *)(v5 + 216);
  if ( *(_WORD *)(a1 + 76) )
    *(_WORD *)(v5 + 182) = *(_WORD *)(a1 + 74) + v12;
  a2 = v9;
  if ( *(_DWORD *)(a1 + 48) != v7 )
  {
    if ( !rmnet_frag_pull(a1, v9, v7) )
    {
      kfree(v5);
      goto LABEL_108;
    }
LABEL_10:
    v13 = *(__int64 **)(a1 + 16);
    if ( v13 != (__int64 *)(a1 + 16) )
    {
      v14 = (__int64 *)v5;
      v15 = *(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212);
      while ( 1 )
      {
        v16 = (__int64 *)*v13;
        v17 = *((_DWORD *)v13 + 6);
        v18 = (v13[2] & 1) != 0 ? 0LL : v13[2];
        if ( *(unsigned __int8 *)(v15 + 2) >= 0x11u )
          break;
LABEL_20:
        v21 = *(_QWORD *)(v18 + 8);
        if ( (v21 & 1) != 0 )
          v22 = v21 - 1;
        else
          v22 = v18;
        _X8 = (unsigned int *)(v22 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
          v30 = __ldxr(_X8);
        while ( __stxr(v30 + 1, _X8) );
        skb_add_rx_frag_netmem(v14, *(unsigned __int8 *)(v15 + 2), v18, *((unsigned int *)v13 + 7), v17, v17);
        if ( v14 != (__int64 *)v5 )
        {
          v23 = *(_DWORD *)(v5 + 116) + v17;
          *(_DWORD *)(v5 + 112) += v17;
          *(_DWORD *)(v5 + 116) = v23;
        }
        v13 = v16;
        if ( v16 == (__int64 *)(a1 + 16) )
          goto LABEL_30;
      }
      while ( 1 )
      {
        v19 = _alloc_skb(0, 2080, 0, 0xFFFFFFFFLL);
        if ( !v19 )
          break;
        v20 = (__int64 *)(v15 + 8);
        if ( v14 != (__int64 *)v5 )
          v20 = v14;
        v14 = (__int64 *)v19;
        *v20 = v19;
        v15 = *(_QWORD *)(v19 + 216) + *(unsigned int *)(v19 + 212);
        if ( *(unsigned __int8 *)(v15 + 2) < 0x11u )
          goto LABEL_20;
      }
    }
  }
LABEL_30:
  *(_QWORD *)(v5 + 16) = *(_QWORD *)(a1 + 32);
  rmnet_set_skb_proto(v5);
  *(_DWORD *)(v5 + 44) = *(_DWORD *)(a1 + 44);
  *(_DWORD *)(v5 + 48) = *(_DWORD *)(a1 + 40);
  v31 = *(unsigned __int8 *)(a1 + 81);
  if ( (v31 & 4) != 0 )
  {
    v32 = *(_DWORD *)(v5 + 116);
    if ( v32 && *(_DWORD *)(v5 + 112) == v32 )
    {
      v33 = *(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212);
      v34 = 0;
      v35 = *(_QWORD *)(v33 + 88);
      if ( v35 && (v35 & 1) == 0 )
        v34 = (((v35 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
            + *(unsigned int *)(v33 + 100);
    }
    else
    {
      v34 = *(_QWORD *)(v5 + 224);
    }
    v36 = *(_WORD *)(v34 + 4);
    v37 = *(unsigned __int16 *)(a1 + 64);
    _CF = (unsigned __int16)(-2 - (v36 + *(_WORD *)(v34 + 10))) >= (unsigned int)(unsigned __int16)~v36;
    v38 = -2 - (v36 + *(_WORD *)(v34 + 10)) + v37;
    if ( !_CF )
      ++v38;
    if ( v37 > v38 )
      ++v38;
    *(_WORD *)(v34 + 10) = ~v38;
    *(_WORD *)(v34 + 4) = *(_WORD *)(a1 + 64);
    v31 = *(unsigned __int8 *)(a1 + 81);
    if ( (v31 & 8) == 0 )
    {
LABEL_32:
      if ( (v31 & 0x20) == 0 )
        goto LABEL_59;
      goto LABEL_52;
    }
  }
  else if ( (v31 & 8) == 0 )
  {
    goto LABEL_32;
  }
  v39 = *(_DWORD *)(v5 + 116);
  if ( v39 && *(_DWORD *)(v5 + 112) == v39 )
  {
    v40 = *(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212);
    v41 = 0;
    v42 = *(_QWORD *)(v40 + 88);
    if ( v42 && (v42 & 1) == 0 )
      v41 = (((v42 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
          + *(unsigned int *)(v40 + 100);
  }
  else
  {
    v41 = *(_QWORD *)(v5 + 224);
  }
  *(_DWORD *)(v41 + *(unsigned __int16 *)(a1 + 74) + 4) = *(_DWORD *)(a1 + 60);
  v31 = *(unsigned __int8 *)(a1 + 81);
  if ( (v31 & 0x20) != 0 )
  {
LABEL_52:
    v43 = *(_DWORD *)(v5 + 116);
    if ( v43 && *(_DWORD *)(v5 + 112) == v43 )
    {
      v44 = *(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212);
      v45 = 0;
      v46 = *(_QWORD *)(v44 + 88);
      if ( v46 && (v46 & 1) == 0 )
        v45 = (((v46 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
            + *(unsigned int *)(v44 + 100);
    }
    else
    {
      v45 = *(_QWORD *)(v5 + 224);
    }
    *(_WORD *)(v45 + *(unsigned __int16 *)(a1 + 74) + 12) = *(_WORD *)(a1 + 66);
    v31 = *(unsigned __int8 *)(a1 + 81);
  }
LABEL_59:
  if ( (~v31 & 3) != 0 )
  {
    if ( (v31 & 1) != 0 )
    {
      v83 = *(_BYTE *)(v5 + 128) & 0x9F | 0x20;
    }
    else
    {
      if ( (v31 & 2) == 0 )
        goto LABEL_96;
      v59 = *(unsigned __int8 *)(a1 + 79);
      if ( v59 != 17 && v59 != 6 )
        goto LABEL_96;
      v60 = *(_QWORD *)(v5 + 216);
      v61 = *(_DWORD *)(v5 + 112);
      v62 = v60 + *(unsigned __int16 *)(v5 + 182) - *(_DWORD *)(v5 + 224);
      v63 = v60 + *(unsigned __int16 *)(v5 + 184);
      if ( *(_BYTE *)(a1 + 78) == 4 )
      {
        v64 = *(_WORD *)(v63 + 2);
        v65 = bswap32(v61) >> 16;
        v66 = -2 - (v64 + *(_WORD *)(v63 + 10));
        *(_WORD *)(v63 + 2) = v65;
        v67 = v66;
        v68 = v66 + v65;
        if ( v67 >= (unsigned __int16)~v64 )
          v69 = v68;
        else
          v69 = v68 + 1;
        if ( v65 > v69 )
          ++v69;
        *(_WORD *)(v63 + 10) = ~v69;
        HIDWORD(v70) = csum_tcpudp_nofold(
                         *(unsigned int *)(v63 + 12),
                         *(unsigned int *)(v63 + 16),
                         *(_DWORD *)(v5 + 112) - (unsigned int)*(unsigned __int16 *)(a1 + 74),
                         *(unsigned __int8 *)(a1 + 79),
                         0);
        LODWORD(v70) = HIDWORD(v70);
        v71 = ~(((unsigned int)(v70 >> 16) + HIDWORD(v70)) >> 16);
      }
      else
      {
        *(_WORD *)(v63 + 4) = bswap32(v61 - 40) >> 16;
        LOWORD(v71) = csum_ipv6_magic(
                        v63 + 8,
                        v63 + 24,
                        *(_DWORD *)(v5 + 112) - (unsigned int)*(unsigned __int16 *)(a1 + 74),
                        *(unsigned __int8 *)(a1 + 79),
                        0);
      }
      if ( *(_BYTE *)(a1 + 79) == 6 )
      {
        v90 = 16;
      }
      else
      {
        v90 = 6;
        *(_WORD *)(*(_QWORD *)(v5 + 216) + *(unsigned __int16 *)(v5 + 182) + 4LL) = bswap32(
                                                                                      *(unsigned __int16 *)(v5 + 112)
                                                                                    - *(unsigned __int16 *)(a1 + 74)) >> 16;
      }
      v91 = *(_QWORD *)(v5 + 216) + *(unsigned __int16 *)(v5 + 182);
      *(_WORD *)(v91 + v90) = ~(_WORD)v71;
      HIDWORD(v92) = skb_checksum(v5, v62, *(_DWORD *)(v5 + 112) - v62, 0);
      LODWORD(v92) = HIDWORD(v92);
      v93 = 255 - (((unsigned int)(v92 >> 16) + HIDWORD(v92)) >> 16);
      if ( (unsigned __int16)(255 - (((unsigned int)(v92 >> 16) + HIDWORD(v92)) >> 16)) < 0x100u )
        LOWORD(v93) = v93 + 1;
      *(_WORD *)(v91 + v90) = v93;
      v83 = *(_BYTE *)(v5 + 128) & 0x9F;
    }
    *(_BYTE *)(v5 + 128) = v83;
    v85 = *(_DWORD *)(a1 + 52);
    if ( !v85 )
      goto LABEL_98;
    goto LABEL_97;
  }
  v47 = *(_DWORD *)(v5 + 112);
  v48 = *(_QWORD *)(v5 + 224);
  v49 = v47 - *(unsigned __int16 *)(a1 + 74);
  if ( *(_BYTE *)(a1 + 78) == 4 )
  {
    *(_WORD *)(v48 + 10) = 0;
    v50 = (unsigned int *)(v48 + 16);
    v51 = *(_BYTE *)v48 & 0xF;
    *(_WORD *)(v48 + 2) = bswap32(v47) >> 16;
    v52 = *(_QWORD *)(v48 + 8);
    v53 = v52 + __CFADD__(v52, *(_QWORD *)v48) + *(_QWORD *)v48;
    v54 = v51 - 3;
    do
    {
      v55 = *v50++;
      --v54;
      v53 += v55;
    }
    while ( v54 > 1 );
    v56 = *(unsigned int *)(v48 + 16);
    HIDWORD(v57) = (__ROR8__(v53, 32) + v53) >> 32;
    LODWORD(v57) = HIDWORD(v57);
    *(_WORD *)(v48 + 10) = ~(((unsigned int)(v57 >> 16) + HIDWORD(v57)) >> 16);
    HIDWORD(v57) = csum_tcpudp_nofold(HIDWORD(v52), v56, (unsigned __int16)v49, *(unsigned __int8 *)(a1 + 79), 0);
    LODWORD(v57) = HIDWORD(v57);
    v58 = ((unsigned int)(v57 >> 16) + HIDWORD(v57)) >> 16;
  }
  else
  {
    *(_WORD *)(v48 + 4) = bswap32(v47 - 40) >> 16;
    LOWORD(v58) = ~(unsigned __int16)csum_ipv6_magic(
                                       v48 + 8,
                                       v48 + 24,
                                       (unsigned __int16)v49,
                                       *(unsigned __int8 *)(a1 + 79),
                                       0);
  }
  v82 = (_WORD *)(v48 + *(unsigned __int16 *)(a1 + 74));
  if ( *(_BYTE *)(a1 + 79) == 6 )
  {
    v82[8] = v58;
    *(_WORD *)(v5 + 142) = 16;
    rmnet_module_hook_perf_tether_ingress();
  }
  else
  {
    v82[3] = v58;
    v82[2] = bswap32(v49) >> 16;
    *(_WORD *)(v5 + 142) = 6;
  }
  v84 = *(_DWORD *)(v5 + 216);
  *(_BYTE *)(v5 + 128) |= 0x60u;
  *(_WORD *)(v5 + 140) = v48 + *(_WORD *)(a1 + 74) - v84;
LABEL_96:
  v85 = *(_DWORD *)(a1 + 52);
  if ( v85 )
  {
LABEL_97:
    v86 = *(_DWORD *)(v5 + 129);
    *(_DWORD *)(v5 + 152) = v85;
    *(_DWORD *)(v5 + 129) = v86 | 0x400;
  }
LABEL_98:
  if ( (*(_BYTE *)(a1 + 81) & 0x10) != 0 )
    *(_BYTE *)(v5 + 40) = 1;
  if ( *(unsigned __int16 *)(a1 + 72) >= 2u )
  {
    if ( *(_BYTE *)(a1 + 79) == 6 )
    {
      if ( *(_BYTE *)(a1 + 78) == 4 )
        v87 = 1;
      else
        v87 = 16;
    }
    else
    {
      v87 = 0x20000;
    }
    v88 = *(_QWORD *)(v5 + 216) + *(unsigned int *)(v5 + 212);
    *(_DWORD *)(v88 + 24) = v87;
    *(_WORD *)(v88 + 4) = *(_WORD *)(a1 + 70);
    *(_WORD *)(v88 + 6) = *(_WORD *)(a1 + 72);
  }
  *(_DWORD *)(v5 + 144) = *(_DWORD *)(a1 + 56);
  rmnet_deliver_skb(v5, a2);
LABEL_108:
  result = rmnet_recycle_frag_descriptor((_QWORD *)a1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
