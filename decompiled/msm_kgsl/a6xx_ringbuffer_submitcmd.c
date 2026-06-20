__int64 __fastcall a6xx_ringbuffer_submitcmd(__int64 a1, __int64 a2, char a3, __int64 a4)
{
  signed int v7; // w23
  int v10; // w20
  _QWORD *v11; // x9
  __int64 v12; // x25
  unsigned __int64 v13; // x26
  _DWORD *v14; // x0
  unsigned int v15; // w10
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x9
  __int64 v22; // x9
  unsigned __int64 v23; // x9
  __int64 v24; // x11
  __int64 v25; // x16
  __int64 v26; // x13
  unsigned __int64 v27; // x9
  _DWORD *v28; // x12
  __int64 v29; // x11
  unsigned __int64 v30; // x9
  unsigned __int64 v31; // x9
  unsigned __int64 v32; // x9
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x9
  signed int v35; // w13
  __int64 *v36; // x12
  unsigned __int64 v37; // x14
  unsigned __int64 v39; // x14
  unsigned __int64 v40; // x15
  bool v41; // cf
  unsigned __int64 v42; // x15
  unsigned __int64 v43; // x14
  bool v44; // cf
  unsigned __int64 v45; // x14
  unsigned __int64 v46; // x16
  bool v47; // cf
  unsigned __int64 v48; // x16
  int v49; // w15
  unsigned __int64 v50; // x16
  bool v51; // cf
  unsigned __int64 v52; // x16
  unsigned __int64 v53; // x11
  bool v54; // cf
  unsigned __int64 v55; // x11
  unsigned __int64 v56; // x12
  bool v57; // cf
  unsigned __int64 v58; // x12
  unsigned __int64 v59; // x9
  bool v60; // cf
  unsigned __int64 v61; // x9
  unsigned int v62; // w9
  unsigned int v63; // w11
  unsigned __int64 v64; // x10
  bool v65; // cf
  unsigned __int64 v66; // x10
  unsigned __int64 v67; // x12
  bool v68; // cf
  unsigned __int64 v69; // x12
  unsigned __int64 v70; // x12
  bool v71; // cf
  unsigned __int64 v72; // x12
  signed int v73; // w10
  unsigned __int64 v74; // x13
  __int64 v75; // x10
  __int64 v76; // x11
  _DWORD *v77; // x12
  __int64 v78; // x14
  __int64 v79; // x11
  unsigned __int64 v80; // x13
  unsigned __int64 v81; // x13
  __int64 v82; // x14
  unsigned __int64 v83; // x13
  __int64 v84; // x10
  _DWORD *v85; // x12
  __int64 v86; // x10
  unsigned __int64 v87; // x9
  int v88; // w9
  __int64 v89; // x13
  __int64 v90; // x12
  unsigned __int64 v91; // x9
  __int64 v92; // x11
  __int64 v93; // x14
  __int64 v94; // x13
  _DWORD *v95; // x8
  __int64 v96; // x11
  unsigned __int64 v97; // x9
  unsigned __int64 v98; // x9
  unsigned __int64 v99; // x9
  bool v100; // cf
  unsigned __int64 v101; // x9
  unsigned __int64 v102; // x9
  bool v103; // cf
  unsigned __int64 v104; // x9
  unsigned int v105; // w8
  unsigned int v106; // w26
  unsigned int v111; // w9
  __int64 v112; // x26
  __int64 v113; // x8
  unsigned int v114; // w5
  int v115; // w9
  unsigned int v116; // w8
  __int64 v117; // x8
  __int64 v118; // x0
  _DWORD *v119; // x10
  __int64 v120; // x11
  __int64 v121; // x14
  unsigned int v122; // w15
  unsigned int v123; // w8
  _DWORD *v124; // x16
  __int64 v125; // x1
  __int64 v126; // x17
  __int64 v127; // x1
  __int64 v128; // x8
  unsigned int v129; // w11
  __int64 v130; // x12
  __int64 v131; // x12
  __int64 v132; // x13
  unsigned int v133; // w0
  unsigned int v134; // w26
  const void *v135; // x25
  unsigned __int64 StatusReg; // x27
  __int64 v137; // x28
  int v140; // w8
  _DWORD *v141; // x23
  unsigned int v142; // [xsp+4h] [xbp-CCh]
  _DWORD *v143; // [xsp+8h] [xbp-C8h]
  _DWORD *v144; // [xsp+8h] [xbp-C8h]
  _QWORD *v145; // [xsp+10h] [xbp-C0h]
  __int64 v146; // [xsp+10h] [xbp-C0h]
  _QWORD v147[20]; // [xsp+18h] [xbp-B8h] BYREF
  int v148; // [xsp+B8h] [xbp-18h]
  __int64 v149; // [xsp+C0h] [xbp-10h]

  LOBYTE(v7) = a3;
  v149 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  _X22 = *(_QWORD *)(a2 + 8);
  if ( (a3 & 0x10) != 0 )
  {
    v10 = 0;
  }
  else
  {
    v10 = -1;
    v11 = (_QWORD *)(a2 + 88);
    do
    {
      v11 = (_QWORD *)*v11;
      ++v10;
    }
    while ( v11 != (_QWORD *)(a2 + 88) );
  }
  v12 = *(_QWORD *)(_X22 + 1536);
  v13 = 20 * v10 + 160;
  v14 = (_DWORD *)_kvmalloc_node_noprof(v13, 0, 3264, 0xFFFFFFFFLL);
  if ( !v14 )
  {
LABEL_189:
    v134 = -12;
    goto LABEL_190;
  }
  while ( 1 )
  {
    if ( v13 < 4 )
      goto LABEL_188;
    *v14 = 1880096769;
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 4 )
      goto LABEL_188;
    v14[1] = 783149758;
    if ( (v7 & 0x40) != 0 )
    {
      if ( v13 < 8 )
        goto LABEL_188;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 8 )
        goto LABEL_188;
      v16 = *(_QWORD *)(a1 + 20448);
      v17 = *(unsigned int *)(a2 + 144);
      v18 = *(_QWORD *)(v16 + 24);
      v14[2] = 1883144195;
      if ( v13 < 0xC )
        goto LABEL_188;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0xC )
        goto LABEL_188;
      v14[3] = 1074268544;
      if ( v13 < 0x10 )
        goto LABEL_188;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
        goto LABEL_188;
      v19 = 32 * v17;
      v20 = v19 + v18;
      v14[4] = v20;
      if ( v13 < 0x14 )
        goto LABEL_188;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x14 )
        goto LABEL_188;
      v14[5] = HIDWORD(v20);
      if ( v13 < 0x18 )
        goto LABEL_188;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x18 )
        goto LABEL_188;
      v21 = *(_QWORD *)(v16 + 24);
      v14[6] = 1883144195;
      if ( v13 < 0x1C )
        goto LABEL_188;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x1C )
        goto LABEL_188;
      v14[7] = 1074268546;
      if ( v13 < 0x20 )
        goto LABEL_188;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x20 )
        goto LABEL_188;
      v22 = v21 + v19 + 16;
      v14[8] = v22;
      if ( v13 < 0x24 || (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x24 )
        goto LABEL_188;
      v15 = 10;
      v14[9] = HIDWORD(v22);
      if ( (v7 & 0x20) == 0 )
      {
LABEL_11:
        if ( !v10 )
          goto LABEL_83;
        goto LABEL_43;
      }
    }
    else
    {
      v15 = 2;
      if ( (v7 & 0x20) == 0 )
        goto LABEL_11;
    }
    v23 = *(_QWORD *)(v12 + 1304);
    if ( v23 > 0xFFFFFFFFFFFFF000LL )
    {
      if ( !v10 )
        goto LABEL_83;
LABEL_43:
      v32 = 4LL * v15;
      _CF = v13 >= v32;
      v33 = v13 - v32;
      if ( !_CF )
        goto LABEL_188;
      if ( v33 < 4 )
        goto LABEL_188;
      v34 = 4LL * (v15 + 1);
      v14[v15] = 1894055937;
      if ( v13 < v34 || v13 - v34 < 4 )
        goto LABEL_188;
      v35 = v15 + 2;
      v36 = *(__int64 **)(a2 + 88);
      for ( v14[v15 + 1] = 13; v36 != (__int64 *)(a2 + 88); v36 = (__int64 *)*v36 )
      {
        if ( (v36[7] & 2) != 0 || (v7 & 0x80) == 0 && (v36[6] & 2) != 0 )
        {
          v37 = 4LL * v35;
          _CF = v13 >= v37;
          v39 = v13 - v37;
          if ( v35 < 0 || !_CF || v39 < 4 )
            goto LABEL_188;
          v14[v35++] = 1880096772;
        }
        v40 = 4LL * v35;
        v41 = v13 >= v40;
        v42 = v13 - v40;
        if ( v35 < 0 )
          goto LABEL_188;
        if ( !v41 )
          goto LABEL_188;
        if ( v42 < 4 )
          goto LABEL_188;
        v14[v35] = 1891598339;
        v43 = 4LL * (v35 + 1);
        v44 = v13 >= v43;
        v45 = v13 - v43;
        if ( v35 + 1 < 0 )
          goto LABEL_188;
        if ( !v44 )
          goto LABEL_188;
        if ( v45 < 4 )
          goto LABEL_188;
        v46 = 4LL * (v35 + 2);
        v14[v35 + 1] = v36[4];
        v47 = v13 >= v46;
        v48 = v13 - v46;
        if ( v35 + 2 < 0 )
          goto LABEL_188;
        if ( !v47 )
          goto LABEL_188;
        if ( v48 < 4 )
          goto LABEL_188;
        v49 = v35 + 3;
        v50 = 4LL * (v35 + 3);
        v14[v35 + 2] = *((_DWORD *)v36 + 9);
        v51 = v13 >= v50;
        v52 = v13 - v50;
        if ( v35 + 3 < 0 || !v51 || v52 < 4 )
          goto LABEL_188;
        v35 += 4;
        v14[v49] = (*((_DWORD *)v36 + 10) >> 2) & 0xFFFFF;
      }
      v53 = 4LL * v35;
      v54 = v13 >= v53;
      v55 = v13 - v53;
      if ( v35 < 0 )
        goto LABEL_188;
      if ( !v54 )
        goto LABEL_188;
      if ( v55 < 4 )
        goto LABEL_188;
      v14[v35] = 1894055937;
      v56 = 4LL * (v35 + 1);
      v57 = v13 >= v56;
      v58 = v13 - v56;
      if ( v35 + 1 < 0 || !v57 || v58 < 4 )
        goto LABEL_188;
      v15 = v35 + 2;
      v14[v35 + 1] = 14;
      goto LABEL_83;
    }
    v24 = (unsigned int)(16 * *(_DWORD *)(v12 + 1312));
    v25 = *(_QWORD *)(v23 + 8) + v24;
    v26 = *(_QWORD *)(v23 + 24);
    v27 = 4LL * v15;
    *(_QWORD *)(v25 + 8) = *(_QWORD *)(a2 + 136) + 24LL;
    *(_DWORD *)v25 = 1883144195;
    *(_DWORD *)(v25 + 4) = 1074268544;
    if ( v13 < v27 )
      goto LABEL_188;
    if ( v13 - v27 < 4 )
      goto LABEL_188;
    v28 = &v14[v27 / 4];
    v14[v15] = 1891598339;
    if ( v13 < (v27 | 4) )
      goto LABEL_188;
    if ( v13 - (v27 | 4) < 4 )
      goto LABEL_188;
    v29 = v26 + v24;
    v28[1] = v29;
    if ( v13 < v27 + 8 )
      goto LABEL_188;
    if ( v13 - (v27 + 8) < 4 )
      goto LABEL_188;
    v30 = v27 + 12;
    _CF = v13 >= v30;
    v31 = v13 - v30;
    v28[2] = HIDWORD(v29);
    if ( !_CF || v31 < 4 )
      goto LABEL_188;
    v28[3] = 4;
    *(_DWORD *)(v12 + 1312) = (unsigned __int8)(*(_DWORD *)(v12 + 1312) + 1);
    v15 |= 4u;
    if ( v10 )
      goto LABEL_43;
