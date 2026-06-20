__int64 __fastcall populate_dot11f_tx_power_env(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        _BYTE *a11,
        unsigned int a12,
        unsigned int a13,
        __int16 *a14)
{
  __int64 v19; // x0
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w26
  unsigned __int64 v38; // x24
  unsigned __int64 v39; // x27
  unsigned int bw_value; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x4
  _BOOL4 v50; // w25
  unsigned int v51; // w10
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  char v60; // w9
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x5
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  __int64 v78; // x5
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  __int64 v87; // x5
  __int16 v88; // w8
  unsigned int v89; // w9
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  _BOOL4 v98; // w10
  unsigned int v99; // w11
  unsigned int v100; // w12
  char v101; // w8
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x5
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  __int64 v119; // x5
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  __int64 v128; // x5
  _BYTE *v129; // x25
  unsigned int v130; // w19
  __int64 v131; // x0
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  int v140; // w9
  unsigned int v141; // w8
  int v142; // w9
  __int64 v143; // x19
  int v144; // w23
  __int64 v145; // x24
  int v146; // w27
  char v147; // w8
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x22
  _BYTE *v157; // x25
  unsigned __int8 v158; // w8
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  unsigned __int64 v167; // [xsp+8h] [xbp-48h]
  _BYTE *v168; // [xsp+10h] [xbp-40h]
  __int16 v169; // [xsp+1Ch] [xbp-34h]
  unsigned int v170; // [xsp+20h] [xbp-30h]
  unsigned int v171; // [xsp+28h] [xbp-28h] BYREF
  char v172; // [xsp+2Ch] [xbp-24h]
  __int64 v173; // [xsp+30h] [xbp-20h] BYREF
  __int64 v174; // [xsp+38h] [xbp-18h]
  unsigned __int16 v175; // [xsp+40h] [xbp-10h]
  unsigned __int16 v176; // [xsp+44h] [xbp-Ch]
  __int64 v177; // [xsp+48h] [xbp-8h]

  v177 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = *(_QWORD *)(a1 + 21560);
  v176 = 0;
  v175 = 0;
  v173 = 0;
  v174 = 0;
  v172 = 0;
  v171 = 0;
  wlan_reg_get_cur_6g_ap_pwr_type(v19, &v171, a2, a3, a4, a5, a6, a7, a8, a9);
  result = wlan_reg_is_6ghz_chan_freq(a13);
  if ( (result & 1) != 0 )
  {
    wlan_reg_get_client_power_for_6ghz_ap();
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: chan_freq %d, eirp_power %d, psd_power %d",
               v29,
               v30,
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               "populate_dot11f_tx_power_env",
               a13,
               v176,
               v175);
    if ( a12 > 7 )
      goto LABEL_50;
  }
  else
  {
    v172 = 0;
    if ( a12 > 7 )
      goto LABEL_50;
  }
  if ( ((0x9Fu >> a12) & 1) != 0 )
  {
    v37 = 0x61u >> a12;
    v170 = 2u >> a12;
    v38 = 0x300000303020100uLL >> (8 * (unsigned __int8)a12);
    v39 = 0x401010404030201uLL >> (8 * (unsigned __int8)a12);
    if ( (v172 & 1) == 0 )
    {
      result = wlan_reg_get_channel_reg_power_for_freq(
                 *(_QWORD *)(a1 + 21560),
                 a13,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28);
      v88 = 1;
      a11[1] = v38;
      *a11 = 1;
      a11[2] = v39;
      a11[3] = result;
      if ( (v37 & 1) == 0 )
      {
        a11[4] = result;
        if ( (v170 & 1) != 0 || (a11[5] = result, ((4u >> a12) & 1) != 0) )
        {
          v88 = 1;
        }
        else
        {
          a11[6] = result;
          v88 = 1;
        }
      }
      goto LABEL_49;
    }
    bw_value = (unsigned __int16)wlan_reg_get_bw_value(a12);
    v49 = 20;
    v50 = bw_value > 0x14;
    if ( (unsigned int)v175 + 13 < v176 && bw_value >= 0x15 )
    {
      v51 = v175 + 16;
      do
      {
        v49 = (unsigned int)(2 * v49);
        v50 = (unsigned int)v49 < bw_value;
        if ( v51 >= v176 )
          break;
        v51 += 3;
      }
      while ( (unsigned int)v49 < bw_value );
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: bw_threshold %d",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "populate_dot11f_tx_power_env",
      v49);
    if ( v50 )
    {
      v60 = v176;
      *a11 = 1;
      a11[1] = v38 | 0x10;
      a11[2] = v39;
      a11[3] = 2 * v60;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: non-psd default TPE %d %d",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "populate_dot11f_tx_power_env",
        0,
        (unsigned __int8)(2 * v60));
      if ( (v37 & 1) == 0 )
      {
        v69 = (unsigned __int8)(2 * v176);
        a11[4] = 2 * v176;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: non-psd default TPE %d %d",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "populate_dot11f_tx_power_env",
          1,
          v69);
        if ( (v170 & 1) == 0 )
        {
          v78 = (unsigned __int8)(2 * v176);
          a11[5] = 2 * v176;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: non-psd default TPE %d %d",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "populate_dot11f_tx_power_env",
            2,
            v78);
          if ( ((4u >> a12) & 1) == 0 )
          {
            v87 = (unsigned __int8)(2 * v176);
            a11[6] = 2 * v176;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: non-psd default TPE %d %d",
              v79,
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              "populate_dot11f_tx_power_env",
              3,
              v87);
          }
        }
      }
      a11 += 27;
      v169 = 1;
    }
    else
    {
      v169 = 0;
    }
    wlan_reg_get_client_power_for_6ghz_ap();
    if ( !v176 )
      goto LABEL_35;
    v89 = (unsigned __int16)wlan_reg_get_bw_value(a12);
    v98 = v89 > 0x14;
    if ( (unsigned int)v175 + 13 < v176 && v89 >= 0x15 )
    {
      v99 = v175 + 16;
      v100 = 20;
      do
      {
        v100 *= 2;
        v98 = v100 < v89;
        if ( v99 >= v176 )
          break;
        v99 += 3;
      }
      while ( v100 < v89 );
    }
    if ( v98 || v50 )
    {
      v101 = 2 * v176;
      *a11 = 1;
      a11[2] = v39;
      a11[1] = v38 | 0x50;
      a11[3] = v101;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: non-psd subord TPE %d %d",
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        "populate_dot11f_tx_power_env",
        0,
        v101 & 0xFE);
      if ( (v37 & 1) == 0 )
      {
        v110 = (unsigned __int8)(2 * v176);
        a11[4] = 2 * v176;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: non-psd subord TPE %d %d",
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          "populate_dot11f_tx_power_env",
          1,
          v110);
        if ( (v170 & 1) == 0 )
        {
          v119 = (unsigned __int8)(2 * v176);
          a11[5] = 2 * v176;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: non-psd subord TPE %d %d",
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            v118,
            "populate_dot11f_tx_power_env",
            2,
            v119);
          if ( ((4u >> a12) & 1) == 0 )
          {
            v128 = (unsigned __int8)(2 * v176);
            a11[6] = 2 * v176;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: non-psd subord TPE %d %d",
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              "populate_dot11f_tx_power_env",
              3,
              v128);
          }
        }
      }
      v129 = a11 + 27;
      ++v169;
    }
    else
    {
LABEL_35:
      v129 = a11;
    }
    v130 = (unsigned __int16)wlan_reg_get_bw_value(a12);
    v131 = *(_QWORD *)(a1 + 21560);
    LODWORD(v173) = a12;
    result = wlan_reg_set_channel_params_for_pwrmode(
               v131,
               a13,
               a13,
               (__int64)&v173,
               0,
               v132,
               v133,
               v134,
               v135,
               v136,
               v137,
               v138,
               v139);
    v140 = v174;
    if ( HIDWORD(v174) )
      v140 = HIDWORD(v174);
    if ( v130 == 320 )
      v141 = 3;
    else
      v141 = a12;
    if ( v141 <= 4 )
    {
      v142 = v140 - (v130 >> 1);
      v143 = dword_A16CD4[v141];
      v144 = v142 + 10;
      v145 = 0;
      *v129 = 1;
      v129[2] = v143;
      v167 = 0x1C1C1B1A19uLL >> (8 * (unsigned __int8)v141);
      v168 = v129;
      v146 = v142 + 10;
      v129[1] = v167;
      do
      {
        wlan_reg_get_client_power_for_6ghz_ap();
        v147 = 2 * v175;
        v146 += 20;
        v129[v145 + 3] = 2 * v175;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: psd default TPE %d %d",
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          v154,
          v155,
          "populate_dot11f_tx_power_env",
          (unsigned int)v145++,
          v147 & 0xFE);
      }
      while ( v143 != v145 );
      result = wlan_reg_get_client_power_for_6ghz_ap();
      if ( v175 )
      {
        v156 = 0;
        v129[27] = 1;
        v157 = v129 + 30;
        v168[28] = v167 | 0x40;
        v168[29] = v143;
        do
        {
          wlan_reg_get_client_power_for_6ghz_ap();
          v158 = 2 * v175;
          v144 += 20;
          v157[v156] = 2 * v175;
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: psd subord TPE %d %d",
                     v159,
                     v160,
                     v161,
                     v162,
                     v163,
                     v164,
                     v165,
                     v166,
                     "populate_dot11f_tx_power_env",
                     (unsigned int)v156++,
                     v158 & 0xFE);
        }
        while ( v143 != v156 );
        v88 = v169 + 2;
      }
      else
      {
        v88 = v169 + 1;
      }
LABEL_49:
      *a14 = v88;
    }
  }
LABEL_50:
  _ReadStatusReg(SP_EL0);
  return result;
}
