__int64 __fastcall ieee80211_rx_list(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v6; // x20
  unsigned __int64 v7; // x8
  __int64 v8; // x8
  unsigned int v9; // w9
  unsigned int v10; // w1
  bool v11; // w19
  unsigned int v12; // w1
  unsigned int v13; // w1
  unsigned int v14; // w1
  int v15; // w2
  __int64 v16; // x21
  int v17; // w2
  __int64 v18; // x21
  unsigned int v19; // w9
  int v20; // w2
  __int64 v21; // x21
  unsigned int v22; // w8
  __int64 v23; // x21
  __int64 v24; // x26
  int v25; // w9
  unsigned int v26; // w21
  unsigned int v27; // w22
  unsigned int v28; // w9
  unsigned int v29; // w10
  _BOOL4 v30; // w28
  __int16 v31; // w9
  int v32; // w8
  __int64 v33; // x0
  char v34; // w8
  __int64 v35; // x27
  __int64 v36; // x26
  _QWORD *v37; // x22
  _QWORD *v38; // x19
  _QWORD *v39; // x25
  _BOOL4 v40; // w24
  unsigned int v41; // w27
  __int64 v42; // x1
  __int64 v43; // x0
  __int64 v44; // x24
  char v45; // w10
  __int64 v46; // x0
  __int64 v47; // x10
  __int64 v48; // x8
  __int64 v49; // x8
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v57; // x12
  unsigned __int64 v60; // x9
  __int64 v61; // x1
  __int64 v62; // x0
  __int64 v63; // x2
  __int64 v64; // x19
  __int64 v65; // x0
  unsigned __int16 *v66; // x8
  __int64 v67; // x0
  int v68; // w22
  unsigned int v69; // w0
  unsigned int v70; // w8
  __int64 v71; // x8
  _WORD *v72; // x19
  unsigned __int16 *v73; // x9
  int v74; // w10
  __int64 v75; // x10
  char v76; // w10
  unsigned int v77; // w9
  unsigned __int64 v78; // x9
  __int64 v79; // x8
  int v80; // w10
  char v81; // w10
  __int64 *v82; // x9
  __int64 *v83; // x9
  unsigned __int64 v84; // x10
  __int64 v85; // x8
  int v86; // w8
  unsigned __int64 v87; // x8
  __int64 v88; // x22
  char v89; // w23
  int v90; // w25
  __int64 *v91; // x0
  __int64 *v92; // x8
  __int64 *v93; // x8
  unsigned __int64 v94; // x9
  __int64 v95; // x9
  unsigned int v96; // w19
  __int64 v97; // x0
  __int64 v98; // x19
  __int64 v99; // x8
  __int64 v100; // x26
  __int64 *v101; // x9
  __int64 *v102; // x9
  __int64 v103; // x10
  __int64 v104; // x10
  int v105; // w8
  __int64 bss; // x0
  __int64 *v107; // x9
  __int64 *v108; // x9
  __int64 v109; // x10
  __int64 v110; // x10
  __int64 *v111; // x19
  __int64 v112; // x20
  __int64 *v113; // x8
  __int64 *v114; // x0
  __int64 v115; // x22
  __int64 v116; // x0
  __int64 v117; // x1
  __int64 v118; // x2
  __int64 v119; // x3
  __int64 v120; // x8
  __int64 v121; // x0
  unsigned int v122; // w8
  unsigned int v123; // w8
  __int64 *v124; // x9
  __int64 v125; // x10
  __int64 *v126; // x9
  __int64 v127; // x10
  __int64 v128; // x19
  __int64 v129; // x0
  __int64 v130; // x8
  unsigned int v131; // w8
  unsigned int v132; // w8
  __int64 *v133; // x9
  __int64 v134; // x9
  __int64 v135; // x9
  __int64 *v136; // x8
  __int64 v137; // x19
  unsigned int v138; // [xsp+4h] [xbp-7Ch]
  __int64 v139; // [xsp+8h] [xbp-78h]
  __int64 v140; // [xsp+10h] [xbp-70h]
  __int64 v141; // [xsp+18h] [xbp-68h]
  __int64 v142; // [xsp+20h] [xbp-60h] BYREF
  __int64 v143; // [xsp+28h] [xbp-58h]
  __int64 v144; // [xsp+30h] [xbp-50h]
  __int64 *v145; // [xsp+38h] [xbp-48h]
  __int64 *v146; // [xsp+40h] [xbp-40h]
  __int64 v147; // [xsp+48h] [xbp-38h]
  __int64 v148; // [xsp+50h] [xbp-30h]
  __int64 v149; // [xsp+58h] [xbp-28h]
  __int64 v150; // [xsp+60h] [xbp-20h]
  __int64 v151; // [xsp+68h] [xbp-18h]
  __int64 v152; // [xsp+70h] [xbp-10h]
  __int64 v153; // [xsp+78h] [xbp-8h]

  v6 = result;
  v153 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_DWORD *)(_ReadStatusReg(SP_EL0) + 16) & 0xFF00) == 0 )
    __break(0x800u);
  v7 = *(unsigned __int8 *)(a3 + 76);
  if ( v7 >= 6 )
    goto LABEL_40;
  v8 = *(_QWORD *)(*(_QWORD *)(result + 72) + 8 * v7 + 328);
  if ( !v8 )
    goto LABEL_40;
  if ( (*(_BYTE *)(result + 1468) & 1) != 0
    || (*(_BYTE *)(result + 1465) & 1) != 0
    || (*(_BYTE *)(result + 1470) & 1) != 0 )
  {
    goto LABEL_39;
  }
  if ( (*(_BYTE *)(result + 1469) & 1) == 0 )
    goto LABEL_40;
  if ( (*(_BYTE *)(a3 + 64) & 0x40) != 0 )
    goto LABEL_42;
  v9 = *(_BYTE *)(a3 + 71) & 7;
  if ( v9 > 1 )
  {
    switch ( v9 )
    {
      case 2u:
        v13 = *(unsigned __int8 *)(a3 + 73);
        if ( v13 <= 0xB )
        {
          v11 = (unsigned int)*(unsigned __int8 *)(a3 + 74) - 9 < 0xFFFFFFF8;
          if ( (unsigned int)*(unsigned __int8 *)(a3 + 74) - 9 >= 0xFFFFFFF8 )
            goto LABEL_38;
        }
        else
        {
          v11 = 1;
        }
        if ( (ieee80211_rx_list___already_done & 1) != 0 )
          goto LABEL_38;
        v15 = *(unsigned __int8 *)(a3 + 74);
        ieee80211_rx_list___already_done = 1;
        v16 = a4;
        result = _warn_printk("Rate marked as a VHT rate but data is invalid: MCS: %d, NSS: %d\n", v13, v15);
        a4 = v16;
        __break(0x800u);
        if ( !v11 )
          goto LABEL_42;
        break;
      case 3u:
        v14 = *(unsigned __int8 *)(a3 + 73);
        if ( v14 <= 0xB )
        {
          v11 = (unsigned int)*(unsigned __int8 *)(a3 + 74) - 9 < 0xFFFFFFF8;
          if ( (unsigned int)*(unsigned __int8 *)(a3 + 74) - 9 >= 0xFFFFFFF8 )
            goto LABEL_38;
        }
        else
        {
          v11 = 1;
        }
        if ( (ieee80211_rx_list___already_done_6 & 1) != 0 )
          goto LABEL_38;
        v17 = *(unsigned __int8 *)(a3 + 74);
        ieee80211_rx_list___already_done_6 = 1;
        v18 = a4;
        result = _warn_printk("Rate marked as an HE rate but data is invalid: MCS: %d, NSS: %d\n", v14, v17);
        a4 = v18;
        __break(0x800u);
        if ( !v11 )
          goto LABEL_42;
        break;
      case 4u:
        v10 = *(unsigned __int8 *)(a3 + 73);
        if ( v10 <= 0xF && (unsigned int)*(unsigned __int8 *)(a3 + 74) - 9 >= 0xFFFFFFF8 )
        {
          v11 = (~*(unsigned __int8 *)(a3 + 72) & 0x30) == 0;
          if ( (~*(unsigned __int8 *)(a3 + 72) & 0x30) != 0 )
            goto LABEL_38;
        }
        else
        {
          v11 = 1;
        }
        if ( (ieee80211_rx_list___already_done_8 & 1) != 0 )
        {
LABEL_38:
          if ( v11 )
            goto LABEL_39;
          goto LABEL_42;
        }
        v19 = *(unsigned __int8 *)(a3 + 72);
        v20 = *(unsigned __int8 *)(a3 + 74);
        v21 = a4;
        ieee80211_rx_list___already_done_8 = 1;
        result = _warn_printk(
                   "Rate marked as an EHT rate but data is invalid: MCS:%d, NSS:%d, GI:%d\n",
                   v10,
                   v20,
                   (v19 >> 4) & 3);
        a4 = v21;
        __break(0x800u);
        if ( v11 )
          goto LABEL_39;
LABEL_42:
        v141 = 0;
        goto LABEL_43;
      default:
        goto LABEL_25;
    }
    goto LABEL_39;
  }
  if ( (*(_BYTE *)(a3 + 71) & 7) != 0 )
  {
    if ( v9 != 1 )
    {
LABEL_25:
      __break(0x800u);
      goto LABEL_26;
    }
    v12 = *(unsigned __int8 *)(a3 + 73);
    if ( v12 < 0x4D )
      goto LABEL_42;
    _warn_printk(
      "Rate marked as an HT rate but passed status->rate_idx is not an MCS index [0-76]: %d (0x%02x)\n",
      v12,
      *(unsigned __int8 *)(a3 + 73));
    __break(0x800u);
LABEL_39:
    result = sk_skb_reason_drop(0);
    goto LABEL_245;
  }
