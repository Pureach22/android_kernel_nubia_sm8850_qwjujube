__int64 __fastcall ml_nlink_handle_legacy_intf_3_ports(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        unsigned __int8 a5,
        unsigned __int8 *a6,
        unsigned int *a7,
        unsigned int *a8)
{
  unsigned int v14; // w19
  __int64 result; // x0
  int v16; // w19
  unsigned int v17; // w20
  unsigned int v18; // w28
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w27
  int v28; // w22
  int v29; // w28
  int v30; // w27
  unsigned int v31; // w8
  unsigned __int64 v32; // x23
  unsigned __int64 v33; // x20
  __int64 v34; // x25
  unsigned __int64 v35; // x26
  unsigned __int64 v36; // x28
  char v37; // w11
  const char *v38; // x2
  unsigned int v39; // w19
  unsigned int v40; // w22
  bool is_24ghz_ch_freq; // w0
  bool v42; // cf
  char v43; // w19
  char v44; // w8
  _WORD *v45; // x20
  int v46; // w13
  __int64 v47; // x24
  unsigned int v48; // w20
  unsigned int v49; // w28
  __int64 v50; // x1
  unsigned int hc_id; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  const char *v60; // x2
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w25
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned int v78; // w22
  unsigned int v79; // w20
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int v88; // w8
  unsigned int *v89; // x19
  unsigned int rd_type; // w0
  char v91; // w0
  __int16 v92; // w9
  __int64 v93; // x4
  __int64 v94; // x6
  const char *v95; // x2
  __int64 v96; // x7
  __int64 v97; // x5
  unsigned int v98; // w24
  __int64 v99; // x4
  unsigned int *v100; // x19
  __int64 v101; // x8
  unsigned int *v102; // x8
  unsigned int v103; // w23
  unsigned int v104; // w24
  const char *v105; // x20
  __int64 v106; // x22
  __int64 v107; // x27
  const char *v108; // x24
  const char *v109; // x23
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  unsigned int v118; // w0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  unsigned int v127; // w0
  char v128; // w20
  char v129; // w27
  char v130; // w11
  char v131; // w9
  int v132; // w10
  int v133; // w8
  char v134; // w28
  unsigned int v135; // w24
  unsigned int v136; // w8
  unsigned __int64 v137; // x22
  __int64 v138; // x24
  bool is_5ghz_ch_freq; // w0
  int *v140; // x8
  unsigned int v141; // w19
  const char *v142; // x25
  __int64 v143; // x22
  __int64 v144; // x27
  const char *v145; // x26
  const char *v146; // x23
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  int v163; // w8
  unsigned int v164; // w9
  unsigned __int16 v165; // w3
  int v166; // w10
  int v167; // w8
  unsigned int v168; // w19
  char v169; // w0
  int v170; // w20
  int v171; // w20
  int v172; // w20
  unsigned int *v173; // x28
  unsigned int *v174; // x24
  int v175; // w23
  unsigned int v176; // w4
  char v177; // w19
  unsigned int v178; // w5
  bool v179; // cc
  __int64 v180; // [xsp+0h] [xbp-1F0h]
  int v181; // [xsp+10h] [xbp-1E0h]
  int v182; // [xsp+10h] [xbp-1E0h]
  unsigned int v183; // [xsp+24h] [xbp-1CCh]
  int v184; // [xsp+28h] [xbp-1C8h]
  unsigned int *v185; // [xsp+30h] [xbp-1C0h]
  char v186; // [xsp+30h] [xbp-1C0h]
  unsigned int *v187; // [xsp+38h] [xbp-1B8h]
  unsigned int *v188; // [xsp+38h] [xbp-1B8h]
  char v189; // [xsp+38h] [xbp-1B8h]
  int v190; // [xsp+40h] [xbp-1B0h]
  int v191; // [xsp+40h] [xbp-1B0h]
  unsigned int v192; // [xsp+40h] [xbp-1B0h]
  int v193; // [xsp+40h] [xbp-1B0h]
  _WORD *v194; // [xsp+40h] [xbp-1B0h]
  int v195; // [xsp+40h] [xbp-1B0h]
  __int64 v196; // [xsp+48h] [xbp-1A8h]
  __int64 v197; // [xsp+48h] [xbp-1A8h]
  __int64 v198; // [xsp+48h] [xbp-1A8h]
  unsigned int v201; // [xsp+58h] [xbp-198h]
  __int64 v202; // [xsp+60h] [xbp-190h]
  const char *v203; // [xsp+60h] [xbp-190h]
  unsigned int v204; // [xsp+6Ch] [xbp-184h]
  unsigned int v205; // [xsp+6Ch] [xbp-184h]
  unsigned int v206; // [xsp+70h] [xbp-180h]
  unsigned int v207; // [xsp+70h] [xbp-180h]
  const char *v208; // [xsp+70h] [xbp-180h]
  unsigned int v209; // [xsp+7Ch] [xbp-174h] BYREF
  __int64 v210; // [xsp+80h] [xbp-170h] BYREF
  unsigned int v211; // [xsp+88h] [xbp-168h] BYREF
  _BYTE v212[4]; // [xsp+8Ch] [xbp-164h] BYREF
  unsigned int v213; // [xsp+90h] [xbp-160h] BYREF
  unsigned int v214; // [xsp+94h] [xbp-15Ch] BYREF
  unsigned int v215; // [xsp+98h] [xbp-158h] BYREF
  _BYTE v216[4]; // [xsp+9Ch] [xbp-154h] BYREF
  unsigned int v217; // [xsp+A0h] [xbp-150h] BYREF
  unsigned int v218; // [xsp+A4h] [xbp-14Ch] BYREF
  unsigned int v219; // [xsp+A8h] [xbp-148h] BYREF
  unsigned int v220; // [xsp+ACh] [xbp-144h] BYREF
  int v221; // [xsp+B0h] [xbp-140h] BYREF
  char v222; // [xsp+B4h] [xbp-13Ch] BYREF
  int v223; // [xsp+B8h] [xbp-138h] BYREF
  char v224; // [xsp+BCh] [xbp-134h]
  int v225; // [xsp+C0h] [xbp-130h] BYREF
  unsigned __int8 v226; // [xsp+C4h] [xbp-12Ch]
  int v227; // [xsp+C8h] [xbp-128h] BYREF
  char v228; // [xsp+CCh] [xbp-124h]
  int v229; // [xsp+D0h] [xbp-120h] BYREF
  char v230; // [xsp+D4h] [xbp-11Ch]
  int v231; // [xsp+D8h] [xbp-118h] BYREF
  char v232; // [xsp+DCh] [xbp-114h]
  int v233; // [xsp+E0h] [xbp-110h] BYREF
  char v234; // [xsp+E4h] [xbp-10Ch]
  int v235; // [xsp+E8h] [xbp-108h] BYREF
  char v236; // [xsp+ECh] [xbp-104h]
  int v237; // [xsp+F0h] [xbp-100h] BYREF
  char v238; // [xsp+F4h] [xbp-FCh]
  int v239; // [xsp+F8h] [xbp-F8h] BYREF
  char v240; // [xsp+FCh] [xbp-F4h]
  int v241; // [xsp+100h] [xbp-F0h] BYREF
  char v242; // [xsp+104h] [xbp-ECh]
  int v243; // [xsp+108h] [xbp-E8h] BYREF
  char v244; // [xsp+10Ch] [xbp-E4h]
  int v245; // [xsp+110h] [xbp-E0h] BYREF
  char v246; // [xsp+114h] [xbp-DCh]
  _BYTE v247[40]; // [xsp+118h] [xbp-D8h] BYREF
  __int64 v248; // [xsp+140h] [xbp-B0h] BYREF
  __int64 v249; // [xsp+148h] [xbp-A8h]
  unsigned int v250; // [xsp+150h] [xbp-A0h]
  __int64 v251; // [xsp+158h] [xbp-98h] BYREF
  __int64 v252; // [xsp+160h] [xbp-90h]
  unsigned int v253; // [xsp+168h] [xbp-88h]
  __int64 v254; // [xsp+170h] [xbp-80h] BYREF
  __int64 v255; // [xsp+178h] [xbp-78h]
  int v256; // [xsp+180h] [xbp-70h]
  __int64 v257; // [xsp+188h] [xbp-68h] BYREF
  __int64 v258; // [xsp+190h] [xbp-60h]
  int v259; // [xsp+198h] [xbp-58h]
  __int64 v260; // [xsp+1A0h] [xbp-50h] BYREF
  __int64 v261; // [xsp+1A8h] [xbp-48h]
  __int64 v262; // [xsp+1B0h] [xbp-40h]
  __int64 v263; // [xsp+1B8h] [xbp-38h]
  __int64 v264; // [xsp+1C0h] [xbp-30h]
  __int64 v265; // [xsp+1C8h] [xbp-28h] BYREF
  __int64 v266; // [xsp+1D0h] [xbp-20h]
  unsigned int v267; // [xsp+1D8h] [xbp-18h]
  __int64 v268; // [xsp+1E0h] [xbp-10h]

  v268 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = a5;
  v212[0] = 0;
  v211 = 0;
  v210 = 0;
  v209 = 0;
  v224 = 0;
  v223 = 0;
  v250 = 0;
  v248 = 0;
  v249 = 0;
  v222 = 0;
  v221 = 0;
  memset(v247, 0, sizeof(v247));
  result = policy_mgr_get_rd_type(a1);
  if ( v14 < 2 )
    goto LABEL_229;
  v16 = result;
  v17 = *a8;
  v18 = *a6;
  v204 = a7[1];
  v206 = *a7;
  result = ml_nlink_get_link_info(
             a1,
             a2,
             1u,
             5u,
             v247,
             (unsigned int *)&v248,
             (unsigned __int8 *)&v223,
             &v221,
             v212,
             &v211);
  v27 = v212[0];
  if ( v212[0] < 2u )
    goto LABEL_229;
  v202 = a3;
  if ( (int)v17 > 1 )
  {
    if ( v17 - 2 < 2 )
    {
      if ( (policy_mgr_is_vdev_high_tput_or_low_latency(a1, v18) & 1) == 0 )
      {
        v190 = v16;
        v28 = 0;
        goto LABEL_99;
      }
      goto LABEL_15;
    }
    if ( v17 == 5 )
      goto LABEL_17;
    goto LABEL_59;
  }
  if ( !v17 )
  {
LABEL_15:
    v28 = 0;
    v190 = v16;
    v185 = a7;
    v187 = a8;
    v196 = a2;
    v183 = 1;
    goto LABEL_100;
  }
  if ( v17 != 1 )
  {
LABEL_59:
    v38 = "%s: unexpected legacy intf mode %d";
LABEL_119:
    result = qdf_trace_msg(
               0x8Fu,
               8u,
               v38,
               v19,
               v20,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               "ml_nlink_handle_legacy_intf_3_ports",
               v17);
    goto LABEL_229;
  }
  v216[0] = 0;
  v215 = 0;
  v234 = 0;
  v233 = 0;
  v256 = 0;
  v254 = 0;
  v255 = 0;
  v232 = 0;
  v231 = 0;
  v263 = 0;
  v264 = 0;
  v261 = 0;
  v262 = 0;
  v260 = 0;
  v230 = 0;
  v229 = 0;
  v228 = 0;
  v227 = 0;
  v253 = 0;
  v251 = 0;
  v252 = 0;
  v226 = 0;
  v225 = 0;
  LOBYTE(v214) = 0;
  LOBYTE(v213) = 0;
  if ( !policy_mgr_is_dual_sap_active(a1) )
    goto LABEL_17;
  ml_nlink_get_link_info(a1, a2, 1u, 5u, &v260, (unsigned int *)&v254, (unsigned __int8 *)&v233, &v231, v216, &v215);
  v29 = v216[0];
  if ( v216[0] < 2u )
    goto LABEL_17;
  policy_mgr_get_ml_and_non_ml_mode_count(
    a1,
    &v214,
    (__int64)&v229,
    &v213,
    (__int64)&v227,
    (unsigned __int64)&v251,
    (unsigned __int64)&v225,
    1u);
  if ( !((unsigned __int8)v213 | (unsigned __int8)v214) )
  {
    v45 = (_WORD *)(a3 + 2);
    wlan_reg_is_6ghz_chan_freq(v254);
    result = wlan_reg_is_6ghz_chan_freq(WORD2(v254));
    v30 = 0;
    v46 = 0;
    goto LABEL_232;
  }
  result = (unsigned int)v251;
  if ( (_DWORD)v251 && (result = wlan_reg_is_5ghz_ch_freq(v251), (result & 1) != 0) )
  {
    result = policy_mgr_get_ap_6ghz_capable(a1, (unsigned __int8)v225, nullptr);
    v30 = result ^ 1;
  }
  else
  {
    v30 = 0;
  }
  if ( (unsigned __int8)v213 + (unsigned int)(unsigned __int8)v214 >= 2 )
  {
    result = HIDWORD(v251);
    if ( HIDWORD(v251) )
    {
      result = wlan_reg_is_5ghz_ch_freq(HIDWORD(v251));
      if ( (result & 1) != 0 )
      {
        result = policy_mgr_get_ap_6ghz_capable(a1, BYTE1(v225), nullptr);
        v30 |= result ^ 1;
      }
    }
    if ( (unsigned __int8)v213 + (unsigned int)(unsigned __int8)v214 >= 3 )
    {
      result = (unsigned int)v252;
      if ( (_DWORD)v252 )
      {
        result = wlan_reg_is_5ghz_ch_freq(v252);
        if ( (result & 1) != 0 )
        {
          result = policy_mgr_get_ap_6ghz_capable(a1, BYTE2(v225), nullptr);
          v30 |= result ^ 1;
        }
      }
      if ( (unsigned __int8)v213 + (unsigned int)(unsigned __int8)v214 >= 4 )
      {
        result = HIDWORD(v252);
        if ( HIDWORD(v252) )
        {
          result = wlan_reg_is_5ghz_ch_freq(HIDWORD(v252));
          if ( (result & 1) != 0 )
          {
            result = policy_mgr_get_ap_6ghz_capable(a1, HIBYTE(v225), nullptr);
            v30 |= result ^ 1;
          }
        }
        if ( (unsigned __int8)v213 + (unsigned int)(unsigned __int8)v214 >= 5 )
        {
          result = v253;
          if ( v253 )
          {
            result = wlan_reg_is_5ghz_ch_freq(v253);
            if ( (result & 1) != 0 )
            {
              result = policy_mgr_get_ap_6ghz_capable(a1, v226, nullptr);
              v30 |= result ^ 1;
            }
          }
          if ( (unsigned __int8)v213 + (unsigned int)(unsigned __int8)v214 > 5 )
            goto LABEL_318;
        }
      }
    }
  }
  v29 = v216[0];
  if ( v216[0] )
  {
    v45 = (_WORD *)(a3 + 2);
    result = wlan_reg_is_6ghz_chan_freq(v254);
    if ( ((unsigned int)result & v30 & 1) != 0 )
    {
      v46 = 1;
      *v45 |= 1 << v231;
    }
    else
    {
      v46 = 0;
    }
    if ( v29 == 1 )
    {
      v134 = 0;
      v129 = 0;
      v130 = 0;
      v131 = 0;
      v132 = 0;
      v128 = 1;
      v133 = 1;
      goto LABEL_262;
    }
    v193 = v46;
    result = wlan_reg_is_6ghz_chan_freq(WORD2(v254));
    if ( ((unsigned int)result & v30 & 1) != 0 )
    {
      v30 = 1;
      v46 = v193 + 1;
      *v45 |= 1 << SBYTE1(v231);
    }
    else
    {
      v46 = v193;
    }
LABEL_232:
    if ( v29 == 2 )
    {
      v134 = 0;
      v128 = 0;
      v130 = 0;
      v131 = 0;
      v132 = 0;
      v133 = 2;
      v129 = 1;
    }
    else
    {
      v194 = v45;
      v170 = v46;
      result = wlan_reg_is_6ghz_chan_freq(v255);
      if ( ((unsigned int)result & v30 & 1) != 0 )
      {
        v46 = v170 + 1;
        *v194 |= 1 << SBYTE2(v231);
      }
      else
      {
        v46 = v170;
      }
      if ( v29 == 3 )
      {
        v134 = 0;
        v128 = 0;
        v129 = 0;
        v131 = 0;
        v132 = 0;
        v133 = 3;
        v130 = 1;
      }
      else
      {
        v171 = v46;
        result = wlan_reg_is_6ghz_chan_freq(WORD2(v255));
        if ( ((unsigned int)result & v30 & 1) != 0 )
        {
          v46 = v171 + 1;
          *v194 |= 1 << SHIBYTE(v231);
        }
        else
        {
          v46 = v171;
        }
        if ( v29 == 4 )
        {
          v134 = 0;
          v128 = 0;
          v129 = 0;
          v130 = 0;
          v132 = 0;
          v133 = 4;
          v131 = 1;
        }
        else
        {
          v172 = v46;
          result = wlan_reg_is_6ghz_chan_freq(v256);
          if ( ((unsigned int)result & v30 & 1) != 0 )
          {
            v46 = v172 + 1;
            *v194 |= 1 << v232;
          }
          else
          {
            v46 = v172;
          }
          if ( v29 != 5 )
            goto LABEL_318;
          v134 = 0;
          v128 = 0;
          v129 = 0;
          v130 = 0;
          v131 = 0;
          v133 = 5;
          v132 = 1;
        }
      }
    }
    goto LABEL_262;
  }
  v128 = 0;
  v129 = 0;
  v130 = 0;
  v131 = 0;
  v132 = 0;
  v133 = 0;
  v46 = 0;
  v134 = 1;
LABEL_262:
  if ( v133 - v46 <= 1 )
    goto LABEL_229;
  v189 = v130;
  v184 = v132;
  v186 = v131;
  LOBYTE(v220) = 0;
  LOBYTE(v219) = 0;
  LOBYTE(v218) = 0;
  LOBYTE(v217) = 0;
  v246 = 0;
  v245 = 0;
  v244 = 0;
  v243 = 0;
  v267 = 0;
  v265 = 0;
  v266 = 0;
  v242 = 0;
  v241 = 0;
  v240 = 0;
  v239 = 0;
  v238 = 0;
  v237 = 0;
  v259 = 0;
  v257 = 0;
  v258 = 0;
  v236 = 0;
  v235 = 0;
  policy_mgr_get_ml_and_non_ml_mode_count(
    a1,
    &v220,
    (__int64)&v245,
    &v219,
    (__int64)&v243,
    (unsigned __int64)&v265,
    (unsigned __int64)&v241,
    0);
  result = policy_mgr_get_ml_and_non_ml_mode_count(
             a1,
             &v218,
             (__int64)&v239,
             &v217,
             (__int64)&v237,
             (unsigned __int64)&v257,
             (unsigned __int64)&v235,
             1u);
  if ( (unsigned __int8)v220 < 2u
    || (unsigned __int8)v218 + (unsigned int)(unsigned __int8)v217 < 2
    || (_DWORD)v265
    && ((_DWORD)v265 == (_DWORD)v257
     || (_DWORD)v265 == HIDWORD(v257)
     || (_DWORD)v265 == (_DWORD)v258
     || (_DWORD)v265 == HIDWORD(v258)
     || (_DWORD)v265 == v259)
    || HIDWORD(v265)
    && (HIDWORD(v265) == (_DWORD)v257
     || HIDWORD(v265) == HIDWORD(v257)
     || HIDWORD(v265) == (_DWORD)v258
     || HIDWORD(v265) == HIDWORD(v258)
     || HIDWORD(v265) == v259)
    || (_DWORD)v266
    && ((_DWORD)v266 == (_DWORD)v257
     || (_DWORD)v266 == HIDWORD(v257)
     || (_DWORD)v266 == (_DWORD)v258
     || (_DWORD)v266 == HIDWORD(v258)
     || (_DWORD)v266 == v259)
    || HIDWORD(v266)
    && (HIDWORD(v266) == (_DWORD)v257
     || HIDWORD(v266) == HIDWORD(v257)
     || HIDWORD(v266) == (_DWORD)v258
     || HIDWORD(v266) == HIDWORD(v258)
     || HIDWORD(v266) == v259)
    || v267
    && (v267 == (_DWORD)v257 || v267 == HIDWORD(v257) || v267 == (_DWORD)v258 || v267 == HIDWORD(v258) || v267 == v259)
    || (v134 & 1) != 0 )
  {
    goto LABEL_265;
  }
  v173 = a7;
  v174 = a8;
  v195 = v16;
  v175 = 1 << v231;
  if ( (v128 & 1) == 0 )
  {
    v175 |= 1 << SBYTE1(v231);
    if ( (v129 & 1) == 0 )
    {
      v175 |= 1 << SBYTE2(v231);
      if ( (v189 & 1) == 0 )
      {
        v175 |= 1 << SHIBYTE(v231);
        if ( (v186 & 1) == 0 )
        {
          if ( !v184 )
            goto LABEL_317;
          v175 |= 1 << v232;
        }
      }
    }
  }
  v176 = 0;
  v177 = 0;
  v178 = v175;
  while ( 1 )
  {
    if ( (v178 & 1) == 0 )
      goto LABEL_306;
    if ( v176 >= 0xF )
      break;
    ++v177;
LABEL_306:
    v179 = v178 > 1;
    ++v176;
    v178 >>= 1;
    if ( !v179 )
      goto LABEL_311;
  }
  result = qdf_trace_msg(
             0x8Fu,
             2u,
             "%s: linkid invalid %d 0x%x",
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             v26,
             "convert_link_bitmap_to_link_ids");
LABEL_311:
  *(_BYTE *)(a3 + 8) = v177;
  if ( (v177 & 0xFE) != 0 )
  {
    *(_WORD *)(a3 + 10) = v175;
    *(_BYTE *)(a3 + 8) = v177 - 1;
  }
  else
  {
    *(_BYTE *)(a3 + 8) = 0;
  }
  v16 = v195;
  a8 = v174;
  a7 = v173;
LABEL_265:
  if ( *(_BYTE *)(a3 + 8) )
    goto LABEL_229;
LABEL_17:
  LOBYTE(v245) = 0;
  LODWORD(v251) = 0;
  BYTE4(v257) = 0;
  LODWORD(v257) = 0;
  v267 = 0;
  v265 = 0;
  v266 = 0;
  BYTE4(v254) = 0;
  LODWORD(v254) = 0;
  v263 = 0;
  v264 = 0;
  v261 = 0;
  v262 = 0;
  v260 = 0;
  if ( wlan_nan_is_disc_active(a1, v19, v20, v21, v22, v23, v24, v25, v26) )
  {
    ml_nlink_get_link_info(
      a1,
      a2,
      1u,
      5u,
      &v260,
      (unsigned int *)&v265,
      (unsigned __int8 *)&v257,
      &v254,
      &v245,
      (unsigned int *)&v251);
    if ( (unsigned __int8)v245 >= 2u )
    {
      v191 = v16;
      v188 = a8;
      v197 = a2;
      if ( !(unsigned int)policy_mgr_get_sap_mode_count(a1, nullptr) )
        goto LABEL_45;
      if ( wlan_reg_is_24ghz_ch_freq(v265) && (_DWORD)v265 != 2437 )
        *(_WORD *)(a3 + 2) |= 1 << v254;
      v31 = (unsigned __int8)v245;
      if ( (unsigned __int8)v245 >= 2u )
      {
        if ( !(unsigned int)policy_mgr_get_sap_mode_count(a1, nullptr) )
          goto LABEL_45;
        if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v265)) && HIDWORD(v265) != 2437 )
          *(_WORD *)(a3 + 2) |= 1 << SBYTE1(v254);
        v31 = (unsigned __int8)v245;
        if ( (unsigned __int8)v245 >= 3u )
        {
          if ( !(unsigned int)policy_mgr_get_sap_mode_count(a1, nullptr) )
            goto LABEL_45;
          if ( wlan_reg_is_24ghz_ch_freq(v266) && (_DWORD)v266 != 2437 )
            *(_WORD *)(a3 + 2) |= 1 << SBYTE2(v254);
          v31 = (unsigned __int8)v245;
          if ( (unsigned __int8)v245 >= 4u )
          {
            if ( !(unsigned int)policy_mgr_get_sap_mode_count(a1, nullptr) )
              goto LABEL_45;
            if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v266)) && HIDWORD(v266) != 2437 )
              *(_WORD *)(a3 + 2) |= 1 << SBYTE3(v254);
            v31 = (unsigned __int8)v245;
            if ( (unsigned __int8)v245 >= 5u )
            {
              if ( !(unsigned int)policy_mgr_get_sap_mode_count(a1, nullptr) )
                goto LABEL_45;
              if ( wlan_reg_is_24ghz_ch_freq(v267) && v267 != 2437 )
                *(_WORD *)(a3 + 2) |= 1 << SBYTE4(v254);
              v31 = (unsigned __int8)v245;
              if ( (unsigned __int8)v245 >= 6u )
              {
                if ( (unsigned int)policy_mgr_get_sap_mode_count(a1, nullptr) )
                  goto LABEL_318;
LABEL_45:
                v31 = (unsigned __int8)v245;
              }
            }
          }
        }
      }
      if ( v31 )
      {
        v32 = 0;
        v33 = v31;
        v34 = 1;
        do
        {
          v35 = v32 + 1;
          if ( v32 + 1 < v33 )
          {
            if ( v32 <= 4 )
            {
              v36 = v34;
              while ( 4 * v32 <= 0x13 )
              {
                if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&v265 + v32)) )
                {
                  if ( v36 > 4 )
                    goto LABEL_318;
                  if ( !wlan_reg_is_24ghz_ch_freq(*((_DWORD *)&v265 + v36))
                    && (policy_mgr_2_freq_same_mac_in_dbs(a1, *((_DWORD *)&v265 + v32), *((_DWORD *)&v265 + v36)) & 1) != 0 )
                  {
                    v37 = *(_BYTE *)(v202 + 8);
                    *(_WORD *)(v202 + 10) |= (unsigned __int16)(1 << *((_BYTE *)&v254 + v32))
                                           | (unsigned __int16)(1 << *((_BYTE *)&v254 + v36));
                    *(_BYTE *)(v202 + 8) = v37 + 1;
                  }
                }
                if ( (_DWORD)v33 == (unsigned __int8)++v36 )
                  goto LABEL_48;
              }
              goto LABEL_317;
            }
            goto LABEL_318;
          }
