__int64 __fastcall gen8_ringbuffer_submitcmd(__int64 a1, __int64 a2, char a3, __int64 a4)
{
  signed int v7; // w28
  int v10; // w20
  _QWORD *v11; // x9
  __int64 v12; // x25
  unsigned __int64 v13; // x26
  _DWORD *v14; // x0
  unsigned int v15; // w9
  __int64 v16; // x9
  __int64 v17; // x10
  __int64 v18; // x11
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x9
  __int64 v22; // x9
  unsigned __int64 v23; // x10
  int v24; // w10
  __int64 v25; // x12
  __int64 v26; // x10
  __int64 v27; // x13
  unsigned __int64 v28; // x11
  __int64 v29; // x14
  _DWORD *v30; // x12
  __int64 v31; // x13
  unsigned __int64 v32; // x10
  unsigned __int64 v33; // x10
  unsigned int v34; // w10
  unsigned __int64 v35; // x11
  unsigned __int64 v36; // x11
  unsigned __int64 v37; // x10
  unsigned __int64 v38; // x10
  unsigned __int64 v39; // x10
  signed int v40; // w13
  __int64 *v41; // x12
  unsigned __int64 v42; // x14
  unsigned __int64 v44; // x14
  unsigned __int64 v45; // x15
  bool v46; // cf
  unsigned __int64 v47; // x15
  unsigned __int64 v48; // x14
  bool v49; // cf
  unsigned __int64 v50; // x14
  unsigned __int64 v51; // x16
  bool v52; // cf
  unsigned __int64 v53; // x16
  int v54; // w15
  unsigned __int64 v55; // x16
  bool v56; // cf
  unsigned __int64 v57; // x16
  unsigned __int64 v58; // x11
  bool v59; // cf
  unsigned __int64 v60; // x11
  unsigned __int64 v61; // x12
  bool v62; // cf
  unsigned __int64 v63; // x12
  unsigned __int64 v64; // x10
  bool v65; // cf
  unsigned __int64 v66; // x10
  unsigned int v67; // w10
  unsigned __int64 v68; // x11
  bool v69; // cf
  unsigned __int64 v70; // x11
  unsigned __int64 v71; // x11
  bool v72; // cf
  unsigned __int64 v73; // x11
  unsigned __int64 v74; // x11
  bool v75; // cf
  unsigned __int64 v76; // x11
  unsigned __int64 v77; // x12
  bool v78; // cf
  unsigned __int64 v79; // x12
  unsigned __int64 v80; // x10
  bool v81; // cf
  unsigned __int64 v82; // x10
  signed int v83; // w10
  unsigned __int64 v84; // x13
  __int64 v85; // x10
  __int64 v86; // x11
  _DWORD *v87; // x12
  __int64 v88; // x14
  __int64 v89; // x11
  unsigned __int64 v90; // x13
  unsigned __int64 v91; // x13
  __int64 v92; // x14
  unsigned __int64 v93; // x13
  __int64 v94; // x10
  _DWORD *v95; // x12
  __int64 v96; // x10
  unsigned __int64 v97; // x9
  int v98; // w9
  __int64 v99; // x12
  __int64 v100; // x9
  __int64 v101; // x13
  unsigned __int64 v102; // x11
  __int64 v103; // x12
  _DWORD *v104; // x8
  __int64 v105; // x12
  unsigned __int64 v106; // x9
  bool v107; // cf
  unsigned __int64 v108; // x9
  unsigned __int64 v109; // x9
  bool v110; // cf
  unsigned __int64 v111; // x9
  unsigned int v112; // w8
  unsigned int v113; // w26
  unsigned int v118; // w9
  __int64 v119; // x8
  __int64 v120; // x26
  __int64 v121; // x8
  char v122; // w8
  int v123; // w17
  unsigned int v124; // w8
  int v125; // w8
  __int64 v126; // x8
  __int64 v127; // x0
  int v128; // w11
  _DWORD *v129; // x9
  __int64 v130; // x10
  __int64 v131; // x13
  __int64 v132; // x10
  int v133; // w8
  int v134; // w10
  __int64 v135; // x12
  int v136; // w5
  __int64 v137; // x11
  int v138; // w13
  __int64 v139; // x10
  __int64 v140; // x9
  __int64 v141; // x9
  _DWORD *v142; // x23
  unsigned int v143; // w0
  unsigned int v144; // w26
  const void *v145; // x25
  unsigned __int64 StatusReg; // x23
  __int64 v147; // x27
  int v150; // w8
  _DWORD *v151; // x23
  int v152; // [xsp+Ch] [xbp-124h]
  _DWORD *v153; // [xsp+10h] [xbp-120h]
  _DWORD *v154; // [xsp+10h] [xbp-120h]
  _QWORD *v155; // [xsp+18h] [xbp-118h]
  __int64 v156; // [xsp+18h] [xbp-118h]
  _DWORD v157[6]; // [xsp+24h] [xbp-10Ch] BYREF
  __int64 v158; // [xsp+3Ch] [xbp-F4h]
  __int64 v159; // [xsp+44h] [xbp-ECh]
  unsigned __int64 v160; // [xsp+4Ch] [xbp-E4h]
  __int64 v161; // [xsp+54h] [xbp-DCh]
  __int64 v162; // [xsp+5Ch] [xbp-D4h]
  __int64 v163; // [xsp+64h] [xbp-CCh]
  __int64 v164; // [xsp+6Ch] [xbp-C4h]
  __int64 v165; // [xsp+74h] [xbp-BCh]
  __int64 v166; // [xsp+7Ch] [xbp-B4h]
  __int64 v167; // [xsp+84h] [xbp-ACh]
  __int64 v168; // [xsp+8Ch] [xbp-A4h]
  __int64 v169; // [xsp+94h] [xbp-9Ch]
  __int64 v170; // [xsp+9Ch] [xbp-94h]
  __int64 v171; // [xsp+A4h] [xbp-8Ch]
  __int64 v172; // [xsp+ACh] [xbp-84h]
  __int64 v173; // [xsp+B4h] [xbp-7Ch]
  __int64 v174; // [xsp+BCh] [xbp-74h]
  __int64 v175; // [xsp+C4h] [xbp-6Ch]
  __int64 v176; // [xsp+CCh] [xbp-64h]
  __int64 v177; // [xsp+D4h] [xbp-5Ch]
  __int64 v178; // [xsp+DCh] [xbp-54h]
  __int64 v179; // [xsp+E4h] [xbp-4Ch]
  __int64 v180; // [xsp+ECh] [xbp-44h]
  __int64 v181; // [xsp+F4h] [xbp-3Ch]
  __int64 v182; // [xsp+FCh] [xbp-34h]
  __int64 v183; // [xsp+104h] [xbp-2Ch]
  __int64 v184; // [xsp+10Ch] [xbp-24h]
  __int64 v185; // [xsp+114h] [xbp-1Ch]
  int v186; // [xsp+11Ch] [xbp-14h]
  __int64 v187; // [xsp+120h] [xbp-10h]

  LOBYTE(v7) = a3;
  v187 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v13 = 20 * v10 + 240;
  v14 = (_DWORD *)_kvmalloc_node_noprof(v13, 0, 3264, 0xFFFFFFFFLL);
  if ( !v14 )
  {
LABEL_207:
    v144 = -12;
    goto LABEL_208;
  }
  while ( 1 )
  {
    if ( v13 < 4 )
      goto LABEL_206;
    *v14 = 1880096769;
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 4 )
      goto LABEL_206;
    v14[1] = 783149758;
    if ( (v7 & 0x40) != 0 )
    {
      if ( v13 < 8 )
        goto LABEL_206;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 8 )
        goto LABEL_206;
      v16 = *(_QWORD *)(a1 + 20448);
      v17 = *(unsigned int *)(a2 + 144);
      v18 = *(_QWORD *)(v16 + 24);
      v14[2] = 1883144195;
      if ( v13 < 0xC )
        goto LABEL_206;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0xC )
        goto LABEL_206;
      v14[3] = 1074268391;
      if ( v13 < 0x10 )
        goto LABEL_206;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
        goto LABEL_206;
      v19 = 32 * v17;
      v20 = v19 + v18;
      v14[4] = v20;
      if ( v13 < 0x14 )
        goto LABEL_206;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x14 )
        goto LABEL_206;
      v14[5] = HIDWORD(v20);
      if ( v13 < 0x18 )
        goto LABEL_206;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x18 )
        goto LABEL_206;
      v21 = *(_QWORD *)(v16 + 24);
      v14[6] = 1883144195;
      if ( v13 < 0x1C )
        goto LABEL_206;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x1C )
        goto LABEL_206;
      v14[7] = 1074268393;
      if ( v13 < 0x20 )
        goto LABEL_206;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x20 )
        goto LABEL_206;
      v22 = v21 + v19 + 16;
      v14[8] = v22;
      if ( v13 < 0x24 || (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x24 )
        goto LABEL_206;
      v14[9] = HIDWORD(v22);
      v15 = 10;
      if ( (v7 & 0x20) != 0 )
      {
LABEL_29:
        v23 = *(_QWORD *)(v12 + 1304);
        if ( v23 <= 0xFFFFFFFFFFFFF000LL )
        {
          v25 = *(_QWORD *)(v23 + 8);
          v26 = (unsigned int)(16 * *(_DWORD *)(v12 + 1312));
          v27 = *(_QWORD *)(a2 + 136) + 24LL;
          v28 = 4LL * v15;
          v29 = v25 + v26;
          *(_DWORD *)v29 = 1883144195;
          *(_DWORD *)(v29 + 4) = 1074268391;
          *(_QWORD *)(v29 + 8) = v27;
          if ( v13 < v28 )
            goto LABEL_206;
          if ( v13 - v28 < 4 )
            goto LABEL_206;
          v30 = &v14[v28 / 4];
          v14[v15] = 1891598339;
          if ( v13 < (v28 | 4) )
            goto LABEL_206;
          if ( v13 - (v28 | 4) < 4 )
            goto LABEL_206;
          v31 = *(_QWORD *)(v12 + 1304);
          v30[1] = v26 + *(_DWORD *)(v31 + 24);
          if ( v13 < v28 + 8 )
            goto LABEL_206;
          if ( v13 - (v28 + 8) < 4 )
            goto LABEL_206;
          v30[2] = (unsigned __int64)(*(_QWORD *)(v31 + 24) + v26) >> 32;
          if ( v13 < v28 + 12 || v13 - (v28 + 12) < 4 )
            goto LABEL_206;
          v24 = 4;
          v30[3] = 4;
          *(_DWORD *)(v12 + 1312) = (unsigned __int8)(*(_DWORD *)(v12 + 1312) + 1);
        }
        else
        {
          v24 = 0;
        }
        v15 |= v24;
      }
    }
    else
    {
      v15 = 2;
      if ( (v7 & 0x20) != 0 )
        goto LABEL_29;
    }
    if ( _X22 && (*(_BYTE *)(_X22 + 202) & 2) == 0 )
    {
      v32 = 4LL * v15;
      _CF = v13 >= v32;
      v33 = v13 - v32;
      if ( !_CF )
        goto LABEL_206;
      if ( v33 < 4 )
        goto LABEL_206;
      v34 = v15 + 1;
      v14[v15] = 1888944129;
      v35 = 4LL * (v15 + 1);
      _CF = v13 >= v35;
      v36 = v13 - v35;
      if ( !_CF || v36 < 4 )
        goto LABEL_206;
      v15 += 2;
      v14[v34] = 3;
    }
    if ( v10 )
    {
      v37 = 4LL * v15;
      _CF = v13 >= v37;
      v38 = v13 - v37;
      if ( !_CF )
        goto LABEL_206;
      if ( v38 < 4 )
        goto LABEL_206;
      v39 = 4LL * (v15 + 1);
      v14[v15] = 1894055937;
      if ( v13 < v39 || v13 - v39 < 4 )
        goto LABEL_206;
      v40 = v15 + 2;
      v41 = *(__int64 **)(a2 + 88);
      for ( v14[v15 + 1] = 13; v41 != (__int64 *)(a2 + 88); v41 = (__int64 *)*v41 )
      {
        if ( (v41[7] & 2) != 0 || (v7 & 0x80) == 0 && (v41[6] & 2) != 0 )
        {
          v42 = 4LL * v40;
          _CF = v13 >= v42;
          v44 = v13 - v42;
          if ( v40 < 0 || !_CF || v44 < 4 )
            goto LABEL_206;
          v14[v40++] = 1880096772;
        }
        v45 = 4LL * v40;
        v46 = v13 >= v45;
        v47 = v13 - v45;
        if ( v40 < 0 )
          goto LABEL_206;
        if ( !v46 )
          goto LABEL_206;
        if ( v47 < 4 )
          goto LABEL_206;
        v14[v40] = 1891598339;
        v48 = 4LL * (v40 + 1);
        v49 = v13 >= v48;
        v50 = v13 - v48;
        if ( v40 + 1 < 0 )
          goto LABEL_206;
        if ( !v49 )
          goto LABEL_206;
        if ( v50 < 4 )
          goto LABEL_206;
        v51 = 4LL * (v40 + 2);
        v14[v40 + 1] = v41[4];
        v52 = v13 >= v51;
        v53 = v13 - v51;
        if ( v40 + 2 < 0 )
          goto LABEL_206;
        if ( !v52 )
          goto LABEL_206;
        if ( v53 < 4 )
          goto LABEL_206;
        v54 = v40 + 3;
        v55 = 4LL * (v40 + 3);
        v14[v40 + 2] = *((_DWORD *)v41 + 9);
        v56 = v13 >= v55;
        v57 = v13 - v55;
        if ( v40 + 3 < 0 || !v56 || v57 < 4 )
          goto LABEL_206;
        v40 += 4;
        v14[v54] = (*((_DWORD *)v41 + 10) >> 2) & 0xFFFFF;
      }
      v58 = 4LL * v40;
      v59 = v13 >= v58;
      v60 = v13 - v58;
      if ( v40 < 0 )
        goto LABEL_206;
      if ( !v59 )
        goto LABEL_206;
      if ( v60 < 4 )
        goto LABEL_206;
      v14[v40] = 1894055937;
      v61 = 4LL * (v40 + 1);
      v62 = v13 >= v61;
      v63 = v13 - v61;
      if ( v40 + 1 < 0 || !v62 || v63 < 4 )
        goto LABEL_206;
      v15 = v40 + 2;
      v14[v40 + 1] = 14;
    }
    if ( _X22 && (*(_BYTE *)(_X22 + 202) & 2) == 0 )
    {
      v64 = 4LL * (int)v15;
      v65 = v13 >= v64;
      v66 = v13 - v64;
      if ( (v15 & 0x80000000) != 0 )
        goto LABEL_206;
      if ( !v65 )
        goto LABEL_206;
      if ( v66 < 4 )
        goto LABEL_206;
      v67 = v15 + 1;
      v14[v15] = 1888944129;
      v68 = 4LL * (int)(v15 + 1);
      v69 = v13 >= v68;
      v70 = v13 - v68;
      if ( ((v15 + 1) & 0x80000000) != 0 || !v69 || v70 < 4 )
        goto LABEL_206;
      v15 += 2;
      v14[v67] = 1;
    }
    v155 = (_QWORD *)a4;
    v71 = 4LL * (int)v15;
    v72 = v13 >= v71;
    v73 = v13 - v71;
    if ( (v15 & 0x80000000) == 0 && v72 && v73 >= 4 )
    {
      a4 = 1883635713;
      v14[v15] = 1883635713;
      v74 = 4LL * (int)(v15 + 1);
      v75 = v13 >= v74;
      v76 = v13 - v74;
      if ( ((v15 + 1) & 0x80000000) == 0 && v75 && v76 >= 4 )
      {
        v14[v15 + 1] = 24;
        v77 = 4LL * (int)(v15 + 2);
        v78 = v13 >= v77;
        v79 = v13 - v77;
        if ( ((v15 + 2) & 0x80000000) == 0 && v78 && v79 >= 4 )
        {
          v14[v15 + 2] = 1883635713;
          v80 = 4LL * (int)(v15 + 3);
          v81 = v13 >= v80;
          v82 = v13 - v80;
          if ( ((v15 + 3) & 0x80000000) == 0 && v81 && v82 >= 4 )
          {
            v83 = v15 + 4;
            v14[v15 + 3] = 25;
            if ( (v7 & 0x40) != 0 )
            {
              v84 = 4LL * v83;
              if ( v83 < 0 )
                goto LABEL_206;
              if ( v13 < v84 )
                goto LABEL_206;
              if ( v13 - v84 < 4 )
                goto LABEL_206;
              v85 = *(_QWORD *)(a1 + 20448);
              v86 = *(unsigned int *)(a2 + 144);
              v87 = &v14[v84 / 4];
              v88 = *(_QWORD *)(v85 + 24);
              v14[v84 / 4] = 1883144195;
              if ( v13 < v84 + 4 )
                goto LABEL_206;
              if ( v13 - (v84 + 4) < 4 )
                goto LABEL_206;
              v87[1] = 1074268391;
              if ( v13 < v84 + 8 )
                goto LABEL_206;
              if ( v13 - (v84 + 8) < 4 )
                goto LABEL_206;
              v89 = 32 * v86;
              v90 = v84 + 12;
              _CF = v13 >= v90;
              v91 = v13 - v90;
              v92 = v88 + v89 + 8;
              v87[2] = v92;
              if ( !_CF )
                goto LABEL_206;
              if ( v91 < 4 )
                goto LABEL_206;
              v93 = 4LL * (int)(v15 + 8);
              v87[3] = HIDWORD(v92);
              if ( ((v15 + 8) & 0x80000000) != 0 )
                goto LABEL_206;
              if ( v13 < v93 )
                goto LABEL_206;
              if ( v13 - v93 < 4 )
                goto LABEL_206;
              v94 = *(_QWORD *)(v85 + 24);
              v95 = &v14[v93 / 4];
              v14[v15 + 8] = 1883144195;
              if ( v13 < v93 + 4 )
                goto LABEL_206;
              if ( v13 - (v93 + 4) < 4 )
                goto LABEL_206;
              v95[1] = 1074268393;
              if ( v13 < v93 + 8 )
                goto LABEL_206;
              if ( v13 - (v93 + 8) < 4 )
                goto LABEL_206;
              v96 = v94 + v89 + 24;
              v95[2] = v96;
              if ( v13 < v93 + 12 || v13 - (v93 + 12) < 4 )
                goto LABEL_206;
              v95[3] = HIDWORD(v96);
              v83 = v15 + 12;
            }
            if ( (v7 & 0x20) != 0 )
            {
              v97 = *(_QWORD *)(v12 + 1304);
              if ( v97 <= 0xFFFFFFFFFFFFF000LL )
              {
                v99 = *(_QWORD *)(v97 + 8);
                v100 = (unsigned int)(16 * *(_DWORD *)(v12 + 1312));
                v101 = *(_QWORD *)(a2 + 136) + 32LL;
                v102 = 4LL * v83;
                v103 = v99 + v100;
                *(_DWORD *)v103 = 1883144195;
                *(_DWORD *)(v103 + 4) = 1074268391;
                *(_QWORD *)(v103 + 8) = v101;
                if ( v83 < 0 )
                  goto LABEL_206;
                if ( v13 < v102 )
                  goto LABEL_206;
                if ( v13 - v102 < 4 )
                  goto LABEL_206;
                v104 = &v14[v102 / 4];
                v14[v83] = 1891598339;
                if ( v13 < v102 + 4 )
                  goto LABEL_206;
                if ( v13 - (v102 + 4) < 4 )
                  goto LABEL_206;
                v105 = *(_QWORD *)(v12 + 1304);
                v104[1] = v100 + *(_DWORD *)(v105 + 24);
                if ( v13 < v102 + 8 )
                  goto LABEL_206;
                if ( v13 - (v102 + 8) < 4 )
                  goto LABEL_206;
                v104[2] = (unsigned __int64)(*(_QWORD *)(v105 + 24) + v100) >> 32;
                if ( v13 < v102 + 12 || v13 - (v102 + 12) < 4 )
                  goto LABEL_206;
                v98 = 4;
                v104[3] = 4;
                *(_DWORD *)(v12 + 1312) = (unsigned __int8)(*(_DWORD *)(v12 + 1312) + 1);
              }
              else
              {
                v98 = 0;
              }
              v83 += v98;
            }
            v106 = 4LL * v83;
            v107 = v13 >= v106;
            v108 = v13 - v106;
            if ( (v83 & 0x80000000) == 0 && v107 && v108 >= 4 )
            {
              v7 = v83;
              v14[v83] = 1880096769;
              v109 = 4LL * (v83 + 1);
              v110 = v13 >= v109;
              v111 = v13 - v109;
              if ( ((v83 + 1) & 0x80000000) == 0 && v110 && v111 >= 4 )
                break;
            }
          }
        }
      }
    }