LABEL_26:
  if ( *(_DWORD *)(v8 + 24) <= (int)*(unsigned __int8 *)(a3 + 73) )
  {
LABEL_40:
    __break(0x800u);
    goto LABEL_39;
  }
  v141 = *(_QWORD *)(v8 + 8) + 12LL * *(unsigned __int8 *)(a3 + 73);
LABEL_43:
  if ( (~*(unsigned __int8 *)(a3 + 86) & 0x1E) == 0 )
    goto LABEL_40;
  v22 = *(_DWORD *)(a3 + 64);
  v23 = a3;
  *(_BYTE *)(a3 + 75) = 0;
  if ( (v22 & 0x40000000) != 0 )
    goto LABEL_112;
  v24 = *(_QWORD *)(v6 + 5384);
  if ( (v22 & 0x100000) != 0 && *(__int16 *)(a3 + 186) == -1 )
    goto LABEL_249;
  v25 = ((int)(32 * v22) >> 31) & 0xC;
  if ( (v22 & 0x8000000) != 0 )
    v25 = (((int)(32 * v22) >> 31) & 0xC) + 12;
  if ( (v22 & 0x100000) != 0 )
  {
    v26 = *(_DWORD *)(a3 + 216) + *(unsigned __int16 *)(a3 + 186) - *(_DWORD *)(a3 + 224);
    if ( (v22 & 0x20000000) != 0 )
      goto LABEL_51;
  }
  else
  {
    v26 = v25 + ((v22 >> 26) & 4);
    if ( (v22 & 0x20000000) != 0 )
    {
LABEL_51:
      v27 = 0;
      v28 = v26;
      goto LABEL_58;
    }
  }
  if ( (*(_QWORD *)(v6 + 96) & 2) != 0 )
  {
    if ( *(_DWORD *)(a3 + 112) > v26 + 4 )
    {
      v27 = 4;
      goto LABEL_57;
    }
LABEL_249:
    __break(0x800u);
    goto LABEL_106;
  }
  v27 = 0;