LABEL_83:
    v59 = 4LL * (int)v15;
    v145 = (_QWORD *)a4;
    v60 = v13 >= v59;
    v61 = v13 - v59;
    if ( (v15 & 0x80000000) != 0 )
      goto LABEL_188;
    if ( !v60 )
      goto LABEL_188;
    if ( v61 < 4 )
      goto LABEL_188;
    v62 = v15;
    a4 = 1883635713;
    v63 = v15 + 1;
    v14[v15] = 1883635713;
    v64 = 4LL * (int)(v15 + 1);
    v65 = v13 >= v64;
    v66 = v13 - v64;
    if ( (v63 & 0x80000000) != 0 )
      goto LABEL_188;
    if ( !v65 )
      goto LABEL_188;
    if ( v66 < 4 )
      goto LABEL_188;
    v14[v63] = 24;
    v67 = 4LL * (int)(v62 + 2);
    v68 = v13 >= v67;
    v69 = v13 - v67;
    if ( ((v62 + 2) & 0x80000000) != 0 )
      goto LABEL_188;
    if ( !v68 )
      goto LABEL_188;
    if ( v69 < 4 )
      goto LABEL_188;
    v14[v62 + 2] = 1883635713;
    v70 = 4LL * (int)(v62 + 3);
    v71 = v13 >= v70;
    v72 = v13 - v70;
    if ( ((v62 + 3) & 0x80000000) != 0 || !v71 || v72 < 4 )
      goto LABEL_188;
    v73 = v62 + 4;
    v14[v62 + 3] = 25;
    if ( (v7 & 0x40) != 0 )
    {
      v74 = 4LL * v73;
      if ( v73 < 0 )
        goto LABEL_188;
      if ( v13 < v74 )
        goto LABEL_188;
      if ( v13 - v74 < 4 )
        goto LABEL_188;
      v75 = *(_QWORD *)(a1 + 20448);
      v76 = *(unsigned int *)(a2 + 144);
      v77 = &v14[v74 / 4];
      v78 = *(_QWORD *)(v75 + 24);
      v14[v74 / 4] = 1883144195;
      if ( v13 < v74 + 4 )
        goto LABEL_188;
      if ( v13 - (v74 + 4) < 4 )
        goto LABEL_188;
      v77[1] = 1074268544;
      if ( v13 < v74 + 8 )
        goto LABEL_188;
      if ( v13 - (v74 + 8) < 4 )
        goto LABEL_188;
      v79 = 32 * v76;
      v80 = v74 + 12;
      _CF = v13 >= v80;
      v81 = v13 - v80;
      v82 = v78 + v79 + 8;
      v77[2] = v82;
      if ( !_CF )
        goto LABEL_188;
      if ( v81 < 4 )
        goto LABEL_188;
      v83 = 4LL * (int)(v62 + 8);
      v77[3] = HIDWORD(v82);
      if ( ((v62 + 8) & 0x80000000) != 0 )
        goto LABEL_188;
      if ( v13 < v83 )
        goto LABEL_188;
      if ( v13 - v83 < 4 )
        goto LABEL_188;
      v84 = *(_QWORD *)(v75 + 24);
      v85 = &v14[v83 / 4];
      v14[v62 + 8] = 1883144195;
      if ( v13 < v83 + 4 )
        goto LABEL_188;
      if ( v13 - (v83 + 4) < 4 )
        goto LABEL_188;
      v85[1] = 1074268546;
      if ( v13 < v83 + 8 )
        goto LABEL_188;
      if ( v13 - (v83 + 8) < 4 )
        goto LABEL_188;
      v86 = v84 + v79 + 24;
      v85[2] = v86;
      if ( v13 < v83 + 12 || v13 - (v83 + 12) < 4 )
        goto LABEL_188;
      v85[3] = HIDWORD(v86);
      v73 = v62 + 12;
    }
    if ( (v7 & 0x20) != 0 )
    {
      v87 = *(_QWORD *)(v12 + 1304);
      if ( v87 <= 0xFFFFFFFFFFFFF000LL )
      {
        v89 = *(_QWORD *)(v87 + 8);
        v90 = *(_QWORD *)(v87 + 24);
        v91 = 4LL * v73;
        v92 = (unsigned int)(16 * *(_DWORD *)(v12 + 1312));
        v93 = *(_QWORD *)(a2 + 136) + 32LL;
        v94 = v89 + v92;
        *(_DWORD *)v94 = 1883144195;
        *(_DWORD *)(v94 + 4) = 1074268544;
        *(_QWORD *)(v94 + 8) = v93;
        if ( v73 < 0 )
          goto LABEL_188;
        if ( v13 < v91 )
          goto LABEL_188;
        if ( v13 - v91 < 4 )
          goto LABEL_188;
        v95 = &v14[v91 / 4];
        v14[v73] = 1891598339;
        if ( v13 < v91 + 4 )
          goto LABEL_188;
        if ( v13 - (v91 + 4) < 4 )
          goto LABEL_188;
        v96 = v90 + v92;
        v95[1] = v96;
        if ( v13 < v91 + 8 )
          goto LABEL_188;
        if ( v13 - (v91 + 8) < 4 )
          goto LABEL_188;
        v97 = v91 + 12;
        _CF = v13 >= v97;
        v98 = v13 - v97;
        v95[2] = HIDWORD(v96);
        if ( !_CF || v98 < 4 )
          goto LABEL_188;
        v88 = 4;
        v95[3] = 4;
        *(_DWORD *)(v12 + 1312) = (unsigned __int8)(*(_DWORD *)(v12 + 1312) + 1);
      }
      else
      {
        v88 = 0;
      }
      v73 += v88;
    }
    v99 = 4LL * v73;
    v100 = v13 >= v99;
    v101 = v13 - v99;
    if ( (v73 & 0x80000000) == 0 && v100 && v101 >= 4 )
    {
      v7 = v73;
      v14[v73] = 1880096769;
      v102 = 4LL * (v73 + 1);
      v103 = v13 >= v102;
      v104 = v13 - v102;
      if ( ((v73 + 1) & 0x80000000) == 0 && v103 && v104 >= 4 )
        break;
    }
