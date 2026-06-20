__int64 __fastcall ieee80211_prep_channel(__int64 a1, __int64 a2, unsigned int **a3, char a4, unsigned int *a5)
{
  __int64 v10; // x24
  int v11; // w26
  unsigned int *v12; // x8
  unsigned int *v13; // x25
  __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x0
  _QWORD *v17; // x22
  __int64 lock; // x0
  __int64 v19; // x2
  __int64 v20; // x3
  unsigned int v21; // w28
  __int64 v22; // x8
  __int64 v23; // x27
  unsigned int v24; // w8
  unsigned int v25; // w8
  _DWORD *v26; // x9
  __int64 v27; // x10
  __int64 v28; // x2
  __int64 v29; // x3
  __int64 v30; // x8
  int v31; // w8
  unsigned int v32; // w9
  unsigned int v33; // w10
  __int64 v34; // x9
  unsigned int v35; // w8
  unsigned int v36; // w9
  unsigned int v37; // w13
  __int64 v38; // x11
  unsigned int v39; // w14
  unsigned int v40; // w5
  unsigned int v41; // w5
  unsigned int v42; // w15
  unsigned int v43; // w5
  unsigned int v44; // w15
  unsigned int v45; // w5
  unsigned int v46; // w15
  unsigned int v47; // w5
  unsigned int v48; // w15
  unsigned int v49; // w5
  unsigned int v50; // w15
  unsigned int v51; // w5
  unsigned int v52; // w8
  unsigned int v53; // w5
  int v54; // w8
  unsigned int v55; // w8
  __int64 v56; // x9
  __int64 v57; // x13
  __int64 v58; // x12
  __int64 v59; // x14
  unsigned __int16 *v60; // x8
  __int64 v61; // x9
  __int64 v62; // x9
  int v63; // t1
  unsigned int v64; // w17
  unsigned int v65; // w9
  unsigned int v66; // w11
  unsigned int v67; // w12
  unsigned int v68; // w13
  unsigned int v69; // w14
  unsigned int v70; // w15
  unsigned int v71; // w16
  unsigned int v72; // w17
  __int64 v73; // x0
  unsigned int v74; // w1
  unsigned int v75; // w1
  int v76; // w9
  int v77; // w11
  unsigned __int8 *v78; // x8
  unsigned int v79; // w10
  __int64 v80; // x12
  _BYTE *v81; // x10
  __int64 v82; // x13
  __int64 v83; // x11
  __int64 v84; // x12
  _BYTE *v85; // x9
  unsigned int v86; // w11
  unsigned int v87; // w17
  unsigned int v88; // w15
  unsigned int v89; // w13
  unsigned int v90; // w16
  unsigned int v91; // w14
  char v92; // w11
  int v93; // w12
  int v94; // w11
  unsigned int v95; // w17
  unsigned int v96; // w16
  unsigned int v97; // w15
  unsigned int v98; // w16
  unsigned int v99; // w13
  unsigned int v100; // w13
  unsigned int v101; // w14
  unsigned int v102; // w13
  unsigned int v103; // w14
  unsigned int v104; // w15
  unsigned int v105; // w15
  unsigned int v106; // w15
  unsigned int v107; // w13
  unsigned int v108; // w8
  unsigned int v109; // w13
  unsigned int v110; // w12
  unsigned int v111; // w11
  unsigned int v112; // w9
  unsigned int v113; // w8
  _BYTE *v115; // x8
  unsigned int *v116; // x8
  unsigned __int64 v117; // x9
  __int64 v118; // x10
  __int64 v119; // x8
  unsigned __int64 v120; // x8
  int v121; // w8
  __int64 v122; // x0
  _QWORD *v123; // x8
  __int64 v124; // x12
  __int64 v125; // x9
  __int64 v126; // x11
  __int64 v127; // x9
  __int64 v128; // x11
  __int64 v129; // x12
  __int64 v130; // x9
  __int64 v131; // x11
  __int64 v132; // x12
  __int64 v133; // x0
  __int64 v134; // x1
  int v135; // w8
  unsigned int v136; // w8
  __int64 v137; // x8
  __int64 v138; // x0
  unsigned int *v139; // x8
  __int64 v140; // x2
  unsigned int v141; // w9
  unsigned int v142; // w8
  int v143; // w11
  int v144; // w9
  unsigned int v145; // w9
  int v146; // w8
  unsigned int v147; // w8
  unsigned int v148; // w8
  int v149; // w0
  char v150; // [xsp+14h] [xbp-BCh]
  _DWORD *v151; // [xsp+20h] [xbp-B0h] BYREF
  __int64 v152; // [xsp+28h] [xbp-A8h]
  __int64 v153; // [xsp+30h] [xbp-A0h]
  __int64 v154; // [xsp+38h] [xbp-98h]
  _DWORD *v155; // [xsp+40h] [xbp-90h] BYREF
  __int64 v156; // [xsp+48h] [xbp-88h]
  __int64 v157; // [xsp+50h] [xbp-80h]
  __int64 v158; // [xsp+58h] [xbp-78h]
  _DWORD *v159; // [xsp+60h] [xbp-70h]
  __int64 v160; // [xsp+68h] [xbp-68h]
  __int64 v161; // [xsp+70h] [xbp-60h]
  __int64 v162; // [xsp+78h] [xbp-58h]
  _QWORD v163[7]; // [xsp+80h] [xbp-50h] BYREF
  int v164; // [xsp+B8h] [xbp-18h]
  char v165; // [xsp+BCh] [xbp-14h]
  __int16 v166; // [xsp+BDh] [xbp-13h]
  char v167; // [xsp+BFh] [xbp-11h]
  __int64 v168; // [xsp+C0h] [xbp-10h]

  v168 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1616);
  v11 = **a3;
  v161 = 0;
  v162 = 0;
  v159 = nullptr;
  v160 = 0;
  v157 = 0;
  v158 = 0;
  v155 = nullptr;
  v156 = 0;
  v153 = 0;
  v154 = 0;
  v151 = nullptr;
  v152 = 0;
  _rcu_read_lock(a1, a2);
  v12 = a3[1];
  v13 = *a3;
  v14 = (__int64)v12 + 29;
  v15 = (int)v12[6];
  v163[0] = 0;
  v163[1] = v14;
  v163[2] = v15;
  memset(&v163[3], 0, 32);
  v164 = -1;
  v165 = 1;
  LODWORD(v15) = *a5;
  v166 = 0;
  v167 = 0;
  LODWORD(v163[0]) = v15;
  v16 = ieee802_11_parse_elems_full(v163);
  if ( !v16 )
  {
LABEL_260:
    LODWORD(v17) = -12;
    _rcu_read_unlock(v16);
    goto LABEL_261;
  }
  v17 = (_QWORD *)v16;
  v150 = a4;
  while ( 1 )
  {
    lock = ieee80211_determine_ap_chan(a1, v13, *((unsigned int *)a3 + 40), v17, 0, a5, &v151);
    if ( (unsigned int)lock > *a5 )
      goto LABEL_281;
    v21 = lock;
    if ( *a5 != (_DWORD)lock )
    {
      *a5 = lock;
      goto LABEL_4;
    }
    v22 = *v13;
    if ( (unsigned int)v22 >= 6 )
    {
      __break(0x5512u);
      goto LABEL_366;
    }
    v23 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL) + 8 * v22 + 328);
    if ( (_DWORD)v22 != 3 )
    {
      if ( (_DWORD)v22 == 4 )
      {
        if ( (_DWORD)lock )
          goto LABEL_281;
        goto LABEL_265;
      }
      if ( (int)lock <= 2 )
      {
        if ( (_DWORD)lock == 1 )
        {
          v24 = 0;
        }
        else
        {
          if ( (_DWORD)lock != 2 )
            goto LABEL_281;
          v24 = a5[1] != 0;
        }
LABEL_14:
        a5[1] = v24;
        v159 = nullptr;
        v155 = v151;
        v156 = v152;
        v157 = v153;
        v158 = v154;
        goto LABEL_21;
      }
      if ( (unsigned int)(lock - 3) < 2 )
        goto LABEL_12;
      goto LABEL_17;
    }
    if ( (unsigned int)lock <= 3 )
      break;
    if ( (_DWORD)lock != 5 )
    {
LABEL_12:
      v24 = a5[1];
      if ( v24 >= 3 )
        v24 = 3;
      goto LABEL_14;
    }
