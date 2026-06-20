__int64 __fastcall sch_send_beacon_req(__int64 a1, const void *a2, unsigned __int16 a3, __int64 a4, int a5)
{
  _BYTE *v10; // x27
  __int64 v11; // x21
  int v12; // w8
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  int sap_mode_info; // w24
  unsigned __int8 *v24; // x25
  int v25; // w24
  bool is_6ghz_chan_freq; // w0
  _BYTE *v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x24
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w5
  unsigned int v47; // w4
  __int64 v48; // x25
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x26
  __int64 v58; // x8
  unsigned int v59; // w28
  char v60; // w8
  bool v61; // w0
  unsigned int v62; // w11
  __int16 v63; // w8
  unsigned int v64; // w28
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 cmpt_obj; // x0
  unsigned __int8 v74; // w26
  unsigned int v75; // w26
  const char *v76; // x2
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w25
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  _BYTE *v94; // x26
  __int64 v95; // x8
  int v96; // w4
  char v97; // w8
  char v98; // w8
  int v99; // w4
  char v100; // w8
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x0
  __int64 v110; // x1
  __int64 v111; // x2
  const char *v112; // x2
  __int64 v113; // x4
  __int64 v114; // x5
  __int64 v115; // x0
  __int64 v116; // x24
  int v117; // w8
  char v118; // w8
  unsigned int v119; // w4
  __int64 result; // x0
  unsigned __int8 v121; // w1
  unsigned int v122; // w0
  unsigned int v123; // w19
  __int64 v124; // x0
  char v125; // w8
  __int64 v126; // x0
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  unsigned int v135; // w8
  __int64 v136; // x0
  __int64 v137; // x0
  __int64 v138; // x9
  __int64 v139; // x11
  _BYTE *v140; // x8
  char *v142; // x13
  unsigned int v143; // w8
  unsigned int v144; // w4
  char v145; // w16
  int v146; // w0
  int v147; // w17
  unsigned int v148; // [xsp+8h] [xbp-178h]
  const void *v149; // [xsp+10h] [xbp-170h]
  __int64 v150; // [xsp+18h] [xbp-168h]
  __int16 v151; // [xsp+24h] [xbp-15Ch]
  unsigned int v152; // [xsp+28h] [xbp-158h]
  unsigned int v153; // [xsp+2Ch] [xbp-154h]
  __int64 v154; // [xsp+30h] [xbp-150h] BYREF
  __int64 v155; // [xsp+38h] [xbp-148h]
  __int64 v156; // [xsp+40h] [xbp-140h]
  __int64 v157; // [xsp+48h] [xbp-138h]
  __int64 v158; // [xsp+50h] [xbp-130h]
  __int64 v159; // [xsp+58h] [xbp-128h]
  unsigned __int16 v160[2]; // [xsp+60h] [xbp-120h] BYREF
  int v161; // [xsp+64h] [xbp-11Ch] BYREF
  __int16 v162; // [xsp+68h] [xbp-118h]
  __int16 v163; // [xsp+6Ch] [xbp-114h] BYREF
  __int64 v164; // [xsp+70h] [xbp-110h] BYREF
  __int64 v165; // [xsp+78h] [xbp-108h]
  __int64 v166; // [xsp+80h] [xbp-100h]
  __int64 v167; // [xsp+88h] [xbp-F8h]
  __int64 v168; // [xsp+90h] [xbp-F0h]
  __int64 v169; // [xsp+98h] [xbp-E8h]
  __int64 v170; // [xsp+A0h] [xbp-E0h]
  __int64 v171; // [xsp+A8h] [xbp-D8h]
  __int64 v172; // [xsp+B0h] [xbp-D0h]
  __int64 v173; // [xsp+B8h] [xbp-C8h]
  __int64 v174; // [xsp+C0h] [xbp-C0h]
  __int64 v175; // [xsp+C8h] [xbp-B8h]
  __int64 v176; // [xsp+D0h] [xbp-B0h]
  __int64 v177; // [xsp+D8h] [xbp-A8h]
  __int64 v178; // [xsp+E0h] [xbp-A0h]
  __int64 v179; // [xsp+E8h] [xbp-98h]
  __int64 v180; // [xsp+F0h] [xbp-90h]
  __int64 v181; // [xsp+F8h] [xbp-88h]
  __int64 v182; // [xsp+100h] [xbp-80h]
  __int64 v183; // [xsp+108h] [xbp-78h]
  __int64 v184; // [xsp+110h] [xbp-70h]
  __int64 v185; // [xsp+118h] [xbp-68h]
  __int64 v186; // [xsp+120h] [xbp-60h]
  __int64 v187; // [xsp+128h] [xbp-58h]
  __int64 v188; // [xsp+130h] [xbp-50h]
  __int64 v189; // [xsp+138h] [xbp-48h]
  __int64 v190; // [xsp+140h] [xbp-40h]
  _QWORD v191[4]; // [xsp+148h] [xbp-38h] BYREF
  char v192; // [xsp+168h] [xbp-18h]
  __int64 v193; // [xsp+170h] [xbp-10h]

  v10 = (_BYTE *)(a4 + 7170);
  v193 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = a1 + 12288;
  v12 = *(_DWORD *)(a4 + 88);
  v158 = 0;
  v159 = 0;
  v156 = 0;
  v157 = 0;
  v154 = 0;
  v155 = 0;
  if ( v12 != 1 || !*(_BYTE *)(a1 + 12450) )
    goto LABEL_83;
  v13 = lim_send_probe_rsp_template_to_hal(a1, a4, a4 + 1952);
  if ( v13 )
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FAILED to send probe response template with retCode %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "sch_send_beacon_req",
      v13);
  v22 = *(_QWORD *)(a1 + 21624);
  BYTE4(v191[0]) = 0;
  LODWORD(v191[0]) = 0;
  LODWORD(v166) = 0;
  v164 = 0;
  v165 = 0;
  sap_mode_info = (unsigned __int8)policy_mgr_get_sap_mode_info(v22, (unsigned __int64)&v164, (unsigned __int64)v191);
  if ( (unsigned int)(sap_mode_info - 1) > 3 )
    goto LABEL_11;
  if ( !wlan_reg_is_24ghz_ch_freq(v164) && !wlan_reg_is_5ghz_ch_freq(v164) )
  {
    if ( sap_mode_info != 1 )
    {
      v24 = (unsigned __int8 *)v191 + 1;
      if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v164)) )
        goto LABEL_9;
      if ( wlan_reg_is_5ghz_ch_freq(HIDWORD(v164)) )
        goto LABEL_9;
      if ( sap_mode_info != 2 )
      {
        v24 = (unsigned __int8 *)v191 + 2;
        if ( wlan_reg_is_24ghz_ch_freq(v165) )
          goto LABEL_9;
        if ( wlan_reg_is_5ghz_ch_freq(v165) )
          goto LABEL_9;
        if ( sap_mode_info != 3 )
        {
          v24 = (unsigned __int8 *)v191 + 3;
          if ( wlan_reg_is_24ghz_ch_freq(HIDWORD(v165)) || wlan_reg_is_5ghz_ch_freq(HIDWORD(v165)) )
            goto LABEL_9;
        }
      }
    }
