_WORD *__fastcall ieee80211_prepare_and_rx_handle(__int64 a1, __int64 a2, char a3)
{
  __int64 v4; // x20
  __int64 v6; // x26
  __int64 v7; // x28
  __int16 *v8; // x25
  __int64 v9; // x27
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x22
  unsigned __int16 *v13; // x23
  unsigned __int16 v14; // w24
  int v15; // w0
  unsigned int v16; // w8
  int v17; // w9
  _BOOL4 v18; // w10
  unsigned int v19; // w24
  int v20; // w13
  unsigned __int16 *v21; // x8
  char *v22; // x8
  __int64 v23; // x24
  __int64 v24; // x23
  __int64 v25; // x22
  _WORD *result; // x0
  __int64 v27; // x2
  int v28; // w8
  bool v29; // w9
  int v30; // w11
  int v31; // w9
  __int64 v32; // x10
  int v33; // w8
  __int64 v34; // x12
  int v35; // w11
  int v36; // w12
  __int64 i; // x13
  __int64 v38; // x15
  int v39; // w10
  int v40; // w10
  int v41; // w11
  char v43; // w12
  char v44; // w9
  int v45; // w11
  int v46; // w12
  int v47; // w13
  int v48; // w15
  _WORD *v49; // x1
  int v50; // w10
  int v51; // w14
  int v52; // w15
  int v53; // w9
  __int64 v54; // x12
  __int64 v56; // x11
  int v57; // w13
  unsigned int v58; // w11
  __int64 v59; // x11
  bool v60; // zf
  char v61; // w11
  int v62; // w8
  int v63; // w21
  __int64 v64; // x8
  int v65; // w26
  int *v66; // x9
  int *v67; // x10
  int v68; // w21
  __int16 v69; // w23
  int v70; // w24
  __int16 v71; // w25
  __int64 v72; // x0
  __int64 v73; // x8
  __int64 v74; // x8
  __int64 v75; // x8
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x8
  __int64 v79; // x9
  unsigned __int16 *v80; // x22
  __int64 v81; // x0
  __int64 v82; // x8
  int v83; // w9
  __int64 v84; // x10
  __int16 *v85; // x8
  __int64 v86; // x9
  char v87; // w9
  int v88; // w9
  __int64 v89; // x21
  int v90; // w8
  __int64 v91; // x21
  char v92; // w9
  char v93; // w8
  __int16 v94; // w11
  __int64 v95; // x10
  __int64 v96; // x11
  __int64 **v97; // x8
  unsigned int v98; // w23
  unsigned int v99; // w22
  char v100; // w10
  unsigned int v101; // w8
  unsigned int v102; // w9
  unsigned int v103; // w11
  __int16 v104; // w24
  unsigned __int64 v105; // x13
  __int64 v106; // x9
  __int64 v107; // x10
  _QWORD *v108; // x11
  __int64 v109; // x12
  int v110; // w9
  __int16 v111; // w8
  int v112; // w10
  __int64 v113; // x9
  __int64 v114; // x9
  int v115; // w8
  int v116; // w9
  __int64 v117; // x8
  int v118; // w9
  __int16 *v119; // x8
  int v120; // w0
  __int64 v121; // x9
  int v122; // w10
  int v123; // w8
  int v124; // w1
  __int64 v125; // x0
  __int64 v126; // x8
  unsigned __int64 v132; // x8
  int v133; // [xsp+8h] [xbp-38h]
  unsigned int v134; // [xsp+Ch] [xbp-34h]
  __int64 v135; // [xsp+10h] [xbp-30h]
  __int64 *v136; // [xsp+18h] [xbp-28h] BYREF
  __int64 **v137; // [xsp+20h] [xbp-20h]
  __int64 v138; // [xsp+28h] [xbp-18h]
  __int16 v139; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v140; // [xsp+38h] [xbp-8h]

  v4 = a2;
  v140 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 16);
  v7 = *(_QWORD *)(a1 + 24);
  v8 = *(__int16 **)(a2 + 224);
  v9 = *(_QWORD *)(a1 + 48);
  v10 = *(_QWORD *)(a1 + 32);
  *(_QWORD *)(a1 + 8) = a2;
  v135 = v10;
  if ( (a3 & 1) != 0 )
  {
    v11 = *(_QWORD *)(a1 + 40);
    if ( v11 )
    {
      v12 = *(_QWORD *)(v11 + 160);
      if ( v12 )
      {
        v13 = *(unsigned __int16 **)(a2 + 224);
        v14 = *v13;
        v134 = *(_DWORD *)(a2 + 112);
        v15 = ieee80211_hdrlen(*v13);
        v16 = *(_DWORD *)(v4 + 64);
        if ( (v16 & 0x800) != 0 )
        {
          v17 = *(unsigned __int8 *)(v12 + 29);
          v18 = (v17 & 1) == 0 || (~v16 & 0x402) == 0;
          if ( (v14 & 0x44C) == 8
            && v18
            && (v13[11] & 0xF) == 0
            && !(*((_DWORD *)v13 + 1) ^ *(_DWORD *)(v12 + 12) | v13[4] ^ *(unsigned __int16 *)(v12 + 16))
            && (v14 & 0x300) == *(_WORD *)(v12 + 26) )
          {
            v19 = (v17 << 31 >> 31) & ~(v16 >> 1) & 8;
            v20 = v19 + v15;
            if ( (*(_BYTE *)(v4 + 75) & 8) != 0 )
            {
LABEL_130:
              if ( *(_QWORD *)(a1 + 56) )
              {
                if ( (*(_BYTE *)(v4 + 66) & 0x20) != 0 )
                  goto LABEL_134;
                v63 = v20;
                if ( (unsigned int)pskb_trim(v4, *(_DWORD *)(v4 + 112) - (unsigned int)*(unsigned __int8 *)(v12 + 28)) )
                  goto LABEL_138;
                v20 = v63;
                if ( *(_QWORD *)(a1 + 56) )
                {
LABEL_134:
                  if ( (*v13 & 0x4000) == 0 )
                    goto LABEL_138;
                }
              }
              if ( (*(_BYTE *)(v4 + 75) & 8) == 0 )
              {
                v64 = *(_QWORD *)(v4 + 224);
                v65 = v20;
                v66 = (int *)(v64 + *(unsigned __int8 *)(v12 + 30));
                v67 = (int *)(v64 + *(unsigned __int8 *)(v12 + 31));
                v68 = *v66;
                v69 = *((_WORD *)v66 + 2);
                v70 = *v67;
                v71 = *((_WORD *)v67 + 2);
                skb_postpull_rcsum(v4, v64 + v20);
                skb_pull(v4, (unsigned int)(v65 + 6));
                v72 = skb_push(v4, 12);
                *(_DWORD *)v72 = v68;
                *(_WORD *)(v72 + 4) = v69;
                *(_DWORD *)(v72 + 6) = v70;
                *(_WORD *)(v72 + 10) = v71;
                ieee80211_rx_8023(a1, (__int64 *)v12, v134);
LABEL_184:
                result = (_WORD *)&unk_1;
                goto LABEL_185;
              }
              if ( !(unsigned int)_ieee80211_rx_h_amsdu((_QWORD *)a1, v19) )
                goto LABEL_184;
LABEL_138:
              consume_skb(v4);
              v73 = *(_QWORD *)(a1 + 48);
              if ( (*(_BYTE *)(v12 + 29) & 4) != 0 )
              {
                v75 = *(_QWORD *)(v73 + 104);
                v74 = _ReadStatusReg(TPIDR_EL1) + v75;
              }
              else
              {
                v74 = v73 + 112;
              }
              ++*(_QWORD *)(v74 + 32);
              goto LABEL_184;
            }
            v21 = v13;
            if ( v20 + 8 > v134 - *(_DWORD *)(v4 + 116) )
            {
              if ( v134 < v20 + 8 )
                goto LABEL_16;
              v133 = v19 + v15;
              v125 = _pskb_pull_tail(v4);
              v20 = v133;
              if ( !v125 )
                goto LABEL_16;
              v21 = *(unsigned __int16 **)(v4 + 224);
            }
            v22 = (char *)v21 + v20;
            if ( !(*(_DWORD *)(v12 + 18) ^ *(_DWORD *)v22
                 | *(unsigned __int16 *)(v12 + 22) ^ *((unsigned __int16 *)v22 + 2)) )
            {
              v62 = *((unsigned __int16 *)v22 + 3);
              if ( v62 != 3465 && v62 != *(unsigned __int16 *)(v12 + 24) )
                goto LABEL_130;
            }
          }
        }
      }
    }
  }
