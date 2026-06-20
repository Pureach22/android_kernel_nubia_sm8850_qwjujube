__int64 __fastcall ieee80211_mgd_assoc(__int64 a1, __int64 a2)
{
  int v4; // w1
  __int64 v5; // x25
  size_t v6; // x24
  unsigned __int64 v7; // x20
  __int64 v8; // x26
  unsigned __int64 v9; // x23
  unsigned __int64 v10; // x28
  __int64 v11; // x27
  __int64 result; // x0
  unsigned __int64 v13; // x22
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x9
  __int64 v17; // x0
  unsigned int v18; // w24
  __int64 v19; // x1
  __int64 v20; // x0
  __int64 v21; // x0
  char v22; // w24
  __int64 unlock; // x0
  __int64 v24; // x1
  __int64 v25; // x2
  __int64 v26; // x3
  __int64 elem; // x0
  size_t v28; // x2
  __int64 v29; // x15
  __int64 v30; // x0
  unsigned int v31; // w19
  void *v32; // x0
  int *v33; // x9
  _DWORD *v34; // x8
  __int64 v35; // x20
  __int16 v36; // w10
  int v37; // w9
  __int64 v38; // x9
  __int64 v39; // x10
  __int64 v40; // x11
  __int64 v41; // x10
  __int64 v42; // x11
  __int64 v43; // x12
  __int64 v44; // x9
  __int64 v45; // x9
  __int64 v46; // x10
  __int64 v47; // x8
  __int64 v48; // x11
  int v49; // w10
  __int64 v50; // x9
  unsigned __int64 v51; // x12
  unsigned __int64 v52; // x22
  __int64 v53; // x8
  __int64 v54; // x8
  _BOOL4 v55; // w9
  bool v56; // zf
  __int64 v57; // x9
  size_t v58; // x27
  __int64 v59; // x1
  unsigned int v60; // w9
  unsigned int v61; // w10
  int v62; // w22
  int v63; // w9
  _BOOL8 v64; // x3
  __int64 v65; // x8
  __int64 v66; // x1
  __int64 *v67; // x8
  unsigned int v68; // w8
  unsigned int v69; // w8
  __int64 v70; // x8
  char v71; // w8
  size_t v72; // x2
  size_t v73; // x1
  __int64 v74; // x8
  char *v75; // x8
  const void *v76; // x1
  size_t v77; // x2
  __int64 *v78; // x8
  __int64 v79; // x9
  __int64 v80; // x10
  __int64 v81; // x8
  __int64 v82; // x11
  __int64 v83; // x8
  __int64 v84; // x28
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x9
  bool v87; // cf
  unsigned __int64 v88; // x9
  _BOOL4 v89; // w23
  unsigned __int64 v90; // x8
  unsigned int v91; // w8
  int v92; // w8
  unsigned int v93; // w8
  int v94; // w8
  int *v95; // x8
  __int16 v96; // w9
  int v97; // w8
  int v98; // w8
  unsigned int v99; // w8
  unsigned int v100; // w8
  unsigned int v101; // w8
  int v102; // w9
  char v103; // w10
  __int64 v104; // x2
  size_t v105; // x2
  unsigned __int64 v106; // x20
  __int64 v107; // x8
  __int16 v108; // w11
  __int64 v109; // x1
  int v110; // w21
  __int64 lock; // x0
  __int64 v112; // x3
  __int64 v113; // x1
  __int64 v114; // x22
  __int64 v115; // x8
  size_t v116; // x23
  __int64 v117; // x25
  size_t v118; // x26
  unsigned __int64 v119; // x24
  unsigned int **v120; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v122; // x23
  unsigned int **v123; // [xsp+8h] [xbp-F8h]
  __int64 v124; // [xsp+8h] [xbp-F8h]
  size_t v125; // [xsp+10h] [xbp-F0h]
  __int64 v126; // [xsp+18h] [xbp-E8h]
  unsigned __int64 v127; // [xsp+20h] [xbp-E0h]
  unsigned __int64 v128; // [xsp+28h] [xbp-D8h]
  unsigned int v129; // [xsp+44h] [xbp-BCh]
  _BOOL4 v130; // [xsp+48h] [xbp-B8h]
  __int64 v131; // [xsp+48h] [xbp-B8h]
  size_t v132; // [xsp+50h] [xbp-B0h]
  unsigned __int64 v133; // [xsp+58h] [xbp-A8h]
  unsigned __int64 v134; // [xsp+60h] [xbp-A0h]
  unsigned __int64 v135; // [xsp+60h] [xbp-A0h]
  __int64 v136; // [xsp+68h] [xbp-98h]
  __int64 v137; // [xsp+70h] [xbp-90h]
  __int64 v138; // [xsp+78h] [xbp-88h]
  __int64 v139; // [xsp+80h] [xbp-80h]
  __int64 v140; // [xsp+88h] [xbp-78h]
  __int64 v141; // [xsp+90h] [xbp-70h]
  __int64 v142; // [xsp+98h] [xbp-68h]
  __int64 v143; // [xsp+A0h] [xbp-60h]
  __int64 v144; // [xsp+A8h] [xbp-58h]
  __int64 v145; // [xsp+B0h] [xbp-50h]
  __int64 v146; // [xsp+B8h] [xbp-48h]
  __int64 v147; // [xsp+B8h] [xbp-48h]
  int v148; // [xsp+C4h] [xbp-3Ch]
  __int64 v149; // [xsp+C8h] [xbp-38h]
  _QWORD v150[3]; // [xsp+D0h] [xbp-30h] BYREF
  __int16 v151; // [xsp+E8h] [xbp-18h]
  __int64 v152; // [xsp+F0h] [xbp-10h]

  v152 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(char *)(a2 + 792);
  v5 = *(_QWORD *)(a1 + 1616);
  v6 = *(_QWORD *)(a2 + 352);
  v7 = *(_QWORD *)(a2 + 384);
  v8 = *(_QWORD *)(a2 + 480);
  v9 = *(_QWORD *)(a2 + 512);
  v10 = *(_QWORD *)(a2 + 640);
  v11 = *(_QWORD *)(a2 + 672);
  if ( *(_BYTE *)(a1 + 2524) && (v4 & 0x80000000) == 0 )
  {
    result = 4294967201LL;
    goto LABEL_209;
  }
  v142 = *(_QWORD *)(a2 + 24);
  v141 = *(_QWORD *)(a2 + 416);
  v143 = *(_QWORD *)(a2 + 544);
  v148 = v4;
  v139 = *(_QWORD *)(a2 + 320);
  v13 = v142
      + v139
      + v6
      + v7
      + v141
      + *(_QWORD *)(a2 + 448)
      + v8
      + v9
      + v143
      + *(_QWORD *)(a2 + 576)
      + *(_QWORD *)(a2 + 608)
      + v10
      + v11
      + *(_QWORD *)(a2 + 704)
      + *(_QWORD *)(a2 + 736)
      + *(_QWORD *)(a2 + 768)
      + 1168;
  v138 = *(_QWORD *)(a2 + 448);
  v140 = *(_QWORD *)(a2 + 576);
  v137 = *(_QWORD *)(a2 + 704);
  v145 = *(_QWORD *)(a2 + 608);
  v136 = *(_QWORD *)(a2 + 736);
  v144 = *(_QWORD *)(a2 + 768);
  v14 = _kmalloc_noprof(v13, 3520);
  if ( !v14 )
  {
LABEL_208:
    result = 4294967284LL;
    goto LABEL_209;
  }
  while ( 1 )
  {
    v15 = *(char *)(a2 + 792);
    v16 = a2;
    v146 = v5;
    v132 = v6;
    v133 = v9;
    v134 = v7;
    if ( (v15 & 0x8000000000000000LL) == 0 )
    {
      if ( (unsigned int)v15 > 0xE )
        goto LABEL_203;
      v16 = a2 + 304 + 32 * v15;
    }
    v9 = *(_QWORD *)v16;
    v149 = v14;
    v17 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(**(_QWORD **)v16 + 4LL)));
    v18 = v17;
    _rcu_read_lock(v17, v19);
    v20 = ieee80211_mgd_csa_present(a1, *(_QWORD *)(v9 + 16), v18, 0);
    if ( (v20 & 1) != 0 )
    {
      _rcu_read_unlock(v20);
LABEL_83:
      printk(&unk_BB8EB, a1 + 1640, v25, v26);
      goto LABEL_13;
    }
    v21 = ieee80211_mgd_csa_present(a1, *(_QWORD *)(v9 + 24), v18, *(_BYTE *)(v9 + 83) & 1);
    v22 = v21;
    unlock = _rcu_read_unlock(v21);
    if ( (v22 & 1) != 0 )
      goto LABEL_83;
    _rcu_read_lock(unlock, v24);
    elem = ieee80211_bss_get_elem(v9, 0);
    if ( !elem || (v28 = *(unsigned __int8 *)(elem + 1), v5 = elem, v28 >= 0x21) )
    {
      _rcu_read_unlock(elem);
LABEL_13:
      v29 = v149;
      goto LABEL_14;
    }
    if ( v13 >= 0x3EA )
      v6 = v13 - 1002;
    else
      v6 = 0;
    if ( v6 < v28 )
      goto LABEL_204;
    v32 = memcpy((void *)(v149 + 1002), (const void *)(elem + 2), v28);
    if ( v13 < 0x40B )
      goto LABEL_199;
    *(_BYTE *)(v149 + 1034) = *(_BYTE *)(v5 + 1);
    _rcu_read_unlock(v32);
    v33 = *(int **)(a2 + 784);
    v34 = (_DWORD *)(v149 + 960);
    v29 = v149;
    if ( v33 )
    {
      v35 = v146;
      v36 = *((_WORD *)v33 + 2);
      v37 = *v33;
      *(_WORD *)(v149 + 964) = v36;
      *v34 = v37;
      if ( (*(_BYTE *)(a1 + 2477) & 8) != 0 )
        goto LABEL_29;
    }
    else
    {
      v35 = v146;
      v49 = *(_DWORD *)(v9 + 72);
      *(_WORD *)(v149 + 964) = *(_WORD *)(v9 + 76);
      *v34 = v49;
      if ( (*(_BYTE *)(a1 + 2477) & 8) != 0 )
      {
LABEL_29:
        v151 = 0;
        memset(v150, 0, sizeof(v150));
        printk(&unk_B9DC5, a1 + 1640, a1 + 4802, v149 + 960);
        ieee80211_set_disassoc(a1, 0xC0u, 1u, 0, (__int64)v150);
        ieee80211_report_disconnect(a1, (__int64)v150, 26, 1, 1, 0);
        v29 = v149;
      }
    }
    v38 = *(_QWORD *)(a2 + 185);
    v39 = *(_QWORD *)(a2 + 169);
    v40 = *(_QWORD *)(a2 + 177);
    *(_WORD *)(a1 + 2560) = *(_WORD *)(a2 + 193);
    *(_QWORD *)(a1 + 2552) = v38;
    *(_QWORD *)(a1 + 2544) = v40;
    *(_QWORD *)(a1 + 2536) = v39;
    v41 = *(_QWORD *)(a2 + 211);
    v42 = *(_QWORD *)(a2 + 195);
    v43 = *(_QWORD *)(a2 + 203);
    *(_WORD *)(a1 + 2586) = *(_WORD *)(a2 + 219);
    *(_QWORD *)(a1 + 2570) = v43;
    *(_QWORD *)(a1 + 2578) = v41;
    *(_QWORD *)(a1 + 2562) = v42;
    v44 = *(_QWORD *)(a2 + 221);
    *(_DWORD *)(a1 + 2596) = *(_DWORD *)(a2 + 229);
    *(_QWORD *)(a1 + 2588) = v44;
    v45 = *(_QWORD *)(a2 + 233);
    *(_DWORD *)(a1 + 2608) = *(_DWORD *)(a2 + 241);
    *(_QWORD *)(a1 + 2600) = v45;
    v46 = *(_QWORD *)(a2 + 272);
    *(_QWORD *)(a1 + 2619) = *(_QWORD *)(a2 + 279);
    v47 = *(_QWORD *)(a1 + 2480);
    *(_QWORD *)(a1 + 2612) = v46;
    v48 = *(_QWORD *)(a2 + 287);
    *(_QWORD *)(a1 + 2634) = *(_QWORD *)(a2 + 294);
    *(_QWORD *)(a1 + 2627) = v48;
    if ( !v47 )
      goto LABEL_27;
    if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x3C0 || (v13 & 0xFFFFFFFFFFFFFFFELL) == 0x3C4 )
      goto LABEL_199;
    if ( !(*(_DWORD *)(v29 + 960) ^ *(_DWORD *)(v47 + 48)
         | *(unsigned __int16 *)(v29 + 964) ^ *(unsigned __int16 *)(v47 + 52)) )
      v130 = *(_DWORD *)(v47 + 44) == *(char *)(a2 + 792);
    else
