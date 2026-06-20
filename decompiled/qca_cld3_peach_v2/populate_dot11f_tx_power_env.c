__int64 __fastcall populate_dot11f_tx_power_env(
        __int64 a1,
        __int64 a2,
        _BYTE *a3,
        unsigned int a4,
        unsigned int a5,
        __int16 *a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v22; // x0
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned __int64 v40; // x24
  unsigned int bw_value; // w8
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w4
  _BOOL4 v51; // w27
  unsigned __int64 v52; // x28
  unsigned int v53; // w10
  __int16 v54; // w8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  char v63; // w9
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  __int64 v72; // x5
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x5
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x5
  unsigned int v91; // w9
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  _BOOL4 v100; // w10
  unsigned int v101; // w11
  unsigned int v102; // w12
  char v103; // w8
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x5
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  __int64 v121; // x5
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  __int64 v130; // x5
  unsigned __int16 v131; // w26
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  __int64 v140; // x2
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  int v149; // w24
  __int64 v150; // x0
  unsigned int v151; // w1
  char v152; // w25
  __int64 v153; // x0
  int v154; // w24
  unsigned __int64 v155; // x12
  unsigned int v156; // w8
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int64 v165; // x25
  __int64 v166; // x23
  unsigned int v167; // w9
  unsigned int v168; // w24
  unsigned int v169; // w26
  __int64 v170; // x5
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x22
  unsigned __int8 v180; // w8
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  __int16 *v189; // [xsp+8h] [xbp-58h]
  __int16 v190; // [xsp+18h] [xbp-48h]
  char v191; // [xsp+1Ch] [xbp-44h]
  unsigned int v192; // [xsp+20h] [xbp-40h]
  char v193; // [xsp+20h] [xbp-40h]
  unsigned int v194; // [xsp+28h] [xbp-38h]
  unsigned int v195; // [xsp+28h] [xbp-38h]
  unsigned int v196; // [xsp+2Ch] [xbp-34h]
  unsigned int v197; // [xsp+2Ch] [xbp-34h]
  unsigned int v198; // [xsp+30h] [xbp-30h] BYREF
  char v199; // [xsp+34h] [xbp-2Ch]
  __int64 v200; // [xsp+38h] [xbp-28h] BYREF
  __int64 v201; // [xsp+40h] [xbp-20h]
  __int64 v202; // [xsp+48h] [xbp-18h]
  unsigned __int16 v203; // [xsp+50h] [xbp-10h]
  unsigned __int16 v204; // [xsp+54h] [xbp-Ch]
  __int64 v205; // [xsp+58h] [xbp-8h]

  v205 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = *(_QWORD *)(a1 + 21632);
  v204 = 0;
  v203 = 0;
  v201 = 0;
  v202 = 0;
  v200 = 0;
  v199 = 0;
  v198 = 0;
  wlan_reg_get_cur_6g_ap_pwr_type(v22, &v198, a8, a9, a10, a11, a12, a13, a14, a15);
  result = wlan_reg_is_6ghz_chan_freq(a5);
  if ( (result & 1) != 0 )
  {
    wlan_reg_get_client_power_for_6ghz_ap();
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: chan_freq %d, eirp_power %d, psd_power %d",
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               v39,
               "populate_dot11f_tx_power_env",
               a5,
               v204,
               v203);
    if ( a4 > 7 )
      goto LABEL_76;
  }
  else
  {
    v199 = 0;
    if ( a4 > 7 )
      goto LABEL_76;
  }
  if ( ((0x9Fu >> a4) & 1) != 0 )
  {
    v194 = 2u >> a4;
    v191 = a7;
    v192 = 4u >> a4;
    v40 = 0x300000303020100uLL >> (8 * (unsigned __int8)a4);
    v196 = 0x7Fu >> a4;
    if ( (v199 & 1) == 0 )
    {
      result = wlan_reg_get_channel_reg_power_for_freq(
                 *(_QWORD *)(a1 + 21632),
                 a5,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31);
      a3[1] = v40;
      *a3 = 1;
      v204 = (unsigned __int8)result;
      a3[2] = 0x401010404030201uLL >> (8 * (unsigned __int8)a4);
      a3[3] = result;
      if ( ((0x61u >> a4) & 1) == 0 )
      {
        a3[4] = result;
        if ( (v194 & 1) == 0 )
        {
          a3[5] = result;
          if ( (v192 & 1) == 0 )
            a3[6] = result;
        }
      }
      if ( (v196 & 1) == 0 )
        result = update_ext_max_tpe_power(a1, a3, a5, 0);
      v54 = 1;
      goto LABEL_75;
    }
    v189 = a6;
    bw_value = (unsigned __int16)wlan_reg_get_bw_value(a4);
    v50 = 20;
    v51 = bw_value > 0x14;
    if ( (unsigned int)v203 + 13 >= v204 )
    {
      v52 = 0x401010404030201uLL >> (8 * (unsigned __int8)a4);
    }
    else
    {
      v52 = 0x401010404030201uLL >> (8 * (unsigned __int8)a4);
      if ( bw_value >= 0x15 )
      {
        v53 = v203 + 16;
        do
        {
          v50 *= 2;
          v51 = v50 < bw_value;
          if ( v53 >= v204 )
            break;
          v53 += 3;
        }
        while ( v50 < bw_value );
      }
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: bw_threshold %d",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "populate_dot11f_tx_power_env");
    if ( v51 )
    {
      v63 = v204;
      *a3 = 1;
      a3[1] = v40 | 0x10;
      a3[2] = v52;
      a3[3] = 2 * v63;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: non-psd default TPE %d %d",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "populate_dot11f_tx_power_env",
        0,
        (unsigned __int8)(2 * v63));
      if ( ((0x61u >> a4) & 1) == 0 )
      {
        v72 = (unsigned __int8)(2 * v204);
        a3[4] = 2 * v204;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: non-psd default TPE %d %d",
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          v71,
          "populate_dot11f_tx_power_env",
          1,
          v72);
        if ( (v194 & 1) == 0 )
        {
          v81 = (unsigned __int8)(2 * v204);
          a3[5] = 2 * v204;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: non-psd default TPE %d %d",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            "populate_dot11f_tx_power_env",
            2,
            v81);
          if ( (v192 & 1) == 0 )
          {
            v90 = (unsigned __int8)(2 * v204);
            a3[6] = 2 * v204;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: non-psd default TPE %d %d",
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              "populate_dot11f_tx_power_env",
              3,
              v90);
          }
        }
      }
      if ( (v196 & 1) == 0 )
        update_ext_max_tpe_power(a1, a3, a5, 0);
      a3 += 27;
      v190 = 1;
    }
    else
    {
      v190 = 0;
    }
    wlan_reg_get_client_power_for_6ghz_ap();
    if ( v204 )
    {
      v91 = (unsigned __int16)wlan_reg_get_bw_value(a4);
      v100 = v91 > 0x14;
      if ( (unsigned int)v203 + 13 < v204 && v91 >= 0x15 )
      {
        v101 = v203 + 16;
        v102 = 20;
        do
        {
          v102 *= 2;
          v100 = v102 < v91;
          if ( v101 >= v204 )
            break;
          v101 += 3;
        }
        while ( v102 < v91 );
      }
      if ( v100 || v51 )
      {
        v103 = 2 * v204;
        *a3 = 1;
        a3[2] = v52;
        a3[1] = v40 | 0x50;
        a3[3] = v103;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: non-psd subord TPE %d %d",
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          "populate_dot11f_tx_power_env",
          0,
          v103 & 0xFE);
        if ( ((0x61u >> a4) & 1) == 0 )
        {
          v112 = (unsigned __int8)(2 * v204);
          a3[4] = 2 * v204;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: non-psd subord TPE %d %d",
            v104,
            v105,
            v106,
            v107,
            v108,
            v109,
            v110,
            v111,
            "populate_dot11f_tx_power_env",
            1,
            v112);
          if ( (v194 & 1) == 0 )
          {
            v121 = (unsigned __int8)(2 * v204);
            a3[5] = 2 * v204;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: non-psd subord TPE %d %d",
              v113,
              v114,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              "populate_dot11f_tx_power_env",
              2,
              v121);
            if ( (v192 & 1) == 0 )
            {
              v130 = (unsigned __int8)(2 * v204);
              a3[6] = 2 * v204;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: non-psd subord TPE %d %d",
                v122,
                v123,
                v124,
                v125,
                v126,
                v127,
                v128,
                v129,
                "populate_dot11f_tx_power_env",
                3,
                v130);
            }
          }
        }
        if ( (v196 & 1) == 0 )
          update_ext_max_tpe_power(a1, a3, a5, 0);
        a3 += 27;
        ++v190;
      }
    }
    v131 = wlan_reg_get_bw_value(a4);
    if ( a2
      && *(_BYTE *)(a2 + 10071) == 1
      && ((v140 = 1LL << wlan_reg_freq_to_band(a5), (v191 & 1) == 0)
        ? ((*(_BYTE *)(a2 + 10165) & 2) != 0 ? (v149 = *(unsigned __int16 *)(a2 + 10173)) : (v149 = 0),
           v150 = *(_QWORD *)(a1 + 21632),
           v151 = *(unsigned __int8 *)(a2 + 7186))
        : (v149 = *(unsigned __int16 *)(a2 + 7216),
           v150 = *(_QWORD *)(a1 + 21632),
           v151 = *(unsigned __int8 *)(a2 + 7191)),
          HIDWORD(v201) = wlan_reg_chan_band_to_freq(v150, v151, v140, v141, v142, v143, v144, v145, v146, v147, v148),
          v149) )
    {
      wlan_reg_set_input_punc_bitmap((__int64)&v200, v149);
      v152 = 0;
    }
    else
    {
      v152 = 1;
    }
    v153 = *(_QWORD *)(a1 + 21632);
    LODWORD(v200) = a4;
    result = wlan_reg_set_channel_params_for_pwrmode(
               v153,
               a5,
               a5,
               (__int64)&v200,
               0,
               v132,
               v133,
               v134,
               v135,
               v136,
               v137,
               v138,
               v139);
    if ( HIDWORD(v201) )
      v154 = HIDWORD(v201);
    else
      v154 = v201;
    if ( (v152 & 1) != 0 )
    {
      if ( v131 == 320 )
      {
        LOBYTE(v155) = 28;
        v156 = 8;
        goto LABEL_64;
      }
    }
    else
    {
      wlan_reg_set_non_eht_ch_params((__int64)&v200, 1);
      result = wlan_reg_set_channel_params_for_pwrmode(
                 *(_QWORD *)(a1 + 21632),
                 a5,
                 a5,
                 (__int64)&v200,
                 0,
                 v157,
                 v158,
                 v159,
                 v160,
                 v161,
                 v162,
                 v163,
                 v164);
      a4 = v200;
    }
    if ( a4 <= 4 )
    {
      v156 = dword_B08DB4[a4];
      v155 = 0x1C1C1B1A19uLL >> (8 * (unsigned __int8)a4);
LABEL_64:
      v165 = 0;
      v166 = v156;
      a3[2] = v156;
      v167 = v131 / 0x14u;
      v168 = v154 - ((unsigned __int16)(v131 & 0xFFFE) >> 1) + 10;
      v169 = v168;
      v193 = v155;
      a3[1] = v155;
      *a3 = 1;
      v195 = v167 - v156;
      v197 = v167;
      do
      {
        wlan_reg_get_client_power_for_6ghz_ap();
        v169 += 20;
        v170 = (unsigned __int8)(2 * v203);
        a3[v165 + 3] = 2 * v203;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: psd default TPE %d %d",
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v178,
          "populate_dot11f_tx_power_env",
          (unsigned int)v165++,
          v170);
      }
      while ( v166 != v165 );
      if ( (_DWORD)v166 != v197 )
        update_ext_max_tpe_power(a1, a3, v169, v195);
      result = wlan_reg_get_client_power_for_6ghz_ap();
      if ( v203 )
      {
        v179 = 0;
        a3[27] = 1;
        a3[28] = v193 | 0x40;
        a3[29] = v166;
        do
        {
          wlan_reg_get_client_power_for_6ghz_ap();
          v180 = 2 * v203;
          v168 += 20;
          a3[v179 + 30] = 2 * v203;
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: psd subord TPE %d %d",
                     v181,
                     v182,
                     v183,
                     v184,
                     v185,
                     v186,
                     v187,
                     v188,
                     "populate_dot11f_tx_power_env",
                     (unsigned int)v179++,
                     v180 & 0xFE);
        }
        while ( v166 != v179 );
        a6 = v189;
        if ( (_DWORD)v166 != v197 )
          result = update_ext_max_tpe_power(a1, a3 + 27, v168, v195);
        v54 = v190 + 2;
      }
      else
      {
        a6 = v189;
        v54 = v190 + 1;
      }
LABEL_75:
      *a6 = v54;
    }
  }
LABEL_76:
  _ReadStatusReg(SP_EL0);
  return result;
}
