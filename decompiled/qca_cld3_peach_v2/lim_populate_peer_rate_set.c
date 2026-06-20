__int64 __fastcall lim_populate_peer_rate_set(
        __int64 a1,
        char *a2,
        _BYTE *a3,
        char a4,
        __int64 a5,
        __int64 a6,
        char *a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        __int64 a17,
        __int64 a18)
{
  unsigned __int8 v18; // w20
  unsigned int v19; // w8
  unsigned int v25; // w10
  int v26; // w9
  int v27; // w8
  size_t v28; // x2
  __int64 v29; // x11
  int v30; // w10
  unsigned int v31; // w13
  const char *v32; // x2
  __int64 v33; // x10
  int v34; // w9
  unsigned int v35; // w13
  char v36; // w21
  size_t v37; // x2
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w8
  unsigned int v47; // w26
  unsigned int v48; // w27
  unsigned int v49; // w23
  unsigned int v50; // w9
  unsigned int v51; // w11
  unsigned int v52; // w10
  unsigned int v53; // w11
  bool v54; // cc
  unsigned int v55; // w11
  bool v56; // cc
  unsigned int v57; // w11
  bool v58; // cc
  unsigned int v59; // w11
  bool v60; // cc
  unsigned int v61; // w11
  bool v62; // cc
  unsigned int v63; // w11
  bool v64; // cc
  unsigned int v65; // w11
  bool v66; // cc
  unsigned int v67; // w11
  bool v68; // cc
  unsigned int v69; // w11
  bool v70; // cc
  __int64 v71; // x20
  __int64 v72; // x4
  unsigned int v73; // w8
  const char *v74; // x2
  unsigned int v75; // w8
  int v76; // w8
  __int64 v77; // x9
  _BYTE *v78; // x22
  __int64 result; // x0
  unsigned int v80; // w8
  char v81; // w10
  char v82; // w9
  char v83; // w10
  char v84; // w9
  char v85; // w10
  char v86; // w9
  char v87; // w10
  char v88; // w9
  char v89; // w10
  char v90; // w9
  char v91; // w10
  char v92; // w9
  char v93; // w10
  char v94; // w9
  char v95; // w10
  char v96; // w9
  char v97; // w10
  char v98; // w9
  char v99; // w10
  char v100; // w9
  char v101; // w10
  char v102; // w9
  char v103; // w10
  char v104; // w9
  char v105; // w10
  char v106; // w9
  char v107; // w10
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  char *v124; // x2
  char *v125; // x22
  char v126; // w10
  int v127; // w12
  char is_session_chwidth_320mhz; // w0
  __int64 v129; // x0
  int ielen_from_bss_description; // w24
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  unsigned int v139; // w23
  bool is_24ghz_ch_freq; // w0
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  __int64 v149; // [xsp+8h] [xbp-68h]
  __int64 v150; // [xsp+10h] [xbp-60h]
  unsigned __int8 *v154; // [xsp+30h] [xbp-40h]
  char *v155; // [xsp+38h] [xbp-38h]
  size_t v156[3]; // [xsp+40h] [xbp-30h] BYREF
  _QWORD v157[3]; // [xsp+58h] [xbp-18h] BYREF

  v157[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(unsigned __int8 *)(a5 + 252);
  memset(v157, 0, 13);
  memset(v156, 0, 21);
  if ( v19 > 0xC )
  {
    v32 = "%s: more than SIR_MAC_MAX_NUMBER_OF_RATES rates";
    goto LABEL_120;
  }
  qdf_mem_copy((char *)v157 + 1, (const void *)(a5 + 253), v19);
  v25 = *(unsigned __int8 *)(a5 + 154);
  v26 = *(unsigned __int8 *)(a5 + 252);
  v27 = 0;
  LOBYTE(v157[0]) = *(_BYTE *)(a5 + 252);
  if ( v25 <= 0xA && ((1 << v25) & 0x534) != 0 )
  {
    v28 = *(unsigned __int8 *)(a5 + 265);
    if ( (unsigned int)v28 <= 0xC )
    {
      qdf_mem_copy((char *)&v156[1] + 1, (const void *)(a5 + 266), v28);
      v27 = *(unsigned __int8 *)(a5 + 265);
      v26 = LOBYTE(v157[0]);
      goto LABEL_6;
    }
    v32 = "%s: numRates more than SIR_MAC_MAX_NUM_OF_RATES";
LABEL_120:
    qdf_trace_msg(0x35u, 2u, v32, a9, a10, a11, a12, a13, a14, a15, a16, "lim_populate_peer_rate_set");
    result = 16;
    goto LABEL_121;
  }
LABEL_6:
  LOBYTE(v156[1]) = v27;
  if ( v26 )
  {
    v29 = 0;
    v30 = 0;
    while ( v29 != 12 )
    {
      if ( *((unsigned __int8 *)v157 + v29 + 1) > 0xF9u )
        ++v30;
      v31 = v29 + v30;
      if ( (int)v29 + v30 < v26 )
      {
        if ( v31 > 0xB )
          goto LABEL_27;
        *((_BYTE *)v157 + v29 + 1) = *((_BYTE *)v157 + v31 + 1);
      }
      if ( v26 == ++v29 )
        goto LABEL_18;
    }
    goto LABEL_27;
  }
  LOBYTE(v30) = 0;
LABEL_18:
  v18 = v26 - v30;
  LOBYTE(v157[0]) = v26 - v30;
  if ( v27 )
  {
    v33 = 0;
    v34 = 0;
    while ( v33 != 12 )
    {
      if ( *((unsigned __int8 *)&v156[1] + v33 + 1) > 0xF9u )
        ++v34;
      v35 = v33 + v34;
      if ( (int)v33 + v34 < v27 )
      {
        if ( v35 > 0xB )
          break;
        *((_BYTE *)&v156[1] + v33 + 1) = *((_BYTE *)&v156[1] + v35 + 1);
      }
      if ( v27 == ++v33 )
        goto LABEL_29;
    }
LABEL_27:
    __break(0x5512u);
  }
  LOBYTE(v34) = 0;
LABEL_29:
  v36 = v27 - v34;
  LOBYTE(v156[1]) = v27 - v34;
  if ( (unsigned __int8)(v27 - v34) + (unsigned int)v18 > 0xC )
  {
    v32 = "%s: rates in CFG are more than SIR_MAC_MAX_NUM_OF_RATES";
    goto LABEL_120;
  }
  v149 = a6;
  v150 = a1;
  if ( v27 != (unsigned __int8)v34 )
  {
    if ( (((_BYTE)v27 - (_BYTE)v34) & 0xFE) != 0 )
      v37 = (unsigned __int8)(v27 - v34);
    else
      v37 = 1;
    memcpy((char *)v157 + v18 + 1, (char *)&v156[1] + 1, v37);
  }
  LOBYTE(v157[0]) = v36 + v18;
  v154 = (unsigned __int8 *)a2;
  qdf_mem_set(a2, 0x4Cu, 0);
  v46 = LOBYTE(v157[0]);
  if ( LOBYTE(v157[0]) )
  {
    v47 = 0;
    v48 = 0;
    v49 = 0;
    v155 = a2 + 8;
    while ( 1 )
    {
      if ( v46 == 1 )
      {
        v50 = 0;
      }
      else
      {
        v51 = BYTE1(v157[0]) & 0x7F;
        v52 = BYTE2(v157[0]) & 0x7F;
        v50 = v51 > v52;
        if ( v51 < v52 )
          v52 = BYTE1(v157[0]) & 0x7F;
        if ( v46 != 2 )
        {
          v53 = BYTE3(v157[0]) & 0x7F;
          v54 = v52 > v53;
          if ( v52 >= v53 )
            v52 = BYTE3(v157[0]) & 0x7F;
          if ( v54 )
            v50 = 2;
          if ( v46 != 3 )
          {
            v55 = BYTE4(v157[0]) & 0x7F;
            v56 = v52 > v55;
            if ( v52 >= v55 )
              v52 = BYTE4(v157[0]) & 0x7F;
            if ( v56 )
              v50 = 3;
            if ( v46 != 4 )
            {
              v57 = BYTE5(v157[0]) & 0x7F;
              v58 = v52 > v57;
              if ( v52 >= v57 )
                v52 = BYTE5(v157[0]) & 0x7F;
              if ( v58 )
                v50 = 4;
              if ( v46 != 5 )
              {
                v59 = BYTE6(v157[0]) & 0x7F;
                v60 = v52 > v59;
                if ( v52 >= v59 )
                  v52 = BYTE6(v157[0]) & 0x7F;
                if ( v60 )
                  v50 = 5;
                if ( v46 != 6 )
                {
                  v61 = HIBYTE(v157[0]) & 0x7F;
                  v62 = v52 > v61;
                  if ( v52 >= v61 )
                    v52 = HIBYTE(v157[0]) & 0x7F;
                  if ( v62 )
                    v50 = 6;
                  if ( v46 != 7 )
                  {
                    v63 = v157[1] & 0x7F;
                    v64 = v52 > v63;
                    if ( v52 >= v63 )
                      v52 = v157[1] & 0x7F;
                    if ( v64 )
                      v50 = 7;
                    if ( v46 != 8 )
                    {
                      v65 = BYTE1(v157[1]) & 0x7F;
                      v66 = v52 > v65;
                      if ( v52 >= v65 )
                        v52 = BYTE1(v157[1]) & 0x7F;
                      if ( v66 )
                        v50 = 8;
                      if ( v46 != 9 )
                      {
                        v67 = BYTE2(v157[1]) & 0x7F;
                        v68 = v52 > v67;
                        if ( v52 >= v67 )
                          v52 = BYTE2(v157[1]) & 0x7F;
                        if ( v68 )
                          v50 = 9;
                        if ( v46 != 10 )
                        {
                          v69 = BYTE3(v157[1]) & 0x7F;
                          v70 = v52 > v69;
                          if ( v52 >= v69 )
                            v52 = BYTE3(v157[1]) & 0x7F;
                          if ( v70 )
                            v50 = 10;
                          if ( v46 != 11 )
                          {
                            if ( v52 > (BYTE4(v157[1]) & 0x7Fu) )
                              v50 = 11;
                            if ( v46 < 0xC )
                              __break(1u);
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
      if ( a4 )
      {
        v71 = v50;
        if ( (*((char *)v157 + v50 + 1) & 0x80000000) == 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Invalid basic rate",
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            v45,
            "lim_populate_peer_rate_set");
          goto LABEL_115;
        }
        v72 = *((unsigned __int8 *)v157 + v50 + 1);
      }
      else
      {
        v71 = v50;
        v72 = *((unsigned __int8 *)v157 + v50 + 1);
      }
      v73 = v72 & 0x7F;
      if ( v73 > 0x30 )
        goto LABEL_101;
      if ( ((1LL << v73) & 0x1001001041000LL) == 0 )
        break;
LABEL_103:
      if ( v48 >= 8 )
      {
        v74 = "%s: OOB, aRateIndex: %d";
        v72 = v48;
        goto LABEL_114;
      }
      if ( v48 && *(unsigned __int16 *)&v155[2 * v48 - 2] == (_DWORD)v72 )
      {
        v74 = "%s: Duplicate 11a rate: %d";
        goto LABEL_114;
      }
      *(_WORD *)&v155[2 * v48++] = v72;
LABEL_115:
      *((_BYTE *)v157 + v71 + 1) = -1;
      ++v49;
      v46 = LOBYTE(v157[0]);
      if ( v49 >= LOBYTE(v157[0]) )
        goto LABEL_116;
    }
    if ( ((1LL << v73) & 0x400814) != 0 )
    {
      if ( v47 >= 4 )
      {
        v74 = "%s: OOB, bRateIndex: %d";
        v72 = v47;
LABEL_114:
        qdf_trace_msg(0x35u, 8u, v74, v38, v39, v40, v41, v42, v43, v44, v45, "lim_populate_peer_rate_set", v72);
        goto LABEL_115;
      }
      if ( v47 && *(unsigned __int16 *)&a2[2 * v47 - 2] == (_DWORD)v72 )
      {
        v74 = "%s: Duplicate 11b rate: %d";
        goto LABEL_114;
      }
      *(_WORD *)&a2[2 * v47++] = v72;
      goto LABEL_115;
    }
LABEL_101:
    v75 = v73 - 72;
    if ( v75 > 0x24 || ((1LL << v75) & 0x1001000001LL) == 0 )
    {
      v74 = "%s: %d is neither 11a nor 11b rate";
      goto LABEL_114;
    }
    goto LABEL_103;
  }
LABEL_116:
  v76 = *(unsigned __int8 *)(a5 + 154);
  if ( ((unsigned int)(v76 - 7) < 7 || v76 == 5 || !*(_BYTE *)(a5 + 154)) && (*(_BYTE *)(a5 + 8764) & 1) == 0 )
  {
    v77 = *(_QWORD *)(v150 + 8);
    v78 = a2 + 24;
    v156[0] = 16;
    if ( (unsigned int)wlan_mlme_get_cfg_str(v154 + 24, v77 + 3056, v156, v38, v39, v40, v41, v42, v43, v44, v45) )
    {
      v32 = "%s: could not retrieve supportedMCSSet";
      goto LABEL_120;
    }
    v80 = *(unsigned __int8 *)(a5 + 8635);
    if ( v80 <= 1 )
    {
      v78[*(unsigned __int8 *)(a5 + 8635)] = 0;
      if ( !v80 )
        v154[25] = 0;
    }
    if ( a3 )
    {
      v81 = v154[25];
      v154[24] &= *a3;
      v82 = v81 & a3[1];
      v83 = v154[26];
      v154[25] = v82;
      v84 = v83 & a3[2];
      v85 = v154[27];
      v154[26] = v84;
      v86 = v85 & a3[3];
      v87 = v154[28];
      v154[27] = v86;
      v88 = v87 & a3[4];
      v89 = v154[29];
      v154[28] = v88;
      v90 = v89 & a3[5];
      v91 = v154[30];
      v154[29] = v90;
      v92 = v91 & a3[6];
      v93 = v154[31];
      v154[30] = v92;
      v94 = v93 & a3[7];
      v95 = v154[32];
      v154[31] = v94;
      v96 = v95 & a3[8];
      v97 = v154[33];
      v154[32] = v96;
      v98 = v97 & a3[9];
      v99 = v154[34];
      v154[33] = v98;
      v100 = v99 & a3[10];
      v101 = v154[35];
      v154[34] = v100;
      v102 = v101 & a3[11];
      v103 = v154[36];
      v154[35] = v102;
      v104 = v103 & a3[12];
      v105 = v154[37];
      v154[36] = v104;
      v106 = v105 & a3[13];
      v107 = v154[38];
      v154[37] = v106;
      v154[38] = v107 & a3[14];
      v154[39] &= a3[15];
    }
    lim_dump_ht_mcs_mask(nullptr, v154 + 24);
    if ( !*v78 )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Incorrect MCS 0 - 7. They must be supported",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "lim_populate_peer_rate_set");
      *v78 = -1;
    }
    *(_BYTE *)(a5 + 8653) = v154[25] == 0;
  }
  lim_populate_vht_mcs_set(v150, v154, v149, a5, *(_BYTE *)(a5 + 8635), a17);
  v124 = a7;
  v125 = nullptr;
  if ( a7 && (*(_BYTE *)(a5 + 8676) & 1) != 0 )
  {
    if ( *a7 )
    {
      if ( *(_BYTE *)(a5 + 8635) )
      {
        v126 = 1;
        do
        {
          v127 = 3 << (2 * v126 - 2);
          if ( (v127 & ~*((unsigned __int16 *)a7 + 10)) == 0 || (v127 & ~*((unsigned __int16 *)a7 + 11)) == 0 )
            goto LABEL_145;
        }
        while ( *(unsigned __int8 *)(a5 + 8635) >= (unsigned int)(unsigned __int8)++v126 );
      }
      if ( *(_DWORD *)(a5 + 7176) == 3
        || (is_session_chwidth_320mhz = lim_is_session_chwidth_320mhz(a5),
            v124 = a7,
            (is_session_chwidth_320mhz & 1) != 0) )
      {
        if ( (v124[7] & 0x10) == 0 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: session BW 160/320 MHz but peer BW less than 160 MHz",
            v116,
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            "lim_check_valid_mcs_for_nss");
LABEL_145:
          if ( !a18 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: bssDescription is NULL",
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              v123,
              "lim_populate_peer_rate_set");
            result = 4;
            goto LABEL_121;
          }
          v129 = _qdf_mem_malloc(0x1A08u, "lim_populate_peer_rate_set", 1791);
          if ( !v129 )
          {
            result = 2;
            goto LABEL_121;
          }
          v125 = (char *)v129;
          ielen_from_bss_description = (unsigned __int16)wlan_get_ielen_from_bss_description(a18);
          qdf_mem_set(v125, 0x1A08u, 0);
          if ( ielen_from_bss_description && (unsigned int)sir_parse_beacon_ie(v150, (int)v125) )
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: APCapExtract: Beacon parsing error!",
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              v138,
              "lim_extract_ap_capabilities");
          v124 = v125 + 2640;
          goto LABEL_152;
        }
      }
    }
    v125 = nullptr;
  }
LABEL_152:
  lim_populate_he_mcs_set(v150, v154, v124, a5, *(unsigned __int8 *)(a5 + 8635));
  v139 = *(_DWORD *)(a5 + 7176);
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(a5 + 284));
  lim_populate_eht_mcs_set(v150, v154, a8, a5, v139, is_24ghz_ch_freq);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: nss 1x1 %d nss %d",
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    "lim_populate_peer_rate_set",
    *(unsigned __int8 *)(a5 + 8653),
    *(unsigned __int8 *)(a5 + 8635));
  if ( v125 )
    _qdf_mem_free((__int64)v125);
  result = 0;
LABEL_121:
  _ReadStatusReg(SP_EL0);
  return result;
}
