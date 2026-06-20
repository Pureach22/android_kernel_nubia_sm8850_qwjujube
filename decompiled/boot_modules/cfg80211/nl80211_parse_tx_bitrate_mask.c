__int64 __fastcall nl80211_parse_tx_bitrate_mask(
        _QWORD *a1,
        __int64 a2,
        unsigned int a3,
        char *s,
        __int64 a5,
        char a6,
        unsigned int a7)
{
  __int64 v9; // x8
  __int64 v10; // x25
  __int64 v11; // x2
  unsigned __int64 v12; // x26
  __int64 v13; // x8
  __int64 v15; // x23
  char *v16; // x22
  __int64 v17; // x9
  unsigned int v18; // w9
  __int64 v19; // x8
  __int64 v20; // x9
  _BYTE *v21; // x23
  __int64 v22; // x0
  int v23; // w8
  __int64 v24; // x9
  _WORD *v26; // x8
  int v27; // w24
  unsigned __int16 *v28; // x26
  __int64 v29; // x28
  unsigned int v30; // w9
  __int64 result; // x0
  __int64 v32; // x27
  __int64 v33; // x23
  __int64 v34; // x2
  __int64 v35; // x14
  _WORD *v36; // x8
  __int64 v37; // x12
  __int64 v38; // x11
  int v39; // w10
  unsigned __int16 *v40; // x16
  int v41; // t1
  _BYTE *v42; // x11
  char v43; // w9
  char *v44; // x8
  unsigned __int8 v45; // w10
  char *v46; // x8
  unsigned __int64 v47; // x12
  unsigned __int64 v50; // x13
  int v51; // w15
  __int64 v52; // x16
  _BYTE *v53; // x11
  __int64 v54; // x14
  __int64 v55; // x16
  unsigned __int64 v56; // x13
  char v57; // w17
  unsigned __int16 *v58; // x19
  int v59; // w8
  __int64 v60; // x0
  char *v61; // x21
  int v62; // w8
  int v63; // w8
  int v64; // w8
  int v65; // w8
  int v66; // w8
  int v67; // w8
  int v68; // w8
  int v69; // w8
  unsigned int v70; // w8
  __int64 v71; // x22
  unsigned __int16 *v72; // x28
  unsigned int v73; // w9
  __int64 v74; // x8
  char *v75; // x19
  __int64 v76; // x9
  _BYTE *v77; // x21
  __int64 v78; // x0
  int v79; // w8
  __int64 v80; // x9
  __int64 v81; // x8
  int v82; // w8
  int v83; // w8
  int v84; // w8
  int v85; // w8
  int v86; // w8
  int v87; // w8
  int v88; // w8
  int v89; // w8
  char *v90; // x19
  __int64 v91; // x8
  __int64 v92; // x8
  __int64 v93; // [xsp+8h] [xbp-78h]
  __int64 v98; // [xsp+28h] [xbp-58h] BYREF
  _BYTE *v99; // [xsp+30h] [xbp-50h]
  _BYTE *v100; // [xsp+38h] [xbp-48h]
  unsigned __int16 *v101; // [xsp+40h] [xbp-40h]
  __int64 v102; // [xsp+48h] [xbp-38h]
  unsigned __int16 *v103; // [xsp+50h] [xbp-30h]
  __int64 v104; // [xsp+58h] [xbp-28h]
  __int64 v105; // [xsp+60h] [xbp-20h]
  __int64 v106; // [xsp+68h] [xbp-18h] BYREF
  __int64 v107; // [xsp+70h] [xbp-10h]
  __int64 v108; // [xsp+78h] [xbp-8h]

  v108 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[6];
  v98 = 0;
  v10 = *(_QWORD *)(a5 + 992);
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = nullptr;
  v100 = nullptr;
  v101 = nullptr;
  v93 = v9;
  v99 = nullptr;
  memset(s, 0, 0x168u);
  if ( (a6 & 1) != 0 )
  {
    v12 = 0;
    do
    {
      v15 = *(_QWORD *)(v93 + 1320 + 8 * v12);
      if ( v15 )
      {
        v16 = &s[60 * v12];
        *(_DWORD *)v16 = ~(-1 << *(_DWORD *)(v15 + 24));
        v17 = *(_QWORD *)(v15 + 33);
        *((_WORD *)v16 + 6) = *(_WORD *)(v15 + 41);
        *(_QWORD *)(v16 + 4) = v17;
        if ( *(_BYTE *)(v15 + 52) == 1 )
          vht_build_mcs_mask(*(unsigned __int16 *)(v15 + 64), v16 + 14);
        v18 = *(unsigned __int8 *)(v10 + 8);
        if ( v18 >= 0xC )
        {
          __break(0x800u);
        }
        else
        {
          v19 = *(unsigned __int16 *)(v15 + 92);
          if ( *(_WORD *)(v15 + 92) )
          {
            if ( v18 == 4 )
              LOBYTE(v18) = 3;
            v20 = 1LL << v18;
            v21 = (_BYTE *)(*(_QWORD *)(v15 + 96) + 2LL);
            while ( ((unsigned __int16)v20 & *((_WORD *)v21 - 1)) == 0 )
            {
              --v19;
              v21 += 128;
              if ( !v19 )
                goto LABEL_5;
            }
            if ( v21 != (_BYTE *)&_ksymtab___cfg80211_alloc_event_skb + 2 && v21 && (*v21 & 1) != 0 )
            {
              v22 = wdev_chandef(*(_QWORD *)(a1[7] + 992LL), a7, v11);
              if ( v22 )
              {
                v23 = *(_DWORD *)(v22 + 8);
                v24 = 20;
                if ( v23 == 5 )
                  v24 = 24;
                _ZF = v23 == 4;
                v13 = 28;
                if ( !_ZF )
                  v13 = v24;
              }
              else
              {
                v13 = 20;
              }
              he_build_mcs_mask(*(unsigned __int16 *)&v21[v13], v16 + 30);
              *(_QWORD *)(v16 + 52) = 0xFF000000FFLL;
            }
          }
        }
      }
LABEL_5:
      ;
    }
    while ( v12++ < 5 );
  }
  v26 = *(_WORD **)(a2 + 8LL * a3);
  if ( !v26 || (v27 = (unsigned __int16)(*v26 - 4), (unsigned int)v27 < 4) )
  {
LABEL_136:
    result = 0;
    goto LABEL_139;
  }
  v28 = v26 + 2;
  v29 = v93 + 1320;
  while ( 1 )
  {
    v30 = *v28;
    result = 0;
    if ( v30 < 4 || v27 < v30 )
      goto LABEL_139;
    v32 = v28[1] & 0x3FFF;
    if ( (unsigned int)v32 > 5 )
      goto LABEL_138;
    v33 = *(_QWORD *)(v29 + 8 * v32);
    if ( !v33 )
      goto LABEL_138;
    result = _nla_parse(&v98, 7, v28 + 2, (unsigned __int16)(v30 - 4), &nl80211_txattr_policy, 0, a1[8]);
    if ( (_DWORD)result )
      goto LABEL_139;
    v36 = v99;
    if ( v99 )
    {
      if ( *v99 == 4 )
      {
LABEL_49:
        *(_DWORD *)&s[60 * (unsigned int)v32] = 0;
      }
      else
      {
        v37 = *(unsigned int *)(v33 + 24);
        v38 = 0;
        v39 = 0;
        do
        {
          if ( (int)v37 < 1 )
          {
            v35 = 0;
            if ( !(_DWORD)v37 )
              goto LABEL_49;
          }
          else
          {
            v35 = 0;
            v40 = (unsigned __int16 *)(*(_QWORD *)(v33 + 8) + 4LL);
            while ( 1 )
            {
              v41 = *v40;
              v40 += 6;
              if ( 5 * (*((_BYTE *)&_ksymtab___cfg80211_alloc_event_skb + (_QWORD)v99 + v38 + 4) & 0x7F) == v41 )
                break;
              if ( v37 == ++v35 )
                goto LABEL_49;
            }
            v39 |= 1 << v35;
            if ( (_DWORD)v35 == (_DWORD)v37 )
              goto LABEL_49;
          }
          ++v38;
        }
        while ( v38 != (unsigned __int8)(*v99 - 4) );
        *(_DWORD *)&s[60 * (unsigned int)v32] = v39;
        if ( v39 )
          goto LABEL_51;
      }
      if ( *v36 != 4 )
        goto LABEL_138;
    }
LABEL_51:
    v42 = v100;
    if ( v100 )
    {
      v43 = *v100;
      v44 = &s[60 * (unsigned int)v32];
      v45 = *v100 - 4;
      *(_QWORD *)(v44 + 4) = 0;
      v46 = v44 + 4;
      *((_WORD *)v46 + 4) = 0;
      if ( v43 != 4 )
      {
        v47 = (unsigned __int8)v42[4];
        if ( (unsigned int)v47 > 0x4F )
          goto LABEL_138;
        __asm { HINT            #0x14 }
        v50 = -(v35 + (v47 >> 3 < 0xA)) & (v47 >> 3);
        v51 = 1 << (v47 & 7);
        if ( ((unsigned __int8)v51 & *(_BYTE *)(v33 + 33 + v50)) == 0 )
          goto LABEL_138;
        v52 = 0;
        v53 = v42 + 5;
        do
        {
          v54 = v52;
          v55 = (unsigned __int8)v46[v50];
          v46[v50] = v55 | v51;
          if ( v45 - 1LL == v54 )
            break;
          v56 = (unsigned __int8)v53[v54];
          if ( (unsigned int)v56 > 0x4F )
            break;
          v57 = v56 & 7;
          __asm { HINT            #0x14 }
          v50 = -(v55 + (v56 >> 3 < 0xA)) & (v56 >> 3);
          v51 = 1 << v57;
          v52 = v54 + 1;
        }
        while ( ((1 << v57) & *(unsigned __int8 *)(v33 + 33 + v50)) != 0 );
        if ( v54 + 1 < (unsigned __int64)v45 )
          goto LABEL_138;
      }
    }
    v58 = v101;
    if ( v101 )
    {
      v59 = *(unsigned __int8 *)(v33 + 52);
      v60 = *(unsigned __int16 *)(v33 + 64);
      v106 = 0;
      v107 = 0;
      if ( v59 != 1 )
        goto LABEL_138;
      v61 = &s[60 * (unsigned int)v32];
      *(_QWORD *)(v61 + 22) = 0;
      *(_QWORD *)(v61 + 14) = 0;
      vht_build_mcs_mask(v60, &v106);
      v62 = v58[2];
      if ( (v62 & ~(unsigned __int16)v106) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 7) = v62;
      v63 = v58[3];
      if ( (v63 & ~WORD1(v106)) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 8) = v63;
      v64 = v58[4];
      if ( (v64 & ~WORD2(v106)) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 9) = v64;
      v65 = v58[5];
      if ( (v65 & ~HIWORD(v106)) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 10) = v65;
      v66 = v58[6];
      if ( (v66 & ~(unsigned __int16)v107) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 11) = v66;
      v67 = v58[7];
      if ( (v67 & ~WORD1(v107)) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 12) = v67;
      v68 = v58[8];
      if ( (v68 & ~WORD2(v107)) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 13) = v68;
      v69 = v58[9];
      if ( (v69 & ~HIWORD(v107)) != 0 )
        goto LABEL_138;
      *((_WORD *)v61 + 14) = v69;
    }
    if ( v102 )
    {
      v70 = *(unsigned __int8 *)(v102 + 4);
      *(_DWORD *)&s[60 * (unsigned int)v32 + 48] = v70;
      if ( v70 > 2 )
        goto LABEL_138;
    }
    v71 = v29;
    v72 = v103;
    if ( v103 )
    {
      v73 = *(unsigned __int8 *)(v10 + 8);
      v106 = 0;
      v107 = 0;
      if ( v73 >= 0xC )
      {
        __break(0x800u);
LABEL_138:
        result = 4294967274LL;
        goto LABEL_139;
      }
      v74 = *(unsigned __int16 *)(v33 + 92);
      if ( !*(_WORD *)(v33 + 92) )
        goto LABEL_138;
      v75 = &s[60 * (unsigned int)v32];
      if ( v73 == 4 )
        LOBYTE(v73) = 3;
      v76 = 1LL << v73;
      v77 = (_BYTE *)(*(_QWORD *)(v33 + 96) + 2LL);
      while ( ((unsigned __int16)v76 & *((_WORD *)v77 - 1)) == 0 )
      {
        --v74;
        v77 += 128;
        if ( !v74 )
          goto LABEL_138;
      }
      if ( v77 == (_BYTE *)&_ksymtab___cfg80211_alloc_event_skb + 2 || !v77 || (*v77 & 1) == 0 )
        goto LABEL_138;
      *(_QWORD *)(v75 + 38) = 0;
      *(_QWORD *)(v75 + 30) = 0;
      v78 = wdev_chandef(*(_QWORD *)(a1[7] + 992LL), a7, v34);
      if ( v78 )
      {
        v79 = *(_DWORD *)(v78 + 8);
        v80 = 20;
        if ( v79 == 5 )
          v80 = 24;
        _ZF = v79 == 4;
        v81 = 28;
        if ( !_ZF )
          v81 = v80;
      }
      else
      {
        v81 = 20;
      }
      he_build_mcs_mask(*(unsigned __int16 *)&v77[v81], &v106);
      v82 = v72[2];
      if ( (v82 & ~(unsigned __int16)v106) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 15) = v82;
      v83 = v72[3];
      if ( (v83 & ~WORD1(v106)) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 16) = v83;
      v84 = v72[4];
      if ( (v84 & ~WORD2(v106)) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 17) = v84;
      v85 = v72[5];
      if ( (v85 & ~HIWORD(v106)) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 18) = v85;
      v86 = v72[6];
      if ( (v86 & ~(unsigned __int16)v107) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 19) = v86;
      v87 = v72[7];
      if ( (v87 & ~WORD1(v107)) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 20) = v87;
      v88 = v72[8];
      if ( (v88 & ~WORD2(v107)) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 21) = v88;
      v89 = v72[9];
      if ( (v89 & ~HIWORD(v107)) != 0 )
        goto LABEL_138;
      *((_WORD *)v75 + 22) = v89;
    }
    if ( v104 )
      *(_DWORD *)&s[60 * (unsigned int)v32 + 52] = *(unsigned __int8 *)(v104 + 4);
    v29 = v71;
    if ( v105 )
      *(_DWORD *)&s[60 * (unsigned int)v32 + 56] = *(unsigned __int8 *)(v105 + 4);
    v90 = &s[60 * (unsigned int)v32];
    if ( !*(_DWORD *)v90 )
      break;
    result = 0;
    v91 = (*v28 + 3) & 0x1FFFC;
    v27 -= v91;
    v28 = (unsigned __int16 *)((char *)v28 + v91);
    if ( v27 <= 3 )
      goto LABEL_139;
  }
  v92 = *(_QWORD *)(v71 + 8 * v32);
  if ( (*(_BYTE *)(v92 + 30) & 1) == 0
    && (*(_BYTE *)(v92 + 52) & 1) == 0
    && !ieee80211_get_he_iftype_cap(v33, *(unsigned int *)(v10 + 8)) )
  {
    goto LABEL_138;
  }
  if ( v90[4]
    || v90[5]
    || v90[6]
    || v90[7]
    || v90[8]
    || v90[9]
    || v90[10]
    || v90[11]
    || v90[12]
    || v90[13]
    || *((_WORD *)v90 + 7)
    || *((_WORD *)v90 + 8)
    || *((_WORD *)v90 + 9)
    || *((_WORD *)v90 + 10)
    || *((_WORD *)v90 + 11)
    || *((_WORD *)v90 + 12)
    || *((_WORD *)v90 + 13)
    || *((_WORD *)v90 + 14)
    || *((_WORD *)v90 + 15)
    || *((_WORD *)v90 + 16)
    || *((_WORD *)v90 + 17)
    || *((_WORD *)v90 + 18)
    || *((_WORD *)v90 + 19)
    || *((_WORD *)v90 + 20)
    || *((_WORD *)v90 + 21) )
  {
    goto LABEL_136;
  }
  if ( *((_WORD *)v90 + 22) )
    result = 0;
  else
    result = 4294967274LL;
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return result;
}
