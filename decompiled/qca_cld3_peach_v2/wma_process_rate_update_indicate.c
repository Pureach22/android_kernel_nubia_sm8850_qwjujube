__int64 __fastcall wma_process_rate_update_indicate(__int64 a1, unsigned __int8 *a2)
{
  __int64 v3; // x23
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w25
  unsigned int v13; // w20
  __int64 cmpt_obj; // x0
  unsigned int v15; // w24
  int v16; // w8
  int v17; // w21
  int v18; // w27
  const char *v19; // x2
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w24
  unsigned int v37; // w22
  unsigned int v38; // w23
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned int v55; // w8
  unsigned int v56; // w4
  char v57; // w26
  int v58; // w28
  char v59; // w8
  int v60; // w9
  int v61; // w13
  int v62; // w14
  char *v63; // x10
  int v64; // w11
  unsigned __int64 v65; // x11
  __int64 v66; // x12
  int v67; // w15
  _BYTE *v68; // x8
  int v69; // w23
  int v70; // w24
  int v71; // w11
  int v72; // w12
  char *v73; // x10
  int v74; // w8
  unsigned __int64 v75; // x8
  __int64 v76; // x9
  int v77; // w13
  unsigned int v78; // w24
  int v79; // w9
  int v80; // w10
  int v81; // w12
  unsigned __int64 v82; // x12
  __int64 v83; // x11
  int v84; // w13
  int v85; // w14
  int v86; // w11
  int v87; // w15
  char *v88; // x10
  char *v89; // x10
  int v90; // t1
  int v91; // w12
  int v92; // w8
  int v93; // w13
  char *v94; // x10
  int v95; // t1
  int v96; // w9
  int v97; // w9
  int v98; // w10
  int v99; // w13
  int v100; // w14
  char *v101; // x8
  int v102; // w11
  unsigned __int64 v103; // x11
  __int64 v104; // x12
  int v105; // w15
  char v106; // w9
  int v107; // w10
  int v108; // w13
  int v109; // w14
  char *v110; // x8
  int v111; // w11
  unsigned __int64 v112; // x11
  __int64 v113; // x12
  int v114; // w15
  int v115; // w14
  int v116; // w11
  int v117; // w15
  int v118; // w14
  int v119; // w11
  int v120; // w15
  int v121; // w14
  int v122; // w11
  int v123; // w15
  char *v124; // x8
  char *v125; // x8
  int v126; // t1
  int v127; // w14
  int v128; // w11
  int v129; // w15
  char *v130; // x8
  int v131; // t1
  unsigned __int64 v132; // x11
  int v133; // w9
  unsigned __int64 v134; // x10
  char v135; // w8
  double v136; // d0
  double v137; // d1
  double v138; // d2
  double v139; // d3
  double v140; // d4
  double v141; // d5
  double v142; // d6
  double v143; // d7
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  const char *v152; // x2
  unsigned int v153; // w1
  __int64 v155; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int64 v156; // [xsp+20h] [xbp-10h]
  __int64 v157; // [xsp+28h] [xbp-8h]

  v157 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 520);
  v155 = 0;
  v156 = 0;
  if ( !(unsigned int)wma_find_vdev_id_by_addr() )
  {
    if ( *(_QWORD *)v3 )
    {
      v13 = *(_DWORD *)(v3 + 32);
      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)v3, v4, v5, v6, v7, v8, v9, v10, v11);
      if ( cmpt_obj )
      {
        v15 = *(_DWORD *)(cmpt_obj + 304);
        v16 = *((_DWORD *)a2 + 5);
        if ( !v13 )
          v13 = (v15 >> 3) & 1;
        if ( v16 )
        {
          v17 = *((_DWORD *)a2 + 4);
        }
        else
        {
          v17 = *((_DWORD *)a2 + 3);
          if ( (v17 & 0x80000000) == 0 )
          {
            v18 = 35;
            goto LABEL_16;
          }
          LOBYTE(v16) = a2[28];
          v17 = *((_DWORD *)a2 + 6);
        }
        v18 = 36;
        if ( (v16 & 8) != 0 )
          v13 = 1;
LABEL_16:
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: dev_id = %d, dev_type = %d, dev_mode = %d,",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "wma_process_rate_update_indicate");
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: mac = %02x:%02x:%02x:**:**:%02x, config.shortgi = %d, rate_flags = 0x%x",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "wma_process_rate_update_indicate",
          a2[1],
          a2[2],
          a2[3],
          a2[6],
          *(_DWORD *)(v3 + 32),
          v15);
        v36 = *a2;
        v37 = *(_DWORD *)(v3 + 40);
        v38 = *(_DWORD *)(v3 + 436);
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Input: nss = %d, mbpsx10 = 0x%x, chwidth = %d, shortgi = %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "wma_encode_mc_rate",
          *a2,
          (unsigned int)v17,
          v37,
          v13);
        if ( (v17 & 0x40000000) != 0 && v36 )
        {
          v55 = ((unsigned int)v17 >> 28) & 3;
          v17 &= 0x8FFFFFFF;
          if ( v55 >= v36 )
            v56 = v36;
          else
            v56 = v55;
        }
        else if ( v17 >= 2001 )
        {
          v56 = v36;
        }
        else
        {
          v56 = 0;
        }
        v57 = 16 * v56;
        v58 = (16 * (_BYTE)v56) & 0x30;
        if ( v17 >= 541 )
        {
          if ( v37 == 1 )
          {
            v70 = (unsigned int)v17 >> (v56 == 1);
            if ( !v13 )
            {
              if ( v70 > 1349 )
              {
                v70 = 1350;
                v89 = (char *)&unk_B09ADC;
                goto LABEL_123;
              }
              if ( v70 < 136 )
              {
                v70 = 135;
                v89 = (char *)&unk_B09B14;
              }
              else
              {
                v71 = 0;
                v91 = 7;
                v73 = (char *)&ht40_800ns_rate_tbl;
                do
                {
                  v92 = (v71 + v91) >> 1;
                  if ( v92 == 8 )
                    goto LABEL_251;
                  v75 = 8LL * v92;
                  if ( v75 > 0x40 )
                    goto LABEL_251;
                  v76 = (__int64)(v71 + v91) >> 1;
                  if ( (unsigned __int64)(8 * v76) > 0x40 )
                    goto LABEL_251;
                  v93 = *((_DWORD *)&ht40_800ns_rate_tbl + 2 * v76);
                  if ( v70 == v93 )
                  {
LABEL_116:
                    v89 = &v73[8 * v76 + 4];
                    goto LABEL_117;
                  }
                  if ( v70 > v93 )
                    v91 = (v71 + v91) >> 1;
                  else
                    v71 = (v71 + v91) >> 1;
                }
                while ( v91 - v71 > 1 );
LABEL_102:
                if ( v71 == 8 )
                  goto LABEL_251;
                v75 = 8LL * v71;
                if ( v75 > 0x40 )
                  goto LABEL_251;
                v76 = v71;
                v94 = &v73[8 * v71];
                v95 = *(_DWORD *)v94;
                v89 = v94 + 4;
                v70 = v95;
LABEL_117:
                if ( (v75 | 4) > 0x40 || ((8 * v76) | 4uLL) > 0x40 )
                  goto LABEL_251;
              }
LABEL_123:
              v12 = 4 * (v70 == 0);
              LOBYTE(v58) = v58 | *v89 & 0xF | 0x80;
              if ( v38 < 0xBB8 )
              {
LABEL_239:
                v135 = v58;
                v133 = v70;
                goto LABEL_240;
              }
LABEL_124:
              if ( v37 == 2 )
              {
                v106 = v56 == 1;
                v107 = (unsigned int)v17 >> (v56 == 1);
                if ( v13 )
                {
                  if ( v107 <= 4332 )
                  {
                    if ( v107 >= 326 )
                    {
                      v108 = 0;
                      v115 = 9;
                      v110 = (char *)&vht80_400ns_rate_tbl;
                      while ( 1 )
                      {
                        v116 = (v108 + v115) >> 1;
                        if ( v116 == 10 )
                          goto LABEL_251;
                        v112 = 8LL * v116;
                        if ( v112 > 0x50 )
                          goto LABEL_251;
                        v113 = (__int64)(v108 + v115) >> 1;
                        if ( (unsigned __int64)(8 * v113) > 0x50 )
                          goto LABEL_251;
                        v117 = *((_DWORD *)&vht80_400ns_rate_tbl + 2 * v113);
                        if ( v107 == v117 )
                          goto LABEL_210;
                        if ( v107 > v117 )
                          v115 = (v108 + v115) >> 1;
                        else
                          v108 = (v108 + v115) >> 1;
                        if ( v115 - v108 <= 1 )
                          goto LABEL_190;
                      }
                    }
                    v125 = (char *)&unk_B09C94;
                    v107 = 325;
                    v132 = 76;
                    goto LABEL_217;
                  }
                  v125 = (char *)&unk_B09C4C;
                  v107 = 4333;
                }
                else
                {
                  if ( v107 <= 3899 )
                  {
                    if ( v107 < 294 )
                    {
                      v125 = (char *)&unk_B09CE4;
                      v107 = 293;
                      v132 = 76;
                    }
                    else
                    {
                      v108 = 0;
                      v121 = 9;
                      v110 = (char *)&vht80_800ns_rate_tbl;
                      do
                      {
                        v122 = (v108 + v121) >> 1;
                        if ( v122 == 10 )
                          goto LABEL_251;
                        v112 = 8LL * v122;
                        if ( v112 > 0x50 )
                          goto LABEL_251;
                        v113 = (__int64)(v108 + v121) >> 1;
                        if ( (unsigned __int64)(8 * v113) > 0x50 )
                          goto LABEL_251;
                        v123 = *((_DWORD *)&vht80_800ns_rate_tbl + 2 * v113);
                        if ( v107 == v123 )
                        {
LABEL_210:
                          v125 = &v110[8 * v113 + 4];
                          goto LABEL_211;
                        }
                        if ( v107 > v123 )
                          v121 = (v108 + v121) >> 1;
                        else
                          v108 = (v108 + v121) >> 1;
                      }
                      while ( v121 - v108 > 1 );
LABEL_190:
                      if ( v108 == 10 )
                        goto LABEL_251;
                      v112 = 8LL * v108;
                      if ( v112 > 0x50 )
                        goto LABEL_251;
                      v113 = v108;
                      v124 = &v110[8 * v108];
                      v126 = *(_DWORD *)v124;
                      v125 = v124 + 4;
                      v107 = v126;
LABEL_211:
                      if ( (v112 | 4) > 0x50 )
                        goto LABEL_251;
                      v132 = (8 * v113) | 4;
                      if ( v132 > 0x50 )
                        goto LABEL_251;
                    }
                    goto LABEL_217;
                  }
                  v125 = (char *)&unk_B09C9C;
                  v107 = 3900;
                }
              }
              else
              {
                if ( v37 != 1 )
                {
                  if ( v37 )
                  {
                    qdf_trace_msg(
                      0x36u,
                      2u,
                      "%s: chwidth enum %d not supported",
                      v47,
                      v48,
                      v49,
                      v50,
                      v51,
                      v52,
                      v53,
                      v54,
                      "wma_fill_vht_mcast_rate",
                      v37);
LABEL_238:
                    v12 = 4 * (v70 == 0);
                    goto LABEL_239;
                  }
                  v98 = (unsigned int)v17 >> (v56 == 1);
                  if ( v13 )
                  {
                    if ( v98 <= 866 )
                    {
                      if ( v98 >= 73 )
                      {
                        v99 = 0;
                        v100 = 8;
                        v101 = (char *)&vht20_400ns_rate_tbl;
                        while ( 1 )
                        {
                          v102 = (v99 + v100) >> 1;
                          if ( v102 == 9 )
                            goto LABEL_251;
                          v103 = 8LL * v102;
                          if ( v103 > 0x48 )
                            goto LABEL_251;
                          v104 = (__int64)(v99 + v100) >> 1;
                          if ( (unsigned __int64)(8 * v104) > 0x48 )
                            goto LABEL_251;
                          v105 = *((_DWORD *)&vht20_400ns_rate_tbl + 2 * v104);
                          if ( v98 == v105 )
                            goto LABEL_223;
                          if ( v98 > v105 )
                            v100 = (v99 + v100) >> 1;
                          else
                            v99 = (v99 + v100) >> 1;
                          if ( v100 - v99 <= 1 )
                            goto LABEL_204;
                        }
                      }
                      v125 = (char *)&unk_B09B5C;
                      v98 = 72;
LABEL_230:
                      v132 = 68;
                      goto LABEL_231;
                    }
                    v125 = (char *)&unk_B09B1C;
                    v98 = 867;
                  }
                  else
                  {
                    if ( v98 <= 779 )
                    {
                      if ( v98 >= 66 )
                      {
                        v99 = 0;
                        v127 = 8;
                        v101 = (char *)&vht20_800ns_rate_tbl;
                        do
                        {
                          v128 = (v99 + v127) >> 1;
                          if ( v128 == 9 )
                            goto LABEL_251;
                          v103 = 8LL * v128;
                          if ( v103 > 0x48 )
                            goto LABEL_251;
                          v104 = (__int64)(v99 + v127) >> 1;
                          if ( (unsigned __int64)(8 * v104) > 0x48 )
                            goto LABEL_251;
                          v129 = *((_DWORD *)&vht20_800ns_rate_tbl + 2 * v104);
                          if ( v98 == v129 )
                          {
LABEL_223:
                            v125 = &v101[8 * v104 + 4];
                            goto LABEL_224;
                          }
                          if ( v98 > v129 )
                            v127 = (v99 + v127) >> 1;
                          else
                            v99 = (v99 + v127) >> 1;
                        }
                        while ( v127 - v99 > 1 );
LABEL_204:
                        if ( v99 == 9 )
                          goto LABEL_251;
                        v103 = 8LL * v99;
                        if ( v103 > 0x48 )
                          goto LABEL_251;
                        v104 = v99;
                        v130 = &v101[8 * v99];
                        v131 = *(_DWORD *)v130;
                        v125 = v130 + 4;
                        v98 = v131;
LABEL_224:
                        if ( (v103 | 4) > 0x48 )
                          goto LABEL_251;
                        v132 = (8 * v104) | 4;
                        if ( v132 > 0x48 )
                          goto LABEL_251;
                        goto LABEL_231;
                      }
                      v125 = (char *)&unk_B09BA4;
                      v98 = 65;
                      goto LABEL_230;
                    }
                    v125 = (char *)&unk_B09B64;
                    v98 = 780;
                  }
                  v132 = 4;
LABEL_231:
                  v133 = v98 << (v56 == 1);
                  v134 = 72;
LABEL_232:
                  if ( v134 <= v132 )
                    goto LABEL_251;
                  if ( v133 )
                  {
                    v135 = v57 | *v125 & 0xF | 0xC0;
                    if ( v70 )
                    {
                      if ( v70 >= v17 )
                      {
                        v12 = 0;
                        if ( v133 < v17 || v133 >= v70 )
                        {
LABEL_241:
                          qdf_trace_msg(
                            0x36u,
                            8u,
                            "%s: NSS = %d, freq = %d",
                            v47,
                            v48,
                            v49,
                            v50,
                            v51,
                            v52,
                            v53,
                            v54,
                            "wma_encode_mc_rate");
                          v69 = (unsigned __int8)v58;
                          qdf_trace_msg(
                            0x36u,
                            8u,
                            "%s: input_rate = %d, chwidth = %d rate = 0x%x, streaming_rate = %d",
                            v136,
                            v137,
                            v138,
                            v139,
                            v140,
                            v141,
                            v142,
                            v143,
                            "wma_encode_mc_rate",
                            (unsigned int)v17,
                            v37,
                            (unsigned __int8)v58,
                            (unsigned int)v70);
                          if ( v12 )
                          {
                            v152 = "%s: Error, Invalid input rate value";
                            v153 = 2;
                            goto LABEL_245;
                          }
LABEL_243:
                          LODWORD(v155) = 28;
                          HIDWORD(v155) = v13;
                          v156 = __PAIR64__(v69, v18);
                          v12 = wma_send_multi_pdev_vdev_set_params(1, 0, &v155, 2);
                          if ( !v12 )
                            goto LABEL_246;
                          v152 = "%s: failed to send vdev set params";
                          v153 = 8;
LABEL_245:
                          qdf_trace_msg(
                            0x36u,
                            v153,
                            v152,
                            v144,
                            v145,
                            v146,
                            v147,
                            v148,
                            v149,
                            v150,
                            v151,
                            "wma_process_rate_update_indicate");
                          goto LABEL_246;
                        }
                      }
                      else
                      {
                        v12 = 0;
                        if ( v70 >= v133 )
                          goto LABEL_241;
                      }
                    }
                    else
                    {
                      v12 = 0;
                    }
LABEL_240:
                    LOBYTE(v58) = v135;
                    v70 = v133;
                    goto LABEL_241;
                  }
                  goto LABEL_238;
                }
                v106 = v56 == 1;
                v107 = (unsigned int)v17 >> (v56 == 1);
                if ( v13 )
                {
                  if ( v107 <= 1999 )
                  {
                    if ( v107 >= 151 )
                    {
                      v108 = 0;
                      v109 = 9;
                      v110 = (char *)&vht40_400ns_rate_tbl;
                      while ( 1 )
                      {
                        v111 = (v108 + v109) >> 1;
                        if ( v111 == 10 )
                          goto LABEL_251;
                        v112 = 8LL * v111;
                        if ( v112 > 0x50 )
                          goto LABEL_251;
                        v113 = (__int64)(v108 + v109) >> 1;
                        if ( (unsigned __int64)(8 * v113) > 0x50 )
                          goto LABEL_251;
                        v114 = *((_DWORD *)&vht40_400ns_rate_tbl + 2 * v113);
                        if ( v107 == v114 )
                          goto LABEL_210;
                        if ( v107 > v114 )
                          v109 = (v108 + v109) >> 1;
                        else
                          v108 = (v108 + v109) >> 1;
                        if ( v109 - v108 <= 1 )
                          goto LABEL_190;
                      }
                    }
                    v125 = (char *)&unk_B09BF4;
                    v107 = 150;
                    v132 = 76;
                    goto LABEL_217;
                  }
                  v125 = (char *)&unk_B09BAC;
                  v107 = 2000;
                }
                else
                {
                  if ( v107 <= 1799 )
                  {
                    if ( v107 >= 136 )
                    {
                      v108 = 0;
                      v118 = 9;
                      v110 = (char *)&vht40_800ns_rate_tbl;
                      while ( 1 )
                      {
                        v119 = (v108 + v118) >> 1;
                        if ( v119 == 10 )
                          goto LABEL_251;
                        v112 = 8LL * v119;
                        if ( v112 > 0x50 )
                          goto LABEL_251;
                        v113 = (__int64)(v108 + v118) >> 1;
                        if ( (unsigned __int64)(8 * v113) > 0x50 )
                          goto LABEL_251;
                        v120 = *((_DWORD *)&vht40_800ns_rate_tbl + 2 * v113);
                        if ( v107 == v120 )
                          goto LABEL_210;
                        if ( v107 > v120 )
                          v118 = (v108 + v118) >> 1;
                        else
                          v108 = (v108 + v118) >> 1;
                        if ( v118 - v108 <= 1 )
                          goto LABEL_190;
                      }
                    }
                    v125 = (char *)&unk_B09C44;
                    v107 = 135;
                    v132 = 76;
                    goto LABEL_217;
                  }
                  v125 = (char *)&unk_B09BFC;
                  v107 = 1800;
                }
              }
              v132 = 4;
LABEL_217:
              v133 = v107 << v106;
              v134 = 80;
              goto LABEL_232;
            }
            if ( v70 > 1499 )
            {
              v70 = 1500;
              v89 = (char *)&unk_B09A9C;
              goto LABEL_123;
            }
            if ( v70 < 151 )
            {
              v70 = 150;
              v89 = (char *)&unk_B09AD4;
              goto LABEL_123;
            }
            v71 = 0;
            v72 = 7;
            v73 = (char *)&ht40_400ns_rate_tbl;
            while ( 1 )
            {
              v74 = (v71 + v72) >> 1;
              if ( v74 == 8 )
                break;
              v75 = 8LL * v74;
              if ( v75 > 0x40 )
                break;
              v76 = (__int64)(v71 + v72) >> 1;
              if ( (unsigned __int64)(8 * v76) > 0x40 )
                break;
              v77 = *((_DWORD *)&ht40_400ns_rate_tbl + 2 * v76);
              if ( v70 == v77 )
                goto LABEL_116;
              if ( v70 > v77 )
                v72 = (v71 + v72) >> 1;
              else
                v71 = (v71 + v72) >> 1;
              if ( v72 - v71 <= 1 )
                goto LABEL_102;
            }
          }
          else
          {
            if ( v37 )
            {
              v78 = v56;
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Error, Invalid chwidth enum %d",
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                "wma_fill_ht_mcast_rate",
                v37);
              v56 = v78;
              v70 = 0;
              v12 = 4;
              if ( v38 < 0xBB8 )
                goto LABEL_239;
              goto LABEL_124;
            }
            v59 = v56 == 1;
            v60 = (unsigned int)v17 >> (v56 == 1);
            if ( v13 )
            {
              if ( v60 <= 721 )
              {
                if ( v60 >= 73 )
                {
                  v61 = 0;
                  v62 = 7;
                  v63 = (char *)&ht20_400ns_rate_tbl;
                  while ( 1 )
                  {
                    v64 = (v61 + v62) >> 1;
                    if ( v64 == 8 )
                      goto LABEL_251;
                    v65 = 8LL * v64;
                    if ( v65 > 0x40 )
                      goto LABEL_251;
                    v66 = (__int64)(v61 + v62) >> 1;
                    if ( (unsigned __int64)(8 * v66) > 0x40 )
                      goto LABEL_251;
                    v67 = *((_DWORD *)&ht20_400ns_rate_tbl + 2 * v66);
                    if ( v60 == v67 )
                      goto LABEL_112;
                    if ( v60 > v67 )
                      v62 = (v61 + v62) >> 1;
                    else
                      v61 = (v61 + v62) >> 1;
                    if ( v62 - v61 <= 1 )
                      goto LABEL_88;
                  }
                }
                v97 = 72;
                v89 = (char *)&unk_B09A54;
                goto LABEL_121;
              }
              v96 = 722;
              v89 = (char *)&unk_B09A1C;
LABEL_108:
              v70 = v96 << v59;
              goto LABEL_123;
            }
            if ( v60 > 649 )
            {
              v96 = 650;
              v89 = (char *)&unk_B09A5C;
              goto LABEL_108;
            }
            if ( v60 < 66 )
            {
              v97 = 65;
              v89 = (char *)&unk_B09A94;
LABEL_121:
              v70 = v97 << v59;
              goto LABEL_123;
            }
            v61 = 0;
            v85 = 7;
            v63 = (char *)&ht20_800ns_rate_tbl;
            do
            {
              v86 = (v61 + v85) >> 1;
              if ( v86 == 8 )
                goto LABEL_251;
              v65 = 8LL * v86;
              if ( v65 > 0x40 )
                goto LABEL_251;
              v66 = (__int64)(v61 + v85) >> 1;
              if ( (unsigned __int64)(8 * v66) > 0x40 )
                goto LABEL_251;
              v87 = *((_DWORD *)&ht20_800ns_rate_tbl + 2 * v66);
              if ( v60 == v87 )
              {
LABEL_112:
                v89 = &v63[8 * v66 + 4];
                goto LABEL_113;
              }
              if ( v60 > v87 )
                v85 = (v61 + v85) >> 1;
              else
                v61 = (v61 + v85) >> 1;
            }
            while ( v85 - v61 > 1 );
LABEL_88:
            if ( v61 != 8 )
            {
              v65 = 8LL * v61;
              if ( v65 <= 0x40 )
              {
                v66 = v61;
                v88 = &v63[8 * v61];
                v90 = *(_DWORD *)v88;
                v89 = v88 + 4;
                v60 = v90;
LABEL_113:
                if ( (v65 | 4) <= 0x40 && ((8 * v66) | 4uLL) <= 0x40 )
                {
                  v70 = v60 << v59;
                  goto LABEL_123;
                }
              }
            }
          }