LABEL_11:
    v25 = 255;
    goto LABEL_12;
  }
  v24 = (unsigned __int8 *)v191;
LABEL_9:
  v25 = *v24;
LABEL_12:
  is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a4 + 284));
  if ( v25 == 255 && is_6ghz_chan_freq )
  {
    v27 = (_BYTE *)_qdf_mem_malloc(0x18u, "lim_send_fils_discovery_template", 524);
    if ( v27 )
    {
      v36 = (__int64)v27;
      *v27 = *(_BYTE *)(a4 + 10);
      v37 = _qdf_mem_malloc(0x200u, "lim_send_fils_discovery_template", 531);
      *(_QWORD *)(v36 + 16) = v37;
      if ( v37 )
      {
        v46 = *(unsigned __int16 *)(a4 + 7176);
        v47 = *(_DWORD *)(a4 + 284);
        v48 = v37;
        v163 = 0;
        v192 = 0;
        memset(v191, 0, sizeof(v191));
        v160[0] = 0;
        v189 = 0;
        v190 = 0;
        v187 = 0;
        v188 = 0;
        v185 = 0;
        v186 = 0;
        v183 = 0;
        v184 = 0;
        v181 = 0;
        v182 = 0;
        v179 = 0;
        v180 = 0;
        v177 = 0;
        v178 = 0;
        v175 = 0;
        v176 = 0;
        v173 = 0;
        v174 = 0;
        v171 = 0;
        v172 = 0;
        v169 = 0;
        v170 = 0;
        v167 = 0;
        v168 = 0;
        v165 = 0;
        v166 = 0;
        v164 = 0;
        v162 = -1;
        v161 = -1;
        v152 = v46;
        v153 = v47;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: FD TMPL freq: %d chWidth: %d",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "lim_populate_fd_tmpl_frame");
        v57 = *(_QWORD *)(a4 + 16);
        if ( v57 )
        {
          v58 = *(_QWORD *)(v57 + 40);
          if ( v58 )
          {
            v149 = a2;
            v150 = *(_QWORD *)(v57 + 40);
            v59 = *(_DWORD *)(v58 + 28);
            lim_populate_mac_header(a1, v48, 0, 13, &v161, (_BYTE *)(a4 + 30));
            *(_BYTE *)(v48 + 16) = *(_BYTE *)(a4 + 24);
            *(_BYTE *)(v48 + 17) = *(_BYTE *)(a4 + 25);
            *(_BYTE *)(v48 + 18) = *(_BYTE *)(a4 + 26);
            *(_BYTE *)(v48 + 19) = *(_BYTE *)(a4 + 27);
            *(_BYTE *)(v48 + 20) = *(_BYTE *)(a4 + 28);
            v60 = *(_BYTE *)(a4 + 29);
            *(_WORD *)(v48 + 24) = 8708;
            *(_BYTE *)(v48 + 21) = v60;
            v61 = wlan_reg_is_6ghz_chan_freq(v153);
            v62 = v59;
            v148 = v59;
            if ( v61 )
              v63 = 99;
            else
              v63 = 67;
            if ( v61 )
              v64 = 2;
            else
              v64 = 0;
            if ( v62 <= 0x27 && ((1LL << v62) & 0x8060180000LL) != 0 )
            {
              v63 |= 0x200u;
              v64 |= 1u;
            }
            if ( v64 )
              v63 |= 0x1000u;
            v151 = v63;
            *(_WORD *)(v48 + 26) = v63;
            qdf_mem_set((void *)(v48 + 28), 8u, 0);
            *(_WORD *)(v48 + 36) = *(_WORD *)(a4 + 7158);
            cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v57, v65, v66, v67, v68, v69, v70, v71, v72);
            if ( cmpt_obj )
            {
              v74 = *(_BYTE *)(cmpt_obj + 178);
              if ( v74 )
                qdf_mem_copy(v191, (const void *)(cmpt_obj + 145), *(unsigned __int8 *)(cmpt_obj + 178));
            }
            else
            {
              v74 = 0;
            }
            *(_DWORD *)(v48 + 38) = wlan_construct_shortssid((char *)v191, v74);
            if ( v64 )
            {
              *(_BYTE *)(v48 + 42) = v64;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: length: %d",
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                v93,
                "lim_populate_fd_tmpl_frame",
                v64);
              v94 = (_BYTE *)(v48 + 43);
              v85 = v64 + 43;
            }
            else
            {
              v94 = (_BYTE *)(v48 + 42);
              v85 = 42;
            }
            a2 = v149;
            v95 = v150;
            if ( (v151 & 0x20) == 0 )
            {
LABEL_72:
              if ( (v151 & 0x200) != 0 )
                *v94++ = *(_BYTE *)(v95 + 3);
              if ( wlan_reg_is_6ghz_chan_freq(v153) || *v10 )
              {
                v109 = populate_dot11f_tx_power_env(a1, a4, &v164, v152, v153, v160, 0);
                if ( v160[0] > 8u )
                {
                  v112 = "%s: tpe_num  %d greater than max size";
LABEL_78:
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    v112,
                    v101,
                    v102,
                    v103,
                    v104,
                    v105,
                    v106,
                    v107,
                    v108,
                    "lim_populate_fd_tmpl_frame");
                  goto LABEL_79;
                }
                if ( v160[0] )
                {
                  v138 = 0;
                  v139 = 1;
                  do
                  {
                    *v94 = -61;
                    if ( v138 == 216 )
                      goto LABEL_114;
                    if ( (unsigned __int64)(v138 - 214) < 0xFFFFFFFFFFFFFF28LL )
                      goto LABEL_157;
                    v142 = (char *)&v164 + v138 + 5;
                    v143 = *((unsigned __int8 *)&v164 + v138 + 2);
                    if ( v143 >= 9 )
                    {
                      v112 = "%s: num_tx_power %d greater than max num";
                      goto LABEL_78;
                    }
                    v144 = v143 + 1;
                    v94[1] = v143 + 1;
                    if ( !v143 )
                    {
                      v112 = "%s: tpe length %d less than min len or greater than max len";
                      goto LABEL_78;
                    }
                    if ( (unsigned __int64)(v138 - 215) < 0xFFFFFFFFFFFFFF28LL
                      || (v145 = *((_BYTE *)&v164 + v138 + 1),
                          v146 = v94[2] & 0xF8 | v145 & 7,
                          v94[2] = v94[2] & 0xF8 | v145 & 7,
                          v147 = *((_BYTE *)&v164 + v138 + 1) & 0x38,
                          v109 = v146 & 0xFFFFFFC7 | v147,
                          v94[2] = v109,
                          v94[2] = v145 & 7 | *((_BYTE *)&v164 + v138 + 1) & 0xC0 | v147,
                          (unsigned __int64)(v138 - 214) < 0xFFFFFFFFFFFFFF28LL) )
                    {
LABEL_157:
                      __break(1u);
                      return lim_send_probe_rsp_template_to_hal(v109, v110, v111);
                    }
                    if ( *(v142 - 3) )
                    {
                      if ( (unsigned __int64)(v138 - 213) < 0xFFFFFFFFFFFFFF28LL )
                        goto LABEL_157;
                      v94[3] = *((_BYTE *)&v164 + v138 + 3);
                      if ( (unsigned __int8)*(v142 - 3) < 2u )
                      {
                        v140 = v94 + 4;
                      }
                      else
                      {
                        if ( (unsigned __int64)(v138 - 212) < 0xFFFFFFFFFFFFFF28LL )
                          goto LABEL_157;
                        v94[4] = *((_BYTE *)&v164 + v138 + 4);
                        if ( (unsigned __int8)*(v142 - 3) < 3u )
                        {
                          v140 = v94 + 5;
                        }
                        else
                        {
                          if ( (unsigned __int64)(v138 - 211) < 0xFFFFFFFFFFFFFF28LL )
                            goto LABEL_157;
                          v94[5] = *((_BYTE *)&v164 + v138 + 5);
                          if ( (unsigned __int8)*(v142 - 3) < 4u )
                          {
                            v140 = v94 + 6;
                          }
                          else
                          {
                            if ( (unsigned __int64)(v138 - 210) < 0xFFFFFFFFFFFFFF28LL )
                              goto LABEL_157;
                            v94[6] = *((_BYTE *)&v164 + v138 + 6);
                            if ( (unsigned __int8)*(v142 - 3) < 5u )
                            {
                              v140 = v94 + 7;
                            }
                            else
                            {
                              if ( (unsigned __int64)(v138 - 209) < 0xFFFFFFFFFFFFFF28LL )
                                goto LABEL_157;
                              v94[7] = *((_BYTE *)&v164 + v138 + 7);
                              if ( (unsigned __int8)*(v142 - 3) < 6u )
                              {
                                v140 = v94 + 8;
                              }
                              else
                              {
                                if ( (unsigned __int64)(v138 - 208) < 0xFFFFFFFFFFFFFF28LL )
                                  goto LABEL_157;
                                v94[8] = *((_BYTE *)&v164 + v138 + 8);
                                if ( (unsigned __int8)*(v142 - 3) < 7u )
                                {
                                  v140 = v94 + 9;
                                }
                                else
                                {
                                  if ( (unsigned __int64)(v138 - 207) < 0xFFFFFFFFFFFFFF28LL )
                                    goto LABEL_157;
                                  v94[9] = *((_BYTE *)&v165 + v138 + 1);
                                  v140 = v94 + 10;
                                  if ( (unsigned __int8)*(v142 - 3) >= 8u )
                                  {
                                    if ( (unsigned __int64)(v138 - 206) < 0xFFFFFFFFFFFFFF28LL )
                                      goto LABEL_157;
                                    *v140 = *((_BYTE *)&v165 + v138 + 2);
                                    if ( (unsigned __int8)*(v142 - 3) > 8u )
                                      goto LABEL_114;
                                    v140 = v94 + 11;
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
                      v140 = v94 + 3;
                    }
                    v138 += 27;
                    v85 += v144 + 2;
                    v94 = v140;
                  }
                  while ( v160[0] > (unsigned int)(unsigned __int16)v139++ );
                }
              }
              *(_DWORD *)(v36 + 4) = v85;
              *(_DWORD *)(v36 + 8) = (v85 + 3) & 0xFFFFFFFC;
              v75 = target_if_vdev_mgr_send_fd_tmpl(
                      *(_QWORD *)(a4 + 16),
                      v36,
                      v101,
                      v102,
                      v103,
                      v104,
                      v105,
                      v106,
                      v107,
                      v108);
              if ( !v75 )
              {
LABEL_81:
                _qdf_mem_free(*(_QWORD *)(v36 + 16));
                _qdf_mem_free(v36);
                if ( !v75 )
                  goto LABEL_83;
                goto LABEL_82;
              }
              v113 = v85;
              v114 = v75;
LABEL_80:
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: FAIL bytes %d retcode[%X]",
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                "lim_send_fils_discovery_template",
                v113,
                v114);
              goto LABEL_81;
            }
            v96 = *(_DWORD *)(a4 + 7176);
            v97 = v163 | (2 * *(_BYTE *)(a4 + 1620));
            LOBYTE(v163) = v97;
            if ( v96 > 2 )
            {
              if ( (unsigned int)(v96 - 3) < 2 )
              {
                v98 = v97 | 0xC;
                goto LABEL_62;
              }
              if ( v96 == 7 )
              {
                v98 = v97 | 0x10;
                goto LABEL_62;
              }
            }
            else
            {
              switch ( v96 )
              {
                case 0:
LABEL_63:
                  v99 = (unsigned __int8)v10[1465];
                  if ( (unsigned int)(v99 - 3) >= 6 )
                  {
                    if ( (unsigned int)(v99 - 1) > 1 )
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: NSS value: %d is not supported",
                        v86,
                        v87,
                        v88,
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        "lim_populate_fd_capability");
                    else
                      LOBYTE(v163) = v163 | (32 * v99 - 32);
                  }
                  else
                  {
                    LOBYTE(v163) = v163 | 0x80;
                  }
                  if ( v148 - 5 > 0x23 )
                    v100 = 4;
                  else
                    v100 = byte_AFC768[v148 - 5];
                  HIBYTE(v163) |= v100;
                  qdf_mem_copy(v94, &v163, 2u);
                  v95 = v150;
                  v94 += 2;
                  goto LABEL_72;
                case 1:
                  v98 = v97 | 4;
                  goto LABEL_62;
                case 2:
                  v98 = v97 | 8;
LABEL_62:
                  LOBYTE(v163) = v98;
                  goto LABEL_63;
              }
            }
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: channel width : %d is not supported",
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              v93,
              "lim_fd_cap_channel_width320");
            goto LABEL_63;
          }
          v76 = "%s: des_chan is NULL";
        }
        else
        {
          v76 = "%s: VDEV is NULL";
        }
        qdf_trace_msg(0x35u, 2u, v76, v49, v50, v51, v52, v53, v54, v55, v56, "lim_populate_fd_tmpl_frame");
        v85 = 24;
LABEL_79:
        v113 = v85;
        v114 = 16;
        v75 = 16;
        goto LABEL_80;
      }
      _qdf_mem_free(v36);
      v75 = 2;
    }
    else
    {
      v75 = 2;
    }
LABEL_82:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: FAILED to send fils discovery template retCode %d",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "sch_send_beacon_req",
      v75);
  }
