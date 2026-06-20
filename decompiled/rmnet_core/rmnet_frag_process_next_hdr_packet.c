__int64 __fastcall rmnet_frag_process_next_hdr_packet(__int64 a1, __int64 a2, _QWORD *a3, unsigned __int16 a4)
{
  __int64 v8; // x27
  __int16 *v9; // x0
  int v10; // w8
  __int64 v11; // x8
  __int64 v12; // x22
  unsigned int *v13; // x0
  unsigned __int64 v14; // x8
  __int64 v15; // x9
  unsigned int v16; // w10
  unsigned int v17; // w9
  unsigned __int8 v18; // w9
  unsigned __int8 v19; // w9
  unsigned __int8 v20; // w9
  unsigned __int8 v21; // w9
  unsigned __int8 v22; // w9
  unsigned __int64 v23; // x23
  __int64 v24; // x10
  unsigned int v25; // w9
  __int64 v26; // x1
  __int64 v27; // x8
  __int16 *v28; // x23
  __int64 v29; // x28
  char *v30; // x0
  char v31; // w8
  int v32; // w9
  unsigned __int64 v33; // x0
  unsigned int v34; // w9
  unsigned __int64 v35; // x0
  unsigned __int64 v36; // x24
  unsigned int v37; // w26
  unsigned int v38; // w23
  unsigned int v39; // w25
  unsigned int v40; // w23
  __int64 v41; // x2
  char v42; // w8
  int v43; // w8
  unsigned __int8 *v44; // x0
  unsigned __int8 *v45; // x26
  unsigned __int16 *v46; // x0
  unsigned int *v47; // x11
  __int16 v48; // w10
  __int64 v49; // x8
  int v50; // w12
  unsigned int v51; // t1
  unsigned __int64 v52; // t2
  __int64 v53; // x3
  unsigned __int64 v54; // t2
  int v55; // w8
  unsigned int v56; // w25
  unsigned int v57; // w24
  unsigned __int64 v58; // x0
  __int64 v59; // x10
  __int64 *v60; // x24
  unsigned int v61; // w8
  __int64 v62; // x9
  unsigned __int64 v63; // x10
  unsigned int v64; // w8
  unsigned int v65; // w26
  unsigned int v66; // w0
  unsigned __int64 v67; // t2
  _BOOL4 v68; // w8
  __int64 v69; // x9
  _QWORD *v70; // x8
  __int64 v71; // x9
  __int64 *v72; // x1
  __int64 result; // x0
  unsigned int v74; // w9
  __int64 v75; // x8
  __int64 *v76; // x23
  __int64 *v77; // x25
  unsigned __int64 v78; // x8
  unsigned int v79; // w27
  unsigned int v80; // w8
  unsigned int v81; // w26
  unsigned int v82; // w10
  unsigned int v83; // w10
  size_t v84; // x22
  unsigned __int64 v85; // x1
  __int64 v86; // x10
  unsigned __int64 v87; // x11
  _QWORD *v88; // x8
  __int64 v89; // x9
  unsigned __int64 v90; // x27
  _BYTE *v91; // x8
  int v92; // w8
  _BYTE *v93; // x0
  unsigned int v94; // w22
  int v95; // w24
  int v96; // w23
  unsigned __int64 v97; // x0
  int v98; // w23
  int v99; // w28
  unsigned int v100; // w26
  char v101; // w8
  int v102; // w8
  unsigned __int64 v103; // x0
  unsigned __int8 *v104; // x25
  unsigned __int16 *v105; // x0
  unsigned __int64 v106; // x0
  __int64 v107; // x9
  __int64 v108; // x0
  __int64 v109; // x8
  __int64 v110; // x2
  __int64 v111; // x1
  __int64 v112; // x3
  unsigned __int64 v113; // x0
  __int64 v114; // x9
  bool v115; // w22
  _QWORD *v116; // x8
  char v117; // w11
  int v118; // w10
  __int64 v119; // x12
  char v120; // w13
  __int64 *v121; // x1
  int v122; // w9
  __int16 v123; // w11
  unsigned int v124; // w8
  _QWORD *v125; // x8
  __int64 v126; // x10
  unsigned __int64 v127; // x23
  unsigned int v128; // w22
  unsigned __int64 v129; // t2
  unsigned int v130; // w8
  __int64 v131; // x24
  unsigned int v132; // w22
  unsigned __int16 *v133; // x28
  unsigned int v134; // w25
  __int64 v135; // x0
  __int64 v136; // x1
  _BOOL8 v137; // x4
  _QWORD *v138; // x2
  __int64 v139; // x3
  __int64 v140; // x0
  __int64 v141; // x0
  unsigned __int64 v142; // t2
  unsigned int v143; // w8
  _QWORD *v144; // [xsp+8h] [xbp-C8h]
  unsigned __int64 v145; // [xsp+10h] [xbp-C0h]
  __int64 v146; // [xsp+18h] [xbp-B8h]
  __int64 v147; // [xsp+20h] [xbp-B0h]
  __int64 v148; // [xsp+28h] [xbp-A8h]
  __int64 v149; // [xsp+30h] [xbp-A0h]
  __int64 v150; // [xsp+38h] [xbp-98h]
  __int64 v151; // [xsp+40h] [xbp-90h]
  __int64 v152; // [xsp+48h] [xbp-88h]
  int v153; // [xsp+54h] [xbp-7Ch] BYREF
  _WORD v154[2]; // [xsp+58h] [xbp-78h] BYREF
  _WORD v155[2]; // [xsp+5Ch] [xbp-74h] BYREF
  _QWORD v156[3]; // [xsp+60h] [xbp-70h] BYREF
  int v157; // [xsp+78h] [xbp-58h]
  __int64 v158; // [xsp+80h] [xbp-50h] BYREF
  __int64 v159; // [xsp+88h] [xbp-48h]
  __int64 v160; // [xsp+90h] [xbp-40h]
  __int64 v161; // [xsp+98h] [xbp-38h]
  __int64 v162; // [xsp+A0h] [xbp-30h]
  __int64 v163; // [xsp+A8h] [xbp-28h]
  __int64 v164; // [xsp+B0h] [xbp-20h]
  int v165; // [xsp+B8h] [xbp-18h]
  __int64 v166; // [xsp+C0h] [xbp-10h]

  v166 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 32);
  v153 = 0;
  v9 = (__int16 *)rmnet_frag_header_ptr(a1, 4u, 4u, (__int64)&v153);
  if ( !v9 )
    goto LABEL_86;
  v10 = (unsigned __int8)*v9 >> 1;
  if ( v10 == 2 )
  {
    v28 = v9;
    rmnet_module_hook_perf_non_coal_stat(*(unsigned __int8 *)(v8 + 2688), a4);
    v29 = *(_QWORD *)(a1 + 32);
    if ( (*(_BYTE *)(v29 + 189) & 1) == 0 )
    {
      ++*(_QWORD *)(v8 + 2784);
      goto LABEL_77;
    }
    if ( *v28 < 0 )
      goto LABEL_28;
    LOBYTE(v154[0]) = 0;
    v30 = (char *)rmnet_frag_header_ptr(a1, 8u, 1u, (__int64)v154);
    if ( !v30 )
      goto LABEL_76;
    v31 = *v30;
    v32 = *v30 & 0xF0;
    if ( v32 != 96 )
    {
      if ( v32 != 64 )
        goto LABEL_76;
      v165 = 0;
      v163 = 0;
      v164 = 0;
      v161 = 0;
      v162 = 0;
      v159 = 0;
      v160 = 0;
      v158 = 0;
      *(_WORD *)(a1 + 74) = 4 * (v31 & 0xF);
      v33 = rmnet_frag_header_ptr(a1, 8u, 4 * (v31 & 0xFu), (__int64)&v158);
      if ( !v33 )
        goto LABEL_76;
      if ( (*(_WORD *)(v33 + 6) & 0xFF3F) != 0 )
        goto LABEL_76;
      v34 = bswap32(*(unsigned __int16 *)(v33 + 2)) >> 16;
      if ( *(_DWORD *)(a1 + 48) - 8 < v34 )
        goto LABEL_76;
      v47 = (unsigned int *)(v33 + 16);
      v48 = *(_WORD *)(a1 + 74);
      v49 = *(_QWORD *)(v33 + 8) + __CFADD__(*(_QWORD *)(v33 + 8), *(_QWORD *)v33) + *(_QWORD *)v33;
      v50 = (*(_BYTE *)v33 & 0xF) - 3;
      do
      {
        v51 = *v47++;
        --v50;
        v49 += v51;
      }
      while ( v50 > 1 );
      HIDWORD(v52) = (unsigned __int64)(__ROR8__(v49, 32) + v49) >> 32;
      LODWORD(v52) = HIDWORD(v52);
      if ( (unsigned int)(v52 >> 16) + HIDWORD(v52) <= 0xFFFEFFFF )
      {
        v68 = 0;
        v69 = *(_QWORD *)(v29 + 2784) + 1LL;
        goto LABEL_74;
      }
      LOWORD(v40) = v34 - v48;
      *(_BYTE *)(a1 + 78) = 4;
      v53 = *(unsigned __int8 *)(v33 + 9);
      *(_BYTE *)(a1 + 79) = v53;
      HIDWORD(v54) = csum_tcpudp_nofold(
                       *(unsigned int *)(v33 + 12),
                       *(unsigned int *)(v33 + 16),
                       (unsigned __int16)(v34 - v48),
                       v53,
                       0);
      LODWORD(v54) = HIDWORD(v54);
      v41 = (((unsigned int)(v54 >> 16) + HIDWORD(v54)) >> 16) | 0xFFFF0000;
LABEL_52:
      v55 = *(unsigned __int8 *)(a1 + 79);
      if ( v55 == 17 || v55 == 6 )
      {
        v56 = *(unsigned __int16 *)(a1 + 74) + 8;
        if ( v55 != 17 )
          goto LABEL_58;
        v57 = v41;
        v158 = 0;
        v58 = rmnet_frag_header_ptr(a1, v56, 8u, (__int64)&v158);
        if ( v58 )
        {
          if ( *(_WORD *)(v58 + 6) )
          {
            v41 = v57;
LABEL_58:
            v59 = a1 + 16;
            v60 = *(__int64 **)(a1 + 16);
            if ( v60 != (__int64 *)(a1 + 16) )
            {
              do
              {
                if ( !(_WORD)v40 )
                  break;
                v61 = *((_DWORD *)v60 + 6);
                if ( v56 >= v61 )
                {
                  v56 -= v61;
                }
                else
                {
                  v62 = v60[2];
                  v63 = 0;
                  if ( v62 && (v62 & 1) == 0 )
                    v63 = (((v62 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                        + *((unsigned int *)v60 + 7);
                  v64 = v61 - v56;
                  v65 = v64 >= (unsigned __int16)v40 ? (unsigned __int16)v40 : v64;
                  v66 = csum_partial(v63 + (int)v56, v65, v41);
                  v59 = a1 + 16;
                  v41 = v66;
                  v56 = 0;
                  LOWORD(v40) = v40 - v65;
                }
                v60 = (__int64 *)*v60;
              }
              while ( v60 != (__int64 *)v59 );
            }
            HIDWORD(v67) = v41;
            LODWORD(v67) = v41;
            ++*(_QWORD *)(v29 + 2784);
            if ( (unsigned int)(v67 >> 16) + (unsigned int)v41 <= 0xFFFEFFFF )
              goto LABEL_72;
            goto LABEL_28;
          }
          v69 = *(_QWORD *)(v29 + 2784) + 1LL;
          v68 = *(unsigned __int8 *)(a1 + 78) == 4;
LABEL_74:
          *(_QWORD *)(v29 + 2784) = v69;
          if ( !v68 )
          {
LABEL_72:
            ++*(_QWORD *)(v8 + 2728);
            goto LABEL_77;
          }
LABEL_28:
          ++*(_QWORD *)(v8 + 2720);
          *(_BYTE *)(a1 + 81) |= 1u;
LABEL_77:
          if ( rmnet_frag_pull(a1, a2, 8u) && rmnet_frag_trim(a1, a2, a4) )
          {
            v70 = *(_QWORD **)(a1 + 8);
            if ( *v70 == a1 && (v71 = *(_QWORD *)a1, *(_QWORD *)(*(_QWORD *)a1 + 8LL) == a1) )
            {
              *(_QWORD *)(v71 + 8) = v70;
              *v70 = v71;
            }
            else
            {
              _list_del_entry_valid_or_report(a1);
            }
            *(_QWORD *)a1 = a1;
            *(_QWORD *)(a1 + 8) = a1;
            v72 = (__int64 *)a3[1];
            if ( (_QWORD *)a1 == a3 || v72 == (__int64 *)a1 || (_QWORD *)*v72 != a3 )
            {
LABEL_210:
              _list_add_valid_or_report(a1, v72, a3);
              result = 0;
            }
            else
            {
              result = 0;
              a3[1] = a1;
              *(_QWORD *)a1 = a3;
              *(_QWORD *)(a1 + 8) = v72;
              *v72 = a1;
            }
            goto LABEL_87;
          }
LABEL_86:
          result = 4294967274LL;
          goto LABEL_87;
        }
      }
LABEL_76:
      ++*(_QWORD *)(v8 + 2736);
      goto LABEL_77;
    }
    v161 = 0;
    v162 = 0;
    v159 = 0;
    v160 = 0;
    v158 = 0;
    v35 = rmnet_frag_header_ptr(a1, 8u, 0x28u, (__int64)&v158);
    if ( !v35 )
      goto LABEL_76;
    v36 = v35;
    *(_BYTE *)(a1 + 78) = 6;
    v37 = *(unsigned __int8 *)(v35 + 6);
    LOWORD(v38) = 0;
    v39 = 48;
    if ( (ipv6_ext_hdr(*(unsigned __int8 *)(v35 + 6)) & 1) == 0 )
    {
LABEL_33:
      if ( (v39 & 0x80000000) != 0 )
        goto LABEL_76;
LABEL_34:
      if ( (_WORD)v38 )
        goto LABEL_76;
      *(_WORD *)(a1 + 74) = v39;
      v40 = bswap32(*(unsigned __int16 *)(v36 + 4)) >> 16;
      if ( v40 + (unsigned __int16)v39 > *(_DWORD *)(a1 + 48) - 8 )
        goto LABEL_76;
      *(_BYTE *)(a1 + 79) = v37;
      v41 = ~(unsigned int)csum_ipv6_magic(v36 + 8, v36 + 24, v40, v37, 0) | 0xFFFF0000;
      goto LABEL_52;
    }
    while ( 1 )
    {
      LOWORD(v156[0]) = 0;
      if ( (unsigned __int8)v37 == 59 )
        goto LABEL_76;
      v44 = (unsigned __int8 *)rmnet_frag_header_ptr(a1, v39, 2u, (__int64)v156);
      if ( !v44 )
        goto LABEL_76;
      if ( (unsigned __int8)v37 == 51 )
        break;
      if ( (unsigned __int8)v37 != 44 )
      {
        v42 = 3;
        goto LABEL_38;
      }
      v45 = v44;
      v155[0] = 0;
      v46 = (unsigned __int16 *)rmnet_frag_header_ptr(a1, v39 + 2, 2u, (__int64)v155);
      if ( !v46 )
        goto LABEL_76;
      v38 = *v46;
      if ( __rev16(v38) >= 8 )
      {
        v37 = 44;
        if ( (v39 & 0x80000000) == 0 )
          goto LABEL_34;
        goto LABEL_76;
      }
      v44 = v45;
      v43 = 8;
LABEL_39:
      v37 = *v44;
      v39 += v43;
      if ( (ipv6_ext_hdr(*v44) & 1) == 0 )
        goto LABEL_33;
    }
    v42 = 2;
LABEL_38:
    v43 = (v44[1] << v42) + 8;
    goto LABEL_39;
  }
  if ( v10 != 1 )
    goto LABEL_86;
  v11 = *(_QWORD *)(v8 + 2800);
  LODWORD(v161) = 0;
  v159 = 0;
  v160 = 0;
  *(_QWORD *)(v8 + 2800) = v11 + 1;
  v12 = *(_QWORD *)(a1 + 32);
  v158 = 0;
  v13 = (unsigned int *)rmnet_frag_header_ptr(a1, 4u, 0x1Cu, (__int64)&v158);
  if ( !v13 )
    goto LABEL_86;
  v14 = *v13;
  v15 = 2816;
  v16 = ((unsigned int)v14 >> 12) & 7;
  if ( !v16 || v16 == 7 )
    goto LABEL_30;
  v17 = *((unsigned __int8 *)v13 + 7);
  if ( v17 > 0x30
    || (v18 = *((_BYTE *)v13 + 11) + v17, v18 > 0x30u)
    || (v19 = *((_BYTE *)v13 + 15) + v18, v19 > 0x30u)
    || (v20 = *((_BYTE *)v13 + 19) + v19, v20 > 0x30u)
    || (v21 = *((_BYTE *)v13 + 23) + v20, v21 > 0x30u)
    || (v22 = *((_BYTE *)v13 + 27) + v21, v22 > 0x30u) )
  {
    v15 = 2824;
LABEL_30:
    ++*(_QWORD *)(v12 + v15);
    goto LABEL_86;
  }
  v23 = v14 >> 28;
  v147 = *((unsigned __int8 *)v13 + 22);
  v148 = *((unsigned __int8 *)v13 + 18);
  v150 = *((unsigned __int8 *)v13 + 14);
  v151 = *((unsigned __int8 *)v13 + 10);
  v149 = *((unsigned __int8 *)v13 + 6);
  v24 = *((unsigned __int8 *)v13 + 26);
  *(_QWORD *)(v12 + 2808) += v22;
  v152 = v24;
  v25 = HIWORD(*v13) & 0xF;
  if ( v25 <= 1 )
  {
    if ( v25 )
    {
      v26 = 3;
      v27 = 184;
    }
    else
    {
      v26 = 2;
      v27 = 176;
    }
    goto LABEL_96;
  }
  switch ( v25 )
  {
    case 2u:
      v26 = 4;
      v27 = 192;
      goto LABEL_96;
    case 3u:
      v74 = (*v13 >> 20) & 0xF;
      if ( v74 < 5 )
      {
        v26 = v74 + 5;
        v27 = 8 * v74 + 200LL;
        goto LABEL_96;
      }
      break;
    case 4u:
      v26 = 10;
      v27 = 240;
LABEL_96:
      ++*(_QWORD *)(v12 + 2688 + v27);
      rmnet_module_hook_perf_coal_common_stat(*(unsigned __int8 *)(v12 + 2688), v26);
      break;
  }
  ++*(_QWORD *)(v12 + 8 * v23 + 2936);
  if ( *(_DWORD *)(a1 + 48) < 0x20u )
    goto LABEL_154;
  v75 = *(_QWORD *)(a1 + 32);
  v157 = 0;
  v76 = (__int64 *)(a1 + 16);
  v77 = *(__int64 **)(a1 + 16);
  v146 = v75;
  v78 = *(_QWORD *)(v75 + 184);
  memset(v156, 0, sizeof(v156));
  v145 = v78;
  if ( v77 != (__int64 *)(a1 + 16) )
  {
    v79 = 0;
    v80 = 4;
    v81 = 28;
    do
    {
      v82 = *((_DWORD *)v77 + 6);
      if ( v80 >= v82 )
      {
        v80 -= v82;
      }
      else
      {
        v83 = v82 - v80;
        if ( v81 >= v83 )
          v84 = v83;
        else
          v84 = v81;
        if ( v79 <= 0x1C )
          v85 = 28LL - v79;
        else
          v85 = 0;
        if ( v85 < v84 )
        {
          _fortify_panic(17);
          goto LABEL_210;
        }
        v86 = v77[2];
        v87 = 0;
        if ( v86 && (v86 & 1) == 0 )
          v87 = (((v86 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + *((unsigned int *)v77 + 7);
        memcpy((char *)v156 + v79, (const void *)(v87 + v80), v84);
        v80 = 0;
        v79 += v84;
        v81 -= v84;
      }
      v77 = (__int64 *)*v77;
    }
    while ( v77 != v76 && v81 );
  }
  if ( !rmnet_frag_pull(a1, a2, 0x20u) )
    goto LABEL_154;
  v88 = (_QWORD *)*v76;
  if ( (__int64 *)*v76 == v76 )
    goto LABEL_154;
  if ( !v88 )
    goto LABEL_154;
  v89 = v88[2];
  if ( !v89 )
    goto LABEL_154;
  if ( (v89 & 1) != 0 )
    goto LABEL_154;
  v144 = (_QWORD *)(a1 + 16);
  v90 = (v147 << 32) | (v148 << 24) | (v150 << 16) | v149 | (v151 << 8) | (v152 << 40);
  v91 = (_BYTE *)((((v89 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                + *((unsigned int *)v88 + 7));
  if ( !v91 )
    goto LABEL_154;
  v92 = *v91 & 0xF0;
  if ( v92 != 96 )
  {
    if ( v92 != 64 )
      goto LABEL_153;
    LODWORD(v160) = 0;
    v158 = 0;
    v159 = 0;
    v93 = (_BYTE *)rmnet_frag_header_ptr(a1, 0, 0x14u, (__int64)&v158);
    if ( v93 )
    {
      *(_BYTE *)(a1 + 78) = 4;
      LOWORD(v94) = 4 * (*v93 & 0xF);
      *(_WORD *)(a1 + 74) = v94;
      v95 = (unsigned __int8)v93[9];
      *(_BYTE *)(a1 + 79) = v95;
      v96 = ((*v93 & 0xF) == 5) & (v145 >> 55);
      goto LABEL_144;
    }
    goto LABEL_154;
  }
  v161 = 0;
  v162 = 0;
  v159 = 0;
  v160 = 0;
  v158 = 0;
  v97 = rmnet_frag_header_ptr(a1, 0, 0x28u, (__int64)&v158);
  if ( !v97 )
    goto LABEL_154;
  *(_BYTE *)(a1 + 78) = 6;
  v98 = *(unsigned __int8 *)(v97 + 6);
  if ( (ipv6_ext_hdr(*(unsigned __int8 *)(v97 + 6)) & 1) == 0 )
  {
    LOWORD(v100) = 0;
    v99 = 0;
    v94 = 40;
    v95 = v98;
LABEL_141:
    *(_BYTE *)(a1 + 79) = v95;
    if ( (v94 & 0x80000000) == 0 )
      goto LABEL_142;
LABEL_153:
    ++*(_QWORD *)(v146 + 2848);
    goto LABEL_154;
  }
  v99 = 0;
  LOWORD(v100) = 0;
  v94 = 40;
  LOBYTE(v95) = v98;
  while ( 1 )
  {
    v155[0] = 0;
    if ( (unsigned __int8)v95 == 59 || (v103 = rmnet_frag_header_ptr(a1, v94, 2u, (__int64)v155)) == 0 )
    {
LABEL_152:
      *(_BYTE *)(a1 + 79) = v98;
      goto LABEL_153;
    }
    v104 = (unsigned __int8 *)v103;
    if ( (unsigned __int8)v95 != 51 )
      break;
    v101 = 2;
LABEL_130:
    v102 = (*(unsigned __int8 *)(v103 + 1) << v101) + 8;
LABEL_131:
    v95 = *v104;
    v94 += v102;
    if ( (ipv6_ext_hdr(*v104) & 1) == 0 )
      goto LABEL_141;
  }
  if ( (unsigned __int8)v95 != 44 )
  {
    v101 = 3;
    goto LABEL_130;
  }
  v154[0] = 0;
  v105 = (unsigned __int16 *)rmnet_frag_header_ptr(a1, v94 + 2, 2u, (__int64)v154);
  if ( !v105 )
    goto LABEL_152;
  v100 = *v105;
  if ( __rev16(v100) < 8 )
  {
    v102 = 8;
    v99 = 1;
    goto LABEL_131;
  }
  v95 = 44;
  v99 = 1;
  *(_BYTE *)(a1 + 79) = 44;
  if ( (v94 & 0x80000000) != 0 )
    goto LABEL_153;
LABEL_142:
  if ( (_WORD)v100 )
    goto LABEL_153;
  *(_WORD *)(a1 + 74) = v94;
  v96 = ((unsigned __int16)v94 < 0x29u) & (v99 ^ 1) & (v145 >> 55);
LABEL_144:
  if ( v95 != 17 )
  {
    if ( v95 == 6 )
    {
      LODWORD(v160) = 0;
      v158 = 0;
      v159 = 0;
      v106 = rmnet_frag_header_ptr(a1, (unsigned __int16)v94, 0x14u, (__int64)&v158);
      if ( v106 )
      {
        *(_WORD *)(a1 + 76) = (*(_WORD *)(v106 + 12) >> 2) & 0x3C;
        v107 = *(_QWORD *)(v146 + 3072);
        v108 = *(unsigned __int8 *)(v146 + 2688);
        ++*(_QWORD *)(v146 + 3064);
        v109 = v107 + *(unsigned int *)(a1 + 48);
        LODWORD(v107) = v156[0];
        *(_QWORD *)(v146 + 3072) = v109;
        v110 = *(unsigned int *)(a1 + 48);
        v111 = (unsigned int)v107 >> 28;
        v112 = 2 * (unsigned int)(*(_BYTE *)(a1 + 78) != 4);
        goto LABEL_158;
      }
    }
    else
    {
      ++*(_QWORD *)(v146 + 2856);
    }
    goto LABEL_154;
  }
  v158 = 0;
  v113 = rmnet_frag_header_ptr(a1, (unsigned __int16)v94, 8u, (__int64)&v158);
  if ( !v113 )
    goto LABEL_154;
  *(_WORD *)(a1 + 76) = 8;
  v114 = *(_QWORD *)(v146 + 3088);
  ++*(_QWORD *)(v146 + 3080);
  *(_QWORD *)(v146 + 3088) = v114 + *(unsigned int *)(a1 + 48);
  if ( *(_BYTE *)(a1 + 78) == 4 )
  {
    v115 = *(_WORD *)(v113 + 6) == 0;
    rmnet_module_hook_perf_coal_stat(
      *(unsigned __int8 *)(v146 + 2688),
      LODWORD(v156[0]) >> 28,
      *(unsigned int *)(a1 + 48),
      1);
  }
  else
  {
    v110 = *(unsigned int *)(a1 + 48);
    v112 = 3;
    v111 = LODWORD(v156[0]) >> 28;
    v108 = *(unsigned __int8 *)(v146 + 2688);
LABEL_158:
    rmnet_module_hook_perf_coal_stat(v108, v111, v110, v112);
    v115 = 0;
  }
  v116 = *(_QWORD **)(a1 + 16);
  v117 = *(_BYTE *)(a1 + 81) | 2;
  *(_DWORD *)(a1 + 44) = *(_DWORD *)(a1 + 48);
  *(_BYTE *)(a1 + 81) = v117;
  if ( v116 != v144 )
  {
    v118 = *(_DWORD *)(a1 + 40);
    do
    {
      v119 = v116[2];
      v120 = 0;
      if ( (v119 & 1) != 0 )
        v119 = 0;
      if ( (*(_QWORD *)v119 & 0x40) != 0 )
        v120 = *(_BYTE *)(v119 + 64);
      v118 += 4096LL << v120;
      *(_DWORD *)(a1 + 40) = v118;
      v116 = (_QWORD *)*v116;
    }
    while ( v116 != v144 );
  }
  if ( !(v115 | ((rmnet_map_v5_csum_buggy(v156) & 1) == 0)) )
  {
    v125 = (_QWORD *)*v144;
    if ( (_QWORD *)*v144 != v144 )
    {
      if ( v125 )
      {
        v126 = v125[2];
        if ( v126 )
        {
          if ( (v126 & 1) == 0 )
          {
            v127 = (((v126 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
                 + *((unsigned int *)v125 + 7);
            if ( v127 )
            {
              v128 = *(_DWORD *)(a1 + 48) - *(unsigned __int16 *)(a1 + 74);
              if ( *(_BYTE *)(a1 + 78) == 4 )
              {
                HIDWORD(v129) = csum_tcpudp_nofold(
                                  *(unsigned int *)(v127 + 12),
                                  *(unsigned int *)(v127 + 16),
                                  v128,
                                  *(unsigned __int8 *)(a1 + 79),
                                  0);
                LODWORD(v129) = HIDWORD(v129);
                v130 = ((unsigned int)(v129 >> 16) + HIDWORD(v129)) >> 16;
              }
              else
              {
                v130 = ~(unsigned int)csum_ipv6_magic(v127 + 8, v127 + 24, v128, *(unsigned __int8 *)(a1 + 79), 0);
              }
              HIDWORD(v142) = csum_partial(v127 + *(unsigned __int16 *)(a1 + 74), v128, (unsigned __int16)v130);
              LODWORD(v142) = HIDWORD(v142);
              if ( (unsigned int)(v142 >> 16) + HIDWORD(v142) >= 0xFFFF0000 )
                *(_BYTE *)(a1 + 81) |= 1u;
            }
          }
        }
      }
    }
    v143 = (bswap32(WORD2(v156[0])) >> 16) - (*(unsigned __int16 *)(a1 + 74) + *(unsigned __int16 *)(a1 + 76));
    *(_WORD *)(a1 + 72) = HIBYTE(v156[0]);
    *(_WORD *)(a1 + 70) = v143;
    v121 = (__int64 *)a3[1];
    if ( (_QWORD *)a1 != a3 && v121 != (__int64 *)a1 && (_QWORD *)*v121 == a3 )
    {
      a3[1] = a1;
      *(_QWORD *)a1 = a3;
      *(_QWORD *)(a1 + 8) = v121;
      *v121 = a1;
      goto LABEL_154;
    }
    goto LABEL_213;
  }
  if ( (v156[0] & 0xF000) == 0x9000 )
    v122 = v96;
  else
    v122 = 0;
  if ( v122 == 1 )
  {
    v123 = HIBYTE(v156[0]);
    v124 = (bswap32(WORD2(v156[0])) >> 16) - (*(unsigned __int16 *)(a1 + 74) + *(unsigned __int16 *)(a1 + 76));
    *(_BYTE *)(a1 + 81) |= 1u;
    *(_WORD *)(a1 + 70) = v124;
    *(_WORD *)(a1 + 72) = v123;
    list_add_tail((_QWORD *)a1, a3);
    goto LABEL_154;
  }
  if ( (v156[0] & 0x7000) != 0 )
  {
    v131 = 0;
    v132 = 0;
    while ( 1 )
    {
      if ( v131 == 6 )
        goto LABEL_212;
      if ( 4 * v131 == 24 )
        break;
      v133 = (unsigned __int16 *)v156 + 2 * v131 + 2;
      *(_WORD *)(a1 + 70) = (bswap32(*v133) >> 16) - (*(_WORD *)(a1 + 74) + *(_WORD *)(a1 + 76));
      if ( (unsigned __int64)(4 * v131 - 22) < 0xFFFFFFFFFFFFFFE3LL )
        break;
      if ( *((_BYTE *)v133 + 3) )
      {
        v134 = 0;
        do
        {
          if ( (v96 & 1) != 0 )
          {
            if ( (v90 & 1) == 0 )
            {
              ++*(_WORD *)(a1 + 72);
              goto LABEL_189;
            }
            v141 = *(unsigned __int8 *)(v146 + 2688);
            ++*(_QWORD *)(v146 + 2832);
            rmnet_module_hook_perf_coal_common_stat(v141, 0);
            if ( *(_WORD *)(a1 + 72) )
              _rmnet_frag_segment_data(a1, a2, a3, v132, 1);
            v135 = a1;
            v136 = a2;
            v138 = a3;
            v139 = v132;
            v137 = 0;
            *(_WORD *)(a1 + 72) = 1;
          }
          else
          {
            *(_WORD *)(a1 + 72) = 1;
            if ( (v90 & 1) != 0 )
            {
              v140 = *(unsigned __int8 *)(v146 + 2688);
              ++*(_QWORD *)(v146 + 2832);
              rmnet_module_hook_perf_coal_common_stat(v140, 0);
            }
            v135 = a1;
            v136 = a2;
            v137 = (v90 & 1) == 0;
            v138 = a3;
            v139 = v132;
          }
          _rmnet_frag_segment_data(v135, v136, v138, v139, v137);
LABEL_189:
          ++v134;
          v90 >>= 1;
          ++v132;
        }
        while ( v134 < *((unsigned __int8 *)v133 + 3) );
      }
      if ( *(_WORD *)(a1 + 72) )
        _rmnet_frag_segment_data(a1, a2, a3, v132, 1);
      if ( ((LODWORD(v156[0]) >> 12) & 7) <= (unsigned int)++v131 )
        goto LABEL_154;
    }
    __break(1u);
LABEL_212:
    __break(0x5512u);
LABEL_213:
    _list_add_valid_or_report(a1, v121, a3);
  }
LABEL_154:
  if ( *a3 != a1 )
    rmnet_recycle_frag_descriptor((_QWORD *)a1, a2);
  result = 0;
LABEL_87:
  _ReadStatusReg(SP_EL0);
  return result;
}
