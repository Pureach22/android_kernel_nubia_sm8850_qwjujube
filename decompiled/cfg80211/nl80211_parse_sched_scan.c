__int64 __fastcall nl80211_parse_sched_scan(__int64 a1, unsigned __int16 *a2, _QWORD *a3, int a4)
{
  _WORD *v7; // x8
  unsigned __int16 *v8; // x8
  __int16 v9; // t1
  unsigned int v10; // w9
  unsigned __int16 *v11; // x10
  int v12; // w11
  unsigned int v13; // w12
  bool v14; // cc
  unsigned __int16 *v15; // x24
  unsigned __int16 *v16; // x10
  int v17; // w11
  __int64 v18; // x12
  unsigned int v19; // w12
  unsigned __int16 *v20; // x13
  int v21; // w14
  __int64 v22; // x15
  unsigned int v23; // w15
  unsigned __int64 v24; // x28
  _WORD *v25; // x9
  int v26; // w8
  __int64 v27; // x25
  unsigned __int16 *v28; // x9
  unsigned int v29; // w10
  __int64 v30; // x10
  _WORD *v31; // x8
  int v32; // w26
  unsigned int v33; // w23
  unsigned __int16 *v34; // x27
  __int64 v35; // x8
  unsigned int v36; // w9
  __int64 result; // x0
  __int64 v39; // x26
  _WORD *v40; // x8
  unsigned __int16 v41; // w8
  size_t v42; // x13
  _WORD *v43; // x9
  __int64 v44; // x8
  int v45; // w8
  int v46; // w21
  unsigned __int16 *v47; // x9
  unsigned int v48; // w10
  __int64 v49; // x10
  __int64 v50; // x10
  __int64 v51; // x22
  __int64 v52; // x27
  __int64 v53; // x9
  __int64 v54; // x8
  bool v55; // cf
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x9
  __int64 v59; // x8
  unsigned __int64 v60; // x8
  unsigned __int64 v61; // x23
  __int64 v62; // x1
  char v63; // w10
  __int64 v64; // x9
  __int64 v65; // x9
  __int64 v66; // x8
  __int64 v67; // x9
  __int64 v68; // x8
  unsigned __int64 v69; // x9
  unsigned __int64 v70; // x9
  _WORD *v71; // x8
  __int64 v72; // x8
  unsigned int v73; // w8
  __int64 channel_khz; // x0
  unsigned __int64 v75; // x8
  __int64 v76; // x12
  __int64 v77; // x8
  __int64 v78; // x10
  int v79; // w9
  __int64 v80; // x11
  char *v81; // x13
  char *v82; // x13
  char v83; // t1
  unsigned __int64 v84; // x12
  __int64 v85; // x12
  __int64 v86; // x10
  __int64 i; // x11
  __int64 v88; // x13
  unsigned __int64 v89; // x12
  __int64 v90; // x12
  __int64 v91; // x10
  __int64 j; // x11
  __int64 v93; // x13
  unsigned __int64 v94; // x12
  __int64 v95; // x12
  __int64 v96; // x10
  __int64 k; // x11
  __int64 v98; // x13
  unsigned __int64 v99; // x12
  __int64 v100; // x12
  __int64 v101; // x10
  __int64 m; // x11
  __int64 v103; // x13
  unsigned __int64 v104; // x12
  __int64 v105; // x12
  __int64 v106; // x10
  __int64 v107; // x11
  __int64 v108; // x13
  unsigned __int64 v109; // x12
  _WORD *v110; // x8
  _BOOL4 v111; // w12
  unsigned int v112; // w8
  unsigned int v113; // w9
  __int64 v114; // x8
  size_t v115; // x2
  _BOOL4 v116; // w23
  __int64 v117; // x8
  _WORD *v118; // x8
  _BOOL4 v119; // w9
  __int64 v120; // x8
  unsigned int v121; // w9
  int v122; // w0
  __int64 v123; // x11
  size_t v124; // x2
  __int64 v125; // x9
  __int16 v126; // w10
  int v127; // w11
  int v128; // w8
  size_t v129; // x1
  int *v130; // x9
  int v131; // w10
  int v132; // w11
  int v133; // t1
  __int64 v134; // x22
  __int64 v135; // x8
  __int64 v136; // x8
  char v137; // w8
  __int64 v138; // x8
  unsigned int v139; // w9
  size_t v140; // [xsp+10h] [xbp-80h]
  __int64 v141; // [xsp+18h] [xbp-78h]
  __int64 v142; // [xsp+18h] [xbp-78h]
  char v143; // [xsp+20h] [xbp-70h]
  unsigned __int64 StatusReg; // [xsp+20h] [xbp-70h]
  unsigned __int64 v145; // [xsp+28h] [xbp-68h]
  __int64 v146; // [xsp+30h] [xbp-60h]
  unsigned __int64 v147; // [xsp+30h] [xbp-60h]
  __int64 v148; // [xsp+30h] [xbp-60h]
  size_t n; // [xsp+38h] [xbp-58h]
  __int64 v150; // [xsp+40h] [xbp-50h]
  int v151; // [xsp+4Ch] [xbp-44h]
  __int64 v152; // [xsp+50h] [xbp-40h] BYREF
  unsigned __int64 v153; // [xsp+58h] [xbp-38h]
  __int64 v154; // [xsp+60h] [xbp-30h]
  __int64 v155; // [xsp+68h] [xbp-28h]
  __int64 v156; // [xsp+70h] [xbp-20h]
  __int64 v157; // [xsp+78h] [xbp-18h]
  __int64 v158; // [xsp+80h] [xbp-10h]
  __int64 v159; // [xsp+88h] [xbp-8h]

  v159 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = (_WORD *)a3[44];
  v157 = 0;
  v158 = 0;
  v155 = 0;
  v156 = 0;
  v153 = 0;
  v154 = 0;
  v152 = 0;
  if ( v7 )
  {
    v9 = *v7;
    v8 = v7 + 2;
    v10 = (unsigned __int16)(v9 - 4);
    if ( v10 < 4 )
      goto LABEL_72;
    v11 = v8;
    v12 = v10;
    do
    {
      v13 = *v11;
      if ( v13 < 4 || v12 < v13 )
        break;
      if ( v13 != 8 )
        goto LABEL_72;
      v14 = v12 <= 11;
      v12 -= 8;
      v11 += 4;
    }
    while ( !v14 );
    LODWORD(v15) = 0;
    v16 = v8;
    v17 = v10;
    do
    {
      v19 = *v16;
      if ( v19 < 4 || v17 < v19 )
        break;
      LODWORD(v15) = (_DWORD)v15 + 1;
      v20 = v8;
      v21 = v10;
      do
      {
        v23 = *v20;
        if ( v23 < 4 || v21 < v23 )
          break;
        if ( v16 != v20 && *((_DWORD *)v16 + 1) == *((_DWORD *)v20 + 1) )
          goto LABEL_72;
        v22 = (v23 + 3) & 0x1FFFC;
        v21 -= v22;
        v20 = (unsigned __int16 *)((char *)v20 + v22);
      }
      while ( v21 > 3 );
      v18 = (v19 + 3) & 0x1FFFC;
      v17 -= v18;
      v16 = (unsigned __int16 *)((char *)v16 + v18);
    }
    while ( v17 > 3 );
    v24 = (unsigned __int64)a2;
    if ( !(_DWORD)v15 )
      goto LABEL_72;
  }
  else
  {
    v24 = (unsigned __int64)a2;
    LODWORD(v15) = ieee80211_get_num_supported_channels(a1);
  }
  v25 = (_WORD *)a3[45];
  if ( v25 && (v26 = (unsigned __int16)(*v25 - 4), (unsigned int)v26 >= 4) )
  {
    LODWORD(v27) = 0;
    v28 = v25 + 2;
    do
    {
      v29 = *v28;
      if ( v29 < 4 )
        break;
      if ( v26 < v29 )
        break;
      LODWORD(v27) = v27 + 1;
      v30 = (v29 + 3) & 0x1FFFC;
      v26 -= v30;
      v28 = (unsigned __int16 *)((char *)v28 + v30);
    }
    while ( v26 > 3 );
    if ( (int)v27 > *(unsigned __int8 *)(a1 + 138) )
      goto LABEL_72;
    v31 = (_WORD *)a3[132];
    if ( !v31 )
    {
LABEL_43:
      v33 = 0;
      v151 = -300;
LABEL_44:
      if ( v151 != -300 && v33 == 0 )
        v39 = 1;
      else
        v39 = v33;
      if ( (int)v39 > a4 )
        goto LABEL_72;
      v40 = (_WORD *)a3[42];
      if ( v40 )
      {
        v41 = *v40 - 4;
        if ( *(unsigned __int16 *)(a1 + 142) < (unsigned int)v41 )
          goto LABEL_72;
        v42 = v41;
      }
      else
      {
        v42 = 0;
      }
      v43 = (_WORD *)a3[225];
      v44 = a3[119];
      if ( v43 )
      {
        if ( v44 )
          goto LABEL_72;
        v45 = (unsigned __int16)(*v43 - 4);
        if ( (unsigned int)v45 < 4 )
          goto LABEL_72;
        v46 = 0;
        v47 = v43 + 2;
        do
        {
          v48 = *v47;
          if ( v48 < 4 )
            break;
          if ( v45 < v48 )
            break;
          ++v46;
          v49 = (v48 + 3) & 0x1FFFC;
          v45 -= v49;
          v47 = (unsigned __int16 *)((char *)v47 + v49);
        }
        while ( v45 > 3 );
        if ( !v46 )
          goto LABEL_72;
        goto LABEL_68;
      }
      if ( v44 )
      {
        v46 = 1;
LABEL_68:
        if ( (unsigned int)v46 > *(_DWORD *)(a1 + 144) || (*(_BYTE *)(a1 + 113) & 0x10) == 0 && (a3[246] || a3[247]) )
          goto LABEL_72;
        v50 = 8LL * (int)v15 + 192;
        v51 = 33LL * (int)v27;
        n = v42;
        LODWORD(v150) = v39;
        if ( (unsigned __int64)(8LL * (int)v15) >= 0xFFFFFFFFFFFFFF40LL )
          v50 = -1;
        if ( (int)v15 < 0 )
          v52 = -1;
        else
          v52 = v50;
        v53 = 44LL * (int)v39;
        if ( is_mul_ok((int)v27, 0x21u) )
          v54 = 33LL * (int)v27;
        else
          v54 = -1;
        v55 = __CFADD__(v52, v54);
        v56 = v52 + v54;
        if ( v55 )
          v56 = -1;
        if ( !is_mul_ok((int)v39, 0x2Cu) )
          v53 = -1;
        v55 = __CFADD__(v56, v53);
        v57 = v56 + v53;
        v58 = 8LL * v46;
        if ( v55 )
          v57 = -1;
        if ( v46 < 0 )
          v58 = -1;
        v55 = __CFADD__(v57, v58);
        v59 = v57 + v58;
        if ( v55 )
          v59 = -1;
        v55 = __CFADD__(v59, v42);
        v60 = v59 + v42;
        if ( v55 )
          v61 = -1;
        else
          v61 = v60;
        result = _kmalloc_noprof(v61, 3520);
        if ( !result )
        {
LABEL_312:
          result = -12;
          goto LABEL_73;
        }
        while ( 1 )
        {
          if ( v61 < 0x14 || (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x14 )
            goto LABEL_311;
          v62 = v24;
          *(_DWORD *)(result + 20) = (_DWORD)v15;
          if ( (_DWORD)v27 )
          {
            if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 8 )
              goto LABEL_311;
            *(_QWORD *)(result + 8) = result + v52;
            if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
              goto LABEL_311;
            *(_DWORD *)(result + 16) = v27;
            if ( n )
            {
              if ( v61 < 0x18 || (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
                goto LABEL_311;
              v63 = 0;
              v64 = result + v52 + v51;
              goto LABEL_114;
            }
          }
          else
          {
            if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
              goto LABEL_311;
            *(_DWORD *)(result + 16) = 0;
            if ( n )
            {
              if ( v61 < 0x18 || (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
                goto LABEL_311;
              v63 = 0;
              v64 = result + 8LL * (int)v15 + 192;
LABEL_114:
              *(_QWORD *)(result + 24) = v64;
              goto LABEL_116;
            }
          }
          v63 = 1;
LABEL_116:
          if ( !(_DWORD)v39 )
          {
            if ( v61 < 0x38 )
              goto LABEL_311;
            if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x38 )
              goto LABEL_311;
            *(_DWORD *)(result + 56) = 0;
            if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
              goto LABEL_311;
            v67 = *(_QWORD *)(result + 24);
            if ( v67 )
            {
              if ( v61 < 0x48 || (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
                goto LABEL_311;
              v68 = v67 + n;
            }
            else
            {
              v70 = v61 & 0xFFFFFFFFFFFFFFF8LL;
              if ( (_DWORD)v27 )
              {
                if ( v70 == 8 || v61 < 0x48 || (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x48 )
                  goto LABEL_311;
                v68 = *(_QWORD *)(result + 8) + v51;
              }
              else
              {
                if ( v61 < 0x48 || v70 == 72 )
                  goto LABEL_311;
                v68 = result + 8LL * (int)v15 + 192;
              }
            }
LABEL_148:
            *(_QWORD *)(result + 72) = v68;
            if ( v61 < 0x50 || (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x50 )
              goto LABEL_311;
            v71 = (_WORD *)a3[44];
            *(_DWORD *)(result + 80) = v46;
            v150 = result;
            if ( v71 )
            {
              LODWORD(v15) = (unsigned __int16)(*v71 - 4);
              if ( (unsigned int)v15 < 4 )
                goto LABEL_266;
              v51 = 0;
              v52 = (__int64)(v71 + 2);
              v143 = v63;
              v146 = result + 192;
              do
              {
                v73 = *(unsigned __int16 *)v52;
                if ( v73 < 4 || (unsigned int)v15 < v73 )
                  break;
                v24 = v62;
                channel_khz = ieee80211_get_channel_khz(a1, (unsigned int)(1000 * *(_DWORD *)(v52 + 4)));
                if ( !channel_khz )
                {
LABEL_265:
                  result = v150;
                  goto LABEL_266;
                }
                if ( (*(_BYTE *)(channel_khz + 12) & 1) != 0 )
                {
                  v62 = v24;
                }
                else
                {
                  if ( (int)v51 < -24 )
                    goto LABEL_311;
                  v75 = 8LL * (int)v51 + 192;
                  if ( v61 < v75 || v61 - v75 < 8 )
                    goto LABEL_311;
                  v62 = v24;
                  *(_QWORD *)(v146 + 8LL * (int)v51) = channel_khz;
                  v51 = (unsigned int)(v51 + 1);
                }
                result = v150;
                v72 = (*(unsigned __int16 *)v52 + 3) & 0x1FFFC;
                LODWORD(v15) = (_DWORD)v15 - v72;
                v52 += v72;
              }
              while ( (int)v15 > 3 );
            }
            else
            {
              v76 = *(_QWORD *)(a1 + 328);
              v77 = result + 192;
              v143 = v63;
              if ( v76 && *(int *)(v76 + 20) >= 1 )
              {
                v78 = 0;
                v79 = 0;
                v80 = 12;
                while ( 1 )
                {
                  v81 = (char *)(*(_QWORD *)v76 + v80);
                  v83 = *v81;
                  v82 = v81 - 12;
                  if ( (v83 & 1) == 0 )
                  {
                    if ( v79 < -24 )
                      goto LABEL_311;
                    v84 = 8LL * v79 + 192;
                    if ( v61 < v84 || v61 - v84 < 8 )
                      goto LABEL_311;
                    v76 = *(_QWORD *)(a1 + 328);
                    *(_QWORD *)(v77 + 8LL * v79++) = v82;
                  }
                  ++v78;
                  v80 += 64;
                  if ( v78 >= *(int *)(v76 + 20) )
                    goto LABEL_173;
                }
              }
              v79 = 0;
LABEL_173:
              v85 = *(_QWORD *)(a1 + 336);
              if ( v85 && *(int *)(v85 + 20) >= 1 )
              {
                v86 = 0;
                for ( i = 0; i < *(int *)(v85 + 20); ++i )
                {
                  v88 = *(_QWORD *)v85 + v86;
                  if ( (*(_BYTE *)(v88 + 12) & 1) == 0 )
                  {
                    if ( v79 < -24 )
                      goto LABEL_311;
                    v89 = 8LL * v79 + 192;
                    if ( v61 < v89 || v61 - v89 < 8 )
                      goto LABEL_311;
                    v85 = *(_QWORD *)(a1 + 336);
                    *(_QWORD *)(v77 + 8LL * v79++) = v88;
                  }
                  v86 += 64;
                }
              }
              v90 = *(_QWORD *)(a1 + 344);
              if ( v90 && *(int *)(v90 + 20) >= 1 )
              {
                v91 = 0;
                for ( j = 0; j < *(int *)(v90 + 20); ++j )
                {
                  v93 = *(_QWORD *)v90 + v91;
                  if ( (*(_BYTE *)(v93 + 12) & 1) == 0 )
                  {
                    if ( v79 < -24 )
                      goto LABEL_311;
                    v94 = 8LL * v79 + 192;
                    if ( v61 < v94 || v61 - v94 < 8 )
                      goto LABEL_311;
                    v90 = *(_QWORD *)(a1 + 344);
                    *(_QWORD *)(v77 + 8LL * v79++) = v93;
                  }
                  v91 += 64;
                }
              }
              v95 = *(_QWORD *)(a1 + 352);
              if ( v95 && *(int *)(v95 + 20) >= 1 )
              {
                v96 = 0;
                for ( k = 0; k < *(int *)(v95 + 20); ++k )
                {
                  v98 = *(_QWORD *)v95 + v96;
                  if ( (*(_BYTE *)(v98 + 12) & 1) == 0 )
                  {
                    if ( v79 < -24 )
                      goto LABEL_311;
                    v99 = 8LL * v79 + 192;
                    if ( v61 < v99 || v61 - v99 < 8 )
                      goto LABEL_311;
                    v95 = *(_QWORD *)(a1 + 352);
                    *(_QWORD *)(v77 + 8LL * v79++) = v98;
                  }
                  v96 += 64;
                }
              }
              v100 = *(_QWORD *)(a1 + 360);
              if ( v100 && *(int *)(v100 + 20) >= 1 )
              {
                v101 = 0;
                for ( m = 0; m < *(int *)(v100 + 20); ++m )
                {
                  v103 = *(_QWORD *)v100 + v101;
                  if ( (*(_BYTE *)(v103 + 12) & 1) == 0 )
                  {
                    if ( v79 < -24 )
                      goto LABEL_311;
                    v104 = 8LL * v79 + 192;
                    if ( v61 < v104 || v61 - v104 < 8 )
                      goto LABEL_311;
                    v100 = *(_QWORD *)(a1 + 360);
                    *(_QWORD *)(v77 + 8LL * v79++) = v103;
                  }
                  v101 += 64;
                }
              }
              v105 = *(_QWORD *)(a1 + 368);
              if ( v105 && *(int *)(v105 + 20) >= 1 )
              {
                v106 = 0;
                v107 = 0;
                while ( 1 )
                {
                  v108 = *(_QWORD *)v105 + v106;
                  if ( (*(_BYTE *)(v108 + 12) & 1) == 0 )
                  {
                    if ( v79 < -24 )
                      goto LABEL_311;
                    v109 = 8LL * v79 + 192;
                    if ( v61 < v109 || v61 - v109 < 8 )
                      goto LABEL_311;
                    v105 = *(_QWORD *)(a1 + 368);
                    *(_QWORD *)(v77 + 8LL * v79++) = v108;
                  }
                  ++v107;
                  v106 += 64;
                  v51 = (unsigned int)v79;
                  if ( v107 >= *(int *)(v105 + 20) )
                    goto LABEL_222;
                }
              }
              v51 = (unsigned int)v79;
            }
LABEL_222:
            if ( !(_DWORD)v51 )
              goto LABEL_266;
            if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x14 )
              goto LABEL_311;
            *(_DWORD *)(result + 20) = v51;
            if ( (_DWORD)v27 )
            {
              v110 = (_WORD *)a3[45];
              v51 = (unsigned __int16)(*v110 - 4);
              if ( (unsigned int)v51 >= 4 )
              {
                LODWORD(v15) = 0;
                v24 = (unsigned __int64)(v110 + 2);
                v145 = v61;
                v147 = v61 & 0xFFFFFFFFFFFFFFF8LL;
                v111 = (v61 & 0xFFFFFFFFFFFFFFF8LL) == 8;
                do
                {
                  v112 = *(unsigned __int16 *)v24;
                  v113 = v112 - 4;
                  if ( v112 < 4 || (unsigned int)v51 < v112 )
                    break;
                  if ( v113 > 0x20 )
                    goto LABEL_265;
                  v114 = v150;
                  if ( v111 )
                    goto LABEL_311;
                  v27 = 33LL * (int)v15;
                  *(_BYTE *)(*(_QWORD *)(v150 + 8) + v27 + 32) = v113;
                  if ( v147 == 8 )
                    goto LABEL_311;
                  v115 = (unsigned __int16)(*(_WORD *)v24 - 4);
                  if ( (unsigned int)v115 < 0x21 || (nl80211_parse_sched_scan___already_done & 1) != 0 )
                  {
                    if ( v111 )
                      goto LABEL_311;
                  }
                  else
                  {
                    v141 = v62;
                    v52 = (unsigned __int16)(*(_WORD *)v24 - 4);
                    nl80211_parse_sched_scan___already_done = 1;
                    v61 = v111;
                    _warn_printk(
                      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                      v115,
                      "field \"request->ssids[i].ssid\" at ../soc-repo/net/wireless/nl80211.c:9944",
                      0x20u);
                    v114 = v150;
                    v62 = v141;
                    v111 = v61;
                    v115 = v52;
                    __break(0x800u);
                    if ( (v61 & 1) != 0 )
                      goto LABEL_311;
                  }
                  v52 = v62;
                  v116 = v111;
                  memcpy((void *)(*(_QWORD *)(v114 + 8) + v27), (const void *)(v24 + 4), v115);
                  v111 = v116;
                  v61 = v145;
                  LODWORD(v15) = (_DWORD)v15 + 1;
                  v62 = v52;
                  v117 = (*(unsigned __int16 *)v24 + 3) & 0x1FFFC;
                  v51 = (unsigned int)(v51 - v117);
                  v24 += v117;
                }
                while ( (int)v51 > 3 );
              }
            }
            v118 = (_WORD *)a3[132];
            if ( v118 )
            {
              result = v150;
              v51 = (unsigned __int16)(*v118 - 4);
              v119 = 1;
              if ( (unsigned int)v51 >= 4 )
              {
                LODWORD(v27) = 0;
                v15 = v118 + 2;
                while ( 1 )
                {
                  v121 = *v15;
                  if ( v121 < 4 || (unsigned int)v51 < v121 )
                  {
LABEL_269:
                    v119 = v27 == 0;
                    break;
                  }
                  v52 = v62;
                  v122 = _nla_parse(&v152, 6, v15 + 2, (unsigned __int16)(v121 - 4), &nl80211_match_policy, 0, 0);
                  if ( v122 )
                  {
                    LODWORD(v24) = v122;
                    result = v150;
                    goto LABEL_287;
                  }
                  v24 = v153;
                  v123 = v157;
                  v62 = v52;
                  result = v150;
                  if ( v153 | v157 )
                  {
                    if ( (int)v27 >= (int)v39 )
                    {
                      __break(0x800u);
                      goto LABEL_266;
                    }
                    if ( v153 )
                    {
                      v142 = v157;
                      if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                        goto LABEL_311;
                      v124 = (unsigned __int16)(*(_WORD *)v153 - 4);
                      if ( (unsigned int)v124 < 0x21 || (nl80211_parse_sched_scan___already_done_88 & 1) != 0 )
                      {
                        if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                          goto LABEL_311;
                      }
                      else
                      {
                        v129 = (unsigned __int16)(*(_WORD *)v153 - 4);
                        v140 = v129;
                        nl80211_parse_sched_scan___already_done_88 = 1;
                        _warn_printk(
                          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                          v129,
                          "field \"request->match_sets[i].ssid.ssid\" at ../soc-repo/net/wireless/nl80211.c:9982",
                          0x20u);
                        v124 = v140;
                        result = v150;
                        __break(0x800u);
                        if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                          goto LABEL_311;
                      }
                      memcpy((void *)(*(_QWORD *)(result + 48) + 44LL * (int)v27), (const void *)(v24 + 4), v124);
                      if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                        goto LABEL_311;
                      result = v150;
                      v62 = v52;
                      v123 = v142;
                      *(_BYTE *)(*(_QWORD *)(v150 + 48) + 44LL * (int)v27 + 32) = *(_BYTE *)v24 - 4;
                    }
                    if ( v123 )
                    {
                      if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                        goto LABEL_311;
                      v125 = *(_QWORD *)(result + 48) + 44LL * (int)v27;
                      v126 = *(_WORD *)(v123 + 8);
                      v127 = *(_DWORD *)(v123 + 4);
                      v128 = v27;
                      *(_WORD *)(v125 + 37) = v126;
                      *(_DWORD *)(v125 + 33) = v127;
                    }
                    else
                    {
                      v128 = v27;
                    }
                    if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                      goto LABEL_311;
                    *(_DWORD *)(*(_QWORD *)(result + 48) + 44LL * v128 + 40) = v151;
                    if ( v154 )
                    {
                      if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                        goto LABEL_311;
                      *(_DWORD *)(*(_QWORD *)(result + 48) + 44LL * v128 + 40) = *(_DWORD *)(v154 + 4);
                    }
                  }
                  LODWORD(v27) = v27 + 1;
                  v120 = (*v15 + 3) & 0x1FFFC;
                  v51 = (unsigned int)(v51 - v120);
                  v15 = (unsigned __int16 *)((char *)v15 + v120);
                  if ( (int)v51 <= 3 )
                    goto LABEL_269;
                }
              }
              if ( (_DWORD)v39 && v119 )
              {
                if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                  goto LABEL_311;
                *(_DWORD *)(*(_QWORD *)(result + 48) + 40LL) = v151;
              }
              if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x3C )
                goto LABEL_311;
              *(_DWORD *)(result + 60) = 0x7FFFFFFF;
              if ( (int)v39 >= 1 )
              {
                if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) != 0x30 )
                {
                  v130 = (int *)(*(_QWORD *)(result + 48) + 40LL);
                  v131 = 0x7FFFFFFF;
                  while ( (v61 & 0xFFFFFFFFFFFFFFFCLL) != 0x3C )
                  {
                    v133 = *v130;
                    v130 += 11;
                    v132 = v133;
                    if ( v133 < v131 )
                      v131 = v132;
                    --v39;
                    *(_DWORD *)(result + 60) = v131;
                    if ( !v39 )
                      goto LABEL_282;
                  }
                }
                goto LABEL_311;
              }
            }
            else
            {
              if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x3C )
                goto LABEL_311;
              *(_DWORD *)(v150 + 60) = -300;
            }
LABEL_282:
            if ( (v143 & 1) == 0 )
            {
              if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x20 )
                goto LABEL_311;
              *(_QWORD *)(v150 + 32) = n;
              if ( (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
                goto LABEL_311;
              v134 = v62;
              memcpy(*(void **)(v150 + 24), (const void *)(a3[42] + 4LL), n);
              v62 = v134;
            }
            v51 = v150;
            v24 = (unsigned int)nl80211_check_scan_flags((_BYTE *)a1, v62, v150, (__int64)a3, 1);
            result = v150;
            if ( (_DWORD)v24 )
              goto LABEL_287;
            v135 = a3[220];
            if ( v135 )
            {
              if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x40 )
                goto LABEL_311;
              *(_DWORD *)(v150 + 64) = *(_DWORD *)(v135 + 4);
            }
            v136 = a3[246];
            if ( v136 )
            {
              if ( v61 < 0x62 )
                goto LABEL_311;
              v137 = *(_BYTE *)(v136 + 4);
              *(_BYTE *)(v150 + 96) = 1;
              *(_BYTE *)(v150 + 97) = v137;
LABEL_299:
              v138 = a3[247];
              if ( v138 )
              {
                if ( v61 < 0x64 )
                  goto LABEL_311;
                if ( (v61 & 0xFFFFFFFFFFFFFFFCLL) == 0x64 )
                  goto LABEL_311;
                v139 = *(unsigned __int8 *)(v138 + 4);
                *(_DWORD *)(v150 + 100) = v139;
                if ( v61 < 0x69 )
                  goto LABEL_311;
                *(_BYTE *)(v150 + 104) = *(_BYTE *)(v138 + 5);
                if ( v139 > 5 || !*(_QWORD *)(a1 + 8LL * v139 + 328) )
                {
LABEL_266:
                  LODWORD(v24) = -22;
LABEL_287:
                  kfree(result);
                  result = (int)v24;
                  goto LABEL_73;
                }
              }
            }
            else
            {
              if ( v61 < 0x61 )
                goto LABEL_311;
              if ( (*(_BYTE *)(v150 + 96) & 1) != 0 )
                goto LABEL_299;
            }
            v24 = (unsigned int)nl80211_parse_sched_scan_plans(a1, (unsigned int)v46, v150, a3);
            result = v150;
            if ( (_DWORD)v24 )
              goto LABEL_287;
            if ( v61 >= 0x80 && (v61 & 0xFFFFFFFFFFFFFFF8LL) != 0x80 )
            {
              *(_QWORD *)(v150 + 128) = jiffies;
              goto LABEL_73;
            }
            goto LABEL_311;
          }
          if ( v61 < 0x18 || (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 )
            goto LABEL_311;
          v65 = *(_QWORD *)(result + 24);
          if ( v65 )
          {
            if ( v61 < 0x30 || (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
              goto LABEL_311;
            v66 = v65 + n;
          }
          else
          {
            v69 = v61 & 0xFFFFFFFFFFFFFFF8LL;
            if ( (_DWORD)v27 )
            {
              if ( v69 == 8 || v61 < 0x30 || (v61 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
                goto LABEL_311;
              v66 = *(_QWORD *)(result + 8) + v51;
            }
            else
            {
              if ( v61 < 0x30 || v69 == 48 )
                goto LABEL_311;
              v66 = result + 8LL * (int)v15 + 192;
            }
          }
          *(_QWORD *)(result + 48) = v66;
          if ( v61 >= 0x38 && (v61 & 0xFFFFFFFFFFFFFFFCLL) != 0x38 )
          {
            *(_DWORD *)(result + 56) = v39;
            if ( v61 >= 0x48 && (v61 & 0xFFFFFFFFFFFFFFF8LL) != 0x48 )
            {
              v68 = v66 + 44LL * (int)v150;
              goto LABEL_148;
            }
          }
LABEL_311:
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v148 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &nl80211_parse_sched_scan__alloc_tag;
          result = _kmalloc_noprof(v61, 3520);
          *(_QWORD *)(StatusReg + 80) = v148;
          if ( !result )
            goto LABEL_312;
        }
      }
LABEL_72:
      result = -22;
      goto LABEL_73;
    }
  }
  else
  {
    LODWORD(v27) = 0;
    v31 = (_WORD *)a3[132];
    if ( !v31 )
      goto LABEL_43;
  }
  v32 = (unsigned __int16)(*v31 - 4);
  if ( (unsigned int)v32 < 4 )
    goto LABEL_43;
  v33 = 0;
  v34 = v31 + 2;
  v151 = -300;
  while ( 1 )
  {
    v36 = *v34;
    if ( v36 < 4 || v32 < v36 )
      goto LABEL_44;
    LODWORD(result) = _nla_parse(&v152, 6, v34 + 2, (unsigned __int16)(v36 - 4), &nl80211_match_policy, 0, 0);
    if ( (_DWORD)result )
      break;
    if ( v153 && v157 )
      goto LABEL_72;
    if ( v153 | v157 )
    {
      ++v33;
    }
    else if ( v154 )
    {
      v151 = *(_DWORD *)(v154 + 4);
    }
    v35 = (*v34 + 3) & 0x1FFFC;
    v32 -= v35;
    v34 = (unsigned __int16 *)((char *)v34 + v35);
    if ( v32 <= 3 )
      goto LABEL_44;
  }
  result = (int)result;
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
