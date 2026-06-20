__int64 __fastcall lim_fill_lim_assoc_ind_params(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x21
  unsigned __int8 *v14; // x26
  __int64 v16; // x20
  __int16 v18; // w8
  unsigned __int8 *vendor_ie_ptr_from_oui; // x24
  __int64 result; // x0
  __int16 v21; // w8
  size_t v22; // x2
  __int64 v23; // x4
  const char *v24; // x2
  __int64 v25; // x8
  size_t v26; // x2
  size_t v27; // x2
  char *v28; // x25
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x8
  __int64 v38; // x8
  int v39; // w8
  int max_rate_flags; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  _WORD *v49; // x27
  size_t v50; // x2
  unsigned __int8 v51; // w1
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _BYTE *v60; // x23
  const void *v61; // x1
  __int64 v62; // x24
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  int v79; // w8
  unsigned int v80; // w8
  __int64 v81; // x8
  int v82; // w7
  unsigned int v83; // w8
  int v84; // w0
  unsigned int v85; // w9
  __int16 v86; // w8
  __int64 v87; // x4
  unsigned int v88; // w8
  unsigned __int64 v89; // x27
  unsigned __int64 v90; // x23
  unsigned __int8 *v91; // x1
  __int64 v92; // x28
  unsigned int v93; // w24
  unsigned __int8 v94; // w22
  __int64 v95; // x21
  unsigned __int8 *v96; // x20
  unsigned int v97; // w25
  int v98; // w8
  bool is_24ghz_ch_freq; // w0
  __int64 v100; // x14
  __int16 v101; // w10
  unsigned __int64 v102; // x10
  int v103; // w10
  unsigned __int64 v104; // x10
  __int64 v105; // x11
  __int64 v106; // x12
  unsigned __int64 v107; // x12
  __int64 v108; // x14
  char v109; // w16
  __int64 v110; // x17
  const char *v111; // x2
  int v112; // w8
  int v113; // w8
  int v114; // w8
  int v115; // w8
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x4
  unsigned int v125; // w9
  int v126; // w8
  int v127; // w9
  char he_max_mcs_idx; // w0
  char vht_max_mcs_idx; // w0
  int v130; // w8
  int v131; // w8
  __int64 v132; // x0
  __int64 cmpt_obj; // x0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  int v142; // w8
  int v143; // w8
  int v144; // w8
  int v145; // w8
  unsigned __int8 *v146; // [xsp+8h] [xbp-28h]
  __int64 v147; // [xsp+10h] [xbp-20h]
  __int64 v148; // [xsp+18h] [xbp-18h]
  __int16 v149; // [xsp+24h] [xbp-Ch] BYREF
  char v150; // [xsp+26h] [xbp-Ah]
  __int64 v151; // [xsp+28h] [xbp-8h]

  v151 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a4 + 384);
  v150 = 0;
  v149 = 0;
  if ( !v12 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s:  Parsed Assoc req is NULL",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_fill_lim_assoc_ind_params");
    result = 0;
LABEL_217:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v13 = a3;
  v14 = *(unsigned __int8 **)(v12 + 8LL * *(unsigned __int16 *)(a3 + 348));
  if ( !v14 )
  {
    v24 = "%s: assoc req for assoc_id:%d is NULL";
    goto LABEL_21;
  }
  v16 = a4;
  qdf_mem_copy((void *)a1, (const void *)(a3 + 350), 6u);
  qdf_mem_copy((void *)(a1 + 2891), (const void *)(v13 + 1080), 6u);
  *(_WORD *)(a1 + 6) = *(_WORD *)(v13 + 348);
  qdf_mem_copy((void *)(a1 + 16), v14 + 10, (unsigned int)v14[10] + 1);
  *(_BYTE *)(a1 + 2724) = *(_BYTE *)(v16 + 8);
  *(_DWORD *)(a1 + 8) = *(_DWORD *)(v13 + 12);
  *(_DWORD *)(a1 + 12) = *(_DWORD *)(v13 + 16);
  v18 = *(_WORD *)v14;
  *(_WORD *)(a1 + 50) = 0;
  *(_WORD *)(a1 + 2622) = v18;
  if ( v14[3268] && *((_WORD *)v14 + 502) )
  {
    vendor_ie_ptr_from_oui = wlan_get_vendor_ie_ptr_from_oui(&unk_AFB6F8, 4u, v14 + 1006, *((_WORD *)v14 + 502));
    if ( !v14[3267] )
      goto LABEL_11;
  }
  else
  {
    vendor_ie_ptr_from_oui = nullptr;
    if ( !v14[3267] )
      goto LABEL_11;
  }
  if ( !vendor_ie_ptr_from_oui )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Assoc Req RSN IE len: %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_fill_lim_assoc_ind_params",
      v14[748]);
    v21 = v14[748];
    *(_BYTE *)(a1 + 52) = 48;
    *(_WORD *)(a1 + 50) = v21 + 2;
    v22 = v14[748];
    *(_BYTE *)(a1 + 53) = v22;
    qdf_mem_copy((void *)(a1 + 54), v14 + 749, v22);
  }
