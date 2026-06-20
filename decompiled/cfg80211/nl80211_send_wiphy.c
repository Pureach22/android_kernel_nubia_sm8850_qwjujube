__int64 __fastcall nl80211_send_wiphy(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7)
{
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x20
  const char *v14; // x25
  int v15; // w0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 result; // x0
  int v19; // w8
  char v20; // w9
  char v21; // w9
  char v22; // w9
  __int64 v23; // x23
  __int64 v24; // x24
  int v25; // w8
  unsigned __int64 v26; // x9
  unsigned int v27; // w10
  char v28; // w11
  __int64 v29; // x23
  __int64 v30; // x12
  __int64 v31; // x24
  char v32; // w9
  __int64 v33; // x25
  __int64 v34; // x26
  char v35; // w9
  __int64 v36; // x25
  __int64 v37; // x26
  int v38; // w8
  int v39; // w9
  __int64 v40; // x25
  __int64 v41; // x26
  __int64 v42; // x28
  __int64 v43; // x27
  _WORD *v44; // x28
  int v45; // w8
  unsigned __int64 v46; // x10
  char v47; // w11
  char *v48; // x3
  __int64 v49; // x0
  __int64 v50; // x1
  __int64 v51; // x2
  __int64 v52; // x23
  __int64 v53; // x24
  _WORD *v54; // x24
  __int64 v55; // x25
  __int64 v56; // x23
  int v57; // w0
  unsigned int v58; // w23
  __int64 v59; // x22
  __int64 v60; // x24
  _WORD *v61; // x24
  unsigned int v62; // w22
  __int64 v63; // x3
  __int64 v64; // x3
  __int64 v65; // x23
  __int64 v66; // x24
  __int64 v67; // x25
  unsigned __int64 v68; // x23
  int v69; // w0
  __int64 v70; // x3
  __int64 v71; // x23
  __int64 v72; // x24
  _WORD *v73; // x24
  unsigned int v74; // w23
  __int64 v75; // x26
  __int64 v76; // x25
  __int64 v77; // x27
  _WORD *v78; // x25
  __int64 v79; // x26
  char v80; // w8
  bool v81; // cc
  __int64 v82; // x23
  __int64 v83; // x24
  __int64 v84; // x25
  __int64 v85; // x23
  int v86; // w0
  __int64 v87; // x10
  __int64 v88; // x23
  __int64 v89; // x24
  _WORD *v90; // x24
  unsigned int v91; // w0
  _QWORD *v92; // x8
  unsigned int v93; // w23
  char v94; // w9
  char v95; // w9
  char v96; // w9
  __int64 v97; // x3
  char v98; // w9
  int v99; // w8
  __int64 v100; // x3
  _WORD *v101; // [xsp+8h] [xbp-58h]
  _WORD *v102; // [xsp+10h] [xbp-50h]
  _WORD *v103; // [xsp+18h] [xbp-48h]
  _QWORD v104[6]; // [xsp+20h] [xbp-40h] BYREF
  _QWORD v105[2]; // [xsp+50h] [xbp-10h] BYREF

  v105[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 1064);
  v12 = genlmsg_put(a3, a4, a5, &nl80211_fam, a6, a2);
  if ( v12 )
  {
    if ( a7 )
    {
      v13 = v12;
      LODWORD(v104[0]) = *(_DWORD *)(a1 + 100);
      if ( !(unsigned int)nla_put(a3, 1, 4, v104) )
      {
        v14 = *(const char **)(a1 + 1496);
        if ( !v14 )
          v14 = *(const char **)(a1 + 1384);
        v15 = strlen(v14);
        if ( !(unsigned int)nla_put(a3, 2, (unsigned int)(v15 + 1), v14) )
        {
          LODWORD(v104[0]) = cfg80211_rdev_list_generation;
          if ( !(unsigned int)nla_put(a3, 46, 4, v104) )
          {
            if ( a2 != 3 )
            {
LABEL_270:
              result = 0;
              *(_DWORD *)(v13 - 20) = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (v13 - 20);
              goto LABEL_14;
            }
            switch ( *(_QWORD *)(a7 + 16) )
            {
              case 0LL:
                LOBYTE(v104[0]) = *(_BYTE *)(a1 + 1188);
                if ( (unsigned int)nla_put(a3, 61, 1, v104) )
                  goto LABEL_8;
                LOBYTE(v104[0]) = *(_BYTE *)(a1 + 1189);
                if ( (unsigned int)nla_put(a3, 62, 1, v104) )
                  goto LABEL_8;
                LODWORD(v104[0]) = *(_DWORD *)(a1 + 1192);
                if ( (unsigned int)nla_put(a3, 63, 4, v104) )
                  goto LABEL_8;
                LODWORD(v104[0]) = *(_DWORD *)(a1 + 1196);
                if ( (unsigned int)nla_put(a3, 64, 4, v104) )
                  goto LABEL_8;
                LOBYTE(v104[0]) = *(_BYTE *)(a1 + 1200);
                if ( (unsigned int)nla_put(a3, 89, 1, v104) )
                  goto LABEL_8;
                LOBYTE(v104[0]) = *(_BYTE *)(a1 + 1128);
                if ( (unsigned int)nla_put(a3, 43, 1, v104) )
                  goto LABEL_8;
                LOBYTE(v104[0]) = *(_BYTE *)(a1 + 1130);
                if ( (unsigned int)nla_put(a3, 123, 1, v104) )
                  goto LABEL_8;
                LOWORD(v104[0]) = *(_WORD *)(a1 + 1132);
                if ( (unsigned int)nla_put(a3, 56, 2, v104) )
                  goto LABEL_8;
                LOWORD(v104[0]) = *(_WORD *)(a1 + 1134);
                if ( (unsigned int)nla_put(a3, 124, 2, v104) )
                  goto LABEL_8;
                LOBYTE(v104[0]) = *(_BYTE *)(a1 + 1131);
                if ( (unsigned int)nla_put(a3, 133, 1, v104) )
                  goto LABEL_8;
                v19 = *(_DWORD *)(a1 + 1092);
                if ( (v19 & 0x100) == 0 )
                  goto LABEL_30;
                if ( (unsigned int)nla_put(a3, 104, 0, 0) )
                  goto LABEL_8;
                v19 = *(_DWORD *)(a1 + 1092);
LABEL_30:
                if ( (v19 & 0x400) == 0 )
                  goto LABEL_33;
                if ( (unsigned int)nla_put(a3, 115, 0, 0) )
                  goto LABEL_8;
                v19 = *(_DWORD *)(a1 + 1092);
LABEL_33:
                if ( (v19 & 0x4000) == 0 )
                  goto LABEL_36;
                if ( (unsigned int)nla_put(a3, 130, 0, 0) )
                  goto LABEL_8;
                v19 = *(_DWORD *)(a1 + 1092);
LABEL_36:
                if ( (v19 & 0x2000) == 0 )
                  goto LABEL_39;
                if ( (unsigned int)nla_put(a3, 131, 0, 0) )
                  goto LABEL_8;
                v19 = *(_DWORD *)(a1 + 1092);
LABEL_39:
                if ( (v19 & 0x8000) == 0 )
                  goto LABEL_42;
                if ( (unsigned int)nla_put(a3, 139, 0, 0) )
                  goto LABEL_8;
                v19 = *(_DWORD *)(a1 + 1092);
LABEL_42:
                if ( (v19 & 0x10000) != 0 && (unsigned int)nla_put(a3, 140, 0, 0) )
                  goto LABEL_8;
                v20 = *(_BYTE *)(a7 + 48);
                ++*(_QWORD *)(a7 + 16);
                if ( (v20 & 1) != 0 )
                  goto LABEL_270;
LABEL_45:
                if ( (unsigned int)nla_put(a3, 57, (unsigned int)(4 * *(_DWORD *)(a1 + 1148)), *(_QWORD *)(a1 + 1152)) )
                  goto LABEL_8;
                LOBYTE(v104[0]) = *(_BYTE *)(a1 + 1258);
                if ( (unsigned int)nla_put(a3, 86, 1, v104)
                  || (*(_BYTE *)(a1 + 1092) & 0x80) != 0 && (unsigned int)nla_put(a3, 102, 0, 0) )
                {
                  goto LABEL_8;
                }
                LODWORD(v104[0]) = *(_DWORD *)(a1 + 1260);
                if ( (unsigned int)nla_put(a3, 113, 4, v104) )
                  goto LABEL_8;
                LODWORD(v104[0]) = *(_DWORD *)(a1 + 1264);
                if ( (unsigned int)nla_put(a3, 114, 4, v104) )
                  goto LABEL_8;
                if ( (*(_BYTE *)(a1 + 1094) & 8) != 0 )
                {
                  LODWORD(v104[0]) = *(_DWORD *)(a1 + 1268);
                  if ( (unsigned int)nla_put(a3, 144, 4, v104) )
                    goto LABEL_8;
                }
                if ( *(_DWORD *)(a1 + 1260) || *(_DWORD *)(a1 + 1264) )
                {
                  if ( *(_QWORD *)(*(_QWORD *)a1 + 584LL) )
                  {
                    v105[0] = 0;
                    if ( !(unsigned int)rdev_get_antenna(a1, (char *)v105 + 4, v105) )
                    {
                      LODWORD(v104[0]) = HIDWORD(v105[0]);
                      if ( (unsigned int)nla_put(a3, 105, 4, v104) )
                        goto LABEL_8;
                      LODWORD(v104[0]) = v105[0];
                      if ( (unsigned int)nla_put(a3, 106, 4, v104) )
                        goto LABEL_8;
                    }
                  }
                }
                v21 = *(_BYTE *)(a7 + 48);
                ++*(_QWORD *)(a7 + 16);
                if ( (v21 & 1) != 0 )
                  goto LABEL_270;
LABEL_58:
                if ( (unsigned int)nl80211_put_iftypes(a3, 32, *(unsigned __int16 *)(a1 + 1088)) )
                  goto LABEL_8;
                v22 = *(_BYTE *)(a7 + 48);
                ++*(_QWORD *)(a7 + 16);
                if ( (v22 & 1) != 0 )
                  goto LABEL_270;
LABEL_60:
                v23 = *(_QWORD *)(a3 + 216);
                v24 = *(unsigned int *)(a3 + 208);
                if ( (nla_put(a3, 22, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_8;
                v102 = (_WORD *)(v23 + v24);
                if ( !(v23 + v24) )
                  goto LABEL_8;
                LOBYTE(v25) = *(_BYTE *)(a7 + 48);
                v26 = *(_QWORD *)(a7 + 24);
                if ( (_BYTE)v25 )
                  v27 = 6;
                else
                  v27 = 3;
                if ( (unsigned int)v26 > 1 )
                  v28 = v25 ^ 1;
                else
                  v28 = 0;
                if ( (v28 & 1) != 0 || v27 <= (unsigned int)v26 )
                  goto LABEL_203;
                v29 = (unsigned int)*(_QWORD *)(a7 + 24);
                v30 = a1 + 1320;
                while ( 2 )
                {
                  v31 = *(_QWORD *)(v30 + 8 * v29);
                  v32 = v25;
                  if ( !v31 )
                    goto LABEL_94;
                  v33 = *(_QWORD *)(a3 + 216);
                  v34 = *(unsigned int *)(a3 + 208);
                  if ( (nla_put(a3, (unsigned int)v29, 0, 0) & 0x80000000) != 0 )
                    goto LABEL_8;
                  v103 = (_WORD *)(v33 + v34);
                  if ( !(v33 + v34) )
                    goto LABEL_8;
                  if ( *(_QWORD *)(a7 + 32) )
                    goto LABEL_77;
                  if ( (unsigned int)nl80211_send_band_rateinfo(a3, v31, *(unsigned __int8 *)(a7 + 48)) )
                    goto LABEL_8;
                  v35 = *(_BYTE *)(a7 + 48);
                  ++*(_QWORD *)(a7 + 32);
                  if ( (v35 & 1) == 0 )
                  {
LABEL_77:
                    v36 = *(_QWORD *)(a3 + 216);
                    v37 = *(unsigned int *)(a3 + 208);
                    if ( (nla_put(a3, 1, 0, 0) & 0x80000000) != 0 )
                      goto LABEL_8;
                    v101 = (_WORD *)(v36 + v37);
                    if ( !(v36 + v37) )
                      goto LABEL_8;
                    v38 = *(_DWORD *)(v31 + 20);
                    v39 = *(_DWORD *)(a7 + 32) - 1;
                    if ( v39 < v38 )
                    {
                      v40 = v39;
                      v41 = (__int64)v39 << 6;
                      while ( 1 )
                      {
                        v42 = *(_QWORD *)(a3 + 216);
                        v43 = *(unsigned int *)(a3 + 208);
                        if ( (nla_put(a3, (unsigned int)v40, 0, 0) & 0x80000000) != 0 )
                          goto LABEL_8;
                        v44 = (_WORD *)(v42 + v43);
                        if ( !v44
                          || (unsigned int)nl80211_msg_put_channel(
                                             a3,
                                             a1 + 992,
                                             *(_QWORD *)v31 + v41,
                                             *(unsigned __int8 *)(a7 + 48)) )
                        {
                          goto LABEL_8;
                        }
                        *v44 = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v44;
                        v38 = *(_DWORD *)(v31 + 20);
                        if ( (*(_BYTE *)(a7 + 48) & 1) == 0 )
                        {
                          ++v40;
                          v41 += 64;
                          if ( v40 < v38 )
                            continue;
                        }
                        goto LABEL_88;
                      }
                    }
                    LODWORD(v40) = *(_DWORD *)(a7 + 32) - 1;
LABEL_88:
                    if ( (int)v40 >= v38 )
                      v45 = 0;
                    else
                      v45 = v40 + 2;
                    *(_QWORD *)(a7 + 32) = v45;
                    *v101 = *(_WORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v101;
                  }
                  *v103 = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v103;
                  v25 = *(unsigned __int8 *)(a7 + 48);
                  if ( v25 != 1 )
                  {
                    v30 = a1 + 1320;
                    v32 = 0;
LABEL_94:
                    v46 = 3;
                    if ( (v32 & 1) != 0 )
                      v46 = 6;
                    v47 = (v29 != 0) & (v32 ^ 1);
                    v26 = v29 + 1;
                    if ( (v47 & 1) != 0 )
                      goto LABEL_203;
                    ++v29;
                    if ( v26 >= v46 )
                      goto LABEL_203;
                    continue;
                  }
                  break;
                }
                LODWORD(v26) = v29 - (*(_QWORD *)(a7 + 32) != 0);
LABEL_203:
                if ( (unsigned int)v26 <= 5 )
                  v87 = (unsigned int)(v26 + 1);
                else
                  v87 = 0;
                *v102 = *(_WORD *)(a3 + 216) + *(_WORD *)(a3 + 208) - (_WORD)v102;
                *(_QWORD *)(a7 + 24) = v87;
                if ( (unsigned int)v26 >= 6 && !*(_QWORD *)(a7 + 32) )
                  ++*(_QWORD *)(a7 + 16);
                if ( (*(_BYTE *)(a7 + 48) & 1) != 0 )
                  goto LABEL_270;
LABEL_210:
                v88 = *(_QWORD *)(a3 + 216);
                v89 = *(unsigned int *)(a3 + 208);
                if ( (nla_put(a3, 50, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_8;
                v90 = (_WORD *)(v88 + v89);
                if ( !v90 )
                  goto LABEL_8;
                v91 = nl80211_add_commands_unsplit(a1, a3);
                if ( (v91 & 0x80000000) != 0 )
                  goto LABEL_8;
                if ( *(_BYTE *)(a7 + 48) == 1 )
                {
                  v92 = *(_QWORD **)a1;
                  v93 = v91;
                  if ( *(_QWORD *)(*(_QWORD *)a1 + 704LL) )
                  {
                    v93 = v91 + 1;
                    LODWORD(v104[0]) = 98;
                    if ( (unsigned int)nla_put(a3, v91 + 1, 4, v104) )
                      goto LABEL_8;
                    v92 = *(_QWORD **)a1;
                  }
                  if ( v92[89] )
                  {
                    ++v93;
                    LODWORD(v104[0]) = 99;
                    if ( (unsigned int)nla_put(a3, v93, 4, v104) )
                      goto LABEL_8;
                    v92 = *(_QWORD **)a1;
                  }
                  if ( (*(_BYTE *)(a1 + 1094) & 0x80) != 0 && v92[91] )
                  {
                    ++v93;
                    LODWORD(v104[0]) = 102;
                    if ( (unsigned int)nla_put(a3, v93, 4, v104) )
                      goto LABEL_8;
                    v92 = *(_QWORD **)a1;
                  }
                  if ( v92[92] )
                  {
                    ++v93;
                    LODWORD(v104[0]) = 104;
                    if ( (unsigned int)nla_put(a3, v93, 4, v104) )
                      goto LABEL_8;
                    v92 = *(_QWORD **)a1;
                  }
                  if ( (*(_BYTE *)(a1 + 1103) & 4) != 0 && v92[94] )
                  {
                    ++v93;
                    LODWORD(v104[0]) = 105;
                    if ( (unsigned int)nla_put(a3, v93, 4, v104) )
                      goto LABEL_8;
                    v92 = *(_QWORD **)a1;
                  }
                  if ( v92[103] )
                  {
                    ++v93;
                    LODWORD(v104[0]) = 121;
                    if ( (unsigned int)nla_put(a3, v93, 4, v104) )
                      goto LABEL_8;
                    v92 = *(_QWORD **)a1;
                  }
                  if ( v92[47] )
                  {
                    ++v93;
                    LODWORD(v104[0]) = 122;
                    if ( (unsigned int)nla_put(a3, v93, 4, v104) )
                      goto LABEL_8;
                    v92 = *(_QWORD **)a1;
                  }
                  if ( v92[87] )
                  {
                    ++v93;
                    LODWORD(v104[0]) = 96;
                    if ( (unsigned int)nla_put(a3, v93, 4, v104) )
                      goto LABEL_8;
                  }
                  if ( *(_QWORD *)(a1 + 2464) )
                  {
                    if ( *(_QWORD *)(*(_QWORD *)a1 + 928LL) )
                    {
                      LODWORD(v104[0]) = 140;
                      if ( (unsigned int)nla_put(a3, v93 + 1, 4, v104) )
                        goto LABEL_8;
                    }
                  }
                }
                *v90 = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v90;
                v94 = *(_BYTE *)(a7 + 48);
                ++*(_QWORD *)(a7 + 16);
                if ( (v94 & 1) != 0 )
                  goto LABEL_270;
LABEL_243:
                if ( *(_QWORD *)(*(_QWORD *)a1 + 504LL) )
                {
                  if ( (*(_BYTE *)(a1 + 1094) & 0x20) != 0 )
                  {
                    LODWORD(v104[0]) = *(unsigned __int16 *)(a1 + 1256);
                    if ( (unsigned int)nla_put(a3, 111, 4, v104) )
                      goto LABEL_8;
                  }
                }
                if ( (*(_BYTE *)(a1 + 1094) & 0x10) != 0 && (unsigned int)nla_put(a3, 108, 0, 0) )
                  goto LABEL_8;
                v95 = *(_BYTE *)(a7 + 48);
                ++*(_QWORD *)(a7 + 16);
                if ( (v95 & 1) != 0 )
                  goto LABEL_270;
                v80 = 0;
LABEL_250:
                if ( (unsigned int)nl80211_send_wowlan(a3, a1, v80 & 1) )
                  goto LABEL_8;
                v96 = *(_BYTE *)(a7 + 48);
                ++*(_QWORD *)(a7 + 16);
                if ( (v96 & 1) != 0 )
                  goto LABEL_270;
LABEL_252:
                if ( (unsigned int)nl80211_put_iftypes(a3, 121, *(unsigned __int16 *)(a1 + 1084)) )
                  goto LABEL_8;
                v97 = *(_DWORD *)(a1 + 2488) ? 0LL : 0xFFFFFFFFLL;
                if ( (unsigned int)nl80211_put_iface_combinations(
                                     a1 + 992,
                                     a3,
                                     120,
                                     v97,
                                     *(unsigned __int8 *)(a7 + 48),
                                     0) )
                  goto LABEL_8;
                v98 = *(_BYTE *)(a7 + 48);
                ++*(_QWORD *)(a7 + 16);
                if ( (v98 & 1) != 0 )
                  goto LABEL_270;
LABEL_258:
                if ( (*(_BYTE *)(a1 + 1094) & 2) != 0 )
                {
                  LODWORD(v104[0]) = *(_DWORD *)(a1 + 1116);
                  if ( (unsigned int)nla_put(a3, 141, 4, v104) )
                    goto LABEL_8;
                }
                v99 = *(_DWORD *)(a1 + 1100);
                if ( *(_BYTE *)(a7 + 48) )
                  v99 |= 0x4000u;
                LODWORD(v104[0]) = v99;
                if ( (unsigned int)nla_put(a3, 143, 4, v104) )
                  goto LABEL_8;
                v100 = *(_QWORD *)(a1 + 2312);
                if ( v100 )
                {
                  if ( (unsigned int)nla_put(a3, 148, 26, v100) )
                    goto LABEL_8;
                }
                if ( (*(_BYTE *)(a1 + 1094) & 2) != 0 )
                {
                  if ( *(_WORD *)(a1 + 1090) )
                  {
                    LODWORD(v104[0]) = *(unsigned __int16 *)(a1 + 1090);
                    if ( (unsigned int)nla_put(a3, 167, 4, v104) )
                      goto LABEL_8;
                  }
                }
                if ( *(_BYTE *)(a7 + 48) != 1 )
                {
LABEL_151:
                  *(_QWORD *)(a7 + 16) = 0;
                  goto LABEL_270;
                }
                goto LABEL_269;
              case 1LL:
                goto LABEL_45;
              case 2LL:
                goto LABEL_58;
              case 3LL:
                goto LABEL_60;
              case 4LL:
                goto LABEL_210;
              case 5LL:
                goto LABEL_243;
              case 6LL:
                v80 = *(_BYTE *)(a7 + 48);
                goto LABEL_250;
              case 7LL:
                goto LABEL_252;
              case 8LL:
                goto LABEL_258;
              case 9LL:
                if ( (unsigned int)nl80211_send_mgmt_stypes(a3, v11) )
                  goto LABEL_8;
                LODWORD(v104[0]) = *(_DWORD *)(a1 + 1136);
                if ( (unsigned int)nla_put(a3, 222, 4, v104) )
                  goto LABEL_8;
                LODWORD(v104[0]) = *(_DWORD *)(a1 + 1140);
                if ( (unsigned int)nla_put(a3, 223, 4, v104) )
                  goto LABEL_8;
                LODWORD(v104[0]) = *(_DWORD *)(a1 + 1144);
                if ( (unsigned int)nla_put(a3, 224, 4, v104) )
                  goto LABEL_8;
                v63 = *(_QWORD *)(a1 + 1272);
                if ( v63 )
                {
                  if ( (unsigned int)nla_put(a3, 169, *(unsigned __int8 *)(a1 + 1288), v63)
                    || (unsigned int)nla_put(a3, 170, *(unsigned __int8 *)(a1 + 1288), *(_QWORD *)(a1 + 1280)) )
                  {
                    goto LABEL_8;
                  }
                }
                v64 = *(_QWORD *)(a1 + 2320);
                if ( v64 )
                {
                  if ( (unsigned int)nla_put(a3, 176, 12, v64) )
                    goto LABEL_8;
                }
                if ( (unsigned int)nla_put(a3, 6, 6, a1 + 1040)
                  || *(_DWORD *)(a1 + 1046) | *(unsigned __int16 *)(a1 + 1050)
                  && (unsigned int)nla_put(a3, 215, 6, a1 + 1046) )
                {
                  goto LABEL_8;
                }
                if ( *(unsigned __int16 *)(a1 + 1086) < 2u )
                  goto LABEL_269;
                v65 = *(_QWORD *)(a3 + 216);
                v66 = *(unsigned int *)(a3 + 208);
                if ( (nla_put(a3, 32934, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_8;
                v61 = (_WORD *)(v65 + v66);
                if ( !v61 )
                  goto LABEL_8;
                v67 = 0;
                v68 = 0;
                while ( v68 < *(unsigned __int16 *)(a1 + 1086) )
                {
                  v69 = nla_put(a3, (unsigned int)++v68, 6, *(_QWORD *)(a1 + 1056) + v67);
                  v67 += 6;
                  if ( v69 )
                    goto LABEL_8;
                }
                goto LABEL_201;
              case 0xALL:
                if ( (unsigned int)nl80211_send_coalesce(a3, a1)
                  || (*(_BYTE *)(a1 + 1094) & 0x40) != 0
                  && ((unsigned int)nla_put(a3, 192, 0, 0) || (unsigned int)nla_put(a3, 193, 0, 0)) )
                {
                  goto LABEL_8;
                }
                if ( !*(_WORD *)(a1 + 2384) )
                  goto LABEL_269;
                v48 = (char *)v104;
                v49 = a3;
                v50 = 202;
                LODWORD(v104[0]) = *(unsigned __int16 *)(a1 + 2384);
                goto LABEL_173;
              case 0xBLL:
                if ( !*(_DWORD *)(a1 + 2376) )
                  goto LABEL_194;
                v52 = *(_QWORD *)(a3 + 216);
                v53 = *(unsigned int *)(a3 + 208);
                if ( (nla_put(a3, 197, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_8;
                v54 = (_WORD *)(v52 + v53);
                if ( !v54 )
                  goto LABEL_8;
                v55 = 0;
                v56 = 0;
                while ( v56 < *(int *)(a1 + 2376) )
                {
                  v57 = nla_put(a3, (unsigned int)++v56, 8, *(_QWORD *)(a1 + 2360) + v55);
                  v55 += 56;
                  if ( v57 )
                    goto LABEL_8;
                }
                *v54 = *(_WORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v54;
LABEL_194:
                if ( !*(_DWORD *)(a1 + 2380) )
                  goto LABEL_269;
                v82 = *(_QWORD *)(a3 + 216);
                v83 = *(unsigned int *)(a3 + 208);
                if ( (nla_put(a3, 198, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_8;
                v61 = (_WORD *)(v82 + v83);
                if ( !v61 )
                  goto LABEL_8;
                v84 = 0;
                v85 = 0;
                while ( v85 < *(int *)(a1 + 2380) )
                {
                  v86 = nla_put(a3, (unsigned int)++v85, 8, *(_QWORD *)(a1 + 2368) + v84);
                  v84 += 8;
                  if ( v86 )
                    goto LABEL_8;
                }
                goto LABEL_201;
              case 0xCLL:
                if ( (*(_BYTE *)(a1 + 1094) & 0x80) != 0 )
                {
                  LOBYTE(v104[0]) = *(_BYTE *)(a1 + 2386);
                  if ( (unsigned int)nla_put(a3, 206, 1, v104) )
                    goto LABEL_8;
                }
                if ( (*(_BYTE *)(a1 + 1096) & 0x80) != 0 && (unsigned int)nla_put(a3, 216, 0, 0) )
                  goto LABEL_8;
                if ( *(_BYTE *)(a1 + 1129) )
                {
                  LODWORD(v104[0]) = *(unsigned __int8 *)(a1 + 1129);
                  if ( (unsigned int)nla_put(a3, 256, 4, v104) )
                    goto LABEL_8;
                }
                if ( (unsigned int)nla_put(a3, 217, 9, a1 + 1104) )
                  goto LABEL_8;
                v58 = *(_DWORD *)(a1 + 2388);
                if ( !v58 )
                  goto LABEL_269;
                v59 = *(_QWORD *)(a3 + 216);
                v60 = *(unsigned int *)(a3 + 208);
                if ( (nla_put(a3, 227, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_8;
                v61 = (_WORD *)(v59 + v60);
                if ( !v61 )
                  goto LABEL_8;
                v62 = 0;
                while ( (v58 & 1) == 0 || !(unsigned int)nla_put(a3, v62, 0, 0) )
                {
                  v81 = v58 > 1;
                  ++v62;
                  v58 >>= 1;
                  if ( !v81 )
                  {
LABEL_201:
                    *v61 = *(_WORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v61;
                    goto LABEL_269;
                  }
                }
                goto LABEL_8;
              case 0xDLL:
                if ( !*(_DWORD *)(a1 + 1304) || !*(_QWORD *)(a1 + 1296) )
                  goto LABEL_182;
                v71 = *(_QWORD *)(a3 + 216);
                v72 = *(unsigned int *)(a3 + 208);
                if ( (nla_put(a3, 230, 0, 0) & 0x80000000) != 0 )
                  goto LABEL_8;
                v73 = (_WORD *)(v71 + v72);
                if ( !v73 )
                  goto LABEL_8;
                v74 = *(_DWORD *)(a7 + 40);
                if ( *(_DWORD *)(a1 + 1304) <= v74 )
                  goto LABEL_167;
                break;
              case 0xELL:
                if ( (unsigned int)nl80211_send_pmsr_capa(a1, a3) )
                  goto LABEL_8;
                goto LABEL_269;
              case 0xFLL:
                v70 = *(_QWORD *)(a1 + 1168);
                if ( v70 && (unsigned int)nla_put(a3, 76, (unsigned int)(4 * *(_DWORD *)(a1 + 1160)), v70)
                  || (unsigned int)nl80211_put_iftype_akm_suites(a1, a3)
                  || (unsigned int)nl80211_put_tid_config_support(a1, a3) )
                {
                  goto LABEL_8;
                }
                goto LABEL_269;
              case 0x10LL:
                if ( (unsigned int)nl80211_put_sar_specs(a1, a3) )
                  goto LABEL_8;
                if ( (unsigned int)nl80211_put_mbssid_support(a1 + 992, a3) )
                  goto LABEL_8;
                LOWORD(v104[0]) = *(_WORD *)(a1 + 2482);
                if ( (unsigned int)nla_put(a3, 316, 2, v104) )
                  goto LABEL_8;
                if ( (*(_BYTE *)(a1 + 1092) & 2) != 0 )
                  nla_put(a3, 315, 0, 0);
                if ( !*(_WORD *)(a1 + 2484) )
                  goto LABEL_269;
                LOWORD(v104[0]) = *(_WORD *)(a1 + 2484);
                v48 = (char *)v104;
                v49 = a3;
                v50 = 323;
                v51 = 2;
                goto LABEL_174;
              case 0x11LL:
                if ( (unsigned int)nl80211_put_radios(a1 + 992, a3) )
                  goto LABEL_8;
                goto LABEL_151;
              default:
                goto LABEL_270;
            }
            while ( 1 )
            {
              v75 = *(_QWORD *)(a1 + 1296);
              v76 = *(_QWORD *)(a3 + 216);
              v77 = *(unsigned int *)(a3 + 208);
              if ( (nla_put(a3, v74, 0, 0) & 0x80000000) != 0 )
                break;
              v78 = (_WORD *)(v76 + v77);
              if ( !v78 )
                break;
              v79 = v75 + 32LL * (int)v74;
              LODWORD(v104[0]) = *(_DWORD *)v79;
              if ( (unsigned int)nla_put(a3, 5, 4, v104) )
                break;
              if ( (unsigned int)nla_put(a3, 169, *(unsigned __int8 *)(v79 + 24), *(_QWORD *)(v79 + 8)) )
                break;
              if ( (unsigned int)nla_put(a3, 170, *(unsigned __int8 *)(v79 + 24), *(_QWORD *)(v79 + 16)) )
                break;
              if ( (*(_BYTE *)(a1 + 1092) & 2) != 0 )
              {
                LOWORD(v104[0]) = *(_WORD *)(v79 + 26);
                if ( (unsigned int)nla_put(a3, 317, 2, v104) )
                  break;
                LOWORD(v104[0]) = *(_WORD *)(v79 + 28);
                if ( (unsigned int)nla_put(a3, 318, 2, v104) )
                  break;
              }
              *v78 = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v78;
              if ( (*(_BYTE *)(a7 + 48) & 1) == 0 && ++v74 < *(_DWORD *)(a1 + 1304) )
                continue;
LABEL_167:
              *v73 = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v73;
              if ( v74 < *(_DWORD *)(a1 + 1304) )
              {
                *(_QWORD *)(a7 + 40) = (int)(v74 + 1);
                goto LABEL_270;
              }
LABEL_182:
              LODWORD(v104[0]) = *(unsigned __int8 *)(a1 + 2392);
              if ( !(unsigned int)nla_put(a3, 239, 4, v104) )
              {
                if ( (*(_BYTE *)(a1 + 1107) & 0x10) == 0 )
                  goto LABEL_269;
                memset(v104, 0, sizeof(v104));
                if ( (unsigned int)rdev_get_txq_stats(a1, 0, v104) || (nl80211_put_txq_stats(a3, v104, 265) & 1) != 0 )
                {
                  HIDWORD(v105[0]) = *(_DWORD *)(a1 + 2396);
                  if ( !(unsigned int)nla_put(a3, 266, 4, (char *)v105 + 4) )
                  {
                    HIDWORD(v105[0]) = *(_DWORD *)(a1 + 2400);
                    if ( !(unsigned int)nla_put(a3, 267, 4, (char *)v105 + 4) )
                    {
                      v48 = (char *)v105 + 4;
                      v49 = a3;
                      v50 = 268;
                      HIDWORD(v105[0]) = *(_DWORD *)(a1 + 2404);
LABEL_173:
                      v51 = 4;
LABEL_174:
                      if ( !(unsigned int)nla_put(v49, v50, v51, v48) )
                      {
LABEL_269:
                        ++*(_QWORD *)(a7 + 16);
                        goto LABEL_270;
                      }
                    }
                  }
                }
              }
              break;
            }
          }
        }
      }
LABEL_8:
      v16 = v13 - 20;
      if ( v13 != 20 )
      {
        v17 = *(_QWORD *)(a3 + 224);
        if ( v17 > v16 )
        {
          __break(0x800u);
          v17 = *(_QWORD *)(a3 + 224);
        }
        skb_trim(a3, (unsigned int)(v16 - v17));
      }
      result = 4294967206LL;
    }
    else
    {
      __break(0x800u);
      result = 4294967274LL;
    }
  }
  else
  {
    result = 4294967191LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
