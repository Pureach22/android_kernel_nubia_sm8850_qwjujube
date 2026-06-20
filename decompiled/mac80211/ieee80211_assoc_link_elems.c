__int64 __fastcall ieee80211_assoc_link_elems(
        __int64 a1,
        __int64 a2,
        __int16 *a3,
        __int64 a4,
        char *a5,
        __int64 a6,
        unsigned int a7,
        __int64 a8,
        _WORD *a9)
{
  __int64 v10; // x25
  int v13; // w24
  __int64 v14; // x28
  __int64 v15; // x20
  unsigned int ***v16; // x26
  unsigned int **v17; // x23
  __int64 lock; // x0
  __int64 v19; // x8
  unsigned int v20; // w21
  int v21; // w8
  __int64 v22; // x8
  int v23; // w9
  __int64 v24; // x27
  __int64 v25; // x8
  __int64 v26; // x24
  __int64 v27; // x9
  __int64 v28; // x23
  int v29; // w3
  __int64 v30; // x4
  __int64 v31; // x0
  int v32; // w9
  int v33; // w8
  _BYTE *v34; // x0
  __int64 v35; // x22
  _BYTE *v36; // x23
  __int64 v37; // x26
  char v38; // w0
  __int64 v39; // x22
  void *v40; // x0
  __int64 v41; // x23
  __int64 v42; // x9
  char v43; // w22
  unsigned int v44; // w21
  __int64 v45; // x10
  int v46; // w8
  bool v47; // zf
  unsigned int v48; // w21
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x23
  unsigned int v52; // w22
  __int64 v53; // x21
  void *v54; // x0
  char *v55; // x1
  __int64 v56; // x8
  __int64 v57; // x21
  unsigned int v58; // w9
  int v59; // w8
  __int64 *v60; // x12
  __int64 v61; // x23
  char v62; // w22
  unsigned int v63; // w8
  unsigned int v64; // w21
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x23
  unsigned int v68; // w22
  __int64 v69; // x21
  void *v70; // x0
  _DWORD *v71; // x26
  unsigned int v72; // t1
  int v73; // w8
  __int64 v74; // x1
  __int64 v75; // x27
  __int64 iftype_ext_capa; // x0
  __int16 v77; // w23
  __int16 v78; // w22
  _WORD *v79; // x21
  __int64 v80; // x0
  __int16 v81; // w10
  __int64 v82; // x26
  __int64 v83; // x22
  __int64 v84; // x21
  __int64 v85; // x25
  __int64 v86; // x0
  __int16 v87; // w9
  _WORD *v88; // x28
  __int64 v89; // x0
  unsigned int v90; // w25
  __int64 v91; // x22
  void *v92; // x0
  __int64 v93; // x22
  char *v94; // x21
  char v95; // w28
  char v96; // w25
  char v97; // w8
  unsigned int v98; // w23
  int v99; // w8
  const void *v100; // x20
  size_t v101; // x21
  void *v102; // x0
  __int64 v104; // [xsp+10h] [xbp-80h]
  unsigned int ***v105; // [xsp+18h] [xbp-78h]
  _DWORD *v106; // [xsp+18h] [xbp-78h]
  __int16 v107; // [xsp+20h] [xbp-70h]
  int v108; // [xsp+24h] [xbp-6Ch]
  __int64 v109; // [xsp+28h] [xbp-68h]
  unsigned int v110; // [xsp+30h] [xbp-60h]
  __int64 v111; // [xsp+30h] [xbp-60h]
  __int64 v113; // [xsp+38h] [xbp-58h]
  __int64 v115; // [xsp+40h] [xbp-50h]
  unsigned int *v116; // [xsp+48h] [xbp-48h]
  _BYTE *v117; // [xsp+48h] [xbp-48h]
  unsigned int v119; // [xsp+5Ch] [xbp-34h]
  unsigned int v120; // [xsp+5Ch] [xbp-34h]
  __int64 v122; // [xsp+60h] [xbp-30h]
  __int16 v123; // [xsp+6Ch] [xbp-24h] BYREF
  __int64 v124; // [xsp+70h] [xbp-20h] BYREF
  _BYTE v125[14]; // [xsp+78h] [xbp-18h]
  __int64 v126; // [xsp+88h] [xbp-8h]

  v10 = a1;
  v126 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_DWORD *)(a1 + 4720);
  if ( *(_BYTE *)(a1 + 5848) == 1 )
  {
    if ( v13 == 2 )
    {
      LOBYTE(v13) = 8;
    }
    else if ( v13 == 3 )
    {
      LOBYTE(v13) = 9;
    }
  }
  if ( a7 >= 0xF )
    goto LABEL_173;
  v14 = *(_QWORD *)(a1 + 2488);
  v15 = *(_QWORD *)(a1 + 1616);
  v16 = (unsigned int ***)(v14 + ((unsigned __int64)a7 << 6));
  v17 = *v16;
  v116 = **v16;
  v107 = *a3;
  if ( a8 )
  {
    v108 = *(_DWORD *)(a8 + 444);
    lock = _rcu_read_lock(a1, a2);
    v19 = *(_QWORD *)(*(_QWORD *)(a8 + 944) + 832LL);
    v20 = v19 ? *(_DWORD *)(v19 + 8) : 1;
    _rcu_read_unlock(lock);
  }
  else
  {
    v20 = 1;
    v21 = *(_BYTE *)(a1 + 2496) ? 3 : 1;
    v108 = v21;
  }
  v22 = *v116;
  if ( (unsigned int)v22 > 5 )
