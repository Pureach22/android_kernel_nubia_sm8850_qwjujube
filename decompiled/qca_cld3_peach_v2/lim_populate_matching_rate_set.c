__int64 __fastcall lim_populate_matching_rate_set(
        __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        _BYTE *a4,
        _BYTE *a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  size_t v9; // x28
  int *v13; // x8
  size_t v14; // x2
  int v18; // w23
  unsigned __int64 v20; // x25
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w9
  size_t v30; // x8
  __int64 v31; // x11
  int v32; // w10
  unsigned int v33; // w13
  __int64 v34; // x10
  int v35; // w9
  unsigned int v36; // w13
  char v37; // w24
  const char *v38; // x2
  size_t v39; // x2
  __int64 v40; // x11
  unsigned int v41; // w6
  unsigned int v42; // w24
  unsigned int v43; // w7
  unsigned int v44; // w24
  bool v45; // cc
  unsigned int v46; // w24
  bool v47; // cc
  unsigned int v48; // w24
  bool v49; // cc
  unsigned int v50; // w24
  bool v51; // cc
  unsigned int v52; // w24
  bool v53; // cc
  unsigned int v54; // w24
  bool v55; // cc
  unsigned int v56; // w24
  bool v57; // cc
  unsigned int v58; // w24
  bool v59; // cc
  unsigned int v60; // w24
  bool v61; // cc
  char v62; // w7
  unsigned int v63; // w24
  __int64 v64; // x4
  unsigned int v65; // w9
  unsigned int v66; // w10
  __int64 v67; // x10
  __int64 v68; // x9
  unsigned __int8 v69; // w12
  char v70; // w13
  size_t v71; // x14
  unsigned __int8 *v72; // x15
  unsigned __int8 v73; // t1
  unsigned __int8 v74; // w14
  char *v75; // x10
  unsigned __int64 v76; // x11
  __int64 v77; // x12
  __int64 v78; // x14
  char v79; // t1
  char *v80; // x16
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  int v89; // w12
  __int64 v90; // x13
  __int64 v91; // x8
  unsigned int v92; // w9
  unsigned int v93; // w10
  int v94; // w11
  __int64 v95; // x15
  __int16 v96; // w1
  __int64 v97; // x3
  char *v98; // x4
  int v99; // w2
  char v100; // t1
  unsigned int v101; // w3
  __int64 v102; // x9
  __int64 result; // x0
  unsigned int v104; // w8
  unsigned int v105; // w22
  bool is_24ghz_ch_freq; // w0
  int v107; // w8
  _BYTE *v108; // [xsp+0h] [xbp-50h]
  __int64 v109; // [xsp+8h] [xbp-48h]
  size_t v110; // [xsp+10h] [xbp-40h] BYREF
  __int64 v111; // [xsp+18h] [xbp-38h] BYREF
  __int64 v112; // [xsp+20h] [xbp-30h]
  _BYTE v113[16]; // [xsp+28h] [xbp-28h] BYREF
  _QWORD v114[3]; // [xsp+38h] [xbp-18h] BYREF

  v108 = a5;
  v114[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = (int *)(a6 + 7232);
  v14 = *(unsigned __int8 *)(a6 + 252);
  if ( !a6 )
    v13 = (int *)(a1 + 4840);
  v18 = *v13;
  v20 = (unsigned __int64)v114 + 1;
  memset(v114, 0, 13);
  v112 = 0;
  memset(v113, 0, 13);
  v110 = 0;
  v111 = 0;
  qdf_mem_copy((char *)v114 + 1, (const void *)(a6 + 253), v14);
  v29 = *(unsigned __int8 *)(a6 + 252);
  LOBYTE(v114[0]) = *(_BYTE *)(a6 + 252);
  if ( v18 == 2 )
  {
    qdf_mem_copy(&v113[1], (const void *)(a6 + 266), *(unsigned __int8 *)(a6 + 265));
    LODWORD(v30) = *(unsigned __int8 *)(a6 + 265);
    v29 = LOBYTE(v114[0]);
    v113[0] = *(_BYTE *)(a6 + 265);
    if ( LOBYTE(v114[0]) )
      goto LABEL_5;
LABEL_15:
    LOBYTE(v32) = 0;
    goto LABEL_16;
  }
  LODWORD(v30) = 0;
  if ( !v29 )
    goto LABEL_15;
LABEL_5:
  v31 = 0;
  v32 = 0;
  do
  {
    if ( v31 == 12 )
      goto LABEL_25;
    if ( *((unsigned __int8 *)v114 + v31 + 1) > 0xF9u )
      ++v32;
    v33 = v31 + v32;
    if ( (int)v31 + v32 < v29 )
    {
      if ( v33 > 0xB )
        goto LABEL_25;
      *((_BYTE *)v114 + v31 + 1) = *((_BYTE *)v114 + v33 + 1);
    }
    ++v31;
  }
  while ( v29 != v31 );
LABEL_16:
  LOBYTE(v9) = v29 - v32;
  v109 = a7;
  LOBYTE(v114[0]) = v29 - v32;
  if ( !(_DWORD)v30 )
    goto LABEL_26;
  v34 = 0;
  v35 = 0;
  while ( v34 != 12 )
  {
    if ( (unsigned __int8)v113[v34 + 1] > 0xF9u )
      ++v35;
    v36 = v34 + v35;
    if ( (int)v34 + v35 < (int)v30 )
    {
      if ( v36 > 0xB )
        goto LABEL_25;
      v113[v34 + 1] = v113[v36 + 1];
    }
    if ( (unsigned int)v30 == ++v34 )
      goto LABEL_27;
  }
  while ( 1 )
  {
    while ( 1 )
    {
LABEL_25:
      __break(0x5512u);
LABEL_26:
      LOBYTE(v35) = 0;
LABEL_27:
      v37 = v30 - v35;
      v113[0] = v30 - v35;
      if ( (unsigned __int8)(v30 - v35) + (unsigned int)(unsigned __int8)v9 > 0xC )
      {
        v38 = "%s: more than 12 rates in CFG";
LABEL_151:
        qdf_trace_msg(
          0x35u,
          2u,
          v38,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "lim_populate_matching_rate_set",
          v108,
          v109,
          v110);
        result = 16;
        goto LABEL_178;
      }
      if ( (_DWORD)v30 != (unsigned __int8)v35 )
      {
        if ( (((_BYTE)v30 - (_BYTE)v35) & 0xFE) != 0 )
          v39 = (unsigned __int8)(v30 - v35);
        else
          v39 = 1;
        memcpy((char *)v114 + (unsigned __int8)v9 + 1, &v113[1], v39);
      }
      v113[0] = 0;
      LOBYTE(v114[0]) = v37 + v9;
      LODWORD(v30) = (unsigned __int8)(v37 + v9);
      if ( !(v37 + (_BYTE)v9) )
        break;
      v40 = 1;
      while ( (unsigned int)(v30 - 13) >= 0xFFFFFFF4 )
      {
        if ( (_DWORD)v30 == 1 )
        {
          v41 = 0;
        }
        else
        {
          v42 = BYTE1(v114[0]) & 0x7F;
          v43 = BYTE2(v114[0]) & 0x7F;
          v41 = v42 > v43;
          if ( v42 < v43 )
            v43 = BYTE1(v114[0]) & 0x7F;
          if ( (_DWORD)v30 != 2 )
          {
            v44 = BYTE3(v114[0]) & 0x7F;
            v45 = v43 > v44;
            if ( v43 >= v44 )
              v43 = BYTE3(v114[0]) & 0x7F;
            if ( v45 )
              v41 = 2;
            if ( (_DWORD)v30 != 3 )
            {
              v46 = BYTE4(v114[0]) & 0x7F;
              v47 = v43 > v46;
              if ( v43 >= v46 )
                v43 = BYTE4(v114[0]) & 0x7F;
              if ( v47 )
                v41 = 3;
              if ( (_DWORD)v30 != 4 )
              {
                v48 = BYTE5(v114[0]) & 0x7F;
                v49 = v43 > v48;
                if ( v43 >= v48 )
                  v43 = BYTE5(v114[0]) & 0x7F;
                if ( v49 )
                  v41 = 4;
                if ( (_DWORD)v30 != 5 )
                {
                  v50 = BYTE6(v114[0]) & 0x7F;
                  v51 = v43 > v50;
                  if ( v43 >= v50 )
                    v43 = BYTE6(v114[0]) & 0x7F;
                  if ( v51 )
                    v41 = 5;
                  if ( (_DWORD)v30 != 6 )
                  {
                    v52 = HIBYTE(v114[0]) & 0x7F;
                    v53 = v43 > v52;
                    if ( v43 >= v52 )
                      v43 = HIBYTE(v114[0]) & 0x7F;
                    if ( v53 )
                      v41 = 6;
                    if ( (_DWORD)v30 != 7 )
                    {
                      v54 = v114[1] & 0x7F;
                      v55 = v43 > v54;
                      if ( v43 >= v54 )
                        v43 = v114[1] & 0x7F;
                      if ( v55 )
                        v41 = 7;
                      if ( (_DWORD)v30 != 8 )
                      {
                        v56 = BYTE1(v114[1]) & 0x7F;
                        v57 = v43 > v56;
                        if ( v43 >= v56 )
                          v43 = BYTE1(v114[1]) & 0x7F;
                        if ( v57 )
                          v41 = 8;
                        if ( (_DWORD)v30 != 9 )
                        {
                          v58 = BYTE2(v114[1]) & 0x7F;
                          v59 = v43 > v58;
                          if ( v43 >= v58 )
                            v43 = BYTE2(v114[1]) & 0x7F;
                          if ( v59 )
                            v41 = 9;
                          if ( (_DWORD)v30 != 10 )
                          {
                            v60 = BYTE3(v114[1]) & 0x7F;
                            v61 = v43 > v60;
                            if ( v43 >= v60 )
                              v43 = BYTE3(v114[1]) & 0x7F;
                            if ( v61 )
                              v41 = 10;
                            if ( (_DWORD)v30 != 11 && v43 > (BYTE4(v114[1]) & 0x7Fu) )
                              v41 = 11;
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
        v62 = *(_BYTE *)(v20 + v41);
        v113[0] = v40;
        if ( (_DWORD)v40 == 13 )
          break;
        if ( v40 == 13 )
LABEL_179:
          __break(1u);
        v113[v40++] = v62;
        *(_BYTE *)(v20 + v41) = -1;
        if ( (_DWORD)v40 - (_DWORD)v30 == 1 )
          goto LABEL_92;
      }
    }
LABEL_92:
    v63 = *(unsigned __int8 *)a3;
    if ( v63 >= 0xC )
      v9 = 12;
    else
      v9 = *(unsigned __int8 *)a3;
    if ( *(_BYTE *)a3 )
    {
      memcpy((void *)v20, (const void *)(a3 + 1), v9);
      a3 = (unsigned int)v9;
    }
    else
    {
      a3 = 0;
    }
    v64 = (unsigned __int8)*a4 + v63;
    LOBYTE(v114[0]) = v63;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sum of SUPPORTED and EXTENDED Rate Set (%1d)",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_populate_matching_rate_set",
      v64,
      v108);
    v65 = (unsigned __int8)*a4;
    if ( *a4 )
    {
      v30 = LOBYTE(v114[0]);
      v66 = LOBYTE(v114[0]) + v65;
      if ( LOBYTE(v114[0]) <= 0xBuLL && v66 >= 0xD )
      {
        v67 = 0;
        if ( v65 >= 0xC )
          v68 = 12;
        else
          v68 = (unsigned __int8)*a4;
        v69 = v114[0];
        while ( 1 )
        {
          v70 = a4[v67 + 1];
          v71 = v30;
          v72 = (unsigned __int8 *)v20;
          if ( (_DWORD)v30 )
          {
            while ( 1 )
            {
              v73 = *v72++;
              if ( (((unsigned __int8)v70 ^ v73) & 0x7F) == 0 )
                break;
              if ( !--v71 )
                goto LABEL_109;
            }
          }
          else
          {
LABEL_109:
            v74 = v69 + 1;
            LOBYTE(v114[0]) = v69 + 1;
            if ( v69 > 0xBu )
              goto LABEL_25;
            *(_BYTE *)(v20 + v69++) = v70;
            if ( v74 > 0xBu )
              goto LABEL_119;
          }
          if ( ++v67 == v68 )
            goto LABEL_119;
        }
      }
      if ( v66 > 0xC )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Relying only on the SUPPORTED Rate Set IE",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "lim_populate_matching_rate_set");
      }
      else
      {
        v75 = a4 + 1;
        v76 = (unsigned int)a3;
        v77 = (unsigned int)(12 - v9);
        v78 = (unsigned __int8)*a4;
        do
        {
          if ( !v77 )
            break;
          if ( v76 > 0xB )
            goto LABEL_179;
          v79 = *v75++;
          v80 = (char *)v114 + v76;
          --v78;
          --v77;
          ++v76;
          v80[1] = v79;
        }
        while ( v78 );
        LOBYTE(v114[0]) = v30 + v65;
      }
    }
LABEL_119:
    a4 = (_BYTE *)(a2 + 264);
    qdf_mem_set((void *)(a2 + 264), 0x4Cu, 0);
    if ( v113[0] )
      break;
    v20 = 0;
    if ( (*(_BYTE *)(a2 + 32) & 8) == 0 )
      goto LABEL_173;
LABEL_149:
    v102 = *(_QWORD *)(a1 + 8);
    v110 = 16;
    if ( (unsigned int)wlan_mlme_get_cfg_str(&v111, v102 + 3056, &v110, v81, v82, v83, v84, v85, v86, v87, v88) )
    {
      v38 = "%s: could not retrieve supportedMCSet";
      goto LABEL_151;
    }
    v104 = *(unsigned __int8 *)(a6 + 8635);
    if ( v104 <= 1 )
    {
      *((_BYTE *)&v111 + *(unsigned __int8 *)(a6 + 8635)) = 0;
      if ( !v104 )
        BYTE1(v111) = 0;
    }
    wlan_ll_lt_sap_get_mcs(*(_QWORD *)(a1 + 21624), *(unsigned __int8 *)(a6 + 10), &v111);
    v30 = v110;
    if ( v110 )
    {
      *(_BYTE *)(a2 + 288) = *v108 & v111;
      if ( v30 != 1 )
      {
        *(_BYTE *)(a2 + 289) = v108[1] & BYTE1(v111);
        if ( v30 != 2 )
        {
          *(_BYTE *)(a2 + 290) = v108[2] & BYTE2(v111);
          if ( v30 != 3 )
          {
            *(_BYTE *)(a2 + 291) = v108[3] & BYTE3(v111);
            if ( v30 != 4 )
            {
              *(_BYTE *)(a2 + 292) = v108[4] & BYTE4(v111);
              if ( v30 != 5 )
              {
                *(_BYTE *)(a2 + 293) = v108[5] & BYTE5(v111);
                if ( v30 != 6 )
                {
                  *(_BYTE *)(a2 + 294) = v108[6] & BYTE6(v111);
                  if ( v30 != 7 )
                  {
                    *(_BYTE *)(a2 + 295) = v108[7] & HIBYTE(v111);
                    if ( v30 != 8 )
                    {
                      *(_BYTE *)(a2 + 296) = v108[8] & v112;
                      if ( v30 != 9 )
                      {
                        *(_BYTE *)(a2 + 297) = v108[9] & BYTE1(v112);
                        if ( v30 != 10 )
                        {
                          *(_BYTE *)(a2 + 298) = v108[10] & BYTE2(v112);
                          if ( v30 != 11 )
                          {
                            *(_BYTE *)(a2 + 299) = v108[11] & BYTE3(v112);
                            if ( v30 != 12 )
                            {
                              *(_BYTE *)(a2 + 300) = v108[12] & BYTE4(v112);
                              if ( v30 != 13 )
                              {
                                *(_BYTE *)(a2 + 301) = v108[13] & BYTE5(v112);
                                if ( v30 != 14 )
                                {
                                  *(_BYTE *)(a2 + 302) = v108[14] & BYTE6(v112);
                                  if ( v30 != 15 )
                                  {
                                    *(_BYTE *)(a2 + 303) = v108[15] & HIBYTE(v112);
                                    if ( v30 != 16 )
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
    lim_dump_ht_mcs_mask((unsigned __int8 *)&v111, (unsigned __int8 *)(a2 + 288));
    goto LABEL_173;
  }
  v89 = LOBYTE(v114[0]);
  if ( v113[0] >= 0xCu )
    v90 = 12;
  else
    v90 = v113[0];
  v91 = 0;
  v92 = 0;
  v93 = 0;
  v94 = 0;
  if ( LOBYTE(v114[0]) >= 0xCu )
    v95 = 12;
  else
    v95 = LOBYTE(v114[0]);
  do
  {
    if ( v89 )
    {
      v96 = (unsigned __int8)v113[v91 + 1];
      v97 = v95;
      v98 = (char *)v20;
      v99 = v96 & 0x7F;
      while ( 1 )
      {
        v100 = *v98++;
        if ( v99 == (v100 & 0x7F) )
          break;
        if ( !--v97 )
          goto LABEL_127;
      }
      v101 = v99 - 12;
      if ( (unsigned int)(v99 - 12) <= 0x3C && ((1LL << v101) & 0x1000001001001041LL) != 0 || v99 == 96 )
      {
        if ( v93 <= 7 )
          goto LABEL_126;
      }
      else if ( v99 == 108 && v93 < 8 )
      {
LABEL_126:
        *(_WORD *)(a2 + 272 + 2LL * v93) = v96;
        v94 = 1;
        ++v93;
        goto LABEL_127;
      }
      if ( v92 <= 3 && (v101 > 0x3C || ((1LL << v101) & 0x1000001001001041LL) == 0) && v99 != 96 && v99 != 108 )
        *(_WORD *)&a4[2 * v92++] = v96;
    }
LABEL_127:
    ++v91;
  }
  while ( v91 != v90 );
  v20 = v94 != 0;
  if ( (*(_BYTE *)(a2 + 32) & 8) != 0 )
    goto LABEL_149;
LABEL_173:
  lim_populate_vht_mcs_set(a1, (_WORD *)(a2 + 264), v109, a6, *(_BYTE *)(a6 + 8635), a2);
  lim_populate_he_mcs_set(a1, a2 + 264, a8, a6, *(unsigned __int8 *)(a6 + 8635));
  v105 = *(_DWORD *)(a2 + 360);
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a6 + 284));
  lim_populate_eht_mcs_set(a1, a2 + 264, a9, a6, v105, is_24ghz_ch_freq);
  if ( v18 == 2 )
    v107 = v20;
  else
    v107 = 0;
  result = 0;
  if ( v107 == 1 )
    *(_WORD *)a2 |= 4u;
LABEL_178:
  _ReadStatusReg(SP_EL0);
  return result;
}
