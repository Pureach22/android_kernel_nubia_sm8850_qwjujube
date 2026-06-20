__int64 __fastcall lim_process_auth_frame(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x25
  unsigned int v12; // w26
  __int64 v13; // x22
  __int64 v15; // x20
  __int64 v16; // x21
  char v17; // w0
  char v18; // w8
  __int64 v19; // x8
  __int64 v20; // x4
  __int64 v21; // x5
  __int64 v22; // x6
  __int64 v23; // x7
  const char *v24; // x2
  __int64 v25; // x20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w28
  unsigned int v35; // w27
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x0
  __int64 v45; // x21
  const char *v46; // x2
  unsigned int v47; // w1
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x5
  __int64 v57; // x6
  __int64 v58; // x7
  int v59; // w8
  __int64 v60; // x24
  __int64 v61; // x6
  __int64 v62; // x7
  int v63; // w8
  int v64; // w10
  int v65; // w8
  __int64 v66; // x9
  __int64 v67; // x28
  __int64 v68; // x0
  __int64 v69; // x24
  void *v70; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  int v79; // w8
  __int64 v80; // x0
  int v81; // w8
  __int64 v82; // x5
  __int64 v83; // x6
  __int64 v84; // x7
  int v85; // w8
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  const char *v94; // x2
  __int64 v95; // x5
  __int64 v96; // x6
  __int64 v97; // x7
  int v98; // w8
  int v99; // w8
  __int64 v100; // x4
  _BYTE *v101; // x8
  unsigned int v102; // w22
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  int v111; // w4
  __int64 v112; // x0
  int v113; // w21
  int wep_key; // w0
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int16 v123; // w9
  const char *v124; // x2
  unsigned int v125; // w1
  __int64 v126; // x4
  __int64 v127; // x5
  __int64 v128; // x6
  __int64 v129; // x7
  __int64 v130; // x4
  __int64 v131; // x5
  __int64 v132; // x6
  __int64 v133; // x7
  int v134; // w8
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  __int64 v143; // x4
  __int64 v144; // x5
  __int64 v145; // x6
  __int64 v146; // x7
  int v147; // w8
  __int64 v148; // x0
  __int64 v149; // x1
  __int64 v150; // x2
  __int64 v151; // x3
  int v152; // w8
  __int64 v153; // [xsp+0h] [xbp-80h]
  __int64 v154; // [xsp+38h] [xbp-48h]
  int v155[2]; // [xsp+40h] [xbp-40h]
  unsigned __int16 *v156; // [xsp+48h] [xbp-38h]
  unsigned int v157; // [xsp+54h] [xbp-2Ch]
  __int64 v158; // [xsp+58h] [xbp-28h]
  unsigned __int64 v159; // [xsp+60h] [xbp-20h] BYREF
  _BYTE v160[16]; // [xsp+68h] [xbp-18h] BYREF
  __int64 v161; // [xsp+78h] [xbp-8h]

  v161 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a2 + 16);
  v12 = *(unsigned __int16 *)(a2 + 40);
  v159 = 0;
  memset(v160, 0, 13);
  if ( !v12 )
  {
    if ( v11 == -10 )
    {
      v22 = 0;
      v20 = 0;
      v21 = 0;
      v23 = 0;
    }
    else
    {
      v20 = *(unsigned __int8 *)(v11 + 10);
      v21 = *(unsigned __int8 *)(v11 + 11);
      v22 = *(unsigned __int8 *)(v11 + 12);
      v23 = *(unsigned __int8 *)(v11 + 15);
    }
    v24 = "%s: received Auth frame with no body from: %02x:%02x:%02x:**:**:%02x";
    goto LABEL_17;
  }
  if ( (*(_BYTE *)(v11 + 10) & 1) != 0 )
  {
    if ( v11 == -10 )
      v20 = 0;
    else
      v20 = *(unsigned __int8 *)(v11 + 10);
    if ( v11 == -10 )
    {
      v22 = 0;
      v21 = 0;
      v23 = 0;
      v24 = "%s: received Auth frame from a BC/MC addr: %02x:%02x:%02x:**:**:%02x";
    }
    else
    {
      v21 = *(unsigned __int8 *)(v11 + 11);
      v22 = *(unsigned __int8 *)(v11 + 12);
      v24 = "%s: received Auth frame from a BC/MC addr: %02x:%02x:%02x:**:**:%02x";
      v23 = *(unsigned __int8 *)(v11 + 15);
    }
LABEL_17:
    result = qdf_trace_msg(
               0x35u,
               2u,
               v24,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_process_auth_frame",
               v20,
               v21,
               v22,
               v23);
    goto LABEL_18;
  }
  v13 = *(_QWORD *)(result + 8);
  if ( *(_DWORD *)(a3 + 88) != 1
    || (v15 = result, v16 = a2, v17 = lim_mismatch_bssid_da(v11), a2 = v16, v18 = v17, result = v15, (v18 & 1) == 0) )
  {
    v19 = *(_QWORD *)(a3 + 16);
    if ( *(_DWORD *)(v19 + 1336) )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: SAP is suspended, reject peer auth",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "lim_process_auth_frame");
      goto LABEL_18;
    }
    v158 = result;
    v25 = a2;
    if ( (unsigned int)wlan_vdev_is_restart_progress(v19) )
    {
      v34 = *(unsigned __int16 *)(v11 + 22);
      v35 = v34 >> 4;
      if ( *(unsigned __int16 *)(a3 + 9984) == v34 >> 4
        && !(unsigned int)qdf_mem_cmp((const void *)(a3 + 9986), (const void *)(v11 + 10), 6u)
        && (*(_WORD *)v11 & 0x800) != 0 )
      {
        v46 = "%s: auth frame, seq num: %d is already processed, drop it";
        v47 = 8;
        goto LABEL_36;
      }
      v44 = lim_search_pre_auth_list(v158, v11 + 10);
      v45 = v44;
      if ( v44 && *(unsigned __int16 *)(v44 + 544) == v34 >> 4 )
      {
        v46 = "%s: Received an already processed auth frame with seq_num : %d";
        v47 = 2;
LABEL_36:
        result = qdf_trace_msg(0x35u, v47, v46, v36, v37, v38, v39, v40, v41, v42, v43, "lim_process_auth_frame", v35);
        goto LABEL_18;
      }
      *(_WORD *)(a3 + 9984) = v35;
      qdf_mem_copy((void *)(a3 + 9986), (const void *)(v11 + 10), 6u);
      if ( v12 <= 1 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: invalid frame len: %d",
                   v48,
                   v49,
                   v50,
                   v51,
                   v52,
                   v53,
                   v54,
                   v55,
                   "lim_process_auth_frame",
                   1);
        goto LABEL_18;
      }
      v156 = *(unsigned __int16 **)(v25 + 24);
      v157 = *v156;
      v60 = jiffies;
      if ( lim_process_auth_frame___last_ticks - jiffies + 125 < 0 )
      {
        if ( v11 == -10 )
        {
          v63 = 0;
          v61 = 0;
          v62 = 0;
          v64 = 0;
        }
        else
        {
          v61 = *(unsigned __int8 *)(v11 + 10);
          v62 = *(unsigned __int8 *)(v11 + 11);
          v63 = *(unsigned __int8 *)(v11 + 12);
          v64 = *(unsigned __int8 *)(v11 + 15);
        }
        qdf_trace_msg(
          0x35u,
          4u,
          "Auth RX: vdev %d sys role %d lim_state %d from %02x:%02x:%02x:**:**:%02x rssi %d auth_alg %d seq %d",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          *(unsigned __int8 *)(a3 + 10),
          *(unsigned int *)(a3 + 88),
          *(unsigned int *)(a3 + 72),
          v61,
          v62,
          v63,
          v64,
          *(_DWORD *)(v25 + 8),
          *v156,
          v34 >> 4);
        lim_process_auth_frame___last_ticks = v60;
      }
      if ( *(_DWORD *)(a3 + 7036) == 2 && *(_DWORD *)(a3 + 7092) )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Restore default failure timeout",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "lim_process_auth_frame");
        v65 = *(_DWORD *)(a3 + 7092);
        v66 = *(_QWORD *)(v158 + 8);
        if ( (unsigned int)(v65 - 500) > 0x1194 )
        {
          *(_DWORD *)(v66 + 3480) = 1000;
          *(_DWORD *)(a3 + 7092) = 1000;
        }
        else
        {
          *(_DWORD *)(v66 + 3480) = v65;
        }
      }
      result = _qdf_mem_malloc(0x3FFu, "lim_process_auth_frame", 1893);
      if ( result )
      {
        v67 = result;
        v68 = _qdf_mem_malloc(0x3FFu, "lim_process_auth_frame", 1897);
        if ( v68 )
        {
          v69 = v68;
          v70 = (void *)_qdf_mem_malloc(0x10Du, "lim_process_auth_frame", 1901);
          if ( v70 )
          {
            *(_QWORD *)v155 = v70;
            qdf_mem_set(v70, 0x10Du, 0);
            if ( (*(_WORD *)v11 & 0x4000) != 0 )
            {
              if ( v12 > 3 )
              {
                v81 = *(_DWORD *)(a3 + 88);
                if ( v81 == 2 )
                {
                  *(_WORD *)(v69 + 4) = 15;
                  *(_DWORD *)v69 = 262145;
                  if ( v11 == -10 )
                  {
                    v84 = 0;
                    v82 = 0;
                    v83 = 0;
                    v85 = 0;
                  }
                  else
                  {
                    v82 = *(unsigned __int8 *)(v11 + 10);
                    v83 = *(unsigned __int8 *)(v11 + 11);
                    v84 = *(unsigned __int8 *)(v11 + 12);
                    v85 = *(unsigned __int8 *)(v11 + 15);
                  }
                  LODWORD(v153) = v85;
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: rx Auth frm with wep bit set role: %d %02x:%02x:%02x:**:**:%02x",
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    "lim_process_auth_frame",
                    *(unsigned int *)(a3 + 88),
                    v82,
                    v83,
                    v84,
                    v153);
                }
                else
                {
                  if ( v12 - 270 <= 0xFFFFFF81 )
                  {
                    if ( v11 == -10 )
                    {
                      v97 = 0;
                      v95 = 0;
                      v96 = 0;
                      v98 = 0;
                    }
                    else
                    {
                      v95 = *(unsigned __int8 *)(v11 + 10);
                      v96 = *(unsigned __int8 *)(v11 + 11);
                      v97 = *(unsigned __int8 *)(v11 + 12);
                      v98 = *(unsigned __int8 *)(v11 + 15);
                    }
                    v124 = "%s: Not enough size: %d to decry rx Auth frm %02x:%02x:%02x:**:**:%02x";
                    v125 = 2;
                    v100 = v12;
                    goto LABEL_96;
                  }
                  if ( v81 == 1 )
                    v101 = (_BYTE *)(a3 + 1620);
                  else
                    v101 = (_BYTE *)(v13 + 5436);
                  if ( *v101 )
                  {
                    v154 = v13 + 5436;
                    if ( v45 )
                    {
                      v102 = *((unsigned __int8 *)v156 + 3);
                      lim_deactivate_and_change_per_sta_id_timer(v158, 9, *(unsigned __int8 *)(v45 + 24));
                      v111 = *(_DWORD *)(v45 + 20);
                      if ( v111 == 6 || v111 == 8 )
                      {
                        v112 = *(_QWORD *)(a3 + 16);
                        v113 = *(_DWORD *)(a3 + 88);
                        v159 = 13;
                        wep_key = mlme_get_wep_key(
                                    v112,
                                    v103,
                                    v104,
                                    v105,
                                    v106,
                                    v107,
                                    v108,
                                    v109,
                                    v110,
                                    v154,
                                    v102 >> 6,
                                    v160,
                                    &v159);
                        if ( v113 == 1 || !wep_key )
                        {
                          if ( (unsigned __int8)lim_decrypt_auth_frame(v158, (int)v160, (int)v156) != 1 )
                          {
                            if ( (unsigned int)sir_convert_auth_frame2_struct(v158, v155[0], v12 - 8, v67) )
                              goto LABEL_66;
                            if ( *(_DWORD *)(a3 + 7036) != 1 || (*(unsigned __int16 *)(v67 + 2) | 2) == 3 )
                            {
                              if ( !(unsigned int)is_auth_valid(v67, a3) )
                                goto LABEL_66;
LABEL_74:
                              if ( (lim_is_valid_fils_auth_frame(v158, a3, v67) & 1) == 0 )
                              {
                                v94 = "%s: Received invalid FILS auth packet";
                                goto LABEL_67;
                              }
                              v99 = *(unsigned __int16 *)(v67 + 2);
                              if ( *(_DWORD *)(a3 + 72) == 7 && (unsigned int)(v99 - 1) >= 3 )
                              {
                                qdf_trace_msg(
                                  0x35u,
                                  3u,
                                  "%s: Override AuthFrame 4's seqNumber to 4",
                                  v86,
                                  v87,
                                  v88,
                                  v89,
                                  v90,
                                  v91,
                                  v92,
                                  v93,
                                  "lim_process_auth_frame");
                                LOBYTE(v99) = 4;
                                *(_WORD *)(v67 + 2) = 4;
                              }
                              wlan_connectivity_mgmt_event(
                                *(_QWORD *)(v158 + 21552),
                                v11,
                                *(unsigned __int8 *)(a3 + 10),
                                *(unsigned __int16 *)(v67 + 4),
                                0,
                                *(_DWORD *)(v25 + 8),
                                v157,
                                0,
                                v99,
                                0,
                                3);
                              lim_cp_stats_cstats_log_auth_evt(
                                a3,
                                1,
                                v157,
                                *(unsigned __int16 *)(v67 + 2),
                                *(unsigned __int16 *)(v67 + 4));
                              v100 = *(unsigned __int16 *)(v67 + 2);
                              if ( *(unsigned __int16 *)(v67 + 2) > 2u )
                              {
                                if ( (_DWORD)v100 == 3 )
                                {
                                  lim_process_auth_frame_type3(v158, v11, v67, v69, a3);
                                  goto LABEL_133;
                                }
                                if ( (_DWORD)v100 == 4 )
                                {
                                  lim_process_auth_frame_type4(v158, v11, v67, a3);
                                  goto LABEL_133;
                                }
                              }
                              else
                              {
                                if ( (_DWORD)v100 == 1 )
                                {
                                  lim_process_auth_frame_type1(v158, v11, v67, v35, v69, a3);
                                  goto LABEL_133;
                                }
                                if ( (_DWORD)v100 == 2 )
                                {
                                  lim_process_auth_frame_type2(v158, v11, v67, v69, *(_QWORD *)v155, v156, v12, a3);
                                  goto LABEL_133;
                                }
                              }
                              if ( v11 == -10 )
                              {
                                v97 = 0;
                                v95 = 0;
                                v96 = 0;
                                v98 = 0;
                              }
                              else
                              {
                                v95 = *(unsigned __int8 *)(v11 + 10);
                                v96 = *(unsigned __int8 *)(v11 + 11);
                                v97 = *(unsigned __int8 *)(v11 + 12);
                                v98 = *(unsigned __int8 *)(v11 + 15);
                              }
                              v124 = "%s: rx auth frm with invalid authseq no: %d from: %02x:%02x:%02x:**:**:%02x";
                              v125 = 3;
LABEL_96:
                              LODWORD(v153) = v98;
                              qdf_trace_msg(
                                0x35u,
                                v125,
                                v124,
                                v71,
                                v72,
                                v73,
                                v74,
                                v75,
                                v76,
                                v77,
                                v78,
                                "lim_process_auth_frame",
                                v100,
                                v95,
                                v96,
                                v97,
                                v153);
                              goto LABEL_133;
                            }
                            if ( v11 == -10 )
                              v152 = 0;
                            else
                              v152 = *(unsigned __int8 *)(v11 + 15);
                            LODWORD(v153) = v152;
                            qdf_trace_msg(
                              0x35u,
                              8u,
                              "%s: received Authentication frame from peer with wrong seq num %d: %02x:%02x:%02x:**:**:%02x",
                              v86,
                              v87,
                              v88,
                              v89,
                              v90,
                              v91,
                              v92,
                              v93,
                              "lim_process_auth_frame",
                              v153);
                            v148 = v158;
                            v150 = v11 + 10;
                            v151 = 1;
                            *(_DWORD *)(v69 + 2) = 917506;
                            v149 = v69;
LABEL_132:
                            lim_send_auth_mgmt_frame(v148, v149, v150, v151, a3);
                            goto LABEL_133;
                          }
                          if ( v11 == -10 )
                          {
                            v145 = 0;
                            v143 = 0;
                            v144 = 0;
                            v146 = 0;
                          }
                          else
                          {
                            v143 = *(unsigned __int8 *)(v11 + 10);
                            v144 = *(unsigned __int8 *)(v11 + 11);
                            v145 = *(unsigned __int8 *)(v11 + 12);
                            v146 = *(unsigned __int8 *)(v11 + 15);
                          }
                          qdf_trace_msg(
                            0x35u,
                            2u,
                            "%s: received Authentication frame from peer that failed decryption: %02x:%02x:%02x:**:**:%02x",
                            v135,
                            v136,
                            v137,
                            v138,
                            v139,
                            v140,
                            v141,
                            v142,
                            "lim_process_auth_frame",
                            v143,
                            v144,
                            v145,
                            v146);
                          lim_delete_pre_auth_node(v158, v11 + 10);
                          v148 = v158;
                          *(_DWORD *)v69 = 262145;
                          v149 = v69;
                          *(_WORD *)(v69 + 4) = 15;
LABEL_131:
                          v150 = v11 + 10;
                          v151 = 0;
                          goto LABEL_132;
                        }
                        qdf_trace_msg(
                          0x35u,
                          3u,
                          "%s: could not retrieve Default key",
                          v115,
                          v116,
                          v117,
                          v118,
                          v119,
                          v120,
                          v121,
                          v122,
                          "lim_process_auth_frame");
                        v123 = 15;
                      }
                      else
                      {
                        if ( v11 == -10 )
                          v147 = 0;
                        else
                          v147 = *(unsigned __int8 *)(v11 + 15);
                        LODWORD(v153) = v147;
                        qdf_trace_msg(
                          0x35u,
                          2u,
                          "%s: received Authentication frame from peer that is in state %d %02x:%02x:%02x:**:**:%02x",
                          v103,
                          v104,
                          v105,
                          v106,
                          v107,
                          v108,
                          v109,
                          v110,
                          "lim_process_auth_frame",
                          v153);
                        v123 = 14;
                      }
                    }
                    else
                    {
                      if ( v11 == -10 )
                      {
                        v132 = 0;
                        v130 = 0;
                        v131 = 0;
                        v133 = 0;
                      }
                      else
                      {
                        v130 = *(unsigned __int8 *)(v11 + 10);
                        v131 = *(unsigned __int8 *)(v11 + 11);
                        v132 = *(unsigned __int8 *)(v11 + 12);
                        v133 = *(unsigned __int8 *)(v11 + 15);
                      }
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: rx Auth frame with no preauth ctx with WEP bit set %02x:%02x:%02x:**:**:%02x",
                        v71,
                        v72,
                        v73,
                        v74,
                        v75,
                        v76,
                        v77,
                        v78,
                        "lim_process_auth_frame",
                        v130,
                        v131,
                        v132,
                        v133);
                      v123 = 14;
                    }
                  }
                  else
                  {
                    if ( v11 == -10 )
                    {
                      v128 = 0;
                      v126 = 0;
                      v127 = 0;
                      v129 = 0;
                    }
                    else
                    {
                      v126 = *(unsigned __int8 *)(v11 + 10);
                      v127 = *(unsigned __int8 *)(v11 + 11);
                      v128 = *(unsigned __int8 *)(v11 + 12);
                      v129 = *(unsigned __int8 *)(v11 + 15);
                    }
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: received Authentication frame3 from peer that while privacy option is turned OFF %02x:%02x:%02x:**:**:%02x",
                      v71,
                      v72,
                      v73,
                      v74,
                      v75,
                      v76,
                      v77,
                      v78,
                      "lim_process_auth_frame",
                      v126,
                      v127,
                      v128,
                      v129);
                    v123 = 15;
                  }
                  *(_DWORD *)v69 = 262145;
                  *(_WORD *)(v69 + 4) = v123;
                }
LABEL_130:
                v148 = v158;
                v149 = v69;
                goto LABEL_131;
              }
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: invalid frame len: %d",
                v71,
                v72,
                v73,
                v74,
                v75,
                v76,
                v77,
                v78,
                "lim_process_auth_frame",
                v12);
            }
            else
            {
              switch ( v157 )
              {
                case 2u:
                  if ( *(_DWORD *)(a3 + 88) != 1 )
                  {
LABEL_65:
                    if ( (unsigned int)sir_convert_auth_frame2_struct(v158, (int)v156, v12, v67) )
                    {
LABEL_66:
                      v94 = "%s: failed to convert Auth Frame to structure or Auth is not valid";
LABEL_67:
                      qdf_trace_msg(0x35u, 2u, v94, v86, v87, v88, v89, v90, v91, v92, v93, "lim_process_auth_frame");
                      break;
                    }
                    if ( *(_DWORD *)(a3 + 7036) != 1 || (*(unsigned __int16 *)(v67 + 2) | 2) == 3 )
                    {
                      if ( !(unsigned int)is_auth_valid(v67, a3) )
                        goto LABEL_66;
                      goto LABEL_74;
                    }
                    if ( v11 == -10 )
                      v134 = 0;
                    else
                      v134 = *(unsigned __int8 *)(v11 + 15);
                    LODWORD(v153) = v134;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: received Authentication frame from peer with wrong seq num %d: %02x:%02x:%02x:**:**:%02x",
                      v86,
                      v87,
                      v88,
                      v89,
                      v90,
                      v91,
                      v92,
                      v93,
                      "lim_process_auth_frame",
                      v153);
                    *(_DWORD *)(v69 + 2) = 917506;
                    goto LABEL_130;
                  }
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Auth Frame auth_alg  eSIR_FT_AUTH",
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    v77,
                    v78,
                    "lim_process_auth_frame");
                  lim_process_ft_auth_frame(v158, v25, a3);
                  break;
                case 7u:
                  lim_process_pasn_auth_frame(v158, *(unsigned __int8 *)(a3 + 10), v25);
                  break;
                case 3u:
                  v79 = *(_DWORD *)(a3 + 88);
                  if ( v79 == 2 || v79 == 1 && *(_BYTE *)(*(_QWORD *)(v158 + 8) + 3233LL) == 1 )
                    lim_process_sae_auth_frame(v158, v25, a3);
                  break;
                default:
                  goto LABEL_65;
              }
            }
LABEL_133:
            _qdf_mem_free(v69);
            _qdf_mem_free(v67);
            v80 = *(_QWORD *)v155;
            goto LABEL_134;
          }
          _qdf_mem_free(v69);
        }
        v80 = v67;
LABEL_134:
        result = _qdf_mem_free(v80);
      }
    }
    else
    {
      if ( v11 == -10 )
      {
        v58 = 0;
        v56 = 0;
        v57 = 0;
        v59 = 0;
      }
      else
      {
        v56 = *(unsigned __int8 *)(v11 + 10);
        v57 = *(unsigned __int8 *)(v11 + 11);
        v58 = *(unsigned __int8 *)(v11 + 12);
        v59 = *(unsigned __int8 *)(v11 + 15);
      }
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: vdev %d is restarting, drop auth frame sa:%02x:%02x:%02x:**:**:%02x",
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 "lim_process_auth_frame",
                 *(unsigned __int8 *)(a3 + 10),
                 v56,
                 v57,
                 v58,
                 v59);
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