LABEL_57:
  v28 = v26 + 2;
LABEL_58:
  v29 = *(_DWORD *)(a3 + 112);
  if ( v28 > v29 - *(_DWORD *)(a3 + 116) )
  {
    if ( v29 < v28 )
      goto LABEL_106;
    v137 = a4;
    if ( !_pskb_pull_tail(a3) )
      goto LABEL_106;
    v22 = *(_DWORD *)(a3 + 64);
    a4 = v137;
  }
  if ( (v22 & 0x20000064) != 0 || *(_DWORD *)(a3 + 112) < v26 + v27 + 16 )
  {
    v30 = 1;
    if ( (v22 & 0x40000) != 0 )
      goto LABEL_105;
    goto LABEL_65;
  }
  v31 = *(_WORD *)(*(_QWORD *)(a3 + 224) + v26);
  if ( (v31 & 0xC) == 4 )
  {
    v30 = (((v31 & 0xF4) - 132) & 0xFFFFFFD0) != 0;
    if ( (v22 & 0x40000) != 0 )
      goto LABEL_105;
LABEL_65:
    if ( *(_DWORD *)(v6 + 1320) )
      goto LABEL_66;
LABEL_105:
    if ( v30 )
    {
LABEL_106:
      v65 = a3;
      goto LABEL_244;
    }
LABEL_110:
    v62 = a3;
    v61 = v27;
    v63 = v26;
    v64 = a4;
    goto LABEL_111;
  }
  if ( (v22 & 0x40000) != 0 || !*(_DWORD *)(v6 + 1320) )
    goto LABEL_110;
  v30 = 0;
