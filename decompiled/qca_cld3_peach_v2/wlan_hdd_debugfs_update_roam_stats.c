__int64 __fastcall wlan_hdd_debugfs_update_roam_stats(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x20
  __int64 v26; // x19
  __int64 v27; // x21
  int v28; // w0
  const char *v29; // x2
  unsigned int v30; // w1
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x23
  __int64 v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  const char *v66; // x2
  unsigned __int64 v67; // x22
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  int v76; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x26
  int v86; // w23
  int v87; // w0
  _DWORD *v89; // x24
  unsigned int v90; // w25
  void *v91; // x0
  int v92; // w0
  const char *v93; // x3
  unsigned __int64 v94; // x24
  unsigned int v95; // w8
  int v96; // w0
  __int64 v97; // x25
  __int64 v98; // x26
  const char *v99; // x3
  unsigned int v100; // w8
  unsigned int v101; // w0
  __int64 v102; // x23
  unsigned int v103; // w8
  unsigned int v104; // w22
  int v105; // w0
  __int64 v106; // x25
  __int64 v107; // x28
  int v108; // w0
  __int64 v109; // x27
  int v110; // w0
  int v111; // w0
  __int64 v112; // x1
  int v113; // w3
  int v114; // w4
  int v115; // w5
  int v116; // w6
  int v117; // w3
  int v118; // w4
  int v119; // w5
  int v120; // w6
  int v121; // w7
  int v122; // w8
  int v123; // w9
  int v124; // w10
  int v125; // w0
  int v126; // w0
  int v127; // w0
  int v128; // w3
  int v129; // w4
  int v130; // w5
  int v131; // w6
  int v132; // w0
  int v133; // w3
  int v134; // w4
  int v135; // w5
  int v136; // w6
  int v137; // w0
  int v138; // w3
  int v139; // w4
  int v140; // w5
  int v141; // w6
  int v142; // w0
  int v143; // w3
  int v144; // w4
  int v145; // w5
  int v146; // w6
  int v147; // w0
  unsigned __int64 v148; // [xsp+20h] [xbp-20h]
  unsigned __int64 v149; // [xsp+28h] [xbp-18h]
  _DWORD *v150; // [xsp+30h] [xbp-10h]
  int v151; // [xsp+3Ch] [xbp-4h]

  qdf_trace_msg(0x33u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_debugfs_update_roam_stats");
  v16 = wlan_hdd_current_time_info_debugfs(a3, a4);
  v25 = a4 - v16;
  if ( a4 <= v16 )
  {
    v29 = "%s: No sufficient buf_avail_len";
    v30 = 2;
LABEL_21:
    qdf_trace_msg(0x33u, v30, v29, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_debugfs_update_roam_stats");
    return a4;
  }
  v26 = v16;
  v27 = a3 + v16;
  if ( !*(_DWORD *)(a2 + 40) )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v17, v18, v19, v20, v21, v22, v23, v24, "hdd_get_roam_scan_stats");
    if ( !wlan_hdd_validate_modules_state(a1, v31, v32, v33, v34, v35, v36, v37, v38) )
      goto LABEL_19;
    v47 = osif_request_alloc(&hdd_get_roam_scan_stats_params);
    if ( !v47 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Request allocation failure",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "hdd_get_roam_scan_stats");
      goto LABEL_19;
    }
    v56 = v47;
    v57 = osif_request_cookie(v47);
    if ( (unsigned int)sme_get_roam_scan_stats(
                         *(_QWORD *)(a1 + 16),
                         (__int64)hdd_roam_scan_stats_cb,
                         v57,
                         *(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL)) )
    {
      v66 = "%s: roam scan stats request failed";
    }
    else if ( (unsigned int)osif_request_wait_for_response(v56) )
    {
      v66 = "%s: roam scan stats response time out";
    }
    else
    {
      v89 = *(_DWORD **)osif_request_priv(v56);
      if ( v89 )
      {
        v90 = 328 * *v89 + 8;
        v91 = (void *)_qdf_mem_malloc(v90, "hdd_get_roam_scan_stats", 165);
        v67 = (unsigned __int64)v91;
        if ( v91 )
          qdf_mem_copy(v91, v89, v90);
LABEL_15:
        osif_request_put(v56);
        qdf_trace_msg(0x33u, 8u, "%s: exit", v68, v69, v70, v71, v72, v73, v74, v75, "hdd_get_roam_scan_stats");
        if ( v67 )
        {
          v77 = scnprintf(v27, v25, "\n\nStats of last %u roam scans\n", *(_DWORD *)v67);
          if ( v76 < 1 )
          {
            v85 = 0;
          }
          else
          {
            v85 = (unsigned int)v76;
            if ( *(_DWORD *)v67 )
            {
              v86 = 0;
              v150 = (_DWORD *)v67;
              v149 = v67 + 8;
              v148 = v67 + 24;
              while ( v25 > v85 )
              {
                v77 = scnprintf(v27 + v85, v25 - v85, "\nRoam scan[%u] details\n", v86);
                if ( v92 < 1 )
                  goto LABEL_105;
                v85 += (unsigned int)v92;
                if ( v25 <= v85 )
                  break;
                v93 = "UNKNOWN";
                v94 = v149 + 328LL * v86;
                v95 = *(_DWORD *)(v94 + 8) - 1;
                if ( v95 <= 9 )
                  v93 = off_B2F4A0[v95];
                v77 = scnprintf(v27 + v85, v25 - v85, "This scan is triggered by \"%s\" scan client\n", v93);
                if ( v96 < 1 )
                  goto LABEL_105;
                v97 = v85 + (unsigned int)v96;
                v98 = v25 - v97;
                if ( v25 <= v97 )
                  break;
                v99 = "UNKNOWN REASON";
                v100 = *(_DWORD *)(v94 + 316) - 1;
                if ( v100 <= 0xA )
                  v99 = off_B2F4F0[v100];
                v151 = v86;
                v77 = scnprintf(v27 + v97, v25 - v97, "Trigger reason is %s\n", v99);
                if ( (int)v101 < 1 )
                {
                  v102 = 0;
                }
                else
                {
                  v102 = v101;
                  v103 = *(_DWORD *)(v94 + 316) - 1;
                  if ( v103 <= 6 && ((0x5Du >> v103) & 1) != 0 )
                  {
                    if ( v98 <= v101 )
                    {
                      qdf_trace_msg(
                        0x33u,
                        2u,
                        "%s: No sufficient buf_avail_len",
                        v77,
                        v78,
                        v79,
                        v80,
                        v81,
                        v82,
                        v83,
                        v84,
                        "hdd_roam_scan_trigger");
                      v102 = v25 - v97;
                    }
                    else
                    {
                      v104 = v101;
                      v77 = scnprintf(
                              v27 + v97 + v101,
                              v98 - v101,
                              "Trigger value is: %u %s\n",
                              *(_DWORD *)(v94 + 320),
                              off_B2F548[v103]);
                      if ( v105 >= 1 )
                        v102 = v105 + v104;
                    }
                  }
                }
                v106 = v102 + v97;
                v67 = (unsigned __int64)v150;
                v107 = v25 - v106;
                if ( v25 <= v106 )
                  break;
                v77 = scnprintf(
                        v27 + v106,
                        v25 - v106,
                        "Num of scan channels: %u\nscan channel list:",
                        *(_DWORD *)(v94 + 12));
                if ( v108 < 1 )
                {
                  v109 = 0;
                }
                else
                {
                  v109 = (unsigned int)v108;
                  if ( *(_DWORD *)(v94 + 12) )
                  {
                    v67 = 0;
                    while ( v107 > v109 )
                    {
                      if ( v67 == 50 )
                        goto LABEL_103;
                      v77 = scnprintf(v27 + v106 + v109, v107 - v109, "%u ", *(_DWORD *)(v148 + 328LL * v151 + 4 * v67));
                      if ( v110 >= 1 )
                      {
                        ++v67;
                        v109 += (unsigned int)v110;
                        if ( v67 < *(unsigned int *)(v94 + 12) )
                          continue;
                      }
                      goto LABEL_57;
                    }
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: No sufficient buf_avail_len",
                      v77,
                      v78,
                      v79,
                      v80,
                      v81,
                      v82,
                      v83,
                      v84,
                      "hdd_roam_scan_chan");
                    v109 = v25 - v106;
                  }
                }
LABEL_57:
                v85 = v109 + v106;
                v67 = (unsigned __int64)v150;
                if ( v25 <= v109 + v106 )
                  break;
                v77 = scnprintf(v27 + v85, v25 - (v109 + v106), "\nRoam Scan time: 0x%llx\n", *(_QWORD *)v94);
                if ( v111 < 1 )
                  goto LABEL_105;
                v85 += (unsigned int)v111;
                v112 = v25 - v85;
                if ( v25 <= v85 )
                  break;
                if ( *(_DWORD *)(v94 + 216) )
                {
                  if ( v94 == -220 )
                  {
                    v115 = 0;
                    v113 = 0;
                    v114 = 0;
                    v116 = 0;
                  }
                  else
                  {
                    v113 = *(unsigned __int8 *)(v94 + 220);
                    v114 = *(unsigned __int8 *)(v94 + 221);
                    v115 = *(unsigned __int8 *)(v94 + 222);
                    v116 = *(unsigned __int8 *)(v94 + 225);
                  }
                  if ( v94 == -226 )
                  {
                    v123 = 0;
                    v121 = 0;
                    v122 = 0;
                    v124 = 0;
                  }
                  else
                  {
                    v121 = *(unsigned __int8 *)(v94 + 226);
                    v122 = *(unsigned __int8 *)(v94 + 227);
                    v123 = *(unsigned __int8 *)(v94 + 228);
                    v124 = *(unsigned __int8 *)(v94 + 231);
                  }
                  v77 = scnprintf(
                          v27 + v85,
                          v112,
                          "\nSTA roamed from %02x:%02x:%02x:**:**:%02x to %02x:%02x:%02x:**:**:%02x\n",
                          v113,
                          v114,
                          v115,
                          v116,
                          v121,
                          v122,
                          v123,
                          v124);
                }
                else
                {
                  if ( v94 == -220 )
                  {
                    v119 = 0;
                    v117 = 0;
                    v118 = 0;
                    v120 = 0;
                  }
                  else
                  {
                    v117 = *(unsigned __int8 *)(v94 + 220);
                    v118 = *(unsigned __int8 *)(v94 + 221);
                    v119 = *(unsigned __int8 *)(v94 + 222);
                    v120 = *(unsigned __int8 *)(v94 + 225);
                  }
                  v77 = scnprintf(
                          v27 + v85,
                          v112,
                          "\nSTA is connected to %02x:%02x:%02x:**:**:%02x before and after scan, not roamed\n",
                          v117,
                          v118,
                          v119,
                          v120);
                }
                if ( v125 < 1 )
                  goto LABEL_105;
                v85 += (unsigned int)v125;
                if ( v25 <= v85 )
                  break;
                v77 = scnprintf(v27 + v85, v25 - v85, "Roam candidate details\n", v77);
                if ( v126 < 1 )
                  goto LABEL_105;
                v85 += (unsigned int)v126;
                if ( v25 <= v85 )
                  break;
                v77 = scnprintf(v27 + v85, v25 - v85, "      BSSID     FREQ   SCORE  RSSI\n", v77);
                if ( v127 < 1 )
                  goto LABEL_105;
                v85 += (unsigned int)v127;
                if ( *(_DWORD *)(v94 + 232) )
                {
                  if ( v25 <= v85 )
                    break;
                  if ( v94 == -248 )
                  {
                    v130 = 0;
                    v128 = 0;
                    v129 = 0;
                    v131 = 0;
                  }
                  else
                  {
                    v128 = *(unsigned __int8 *)(v94 + 248);
                    v129 = *(unsigned __int8 *)(v94 + 249);
                    v130 = *(unsigned __int8 *)(v94 + 250);
                    v131 = *(unsigned __int8 *)(v94 + 253);
                  }
                  v77 = scnprintf(
                          v27 + v85,
                          v25 - v85,
                          "%02x:%02x:%02x:**:**:%02x %4u  %3u   %3u\n",
                          v128,
                          v129,
                          v130,
                          v131,
                          *(_DWORD *)(v94 + 244),
                          *(_DWORD *)(v94 + 236),
                          *(_DWORD *)(v94 + 240));
                  if ( v132 < 1 )
                    goto LABEL_105;
                  v85 += (unsigned int)v132;
                  if ( *(_DWORD *)(v94 + 232) >= 2u )
                  {
                    if ( v25 <= v85 )
                      break;
                    if ( v94 == -268 )
                    {
                      v135 = 0;
                      v133 = 0;
                      v134 = 0;
                      v136 = 0;
                    }
                    else
                    {
                      v133 = *(unsigned __int8 *)(v94 + 268);
                      v134 = *(unsigned __int8 *)(v94 + 269);
                      v135 = *(unsigned __int8 *)(v94 + 270);
                      v136 = *(unsigned __int8 *)(v94 + 273);
                    }
                    v77 = scnprintf(
                            v27 + v85,
                            v25 - v85,
                            "%02x:%02x:%02x:**:**:%02x %4u  %3u   %3u\n",
                            v133,
                            v134,
                            v135,
                            v136,
                            *(_DWORD *)(v94 + 264),
                            *(_DWORD *)(v94 + 256),
                            *(_DWORD *)(v94 + 260));
                    if ( v137 < 1 )
                      goto LABEL_105;
                    v85 += (unsigned int)v137;
                    if ( *(_DWORD *)(v94 + 232) >= 3u )
                    {
                      if ( v25 <= v85 )
                        break;
                      if ( v94 == -288 )
                      {
                        v140 = 0;
                        v138 = 0;
                        v139 = 0;
                        v141 = 0;
                      }
                      else
                      {
                        v138 = *(unsigned __int8 *)(v94 + 288);
                        v139 = *(unsigned __int8 *)(v94 + 289);
                        v140 = *(unsigned __int8 *)(v94 + 290);
                        v141 = *(unsigned __int8 *)(v94 + 293);
                      }
                      v77 = scnprintf(
                              v27 + v85,
                              v25 - v85,
                              "%02x:%02x:%02x:**:**:%02x %4u  %3u   %3u\n",
                              v138,
                              v139,
                              v140,
                              v141,
                              *(_DWORD *)(v94 + 284),
                              *(_DWORD *)(v94 + 276),
                              *(_DWORD *)(v94 + 280));
                      if ( v142 < 1 )
                        goto LABEL_105;
                      v85 += (unsigned int)v142;
                      if ( *(_DWORD *)(v94 + 232) >= 4u )
                      {
                        if ( v25 <= v85 )
                          break;
                        if ( v94 == -308 )
                        {
                          v145 = 0;
                          v143 = 0;
                          v144 = 0;
                          v146 = 0;
                        }
                        else
                        {
                          v143 = *(unsigned __int8 *)(v94 + 308);
                          v144 = *(unsigned __int8 *)(v94 + 309);
                          v145 = *(unsigned __int8 *)(v94 + 310);
                          v146 = *(unsigned __int8 *)(v94 + 313);
                        }
                        v77 = scnprintf(
                                v27 + v85,
                                v25 - v85,
                                "%02x:%02x:%02x:**:**:%02x %4u  %3u   %3u\n",
                                v143,
                                v144,
                                v145,
                                v146,
                                *(_DWORD *)(v94 + 304),
                                *(_DWORD *)(v94 + 296),
                                *(_DWORD *)(v94 + 300));
                        if ( v147 < 1 )
                          goto LABEL_105;
                        if ( *(_DWORD *)(v94 + 232) > 4u )
                        {
LABEL_103:
                          __break(0x5512u);
                          break;
                        }
                        v85 += (unsigned int)v147;
                      }
                    }
                  }
                }
                v86 = v151 + 1;
                if ( (unsigned int)(v151 + 1) >= *v150 )
                  goto LABEL_105;
              }
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: No sufficient buf_avail_len",
                v77,
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                "wlan_hdd_update_roam_stats");
              v85 = v25;
            }
          }
LABEL_105:
          _qdf_mem_free(v67);
          goto LABEL_20;
        }
LABEL_19:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Couldn't get roam stats",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "wlan_hdd_update_roam_stats");
        v17 = scnprintf(v27, v25, "Failed to fetch roam stats\n");
        v85 = v87 & (unsigned int)~(v87 >> 31);
LABEL_20:
        a4 = v85 + v26;
        v29 = "%s: exit";
        v30 = 8;
        goto LABEL_21;
      }
      v66 = "%s: Failure of roam scan stats response retrieval";
    }
    qdf_trace_msg(0x33u, 2u, v66, v58, v59, v60, v61, v62, v63, v64, v65, "hdd_get_roam_scan_stats");
    v67 = 0;
    goto LABEL_15;
  }
  scnprintf(a3 + v16, v25, "Interface is not in STA Mode\n");
  if ( v28 < 1 )
    return v26;
  else
    return v26 + (unsigned int)v28;
}
