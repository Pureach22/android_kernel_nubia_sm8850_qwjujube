__int64 __fastcall policy_mgr_get_connection_channels(
        __int64 a1,
        unsigned int a2,
        int a3,
        char a4,
        int a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8,
        unsigned int *a9)
{
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x19
  unsigned int v27; // w28
  char v28; // w27
  char v29; // w8
  const char *v30; // x2
  char is_6ghz_conc_mode_supported; // w23
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int *v49; // x27
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  bool is_6ghz_chan_freq; // w25
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  bool v67; // w0
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  bool v108; // w25
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  bool v133; // w25
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  bool v166; // w25
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  bool v175; // w25
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  char v184; // [xsp+4h] [xbp-Ch]

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( !comp_private_obj )
  {
    v30 = "%s: Invalid Context";
    return qdf_trace_msg(0x4Fu, 2u, v30, v18, v19, v20, v21, v22, v23, v24, v25, "policy_mgr_get_connection_channels");
  }
  if ( !a7 || !a8 )
  {
    v30 = "%s: list or index is NULL";
    return qdf_trace_msg(0x4Fu, 2u, v30, v18, v19, v20, v21, v22, v23, v24, v25, "policy_mgr_get_connection_channels");
  }
  v26 = comp_private_obj;
  v27 = *a9;
  if ( a5 )
  {
    if ( a5 == 1 )
    {
      v28 = -41;
      v29 = -21;
    }
    else
    {
      v28 = -61;
      v29 = -41;
    }
  }
  else
  {
    v28 = -21;
    v29 = -1;
  }
  v184 = v29;
  is_6ghz_conc_mode_supported = policy_mgr_is_6ghz_conc_mode_supported(a1, a2);
  qdf_mutex_acquire(v26 + 56);
  if ( a3 > 1 )
  {
    if ( a3 != 2 )
    {
      if ( a3 != 3 )
        goto LABEL_61;
      if ( (qword_81C458 & 0x100000000LL) != 0 )
      {
        v49 = a9;
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C47C) != 1 )
          goto LABEL_272;
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C4A0) != 1 )
          goto LABEL_272;
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C4C4) != 1 )
          goto LABEL_272;
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C4E8) != 1 || !wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0)) )
          goto LABEL_272;
        goto LABEL_211;
      }
      goto LABEL_271;
    }
    if ( (qword_81C458 & 0x100000000LL) == 0 )
      goto LABEL_230;
    if ( (a4 & 1) != 0
      && (wlan_reg_is_dfs_for_freq(
            *(_QWORD *)(v26 + 8),
            HIDWORD(pm_conc_connection_list),
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40)
        & 1) != 0 )
    {
      if ( (qword_81C47C & 0x100000000LL) == 0 )
        goto LABEL_230;
    }
    else
    {
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && v27 < a8 )
      {
        *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
        *(_BYTE *)(a7 + v27++) = v184;
      }
      if ( (qword_81C47C & 0x100000000LL) == 0 )
        goto LABEL_230;
      if ( (a4 & 1) == 0 )
        goto LABEL_126;
    }
    if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v26 + 8), HIDWORD(qword_81C464), v76, v77, v78, v79, v80, v81, v82, v83)
        & 1) != 0 )
    {
      if ( (qword_81C4A0 & 0x100000000LL) == 0 )
        goto LABEL_230;
LABEL_131:
      if ( (wlan_reg_is_dfs_for_freq(
              *(_QWORD *)(v26 + 8),
              HIDWORD(qword_81C488),
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107)
          & 1) != 0 )
      {
        if ( (qword_81C4C4 & 0x100000000LL) == 0 )
          goto LABEL_230;
LABEL_163:
        if ( (wlan_reg_is_dfs_for_freq(
                *(_QWORD *)(v26 + 8),
                HIDWORD(qword_81C4AC),
                v125,
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                v132)
            & 1) != 0 )
        {
          if ( (qword_81C4E8 & 0x100000000LL) == 0 )
            goto LABEL_230;
          goto LABEL_226;
        }
LABEL_221:
        if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4AC)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( (qword_81C4E8 & 0x100000000LL) != 0 )
        {
          if ( (a4 & 1) == 0 )
          {
LABEL_227:
            if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4D0)) && v27 < a8 )
            {
              *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4D0);
              *(_BYTE *)(a7 + v27++) = v184;
            }
            goto LABEL_230;
          }