LABEL_16:
  v23 = *(_QWORD *)(a1 + 8);
  v24 = *(_QWORD *)(a1 + 24);
  v25 = *(_QWORD *)(v23 + 224);
  result = (_WORD *)ieee80211_get_bssid(v25, *(unsigned int *)(v23 + 112), *(unsigned int *)(v24 + 4720));
  v28 = *(_DWORD *)(v25 + 4);
  v29 = (v28 & 1) != 0 || (*(_WORD *)v25 & 0xFC) == 28;
  v30 = *(_DWORD *)(v24 + 4720);
  if ( v30 > 6 )
  {
    if ( v30 > 10 )
    {
      if ( v30 == 11 )
      {
        if ( result )
        {
          if ( (*(_WORD *)v25 & 0x4C) != 8
            || (unsigned __int16)(result[1] & *result & result[2]) != 0xFFFF
            || !v29
            && **(_DWORD **)(*(_QWORD *)(v24 + 1608) + 1008LL) ^ v28
             | *(unsigned __int16 *)(v25 + 8)
             ^ *(unsigned __int16 *)(*(_QWORD *)(*(_QWORD *)(v24 + 1608) + 1008LL) + 4LL) )
          {
            goto LABEL_106;
          }
          if ( !*(_QWORD *)(a1 + 40) )
            ieee80211_ocb_rx_no_sta((_QWORD *)v24, (__int64)result, v25 + 10);
          goto LABEL_142;
        }
        goto LABEL_185;
      }
      if ( v30 == 12 )
        goto LABEL_106;
    }
    else
    {
      if ( v30 == 7 )
      {
        v40 = *(_DWORD *)(v24 + 5842);
        v41 = *(unsigned __int16 *)(v24 + 5846);
        _ZF = *(_DWORD *)(v25 + 10) == v40 && *(unsigned __int16 *)(v25 + 14) == v41;
        v43 = _ZF || v29;
        v44 = _ZF;
        if ( (v43 & 1) != 0 )
        {
LABEL_72:
          if ( (v44 & 1) != 0 )
            goto LABEL_106;
LABEL_142:
          if ( (a3 & 1) == 0 )
          {
            v76 = skb_copy(v4, 2080);
            *(_QWORD *)(a1 + 8) = v76;
            if ( !v76 )
            {
              if ( (unsigned int)net_ratelimit() )
                dev_printk(
                  &unk_BBEF5,
                  *(_QWORD *)(v6 + 72) + 392LL,
                  "failed to copy skb for %s\n",
                  (const char *)(v7 + 1640));
              goto LABEL_184;
            }
            *(_QWORD *)(*(_QWORD *)(v76 + 216) + *(unsigned int *)(v76 + 212) + 16LL) = *(_QWORD *)(*(_QWORD *)(v4 + 216)
                                                                                                  + *(unsigned int *)(v4 + 212)
                                                                                                  + 16LL);
            v8 = *(__int16 **)(*(_QWORD *)(a1 + 8) + 224LL);
          }
          v77 = *(_QWORD *)(a1 + 40);
          if ( v77 )
          {
            if ( *(_BYTE *)(v77 + 2715) == 1 )
            {
              v110 = *((_DWORD *)v8 + 1);
              if ( (v110 & 1) == 0 )
              {
                v111 = *v8;
                v112 = *v8 & 0xFC;
                if ( v112 != 80 && v112 != 128 )
                {
                  if ( !(*(_DWORD *)(*(_QWORD *)(v135 + 944) + 28LL) ^ v110
                       | (unsigned __int16)v8[4] ^ *(unsigned __int16 *)(*(_QWORD *)(v135 + 944) + 32LL)) )
                  {
                    v113 = *(_QWORD *)(a1 + 24);
                    *((_DWORD *)v8 + 1) = *(_DWORD *)(v113 + 5842);
                    v8[4] = *(_WORD *)(v113 + 5846);
                  }
                  if ( !(*(_DWORD *)(v8 + 5) ^ *(_DWORD *)v9 | (unsigned __int16)v8[7] ^ *(unsigned __int16 *)(v9 + 4)) )
                  {
                    v114 = *(_QWORD *)(a1 + 40);
                    *(_DWORD *)(v8 + 5) = *(_DWORD *)(v114 + 64);
                    v8[7] = *(_WORD *)(v114 + 68);
                  }
                  if ( (v111 & 0x300) == 0 )
                  {
                    v115 = (unsigned __int16)v8[10];
                    v116 = *((_DWORD *)v8 + 4);
                    if ( !(v116 ^ *(_DWORD *)v9 | (unsigned __int16)(v115 ^ *(_WORD *)(v9 + 4))) )
                    {
                      v126 = *(_QWORD *)(a1 + 40);
                      v118 = *(_DWORD *)(v126 + 64);
                      v119 = (__int16 *)(v126 + 68);
                      goto LABEL_243;
                    }
                    if ( !(*(_DWORD *)(*(_QWORD *)(v135 + 944) + 28LL) ^ v116
                         | *(unsigned __int16 *)(*(_QWORD *)(v135 + 944) + 32LL) ^ v115) )
                    {
                      v117 = *(_QWORD *)(a1 + 24);
                      v118 = *(_DWORD *)(v117 + 5842);
                      v119 = (__int16 *)(v117 + 5846);
LABEL_243:
                      *((_DWORD *)v8 + 4) = v118;
                      v8[10] = *v119;
                    }
                  }
                }
              }
            }
          }
          v78 = *(_QWORD *)(a1 + 8);
          v136 = (__int64 *)&v136;
          v79 = *(unsigned int *)(v78 + 64);
          v137 = &v136;
          v138 = 0;
          if ( (v79 & 0x800) != 0 )
            goto LABEL_149;
          if ( *(_DWORD *)(v78 + 112) < 0x18u )
            goto LABEL_149;
          v85 = *(__int16 **)(v78 + 224);
          v94 = *v85;
          if ( (*v85 & 0xC) == 4 )
            goto LABEL_149;
          if ( (v94 & 0x7C) == 0x48 )
            goto LABEL_149;
          v95 = *(_QWORD *)(a1 + 40);
          if ( !v95 )
            goto LABEL_149;
          if ( (v85[2] & 1) != 0 )
          {
            if ( (v94 & 0x4C) != 8 )
              goto LABEL_149;
            v121 = *(_QWORD *)(a1 + 24);
            if ( !*(_WORD *)(v121 + 5800) || *(_DWORD *)(v121 + 4720) != 2 )
              goto LABEL_149;
            v122 = *(unsigned __int16 *)(v121 + 2504);
            v123 = (unsigned __int16)v85[11] >> 4;
            if ( v122 == 4096 || (((_WORD)v122 - (_WORD)v123) & 0xFFFu) >= 0x801 )
            {
              *(_WORD *)(v121 + 2504) = v123;
              goto LABEL_149;
            }
            v124 = 65540;
          }
          else
          {
            if ( (*v85 & 0x800) == 0 )
              goto LABEL_175;
            v96 = *(unsigned int *)(a1 + 68);
            if ( (unsigned int)v96 >= 0x11 )
              goto LABEL_251;
            if ( *(unsigned __int16 *)(v95 + 2 * v96 + 456) != (unsigned __int16)v85[11] )
            {
LABEL_175:
              if ( (v79 & 0x80000) == 0 )
              {
                v79 = *(unsigned int *)(a1 + 68);
                if ( (unsigned int)v79 <= 0x10 )
                {
                  *(_WORD *)(v95 + 2 * v79 + 456) = v85[11];
                  goto LABEL_149;
                }
LABEL_251:
                __break(0x5512u);
                goto LABEL_252;
              }
LABEL_149:
              v4 = *(_QWORD *)(a1 + 8);
              v80 = *(unsigned __int16 **)(v4 + 224);
              v81 = *v80;
              if ( (v81 & 0xC) != 8 && (v81 & 0xFC) != 0xA4 )
                goto LABEL_155;
              v82 = *(_QWORD *)(a1 + 24);
              v83 = *(_DWORD *)(v82 + 4720);
              if ( v83 == 1 || v83 == 11 )
                goto LABEL_155;
              v84 = *(_QWORD *)(a1 + 40);
              if ( v84 )
              {
                if ( (*(_QWORD *)(v84 + 216) & 2) != 0 )
                  goto LABEL_155;
                if ( (v81 & 0x4C) == 8 && v83 == 2 )
                {
                  v139 = 0;
                  v120 = ieee80211_hdrlen(v81);
                  if ( *(_DWORD *)(v4 + 112) < (unsigned int)(v120 + 8) )
                    goto LABEL_248;
                  skb_copy_bits(v4, (unsigned int)(v120 + 6), &v139, 2);
                  v82 = *(_QWORD *)(a1 + 24);
                  if ( v139 == *(_WORD *)(v82 + 1940) )
                  {
                    v4 = *(_QWORD *)(a1 + 8);
                    v80 = *(unsigned __int16 **)(v4 + 224);
                    LODWORD(v81) = *v80;
LABEL_155:
                    if ( (v81 & 0x8C) != 0x88 )
                      goto LABEL_182;
                    if ( (v80[2] & 1) != 0 )
                      goto LABEL_182;
                    v85 = *(__int16 **)(a1 + 40);
                    if ( !v85 )
                      goto LABEL_182;
                    v86 = 12;
                    if ( (~(_DWORD)v81 & 0x300) == 0 )
                      v86 = 15;
                    v87 = v80[v86];
                    v27 = v87 & 0xF;
                    v88 = v87 & 0x60;
                    v89 = *(_QWORD *)&v85[4 * v27 + 348];
                    if ( v89 )
                    {
                      if ( (v81 & 0x40) != 0 || v88 == 32 )
                        goto LABEL_182;
                      if ( *(_WORD *)(v89 + 152) )
                        *(_QWORD *)(v89 + 136) = jiffies;
                      if ( (v80[11] & 0xF) != 0 )
                      {
                        v90 = *(_DWORD *)(a1 + 76);
                        v91 = *(_QWORD *)(a1 + 24);
                        v92 = *(_BYTE *)(v4 + 86);
                        *(_WORD *)(v4 + 180) = 0;
                        if ( v90 < 0 )
                          v93 = v92 & 0xFE;
                        else
                          v93 = v92 & 0xE0 | (2 * (v90 & 0xF)) | 1;
                        *(_BYTE *)(v4 + 86) = v93;
                        skb_queue_tail(v91 + 1984);
                        wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v91 + 1616) + 72LL), v91 + 1960);
                        goto LABEL_183;
                      }
                      v98 = *(unsigned __int16 *)(*(_QWORD *)(v4 + 224) + 22LL);
                      v99 = v98 >> 4;
                      raw_spin_lock(v89 + 16);
                      v100 = *(_BYTE *)(v89 + 155);
                      if ( (v100 & 1) != 0 )
                      {
                        v100 &= ~1u;
                        v101 = v98 >> 4;
                        *(_WORD *)(v89 + 148) = v99;
                        *(_BYTE *)(v89 + 155) = v100;
                        *(_WORD *)(v89 + 144) = v99;
                      }
                      else
                      {
                        v101 = *(unsigned __int16 *)(v89 + 144);
                      }
                      v102 = *(unsigned __int16 *)(v89 + 150);
                      v103 = ((_WORD)v99 - (_WORD)v101) & 0xFFF;
                      if ( (v100 & 4) != 0 )
                      {
                        if ( v103 >= 0x801 )
                        {
LABEL_202:
                          consume_skb(v4);
LABEL_203:
                          raw_spin_unlock(v89 + 16);
                          goto LABEL_183;
                        }
                      }
                      else
                      {
                        if ( v103 > 0x800 )
                        {
LABEL_212:
                          raw_spin_unlock(v89 + 16);
LABEL_182:
                          v97 = v137;
                          *(_QWORD *)v4 = &v136;
                          *(_QWORD *)(v4 + 8) = v97;
                          v137 = (__int64 **)v4;
                          *v97 = (__int64 *)v4;
                          LODWORD(v138) = v138 + 1;
LABEL_183:
                          ieee80211_rx_handlers(a1, &v136);
                          goto LABEL_184;
                        }
                        *(_BYTE *)(v89 + 155) = v100 | 4;
                      }
                      if ( (((_WORD)v99 - (_WORD)v101 - (_WORD)v102) & 0xFFFu) <= 0x800
                        && (((_WORD)v101 - ((_WORD)v99 - (_WORD)v102 + 1)) & 0xFFFu) >= 0x801 )
                      {
                        v104 = v99 - v102 + 1;
                        do
                        {
                          ieee80211_release_reorder_frame(
                            v89,
                            (unsigned __int16)v101 % (unsigned int)*(unsigned __int16 *)(v89 + 150),
                            (__int64)&v136);
                          v101 = *(unsigned __int16 *)(v89 + 144);
                        }
                        while ( (((_WORD)v101 - v104) & 0xFFFu) > 0x800 );
                        v102 = *(unsigned __int16 *)(v89 + 150);
                      }
                      v105 = *(_QWORD *)(v89 + 24);
                      v106 = v99 % v102;
                      v107 = *(_QWORD *)(v89 + 32) + 24LL * (unsigned int)v106;
                      v108 = *(_QWORD **)(v107 + 8);
                      if ( v108 == (_QWORD *)v107 )
                        v109 = 0;
                      else
                        v109 = *(_QWORD *)(v107 + 8);
                      if ( v105 && ((v105 >> v106) & 1) != 0 || v109 && (*(_BYTE *)(v109 + 66) & 8) == 0 )
                        goto LABEL_202;
                      if ( v101 != v98 >> 4 || *(_WORD *)(v89 + 146) )
                      {
                        *(_QWORD *)v4 = v107;
                        *(_QWORD *)(v4 + 8) = v108;
                        *(_QWORD *)(v107 + 8) = v4;
                        *v108 = v4;
                        ++*(_DWORD *)(v107 + 16);
                        if ( (*(_BYTE *)(v4 + 66) & 8) == 0 )
                        {
                          *(_QWORD *)(*(_QWORD *)(v89 + 40) + 8 * v106) = jiffies;
                          ++*(_WORD *)(v89 + 146);
                          ieee80211_sta_reorder_release(v89);
                        }
                        goto LABEL_203;
                      }
                      if ( (*(_BYTE *)(v4 + 66) & 8) == 0 )
                        *(_WORD *)(v89 + 144) = (v99 + 1) & 0xFFF;
                      goto LABEL_212;
                    }
                    if ( v88 != 96 )
                      goto LABEL_182;
                    v79 = 1LL << v27;
                    if ( (*((_QWORD *)v85 + 108) & (1LL << v27)) != 0 )
                      goto LABEL_182;
LABEL_252:
                    _X10 = (unsigned __int64 *)(v85 + 436);
                    __asm { PRFM            #0x11, [X10] }
                    do
                      v132 = __ldxr(_X10);
                    while ( __stlxr(v132 | v79, _X10) );
                    __dmb(0xBu);
                    if ( (v132 & v79) == 0 )
                      ieee80211_send_delba(*(_QWORD *)(a1 + 24), *(_QWORD *)(a1 + 40) + 2688LL, v27, 0, 38);
                    goto LABEL_182;
                  }
                  v83 = *(_DWORD *)(v82 + 4720);
                }
              }
              if ( v83 == 3 && (cfg80211_rx_spurious_frame(*(_QWORD *)(v82 + 1608), v80 + 5, 2080) & 1) != 0 )
              {
                v124 = 65541;
                goto LABEL_249;
              }
LABEL_248:
              v124 = 0x20000;
              goto LABEL_249;
            }
            v124 = 65540;
            ++*(_QWORD *)(*(_QWORD *)(a1 + 48) + 128LL);
          }
LABEL_249:
          ieee80211_rx_handlers_result(a1, v124);
          goto LABEL_184;
        }
        if ( !(v40 ^ v28 | *(unsigned __int16 *)(v25 + 8) ^ v41) )
          goto LABEL_142;
        goto LABEL_106;
      }
      if ( v30 == 10 )
      {
        v33 = *(_WORD *)v25 & 0xFC;
        if ( *(_DWORD *)(v23 + 112) >= 0x19u && v33 == 208 && *(_BYTE *)(v25 + 24) == 4 || v33 == 64 || v33 == 80 )
          goto LABEL_142;
        goto LABEL_39;
      }
    }
