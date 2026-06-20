__int64 __fastcall reg_set_channel_params_for_pwrmode(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v17; // x23
  unsigned int v18; // w24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w8
  int v29; // w3
  int v30; // w9
  int v31; // w10
  int v32; // w8
  unsigned __int64 v33; // x25
  __int16 v34; // w9
  __int16 v35; // w10
  unsigned int v36; // w26
  unsigned int v37; // w12
  __int64 v38; // x25
  const char *v39; // x2
  unsigned int v40; // w8
  __int16 v41; // w12
  int v42; // w11
  unsigned int v43; // w10
  int v44; // w11
  unsigned int v45; // w9
  unsigned __int8 v46; // w11
  unsigned int v47; // w10
  unsigned int v48; // w12
  char v49; // w9
  _BOOL4 v50; // w9
  int v51; // w8
  unsigned int v52; // w2
  __int16 v53; // w9
  unsigned int v54; // w4
  __int16 v55; // w10
  unsigned int v56; // w1
  unsigned int v57; // w12
  __int64 v58; // x25
  int v59; // w8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w28
  int v69; // w8
  __int64 v70; // x1
  unsigned int v71; // w8
  bool v72; // zf
  __int64 v73; // x8
  unsigned int v74; // w9
  unsigned __int16 *v75; // x8
  unsigned int v76; // w1
  char v77; // w9
  unsigned int v78; // w8
  unsigned int v79; // w1
  __int64 v80; // x8
  unsigned int v81; // w21
  unsigned int v82; // w27
  char v83; // w28
  unsigned __int16 v84; // w26
  __int64 v85; // x25
  unsigned int v86; // w1
  _WORD v88[2]; // [xsp+10h] [xbp-50h] BYREF
  unsigned __int8 v89[4]; // [xsp+14h] [xbp-4Ch] BYREF
  unsigned __int16 *v90; // [xsp+18h] [xbp-48h] BYREF
  _QWORD v91[3]; // [xsp+20h] [xbp-40h] BYREF
  __int64 v92; // [xsp+38h] [xbp-28h]
  __int64 v93; // [xsp+40h] [xbp-20h]
  __int64 v94; // [xsp+48h] [xbp-18h]
  int v95; // [xsp+50h] [xbp-10h]
  __int64 v96; // [xsp+58h] [xbp-8h]

  v17 = result;
  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)channel_map <= a2 && *(_DWORD *)(channel_map + 156) >= a2 )
  {
    result = reg_set_2g_channel_params_for_freq(result, a2, a4, a3, a7, a8, a9, a10, a11, a12, a13, a14);
    goto LABEL_78;
  }
  if ( *(_DWORD *)(channel_map + 168) <= a2 && *(_DWORD *)(channel_map + 492) >= a2 )
  {
    v18 = (unsigned __int16)a2;
  }
  else
  {
    v18 = (unsigned __int16)a2;
    if ( *(_DWORD *)(channel_map + 504) > (unsigned int)(unsigned __int16)a2
      || *(_DWORD *)(channel_map + 1212) < (unsigned int)(unsigned __int16)a2 )
    {
      goto LABEL_78;
    }
  }
  if ( *(_DWORD *)a4 == 7 )
  {
    v95 = 0;
    v93 = 0;
    v94 = 0;
    v92 = 0;
    memset(v91, 0, sizeof(v91));
    qdf_mem_set(v91, 0x34u, 0);
    v28 = *(_DWORD *)a4;
    v29 = *(_DWORD *)(a4 + 12);
    WORD1(v92) = *(_WORD *)(a4 + 22);
    HIWORD(v95) = WORD1(v92);
    LODWORD(v90) = v28;
    if ( v28 < 9 )
    {
      if ( v28 != 7 )
        goto LABEL_16;
    }
    else
    {
      LODWORD(v90) = 7;
    }
    v89[0] = 0;
    result = reg_fill_channel_list_for_320_for_pwrmode(
               v17,
               a2,
               (unsigned int *)&v90,
               v29,
               v91,
               v89,
               a5,
               a6 & 1,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27);
    if ( v89[0] != 1 )
    {
LABEL_17:
      v30 = HIDWORD(v91[1]);
      v31 = v91[2];
      *(_BYTE *)(a4 + 6) = BYTE2(v91[1]);
      v32 = HIDWORD(v91[0]);
      *(_DWORD *)(a4 + 8) = v30;
      *(_DWORD *)(a4 + 12) = v31;
      LOWORD(v30) = v91[1];
      LOWORD(v31) = HIWORD(v91[2]);
      *(_DWORD *)a4 = v32;
      *(_WORD *)(a4 + 4) = v30;
      *(_WORD *)(a4 + 18) = v31;
      goto LABEL_31;
    }
    v28 = (unsigned int)v90;
LABEL_16:
    HIDWORD(v91[0]) = v28;
    LOBYTE(v91[0]) = 1;
    HIWORD(v91[2]) = 0;
    result = reg_set_channel_params_for_pwrmode(v17, a2, a3, (char *)v91 + 4, a5, a6 & 1);
    goto LABEL_17;
  }
  while ( 1 )
  {
    *(_WORD *)v89 = 0;
    v88[0] = 0;
    if ( !a4 )
    {
      v39 = "%s: ch_params is NULL";
LABEL_30:
      result = qdf_trace_msg(
                 0x51u,
                 2u,
                 v39,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 a14,
                 "reg_set_5g_channel_params_for_pwrmode");
      goto LABEL_31;
    }
    v33 = *(unsigned __int16 *)(a4 + 22);
    v34 = 0;
    v35 = 101;
    while ( 1 )
    {
      v36 = (v34 + v35) / 2;
      v37 = *(_DWORD *)(channel_map + 12LL * (int)v36);
      if ( v37 == v18 )
        break;
      if ( v37 >= v18 )
        v35 = v36 - 1;
      else
        v34 = v36 + 1;
      if ( v34 > v35 )
      {
        v38 = jiffies;
        if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x51u,
            8u,
            "%s: invalid channel center frequency %d",
            a7,
            a8,
            a9,
            a10,
            a11,
            a12,
            a13,
            a14,
            "reg_get_chan_enum_for_freq",
            v18);
          reg_get_chan_enum_for_freq___last_ticks = v38;
        }
LABEL_29:
        v39 = "%s: chan freq is not valid";
        goto LABEL_30;
      }
    }
    if ( v36 >= 0x66 )
      goto LABEL_29;
    if ( !reg_get_pdev_obj(v17, a7, a8, a9, a10, a11, a12, a13, a14) )
    {
      v39 = "%s: reg pdev priv obj is NULL";
      goto LABEL_30;
    }
    if ( *(_DWORD *)a4 >= 9u )
    {
      if ( *(_DWORD *)(a4 + 12) )
        v51 = 4;
      else
        v51 = 3;
      *(_DWORD *)a4 = v51;
    }
    result = reg_get_min_max_bw_reg_chan_list(v17, v36, a5, nullptr, v89, a7, a8, a9, a10, a11, a12, a13, a14);
    if ( !(_DWORD)result )
    {
      v52 = *(_DWORD *)a4;
      if ( *(_DWORD *)a4 != 4 )
        goto LABEL_83;
      v53 = 0;
      v54 = *(_DWORD *)(a4 + 12) - 10;
      v55 = 101;
      while ( 1 )
      {
        v56 = (v53 + v55) / 2;
        v57 = *(_DWORD *)(channel_map + 12LL * (int)v56);
        if ( v57 == v54 )
          break;
        if ( v57 >= v54 )
          v55 = v56 - 1;
        else
          v53 = v56 + 1;
        if ( v53 > v55 )
        {
          v58 = jiffies;
          if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x51u,
              8u,
              "%s: invalid channel center frequency %d",
              a7,
              a8,
              a9,
              a10,
              a11,
              a12,
              a13,
              a14,
              "reg_get_chan_enum_for_freq");
            reg_get_chan_enum_for_freq___last_ticks = v58;
          }
LABEL_80:
          v39 = "%s: secondary channel freq is not valid";
          goto LABEL_30;
        }
      }
      if ( v56 >= 0x66 )
        goto LABEL_80;
      result = reg_get_min_max_bw_reg_chan_list(v17, v56, a5, nullptr, v88, a7, a8, a9, a10, a11, a12, a13, a14);
      if ( !(_DWORD)result )
      {
        v52 = *(_DWORD *)a4;
LABEL_83:
        if ( v52 == 4 )
          goto LABEL_89;
LABEL_121:
        if ( v52 == 8 )
          goto LABEL_142;
        if ( v52 > 9 || ((0x2EFu >> v52) & 1) == 0 || *(unsigned __int16 *)v89 >= (unsigned int)word_AD81B0[v52] )
          goto LABEL_91;
LABEL_117:
        while ( 1 )
        {
          v59 = v52;
          if ( v52 <= 7 )
            break;
          v52 = 8;
LABEL_120:
          *(_DWORD *)a4 = v52;
          if ( v52 != 4 )
            goto LABEL_121;
LABEL_89:
          v59 = 4;
          if ( *(unsigned __int16 *)v89 < 0x50u || v88[0] < 0x50u )
            break;
LABEL_91:
          v90 = nullptr;
          reg_get_5g_bonded_channel_for_pwrmode(v17, a2, v52, &v90, a5, v33, a7, a8, a9, a10, a11, a12, a13, a14);
          if ( (a6 & 1) != 0 )
            result = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(v17, v18);
          else
            result = reg_get_5g_chan_state(
                       v17,
                       v18,
                       *(_DWORD *)a4,
                       a5,
                       *(_WORD *)(a4 + 22),
                       v60,
                       v61,
                       v62,
                       v63,
                       v64,
                       v65,
                       v66,
                       v67);
          v52 = *(_DWORD *)a4;
          v68 = result;
          if ( *(_DWORD *)a4 == 4 )
          {
            v69 = *(_DWORD *)(a4 + 12);
            LODWORD(v91[0]) = 2;
            v70 = (unsigned int)(v69 - 10);
            memset((char *)v91 + 4, 0, 20);
            if ( (a6 & 1) != 0 )
              result = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(v17, v70);
            else
              result = reg_get_5g_chan_state(v17, v70, 2u, a5, 0, a7, a8, a9, a10, a11, a12, a13, a14);
            v52 = *(_DWORD *)a4;
            if ( v68 >= (unsigned int)result )
              v71 = result;
            else
              v71 = v68;
            v72 = (_DWORD)result == 4 || v68 == 4;
            if ( v72 )
              v68 = 4;
            else
              v68 = v71;
          }
          if ( v68 - 4 >= 0xFFFFFFFE )
          {
            if ( !v52 )
            {
              v76 = v18;
              *(_BYTE *)(a4 + 4) = 0;
              goto LABEL_128;
            }
            v73 = 0;
            while ( 1 )
            {
              v74 = *(unsigned __int16 *)((char *)&bonded_chan_40mhz_list_freq + v73);
              if ( v74 <= (unsigned __int16)a2
                && *(unsigned __int16 *)((char *)&bonded_chan_40mhz_list_freq + v73 + 2) >= (unsigned int)(unsigned __int16)a2 )
              {
                break;
              }
              v73 += 4;
              if ( v73 == 172 )
              {
                result = qdf_trace_msg(
                           0x51u,
                           8u,
                           "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
                           a7,
                           a8,
                           a9,
                           a10,
                           a11,
                           a12,
                           a13,
                           a14,
                           "reg_get_bonded_chan_entry",
                           v18,
                           1,
                           0);
                v52 = *(_DWORD *)a4;
                goto LABEL_117;
              }
            }
            if ( (char *)&bonded_chan_40mhz_list_freq + v73 )
            {
              v75 = v90;
              if ( v90 )
              {
                if ( v74 == (unsigned __int16)a2 )
                  v77 = 1;
                else
                  v77 = 3;
                *(_BYTE *)(a4 + 4) = v77;
                v76 = (*(unsigned __int16 *)((char *)&off_0 + (_QWORD)v75 + 2) + (unsigned int)*v75) >> 1;
LABEL_128:
                *(_DWORD *)(a4 + 8) = v76;
                result = reg_freq_to_chan(v17, v76, a7, a8, a9, a10, a11, a12, a13, a14);
                v78 = *(_DWORD *)a4;
                *(_BYTE *)(a4 + 5) = result;
                if ( v78 == 3 )
                {
                  v79 = *(_DWORD *)(a4 + 8);
                  *(_DWORD *)(a4 + 12) = v79;
                  result = reg_freq_to_chan(v17, v79, a7, a8, a9, a10, a11, a12, a13, a14);
                  v80 = 0;
                  *(_BYTE *)(a4 + 6) = result;
                  while ( 1 )
                  {
                    v81 = *(unsigned __int16 *)((char *)&bonded_chan_80mhz_list_freq + v80);
                    if ( v81 <= (unsigned __int16)a2 )
                    {
                      v82 = *(unsigned __int16 *)((char *)&bonded_chan_80mhz_list_freq + v80 + 2);
                      if ( v82 >= (unsigned __int16)a2 )
                        break;
                    }
                    v80 += 4;
                    if ( v80 == 84 )
                    {
                      result = qdf_trace_msg(
                                 0x51u,
                                 8u,
                                 "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
                                 a7,
                                 a8,
                                 a9,
                                 a10,
                                 a11,
                                 a12,
                                 a13,
                                 a14,
                                 "reg_get_bonded_chan_entry",
                                 v18,
                                 2,
                                 0);
                      goto LABEL_139;
                    }
                  }
                  if ( (char *)&bonded_chan_80mhz_list_freq + v80 )
                  {
                    v83 = 0;
                    v84 = *(_WORD *)((char *)&bonded_chan_80mhz_list_freq + v80);
                    do
                    {
                      if ( ((v33 >> v83) & 1) == 0 )
                        reg_get_channel_state_for_pwrmode(v17, v84, a5, a7, a8, a9, a10, a11, a12, a13, a14);
                      v84 += 20;
                      ++v83;
                    }
                    while ( v82 >= v84 );
                    v86 = (v82 + v81) >> 1;
                    *(_DWORD *)(a4 + 8) = v86;
                    result = reg_freq_to_chan(v17, v86, a7, a8, a9, a10, a11, a12, a13, a14);
                    *(_BYTE *)(a4 + 5) = result;
                    goto LABEL_142;
                  }
LABEL_139:
                  v85 = jiffies;
                  if ( reg_get_5g_bonded_channel_for_pwrmode___last_ticks - jiffies + 125 < 0 )
                  {
                    result = qdf_trace_msg(
                               0x51u,
                               8u,
                               "%s: bonded_chan_ptr_ptr is NULL",
                               a7,
                               a8,
                               a9,
                               a10,
                               a11,
                               a12,
                               a13,
                               a14,
                               "reg_get_5g_bonded_channel_for_pwrmode");
                    reg_get_5g_bonded_channel_for_pwrmode___last_ticks = v85;
                  }
                }
LABEL_142:
                if ( (unsigned int)(*(_DWORD *)a4 - 3) >= 2 )
                {
                  *(_DWORD *)(a4 + 12) = 0;
                  *(_BYTE *)(a4 + 6) = 0;
                }
                goto LABEL_31;
              }
            }
          }
        }
        v52 = get_next_lower_bandwidth_get_next_lower_bw[v59];
        goto LABEL_120;
      }
    }