LABEL_83:
  v115 = _qdf_mem_malloc(0x268u, "sch_send_beacon_req", 628);
  if ( !v115 )
  {
    result = 2;
    goto LABEL_117;
  }
  v116 = v115;
  LODWORD(v154) = 4145;
  qdf_mem_copy((void *)(v115 + 1), (const void *)(a4 + 24), 6u);
  *(_DWORD *)(v116 + 524) = *(unsigned __int16 *)(a4 + 7360);
  if ( v10[112] )
  {
    *(_DWORD *)(v116 + 532) = *(_DWORD *)(a1 + 12456);
    *(_DWORD *)(v116 + 536) = *(_DWORD *)(a1 + 12460);
  }
  v117 = *(unsigned __int8 *)(v11 + 176);
  *(_BYTE *)(v116 + 548) = v117;
  if ( v117 )
  {
    *(_DWORD *)(v116 + 552) = *(_DWORD *)(a1 + 12468);
    *(_DWORD *)(v116 + 560) = *(_DWORD *)(a1 + 12472);
    *(_DWORD *)(v116 + 564) = *(_DWORD *)(a1 + 12476);
    *(_DWORD *)(v116 + 568) = *(_DWORD *)(a1 + 12480);
    if ( *(unsigned __int8 *)(v11 + 176) > 1u )
    {
      *(_DWORD *)(v116 + 584) = *(_DWORD *)(a1 + 12500);
      *(_DWORD *)(v116 + 592) = *(_DWORD *)(a1 + 12504);
      *(_DWORD *)(v116 + 596) = *(_DWORD *)(a1 + 12508);
      *(_DWORD *)(v116 + 600) = *(_DWORD *)(a1 + 12512);
      if ( *(unsigned __int8 *)(v11 + 176) >= 3u )
      {
        *(_DWORD *)(v116 + 616) = *(_DWORD *)(a1 + 12532);
        *(_DWORD *)(v116 + 624) = *(_DWORD *)(a1 + 12536);
        *(_DWORD *)(v116 + 628) = *(_DWORD *)(a1 + 12540);
        *(_DWORD *)(v116 + 632) = *(_DWORD *)(a1 + 12544);
        if ( *(unsigned __int8 *)(v11 + 176) > 3u )
          goto LABEL_114;
      }
    }
  }
  v118 = *(_BYTE *)(a4 + 10);
  *(_DWORD *)(v116 + 540) = a5;
  *(_BYTE *)v116 = v118;
  v119 = *(unsigned __int16 *)(v11 + 164);
  if ( !*(_WORD *)(v11 + 164) || v119 >= *(unsigned __int16 *)(a4 + 7360) )
  {
    *(_WORD *)(v116 + 528) = v119;
    if ( a3 >= 0x201u )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: beacon size (%d) exceed host limit %d",
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        "sch_send_beacon_req",
        a3,
        512);
      goto LABEL_95;
    }
    qdf_mem_copy((void *)(v116 + 7), a2, a3);
    *(_DWORD *)(v116 + 520) = a3;
    v121 = *(_BYTE *)(a4 + 8);
    v155 = v116;
    HIDWORD(v154) = 0;
    mac_trace_msg_tx(a1, v121, 4145);
    v122 = wma_post_ctrl_msg(a1, &v154);
    if ( v122 )
    {
      v123 = v122;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Posting SEND_BEACON_REQ to HAL failed, reason=%X",
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        "sch_send_beacon_req",
        v122);
      result = v123;
      goto LABEL_117;
    }
    v124 = *(_QWORD *)(a4 + 16);
    if ( *(_DWORD *)(v124 + 16) != 1
      || (wlan_vdev_mlme_is_mlo_vdev(v124, v101, v102, v103, v104, v105, v106, v107, v108) & 1) == 0 )
    {
      goto LABEL_115;
    }
    v125 = v10[3006];
    v164 = 0;
    v165 = 0;
    LOWORD(v191[0]) = 0;
    if ( (v125 & 1) == 0
      && (mlme_is_notify_co_located_ap_update_rnr(*(_QWORD *)(a4 + 16), v101, v102, v103, v104, v105, v106, v107, v108)
        & 1) == 0 )
    {
      goto LABEL_116;
    }
    v126 = *(_QWORD *)(a4 + 16);
    v10[3006] = 0;
    mlme_set_notify_co_located_ap_update_rnr(v126, 0, v101, v102, v103, v104, v105, v106, v107, v108);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: vdev id %d mlo notify beacon change info to partner link",
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      "lim_notify_link_info",
      *(unsigned __int8 *)(*(_QWORD *)(a4 + 16) + 168LL));
    lim_get_mlo_vdev_list(a4, v191, &v164);
    v135 = LOWORD(v191[0]);
    if ( !LOWORD(v191[0]) )
      goto LABEL_116;
    v136 = v164;
    if ( v164 )
    {
      if ( v164 != *(_QWORD *)(a4 + 16) )
      {
        lim_partner_link_info_change();
        v136 = v164;
      }
      lim_mlo_release_vdev_ref(v136);
      v135 = LOWORD(v191[0]);
    }
    if ( v135 < 2 )
      goto LABEL_116;
    v137 = v165;
    if ( v165 )
    {
      if ( v165 != *(_QWORD *)(a4 + 16) )
      {
        lim_partner_link_info_change();
        v137 = v165;
      }
      lim_mlo_release_vdev_ref(v137);
    }
    if ( LOWORD(v191[0]) <= 2u )
      goto LABEL_116;
LABEL_114:
    __break(0x5512u);
LABEL_115:
    lim_ap_mlme_vdev_rnr_notify(a4, v101, v102, v103, v104, v105, v106, v107, v108);
LABEL_116:
    result = 0;
    goto LABEL_117;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Invalid p2pIeOffset:[%d]",
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    "sch_send_beacon_req");
LABEL_95:
  _qdf_mem_free(v116);
  result = 16;
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return result;
}