LABEL_11:
  if ( !v14[3269] || !v14[3270] )
  {
    *(_BYTE *)(a1 + 2624) = 0;
    goto LABEL_16;
  }
  *(_BYTE *)(a1 + 2624) = 1;
  *(_BYTE *)(a1 + 2625) = v14[3058];
  *(_BYTE *)(a1 + 2626) = v14[3059];
  if ( v14[3061] > 0x5Fu )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Number of supported channels: %d is more than MAX",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_convert_supported_channels",
      v14[3061]);
    *(_BYTE *)(a1 + 2627) = 0;
    goto LABEL_16;
  }
  if ( !v14[3061] )
  {
    LOBYTE(v90) = 0;
LABEL_186:
    *(_BYTE *)(a1 + 2627) = v90;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Send AssocInd to WSM: minPwr: %d maxPwr: %d numChnl: %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_convert_supported_channels");
    ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(53, 8, v14 + 3062, v14[3061]);
LABEL_16:
    if ( v14[3266] && !vendor_ie_ptr_from_oui )
    {
      v23 = *(unsigned __int16 *)(a1 + 50);
      if ( v14[492] + (unsigned int)v23 >= 0xFF )
      {
        v24 = "%s: rsnIEdata index out of bounds: %d";
LABEL_21:
        qdf_trace_msg(0x35u, 2u, v24, a5, a6, a7, a8, a9, a10, a11, a12, "lim_fill_lim_assoc_ind_params");
        result = 0;
        goto LABEL_217;
      }
      *(_BYTE *)(a1 + 52 + *(unsigned __int16 *)(a1 + 50)) = -35;
      v25 = v23 + a1 + 52;
      v26 = v14[492];
      *(_BYTE *)(v25 + 1) = v26;
      qdf_mem_copy((void *)(v25 + 2), v14 + 493, v26);
      *(_WORD *)(a1 + 50) += v14[492] + 2;
    }
    if ( !vendor_ie_ptr_from_oui && v14[3265] )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Received WAPI IE length in Assoc Req is %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "lim_fill_assoc_ind_wapi_info",
        v14[236]);
      *(_BYTE *)(a1 + 312) = 68;
      v27 = v14[236];
      *(_BYTE *)(a1 + 313) = v27;
      qdf_mem_copy((void *)(a1 + 314), v14 + 237, v27);
      *(_WORD *)(a1 + 310) = v14[236] + 2;
    }
    *(_WORD *)(a1 + 570) = 0;
    if ( v14[3268] )
    {
      qdf_mem_copy((void *)(a1 + 572), v14 + 1006, *((unsigned __int16 *)v14 + 502));
      *(_WORD *)(a1 + 570) = *((_WORD *)v14 + 502);
    }
    v28 = (char *)(v16 + 7032);
    if ( v14[3160] )
    {
      qdf_mem_copy((void *)(a1 + 2812), v14 + 3160, 0x3Cu);
      v37 = *(unsigned __int16 *)(a1 + 570);
      if ( (unsigned int)v37 > 0xE2 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Fail:HT capabilities IE to addIE",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "lim_fill_lim_assoc_ind_params");
        if ( !v14[3261] )
        {
LABEL_33:
          *(_DWORD *)(a1 + 2728) = *((_DWORD *)v14 + 820);
          *(_QWORD *)(a1 + 2736) = *((_QWORD *)v14 + 411);
          v39 = *(_DWORD *)(v16 + 284);
          *(_DWORD *)(a1 + 2752) = 0;
          *(_DWORD *)(a1 + 2744) = v39;
          *(_DWORD *)(a1 + 2748) = v39;
          *(_DWORD *)(a1 + 2760) = *v28 << 16;
          *(_DWORD *)(a1 + 2764) = *v28 << 8;
          *(_BYTE *)(a1 + 2768) = *(_BYTE *)(v13 + 659);
          max_rate_flags = lim_get_max_rate_flags(a2, v13);
          *(_QWORD *)(a1 + 2784) = 0;
          *(_DWORD *)(a1 + 2772) = max_rate_flags;
          *(_DWORD *)(a1 + 2792) = 0;
          *(_WORD *)(a1 + 2796) = -1;
          *(_BYTE *)(a1 + 2798) = -1;
          *(_WORD *)(a1 + 2800) = -1;
          if ( v14[44] )
            *(_BYTE *)(a1 + 2796) = lim_get_max_rate_idx(v14 + 44);
          if ( v14[57] )
            *(_BYTE *)(a1 + 2797) = lim_get_max_rate_idx(v14 + 57);
          v49 = v14 + 3161;
          if ( (*(_BYTE *)(v13 + 32) & 8) != 0 )
          {
            *(_BYTE *)(a1 + 2784) = 1;
            if ( (*(_BYTE *)(v13 + 344) & 6) != 0 )
              *(_BYTE *)(a1 + 2785) = 1;
            *(_BYTE *)(a1 + 2786) = (*v49 & 0x80) != 0;
            *(_BYTE *)(a1 + 2787) = (*v49 & 0x300) != 0;
            v85 = *(unsigned __int8 *)(v13 + 346);
            *(_DWORD *)(a1 + 2792) = 1;
            *(_DWORD *)(a1 + 2788) = (v85 >> 3) & 1;
            *(_BYTE *)(a1 + 2798) = lim_get_ht_max_mcs_idx(v14 + 3160);
            if ( (*(_BYTE *)(v13 + 32) & 0x10) == 0 )
            {
LABEL_39:
              if ( !v14[3314] )
                goto LABEL_44;
              goto LABEL_40;
            }
          }
          else if ( (*(_BYTE *)(v13 + 32) & 0x10) == 0 )
          {
            goto LABEL_39;
          }
          *(_BYTE *)(a1 + 2784) = 1;
          v86 = *(_WORD *)(v14 + 3297);
          if ( (v86 & 0x60) != 0 )
          {
            *(_BYTE *)(a1 + 2785) = 1;
            v86 = *(_WORD *)(v14 + 3297);
          }
          *(_BYTE *)(a1 + 2786) = (v86 & 0x80) != 0;
          *(_BYTE *)(a1 + 2787) = (*(_WORD *)(v14 + 3297) & 0x700) != 0;
          v87 = *(unsigned int *)(v13 + 360);
          if ( (unsigned int)v87 < 0xA && ((0x29Fu >> v87) & 1) != 0 )
          {
            v88 = dword_AFB700[v87];
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: invalid enum: %d",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "lim_convert_channel_width_enum");
            v88 = 0;
          }
          *(_DWORD *)(a1 + 2788) = v88;
          *(_DWORD *)(a1 + 2792) = 2;
          *(_BYTE *)(a1 + 2800) = v14[3302];
          *(_BYTE *)(a1 + 2801) = v14[3306];
          if ( !v14[3314] )
          {
LABEL_44:
            if ( v14[3223] )
            {
              qdf_mem_set(&v149, 3u, 0);
              v51 = v14[3224];
              v150 = 4;
              *(_BYTE *)(a1 + 2808) = wlan_reg_get_band_cap_from_op_class(
                                        (unsigned __int8 *)&v149,
                                        v51,
                                        v14 + 3225,
                                        v52,
                                        v53,
                                        v54,
                                        v55,
                                        v56,
                                        v57,
                                        v58,
                                        v59);
            }
            v60 = v14 + 3296;
            v61 = v14 + 3296;
            if ( !v14[3296] )
            {
              if ( !v14[3344] )
                goto LABEL_50;
              v61 = v14 + 3344;
            }
            qdf_mem_copy((void *)(a1 + 2872), v61, 0x10u);
LABEL_50:
            v62 = 1LL << wlan_reg_freq_to_band(*(_DWORD *)(v16 + 284));
            *(_DWORD *)(a1 + 2748) = wlan_reg_chan_band_to_freq(
                                       *(_QWORD *)(a2 + 21632),
                                       *(unsigned __int8 *)(v16 + 7174),
                                       v62,
                                       v63,
                                       v64,
                                       v65,
                                       v66,
                                       v67,
                                       v68,
                                       v69,
                                       v70);
            if ( *(_BYTE *)(v16 + 7186) )
              *(_DWORD *)(a1 + 2752) = wlan_reg_chan_band_to_freq(
                                         *(_QWORD *)(a2 + 21632),
                                         *(unsigned __int8 *)(v16 + 7186),
                                         v62,
                                         v71,
                                         v72,
                                         v73,
                                         v74,
                                         v75,
                                         v76,
                                         v77,
                                         v78);
            if ( *(_DWORD *)(v16 + 7176) == 1 )
            {
              if ( *(_DWORD *)(v16 + 164) == 1 )
                v79 = 10;
              else
                v79 = -10;
              *(_DWORD *)(a1 + 2748) += v79;
            }
            if ( *(_BYTE *)(v16 + 8676) == 1 && v14[3372] )
            {
              v80 = *(_DWORD *)(v16 + 7176);
              if ( *(_DWORD *)(v16 + 168) )
              {
                if ( v80 == 3 )
                {
                  v81 = *(_QWORD *)(v14 + 3373);
                  if ( (v81 & 0x10000000000000LL) != 0 )
                  {
                    v82 = 20;
                    goto LABEL_154;
                  }
LABEL_130:
                  if ( (v81 & 0x8000000000000LL) != 0 )
                  {
                    v82 = 18;
                    goto LABEL_154;
                  }
                  goto LABEL_153;
                }
                if ( v80 >= 2 )
                {
                  v81 = *(_QWORD *)(v14 + 3373);
                  goto LABEL_130;
                }
                if ( !v80 || (v14[3379] & 8) == 0 )
                {
LABEL_153:
                  v82 = 16;
                  goto LABEL_154;
                }
              }
              else if ( v80 != 1 || (v14[3379] & 4) == 0 )
              {
                goto LABEL_153;
              }
              v82 = 17;
LABEL_154:
              *(_DWORD *)(a1 + 2756) = v82;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: ch_width: %d vht_cap %d ht_cap %d chan_info %d center_freq1 %d",
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                "lim_fill_lim_assoc_ind_params",
                *(unsigned int *)(v16 + 7176),
                *(unsigned __int8 *)(v16 + 7170),
                *(unsigned __int8 *)(v16 + 155),
                *(_DWORD *)(a1 + 2748));
              *(_BYTE *)(a1 + 2888) = v14[3372] != 0;
              *(_BYTE *)(a1 + 2889) = v14[3480] != 0;
              *(_BYTE *)(a1 + 2890) = v14[3572];
              if ( *(_BYTE *)(v13 + 38) == 1 && *(_BYTE *)(v16 + 8676) == 1 )
              {
                v124 = *(unsigned int *)(v13 + 360);
                if ( (unsigned int)v124 < 0xA && ((0x29Fu >> v124) & 1) != 0 )
                {
                  v125 = dword_AFB700[v124];
                }
                else
                {
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: invalid enum: %d",
                    v116,
                    v117,
                    v118,
                    v119,
                    v120,
                    v121,
                    v122,
                    v123,
                    "lim_convert_channel_width_enum");
                  v125 = 0;
                }
                v126 = *(_DWORD *)(a1 + 2772);
                *(_DWORD *)(a1 + 2788) = v125;
                v127 = *(_DWORD *)(v13 + 360);
                if ( (v126 & 0x3E000) != 0 )
                {
                  if ( v127 > 2 )
                  {
                    if ( (unsigned int)(v127 - 3) >= 2 )
                    {
                      if ( v127 == 7 )
                        v126 |= 0x20000u;
                    }
                    else
                    {
                      v126 |= 0x10000u;
                    }
                  }
                  else if ( v127 )
                  {
                    if ( v127 == 1 )
                    {
                      v126 |= 0x4000u;
                    }
                    else if ( v127 == 2 )
                    {
                      v126 |= 0x8000u;
                    }
                  }
                  else
                  {
                    v126 |= 0x2000u;
                  }
                }
                else if ( (v126 & 0xF00) != 0 )
                {
                  if ( v127 > 2 )
                  {
                    if ( (unsigned int)(v127 - 3) < 2 )
                      v126 |= 0x800u;
                  }
                  else if ( v127 )
                  {
                    if ( v127 == 1 )
                    {
                      v126 |= 0x200u;
                    }
                    else if ( v127 == 2 )
                    {
                      v126 |= 0x400u;
                    }
                  }
                  else
                  {
                    v126 |= 0x100u;
                  }
                }
                else if ( (v126 & 0x10E0) != 0 )
                {
                  if ( v127 > 2 )
                  {
                    if ( (unsigned int)(v127 - 3) < 2 )
                      v126 |= 0x1000u;
                  }
                  else if ( v127 )
                  {
                    if ( v127 == 1 )
                    {
                      v126 |= 0x40u;
                    }
                    else if ( v127 == 2 )
                    {
                      v126 |= 0x80u;
                    }
                  }
                  else
                  {
                    v126 |= 0x20u;
                  }
                }
                else if ( v127 == 1 )
                {
                  v126 |= 4u;
                }
                else if ( !v127 )
                {
                  v126 |= 2u;
                }
                *(_DWORD *)(a1 + 2772) = v126;
                *(_DWORD *)(a1 + 2792) = 3;
              }
              *(_BYTE *)(a1 + 2799) = -1;
              if ( *(_BYTE *)(v13 + 38) != 1
                || *(_BYTE *)(v16 + 8676) != 1
                || (he_max_mcs_idx = lim_get_he_max_mcs_idx(*(unsigned int *)(v13 + 360), v14 + 3372),
                    *(_BYTE *)(a1 + 2799) = he_max_mcs_idx,
                    he_max_mcs_idx == -1) )
              {
                if ( (*(_BYTE *)(v13 + 32) & 0x10) == 0
                  || (vht_max_mcs_idx = lim_get_vht_max_mcs_idx(v14 + 3296),
                      *(_BYTE *)(a1 + 2799) = vht_max_mcs_idx,
                      vht_max_mcs_idx == -1) )
                {
                  v130 = *(unsigned __int8 *)(a1 + 2798);
                  *(_BYTE *)(a1 + 2799) = v130;
                  if ( v130 == 255 )
                  {
                    v131 = *(unsigned __int8 *)(a1 + 2797);
                    *(_BYTE *)(a1 + 2799) = v131;
                    if ( v131 == 255 )
                      *(_BYTE *)(a1 + 2799) = *(_BYTE *)(a1 + 2796);
                  }
                }
              }
              v132 = *(_QWORD *)(v16 + 16);
              if ( v132 )
              {
                cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v132, v116, v117, v118, v119, v120, v121, v122, v123);
                if ( cmpt_obj )
                  qdf_mem_copy((void *)(*(_QWORD *)(cmpt_obj + 536) + 23964LL), (const void *)(a1 + 2744), 0x28u);
                else
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: vdev component object is NULL",
                    v134,
                    v135,
                    v136,
                    v137,
                    v138,
                    v139,
                    v140,
                    v141,
                    "lim_fill_lim_assoc_ind_params");
              }
              result = 1;
              goto LABEL_217;
            }
            if ( !*(_DWORD *)(v16 + 168) )
            {
              if ( *(_BYTE *)(v16 + 7170) && *v60 )
              {
                v82 = 11;
              }
              else if ( *(_BYTE *)(v16 + 155) && v14[3160] )
              {
                v82 = 5;
              }
              else
              {
                v82 = 1;
                v112 = *(_WORD *)(v13 + 272) & 0x7F;
                if ( ((unsigned int)(v112 - 12) > 0x3C
                   || ((1LL << ((unsigned __int8)v112 - 12)) & 0x1000001001001041LL) == 0)
                  && v112 != 96
                  && v112 != 108 )
                {
                  v113 = *(_WORD *)(v13 + 274) & 0x7F;
                  if ( ((unsigned int)(v113 - 12) > 0x3C
                     || ((1LL << ((unsigned __int8)v113 - 12)) & 0x1000001001001041LL) == 0)
                    && v113 != 96
                    && v113 != 108 )
                  {
                    v114 = *(_WORD *)(v13 + 276) & 0x7F;
                    if ( ((unsigned int)(v114 - 12) > 0x3C
                       || ((1LL << ((unsigned __int8)v114 - 12)) & 0x1000001001001041LL) == 0)
                      && v114 != 96
                      && v114 != 108 )
                    {
                      v115 = *(_WORD *)(v13 + 278) & 0x7F;
                      if ( ((unsigned int)(v115 - 12) > 0x3C
                         || ((1LL << ((unsigned __int8)v115 - 12)) & 0x1000001001001041LL) == 0)
                        && v115 != 96
                        && v115 != 108 )
                      {
                        v142 = *(_WORD *)(v13 + 280) & 0x7F;
                        if ( ((unsigned int)(v142 - 12) > 0x3C
                           || ((1LL << ((unsigned __int8)v142 - 12)) & 0x1000001001001041LL) == 0)
                          && v142 != 96
                          && v142 != 108 )
                        {
                          v143 = *(_WORD *)(v13 + 282) & 0x7F;
                          if ( ((unsigned int)(v143 - 12) > 0x3C
                             || ((1LL << ((unsigned __int8)v143 - 12)) & 0x1000001001001041LL) == 0)
                            && v143 != 96
                            && v143 != 108 )
                          {
                            v144 = *(_WORD *)(v13 + 284) & 0x7F;
                            if ( ((unsigned int)(v144 - 12) > 0x3C
                               || ((1LL << ((unsigned __int8)v144 - 12)) & 0x1000001001001041LL) == 0)
                              && v144 != 96
                              && v144 != 108 )
                            {
                              v145 = *(_WORD *)(v13 + 286) & 0x7F;
                              if ( ((unsigned int)(v145 - 12) > 0x3C
                                 || ((1LL << ((unsigned __int8)v145 - 12)) & 0x1000001001001041LL) == 0)
                                && v145 != 96
                                && v145 != 108 )
                              {
                                v82 = 2;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              goto LABEL_154;
            }
            if ( !*(_BYTE *)(v16 + 7170) || !*v60 )
            {
              if ( *(_BYTE *)(v16 + 155) && v14[3160] )
              {
                if ( *(_DWORD *)(v16 + 7176) == 1 && (*v49 & 2) != 0 )
                  v82 = 6;
                else
                  v82 = 4;
              }
              else
              {
                v82 = 0;
              }
              goto LABEL_154;
            }
            v83 = *(_DWORD *)(v16 + 7176);
            if ( v83 < 2 )
            {
              if ( v83 == 1 && (*v49 & 2) != 0 )
              {
                v82 = 9;
                goto LABEL_154;
              }
            }
            else if ( (*v49 & 2) != 0 )
            {
              v84 = cds_chan_to_freq(*(_BYTE *)(v16 + 7174));
              v82 = 10;
              *(_DWORD *)(a1 + 2748) = v84;
              goto LABEL_154;
            }
            v82 = 8;
            goto LABEL_154;
          }
LABEL_40:
          *(_BYTE *)(a1 + 2802) = (v14[3316] & 4) != 0;
          if ( v14[3315] >= 4u )
            v50 = 4;
          else
            v50 = v14[3315];
          qdf_mem_copy((void *)(a1 + 2804), v14 + 3316, v50);
          goto LABEL_44;
        }
LABEL_32:
        *(_BYTE *)(a1 + 2725) = *(_BYTE *)(*(_QWORD *)(a2 + 8) + 5669LL);
        goto LABEL_33;
      }
      *(_BYTE *)(a1 + 572 + *(unsigned __int16 *)(a1 + 570)) = 45;
      v38 = v37 + a1 + 572;
      *(_BYTE *)(v38 + 1) = 26;
      qdf_mem_copy((void *)(v38 + 2), v14 + 3161, 0x1Au);
      *(_WORD *)(a1 + 570) += 28;
    }
    if ( !v14[3261] )
      goto LABEL_33;
    goto LABEL_32;
  }
  v148 = a2;
  v89 = 0;
  LOWORD(v90) = 0;
  v91 = v14 + 3062;
  v92 = a1 + 2628;
  v146 = vendor_ie_ptr_from_oui;
  v147 = v13;
  while ( v89 < 0x60 )
  {
    v93 = v91[v89];
    *(_BYTE *)(v92 + (unsigned __int16)v90) = v93;
    v94 = v91[v89 + 1];
    if ( (unsigned __int16)v90 == 95 )
    {
      v111 = "%s: Ch count > max supported: %d";
      goto LABEL_175;
    }
    LOWORD(v90) = v90 + 1;
    if ( v91[v89 + 1] >= 2u )
    {
      v95 = v16;
      v96 = v91;
      v97 = wlan_reg_legacy_chan_to_freq(*(_QWORD *)(v148 + 21632), v93, a5, a6, a7, a8, a9, a10, a11, a12);
      if ( !wlan_reg_is_6ghz_chan_freq(v97) )
      {
        if ( wlan_reg_is_5ghz_ch_freq(v97) )
        {
          v91 = v96;
          v16 = v95;
          v13 = v147;
          v98 = 4;
LABEL_102:
          v100 = (unsigned __int16)v90;
          if ( v94 <= 2u )
            v101 = 2;
          else
            v101 = v94;
          v102 = (unsigned __int16)(v101 - 2);
          if ( v102 >= 95 - (unsigned __int64)(unsigned __int16)v90 )
            v102 = 95LL - (unsigned __int16)v90;
          if ( v102 >= 2 )
          {
            v104 = v102 + 1;
            v105 = 0;
            v106 = v104 & 1;
            if ( (v104 & 1) == 0 )
              v106 = 2;
            v107 = v104 - v106;
            v90 = v107 + (unsigned __int16)v90;
            v103 = v107 + 1;
            v108 = a1 + v100;
            do
            {
              v109 = v93 + v98 * v105;
              v110 = v108 + v105;
              v105 += 2;
              *(_BYTE *)(v110 + 2628) = v109 + v98;
              *(_BYTE *)(v110 + 2629) = v109 + 2 * v98;
            }
            while ( v107 != v105 );
            v93 += v98 * v107;
          }
          else
          {
            v103 = 1;
            v90 = (unsigned __int16)v90;
          }
          while ( 1 )
          {
            v93 += v98;
            *(_BYTE *)(v92 + v90) = v93;
            if ( v90 == 95 )
              break;
            ++v103;
            ++v90;
            if ( v94 <= (unsigned int)(unsigned __int16)v103 )
              goto LABEL_90;
          }
          v111 = "%s: Ch count > supported: %d";
LABEL_175:
          qdf_trace_msg(0x35u, 3u, v111, a5, a6, a7, a8, a9, a10, a11, a12, "lim_convert_supported_channels", v94);
          a2 = v148;
          vendor_ie_ptr_from_oui = v146;
          *(_BYTE *)(a1 + 2627) = 0;
          goto LABEL_16;
        }
        wlan_reg_is_24ghz_ch_freq(v97);
      }
      if ( wlan_reg_is_6ghz_chan_freq(v97) || wlan_reg_is_5ghz_ch_freq(v97) )
      {
        v91 = v96;
        v16 = v95;
        v13 = v147;
      }
      else
      {
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v97);
        v91 = v96;
        v16 = v95;
        v13 = v147;
        if ( is_24ghz_ch_freq )
        {
          v98 = 1;
          goto LABEL_102;
        }
      }
    }
LABEL_90:
    v89 += 2LL;
    if ( v89 >= v14[3061] )
    {
      a2 = v148;
      vendor_ie_ptr_from_oui = v146;
      goto LABEL_186;
    }
  }
  __break(0x5512u);
  return lim_send_mlm_assoc_ind();
}