LABEL_226:
          if ( (wlan_reg_is_dfs_for_freq(
                  *(_QWORD *)(v26 + 8),
                  HIDWORD(qword_81C4D0),
                  v158,
                  v159,
                  v160,
                  v161,
                  v162,
                  v163,
                  v164,
                  v165)
              & 1) != 0 )
            goto LABEL_230;
          goto LABEL_227;
        }
LABEL_230:
        if ( BYTE4(qword_81C458) == 1 )
        {
          if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && v27 < a8 )
          {
            *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
            *(_BYTE *)(a7 + v27++) = v28;
          }
          if ( BYTE4(qword_81C47C) == 1 )
          {
            if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) && v27 < a8 )
            {
              *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
              *(_BYTE *)(a7 + v27++) = v28;
            }
            if ( BYTE4(qword_81C4A0) == 1 )
            {
              if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488)) && v27 < a8 )
              {
                *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
                *(_BYTE *)(a7 + v27++) = v28;
              }
              if ( BYTE4(qword_81C4C4) == 1 )
              {
                if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC)) && v27 < a8 )
                {
                  *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
                  *(_BYTE *)(a7 + v27++) = v28;
                }
                if ( BYTE4(qword_81C4E8) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0)) )
                {
LABEL_248:
                  if ( v27 < a8 )
                  {
                    *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4D0);
                    *(_BYTE *)(a7 + v27++) = v28;
                  }
                  goto LABEL_250;
                }
              }
            }
          }
        }
        goto LABEL_250;
      }
LABEL_158:
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C488)) && v27 < a8 )
      {
        *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
        *(_BYTE *)(a7 + v27++) = v184;
      }
      if ( (qword_81C4C4 & 0x100000000LL) == 0 )
        goto LABEL_230;
      if ( (a4 & 1) == 0 )
        goto LABEL_221;
      goto LABEL_163;
    }
LABEL_126:
    if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C464)) && v27 < a8 )
    {
      *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
      *(_BYTE *)(a7 + v27++) = v184;
    }
    if ( (qword_81C4A0 & 0x100000000LL) == 0 )
      goto LABEL_230;
    if ( (a4 & 1) == 0 )
      goto LABEL_158;
    goto LABEL_131;
  }
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      if ( (qword_81C458 & 0x100000000LL) != 0 )
      {
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C47C) == 1 )
        {
          if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C464)) && v27 < a8 )
          {
            *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
            *(_BYTE *)(a7 + v27++) = v184;
          }
          if ( BYTE4(qword_81C4A0) == 1 )
          {
            if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C488)) && v27 < a8 )
            {
              *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
              *(_BYTE *)(a7 + v27++) = v184;
            }
            if ( BYTE4(qword_81C4C4) == 1 )
            {
              if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4AC)) && v27 < a8 )
              {
                *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
                *(_BYTE *)(a7 + v27++) = v184;
              }
              if ( BYTE4(qword_81C4E8) == 1 && wlan_reg_is_24ghz_ch_freq(HIDWORD(qword_81C4D0)) && v27 < a8 )
              {
                *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4D0);
                *(_BYTE *)(a7 + v27++) = v184;
              }
            }
          }
        }
      }
      if ( BYTE4(qword_81C458) != 1 )
        goto LABEL_250;
      if ( (a4 & 1) != 0
        && (wlan_reg_is_dfs_for_freq(
              *(_QWORD *)(v26 + 8),
              HIDWORD(pm_conc_connection_list),
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40)
          & 1) != 0 )
      {
        if ( (qword_81C47C & 0x100000000LL) == 0 )
          goto LABEL_250;
      }
      else
      {
        if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
          *(_BYTE *)(a7 + v27++) = v28;
        }
        if ( (qword_81C47C & 0x100000000LL) == 0 )
          goto LABEL_250;
        if ( (a4 & 1) == 0 )
          goto LABEL_118;
      }
      if ( (wlan_reg_is_dfs_for_freq(
              *(_QWORD *)(v26 + 8),
              HIDWORD(qword_81C464),
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48)
          & 1) != 0 )
      {
        if ( (qword_81C4A0 & 0x100000000LL) == 0 )
          goto LABEL_250;
LABEL_123:
        if ( (wlan_reg_is_dfs_for_freq(
                *(_QWORD *)(v26 + 8),
                HIDWORD(qword_81C488),
                v92,
                v93,
                v94,
                v95,
                v96,
                v97,
                v98,
                v99)
            & 1) != 0 )
        {
          if ( (qword_81C4C4 & 0x100000000LL) == 0 )
            goto LABEL_250;
LABEL_155:
          if ( (wlan_reg_is_dfs_for_freq(
                  *(_QWORD *)(v26 + 8),
                  HIDWORD(qword_81C4AC),
                  v117,
                  v118,
                  v119,
                  v120,
                  v121,
                  v122,
                  v123,
                  v124)
              & 1) != 0 )
          {
            if ( (qword_81C4E8 & 0x100000000LL) == 0 )
              goto LABEL_250;
LABEL_218:
            if ( (wlan_reg_is_dfs_for_freq(
                    *(_QWORD *)(v26 + 8),
                    HIDWORD(qword_81C4D0),
                    v150,
                    v151,
                    v152,
                    v153,
                    v154,
                    v155,
                    v156,
                    v157)
                & 1) != 0 )
              goto LABEL_250;
LABEL_219:
            if ( !wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4D0)) )
              goto LABEL_250;
            goto LABEL_248;
          }
