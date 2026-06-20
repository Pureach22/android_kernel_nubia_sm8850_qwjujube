__int64 __fastcall reg_set_channel_params_for_pwrmode(
        __int64 result,
        unsigned int a2,
        unsigned __int16 a3,
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
  __int64 v17; // x20
  __int16 v18; // w9
  unsigned int v19; // w23
  __int16 v20; // w10
  unsigned int v21; // w24
  unsigned int v22; // w12
  __int64 v23; // x20
  const char *v24; // x2
  unsigned __int16 v25; // w27
  int v26; // w8
  __int64 v27; // x10
  __int64 v28; // x13
  unsigned int i; // w2
  __int16 v30; // w9
  unsigned int v31; // w4
  __int16 v32; // w10
  unsigned int v33; // w1
  unsigned int v34; // w12
  __int64 v35; // x20
  unsigned __int16 v36; // w1
  unsigned int v37; // w8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w26
  int v47; // w8
  __int64 v48; // x1
  unsigned int v49; // w9
  __int64 v51; // x9
  unsigned __int16 *v52; // x9
  char v53; // w8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w8
  unsigned int v63; // w1
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  unsigned int v80; // w1
  int v81; // [xsp+8h] [xbp-28h] BYREF
  __int64 v82; // [xsp+Ch] [xbp-24h]
  int v83; // [xsp+14h] [xbp-1Ch]
  _WORD v84[2]; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int16 v85; // [xsp+1Ch] [xbp-14h] BYREF
  _QWORD v86[2]; // [xsp+20h] [xbp-10h] BYREF

  v17 = result;
  v86[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_DWORD *)(channel_map + 168) > a2 || *(_DWORD *)(channel_map + 492) < a2)
    && (*(_DWORD *)(channel_map + 504) > (unsigned int)(unsigned __int16)a2
     || *(_DWORD *)(channel_map + 1212) < (unsigned int)(unsigned __int16)a2) )
  {
    if ( *(_DWORD *)channel_map <= a2 && *(_DWORD *)(channel_map + 156) >= a2 )
      result = reg_set_2g_channel_params_for_freq(
                 result,
                 a2,
                 (unsigned int *)a4,
                 a3,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 a14);
    goto LABEL_21;
  }
  v85 = 0;
  v84[0] = 0;
  if ( !a4 )
  {
    v24 = "%s: ch_params is NULL";
LABEL_20:
    result = qdf_trace_msg(0x51u, 2u, v24, a7, a8, a9, a10, a11, a12, a13, a14, "reg_set_5g_channel_params_for_pwrmode");
LABEL_21:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v18 = 0;
  v19 = (unsigned __int16)a2;
  v20 = 101;
  while ( 1 )
  {
    v21 = (v18 + v20) / 2;
    v22 = *(_DWORD *)(channel_map + 12LL * (int)v21);
    if ( v22 == (unsigned __int16)a2 )
      break;
    if ( v22 >= (unsigned __int16)a2 )
      v20 = v21 - 1;
    else
      v18 = v21 + 1;
    if ( v18 > v20 )
    {
      v23 = jiffies;
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
          (unsigned __int16)a2);
        reg_get_chan_enum_for_freq___last_ticks = v23;
      }
      goto LABEL_19;
    }
  }
  if ( v21 >= 0x66 )
  {
LABEL_19:
    v24 = "%s: chan freq is not valid";
    goto LABEL_20;
  }
  v25 = a2;
  if ( !reg_get_pdev_obj(result, a7, a8, a9, a10, a11, a12, a13, a14) )
  {
    v24 = "%s: reg pdev priv obj is NULL";
    goto LABEL_20;
  }
  if ( *(_DWORD *)a4 >= 9u )
  {
    if ( *(_DWORD *)(a4 + 12) )
      v26 = 4;
    else
      v26 = 3;
    *(_DWORD *)a4 = v26;
  }
  result = reg_get_min_max_bw_reg_chan_list(v17, v21, a5, nullptr, &v85, a7, a8, a9, a10, a11, a12, a13, a14);
  if ( (_DWORD)result )
    goto LABEL_21;
  i = *(_DWORD *)a4;
  if ( *(_DWORD *)a4 == 4 )
  {
    v30 = 0;
    v31 = *(_DWORD *)(a4 + 12) - 10;
    v32 = 101;
    while ( 1 )
    {
      v33 = (v30 + v32) / 2;
      v34 = *(_DWORD *)(channel_map + 12LL * (int)v33);
      if ( v34 == v31 )
        break;
      if ( v34 >= v31 )
        v32 = v33 - 1;
      else
        v30 = v33 + 1;
      if ( v30 > v32 )
      {
        v35 = jiffies;
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
          reg_get_chan_enum_for_freq___last_ticks = v35;
        }
        goto LABEL_40;
      }
    }
    if ( v33 >= 0x66 )
    {
LABEL_40:
      v24 = "%s: secondary channel freq is not valid";
      goto LABEL_20;
    }
    result = reg_get_min_max_bw_reg_chan_list(v17, v33, a5, nullptr, v84, a7, a8, a9, a10, a11, a12, a13, a14);
    if ( (_DWORD)result )
      goto LABEL_21;
    i = *(_DWORD *)a4;
  }
  v36 = v25;
  if ( i == 4 )
    goto LABEL_51;
  while ( 1 )
  {
    if ( i == 8 )
      goto LABEL_90;
    if ( i <= 9 && ((0x26Fu >> i) & 1) != 0 && v85 < (unsigned int)word_9E63AC[i] )
    {
      v37 = i;
    }
    else
    {
LABEL_53:
      v86[0] = 0;
      reg_get_5g_bonded_channel_for_pwrmode(v17, v36, i, v86, a5, a7, a8, a9, a10, a11, a12, a13, a14);
      if ( (a6 & 1) != 0 )
        result = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(v17, v19, a4, a5);
      else
        result = reg_get_5g_chan_state(v17, v19, *(_DWORD *)a4, a5, v38, v39, v40, v41, v42, v43, v44, v45);
      v37 = *(_DWORD *)a4;
      v46 = result;
      if ( *(_DWORD *)a4 == 4 )
      {
        v47 = *(_DWORD *)(a4 + 12);
        v83 = 0;
        v82 = 0;
        v48 = (unsigned int)(v47 - 10);
        v81 = 2;
        if ( (a6 & 1) != 0 )
          result = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(v17, v48, &v81, a5);
        else
          result = reg_get_5g_chan_state(v17, v48, 2, a5, a7, a8, a9, a10, a11, a12, a13, a14);
        v37 = *(_DWORD *)a4;
        v27 = 4;
        if ( v46 >= (unsigned int)result )
          v49 = result;
        else
          v49 = v46;
        if ( (_DWORD)result == 4 || v46 == 4 )
          v46 = 4;
        else
          v46 = v49;
      }
      v36 = v25;
      if ( v46 - 4 >= 0xFFFFFFFE )
      {
        if ( !v37 )
        {
          *(_BYTE *)(a4 + 4) = 0;
          goto LABEL_87;
        }
        v51 = 0;
        while ( 1 )
        {
          v27 = *(unsigned __int16 *)((char *)&bonded_chan_40mhz_list_freq + v51);
          if ( (unsigned int)v27 <= v25
            && *(unsigned __int16 *)((char *)&bonded_chan_40mhz_list_freq + v51 + 2) >= (unsigned int)v25 )
          {
            break;
          }
          v51 += 4;
          if ( v51 == 172 )
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
                       v19,
                       1,
                       0);
            v37 = *(_DWORD *)a4;
            v36 = v25;
            goto LABEL_79;
          }
        }
        if ( (char *)&bonded_chan_40mhz_list_freq + v51 )
        {
          v52 = (unsigned __int16 *)v86[0];
          if ( v86[0] )
          {
            if ( (_DWORD)v27 == v25 )
              v53 = 1;
            else
              v53 = 3;
            *(_BYTE *)(a4 + 4) = v53;
            v19 = (*(unsigned __int16 *)((char *)&off_0 + (_QWORD)v52 + 2) + (unsigned int)*v52) >> 1;
LABEL_87:
            *(_DWORD *)(a4 + 8) = v19;
            result = reg_freq_to_chan(v17, v19, a7, a8, a9, a10, a11, a12, a13, a14);
            v62 = *(_DWORD *)a4;
            *(_BYTE *)(a4 + 5) = result;
            if ( v62 == 3 )
            {
              v63 = *(_DWORD *)(a4 + 8);
              *(_DWORD *)(a4 + 12) = v63;
              *(_BYTE *)(a4 + 6) = reg_freq_to_chan(v17, v63, v54, v55, v56, v57, v58, v59, v60, v61);
              result = reg_get_5g_bonded_channel_for_pwrmode(
                         v17,
                         v25,
                         2,
                         v86,
                         a5,
                         v64,
                         v65,
                         v66,
                         v67,
                         v68,
                         v69,
                         v70,
                         v71);
              if ( v86[0] )
              {
                v80 = (*(unsigned __int16 *)(v86[0] + 2LL) + (unsigned int)*(unsigned __int16 *)v86[0]) >> 1;
                *(_DWORD *)(a4 + 8) = v80;
                result = reg_freq_to_chan(v17, v80, v72, v73, v74, v75, v76, v77, v78, v79);
                *(_BYTE *)(a4 + 5) = result;
              }
            }
LABEL_90:
            if ( (unsigned int)(*(_DWORD *)a4 - 3) >= 2 )
            {
              *(_DWORD *)(a4 + 12) = 0;
              *(_BYTE *)(a4 + 6) = 0;
            }
            goto LABEL_21;
          }
        }
      }
    }
LABEL_79:
    if ( v37 <= 7 )
      break;
    for ( i = 8; ; i = get_next_lower_bandwidth_get_next_lower_bw[v37] )
    {
      *(_DWORD *)a4 = i;
      if ( i != 4 )
        break;
LABEL_51:
      v37 = 4;
      if ( v85 >= 0x50u && v84[0] >= 0x50u )
        goto LABEL_53;
LABEL_81:
      ;
    }
  }
  if ( v37 != 7 )
    goto LABEL_81;
  __break(0x5512u);
  return reg_get_channel_reg_power_for_freq(result, v28 + __ROR8__(v27, 46));
}
