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
  __int64 v17; // x0
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x20
  __int64 v28; // x20
  __int64 v29; // x10
  char v30; // w24
  unsigned int v31; // w4
  unsigned int v32; // w1
  unsigned int v33; // w3
  unsigned int v34; // w2
  __int64 v35; // x22
  int v36; // w6
  int v37; // w27
  int v38; // w5
  char v39; // w28
  unsigned int v40; // w30
  unsigned int v41; // w7
  unsigned int v42; // w25
  unsigned int v43; // w23
  int v44; // w9
  int v45; // w8
  __int64 *v46; // x13
  __int64 v47; // x14
  __int64 v48; // x15
  int v49; // w17
  unsigned int v50; // w15
  int v51; // w23
  _BOOL4 v52; // w9
  bool v53; // zf
  unsigned int v54; // w25
  __int64 v55; // x8
  unsigned int v56; // w26
  unsigned int v57; // w0
  _BOOL4 v58; // w8
  unsigned __int16 bw_value; // w21
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned __int8 *v68; // x12
  unsigned int v69; // w1
  char v70; // w15
  char v71; // w8
  int v72; // w11
  _BOOL4 v73; // w13
  int v74; // w12
  int v75; // w13
  char v76; // w27
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w8
  __int64 *v94; // x8
  __int64 v95; // x10
  char v96; // w21
  __int64 v97; // x9
  __int64 v98; // x8
  unsigned int v99; // w8
  __int64 v100; // x22
  unsigned int v101; // w4
  __int64 v102; // x21
  unsigned __int64 v103; // x25
  __int64 v104; // x22
  unsigned __int64 v105; // x27
  int v106; // w8
  __int16 v107; // w8
  char v108; // w22
  int v109; // w27
  int v110; // w25
  __int64 *v111; // x8
  __int64 v112; // x10
  char v113; // w19
  __int64 v114; // x9
  __int64 v115; // x8
  unsigned __int8 *v116; // x11
  unsigned int v117; // w8
  __int64 v118; // x21
  unsigned int v119; // w9
  unsigned int v120; // w21
  unsigned __int8 v121; // w0
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  int v138; // w8
  int v139; // w8
  __int64 v140; // x3
  __int16 v141; // w9
  __int64 v142; // x1
  __int64 v143; // x5
  __int64 v144; // x11
  int v145; // w10
  __int64 v146; // x8
  __int64 v147; // x9
  __int64 v148; // x14
  __int64 v149; // x12
  __int64 v150; // x13
  __int16 v151; // w9
  __int64 v152; // x19
  unsigned int v153; // w21
  __int16 v154; // w9
  __int16 v155; // w9
  __int16 v156; // w9
  __int16 v157; // w9
  __int16 v158; // w9
  unsigned int v159; // w19
  unsigned int v160; // w21
  int v161; // w10
  __int64 *v162; // x8
  __int64 v163; // x9
  __int64 v164; // x10
  __int64 v165; // x11
  unsigned int v166; // w9
  __int16 v167; // w8
  unsigned int v168; // w10
  __int16 v169; // w9
  __int64 *v170; // x9
  unsigned __int64 v171; // x22
  __int64 *v172; // x8
  __int64 v173; // x10
  __int64 v174; // x11
  __int64 v175; // x12
  _WORD *v176; // x27
  __int64 v177; // x10
  __int64 v178; // x12
  __int64 v179; // x12
  unsigned int v180; // w10
  int v181; // w8
  __int64 v182; // x25
  _BYTE *v183; // x8
  int v184; // w9
  __int16 v185; // w9
  unsigned int v186; // [xsp+68h] [xbp-108h]
  _BOOL4 v187; // [xsp+6Ch] [xbp-104h]
  unsigned int v188; // [xsp+70h] [xbp-100h]
  unsigned int v189; // [xsp+74h] [xbp-FCh]
  unsigned int v190; // [xsp+78h] [xbp-F8h]
  int v191; // [xsp+7Ch] [xbp-F4h]
  unsigned int v192; // [xsp+80h] [xbp-F0h]
  int v193; // [xsp+84h] [xbp-ECh]
  __int64 *v194; // [xsp+88h] [xbp-E8h]
  unsigned int v195; // [xsp+94h] [xbp-DCh]
  unsigned int v196; // [xsp+98h] [xbp-D8h]
  unsigned int v197; // [xsp+9Ch] [xbp-D4h]
  unsigned int v198; // [xsp+9Ch] [xbp-D4h]
  unsigned int v199; // [xsp+A0h] [xbp-D0h]
  unsigned int v200; // [xsp+A4h] [xbp-CCh]
  int v201; // [xsp+A8h] [xbp-C8h]
  int v202; // [xsp+ACh] [xbp-C4h]
  unsigned __int8 *v203; // [xsp+B0h] [xbp-C0h]
  __int64 v204; // [xsp+B8h] [xbp-B8h]
  int v205; // [xsp+C4h] [xbp-ACh]
  unsigned int v206; // [xsp+C8h] [xbp-A8h]
  char v207; // [xsp+C8h] [xbp-A8h]
  __int64 v210; // [xsp+E0h] [xbp-90h] BYREF
  __int64 v211; // [xsp+E8h] [xbp-88h]
  __int16 v212; // [xsp+F4h] [xbp-7Ch] BYREF
  __int16 v213[2]; // [xsp+F8h] [xbp-78h] BYREF
  unsigned int v214; // [xsp+FCh] [xbp-74h] BYREF
  __int64 v215; // [xsp+100h] [xbp-70h]
  __int64 v216; // [xsp+108h] [xbp-68h]
  _QWORD v217[2]; // [xsp+110h] [xbp-60h] BYREF
  __int64 v218; // [xsp+120h] [xbp-50h]
  __int64 v219; // [xsp+128h] [xbp-48h]
  _QWORD v220[2]; // [xsp+130h] [xbp-40h] BYREF
  __int64 v221; // [xsp+140h] [xbp-30h] BYREF
  __int64 v222; // [xsp+148h] [xbp-28h]
  _QWORD v223[4]; // [xsp+150h] [xbp-20h]

  v223[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *(_QWORD *)(a2 + 16);
  v214 = 0;
  v213[0] = 0;
  v212 = 0;
  v210 = 0;
  v211 = 0;
  v219 = 0;
  memset(v220, 0, 11);
  v218 = 0;
  v216 = 0;
  memset(v217, 0, 11);
  v215 = 0;
  result = wlan_vdev_mlme_get_cmpt_obj(v17, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !result )
    goto LABEL_170;
  if ( *(_BYTE *)(a2 + 10070) == 1 )
  {
    v27 = jiffies;
    if ( lim_parse_tpe_ie___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: STA operates in 6 GHz power of SAP, do not update STA power",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "lim_parse_tpe_ie");
      lim_parse_tpe_ie___last_ticks = v27;
    }
    goto LABEL_170;
  }
  v203 = (unsigned __int8 *)(a2 + 7174);
  v28 = result;
  *(_WORD *)(result + 533) = 0;
  *(_BYTE *)(result + 535) = 0;
  *a14 = 0;
  wlan_reg_get_cur_6g_client_type(*(_QWORD *)(a1 + 21560), &v214, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( a4 )
  {
    v29 = 0;
    v30 = 0;
    v31 = 0;
    v32 = 0;
    v33 = 0;
    v34 = 0;
    LODWORD(v35) = 0;
    v36 = 0;
    v37 = 0;
    v38 = 0;
    result = 0;
    v39 = 0;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    v43 = 0;
    v44 = 0;
    v45 = 0;
    v46 = a3;
    v205 = 0;
    do
    {
      v47 = *v46;
      v48 = v46[1];
      v49 = *(_DWORD *)((char *)v46 + 23);
      v223[0] = v46[2];
      v221 = v47;
      v222 = v48;
      *(_DWORD *)((char *)v223 + 7) = v49;
      if ( (_BYTE)v47 && v214 == BYTE1(v221) >> 6 )
      {
        v50 = (BYTE1(v221) >> 3) & 7;
        if ( v50 > 2 )
        {
          switch ( v50 )
          {
            case 3u:
              ++v44;
              result = 1;
              v43 = (unsigned __int8)v29;
              LODWORD(v35) = 1;
              v31 = (unsigned __int8)v29;
              break;
            case 4u:
              ++v44;
              v39 = 1;
              v41 = (unsigned __int8)v29;
              v205 = 1;
              break;
            case 5u:
              ++v44;
              result = 1;
              v40 = (unsigned __int8)v29;
              v30 = 1;
              break;
          }
        }
        else if ( v50 )
        {
          if ( v50 == 1 )
          {
            ++v45;
            result = 1;
            v43 = (unsigned __int8)v29;
            v37 = 1;
            v33 = (unsigned __int8)v29;
          }
          else
          {
            ++v44;
            v39 = 1;
            v42 = (unsigned __int8)v29;
            v36 = 1;
            v32 = (unsigned __int8)v29;
          }
        }
        else
        {
          ++v45;
          v39 = 1;
          v42 = (unsigned __int8)v29;
          v38 = 1;
          v34 = (unsigned __int8)v29;
        }
      }
      ++v29;
      v46 = (__int64 *)((char *)v46 + 27);
    }
    while ( a4 != v29 );
  }
  else
  {
    LOBYTE(v45) = 0;
    LOBYTE(v44) = 0;
    v43 = 0;
    v42 = 0;
    v41 = 0;
    v40 = 0;
    v39 = 0;
    result = 0;
    v38 = 0;
    v37 = 0;
    v36 = 0;
    LODWORD(v35) = 0;
    v34 = 0;
    v33 = 0;
    v32 = 0;
    v31 = 0;
    v205 = 0;
    v30 = 0;
  }
  v200 = v43;
  v192 = v31;
  if ( (unsigned __int8)v44 | (unsigned __int8)v45 )
  {
    v195 = v42;
    v196 = v40;
    v51 = result;
    v206 = (unsigned __int8)v44;
    v52 = (unsigned __int8)v44 != 0;
    v54 = (unsigned __int8)v45;
    v53 = (unsigned __int8)v45 == 0;
    v55 = a2;
    v56 = *(_DWORD *)(a2 + 284);
    v199 = v41;
    v57 = *(_DWORD *)(v55 + 7176);
    v204 = v55;
    v58 = !v53 && v52;
    v201 = v38;
    v202 = v36;
    v188 = v33;
    v189 = v34;
    v190 = v32;
    v187 = v58;
    bw_value = wlan_reg_get_bw_value(v57);
    v194 = a3;
    v193 = v35;
    if ( wlan_reg_is_6ghz_chan_freq(v56) )
    {
      v68 = v203;
      v69 = v203[2895];
      if ( (v51 & 1) == 0 )
      {
        v70 = v202;
        v51 = 0;
        v71 = 0;
        goto LABEL_37;
      }
      v197 = v203[2895];
      v51 = 1;
      wlan_reg_get_client_power_for_connecting_ap(
        *(_QWORD *)(a1 + 21560),
        v69,
        v56,
        1,
        v213,
        &v212,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67);
      if ( v212 )
      {
        v70 = v202;
        v71 = 0;
LABEL_36:
        v68 = v203;
        v69 = v197;
LABEL_37:
        v72 = *v68;
        if ( v199 )
          v73 = v69 == 1;
        else
          v73 = 1;
        v74 = v68[10];
        v53 = !v73;
        v191 = v37;
        v75 = v37 & 1;
        if ( v53 )
          v76 = v71;
        else
          v76 = v39;
        v198 = v69;
        v186 = bw_value;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: psd_set: %d, non_psd_set: %d, reg_count: %d, local_count: %d, conn_pwr_type_sp: %d, freq: %d, seg0: %d, se"
          "g1: %d, bw_val: %d, puncture_bit_map: %d, Local: eirp: %d psd: %d, Regulatory: eirp: %d psd %d, Addn Regulator"
          "y PSD %d eirp %d",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "lim_parse_tpe_ie",
          v51 & 1,
          v76 & 1,
          v206,
          v54,
          v69 == 1,
          *(_DWORD *)(v204 + 284),
          v72,
          v74,
          bw_value,
          0,
          v201 & 1,
          v75,
          v70 & 1,
          v35 & 1,
          v30 & 1,
          v205 & 1);
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: psd_index: %u non_psd_index %u addn_non_psd_index %u addn_psd_index %u",
                   v77,
                   v78,
                   v79,
                   v80,
                   v81,
                   v82,
                   v83,
                   v84,
                   "lim_parse_tpe_ie",
                   v200,
                   v195,
                   v199,
                   v196);
        v207 = v76;
        if ( (v76 & 1) != 0 && ((v51 ^ 1 | v205) & 1) != 0 )
        {
          v93 = v199;
          if ( ((v198 == 1) & (unsigned __int8)v205) != 0 || (v93 = v195, ((v201 | v202) & 1) != 0) )
          {
            v94 = (__int64 *)((char *)a3 + 27 * v93);
            v95 = v94[1];
            v96 = BYTE1(*v94);
            v221 = *v94;
            v222 = v95;
            v97 = v94[2];
            LODWORD(v94) = *(_DWORD *)((char *)v94 + 23);
            v223[0] = v97;
            *(_DWORD *)((char *)v223 + 7) = (_DWORD)v94;
            if ( (v96 & 7u) >= 4 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Invalid max tx pwr count: %d",
                v85,
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                "lim_parse_tpe_ie");
              v96 = v96 & 0xF8 | 3;
              BYTE1(v221) = v96;
            }
            v98 = *(unsigned int *)(v204 + 7176);
            if ( (unsigned int)v98 < 8 && ((0x8Fu >> v98) & 1) != 0 )
            {
              v99 = dword_A300B0[v98];
              if ( v99 >= (v96 & 7u) )
                LOBYTE(v99) = v96 & 7;
              v96 = v96 & 0xF8 | v99;
              BYTE1(v221) = v96;
            }
            else
            {
              v100 = jiffies;
              if ( lim_get_num_pwr_levels___last_ticks_43 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x35u,
                  2u,
                  "%s: Invalid channel width",
                  v85,
                  v86,
                  v87,
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  "lim_get_num_pwr_levels");
                lim_get_num_pwr_levels___last_ticks_43 = v100;
              }
            }
            v101 = v96 & 7;
            *(_BYTE *)(v28 + 528) = 0;
            *(_WORD *)(v28 + 530) = 0;
            if ( v101 >= 4 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: tx pwr count: %d, larger than bw num: %d",
                v85,
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                "lim_parse_tpe_ie");
              v101 = 3;
              BYTE1(v221) = v96 & 0xF8 | 3;
            }
            v102 = 0;
            v103 = 0;
            v104 = v28 + 556;
            v105 = v101;
            *(_BYTE *)(v28 + 533) = v101 + 1;
            *(_BYTE *)(v28 + 535) = v101 + 1;
            LODWORD(v210) = 0;
            while ( 1 )
            {
              result = wlan_reg_set_channel_params_for_pwrmode(
                         *(_QWORD *)(a1 + 21560),
                         v56,
                         0,
                         (__int64)&v210,
                         0,
                         v85,
                         v86,
                         v87,
                         v88,
                         v89,
                         v90,
                         v91,
                         v92);
              if ( (v30 & 1) == 0 )
              {
                if ( v103 - 24 < 0xFFFFFFFFFFFFFFE5LL )
                  goto LABEL_177;
                if ( *(unsigned __int8 *)(v28 + v103 + 620) != *((unsigned __int8 *)&v221 + v103 + 3)
                  || *(_DWORD *)(v104 + 4 * v103) != (_DWORD)v211 )
                {
                  *a14 = 1;
                }
              }
              v106 = v211;
              *(_DWORD *)(v104 + 4 * v103) = v211;
              if ( v103 == 6 )
                break;
              *(_DWORD *)(v28 + v102 + 892) = v106;
              if ( v103 - 24 < 0xFFFFFFFFFFFFFFE5LL )
                goto LABEL_177;
              v107 = *((unsigned __int8 *)&v221 + v103 + 3);
              *(_BYTE *)(v28 + v103 + 620) = v107;
              *(_WORD *)(v28 + v102 + 896) = v107;
              if ( (_DWORD)v210 == 8 )
              {
                if ( v103 >= v105 )
                  goto LABEL_71;
              }
              else
              {
                if ( (unsigned int)v210 > 3 )
                  break;
                LODWORD(v210) = get_next_higher_bw[(unsigned int)v210];
                if ( v103 >= v105 )
                  goto LABEL_71;
              }
              ++v103;
              v102 += 8;
            }
LABEL_176:
            __break(0x5512u);
LABEL_177:
            __break(1u);
          }
        }
