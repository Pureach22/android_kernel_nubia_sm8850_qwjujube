__int64 __fastcall cfg80211_inform_bss_data(
        __int64 a1,
        __int64 a2,
        int a3,
        int *a4,
        __int64 a5,
        __int16 a6,
        __int16 a7,
        char *a8,
        size_t a9,
        unsigned int a10)
{
  unsigned int v12; // w9
  unsigned int v13; // w8
  int v14; // w9
  __int64 v15; // x8
  __int64 result; // x0
  char *v17; // x8
  unsigned __int64 v18; // x10
  unsigned __int64 v19; // x12
  char *v20; // x9
  char *v21; // x11
  __int64 v22; // x13
  __int64 v23; // x22
  __int64 v24; // x8
  __int64 v25; // x8
  unsigned __int64 v26; // x22
  unsigned __int16 *v27; // x23
  size_t v28; // x9
  char *v29; // x10
  signed __int64 v30; // x11
  char *v31; // x24
  __int64 v32; // x11
  __int64 v33; // x8
  _BYTE *v34; // x28
  unsigned __int64 v35; // x27
  __int64 v36; // x9
  unsigned __int8 *v37; // x25
  unsigned __int8 v38; // w0
  __int64 v39; // x10
  unsigned __int64 v40; // x8
  char *v41; // x11
  unsigned __int64 v42; // x12
  _BYTE *v43; // x9
  __int64 v44; // x13
  __int64 v45; // x10
  __int64 v46; // x8
  __int64 v47; // x8
  unsigned __int64 v48; // x9
  unsigned __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x10
  __int64 v52; // x0
  int v53; // w8
  __int64 v54; // x8
  size_t v55; // x25
  char *v56; // x26
  int v57; // w2
  __int64 v58; // x3
  char *v59; // x8
  char *v60; // x4
  signed __int64 v61; // x9
  unsigned __int64 StatusReg; // x30
  __int64 v63; // x11
  __int64 v64; // x10
  __int64 v65; // x10
  unsigned __int64 v66; // x28
  int v67; // w15
  unsigned int v68; // w12
  char v69; // w11
  int v70; // w17
  unsigned int v71; // w13
  unsigned int v72; // w15
  char v73; // w14
  char *v74; // x9
  unsigned __int64 v75; // x10
  __int64 v76; // x11
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x2
  size_t v80; // x4
  _WORD *v81; // x25
  __int64 v82; // x28
  size_t v83; // x0
  __int64 v84; // x10
  unsigned __int64 v85; // x17
  _BYTE *v86; // x8
  _BYTE *v87; // x25
  __int64 v88; // x12
  unsigned int v89; // w9
  __int64 v90; // x13
  __int64 v91; // x15
  unsigned __int64 v92; // x14
  __int64 v93; // x0
  unsigned __int64 v94; // x16
  __int64 v95; // x1
  __int64 v96; // x0
  unsigned __int64 v97; // x1
  bool v98; // cf
  unsigned __int64 v99; // x1
  unsigned __int64 v100; // x0
  unsigned __int64 v101; // x0
  __int64 i; // x26
  size_t v103; // x0
  char *v104; // x3
  _BYTE *v105; // x9
  char *v106; // x8
  __int64 v107; // x8
  __int64 v108; // x0
  char *v109; // x23
  __int64 v110; // x26
  __int64 v111; // x0
  __int64 v112; // x0
  unsigned __int64 v113; // x10
  _BYTE *v114; // x25
  _BYTE *v115; // x9
  _BYTE *v116; // x8
  __int64 v117; // x11
  char *v118; // x11
  unsigned __int64 v119; // x9
  __int16 v120; // w8
  _BYTE *v121; // x8
  __int64 v122; // x2
  __int64 v123; // x0
  int v124; // w25
  char v125; // w9
  int v126; // w8
  char v127; // w9
  __int64 v128; // x25
  __int64 v129; // x13
  char *v130; // x8
  unsigned __int64 v131; // x10
  char *v132; // x9
  __int64 v133; // x11
  size_t v134; // x10
  char *v135; // x8
  __int64 v136; // x26
  unsigned __int64 v137; // x10
  unsigned __int16 *v138; // x11
  unsigned __int64 v139; // x9
  unsigned __int64 v140; // x12
  unsigned int v141; // w8
  int v142; // w13
  char v143; // w13
  char v144; // w14
  __int64 v145; // x14
  __int64 v146; // x12
  __int16 v147; // w12
  int v148; // w11
  __int64 v149; // x10
  __int64 v150; // x9
  unsigned int v151; // w0
  _DWORD *channel_khz; // x0
  __int64 *bss; // x0
  __int64 v154; // x1
  unsigned __int64 v155; // x0
  size_t v156; // x1
  __int64 v157; // x25
  unsigned __int64 v158; // x8
  __int64 v159; // x9
  size_t v160; // x2
  unsigned __int64 v161; // x8
  char v162; // [xsp+4h] [xbp-18Ch]
  __int64 v163; // [xsp+8h] [xbp-188h]
  int v164; // [xsp+10h] [xbp-180h]
  char v165; // [xsp+14h] [xbp-17Ch]
  __int64 v166; // [xsp+18h] [xbp-178h]
  char v167; // [xsp+20h] [xbp-170h]
  char v168; // [xsp+24h] [xbp-16Ch]
  char *v169; // [xsp+28h] [xbp-168h]
  char *v170; // [xsp+30h] [xbp-160h]
  __int16 v171; // [xsp+38h] [xbp-158h]
  size_t v172; // [xsp+38h] [xbp-158h]
  int v173; // [xsp+44h] [xbp-14Ch]
  unsigned __int64 v174; // [xsp+48h] [xbp-148h]
  char *v175; // [xsp+48h] [xbp-148h]
  unsigned __int64 v176; // [xsp+50h] [xbp-140h]
  __int64 v177; // [xsp+58h] [xbp-138h]
  char *v178; // [xsp+60h] [xbp-130h]
  int v179; // [xsp+6Ch] [xbp-124h]
  char v180; // [xsp+70h] [xbp-120h]
  unsigned __int64 v181; // [xsp+70h] [xbp-120h]
  void *s; // [xsp+78h] [xbp-118h]
  char *sa; // [xsp+78h] [xbp-118h]
  unsigned __int8 *sb; // [xsp+78h] [xbp-118h]
  __int64 v185; // [xsp+80h] [xbp-110h]
  __int64 *v186; // [xsp+80h] [xbp-110h]
  __int64 v187; // [xsp+88h] [xbp-108h] BYREF
  __int64 v188; // [xsp+90h] [xbp-100h]
  __int64 v189; // [xsp+98h] [xbp-F8h]
  __int64 v190; // [xsp+A0h] [xbp-F0h]
  int v191; // [xsp+ACh] [xbp-E4h] BYREF
  __int64 v192; // [xsp+B0h] [xbp-E0h] BYREF
  int v193; // [xsp+B8h] [xbp-D8h]
  __int64 v194; // [xsp+BCh] [xbp-D4h]
  __int64 v195; // [xsp+C4h] [xbp-CCh]
  int v196; // [xsp+CCh] [xbp-C4h]
  __int64 v197; // [xsp+D0h] [xbp-C0h]
  __int16 v198; // [xsp+D8h] [xbp-B8h]
  __int16 v199; // [xsp+DAh] [xbp-B6h]
  int v200; // [xsp+DCh] [xbp-B4h]
  char *v201; // [xsp+E0h] [xbp-B0h]
  size_t n; // [xsp+E8h] [xbp-A8h]
  __int64 v203; // [xsp+F0h] [xbp-A0h]
  __int64 v204; // [xsp+F8h] [xbp-98h]
  __int16 v205; // [xsp+100h] [xbp-90h]
  char v206; // [xsp+102h] [xbp-8Eh]
  int v207; // [xsp+103h] [xbp-8Dh]
  char v208; // [xsp+107h] [xbp-89h]
  __int64 v209; // [xsp+108h] [xbp-88h]
  __int64 v210; // [xsp+110h] [xbp-80h] BYREF
  int v211; // [xsp+118h] [xbp-78h]
  _DWORD v212[5]; // [xsp+11Ch] [xbp-74h] BYREF
  __int64 v213; // [xsp+130h] [xbp-60h]
  _QWORD v214[3]; // [xsp+138h] [xbp-58h] BYREF
  __int64 v215; // [xsp+150h] [xbp-40h]
  __int64 v216; // [xsp+158h] [xbp-38h]
  __int64 v217; // [xsp+160h] [xbp-30h]
  __int64 v218; // [xsp+168h] [xbp-28h]
  _DWORD src[4]; // [xsp+170h] [xbp-20h] BYREF
  __int64 v220; // [xsp+180h] [xbp-10h]

  v220 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(unsigned __int8 *)(a2 + 43);
  v192 = a2;
  v201 = a8;
  n = a9;
  v13 = v12 >> 1;
  v193 = a3;
  if ( (v12 & 1) == 0 )
    LOBYTE(v13) = 3;
  v14 = *a4;
  v194 = 0;
  v206 = v13;
  v207 = 0;
  v15 = *(unsigned __int8 *)(a2 + 44);
  v195 = 0;
  v209 = v15;
  LOWORD(v15) = *((_WORD *)a4 + 2);
  v197 = a5;
  v198 = a6;
  v199 = a7;
  v200 = 0;
  v203 = 0;
  v204 = 0;
  v205 = 0;
  v208 = 0;
  v196 = (unsigned __int16)v15;
  HIDWORD(v195) = v14;
  result = cfg80211_inform_single_bss_data(a1, &v192, a10);
  if ( a3 != 3 && result )
  {
    memset(v212, 0, sizeof(v212));
    v210 = v192;
    v211 = v193;
    v213 = v197;
    v215 = 1;
    v216 = result;
    WORD1(v214[0]) = v199;
    BYTE2(v217) = v206;
    LOWORD(v214[0]) = 0;
    memset((char *)v214 + 4, 0, 20);
    v218 = v209;
    LOWORD(v217) = 0;
    *(_DWORD *)((char *)&v217 + 3) = 0;
    HIBYTE(v217) = 0;
    if ( (n & 0xFFFFFFFE) != 0 )
    {
      v17 = v201;
      v18 = (unsigned int)n;
      v19 = (unsigned int)n;
      v20 = &v201[(unsigned int)n];
      v21 = v201;
      while ( 1 )
      {
        v22 = (unsigned __int8)v21[1];
        if ( v19 < v22 + 2 )
          goto LABEL_76;
        if ( *v21 == 71 )
          break;
        v21 += v22 + 2;
        v19 = v20 - v21;
        if ( v20 - v21 <= 1 )
          goto LABEL_76;
      }
      if ( v21 && (*(_BYTE *)(a1 + 1424) & 1) != 0 )
      {
        if ( (*(_BYTE *)(a1 + 1424) & 2) != 0 )
        {
          while ( 1 )
          {
            v32 = (unsigned __int8)v17[1];
            if ( v18 < v32 + 2 )
              goto LABEL_76;
            if ( v17[1] && (unsigned __int8)*v17 == 255 && v17[2] == 35 )
              break;
            v17 += v32 + 2;
            v18 = v20 - v17;
            if ( v20 - v17 <= 1 )
              goto LABEL_76;
          }
          if ( !v17 )
            goto LABEL_76;
        }
        v23 = result;
        if ( (a10 & 0x400010) != 0 )
        {
          v24 = 1;
          if ( (a10 & 0x10) == 0 )
            v24 = 2;
        }
        else
        {
          v24 = 0;
        }
        v25 = _kmalloc_cache_noprof(kmalloc_caches[14 * v24 + 12], a10, 2304);
        result = v23;
        if ( v25 )
          goto LABEL_17;
      }
    }
LABEL_76:
    while ( 2 )
    {
      if ( v193 == 2 )
      {
        v55 = n;
        if ( (__int64)n >= 2 )
        {
          v56 = v201;
          v31 = (char *)&v210;
          v57 = a10 & 0x400010;
          if ( (a10 & 0x10) != 0 )
            v58 = 1;
          else
            v58 = 2;
          v59 = &v201[n];
          v60 = (char *)src + 1;
          v61 = n;
          v26 = (unsigned __int64)v201;
          StatusReg = _ReadStatusReg(SP_EL0);
          while ( 1 )
          {
            v64 = *(unsigned __int8 *)(v26 + 1);
            if ( v61 < (unsigned __int64)(v64 + 2) )
              goto LABEL_284;
            if ( *(_BYTE *)(v26 + 1) && *(unsigned __int8 *)v26 == 255 && *(_BYTE *)(v26 + 2) == 107 )
              break;
LABEL_85:
            v26 += v64 + 2;
            v59 = &v56[v55];
            v61 = (signed __int64)&v56[v55 - v26];
            if ( v61 <= 1 )
              goto LABEL_284;
          }
          v27 = (unsigned __int16 *)(v26 + 3);
          v217 = 0;
          v218 = 0;
          v215 = 2;
          v210 = v192;
          v213 = 0;
          memset(v214, 0, sizeof(v214));
          memset(v212, 0, sizeof(v212));
          v211 = v193;
          v216 = result;
          if ( v26 == -3 )
            goto LABEL_84;
          v65 = *(unsigned __int8 *)(v26 + 1);
          v66 = v65 - 1;
          if ( (unsigned __int64)(v65 - 1) < 2 )
            goto LABEL_84;
          v35 = *v27;
          switch ( v35 & 7 )
          {
            case 3uLL:
              LOBYTE(v68) = 7;
              break;
            case 1uLL:
              if ( (v35 & 0x10) != 0 )
                LOBYTE(v68) = 2;
              else
                LOBYTE(v68) = 1;
              break;
            case 0uLL:
              if ( (v35 & 0x10) != 0 )
                v67 = 8;
              else
                v67 = 7;
              v68 = v67
                  + (((unsigned __int8)(v35 & 0xE0) >> 5) & 1)
                  + (((unsigned __int8)v35 >> 5) & 2)
                  + (((unsigned int)v35 >> 6) & 2)
                  + (((unsigned int)v35 >> 7) & 2)
                  + (((unsigned int)v35 >> 9) & 1);
              break;
            default:
LABEL_84:
              v56 = v201;
              v55 = n;
              v64 = *(unsigned __int8 *)(v26 + 1);
              goto LABEL_85;
          }
          if ( (unsigned __int64)(unsigned __int8)v68 + 2 <= v66
            && (v35 & 7) == 0
            && *(unsigned __int8 *)(v26 + 5) >= (unsigned int)(unsigned __int8)v68
            && (~(_DWORD)v35 & 0x130) == 0 )
          {
            v69 = (v35 & 0x10) != 0 ? *(_BYTE *)(v26 + 12) : -1;
            v180 = v69;
            v70 = (v35 & 0x200) != 0 ? *(unsigned __int8 *)(v26 + ((v35 >> 5) & 2) + ((v35 >> 6) & 2) + 16) : 0;
            if ( v26 )
            {
              sa = (char *)*(unsigned __int8 *)(v26 + 5);
              v71 = (unsigned int)v35 >> 6;
              v72 = (unsigned int)v35 >> 7;
              v73 = (v35 & 0x10) != 0 ? 8 : 7;
              if ( v66 >= (unsigned __int8)(v73
                                          + ((v35 & 0x20) != 0)
                                          + (((unsigned __int8)v35 >> 5) & 2)
                                          + (v71 & 2)
                                          + (v72 & 2)
                                          + ((v35 & 0x200) != 0)
                                          + 2)
                && (unsigned int)sa >= (unsigned __int8)(v73
                                                       + ((v35 & 0x20) != 0)
                                                       + (((unsigned __int8)v35 >> 5) & 2)
                                                       + (v71 & 2)
                                                       + (v72 & 2)
                                                       + ((v35 & 0x200) != 0)) )
              {
                v74 = (char *)(v26 + 2 + v65);
                v75 = v59 - v74;
                if ( v59 - v74 >= 2 )
                {
                  do
                  {
                    v76 = (unsigned __int8)v74[1];
                    if ( v75 < v76 + 2 )
                      break;
                    if ( (unsigned __int8)*v74 != 242 )
                      break;
                    v66 += v76;
                    v74 += v76 + 2;
                    v75 = v59 - v74;
                  }
                  while ( v59 - v74 > 1 );
                }
                v173 = v70;
                v176 = StatusReg;
                v177 = v58;
                v178 = v60;
                v179 = v57;
                v186 = (__int64 *)result;
                v171 = *(unsigned __int8 *)(v26 + 13);
                v77 = v66 >= 0xFFFFFFFFFFFFFF08LL ? -1LL : v66 + 248;
                v174 = v77;
                v78 = _kmalloc_noprof(v77, a10 | 0x100);
                v58 = v177;
                v60 = v178;
                result = (__int64)v186;
                v57 = v179;
                StatusReg = v176;
                if ( v78 )
                {
                  v79 = v55;
                  v80 = v66;
                  v81 = (_WORD *)(v78 + 248);
                  v82 = v78;
                  v83 = cfg80211_defragment_element(
                          (unsigned __int8 *)v26,
                          (__int64)v56,
                          v79,
                          (char *)(v78 + 248),
                          v80,
                          0xF2u);
                  v63 = v82;
                  if ( (v83 & 0x8000000000000000LL) == 0 )
                  {
                    *(_QWORD *)v82 = v81;
                    if ( (v174 & 0xFFFFFFFFFFFFFFFELL) == 0xF8 )
                      goto LABEL_285;
                    if ( (*v81 & 7u) >= 5 )
                    {
                      v84 = 0;
                      __break(0x800u);
                    }
                    else
                    {
                      if ( v174 < 0xFB )
                        goto LABEL_285;
                      v84 = (unsigned __int8)(*(_BYTE *)(v82 + 250) + 2);
                    }
                    v85 = v83 - v84;
                    v86 = (char *)v81 + v84;
                    v87 = (char *)v81 + v83;
                    if ( (__int64)(v83 - v84) >= 2 )
                    {
                      v88 = v84 + 248;
                      v89 = 0;
                      v90 = v84 + 248;
                      v91 = v84 + 248;
                      v92 = v84 + 248;
                      while ( v88 + 1 >= 0 )
                      {
                        if ( v174 <= v88 + 1 )
                          break;
                        if ( v90 + 1 < 0 )
                          break;
                        if ( v174 <= v90 + 1 )
                          break;
                        if ( v91 + 1 < 0 )
                          break;
                        if ( v174 <= v91 + 1 )
                          break;
                        v94 = v92 + 1;
                        if ( ((v92 + 1) & 0x8000000000000000LL) != 0 || v174 <= v94 )
                          break;
                        v93 = (unsigned __int8)v86[1];
                        if ( v85 < v93 + 2 )
                          goto LABEL_82;
                        if ( v90 < 0 || v91 < 0 || (v92 & 0x8000000000000000LL) != 0 || v174 <= v92 )
                          break;
                        if ( !*v86 )
                        {
                          if ( v89 >= 0xF )
                            goto LABEL_286;
                          v95 = 8LL * v89;
                          if ( v174 < v95 + 8 )
                            break;
                          if ( v174 - (v95 + 8) < 8 )
                            break;
                          v96 = 8LL * v89;
                          if ( v174 < v96 + 8 )
                            break;
                          if ( v174 - (v96 + 8) < 8 )
                            break;
                          v97 = v95 | 0x80;
                          *(_QWORD *)(v82 + 8 + 8LL * v89) = v86 + 2;
                          v98 = v174 >= v97;
                          v99 = v174 - v97;
                          if ( !v98 )
                            break;
                          if ( v99 < 8 )
                            break;
                          if ( v174 <= v94 )
                            break;
                          v100 = v96 | 0x80;
                          v98 = v174 >= v100;
                          v101 = v174 - v100;
                          if ( !v98 || v101 < 8 )
                            break;
                          *(_QWORD *)(v82 + 128 + 8LL * v89) = (unsigned __int8)v86[1];
                          if ( v89 == 14 )
                            goto LABEL_82;
                          if ( v174 <= v94 )
                            break;
                          v93 = (unsigned __int8)v86[1];
                          ++v89;
                        }
                        v86 += v93 + 2;
                        v85 = v87 - v86;
                        v88 += v93 + 2;
                        v90 += v93 + 2;
                        v91 += v93 + 2;
                        v92 += v93 + 2;
                        if ( v87 - v86 <= 1 )
                          goto LABEL_82;
                      }
LABEL_285:
                      __break(1u);
LABEL_286:
                      __break(0x5512u);
LABEL_287:
                      _fortify_panic(17, v35);
                      goto LABEL_288;
                    }
LABEL_82:
                    v63 = v82;
                    if ( v87 == v86 )
                    {
                      for ( i = 128; i != 248; i += 8 )
                      {
                        if ( i - 120 < 0 )
                          goto LABEL_285;
                        v104 = *(char **)(v63 + i - 120);
                        if ( !v104 )
                          break;
                        if ( i < 0 )
                          goto LABEL_285;
                        if ( *(__int64 *)(v63 + i) >= 255 )
                        {
                          v105 = v87;
                          v106 = v104 - 2;
                          if ( i != 240 )
                          {
                            if ( i - 112 < 0 )
                              goto LABEL_285;
                            v105 = *(_BYTE **)(v63 + i - 112);
                            if ( v105 )
                              v106 = *(char **)(v63 + i - 120);
                            else
                              v106 = v104 - 2;
                            if ( !v105 )
                              v105 = v87;
                          }
                          v103 = cfg80211_defragment_element(
                                   (unsigned __int8 *)v104 - 2,
                                   (__int64)(v104 - 2),
                                   v105 - v106,
                                   v104,
                                   v105 - v106,
                                   0xFEu);
                          v63 = v82;
                          *(_QWORD *)(v82 + i) = v103;
                          if ( (v103 & 0x8000000000000000LL) != 0 )
                            goto LABEL_83;
                        }
                      }
                      if ( *(_QWORD *)(v63 + 8) )
                      {
                        if ( v179 )
                          v107 = v177;
                        else
                          v107 = 0;
                        v108 = _kmalloc_cache_noprof(kmalloc_caches[14 * v107 + 12], a10, 2304);
                        if ( v108 )
                        {
                          memset((char *)&src[1] + 3, 0, 9);
                          v175 = (char *)v108;
                          if ( v173 )
                          {
                            v108 = 0;
                            v167 = 1;
                            goto LABEL_216;
                          }
                          v191 = 0;
                          _rcu_read_lock(v108);
                          v110 = v186[1];
                          v111 = (unsigned int)(1000 * *(_DWORD *)(*v186 + 4));
                          LOWORD(v191) = 4096;
                          v112 = ieee80211_freq_khz_to_channel(v111);
                          v113 = *(unsigned int *)(v110 + 24);
                          v114 = (_BYTE *)(v110 + 29);
                          HIBYTE(v191) = v112;
                          if ( (unsigned int)v113 < 2 )
                            goto LABEL_198;
                          v115 = &v114[v113];
                          v116 = (_BYTE *)(v110 + 29);
                          while ( 1 )
                          {
                            v117 = (unsigned __int8)v116[1];
                            if ( v113 < v117 + 2 )
                              goto LABEL_198;
                            if ( *v116 == 59 )
                              break;
                            v116 += v117 + 2;
                            v113 = v115 - v116;
                            if ( v115 - v116 <= 1 )
                              goto LABEL_198;
                          }
                          if ( v116 && v116[1] )
                          {
                            v118 = v178;
                            BYTE2(v191) = v116[2];
LABEL_199:
                            LOBYTE(src[0]) = -1;
                            v119 = *(unsigned int *)(v110 + 24);
                            LOBYTE(src[3]) = 0x80;
                            v120 = *((_WORD *)v186 + 38);
                            *(_DWORD *)v118 = *((_DWORD *)v186 + 18);
                            *((_WORD *)v118 + 2) = v120;
                            if ( (unsigned int)v119 >= 2 )
                            {
                              v121 = &v114[v119];
                              while ( 1 )
                              {
                                v122 = (unsigned __int8)v114[1];
                                if ( v119 < v122 + 2 )
                                  goto LABEL_214;
                                if ( !*v114 )
                                  break;
                                v114 += v122 + 2;
                                v119 = v121 - v114;
                                if ( v121 - v114 <= 1 )
                                  goto LABEL_214;
                              }
                              if ( v114 && (unsigned int)v122 <= 0x20 )
                              {
                                v123 = crc32_le(0xFFFFFFFFLL, v114 + 2);
                                v124 = ~(_DWORD)v123;
                                _rcu_read_unlock(v123);
                                *(_DWORD *)((char *)&src[1] + 3) = v124;
                                if ( (v35 & 0x200) != 0 )
                                  v125 = 14;
                                else
                                  v125 = 2;
                                HIBYTE(src[2]) = v125;
                                BYTE1(src[3]) = 0;
                                HIWORD(src[3]) = v180 & 0xF | (16 * v171);
                                v35 = BYTE1(v191);
                                v108 = _kmalloc_noprof(BYTE1(v191) + 6LL, a10 | 0x100);
                                if ( v108 )
                                {
                                  v126 = v191;
                                  v127 = BYTE1(v191);
                                  *(_BYTE *)v108 = -55;
                                  *(_DWORD *)(v108 + 2) = v126;
                                  *(_BYTE *)(v108 + 1) = v127 + 4;
                                  if ( v35 < BYTE1(v126) )
                                    goto LABEL_287;
                                  if ( BYTE1(v126) < 0x11u )
                                  {
                                    v128 = v108;
                                    memcpy((void *)(v108 + 6), src, BYTE1(v126));
                                    v108 = v128;
                                    v167 = 0;
                                    goto LABEL_216;
                                  }
LABEL_288:
                                  _fortify_panic(16, v35);
LABEL_289:
                                  _fortify_panic(17, v156);
LABEL_290:
                                  v54 = 1;
                                  if ( (a10 & 0x10) == 0 )
                                    v54 = 2;
LABEL_73:
                                  v25 = _kmalloc_cache_noprof(kmalloc_caches[14 * v54 + 12], a10, 2304);
                                  *((_QWORD *)v27 + 10) = v31;
                                  result = v26;
                                  if ( !v25 )
                                    continue;
LABEL_17:
                                  s = (void *)v25;
                                  v185 = result;
                                  v26 = n;
                                  v27 = (unsigned __int16 *)_kmalloc_noprof(n, a10);
                                  if ( v27 )
                                  {
                                    v28 = n;
                                    if ( (__int64)n >= 2 )
                                    {
                                      v29 = v201;
                                      v30 = n;
                                      v31 = v201;
                                      do
                                      {
                                        v33 = (unsigned __int8)v31[1];
                                        if ( v30 < (unsigned __int64)(v33 + 2) )
                                          break;
                                        if ( (unsigned int)v33 >= 4 && *v31 == 71 )
                                        {
                                          v34 = v31 + 2;
                                          v35 = (unsigned __int64)(v31 + 3);
                                          if ( (unsigned int)(unsigned __int8)v31[2] - 1 <= 7 )
                                          {
                                            v37 = (unsigned __int8 *)(v31 + 4);
                                            v36 = (unsigned __int8)v31[4];
                                            if ( v33 - 1 >= (unsigned __int64)(v36 + 2) )
                                            {
                                              while ( 1 )
                                              {
                                                if ( (unsigned int)v36 >= 4
                                                  && !*(_BYTE *)v35
                                                  && *(_BYTE *)(v35 + 2) == 83
                                                  && *(_BYTE *)(v35 + 3) == 2 )
                                                {
                                                  if ( v26 < n )
                                                  {
                                                    v52 = _fortify_panic(15, v26);
                                                    v27 = (unsigned __int16 *)_ReadStatusReg(SP_EL0);
                                                    v31 = *((char **)v27 + 10);
                                                    v26 = v52;
                                                    *((_QWORD *)v27 + 10) = &cfg80211_parse_mbssid_data__alloc_tag;
                                                    if ( (a10 & v53) != 0 )
                                                      goto LABEL_290;
                                                    v54 = 0;
                                                    goto LABEL_73;
                                                  }
                                                  memset(v27, 0, n);
                                                  v38 = cfg80211_merge_profile(
                                                          (int)v201,
                                                          n,
                                                          (__int64)v31,
                                                          v35,
                                                          (char *)v27,
                                                          n);
                                                  if ( (v38 & 0xFE) != 0 )
                                                  {
                                                    v39 = 0;
                                                    v40 = 0;
                                                    v41 = (char *)v27 + v38;
                                                    v42 = v38;
                                                    v43 = v27;
                                                    while ( v39 + 1 >= 0
                                                         && v26 > v39 + 1
                                                         && (__int64)(v40 + 1) >= 0
                                                         && v26 > v40 + 1 )
                                                    {
                                                      v44 = (unsigned __int8)v43[1];
                                                      if ( v42 < v44 + 2 )
                                                        goto LABEL_68;
                                                      if ( (v40 & 0x8000000000000000LL) != 0 || v26 <= v40 )
                                                        break;
                                                      if ( *v43 == 85 )
                                                      {
                                                        if ( v43 && v43[1] )
                                                        {
                                                          v45 = v39 + 2;
                                                          if ( v45 < 0 )
                                                            goto LABEL_285;
                                                          if ( v26 <= v45 )
                                                            goto LABEL_285;
                                                          v46 = v40 + 2;
                                                          if ( v46 < 0 || v26 <= v46 )
                                                            goto LABEL_285;
                                                          v47 = (unsigned __int8)v43[2];
                                                          if ( (unsigned int)(v47 - 47) >= 0xFFFFFFD2
                                                            && 1 << *v34 > (int)v47 )
                                                          {
                                                            BYTE1(v217) = v43[2];
                                                            LOBYTE(v217) = *v34;
                                                            v48 = ((unsigned __int64)HIBYTE(v195) << 16)
                                                                | ((unsigned __int64)(unsigned __int8)v196 << 8)
                                                                | ((((unsigned __int64)BYTE4(v195) << 16)
                                                                  | ((unsigned __int64)BYTE5(v195) << 8)
                                                                  | BYTE6(v195)) << 24)
                                                                | BYTE1(v196);
                                                            v49 = ((v48 & (0xFFFFFFFFFFFFFFFFLL >> -(char)v217)) + v47)
                                                                & (0xFFFFFFFFFFFFFFFFLL >> -(char)v217)
                                                                | v48 & ~(0xFFFFFFFFFFFFFFFFLL >> -(char)v217);
                                                            *(_DWORD *)((char *)&v212[3] + 2) = bswap32(v49);
                                                            BYTE1(v212[3]) = BYTE4(v49);
                                                            LOBYTE(v212[3]) = BYTE5(v49);
                                                            memset(s, 0, 0x900u);
                                                            v214[1] = s;
                                                            v214[2] = cfg80211_gen_new_ie(v201);
                                                            if ( v214[2] )
                                                            {
                                                              if ( (v26 & 0xFFFFFFFFFFFFFFFELL) == 2 || v26 < 4 )
                                                                goto LABEL_285;
                                                              LOWORD(v214[0]) = v27[1];
                                                              v50 = cfg80211_inform_single_bss_data(a1, &v210, a10);
                                                              if ( !v50 )
                                                              {
                                                                v33 = (unsigned __int8)v31[1];
                                                                goto LABEL_31;
                                                              }
                                                              cfg80211_put_bss(a1, v50);
                                                            }
                                                          }
                                                        }
                                                        goto LABEL_68;
                                                      }
                                                      v43 += v44 + 2;
                                                      v39 += v44 + 2;
                                                      v40 += v44 + 2;
                                                      v42 = v41 - v43;
                                                      if ( v41 - v43 <= 1 )
                                                        goto LABEL_68;
                                                    }
                                                    goto LABEL_285;
                                                  }
                                                }
LABEL_68:
                                                v33 = (unsigned __int8)v31[1];
                                                v35 += *v37 + 2LL;
                                                v51 = (__int64)&v34[v33 - v35];
                                                if ( v51 > 1 )
                                                {
                                                  v37 = (unsigned __int8 *)(v35 + 1);
                                                  v36 = *(unsigned __int8 *)(v35 + 1);
                                                  if ( v51 >= (unsigned __int64)(v36 + 2) )
                                                    continue;
                                                }
                                                break;
                                              }
                                            }
LABEL_31:
                                            v29 = v201;
                                            v28 = n;
                                          }
                                        }
                                        v31 += v33 + 2;
                                        v30 = &v29[v28] - v31;
                                      }
                                      while ( v30 > 1 );
                                    }
                                  }
                                  kfree(s);
                                  kfree(v27);
                                  result = v185;
                                  continue;
                                }
LABEL_215:
                                v167 = 1;
LABEL_216:
                                v129 = v82;
                                if ( (n & 0xFFFFFFFE) != 0 )
                                {
                                  v130 = v201;
                                  v131 = (unsigned int)n;
                                  v132 = &v201[(unsigned int)n];
                                  while ( 1 )
                                  {
                                    v133 = (unsigned __int8)v130[1];
                                    if ( v131 < v133 + 2 )
                                      goto LABEL_221;
                                    if ( !*v130 )
                                      break;
                                    v130 += v133 + 2;
                                    v131 = v132 - v130;
                                    if ( v132 - v130 <= 1 )
                                      goto LABEL_221;
                                  }
                                  if ( v130 )
                                    v134 = (unsigned __int8)v130[1];
                                  else
                                    v134 = 0;
                                  if ( v130 )
                                    v135 = v130 + 2;
                                  else
                                    v135 = nullptr;
                                  v170 = v135;
                                  v172 = v134;
                                }
                                else
                                {
LABEL_221:
                                  v170 = nullptr;
                                  v172 = 0;
                                }
                                v35 = 0;
                                v136 = 0;
                                v169 = sa + 5;
                                v168 = (_BYTE)sa + 3;
                                v181 = (unsigned __int64)(sa + 2);
                                while ( 2 )
                                {
                                  if ( (__int64)(v35 + 8) < 0 )
                                    goto LABEL_285;
                                  v137 = v129 + v35;
                                  v138 = *(unsigned __int16 **)(v129 + v35 + 8);
                                  if ( !v138 )
                                    goto LABEL_281;
                                  src[0] = 0;
                                  if ( (__int64)(v35 + 128) < 0 )
                                    goto LABEL_285;
                                  v139 = v129 + v35;
                                  v140 = *(_QWORD *)(v129 + v35 + 128);
                                  if ( v140 >= 3 )
                                  {
                                    v141 = *v138;
                                    v142 = ((v141 >> 4) & 8 | (v141 >> 5) & 2) + ((v141 >> 7) & 2);
                                    if ( (v141 & 0x20) != 0 )
                                      v143 = v142 + 7;
                                    else
                                      v143 = v142 + 1;
                                    v144 = v143 + 2;
                                    if ( (v141 & 0x400) == 0 )
                                      v144 = v143 + 1;
                                    if ( (~v141 & 0x210) == 0 )
                                      v143 = v144;
                                    if ( (v141 & 0x10) != 0 )
                                    {
                                      v145 = *((unsigned __int8 *)v138 + 2);
                                      if ( (unsigned int)v145 >= (unsigned __int8)(v143 + ((v141 & 0x800) != 0))
                                        && v145 + 2 <= v140 )
                                      {
                                        v146 = 1LL << (v141 & 0xF);
                                        if ( (v146 & v136) != 0 )
                                          goto LABEL_281;
                                        v136 |= v146;
                                        if ( (~v141 & 0xE0) == 0 )
                                        {
                                          v147 = *(unsigned __int16 *)((char *)v138 + 7);
                                          v148 = *(_DWORD *)((char *)v138 + 3);
                                          v149 = *(_QWORD *)(v137 + 8);
                                          v150 = *(_QWORD *)(v139 + 128);
                                          LOWORD(v212[4]) = v147;
                                          v212[3] = v148;
                                          WORD1(v214[0]) = *(_WORD *)(v149 + 9);
                                          v213 = *(_QWORD *)(v149 + 11) + v197;
                                          if ( v150 - (*(unsigned __int8 *)(v149 + 2) + 3LL) + 1 >= 2 )
                                          {
                                            sb = (unsigned __int8 *)v108;
                                            LOWORD(v214[0]) = *(_WORD *)(v149 + *(unsigned __int8 *)(v149 + 2) + 2);
                                            v188 = 0;
                                            v187 = 0;
                                            v189 = (unsigned __int8)v173;
                                            v165 = v141 & 0xF;
                                            *(_DWORD *)((char *)&v189 + 1) = v141 & 0xF;
                                            cfg80211_iter_rnr(
                                              (unsigned __int8 *)v201,
                                              n,
                                              cfg802121_mld_ap_rnr_iter,
                                              (__int64)&v187);
                                            if ( !BYTE4(v188) )
                                              goto LABEL_230;
                                            v164 = BYTE4(v188);
                                            if ( (v189 & 0x10000) != 0 )
                                              goto LABEL_230;
                                            v162 = v188;
                                            v163 = v187;
                                            if ( (ieee80211_operating_class_to_band(
                                                    *((unsigned __int8 *)&_ksymtab___cfg80211_alloc_event_skb + v187 + 2),
                                                    src)
                                                & 1) == 0 )
                                              goto LABEL_230;
                                            v151 = ieee80211_channel_to_freq_khz(
                                                     *((unsigned __int8 *)&_ksymtab___cfg80211_alloc_event_skb + v163 + 3),
                                                     src[0]);
                                            channel_khz = (_DWORD *)ieee80211_get_channel_khz(a1, v151);
                                            *(_QWORD *)&v212[1] = channel_khz;
                                            if ( !channel_khz )
                                              goto LABEL_230;
                                            bss = _cfg80211_get_bss(
                                                    a1,
                                                    channel_khz,
                                                    (__int64)&v212[3],
                                                    v170,
                                                    v172,
                                                    4u,
                                                    2u,
                                                    1);
                                            if ( !bss )
                                              goto LABEL_258;
                                            v154 = (__int64)bss;
                                            if ( LOWORD(v214[0]) == *((unsigned __int16 *)bss + 35)
                                              && *((_DWORD *)bss - 2) != 2 )
                                            {
                                              goto LABEL_280;
                                            }
                                            cfg80211_put_bss(a1, bss);
LABEL_258:
                                            if ( v164 == 2 )
                                            {
                                              if ( (*(_BYTE *)(a1 + 101) & 0x10) != 0 )
                                              {
                                                LOBYTE(v164) = 2;
                                              }
                                              else
                                              {
                                                LOBYTE(v164) = 0;
                                                v218 = 1;
                                              }
                                            }
                                            BYTE2(v217) = v164;
                                            memset(v175, 0, 0x900u);
                                            v214[1] = v175;
                                            v155 = cfg80211_gen_new_ie(v201);
                                            v214[2] = v155;
                                            if ( !v155 || (unsigned __int64)&v169[v155] > 0x900 )
                                              goto LABEL_230;
                                            if ( v155 > 0x8FF )
                                              goto LABEL_285;
                                            v175[v155] = -1;
                                            if ( v155 == 2303 )
                                              goto LABEL_285;
                                            v214[2] = v155 + 3;
                                            v175[v155 + 1] = v168;
                                            if ( v155 == 2302 )
                                              goto LABEL_285;
                                            v156 = 2301 - v155;
                                            v175[v155 + 2] = 107;
                                            if ( 2301 - v155 < v181 )
                                              goto LABEL_289;
                                            v157 = v214[2];
                                            memcpy(&v175[v214[2]], (const void *)(v26 + 3), v181);
                                            if ( (unsigned __int64)(v157 - 2295) < 0xFFFFFFFFFFFFF700LL )
                                              goto LABEL_285;
                                            v175[v157 + 9] = v165;
                                            if ( (unsigned __int64)(v157 - 2294) < 0xFFFFFFFFFFFFF700LL )
                                              goto LABEL_285;
                                            v175[v157 + 10] = v162;
                                            v158 = v157 + v181;
                                            v214[2] = v157 + v181;
                                            if ( !sb || (v164 & 1) == 0 )
                                              goto LABEL_279;
                                            if ( (v167 & 1) != 0 )
                                              goto LABEL_285;
                                            v159 = sb[1];
                                            if ( v158 + v159 + 2 <= 0x900 )
                                            {
                                              v160 = v159 + 2;
                                              v98 = v158 <= 0x900;
                                              v161 = 2304 - v158;
                                              if ( v98 )
                                                v156 = v161;
                                              else
                                                v156 = 0;
                                              if ( v156 < v160 )
                                                goto LABEL_289;
                                              v166 = v214[2];
                                              memcpy(&v175[v214[2]], sb, v160);
                                              v214[2] = v166 + sb[1] + 2;
LABEL_279:
                                              v154 = cfg80211_inform_single_bss_data(a1, &v210, a10);
                                              v108 = (__int64)sb;
                                              if ( !v154 )
                                              {
LABEL_281:
                                                v109 = v175;
                                                goto LABEL_282;
                                              }
LABEL_280:
                                              cfg80211_put_bss(a1, v154);
                                              v108 = (__int64)sb;
                                            }
                                            else
                                            {
LABEL_230:
                                              v108 = (__int64)sb;
                                            }
                                          }
                                        }
                                      }
                                    }
                                    v129 = v82;
                                  }
                                  v35 += 8LL;
                                  if ( v35 == 120 )
                                    goto LABEL_281;
                                  continue;
                                }
                              }
                            }
                          }
                          else
                          {
LABEL_198:
                            v189 = 0;
                            v190 = 0;
                            v187 = 0;
                            v188 = 0;
                            cfg80211_chandef_create((__int64)&v187, *v186, 0);
                            v112 = ieee80211_chandef_to_operating_class(&v187, (char *)&v191 + 2);
                            v118 = v178;
                            if ( (v112 & 1) != 0 )
                              goto LABEL_199;
                          }
LABEL_214:
                          _rcu_read_unlock(v112);
                          v108 = 0;
                          goto LABEL_215;
                        }
                        v109 = nullptr;
                      }
                      else
                      {
                        v109 = nullptr;
                        v108 = 0;
                      }
LABEL_282:
                      kfree(v108);
                      kfree(v109);
                      v63 = v82;
                    }
                  }
LABEL_83:
                  kfree(v63);
                  v58 = v177;
                  v60 = v178;
                  result = (__int64)v186;
                  v57 = v179;
                  StatusReg = v176;
                }
              }
            }
          }
          goto LABEL_84;
        }
      }
      break;
    }
  }
LABEL_284:
  _ReadStatusReg(SP_EL0);
  return result;
}