LABEL_213:
          if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4AC)) && v27 < a8 )
          {
            *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
            *(_BYTE *)(a7 + v27++) = v28;
          }
          if ( (qword_81C4E8 & 0x100000000LL) != 0 )
          {
            if ( (a4 & 1) == 0 )
              goto LABEL_219;
            goto LABEL_218;
          }
LABEL_250:
          if ( (is_6ghz_conc_mode_supported & 1) != 0 && BYTE4(qword_81C458) == 1 )
          {
            if ( wlan_reg_is_6ghz_chan_freq(WORD2(pm_conc_connection_list)) && v27 < a8 )
            {
              *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
              *(_BYTE *)(a7 + v27++) = v28;
            }
            if ( BYTE4(qword_81C47C) == 1 )
            {
              if ( wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C464)) && v27 < a8 )
              {
                *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
                *(_BYTE *)(a7 + v27++) = v28;
              }
              if ( BYTE4(qword_81C4A0) == 1 )
              {
                if ( wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C488)) && v27 < a8 )
                {
                  *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
                  *(_BYTE *)(a7 + v27++) = v28;
                }
                if ( BYTE4(qword_81C4C4) == 1 )
                {
                  if ( wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4AC)) && v27 < a8 )
                  {
                    *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
                    *(_BYTE *)(a7 + v27++) = v28;
                  }
                  if ( BYTE4(qword_81C4E8) == 1 && wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4D0)) )
                  {
                    v184 = v28;
                    v49 = a9;
                    if ( v27 >= a8 )
                      goto LABEL_272;
                    goto LABEL_287;
                  }
                }
              }
            }
          }
          goto LABEL_271;
        }
LABEL_150:
        if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C488)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
          *(_BYTE *)(a7 + v27++) = v28;
        }
        if ( (qword_81C4C4 & 0x100000000LL) == 0 )
          goto LABEL_250;
        if ( (a4 & 1) == 0 )
          goto LABEL_213;
        goto LABEL_155;
      }
LABEL_118:
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C464)) && v27 < a8 )
      {
        *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
        *(_BYTE *)(a7 + v27++) = v28;
      }
      if ( (qword_81C4A0 & 0x100000000LL) == 0 )
        goto LABEL_250;
      if ( (a4 & 1) == 0 )
        goto LABEL_150;
      goto LABEL_123;
    }
