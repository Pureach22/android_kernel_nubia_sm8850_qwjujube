__int64 __fastcall reg_fill_channel_list_for_320_for_pwrmode(
        __int64 a1,
        unsigned int a2,
        unsigned int *a3,
        int a4,
        _BYTE *a5,
        _BYTE *a6,
        unsigned int a7,
        char a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  __int16 v20; // w8
  __int16 v21; // w10
  unsigned int v22; // w25
  unsigned int v23; // w12
  __int64 v24; // x21
  const char *v25; // x2
  __int64 result; // x0
  __int64 v29; // x3
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x9
  unsigned int v39; // w9
  unsigned int *v40; // x13
  _BYTE *v41; // x9
  char v42; // w22
  void *v43; // x11
  unsigned int v44; // w10
  unsigned __int16 *v45; // x9
  _BOOL4 v46; // w9
  __int64 v47; // x25
  unsigned int v48; // w28
  int v49; // w8
  __int64 v50; // x26
  unsigned __int16 **v51; // x19
  unsigned int v52; // w1
  unsigned __int16 *v53; // x27
  __int64 v54; // x22
  unsigned int v55; // w1
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w8
  unsigned __int16 *v65; // x8
  __int64 v66; // x8
  unsigned int v67; // w8
  __int64 v68; // x8
  int v69; // [xsp+Ch] [xbp-54h]
  unsigned __int16 *v70; // [xsp+10h] [xbp-50h]
  unsigned int v71; // [xsp+18h] [xbp-48h]
  unsigned int *v73; // [xsp+30h] [xbp-30h]
  unsigned int v74; // [xsp+38h] [xbp-28h]
  unsigned __int16 v76[2]; // [xsp+40h] [xbp-20h] BYREF
  __int16 v77; // [xsp+44h] [xbp-1Ch] BYREF
  _QWORD v78[3]; // [xsp+48h] [xbp-18h] BYREF

  v20 = 0;
  v21 = 101;
  v78[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a6 = 0;
  v76[0] = 0;
  v78[0] = 0;
  v78[1] = 0;
  while ( 1 )
  {
    v22 = (v20 + v21) / 2;
    v23 = *(_DWORD *)(channel_map + 12LL * (int)v22);
    if ( v23 == a2 )
      break;
    if ( v23 >= a2 )
      v21 = v22 - 1;
    else
      v20 = v22 + 1;
    if ( v20 > v21 )
    {
      v24 = jiffies;
      if ( reg_get_chan_enum_for_freq___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x51u,
          8u,
          "%s: invalid channel center frequency %d",
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          a16,
          "reg_get_chan_enum_for_freq",
          a2);
        reg_get_chan_enum_for_freq___last_ticks = v24;
      }
LABEL_10:
      v25 = "%s: chan freq is not valid";
LABEL_11:
      result = qdf_trace_msg(
                 0x51u,
                 2u,
                 v25,
                 a9,
                 a10,
                 a11,
                 a12,
                 a13,
                 a14,
                 a15,
                 a16,
                 "reg_fill_channel_list_for_320_for_pwrmode");
      goto LABEL_12;
    }
  }
  if ( v22 >= 0x66 )
    goto LABEL_10;
  if ( !reg_get_pdev_obj(a1, a9, a10, a11, a12, a13, a14, a15, a16) )
  {
    v25 = "%s: reg pdev priv obj is NULL";
    goto LABEL_11;
  }
  v77 = 0;
  result = reg_get_min_max_bw_reg_chan_list(a1, v22, a7, nullptr, v76, a9, a10, a11, a12, a13, a14, a15, a16);
  if ( (_DWORD)result )
    goto LABEL_12;
  if ( v76[0] <= 0xA0u )
  {
    v38 = *a3;
    if ( (unsigned int)v38 > 7 )
      v39 = 8;
    else
      v39 = get_next_lower_bandwidth_get_next_lower_bw[v38];
    *a3 = v39;
    *a6 = 1;
    goto LABEL_12;
  }
  v40 = a3;
  v41 = a6;
  if ( a4 > 6424 )
  {
    v42 = a8;
    if ( a4 > 6744 )
    {
      if ( a4 == 6745 )
      {
        v43 = &unk_AD7E94;
        goto LABEL_68;
      }
      if ( a4 == 6905 )
      {
        v43 = &unk_AD7E98;
        goto LABEL_68;
      }
    }
    else
    {
      if ( a4 == 6425 )
      {
        v43 = &unk_AD7E8C;
        goto LABEL_68;
      }
      if ( a4 == 6585 )
      {
        v43 = &unk_AD7E90;
        goto LABEL_68;
      }
    }
LABEL_64:
    result = qdf_trace_msg(
               0x51u,
               8u,
               "%s: No bonded pair for the given band_center\n",
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               "reg_fill_channel_list_for_320_for_pwrmode");
    *a5 = 0;
    goto LABEL_12;
  }
  v42 = a8;
  if ( a4 > 6104 )
  {
    if ( a4 == 6105 )
    {
      v43 = &unk_AD7E84;
      goto LABEL_68;
    }
    if ( a4 == 6265 )
    {
      v43 = &unk_AD7E88;
      goto LABEL_68;
    }
    goto LABEL_64;
  }
  v43 = &bonded_chan_320mhz_list_freq;
  if ( !a4 )
  {
    v44 = 0;
    if ( a2 >> 2 >= 0x55F && a2 <= 0x1658 )
    {
      v44 = 1;
      v78[0] = &bonded_chan_320mhz_list_freq;
    }
    if ( a2 >= 0x1743 && a2 >> 4 <= 0x186 )
      v78[v44++] = &unk_AD7E84;
    v73 = v40;
    if ( v44 <= 1 )
    {
      if ( a2 >= 0x17E3 && a2 >> 4 <= 0x190 )
        v78[v44++] = &unk_AD7E88;
      if ( v44 <= 1 )
      {
        if ( a2 >= 0x1883 && a2 >> 4 <= 0x19A )
          v78[v44++] = &unk_AD7E8C;
        if ( v44 <= 1 )
        {
          if ( a2 >= 0x1923 && a2 >> 4 <= 0x1A4 )
            v78[v44++] = &unk_AD7E90;
          if ( v44 <= 1 )
          {
            if ( a2 >= 0x19C3 && a2 >> 4 <= 0x1AE )
              v78[v44++] = &unk_AD7E94;
            if ( v44 <= 1 && a2 >= 0x1A63 && a2 >> 4 <= 0x1B8 )
              v78[v44++] = &unk_AD7E98;
          }
        }
      }
    }
    if ( !v44 )
    {
      v68 = *v40;
      if ( (unsigned int)v68 > 7 )
        *v40 = 8;
      else
        *v40 = get_next_lower_bandwidth_get_next_lower_bw[v68];
      goto LABEL_113;
    }
    goto LABEL_69;
  }
  if ( a4 != 5650 )
    goto LABEL_64;
LABEL_68:
  v44 = 1;
  v73 = v40;
  v78[0] = v43;
LABEL_69:
  v45 = (unsigned __int16 *)&unk_AD7EC8;
  v71 = a2 >> 4;
  if ( a2 >> 4 > 0x1AE )
    v45 = (unsigned __int16 *)&unk_AD7ECC;
  v70 = v45;
  v46 = a2 - 7056 < 0xFFFFFF73 && a2 >> 4 > 0x1AE;
  v47 = 0;
  v48 = 0;
  v49 = a2 < 0x1A63 || v46;
  v50 = 24LL * v44;
  v51 = (unsigned __int16 **)v78;
  v74 = a2 >> 2;
  v69 = v49 ^ 1;
  do
  {
    if ( v47 == 48 )
LABEL_117:
      __break(0x5512u);
    v53 = *v51;
    result = reg_get_320_bonded_channel_state_for_pwrmode(
               a1,
               a2,
               *v51,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v29,
               &v77,
               a7,
               v42 & 1,
               *(_WORD *)&a5[v47 + 26]);
    if ( (result & 0xFFFFFFFB) != 0 )
    {
      if ( v48 > 2 )
        goto LABEL_117;
      v54 = (__int64)&a5[24 * v48 + 4];
      v55 = *v53 + 150;
      *(_DWORD *)(v54 + 12) = v55;
      *(_BYTE *)(v54 + 6) = reg_freq_to_chan(a1, v55, v30, v31, v32, v33, v34, v35, v36, v37);
      v64 = *v73;
      *(_WORD *)(v54 + 18) = v77;
      *(_DWORD *)v54 = v64;
      if ( v74 >= 0x50F )
      {
        v65 = (unsigned __int16 *)&bonded_chan_160mhz_list_freq;
        if ( a2 < 0x14C9 )
          goto LABEL_78;
        if ( v74 >= 0x55F )
        {
          v65 = (unsigned __int16 *)&unk_AD7EAC;
          if ( a2 < 0x1609 )
            goto LABEL_78;
          if ( a2 < 0x1671 )
          {
            result = qdf_trace_msg(
                       0x51u,
                       8u,
                       "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
                       v56,
                       v57,
                       v58,
                       v59,
                       v60,
                       v61,
                       v62,
                       v63,
                       "reg_get_bonded_chan_entry",
                       a2,
                       3,
                       0);
            if ( a2 - 5660 <= 0x3C )
            {
              *(_DWORD *)(v54 + 8) = 5730;
              *(_BYTE *)(v54 + 5) = -110;
              goto LABEL_79;
            }
            goto LABEL_86;
          }
          v65 = (unsigned __int16 *)&unk_AD7EB0;
          if ( a2 >> 1 < 0xB7F )
            goto LABEL_78;
          if ( a2 >= 0x1743 )
          {
            v65 = (unsigned __int16 *)&unk_AD7EB4;
            if ( v71 < 0x17D )
              goto LABEL_78;
            if ( a2 >= 0x17E3 )
            {
              v65 = (unsigned __int16 *)&unk_AD7EB8;
              if ( v71 < 0x187 )
                goto LABEL_78;
              if ( a2 >= 0x1883 )
              {
                v65 = (unsigned __int16 *)&unk_AD7EBC;
                if ( v71 < 0x191 )
                  goto LABEL_78;
                if ( a2 >= 0x1923 )
                {
                  v65 = (unsigned __int16 *)&unk_AD7EC0;
                  if ( v71 < 0x19B )
                    goto LABEL_78;
                  if ( a2 >= 0x19C3 )
                  {
                    v65 = v70;
                    if ( v71 <= 0x1A4 )
                      v65 = (unsigned __int16 *)&unk_AD7EC4;
                    if ( v71 < 0x1A5 || v69 )
                    {
LABEL_78:
                      v52 = (v65[1] + (unsigned int)*v65) >> 1;
                      *(_DWORD *)(v54 + 8) = v52;
                      result = reg_freq_to_chan(a1, v52, v56, v57, v58, v59, v60, v61, v62, v63);
                      *(_BYTE *)(v54 + 5) = result;
LABEL_79:
                      v42 = a8;
                      *a5 = ++v48;
                      goto LABEL_80;
                    }
                  }
                }
              }
            }
          }
        }
      }
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: Could not find a bonded pair for freq %d and width %d cen320_freq %u",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "reg_get_bonded_chan_entry",
        a2,
        3,
        0);
LABEL_86:
      *(_DWORD *)v54 = 8;
      result = qdf_trace_msg(
                 0x51u,
                 8u,
                 "%s: Cannot find 160 MHz centers for freq %d",
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 "reg_fill_chan320mhz_seg0_center",
                 a2);
      goto LABEL_79;
    }
LABEL_80:
    v47 += 24;
    ++v51;
  }
  while ( v50 != v47 );
  if ( !*a5 )
  {
    v66 = *v73;
    if ( (unsigned int)v66 > 7 )
      v67 = 8;
    else
      v67 = get_next_lower_bandwidth_get_next_lower_bw[v66];
    v41 = a6;
    *v73 = v67;
LABEL_113:
    *v41 = 1;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