LABEL_17:
    v25 = a5[1];
    v159 = nullptr;
    if ( v25 >= 4 )
      v25 = 4;
    v26 = v151;
    v27 = v152;
    a5[1] = v25;
    v155 = v26;
    v156 = v27;
    LOBYTE(v27) = *(_BYTE *)(a1 + 5872);
    v157 = v153;
    v158 = v154;
    if ( (v27 & 0x20) == 0 )
    {
      v159 = v151;
      v160 = v152;
      v161 = v153;
      v162 = v154;
    }
LABEL_21:
    while ( 1 )
    {
      if ( (cfg80211_chandef_usable(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), &v155, 1) & 1) != 0 )
      {
        if ( !HIWORD(v158) )
          break;
        v30 = *(_QWORD *)(a1 + 1616);
        if ( (*(_QWORD *)(v30 + 96) & 0x20000000000000LL) == 0
          && (*v155 != 1 || (*(_QWORD *)(v30 + 96) & 0x40000000000000LL) == 0) )
        {
          break;
        }
      }
      if ( !(_DWORD)v156 )
        goto LABEL_281;
      ieee80211_chandef_downgrade(&v155, a5);
      if ( a5 )
      {
        if ( *a5 <= 4 )
          v159 = nullptr;
      }
      else
      {
        __break(0x800u);
      }
    }
    if ( *a5 >= 4 )
    {
      if ( (cfg80211_chandef_usable(*(_QWORD *)(a1 + 16), &v155, 0x2000) & 1) != 0 )
      {
        if ( *a5 < 5 || (cfg80211_chandef_usable(*(_QWORD *)(a1 + 16), &v155, 0x100000) & 1) != 0 )
          goto LABEL_40;
        v31 = 4;
      }
      else
      {
        v31 = 3;
      }
      v32 = a5[1];
      if ( v32 >= 3 )
        v32 = 3;
      *a5 = v31;
      a5[1] = v32;
    }