LABEL_66:
  v138 = v27;
  v139 = a4;
  v140 = a2;
  if ( v24 )
  {
    if ( (int)v26 + 50LL <= (unsigned __int64)*(unsigned int *)(a3 + 112) )
    {
      v32 = *(_DWORD *)(v24 + 2268);
      if ( (v32 & 1) == 0 )
      {
        if ( v32 | *(unsigned __int16 *)(v24 + 2272) )
        {
          LOWORD(v145) = 0;
          v143 = 0;
          v144 = 0;
          v142 = 0;
          skb_copy_bits(a3, v26, &v142, 26);
          if ( (v142 & 0xFC) == 0xD0
            && (unsigned __int8)v145 == 21
            && BYTE1(v145) == 1
            && !(*(_DWORD *)(v24 + 2268) ^ HIDWORD(v142) | *(unsigned __int16 *)(v24 + 2272) ^ (unsigned __int16)v143) )
          {
            v33 = skb_copy(a3, 2080);
            if ( v33 )
            {
              v34 = *(_BYTE *)(v33 + 86);
              *(_WORD *)(v33 + 180) = 0;
              *(_BYTE *)(v33 + 86) = v34 & 0xFE;
              skb_queue_tail(v24 + 1984);
              wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v24 + 1616) + 72LL), v24 + 1960);
            }
          }
        }
      }
    }
  }
  v35 = 0;
  v36 = a3;
  v37 = (_QWORD *)(v6 + 4632);
  v38 = (_QWORD *)(v6 + 4632);
  do
  {
    v38 = (_QWORD *)*v38;
    if ( v38 == v37 )
      break;
    v39 = (_QWORD *)*v38;
    if ( !v35 )
    {
      v40 = v39 == v37 && v30;
      v41 = ieee80211_rx_radiotap_hdrlen(v6, v36 + 40, v36);
      v42 = v41 - v26;
      if ( v40 )
      {
        if ( (unsigned int)v42 > *(_DWORD *)(v36 + 224) - *(_DWORD *)(v36 + 216)
          && (unsigned int)pskb_expand_head(v36, v42, 0, 2080) )
        {
          consume_skb(v36);
          v36 = 0;
          v35 = 0;
          continue;
        }
        v44 = 0;
      }
      else
      {
        v43 = skb_copy_expand(v36, (unsigned int)(v42 + 64), 0, 2080);
        if ( !v43 )
        {
          v35 = 0;
          continue;
        }
        v44 = v36;
        v36 = v43;
      }
      ieee80211_add_rx_radiotap_header(v6, v36, v141, v41, 1);
      v45 = *(_BYTE *)(v36 + 128);
      *(_WORD *)(v36 + 186) = *(_DWORD *)(v36 + 224) - *(_DWORD *)(v36 + 216);
      *(_BYTE *)(v36 + 128) = v45 & 0x98 | 0x23;
      *(_WORD *)(v36 + 180) = 1024;
      if ( !v36 )
      {
        v35 = 0;
        v36 = v44;
        continue;
      }
      v35 = v36;
      v36 = v44;
    }
    if ( v39 == v37 )
    {
      v46 = v35;
      v35 = 0;
LABEL_97:
      v47 = *(unsigned int *)(v46 + 112);
      v48 = *(v38 - 84);
      *(_QWORD *)(v46 + 16) = v48;
      v49 = *(_QWORD *)(v48 + 160);
      StatusReg = _ReadStatusReg(TPIDR_EL1);
      _X11 = (unsigned __int64 *)(StatusReg + v49 + 8);
      __asm { PRFM            #0x11, [X11] }
      do
        v57 = __ldxr(_X11);
      while ( __stxr(v57 + v47, _X11) );
      _X8 = (unsigned __int64 *)(v49 + StatusReg);
      __asm { PRFM            #0x11, [X8] }
      do
        v60 = __ldxr(_X8);
      while ( __stxr(v60 + 1, _X8) );
      netif_receive_skb();
      continue;
    }
    v46 = skb_clone(v35, 2080);
    if ( v46 )
      goto LABEL_97;
  }
  while ( v39 != v37 );
  result = consume_skb(v35);
  a2 = v140;
  if ( !v36 )
    goto LABEL_245;
  v61 = v138;
  v62 = v36;
  v63 = v26;
  v64 = v139;
LABEL_111:
  result = ieee80211_clean_skb(v62, v61, v63);
  a4 = v64;
  v23 = result;
LABEL_112:
  if ( !v23 )
    goto LABEL_245;
  if ( (*(_BYTE *)(a3 + 67) & 0x40) != 0 )
  {
    v151 = 0;
    v152 = 0;
    v149 = 0;
    v150 = 0;
    v147 = 0;
    v148 = 0;
    v145 = nullptr;
    v146 = nullptr;
    v143 = v23;
    v144 = v6;
    v142 = a4;
    if ( !a2 || *(_DWORD *)(v23 + 112) < 0xEu )
      goto LABEL_243;
    v78 = *(unsigned __int8 *)(v23 + 86);
    v79 = (v78 >> 1) & 0xF;
    if ( (v78 & 1) != 0 )
      v80 = (v78 >> 1) & 0xF;
    else
      v80 = -1;
    HIDWORD(v151) = v80;
    v81 = v78;
    v147 = a2 - 2688;
    if ( a2 == 2688 )
    {
      if ( (v78 & 1) != 0 )
      {
        HIDWORD(v151) = (v78 >> 1) & 0xF;
        v146 = (__int64 *)qword_11D8[(v78 >> 1) & 0xF];
        if ( !v146 )
          goto LABEL_243;
        goto LABEL_158;
      }
      v82 = nullptr;
    }
    else
    {
      v82 = *(__int64 **)(a2 - 2608);
      v144 = v82[202];
      v145 = v82;
      v148 = a2 - 1048;
      if ( (v81 & 1) != 0 )
      {
        HIDWORD(v151) = v79;
        v83 = (__int64 *)v82[v79 + 571];
        v84 = (unsigned __int64)*(unsigned __int16 *)(a2 + 184) >> v79;
        v146 = v83;
        if ( (v84 & 1) == 0 )
          goto LABEL_243;
        v85 = *(_QWORD *)(a2 + 8 * v79 - 120);
        v148 = v85;
        if ( !v83 || !v85 )
          goto LABEL_243;
LABEL_158:
        if ( !*(_QWORD *)(a2 - 2528) )
          goto LABEL_243;
        result = ieee80211_rx_8023(&v142);
        goto LABEL_245;
      }
    }
    v146 = v82 + 452;
    goto LABEL_158;
  }
  v66 = *(unsigned __int16 **)(v23 + 224);
  v151 = 0;
  v152 = 0;
  v149 = 0;
  v150 = 0;
  v147 = 0;
  v148 = 0;
  v145 = nullptr;
  v146 = nullptr;
  v143 = 0;
  v144 = 0;
  v142 = 0;
  v67 = *v66;
  v146 = nullptr;
  v147 = 0;
  v148 = 0;
  v149 = 0;
  v68 = v67 & 0xC;
  v150 = 0;
  v152 = 0;
  v142 = a4;
  v143 = v23;
  HIDWORD(v151) = -1;
  v144 = v6;
  v145 = nullptr;
  if ( (v67 & 0xC) != 0 )
  {
    v69 = ieee80211_hdrlen(v67);
    v70 = *(_DWORD *)(v23 + 112);
    if ( v69 <= v70 - *(_DWORD *)(v23 + 116) )
      goto LABEL_116;
    if ( v70 < v69 )
      goto LABEL_243;
LABEL_153:
    if ( !_pskb_pull_tail(v23) )
      goto LABEL_243;
  }
  else
  {
    v96 = *(_DWORD *)(v23 + 112);
    if ( v96 < (unsigned int)ieee80211_hdrlen(v67) )
      goto LABEL_243;
    if ( *(_DWORD *)(v23 + 116) )
      goto LABEL_153;
  }
LABEL_116:
  v71 = v143;
  v72 = *(_WORD **)(v23 + 224);
  v73 = *(unsigned __int16 **)(v143 + 224);
  v74 = *v73;
  if ( (v74 & 0x8C) == 0x88 )
  {
    _ZF = (~v74 & 0x300) == 0;
    v75 = 12;
    if ( _ZF )
      v75 = 15;
    v76 = v73[v75];
    v77 = v76 & 0xF;
    if ( v76 < 0 )
      *(_BYTE *)(v143 + 75) |= 8u;
    HIDWORD(v150) = v76 & 0xF;
    LODWORD(v151) = HIDWORD(v150);
    if ( v77 > 7 )
      v77 = 0;
  }
  else
  {
    v77 = 0;
    HIDWORD(v150) = 16;
    LODWORD(v151) = 16 * ((v74 & 0xC) == 0);
  }
  *(_DWORD *)(v71 + 144) = v77;
  v86 = *v72 & 0xFC;
  if ( v86 == 80 || v86 == 128 || v86 == 28 )
  {
    ieee80211_scan_rx(v6, v23);
    if ( v68 != 8 )
      goto LABEL_197;
  }
  else if ( v68 != 8 )
  {
    goto LABEL_197;
  }
  v87 = *(unsigned __int8 *)(v23 + 86);
  v88 = (v87 >> 1) & 0xF;
  v89 = *(_BYTE *)(v23 + 86);
  if ( (v87 & 1) != 0 )
    v90 = (v87 >> 1) & 0xF;
  else
    v90 = -1;
  if ( a2 )
  {
    HIDWORD(v151) = v90;
    v147 = a2 - 2688;
    if ( a2 == 2688 )
    {
      v91 = v145;
      v148 = 0;
      if ( (v89 & 1) != 0 )
      {
        HIDWORD(v151) = (v87 >> 1) & 0xF;
        v146 = (__int64 *)v145[((v87 >> 1) & 0xF) + 571];
        if ( !v146 )
          goto LABEL_243;
        goto LABEL_242;
      }
    }
    else
    {
      v91 = v145;
      v92 = *(__int64 **)(a2 - 2608);
      v144 = v92[202];
      if ( !v145 )
      {
        v91 = v92;
        v145 = v92;
      }
      v148 = a2 - 1048;
      if ( (v89 & 1) != 0 )
      {
        HIDWORD(v151) = v88;
        v93 = (__int64 *)v91[v88 + 571];
        v94 = (unsigned __int64)*(unsigned __int16 *)(a2 + 184) >> v88;
        v146 = v93;
        if ( (v94 & 1) != 0 )
        {
          v95 = *(_QWORD *)(a2 + 8 * v88 - 120);
          v148 = v95;
          if ( v93 )
            goto LABEL_238;
        }
        goto LABEL_243;
      }
    }
    v105 = *(unsigned __int8 *)(a2 + 27);
    v146 = v91 + 452;
    if ( v105 == 1 )
    {
      bss = link_sta_info_get_bss(v91, v72 + 5);
      if ( !bss )
        goto LABEL_243;
      ieee80211_rx_data_set_link(&v142, *(unsigned __int8 *)(bss + 6));
    }
    goto LABEL_242;
  }
  v97 = sta_info_hash_lookup(v6, v72 + 5);
  if ( v97 )
  {
    v98 = v97;
    v99 = 0;
    v100 = 1LL << v88;
    while ( 1 )
    {
      if ( v99 )
      {
        v101 = *(__int64 **)(v99 + 80);
        HIDWORD(v151) = v90;
        v147 = v99;
        v144 = v101[202];
        v145 = v101;
        if ( !v101 )
          v145 = nullptr;
        v148 = v99 + 1640;
        if ( (v89 & 1) != 0 )
        {
          HIDWORD(v151) = v88;
          v102 = (__int64 *)v101[(unsigned int)v88 + 571];
          v103 = *(unsigned __int16 *)(v99 + 2872);
          v146 = v102;
          if ( (v100 & v103) == 0 )
            goto LABEL_243;
          v104 = *(_QWORD *)(v99 + 8LL * (unsigned int)v88 + 2568);
          v148 = v104;
          if ( !v102 || !v104 )
            goto LABEL_243;
        }
        else
        {
          v146 = v101 + 452;
        }
        if ( (*(_BYTE *)(v23 + 86) & 1) == 0 && (*(_BYTE *)(v99 + 2715) & 1) != 0 )
          goto LABEL_164;
        ieee80211_prepare_and_rx_handle(&v142, v23, 0);
      }
      v99 = v98 - 48;
LABEL_164:
      v98 = *(_QWORD *)(v98 + 8);
      if ( !v98 )
      {
        if ( v99 )
        {
          v107 = *(__int64 **)(v99 + 80);
          HIDWORD(v151) = v90;
          v147 = v99;
          v144 = v107[202];
          v145 = v107;
          if ( !v107 )
            v145 = nullptr;
          v148 = v99 + 1640;
          if ( (v89 & 1) != 0 )
          {
            HIDWORD(v151) = v88;
            v108 = (__int64 *)v107[(unsigned int)v88 + 571];
            v109 = *(unsigned __int16 *)(v99 + 2872);
            v146 = v108;
            if ( (v100 & v109) != 0 )
            {
              v110 = *(_QWORD *)(v99 + 8LL * (unsigned int)v88 + 2568);
              v148 = v110;
              if ( v108 )
              {
                if ( v110 )
                  goto LABEL_192;
              }
            }
          }
          else
          {
            v146 = v107 + 452;
LABEL_192:
            if ( (*(_BYTE *)(v23 + 86) & 1) != 0 || (*(_BYTE *)(v99 + 2715) & 1) == 0 )
              goto LABEL_242;
          }
LABEL_243:
          v65 = v23;
LABEL_244:
          result = consume_skb(v65);
          goto LABEL_245;
        }
        break;
      }
    }
  }
LABEL_197:
  v111 = *(__int64 **)(v6 + 4616);
  v112 = v6 + 4616;
  if ( v111 == (__int64 *)v112 )
    goto LABEL_243;
  v113 = nullptr;
  do
  {
    v114 = v113;
    if ( (v111[204] & 1) != 0 && (*((_DWORD *)v111 + 1180) | 2) != 6 )
    {
      v113 = v111;
      if ( v114 )
      {
        v115 = *(_QWORD *)(v23 + 224);
        v145 = v114;
        v116 = link_sta_info_get_bss(v114, v115 + 10);
        if ( v116 )
        {
          v120 = v116;
          v121 = *(_QWORD *)(v116 + 32);
          v122 = *(unsigned __int8 *)(v120 + 6);
        }
        else
        {
          v121 = sta_info_get_bss(v145, v115 + 10);
          v123 = *(unsigned __int8 *)(v23 + 86);
          if ( (v123 & 1) != 0 )
            v122 = (v123 >> 1) & 0xF;
          else
            v122 = -1;
        }
        HIDWORD(v151) = v122;
        v147 = v121;
        if ( v121 )
        {
          v124 = *(__int64 **)(v121 + 80);
          v144 = v124[202];
          if ( !v145 )
            v145 = v124;
          v148 = v121 + 1640;
          if ( (v122 & 0x80000000) != 0 )
          {
LABEL_219:
            v146 = v145 + 452;
LABEL_221:
            ieee80211_prepare_and_rx_handle(&v142, v23, 0);
            v113 = v111;
            goto LABEL_199;
          }
        }
        else
        {
          v148 = 0;
          if ( (v122 & 0x80000000) != 0 )
            goto LABEL_219;
        }
        HIDWORD(v151) = v122;
        if ( (v122 & 0xF0) != 0 )
          goto LABEL_253;
        v125 = v122;
        v126 = (__int64 *)v145[v122 + 571];
        v146 = v126;
        if ( !v121 )
        {
          v113 = v111;
          if ( !v126 )
            goto LABEL_199;
          goto LABEL_221;
        }
        v113 = v111;
        if ( (((unsigned __int64)*(unsigned __int16 *)(v121 + 2872) >> v125) & 1) != 0 )
        {
          v127 = *(_QWORD *)(v121 + 8 * v125 + 2568);
          v113 = v111;
          v148 = v127;
          if ( v126 )
          {
            v113 = v111;
            if ( v127 )
              goto LABEL_221;
          }
        }
      }
    }
LABEL_199:
    v111 = (__int64 *)*v111;
  }
  while ( v111 != (__int64 *)v112 );
  if ( !v113 )
    goto LABEL_243;
  v128 = *(_QWORD *)(v23 + 224);
  v145 = v113;
  v129 = link_sta_info_get_bss(v113, v128 + 10);
  if ( v129 )
  {
    v130 = v129;
    v121 = *(_QWORD *)(v129 + 32);
    v131 = *(unsigned __int8 *)(v130 + 6);
  }
  else
  {
    v121 = sta_info_get_bss(v145, v128 + 10);
    v132 = *(unsigned __int8 *)(v23 + 86);
    if ( (v132 & 1) != 0 )
      v131 = (v132 >> 1) & 0xF;
    else
      v131 = -1;
  }
  HIDWORD(v151) = v131;
  v147 = v121;
  if ( v121 )
  {
    v133 = *(__int64 **)(v121 + 80);
    v144 = v133[202];
    if ( !v145 )
      v145 = v133;
    v134 = v121 + 1640;
  }
  else
  {
    v134 = 0;
  }
  v148 = v134;
  if ( (v131 & 0x80000000) != 0 )
  {
    v146 = v145 + 452;
    goto LABEL_242;
  }
  HIDWORD(v151) = v131;
  if ( (v131 & 0xF0) != 0 )
  {
LABEL_253:
    __break(0x5512u);
    return ieee80211_rx_napi(v121, v117, v118, v119);
  }
  v135 = v131;
  v136 = (__int64 *)v145[v131 + 571];
  v146 = v136;
  if ( !v121 )
  {
    if ( !v136 )
      goto LABEL_243;
    goto LABEL_242;
  }
  if ( (((unsigned __int64)*(unsigned __int16 *)(v121 + 2872) >> v135) & 1) == 0 )
    goto LABEL_243;
  v95 = *(_QWORD *)(v121 + 8 * v135 + 2568);
  v148 = v95;
  if ( !v136 )
    goto LABEL_243;
LABEL_238:
  if ( !v95 )
    goto LABEL_243;
LABEL_242:
  result = ieee80211_prepare_and_rx_handle(&v142, v23, 1);
  if ( (result & 1) == 0 )
    goto LABEL_243;
LABEL_245:
  _ReadStatusReg(SP_EL0);
  return result;
}
