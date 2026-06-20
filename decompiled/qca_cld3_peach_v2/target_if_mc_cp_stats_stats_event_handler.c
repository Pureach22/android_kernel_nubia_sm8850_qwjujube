__int64 __fastcall target_if_mc_cp_stats_stats_event_handler(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 psoc_from_scn_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 v23; // x8
  __int64 v24; // x22
  __int64 v25; // x0
  unsigned int *v26; // x19
  unsigned int stats_param; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x21
  unsigned int v37; // w26
  const char *v38; // x2
  __int64 result; // x0
  __int64 v40; // x21
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  char v49; // w10
  bool v50; // zf
  char v51; // w8
  _QWORD *context; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w8
  _QWORD *v62; // x24
  __int64 v63; // x0
  __int64 v64; // x0
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  int *v73; // x25
  __int64 v74; // x28
  unsigned __int64 v75; // x27
  unsigned int pdev_stats; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x8
  __int64 v86; // x8
  _DWORD *v87; // x8
  int v88; // w9
  __int64 v89; // x0
  char v90; // w0
  char v91; // w24
  unsigned __int64 v92; // x25
  __int64 v93; // x28
  char v94; // w8
  _QWORD *v95; // x0
  _QWORD *v96; // x24
  __int64 v97; // x0
  int v98; // w8
  __int64 v99; // x27
  unsigned __int64 v100; // x25
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v109; // x0
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 v118; // x28
  __int64 v119; // x8
  _DWORD *v120; // x8
  __int64 v121; // x2
  __int64 v122; // x8
  __int64 v123; // x0
  __int64 v124; // x0
  __int64 v125; // x24
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  __int64 v134; // x26
  unsigned __int64 v135; // x27
  __int64 v136; // x25
  __int64 v137; // x8
  _BYTE *v138; // x0
  __int64 (__fastcall *v139)(__int64, unsigned int *); // x8
  __int64 v140; // [xsp+60h] [xbp-F0h]
  __int64 v141; // [xsp+68h] [xbp-E8h] BYREF
  __int64 v142; // [xsp+70h] [xbp-E0h]
  __int64 v143; // [xsp+78h] [xbp-D8h]
  __int64 v144; // [xsp+80h] [xbp-D0h]
  __int64 v145; // [xsp+88h] [xbp-C8h]
  __int64 v146; // [xsp+90h] [xbp-C0h]
  __int64 v147; // [xsp+98h] [xbp-B8h]
  __int64 v148; // [xsp+A0h] [xbp-B0h]
  __int64 v149; // [xsp+A8h] [xbp-A8h]
  __int64 v150; // [xsp+B0h] [xbp-A0h]
  __int64 v151; // [xsp+B8h] [xbp-98h]
  __int64 v152; // [xsp+C0h] [xbp-90h]
  __int64 v153; // [xsp+C8h] [xbp-88h]
  __int64 v154; // [xsp+D0h] [xbp-80h]
  __int64 v155; // [xsp+D8h] [xbp-78h]
  __int64 v156; // [xsp+E0h] [xbp-70h]
  _QWORD v157[10]; // [xsp+E8h] [xbp-68h] BYREF
  int v158; // [xsp+138h] [xbp-18h]
  __int64 v159; // [xsp+140h] [xbp-10h]

  v159 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
    if ( psoc_from_scn_hdl )
    {
      v22 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
      if ( v22 )
      {
        if ( *(_QWORD *)(v22 + 176) )
        {
          v23 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
          if ( v23 && (v24 = *(_QWORD *)(v23 + 16)) != 0 )
          {
            v140 = psoc_from_scn_hdl;
            v25 = _qdf_mem_malloc(0xD8u, "target_if_mc_cp_stats_stats_event_handler", 1175);
            if ( v25 )
            {
              v26 = (unsigned int *)v25;
              v148 = 0;
              v149 = 0;
              v146 = 0;
              v147 = 0;
              v144 = 0;
              v145 = 0;
              v142 = 0;
              v143 = 0;
              v141 = 0;
              if ( !a3 )
              {
                qdf_trace_msg(
                  0x62u,
                  2u,
                  "%s: Invalid input parameters",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "target_if_cp_stats_extract_event");
                v37 = 4;
                goto LABEL_23;
              }
              stats_param = wmi_extract_stats_param(v24);
              if ( stats_param )
              {
                v36 = jiffies;
                v37 = stats_param;
                if ( target_if_cp_stats_extract_event___last_ticks - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x62u,
                    2u,
                    "%s: stats param extract failed: %d",
                    v28,
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    "target_if_cp_stats_extract_event",
                    stats_param);
                  target_if_cp_stats_extract_event___last_ticks = v36;
                }
                goto LABEL_23;
              }
              qdf_trace_msg(
                0x62u,
                8u,
                "num: pdev: %d, pdev_extd: %d, vdev: %d, vdev_extd: %d, peer: %d, peer_extd: %d rssi: %d, mib %d, mib_ext"
                "d %d, bcnflt: %d, channel: %d, bcn: %d, peer_extd2: %d, recv_bcn: %d last_event: %x, stats id: %u",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                HIDWORD(v141),
                (unsigned int)v142,
                HIDWORD(v142),
                HIDWORD(v148),
                (unsigned int)v143,
                HIDWORD(v143),
                v146,
                v147,
                HIDWORD(v147),
                v144,
                HIDWORD(v144),
                HIDWORD(v145),
                HIDWORD(v146),
                v149,
                HIDWORD(v149),
                v141);
              v49 = target_if_cp_stats_extract_event_mac_seq;
              v50 = (~HIDWORD(v149) & 0x80000001) == 0;
              v26[37] = HIDWORD(v149);
              if ( v50 )
                v51 = 0;
              else
                v51 = v49 + 1;
              *((_BYTE *)v26 + 152) = v49;
              target_if_cp_stats_extract_event_mac_seq = v51;
              context = _cds_get_context(
                          71,
                          (__int64)"target_if_cp_stats_extract_pdev_stats",
                          v41,
                          v42,
                          v43,
                          v44,
                          v45,
                          v46,
                          v47,
                          v48);
              v61 = HIDWORD(v141);
              *v26 = HIDWORD(v141);
              if ( v61 )
              {
                v62 = context;
                v63 = _qdf_mem_malloc(12672LL * v61, "target_if_cp_stats_extract_pdev_stats", 422);
                *((_QWORD *)v26 + 1) = v63;
                if ( !v63 )
                  goto LABEL_101;
                v64 = _qdf_mem_malloc(0x118u, "target_if_cp_stats_extract_pdev_stats", 426);
                if ( !v64 )
                {
                  v37 = 2;
                  qdf_trace_msg(
                    0x62u,
                    2u,
                    "%s: malloc failed for pdev_stats",
                    v65,
                    v66,
                    v67,
                    v68,
                    v69,
                    v70,
                    v71,
                    v72,
                    "target_if_cp_stats_extract_pdev_stats");
                  goto LABEL_23;
                }
                v73 = (int *)v64;
                if ( *v26 )
                {
                  v74 = 0;
                  v75 = 0;
                  while ( 1 )
                  {
                    pdev_stats = wmi_extract_pdev_stats(v24);
                    if ( pdev_stats )
                      break;
                    *(_DWORD *)(*((_QWORD *)v26 + 1) + v74) = (unsigned int)v73[6] >> 1;
                    v85 = *((_QWORD *)v26 + 1);
                    if ( *(_DWORD *)(v85 + v74) == 63 )
                    {
                      *(_DWORD *)(v85 + v74) = 0;
                      v85 = *((_QWORD *)v26 + 1);
                    }
                    *(_DWORD *)(v85 + v74 + 4) = v73[69];
                    *(_DWORD *)(*((_QWORD *)v26 + 1) + v74 + 8) = v73[3];
                    *(_DWORD *)(*((_QWORD *)v26 + 1) + v74 + 16) = v73[1];
                    *(_DWORD *)(*((_QWORD *)v26 + 1) + v74 + 12) = v73[4];
                    if ( v62 && *v62 )
                    {
                      v86 = *(_QWORD *)(*v62 + 8LL);
                      if ( v86 )
                      {
                        v87 = *(_DWORD **)(v86 + 96);
                        if ( v87 )
                        {
                          v88 = *v73;
                          *(_QWORD *)((char *)v157 + 2) = 0;
                          *(_QWORD *)((char *)&v157[1] + 2) = 0;
                          LOWORD(v157[0]) = v88;
                          v157[2] = 0;
                          if ( *(v87 - 1) != 1785247490 )
                            __break(0x8228u);
                          ((void (__fastcall *)(_QWORD *, _QWORD, __int64, _QWORD *))v87)(v62, 0, 15, v157);
                        }
                      }
                    }
                    else
                    {
                      qdf_trace_msg(
                        0x89u,
                        8u,
                        "%s: Invalid Instance:",
                        v77,
                        v78,
                        v79,
                        v80,
                        v81,
                        v82,
                        v83,
                        v84,
                        "cdp_txrx_set_pdev_param");
                    }
                    ++v75;
                    v74 += 12672;
                    if ( v75 >= *v26 )
                      goto LABEL_46;
                  }
                  v37 = pdev_stats;
                  qdf_trace_msg(
                    0x62u,
                    2u,
                    "%s: wmi_extract_pdev_stats failed",
                    v77,
                    v78,
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    v84,
                    "target_if_cp_stats_extract_pdev_stats");
                  _qdf_mem_free((__int64)v73);
                  goto LABEL_23;
                }
LABEL_46:
                _qdf_mem_free((__int64)v73);
              }
              v158 = 0;
              memset(v157, 0, sizeof(v157));
              if ( (_DWORD)v143 )
              {
                v89 = _qdf_mem_malloc(88LL * (unsigned int)v143, "target_if_cp_stats_extract_peer_stats", 618);
                *((_QWORD *)v26 + 5) = v89;
                if ( !v89 )
                  goto LABEL_83;
                v26[8] = v143;
                v90 = wmi_service_enabled(v24, 0xACu, v28, v29, v30, v31, v32, v33, v34, v35);
                if ( v26[8] )
                {
                  v91 = v90;
                  v92 = 0;
                  v93 = 8;
                  do
                  {
                    if ( (unsigned int)wmi_extract_peer_stats(v24) )
                    {
                      qdf_trace_msg(
                        0x62u,
                        2u,
                        "%s: wmi_extract_peer_stats failed",
                        v53,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        "target_if_cp_stats_extract_peer_stats");
                    }
                    else
                    {
                      *(_DWORD *)(*((_QWORD *)v26 + 5) + v93 + 1) = v157[0];
                      *(_WORD *)(*((_QWORD *)v26 + 5) + v93 + 5) = WORD2(v157[0]);
                      *(_QWORD *)(*((_QWORD *)v26 + 5) + v93 - 8) = v157[2];
                      v94 = v157[1];
                      if ( (v91 & 1) == 0 )
                        v94 = LOBYTE(v157[1]) - 96;
                      *(_BYTE *)(*((_QWORD *)v26 + 5) + v93) = v94;
                    }
                    ++v92;
                    v93 += 88;
                  }
                  while ( v92 < v26[8] );
                }
              }
              v155 = 0;
              v156 = 0;
              v153 = 0;
              v154 = 0;
              v151 = 0;
              v152 = 0;
              v150 = 0;
              v95 = _cds_get_context(
                      71,
                      (__int64)"target_if_cp_stats_extract_peer_extd_stats",
                      v53,
                      v54,
                      v55,
                      v56,
                      v57,
                      v58,
                      v59,
                      v60);
              if ( HIDWORD(v143) )
              {
                v96 = v95;
                v97 = _qdf_mem_malloc(32LL * HIDWORD(v143), "target_if_cp_stats_extract_peer_extd_stats", 559);
                *((_QWORD *)v26 + 9) = v97;
                if ( v97 )
                {
                  v98 = HIDWORD(v143);
                  v26[16] = HIDWORD(v143);
                  if ( v98 )
                  {
                    v99 = 0;
                    v100 = 0;
                    do
                    {
                      if ( (unsigned int)wmi_extract_peer_extd_stats(v24) )
                      {
                        qdf_trace_msg(
                          0x62u,
                          2u,
                          "%s: wmi_extract_peer_extd_stats failed",
                          v101,
                          v102,
                          v103,
                          v104,
                          v105,
                          v106,
                          v107,
                          v108,
                          "target_if_cp_stats_extract_peer_extd_stats");
                      }
                      else
                      {
                        *(_DWORD *)(*((_QWORD *)v26 + 9) + v99) = v150;
                        *(_WORD *)(*((_QWORD *)v26 + 9) + v99 + 4) = WORD2(v150);
                        *(_DWORD *)(*((_QWORD *)v26 + 9) + v99 + 28) = v156;
                        *(_DWORD *)(*((_QWORD *)v26 + 9) + v99 + 28) &= (*(int *)(*((_QWORD *)v26 + 9) + v99 + 28) >> 31)
                                                                      & 0x7FFFFFFF;
                        v109 = _qdf_mem_malloc(0x11C0u, "target_if_cp_stats_extract_peer_extd_stats", 585);
                        if ( v109 )
                        {
                          v118 = v109;
                          if ( v96 && *v96 )
                          {
                            v119 = *(_QWORD *)(*v96 + 32LL);
                            if ( v119 )
                            {
                              v120 = *(_DWORD **)(v119 + 144);
                              if ( v120 )
                              {
                                v121 = *((_QWORD *)v26 + 9) + v99;
                                if ( *(v120 - 1) != -1642106733 )
                                  __break(0x8228u);
                                if ( !((unsigned int (__fastcall *)(_QWORD *, __int64, __int64, __int64))v120)(
                                        v96,
                                        255,
                                        v121,
                                        v109) )
                                  *(_DWORD *)(*((_QWORD *)v26 + 9) + v99 + 28) = *(_DWORD *)(v118 + 2976)
                                                                               + *(_DWORD *)(v118 + 2960);
                              }
                            }
                          }
                          else
                          {
                            qdf_trace_msg(
                              0x89u,
                              8u,
                              "%s: Invalid Instance",
                              v110,
                              v111,
                              v112,
                              v113,
                              v114,
                              v115,
                              v116,
                              v117,
                              "cdp_host_get_peer_stats");
                          }
                          _qdf_mem_free(v118);
                        }
                      }
                      ++v100;
                      v99 += 32;
                    }
                    while ( v100 < v26[16] );
                  }
                }
              }
              v122 = HIDWORD(v146);
              v26[12] = HIDWORD(v146);
              if ( !(_DWORD)v122 )
                goto LABEL_88;
              v123 = _qdf_mem_malloc(24 * v122, "target_if_cp_stats_extract_peer_stats", 652);
              *((_QWORD *)v26 + 7) = v123;
              if ( v123 )
              {
                v124 = _qdf_mem_malloc(24LL * v26[12], "target_if_cp_stats_extract_peer_stats", 657);
                if ( v124 )
                {
                  v125 = v124;
                  if ( (unsigned int)wmi_extract_peer_adv_stats(v24, a2, v124) )
                  {
                    qdf_trace_msg(
                      0x62u,
                      2u,
                      "%s: wmi_extract_peer_stats failed",
                      v126,
                      v127,
                      v128,
                      v129,
                      v130,
                      v131,
                      v132,
                      v133,
                      "target_if_cp_stats_extract_peer_stats");
                    _qdf_mem_free(v125);
                    _qdf_mem_free(*((_QWORD *)v26 + 7));
                    *((_QWORD *)v26 + 7) = 0;
                  }
                  else
                  {
                    if ( v26[12] )
                    {
                      v134 = 0;
                      v135 = 0;
                      do
                      {
                        v136 = v125 + v134;
                        qdf_mem_copy((void *)(*((_QWORD *)v26 + 7) + v134), (const void *)(v125 + v134), 6u);
                        ++v135;
                        *(_DWORD *)(*((_QWORD *)v26 + 7) + v134 + 8) = *(_DWORD *)(v125 + v134 + 8);
                        *(_QWORD *)(*((_QWORD *)v26 + 7) + v134 + 16) = *(_QWORD *)(v125 + v134 + 16);
                        v137 = *((_QWORD *)v26 + 7) + v134;
                        v134 += 24;
                        *(_DWORD *)(v137 + 12) = *(_DWORD *)(v136 + 12);
                      }
                      while ( v135 < v26[12] );
                    }
                    _qdf_mem_free(v125);
                  }
LABEL_88:
                  v157[0] = 0;
                  if ( (unsigned int)wmi_extract_cca_stats(v24) )
                  {
LABEL_91:
                    v37 = target_if_cp_stats_extract_vdev_summary_stats(v24, &v141, v26, a2, a3);
                    if ( !v37 )
                    {
                      v37 = target_if_cp_stats_extract_vdev_chain_rssi_stats(v24, &v141, v26, a2);
                      if ( !v37 )
                      {
                        v37 = target_if_cp_stats_extract_mib_stats(v24, &v141, v26, a2);
                        if ( !v37 )
                        {
                          v37 = target_if_cp_stats_extract_pmf_bcn_protect_stats(v24, &v141, v26, a2);
                          if ( !v37 )
                          {
                            v37 = target_if_cp_stats_extract_pdev_extd_stats(v24, &v141, v26, a2);
                            if ( !v37 )
                            {
                              v37 = target_if_cp_stats_extract_vdev_extd_stats(v24, &v141, v26, a2);
                              if ( !v37 )
                              {
                                v37 = target_if_extract_bcn_rssi_history(v24, &v141, v26, a2);
                                if ( !v37 )
                                {
                                  v139 = *(__int64 (__fastcall **)(__int64, unsigned int *))(v22 + 176);
                                  if ( *((_DWORD *)v139 - 1) != -165074511 )
                                    __break(0x8228u);
                                  v37 = v139(v140, v26);
                                  goto LABEL_25;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
LABEL_23:
                    v40 = jiffies;
                    if ( target_if_mc_cp_stats_stats_event_handler___last_ticks - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x62u,
                        2u,
                        "%s: extract event failed",
                        v28,
                        v29,
                        v30,
                        v31,
                        v32,
                        v33,
                        v34,
                        v35,
                        "target_if_mc_cp_stats_stats_event_handler");
                      target_if_mc_cp_stats_stats_event_handler___last_ticks = v40;
                    }
LABEL_25:
                    target_if_cp_stats_free_stats_event(v26);
                    _qdf_mem_free((__int64)v26);
                    result = qdf_status_to_os_return(v37);
                    goto LABEL_20;
                  }
                  v138 = (_BYTE *)_qdf_mem_malloc(8u, "target_if_cp_stats_extract_cca_stats", 696);
                  *((_QWORD *)v26 + 10) = v138;
                  if ( v138 )
                  {
                    *v138 = v157[0];
                    *(_DWORD *)(*((_QWORD *)v26 + 10) + 4LL) = HIDWORD(v157[0]);
                    goto LABEL_91;
                  }
LABEL_101:
                  v37 = 2;
                  goto LABEL_23;
                }
                _qdf_mem_free(*((_QWORD *)v26 + 7));
              }
LABEL_83:
              v37 = 2;
              goto LABEL_23;
            }
            v38 = "%s: ";
          }
          else
          {
            v38 = "%s: wmi_handle is null";
          }
          goto LABEL_18;
        }
      }
      else
      {
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: rx_ops is NULL",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "target_if_cp_stats_get_rx_ops");
      }
      v38 = "%s: callback not registered";
    }
    else
    {
      v38 = "%s: null psoc";
    }
LABEL_18:
    qdf_trace_msg(0x62u, 2u, v38, v14, v15, v16, v17, v18, v19, v20, v21, "target_if_mc_cp_stats_stats_event_handler");
    goto LABEL_19;
  }
  qdf_trace_msg(
    0x62u,
    2u,
    "%s: scn: 0x%pK, data: 0x%pK",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "target_if_mc_cp_stats_stats_event_handler",
    a1,
    a2);
LABEL_19:
  result = 4294967274LL;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