LABEL_48:
          ++v34;
          ++v32;
        }
        while ( v35 != v33 );
        a3 = v202;
        v39 = *(unsigned __int8 *)(v202 + 8);
        a2 = v197;
        v40 = !wlan_reg_is_24ghz_ch_freq(v265);
        if ( (_DWORD)v33 != 1 )
        {
          v40 += !wlan_reg_is_24ghz_ch_freq(HIDWORD(v265));
          if ( (_DWORD)v33 != 2 )
          {
            v40 += !wlan_reg_is_24ghz_ch_freq(v266);
            if ( (_DWORD)v33 != 3 )
            {
              v40 += !wlan_reg_is_24ghz_ch_freq(HIDWORD(v266));
              if ( (_DWORD)v33 != 4 )
              {
                is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v267);
                if ( (_DWORD)v33 == 5 )
                {
                  v40 += !is_24ghz_ch_freq;
                  goto LABEL_66;
                }
LABEL_317:
                __break(1u);
LABEL_318:
                __break(0x5512u);
              }
            }
          }
        }
LABEL_66:
        v42 = v39 >= v40;
        a8 = v188;
        v16 = v191;
        if ( !v42 )
          goto LABEL_97;
        v43 = !wlan_reg_is_24ghz_ch_freq(v265);
        if ( (_DWORD)v33 != 1 )
        {
          v43 += !wlan_reg_is_24ghz_ch_freq(HIDWORD(v265));
          if ( (_DWORD)v33 != 2 )
          {
            v43 += !wlan_reg_is_24ghz_ch_freq(v266);
            if ( (_DWORD)v33 != 3 )
            {
              v43 += !wlan_reg_is_24ghz_ch_freq(HIDWORD(v266));
              if ( (_DWORD)v33 != 4 )
                v43 += !wlan_reg_is_24ghz_ch_freq(v267);
            }
          }
        }
        v44 = v43 - 1;
      }
      else
      {
        v44 = -1;
      }
      v16 = v191;
      *(_BYTE *)(a3 + 8) = v44;
    }
  }
