__int64 __fastcall ieee80211_rx_handlers(__int64 a1, __int64 **a2)
{
  __int64 *v4; // x8
  unsigned int v5; // w22
  __int64 v6; // x9
  _QWORD *v7; // x10
  __int64 v8; // x9
  __int64 v9; // x0
  __int16 v10; // w8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  unsigned __int16 *v15; // x8
  int v16; // w10
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x21
  __int64 v20; // x23
  __int64 v21; // x24
  int v22; // w8
  unsigned __int16 *v23; // x22
  __int64 bssid; // x0
  __int64 v25; // x9
  __int64 v26; // x9
  unsigned __int64 v27; // x8
  char v28; // w8
  __int64 v29; // x8
  __int64 v30; // x8
  __int64 v31; // x9
  unsigned __int64 v32; // x8
  __int64 v33; // x8
  __int64 v34; // x8
  __int64 v35; // x9
  unsigned __int64 v36; // x8
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x9
  unsigned __int64 v40; // x8
  __int64 v41; // x8
  __int64 v42; // x8
  __int64 v43; // x9
  unsigned __int64 v44; // x8
  int v45; // w8
  __int64 v46; // x8
  int v47; // w9
  __int64 v48; // x21
  unsigned __int16 *v49; // x24
  __int64 v50; // x22
  unsigned __int16 *v51; // x8
  unsigned int v52; // w23
  __int64 v53; // x10
  unsigned int v54; // w25
  __int16 v55; // w24
  __int64 v56; // x21
  __int64 v57; // x0
  unsigned __int16 *v58; // x1
  int v59; // w23
  __int64 v60; // x8
  unsigned int v61; // w8
  __int64 v62; // x8
  __int16 v63; // w23
  unsigned __int64 v64; // x9
  __int64 v65; // x22
  int v66; // w0
  int v67; // w11
  __int64 v68; // x10
  unsigned int v69; // w9
  __int64 v70; // x9
  __int64 v71; // x10
  int v72; // w12
  unsigned int v73; // w12
  __int64 v74; // x11
  __int64 v75; // x9
  _BYTE *v76; // x24
  char v77; // w12
  int v78; // t1
  __int64 v79; // x8
  char v80; // w9
  int v81; // w10
  __int64 v82; // x10
  __int64 v83; // x8
  __int64 v84; // x9
  __int64 v85; // x22
  int v86; // w0
  unsigned __int64 v87; // x9
  __int64 v88; // x8
  __int64 v89; // x21
  __int64 v90; // x24
  __int64 v91; // x26
  int v92; // w3
  __int64 v93; // x8
  char v94; // w27
  __int64 v96; // x8
  __int64 v97; // x12
  __int64 v98; // x9
  __int64 v99; // x11
  __int64 v100; // x10
  __int64 v101; // x10
  __int64 v102; // x11
  __int64 v103; // x8
  __int64 v104; // x0
  __int64 v105; // x22
  int v106; // w25
  int v107; // w28
  char v108; // w9
  __int64 v109; // x9
  __int64 v110; // x22
  __int64 v111; // x8
  __int64 v112; // x0
  __int64 v113; // x21
  __int64 v114; // x0
  _QWORD *v115; // x9
  _QWORD *v116; // x9
  int v117; // w8
  unsigned int v118; // w0
  __int64 v119; // x0
  __int64 v120; // x1
  __int64 v121; // x2
  __int64 v122; // x0
  __int64 v123; // x21
  __int64 v124; // x22
  unsigned int v125; // w0
  __int64 *v126; // x8
  __int64 **v127; // x9
  int v128; // w8
  int v129; // w8
  __int64 v130; // x9
  __int64 v131; // x21
  unsigned int v132; // w23
  __int64 v133; // x24
  __int64 v134; // x22
  int v135; // w8
  __int64 v136; // x8
  int v137; // w9
  unsigned int v138; // w9
  __int64 v139; // x24
  __int64 v140; // x0
  __int64 v141; // x8
  unsigned int v142; // w8
  __int64 v143; // x8
  __int64 v144; // x4
  __int64 v145; // x8
  unsigned int v146; // w9
  int v147; // w9
  __int16 v148; // w10
  int v149; // w10
  __int16 v150; // w9
  __int16 v151; // w9
  __int16 v152; // w9
  __int16 v153; // w9
  unsigned int v155; // w8
  int v156; // w8
  __int64 v157; // x8
  __int64 v158; // x8
  __int64 v159; // x10
  int v160; // w11
  __int64 v161; // x24
  int v162; // w8
  int v163; // w0
  unsigned int v164; // w8
  __int64 v165; // x8
  __int16 v166; // w9
  __int64 *v168; // x0
  __int64 v169; // x8
  __int64 *v170; // x9
  int v171; // w8
  int v172; // w9
  __int64 v173; // x8
  int v174; // w10
  int v175; // w11
  unsigned int v176; // w11
  int v177; // w8
  int v178; // w8
  char v179; // w0
  __int64 *i; // x22
  __int64 v181; // x8
  __int64 *v182; // x9
  __int64 v183; // x2
  __int64 v184; // x2
  char *v185; // x8
  unsigned int v186; // w10
  int v187; // w9
  unsigned int v188; // w9
  int v189; // w8
  __int64 v190; // x8
  __int16 v191; // w10
  int v192; // w8
  int v193; // w10
  int v194; // w8
  __int64 v195; // x8
  __int64 v196; // x10
  __int64 v197; // x9
  __int64 v198; // x22
  int v199; // w8
  int v200; // w9
  __int64 v201; // x24
  __int64 v202; // x0
  __int64 v203; // x8
  __int64 v204; // x23
  __int64 v205; // x9
  __int64 v206; // x0
  __int64 v207; // x24
  __int16 v208; // w9
  int v209; // w9
  int v210; // w9
  unsigned int v211; // w9
  int v212; // w11
  unsigned int v213; // w12
  unsigned int v214; // w11
  char *v215; // x11
  int v216; // w8
  char v217; // w10
  char v218; // w8
  char v219; // w10
  int v220; // w9
  int v221; // w0
  __int64 v222; // x8
  int v223; // w0
  __int64 v224; // x8
  unsigned __int64 v225; // x8
  __int64 v226; // x21
  int v227; // w0
  __int64 v228; // x2
  __int64 v229; // x0
  __int64 v230; // x1
  unsigned int v231; // w4
  int v232; // w0
  unsigned __int64 v233; // x8
  unsigned __int64 v234; // x22
  __int64 v235; // x8
  __int64 v236; // x9
  __int64 v237; // x23
  unsigned int v238; // w24
  int v239; // w9
  __int64 v240; // x22
  __int64 v241; // x0
  unsigned int v242; // w11
  unsigned __int64 v245; // x8
  unsigned __int64 v248; // x8
  unsigned __int64 v251; // x9
  unsigned __int64 v256; // x9
  unsigned __int64 v259; // x9
  unsigned __int64 v262; // x9
  unsigned __int64 v265; // x8
  __int64 result; // x0
  __int64 v267; // [xsp+0h] [xbp-50h]
  int v268; // [xsp+Ch] [xbp-44h] BYREF
  __int64 v269; // [xsp+10h] [xbp-40h] BYREF
  __int64 v270; // [xsp+18h] [xbp-38h]
  __int64 v271; // [xsp+20h] [xbp-30h]
  __int64 v272; // [xsp+28h] [xbp-28h]
  __int64 v273; // [xsp+30h] [xbp-20h]
  __int64 v274; // [xsp+38h] [xbp-18h]
  __int64 v275; // [xsp+40h] [xbp-10h]
  __int64 v276; // [xsp+48h] [xbp-8h]

  v276 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  raw_spin_lock_bh(*(_QWORD *)(a1 + 16) + 1600LL);
  v4 = *a2;
  if ( *a2 != (__int64 *)a2 && v4 )
  {
    v5 = 0x20000;
    while ( 1 )
    {
      --*((_DWORD *)a2 + 4);
      v6 = *v4;
      v7 = (_QWORD *)v4[1];
      *v4 = 0;
      v4[1] = 0;
      *(_QWORD *)(v6 + 8) = v7;
      *v7 = v6;
      v8 = *(_QWORD *)(a1 + 32);
      *(_QWORD *)(a1 + 8) = v4;
      if ( !v8 )
      {
        __break(0x800u);
        goto LABEL_301;
      }
      v9 = *(_QWORD *)(a1 + 16);
      if ( *(_BYTE *)(v9 + 5004) != 1 )
        goto LABEL_9;
      v10 = *(_WORD *)v4[28];
      if ( (v10 & 0x20C) != 0x208 )
        goto LABEL_9;
      if ( (v10 & 0x2000) == 0 )
        break;
      ieee80211_send_pspoll(v9, *(_QWORD *)(a1 + 24));
      v11 = *(_QWORD *)(a1 + 40);
      if ( !v11 )
        goto LABEL_25;
LABEL_10:
      v12 = *(_QWORD *)(a1 + 24);
      if ( (unsigned int)(*(_DWORD *)(v12 + 4720) - 3) <= 1 )
      {
        v13 = *(_QWORD *)(a1 + 8);
        v14 = *(_QWORD *)(v12 + 1616);
        v15 = *(unsigned __int16 **)(v13 + 224);
        if ( (*(_QWORD *)(v14 + 96) & 0x100000) == 0 && (*(_QWORD *)(v11 + 216) & 4) != 0 )
        {
          v16 = *v15;
          if ( (v16 & 0xFC) == 0xA4 )
          {
            ieee80211_sta_pspoll(v11 + 2688);
LABEL_87:
            consume_skb(*(_QWORD *)(a1 + 8));
            v5 = 0;
            goto LABEL_301;
          }
          if ( (v16 & 0x400) == 0 && (v16 & 0x108C) == 0x1088 && (*(_BYTE *)(v13 + 75) & 0x20) == 0 )
          {
            v17 = 12;
            if ( (~v16 & 0x300) == 0 )
              v17 = 15;
            v18 = ieee802_1d_to_ac[v15[v17] & 7];
            if ( (unsigned int)v18 >= 4 )
LABEL_667:
              __break(0x5512u);
            if ( ((unsigned __int8)ieee80211_ac_to_qos_mask[v18] & *(_BYTE *)(v11 + 2699)) != 0
              && (*(_QWORD *)(v11 + 216) & 0x40000) == 0 )
            {
              if ( (*(_QWORD *)(v11 + 216) & 0x200) != 0 )
              {
                _X8 = (unsigned __int64 *)(v11 + 216);
                __asm { PRFM            #0x11, [X8] }
                do
                  v251 = __ldxr(_X8);
                while ( __stxr(v251 | 0x20000, _X8) );
              }
              else
              {
                ieee80211_sta_ps_deliver_uapsd(v11);
              }
            }
          }
        }
      }
LABEL_25:
      v19 = *(_QWORD *)(a1 + 40);
      if ( !v19 )
        goto LABEL_88;
      v20 = *(_QWORD *)(a1 + 48);
      if ( !v20 )
        goto LABEL_88;
      v21 = *(_QWORD *)(a1 + 8);
      v22 = *(_DWORD *)(*(_QWORD *)(a1 + 24) + 4720LL);
      v23 = *(unsigned __int16 **)(v21 + 224);
      if ( v22 == 11 )
      {
        *(_QWORD *)(v20 + 120) = jiffies;
        goto LABEL_39;
      }
      if ( v22 == 1 )
      {
        bssid = ieee80211_get_bssid(*(_QWORD *)(v21 + 224), *(unsigned int *)(v21 + 112), 1);
        if ( !(*(_DWORD *)(*(_QWORD *)(a1 + 24) + 2346LL) ^ *(_DWORD *)bssid
             | *(unsigned __int16 *)(*(_QWORD *)(a1 + 24) + 2350LL) ^ *(unsigned __int16 *)(bssid + 4))
          && (*(_QWORD *)(v19 + 216) & 8) != 0 )
        {
          *(_QWORD *)(v20 + 120) = jiffies;
          if ( (*v23 & 0x4C) == 8 && (v23[2] & 1) == 0 )
            goto LABEL_38;
        }
      }
      else if ( (*v23 & 0xFC) != 0x1C && (v23[2] & 1) == 0 )
      {
        *(_QWORD *)(v20 + 120) = jiffies;
        if ( (*v23 & 0x4C) == 8 )
LABEL_38:
          *(_DWORD *)(v20 + 164) = sta_stats_encode_rate(v21 + 40);
      }
LABEL_39:
      v25 = *(_QWORD *)(v20 + 168);
      ++*(_QWORD *)(v20 + 136);
      *(_QWORD *)(v20 + 168) = v25 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 112LL);
      if ( (*(_BYTE *)(v21 + 65) & 1) == 0 )
      {
        *(_DWORD *)(v20 + 152) = *(char *)(v21 + 78);
        v26 = *(_QWORD *)(v20 + 312);
        if ( v26 )
          v27 = (unsigned __int64)(7 * v26 - ((__int64)*(char *)(v21 + 78) << 10)) >> 3;
        else
          v27 = -1024LL * *(char *)(v21 + 78);
        *(_QWORD *)(v20 + 312) = v27;
      }
      if ( !*(_BYTE *)(v21 + 79) )
        goto LABEL_66;
      *(_BYTE *)(v20 + 156) = *(_BYTE *)(v21 + 79);
      v28 = *(_BYTE *)(v21 + 79);
      if ( (v28 & 1) != 0 )
      {
        v29 = *(char *)(v21 + 80);
        *(_BYTE *)(v20 + 157) = v29;
        v30 = -v29;
        v31 = *(_QWORD *)(v20 + 320);
        if ( v31 )
          v32 = (unsigned __int64)(7 * v31 + (v30 << 10)) >> 3;
        else
          v32 = v30 << 10;
        *(_QWORD *)(v20 + 320) = v32;
        v28 = *(_BYTE *)(v21 + 79);
        if ( (v28 & 2) != 0 )
        {
LABEL_54:
          v33 = *(char *)(v21 + 81);
          *(_BYTE *)(v20 + 158) = v33;
          v34 = -v33;
          v35 = *(_QWORD *)(v20 + 328);
          if ( v35 )
            v36 = (unsigned __int64)(7 * v35 + (v34 << 10)) >> 3;
          else
            v36 = v34 << 10;
          *(_QWORD *)(v20 + 328) = v36;
          v28 = *(_BYTE *)(v21 + 79);
          if ( (v28 & 4) != 0 )
          {
LABEL_58:
            v37 = *(char *)(v21 + 82);
            *(_BYTE *)(v20 + 159) = v37;
            v38 = -v37;
            v39 = *(_QWORD *)(v20 + 336);
            if ( v39 )
              v40 = (unsigned __int64)(7 * v39 + (v38 << 10)) >> 3;
            else
              v40 = v38 << 10;
            *(_QWORD *)(v20 + 336) = v40;
            if ( (*(_BYTE *)(v21 + 79) & 8) == 0 )
              goto LABEL_66;
LABEL_62:
            v41 = *(char *)(v21 + 83);
            *(_BYTE *)(v20 + 160) = v41;
            v42 = -v41;
            v43 = *(_QWORD *)(v20 + 344);
            if ( v43 )
              v44 = (unsigned __int64)(7 * v43 + (v42 << 10)) >> 3;
            else
              v44 = v42 << 10;
            *(_QWORD *)(v20 + 344) = v44;
            goto LABEL_66;
          }
          goto LABEL_48;
        }
      }
      else if ( (*(_BYTE *)(v21 + 79) & 2) != 0 )
      {
        goto LABEL_54;
      }
      if ( (v28 & 4) != 0 )
        goto LABEL_58;
LABEL_48:
      if ( (v28 & 8) != 0 )
        goto LABEL_62;
LABEL_66:
      if ( (*v23 & 0xFC) != 0x1C )
      {
        if ( (*v23 & 0x400) == 0
          && (*(_QWORD *)(*(_QWORD *)(v19 + 72) + 96LL) & 0x100000) == 0
          && (v23[2] & 1) == 0
          && (*v23 & 4 | 8) == 8
          && (*(_BYTE *)(v21 + 75) & 0x20) == 0
          && (unsigned int)(*(_DWORD *)(*(_QWORD *)(a1 + 24) + 4720LL) - 3) <= 1 )
        {
          if ( (*(_QWORD *)(v19 + 216) & 4) != 0 )
          {
            if ( (*v23 & 0x1000) == 0 )
            {
              if ( (*(_QWORD *)(v19 + 216) & 0x200) != 0 )
              {
                _X8 = (unsigned __int64 *)(v19 + 216);
                __asm { PRFM            #0x11, [X8] }
                do
                  v262 = __ldxr(_X8);
                while ( __stxr(v262 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
              }
              else
              {
                _X8 = (unsigned __int64 *)(v19 + 216);
                __asm { PRFM            #0x11, [X8] }
                do
                  v256 = __ldxr(_X8);
                while ( __stxr(v256 | 0x2000000, _X8) );
                _X8 = (unsigned __int64 *)(v19 + 216);
                __asm { PRFM            #0x11, [X8] }
                do
                  v259 = __ldxr(_X8);
                while ( __stxr(v259 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
                ieee80211_sta_ps_deliver_wakeup(v19);
              }
            }
          }
          else if ( (*v23 & 0x1000) != 0 )
          {
            sta_ps_start(v19);
          }
        }
        v45 = *v23;
        if ( (v45 & 0x7C) == 0x48 )
        {
          if ( (~v45 & 0x300) == 0 )
          {
            v46 = *(_QWORD *)(a1 + 24);
            v47 = *(_DWORD *)(v46 + 4720);
            if ( v47 == 3 || v47 == 4 && !*(_QWORD *)(v46 + 2280) )
            {
              _X9 = (unsigned __int64 *)(v19 + 216);
              __asm { PRFM            #0x11, [X9] }
              do
                v245 = __ldxr(_X9);
              while ( __stlxr(v245 | 0x80000, _X9) );
              __dmb(0xBu);
              v5 = 131073;
              if ( (v245 & 0x80000) == 0 )
                cfg80211_rx_unexpected_4addr_frame(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 1608LL), v19 + 2688, 2080);
              goto LABEL_301;
            }
          }
          ++*(_QWORD *)(v20 + 112);
          goto LABEL_87;
        }
      }
LABEL_88:
      v48 = *(_QWORD *)(a1 + 8);
      v49 = *(unsigned __int16 **)(v48 + 224);
      if ( (~*v49 & 0xC) == 0 )
        goto LABEL_89;
      *(_QWORD *)(a1 + 56) = 0;
      v62 = *(_QWORD *)(a1 + 40);
      v63 = *v49;
      if ( !v62 )
      {
        if ( (*v49 & 0x4000) != 0 )
        {
          v76 = v49 + 2;
LABEL_161:
          if ( (~*(_DWORD *)(v48 + 64) & 0x12) == 0 )
            goto LABEL_89;
          v85 = *(_QWORD *)(a1 + 8);
          v86 = ieee80211_hdrlen(**(unsigned __int16 **)(v85 + 224));
          if ( *(_DWORD *)(v85 + 112) < (unsigned int)(v86 + 4) )
          {
LABEL_337:
            v5 = 65543;
            goto LABEL_301;
          }
          LOBYTE(v269) = 0;
          skb_copy_bits(v85, (unsigned int)(v86 + 3), &v269, 1);
          v87 = (unsigned __int64)(unsigned __int8)v269 >> 6;
          if ( (*v76 & 1) != 0 && (v88 = *(_QWORD *)(a1 + 48)) != 0 )
          {
            v79 = *(_QWORD *)(v88 + 8 * v87 + 40);
            *(_QWORD *)(a1 + 56) = v79;
            if ( v79 )
              goto LABEL_274;
          }
          else
          {
            v79 = *(_QWORD *)(a1 + 56);
            if ( v79 )
              goto LABEL_274;
          }
          if ( (*v76 & 1) == 0
            || (v79 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 8LL * (unsigned int)v87 + 48), (*(_QWORD *)(a1 + 56) = v79) == 0) )
          {
            v79 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 8LL * (unsigned int)v87 + 1896);
            *(_QWORD *)(a1 + 56) = v79;
            if ( !v79 )
            {
LABEL_147:
              v5 = 0x20000;
              goto LABEL_301;
            }
          }
          if ( (*(_DWORD *)(v79 + 544) | 4) != 0xFAC05 && (*v76 & 1) == 0 )
          {
            *(_QWORD *)(a1 + 56) = 0;
            v5 = 0x20000;
            goto LABEL_301;
          }
LABEL_274:
          if ( (*(_BYTE *)(v79 + 40) & 2) != 0 )
            goto LABEL_147;
          v117 = *(_DWORD *)(v79 + 544);
          v5 = 65544;
          if ( v117 > 1027079 )
          {
            if ( v117 > 1027082 )
            {
              if ( (unsigned int)(v117 - 1027083) < 2 )
              {
                v118 = ieee80211_crypto_aes_gmac_decrypt(a1);
                goto LABEL_295;
              }
              if ( v117 == 1027085 )
              {
                v118 = ieee80211_crypto_aes_cmac_256_decrypt(a1);
                goto LABEL_295;
              }
            }
            else
            {
              if ( (unsigned int)(v117 - 1027080) < 2 )
              {
                v118 = ieee80211_crypto_gcmp_decrypt(a1);
                goto LABEL_295;
              }
              v119 = a1;
              v120 = 16;
LABEL_294:
              v118 = ieee80211_crypto_ccmp_decrypt(v119, v120);
LABEL_295:
              v5 = v118;
            }
LABEL_296:
            *(_DWORD *)(v48 + 64) |= 2u;
            if ( (v63 & 0xFC) == 0x80 && (v5 & 0xFFFF0000) == 0x10000 )
            {
              if ( *(_QWORD *)(*(_QWORD *)(a1 + 24) + 1608LL) )
                goto LABEL_153;
              goto LABEL_301;
            }
            if ( v5 != 1 )
              goto LABEL_301;
            goto LABEL_89;
          }
          if ( v117 <= 1027075 )
          {
            if ( v117 != 1027073 )
            {
              if ( v117 == 1027074 )
              {
                v118 = ieee80211_crypto_tkip_decrypt(a1);
                goto LABEL_295;
              }
              goto LABEL_296;
            }
          }
          else
          {
            if ( v117 == 1027076 )
            {
              v119 = a1;
              v120 = 8;
              goto LABEL_294;
            }
            if ( v117 != 1027077 )
            {
              if ( v117 == 1027078 )
              {
                v118 = ieee80211_crypto_aes_cmac_decrypt(a1);
                goto LABEL_295;
              }
              goto LABEL_296;
            }
          }
          v118 = ((__int64 (__fastcall *)(__int64))ieee80211_crypto_wep_decrypt)(a1);
          goto LABEL_295;
        }
        v65 = 0;
LABEL_116:
        v70 = *(unsigned int *)(v48 + 112);
        if ( (unsigned int)v70 < 0x2A )
          goto LABEL_135;
        v71 = *(_QWORD *)(v48 + 224);
        if ( (*(_BYTE *)(v71 + 4) & 1) == 0 )
          goto LABEL_135;
        v72 = *(_WORD *)v71 & 0xFC;
        if ( v72 != 160 && v72 != 192 )
        {
          if ( v72 != 208
            || (*(_WORD *)v71 & 0x4000) == 0
            && ((v73 = *(unsigned __int8 *)(v71 + 24), v73 <= 0x16) && ((1 << v73) & 0x708890) != 0 || v73 == 127) )
          {
            if ( (*(_WORD *)v71 & 0xFC) != 0x80 )
              goto LABEL_135;
          }
        }
        v74 = v71 + v70;
        if ( *(_BYTE *)(v71 + v70 - 18) == 76 && *(_BYTE *)(v74 - 17) == 16 )
        {
          v75 = -16;
          goto LABEL_134;
        }
        if ( (unsigned int)v70 >= 0x32 && *(_BYTE *)(v74 - 26) == 76 && *(_BYTE *)(v74 - 25) == 24 )
        {
          v75 = -24;
LABEL_134:
          v69 = *(unsigned __int16 *)(v74 + v75);
          v68 = 0;
        }
        else
        {
LABEL_135:
          v68 = 0;
          v69 = -1;
        }
        v67 = 1;
        goto LABEL_137;
      }
      v64 = *(unsigned __int8 *)(v62 + 120);
      if ( v64 >= 5 )
        goto LABEL_667;
      v65 = *(_QWORD *)(v62 + 8 * v64 + 88);
      if ( (*v49 & 0x4000) == 0 )
        goto LABEL_116;
      if ( (*(_BYTE *)(v48 + 64) & 0x10) != 0 )
      {
        v67 = 0;
        v68 = 0;
        v69 = -1;
      }
      else
      {
        v66 = ieee80211_hdrlen(**(unsigned __int16 **)(v48 + 224));
        if ( *(_DWORD *)(v48 + 112) < (unsigned int)(v66 + 4) )
          goto LABEL_337;
        LOBYTE(v269) = 0;
        skb_copy_bits(v48, (unsigned int)(v66 + 3), &v269, 1);
        v67 = 0;
        v62 = *(_QWORD *)(a1 + 40);
        v68 = *(_QWORD *)(v62 + (((unsigned __int64)(unsigned __int8)v269 >> 3) & 0x18) + 88);
        v69 = -1;
      }
LABEL_137:
      v78 = *((_DWORD *)v49 + 1);
      v76 = v49 + 2;
      v77 = v78;
      if ( (v78 & 1) == 0 && v65 )
      {
        if ( v68 )
          v79 = v68;
        else
          v79 = v65;
        *(_QWORD *)(a1 + 56) = v79;
        if ( (~*(_DWORD *)(v48 + 64) & 0x12) != 0 )
          v80 = v67;
        else
          v80 = 1;
        if ( (v80 & 1) != 0 )
          goto LABEL_89;
        goto LABEL_274;
      }
      if ( (v69 & 0x80000000) == 0 )
      {
        v81 = *(_DWORD *)(v48 + 64) & 0x12;
        if ( (v63 & 0xFC) != 0x80 )
        {
          if ( v81 == 18 )
            goto LABEL_89;
          if ( v69 - 6 < 0xFFFFFFFE )
          {
            v5 = 131075;
            goto LABEL_301;
          }
          v101 = *(_QWORD *)(a1 + 48);
          if ( v101 )
          {
            if ( *(_DWORD *)(v48 + 112) >= 0x19u )
            {
              v102 = *(_QWORD *)(v48 + 224);
              if ( (*(_WORD *)v102 & 0xFC) == 0xD0
                && (*(_BYTE *)(v102 + 4) & 1) != 0
                && (unsigned int)*(unsigned __int8 *)(v102 + 24) - 13 <= 1
                && (*(_QWORD *)(v62 + 216) & 0x80) != 0 )
              {
                goto LABEL_147;
              }
            }
            v79 = *(_QWORD *)(v101 + 8LL * v69 + 40);
            *(_QWORD *)(a1 + 56) = v79;
            if ( v79 )
              goto LABEL_274;
          }
          else
          {
            v79 = *(_QWORD *)(a1 + 56);
            if ( v79 )
              goto LABEL_274;
          }
          v79 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 8LL * v69 + 48);
          *(_QWORD *)(a1 + 56) = v79;
          if ( !v79 )
            goto LABEL_147;
          goto LABEL_274;
        }
        if ( v81 == 18 )
          goto LABEL_89;
        if ( v69 - 8 <= 0xFFFFFFFD )
        {
          v5 = 131074;
          if ( !*(_QWORD *)(*(_QWORD *)(a1 + 24) + 1608LL) )
            goto LABEL_301;
LABEL_153:
          ((void (*)(void))cfg80211_rx_unprot_mlme_mgmt)();
          goto LABEL_301;
        }
        v96 = *(_QWORD *)(a1 + 48);
        v97 = v69;
        if ( v69 == 6 )
          v98 = 7;
        else
          v98 = v69 - 1;
        if ( v96 )
        {
          v99 = v96 + 40;
          v79 = *(_QWORD *)(v96 + 40 + 8 * v97);
          if ( !v79 )
          {
            v100 = *(_QWORD *)(a1 + 32);
            v79 = *(_QWORD *)(v100 + 8 * v97 + 48);
            if ( !v79 )
            {
              v79 = *(_QWORD *)(v99 + 8 * v98);
              if ( !v79 )
              {
LABEL_218:
                v79 = *(_QWORD *)(v100 + 8 * v98 + 48);
                *(_QWORD *)(a1 + 56) = v79;
                if ( !v79 )
                  goto LABEL_89;
                goto LABEL_274;
              }
            }
          }
        }
        else
        {
          v100 = *(_QWORD *)(a1 + 32);
          v79 = *(_QWORD *)(v100 + 8 * v97 + 48);
          if ( !v79 )
            goto LABEL_218;
        }
        *(_QWORD *)(a1 + 56) = v79;
        goto LABEL_274;
      }
      if ( !v67 )
        goto LABEL_161;
      if ( (v63 & 0xFC) == 0x80 )
      {
        v82 = *(_QWORD *)(a1 + 48);
        if ( v82 )
        {
          v83 = *(_QWORD *)(v82 + 88);
          if ( !v83 )
          {
            v84 = *(_QWORD *)(a1 + 32);
            v83 = *(_QWORD *)(v84 + 96);
            if ( !v83 )
            {
              v83 = *(_QWORD *)(v82 + 96);
              if ( !v83 )
                goto LABEL_268;
            }
          }
        }
        else
        {
          v84 = *(_QWORD *)(a1 + 32);
          v83 = *(_QWORD *)(v84 + 96);
          if ( !v83 )
          {
LABEL_268:
            v83 = *(_QWORD *)(v84 + 104);
            if ( !v83 )
              goto LABEL_89;
          }
        }
LABEL_269:
        *(_QWORD *)(a1 + 56) = v83;
        goto LABEL_89;
      }
      if ( (v63 & 0xC) != 0 || (v77 & 1) == 0 )
      {
        v115 = *(_QWORD **)(a1 + 48);
        if ( v115 )
        {
          v83 = v115[5];
          if ( v83 )
            goto LABEL_269;
          v83 = v115[6];
          if ( v83 )
            goto LABEL_269;
          v83 = v115[7];
          if ( v83 )
            goto LABEL_269;
          v83 = v115[8];
          if ( v83 )
            goto LABEL_269;
        }
        v116 = *(_QWORD **)(a1 + 32);
        v83 = v116[6];
        if ( v83 )
          goto LABEL_269;
        v83 = v116[7];
        if ( v83 )
          goto LABEL_269;
        v83 = v116[8];
        if ( v83 )
          goto LABEL_269;
        v83 = v116[9];
        if ( v83 )
          goto LABEL_269;
      }
      else
      {
        v83 = *(_QWORD *)(*(_QWORD *)(a1 + 32) + 120LL);
        if ( v83 )
          goto LABEL_269;
      }
LABEL_89:
      v50 = *(_QWORD *)(a1 + 8);
      v51 = *(unsigned __int16 **)(v50 + 224);
      v52 = *v51;
      if ( (v52 & 4) == 0 )
      {
        v53 = *(_QWORD *)(a1 + 40);
        v54 = v51[11];
        v55 = v51[11] & 0xF;
        if ( v53 )
          v56 = v53 + 1368;
        else
          v56 = *(_QWORD *)(a1 + 24) + 1656LL;
        if ( (v52 & 0x400) != 0 || (v54 & 0xF) != 0 )
        {
          if ( (v51[2] & 1) != 0 )
          {
            v5 = 0x20000;
            goto LABEL_301;
          }
          if ( *(_DWORD *)(v50 + 116) && !_pskb_pull_tail(*(_QWORD *)(a1 + 8)) )
          {
            v5 = 65545;
            goto LABEL_301;
          }
          v121 = v54 >> 4;
          if ( (v54 & 0xF) == 0 )
          {
            v140 = ieee80211_reassemble_add(v56, (unsigned int)v121, *(unsigned int *)(a1 + 68), a1 + 8);
            v141 = *(_QWORD *)(a1 + 56);
            if ( !v141 )
              goto LABEL_360;
            v142 = *(_DWORD *)(v141 + 544) - 1027076;
            if ( v142 <= 6 && ((1 << v142) & 0x71) != 0 )
            {
              if ( (v52 & 0x4000) != 0 )
              {
                v164 = *(_DWORD *)(a1 + 72);
                *(_BYTE *)(v140 + 39) |= 3u;
                *(_DWORD *)(v140 + 48) = *(_DWORD *)(*(_QWORD *)(a1 + 56) + 528LL);
                if ( v164 >= 0x12 )
                  goto LABEL_667;
                v5 = 0;
                v165 = *(_QWORD *)(a1 + 56) + 6LL * v164;
                v166 = *(_WORD *)(v165 + 52);
                LODWORD(v165) = *(_DWORD *)(v165 + 48);
                *(_WORD *)(v140 + 44) = v166;
                *(_DWORD *)(v140 + 40) = v165;
                goto LABEL_301;
              }
              goto LABEL_359;
            }
            if ( (v52 & 0x4000) == 0 )
            {
LABEL_359:
              if ( (*(_BYTE *)(v50 + 64) & 2) == 0 )
              {
LABEL_360:
                v5 = 0;
                goto LABEL_301;
              }
            }
            v5 = 0;
            *(_BYTE *)(v140 + 39) |= 2u;
            *(_DWORD *)(v140 + 48) = *(_DWORD *)(*(_QWORD *)(a1 + 56) + 528LL);
            goto LABEL_301;
          }
          v122 = ieee80211_reassemble_find(
                   v56,
                   v54 & 0xF,
                   v121,
                   *(unsigned int *)(a1 + 68),
                   *(_QWORD *)(*(_QWORD *)(a1 + 8) + 224LL));
          if ( !v122 )
            goto LABEL_147;
          v123 = v122;
          if ( (*(_BYTE *)(v122 + 39) & 1) != 0 )
          {
            v145 = *(_QWORD *)(a1 + 56);
            v5 = 65546;
            if ( !v145 )
              goto LABEL_301;
            v146 = *(_DWORD *)(v145 + 544) - 1027076;
            if ( v146 > 6 || ((1 << v146) & 0x71) == 0 || (v52 & 0x4000) == 0 )
              goto LABEL_301;
            if ( *(_DWORD *)(v122 + 48) != *(_DWORD *)(v145 + 528) )
            {
              v5 = 65547;
              goto LABEL_301;
            }
            v147 = *(_DWORD *)(v122 + 40);
            v148 = *(_WORD *)(v122 + 44);
            BYTE4(v269) = v148;
            v149 = HIBYTE(v148);
            LODWORD(v269) = v147;
            BYTE5(v269) = v149 + 1;
            if ( ((v149 + 1) & 0x100) != 0 )
            {
              v150 = BYTE4(v269) + 1;
              ++BYTE4(v269);
              if ( (v150 & 0x100) != 0 )
              {
                v151 = BYTE3(v269) + 1;
                ++BYTE3(v269);
                if ( (v151 & 0x100) != 0 )
                {
                  v152 = BYTE2(v269) + 1;
                  ++BYTE2(v269);
                  if ( (v152 & 0x100) != 0 )
                  {
                    v153 = BYTE1(v269) + 1;
                    ++BYTE1(v269);
                    if ( (v153 & 0x100) != 0 )
                      LOBYTE(v269) = v269 + 1;
                  }
                }
              }
            }
            if ( (_DWORD)v269 != *(_DWORD *)(a1 + 80) || WORD2(v269) != *(unsigned __int16 *)(a1 + 84) )
            {
              v5 = 65538;
              goto LABEL_301;
            }
            v191 = WORD2(v269);
            *(_DWORD *)(v122 + 40) = v269;
            *(_WORD *)(v122 + 44) = v191;
          }
          else if ( (*(_BYTE *)(v122 + 39) & 2) != 0 )
          {
            v157 = *(_QWORD *)(a1 + 56);
            if ( !v157 || (v52 & 0x4000) == 0 && (*(_BYTE *)(v50 + 64) & 2) == 0 )
            {
              v5 = 65562;
              goto LABEL_301;
            }
            if ( *(_DWORD *)(v157 + 528) != *(_DWORD *)(v122 + 48) )
            {
              v5 = 65562;
              goto LABEL_301;
            }
          }
          v124 = *(_QWORD *)(a1 + 8);
          v125 = ieee80211_hdrlen(v52);
          skb_pull(v124, v125);
          v126 = *(__int64 **)(a1 + 8);
          v127 = *(__int64 ***)(v123 + 8);
          *v126 = v123;
          v126[1] = (__int64)v127;
          *(_QWORD *)(v123 + 8) = v126;
          *v127 = v126;
          v128 = *(_DWORD *)(v123 + 16);
          *(_DWORD *)(v123 + 16) = v128 + 1;
          *(_WORD *)(v123 + 36) = v55;
          *(_WORD *)(v123 + 34) += *(_WORD *)(*(_QWORD *)(a1 + 8) + 112LL);
          if ( (v52 & 0x400) != 0 )
          {
            v5 = 0;
            *(_QWORD *)(a1 + 8) = 0;
            goto LABEL_301;
          }
          if ( *(_QWORD *)v123 == v123 )
            v168 = nullptr;
          else
            v168 = *(__int64 **)v123;
          if ( v168 )
          {
            *(_DWORD *)(v123 + 16) = v128;
            v169 = *v168;
            v170 = (__int64 *)v168[1];
            *v168 = 0;
            v168[1] = 0;
            *(_QWORD *)(v169 + 8) = v170;
            *v170 = v169;
          }
          *(_QWORD *)(a1 + 8) = v168;
          if ( *((_DWORD *)v168 + 29) )
            v171 = 0;
          else
            v171 = *((_DWORD *)v168 + 53) - *((_DWORD *)v168 + 52);
          if ( v171 < *(unsigned __int16 *)(v123 + 34) && (unsigned int)pskb_expand_head() )
          {
            _skb_queue_purge((__int64 **)v123);
            v5 = 65545;
            goto LABEL_301;
          }
          for ( i = *(__int64 **)v123; *(_QWORD *)v123 != v123 && i; i = *(__int64 **)v123 )
          {
            --*(_DWORD *)(v123 + 16);
            v181 = *i;
            v182 = (__int64 *)i[1];
            *i = 0;
            i[1] = 0;
            *(_QWORD *)(v181 + 8) = v182;
            *v182 = v181;
            skb_put_data_0(*(_QWORD *)(a1 + 8), i[28], *((unsigned int *)i + 28));
            consume_skb(i);
          }
        }
        if ( *(_QWORD *)(a1 + 40) )
          ++*(_QWORD *)(*(_QWORD *)(a1 + 48) + 112LL);
      }
      v5 = ((__int64 (__fastcall *)(__int64))ieee80211_rx_h_michael_mic_verify)(a1);
      if ( v5 != 1 )
        goto LABEL_301;
      v57 = *(_QWORD *)(a1 + 8);
      v58 = *(unsigned __int16 **)(v57 + 224);
      v59 = *v58;
      if ( (*(_BYTE *)(v57 + 75) & 8) != 0 && (v59 & 0xC) == 8 )
      {
        if ( (v59 & 0x48) != 8 )
          goto LABEL_147;
        if ( (~v59 & 0x300) == 0 )
        {
          v136 = *(_QWORD *)(a1 + 24);
          v5 = 65548;
          v137 = *(_DWORD *)(v136 + 4720);
          if ( v137 == 2 )
          {
            if ( !*(_BYTE *)(v136 + 2524) )
              goto LABEL_301;
          }
          else if ( v137 != 7 )
          {
            if ( v137 != 4 )
              goto LABEL_301;
            if ( !*(_QWORD *)(v136 + 2280) )
            {
              v5 = 65548;
              goto LABEL_301;
            }
          }
        }
        v5 = 65549;
        if ( (v58[2] & 1) != 0 || !*(_QWORD *)(a1 + 40) )
          goto LABEL_301;
        v60 = *(_QWORD *)(a1 + 56);
        if ( v60 )
        {
          v61 = *(_DWORD *)(v60 + 544) - 1027073;
          if ( v61 <= 4 && ((1 << v61) & 0x13) != 0 )
          {
            v5 = 65550;
            goto LABEL_301;
          }
        }
        v5 = _ieee80211_rx_h_amsdu(a1, 0);
        if ( v5 != 1 )
          goto LABEL_301;
        v57 = *(_QWORD *)(a1 + 8);
        v58 = *(unsigned __int16 **)(v57 + 224);
        LOWORD(v59) = *v58;
      }
      v89 = *(_QWORD *)(a1 + 24);
      if ( (v59 & 0xC) != 8 )
      {
        if ( (v59 & 0xC) == 4 )
        {
          if ( (v59 & 0xF4) != 0x84 )
            goto LABEL_612;
          v222 = *(_QWORD *)(a1 + 40);
          v268 = 0;
          v270 = 0;
          v271 = 0;
          v269 = 2;
          if ( !v222 || (unsigned int)skb_copy_bits(v57, 16, &v268, 4) )
            goto LABEL_612;
          v234 = (unsigned __int64)(unsigned __int16)v268 >> 12;
          v235 = *(_QWORD *)(a1 + 40);
          v236 = 1LL << v234;
          if ( (*(_QWORD *)(v235 + 864) & (1LL << v234)) == 0 )
          {
            _X10 = (unsigned __int64 *)(v235 + 872);
            __asm { PRFM            #0x11, [X10] }
            do
              v265 = __ldxr(_X10);
            while ( __stlxr(v265 | v236, _X10) );
            __dmb(0xBu);
            _ZF = (v265 & v236) == 0;
            v235 = *(_QWORD *)(a1 + 40);
            if ( _ZF )
            {
              ieee80211_send_delba(*(_QWORD *)(a1 + 24), v235 + 2688, v234, 0, 38);
              v235 = *(_QWORD *)(a1 + 40);
            }
          }
          v237 = *(_QWORD *)(v235 + 8 * v234 + 696);
          if ( !v237 )
          {
LABEL_612:
            v5 = 0x20000;
            goto LABEL_301;
          }
          LOWORD(v271) = v234;
          v270 = v235 + 2688;
          v238 = HIWORD(v268) >> 4;
          v239 = *(unsigned __int16 *)(v237 + 152);
          WORD1(v271) = HIWORD(v268) >> 4;
          if ( v239 )
          {
            v240 = jiffies;
            v241 = _usecs_to_jiffies((unsigned int)(v239 << 10));
            mod_timer(v237 + 56, v241 + v240);
          }
          raw_spin_lock(v237 + 16);
          ieee80211_release_reorder_frames(v237, v238, a2);
          raw_spin_unlock(v237 + 16);
          drv_event_callback_0(*(_QWORD *)(a1 + 16));
          sk_skb_reason_drop(0);
          goto LABEL_630;
        }
        v129 = v59 & 0xFC;
        if ( v129 == 28 )
        {
          v267 = v57;
          goto LABEL_319;
        }
        v5 = 0x20000;
        if ( (v59 & 0xC) != 0 )
          goto LABEL_301;
        v138 = *(_DWORD *)(v57 + 112);
        if ( v138 < 0x18 )
          goto LABEL_301;
        v139 = v57;
        if ( v129 == 208 )
        {
          if ( v138 < 0x19 )
          {
            v5 = 65552;
            goto LABEL_301;
          }
        }
        else if ( v129 == 128 && *(_DWORD *)(v89 + 4720) == 3 && (*(_BYTE *)(a1 + 64) & 2) == 0 )
        {
          ieee80211_rx_check_bss_color_collision(a1);
          v143 = *(_QWORD *)(a1 + 16);
          if ( (*(_QWORD *)(v143 + 96) & 0x10) == 0 || (*(_BYTE *)(v139 + 65) & 1) != 0 )
            v144 = 0;
          else
            v144 = (unsigned int)*(char *)(v139 + 78);
          cfg80211_report_obss_beacon_khz(
            *(_QWORD *)(v143 + 72),
            *(_QWORD *)(*(_QWORD *)(a1 + 8) + 224LL),
            *(unsigned int *)(*(_QWORD *)(a1 + 8) + 112LL),
            ((*(unsigned __int16 *)(v139 + 68) << 18 >> 31) & 0x1F4) + 1000 * (*(_WORD *)(v139 + 68) & 0x1FFFu),
            v144);
          v139 = *(_QWORD *)(a1 + 8);
          *(_DWORD *)(a1 + 64) |= 2u;
          v58 = *(unsigned __int16 **)(v139 + 224);
          LOWORD(v59) = *v58;
        }
        if ( (*(_BYTE *)(v139 + 64) & 2) != 0 )
        {
          v267 = v139;
          goto LABEL_319;
        }
        v172 = v59 & 0xFC;
        if ( v172 == 208 && *((_BYTE *)v58 + 24) == 9 )
        {
          v5 = 65554;
          goto LABEL_301;
        }
        v173 = *(_QWORD *)(a1 + 40);
        v267 = v139;
        if ( !v173 || (*(_QWORD *)(v173 + 216) & 0x80) == 0 )
          goto LABEL_507;
        v174 = *((_DWORD *)v58 + 1);
        if ( v59 & 0x4000 | v174 & 1 )
        {
          if ( (v174 & 1) != 0 )
          {
            v183 = *(unsigned int *)(v139 + 112);
            if ( (unsigned int)v183 >= 0x19 )
            {
              if ( (v212 = v59 & 0xFC, v212 == 160)
                || v212 == 192
                || v212 == 208
                && ((v59 & 0x4000) != 0
                 || ((v213 = *((unsigned __int8 *)v58 + 24), v213 > 0x16) || ((1 << v213) & 0x708890) == 0)
                 && v213 != 127) )
              {
                if ( (unsigned int)v183 < 0x2A )
                  goto LABEL_588;
                if ( v212 != 160 && v212 != 192 )
                {
                  if ( v212 != 208
                    || (v59 & 0x4000) == 0
                    && ((v214 = *((unsigned __int8 *)v58 + 24), v214 <= 0x16) && ((1 << v214) & 0x708890) != 0
                     || v214 == 127) )
                  {
                    if ( v172 == 192 || v172 == 160 )
                      goto LABEL_590;
                    if ( v172 != 128 )
                      goto LABEL_591;
                  }
                }
                v215 = (char *)v58 + v183;
                if ( (*((_BYTE *)v58 + v183 - 18) != 76 || *(v215 - 17) != 16)
                  && ((unsigned int)v183 < 0x32 || *(v215 - 26) != 76 || *(v215 - 25) != 24) )
                {
LABEL_588:
                  if ( v172 == 192 || v172 == 160 )
LABEL_590:
                    cfg80211_rx_unprot_mlme_mgmt(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 1608LL));
LABEL_591:
                  v5 = 65556;
                  goto LABEL_301;
                }
              }
            }
          }
        }
        else if ( *(_DWORD *)(v139 + 112) >= 0x19u )
        {
          if ( (v175 = v59 & 0xFC, v175 == 160)
            || v175 == 192
            || v175 == 208
            && ((v176 = *((unsigned __int8 *)v58 + 24), v176 > 0x16) || ((1 << v176) & 0x708890) == 0)
            && v176 != 127 )
          {
            if ( v172 != 192 && v172 != 160 )
            {
              v5 = 65555;
              goto LABEL_301;
            }
            if ( *(_QWORD *)(a1 + 56) )
            {
              cfg80211_rx_unprot_mlme_mgmt(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 1608LL));
              v5 = 65555;
              goto LABEL_301;
            }
LABEL_319:
            v130 = v267;
            v131 = *(_QWORD *)(v267 + 224);
            v132 = *(_DWORD *)(v267 + 112);
            if ( (*(_WORD *)v131 & 0xFC) != 0xD0 )
              goto LABEL_527;
            v133 = *(_QWORD *)(a1 + 40);
            v134 = *(_QWORD *)(a1 + 24);
            v135 = *(unsigned __int8 *)(v131 + 24);
            if ( v133 )
            {
              if ( *(unsigned __int8 *)(v131 + 24) > 8u )
              {
                if ( *(unsigned __int8 *)(v131 + 24) > 0x14u )
                {
                  if ( v135 != 21 )
                  {
                    if ( v135 == 22 )
                    {
                      if ( v132 < 0x1A || (*(_BYTE *)(v131 + 25) & 0xFE) != 6 )
                        goto LABEL_526;
                      v179 = ieee80211_process_rx_twt_action(a1);
                      v130 = v267;
                      if ( (v179 & 1) != 0 )
                        goto LABEL_600;
                      goto LABEL_527;
                    }
                    if ( v135 != 37 || v132 < 0x1A )
                      goto LABEL_526;
                    if ( *(_BYTE *)(v131 + 25) != 1 )
                    {
                      if ( !*(_BYTE *)(v131 + 25) && *(_DWORD *)(v134 + 4720) == 2 )
                      {
                        v130 = v267;
                        if ( v132 != 26 )
                          goto LABEL_600;
                        goto LABEL_429;
                      }
LABEL_526:
                      v130 = v267;
LABEL_527:
                      v192 = *(unsigned __int16 *)(v130 + 68);
                      v193 = *(_DWORD *)(a1 + 76);
                      v271 = v131;
                      v272 = v132;
                      BYTE1(v270) = v193;
                      *(_DWORD *)((char *)&v270 + 2) = 0;
                      HIWORD(v270) = 0;
                      v269 = ((v192 << 18 >> 31) & 0x1F4) + 1000 * (v192 & 0x1FFFu);
                      LOBYTE(v192) = *(_BYTE *)(v130 + 75);
                      LOBYTE(v270) = v193 >= 0;
                      v273 = 0;
                      v274 = 0;
                      v275 = 0;
                      if ( (v192 & 0x10) == 0 )
                      {
                        if ( (*(_QWORD *)(*(_QWORD *)(a1 + 16) + 96LL) & 0x10) != 0 && (*(_BYTE *)(v130 + 65) & 1) == 0 )
                          HIDWORD(v269) = *(char *)(v130 + 78);
                        if ( v132 >= 0x19 && (*(_WORD *)v131 & 0xFC) == 0xD0 )
                        {
                          v194 = *(unsigned __int8 *)(v131 + 24);
                          if ( v194 != 4 )
                          {
                            if ( v194 != 11 || v132 < 0x26 || *(_BYTE *)(v131 + 25) != 1 )
                              goto LABEL_541;
LABEL_540:
                            v195 = *(_QWORD *)(v130 + 216);
                            v196 = *(unsigned int *)(v130 + 212);
                            v197 = *(_QWORD *)(v130 + 48);
                            v274 = *(_QWORD *)(v195 + v196 + 16);
                            v275 = v197;
                            goto LABEL_541;
                          }
                          if ( v132 >= 0x2C && *(_BYTE *)(v131 + 25) == 33 )
                            goto LABEL_540;
                        }
LABEL_541:
                        if ( (cfg80211_rx_mgmt_ext(*(_QWORD *)(a1 + 24) + 16LL, &v269) & 1) != 0 )
                        {
                          if ( *(_QWORD *)(a1 + 40) )
                            ++*(_QWORD *)(*(_QWORD *)(a1 + 48) + 112LL);
                          goto LABEL_87;
                        }
                        v130 = *(_QWORD *)(a1 + 8);
                        v131 = *(_QWORD *)(v130 + 224);
                      }
                      if ( (*(_WORD *)v131 & 0xFC) != 0xD0
                        || *(_BYTE *)(v131 + 24) != 8
                        || *(_DWORD *)(v130 + 112) < 0x1Cu
                        || *(_BYTE *)(v131 + 25)
                        || (v198 = *(_QWORD *)(a1 + 24), *(_DWORD *)(v198 + 4720) != 2) )
                      {
                        v5 = ieee80211_rx_h_action_return(a1);
                        if ( v5 == 1 )
                        {
                          v5 = ieee80211_rx_h_ext(a1);
                          if ( v5 == 1 )
                            v5 = ieee80211_rx_h_mgmt(a1);
                        }
                        goto LABEL_301;
                      }
                      if ( !(*(_DWORD *)(v198 + 5842) ^ *(_DWORD *)(v131 + 4)
                           | *(unsigned __int16 *)(v198 + 5846) ^ *(unsigned __int16 *)(v131 + 8)) )
                      {
                        v199 = *(unsigned __int16 *)(v198 + 4156);
                        v200 = *(_DWORD *)(v198 + 4152);
                        if ( !(v200 ^ *(_DWORD *)(v131 + 10) | (unsigned __int16)(v199 ^ *(_WORD *)(v131 + 14)))
                          && !(*(_DWORD *)(v131 + 16) ^ v200 | *(unsigned __int16 *)(v131 + 20) ^ v199) )
                        {
                          v201 = *(_QWORD *)(v198 + 1616);
                          v202 = _netdev_alloc_skb(0, (unsigned int)(*(_DWORD *)(v201 + 104) + 50), 2080);
                          if ( v202 )
                          {
                            v203 = *(int *)(v201 + 104);
                            v204 = v202;
                            v205 = *(_QWORD *)(v202 + 224) + v203;
                            LODWORD(v203) = *(_DWORD *)(v202 + 208) + v203;
                            *(_QWORD *)(v202 + 224) = v205;
                            *(_DWORD *)(v202 + 208) = v203;
                            v206 = skb_put(v202, 24);
                            *(_QWORD *)(v206 + 8) = 0;
                            *(_QWORD *)(v206 + 16) = 0;
                            v207 = v206;
                            *(_QWORD *)v206 = 0;
                            v208 = *(_WORD *)(v131 + 14);
                            *(_DWORD *)(v206 + 4) = *(_DWORD *)(v131 + 10);
                            *(_WORD *)(v206 + 8) = v208;
                            v209 = *(_DWORD *)(v198 + 5842);
                            *(_WORD *)(v206 + 14) = *(_WORD *)(v198 + 5846);
                            *(_DWORD *)(v206 + 10) = v209;
                            v210 = *(_DWORD *)(v198 + 4152);
                            *(_WORD *)(v206 + 20) = *(_WORD *)(v198 + 4156);
                            *(_DWORD *)(v206 + 16) = v210;
                            *(_WORD *)v206 = 208;
                            skb_put(v204, 4);
                            *(_WORD *)(v207 + 24) = 264;
                            *(_WORD *)(v207 + 26) = *(_WORD *)(v131 + 26);
                            ieee80211_tx_skb_tid(v198, v204, 7, 0xFFFFFFFFLL);
                          }
                        }
                      }
LABEL_627:
                      if ( *(_QWORD *)(a1 + 40) )
                        ++*(_QWORD *)(*(_QWORD *)(a1 + 48) + 112LL);
                      consume_skb(*(_QWORD *)(a1 + 8));
LABEL_630:
                      v5 = 0;
                      goto LABEL_301;
                    }
                    if ( *(_DWORD *)(v134 + 4720) != 2 )
                      goto LABEL_526;
                    v130 = v267;
                    if ( v132 > 0x1B )
                      goto LABEL_600;
LABEL_429:
                    *(_BYTE *)(v130 + 75) |= 0x10u;
                    v130 = *(_QWORD *)(a1 + 8);
                    v131 = *(_QWORD *)(v130 + 224);
                    v132 = *(_DWORD *)(v130 + 112);
                    goto LABEL_527;
                  }
                  v177 = *(_DWORD *)(v134 + 4720);
                  if ( (unsigned int)(v177 - 1) >= 4 && v177 != 7 )
                    goto LABEL_526;
                  v130 = v267;
                  if ( v132 < 0x1A )
                    goto LABEL_429;
                  v178 = *(unsigned __int8 *)(v131 + 25);
                  if ( v178 == 1 )
                  {
                    v130 = v267;
                    if ( v132 >= 0x32 )
                      goto LABEL_600;
                    goto LABEL_429;
                  }
                  if ( v178 == 2 )
                  {
                    v130 = v267;
                    if ( v132 != 26 )
                      goto LABEL_600;
                    goto LABEL_429;
                  }
LABEL_519:
                  v130 = v267;
                  goto LABEL_527;
                }
                if ( v135 != 9 )
                {
                  if ( v135 != 15 )
                    goto LABEL_527;
                  goto LABEL_425;
                }
                goto LABEL_428;
              }
              if ( *(unsigned __int8 *)(v131 + 24) > 3u )
              {
                if ( v135 != 4 )
                {
                  if ( v135 != 7 )
                    goto LABEL_526;
                  v158 = *(_QWORD *)(a1 + 48);
                  v159 = *(_QWORD *)(v158 + 920);
                  v130 = v267;
                  if ( *(_BYTE *)(v159 + 46) != 1 )
                    goto LABEL_429;
                  v160 = *(_DWORD *)(v134 + 4720);
                  v161 = *(_QWORD *)(a1 + 16);
                  if ( (unsigned int)(v160 - 1) < 4 || v160 == 7 )
                  {
                    v130 = v267;
                    if ( v132 < 0x1B )
                      goto LABEL_429;
                    if ( *(_BYTE *)(v131 + 25) )
                    {
                      v130 = v267;
                      if ( *(_BYTE *)(v131 + 25) != 1 )
                        goto LABEL_429;
                      v270 = 0;
                      if ( (unsigned int)(v160 - 3) > 1 )
                        goto LABEL_627;
                      v162 = *(unsigned __int8 *)(v131 + 26);
                      if ( *(_BYTE *)(v131 + 26) )
                      {
                        if ( v162 == 3 )
                        {
                          v163 = 3;
                        }
                        else
                        {
                          if ( v162 != 1 )
                          {
                            v130 = v267;
                            goto LABEL_429;
                          }
                          v163 = 2;
                        }
                      }
                      else
                      {
                        v163 = 1;
                      }
                      if ( *(_DWORD *)(v159 + 16) == v163 )
                        goto LABEL_627;
                      *(_DWORD *)(v159 + 16) = v163;
                      v232 = ieee80211_smps_mode_to_smps_mode(v163);
                      LODWORD(v269) = 2;
                      HIDWORD(v269) = v232;
                      v233 = *(unsigned __int8 *)(v267 + 76);
                      if ( v233 >= 6 )
                        goto LABEL_667;
                      v228 = *(_QWORD *)(a1 + 40);
                      v229 = v161;
                      v231 = 2;
                      v230 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 72LL) + 8 * v233 + 328);
                    }
                    else
                    {
                      v219 = *(_BYTE *)(v159 + 44);
                      v220 = *(unsigned __int8 *)(v131 + 26);
                      v269 = 0;
                      v270 = 0;
                      if ( (v219 & 2) == 0 )
                        goto LABEL_627;
                      if ( v220 )
                      {
                        v221 = ((__int64 (__fastcall *)(__int64, _QWORD))ieee80211_sta_cap_rx_bw)(v158, 0);
                        v158 = *(_QWORD *)(a1 + 48);
                      }
                      else
                      {
                        v221 = 0;
                      }
                      *(_DWORD *)(v158 + 912) = v221;
                      v223 = ieee80211_sta_cur_vht_bw(*(_QWORD *)(a1 + 48), 0);
                      v224 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 920LL);
                      if ( *(_DWORD *)(v224 + 232) == v223 )
                        goto LABEL_627;
                      *(_DWORD *)(v224 + 232) = v223;
                      v225 = *(unsigned __int8 *)(v267 + 76);
                      if ( v225 > 5 )
                        goto LABEL_667;
                      v226 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 72LL) + 8 * v225 + 328);
                      v227 = ieee80211_sta_rx_bw_to_chan_width(*(_QWORD *)(a1 + 48));
                      v228 = *(_QWORD *)(a1 + 40);
                      LODWORD(v270) = v227;
                      LODWORD(v269) = 1;
                      v229 = v161;
                      v230 = v226;
                      v231 = 1;
                    }
                    rate_control_rate_update(v229, v230, v228, 0, v231);
                    cfg80211_sta_opmode_change_notify(
                      *(_QWORD *)(v134 + 1608),
                      *(_QWORD *)(a1 + 40) + 64LL,
                      &v269,
                      2080);
                    goto LABEL_627;
                  }
                  goto LABEL_519;
                }
                goto LABEL_428;
              }
              if ( *(_BYTE *)(v131 + 24) )
              {
                if ( v135 != 3 )
                  goto LABEL_526;
                v155 = *(_DWORD *)(v134 + 4720);
                if ( (v155 > 7 || ((1 << v155) & 0x9C) == 0) && v155 != 1 )
                  goto LABEL_526;
                if ( v132 < 0x1A )
                  goto LABEL_526;
                v156 = *(unsigned __int8 *)(v131 + 25);
                if ( v156 != 2 )
                {
                  if ( v156 != 1 )
                  {
                    v130 = v267;
                    if ( !*(_BYTE *)(v131 + 25) && v132 >= 0x21 )
                    {
LABEL_600:
                      v216 = *(_DWORD *)(a1 + 76);
                      v217 = *(_BYTE *)(v130 + 86);
                      *(_WORD *)(v130 + 180) = 0;
                      if ( v216 < 0 )
                        v218 = v217 & 0xFE;
                      else
                        v218 = v217 & 0xE0 | (2 * (v216 & 0xF)) | 1;
                      *(_BYTE *)(v267 + 86) = v218;
                      skb_queue_tail(v134 + 1984);
                      wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v134 + 1616) + 72LL), v134 + 1960);
                      v5 = 0;
                      if ( v133 )
                        ++*(_QWORD *)(v133 + 1752);
                      goto LABEL_301;
                    }
                    goto LABEL_429;
                  }
                  _CF = v132 >= 0x21;
                  goto LABEL_593;
                }
LABEL_436:
                _CF = v132 >= 0x1E;
LABEL_593:
                v130 = v267;
                if ( _CF )
                  goto LABEL_600;
                goto LABEL_429;
              }
            }
            else if ( *(_BYTE *)(v131 + 24) )
            {
              if ( v135 != 4 )
              {
                if ( v135 != 15 )
                {
                  v5 = 65560;
                  goto LABEL_301;
                }
LABEL_425:
                if ( v132 >= 0x1A && (unsigned int)*(unsigned __int8 *)(v131 + 25) - 1 < 5 )
                  goto LABEL_429;
                goto LABEL_527;
              }
LABEL_428:
              if ( v132 < 0x1A )
                goto LABEL_429;
              if ( !v133
                || *(_DWORD *)(v134 + 4720) != 2
                || *(_DWORD *)(v134 + 4152) ^ *(_DWORD *)(v131 + 16)
                 | *(unsigned __int16 *)(v134 + 4156) ^ *(unsigned __int16 *)(v131 + 20)
                || *(_BYTE *)(v131 + 25) != 4 )
              {
                goto LABEL_526;
              }
              goto LABEL_436;
            }
            if ( v132 < 0x1A )
              goto LABEL_526;
            if ( *(_BYTE *)(v131 + 25) == 4 )
            {
              v189 = *(_DWORD *)(v134 + 4720);
              switch ( v189 )
              {
                case 1:
                  v190 = v134 + 2346;
                  break;
                case 7:
                  v190 = v131 + 10;
                  break;
                case 2:
                  v190 = v134 + 4152;
                  break;
                default:
                  goto LABEL_526;
              }
              v130 = v267;
              if ( !(*(_DWORD *)v190 ^ *(_DWORD *)(v131 + 16)
                   | *(unsigned __int16 *)(v190 + 4) ^ *(unsigned __int16 *)(v131 + 20)) )
                goto LABEL_600;
              goto LABEL_527;
            }
            if ( *(_BYTE *)(v131 + 25) || *(_BYTE *)(v267 + 76) != 1 || v132 < 0x20 || *(_DWORD *)(v134 + 4720) != 2 )
              goto LABEL_526;
            ieee80211_process_measurement_req(*(_QWORD *)(a1 + 24), *(_QWORD *)(v267 + 224), (int)v132);
            goto LABEL_627;
          }
        }
        if ( v172 == 128 )
        {
          if ( *(_QWORD *)(a1 + 56) )
          {
            v184 = *(unsigned int *)(v139 + 112);
            if ( (v174 & 1) == 0
              || (unsigned int)v184 < 0x2A
              || ((v185 = (char *)v58 + v184, *((_BYTE *)v58 + v184 - 18) != 76) || *(v185 - 17) != 16)
              && ((unsigned int)v184 < 0x32 || *(v185 - 26) != 76 || *(v185 - 25) != 24) )
            {
              cfg80211_rx_unprot_mlme_mgmt(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 1608LL));
              v5 = 65557;
              goto LABEL_301;
            }
            goto LABEL_319;
          }
        }
        else if ( v172 == 208 && !*(_QWORD *)(a1 + 56) && *(_DWORD *)(v139 + 112) >= 0x19u )
        {
          v5 = 65553;
          if ( (v59 & 0x4000) != 0 )
            goto LABEL_301;
          v242 = *((unsigned __int8 *)v58 + 24);
          if ( (v242 > 0x16 || ((1 << v242) & 0x708890) == 0) && v242 != 127 )
            goto LABEL_301;
        }
        if ( (v174 & 1) == 0 && (v186 = *(_DWORD *)(v139 + 112), v186 >= 0x19) )
        {
          if ( v172 != 208 )
            goto LABEL_319;
          if ( v186 != 25 && *((_BYTE *)v58 + 24) == 4 )
          {
            v211 = *((unsigned __int8 *)v58 + 25);
            v5 = 65558;
            if ( v211 > 0x22 || ((1LL << v211) & 0x70000C289LL) == 0 )
              goto LABEL_301;
          }
        }
        else
        {
LABEL_507:
          if ( v172 != 208 || *(_DWORD *)(v139 + 112) < 0x19u )
            goto LABEL_319;
        }
        v187 = v59 & 0xFC;
        if ( v187 == 160
          || v187 == 192
          || v187 == 208
          && ((v59 & 0x4000) != 0
           || ((v188 = *((unsigned __int8 *)v58 + 24), v188 > 0x16) || ((1 << v188) & 0x708890) == 0) && v188 != 127) )
        {
          v5 = 65559;
          if ( !v173 || (*(_QWORD *)(v173 + 216) & 2) == 0 )
            goto LABEL_301;
        }
        goto LABEL_319;
      }
      if ( (v59 & 0x48) != 8 )
        goto LABEL_147;
      v90 = *(_QWORD *)(a1 + 16);
      v91 = *(_QWORD *)(v89 + 1608);
      v92 = *(_DWORD *)(v89 + 4720);
      if ( (v59 & 0x300) != 0x300 )
      {
        if ( v92 != 2 )
          goto LABEL_202;
LABEL_188:
        if ( ((v59 & 0x300) == 768) != (*(_BYTE *)(v89 + 2524) == 0) )
        {
          v94 = 0;
        }
        else
        {
          if ( !*(_BYTE *)(v89 + 2524) )
          {
            v5 = 65579;
            goto LABEL_301;
          }
          _ZF = *(_DWORD *)(v89 + 5842) == *((_DWORD *)v58 + 1) && *(unsigned __int16 *)(v89 + 5846) == v58[4];
          v94 = !_ZF;
        }
LABEL_230:
        if ( (ieee80211_data_to_8023_exthdr() & 0x80000000) != 0 )
        {
          v5 = 65551;
        }
        else
        {
          v103 = *(_QWORD *)(a1 + 8);
          v104 = *(_QWORD *)(a1 + 24);
          v105 = *(_QWORD *)(v103 + 224);
          v106 = *(unsigned __int16 *)(v104 + 1940);
          v107 = *(unsigned __int16 *)(v105 + 12);
          if ( v107 == v106 )
            v108 = 0;
          else
            v108 = v94;
          if ( (v108 & 1) != 0 )
          {
            v5 = 65581;
          }
          else
          {
            if ( v107 == v106 )
            {
              if ( (ieee80211_is_our_addr(v104, *(_QWORD *)(v103 + 224), nullptr) & 1) != 0
                || !(*(_DWORD *)v105 ^ 0xC28001 | *(unsigned __int16 *)(v105 + 4) ^ 0x300) )
              {
LABEL_242:
                v110 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 224LL);
                if ( *(_WORD *)(v110 + 12) == 3465
                  && (pskb_may_pull() & 1) != 0
                  && *(_BYTE *)(v110 + 14) == 2
                  && *(_BYTE *)(v110 + 15) == 12
                  && (unsigned int)*(unsigned __int8 *)(v110 + 16) - 5 <= 1 )
                {
                  *(_WORD *)(*(_QWORD *)(a1 + 8) + 180LL) = 3465;
                  _ieee80211_queue_skb_to_iface(
                    v89,
                    *(unsigned int *)(a1 + 76),
                    *(_QWORD *)(a1 + 40),
                    *(_QWORD *)(a1 + 8));
                  v5 = 0;
                }
                else
                {
                  if ( v107 == v106 && *(_DWORD *)(*(_QWORD *)(a1 + 24) + 4720LL) == 4 )
                  {
                    v111 = *(_QWORD *)(v89 + 2032);
                    if ( v111 )
                    {
                      v89 = v111 - 2264;
                      v91 = *(_QWORD *)(v111 - 656);
                      *(_QWORD *)(a1 + 24) = v111 - 2264;
                    }
                  }
                  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 16LL) = v91;
                  if ( (*(_QWORD *)(v90 + 96) & 0x400) == 0 )
                  {
                    if ( *(_QWORD *)(v90 + 5008) )
                    {
                      v112 = *(unsigned int *)(v90 + 8);
                      if ( (int)v112 >= 1
                        && (**(_BYTE **)(*(_QWORD *)(a1 + 8) + 224LL) & 1) == 0
                        && !*(_QWORD *)(v90 + 4696)
                        && (*(_QWORD *)(v89 + 1632) & 2) == 0 )
                      {
                        v113 = jiffies;
                        v114 = _msecs_to_jiffies(v112);
                        mod_timer(v90 + 5064, v114 + v113);
                      }
                    }
                  }
                  ieee80211_deliver_skb(a1);
                  v5 = 0;
                }
                goto LABEL_301;
              }
            }
            else
            {
              v109 = *(_QWORD *)(a1 + 40);
              if ( v109
                && (*(_QWORD *)(v109 + 216) & 8) != 0
                && (v59 & 0x4000 | *(_BYTE *)(v103 + 64) & 2 || !*(_QWORD *)(a1 + 56)) )
              {
                goto LABEL_242;
              }
            }
            v5 = 0x20000;
          }
        }
        goto LABEL_301;
      }
      if ( v92 == 2 )
        goto LABEL_188;
      if ( v92 == 4 )
      {
        if ( !*(_QWORD *)(v89 + 2280) )
        {
          v5 = 65578;
          goto LABEL_301;
        }
        v92 = 4;
LABEL_202:
        v94 = 0;
        if ( v92 == 4 && (*((_DWORD *)v58 + 1) & 1) != 0 )
        {
          if ( *(_QWORD *)(v89 + 2280) )
          {
            v5 = 65580;
            goto LABEL_301;
          }
          v94 = 0;
        }
        goto LABEL_230;
      }
      if ( v92 != 3 )
      {
        v94 = 0;
        goto LABEL_230;
      }
      v93 = *(_QWORD *)(a1 + 40);
      if ( v93 )
      {
        _X9 = (unsigned __int64 *)(v93 + 216);
        __asm { PRFM            #0x11, [X9] }
        do
          v248 = __ldxr(_X9);
        while ( __stlxr(v248 | 0x80000, _X9) );
        __dmb(0xBu);
        if ( (v248 & 0x80000) != 0 )
          goto LABEL_147;
        cfg80211_rx_unexpected_4addr_frame(
          *(_QWORD *)(*(_QWORD *)(a1 + 24) + 1608LL),
          *(_QWORD *)(a1 + 40) + 2688LL,
          2080);
        v5 = 0x20000;
      }
      else
      {
        v5 = 0x20000;
      }
LABEL_301:
      ieee80211_rx_handlers_result(a1, v5);
      v4 = *a2;
      if ( *a2 == (__int64 *)a2 || !v4 )
        goto LABEL_666;
    }
    *(_BYTE *)(v9 + 5004) = 0;
LABEL_9:
    v11 = *(_QWORD *)(a1 + 40);
    if ( !v11 )
      goto LABEL_25;
    goto LABEL_10;
  }
LABEL_666:
  result = raw_spin_unlock_bh(*(_QWORD *)(a1 + 16) + 1600LL);
  _ReadStatusReg(SP_EL0);
  return result;
}