LABEL_47:
    result = nullptr;
    __break(0x800u);
    goto LABEL_185;
  }
  if ( (unsigned int)(v30 - 3) < 2 )
  {
    if ( !result )
    {
      v53 = *(unsigned __int16 *)(v25 + 8);
      if ( !(*(_DWORD *)(v24 + 5842) ^ v28 | (unsigned __int16)(v53 ^ *(_WORD *)(v24 + 5846))) )
        goto LABEL_142;
      if ( *(_WORD *)(v24 + 5800) )
      {
        v32 = 0;
        while ( 1 )
        {
          v54 = *(_QWORD *)(v24 + 5680 + 8 * v32);
          if ( v54 )
          {
            if ( !(*(_DWORD *)(v54 + 28) ^ v28 | *(unsigned __int16 *)(v54 + 32) ^ v53) )
              goto LABEL_99;
          }
          ++v32;
          result = nullptr;
          if ( v32 == 15 )
            goto LABEL_185;
        }
      }
      goto LABEL_106;
    }
    v35 = (unsigned __int16)result[2];
    v36 = (unsigned __int16)(result[1] & *result & v35);
    if ( v36 == 0xFFFF || !(*(_DWORD *)result ^ *(_DWORD *)(v24 + 5842) | *(unsigned __int16 *)(v24 + 5846) ^ v35) )
    {
LABEL_56:
      v39 = *(_WORD *)v25 & 0xC;
      if ( (*(_WORD *)v25 & 0x100) != 0 )
        goto LABEL_100;
      if ( v39 == 8 )
        goto LABEL_106;
      if ( v36 == 0xFFFF || (*(_WORD *)v25 & 0xFC) != 0xD0 )
      {
LABEL_100:
        if ( v39 == 8 && v29 )
          goto LABEL_106;
        goto LABEL_142;
      }
      if ( !(*(_DWORD *)result ^ v28 | *(unsigned __int16 *)(v25 + 8) ^ v35) )
        goto LABEL_142;
LABEL_106:
      result = nullptr;
      goto LABEL_185;
    }
    if ( *(_WORD *)(v24 + 5800) )
    {
      for ( i = 0; i != 120; i += 8 )
      {
        v38 = *(_QWORD *)(v24 + 5680 + i);
        if ( v38 )
        {
          if ( !(*(_DWORD *)(v38 + 28) ^ *(_DWORD *)result | *(unsigned __int16 *)(v38 + 32) ^ v35) )
            goto LABEL_56;
        }
      }
    }
    if ( !v29 && (ieee80211_is_our_addr(v24, v25 + 4, (_DWORD *)(a1 + 76)) & 1) == 0 )
      goto LABEL_106;
    v33 = *(_WORD *)v25 & 0xFC;
    if ( *(_DWORD *)(v23 + 112) >= 0x19u && v33 == 208 )
    {
      if ( *(_BYTE *)(v25 + 24) == 4 )
        goto LABEL_142;
      goto LABEL_106;
    }
LABEL_39:
    if ( v33 == 128 )
      goto LABEL_142;
    goto LABEL_106;
  }
  if ( v30 != 1 )
  {
    if ( v30 == 2 )
    {
      if ( !result && !*(_BYTE *)(v24 + 2524) )
        goto LABEL_106;
      if ( (*(_WORD *)(v25 + 22) & 0xF) == 0
        && *(_DWORD *)(v23 + 112) >= 0x19u
        && ((v56 = *(_QWORD *)(v23 + 224), v57 = *(_WORD *)v56 & 0xFC, v57 == 160)
         || v57 == 192
         || v57 == 208
         && ((*(_WORD *)v56 & 0x4000) != 0
          || ((v58 = *(unsigned __int8 *)(v56 + 24), v58 > 0x16) || ((1 << v58) & 0x708890) == 0) && v58 != 127)) )
      {
        v59 = *(_QWORD *)(a1 + 40);
        v60 = v59 == 0;
        if ( v59 )
          v61 = v29;
        else
          v61 = 1;
        v44 = v60;
        if ( (v61 & 1) != 0 )
          goto LABEL_72;
      }
      else if ( v29 )
      {
        goto LABEL_142;
      }
      v31 = *(unsigned __int16 *)(v25 + 8);
      if ( !(*(_DWORD *)(v24 + 5842) ^ v28 | (unsigned __int16)(v31 ^ *(_WORD *)(v24 + 5846))) )
        goto LABEL_142;
      if ( *(_WORD *)(v24 + 5800) )
      {
        v32 = 0;
        while ( 1 )
        {
          v34 = *(_QWORD *)(v24 + 5680 + 8 * v32);
          if ( v34 )
          {
            if ( !(*(_DWORD *)(v34 + 28) ^ v28 | *(unsigned __int16 *)(v34 + 32) ^ v31) )
              break;
          }
          ++v32;
          result = nullptr;
          if ( v32 == 15 )
            goto LABEL_185;
        }
LABEL_99:
        *(_DWORD *)(a1 + 76) = v32;
        goto LABEL_142;
      }
      goto LABEL_106;
    }
    goto LABEL_47;
  }
  if ( result )
  {
    v45 = *(_DWORD *)(v24 + 5842);
    v46 = *(unsigned __int16 *)(v24 + 5846);
    LOWORD(v27) = v25 + 10;
    v47 = *(_DWORD *)(v25 + 10);
    v48 = *(unsigned __int16 *)(v25 + 14);
    if ( !(v47 ^ v45 | v48 ^ v46) )
      goto LABEL_106;
    v49 = result;
    result = nullptr;
    if ( v47 | v48 )
    {
      if ( (v47 & 1) == 0 )
      {
        v50 = *(_DWORD *)(v24 + 2346);
        v51 = *(unsigned __int16 *)(v24 + 2350);
        if ( v50 ^ v47 | v51 ^ v48 )
        {
          if ( (*(_WORD *)v25 & 0xFC) != 0x80 )
          {
            v52 = (unsigned __int16)v49[2];
            if ( *(_DWORD *)v49 ^ v50 | v52 ^ v51 && (v52 & *(_DWORD *)v49 & HIWORD(*(_DWORD *)v49)) != 0xFFFF
              || !v29 && v45 ^ v28 | *(unsigned __int16 *)(v25 + 8) ^ v46 )
            {
              goto LABEL_106;
            }
            if ( !*(_QWORD *)(a1 + 40) )
              ((void (__fastcall *)(__int64))ieee80211_ibss_rx_no_sta)(v24);
          }
          goto LABEL_142;
        }
      }
    }
  }
LABEL_185:
  _ReadStatusReg(SP_EL0);
  return result;
}