LABEL_97:
  v27 = v212[0];
  v28 = HIDWORD(v210);
  if ( v212[0] )
  {
    v190 = v16;
LABEL_99:
    v185 = a7;
    v187 = a8;
    v196 = a2;
    v183 = 0;
LABEL_100:
    v47 = 0;
    v48 = 0;
    v49 = 0;
    do
    {
      if ( v47 == 5 )
        goto LABEL_318;
      v50 = *((unsigned int *)&v248 + v47);
      if ( (_DWORD)v50 == v206 || (_DWORD)v50 == v204 )
      {
        v49 |= 1 << *((_BYTE *)&v221 + v47);
      }
      else if ( (policy_mgr_2_freq_always_on_same_mac(a1, v50, v206) & 1) != 0
             || (policy_mgr_2_freq_always_on_same_mac(a1, *((unsigned int *)&v248 + v47), v204) & 1) != 0 )
      {
        v28 |= 1 << *((_BYTE *)&v221 + v47);
      }
      if ( (policy_mgr_vdev_is_force_inactive(a1, *((_BYTE *)&v223 + v47)) & 1) != 0 )
        v48 |= 1 << *((_BYTE *)&v221 + v47);
      ++v47;
    }
    while ( v27 != v47 );
    a7 = v185;
    a8 = v187;
    a3 = v202;
    a2 = v196;
    v16 = v190;
  }
  else
  {
    v183 = 0;
    v49 = 0;
    v48 = 0;
  }
  hc_id = get_hc_id(a1, v27, (unsigned int *)&v248);
  if ( hc_id >= 0x11 )
  {
    v60 = "%s: invalid ml_link_hc_id";
LABEL_114:
    result = qdf_trace_msg(
               0x8Fu,
               8u,
               v60,
               v52,
               v53,
               v54,
               v55,
               v56,
               v57,
               v58,
               v59,
               "ml_nlink_handle_legacy_intf_3_ports");
    goto LABEL_229;
  }
  v192 = hc_id;
  if ( (policy_mgr_2_freq_always_on_same_mac(a1, v206, v204) & 1) != 0 )
  {
    if ( (a4 & 1) != 0 )
    {
      v17 = get_hc_id(a1, 1u, a7);
      if ( v17 >= 4 )
      {
        v38 = "%s: invalid non_ml_hc_id %d";
        goto LABEL_119;
      }
      rd_type = policy_mgr_get_rd_type(a1);
      if ( rd_type >= 5 )
        goto LABEL_318;
      if ( rd_type - 3 <= 0xFFFFFFFD )
      {
        v60 = "%s: unable to get force inactive tbl";
        goto LABEL_114;
      }
      v100 = a8;
      v101 = sta_p2p_tbl[rd_type] + 80LL * v192;
      HIDWORD(v210) = 0;
      v102 = (unsigned int *)(v101 + 8LL * v17);
      v104 = *v102;
      v103 = v102[1];
      hc_id_2_link_bitmap(a1, v27, &v248, &v221, *v102, (char *)&v210 + 4);
      hc_id_2_link_bitmap(a1, v27, &v248, &v221, v103, &v209);
      v203 = hc_id_to_string(v192);
      v105 = hc_id_to_string(v17);
      v106 = device_mode_to_string_1(*v100);
      v107 = device_mode_to_string_1(v100[1]);
      v108 = hc_id_to_string(v104);
      v109 = hc_id_to_string(v103);
      v181 = policy_mgr_get_rd_type(a1);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: ml %s legacy %s mode %s %s inact %s inact num %s rd %d",
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        "ml_nlink_handle_legacy_intf_3_ports",
        v203,
        v105,
        v106,
        v107,
        v108,
        v109,
        v181);
      v78 = HIDWORD(v210);
      v79 = v209;
    }
    else
    {
      v78 = v28 | v49;
      v79 = v211 & ~v78;
      v209 = v79;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: scc link 0x%x force inact 0x%x force inact num 0x%x",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "ml_nlink_handle_legacy_intf_3_ports",
      v49,
      v78,
      v79);
    if ( v78 )
    {
      if ( v206 == v204 )
      {
        if ( v49 )
        {
          if ( (ml_nlink_allow_conc(a1, a2) & 1) != 0 )
            v78 &= ~v49;
          else
            v78 |= v49;
        }
      }
      else
      {
        v78 |= v49;
      }
      if ( (v211 & ~v78) != 0 )
        *(_WORD *)(a3 + 2) |= v78;
      else
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: unexpected no left links: avail 0x%x inact 0x%x",
          v80,
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          "ml_nlink_handle_legacy_intf_3_ports");
    }
    if ( v79 )
    {
      v91 = convert_link_bitmap_to_link_ids(v79, 0, 0, v80, v81, v82, v83, v84, v85, v86, v87);
      *(_BYTE *)(a3 + 8) = v91;
      if ( (v91 & 0xFE) != 0 )
      {
        v92 = v209;
        *(_BYTE *)(a3 + 8) = v91 - 1;
        *(_WORD *)(a3 + 10) = v92;
      }
      else
      {
        *(_BYTE *)(a3 + 8) = 0;
      }
    }
    v93 = v211;
    v94 = *(unsigned __int16 *)(a3 + 2);
    v95 = "%s: avail 0x%x disallow_mcc %d final 0x%x inact num 0x%x";
    v96 = *(unsigned __int16 *)(a3 + 10);
    v97 = v183;
    goto LABEL_228;
  }
  HIDWORD(v210) = 0;
  if ( (a4 & 1) != 0 )
    ml_nlink_handle_mcc_links(a1, a2, a3);
  v69 = get_hc_id(a1, a5, a7);
  if ( v69 >= 0xA )
  {
    result = qdf_trace_msg(
               0x8Fu,
               8u,
               "%s: unexpected non_ml_hc_id %d",
               v70,
               v71,
               v72,
               v73,
               v74,
               v75,
               v76,
               v77,
               "ml_nlink_handle_legacy_intf_3_ports",
               v69);
    goto LABEL_229;
  }
  v88 = *a8;
  v198 = a2;
  if ( (unsigned int)(v16 - 2) <= 2 )
  {
    if ( v88 == 1 )
    {
      if ( a8[1] == 1 )
      {
        if ( v69 != 4 )
        {
          if ( v69 != 8 )
          {
            if ( v69 == 7 )
            {
              v89 = a7;
              goto LABEL_177;
            }
LABEL_181:
            v89 = a7;
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: SAP+SAP, unexpected non_ml_hc_id %d",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "ml_nlink_handle_legacy_intf_3_ports",
              v69);
            goto LABEL_191;
          }
          v89 = a7;
          if ( v192 == 7 )
          {
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: Skip nlink force for STA(2G+5GL)+SAP(2G+5GH)",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "ml_nlink_handle_legacy_intf_3_ports");
            goto LABEL_191;
          }
LABEL_245:
          v99 = 0;
          v98 = 2;
          goto LABEL_193;
        }
        v89 = a7;
LABEL_249:
        v99 = 0;
        v98 = 1;
        goto LABEL_193;
      }
      if ( (v183 & 1) != 0 )
      {
LABEL_165:
        v118 = get_hc_id(a1, 1u, a7);
        v99 = v118;
        if ( v118 < 0xA )
        {
          v89 = a7;
          switch ( v69 )
          {
            case 4u:
              v98 = 1;
              v183 = 1;
              goto LABEL_193;
            case 8u:
              v98 = 2;
              goto LABEL_256;
            case 7u:
              v98 = 3;
LABEL_256:
              v183 = 1;
              goto LABEL_193;
          }
          goto LABEL_187;
        }
LABEL_172:
        result = qdf_trace_msg(
                   0x8Fu,
                   8u,
                   "%s: disallow_mcc %d invalid force_inact_hc_id %d",
                   v119,
                   v120,
                   v121,
                   v122,
                   v123,
                   v124,
                   v125,
                   v126,
                   "ml_nlink_handle_legacy_intf_3_ports",
                   1,
                   (unsigned int)v99);
        goto LABEL_229;
      }
LABEL_173:
      v89 = a7;
      switch ( v69 )
      {
        case 4u:
          v183 = 0;
          goto LABEL_249;
        case 8u:
          v183 = 0;
          goto LABEL_245;
        case 7u:
          v183 = 0;
LABEL_177:
          v99 = 0;
          v98 = 3;
          goto LABEL_193;
      }
LABEL_189:
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: one SAP unexpected non_ml_hc_id %d",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "ml_nlink_handle_legacy_intf_3_ports",
        v69);
    }
    else
    {
      if ( v183 )
        goto LABEL_165;
      if ( a8[1] == 1 )
        goto LABEL_173;
      v89 = a7;
    }