LABEL_27:
      v130 = 0;
    v5 = v148 & (unsigned int)~(v148 >> 31);
    if ( *(_QWORD *)(a2 + 784) )
    {
      if ( (*(_BYTE *)(a2 + 156) & 0x33) != 0 )
        goto LABEL_14;
      v127 = v10;
      v128 = v11;
      v123 = (unsigned int **)v9;
      v125 = v6;
      v6 = 0;
      v126 = v8;
      v50 = v141 + v138 + v8;
      v8 = 571;
      v51 = v10 + v11;
      v11 = 1;
      v5 = a2 + 332;
      v10 = v142 + v139 + v132 + v134 + v50 + v133 + v143 + v140 + v145 + v51 + v137 + v136 + v144 + 1116;
      do
      {
        v9 = *(_QWORD *)(v5 - 28);
        if ( v9 )
        {
          if ( (*(_BYTE *)(v9 + 104) & 1) == 0 || **(_DWORD **)v9 == 4 )
            goto LABEL_102;
          v129 = v11;
          v11 = *(_QWORD *)(a1 + 8 * v8);
          v7 = v13;
          v52 = v6 + 8;
          if ( v11 )
          {
            if ( (v6 & 0x8000000000000000LL) != 0 )
              goto LABEL_199;
            if ( v7 < v52 )
              goto LABEL_199;
            if ( v10 + 44 < 4 )
              goto LABEL_199;
            v53 = *(_QWORD *)(v11 + 944);
            *(_DWORD *)(v52 + v29) = *(_DWORD *)(v53 + 28);
            if ( v7 < v6 + 12 || v10 + 40 < 2 )
              goto LABEL_199;
            *(_WORD *)(v29 + v6 + 12) = *(_WORD *)(v53 + 32);
          }
          else
          {
            get_random_bytes(v52 + v29, 6);
            if ( (v6 & 0x8000000000000000LL) != 0 || v7 <= v52 )
              goto LABEL_199;
            v29 = v149;
            *(_BYTE *)(v52 + v149) = *(_BYTE *)(v52 + v149) & 0xFC | 2;
          }
          v13 = v7;
          v54 = **(unsigned int **)v9;
          if ( (unsigned int)v54 > 5 )
            goto LABEL_203;
          v55 = v130;
          v56 = (unsigned __int64)(unsigned __int8)(v148 & ~(v148 >> 31)) << 6 != v6 || v11 == 0;
          if ( v56 )
            v55 = 0;
          v56 = v55;
          v57 = 0x400000005LL;
          if ( v56 )
            v57 = *(_QWORD *)(v11 + 552);
          if ( (v6 & 0x8000000000000000LL) != 0 || v7 < v6 + 48 || v10 + 4 < 8 )
            goto LABEL_199;
          v58 = v29 + v6;
          v59 = *(_QWORD *)(*(_QWORD *)(v146 + 72) + 8 * v54 + 328);
          *(_QWORD *)(v29 + v6 + 48) = v57;
          if ( !a2 )
            __break(0x800u);
          v150[0] = 0;
          ieee80211_determine_our_sta_mode(a1, v59, a2, 1, v150);
          if ( (v6 & 0x8000000000000000LL) != 0 || v7 < v6 + 48 || v10 >= 0xFFFFFFFFFFFFFFFCLL )
            goto LABEL_199;
          v60 = *(_DWORD *)(v58 + 48);
          v29 = v149;
          if ( v60 >= LODWORD(v150[0]) )
            v60 = v150[0];
          *(_DWORD *)(v58 + 48) = v60;
          if ( v7 < v6 + 52 || v10 < 4 )
            goto LABEL_199;
          v61 = *(_DWORD *)(v149 + v6 + 52);
          if ( v61 >= HIDWORD(v150[0]) )
            v61 = HIDWORD(v150[0]);
          *(_DWORD *)(v149 + v6 + 52) = v61;
          if ( v7 < v6 )
            goto LABEL_199;
          if ( v10 + 52 < 8 )
            goto LABEL_199;
          *(_QWORD *)v58 = v9;
          if ( v7 <= v6 + 58 )
            goto LABEL_199;
          *(_BYTE *)(v149 + v6 + 58) = *(_BYTE *)(v5 - 4);
          if ( v7 < v6 + 48 )
            goto LABEL_199;
          if ( *(_DWORD *)(v58 + 48) <= 4u )
          {
LABEL_102:
            LODWORD(v30) = -22;
            *(_DWORD *)v5 = -22;
            goto LABEL_15;
          }
          v62 = *(unsigned __int8 *)(v9 + 105);
          if ( (unsigned int)ieee80211_mgd_get_ap_ht_vht_capa(a1) )
          {
            LODWORD(v30) = -22;
            v29 = v149;
            *(_DWORD *)v5 = -22;
            goto LABEL_15;
          }
          v29 = v149;
          v11 = v62 & v129;
          v13 = v7;
        }
        v6 += 64LL;
        v10 -= 64LL;
        v5 += 32;
        ++v8;
      }
      while ( v6 != 960 );
      if ( v13 == 1035 )
        goto LABEL_199;
      v6 = v148 & (unsigned int)~(v148 >> 31);
      v7 = (unsigned __int64)v123;
      *(_BYTE *)(v29 + 1035) = 1;
    }
    else
    {
      v63 = *(_DWORD *)(a1 + 5842);
      *(_WORD *)(v29 + 12) = *(_WORD *)(a1 + 5846);
      *(_DWORD *)(v29 + 8) = v63;
      if ( v13 < 0x412 )
        goto LABEL_199;
      *(_BYTE *)(v29 + 1041) = **(_DWORD **)v9 == 4;
      v64 = *(_BYTE *)(v9 + 104) == 1 && (unsigned __int64)(*(unsigned __int16 *)(v35 + 128) > 3u);
      *(_BYTE *)(v29 + 1035) = v64;
      v7 = v9;
      v125 = v6;
      v126 = v8;
      v127 = v10;
      v128 = v11;
      v65 = **(unsigned int **)v9;
      if ( (_DWORD)v65 == 3 )
      {
        if ( (*(_BYTE *)(a2 + 156) & 0x13) != 0 )
          goto LABEL_14;
      }
      else if ( (unsigned int)v65 > 5 )
      {
        goto LABEL_203;
      }
      v66 = *(_QWORD *)(*(_QWORD *)(v146 + 72) + 8 * v65 + 328);
      *(_QWORD *)v29 = v9;
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x30 )
        goto LABEL_199;
      v67 = (__int64 *)(a1 + 4168);
      if ( !v130 )
        v67 = &ieee80211_conn_settings_unlimited;
      *(_QWORD *)(v29 + 48) = *v67;
      if ( !a2 )
        __break(0x800u);
      v150[0] = 0;
      ieee80211_determine_our_sta_mode(a1, v66, a2, v64, v150);
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x30 )
        goto LABEL_199;
      v68 = *(_DWORD *)(v149 + 48);
      if ( v68 >= LODWORD(v150[0]) )
        v68 = v150[0];
      *(_DWORD *)(v149 + 48) = v68;
      if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x34 )
        goto LABEL_199;
      v69 = *(_DWORD *)(v149 + 52);
      v6 = v148 & (unsigned int)~(v148 >> 31);
      if ( v69 >= HIDWORD(v150[0]) )
        v69 = HIDWORD(v150[0]);
      *(_DWORD *)(v149 + 52) = v69;
      v11 = *(unsigned __int8 *)(v9 + 105);
      LODWORD(v30) = ieee80211_mgd_get_ap_ht_vht_capa(a1);
      v29 = v149;
      if ( (_DWORD)v30 )
        goto LABEL_15;
    }
    if ( v13 < 0x413 )
      goto LABEL_199;
    v70 = *(_QWORD *)(a1 + 2480);
    *(_BYTE *)(v29 + 1042) = (*(_DWORD *)(a2 + 156) & 0x80) != 0;
    if ( v70 && *(_BYTE *)(v70 + 39) != 1 || *(_QWORD *)(a1 + 2488) )
    {
      LODWORD(v30) = -16;
      goto LABEL_15;
    }
    v56 = v70 == 0;
    v71 = v130;
    if ( v56 )
      v71 = 1;
    if ( (v71 & 1) == 0 )
    {
      ieee80211_destroy_auth_data(a1, 0);
      v29 = v149;
    }
    if ( !*(_QWORD *)(a2 + 8) )
      break;
    v72 = *(_QWORD *)(a2 + 24);
    if ( !v72 )
      break;
    if ( v13 >= 0x490 )
      v73 = v13 - 1168;
    else
      v73 = 0;
    if ( v73 >= v72 )
    {
      v9 = v29 + 1168;
      memcpy((void *)(v29 + 1168), *(const void **)(a2 + 8), v72);
      if ( v13 < 0x480 )
        goto LABEL_199;
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x480 )
        goto LABEL_199;
      v74 = *(_QWORD *)(a2 + 24);
      v29 = v149;
      *(_QWORD *)(v149 + 1152) = v74;
      if ( v13 < 0x488 || (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x488 )
        goto LABEL_199;
      v75 = (char *)(v9 + v74);
      goto LABEL_129;
    }