LABEL_61:
    if ( (qword_81C458 & 0x100000000LL) == 0 )
    {
      v49 = a9;
      goto LABEL_192;
    }
    if ( (a4 & 1) != 0
      && (wlan_reg_is_dfs_for_freq(
            *(_QWORD *)(v26 + 8),
            HIDWORD(pm_conc_connection_list),
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40)
        & 1) != 0 )
    {
      v49 = a9;
      if ( (qword_81C47C & 0x100000000LL) == 0 )
        goto LABEL_192;
    }
    else
    {
      v49 = a9;
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(pm_conc_connection_list)) && v27 < a8 )
      {
        *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
        *(_BYTE *)(a7 + v27++) = v184;
      }
      if ( (qword_81C47C & 0x100000000LL) == 0 )
        goto LABEL_192;
      if ( (a4 & 1) == 0 )
        goto LABEL_110;
    }
    if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v26 + 8), HIDWORD(qword_81C464), v50, v51, v52, v53, v54, v55, v56, v57)
        & 1) != 0 )
    {
      if ( (qword_81C4A0 & 0x100000000LL) == 0 )
        goto LABEL_192;
LABEL_115:
      if ( (wlan_reg_is_dfs_for_freq(
              *(_QWORD *)(v26 + 8),
              HIDWORD(qword_81C488),
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91)
          & 1) != 0 )
      {
        if ( (qword_81C4C4 & 0x100000000LL) == 0 )
          goto LABEL_192;
LABEL_147:
        if ( (wlan_reg_is_dfs_for_freq(
                *(_QWORD *)(v26 + 8),
                HIDWORD(qword_81C4AC),
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                v116)
            & 1) != 0 )
        {
          if ( (qword_81C4E8 & 0x100000000LL) == 0 )
            goto LABEL_192;
          goto LABEL_188;
        }
LABEL_183:
        if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4AC)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( (qword_81C4E8 & 0x100000000LL) != 0 )
        {
          if ( (a4 & 1) == 0 )
          {
LABEL_189:
            if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C4D0)) && v27 < a8 )
            {
              *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4D0);
              *(_BYTE *)(a7 + v27++) = v184;
            }
            goto LABEL_192;
          }
LABEL_188:
          if ( (wlan_reg_is_dfs_for_freq(
                  *(_QWORD *)(v26 + 8),
                  HIDWORD(qword_81C4D0),
                  v142,
                  v143,
                  v144,
                  v145,
                  v146,
                  v147,
                  v148,
                  v149)
              & 1) != 0 )
            goto LABEL_192;
          goto LABEL_189;
        }
LABEL_192:
        if ( (is_6ghz_conc_mode_supported & 1) == 0 || BYTE4(qword_81C458) != 1 )
          goto LABEL_272;
        if ( wlan_reg_is_6ghz_chan_freq(WORD2(pm_conc_connection_list)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C47C) != 1 )
          goto LABEL_272;
        if ( wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C464)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C4A0) != 1 )
          goto LABEL_272;
        if ( wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C488)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C4C4) != 1 )
          goto LABEL_272;
        if ( wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4AC)) && v27 < a8 )
        {
          *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
          *(_BYTE *)(a7 + v27++) = v184;
        }
        if ( BYTE4(qword_81C4E8) != 1 || !wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4D0)) )
          goto LABEL_272;
LABEL_211:
        if ( v27 >= a8 )
          goto LABEL_272;
        goto LABEL_287;
      }
LABEL_142:
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C488)) && v27 < a8 )
      {
        *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
        *(_BYTE *)(a7 + v27++) = v184;
      }
      if ( (qword_81C4C4 & 0x100000000LL) == 0 )
        goto LABEL_192;
      if ( (a4 & 1) == 0 )
        goto LABEL_183;
      goto LABEL_147;
    }
LABEL_110:
    if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(qword_81C464)) && v27 < a8 )
    {
      *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
      *(_BYTE *)(a7 + v27++) = v184;
    }
    if ( (qword_81C4A0 & 0x100000000LL) == 0 )
      goto LABEL_192;
    if ( (a4 & 1) == 0 )
      goto LABEL_142;
    goto LABEL_115;
  }
  if ( (qword_81C458 & 0x100000000LL) == 0 )
  {
LABEL_271:
    v49 = a9;
    goto LABEL_272;
  }
  v49 = a9;
  is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(WORD2(pm_conc_connection_list));
  if ( (a4 & 1) != 0 )
  {
    if ( (wlan_reg_is_dfs_for_freq(
            *(_QWORD *)(v26 + 8),
            HIDWORD(pm_conc_connection_list),
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66)
        & 1) != 0
      || v27 >= a8 )
    {
      if ( BYTE4(qword_81C47C) != 1 )
        goto LABEL_272;
      v67 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C464));
      goto LABEL_107;
    }
  }
  else if ( v27 >= a8 )
  {
    if ( BYTE4(qword_81C47C) != 1 )
      goto LABEL_272;
    v67 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C464));
