__int64 __fastcall dfs_prepare_random_channel_for_freq(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int16 *a5,
        int a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  bool v30; // w9
  char bonding_channel_without_seg_info_for_freq; // w0
  unsigned int v32; // w23
  int v33; // w20
  bool v34; // w27
  const char *v35; // x2
  unsigned __int16 *v36; // x28
  __int64 v37; // x8
  int *v38; // x9
  int v39; // t1
  int v40; // w8
  int v41; // w4
  int v42; // w8
  __int64 v43; // x8
  _WORD *v44; // x0
  _WORD *v45; // x24
  __int64 v46; // x8
  _WORD *v47; // x10
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w27
  unsigned int v57; // w28
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x4
  int v67; // w8
  const char *v68; // x2
  unsigned int v69; // w20
  int v70; // w8
  __int64 v71; // x26
  __int64 v73; // x21
  unsigned __int64 v74; // x8
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // [xsp+0h] [xbp-120h]
  __int64 v92; // [xsp+8h] [xbp-118h]
  bool v93; // [xsp+10h] [xbp-110h]
  char v94; // [xsp+14h] [xbp-10Ch]
  _WORD *v95; // [xsp+18h] [xbp-108h]
  _QWORD v96[25]; // [xsp+20h] [xbp-100h] BYREF
  int v97; // [xsp+E8h] [xbp-38h]
  __int64 v98; // [xsp+F0h] [xbp-30h] BYREF
  __int64 v99; // [xsp+F8h] [xbp-28h]
  __int64 v100; // [xsp+100h] [xbp-20h]
  __int64 v101; // [xsp+108h] [xbp-18h]
  __int64 v102; // [xsp+110h] [xbp-10h]

  v102 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v97 = 0;
  memset(v96, 0, sizeof(v96));
  if ( !a2 || !a3 )
  {
    if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: Invalid params %pK, chan_cnt=%d",
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        "dfs_prepare_random_channel_for_freq",
        a2,
        a3);
    goto LABEL_179;
  }
  if ( *a5 >= 8u )
  {
    if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: Invalid chan_wd %d",
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        "dfs_prepare_random_channel_for_freq");
    goto LABEL_179;
  }
  HIDWORD(v91) = a6;
  v95 = (_WORD *)_qdf_mem_malloc(2LL * a3, "dfs_prepare_random_channel_for_freq", 1574);
  if ( !v95 )
  {
LABEL_179:
    v57 = 0;
    goto LABEL_180;
  }
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    qdf_trace_msg(
      0x27u,
      8u,
      "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: flags %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dfs_apply_rules_for_freq",
      a4);
  v30 = (a4 & 2) == 0 || BYTE4(v91) != 2;
  v93 = v30;
  if ( BYTE4(v91) == 6 || BYTE4(v91) == 3 )
  {
    LODWORD(v91) = (a4 >> 8) & 1;
    LODWORD(v92) = (a4 >> 3) & 1;
    HIDWORD(v92) = (a4 >> 2) & 1;
    if ( (a4 & 1) == 0 )
    {
LABEL_23:
      bonding_channel_without_seg_info_for_freq = 0;
      goto LABEL_26;
    }
  }
  else
  {
    v92 = 0;
    LODWORD(v91) = 0;
    if ( (a4 & 1) == 0 )
      goto LABEL_23;
  }
  bonding_channel_without_seg_info_for_freq = dfs_get_bonding_channel_without_seg_info_for_freq(
                                                *(_QWORD *)(a1 + 14888),
                                                &v98);
