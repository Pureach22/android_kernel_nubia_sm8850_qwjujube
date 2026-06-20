__int64 __fastcall wlan_dp_fb_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5, __int64 a6)
{
  __int64 v11; // x25
  int v12; // w27
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w24
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w9
  __int64 v32; // x8
  unsigned int v33; // w19
  __int64 v34; // x0
  _QWORD *v36; // x12
  unsigned int v37; // w13
  __int64 v38; // x14
  unsigned int v39; // w15
  unsigned int v40; // w16
  __int64 v41; // x24
  char v42; // w28
  const char *v43; // x11
  __int64 v44; // x12
  __int64 *v45; // x25
  unsigned __int64 v46; // x8
  const char *v47; // x28
  bool v48; // zf
  unsigned __int8 v49; // w8
  unsigned __int64 v50; // x21
  __int64 v51; // x19
  __int64 v52; // x8
  int v53; // w9
  unsigned int v54; // w12
  _BOOL4 v55; // w2
  signed int v56; // w1
  __int64 v57; // x0
  unsigned __int64 v58; // x5
  unsigned __int64 v59; // x6
  unsigned __int64 v60; // x4
  int v61; // w0
  unsigned __int64 v62; // x2
  int v63; // w3
  int v64; // w2
  int v65; // w4
  __int64 v66; // x2
  unsigned __int64 v67; // x2
  bool v68; // cc
  int v69; // w3
  int v70; // w5
  int v71; // w2
  int v72; // w3
  int v73; // w4
  int v74; // w5
  __int64 v75; // x1
  const char *v76; // x4
  const char *v77; // x5
  int v78; // w9
  __int64 v79; // x8
  bool v80; // cf
  int v81; // w10
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x27
  int v91; // w26
  _QWORD *v92; // x19
  unsigned int v93; // w8
  int v94; // w9
  unsigned int v95; // w11
  char v96; // w28
  __int64 v97; // x24
  __int64 v98; // x0
  char v99; // w8
  unsigned int v100; // w8
  __int64 v101; // x9
  __int64 v102; // x19
  int v103; // w28
  _QWORD *v104; // x24
  __int64 v105; // x0
  __int64 v106; // x8
  __int64 (*v107)(void); // x8
  unsigned __int64 v108; // x12
  unsigned int v109; // w19
  int v110; // w8
  char v111; // w9
  unsigned int v112; // w10
  unsigned __int64 v113; // x8
  unsigned int v114; // w11
  __int64 v115; // x0
  unsigned __int64 v116; // x10
  unsigned __int64 v117; // x9
  unsigned __int64 v118; // x10
  __int64 v119; // x11
  int v120; // w9
  __int64 v121; // x9
  char v122; // w10
  __int64 v123; // x9
  unsigned __int64 v124; // x12
  char v125; // w9
  char v126; // w9
  char v127; // w9
  char v128; // w9
  char v129; // w9
  char v130; // w9
  char v131; // w9
  char v132; // w9
  unsigned __int64 v133; // [xsp+8h] [xbp-168h]
  __int64 v134; // [xsp+18h] [xbp-158h]
  __int64 v135; // [xsp+20h] [xbp-150h]
  __int64 v136; // [xsp+28h] [xbp-148h] BYREF
  __int64 v137; // [xsp+30h] [xbp-140h] BYREF
  __int64 v138; // [xsp+38h] [xbp-138h]
  __int64 v139; // [xsp+40h] [xbp-130h]
  __int64 v140; // [xsp+48h] [xbp-128h]
  _QWORD v141[2]; // [xsp+50h] [xbp-120h] BYREF
  __int64 v142; // [xsp+60h] [xbp-110h]
  __int64 v143; // [xsp+68h] [xbp-108h]
  __int64 v144; // [xsp+70h] [xbp-100h]
  __int64 v145; // [xsp+78h] [xbp-F8h]
  __int64 v146; // [xsp+80h] [xbp-F0h]
  __int64 v147; // [xsp+88h] [xbp-E8h]
  __int64 v148; // [xsp+90h] [xbp-E0h]
  __int64 v149; // [xsp+98h] [xbp-D8h]
  __int64 v150; // [xsp+A0h] [xbp-D0h]
  __int64 v151; // [xsp+A8h] [xbp-C8h]
  __int64 v152; // [xsp+B0h] [xbp-C0h]
  __int64 v153; // [xsp+B8h] [xbp-B8h]
  __int64 v154; // [xsp+C0h] [xbp-B0h]
  __int64 v155; // [xsp+C8h] [xbp-A8h]
  __int64 v156; // [xsp+D0h] [xbp-A0h]
  __int64 v157; // [xsp+D8h] [xbp-98h]
  __int64 v158; // [xsp+E0h] [xbp-90h]
  __int64 v159; // [xsp+E8h] [xbp-88h]
  __int64 v160; // [xsp+F0h] [xbp-80h]
  __int64 v161; // [xsp+F8h] [xbp-78h]
  __int64 v162; // [xsp+100h] [xbp-70h]
  __int64 v163; // [xsp+108h] [xbp-68h]
  __int64 v164; // [xsp+110h] [xbp-60h]
  _QWORD v165[11]; // [xsp+118h] [xbp-58h] BYREF

  v165[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 1480);
  v162 = 0;
  v163 = 0;
  v12 = *(unsigned __int8 *)(a1 + 2912);
  v160 = 0;
  v161 = 0;
  v158 = 0;
  v159 = 0;
  v156 = 0;
  v157 = 0;
  v154 = 0;
  v155 = 0;
  v152 = 0;
  v153 = 0;
  v150 = 0;
  v151 = 0;
  v148 = 0;
  v149 = 0;
  v146 = 0;
  v147 = 0;
  v144 = 0;
  v145 = 0;
  v13 = *(unsigned __int16 *)(v11 + 32);
  v142 = 0;
  v143 = 0;
  v141[1] = 0;
  v139 = 0;
  v140 = 0;
  v137 = 0;
  v138 = 0;
  v136 = 0;
  v141[0] = _qdf_mem_malloc(8 * v13, "wlan_dp_fb_handler", 490);
  if ( !v141[0] )
  {
    v22 = 0;
LABEL_12:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: failed to allocate flow list for ring %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_dp_fb_handler",
      v22);
    goto LABEL_13;
  }
  v22 = 1;
  BYTE1(v145) = 1;
  v143 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v11 + 32), "wlan_dp_fb_handler", 490);
  if ( !v143 )
    goto LABEL_12;
  v22 = 2;
  BYTE1(v148) = 2;
  v146 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v11 + 32), "wlan_dp_fb_handler", 490);
  if ( !v146 )
    goto LABEL_12;
  v22 = 3;
  BYTE1(v151) = 3;
  v149 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v11 + 32), "wlan_dp_fb_handler", 490);
  if ( !v149 )
    goto LABEL_12;
  v22 = 4;
  BYTE1(v154) = 4;
  v152 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v11 + 32), "wlan_dp_fb_handler", 490);
  if ( !v152 )
    goto LABEL_12;
  v22 = 5;
  BYTE1(v157) = 5;
  v155 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v11 + 32), "wlan_dp_fb_handler", 490);
  if ( !v155 )
    goto LABEL_12;
  v22 = 6;
  BYTE1(v160) = 6;
  v158 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v11 + 32), "wlan_dp_fb_handler", 490);
  if ( !v158 )
    goto LABEL_12;
  v22 = 7;
  BYTE1(v163) = 7;
  v161 = _qdf_mem_malloc(8LL * *(unsigned __int16 *)(v11 + 32), "wlan_dp_fb_handler", 490);
  if ( !v161 )
    goto LABEL_12;
  dp_fisa_flow_balance_build_flow_map_tbl(a1, (__int64)v141, (_DWORD *)&v136 + 1, &v136);
  if ( (unsigned int)v136 < 2 )
    goto LABEL_13;
  v31 = HIDWORD(v136);
  v32 = 0;
  v135 = a6;
  do
  {
    v36 = &v141[3 * v32];
    if ( *((_DWORD *)v36 + 3) && *((_DWORD *)v36 + 2) )
    {
      v37 = 0;
      do
      {
        v38 = *v36 + 8LL * (int)v37++;
        v39 = 100 * *(_DWORD *)v38 / v31;
        *(_BYTE *)(v38 + 6) = v39;
        v40 = *((_DWORD *)v36 + 2);
        *((_BYTE *)v36 + 16) += v39;
      }
      while ( v37 < v40 );
    }
    ++v32;
  }
  while ( v32 != 8 );
  v41 = 0;
  v42 = 0;
  v43 = "%s: ring%d is overloaded wtg %u";
  v44 = -184;
  LODWORD(v45) = 1374389535;
  while ( 2 )
  {
    v46 = v44 + 24 * v41;
    while ( 1 )
    {
      if ( v46 < 0xFFFFFFFFFFFFFF40LL )
        goto LABEL_206;
      if ( *(_DWORD *)((char *)&v165[-1] + v46) )
      {
        if ( v46 + 3 < 0xFFFFFFFFFFFFFF3FLL )
          goto LABEL_206;
        if ( *(_DWORD *)((char *)&v164 + v46 + 4) < 90 * *(_DWORD *)(a2 + 4 * v41) / 0x64u )
        {
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: flow thrash detected on ring %d FAP %u RAP %u",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "wlan_dp_fb_handler",
            (unsigned int)v41);
          v76 = "true";
          if ( (v42 & 1) != 0 )
            v77 = "true";
          else
            v77 = "false";
LABEL_120:
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: fb is not eligible FT %s RO %s",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "wlan_dp_fb_handler",
            v76,
            v77);
LABEL_13:
          v33 = 1;
          v34 = v141[0];
          if ( !v141[0] )
            goto LABEL_15;
          goto LABEL_14;
        }
      }
      if ( v46 + 8 < 0xFFFFFFFFFFFFFF40LL )
        goto LABEL_206;
      if ( *((unsigned __int8 *)v165 + v46) > 0x46u )
        break;
      ++v41;
      v46 += 24LL;
      if ( v41 == 8 )
      {
        if ( (v42 & 1) != 0 )
          goto LABEL_50;
        v77 = "false";
        v76 = "false";
        goto LABEL_120;
      }
    }
    v47 = v43;
    v134 = v44;
    qdf_trace_msg(0x45u, 5u, v43, v23, v24, v25, v26, v27, v28, v29, v30, "wlan_dp_fb_handler", (unsigned int)v41);
    v44 = v134;
    v43 = v47;
    v48 = v41++ == 7;
    v42 = 1;
    if ( !v48 )
      continue;
    break;
  }