LABEL_188:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v146 = a4;
    v137 = *(_QWORD *)(StatusReg + 80);
    v13 = 20 * v10 + 160;
    *(_QWORD *)(StatusReg + 80) = &a6xx_ringbuffer_submitcmd__alloc_tag;
    v14 = (_DWORD *)_kvmalloc_node_noprof(v13, 0, 3264, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v137;
    a4 = v146;
    if ( !v14 )
      goto LABEL_189;
  }
  v14[v73 + 1] = 717151917;
  if ( *(_QWORD *)(v12 + 176) == _X22 )
  {
LABEL_185:
    v135 = v14;
    adreno_drawobj_set_constraint(a1, a2);
    v134 = a6xx_ringbuffer_addcmds(a1, *(_QWORD *)(_X22 + 1536), _X22, a3, v135, v7 + 2, *(_DWORD *)(a2 + 20), v145);
    v14 = v135;
    goto LABEL_190;
  }
  if ( !_X22 || (*(_QWORD *)(_X22 + 32) & 2) != 0 )
    goto LABEL_187;
  v105 = *(_DWORD *)_X22;
  if ( *(_DWORD *)_X22 )
  {
    do
    {
      __asm { PRFM            #0x11, [X22] }
      do
        v111 = __ldxr((unsigned int *)_X22);
      while ( v111 == v105 && __stxr(v105 + 1, (unsigned int *)_X22) );
      v106 = v105;
      if ( v111 == v105 )
        break;
      v106 = 0;
      v105 = v111;
    }
    while ( v111 );
  }
  else
  {
    v106 = 0;
  }
  if ( (((v106 + 1) | v106) & 0x80000000) == 0 )
  {
    if ( v106 )
      goto LABEL_157;
LABEL_187:
    v134 = -2;
    goto LABEL_190;
  }
  v144 = v14;
  refcount_warn_saturate(_X22, 0);
  v14 = v144;
  if ( !v106 )
    goto LABEL_187;
LABEL_157:
  v112 = *(_QWORD *)(*(_QWORD *)(_X22 + 24) + 64LL);
  v113 = *(_QWORD *)(v12 + 176);
  v148 = 0;
  memset(v147, 0, sizeof(v147));
  if ( v113 )
    v113 = *(_QWORD *)(*(_QWORD *)(v113 + 24) + 64LL);
  v143 = v14;
  if ( v113 == v112 )
  {
    v115 = *(_DWORD *)(_X22 + 4);
    v116 = 0;
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 23968) & 1) != 0 )
    {
      v114 = 0;
    }
    else
    {
      v114 = 2;
      v147[0] = 0x140050E01LL;
    }
    if ( v112 )
    {
      v117 = *(_QWORD *)(v112 + 96);
      if ( v117 )
      {
        v117 = *(_QWORD *)(v117 + 48);
        if ( v117 )
        {
          v142 = v114;
          if ( *(_DWORD *)(v117 - 4) != 1831526433 )
            __break(0x8228u);
          v118 = ((__int64 (__fastcall *)(__int64))v117)(v112);
          v114 = v142;
          v117 = v118;
        }
      }
    }
    else
    {
      v117 = 0;
    }
    v115 = *(_DWORD *)(_X22 + 4);
    if ( *(_QWORD *)(a1 + 72) == v112 )
    {
      v123 = 0;
    }
    else
    {
      v119 = (_DWORD *)v147 + v114;
      *v119 = 1892909059;
      v119[1] = v117;
      v120 = *(_QWORD *)(a1 + 14264);
      v119[2] = HIDWORD(v117);
      v119[3] = v115;
      v121 = *(_QWORD *)(v120 + 32);
      if ( (v121 & 0x800) != 0 )
      {
        v122 = 4;
      }
      else
      {
        v119[4] = 1881571328;
        v119[5] = 1880326144;
        v122 = 8;
        v119[6] = 1208500225;
        v119[7] = 1;
      }
      v124 = &v119[v122];
      v125 = *(_QWORD *)(a1 + 48);
      *v124 = 1883078661;
      v126 = *(_QWORD *)(v125 + 24);
      v127 = *(int *)(v12 + 28);
      v124[4] = HIDWORD(v117);
      v124[5] = v115;
      v119[v122 | 3] = v117;
      v128 = v126 + 32 * v127 + 16;
      v119[v122 | 1] = v128;
      v119[v122 | 2] = HIDWORD(v128);
      v123 = v122 + 6;
      if ( (v121 & 0x800) == 0 )
      {
        v119[v123] = 1881571328;
        v123 = v122 + 10;
        v124[7] = 1880326144;
        *((_QWORD *)v124 + 4) = 1208500225;
      }
    }
    v116 = v123 + v114;
    if ( (*(_BYTE *)(a1 + 23968) & 1) == 0 )
    {
      *((_DWORD *)v147 + v116) = 1891401734;
      *((_DWORD *)v147 + v116 + 1) = 3;
      *((_DWORD *)&v147[1] + v116) = 1295;
      *((_DWORD *)&v147[1] + v116 + 1) = 0;
      *((_DWORD *)&v147[2] + v116) = 1;
      *((_DWORD *)&v147[2] + v116 + 1) = 1;
      v129 = v116 + 6;
      v116 += 7;
      *((_DWORD *)v147 + v129) = 0;
    }
  }
  *((_DWORD *)v147 + v116) = 1880096769;
  *((_DWORD *)v147 + v116 + 1) = 783138543;
  v130 = *(_QWORD *)(a1 + 40);
  *((_DWORD *)&v147[1] + v116) = 1883078659;
  v131 = *(_QWORD *)(v130 + 24);
  v132 = v131 + 40LL * *(int *)(v12 + 28);
  *((_DWORD *)&v147[3] + v116) = 1883078659;
  *((_DWORD *)&v147[3] + v116 + 1) = v131 + 32;
  *((_DWORD *)&v147[2] + v116 + 1) = v115;
  *((_DWORD *)&v147[1] + v116 + 1) = v132 + 32552;
  *((_DWORD *)&v147[2] + v116) = (unsigned __int64)(v132 + 32552) >> 32;
  *((_DWORD *)&v147[4] + v116 + 1) = v115;
  *((_DWORD *)&v147[5] + v116) = 1883635713;
  *((_DWORD *)&v147[4] + v116) = (unsigned __int64)(v131 + 32) >> 32;
  *((_DWORD *)&v147[5] + v116 + 1) = 49;
  v133 = a6xx_ringbuffer_addcmds(a1, v12, 0, 1, v147, v116 + 12, 0, nullptr);
  if ( !v133 )
  {
    adreno_put_drawctxt_on_timestamp(a1, *(_QWORD *)(v12 + 176), v12, *(unsigned int *)(v12 + 36));
    v14 = v143;
    *(_QWORD *)(v12 + 176) = _X22;
    goto LABEL_185;
  }
  v134 = v133;
  __asm { PRFM            #0x11, [X22] }
  do
    v140 = __ldxr((unsigned int *)_X22);
  while ( __stlxr(v140 - 1, (unsigned int *)_X22) );
  if ( v140 == 1 )
  {
    __dmb(9u);
    kgsl_context_destroy(_X22);
    v14 = v143;
    if ( v134 == -28 )
      goto LABEL_190;
  }
  else
  {
    v14 = v143;
    if ( v140 <= 0 )
    {
      refcount_warn_saturate(_X22, 3);
      v14 = v143;
      if ( v134 == -28 )
        goto LABEL_190;
    }
    else if ( v134 == -28 )
    {
      goto LABEL_190;
    }
  }
  if ( v134 != -2 )
  {
    v141 = v14;
    dev_err(*(_QWORD *)a1, "Unable to switch draw context: %d\n", v134);
    v14 = v141;
  }
LABEL_190:
  kvfree(v14);
  _ReadStatusReg(SP_EL0);
  return v134;
}