LABEL_31:
    if ( !a2 || *(_BYTE *)(a4 + 16) != 1 )
      goto LABEL_78;
    v40 = *(_DWORD *)a4;
    if ( (unsigned int)(*(_DWORD *)a4 - 2) < 3 || v40 == 9 )
      break;
    if ( v40 != 7 )
      goto LABEL_78;
    v41 = *(_WORD *)(a4 + 22);
    v42 = 3;
    if ( v41 )
    {
      v43 = *(_DWORD *)(a4 + 8);
      if ( v43 < a2 )
        v44 = 40;
      else
        v44 = -40;
      v45 = v44 + v43;
      if ( v43 <= *(_DWORD *)(a4 + 12) )
        v46 = v41;
      else
        v46 = HIBYTE(v41);
      goto LABEL_47;
    }
LABEL_57:
    *(_WORD *)(a4 + 22) = 0;
    if ( v42 == v40 )
      goto LABEL_77;
    *(_DWORD *)a4 = v42;
  }
  v45 = *(_DWORD *)(a4 + 8);
  if ( v40 == 3 )
  {
    v43 = *(_DWORD *)(a4 + 12);
    v46 = *(_BYTE *)(a4 + 22);
LABEL_47:
    v48 = v46;
    v72 = v46 == 0;
    v42 = 3;
    if ( v72 )
      goto LABEL_57;
    if ( v45 <= v43 )
      v47 = v48;
    else
      v47 = v48 >> 4;
    goto LABEL_51;
  }
  if ( v40 == 2 )
  {
    v47 = *(unsigned __int16 *)(a4 + 22);
LABEL_51:
    if ( v45 >= a2 )
      v49 = v47;
    else
      v49 = v47 >> 2;
    v50 = (v49 & 3) == 0;
    if ( (v47 & 0xF) != 0 )
      v42 = v50;
    else
      v42 = 2;
    goto LABEL_57;
  }
  *(_WORD *)(a4 + 22) = 0;
LABEL_77:
  *(_BYTE *)(a4 + 16) = 0;
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return result;
}
