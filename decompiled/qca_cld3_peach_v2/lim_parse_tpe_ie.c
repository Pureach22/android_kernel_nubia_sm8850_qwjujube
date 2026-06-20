__int64 __fastcall lim_parse_tpe_ie(
        __int64 a1,
        __int64 a2,
        __int64 *a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        _BYTE *a14)
{
  __int64 v18; // x0
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x20
  __int64 v29; // x20
  __int64 v30; // x10
  char v31; // w24
  unsigned int v32; // w6
  unsigned int v33; // w1
  unsigned int v34; // w5
  unsigned int v35; // w2
  int v36; // w4
  int v37; // w22
  int v38; // w3
  int v39; // w7
  char v40; // w27
  unsigned int v41; // w30
  unsigned int v42; // w25
  unsigned int v43; // w26
  int v44; // w9
  int v45; // w8
  __int64 *v46; // x13
  __int64 v47; // x14
  __int64 v48; // x15
  int v49; // w17
  unsigned int v50; // w15
  int v51; // w22
  unsigned int v52; // w26
  _BOOL4 v53; // w9
  unsigned int v54; // w21
  _BOOL4 v55; // w19
  unsigned __int16 bw_value; // w25
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  unsigned __int8 *v65; // x10
  unsigned int v66; // w1
  unsigned int v67; // w22
  int v68; // w19
  char v69; // w8
  bool v70; // zf
  int v71; // w2
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int v88; // w8
  __int64 *v89; // x8
  __int64 v90; // x10
  char v91; // w19
  __int64 v92; // x9
  __int64 v93; // x8
  unsigned int v94; // w8
  __int64 v95; // x22
  unsigned __int64 v96; // x27
  __int64 v97; // x21
  unsigned __int64 v98; // x25
  __int64 v99; // x28
  int v100; // w8
  __int16 v101; // w8
  int v102; // w8
  char v103; // w9
  int v104; // w9
  char v105; // w22
  _BYTE *v106; // x28
  unsigned int v107; // w10
  __int64 *v108; // x25
  unsigned int v109; // w8
  __int64 *v110; // x8
  __int64 v111; // x10
  char v112; // w19
  __int64 v113; // x9
  __int64 v114; // x8
  unsigned int v115; // w8
  __int64 v116; // x22
  unsigned int v117; // w21
  unsigned int v118; // w9
  unsigned int v119; // w27
  int v120; // w25
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  unsigned __int16 *bonded_chan_entry; // x19
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  unsigned __int16 *v138; // x0
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  unsigned int v147; // w8
  __int16 v148; // w9
  unsigned int v149; // w9
  __int16 v150; // w10
  unsigned int v151; // w9
  __int16 v152; // w10
  unsigned int v153; // w9
  __int16 v154; // w10
  unsigned int v155; // w9
  __int16 v156; // w10
  unsigned int v157; // w9
  __int16 v158; // w10
  unsigned int v159; // w9
  __int16 v160; // w10
  unsigned int v161; // w9
  __int16 v162; // w10
  unsigned int v163; // w9
  char v164; // w8
  __int64 *v165; // x8
  __int64 v166; // x10
  char v167; // w19
  __int64 v168; // x9
  __int64 v169; // x8
  unsigned int v170; // w8
  __int64 v171; // x21
  __int64 v172; // x19
  unsigned int v173; // w9
  unsigned int v174; // w21
  unsigned __int8 v175; // w0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  int v192; // w8
  int v193; // w8
  __int64 v194; // x3
  __int16 v195; // w9
  __int64 v196; // x5
  __int64 v197; // x11
  int v198; // w10
  __int64 v199; // x8
  __int64 v200; // x9
  __int64 v201; // x14
  __int64 v202; // x12
  __int64 v203; // x13
  __int16 v204; // w9
  __int64 v205; // x19
  unsigned int v206; // w21
  __int16 v207; // w9
  __int16 v208; // w9
  __int16 v209; // w9
  __int16 v210; // w9
  __int16 v211; // w9
  __int16 v212; // w9
  unsigned int v213; // w19
  unsigned int v214; // w21
  __int64 *v215; // x8
  __int64 v216; // x9
  __int64 v217; // x10
  __int64 v218; // x11
  unsigned int v219; // w9
  __int16 v220; // w8
  unsigned int v221; // w10
  __int16 v222; // w9
  __int64 *v223; // x9
  unsigned __int64 v224; // x22
  __int64 *v225; // x8
  __int64 v226; // x10
  __int64 v227; // x11
  __int64 v228; // x12
  _WORD *v229; // x27
  __int64 v230; // x10
  __int64 v231; // x12
  __int64 v232; // x12
  unsigned int v233; // w10
  int v234; // w8
  __int64 v235; // x25
  _BYTE *v236; // x8
  int v237; // w9
  unsigned int v238; // [xsp+60h] [xbp-110h]
  int v239; // [xsp+64h] [xbp-10Ch]
  _BOOL4 v240; // [xsp+68h] [xbp-108h]
  unsigned int v241; // [xsp+6Ch] [xbp-104h]
  unsigned int v242; // [xsp+70h] [xbp-100h]
  unsigned int v243; // [xsp+74h] [xbp-FCh]
  unsigned int v244; // [xsp+78h] [xbp-F8h]
  unsigned int v245; // [xsp+7Ch] [xbp-F4h]
  __int64 *v246; // [xsp+80h] [xbp-F0h]
  unsigned int v247; // [xsp+88h] [xbp-E8h]
  unsigned int v248; // [xsp+8Ch] [xbp-E4h]
  int v249; // [xsp+90h] [xbp-E0h]
  int v250; // [xsp+94h] [xbp-DCh]
  __int64 v251; // [xsp+98h] [xbp-D8h]
  __int64 v252; // [xsp+A0h] [xbp-D0h]
  int v253; // [xsp+ACh] [xbp-C4h]
  int v254; // [xsp+B0h] [xbp-C0h]
  unsigned int v255; // [xsp+B4h] [xbp-BCh]
  int v256; // [xsp+B8h] [xbp-B8h]
  unsigned int v257; // [xsp+BCh] [xbp-B4h]
  unsigned int v258; // [xsp+C8h] [xbp-A8h]
  char v259; // [xsp+C8h] [xbp-A8h]
  char v260; // [xsp+CCh] [xbp-A4h]
  __int64 v262; // [xsp+D8h] [xbp-98h] BYREF
  __int64 v263; // [xsp+E0h] [xbp-90h]
  __int64 v264; // [xsp+E8h] [xbp-88h]
  __int16 v265; // [xsp+F4h] [xbp-7Ch] BYREF
  __int16 v266[2]; // [xsp+F8h] [xbp-78h] BYREF
  unsigned int v267; // [xsp+FCh] [xbp-74h] BYREF
  __int64 v268; // [xsp+100h] [xbp-70h]
  __int64 v269; // [xsp+108h] [xbp-68h]
  _QWORD v270[2]; // [xsp+110h] [xbp-60h] BYREF
  __int64 v271; // [xsp+120h] [xbp-50h]
  __int64 v272; // [xsp+128h] [xbp-48h]
  _QWORD v273[2]; // [xsp+130h] [xbp-40h] BYREF
  __int64 v274; // [xsp+140h] [xbp-30h] BYREF
  __int64 v275; // [xsp+148h] [xbp-28h]
  _QWORD v276[4]; // [xsp+150h] [xbp-20h]

  v276[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = *(_QWORD *)(a2 + 16);
  v267 = 0;
  v266[0] = 0;
  v265 = 0;
  v263 = 0;
  v264 = 0;
  v262 = 0;
  v272 = 0;
  memset(v273, 0, 11);
  v271 = 0;
  v269 = 0;
  memset(v270, 0, 11);
  v268 = 0;
  result = wlan_vdev_mlme_get_cmpt_obj(v18, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !result )
    goto LABEL_242;
  if ( *(_BYTE *)(a2 + 10070) == 1 )
  {
    v28 = jiffies;
    if ( lim_parse_tpe_ie___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: STA operates in 6 GHz power of SAP, do not update STA power",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "lim_parse_tpe_ie");
      lim_parse_tpe_ie___last_ticks = v28;
    }
    goto LABEL_242;
  }
  *(_BYTE *)(result + 551) = 0;
  v29 = result;
  *(_WORD *)(result + 549) = 0;
  *a14 = 0;
  v252 = a2 + 7174;
  wlan_reg_get_cur_6g_client_type(*(_QWORD *)(a1 + 21632), &v267, v20, v21, v22, v23, v24, v25, v26, v27);
  if ( a4 )
  {
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v34 = 0;
    v35 = 0;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    v39 = 0;
    result = 0;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = a3;
    v256 = 0;
    v257 = 0;
    do
    {
      v47 = *v46;
      v48 = v46[1];
      v49 = *(_DWORD *)((char *)v46 + 23);
      v276[0] = v46[2];
      v274 = v47;
      v275 = v48;
      *(_DWORD *)((char *)v276 + 7) = v49;
      if ( (_BYTE)v47 && v267 == BYTE1(v274) >> 6 )
      {
        v50 = (BYTE1(v274) >> 3) & 7;
        if ( v50 > 2 )
        {
          switch ( v50 )
          {
            case 3u:
              ++v44;
              result = 1;
              v257 = (unsigned __int8)v30;
              v36 = 1;
              v32 = (unsigned __int8)v30;
              break;
            case 4u:
              ++v44;
              v40 = 1;
              v42 = (unsigned __int8)v30;
              v256 = 1;
              break;
            case 5u:
              ++v44;
              result = 1;
              v41 = (unsigned __int8)v30;
              v31 = 1;
              break;
          }
        }
        else if ( v50 )
        {
          if ( v50 == 1 )
          {
            ++v45;
            result = 1;
            v257 = (unsigned __int8)v30;
            v38 = 1;
            v34 = (unsigned __int8)v30;
          }
          else
          {
            ++v44;
            v40 = 1;
            v43 = (unsigned __int8)v30;
            v37 = 1;
            v33 = (unsigned __int8)v30;
          }
        }
        else
        {
          ++v45;
          v40 = 1;
          v43 = (unsigned __int8)v30;
          v39 = 1;
          v35 = (unsigned __int8)v30;
        }
      }
      ++v30;
      v46 = (__int64 *)((char *)v46 + 27);
    }
    while ( a4 != v30 );
  }
  else
  {
    LOBYTE(v45) = 0;
    LOBYTE(v44) = 0;
    v257 = 0;
    v43 = 0;
    v42 = 0;
    v41 = 0;
    v40 = 0;
    result = 0;
    v39 = 0;
    v38 = 0;
    v37 = 0;
    v36 = 0;
    v35 = 0;
    v34 = 0;
    v33 = 0;
    v32 = 0;
    v256 = 0;
    v31 = 0;
  }
  v253 = v37;
  v254 = v39;
  v244 = v32;
  if ( (unsigned __int8)v44 | (unsigned __int8)v45 )
  {
    v51 = result;
    v245 = v43;
    v52 = *(_DWORD *)(a2 + 284);
    v258 = (unsigned __int8)v44;
    v53 = (unsigned __int8)v44 != 0;
    v54 = (unsigned __int8)v45;
    v248 = v41;
    v249 = v36;
    v255 = v42;
    v241 = v34;
    v242 = v35;
    v250 = v38;
    v243 = v33;
    v246 = a3;
    if ( (_BYTE)v45 )
      v55 = v53;
    else
      v55 = 0;
    bw_value = wlan_reg_get_bw_value(*(_DWORD *)(a2 + 7176));
    v240 = v55;
    if ( wlan_reg_is_6ghz_chan_freq(v52) )
    {
      v65 = (unsigned __int8 *)(a2 + 7174);
      v66 = *(unsigned __int8 *)(a2 + 10069);
      if ( (v51 & 1) == 0 )
      {
        v68 = 0;
        v69 = 0;
LABEL_34:
        if ( v255 )
          v70 = v66 == 1;
        else
          v70 = 1;
        if ( v70 )
          v69 = v40;
        v260 = v69;
        if ( (v65[2991] & 2) != 0 )
          v71 = *(unsigned __int16 *)(v65 + 2999);
        else
          v71 = 0;
        v247 = v66;
        v238 = bw_value;
        v239 = v71;
        v251 = a2;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: psd_set: %d, non_psd_set: %d, reg_count: %d, local_count: %d, conn_pwr_type_sp: %d, freq: %d, seg0: %d, se"
          "g1: %d, bw_val: %d, puncture_bit_map: %d, Local: eirp: %d psd: %d, Regulatory: eirp: %d psd %d, Addn Regulator"
          "y PSD %d eirp %d",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "lim_parse_tpe_ie",
          v68 & 1,
          v69 & 1,
          v258,
          v54,
          v66 == 1,
          *(_DWORD *)(a2 + 284),
          *v65,
          v65[12],
          bw_value,
          v71,
          v254 & 1,
          v250 & 1,
          v253 & 1,
          v249 & 1,
          v31 & 1,
          v256 & 1);
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: psd_index: %u non_psd_index %u addn_non_psd_index %u addn_psd_index %u",
                   v72,
                   v73,
                   v74,
                   v75,
                   v76,
                   v77,
                   v78,
                   v79,
                   "lim_parse_tpe_ie",
                   v257,
                   v245,
                   v255,
                   v248);
        v259 = v68;
        if ( (v260 & 1 & (v68 ^ 1 | v256)) == 1 )
        {
          v88 = v255;
          if ( ((v247 == 1) & (unsigned __int8)v256) != 0 || (v88 = v245, ((v254 | v253) & 1) != 0) )
          {
            v89 = (__int64 *)((char *)v246 + 27 * v88);
            v90 = v89[1];
            v91 = BYTE1(*v89);
            v274 = *v89;
            v275 = v90;
            v92 = v89[2];
            LODWORD(v89) = *(_DWORD *)((char *)v89 + 23);
            v276[0] = v92;
            *(_DWORD *)((char *)v276 + 7) = (_DWORD)v89;
            if ( (v91 & 7u) >= 4 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Invalid max tx pwr count: %d",
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                "lim_parse_tpe_ie");
              v91 = v91 & 0xF8 | 3;
              BYTE1(v274) = v91;
            }
            v93 = *(unsigned int *)(a2 + 7176);
            if ( (unsigned int)v93 < 8 && ((0x8Fu >> v93) & 1) != 0 )
            {
              v94 = dword_B35388[v93];
              if ( v94 >= (v91 & 7u) )
                LOBYTE(v94) = v91 & 7;
              v91 = v91 & 0xF8 | v94;
              BYTE1(v274) = v91;
            }
            else
            {
              v95 = jiffies;
              if ( lim_get_num_pwr_levels___last_ticks_52 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Invalid channel width",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  "lim_get_num_pwr_levels");
                lim_get_num_pwr_levels___last_ticks_52 = v95;
              }
            }
            v96 = v91 & 7;
            v97 = 0;
            v98 = 0;
            v99 = v29 + 572;
            *(_BYTE *)(v29 + 544) = 0;
            *(_WORD *)(v29 + 546) = 0;
            *(_BYTE *)(v29 + 549) = (v91 & 7) + 1;
            *(_BYTE *)(v29 + 551) = (v91 & 7) + 1;
            LODWORD(v262) = 0;
            while ( 1 )
            {
              result = wlan_reg_set_channel_params_for_pwrmode(
                         *(_QWORD *)(a1 + 21632),
                         v52,
                         0,
                         (__int64)&v262,
                         0,
                         v80,
                         v81,
                         v82,
                         v83,
                         v84,
                         v85,
                         v86,
                         v87);
              if ( (v31 & 1) == 0 )
              {
                if ( v98 - 24 < 0xFFFFFFFFFFFFFFE5LL )
                  goto LABEL_244;
                if ( *(unsigned __int8 *)(v29 + v98 + 636) != *((unsigned __int8 *)&v274 + v98 + 3)
                  || *(_DWORD *)(v99 + 4 * v98) != (_DWORD)v263 )
                {
                  *a14 = 1;
                }
              }
              v100 = v263;
              *(_DWORD *)(v99 + 4 * v98) = v263;
              if ( v98 == 6 )
                goto LABEL_243;
              *(_DWORD *)(v29 + v97 + 908) = v100;
              if ( v98 - 24 < 0xFFFFFFFFFFFFFFE5LL )
                goto LABEL_244;
              v101 = *((unsigned __int8 *)&v274 + v98 + 3);
              *(_BYTE *)(v29 + v98 + 636) = v101;
              *(_WORD *)(v29 + v97 + 912) = v101;
              v102 = v262;
              if ( (_DWORD)v262 == 8 )
              {
                if ( v98 >= v96 )
                  break;
              }
              else
              {
                if ( (unsigned int)v262 > 7 )
                  goto LABEL_243;
                LODWORD(v262) = get_next_higher_bw[(unsigned int)v262];
                if ( v98 >= v96 || v102 == 3 )
                {
                  if ( v102 == 3 )
                  {
                    result = lim_update_ext_tpe_power(a1, v251, &v274, 0, a14, 0, 0, 0);
                    v103 = *(_BYTE *)(v29 + 551) + result;
                    *(_BYTE *)(v29 + 549) += result;
                    *(_BYTE *)(v29 + 551) = v103;
                  }
                  break;
                }
              }
              ++v98;
              v97 += 8;
            }
          }
        }
        v104 = v239;
        v105 = v259;
        v106 = a14;
        if ( v239 != 0 && (v259 & 1) != 0 )
        {
          v107 = v247;
          v108 = v246;
          v109 = v248;
          if ( ((v247 == 1) & (unsigned __int8)v31) == 0 )
          {
            v109 = v257;
            if ( ((v250 | v249) & 1) == 0 )
              goto LABEL_211;
          }
          v110 = (__int64 *)((char *)v246 + 27 * v109);
          v111 = v110[1];
          v112 = BYTE1(*v110);
          v274 = *v110;
          v275 = v111;
          v113 = v110[2];
          LODWORD(v110) = *(_DWORD *)((char *)v110 + 23);
          v276[0] = v113;
          *(_DWORD *)((char *)v276 + 7) = (_DWORD)v110;
          if ( (v112 & 7u) >= 5 )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Invalid max tx pwr count psd: %d",
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              "lim_parse_tpe_ie");
            v112 = v112 & 0xF8 | 4;
            BYTE1(v274) = v112;
          }
          v114 = *(unsigned int *)(v251 + 7176);
          if ( (unsigned int)v114 < 8 && ((0x8Fu >> v114) & 1) != 0 )
          {
            v115 = dword_B35328[v114];
          }
          else
          {
            v116 = jiffies;
            if ( lim_get_num_pwr_levels___last_ticks - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: Invalid channel width",
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                "lim_get_num_pwr_levels");
              v115 = 0;
              lim_get_num_pwr_levels___last_ticks = v116;
            }
            else
            {
              v115 = 0;
            }
          }
          v117 = (v112 & 7) - 1;
          *(_BYTE *)(v29 + 544) = 1;
          v118 = (unsigned __int8)(1 << ((v112 & 7) - 1));
          if ( (v112 & 7) == 0 )
            v118 = 0;
          if ( v115 >= v118 )
            v119 = v118;
          else
            v119 = v115;
          *(_BYTE *)(v29 + 549) = v119;
          *(_BYTE *)(v29 + 550) = v119;
          v120 = wlan_reg_compute_6g_center_freq_from_cfi(*(_BYTE *)(v252 + 12));
          bonded_chan_entry = wlan_reg_get_bonded_chan_entry(
                                v52,
                                *(_DWORD *)(v251 + 7176),
                                v120,
                                v121,
                                v122,
                                v123,
                                v124,
                                v125,
                                v126,
                                v127,
                                v128);
          v138 = wlan_reg_get_bonded_chan_entry(v52, v117, v120, v130, v131, v132, v133, v134, v135, v136, v137);
          if ( v138 )
          {
            if ( !v119 )
              goto LABEL_129;
            v147 = *v138;
            if ( v147 > v138[1] )
              goto LABEL_129;
            v148 = BYTE3(v274);
            if ( *(unsigned __int8 *)(v29 + 636) != BYTE3(v274) || *(_DWORD *)(v29 + 572) != v147 )
              *a14 = 1;
            *(_DWORD *)(v29 + 572) = v147;
            *(_DWORD *)(v29 + 780) = v147;
            *(_BYTE *)(v29 + 636) = v148;
            *(_WORD *)(v29 + 784) = v148;
            if ( v119 == 1 )
              goto LABEL_129;
            v149 = v147 + 20;
            if ( v147 + 20 > v138[1] )
              goto LABEL_129;
            v150 = BYTE4(v274);
            if ( *(unsigned __int8 *)(v29 + 637) != BYTE4(v274) || *(_DWORD *)(v29 + 576) != v149 )
              *a14 = 1;
            *(_DWORD *)(v29 + 576) = v149;
            *(_DWORD *)(v29 + 788) = v149;
            *(_BYTE *)(v29 + 637) = v150;
            *(_WORD *)(v29 + 792) = v150;
            if ( v119 == 2 )
              goto LABEL_129;
            v151 = v147 + 40;
            if ( v147 + 40 > v138[1] )
              goto LABEL_129;
            v152 = BYTE5(v274);
            if ( *(unsigned __int8 *)(v29 + 638) != BYTE5(v274) || *(_DWORD *)(v29 + 580) != v151 )
              *a14 = 1;
            *(_DWORD *)(v29 + 580) = v151;
            *(_DWORD *)(v29 + 796) = v151;
            *(_BYTE *)(v29 + 638) = v152;
            *(_WORD *)(v29 + 800) = v152;
            if ( v119 == 3 )
              goto LABEL_129;
            v153 = v147 + 60;
            if ( v147 + 60 > v138[1] )
              goto LABEL_129;
            v154 = BYTE6(v274);
            if ( *(unsigned __int8 *)(v29 + 639) != BYTE6(v274) || *(_DWORD *)(v29 + 584) != v153 )
              *a14 = 1;
            *(_DWORD *)(v29 + 584) = v153;
            *(_DWORD *)(v29 + 804) = v153;
            *(_BYTE *)(v29 + 639) = v154;
            *(_WORD *)(v29 + 808) = v154;
            if ( v119 == 4 )
              goto LABEL_129;
            v155 = v147 + 80;
            if ( v147 + 80 > v138[1] )
              goto LABEL_129;
            v156 = HIBYTE(v274);
            if ( *(unsigned __int8 *)(v29 + 640) != HIBYTE(v274) || *(_DWORD *)(v29 + 588) != v155 )
              *a14 = 1;
            *(_DWORD *)(v29 + 588) = v155;
            *(_DWORD *)(v29 + 812) = v155;
            *(_BYTE *)(v29 + 640) = v156;
            *(_WORD *)(v29 + 816) = v156;
            if ( v119 == 5 )
              goto LABEL_129;
            v157 = v147 + 100;
            if ( v147 + 100 > v138[1] )
              goto LABEL_129;
            v158 = (unsigned __int8)v275;
            if ( *(unsigned __int8 *)(v29 + 641) != (unsigned __int8)v275 || *(_DWORD *)(v29 + 592) != v157 )
              *a14 = 1;
            *(_DWORD *)(v29 + 592) = v157;
            *(_DWORD *)(v29 + 820) = v157;
            *(_BYTE *)(v29 + 641) = v158;
            *(_WORD *)(v29 + 824) = v158;
            if ( v119 == 6 )
              goto LABEL_129;
            v159 = v147 + 120;
            if ( v147 + 120 > v138[1] )
              goto LABEL_129;
            v160 = BYTE1(v275);
            if ( *(unsigned __int8 *)(v29 + 642) != BYTE1(v275) || *(_DWORD *)(v29 + 596) != v159 )
              *a14 = 1;
            *(_DWORD *)(v29 + 596) = v159;
            *(_DWORD *)(v29 + 828) = v159;
            *(_BYTE *)(v29 + 642) = v160;
            *(_WORD *)(v29 + 832) = v160;
            if ( v119 == 7 )
              goto LABEL_129;
            v161 = v147 + 140;
            if ( v147 + 140 > v138[1] )
              goto LABEL_129;
            v162 = BYTE2(v275);
            if ( *(unsigned __int8 *)(v29 + 643) != BYTE2(v275) || *(_DWORD *)(v29 + 600) != v161 )
              *a14 = 1;
            *(_DWORD *)(v29 + 600) = v161;
            *(_DWORD *)(v29 + 836) = v161;
            *(_BYTE *)(v29 + 643) = v162;
            *(_WORD *)(v29 + 840) = v162;
            if ( v119 == 8 || v147 + 160 > v138[1] )
            {
LABEL_129:
              if ( bonded_chan_entry )
                v52 = *bonded_chan_entry;
              v106 = a14;
              result = lim_update_ext_tpe_power(a1, v251, &v274, v52, a14, v119, v138, 1);
              v108 = v246;
              v105 = v259;
              goto LABEL_210;
            }
LABEL_243:
            __break(0x5512u);
LABEL_244:
            __break(1u);
          }
          result = qdf_trace_msg(
                     0x35u,
                     8u,
                     "%s: tx pwr count don't match with any chan pair",
                     v139,
                     v140,
                     v141,
                     v142,
                     v143,
                     v144,
                     v145,
                     v146,
                     "lim_parse_tpe_ie");
          v105 = v259;
          v104 = 0;
        }
        v70 = v104 == 0;
        v108 = v246;
        v107 = v247;
        v163 = v248;
        v164 = !v70;
        if ( !(v164 & 1 | ((v105 & 1) == 0)) )
        {
          if ( ((v247 == 1) & (unsigned __int8)v31) != 0 || (v163 = v257, ((v250 | v249) & 1) != 0) )
          {
            v165 = (__int64 *)((char *)v246 + 27 * v163);
            v166 = v165[1];
            v167 = BYTE1(*v165);
            v274 = *v165;
            v275 = v166;
            v168 = v165[2];
            LODWORD(v165) = *(_DWORD *)((char *)v165 + 23);
            v276[0] = v168;
            *(_DWORD *)((char *)v276 + 7) = (_DWORD)v165;
            if ( (v167 & 7u) >= 5 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Invalid max tx pwr count psd: %d",
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                "lim_parse_tpe_ie");
              v167 = v167 & 0xF8 | 4;
              BYTE1(v274) = v167;
            }
            v169 = *(unsigned int *)(v251 + 7176);
            if ( (unsigned int)v169 < 8 && ((0x8Fu >> v169) & 1) != 0 )
            {
              v170 = dword_B35328[v169];
            }
            else
            {
              v171 = jiffies;
              if ( lim_get_num_pwr_levels___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Invalid channel width",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  "lim_get_num_pwr_levels");
                v170 = 0;
                lim_get_num_pwr_levels___last_ticks = v171;
              }
              else
              {
                v170 = 0;
              }
            }
            *(_BYTE *)(v29 + 544) = 1;
            v173 = (unsigned __int8)(1 << ((v167 & 7) - 1));
            if ( (v167 & 7) == 0 )
              v173 = 0;
            if ( v170 >= v173 )
              v174 = v173;
            else
              v174 = v170;
            *(_BYTE *)(v29 + 549) = v174;
            *(_BYTE *)(v29 + 550) = v174;
            v175 = *(_BYTE *)(v252 + 12);
            LODWORD(v262) = *(_DWORD *)(v251 + 7176);
            HIDWORD(v263) = wlan_reg_compute_6g_center_freq_from_cfi(v175);
            wlan_reg_set_channel_params_for_pwrmode(
              *(_QWORD *)(a1 + 21632),
              v52,
              0,
              (__int64)&v262,
              0,
              v176,
              v177,
              v178,
              v179,
              v180,
              v181,
              v182,
              v183);
            v192 = HIDWORD(v263);
            if ( !HIDWORD(v263) )
              v192 = v263;
            v193 = v192 - (v238 >> 1);
            v194 = (unsigned int)(v193 + 10);
            if ( v174 )
            {
              v195 = BYTE3(v274);
              if ( *(unsigned __int8 *)(v29 + 636) != BYTE3(v274) || *(_DWORD *)(v29 + 572) != (_DWORD)v194 )
                *a14 = 1;
              *(_DWORD *)(v29 + 780) = v194;
              *(_DWORD *)(v29 + 572) = v194;
              v194 = (unsigned int)(v193 + 30);
              *(_BYTE *)(v29 + 636) = v195;
              *(_WORD *)(v29 + 784) = v195;
              if ( v174 == 1 )
              {
                v196 = 1;
              }
              else
              {
                v204 = BYTE4(v274);
                if ( *(unsigned __int8 *)(v29 + 637) != BYTE4(v274) || *(_DWORD *)(v29 + 576) != (_DWORD)v194 )
                  *a14 = 1;
                *(_DWORD *)(v29 + 788) = v194;
                *(_DWORD *)(v29 + 576) = v194;
                v194 = (unsigned int)(v193 + 50);
                *(_BYTE *)(v29 + 637) = v204;
                *(_WORD *)(v29 + 792) = v204;
                if ( v174 == 2 )
                {
                  v196 = 2;
                }
                else
                {
                  v207 = BYTE5(v274);
                  if ( *(unsigned __int8 *)(v29 + 638) != BYTE5(v274) || *(_DWORD *)(v29 + 580) != (_DWORD)v194 )
                    *a14 = 1;
                  *(_DWORD *)(v29 + 796) = v194;
                  *(_DWORD *)(v29 + 580) = v194;
                  v194 = (unsigned int)(v193 + 70);
                  *(_BYTE *)(v29 + 638) = v207;
                  *(_WORD *)(v29 + 800) = v207;
                  if ( v174 == 3 )
                  {
                    v196 = 3;
                  }
                  else
                  {
                    v208 = BYTE6(v274);
                    if ( *(unsigned __int8 *)(v29 + 639) != BYTE6(v274) || *(_DWORD *)(v29 + 584) != (_DWORD)v194 )
                      *a14 = 1;
                    *(_DWORD *)(v29 + 804) = v194;
                    *(_DWORD *)(v29 + 584) = v194;
                    v194 = (unsigned int)(v193 + 90);
                    *(_BYTE *)(v29 + 639) = v208;
                    *(_WORD *)(v29 + 808) = v208;
                    if ( v174 == 4 )
                    {
                      v196 = 4;
                    }
                    else
                    {
                      v209 = HIBYTE(v274);
                      if ( *(unsigned __int8 *)(v29 + 640) != HIBYTE(v274) || *(_DWORD *)(v29 + 588) != (_DWORD)v194 )
                        *a14 = 1;
                      *(_DWORD *)(v29 + 812) = v194;
                      *(_DWORD *)(v29 + 588) = v194;
                      v194 = (unsigned int)(v193 + 110);
                      *(_BYTE *)(v29 + 640) = v209;
                      *(_WORD *)(v29 + 816) = v209;
                      if ( v174 == 5 )
                      {
                        v196 = 5;
                      }
                      else
                      {
                        v210 = (unsigned __int8)v275;
                        if ( *(unsigned __int8 *)(v29 + 641) != (unsigned __int8)v275
                          || *(_DWORD *)(v29 + 592) != (_DWORD)v194 )
                        {
                          *a14 = 1;
                        }
                        *(_DWORD *)(v29 + 820) = v194;
                        *(_DWORD *)(v29 + 592) = v194;
                        v194 = (unsigned int)(v193 + 130);
                        *(_BYTE *)(v29 + 641) = v210;
                        *(_WORD *)(v29 + 824) = v210;
                        if ( v174 == 6 )
                        {
                          v196 = 6;
                        }
                        else
                        {
                          v211 = BYTE1(v275);
                          if ( *(unsigned __int8 *)(v29 + 642) != BYTE1(v275) || *(_DWORD *)(v29 + 596) != (_DWORD)v194 )
                            *a14 = 1;
                          *(_DWORD *)(v29 + 828) = v194;
                          *(_DWORD *)(v29 + 596) = v194;
                          v194 = (unsigned int)(v193 + 150);
                          *(_BYTE *)(v29 + 642) = v211;
                          *(_WORD *)(v29 + 832) = v211;
                          if ( v174 == 7 )
                          {
                            v196 = 7;
                          }
                          else
                          {
                            v212 = BYTE2(v275);
                            if ( *(unsigned __int8 *)(v29 + 643) != BYTE2(v275)
                              || *(_DWORD *)(v29 + 600) != (_DWORD)v194 )
                            {
                              *a14 = 1;
                            }
                            *(_DWORD *)(v29 + 836) = v194;
                            *(_DWORD *)(v29 + 600) = v194;
                            *(_BYTE *)(v29 + 643) = v212;
                            *(_WORD *)(v29 + 840) = v212;
                            if ( v174 != 8 )
                              goto LABEL_243;
                            v106 = a14;
                            v108 = v246;
                            v194 = (unsigned int)(v193 + 170);
                            v105 = v259;
                            v196 = 8;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            else
            {
              v197 = *(unsigned int *)(v251 + 7176);
              if ( (unsigned int)v197 < 8 && ((0x8Fu >> v197) & 1) != 0 )
              {
                v198 = BYTE3(v274);
                v196 = dword_B35328[v197];
                v199 = 0;
                v200 = 0;
                *(_BYTE *)(v29 + 549) = v196;
                *(_BYTE *)(v29 + 550) = v196;
                do
                {
                  v202 = v29 + v200;
                  v203 = v29 + 4 * v200;
                  if ( *(unsigned __int8 *)(v29 + v200 + 636) != v198 || (_DWORD)v194 != *(_DWORD *)(v203 + 572) )
                    *a14 = 1;
                  v201 = v29 + v199;
                  ++v200;
                  *(_DWORD *)(v203 + 572) = v194;
                  *(_DWORD *)(v201 + 780) = v194;
                  v194 = (unsigned int)(v194 + 20);
                  v199 += 8;
                  *(_BYTE *)(v202 + 636) = v198;
                  *(_WORD *)(v201 + 784) = v198;
                }
                while ( v196 != v200 );
              }
              else
              {
                v205 = jiffies;
                if ( lim_get_num_pwr_levels___last_ticks - jiffies + 125 < 0 )
                {
                  v206 = v193 + 10;
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: Invalid channel width",
                    v184,
                    v185,
                    v186,
                    v187,
                    v188,
                    v189,
                    v190,
                    v191,
                    "lim_get_num_pwr_levels");
                  v194 = v206;
                  lim_get_num_pwr_levels___last_ticks = v205;
                }
                v196 = 0;
                *(_WORD *)(v29 + 549) = 0;
              }
            }
            result = lim_update_ext_tpe_power(a1, v251, &v274, v194, v106, v196, 0, 1);
LABEL_210:
            v107 = v247;
            *(_BYTE *)(v29 + 549) = result;
            *(_BYTE *)(v29 + 550) = result;
          }
        }
LABEL_211:
        v214 = v242;
        v213 = v243;
        if ( (v260 & 1) != 0 )
        {
          if ( ((v107 == 1) & (unsigned __int8)v256) != 0 || (v255 = v245, ((v254 | v253) & 1) != 0) )
          {
            v215 = (__int64 *)((char *)v108 + 27 * v255);
            v216 = *v215;
            v217 = v215[1];
            v218 = v215[2];
            LODWORD(v215) = *(_DWORD *)((char *)v215 + 23);
            v276[0] = v218;
            v274 = v216;
            v275 = v217;
            v219 = BYTE1(v216);
            *(_DWORD *)((char *)v276 + 7) = (_DWORD)v215;
            v220 = *((unsigned __int8 *)&off_0 + ((unsigned __int64)&v274 | v219 & 7) + 3);
            *(_WORD *)(v29 + 546) = v220;
            if ( *(_DWORD *)(v251 + 7176) == 7 )
            {
              if ( (v219 & 7) > 2 )
              {
                if ( BYTE2(v274) >= 5u )
                {
                  v221 = (v219 >> 3) & 7;
                  v222 = 0;
                  if ( v221 > 4 || ((1 << v221) & 0x15) == 0 || (v222 = BYTE3(v275), BYTE3(v275) != 100) )
                  {
                    v220 = v222;
                    *(_WORD *)(v29 + 546) = v222;
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: tx power count advertised by ap %d less than %d",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  "lim_get_eirp_320_power_from_tpe_ie");
                v220 = *(_WORD *)(v29 + 546);
              }
            }
            result = qdf_trace_msg(
                       0x35u,
                       8u,
                       "%s: eirp_power %d",
                       v80,
                       v81,
                       v82,
                       v83,
                       v84,
                       v85,
                       v86,
                       v87,
                       "lim_parse_tpe_ie",
                       (unsigned int)v220);
            if ( (v105 & 1) == 0 )
              *(_BYTE *)(v29 + 544) = 0;
          }
        }
        if ( v240 )
        {
          if ( (v254 & v253 & 1) != 0 || (v213 = v244, v214 = v241, (v250 & v249 & 1) != 0) )
          {
            v223 = (__int64 *)((char *)v108 + 27 * v214);
            v224 = 0;
            v225 = (__int64 *)((char *)v108 + 27 * v213);
            v226 = *v223;
            v227 = v223[1];
            v228 = v223[2];
            LODWORD(v223) = *(_DWORD *)((char *)v223 + 23);
            v229 = (_WORD *)(v29 + 912);
            v273[0] = v228;
            v271 = v226;
            v272 = v227;
            v230 = *v225;
            v231 = v225[1];
            *(_DWORD *)((char *)v273 + 7) = (_DWORD)v223;
            v268 = v230;
            v269 = v231;
            v232 = v225[2];
            LODWORD(v225) = *(_DWORD *)((char *)v225 + 23);
            v233 = BYTE1(v230) & 7;
            v270[0] = v232;
            *(_DWORD *)((char *)v270 + 7) = (_DWORD)v225;
            if ( (BYTE1(v271) & 7u) >= v233 )
              v234 = v233;
            else
              v234 = BYTE1(v271) & 7;
            v235 = (unsigned int)(v234 + 1);
            do
            {
              v236 = (_BYTE *)(v29 + 912 + v224 - 276);
              if ( *((unsigned __int8 *)&v271 + v224 + 3) >= (unsigned int)*((unsigned __int8 *)&v268 + v224 + 3) )
                v237 = *((unsigned __int8 *)&v268 + v224 + 3);
              else
                v237 = *((unsigned __int8 *)&v271 + v224 + 3);
              if ( (unsigned __int8)*v236 != v237 )
                *v106 = 1;
              *v236 = v237;
              if ( (v260 & 1) != 0 )
              {
                if ( v224 > 5 )
                  goto LABEL_243;
                v106 = a14;
                *v229 = v237;
              }
              if ( (v259 & 1) != 0 )
                *(v229 - 64) = (unsigned __int8)*v236;
              result = qdf_trace_msg(
                         0x35u,
                         8u,
                         "%s: TPE: Local: %d, Reg: %d, power updated: %d",
                         v80,
                         v81,
                         v82,
                         v83,
                         v84,
                         v85,
                         v86,
                         v87,
                         "lim_parse_tpe_ie");
              ++v224;
              v229 += 4;
            }
            while ( v235 != v224 );
          }
        }
        goto LABEL_242;
      }
      v67 = *(unsigned __int8 *)(a2 + 10069);
      v68 = 1;
      wlan_reg_get_client_power_for_connecting_ap(
        *(_QWORD *)(a1 + 21632),
        v66,
        v52,
        1,
        v266,
        &v265,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64);
      if ( v265 )
      {
        v69 = 0;
        v66 = v67;
      }
      else
      {
        v172 = jiffies;
        if ( lim_parse_tpe_ie___last_ticks_36 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: reg rule doesn't support psd for %d ap type %d",
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            "lim_parse_tpe_ie",
            v52,
            v67);
          v66 = v67;
          v69 = v40;
          lim_parse_tpe_ie___last_ticks_36 = v172;
          v68 = 0;
        }
        else
        {
          v68 = 0;
          v69 = v40;
          v66 = v67;
        }
      }
    }
    else
    {
      v66 = 0;
      v69 = 0;
      v68 = v51;
    }
    v65 = (unsigned __int8 *)(a2 + 7174);
    goto LABEL_34;
  }
LABEL_242:
  _ReadStatusReg(SP_EL0);
  return result;
}