LABEL_173:
    __break(0x5512u);
  v110 = a7;
  v23 = (unsigned __int8)v13;
  v24 = *(_QWORD *)(*(_QWORD *)(v15 + 72) + 8 * v22 + 328);
  if ( (unsigned __int8)v13 >= 0xCu )
  {
    v26 = 0;
    __break(0x800u);
    if ( *(_DWORD *)(v24 + 16) )
      goto LABEL_26;
  }
  else
  {
    v25 = *(unsigned __int16 *)(v24 + 92);
    if ( *(_WORD *)(v24 + 92) )
    {
      v26 = *(_QWORD *)(v24 + 96);
      if ( v23 == 4 )
        LOBYTE(v23) = 3;
      v27 = 1LL << v23;
      while ( ((unsigned __int16)v27 & *(_WORD *)v26) == 0 )
      {
        --v25;
        v26 += 128;
        if ( !v25 )
          goto LABEL_24;
      }
    }
    else
    {
LABEL_24:
      v26 = 0;
    }
    if ( *(_DWORD *)(v24 + 16) )
    {
LABEL_26:
      if ( (*((_WORD *)v17 + 35) & 0x100) == 0 )
        goto LABEL_32;
      goto LABEL_30;
    }
  }
  *a3 |= 0x420u;
  if ( (*((_WORD *)v17 + 35) & 0x100) == 0 )
    goto LABEL_32;
LABEL_30:
  if ( (*(_QWORD *)(v15 + 96) & 0x40) != 0 )
    *a3 |= 0x100u;
LABEL_32:
  v28 = a6;
  if ( *(_DWORD *)(v24 + 16) != 4 )
  {
    v29 = *(unsigned __int8 *)(v14 + 976);
    LODWORD(v124) = 0;
    if ( v29 )
    {
      ieee80211_parse_bitrates(v20, v24);
      v30 = (unsigned int)~(_DWORD)v124;
    }
    else
    {
      v30 = 0;
      LODWORD(v124) = -1;
    }
    ieee80211_put_srates_elem(a2, v24, 0, 0, v30, 1);
    ieee80211_put_srates_elem(a2, v24, 0, 0, (unsigned int)~(_DWORD)v124, 50);
  }
  if ( (*a3 & 0x1100) == 0 )
  {
    v119 = 0;
    v109 = v14;
    if ( (*a3 & 0x100) == 0 )
      goto LABEL_56;
    goto LABEL_48;
  }
  v31 = skb_put(a2, 4);
  *(_BYTE *)(v31 + 2) = 0;
  *(_WORD *)v31 = 545;
  if ( v20 == 7 )
  {
    v32 = v116[5];
    v33 = v116[6] - 3;
  }
  else
  {
    if ( v20 != 6 )
    {
      v33 = v116[5];
      goto LABEL_47;
    }
    v32 = v116[5];
    v33 = v116[6] - 6;
  }
  if ( v33 >= v32 )
    LOBYTE(v33) = v32;
LABEL_47:
  *(_BYTE *)(v31 + 3) = v33;
  *a9 = 33;
  v119 = 1;
  v109 = v14;
  if ( (*a3 & 0x100) == 0 )
    goto LABEL_56;