LABEL_26:
  v32 = 0;
  v33 = 0;
  v94 = bonding_channel_without_seg_info_for_freq;
  if ( bonding_channel_without_seg_info_for_freq )
    v34 = (a4 & 1) == 0;
  else
    v34 = 1;
  do
  {
    v36 = (unsigned __int16 *)(a2 + 32LL * v33);
    if ( (unsigned int)*((unsigned __int8 *)v36 + 18) - 185 <= 0xFFFFFF47 )
    {
      if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
      {
        v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: invalid channel %d";
LABEL_30:
        qdf_trace_msg(0x27u, 8u, v35, v21, v22, v23, v24, v25, v26, v27, v28, "dfs_apply_rules_for_freq", v91);
        goto LABEL_31;
      }
      goto LABEL_31;
    }
    if ( !v34 )
    {
      v40 = *v36;
      if ( v40 == (unsigned __int16)v98 )
        goto LABEL_47;
      if ( v94 != 1 )
      {
        if ( v40 == WORD1(v98) )
          goto LABEL_47;
        if ( v94 != 2 )
        {
          if ( v40 == WORD2(v98) )
            goto LABEL_47;
          if ( v94 != 3 )
          {
            if ( v40 == HIWORD(v98) )
              goto LABEL_47;
            if ( v94 != 4 )
            {
              if ( v40 == (unsigned __int16)v99 )
                goto LABEL_47;
              if ( v94 != 5 )
              {
                if ( v40 == WORD1(v99) )
                  goto LABEL_47;
                if ( v94 != 6 )
                {
                  if ( v40 == WORD2(v99) )
                    goto LABEL_47;
                  if ( v94 != 7 )
                  {
                    if ( v40 == HIWORD(v99) )
                      goto LABEL_47;
                    if ( v94 != 8 )
                    {
                      if ( v40 == (unsigned __int16)v100 )
                        goto LABEL_47;
                      if ( v94 != 9 )
                      {
                        if ( v40 == WORD1(v100) )
                          goto LABEL_47;
                        if ( v94 != 10 )
                        {
                          if ( v40 == WORD2(v100) )
                            goto LABEL_47;
                          if ( v94 != 11 )
                          {
                            if ( v40 == HIWORD(v100) )
                              goto LABEL_47;
                            if ( v94 != 12 )
                            {
                              if ( v40 == (unsigned __int16)v101 )
                                goto LABEL_47;
                              if ( v94 != 13 )
                              {
                                if ( v40 == WORD1(v101) )
                                  goto LABEL_47;
                                if ( v94 != 14 )
                                {
                                  if ( v40 == WORD2(v101) )
                                    goto LABEL_47;
                                  if ( v94 != 15 )
                                  {
                                    if ( v40 == HIWORD(v101) )
                                    {
LABEL_47:
                                      if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
                                      {
                                        v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip %d current operating channel";
                                        goto LABEL_30;
                                      }
                                      goto LABEL_31;
                                    }
                                    if ( v94 != 16 )
                                    {
LABEL_193:
                                      __break(0x5512u);
                                      goto LABEL_194;
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
    }
    if ( a7 && *(_BYTE *)a7 )
    {
      v37 = *(unsigned __int8 *)(a7 + 16);
      if ( !*(_BYTE *)(a7 + 16) )
      {
LABEL_43:
        if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip ch freq %d not in acs range";
          goto LABEL_30;
        }
        goto LABEL_31;
      }
      v38 = *(int **)(a7 + 8);
      while ( 1 )
      {
        v39 = *v38++;
        if ( v39 == *v36 )
          break;
        if ( !--v37 )
          goto LABEL_43;
      }
    }
    if ( (a4 & 0x40) != 0 && *v36 <= 0x9B4u )
    {
      if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
      {
        v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip 2.4 GHz channel=%d";
        goto LABEL_30;
      }
    }
    else if ( (a4 & 0x20) != 0 && wlan_reg_is_5ghz_ch_freq(*v36) )
    {
      if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
      {
        v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip 5 GHz channel=%d";
        goto LABEL_30;
      }
    }
    else if ( v93 || (unsigned int)*v36 - 5600 > 0x32 )
    {
      if ( HIDWORD(v92) && (unsigned int)*v36 - 5180 <= 0x8C )
      {
        if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip indoor channel=%d";
          goto LABEL_30;
        }
      }
      else if ( (_DWORD)v92 && (unsigned int)*v36 - 5500 <= 0xDC )
      {
        if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip outdoor channel=%d";
          goto LABEL_30;
        }
      }
      else if ( (a4 & 0x400) != 0 && wlan_reg_is_6ghz_chan_freq(*v36) )
      {
        if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip 6 GHz channel=%d";
          goto LABEL_30;
        }
      }
      else if ( (a4 & 0x10) != 0 && (v36[8] & 2) != 0 )
      {
        if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip dfs channel=%d";
          goto LABEL_30;
        }
      }
      else
      {
        v41 = *v36;
        if ( (unsigned int)(v41 - 5260) < 0x3D )
          v42 = v91;
        else
          v42 = 0;
        if ( v42 == 1 )
        {
          if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
          {
            v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip japan W53 channel=%d";
            goto LABEL_30;
          }
        }
        else
        {
          if ( !a1 )
          {
            qdf_trace_msg(
              0x27u,
              2u,
              "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: null dfs",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "dfs_is_freq_in_nol");
            LOWORD(v41) = *v36;
LABEL_130:
            v95[v32++] = v41;
            goto LABEL_31;
          }
          v43 = *(_QWORD *)(a1 + 64);
          if ( !v43 )
            goto LABEL_130;
          while ( *(_DWORD *)(v43 + 24) != v41 )
          {
            v43 = *(_QWORD *)(v43 + 136);
            if ( !v43 )
              goto LABEL_130;
          }
          if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
          {
            qdf_trace_msg(
              0x27u,
              8u,
              "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: %d is in nol",
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              "dfs_is_freq_in_nol");
            if ( (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
            {
              v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip nol channel=%d";
              goto LABEL_30;
            }
          }
        }
      }
    }
    else if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    {
      v35 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip weather channel=%d";
      goto LABEL_30;
    }
LABEL_31:
    ++v33;
  }
  while ( v33 != a3 );
  v44 = (_WORD *)_qdf_mem_malloc(2LL * v32, "dfs_prepare_random_channel_for_freq", 1588);
  if ( !v44 )
  {
    _qdf_mem_free((__int64)v95);
    goto LABEL_179;
  }
  v45 = v44;
  if ( (a4 & 0x800) != 0 && *a5 <= 1u )
  {
    v46 = (unsigned __int8)v32;
    if ( (_BYTE)v32 )
    {
      v47 = v95;
      do
      {
        if ( (unsigned int)(unsigned __int16)*v47 - 5200 <= 0x28 )
          *v47 = 0;
        --v46;
        ++v47;
      }
      while ( v46 );
    }
  }
  qdf_mem_copy(v44, v95, 2 * v32);
  if ( !*a5 )
  {
LABEL_168:
    if ( !v32 )
      goto LABEL_186;
    v69 = 0;
    v70 = 0;
    do
    {
      v71 = v70;
      if ( v45[v70] )
      {
        if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
          qdf_trace_msg(
            0x27u,
            8u,
            "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: Chan freq =%d added to available list",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "dfs_prepare_random_channel_for_freq",
            v91);
        if ( v69 >= 0x66 )
          goto LABEL_193;
        *((_WORD *)v96 + v69++) = v45[v71];
      }
      v70 = v71 + 1;
    }
    while ( v32 != (_DWORD)v71 + 1 );
    LODWORD(v98) = 0;
    if ( !v69 )
    {
LABEL_186:
      qdf_trace_msg(
        0x27u,
        2u,
        "WLAN_DEBUG_DFS_ALWAYS : %s: invalid param freq_lst %pK, num_chan = %d",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "dfs_get_rand_from_lst_for_freq",
        v96,
        0,
        v91);
      v57 = 0;
      goto LABEL_190;
    }
    get_random_bytes(&v98, 1);
    v73 = (unsigned int)v98;
    v74 = (qdf_mc_timer_get_system_ticks() + v73) % v69;
    if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    {
      if ( v74 <= 0x65 )
      {
        v57 = *((unsigned __int16 *)v96 + v74);
        qdf_trace_msg(
          0x27u,
          4u,
          "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: random chan freq %d",
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          "dfs_get_rand_from_lst_for_freq",
          *((unsigned __int16 *)v96 + v74));
        goto LABEL_190;
      }
    }
    else if ( v74 <= 0x65 )
    {
      v57 = *((unsigned __int16 *)v96 + v74);
      goto LABEL_190;
    }
LABEL_194:
    __break(1u);
    JUMPOUT(0x68F050);
  }
  v56 = (BYTE4(v91) == 2) & (a4 >> 1);
  while ( 2 )
  {
    v57 = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, unsigned __int16 *, _WORD *, _QWORD))dfs_find_ch_with_fallback_for_freq)(
            a1,
            a5,
            a5 + 6,
            v45,
            v32);
    if ( *a5 == 4 && (a4 & 0x200) != 0 )
    {
      if ( (_WORD)v57 )
      {
        wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(a1 + 14936),
          (unsigned __int16)v57,
          0,
          (__int64)a5,
          0,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65);
        if ( (unsigned int)(*((_DWORD *)a5 + 2) - 5660) > 0x91 || (unsigned int)(*((_DWORD *)a5 + 3) - 5660) >= 0x92 )
        {
          *a5 = 3;
          v57 = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, unsigned __int16 *, _WORD *, _QWORD))dfs_find_ch_with_fallback_for_freq)(
                  a1,
                  a5,
                  a5 + 6,
                  v45,
                  v32);
        }
      }
    }
    v66 = (unsigned __int16)v57;
    if ( (unsigned __int16)v57 == 5580 )
      v67 = v56;
    else
      v67 = 0;
    if ( v67 != 1 )
    {
      if ( (a4 & 0x800) == 0 || (unsigned __int16)v57 == 5200 || (unsigned __int16)(v57 - 5180) > 0x3Cu )
      {
        if ( (_WORD)v57 )
          goto LABEL_190;
      }
      else
      {
        if ( *a5 != 2 )
          goto LABEL_190;
        if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
        {
          v68 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip spruce spur causing (adjacent) channel=%hu";
LABEL_167:
          qdf_trace_msg(
            0x27u,
            8u,
            v68,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            "dfs_prepare_random_channel_for_freq",
            v66,
            v91);
        }
      }
LABEL_145:
      qdf_mem_copy(v45, v95, 2 * v32);
      if ( !*a5 )
        goto LABEL_168;
      continue;
    }
    break;
  }
  if ( *a5 == 1 )
  {
    if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    {
      v68 = "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: skip weather adjacent ch freq =%d\n";
      v66 = 5580;
      goto LABEL_167;
    }
    goto LABEL_145;
  }
  v57 = 5580;
LABEL_190:
  _qdf_mem_free((__int64)v95);
  _qdf_mem_free((__int64)v45);
  if ( !a1 || (*(_BYTE *)(a1 + 2) & 0x20) != 0 )
    qdf_trace_msg(
      0x27u,
      4u,
      "WLAN_DEBUG_DFS_RANDOM_CHAN : %s: target_freq = %d",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "dfs_prepare_random_channel_for_freq",
      (unsigned __int16)v57,
      v91);
LABEL_180:
  _ReadStatusReg(SP_EL0);
  return v57;
}
