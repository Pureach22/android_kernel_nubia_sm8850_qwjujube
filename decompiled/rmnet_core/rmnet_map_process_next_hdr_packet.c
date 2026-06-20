__int64 __fastcall rmnet_map_process_next_hdr_packet(__int64 a1, __int64 *a2, unsigned __int16 a3)
{
  __int64 v3; // x19
  int v5; // w9
  _QWORD *v6; // x8
  unsigned __int64 v7; // x11
  __int64 v8; // x9
  __int64 v9; // x10
  int v10; // w9
  int v11; // w8
  __int64 v12; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x10
  int v15; // w9
  unsigned __int64 v16; // x11
  __int64 v17; // x9
  __int64 v18; // x10
  unsigned __int16 v19; // w21
  __int64 result; // x0
  unsigned __int64 v21; // x10
  _QWORD *v22; // x8
  unsigned int v23; // w11
  unsigned int v24; // w8
  unsigned int v25; // w9
  __int64 v26; // x9
  unsigned int v27; // w11
  unsigned __int8 v28; // w11
  unsigned __int8 v29; // w11
  unsigned __int8 v30; // w11
  unsigned __int8 v31; // w11
  unsigned __int8 v32; // w11
  __int64 v33; // x16
  __int64 v34; // x15
  __int64 v35; // x26
  __int64 v36; // x24
  __int64 v37; // x14
  __int64 v38; // x13
  unsigned int v39; // w12
  unsigned __int64 v40; // x9
  unsigned int v41; // w11
  __int64 v42; // x10
  int v43; // w8
  int v44; // w9
  __int64 *v45; // x8
  unsigned int v46; // w10
  int v47; // w8
  unsigned int v48; // w9
  _QWORD *v49; // x23
  unsigned __int64 v50; // x27
  __int64 v51; // x8
  __int64 v52; // x9
  __int64 v53; // x10
  unsigned __int64 v54; // x9
  __int64 v55; // x28
  __int64 v56; // x25
  __int64 v57; // x22
  __int64 v58; // x21
  unsigned int v59; // w9
  __int64 v60; // x8
  unsigned __int8 *v61; // x25
  __int64 v62; // x8
  __int64 v63; // x9
  int v64; // w28
  unsigned __int64 v65; // x9
  unsigned __int8 v66; // w8
  unsigned __int16 v67; // w22
  unsigned int v68; // w21
  bool v69; // w8
  unsigned __int8 v70; // w8
  __int64 v71; // x24
  __int64 v72; // x26
  char v73; // w27
  __int64 v74; // x12
  bool v75; // w8
  unsigned int v76; // w10
  unsigned int v77; // w10
  int v78; // w9
  int v79; // w11
  char v80; // w8
  __int16 v81; // w22
  __int16 v82; // w23
  int v83; // w10
  __int64 v84; // x8
  __int64 *v85; // x8
  __int64 v86; // x22
  unsigned int v87; // w21
  unsigned __int64 v88; // x25
  unsigned __int16 *v89; // x24
  unsigned int v90; // w26
  __int64 v91; // x0
  _BOOL8 v92; // x4
  __int64 *v93; // x2
  __int64 v94; // x3
  int v95; // w9
  __int64 v96; // x8
  int v97; // w8
  __int64 v98; // x9
  unsigned __int64 v99; // x8
  __int64 v100; // x10
  unsigned int v101; // w23
  unsigned int v102; // w22
  unsigned __int64 v103; // t2
  unsigned int v104; // w8
  __int16 v105; // w0
  unsigned __int64 v106; // t2
  __int64 v107; // x21
  __int64 v108; // x22
  __int64 v109; // x28
  __int64 v110; // x24
  __int64 v111; // x25
  __int64 v112; // [xsp+8h] [xbp-58h]
  __int64 v113; // [xsp+10h] [xbp-50h]
  __int64 v114; // [xsp+18h] [xbp-48h]
  __int64 v115; // [xsp+20h] [xbp-40h]
  unsigned __int64 v116; // [xsp+28h] [xbp-38h]
  unsigned __int8 v117[4]; // [xsp+30h] [xbp-30h] BYREF
  __int16 v118; // [xsp+34h] [xbp-2Ch] BYREF
  unsigned __int8 *v119; // [xsp+38h] [xbp-28h] BYREF
  unsigned __int8 *v120; // [xsp+40h] [xbp-20h]
  __int64 v121; // [xsp+48h] [xbp-18h]
  __int64 v122; // [xsp+50h] [xbp-10h]
  __int64 v123; // [xsp+58h] [xbp-8h]

  v3 = a1;
  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 116);
  v6 = *(_QWORD **)(a1 + 16);
  if ( v5 && *(_DWORD *)(a1 + 112) == v5 )
  {
    v7 = 0;
    v8 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v9 = *(_QWORD *)(v8 + 88);
    if ( v9 && (v9 & 1) == 0 )
      v7 = (((v9 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + *(unsigned int *)(v8 + 100);
  }
  else
  {
    v7 = *(_QWORD *)(a1 + 224);
  }
  v10 = *(unsigned __int8 *)(v7 + 4) >> 1;
  if ( v10 == 2 )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 16) + 189LL) & 1) != 0 )
    {
      v15 = *(_DWORD *)(a1 + 116);
      if ( v15 && *(_DWORD *)(a1 + 112) == v15 )
      {
        v16 = 0;
        v17 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
        v18 = *(_QWORD *)(v17 + 88);
        if ( v18 && (v18 & 1) == 0 )
          v16 = (((v18 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + *(unsigned int *)(v17 + 100);
        if ( (*(__int16 *)(v16 + 4) & 0x80000000) == 0 )
          goto LABEL_21;
      }
      else if ( (*(__int16 *)(*(_QWORD *)(a1 + 224) + 4LL) & 0x80000000) == 0 )
      {
LABEL_21:
        v19 = a3;
        ++v6[341];
        goto LABEL_29;
      }
      v19 = a3;
      ++v6[340];
      *(_BYTE *)(a1 + 128) = *(_BYTE *)(a1 + 128) & 0x9F | 0x20;
    }
    else
    {
      v19 = a3;
      ++v6[348];
    }
LABEL_29:
    v24 = *(_DWORD *)(a1 + 112);
    v25 = v24 - *(_DWORD *)(a1 + 116);
    if ( v25 <= 7 )
    {
      if ( v24 < 8 || !_pskb_pull_tail(a1, 8 - v25) )
        goto LABEL_31;
      v24 = *(_DWORD *)(v3 + 112);
    }
    v26 = *(_QWORD *)(v3 + 224);
    *(_DWORD *)(v3 + 112) = v24 - 8;
    *(_QWORD *)(v3 + 224) = v26 + 8;
LABEL_31:
    rmnet_map_move_headers(v3);
    if ( *(_DWORD *)(v3 + 112) > (unsigned int)v19 )
    {
      if ( *(_DWORD *)(v3 + 116) )
      {
        __pskb_trim(v3);
      }
      else
      {
        v43 = *(_DWORD *)(v3 + 224);
        v44 = *(_DWORD *)(v3 + 216);
        *(_DWORD *)(v3 + 112) = v19;
        *(_DWORD *)(v3 + 208) = v43 - v44 + v19;
      }
    }
    v45 = (__int64 *)a2[1];
    *(_QWORD *)v3 = a2;
    result = 0;
    *(_QWORD *)(v3 + 8) = v45;
    a2[1] = v3;
    *v45 = v3;
    ++*((_DWORD *)a2 + 4);
    goto LABEL_48;
  }
  if ( v10 != 1 )
  {
    result = 4294967274LL;
LABEL_48:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  ++v6[350];
  v11 = *(_DWORD *)(a1 + 116);
  if ( v11 && *(_DWORD *)(a1 + 112) == v11 )
  {
    v12 = *(_QWORD *)(a1 + 216) + *(unsigned int *)(a1 + 212);
    v13 = 0;
    v14 = *(_QWORD *)(v12 + 88);
    if ( v14 && (v14 & 1) == 0 )
      v13 = (((v14 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
          + *(unsigned int *)(v12 + 100);
  }
  else
  {
    v13 = *(_QWORD *)(a1 + 224);
  }
  v21 = *(unsigned int *)(v13 + 4);
  v22 = *(_QWORD **)(a1 + 16);
  v23 = ((unsigned int)v21 >> 12) & 7;
  if ( !v23 || v23 == 7 )
  {
    result = 4294967274LL;
    ++v22[352];
    goto LABEL_48;
  }
  v27 = *(unsigned __int8 *)(v13 + 11);
  if ( v27 >= 0x31
    || (v28 = *(_BYTE *)(v13 + 15) + v27, v28 > 0x30u)
    || (v29 = *(_BYTE *)(v13 + 19) + v28, v29 > 0x30u)
    || (v30 = *(_BYTE *)(v13 + 23) + v29, v30 > 0x30u)
    || (v31 = *(_BYTE *)(v13 + 27) + v30, v31 > 0x30u)
    || (v32 = *(_BYTE *)(v13 + 31) + v31, v32 > 0x30u) )
  {
    result = 4294967274LL;
    ++v22[353];
    goto LABEL_48;
  }
  v33 = *(unsigned __int8 *)(v13 + 26);
  v34 = *(unsigned __int8 *)(v13 + 22);
  v35 = *(unsigned __int8 *)(v13 + 18);
  v36 = *(unsigned __int8 *)(v13 + 14);
  v37 = *(unsigned __int8 *)(v13 + 10);
  v38 = *(unsigned __int8 *)(v13 + 30);
  v22[351] += v32;
  v39 = *(_DWORD *)(v13 + 4);
  v40 = v21 >> 28;
  v41 = HIWORD(v39) & 0xF;
  if ( v41 <= 1 )
  {
    if ( v41 )
      v42 = 184;
    else
      v42 = 176;
  }
  else
  {
    switch ( v41 )
    {
      case 2u:
        v42 = 192;
        break;
      case 3u:
        v46 = (v39 >> 20) & 0xF;
        if ( v46 >= 5 )
          goto LABEL_56;
        v42 = 8 * v46 + 200LL;
        break;
      case 4u:
        v42 = 240;
        break;
      default:
        goto LABEL_56;
    }
  }
  ++*(_QWORD *)((char *)v22 + v42 + 2688);
LABEL_56:
  v119 = nullptr;
  v120 = nullptr;
  v121 = 0;
  v122 = 0;
  ++v22[v40 + 367];
  v48 = *(_DWORD *)(a1 + 112);
  v47 = *(_DWORD *)(a1 + 116);
  v49 = *(_QWORD **)(a1 + 16);
  v50 = v49[23];
  if ( v48 - v47 > 3 )
  {
LABEL_57:
    v51 = *(_QWORD *)(v3 + 224);
    *(_DWORD *)(v3 + 112) = v48 - 4;
    *(_QWORD *)(v3 + 224) = v51 + 4;
    goto LABEL_58;
  }
  v55 = v33;
  v56 = v34;
  v57 = v37;
  v58 = v38;
  if ( v48 < 4 )
  {
    if ( !v47 )
      goto LABEL_71;
    goto LABEL_59;
  }
  a1 = _pskb_pull_tail(a1, 4 - (v48 - v47));
  v38 = v58;
  v37 = v57;
  v34 = v56;
  v33 = v55;
  if ( a1 )
  {
    v48 = *(_DWORD *)(v3 + 112);
    goto LABEL_57;
  }
LABEL_58:
  v47 = *(_DWORD *)(v3 + 116);
  if ( !v47 )
  {
LABEL_71:
    v54 = *(_QWORD *)(v3 + 224);
    goto LABEL_72;
  }
LABEL_59:
  if ( *(_DWORD *)(v3 + 112) != v47 )
    goto LABEL_71;
  v116 = 0;
  v52 = *(_QWORD *)(v3 + 216) + *(unsigned int *)(v3 + 212);
  v53 = *(_QWORD *)(v52 + 88);
  if ( v53 && (v53 & 1) == 0 )
  {
    v47 = *(_DWORD *)(v3 + 116);
    v54 = (((v53 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL) + *(unsigned int *)(v52 + 100);
LABEL_72:
    v116 = v54;
  }
  v59 = *(_DWORD *)(v3 + 112);
  if ( v59 - v47 > 0x1B )
  {
LABEL_74:
    v60 = *(_QWORD *)(v3 + 224);
    *(_DWORD *)(v3 + 112) = v59 - 28;
    *(_QWORD *)(v3 + 224) = v60 + 28;
    goto LABEL_75;
  }
  if ( v59 < 0x1C )
    goto LABEL_76;
  v107 = v38;
  v108 = v37;
  v109 = v36;
  v110 = v34;
  v111 = v33;
  a1 = _pskb_pull_tail(v3, 28 - (v59 - v47));
  v33 = v111;
  v34 = v110;
  v36 = v109;
  v37 = v108;
  v38 = v107;
  if ( a1 )
  {
    v59 = *(_DWORD *)(v3 + 112);
    goto LABEL_74;
  }
LABEL_75:
  v47 = *(_DWORD *)(v3 + 116);
LABEL_76:
  if ( v47 && *(_DWORD *)(v3 + 112) == v47 )
  {
    v61 = nullptr;
    v62 = *(_QWORD *)(v3 + 216) + *(unsigned int *)(v3 + 212);
    v63 = *(_QWORD *)(v62 + 88);
    if ( v63 && (v63 & 1) == 0 )
      v61 = (unsigned __int8 *)((((v63 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                              + *(unsigned int *)(v62 + 100));
  }
  else
  {
    v61 = *(unsigned __int8 **)(v3 + 224);
  }
  v64 = *v61 >> 4;
  if ( v64 != 6 )
  {
    if ( v64 == 4 )
    {
      v65 = v50 >> 55;
      LOBYTE(v122) = 4;
      v66 = *v61;
      v119 = v61;
      v67 = 4 * (v66 & 0xF);
      LOWORD(v121) = v67;
      v68 = v61[9];
      BYTE1(v122) = v61[9];
      v69 = (*v61 & 0xF) == 5;
      goto LABEL_88;
    }
LABEL_86:
    ++v49[356];
    goto LABEL_133;
  }
  v70 = v61[6];
  v112 = v36;
  v113 = v33;
  v71 = v35;
  v72 = v38;
  v114 = v34;
  v115 = v37;
  v118 = 0;
  v117[0] = v70;
  LOBYTE(v122) = 6;
  a1 = ipv6_skip_exthdr(v3, 40, v117, &v118);
  v68 = v117[0];
  LOWORD(v121) = a1;
  v119 = v61;
  BYTE1(v122) = v117[0];
  if ( v118 )
    goto LABEL_86;
  v65 = v50 >> 55;
  v38 = v72;
  v35 = v71;
  v67 = a1;
  v34 = v114;
  v37 = v115;
  v69 = (unsigned __int16)a1 < 0x29u;
  v36 = v112;
  v33 = v113;
LABEL_88:
  v73 = v69 & v65;
  if ( v68 != 17 )
  {
    if ( v68 == 6 )
    {
      v74 = v36;
      v75 = 0;
      v76 = *(unsigned __int16 *)&v61[v67 + 12];
      v120 = &v61[v67];
      LODWORD(v36) = (v76 >> 2) & 0x3C;
      WORD1(v121) = (v76 >> 2) & 0x3C;
      goto LABEL_95;
    }
    ++v49[357];
LABEL_133:
    v96 = *a2;
    if ( (__int64 *)*a2 == a2 )
      v96 = 0;
    if ( v96 != v3 )
      consume_skb(v3);
    result = 0;
    goto LABEL_48;
  }
  v74 = v36;
  LOWORD(v36) = 8;
  WORD1(v121) = 8;
  v120 = &v61[v67];
  v75 = v64 == 4 && *(_WORD *)&v61[v67 + 6] == 0;
LABEL_95:
  v77 = *(_DWORD *)v116;
  v78 = *(_DWORD *)v116 & 0x7000;
  if ( v78 == 4096 && *(_BYTE *)(v116 + 7) == 1 )
  {
    v79 = HIWORD(v77) & 0xF;
    if ( v79 == 4 )
      goto LABEL_101;
    if ( v79 == 3 )
    {
      if ( ((v77 >> 20) & 0xF) - 4 < 0xFFFFFFFD )
        v75 = 1;
LABEL_101:
      if ( !v75 )
      {
        rmnet_map_move_headers(v3);
        v97 = *(_DWORD *)(v3 + 116);
        if ( v97 && *(_DWORD *)(v3 + 112) == v97 )
        {
          v98 = *(_QWORD *)(v3 + 216) + *(unsigned int *)(v3 + 212);
          v99 = 0;
          v100 = *(_QWORD *)(v98 + 88);
          if ( v100 && (v100 & 1) == 0 )
            v99 = (((v100 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                + *(unsigned int *)(v98 + 100);
        }
        else
        {
          v99 = *(_QWORD *)(v3 + 224);
        }
        v101 = v67;
        v102 = *(_DWORD *)(v3 + 112) - v67;
        if ( v64 == 4 )
        {
          HIDWORD(v103) = csum_tcpudp_nofold(*(unsigned int *)(v99 + 12), *(unsigned int *)(v99 + 16), v102, v68, 0);
          LODWORD(v103) = HIDWORD(v103);
          v104 = ((unsigned int)(v103 >> 16) + HIDWORD(v103)) >> 16;
        }
        else
        {
          v105 = csum_ipv6_magic(v99 + 8, v99 + 24, v102, v68, 0);
          v101 = (unsigned __int16)v121;
          LOWORD(v104) = ~v105;
        }
        HIDWORD(v106) = skb_checksum(v3, v101, v102, (unsigned __int16)v104);
        LODWORD(v106) = HIDWORD(v106);
        if ( (unsigned int)(v106 >> 16) + HIDWORD(v106) >= 0xFFFF0000 )
          *(_BYTE *)(v3 + 128) = *(_BYTE *)(v3 + 128) & 0x9F | 0x20;
        goto LABEL_113;
      }
    }
  }
  if ( (*(_DWORD *)v116 & 0xF000) == 0x9000 )
    v80 = v73;
  else
    v80 = 0;
  if ( (v80 & 1) != 0 )
  {
    rmnet_map_move_headers(v3);
    *(_BYTE *)(v3 + 128) = *(_BYTE *)(v3 + 128) & 0x9F | 0x20;
    v81 = (bswap32(*(unsigned __int16 *)(v116 + 4)) >> 16) - (v36 + v67);
    HIWORD(v121) = v81;
    BYTE3(v122) = *(_BYTE *)(v116 + 7);
    v82 = BYTE3(v122);
    if ( BYTE3(v122) > 1u )
    {
      rmnet_map_partial_csum(v3, &v119);
      if ( v64 == 4 )
        v83 = 1;
      else
        v83 = 16;
      v84 = *(_QWORD *)(v3 + 216) + *(unsigned int *)(v3 + 212);
      if ( v68 != 6 )
        v83 = 0x20000;
      *(_WORD *)(v84 + 4) = v81;
      *(_DWORD *)(v84 + 24) = v83;
      *(_WORD *)(v84 + 6) = v82;
    }
LABEL_113:
    v85 = (__int64 *)a2[1];
    *(_QWORD *)v3 = a2;
    *(_QWORD *)(v3 + 8) = v85;
    a2[1] = v3;
    *v85 = v3;
    ++*((_DWORD *)a2 + 4);
    goto LABEL_133;
  }
  if ( !v78 )
    goto LABEL_133;
  v86 = 0;
  v87 = 0;
  v88 = (v33 << 32) | (v34 << 24) | (v35 << 16) | v37 | (v74 << 8) | (v38 << 40);
  while ( v86 != 6 )
  {
    v89 = (unsigned __int16 *)(v116 + 4 + 4 * v86);
    HIWORD(v121) = (bswap32(*v89) >> 16) - (v121 + WORD1(v121));
    if ( *((_BYTE *)v89 + 3) )
    {
      v90 = 0;
      do
      {
        if ( (v73 & 1) != 0 )
        {
          if ( (v88 & 1) == 0 )
          {
            ++BYTE3(v122);
            goto LABEL_122;
          }
          v95 = BYTE3(v122);
          ++v49[354];
          if ( v95 )
            _rmnet_map_segment_coal_skb(v3, &v119, a2, v87, 1);
          v91 = v3;
          v93 = a2;
          v94 = v87;
          v92 = 0;
          BYTE3(v122) = 1;
        }
        else
        {
          BYTE3(v122) = 1;
          if ( (v88 & 1) != 0 )
            ++v49[354];
          v91 = v3;
          v92 = (v88 & 1) == 0;
          v93 = a2;
          v94 = v87;
        }
        a1 = _rmnet_map_segment_coal_skb(v91, &v119, v93, v94, v92);
LABEL_122:
        ++v90;
        v88 >>= 1;
        ++v87;
      }
      while ( v90 < *((unsigned __int8 *)v89 + 3) );
    }
    if ( BYTE3(v122) )
      a1 = _rmnet_map_segment_coal_skb(v3, &v119, a2, v87, 1);
    if ( ((*(_DWORD *)v116 >> 12) & 7u) <= (unsigned int)++v86 )
      goto LABEL_133;
  }
  __break(0x5512u);
  return rmnet_map_move_headers(a1);
}
