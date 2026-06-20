__int64 __fastcall ieee80211_assign_beacon(
        const void **a1,
        unsigned __int64 *a2,
        size_t a3,
        __int64 a4,
        __int64 a5,
        _QWORD *a6)
{
  unsigned __int64 v6; // x21
  __int64 v7; // x8
  size_t v10; // x22
  unsigned __int64 *v11; // x24
  size_t v13; // x28
  size_t v15; // x19
  _BYTE *v16; // x9
  _QWORD *v17; // x25
  int v18; // w8
  __int64 v19; // x10
  _BYTE *v20; // x0
  int v21; // w8
  __int64 v22; // x11
  int v23; // w9
  _BYTE *v24; // x9
  __int64 v25; // x10
  __int64 v26; // x11
  int v27; // w9
  int v28; // w12
  __int64 v29; // x14
  int *v30; // x13
  int v31; // w15
  int v32; // t1
  __int64 v33; // x10
  int *v34; // x11
  int v35; // t1
  __int64 v36; // x10
  __int64 v37; // x11
  int v38; // w12
  int *v39; // x13
  __int64 v40; // x14
  int v41; // w15
  int v42; // t1
  __int64 v43; // x10
  int *v44; // x11
  int v45; // t1
  int v46; // w9
  int v47; // w12
  __int64 v48; // x14
  int *v49; // x13
  int v50; // w15
  int v51; // t1
  __int64 v52; // x10
  int *v53; // x11
  int v54; // t1
  __int64 v55; // x10
  __int64 v56; // x11
  int v57; // w12
  int *v58; // x13
  __int64 v59; // x14
  int v60; // w15
  int v61; // t1
  __int64 v62; // x10
  int *v63; // x11
  int v64; // t1
  unsigned __int64 v65; // x27
  __int64 v66; // x0
  unsigned __int8 *v67; // x10
  __int64 v68; // x8
  __int64 v69; // x9
  size_t v70; // x2
  unsigned __int64 v71; // x9
  bool v72; // cf
  unsigned __int64 v73; // x9
  size_t v74; // x1
  unsigned __int64 v75; // x9
  unsigned __int64 v76; // x8
  unsigned __int64 v77; // x8
  unsigned __int64 v78; // x11
  __int64 v79; // x13
  _BYTE *v80; // x12
  __int64 v81; // x14
  size_t v82; // x13
  __int64 v83; // x8
  __int64 v84; // x9
  _BYTE *v85; // x11
  size_t v86; // x2
  unsigned __int64 v87; // x9
  unsigned __int64 v88; // x9
  size_t v89; // x1
  const void *v90; // x8
  unsigned __int64 v91; // x9
  size_t v92; // x9
  unsigned __int64 v93; // x8
  size_t v94; // x2
  void *v95; // x0
  const void **v96; // x8
  const void **v97; // x9
  __int64 v98; // x8
  unsigned __int64 v99; // x9
  _DWORD *v100; // x27
  __int64 v101; // x0
  size_t v102; // x1
  size_t v103; // x2
  size_t v104; // x1
  int v105; // w8
  size_t v106; // x10
  unsigned __int64 v107; // x27
  size_t v108; // x1
  unsigned __int64 v109; // x8
  unsigned __int64 v110; // x8
  size_t v111; // x1
  size_t v112; // x19
  size_t v113; // x19
  int v114; // w8
  unsigned __int64 StatusReg; // x20
  unsigned __int64 v116; // x22
  __int64 v117; // x21
  __int64 v118; // [xsp+0h] [xbp-A0h]
  __int64 v119; // [xsp+8h] [xbp-98h]
  _BYTE *v120; // [xsp+8h] [xbp-98h]
  __int64 v121; // [xsp+10h] [xbp-90h]
  __int64 v122; // [xsp+18h] [xbp-88h]
  __int64 v123; // [xsp+18h] [xbp-88h]
  _BYTE *v124; // [xsp+20h] [xbp-80h]
  size_t v125; // [xsp+20h] [xbp-80h]
  size_t v126; // [xsp+28h] [xbp-78h]
  unsigned __int64 v127; // [xsp+30h] [xbp-70h]
  _QWORD *v128; // [xsp+38h] [xbp-68h]
  unsigned __int64 *v129; // [xsp+40h] [xbp-60h]
  unsigned __int64 *v130; // [xsp+40h] [xbp-60h]
  size_t v131; // [xsp+48h] [xbp-58h]
  size_t v132; // [xsp+48h] [xbp-58h]
  const void **v133; // [xsp+50h] [xbp-50h]
  _QWORD *v134; // [xsp+58h] [xbp-48h]
  const void **v136; // [xsp+68h] [xbp-38h]
  const void **v137; // [xsp+70h] [xbp-30h]
  size_t v138; // [xsp+78h] [xbp-28h]
  __int64 v139; // [xsp+80h] [xbp-20h]
  _BYTE *v140; // [xsp+88h] [xbp-18h]
  __int64 v141; // [xsp+90h] [xbp-10h]
  __int64 v142; // [xsp+90h] [xbp-10h]
  _BYTE *v143; // [xsp+98h] [xbp-8h]

  v6 = a2[67];
  v7 = *(_QWORD *)(a3 + 8);
  if ( !(v7 | v6) )
    return 4294967274LL;
  v10 = a3;
  v11 = a2;
  if ( v7 )
    LODWORD(v13) = *(_DWORD *)(a3 + 96);
  else
    LODWORD(v13) = *(_DWORD *)(v6 + 16);
  if ( *(_QWORD *)(a3 + 16) || !v6 )
    LODWORD(v15) = *(_DWORD *)(a3 + 104);
  else
    LODWORD(v15) = *(_DWORD *)(v6 + 20);
  v16 = *(_BYTE **)(a3 + 72);
  v17 = (_QWORD *)a2[118];
  v18 = v13 + v15 + 72;
  v137 = (const void **)(a3 + 16);
  if ( !v16 )
  {
    if ( !v6 || (v24 = *(_BYTE **)(v6 + 40)) == nullptr )
    {
      v20 = nullptr;
      v143 = nullptr;
      goto LABEL_55;
    }
    v25 = (unsigned __int8)*v24;
    v20 = *(_BYTE **)(v6 + 48);
    v143 = *(_BYTE **)(v6 + 40);
    v21 = v18 + 16 * v25 + 8;
    if ( v20 )
      v21 += 16 * (unsigned __int8)*v20 + 8;
    if ( !*v24 )
      goto LABEL_23;
    if ( (_DWORD)v25 == 1 )
    {
      v26 = 0;
      v23 = 0;
    }
    else
    {
      v26 = (unsigned __int8)v25 & 0xFE;
      v46 = 0;
      v47 = 0;
      v48 = v26;
      v49 = (int *)(v143 + 32);
      do
      {
        v50 = *(v49 - 4);
        v51 = *v49;
        v49 += 8;
        v48 -= 2;
        v46 += v50;
        v47 += v51;
      }
      while ( v48 );
      v23 = v47 + v46;
      if ( v26 == v25 )
        goto LABEL_45;
    }
    v52 = v25 - v26;
    v53 = (int *)&v143[16 * v26 + 16];
    do
    {
      v54 = *v53;
      v53 += 4;
      --v52;
      v23 += v54;
    }
    while ( v52 );
LABEL_45:
    if ( !v20 )
      goto LABEL_54;
    v55 = (unsigned __int8)*v20;
    if ( !*v20 )
      goto LABEL_54;
    if ( (_DWORD)v55 == 1 )
    {
      v56 = 0;
    }
    else
    {
      v56 = (unsigned __int8)v55 & 0xFE;
      v57 = 0;
      v58 = (int *)(v20 + 32);
      v59 = v56;
      do
      {
        v60 = *(v58 - 4);
        v61 = *v58;
        v58 += 8;
        v59 -= 2;
        v23 += v60;
        v57 += v61;
      }
      while ( v59 );
      v23 += v57;
      if ( v56 == v55 )
        goto LABEL_54;
    }
    v62 = v55 - v56;
    v63 = (int *)&v20[16 * v56 + 16];
    do
    {
      v64 = *v63;
      v63 += 4;
      --v62;
      v23 += v64;
    }
    while ( v62 );
    goto LABEL_54;
  }
  v19 = (unsigned __int8)*v16;
  v20 = *(_BYTE **)(a3 + 80);
  v143 = *(_BYTE **)(a3 + 72);
  v21 = v18 + 16 * v19 + 8;
  if ( v20 )
    v21 += 16 * (unsigned __int8)*v20 + 8;
  if ( !*v16 )
  {
LABEL_23:
    v23 = 0;
    goto LABEL_54;
  }
  if ( (_DWORD)v19 == 1 )
  {
    v22 = 0;
    v23 = 0;
  }
  else
  {
    v22 = (unsigned __int8)v19 & 0xFE;
    v27 = 0;
    v28 = 0;
    v29 = v22;
    v30 = (int *)(v143 + 32);
    do
    {
      v31 = *(v30 - 4);
      v32 = *v30;
      v30 += 8;
      v29 -= 2;
      v27 += v31;
      v28 += v32;
    }
    while ( v29 );
    v23 = v28 + v27;
    if ( v22 == v19 )
      goto LABEL_30;
  }
  v33 = v19 - v22;
  v34 = (int *)&v143[16 * v22 + 16];
  do
  {
    v35 = *v34;
    v34 += 4;
    --v33;
    v23 += v35;
  }
  while ( v33 );
LABEL_30:
  if ( !v20 )
    goto LABEL_54;
  v36 = (unsigned __int8)*v20;
  if ( !*v20 )
    goto LABEL_54;
  if ( (_DWORD)v36 == 1 )
  {
    v37 = 0;
  }
  else
  {
    v37 = (unsigned __int8)v36 & 0xFE;
    v38 = 0;
    v39 = (int *)(v20 + 32);
    v40 = v37;
    do
    {
      v41 = *(v39 - 4);
      v42 = *v39;
      v39 += 8;
      v40 -= 2;
      v23 += v41;
      v38 += v42;
    }
    while ( v40 );
    v23 += v38;
    if ( v37 == v36 )
      goto LABEL_54;
  }
  v43 = v36 - v37;
  v44 = (int *)&v20[16 * v37 + 16];
  do
  {
    v45 = *v44;
    v44 += 4;
    --v43;
    v23 += v45;
  }
  while ( v43 );
LABEL_54:
  v18 = v23 + v21;
LABEL_55:
  v140 = v20;
  v136 = (const void **)(a3 + 8);
  v65 = v18;
  v66 = _kmalloc_noprof(v18, 3520);
  if ( !v66 )
    return 4294967284LL;
  while ( 1 )
  {
    if ( v65 < 8 )
      goto LABEL_179;
    v67 = v143;
    *(_QWORD *)v66 = v66 + 72;
    if ( (v65 & 0xFFFFFFFFFFFFFFF8LL) == 8 )
      goto LABEL_179;
    v68 = v66 + 72 + (int)v13;
    v138 = (int)v13;
    *(_QWORD *)(v66 + 8) = v68;
    if ( v65 < 0x10 )
      goto LABEL_179;
    if ( (v65 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
      goto LABEL_179;
    *(_DWORD *)(v66 + 16) = v13;
    if ( v65 < 0x14 || (v65 & 0xFFFFFFFFFFFFFFFCLL) == 0x14 )
      goto LABEL_179;
    v13 = (int)v15;
    *(_DWORD *)(v66 + 20) = v15;
    v15 = v138;
    v133 = a1;
    v134 = v17;
    v139 = v66;
    v131 = v10;
    if ( v143 )
    {
      if ( v65 < 0x28 || (v65 & 0xFFFFFFFFFFFFFFF8LL) == 0x28 )
        goto LABEL_179;
      a1 = (const void **)(v138 + v13);
      *(_QWORD *)(v66 + 40) = v68 + v13;
      v122 = a4;
      v124 = (_BYTE *)(v68 + v13);
      v126 = v13;
      v69 = (16LL * (unsigned __int8)*v143) | 8;
      v127 = v6;
      v128 = a6;
      v129 = v11;
      v10 = v68 + v13 + v69;
      v119 = (unsigned __int8)*v143;
      v121 = v69;
      v141 = v138 + v13 + v69 + 72;
      if ( *v143 )
      {
        v11 = nullptr;
        a6 = nullptr;
        a4 = 0;
        v6 = (unsigned __int64)a1 + v66;
        v17 = (_QWORD *)(v65 - v138 - v13 - 88);
        while ( 1 )
        {
          v13 = (size_t)v11 + (_QWORD)v67;
          v70 = *(unsigned __int64 *)((char *)v11 + (_QWORD)v67 + 16);
          v71 = v141 + (int)a4;
          v72 = v65 >= v71;
          v73 = v65 - v71;
          v74 = v72 ? v73 : 0LL;
          if ( v74 < v70 )
            goto LABEL_180;
          v15 = v10 + (int)a4;
          memcpy((void *)v15, *(const void **)(v13 + 8), v70);
          if ( (__int64)v11 + (_QWORD)a1 + 88 < 0 )
            goto LABEL_179;
          if ( (unsigned __int64 *)v65 < (unsigned __int64 *)((char *)v11 + (_QWORD)a1 + 88) )
            goto LABEL_179;
          if ( (unsigned __int64)v17 < 8 )
            goto LABEL_179;
          v75 = *(_QWORD *)(v13 + 16);
          v76 = (unsigned __int64)v11 + (_QWORD)a1 + 80;
          *(unsigned __int64 *)((char *)v11 + v6 + 88) = v75;
          if ( (v76 & 0x8000000000000000LL) != 0 || v65 < v76 || (unsigned __int64)v17 >= 0xFFFFFFFFFFFFFFF8LL )
            goto LABEL_179;
          v67 = v143;
          a6 = (_QWORD *)((char *)a6 + 1);
          *(unsigned __int64 *)((char *)v11 + v6 + 80) = v15;
          a4 = (unsigned int)(a4 + v75);
          v11 += 2;
          v77 = (unsigned __int8)*v143;
          v17 -= 2;
          if ( (unsigned __int64)a6 >= v77 )
          {
            v6 = v127;
            a6 = v128;
            v11 = v129;
            v15 = v138;
            v66 = v139;
            v17 = v134;
            v13 = v126;
            goto LABEL_80;
          }
        }
      }
      a4 = 0;
      LOBYTE(v77) = 0;
LABEL_80:
      a1 = v133;
      v78 = v15 + 72 + v13;
      if ( (v78 & 0x8000000000000000LL) != 0 || v65 <= v78 )
        goto LABEL_179;
      *v124 = v77;
      if ( v140 )
      {
        if ( v65 < 0x30 || (v65 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
          goto LABEL_179;
        v79 = (int)a4;
        v80 = (_BYTE *)(v10 + (int)a4);
        *(_QWORD *)(v66 + 48) = v80;
        if ( *v140 )
        {
          v125 = v15 + 72 + v13;
          v81 = (int)a4;
          v82 = v10 + (int)a4;
          v83 = (16LL * (unsigned __int8)*v140) | 8;
          a4 = 0;
          v84 = v65 - v15 - v13 - v81 - 16 * v119;
          v85 = v140;
          v10 = 0;
          a6 = (_QWORD *)(16 * v119 + v15 + v13 + v81);
          v11 = nullptr;
          v13 = v82 + v83;
          v17 = (_QWORD *)(v84 - 96);
          v6 = (unsigned __int64)a6 + v66;
          v142 = v141 + v81 + v83;
          v118 = v81;
          v120 = (_BYTE *)v82;
          while ( 1 )
          {
            a1 = (const void **)&v85[a4];
            v86 = *(_QWORD *)&v85[a4 + 16];
            v87 = v142 + (int)v11;
            v72 = v65 >= v87;
            v88 = v65 - v87;
            v89 = v72 ? v88 : 0LL;
            if ( v89 < v86 )
              goto LABEL_180;
            v15 = v13 + (int)v11;
            memcpy((void *)v15, a1[1], v86);
            if ( (__int64)a6 + a4 + 96 < 0 )
              goto LABEL_179;
            if ( v65 < (unsigned __int64)a6 + a4 + 96 )
              goto LABEL_179;
            if ( (unsigned __int64)v17 < 8 )
              goto LABEL_179;
            v90 = a1[2];
            v85 = v140;
            v91 = (unsigned __int64)a6 + a4 + 88;
            *(_QWORD *)(v6 + a4 + 96) = v90;
            if ( (v91 & 0x8000000000000000LL) != 0 || v65 < v91 || (unsigned __int64)v17 >= 0xFFFFFFFFFFFFFFF8LL )
              goto LABEL_179;
            ++v10;
            v11 = (unsigned __int64 *)(unsigned int)((_DWORD)v11 + (_DWORD)v90);
            *(_QWORD *)(v6 + a4 + 88) = v15;
            a4 += 16;
            v17 -= 2;
            v92 = (unsigned __int8)*v140;
            if ( v10 >= v92 )
            {
              v6 = v127;
              a6 = v128;
              v11 = v129;
              v15 = v138;
              v66 = v139;
              a1 = v133;
              v17 = v134;
              v67 = v143;
              v78 = v125;
              v13 = v126;
              v79 = v118;
              v80 = v120;
              goto LABEL_100;
            }
          }
        }
        LOBYTE(v92) = 0;
LABEL_100:
        v93 = v78 + v121 + v79;
        if ( (v93 & 0x8000000000000000LL) != 0 || v65 <= v93 )
          goto LABEL_179;
        *v80 = v92;
      }
      v10 = v131;
      a4 = v122;
      *((_BYTE *)v17 + 312) = 32 - __clz(*v67);
    }
    if ( !a4 )
    {
      if ( !a5 )
        goto LABEL_115;
      if ( v65 >= 0x25 )
      {
        v66 = v139;
        *(_BYTE *)(v139 + 36) = *(_BYTE *)(a5 + 4);
        if ( (v65 & 0xFFFFFFFFFFFFFFFELL) != 0x20 )
        {
          *(_WORD *)(v139 + 32) = *(_WORD *)a5;
          goto LABEL_115;
        }
      }
      goto LABEL_179;
    }
    if ( v65 < 0x25 )
      goto LABEL_179;
    v94 = 2LL * *(int *)(a4 + 16);
    *(_BYTE *)(v66 + 36) = *(_BYTE *)(a4 + 24);
    if ( v65 - 32 >= v94 )
      break;
LABEL_180:
    _fortify_panic(17);
LABEL_181:
    _fortify_panic(17);
LABEL_182:
    _fortify_panic(17);
    v65 = v114;
    v123 = a4;
    StatusReg = _ReadStatusReg(SP_EL0);
    v132 = v10;
    v116 = v6;
    v117 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_assign_beacon__alloc_tag;
    v66 = _kmalloc_noprof(v114, 3520);
    *(_QWORD *)(StatusReg + 80) = v117;
    a4 = v123;
    v6 = v116;
    v10 = v132;
    if ( !v66 )
      return 4294967284LL;
  }
  if ( v94 >= 5 && (ieee80211_assign_beacon___already_done & 1) == 0 )
  {
    ieee80211_assign_beacon___already_done = 1;
    v112 = v94;
    _warn_printk(
      "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
      v94,
      "field \"new->cntdwn_counter_offsets\" at ../soc-repo/net/mac80211/cfg.c:1186",
      4u);
    v94 = v112;
    v15 = v138;
    v66 = v139;
    __break(0x800u);
  }
  memcpy((void *)(v66 + 32), *(const void **)a4, v94);
  v66 = v139;
LABEL_115:
  v95 = *(void **)v66;
  if ( *v136 )
    v96 = v136;
  else
    v96 = (const void **)v6;
  memcpy(v95, *v96, v15);
  v97 = v137;
  if ( *v137 )
  {
    if ( (v65 & 0xFFFFFFFFFFFFFFF8LL) != 8 )
    {
      v98 = v139;
      goto LABEL_124;
    }
    goto LABEL_179;
  }
  if ( v6 )
  {
    if ( (v65 & 0xFFFFFFFFFFFFFFF8LL) == 8 )
      goto LABEL_179;
    v98 = v139;
    v97 = (const void **)(v6 + 8);
LABEL_124:
    memcpy(*(void **)(v98 + 8), *v97, v13);
  }
  v17 = *(_QWORD **)(v10 + 48);
  v15 = 256;
  if ( v17 )
  {
    v13 = *(_QWORD *)(v10 + 136);
    v99 = v139;
    if ( !v13 )
      goto LABEL_151;
    v10 = v11[68];
    v15 = v13 + 24;
    v100 = (_DWORD *)_kmalloc_noprof(v13 + 24, 3520);
    v101 = v139;
    if ( !v100 )
      goto LABEL_163;
    if ( v15 < 0x10 || (v15 & 0xFFFFFFFFFFFFFFFCLL) == 0x10 )
      goto LABEL_179;
    v100[4] = v13;
    if ( v15 >= 0x18 )
      v102 = v13;
    else
      v102 = 0;
    if ( v102 < v13 )
      goto LABEL_181;
    memcpy(v100 + 6, v17, v13);
    if ( a4 )
    {
      v103 = 2LL * *(int *)(a4 + 20);
      if ( v15 >= 0x14 )
        v104 = v13 + 4;
      else
        v104 = 0;
      if ( v104 < v103 )
        goto LABEL_180;
      if ( v103 >= 5 && (ieee80211_set_probe_resp___already_done_21 & 1) == 0 )
      {
        ieee80211_set_probe_resp___already_done_21 = 1;
        v113 = v103;
        _warn_printk(
          "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
          v103,
          "field \"new->cntdwn_counter_offsets\" at ../soc-repo/net/mac80211/cfg.c:938",
          4u);
        v103 = v113;
        __break(0x800u);
      }
      memcpy(v100 + 5, *(const void **)(a4 + 8), v103);
    }
    else if ( a5 )
    {
      if ( v15 < 0x14 || (v15 & 0xFFFFFFFFFFFFFFFELL) == 0x14 )
        goto LABEL_179;
      *((_WORD *)v100 + 10) = *(_WORD *)(a5 + 2);
    }
    atomic_store((unsigned __int64)v100, v11 + 68);
    v15 = 65792;
    if ( v10 )
      kvfree_call_rcu(v10, v10);
    v10 = v131;
  }
  v99 = v139;
LABEL_151:
  v105 = *(unsigned __int8 *)(v10 + 88);
  if ( v105 == 255 )
    goto LABEL_176;
  v106 = v10;
  *((_BYTE *)v134 + 295) = v105 != 0;
  v13 = *(_QWORD *)(v10 + 144);
  v10 = *(_QWORD *)(v10 + 152);
  if ( !(v10 | v13) )
    goto LABEL_175;
  a4 = *(_QWORD *)(v106 + 56);
  a1 = (const void **)v134[37];
  v143 = *(_BYTE **)(v106 + 64);
  v107 = (int)v10 + (int)v13 + 32LL;
  v17 = (_QWORD *)_kmalloc_noprof(v107, 3520);
  v101 = v139;
  if ( !v17 )
  {
LABEL_163:
    kfree(v101);
    return 4294967284LL;
  }
  v130 = v11;
  v11 = v17 + 4;
  if ( v13 )
  {
    if ( v107 < 0x10 || (v107 & 0xFFFFFFFFFFFFFFF8LL) == 0x10 )
      goto LABEL_179;
    v17[2] = v13;
    *v17 = v11;
    if ( v107 >= 0x20 )
      v108 = (int)v10 + (int)v13;
    else
      v108 = 0;
    if ( v108 < v13 )
      goto LABEL_181;
    memcpy(v17 + 4, (const void *)a4, v13);
    v109 = v13 + 32;
    v11 = (unsigned __int64 *)((char *)v11 + v13);
    if ( !v10 )
      goto LABEL_174;
  }
  else
  {
    v109 = 32;
    if ( !v10 )
      goto LABEL_174;
  }
  if ( v107 < 0x18 || (v107 & 0xFFFFFFFFFFFFFFF8LL) == 0x18 || (v17[3] = v10, (v107 & 0xFFFFFFFFFFFFFFF8LL) == 8) )
  {
LABEL_179:
    __break(1u);
    goto LABEL_180;
  }
  v72 = v107 >= v109;
  v110 = v107 - v109;
  v17[1] = v11;
  if ( v72 )
    v111 = v110;
  else
    v111 = 0;
  if ( v111 < v10 )
    goto LABEL_182;
  memcpy(v11, v143, v10);
LABEL_174:
  v134[37] = v17;
  kfree(a1);
  v11 = v130;
  a1 = v133;
LABEL_175:
  v99 = v139;
  v15 |= 0x4000000uLL;
LABEL_176:
  atomic_store(v99, v11 + 67);
  *((_BYTE *)a1 + 2581) = 1;
  if ( v6 )
    kvfree_call_rcu(v6 + 56, v6);
  *a6 |= v15;
  return 0;
}
