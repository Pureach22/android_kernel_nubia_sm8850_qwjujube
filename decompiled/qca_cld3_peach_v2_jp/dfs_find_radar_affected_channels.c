__int64 __fastcall dfs_find_radar_affected_channels(
        __int64 a1,
        __int64 a2,
        _WORD *a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 result; // x0
  int v17; // w8
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w24
  int v28; // w25
  unsigned __int16 v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w8
  unsigned int v39; // w8
  int v40; // w10
  int v41; // w9
  unsigned int v42; // w11
  unsigned __int16 v43; // w13
  int v44; // w10
  unsigned __int16 v45; // w13
  unsigned int v46; // w11
  int v47; // w10
  unsigned int v48; // w11
  int v49; // w2
  int v50; // w3
  char bonding_channels_for_freq; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  int v60; // w17
  char v61; // w21
  int v62; // w25
  _WORD *v63; // x23
  int v64; // w26
  int v65; // w24
  int v66; // w28
  int v67; // w27
  int v68; // w22
  int v69; // w23
  int v70; // w25
  int v71; // w26
  int v72; // w24
  int v73; // w28
  int v74; // w27
  int v75; // w22
  __int16 v76; // w8
  __int64 v77; // x5
  int v78; // w25
  _WORD *v79; // x26
  int v80; // w23
  int v81; // w24
  int v82; // w28
  int v83; // w27
  unsigned int v84; // w22
  int v85; // w21
  unsigned int v86; // w21
  int v87; // [xsp+1Ch] [xbp-44h]
  _WORD *v88; // [xsp+20h] [xbp-40h]
  char v89; // [xsp+20h] [xbp-40h]
  int v90; // [xsp+2Ch] [xbp-34h]
  __int64 v91; // [xsp+30h] [xbp-30h] BYREF
  __int64 v92; // [xsp+38h] [xbp-28h]
  __int64 v93; // [xsp+40h] [xbp-20h]
  __int64 v94; // [xsp+48h] [xbp-18h] BYREF
  __int64 v95; // [xsp+50h] [xbp-10h]
  __int64 v96; // [xsp+58h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 44) )
  {
    result = dfs_get_bonding_channel_without_seg_info_for_freq(
               *(_QWORD *)(a1 + 14888),
               a3,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12);
    if ( (_BYTE)result )
      goto LABEL_13;
  }
  v17 = *(_DWORD *)(a1 + 224);
  if ( v17 == 1 )
  {
    result = dfs_get_bonding_channel_without_seg_info_for_freq(
               *(_QWORD *)(a1 + 14888),
               a3,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12);
    goto LABEL_13;
  }
  if ( *(_BYTE *)(a1 + 14986) != 1 || v17 != 3 && v17 )
  {
    result = dfs_get_bonding_channels_for_freq(
               a1,
               *(_QWORD *)(a1 + 14888),
               *(_DWORD *)(a2 + 20),
               *(_DWORD *)(a2 + 16),
               a3,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12);
    goto LABEL_13;
  }
  v18 = *(_QWORD *)(a1 + 14888);
  v92 = 0;
  v93 = 0;
  v91 = 0;
  qdf_mem_set(&v91, 0x18u, 0);
  v27 = *(_DWORD *)(v18 + 8);
  HIDWORD(v92) = *(_DWORD *)(a2 + 8);
  LODWORD(v93) = HIDWORD(v92);
  HIDWORD(v93) = HIDWORD(v92);
  v28 = 32 * HIDWORD(v92) / 10;
  if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
  {
    qdf_trace_msg(
      0x27u,
      4u,
      "WLAN_DEBUG_DFS : %s: seg=%d, det=%d, sidx=%d, offset=%d, chirp=%d, flag=%d, f=%d",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "dfs_find_radar_affected_subchans_for_freq",
      *(unsigned int *)(a2 + 20),
      *(unsigned int *)(a2 + 16),
      (unsigned int)v28,
      *(_DWORD *)(a2 + 28),
      v27,
      a4);
    v29 = dfs_chan_to_ch_width(v18);
    if ( !v29 )
    {
      if ( !a1 )
      {
LABEL_19:
        qdf_trace_msg(
          0x27u,
          2u,
          "WLAN_DEBUG_DFS : %s: channel flag=%d is invalid",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "dfs_find_radar_affected_subchans_for_freq",
          v27);
        result = 0;
        goto LABEL_13;
      }
      goto LABEL_18;
    }
  }
  else
  {
    v29 = dfs_chan_to_ch_width(v18);
    if ( !v29 )
    {
LABEL_18:
      if ( (*(_BYTE *)(a1 + 1) & 1) != 0 )
        goto LABEL_19;
LABEL_57:
      result = 0;
      goto LABEL_13;
    }
  }
  if ( *(_DWORD *)(a2 + 28) || (v28 >= 0 ? (LOBYTE(v38) = v28) : (v38 = -v28), (v38 & 0x1F) == 0) )
  {
    LODWORD(v93) = v93 - 10;
    HIDWORD(v93) += 10;
  }
  v39 = (unsigned __int8)(v29 / 0x14u);
  if ( (unsigned __int8)(v29 / 0x14u) )
  {
    v40 = 0;
    v41 = a4 - (v29 >> 1) + 10;
    v42 = (unsigned __int16)(WORD2(v92) + a4);
    v43 = a4 - (v29 >> 1) + 10;
    while ( v43 >= v42 + 10 || v42 >= (unsigned int)v43 + 10 )
    {
      ++v40;
      v43 += 20;
      if ( v39 <= (unsigned __int16)v40 )
        goto LABEL_30;
    }
    LODWORD(v91) = v43;
LABEL_30:
    v44 = 0;
    v45 = a4 - (v29 >> 1) + 10;
    v46 = (unsigned __int16)(v93 + a4);
    while ( v45 >= v46 + 10 || v46 >= (unsigned int)v45 + 10 )
    {
      ++v44;
      v45 += 20;
      if ( v39 <= (unsigned __int16)v44 )
        goto LABEL_35;
    }
    HIDWORD(v91) = v45;
LABEL_35:
    v47 = 0;
    v48 = (unsigned __int16)(WORD2(v93) + a4);
    while ( (unsigned __int16)v41 >= v48 + 10 || v48 >= (unsigned int)(unsigned __int16)v41 + 10 )
    {
      ++v47;
      LOWORD(v41) = v41 + 20;
      if ( v39 <= (unsigned __int16)v47 )
        goto LABEL_40;
    }
    LODWORD(v92) = (unsigned __int16)v41;
  }
LABEL_40:
  v50 = *(_DWORD *)(a2 + 16);
  v49 = *(_DWORD *)(a2 + 20);
  v94 = 0;
  v95 = 0;
  bonding_channels_for_freq = dfs_get_bonding_channels_for_freq(
                                a1,
                                v18,
                                v49,
                                v50,
                                &v94,
                                v30,
                                v31,
                                v32,
                                v33,
                                v34,
                                v35,
                                v36,
                                v37);
  if ( !bonding_channels_for_freq )
    goto LABEL_57;
  v60 = (unsigned __int16)v94;
  v61 = bonding_channels_for_freq;
  v62 = WORD2(v94);
  v63 = a3 - 1;
  v64 = HIWORD(v94);
  v65 = (unsigned __int16)v95;
  v66 = WORD1(v95);
  v67 = WORD2(v95);
  v68 = HIWORD(v95);
  v90 = WORD1(v94);
  if ( (unsigned __int16)v94 == (unsigned __int16)v91 )
    goto LABEL_42;
  if ( bonding_channels_for_freq == 1 )
  {
    v76 = WORD2(v91);
    result = 0;
    if ( (unsigned __int16)v94 == WORD2(v91) )
      goto LABEL_60;
    goto LABEL_63;
  }
  if ( WORD1(v94) == (unsigned __int16)v91 )
    goto LABEL_42;
  if ( bonding_channels_for_freq != 2 )
  {
    if ( WORD2(v94) != (unsigned __int16)v91 )
    {
      if ( bonding_channels_for_freq == 3 )
        goto LABEL_82;
      if ( HIWORD(v94) != (unsigned __int16)v91 )
      {
        if ( bonding_channels_for_freq == 4 )
          goto LABEL_82;
        if ( (unsigned __int16)v95 != (unsigned __int16)v91 )
        {
          if ( bonding_channels_for_freq == 5 )
            goto LABEL_82;
          if ( WORD1(v95) != (unsigned __int16)v91 )
          {
            if ( bonding_channels_for_freq == 6 )
            {
LABEL_91:
              result = 0;
              v68 = HIWORD(v95);
              v67 = WORD2(v95);
              v66 = WORD1(v95);
              v65 = (unsigned __int16)v95;
              v63 = a3 - 1;
              v64 = HIWORD(v94);
              v62 = WORD2(v94);
              v60 = (unsigned __int16)v94;
              goto LABEL_46;
            }
            if ( WORD2(v95) != (unsigned __int16)v91 )
            {
              if ( bonding_channels_for_freq == 7 )
                goto LABEL_91;
              v68 = HIWORD(v95);
              v67 = WORD2(v95);
              v66 = WORD1(v95);
              v65 = (unsigned __int16)v95;
              v63 = a3 - 1;
              v64 = HIWORD(v94);
              v62 = WORD2(v94);
              v60 = (unsigned __int16)v94;
              if ( HIWORD(v95) != (unsigned __int16)v91 )
              {
                if ( bonding_channels_for_freq != 8 )
                  goto LABEL_109;
                goto LABEL_82;
              }
            }
          }
        }
      }
    }
LABEL_42:
    *a3 = v91;
    if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
    {
      v88 = v63;
      v69 = v62;
      v70 = v64;
      v71 = v65;
      v72 = v66;
      v73 = v67;
      v74 = v68;
      v75 = v60;
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS : %s: offset=%d, channel=%d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "dfs_find_radar_affected_subchans_for_freq",
        1);
      v60 = v75;
      v68 = v74;
      v67 = v73;
      v66 = v72;
      v65 = v71;
      v64 = v70;
      v62 = v69;
      v63 = v88;
    }
    result = 1;
    goto LABEL_46;
  }