LABEL_207:
    _fortify_panic(17);
    v147 = v5;
    v117 = v8;
    v118 = v6;
    v119 = v13;
    v135 = v7;
    v120 = (unsigned int **)v9;
    StatusReg = _ReadStatusReg(SP_EL0);
    v122 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ieee80211_mgd_assoc__alloc_tag;
    v14 = _kmalloc_noprof(v119, 3520);
    *(_QWORD *)(StatusReg + 80) = v122;
    v13 = v119;
    v6 = v118;
    v8 = v117;
    v5 = v147;
    v9 = (unsigned __int64)v120;
    v7 = v135;
    if ( !v14 )
      goto LABEL_208;
  }
  if ( v13 < 0x488 || (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x488 )
    goto LABEL_199;
  v75 = (char *)(v29 + 1168);
LABEL_129:
  v76 = *(const void **)(a2 + 248);
  *(_QWORD *)(v29 + 1160) = v75;
  if ( v76 )
  {
    v77 = *(_QWORD *)(a2 + 256);
    if ( v77 >= 0x41 )
      goto LABEL_200;
    if ( v13 - 1080 >= v77 )
    {
      memcpy((void *)(v29 + 1080), v76, v77);
      if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x478 )
        goto LABEL_199;
      v29 = v149;
      *(_QWORD *)(v149 + 1144) = *(_QWORD *)(a2 + 256);
      goto LABEL_134;
    }
LABEL_205:
    _fortify_panic(17);
LABEL_206:
    _fortify_panic(16);
    goto LABEL_207;
  }