LABEL_40:
    if ( (_DWORD)v156 == (_DWORD)v152 && (v33 = v21, v21 == *a5) )
    {
      if ( v21 < 4 )
        goto LABEL_257;
    }
    else
    {
      printk(&unk_BBD68, a1 + 1640, v28, v29);
      v33 = *a5;
      if ( *a5 < 4 )
        goto LABEL_257;
    }
    v34 = v17[21];
    if ( !v34 )
      goto LABEL_158;
    v35 = *(unsigned __int16 *)(v34 + 19);
    v36 = *(unsigned __int16 *)(v34 + 17);
    v37 = v35 & 3;
    if ( v37 == 3 || (v36 & 3) == 3 )
    {
      printk(&unk_BC03A, a1 + 1640, v35, v36);
      goto LABEL_158;
    }
    v38 = v17[22];
    if ( v38 )
    {
      v39 = *(unsigned __int16 *)(v38 + 4);
      if ( *(_WORD *)(v38 + 4) )
      {
        v40 = v39 >> 14;
        if ( v39 >> 14 != 3 )
        {
          v29 = v36 >> 14;
          v28 = 8;
          if ( v35 >> 14 < v40 || v35 >> 14 == 3 || (_DWORD)v29 == 3 || (unsigned int)v29 < v40 )
            goto LABEL_157;
        }
        v41 = (v39 >> 12) & 3;
        if ( v41 != 3 )
        {
          v42 = (v35 >> 12) & 3;
          v29 = (v36 >> 12) & 3;
          v28 = 7;
          if ( v42 < v41 || v42 == 3 || (_DWORD)v29 == 3 || (unsigned int)v29 < v41 )
            goto LABEL_157;
        }
        v43 = (v39 >> 10) & 3;
        if ( v43 != 3 )
        {
          v44 = (v35 >> 10) & 3;
          v29 = (v36 >> 10) & 3;
          v28 = 6;
          if ( v44 < v43 || v44 == 3 || (_DWORD)v29 == 3 || (unsigned int)v29 < v43 )
            goto LABEL_157;
        }
        v45 = (v39 >> 8) & 3;
        if ( v45 != 3 )
        {
          v46 = (v35 >> 8) & 3;
          v29 = (v36 >> 8) & 3;
          v28 = 5;
          if ( v46 < v45 || v46 == 3 || (_DWORD)v29 == 3 || (unsigned int)v29 < v45 )
            goto LABEL_157;
        }
        v47 = (unsigned __int8)v39 >> 6;
        if ( v47 != 3 )
        {
          v48 = (unsigned __int8)v35 >> 6;
          v29 = (unsigned __int8)v36 >> 6;
          v28 = 4;
          if ( v48 < v47 || v48 == 3 || (_DWORD)v29 == 3 || (unsigned int)v29 < v47 )
            goto LABEL_157;
        }
        v49 = (v39 >> 4) & 3;
        if ( v49 != 3 )
        {
          v50 = (v35 >> 4) & 3;
          v29 = (v36 >> 4) & 3;
          v28 = 3;
          if ( v50 < v49 || v50 == 3 || (_DWORD)v29 == 3 || (unsigned int)v29 < v49 )
            goto LABEL_157;
        }
        v51 = (v39 >> 2) & 3;
        if ( v51 != 3 )
        {
          v52 = (v35 >> 2) & 3;
          v29 = (v36 >> 2) & 3;
          v28 = 2;
          if ( v52 < v51 || v52 == 3 || (_DWORD)v29 == 3 || (unsigned int)v29 < v51 )
            goto LABEL_157;
        }
        v53 = v39 & 3;
        if ( v53 != 3 )
        {
          v28 = 1;
          if ( (v36 & 3) < v53 )
          {
            v29 = v36 & 3;
LABEL_157:
            printk(&unk_B8A6A, a1 + 1640, v28, v29);
            goto LABEL_158;
          }
          v29 = v36 & 3;
          if ( v37 < v53 )
            goto LABEL_157;
        }
      }
    }
    v54 = *(_DWORD *)(a1 + 4720);
    if ( *(_BYTE *)(a1 + 5848) == 1 )
    {
      if ( v54 == 2 )
      {
        v55 = 8;
        v56 = *(unsigned __int16 *)(v23 + 92);
        if ( !*(_WORD *)(v23 + 92) )
          goto LABEL_158;
LABEL_93:
        v57 = *(_QWORD *)(v23 + 96);
        v58 = 0;
        if ( v55 == 4 )
          LOBYTE(v55) = 3;
        v59 = 1LL << v55;
        v60 = (unsigned __int16 *)(v57 + 22);
        while ( ((unsigned __int16)v59 & *(_WORD *)(v57 + (v58 << 7))) == 0 )
        {
          ++v58;
          v60 += 64;
          if ( v58 == v56 )
            goto LABEL_158;
        }
        v61 = v57 + (v58 << 7);
        if ( v61 )
        {
          v63 = *(unsigned __int8 *)(v61 + 2);
          v62 = v61 + 2;
          if ( v63 == 1 && v38 && v62 )
          {
            v64 = *(unsigned __int16 *)(v38 + 4);
            if ( *(_WORD *)(v38 + 4) )
            {
              v65 = v64 >> 14;
              v66 = (v64 >> 12) & 3;
              v67 = (v64 >> 10) & 3;
              v68 = (v64 >> 8) & 3;
              v69 = (unsigned __int8)v64 >> 6;
              v70 = (v64 >> 4) & 3;
              v71 = (v64 >> 2) & 3;
              v72 = v64 & 3;
              v73 = 3;
              while ( 1 )
              {
                v28 = *(v60 - 1);
                v74 = *v60;
                if ( v65 == 3
                  || (v29 = (unsigned int)v28 >> 14, v65 <= (unsigned int)v29)
                  && (_DWORD)v29 != 3
                  && (v29 = v74 >> 14, (_DWORD)v29 != 3)
                  && v65 <= (unsigned int)v29 )
                {
                  if ( v66 == 3
                    || (v29 = ((unsigned int)v28 >> 12) & 3, v66 <= (unsigned int)v29)
                    && (_DWORD)v29 != 3
                    && (v29 = (v74 >> 12) & 3, (_DWORD)v29 != 3)
                    && v66 <= (unsigned int)v29 )
                  {
                    if ( v67 == 3
                      || (v29 = ((unsigned int)v28 >> 10) & 3, v67 <= (unsigned int)v29)
                      && (_DWORD)v29 != 3
                      && (v29 = (v74 >> 10) & 3, (_DWORD)v29 != 3)
                      && v67 <= (unsigned int)v29 )
                    {
                      if ( v68 == 3
                        || (v29 = ((unsigned int)v28 >> 8) & 3, v68 <= (unsigned int)v29)
                        && (_DWORD)v29 != 3
                        && (v29 = (v74 >> 8) & 3, (_DWORD)v29 != 3)
                        && v68 <= (unsigned int)v29 )
                      {
                        if ( v69 == 3
                          || (v29 = (unsigned __int8)v28 >> 6, v69 <= (unsigned int)v29)
                          && (_DWORD)v29 != 3
                          && (v29 = (unsigned __int8)v74 >> 6, (_DWORD)v29 != 3)
                          && v69 <= (unsigned int)v29 )
                        {
                          if ( v70 == 3
                            || (v29 = ((unsigned int)v28 >> 4) & 3, v70 <= (unsigned int)v29)
                            && (_DWORD)v29 != 3
                            && (v29 = (v74 >> 4) & 3, (_DWORD)v29 != 3)
                            && v70 <= (unsigned int)v29 )
                          {
                            if ( v71 == 3
                              || (v29 = ((unsigned int)v28 >> 2) & 3, v71 <= (unsigned int)v29)
                              && (_DWORD)v29 != 3
                              && (v29 = (v74 >> 2) & 3, (_DWORD)v29 != 3)
                              && v71 <= (unsigned int)v29 )
                            {
                              if ( v72 == 3 )
                                break;
                              v28 &= 3u;
                              if ( v72 <= (unsigned int)v28 && (_DWORD)v28 != 3 )
                              {
                                v75 = v74 & 3;
                                if ( v75 != 3 && v72 <= v75 )
                                  break;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                --v73;
                v60 += 2;
                if ( !v73 )
                  goto LABEL_158;
              }
            }
            goto LABEL_159;
          }
        }
        goto LABEL_158;
      }
      if ( v54 == 3 )
      {
        v55 = 9;
        v56 = *(unsigned __int16 *)(v23 + 92);
        if ( !*(_WORD *)(v23 + 92) )
          goto LABEL_158;
        goto LABEL_93;
      }
    }
    v55 = (unsigned __int8)*(_DWORD *)(a1 + 4720);
    if ( v55 >= 0xC )
    {
      __break(0x800u);
      goto LABEL_158;
    }
    v56 = *(unsigned __int16 *)(v23 + 92);
    if ( *(_WORD *)(v23 + 92) )
      goto LABEL_93;
LABEL_158:
    *a5 = 3;
    printk(&unk_B846F, a1 + 1640, v28, v29);
    v33 = *a5;
LABEL_159:
    if ( v33 < 5 )
      goto LABEL_257;
    v76 = *(_DWORD *)(a1 + 4720);
    v77 = *(unsigned __int8 *)(a1 + 5848);
    v78 = (unsigned __int8 *)v17[55];
    if ( v77 != 1 )
      goto LABEL_165;
    if ( v76 == 2 )
    {
      v79 = 8;
      v80 = *(unsigned __int16 *)(v23 + 92);
      if ( !*(_WORD *)(v23 + 92) )
      {
LABEL_164:
        v81 = nullptr;
LABEL_175:
        if ( !*(_BYTE *)(a1 + 5848) )
          goto LABEL_188;
        goto LABEL_182;
      }
      goto LABEL_167;
    }
    if ( v76 == 3 )
    {
      v79 = 9;
      v80 = *(unsigned __int16 *)(v23 + 92);
      if ( !*(_WORD *)(v23 + 92) )
        goto LABEL_164;
    }
    else
    {
LABEL_165:
      v79 = (unsigned __int8)*(_DWORD *)(a1 + 4720);
      if ( v79 >= 0xC )
      {
        __break(0x800u);
        v76 = *(_DWORD *)(a1 + 4720);
        v81 = nullptr;
        if ( (*(_BYTE *)(a1 + 5848) & 1) == 0 )
          goto LABEL_188;
        goto LABEL_182;
      }
      v80 = *(unsigned __int16 *)(v23 + 92);
      if ( !*(_WORD *)(v23 + 92) )
        goto LABEL_164;
    }
LABEL_167:
    if ( v79 == 4 )
      LOBYTE(v79) = 3;
    v82 = 1LL << v79;
    v81 = (_BYTE *)(*(_QWORD *)(v23 + 96) + 2LL);
    while ( ((unsigned __int16)v82 & *((_WORD *)v81 - 1)) == 0 )
    {
      --v80;
      v81 += 128;
      if ( !v80 )
        goto LABEL_177;
    }
    if ( v81 != byte_2 )
    {
      if ( (*v81 & 1) != 0 )
        goto LABEL_175;
LABEL_177:
      v81 = nullptr;
      if ( (v77 & 1) != 0 )
        goto LABEL_182;
      goto LABEL_188;
    }
    v81 = nullptr;
    if ( !*(_BYTE *)(a1 + 5848) )
      goto LABEL_188;
LABEL_182:
    if ( v76 == 2 )
    {
      v76 = 8;
      goto LABEL_189;
    }
    if ( v76 == 3 )
    {
      v76 = 9;
      goto LABEL_189;
    }
LABEL_188:
    v76 = (unsigned __int8)v76;
    if ( (unsigned __int8)v76 >= 0xCu )
    {
      __break(0x800u);
      goto LABEL_254;
    }
LABEL_189:
    v83 = *(unsigned __int16 *)(v23 + 92);
    if ( !*(_WORD *)(v23 + 92) )
      goto LABEL_254;
    if ( v76 == 4 )
      LOBYTE(v76) = 3;
    v84 = 1LL << v76;
    v85 = (_BYTE *)(*(_QWORD *)(v23 + 96) + 59LL);
    while ( ((unsigned __int16)v84 & *(_WORD *)(v85 - 59)) == 0 )
    {
      --v83;
      v85 += 128;
      if ( !v83 )
        goto LABEL_254;
    }
    if ( v85 == (_BYTE *)&unk_3B )
      goto LABEL_254;
    if ( *v85 != 1 )
      goto LABEL_254;
    if ( !v78 )
      goto LABEL_254;
    if ( !v81 )
      goto LABEL_254;
    if ( !v85 )
      goto LABEL_254;
    v86 = v78[1];
    v87 = (unsigned __int8)v85[12];
    v88 = v86 & 0xF;
    v89 = v87 & 0xF;
    if ( v88 > v89 )
      goto LABEL_254;
    v90 = v86 >> 4;
    v91 = v87 >> 4;
    if ( v86 >> 4 > v87 >> 4 )
      goto LABEL_254;
    v92 = v81[7];
    v93 = v92 & 0x1E;
    v94 = v92 & 0x18;
    if ( v93 )
    {
      if ( v94 )
      {
        v95 = (unsigned __int8)v85[15];
        if ( v88 > (v95 & 0xF) || v90 > v95 >> 4 )
          goto LABEL_254;
      }
      if ( (v85[3] & 2) != 0 )
        v87 = (unsigned __int8)v85[18];
      else
        v87 = 255;
    }
    if ( v88 <= (v87 & 0xF) && v90 <= v87 >> 4 )
    {
      v96 = v78[2];
      v97 = v96 >> 4;
      v98 = v96 & 0xF;
      if ( v93 )
      {
        if ( v98 > v89 )
          goto LABEL_254;
        if ( v97 > v91 )
          goto LABEL_254;
        if ( v94 )
        {
          v99 = (unsigned __int8)v85[15];
          if ( v98 > (v99 & 0xF) || v97 > v99 >> 4 )
            goto LABEL_254;
        }
        v100 = (v85[3] & 2) != 0 ? (unsigned __int8)v85[18] : 255;
      }
      else
      {
        v100 = (unsigned __int8)v85[13];
        if ( v98 > (v100 & 0xF) || v97 > v100 >> 4 )
          goto LABEL_254;
      }
      if ( v98 <= (v100 & 0xF) && v97 <= v100 >> 4 )
      {
        v101 = v78[3];
        v102 = v101 >> 4;
        v103 = v101 & 0xF;
        if ( v93 )
        {
          v104 = (unsigned __int8)v85[13];
          if ( v103 > (v104 & 0xF) )
            goto LABEL_254;
          if ( v102 > v104 >> 4 )
            goto LABEL_254;
          if ( v94 )
          {
            v105 = (unsigned __int8)v85[16];
            if ( v103 > (v105 & 0xF) || v102 > v105 >> 4 )
              goto LABEL_254;
          }
          if ( (v85[3] & 2) != 0 )
            v106 = (unsigned __int8)v85[19];
          else
            v106 = 255;
        }
        else
        {
          v106 = (unsigned __int8)v85[14];
          if ( v103 > (v106 & 0xF) || v102 > v106 >> 4 )
            goto LABEL_254;
        }
        if ( v103 <= (v106 & 0xF) && v102 <= v106 >> 4 )
        {
          v107 = v78[4];
          v108 = v107 >> 4;
          v109 = v107 & 0xF;
          if ( v93 )
          {
            v110 = (unsigned __int8)v85[14];
            if ( v109 <= (v110 & 0xF) && v108 <= v110 >> 4 )
            {
              if ( !v94 || (v111 = (unsigned __int8)v85[17], v109 <= (v111 & 0xF)) && v108 <= v111 >> 4 )
              {
                if ( (v85[3] & 2) != 0 )
                  v112 = (unsigned __int8)v85[20];
                else
                  v112 = 255;
LABEL_252:
                if ( v109 <= (v112 & 0xF) && v108 <= v112 >> 4 )
                  goto LABEL_257;
              }
            }
          }
          else
          {
            v112 = (unsigned __int8)v85[15];
            if ( v109 <= (v112 & 0xF) && v108 <= v112 >> 4 )
              goto LABEL_252;
          }
        }
      }
    }
LABEL_254:
    v113 = a5[1];
    if ( v113 >= 3 )
      v113 = 3;
    *a5 = 4;
    a5[1] = v113;
    printk(&unk_B9BB5, a1 + 1640, v28, v29);
LABEL_257:
    if ( v21 == *a5 )
    {
      lock = cfg80211_chandef_valid(&v155);
      if ( (lock & 1) == 0 )
      {
LABEL_281:
        __break(0x800u);
        goto LABEL_282;
      }
LABEL_265:
      if ( (unsigned __int64)v17 >= 0xFFFFFFFFFFFFF001LL )
      {
        _rcu_read_unlock(lock);
        goto LABEL_261;
      }
      if ( (v150 & 1) != 0 && !v17[56] )
      {
        v138 = printk(&unk_BCB35, a1 + 1640, v19, v20);
        _rcu_read_unlock(v138);
        kfree(v17);
        LODWORD(v17) = -22;
        goto LABEL_261;
      }
      if ( a2 && v11 == 3 && *a5 >= 4 )
      {
        v115 = (_BYTE *)v17[39];
        if ( v115 )
          *(_BYTE *)(*(_QWORD *)(a2 + 944) + 828LL) = *v115;
        v116 = (unsigned int *)v17[22];
        if ( !v116 )
          goto LABEL_307;
        v117 = *v116;
        if ( (v117 & 0x20000) == 0 )
          goto LABEL_307;
        v118 = 9;
        if ( (v117 & 0x4000) == 0 )
          v118 = 6;
        v119 = (__int64)v116 + v118 + ((v117 >> 15) & 1);
        if ( v119 )
        {
          v120 = ((unsigned __int64)*(unsigned __int8 *)(v119 + 1) >> 3) & 7;
          if ( (unsigned int)v120 > 4 )
            v121 = 0;
          else
            v121 = dword_C0818[v120];
          *(_DWORD *)(*(_QWORD *)(a2 + 944) + 720LL) = v121;
        }
        else
        {
LABEL_307:
          v137 = *(_QWORD *)a2;
          if ( *(_WORD *)(*(_QWORD *)a2 + 5800LL) )
            printk(&unk_BA3A0, v137 + 1640, *(unsigned int *)(a2 + 8), (*a3)[1]);
          else
            printk(&unk_BA650, v137 + 1640, (*a3)[1], v20);
        }
        v123 = (_QWORD *)(*(_QWORD *)(a2 + 944) + 724LL);
        *v123 = v17[61];
        v124 = v17[63];
        v125 = v17[65];
        v126 = v17[62];
        v123[3] = v17[64];
        v123[4] = v125;
        v123[1] = v126;
        v123[2] = v124;
        v127 = v17[69];
        v128 = v17[66];
        v129 = v17[67];
        v123[7] = v17[68];
        v123[8] = v127;
        v123[5] = v128;
        v123[6] = v129;
        v130 = v17[73];
        v131 = v17[70];
        v132 = v17[71];
        v123[11] = v17[72];
        v123[12] = v130;
        v123[9] = v131;
        v123[10] = v132;
        lock = ieee80211_rearrange_tpe(*(_QWORD *)(a2 + 944) + 724LL);
      }
      _rcu_read_unlock(lock);
      v133 = kfree(v17);
      if ( !a2 )
      {
        LODWORD(v17) = 0;
        goto LABEL_261;
      }
      lock = _rcu_read_lock(v133, v134);
      if ( *(_DWORD *)(a2 + 552) < 2u )
      {
        LOBYTE(v17) = 1;
LABEL_369:
        v148 = *(unsigned __int8 *)(v10 + 1504);
        if ( (unsigned __int8)v17 < v148 )
          LOBYTE(v148) = (_BYTE)v17;
        *(_BYTE *)(a2 + 442) = v148;
        _rcu_read_unlock(lock);
        v149 = ieee80211_link_use_channel(a2, (__int64 *)&v155, 0, 0);
        LODWORD(v17) = v149;
        if ( (v156 & 0xFFFFFFFE) != 6 && v149 && (_DWORD)v156 )
        {
          do
          {
            ieee80211_chandef_downgrade(&v155, a5);
            if ( a5 )
            {
              if ( *a5 <= 4 )
                v159 = nullptr;
            }
            else
            {
              __break(0x800u);
            }
            LODWORD(v17) = ieee80211_link_use_channel(a2, (__int64 *)&v155, 0, 0);
          }
          while ( (_DWORD)v17 && (_DWORD)v156 );
        }
        goto LABEL_261;
      }
      lock = ieee80211_bss_get_elem(a3, 45);
      if ( lock && *(unsigned __int8 *)(lock + 1) >= 0x1Au )
      {
        lock = ieee80211_mcs_to_chains(lock + 5);
        LOBYTE(v17) = lock;
      }
      else
      {
        LOBYTE(v17) = 1;
      }
      if ( *(_DWORD *)(a2 + 552) < 3u )
        goto LABEL_369;
      lock = ieee80211_bss_get_elem(a3, 191);
      if ( lock && *(unsigned __int8 *)(lock + 1) >= 0xCu )
      {
        v135 = *(unsigned __int16 *)(lock + 10);
        if ( (~v135 & 0xC000) != 0 )
        {
          v136 = 8;
        }
        else if ( (~v135 & 0x3000) != 0 )
        {
          v136 = 7;
        }
        else if ( (~v135 & 0xC00) != 0 )
        {
          v136 = 6;
        }
        else if ( (~v135 & 0x300) != 0 )
        {
          v136 = 5;
        }
        else if ( (~v135 & 0xC0) != 0 )
        {
          v136 = 4;
        }
        else if ( (~v135 & 0x30) != 0 )
        {
          v136 = 3;
        }
        else
        {
          v136 = (~v135 & 0xC) != 0 ? 2 : (~v135 & 3) != 0;
        }
        if ( (unsigned __int8)v17 <= v136 )
          LOBYTE(v17) = v136;
      }
      if ( *(_DWORD *)(a2 + 552) < 4u )
        goto LABEL_369;
      v139 = a3[1];
      v140 = v139[6];
      LOBYTE(v163[0]) = 35;
      lock = cfg80211_find_elem_match(255, (char *)v139 + 29, v140, v163, 1, 0);
      if ( !lock )
        goto LABEL_369;
      v141 = *(unsigned __int8 *)(lock + 1);
      if ( v141 < 0x11 )
        goto LABEL_369;
      v142 = *(unsigned __int8 *)(lock + 9);
      v143 = (v142 & 8) != 0 ? 8 : 4;
      if ( v141 < v143 + ((v142 >> 2) & 4) + 18 )
        goto LABEL_369;
      v144 = *(unsigned __int16 *)(lock + 22);
      if ( (~v144 & 0xC000) != 0 )
      {
        v145 = 8;
      }
      else if ( (~v144 & 0x3000) != 0 )
      {
        v145 = 7;
      }
      else if ( (~v144 & 0xC00) != 0 )
      {
        v145 = 6;
      }
      else if ( (~v144 & 0x300) != 0 )
      {
        v145 = 5;
      }
      else if ( (~v144 & 0xC0) != 0 )
      {
        v145 = 4;
      }
      else if ( (~v144 & 0x30) != 0 )
      {
        v145 = 3;
      }
      else if ( (~v144 & 0xC) != 0 )
      {
        v145 = 2;
      }
      else
      {
        if ( (~v144 & 3) == 0 )
          goto LABEL_348;
        v145 = 1;
      }
      if ( v145 > (unsigned __int8)v17 )
        LOBYTE(v17) = v145;
LABEL_348:
      if ( (v142 & 8) == 0 )
        goto LABEL_369;
      v146 = *(unsigned __int16 *)(lock + 26);
      if ( (~v146 & 0xC000) != 0 )
      {
        v147 = 8;
      }
      else if ( (~v146 & 0x3000) != 0 )
      {
        v147 = 7;
      }
      else if ( (~v146 & 0xC00) != 0 )
      {
        v147 = 6;
      }
      else if ( (~v146 & 0x300) != 0 )
      {
        v147 = 5;
      }
      else if ( (~v146 & 0xC0) != 0 )
      {
        v147 = 4;
      }
      else if ( (~v146 & 0x30) != 0 )
      {
        v147 = 3;
      }
      else if ( (~v146 & 0xC) != 0 )
      {
        v147 = 2;
      }
      else
      {
        if ( (~v146 & 3) == 0 )
          goto LABEL_369;
LABEL_366:
        v147 = 1;
      }
      if ( v147 > (unsigned __int8)v17 )
        LOBYTE(v17) = v147;
      goto LABEL_369;
    }
LABEL_4:
    kfree(v17);
    LODWORD(v163[0]) = *a5;
    v16 = ieee802_11_parse_elems_full(v163);
    v17 = (_QWORD *)v16;
    if ( !v16 )
      goto LABEL_260;
  }
  printk(&unk_B9B8B, a1 + 1640, v19, v20);
LABEL_282:
  v122 = kfree(v17);
  LODWORD(v17) = -22;
  _rcu_read_unlock(v122);
LABEL_261:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v17;
}