LABEL_190:
    v183 = 0;
    goto LABEL_191;
  }
  if ( v88 == 1 )
  {
    if ( a8[1] == 1 )
    {
      if ( v69 - 7 >= 2 )
        goto LABEL_181;
      v89 = a7;
LABEL_191:
      v99 = 0;
      goto LABEL_192;
    }
    if ( (v183 & 1) == 0 )
    {
      v89 = a7;
      if ( v69 - 7 >= 2 )
        goto LABEL_189;
      goto LABEL_190;
    }
LABEL_171:
    v127 = get_hc_id(a1, 1u, a7);
    v99 = v127;
    if ( v127 >= 0xA )
      goto LABEL_172;
    v89 = a7;
    if ( v69 - 7 < 2 )
    {
      v98 = 0;
      goto LABEL_256;
    }
LABEL_187:
    v135 = v99;
    v183 = 1;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: disallow_mcc %d unexpected non_ml_hc_id %d",
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      v125,
      v126,
      "ml_nlink_handle_legacy_intf_3_ports",
      1,
      v69);
    v99 = v135;
LABEL_192:
    v98 = 0;
    goto LABEL_193;
  }
  if ( v183 )
    goto LABEL_171;
  v89 = a7;
  v183 = 0;
  if ( v69 - 7 < 2 )
  {
    v98 = 0;
    v99 = 0;
    goto LABEL_193;
  }
  v98 = 0;
  v99 = 0;
  if ( a8[1] == 1 )
    goto LABEL_189;