LABEL_50:
  if ( v12 >= (int)v136 )
    v49 = v136;
  else
    v49 = v12;
  v50 = v49;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: fb: num_rings %u num_flows %u",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wlan_dp_fb_handler",
    v49);
  v51 = a6;
  if ( (int)a5 < 1 )
  {
LABEL_91:
    v78 = (unsigned __int8)v142;
    v79 = *(_QWORD *)(a1 + 1480);
    v164 = 0;
    memset(v165, 0, 72);
    if ( (_BYTE)v142 )
    {
      if ( (int)v137 - 5 > (unsigned int)(unsigned __int8)v142 || (int)v137 + 5 < (unsigned int)(unsigned __int8)v142 )
        goto LABEL_132;
      v78 = (unsigned __int8)v145;
      if ( (_BYTE)v145 )
      {
        if ( HIDWORD(v137) - 5 > (unsigned int)(unsigned __int8)v145
          || HIDWORD(v137) + 5 < (unsigned int)(unsigned __int8)v145 )
        {
          goto LABEL_132;
        }
        v78 = (unsigned __int8)v148;
        if ( (_BYTE)v148 )
        {
          if ( (int)v138 - 5 > (unsigned int)(unsigned __int8)v148
            || (int)v138 + 5 < (unsigned int)(unsigned __int8)v148 )
          {
            goto LABEL_132;
          }
          v78 = (unsigned __int8)v151;
          if ( (_BYTE)v151 )
          {
            if ( HIDWORD(v138) - 5 > (unsigned int)(unsigned __int8)v151
              || HIDWORD(v138) + 5 < (unsigned int)(unsigned __int8)v151 )
            {
              goto LABEL_132;
            }
            v78 = (unsigned __int8)v154;
            if ( (_BYTE)v154 )
            {
              v51 = a6;
              if ( (int)v139 - 5 > (unsigned int)(unsigned __int8)v154
                || (int)v139 + 5 < (unsigned int)(unsigned __int8)v154 )
              {
                goto LABEL_132;
              }
              v78 = (unsigned __int8)v157;
              if ( (_BYTE)v157 )
              {
                v51 = a6;
                if ( HIDWORD(v139) - 5 > (unsigned int)(unsigned __int8)v157
                  || HIDWORD(v139) + 5 < (unsigned int)(unsigned __int8)v157 )
                {
                  goto LABEL_132;
                }
                v78 = (unsigned __int8)v160;
                if ( (_BYTE)v160 )
                {
                  v51 = a6;
                  if ( (int)v140 - 5 <= (unsigned int)(unsigned __int8)v160
                    && (int)v140 + 5 >= (unsigned int)(unsigned __int8)v160 )
                  {
                    v78 = (unsigned __int8)v163;
                    if ( (_BYTE)v163 )
                    {
                      v80 = HIDWORD(v140) - 5 <= (unsigned int)(unsigned __int8)v163
                         && HIDWORD(v140) + 5 >= (unsigned int)(unsigned __int8)v163;
                      v81 = 8;
                      v78 = !v80;
                    }
                    else
                    {
                      v81 = 7;
                    }
                    goto LABEL_129;
                  }
LABEL_132:
                  v134 = _qdf_mem_malloc(4LL * *(unsigned __int16 *)(v79 + 32), "wlan_dp_fb_do_flow_balance", 265);
                  if ( v134 )
                  {
                    qdf_sort();
                    v45 = &v137;
                    qdf_sort();
                    v90 = 0;
                    v91 = 0;
                    do
                    {
                      v92 = &v141[3 * v90];
                      v93 = *((unsigned __int8 *)v92 + 16);
                      if ( *((_DWORD *)&v137 + v90) + 5 < v93 )
                      {
                        v94 = *((_DWORD *)v92 + 2);
                        do
                        {
                          v96 = *((_BYTE *)v92 + 17);
                          v97 = *v92 + 8LL * (unsigned int)(v94 - 1);
                          *((_BYTE *)v92 + 16) = v93 - *(_BYTE *)(v97 + 6);
                          v98 = _qdf_mem_malloc(0x10u, "wlan_dp_fb_add_flow_to_fwt", 132);
                          if ( v98 )
                          {
                            *(_WORD *)v98 = *(_WORD *)(v97 + 4);
                            v99 = *(_BYTE *)(v97 + 6);
                            *(_BYTE *)(v98 + 3) = v96;
                            *(_BYTE *)(v98 + 2) = v99;
                            if ( (unsigned int)*(unsigned __int8 *)(v97 + 6) - 100 >= 0xA )
                              v100 = *(unsigned __int8 *)(v97 + 6) / 0xAu;
                            else
                              v100 = 9;
                            if ( v100 > 9 )
                              goto LABEL_206;
                            v101 = v165[v100 - 1];
                            if ( v101 )
                              *(_QWORD *)(v98 + 8) = v101;
                            v165[v100 - 1] = v98;
                          }
                          else
                          {
                            qdf_trace_msg(
                              0x45u,
                              2u,
                              "%s: failed to allocate memory for flow wtg elem",
                              v23,
                              v24,
                              v25,
                              v26,
                              v27,
                              v28,
                              v29,
                              v30,
                              "wlan_dp_fb_add_flow_to_fwt");
                          }
                          ++v91;
                          v93 = *((unsigned __int8 *)v92 + 16);
                          v95 = *((_DWORD *)&v137 + v90) + 5;
                          v94 = *((_DWORD *)v92 + 2) - 1;
                          *((_DWORD *)v92 + 2) = v94;
                        }
                        while ( v95 < v93 );
                      }
                      ++v90;
                    }
                    while ( v90 != 8 );
                    v102 = v134;
                    if ( !(_DWORD)v50 )
                      goto LABEL_210;
                    v103 = 0;
                    LODWORD(v45) = 0;
                    v133 = 0;
                    while ( 1 )
                    {
                      if ( (unsigned __int64)(24LL * v103 - 176) < 0xFFFFFFFFFFFFFF3FLL )
                        goto LABEL_206;
                      v104 = &v141[3 * v103];
                      v105 = *(_QWORD *)(a1 + 240);
                      if ( v105 && *(_QWORD *)v105 && (v106 = *(_QWORD *)(*(_QWORD *)v105 + 152LL)) != 0 )
                      {
                        v107 = *(__int64 (**)(void))(v106 + 264);
                        if ( v107 )
                        {
                          if ( *((_DWORD *)v107 - 1) != -1653155309 )
                            __break(0x8228u);
                          if ( (v107() & 1) != 0 )
                            goto LABEL_151;
                        }
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x45u,
                          1u,
                          "%s invalid instance",
                          v23,
                          v24,
                          v25,
                          v26,
                          v27,
                          v28,
                          v29,
                          v30,
                          "cdp_ipa_check_is_ring_ipa_rx");
                      }
                      if ( dp_rx_is_ring_latency_sensitive_reo(*((_BYTE *)v104 + 17)) )
                      {
LABEL_151:
                        if ( ++v103 > 7 )
                          goto LABEL_208;
                      }
                      else
                      {
                        v108 = v133;
                        if ( (v133 & 0x3FFFFFFFFFFFFFF8LL) != 0
                          || (unsigned __int64)(24LL * v103 - 177) < 0xFFFFFFFFFFFFFF3FLL )
                        {
                          goto LABEL_206;
                        }
                        v109 = (unsigned int)v45;
                        v110 = *((unsigned __int8 *)v104 + 16);
                        LODWORD(v45) = *((_DWORD *)&v137 + v133) - v110;
                        if ( (int)v45 >= 6 )
                        {
                          if ( v91 )
                          {
                            v111 = 1;
LABEL_166:
                            v112 = (unsigned int)v45 / 0xA;
                            if ( (unsigned int)v45 / 0xA >= 9 )
                              v113 = 9;
                            else
                              v113 = v112;
                            v114 = v113;
                            while ( v114 <= 9 )
                            {
                              v115 = v165[v114 - 1];
                              if ( v115 )
                              {
                                v165[v114 - 1] = *(_QWORD *)(v115 + 8);
LABEL_186:
                                v120 = *((unsigned __int8 *)v104 + 17);
                                *((_BYTE *)v104 + 16) += *(_BYTE *)(v115 + 2);
                                if ( *(unsigned __int8 *)(v115 + 3) != v120 )
                                {
                                  v121 = v134 + 4LL * v109++;
                                  *(_WORD *)v121 = *(_WORD *)v115;
                                  *(_BYTE *)(v121 + 2) = *((_BYTE *)v104 + 17);
                                }
                                --v91;
                                LODWORD(v45) = (_DWORD)v45 - *(unsigned __int8 *)(v115 + 2);
                                _qdf_mem_free(v115);
                                if ( (int)v45 < 6 )
                                {
                                  v108 = v133;
                                }
                                else
                                {
                                  v108 = v133;
                                  v111 = 0;
                                  if ( v91 )
                                    goto LABEL_166;
                                }
                                goto LABEL_192;
                              }
                              if ( --v114 == -1 )
                              {
                                if ( v112 >= 8 )
                                  v112 = 8;
                                v48 = (v111 & 1) == 0;
                                v116 = v112 + 2;
                                v117 = 10;
                                if ( v48 )
                                  v117 = v116;
                                v118 = 8LL * (unsigned int)v113 + 8;
                                while ( v113 + 1 < v117 )
                                {
                                  if ( v118 > 0x4F )
                                    goto LABEL_206;
                                  v119 = *(_QWORD *)((char *)&v165[-1] + v118);
                                  v118 += 8LL;
                                  ++v113;
                                  if ( v119 )
                                  {
                                    if ( v113 > 9 )
                                      goto LABEL_206;
                                    v115 = v165[v113 - 1];
                                    v165[v113 - 1] = *(_QWORD *)(v115 + 8);
                                    if ( v115 )
                                      goto LABEL_186;
                                    goto LABEL_192;
                                  }
                                }
                                goto LABEL_192;
                              }
                            }
                            goto LABEL_206;
                          }
LABEL_192:
                          v110 = *((unsigned __int8 *)v104 + 16);
                        }
                        LODWORD(v45) = v109;
                        v122 = *((_BYTE *)v104 + 17);
                        v123 = v135 + 8 * v108;
                        v124 = v108 + 1;
                        *(_DWORD *)v123 = v110;
                        *(_BYTE *)(v123 + 4) = v122;
                        if ( v124 >= v50 )
                          goto LABEL_207;
                        v102 = v134;
                        v68 = v103++ < 7;
                        v133 = v124;
                        if ( !v68 )
                          goto LABEL_208;
                      }
                    }
                  }
                  qdf_trace_msg(
                    0x45u,
                    2u,
                    "%s: failed to allocate mig_list for flow balance",
                    v82,
                    v83,
                    v84,
                    v85,
                    v86,
                    v87,
                    v88,
                    v89,
                    "wlan_dp_fb_do_flow_balance");
LABEL_197:
                  if ( (_DWORD)v50 )
                  {
                    v125 = BYTE1(v142);
                    *(_DWORD *)v51 = (unsigned __int8)v142;
                    *(_BYTE *)(v51 + 4) = v125;
                    if ( (_DWORD)v50 != 1 )
                    {
                      v126 = BYTE1(v145);
                      *(_DWORD *)(v51 + 8) = (unsigned __int8)v145;
                      *(_BYTE *)(v51 + 12) = v126;
                      if ( (_DWORD)v50 != 2 )
                      {
                        v127 = BYTE1(v148);
                        *(_DWORD *)(v51 + 16) = (unsigned __int8)v148;
                        *(_BYTE *)(v51 + 20) = v127;
                        if ( (_DWORD)v50 != 3 )
                        {
                          v128 = BYTE1(v151);
                          *(_DWORD *)(v51 + 24) = (unsigned __int8)v151;
                          *(_BYTE *)(v51 + 28) = v128;
                          if ( (_DWORD)v50 != 4 )
                          {
                            v129 = BYTE1(v154);
                            *(_DWORD *)(v51 + 32) = (unsigned __int8)v154;
                            *(_BYTE *)(v51 + 36) = v129;
                            if ( (_DWORD)v50 != 5 )
                            {
                              v130 = BYTE1(v157);
                              *(_DWORD *)(v51 + 40) = (unsigned __int8)v157;
                              *(_BYTE *)(v51 + 44) = v130;
                              if ( (_DWORD)v50 != 6 )
                              {
                                v131 = BYTE1(v160);
                                *(_DWORD *)(v51 + 48) = (unsigned __int8)v160;
                                *(_BYTE *)(v51 + 52) = v131;
                                if ( (_DWORD)v50 != 7 )
                                {
                                  v132 = BYTE1(v163);
                                  *(_DWORD *)(v51 + 56) = (unsigned __int8)v163;
                                  *(_BYTE *)(v51 + 60) = v132;
                                  if ( (_DWORD)v50 != 8 )
                                    goto LABEL_206;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  goto LABEL_211;
                }
                v81 = 6;
              }
              else
              {
                v81 = 5;
              }
            }
            else
            {
              v81 = 4;
            }
LABEL_129:
            v51 = a6;
            goto LABEL_130;
          }
          v81 = 3;
        }
        else
        {
          v81 = 2;
        }
      }
      else
      {
        v81 = 1;
      }
    }
    else
    {
      v81 = 0;
    }
LABEL_130:
    if ( v81 == (_DWORD)v50 && !v78 )
      goto LABEL_197;
    goto LABEL_132;
  }
  v52 = 0;
  v53 = 0;
  v54 = (unsigned int)v50 % a5;
  while ( 1 )
  {
    v55 = v54 != 0;
    if ( v54 )
      v56 = (unsigned int)v50 / a5 + 1;
    else
      v56 = (unsigned int)v50 / a5;
    v80 = v54-- != 0;
    if ( !v80 )
      v54 = 0;
    if ( v56 )
      break;
LABEL_55:
    if ( ++v52 == a5 )
      goto LABEL_91;
  }
  v57 = 33 - 4LL * v53;
  v58 = (unsigned int)(8 - v53);
  v59 = (unsigned int)v50 / a5 - 1 + v55;
  if ( (unsigned __int64)(4LL * v53) > 0x21 )
    v57 = 0;
  v60 = (unsigned __int64)(v57 + 3) >> 2;
  v61 = *(_DWORD *)(a4 + 8 * v52) / v56;
  if ( v60 >= v58 )
    v62 = (unsigned int)(8 - v53);
  else
    v62 = v60;
  if ( v59 >= v62 )
    v63 = v62;
  else
    v63 = v59;
  v64 = v53;
  v65 = v63 + 1;
  if ( (unsigned int)(v63 + 1) >= 3 )
  {
    v66 = 33 - 4LL * v53;
    if ( (unsigned __int64)(4LL * v53) > 0x21 )
      v66 = 0;
    v67 = (unsigned __int64)(v66 + 3) >> 2;
    if ( v67 >= v58 )
      v67 = (unsigned int)(8 - v53);
    if ( v59 < v67 )
      LODWORD(v67) = v59;
    v68 = v53 + (int)v67 < v53;
    v64 = v53;
    if ( !v68 )
    {
      v69 = ~v63;
      if ( (v65 & 1) != 0 )
        v70 = v65 & 1;
      else
        v70 = 2;
      v71 = v65 - v70;
      v72 = v69 + v70;
      v73 = v53;
      v64 = v53 + v71;
      do
      {
        v74 = v73 + 1;
        *((_DWORD *)&v137 + v73) = v61;
        v72 += 2;
        v73 += 2;
        *((_DWORD *)&v137 + v74) = v61;
      }
      while ( v72 );
    }
  }
  v53 += v56;
  while ( (unsigned __int64)(4LL * v64) <= 0x20 && v64 != 8 )
  {
    v75 = v64++;
    *((_DWORD *)&v137 + v75) = v61;
    if ( v53 == v64 )
      goto LABEL_55;
  }
LABEL_206:
  __break(1u);
LABEL_207:
  v102 = v134;
LABEL_208:
  if ( (_DWORD)v45 )
    dp_fisa_update_fst_table(a1, v102, (int)v45, v23, v24, v25, v26, v27, v28, v29, v30);
LABEL_210:
  _qdf_mem_free(v102);
LABEL_211:
  v33 = 0;
  v34 = v141[0];
  if ( v141[0] )
LABEL_14:
    _qdf_mem_free(v34);
LABEL_15:
  if ( v143 )
    _qdf_mem_free(v143);
  if ( v146 )
    _qdf_mem_free(v146);
  if ( v149 )
    _qdf_mem_free(v149);
  if ( v152 )
    _qdf_mem_free(v152);
  if ( v155 )
    _qdf_mem_free(v155);
  if ( v158 )
    _qdf_mem_free(v158);
  if ( v161 )
    _qdf_mem_free(v161);
  _ReadStatusReg(SP_EL0);
  return v33;
}