LABEL_206:
    __break(1u);
    v156 = a4;
    StatusReg = _ReadStatusReg(SP_EL0);
    v147 = *(_QWORD *)(StatusReg + 80);
    v13 = 20 * v10 + 240;
    *(_QWORD *)(StatusReg + 80) = &gen8_ringbuffer_submitcmd__alloc_tag;
    v14 = (_DWORD *)_kvmalloc_node_noprof(v13, 0, 3264, 0xFFFFFFFFLL);
    *(_QWORD *)(StatusReg + 80) = v147;
    a4 = v156;
    if ( !v14 )
      goto LABEL_207;
  }
  v14[v83 + 1] = 717151917;
  if ( *(_QWORD *)(v12 + 176) == _X22 )
    goto LABEL_203;
  if ( !_X22 || (*(_QWORD *)(_X22 + 32) & 2) != 0 )
    goto LABEL_205;
  v112 = *(_DWORD *)_X22;
  if ( *(_DWORD *)_X22 )
  {
    do
    {
      __asm { PRFM            #0x11, [X22] }
      do
        v118 = __ldxr((unsigned int *)_X22);
      while ( v118 == v112 && __stxr(v112 + 1, (unsigned int *)_X22) );
      v113 = v112;
      if ( v118 == v112 )
        break;
      v113 = 0;
      v112 = v118;
    }
    while ( v118 );
  }
  else
  {
    v113 = 0;
  }
  if ( (((v113 + 1) | v113) & 0x80000000) != 0 )
  {
    v154 = v14;
    refcount_warn_saturate(_X22, 0);
    v14 = v154;
    if ( !v113 )
      goto LABEL_205;
LABEL_175:
    v119 = *(_QWORD *)(_X22 + 24);
    v162 = 0;
    v161 = 0;
    v120 = *(_QWORD *)(v119 + 64);
    v186 = 0;
    v185 = 0;
    v184 = 0;
    v183 = 0;
    v157[0] = 1888944129;
    v157[1] = -2147483645;
    v182 = 0;
    v181 = 0;
    v180 = 0;
    v179 = 0;
    v178 = 0;
    v177 = 0;
    v157[2] = 1881079809;
    v157[3] = 15;
    v157[4] = 1888944129;
    v157[5] = -2147483647;
    v121 = *(_QWORD *)(v12 + 176);
    v163 = 0;
    v176 = 0;
    v175 = 0;
    v174 = 0;
    v173 = 0;
    v172 = 0;
    v171 = 0;
    v170 = 0;
    v169 = 0;
    v168 = 0;
    v167 = 0;
    v166 = 0;
    v165 = 0;
    v164 = 0;
    v160 = 0;
    v159 = 0;
    v158 = 0;
    if ( v121 )
      v121 = *(_QWORD *)(*(_QWORD *)(v121 + 24) + 64LL);
    if ( v121 == v120 )
    {
      v124 = (*(_DWORD *)(a1 + 1020) >> 2) + 163853;
      LODWORD(v158) = (((0x9669u >> ((BYTE1(v124)
                                    ^ (v124 >> 4)
                                    ^ (v124 >> 12)
                                    ^ BYTE2(v124)
                                    ^ (v124 >> 20)
                                    ^ HIBYTE(v124)
                                    ^ (v124 >> 28)
                                    ^ v124)
                                   & 0xF))
                      & 1) << 27)
                    | ((v124 & 0x3FFFF) << 8)
                    | 0x40000001;
      HIDWORD(v158) = *(_DWORD *)(_X22 + 4);
      v125 = 8;
    }
    else
    {
      v158 = 0x370970001LL;
      v159 = 0x2670460001LL;
      v122 = *(_BYTE *)(a1 + 23968);
      v160 = 0x8000000170970001LL;
      if ( (v122 & 1) != 0 )
      {
        v123 = 12;
      }
      else
      {
        v123 = 16;
        v161 = 0x148044901LL;
        v162 = 0x14805E801LL;
      }
      if ( v120 )
      {
        v126 = *(_QWORD *)(v120 + 96);
        if ( v126 )
        {
          v126 = *(_QWORD *)(v126 + 48);
          if ( v126 )
          {
            v153 = v14;
            v152 = v123;
            if ( *(_DWORD *)(v126 - 4) != 1831526433 )
              __break(0x8228u);
            v127 = ((__int64 (__fastcall *)(__int64, __int64, __int64))v126)(v120, 1883144195, 1888944129);
            v123 = v152;
            v126 = v127;
            v14 = v153;
          }
        }
      }
      else
      {
        v126 = 0;
      }
      if ( *(_QWORD *)(a1 + 72) == v120 )
      {
        v133 = 0;
      }
      else
      {
        v128 = *(_DWORD *)(_X22 + 4);
        v129 = &v157[v123];
        *v129 = 1892909059;
        *(_QWORD *)(v129 + 1) = v126;
        v129[3] = v128;
        v129[4] = 1883078661;
        v130 = *(_QWORD *)(a1 + 48);
        v131 = (32LL * *(int *)(v12 + 28)) | 0x10;
        v129[5] = v131 + *(_DWORD *)(v130 + 24);
        v132 = *(_QWORD *)(v130 + 24);
        v129[8] = HIDWORD(v126);
        v129[9] = v128;
        v129[6] = (unsigned __int64)(v131 + v132) >> 32;
        v129[7] = v126;
        v129[10] = 1888944129;
        v129[11] = -2147483647;
        v133 = 12;
      }
      v125 = v133 + v123;
      if ( (*(_BYTE *)(a1 + 23968) & 1) == 0 )
      {
        v157[v125] = 1891401734;
        v157[v125 | 1] = 3;
        v157[v125 | 2] = 415;
        v157[v125 | 3] = 0;
        v157[v125 + 4] = 1;
        v157[v125 + 5] = 1;
        v134 = v125 + 6;
        v125 += 7;
        v157[v134] = 0;
      }
    }
    v157[v125] = 1880096769;
    v157[v125 + 1] = 783138543;
    v157[v125 + 2] = 1883078659;
    v135 = *(_QWORD *)(a1 + 40);
    v136 = v125 + 12;
    v137 = 40LL * *(int *)(v12 + 28);
    v157[v125 + 3] = *(_DWORD *)(v135 + 24) + 32552 + v137;
    v157[v125 + 4] = (unsigned __int64)(v137 + *(_QWORD *)(v135 + 24) + 32552LL) >> 32;
    v138 = *(_DWORD *)(_X22 + 4);
    v157[v125 + 6] = 1883078659;
    v157[v125 + 5] = v138;
    v157[v125 + 7] = *(_DWORD *)(v135 + 24) + 32;
    v139 = *(_QWORD *)(v135 + 24);
    v157[v125 + 9] = v138;
    v157[v125 + 10] = 1883635713;
    v157[v125 + 8] = (unsigned __int64)(v139 + 32) >> 32;
    v157[v125 + 11] = 49;
    if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0 && (v140 = *(_QWORD *)(_X22 + 272)) != 0 )
    {
      v141 = *(_QWORD *)(v140 + 32);
      v142 = v14;
      v157[v136] = 1893105667;
      v136 = v125 + 16;
      v157[v125 + 13] = 3;
      v157[v125 + 14] = v141;
      v157[v125 + 15] = HIDWORD(v141);
    }
    else
    {
      v142 = v14;
    }
    v143 = gen8_ringbuffer_addcmds(a1, v12, 0, 1, v157, v136, 0, nullptr);
    if ( v143 )
    {
      v144 = v143;
      __asm { PRFM            #0x11, [X22] }
      do
        v150 = __ldxr((unsigned int *)_X22);
      while ( __stlxr(v150 - 1, (unsigned int *)_X22) );
      if ( v150 == 1 )
      {
        __dmb(9u);
        kgsl_context_destroy(_X22);
      }
      else
      {
        v14 = v142;
        if ( v150 > 0 )
          goto LABEL_212;
        refcount_warn_saturate(_X22, 3);
      }
      v14 = v142;
LABEL_212:
      if ( v144 != -28 && v144 != -2 )
      {
        v151 = v14;
        dev_err(*(_QWORD *)a1, "Unable to switch draw context: %d\n", v144);
        v14 = v151;
      }
      goto LABEL_208;
    }
    adreno_put_drawctxt_on_timestamp(a1, *(unsigned int **)(v12 + 176), v12, *(_DWORD *)(v12 + 36));
    v14 = v142;
    *(_QWORD *)(v12 + 176) = _X22;
LABEL_203:
    v145 = v14;
    adreno_drawobj_set_constraint(a1, a2);
    v144 = gen8_ringbuffer_addcmds(a1, *(_QWORD *)(_X22 + 1536), _X22, a3, v145, v7 + 2, *(_DWORD *)(a2 + 20), v155);
    v14 = v145;
    goto LABEL_208;
  }
  if ( v113 )
    goto LABEL_175;
LABEL_205:
  v144 = -2;
LABEL_208:
  kvfree(v14);
  _ReadStatusReg(SP_EL0);
  return v144;
}