LABEL_134:
  v78 = *(__int64 **)(a2 + 264);
  if ( v78 )
  {
    v80 = v78[2];
    v79 = v78[3];
    v82 = *v78;
    v81 = v78[1];
    *(_QWORD *)(v29 + 1072) = v79;
    *(_QWORD *)(v29 + 1064) = v80;
    *(_QWORD *)(v29 + 1056) = v81;
    *(_QWORD *)(v29 + 1048) = v82;
  }
  if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x3D8 )
    goto LABEL_199;
  *(_QWORD *)(v29 + 984) = jiffies;
  v124 = v7;
  *(_BYTE *)(v29 + 1039) = 1;
  if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x414 )
    goto LABEL_199;
  v83 = *(_QWORD *)(a2 + 784);
  v9 = (int)v6;
  *(_DWORD *)(v29 + 1044) = v6;
  if ( v83 )
  {
    LODWORD(v30) = ieee80211_vif_set_links((unsigned __int16 *)a1, 1LL << v6, 0);
    v29 = v149;
    if ( (_DWORD)v30 )
    {
LABEL_184:
      if ( !*(_QWORD *)(a1 + 2480) )
        goto LABEL_185;
      goto LABEL_186;
    }
  }
  if ( v148 > 14 )
  {
LABEL_203:
    __break(0x5512u);
    _fortify_panic(17);
LABEL_204:
    _fortify_panic(17);
    _fortify_panic(17);
    goto LABEL_205;
  }
  v84 = *(_QWORD *)(a1 + 8LL * (int)v6 + 4568);
  if ( v84 )
  {
    v85 = ((__int64)(int)v6 << 6) | 0x30;
    if ( v13 >= v85 && v13 - v85 >= 4 )
    {
      v7 = v128;
      v5 = v29 + ((__int64)(int)v6 << 6);
      if ( *(_DWORD *)(v84 + 552) == *(_DWORD *)(v5 + 48) )
      {
        v86 = ((__int64)(int)v6 << 6) | 0x34;
        v87 = v13 >= v86;
        v88 = v13 - v86;
        if ( v87 && v88 >= 4 )
        {
          v89 = *(_DWORD *)(v84 + 556) != *(_DWORD *)(v5 + 52);
          goto LABEL_150;
        }
      }
      else
      {
        v89 = 1;
LABEL_150:
        v87 = v13 >= v85;
        v90 = v13 - v85;
        if ( v87 && v90 >= 8 )
        {
          *(_QWORD *)(v84 + 552) = *(_QWORD *)(v5 + 48);
          ieee80211_setup_assoc_link(a1, v29, a2);
          v91 = *(_DWORD *)(a1 + 5872);
          if ( (v91 & 4) != 0 && (*(_QWORD *)(v146 + 96) & 0x200) != 0 )
          {
            _warn_printk("U-APSD not supported with HW_PS_NULLFUNC_STACK\n");
            __break(0x800u);
            v91 = *(_DWORD *)(a1 + 5872) & 0xFFFFFFFB;
            *(_DWORD *)(a1 + 5872) = v91;
          }
          v29 = v149;
          if ( (*(_BYTE *)(v149 + 1035) & (unsigned __int8)v11 & 1) != 0 && (v91 & 4) != 0 )
          {
            v92 = *(_DWORD *)(a1 + 2500);
            *(_BYTE *)(v149 + 1036) = 1;
            v93 = v92 | 0x80;
          }
          else
          {
            v94 = *(_DWORD *)(a1 + 2500);
            *(_BYTE *)(v149 + 1036) = 0;
            v93 = v94 & 0xFFFFFF7F;
          }
          *(_DWORD *)(a1 + 2500) = v93;
          v95 = *(int **)(a2 + 16);
          if ( v95 )
          {
            v96 = *((_WORD *)v95 + 2);
            v97 = *v95;
            *(_WORD *)(v149 + 1000) = v96;
            *(_DWORD *)(v149 + 996) = v97;
          }
          v131 = v84;
          v148 = v89;
          v98 = *(_DWORD *)(a1 + 2500);
          if ( *(_BYTE *)(a2 + 152) == 1 )
          {
            *(_DWORD *)(a1 + 2512) = 2;
            v99 = v98 | 0x40;
          }
          else
          {
            *(_DWORD *)(a1 + 2512) = 0;
            v99 = v98 & 0xFFFFFFBF;
          }
          *(_DWORD *)(a1 + 2500) = v99;
          v9 = 0;
          v6 = 0;
          v11 = 332;
          v100 = v99 & 0xFFFF7FFF | (((*(_DWORD *)(a2 + 156) >> 2) & 1) << 15);
          *(_DWORD *)(a1 + 2500) = v100;
          v101 = v100 & 0xFFFFFFFB;
          if ( *(_BYTE *)(a2 + 108) )
            v102 = 4;
          else
            v102 = 0;
          *(_DWORD *)(a1 + 2500) = v101 | v102;
          *(_WORD *)(a1 + 1940) = *(_WORD *)(a2 + 110);
          *(_BYTE *)(a1 + 1942) = *(_BYTE *)(a2 + 112);
          v8 = (v13 & 0xFFFFFFFFFFFFFFFCLL) == 1044;
          *(_BYTE *)(a1 + 1944) = *(_BYTE *)(a2 + 113);
          v103 = *(_BYTE *)(a2 + 114);
          *(_QWORD *)(a1 + 2488) = v149;
          v10 = v142
              + v139
              + v132
              + v134
              + v141
              + v138
              + v126
              + v133
              + v143
              + v140
              + v145
              + v127
              + v128
              + v137
              + v136
              + v144
              + 1168;
          *(_BYTE *)(a1 + 1943) = v103;
          while ( (v9 & 0x8000000000000000LL) == 0 && v13 >= v9 && v10 >= 8 )
          {
            v104 = *(_QWORD *)(v29 + v9);
            if ( v104 )
            {
              if ( (v13 & 0xFFFFFFFFFFFFFFFCLL) == 0x414 )
                break;
              if ( v6 != *(_DWORD *)(v29 + 1044) )
              {
                LODWORD(v30) = ieee80211_prep_channel(a1, 0, v104, 1, v29 + v9 + 48);
                v29 = v149;
                if ( (_DWORD)v30 )
                {
                  *(_DWORD *)(a2 + v11) = v30;
                  if ( *(_QWORD *)(a1 + 2480) )
                    goto LABEL_186;
                  goto LABEL_185;
                }
              }
            }
            ++v6;
            v11 += 32;
            v10 -= 64LL;
            v9 += 64LL;
            if ( v6 == 15 )
            {
              v105 = *(unsigned __int8 *)(v29 + 1034);
              if ( v125 < v105 )
                goto LABEL_206;
              v106 = v13;
              if ( (unsigned int)v105 >= 0x21 && (ieee80211_mgd_assoc___already_done_114 & 1) == 0 )
              {
                ieee80211_mgd_assoc___already_done_114 = 1;
                v116 = v105;
                _warn_printk(
                  "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                  v105,
                  "field \"vif_cfg->ssid\" at ../soc-repo/net/mac80211/mlme.c:9089",
                  0x20u);
                v29 = v149;
                v105 = v116;
                __break(0x800u);
              }
              memcpy((void *)(a1 + 4760), (const void *)(v29 + 1002), v105);
              v107 = *(unsigned __int8 *)(v149 + 1034);
              v108 = *(_WORD *)(v149 + 964);
              *(_DWORD *)(a1 + 4802) = *(_DWORD *)(v149 + 960);
              *(_QWORD *)(a1 + 4792) = v107;
              *(_WORD *)(a1 + 4806) = v108;
              v30 = ieee80211_prep_connection(
                      a1,
                      v124,
                      *(unsigned __int8 *)(a2 + 792),
                      *(_QWORD *)(a2 + 784),
                      1,
                      (_QWORD *)(v5 + 48),
                      v148);
              v29 = v149;
              if ( (_DWORD)v30 )
                goto LABEL_184;
              if ( (*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 96LL) & 0x20) != 0 )
              {
                lock = _rcu_read_lock(v30, v109);
                if ( !*(_QWORD *)(*(_QWORD *)a2 + 16LL) )
                {
                  printk(&unk_BCAD8, a1 + 1640, v131 + 536, v112);
                  v114 = jiffies;
                  lock = _usecs_to_jiffies(*(unsigned __int16 *)(*(_QWORD *)a2 + 68LL) << 10);
                  if ( (v106 & 0xFFFFFFFFFFFFFFF8LL) == 0x3D8 )
                    break;
                  v115 = lock + v114;
                  v13 = v106;
                  *(_QWORD *)(v149 + 984) = v115;
                  *(_BYTE *)(v149 + 1039) = 1;
                  *(_BYTE *)(v149 + 1037) = 1;
                }
                _rcu_read_unlock(lock);
                v29 = v149;
              }
              if ( (v13 & 0xFFFFFFFFFFFFFFF8LL) == 0x3D8 )
                break;
              v113 = *(_QWORD *)(v29 + 984);
              if ( !*(_QWORD *)(a1 + 2272) || v113 - *(_QWORD *)(a1 + 2280) < 0 )
                mod_timer(a1 + 2264, v113);
              if ( *(_QWORD *)(a1 + 2480) )
                ieee80211_destroy_auth_data(a1, 1);
              result = 0;
              goto LABEL_209;
            }
          }
        }
      }
    }
LABEL_199:
    __break(1u);
LABEL_200:
    __break(0x800u);
LABEL_14:
    LODWORD(v30) = -22;
    goto LABEL_15;
  }
  __break(0x800u);
  LODWORD(v30) = -22;
  if ( !*(_QWORD *)(a1 + 2480) )
  {
LABEL_185:
    v110 = v30;
    *(_WORD *)(a1 + 4156) = 0;
    *(_DWORD *)(a1 + 4152) = 0;
    ieee80211_link_info_change_notify(a1, a1 + 3616, 128);
    v29 = v149;
    LODWORD(v30) = v110;
  }
LABEL_186:
  *(_QWORD *)(a1 + 2488) = 0;
LABEL_15:
  v31 = v30;
  kfree(v29);
  result = v31;
LABEL_209:
  _ReadStatusReg(SP_EL0);
  return result;
}