LABEL_82:
  result = 0;
LABEL_46:
  v76 = WORD2(v91);
  if ( v60 == WORD2(v91) )
    goto LABEL_60;
  if ( v61 != 1 )
  {
    if ( v90 == WORD2(v91) )
      goto LABEL_60;
    if ( v61 != 2 )
    {
      if ( v62 == WORD2(v91) )
        goto LABEL_60;
      if ( v61 != 3 )
      {
        if ( v64 == WORD2(v91) )
          goto LABEL_60;
        if ( v61 != 4 )
        {
          if ( v65 != WORD2(v91) )
          {
            if ( v61 == 5 )
              goto LABEL_63;
            if ( v66 != WORD2(v91) )
            {
              if ( v61 == 6 )
                goto LABEL_63;
              if ( v67 != WORD2(v91) )
              {
                if ( v61 == 7 )
                  goto LABEL_63;
                if ( v68 != WORD2(v91) )
                {
                  if ( v61 != 8 )
                    goto LABEL_109;
                  goto LABEL_63;
                }
              }
            }
          }
LABEL_60:
          a3[(unsigned int)result] = v76;
          result = (unsigned int)(result + 1);
          if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
          {
            v77 = (unsigned __int16)v63[(unsigned int)result];
            v87 = v62;
            v89 = v61;
            v78 = v64;
            v79 = v63;
            v80 = v65;
            v81 = v66;
            v82 = v67;
            v83 = v68;
            v84 = result;
            v85 = v60;
            qdf_trace_msg(
              0x27u,
              4u,
              "WLAN_DEBUG_DFS : %s: offset=%d, channel=%d",
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              "dfs_find_radar_affected_subchans_for_freq",
              (unsigned int)result,
              v77);
            v60 = v85;
            result = v84;
            v68 = v83;
            v67 = v82;
            v66 = v81;
            v65 = v80;
            v63 = v79;
            v64 = v78;
            v62 = v87;
            v61 = v89;
          }
        }
      }
    }
  }