LABEL_48:
  if ( !a4 || *(_DWORD *)(v24 + 16) != 3 || !*(_BYTE *)(a4 + 1) || (*(_BYTE *)(a4 + 2) & 4) == 0 )
  {
    v105 = v16;
    v34 = (_BYTE *)skb_put(a2, (unsigned int)(2 * *(_DWORD *)(v24 + 20) + 2));
    *v34 = 36;
    v34[1] = 2 * *(_BYTE *)(v24 + 20);
    if ( *(int *)(v24 + 20) >= 1 )
    {
      v35 = 0;
      v36 = v34 + 3;
      v37 = 4;
      do
      {
        v38 = ieee80211_freq_khz_to_channel((unsigned int)(1000 * *(_DWORD *)(*(_QWORD *)v24 + v37)));
        *v36 = 1;
        ++v35;
        v37 += 64;
        *(v36 - 1) = v38;
        v36 += 2;
      }
      while ( v35 < *(int *)(v24 + 20) );
    }
    v16 = v105;
    v28 = a6;
    a9[v119++] = 36;
  }
LABEL_56:
  if ( v28 )
  {
    v39 = ieee80211_ie_split_ric(
            a5,
            v28,
            &ieee80211_add_before_ht_elems_before_ht,
            12,
            &ieee80211_add_before_ht_elems_after_ric,
            9,
            0);
    v40 = (void *)skb_put(a2, (unsigned int)v39);
    memcpy(v40, a5, (unsigned int)v39);
  }
  else
  {
    v39 = 0;
  }
  if ( *(_DWORD *)(v24 + 16) != 3 && *((_DWORD *)v16 + 12) >= 2u )
  {
    v41 = v39;
    v42 = *(_QWORD *)(v24 + 36);
    v43 = *((_BYTE *)v16 + 14);
    v44 = v116[3];
    v45 = *(_QWORD *)(v24 + 42);
    v124 = *(_QWORD *)(v24 + 28);
    *(_QWORD *)v125 = v42;
    *(_QWORD *)&v125[6] = v45;
    ieee80211_apply_htcap_overrides(v10, (__int64)&v124);
    v46 = (unsigned __int16)v124;
    if ( (v43 & 3) == 3 )
    {
      v47 = (v44 & 0x20) == 0;
    }
    else
    {
      if ( (v43 & 3) != 1 )
        goto LABEL_67;
      v47 = (v44 & 0x10) == 0;
    }
    if ( !v47 )
      v46 = v124 & 0xFFBD;
LABEL_67:
    v39 = v41;
    if ( !*((_DWORD *)v16 + 13) )
      v46 &= 0xFFBDu;
    v48 = v46 & 0xFFF3;
    if ( v108 > 2 )
    {
      v28 = a6;
      if ( v108 == 3 )
      {
        v48 |= 4u;
        goto LABEL_78;
      }
      if ( v108 != 4 )
      {
LABEL_78:
        v49 = skb_put(a2, 28);
        ieee80211_ie_build_ht_cap(v49, &v124, v48);
        a9[v119++] = 45;
        goto LABEL_79;
      }
    }
    else
    {
      v28 = a6;
      if ( v108 )
      {
        if ( v108 != 1 )
          goto LABEL_78;
        goto LABEL_76;
      }
    }
    __break(0x800u);
LABEL_76:
    v48 = v46 | 0xC;
    goto LABEL_78;
  }
LABEL_79:
  if ( v28 )
  {
    v50 = ieee80211_ie_split_ric(a5, v28, &ieee80211_add_before_vht_elems_before_vht, 5, 0, 0, v39);
    v51 = v39;
    v52 = v50 - v39;
    v53 = v50;
    v54 = (void *)skb_put(a2, v52);
    v55 = &a5[v51];
    v28 = a6;
    memcpy(v54, v55, v52);
    v39 = v53;
  }
  if ( *(_DWORD *)(v24 + 16) == 3 || *((_DWORD *)v16 + 12) < 3u || *(_BYTE *)(v24 + 52) != 1 )
    goto LABEL_103;
  v56 = *(_QWORD *)(v24 + 60);
  v57 = *(_QWORD *)(v10 + 1616);
  v124 = *(_QWORD *)(v24 + 52);
  *(_QWORD *)v125 = v56;
  ieee80211_apply_vhtcap_overrides(v10, &v124);
  v58 = HIDWORD(v124);
  v59 = *(_DWORD *)((char *)v16 + 15);
  if ( *((_DWORD *)v16 + 13) < 3u )
    v58 = HIDWORD(v124) & 0xFFFFFFB3;
  if ( (v59 & 0x800) != 0 )
  {
    if ( (v59 & 0x80000) == 0 )
      v58 &= ~0x100000u;
    if ( (v58 & 0x100000) != 0 )
    {
LABEL_88:
      v60 = (__int64 *)(v57 + 4616);
      while ( 1 )
      {
        v60 = (__int64 *)*v60;
        if ( v60 == (__int64 *)(v57 + 4616) )
          break;
        if ( *((_BYTE *)v60 + 5639) == 1 )
        {
          v61 = v39;
          v62 = 0;
          v58 &= ~0x100000u;
          goto LABEL_97;
        }
      }
      v61 = v39;
      v62 = 1;
      goto LABEL_97;
    }
  }
  else
  {
    v58 &= 0xFFEFEFFF;
    if ( (v58 & 0x100000) != 0 )
      goto LABEL_88;
  }
  v61 = v39;
  v62 = 0;