LABEL_193:
  v207 = v99;
  hc_id_2_link_bitmap(a1, v27, &v248, &v221, v99, (char *)&v210 + 4);
  v205 = v98;
  hc_id_2_link_bitmap(a1, v27, &v248, &v221, v98, &v210);
  v136 = a5;
  v137 = 0;
  if ( (a5 & 0xFE) == 0 )
    v136 = 1;
  v138 = 4LL * v136;
  while ( 2 )
  {
    if ( a8[v137 / 4] != 1 )
      goto LABEL_197;
    is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v89[v137 / 4]);
    if ( !v27 || !is_5ghz_ch_freq )
      goto LABEL_197;
    if ( wlan_reg_is_6ghz_chan_freq(v248)
      && (policy_mgr_2_freq_always_on_same_mac(a1, (unsigned int)v248, v89[v137 / 4]) & 1) != 0 )
    {
      v140 = &v221;
      goto LABEL_314;
    }
    if ( v27 == 1 )
      goto LABEL_197;
    if ( wlan_reg_is_6ghz_chan_freq(WORD2(v248))
      && (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v248), v89[v137 / 4]) & 1) != 0 )
    {
      v140 = (int *)((char *)&v221 + 1);
      goto LABEL_314;
    }
    if ( v27 == 2 )
      goto LABEL_197;
    if ( wlan_reg_is_6ghz_chan_freq(v249)
      && (policy_mgr_2_freq_always_on_same_mac(a1, (unsigned int)v249, v89[v137 / 4]) & 1) != 0 )
    {
      v140 = (int *)((char *)&v221 + 2);
      goto LABEL_314;
    }
    if ( v27 == 3 )
    {
LABEL_197:
      v137 += 4LL;
      if ( v138 == v137 )
      {
        v201 = 0;
        goto LABEL_217;
      }
      continue;
    }
    break;
  }
  if ( !wlan_reg_is_6ghz_chan_freq(WORD2(v249))
    || (policy_mgr_2_freq_always_on_same_mac(a1, HIDWORD(v249), v89[v137 / 4]) & 1) == 0 )
  {
    if ( v27 != 4 )
    {
      if ( wlan_reg_is_6ghz_chan_freq(v250) && (policy_mgr_2_freq_always_on_same_mac(a1, v250, v89[v137 / 4]) & 1) != 0 )
      {
        v140 = (int *)&v222;
        goto LABEL_314;
      }
      if ( v27 != 5 )
        goto LABEL_318;
    }
    goto LABEL_197;
  }
  v140 = (int *)((char *)&v221 + 3);