LABEL_63:
  if ( v60 != (unsigned __int16)v92 )
  {
    if ( v61 == 1 )
      goto LABEL_13;
    if ( v90 != (unsigned __int16)v92 )
    {
      if ( v61 == 2 )
        goto LABEL_13;
      if ( v62 != (unsigned __int16)v92 )
      {
        if ( v61 == 3 )
          goto LABEL_13;
        if ( v64 != (unsigned __int16)v92 )
        {
          if ( v61 == 4 )
            goto LABEL_13;
          if ( v65 != (unsigned __int16)v92 )
          {
            if ( v61 == 5 )
              goto LABEL_13;
            if ( v66 != (unsigned __int16)v92 )
            {
              if ( v61 == 6 )
              {
LABEL_79:
                result = (unsigned int)result;
                goto LABEL_13;
              }
              if ( v67 != (unsigned __int16)v92 )
              {
                if ( v61 == 7 )
                  goto LABEL_79;
                result = (unsigned int)result;
                if ( v68 != (unsigned __int16)v92 )
                {
                  if ( v61 == 8 )
                    goto LABEL_13;
LABEL_109:
                  __break(0x5512u);
                }
              }
            }
          }
        }
      }
    }
  }
  v86 = result + 1;
  a3[(unsigned int)result] = v92;
  if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
    qdf_trace_msg(
      0x27u,
      4u,
      "WLAN_DEBUG_DFS : %s: offset=%d, channel=%d",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "dfs_find_radar_affected_subchans_for_freq",
      v86,
      (unsigned __int16)v63[v86]);
  result = v86;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
