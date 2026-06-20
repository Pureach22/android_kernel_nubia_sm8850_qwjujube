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
  __int64 v18; // x23
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
  char bonding_channels_for_freq; // w21
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x24
  int v59; // w8
  unsigned int v60; // w27
  __int64 v61; // [xsp+20h] [xbp-40h] BYREF
  __int64 v62; // [xsp+28h] [xbp-38h]
  __int64 v63; // [xsp+30h] [xbp-30h]
  __int64 v64; // [xsp+38h] [xbp-28h] BYREF
  __int64 v65; // [xsp+40h] [xbp-20h]
  __int64 v66; // [xsp+48h] [xbp-18h]
  __int64 v67; // [xsp+50h] [xbp-10h]
  __int64 v68; // [xsp+58h] [xbp-8h]

  v68 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_BYTE *)(a2 + 44)
    || (result = dfs_get_bonding_channel_without_seg_info_for_freq(*(_QWORD *)(a1 + 14888), a3), !(_BYTE)result) )
  {
    v17 = *(_DWORD *)(a1 + 224);
    if ( v17 == 1 )
    {
      result = dfs_get_bonding_channel_without_seg_info_for_freq(*(_QWORD *)(a1 + 14888), a3);
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
    v66 = 0;
    v67 = 0;
    v64 = 0;
    v65 = 0;
    v62 = 0;
    v63 = 0;
    v61 = 0;
    qdf_mem_set(&v61, 0x18u, 0);
    v27 = *(_DWORD *)(v18 + 8);
    HIDWORD(v62) = *(_DWORD *)(a2 + 8);
    LODWORD(v63) = HIDWORD(v62);
    HIDWORD(v63) = HIDWORD(v62);
    v28 = 32 * HIDWORD(v62) / 10;
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
          goto LABEL_20;
        goto LABEL_18;
      }
    }
    else
    {
      v29 = dfs_chan_to_ch_width(v18);
      if ( !v29 )
      {
LABEL_18:
        if ( (*(_BYTE *)(a1 + 1) & 1) == 0 )
        {
          result = 0;
          goto LABEL_13;
        }
LABEL_20:
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
    }
    if ( *(_DWORD *)(a2 + 28) || (v28 >= 0 ? (LOBYTE(v38) = v28) : (v38 = -v28), (v38 & 0x1F) == 0) )
    {
      LODWORD(v63) = v63 - 10;
      HIDWORD(v63) += 10;
    }
    v39 = (unsigned __int8)(v29 / 0x14u);
    if ( (unsigned __int8)(v29 / 0x14u) )
    {
      v40 = 0;
      v41 = a4 - (v29 >> 1) + 10;
      v42 = (unsigned __int16)(WORD2(v62) + a4);
      v43 = a4 - (v29 >> 1) + 10;
      while ( v43 >= v42 + 10 || v42 >= (unsigned int)v43 + 10 )
      {
        ++v40;
        v43 += 20;
        if ( v39 <= (unsigned __int16)v40 )
          goto LABEL_31;
      }
      LODWORD(v61) = v43;
LABEL_31:
      v44 = 0;
      v45 = a4 - (v29 >> 1) + 10;
      v46 = (unsigned __int16)(v63 + a4);
      while ( v45 >= v46 + 10 || v46 >= (unsigned int)v45 + 10 )
      {
        ++v44;
        v45 += 20;
        if ( v39 <= (unsigned __int16)v44 )
          goto LABEL_36;
      }
      HIDWORD(v61) = v45;
LABEL_36:
      v47 = 0;
      v48 = (unsigned __int16)(WORD2(v63) + a4);
      while ( (unsigned __int16)v41 >= v48 + 10 || v48 >= (unsigned int)(unsigned __int16)v41 + 10 )
      {
        ++v47;
        LOWORD(v41) = v41 + 20;
        if ( v39 <= (unsigned __int16)v47 )
          goto LABEL_41;
      }
      LODWORD(v62) = (unsigned __int16)v41;
    }
LABEL_41:
    bonding_channels_for_freq = dfs_get_bonding_channels_for_freq(
                                  a1,
                                  v18,
                                  *(_DWORD *)(a2 + 20),
                                  *(_DWORD *)(a2 + 16),
                                  &v64,
                                  v30,
                                  v31,
                                  v32,
                                  v33,
                                  v34,
                                  v35,
                                  v36,
                                  v37);
    v58 = 0;
    result = 0;
    while ( 1 )
    {
      if ( bonding_channels_for_freq )
      {
        v59 = *(unsigned __int16 *)((char *)&v61 + v58);
        if ( (unsigned __int16)v64 == v59 )
          goto LABEL_47;
        if ( bonding_channels_for_freq != 1 )
        {
          if ( WORD1(v64) == v59 )
            goto LABEL_47;
          if ( bonding_channels_for_freq != 2 )
          {
            if ( WORD2(v64) == v59 )
              goto LABEL_47;
            if ( bonding_channels_for_freq != 3 )
            {
              if ( HIWORD(v64) == v59 )
                goto LABEL_47;
              if ( bonding_channels_for_freq != 4 )
              {
                if ( (unsigned __int16)v65 == v59 )
                  goto LABEL_47;
                if ( bonding_channels_for_freq != 5 )
                {
                  if ( WORD1(v65) == v59 )
                    goto LABEL_47;
                  if ( bonding_channels_for_freq != 6 )
                  {
                    if ( WORD2(v65) == v59 )
                      goto LABEL_47;
                    if ( bonding_channels_for_freq != 7 )
                    {
                      if ( HIWORD(v65) == v59 )
                        goto LABEL_47;
                      if ( bonding_channels_for_freq != 8 )
                      {
                        if ( (unsigned __int16)v66 == v59 )
                          goto LABEL_47;
                        if ( bonding_channels_for_freq != 9 )
                        {
                          if ( WORD1(v66) == v59 )
                            goto LABEL_47;
                          if ( bonding_channels_for_freq != 10 )
                          {
                            if ( WORD2(v66) == v59 )
                              goto LABEL_47;
                            if ( bonding_channels_for_freq != 11 )
                            {
                              if ( HIWORD(v66) == v59 )
                                goto LABEL_47;
                              if ( bonding_channels_for_freq != 12 )
                              {
                                if ( (unsigned __int16)v67 == v59 )
                                  goto LABEL_47;
                                if ( bonding_channels_for_freq != 13 )
                                {
                                  if ( WORD1(v67) == v59 )
                                    goto LABEL_47;
                                  if ( bonding_channels_for_freq != 14 )
                                  {
                                    if ( WORD2(v67) == v59 )
                                      goto LABEL_47;
                                    if ( bonding_channels_for_freq != 15 )
                                      break;
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
LABEL_44:
      v58 += 4;
      if ( v58 == 12 )
        goto LABEL_13;
    }
    if ( HIWORD(v67) != v59 )
    {
      if ( bonding_channels_for_freq != 16 )
        __break(0x5512u);
      goto LABEL_44;
    }
LABEL_47:
    v60 = result + 1;
    a3[(unsigned __int8)result] = v59;
    if ( !a1 || (*(_BYTE *)(a1 + 1) & 1) != 0 )
      qdf_trace_msg(
        0x27u,
        4u,
        "WLAN_DEBUG_DFS : %s: offset=%d, channel=%d",
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        "dfs_find_radar_affected_subchans_for_freq",
        (unsigned __int8)(result + 1),
        (unsigned __int16)a3[(unsigned __int8)(result + 1) - 1]);
    result = v60;
    goto LABEL_44;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