LABEL_71:
        v108 = v51;
        v109 = v191;
        v110 = v201;
        if ( (v51 & 1) == 0 )
          goto LABEL_139;
        if ( ((v198 == 1) & (unsigned __int8)v30) == 0 )
        {
          v196 = v200;
          if ( ((v191 | v193) & 1) == 0 )
            goto LABEL_139;
        }
        v111 = (__int64 *)((char *)a3 + 27 * v196);
        v112 = v111[1];
        v113 = BYTE1(*v111);
        v221 = *v111;
        v222 = v112;
        v114 = v111[2];
        LODWORD(v111) = *(_DWORD *)((char *)v111 + 23);
        v223[0] = v114;
        *(_DWORD *)((char *)v223 + 7) = (_DWORD)v111;
        if ( (v113 & 7u) >= 5 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Invalid max tx pwr count psd: %d",
            v85,
            v86,
            v87,
            v88,
            v89,
            v90,
            v91,
            v92,
            "lim_parse_tpe_ie");
          v113 = v113 & 0xF8 | 4;
          BYTE1(v221) = v113;
        }
        v115 = *(unsigned int *)(v204 + 7176);
        if ( (unsigned int)v115 < 8 && ((0x8Fu >> v115) & 1) != 0 )
        {
          v116 = v203;
          v117 = dword_A30050[v115];
        }
        else
        {
          v118 = jiffies;
          v116 = v203;
          if ( lim_get_num_pwr_levels___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Invalid channel width",
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              "lim_get_num_pwr_levels");
            v116 = v203;
            v117 = 0;
            lim_get_num_pwr_levels___last_ticks = v118;
          }
          else
          {
            v117 = 0;
          }
        }
        *(_BYTE *)(v28 + 528) = 1;
        v119 = (unsigned __int8)(1 << ((v113 & 7) - 1));
        if ( (v113 & 7) == 0 )
          v119 = 0;
        if ( v117 >= v119 )
          v120 = v119;
        else
          v120 = v117;
        *(_BYTE *)(v28 + 533) = v120;
        *(_BYTE *)(v28 + 534) = v120;
        v121 = v116[10];
        LODWORD(v210) = *(_DWORD *)(v204 + 7176);
        HIDWORD(v211) = wlan_reg_compute_6g_center_freq_from_cfi(v121);
        wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(a1 + 21560),
          v56,
          0,
          (__int64)&v210,
          0,
          v122,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          v129);
        v138 = HIDWORD(v211);
        if ( !HIDWORD(v211) )
          v138 = v211;
        v139 = v138 - (v186 >> 1);
        v140 = (unsigned int)(v139 + 10);
        if ( v120 )
        {
          v141 = BYTE3(v221);
          if ( *(unsigned __int8 *)(v28 + 620) != BYTE3(v221) || *(_DWORD *)(v28 + 556) != (_DWORD)v140 )
            *a14 = 1;
          v142 = v204;
          v110 = v201;
          *(_DWORD *)(v28 + 764) = v140;
          *(_DWORD *)(v28 + 556) = v140;
          v140 = (unsigned int)(v139 + 30);
          *(_BYTE *)(v28 + 620) = v141;
          *(_WORD *)(v28 + 768) = v141;
          if ( v120 == 1 )
          {
            v143 = 1;
LABEL_138:
            result = lim_update_ext_tpe_power(a1, v142, &v221, v140, a14, v143, 1);
            *(_BYTE *)(v28 + 533) = result;
            *(_BYTE *)(v28 + 534) = result;
LABEL_139:
            v160 = v189;
            v159 = v190;
            v161 = v202;
            if ( (v207 & 1) != 0 )
            {
              if ( ((v198 == 1) & (unsigned __int8)v205) != 0 || (v199 = v195, ((v110 | v202) & 1) != 0) )
              {
                v162 = (__int64 *)((char *)v194 + 27 * v199);
                v163 = *v162;
                v164 = v162[1];
                v165 = v162[2];
                LODWORD(v162) = *(_DWORD *)((char *)v162 + 23);
                v223[0] = v165;
                v221 = v163;
                v222 = v164;
                v166 = BYTE1(v163);
                *(_DWORD *)((char *)v223 + 7) = (_DWORD)v162;
                v167 = *((unsigned __int8 *)&off_0 + ((unsigned __int64)&v221 | v166 & 7) + 3);
                *(_WORD *)(v28 + 530) = v167;
                if ( *(_DWORD *)(v204 + 7176) == 7 )
                {
                  if ( (v166 & 7) > 2 )
                  {
                    if ( BYTE2(v221) >= 5u )
                    {
                      v168 = (v166 >> 3) & 7;
                      v169 = 0;
                      if ( v168 > 4 || ((1 << v168) & 0x15) == 0 || (v169 = BYTE3(v222), BYTE3(v222) != 100) )
                      {
                        v167 = v169;
                        *(_WORD *)(v28 + 530) = v169;
                      }
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: tx power count advertised by ap %d less than %d",
                      v85,
                      v86,
                      v87,
                      v88,
                      v89,
                      v90,
                      v91,
                      v92,
                      "lim_get_eirp_320_power_from_tpe_ie");
                    v167 = *(_WORD *)(v28 + 530);
                  }
                }
                result = qdf_trace_msg(
                           0x35u,
                           8u,
                           "%s: eirp_power %d",
                           v85,
                           v86,
                           v87,
                           v88,
                           v89,
                           v90,
                           v91,
                           v92,
                           "lim_parse_tpe_ie",
                           (unsigned int)v167);
                v161 = v202;
                if ( (v108 & 1) == 0 )
                  *(_BYTE *)(v28 + 528) = 0;
              }
            }
            if ( v187 )
            {
              if ( (v110 & v161 & 1) != 0 || (v159 = v192, v160 = v188, (v109 & v193 & 1) != 0) )
              {
                v170 = (__int64 *)((char *)v194 + 27 * v160);
                v171 = 0;
                v172 = (__int64 *)((char *)v194 + 27 * v159);
                v173 = *v170;
                v174 = v170[1];
                v175 = v170[2];
                LODWORD(v170) = *(_DWORD *)((char *)v170 + 23);
                v176 = (_WORD *)(v28 + 896);
                v220[0] = v175;
                v218 = v173;
                v219 = v174;
                v177 = *v172;
                v178 = v172[1];
                *(_DWORD *)((char *)v220 + 7) = (_DWORD)v170;
                v215 = v177;
                v216 = v178;
                v179 = v172[2];
                LODWORD(v172) = *(_DWORD *)((char *)v172 + 23);
                v180 = BYTE1(v177) & 7;
                v217[0] = v179;
                *(_DWORD *)((char *)v217 + 7) = (_DWORD)v172;
                if ( (BYTE1(v218) & 7u) >= v180 )
                  v181 = v180;
                else
                  v181 = BYTE1(v218) & 7;
                v182 = (unsigned int)(v181 + 1);
                do
                {
                  v183 = (_BYTE *)(v28 + 896 + v171 - 276);
                  if ( *((unsigned __int8 *)&v218 + v171 + 3) >= (unsigned int)*((unsigned __int8 *)&v215 + v171 + 3) )
                    v184 = *((unsigned __int8 *)&v215 + v171 + 3);
                  else
                    v184 = *((unsigned __int8 *)&v218 + v171 + 3);
                  if ( (unsigned __int8)*v183 != v184 )
                    *a14 = 1;
                  *v183 = v184;
                  if ( (v207 & 1) != 0 )
                  {
                    if ( v171 > 5 )
                      goto LABEL_176;
                    *v176 = v184;
                  }
                  if ( (v51 & 1) != 0 )
                    *(v176 - 64) = (unsigned __int8)*v183;
                  result = qdf_trace_msg(
                             0x35u,
                             8u,
                             "%s: TPE: Local: %d, Reg: %d, power updated: %d",
                             v85,
                             v86,
                             v87,
                             v88,
                             v89,
                             v90,
                             v91,
                             v92,
                             "lim_parse_tpe_ie");
                  ++v171;
                  v176 += 4;
                }
                while ( v182 != v171 );
              }
            }
            goto LABEL_170;
          }
          v151 = BYTE4(v221);
          if ( *(unsigned __int8 *)(v28 + 621) != BYTE4(v221) || *(_DWORD *)(v28 + 560) != (_DWORD)v140 )
            *a14 = 1;
          *(_DWORD *)(v28 + 772) = v140;
          *(_DWORD *)(v28 + 560) = v140;
          v140 = (unsigned int)(v139 + 50);
          *(_BYTE *)(v28 + 621) = v151;
          *(_WORD *)(v28 + 776) = v151;
          if ( v120 == 2 )
          {
            v143 = 2;
            goto LABEL_138;
          }
          v154 = BYTE5(v221);
          if ( *(unsigned __int8 *)(v28 + 622) != BYTE5(v221) || *(_DWORD *)(v28 + 564) != (_DWORD)v140 )
            *a14 = 1;
          *(_DWORD *)(v28 + 780) = v140;
          *(_DWORD *)(v28 + 564) = v140;
          v140 = (unsigned int)(v139 + 70);
          *(_BYTE *)(v28 + 622) = v154;
          *(_WORD *)(v28 + 784) = v154;
          if ( v120 == 3 )
          {
            v143 = 3;
            goto LABEL_138;
          }
          v155 = BYTE6(v221);
          if ( *(unsigned __int8 *)(v28 + 623) != BYTE6(v221) || *(_DWORD *)(v28 + 568) != (_DWORD)v140 )
            *a14 = 1;
          *(_DWORD *)(v28 + 788) = v140;
          *(_DWORD *)(v28 + 568) = v140;
          v140 = (unsigned int)(v139 + 90);
          *(_BYTE *)(v28 + 623) = v155;
          *(_WORD *)(v28 + 792) = v155;
          if ( v120 == 4 )
          {
            v143 = 4;
            goto LABEL_138;
          }
          v156 = HIBYTE(v221);
          if ( *(unsigned __int8 *)(v28 + 624) != HIBYTE(v221) || *(_DWORD *)(v28 + 572) != (_DWORD)v140 )
            *a14 = 1;
          *(_DWORD *)(v28 + 796) = v140;
          *(_DWORD *)(v28 + 572) = v140;
          v140 = (unsigned int)(v139 + 110);
          *(_BYTE *)(v28 + 624) = v156;
          *(_WORD *)(v28 + 800) = v156;
          if ( v120 == 5 )
          {
            v143 = 5;
            goto LABEL_138;
          }
          v157 = (unsigned __int8)v222;
          if ( *(unsigned __int8 *)(v28 + 625) != (unsigned __int8)v222 || *(_DWORD *)(v28 + 576) != (_DWORD)v140 )
            *a14 = 1;
          *(_DWORD *)(v28 + 804) = v140;
          *(_DWORD *)(v28 + 576) = v140;
          v140 = (unsigned int)(v139 + 130);
          *(_BYTE *)(v28 + 625) = v157;
          *(_WORD *)(v28 + 808) = v157;
          if ( v120 == 6 )
          {
            v143 = 6;
            goto LABEL_138;
          }
          v158 = BYTE1(v222);
          if ( *(unsigned __int8 *)(v28 + 626) != BYTE1(v222) || *(_DWORD *)(v28 + 580) != (_DWORD)v140 )
            *a14 = 1;
          *(_DWORD *)(v28 + 812) = v140;
          *(_DWORD *)(v28 + 580) = v140;
          v140 = (unsigned int)(v139 + 150);
          *(_BYTE *)(v28 + 626) = v158;
          *(_WORD *)(v28 + 816) = v158;
          if ( v120 == 7 )
          {
            v143 = 7;
            goto LABEL_138;
          }
          v185 = BYTE2(v222);
          if ( *(unsigned __int8 *)(v28 + 627) != BYTE2(v222) || *(_DWORD *)(v28 + 584) != (_DWORD)v140 )
            *a14 = 1;
          *(_DWORD *)(v28 + 820) = v140;
          *(_DWORD *)(v28 + 584) = v140;
          *(_BYTE *)(v28 + 627) = v185;
          *(_WORD *)(v28 + 824) = v185;
          if ( v120 != 8 )
            goto LABEL_176;
          v108 = v51;
          v109 = v191;
          v140 = (unsigned int)(v139 + 170);
          v142 = v204;
          v143 = 8;
        }
        else
        {
          v144 = *(unsigned int *)(v204 + 7176);
          v142 = v204;
          if ( (unsigned int)v144 < 8 && ((0x8Fu >> v144) & 1) != 0 )
          {
            v145 = BYTE3(v221);
            v143 = dword_A30050[v144];
            v110 = v201;
            v146 = 0;
            v147 = 0;
            *(_BYTE *)(v28 + 533) = v143;
            *(_BYTE *)(v28 + 534) = v143;
            do
            {
              v149 = v28 + v147;
              v150 = v28 + 4 * v147;
              if ( *(unsigned __int8 *)(v28 + v147 + 620) != v145 || (_DWORD)v140 != *(_DWORD *)(v150 + 556) )
                *a14 = 1;
              v148 = v28 + v146;
              ++v147;
              *(_DWORD *)(v150 + 556) = v140;
              *(_DWORD *)(v148 + 764) = v140;
              v140 = (unsigned int)(v140 + 20);
              v146 += 8;
              *(_BYTE *)(v149 + 620) = v145;
              *(_WORD *)(v148 + 768) = v145;
            }
            while ( v143 != v147 );
            goto LABEL_138;
          }
          v152 = jiffies;
          if ( lim_get_num_pwr_levels___last_ticks - jiffies + 125 < 0 )
          {
            v153 = v139 + 10;
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Invalid channel width",
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              v137,
              "lim_get_num_pwr_levels");
            v142 = v204;
            v140 = v153;
            lim_get_num_pwr_levels___last_ticks = v152;
          }
          v143 = 0;
          *(_WORD *)(v28 + 533) = 0;
        }
        v110 = v201;
        goto LABEL_138;
      }
      v35 = jiffies;
      v70 = v202;
      if ( lim_parse_tpe_ie___last_ticks_27 - jiffies + 125 >= 0 )
      {
        LOBYTE(v35) = v193;
        v51 = 0;
        v71 = v39;
        goto LABEL_36;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: reg rule doesn't support psd for %d ap type %d",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "lim_parse_tpe_ie",
        v56,
        v197);
      v70 = v202;
      lim_parse_tpe_ie___last_ticks_27 = v35;
      v69 = v197;
      LOBYTE(v35) = v193;
      v51 = 0;
      v71 = v39;
    }
    else
    {
      v70 = v202;
      v69 = 0;
      v71 = 0;
    }
    v68 = v203;
    goto LABEL_37;
  }
LABEL_170:
  _ReadStatusReg(SP_EL0);
  return result;
}