LABEL_314:
  v201 = 1 << *(_BYTE *)v140;
LABEL_217:
  v141 = v207;
  v208 = hc_id_to_string(v192);
  v142 = hc_id_to_string(v69);
  v143 = device_mode_to_string_1(*a8);
  v144 = device_mode_to_string_1(a8[1]);
  v145 = hc_id_to_string(v141);
  v146 = hc_id_to_string(v205);
  v182 = policy_mgr_get_rd_type(a1);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: ml %s legacy %s mode %s %s inact %s inact2 %s rd %d",
    v147,
    v148,
    v149,
    v150,
    v151,
    v152,
    v153,
    v154,
    "ml_nlink_handle_legacy_intf_3_ports",
    v208,
    v142,
    v143,
    v144,
    v145,
    v146,
    v182);
  LODWORD(v146) = v210;
  LODWORD(v143) = HIDWORD(v210);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: scc link 0x%x force inact 0x%x inact2 0x%x inact3 0x%x",
    v155,
    v156,
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    "ml_nlink_handle_legacy_intf_3_ports",
    v49,
    HIDWORD(v210),
    (unsigned int)v210,
    v201);
  v163 = v143 & ~v49;
  v93 = v211;
  v164 = (unsigned int)v146 & ~v49;
  v165 = *(_WORD *)(v202 + 2);
  if ( (v211 & ~v163) != 0 )
  {
    v165 |= v163;
    *(_WORD *)(v202 + 2) = v165;
  }
  v166 = v165;
  v97 = v183;
  v167 = v201 & ~v49;
  if ( ((unsigned int)v93 & ~(v164 | v165)) != 0 )
  {
    v165 |= v164;
    v166 = v165;
    *(_WORD *)(v202 + 2) = v165;
  }
  if ( ((unsigned int)v93 & ~(v167 | v166)) != 0 )
  {
    v165 |= v167;
    *(_WORD *)(v202 + 2) = v165;
  }
  if ( v48 )
  {
    if ( (v165 & (unsigned __int16)v48) == 0 )
    {
      v168 = v93;
      v169 = ml_nlink_allow_conc(a1, v198);
      v165 = *(_WORD *)(v202 + 2);
      v97 = v183;
      v93 = v168;
      if ( (v169 & 1) == 0 )
      {
        v165 |= v48;
        *(_WORD *)(v202 + 2) = v165;
      }
    }
  }
  v95 = "%s: avail 0x%x disallow_mcc %d inact vdev link 0x%x final 0x%x inact num 0x%x";
  v96 = v165;
  v94 = v48;
  LODWORD(v180) = *(unsigned __int16 *)(v202 + 10);
LABEL_228:
  result = qdf_trace_msg(
             0x8Fu,
             8u,
             v95,
             v80,
             v81,
             v82,
             v83,
             v84,
             v85,
             v86,
             v87,
             "ml_nlink_handle_legacy_intf_3_ports",
             v93,
             v97,
             v94,
             v96,
             v180);
LABEL_229:
  _ReadStatusReg(SP_EL0);
  return result;
}