LABEL_136:
    if ( v27 >= a8 )
    {
      if ( BYTE4(qword_81C4A0) != 1 )
        goto LABEL_272;
      v133 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C488));
LABEL_174:
      if ( v27 >= a8 )
      {
        if ( BYTE4(qword_81C4C4) != 1 )
          goto LABEL_272;
        v166 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4AC));
        goto LABEL_276;
      }
LABEL_175:
      if ( is_6ghz_conc_mode_supported & 1 | !v133 )
      {
        *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C488);
        *(_BYTE *)(a7 + v27++) = v184;
      }
      if ( (qword_81C4C4 & 0x100000000LL) == 0 )
        goto LABEL_272;
      v166 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4AC));
      if ( (a4 & 1) != 0 )
        goto LABEL_179;
LABEL_276:
      if ( v27 >= a8 )
      {
        if ( BYTE4(qword_81C4E8) != 1 )
          goto LABEL_272;
        v175 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4D0));
        goto LABEL_285;
      }
LABEL_277:
      if ( is_6ghz_conc_mode_supported & 1 | !v166 )
      {
        *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4AC);
        *(_BYTE *)(a7 + v27++) = v184;
      }
      if ( (qword_81C4E8 & 0x100000000LL) == 0 )
        goto LABEL_272;
      v175 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4D0));
      if ( (a4 & 1) != 0 )
      {
LABEL_281:
        if ( (wlan_reg_is_dfs_for_freq(
                *(_QWORD *)(v26 + 8),
                HIDWORD(qword_81C4D0),
                v176,
                v177,
                v178,
                v179,
                v180,
                v181,
                v182,
                v183)
            & 1) != 0 )
          goto LABEL_272;
      }
LABEL_285:
      if ( v27 >= a8 || !(is_6ghz_conc_mode_supported & 1 | !v175) )
        goto LABEL_272;
LABEL_287:
      *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C4D0);
      *(_BYTE *)(a7 + v27++) = v184;
      goto LABEL_272;
    }
    goto LABEL_137;
  }
  if ( is_6ghz_conc_mode_supported & 1 | !is_6ghz_chan_freq )
  {
    *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(pm_conc_connection_list);
    *(_BYTE *)(a7 + v27++) = v184;
  }
  if ( (qword_81C47C & 0x100000000LL) == 0 )
    goto LABEL_272;
  v67 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C464));
  if ( (a4 & 1) == 0 )
    goto LABEL_136;
LABEL_107:
  v108 = v67;
  if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v26 + 8), HIDWORD(qword_81C464), v68, v69, v70, v71, v72, v73, v74, v75) & 1) != 0
    || v27 >= a8 )
  {
    if ( BYTE4(qword_81C4A0) != 1 )
      goto LABEL_272;
    v133 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C488));
    goto LABEL_168;
  }
  v67 = v108;
LABEL_137:
  if ( is_6ghz_conc_mode_supported & 1 | !v67 )
  {
    *(_DWORD *)(a6 + 4LL * v27) = HIDWORD(qword_81C464);
    *(_BYTE *)(a7 + v27++) = v184;
  }
  if ( (qword_81C4A0 & 0x100000000LL) == 0 )
    goto LABEL_272;
  v133 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C488));
  if ( (a4 & 1) == 0 )
    goto LABEL_174;
LABEL_168:
  if ( (wlan_reg_is_dfs_for_freq(
          *(_QWORD *)(v26 + 8),
          HIDWORD(qword_81C488),
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          v141)
      & 1) == 0
    && v27 < a8 )
  {
    goto LABEL_175;
  }
  if ( BYTE4(qword_81C4C4) != 1 )
    goto LABEL_272;
  v166 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4AC));
LABEL_179:
  if ( (wlan_reg_is_dfs_for_freq(
          *(_QWORD *)(v26 + 8),
          HIDWORD(qword_81C4AC),
          v167,
          v168,
          v169,
          v170,
          v171,
          v172,
          v173,
          v174)
      & 1) == 0
    && v27 < a8 )
  {
    goto LABEL_277;
  }
  if ( BYTE4(qword_81C4E8) == 1 )
  {
    v175 = wlan_reg_is_6ghz_chan_freq(WORD2(qword_81C4D0));
    goto LABEL_281;
  }
LABEL_272:
  *v49 = v27;
  return qdf_mutex_release(v26 + 56);
}
