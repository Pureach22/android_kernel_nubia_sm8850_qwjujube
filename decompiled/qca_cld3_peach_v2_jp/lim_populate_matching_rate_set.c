__int64 __fastcall lim_populate_matching_rate_set(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        _BYTE *a4,
        _BYTE *a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  size_t v8; // x28
  int *v12; // x8
  size_t v13; // x2
  int v17; // w24
  unsigned __int64 v19; // x25
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w9
  size_t v29; // x8
  __int64 v30; // x11
  int v31; // w10
  unsigned int v32; // w13
  __int64 v33; // x10
  int v34; // w9
  unsigned int v35; // w13
  char v36; // w21
  const char *v37; // x2
  size_t v38; // x2
  __int64 v39; // x11
  unsigned int v40; // w6
  unsigned int v41; // w21
  unsigned int v42; // w7
  unsigned int v43; // w21
  bool v44; // cc
  unsigned int v45; // w21
  bool v46; // cc
  unsigned int v47; // w21
  bool v48; // cc
  unsigned int v49; // w21
  bool v50; // cc
  unsigned int v51; // w21
  bool v52; // cc
  unsigned int v53; // w21
  bool v54; // cc
  unsigned int v55; // w21
  bool v56; // cc
  unsigned int v57; // w21
  bool v58; // cc
  unsigned int v59; // w21
  bool v60; // cc
  char v61; // w7
  unsigned int v62; // w21
  __int64 v63; // x4
  unsigned int v64; // w9
  unsigned int v65; // w10
  __int64 v66; // x10
  __int64 v67; // x9
  unsigned __int8 v68; // w12
  char v69; // w13
  size_t v70; // x14
  unsigned __int8 *v71; // x15
  unsigned __int8 v72; // t1
  unsigned __int8 v73; // w14
  char *v74; // x10
  unsigned __int64 v75; // x11
  __int64 v76; // x12
  __int64 v77; // x14
  char v78; // t1
  char *v79; // x16
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  int v88; // w12
  __int64 v89; // x13
  __int64 v90; // x8
  unsigned int v91; // w9
  unsigned int v92; // w10
  int v93; // w11
  __int64 v94; // x15
  __int16 v95; // w1
  __int64 v96; // x3
  char *v97; // x4
  int v98; // w2
  char v99; // t1
  unsigned int v100; // w3
  __int64 v101; // x9
  __int64 result; // x0
  unsigned int v103; // w8
  int v104; // w8
  _BYTE *v105; // [xsp+0h] [xbp-50h]
  __int64 v106; // [xsp+8h] [xbp-48h]
  size_t v107; // [xsp+10h] [xbp-40h] BYREF
  __int64 v108; // [xsp+18h] [xbp-38h] BYREF
  __int64 v109; // [xsp+20h] [xbp-30h]
  _BYTE v110[16]; // [xsp+28h] [xbp-28h] BYREF
  _QWORD v111[3]; // [xsp+38h] [xbp-18h] BYREF

  v105 = a5;
  v111[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = (int *)(a6 + 7232);
  v13 = *(unsigned __int8 *)(a6 + 252);
  if ( !a6 )
    v12 = (int *)(a1 + 4840);
  v17 = *v12;
  v19 = (unsigned __int64)v111 + 1;
  memset(v111, 0, 13);
  v109 = 0;
  memset(v110, 0, 13);
  v107 = 0;
  v108 = 0;
  qdf_mem_copy((char *)v111 + 1, (const void *)(a6 + 253), v13);
  v28 = *(unsigned __int8 *)(a6 + 252);
  LOBYTE(v111[0]) = *(_BYTE *)(a6 + 252);
  if ( v17 == 2 )
  {
    qdf_mem_copy(&v110[1], (const void *)(a6 + 266), *(unsigned __int8 *)(a6 + 265));
    LODWORD(v29) = *(unsigned __int8 *)(a6 + 265);
    v28 = LOBYTE(v111[0]);
    v110[0] = *(_BYTE *)(a6 + 265);
    if ( LOBYTE(v111[0]) )
      goto LABEL_5;
LABEL_15:
    LOBYTE(v31) = 0;
    goto LABEL_16;
  }
  LODWORD(v29) = 0;
  if ( !v28 )
    goto LABEL_15;
LABEL_5:
  v30 = 0;
  v31 = 0;
  do
  {
    if ( v30 == 12 )
      goto LABEL_25;
    if ( *((unsigned __int8 *)v111 + v30 + 1) > 0xF9u )
      ++v31;
    v32 = v30 + v31;
    if ( (int)v30 + v31 < v28 )
    {
      if ( v32 > 0xB )
        goto LABEL_25;
      *((_BYTE *)v111 + v30 + 1) = *((_BYTE *)v111 + v32 + 1);
    }
    ++v30;
  }
  while ( v28 != v30 );
LABEL_16:
  LOBYTE(v8) = v28 - v31;
  v106 = a7;
  LOBYTE(v111[0]) = v28 - v31;
  if ( !(_DWORD)v29 )
    goto LABEL_26;
  v33 = 0;
  v34 = 0;
  while ( v33 != 12 )
  {
    if ( (unsigned __int8)v110[v33 + 1] > 0xF9u )
      ++v34;
    v35 = v33 + v34;
    if ( (int)v33 + v34 < (int)v29 )
    {
      if ( v35 > 0xB )
        goto LABEL_25;
      v110[v33 + 1] = v110[v35 + 1];
    }
    if ( (unsigned int)v29 == ++v33 )
      goto LABEL_27;
  }
  while ( 1 )
  {
    while ( 1 )
    {
LABEL_25:
      __break(0x5512u);
LABEL_26:
      LOBYTE(v34) = 0;
LABEL_27:
      v36 = v29 - v34;
      v110[0] = v29 - v34;
      if ( (unsigned __int8)(v29 - v34) + (unsigned int)(unsigned __int8)v8 > 0xC )
      {
        v37 = "%s: more than 12 rates in CFG";
LABEL_151:
        qdf_trace_msg(
          0x35u,
          2u,
          v37,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "lim_populate_matching_rate_set",
          v105,
          v106,
          v107);
        result = 16;
        goto LABEL_178;
      }
      if ( (_DWORD)v29 != (unsigned __int8)v34 )
      {
        if ( (((_BYTE)v29 - (_BYTE)v34) & 0xFE) != 0 )
          v38 = (unsigned __int8)(v29 - v34);
        else
          v38 = 1;
        memcpy((char *)v111 + (unsigned __int8)v8 + 1, &v110[1], v38);
      }
      v110[0] = 0;
      LOBYTE(v111[0]) = v36 + v8;
      LODWORD(v29) = (unsigned __int8)(v36 + v8);
      if ( !(v36 + (_BYTE)v8) )
        break;
      v39 = 1;
      while ( (unsigned int)(v29 - 13) >= 0xFFFFFFF4 )
      {
        if ( (_DWORD)v29 == 1 )
        {
          v40 = 0;
        }
        else
        {
          v41 = BYTE1(v111[0]) & 0x7F;
          v42 = BYTE2(v111[0]) & 0x7F;
          v40 = v41 > v42;
          if ( v41 < v42 )
            v42 = BYTE1(v111[0]) & 0x7F;
          if ( (_DWORD)v29 != 2 )
          {
            v43 = BYTE3(v111[0]) & 0x7F;
            v44 = v42 > v43;
            if ( v42 >= v43 )
              v42 = BYTE3(v111[0]) & 0x7F;
            if ( v44 )
              v40 = 2;
            if ( (_DWORD)v29 != 3 )
            {
              v45 = BYTE4(v111[0]) & 0x7F;
              v46 = v42 > v45;
              if ( v42 >= v45 )
                v42 = BYTE4(v111[0]) & 0x7F;
              if ( v46 )
                v40 = 3;
              if ( (_DWORD)v29 != 4 )
              {
                v47 = BYTE5(v111[0]) & 0x7F;
                v48 = v42 > v47;
                if ( v42 >= v47 )
                  v42 = BYTE5(v111[0]) & 0x7F;
                if ( v48 )
                  v40 = 4;
                if ( (_DWORD)v29 != 5 )
                {
                  v49 = BYTE6(v111[0]) & 0x7F;
                  v50 = v42 > v49;
                  if ( v42 >= v49 )
                    v42 = BYTE6(v111[0]) & 0x7F;
                  if ( v50 )
                    v40 = 5;
                  if ( (_DWORD)v29 != 6 )
                  {
                    v51 = HIBYTE(v111[0]) & 0x7F;
                    v52 = v42 > v51;
                    if ( v42 >= v51 )
                      v42 = HIBYTE(v111[0]) & 0x7F;
                    if ( v52 )
                      v40 = 6;
                    if ( (_DWORD)v29 != 7 )
                    {
                      v53 = v111[1] & 0x7F;
                      v54 = v42 > v53;
                      if ( v42 >= v53 )
                        v42 = v111[1] & 0x7F;
                      if ( v54 )
                        v40 = 7;
                      if ( (_DWORD)v29 != 8 )
                      {
                        v55 = BYTE1(v111[1]) & 0x7F;
                        v56 = v42 > v55;
                        if ( v42 >= v55 )
                          v42 = BYTE1(v111[1]) & 0x7F;
                        if ( v56 )
                          v40 = 8;
                        if ( (_DWORD)v29 != 9 )
                        {
                          v57 = BYTE2(v111[1]) & 0x7F;
                          v58 = v42 > v57;
                          if ( v42 >= v57 )
                            v42 = BYTE2(v111[1]) & 0x7F;
                          if ( v58 )
                            v40 = 9;
                          if ( (_DWORD)v29 != 10 )
                          {
                            v59 = BYTE3(v111[1]) & 0x7F;
                            v60 = v42 > v59;
                            if ( v42 >= v59 )
                              v42 = BYTE3(v111[1]) & 0x7F;
                            if ( v60 )
                              v40 = 10;
                            if ( (_DWORD)v29 != 11 && v42 > (BYTE4(v111[1]) & 0x7Fu) )
                              v40 = 11;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        v61 = *(_BYTE *)(v19 + v40);
        v110[0] = v39;
        if ( (_DWORD)v39 == 13 )
          break;
        if ( v39 == 13 )
LABEL_179:
          __break(1u);
        v110[v39++] = v61;
        *(_BYTE *)(v19 + v40) = -1;
        if ( (_DWORD)v39 - (_DWORD)v29 == 1 )
          goto LABEL_92;
      }
    }
LABEL_92:
    v62 = *(unsigned __int8 *)a3;
    if ( v62 >= 0xC )
      v8 = 12;
    else
      v8 = *(unsigned __int8 *)a3;
    if ( *(_BYTE *)a3 )
    {
      memcpy((void *)v19, (const void *)(a3 + 1), v8);
      a3 = (unsigned int)v8;
    }
    else
    {
      a3 = 0;
    }
    v63 = (unsigned __int8)*a4 + v62;
    LOBYTE(v111[0]) = v62;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sum of SUPPORTED and EXTENDED Rate Set (%1d)",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "lim_populate_matching_rate_set",
      v63,
      v105);
    v64 = (unsigned __int8)*a4;
    if ( *a4 )
    {
      v29 = LOBYTE(v111[0]);
      v65 = LOBYTE(v111[0]) + v64;
      if ( LOBYTE(v111[0]) <= 0xBuLL && v65 >= 0xD )
      {
        v66 = 0;
        if ( v64 >= 0xC )
          v67 = 12;
        else
          v67 = (unsigned __int8)*a4;
        v68 = v111[0];
        while ( 1 )
        {
          v69 = a4[v66 + 1];
          v70 = v29;
          v71 = (unsigned __int8 *)v19;
          if ( (_DWORD)v29 )
          {
            while ( 1 )
            {
              v72 = *v71++;
              if ( (((unsigned __int8)v69 ^ v72) & 0x7F) == 0 )
                break;
              if ( !--v70 )
                goto LABEL_109;
            }
          }
          else
          {
LABEL_109:
            v73 = v68 + 1;
            LOBYTE(v111[0]) = v68 + 1;
            if ( v68 > 0xBu )
              goto LABEL_25;
            *(_BYTE *)(v19 + v68++) = v69;
            if ( v73 > 0xBu )
              goto LABEL_119;
          }
          if ( ++v66 == v67 )
            goto LABEL_119;
        }
      }
      if ( v65 > 0xC )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Relying only on the SUPPORTED Rate Set IE",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "lim_populate_matching_rate_set");
      }
      else
      {
        v74 = a4 + 1;
        v75 = (unsigned int)a3;
        v76 = (unsigned int)(12 - v8);
        v77 = (unsigned __int8)*a4;
        do
        {
          if ( !v76 )
            break;
          if ( v75 > 0xB )
            goto LABEL_179;
          v78 = *v74++;
          v79 = (char *)v111 + v75;
          --v77;
          --v76;
          ++v75;
          v79[1] = v78;
        }
        while ( v77 );
        LOBYTE(v111[0]) = v29 + v64;
      }
    }
LABEL_119:
    a4 = (_BYTE *)(a2 + 264);
    qdf_mem_set((void *)(a2 + 264), 0x3Eu, 0);
    if ( v110[0] )
      break;
    v19 = 0;
    if ( (*(_BYTE *)(a2 + 32) & 8) == 0 )
      goto LABEL_173;
LABEL_149:
    v101 = *(_QWORD *)(a1 + 8);
    v107 = 16;
    if ( (unsigned int)wlan_mlme_get_cfg_str(&v108, v101 + 2856, &v107, v80, v81, v82, v83, v84, v85, v86, v87) )
    {
      v37 = "%s: could not retrieve supportedMCSet";
      goto LABEL_151;
    }
    v103 = *(unsigned __int8 *)(a6 + 8635);
    if ( v103 <= 1 )
    {
      *((_BYTE *)&v108 + *(unsigned __int8 *)(a6 + 8635)) = 0;
      if ( !v103 )
        BYTE1(v108) = 0;
    }
    wlan_ll_lt_sap_get_mcs(*(_QWORD *)(a1 + 21552), *(unsigned __int8 *)(a6 + 10), &v108);
    v29 = v107;
    if ( v107 )
    {
      *(_BYTE *)(a2 + 288) = *v105 & v108;
      if ( v29 != 1 )
      {
        *(_BYTE *)(a2 + 289) = v105[1] & BYTE1(v108);
        if ( v29 != 2 )
        {
          *(_BYTE *)(a2 + 290) = v105[2] & BYTE2(v108);
          if ( v29 != 3 )
          {
            *(_BYTE *)(a2 + 291) = v105[3] & BYTE3(v108);
            if ( v29 != 4 )
            {
              *(_BYTE *)(a2 + 292) = v105[4] & BYTE4(v108);
              if ( v29 != 5 )
              {
                *(_BYTE *)(a2 + 293) = v105[5] & BYTE5(v108);
                if ( v29 != 6 )
                {
                  *(_BYTE *)(a2 + 294) = v105[6] & BYTE6(v108);
                  if ( v29 != 7 )
                  {
                    *(_BYTE *)(a2 + 295) = v105[7] & HIBYTE(v108);
                    if ( v29 != 8 )
                    {
                      *(_BYTE *)(a2 + 296) = v105[8] & v109;
                      if ( v29 != 9 )
                      {
                        *(_BYTE *)(a2 + 297) = v105[9] & BYTE1(v109);
                        if ( v29 != 10 )
                        {
                          *(_BYTE *)(a2 + 298) = v105[10] & BYTE2(v109);
                          if ( v29 != 11 )
                          {
                            *(_BYTE *)(a2 + 299) = v105[11] & BYTE3(v109);
                            if ( v29 != 12 )
                            {
                              *(_BYTE *)(a2 + 300) = v105[12] & BYTE4(v109);
                              if ( v29 != 13 )
                              {
                                *(_BYTE *)(a2 + 301) = v105[13] & BYTE5(v109);
                                if ( v29 != 14 )
                                {
                                  *(_BYTE *)(a2 + 302) = v105[14] & BYTE6(v109);
                                  if ( v29 != 15 )
                                  {
                                    *(_BYTE *)(a2 + 303) = v105[15] & HIBYTE(v109);
                                    if ( v29 != 16 )
                                      continue;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    lim_dump_ht_mcs_mask((unsigned __int8 *)&v108, (unsigned __int8 *)(a2 + 288));
    goto LABEL_173;
  }
  v88 = LOBYTE(v111[0]);
  if ( v110[0] >= 0xCu )
    v89 = 12;
  else
    v89 = v110[0];
  v90 = 0;
  v91 = 0;
  v92 = 0;
  v93 = 0;
  if ( LOBYTE(v111[0]) >= 0xCu )
    v94 = 12;
  else
    v94 = LOBYTE(v111[0]);
  do
  {
    if ( v88 )
    {
      v95 = (unsigned __int8)v110[v90 + 1];
      v96 = v94;
      v97 = (char *)v19;
      v98 = v95 & 0x7F;
      while ( 1 )
      {
        v99 = *v97++;
        if ( v98 == (v99 & 0x7F) )
          break;
        if ( !--v96 )
          goto LABEL_127;
      }
      v100 = v98 - 12;
      if ( (unsigned int)(v98 - 12) <= 0x3C && ((1LL << v100) & 0x1000001001001041LL) != 0 || v98 == 96 )
      {
        if ( v92 <= 7 )
          goto LABEL_126;
      }
      else if ( v98 == 108 && v92 < 8 )
      {
LABEL_126:
        *(_WORD *)(a2 + 272 + 2LL * v92) = v95;
        v93 = 1;
        ++v92;
        goto LABEL_127;
      }
      if ( v91 <= 3 && (v100 > 0x3C || ((1LL << v100) & 0x1000001001001041LL) == 0) && v98 != 96 && v98 != 108 )
        *(_WORD *)&a4[2 * v91++] = v95;
    }
LABEL_127:
    ++v90;
  }
  while ( v90 != v89 );
  v19 = v93 != 0;
  if ( (*(_BYTE *)(a2 + 32) & 8) != 0 )
    goto LABEL_149;
LABEL_173:
  lim_populate_vht_mcs_set(a1, (_WORD *)(a2 + 264), v106, a6, *(_BYTE *)(a6 + 8635), a2);
  lim_populate_he_mcs_set(a1, a2 + 264, a8, a6, *(unsigned __int8 *)(a6 + 8635));
  wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a6 + 284));
  if ( v17 == 2 )
    v104 = v19;
  else
    v104 = 0;
  result = 0;
  if ( v104 == 1 )
    *(_WORD *)a2 |= 4u;
LABEL_178:
  _ReadStatusReg(SP_EL0);
  return result;
}