LABEL_251:
          __break(1u);
        }
        if ( v17 < 1 )
        {
          v69 = 255;
        }
        else
        {
          if ( v17 == 540 )
          {
            v68 = &unk_B09CEC;
          }
          else if ( v17 < 11 )
          {
            v68 = &unk_B09D44;
          }
          else
          {
            v79 = 0;
            v80 = 11;
            do
            {
              v81 = (v79 + v80) >> 1;
              if ( v81 == 12 )
                goto LABEL_251;
              v82 = 8LL * v81;
              if ( v82 > 0x60 )
                goto LABEL_251;
              v83 = (__int64)(v79 + v80) >> 1;
              if ( (unsigned __int64)(8 * v83) > 0x60 )
                goto LABEL_251;
              v84 = *((_DWORD *)&ofdm_cck_rate_tbl + 2 * v83);
              if ( v84 == v17 )
                goto LABEL_70;
              if ( v84 < v17 )
                v80 = (v79 + v80) >> 1;
              else
                v79 = (v79 + v80) >> 1;
            }
            while ( v80 - v79 > 1 );
            v83 = v79;
            v82 = 8LL * v79;
LABEL_70:
            if ( (v82 | 4) > 0x60 || ((8 * v83) | 4uLL) > 0x60 )
              goto LABEL_251;
            v68 = (char *)&ofdm_cck_rate_tbl + 8 * v83 + 4;
          }
          v69 = *v68 & 0xF | ((((unsigned __int8)*v68 >> 7) & 1) << 6) | v58;
        }
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: NSS = %d, input_rate = %d, rate = 0x%x",
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          "wma_encode_mc_rate");
        goto LABEL_243;
      }
      v19 = "%s: ailed to get mlme_obj";
    }
    else
    {
      v19 = "%s: vdev is NULL";
    }
    qdf_trace_msg(0x36u, 2u, v19, v4, v5, v6, v7, v8, v9, v10, v11, "wma_get_vdev_rate_flag");
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to get rate_flag for VDEV_%d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "wma_process_rate_update_indicate",
      0);
    v12 = 4;
    goto LABEL_246;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: vdev handle is invalid for %02x:%02x:%02x:**:**:%02x",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wma_process_rate_update_indicate",
    a2[1],
    a2[2],
    a2[3],
    a2[6]);
  v12 = 4;
LABEL_246:
  _qdf_mem_free((__int64)a2);
  _ReadStatusReg(SP_EL0);
  return v12;
}