LABEL_97:
  v63 = *(_DWORD *)((_BYTE *)v16 + 15) & 0xE000;
  if ( v63 >= (v58 & 0xE000) )
    v64 = v58;
  else
    v64 = v58 & 0xFFFF1FFF | v63;
  v65 = skb_put(a2, 14);
  ieee80211_ie_build_vht_cap(v65, &v124, v64);
  if ( a8 )
    *(_BYTE *)(*(_QWORD *)(a8 + 944) + 831LL) = v62;
  v39 = v61;
  v28 = a6;
  a9[v119++] = 191;
LABEL_103:
  if ( v28 )
  {
    v66 = ieee80211_ie_split_ric(a5, v28, &ieee80211_add_before_he_elems_before_he, 13, 0, 0, v39);
    v67 = v39;
    v68 = v66 - v39;
    v69 = v66;
    v70 = (void *)skb_put(a2, v68);
    memcpy(v70, &a5[v67], v68);
    v39 = v69;
  }
  v72 = *((_DWORD *)v16 + 12);
  v71 = v16 + 6;
  if ( v72 >= 4 )
  {
    ieee80211_put_he_cap(a2, v10, v24, v71);
    a9[v119] = 291;
    ieee80211_put_he_6ghz_cap(a2, v10, (unsigned int)v108);
    if ( *v71 >= 5u )
      a9[v119 + 1] = 364;
  }
  if ( *(_DWORD *)(v109 + 1044) != v110 )
    goto LABEL_164;
  v73 = *(unsigned __int16 *)(v10 + 5800);
  v123 = v107;
  if ( !v73 )
    goto LABEL_164;
  v74 = *(unsigned int *)(v10 + 4720);
  v104 = v24;
  if ( *(_BYTE *)(v10 + 5848) == 1 )
  {
    if ( (_DWORD)v74 == 2 )
    {
      v74 = 8;
    }
    else if ( (_DWORD)v74 == 3 )
    {
      v74 = 9;
    }
  }
  v75 = *(_QWORD *)(v10 + 2488);
  v113 = v39;
  iftype_ext_capa = cfg80211_get_iftype_ext_capa(*(_QWORD *)(*(_QWORD *)(v10 + 1616) + 72LL), v74);
  if ( iftype_ext_capa )
  {
    v77 = *(_WORD *)(iftype_ext_capa + 26);
    v78 = *(_WORD *)(iftype_ext_capa + 28);
  }
  else
  {
    v77 = 0;
    v78 = 0;
  }
  v106 = v71;
  *(_BYTE *)skb_put(a2, 1) = -1;
  v111 = skb_put(a2, 1);
  *(_BYTE *)skb_put(a2, 1) = 107;
  v79 = (_WORD *)skb_put(a2, 2);
  *v79 = 256;
  v80 = skb_put(a2, 7);
  v115 = v10;
  *(_BYTE *)v80 = 9;
  v81 = *(_WORD *)(v10 + 5846);
  *(_DWORD *)(v80 + 1) = *(_DWORD *)(v10 + 5842);
  *(_WORD *)(v80 + 5) = v81;
  if ( (v77 & 0x81) != 0 )
  {
    *(_BYTE *)v80 = 11;
    *v79 |= 0x80u;
    *(_WORD *)skb_put(a2, 2) = v77;
  }
  v82 = 0;
  *(_WORD *)skb_put(a2, 2) = v78;
  while ( 2 )
  {
    v83 = v75 + (v82 << 6);
    v124 = 0;
    *(_QWORD *)v125 = 0;
    if ( !*(_QWORD *)v83 || v82 == *(_DWORD *)(v75 + 1044) )
      goto LABEL_123;
    v85 = *(_QWORD *)(v83 + 32);
    v84 = *(_QWORD *)(v83 + 40);
    *(_BYTE *)skb_put(a2, 1) = 0;
    v122 = skb_put(a2, 1);
    *(_WORD *)skb_put(a2, 2) = v82 | 0x30;
    *(_BYTE *)skb_put(a2, 1) = 7;
    v86 = skb_put(a2, 6);
    v87 = *(_WORD *)(v83 + 12);
    *(_DWORD *)v86 = *(_DWORD *)(v83 + 8);
    *(_WORD *)(v86 + 4) = v87;
    v88 = (_WORD *)skb_put(a2, 2);
    v89 = ieee80211_assoc_link_elems(v115, a2, &v123, a4, v84, v85, (unsigned int)v82);
    if ( v84 )
    {
      v90 = v85 - v89;
      v91 = v89;
      v92 = (void *)skb_put(a2, v90);
      memcpy(v92, (const void *)(v84 + v91), v90);
    }
    *v88 = v123;
    v120 = *(_DWORD *)(a2 + 112);
    *(_BYTE *)skb_put(a2, 1) = -1;
    v117 = (_BYTE *)skb_put(a2, 1);
    v93 = 0;
    v94 = nullptr;
    v95 = 0;
    v96 = 0;
    *(_BYTE *)skb_put(a2, 1) = 56;
    do
    {
      v98 = (unsigned __int16)a9[v93];
      if ( !a9[v93] )
        break;
      if ( v98 <= 0xFF && (v96 & 1) != 0 )
      {
        __break(0x800u);
LABEL_137:
        v96 = 1;
        v99 = (unsigned __int16)v124;
        if ( !(_WORD)v124 )
          goto LABEL_155;
        goto LABEL_141;
      }
      if ( !(v96 & 1 | (v98 < 0x100)) )
      {
        if ( v94 )
        {
          v94 = nullptr;
          goto LABEL_137;
        }
        v96 = 1;
        *(_BYTE *)skb_put(a2, 1) = 0;
      }
      v99 = (unsigned __int16)v124;
      if ( !(_WORD)v124 )
        goto LABEL_155;
LABEL_141:
      if ( v98 != v99
        && (!WORD1(v124)
         || v98 != WORD1(v124)
         && (!WORD2(v124)
          || v98 != WORD2(v124)
          && (!HIWORD(v124)
           || v98 != HIWORD(v124)
           && (!*(_WORD *)v125
            || v98 != *(unsigned __int16 *)v125
            && (!*(_WORD *)&v125[2]
             || v98 != *(unsigned __int16 *)&v125[2]
             && (!*(_WORD *)&v125[4] || v98 != *(unsigned __int16 *)&v125[4] && v98 != *(unsigned __int16 *)&v125[6])))))) )
      {
LABEL_155:
        if ( v94 )
        {
          v97 = *v94;
        }
        else
        {
          v94 = (char *)skb_put(a2, 1);
          v97 = 0;
          *v94 = 0;
        }
        *v94 = v97 + 1;
        v95 = 1;
        *(_BYTE *)skb_put(a2, 1) = v98;
      }
      ++v93;
    }
    while ( v93 != 8 );
    if ( (v95 & 1) != 0 && ((unsigned __int8)v96 & (v94 != nullptr)) == 0 )
      *(_BYTE *)skb_put(a2, 1) = 0;
    if ( (v95 & 1) != 0 )
      *v117 = *(_BYTE *)(a2 + 112) - v120 - 2;
    else
      skb_trim(a2, v120);
    ieee80211_fragment_element(a2, v122, 254);
LABEL_123:
    if ( ++v82 != 15 )
      continue;
    break;
  }
  ieee80211_fragment_element(a2, v111, 242);
  v39 = v113;
  v10 = v115;
  v24 = v104;
  v71 = v106;
LABEL_164:
  if ( *v71 >= 5u )
    ieee80211_put_eht_cap(a2, v10, v24, v71);
  if ( *(_DWORD *)(v24 + 16) == 4 )
  {
    ieee80211_add_aid_request_ie(v10, a2);
    ieee80211_add_s1g_capab_ie(v10, v24 + 68, a2);
  }
  if ( v26 )
  {
    v100 = *(const void **)(v26 + 112);
    if ( v100 )
    {
      v101 = *(unsigned int *)(v26 + 120);
      if ( (_DWORD)v101 )
      {
        v102 = (void *)skb_put(a2, (unsigned int)v101);
        memcpy(v102, v100, v101);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v39;
}
