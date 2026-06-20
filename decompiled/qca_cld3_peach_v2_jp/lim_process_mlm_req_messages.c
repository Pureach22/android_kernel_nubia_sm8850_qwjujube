void __fastcall lim_process_mlm_req_messages(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x23
  unsigned int v12; // w8
  unsigned int v13; // w21
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  __int64 v33; // x8
  int v34; // w22
  __int64 v35; // x0
  __int64 v36; // x21
  __int16 v37; // w8
  __int64 v38; // x8
  unsigned __int8 *v39; // x20
  __int64 v40; // x1
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x21
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v60; // x0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x21
  unsigned __int8 v70; // w8
  int v71; // w9
  unsigned int v72; // w2
  __int64 pre_auth_node_from_index; // x0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x20
  __int64 session_by_bssid; // x0
  __int64 v84; // x21
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x4
  __int64 v94; // x5
  __int64 v95; // x6
  __int64 v96; // x7
  char v97; // w8
  unsigned int v98; // w20
  __int64 session_by_session_id; // x0
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  __int64 v108; // x0
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 v117; // x20
  const char *v118; // x2
  const char *v119; // x3
  __int64 v120; // x22
  unsigned int v121; // w20
  __int64 v122; // x0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  unsigned __int8 *v131; // x9
  __int64 v132; // x21
  __int64 v133; // x7
  int v134; // w8
  int v135; // w10
  int v136; // w11
  __int64 v137; // x0
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  __int64 v146; // x5
  __int64 v147; // x21
  int v148; // w8
  const char *v149; // x2
  const char *v150; // x3
  __int64 v151; // x0
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  __int64 v160; // x22
  unsigned int v161; // w8
  int v162; // w9
  __int16 v163; // w10
  int v164; // w8
  __int64 v165; // x4
  const char *v166; // x2
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  int v175; // w8
  __int64 v176; // x8
  __int64 hash_entry; // x22
  __int64 v178; // x0
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  __int64 v187; // x22
  int v188; // w8
  unsigned __int8 *v189; // x8
  __int64 v190; // x4
  __int64 v191; // x5
  __int64 v192; // x6
  __int64 v193; // x7
  int v194; // w8
  __int64 v195; // x0
  int v196; // w8
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  __int64 sae_auth_retry; // x0
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  __int64 v214; // x21
  __int64 v215; // x22
  int v216; // w23
  unsigned __int8 *v217; // x0
  unsigned __int8 *v218; // x21
  double v219; // d0
  double v220; // d1
  double v221; // d2
  double v222; // d3
  double v223; // d4
  double v224; // d5
  double v225; // d6
  double v226; // d7
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  int v235; // w8
  int v236; // w9
  __int16 v237; // w2
  double v238; // d0
  double v239; // d1
  double v240; // d2
  double v241; // d3
  double v242; // d4
  double v243; // d5
  double v244; // d6
  double v245; // d7
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  __int64 v254; // x0
  __int64 v255; // x22
  __int16 v256; // w2
  __int64 v257; // x0
  __int64 v258; // x2
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  __int16 v283; // [xsp+2Ch] [xbp-44h] BYREF
  int v284; // [xsp+30h] [xbp-40h] BYREF
  unsigned __int16 v285; // [xsp+34h] [xbp-3Ch]
  __int64 v286; // [xsp+38h] [xbp-38h] BYREF
  unsigned __int8 *v287; // [xsp+40h] [xbp-30h]
  __int64 v288; // [xsp+48h] [xbp-28h]
  __int64 v289; // [xsp+50h] [xbp-20h]
  __int64 v290; // [xsp+58h] [xbp-18h]
  __int64 v291; // [xsp+60h] [xbp-10h]
  __int64 v292; // [xsp+68h] [xbp-8h]

  v11 = a1 + 20480;
  v292 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a2;
  if ( v12 > 0x13D4 )
  {
    if ( *a2 > 0x13F7u )
    {
      if ( *a2 > 0x13FDu )
      {
        if ( v12 == 5118 )
        {
          lim_process_sae_auth_timeout(a1);
        }
        else if ( v12 == 5120 )
        {
          v98 = *(unsigned __int8 *)(a1 + 3770);
          session_by_session_id = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a1 + 3770));
          if ( session_by_session_id )
          {
            if ( *(_DWORD *)(session_by_session_id + 7036) == 2 )
              lim_handle_heart_beat_failure(a1, session_by_session_id);
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Session does not exist for given session id %d",
              v100,
              v101,
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              "lim_process_channel_vacate_timeout",
              v98);
          }
        }
        goto LABEL_166;
      }
      if ( v12 != 5112 )
      {
        if ( v12 == 5117 )
        {
          v13 = *(unsigned __int8 *)(a1 + 2978);
          v14 = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a1 + 2978));
          if ( v14 )
          {
            v23 = v14;
            if ( (tx_timer_running(a1 + 808) & 1) != 0 && *(_DWORD *)(v23 + 72) == 5 )
            {
              v32 = *(_DWORD *)(v11 + 1108);
              if ( (unsigned int)(v32 - 2) < 2 )
              {
                v33 = *(_QWORD *)(a1 + 11376);
                if ( v33 )
                {
                  v34 = *(_DWORD *)(v33 + 8);
                  v35 = _qdf_mem_malloc(0x3FFu, "lim_process_auth_retry_timer", 1894);
                  if ( !v35 )
                  {
                    v149 = "%s: malloc failed for auth_frame";
LABEL_146:
                    v150 = "lim_process_auth_retry_timer";
                    goto LABEL_78;
                  }
                  v36 = v35;
                  if ( (*(_BYTE *)(v23 + 10008) & (v34 == 3)) != 0 )
                    v37 = 0;
                  else
                    v37 = (unsigned __int8)v34;
                  *(_DWORD *)(v35 + 2) = 1;
                  *(_WORD *)v35 = v37;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Retry Auth",
                    a3,
                    a4,
                    a5,
                    a6,
                    a7,
                    a8,
                    a9,
                    a10,
                    "lim_process_auth_retry_timer");
                  v38 = *(_QWORD *)(v23 + 9976);
                  if ( v38 && *(_BYTE *)v38 == 1 )
                    ++*(_WORD *)(v38 + 68);
                  lim_send_auth_mgmt_frame(a1, v36, *(_QWORD *)(a1 + 11376), 0, v23);
                  _qdf_mem_free(v36);
                }
LABEL_125:
                lim_deactivate_and_change_timer(a1, 20);
                if ( !(unsigned int)tx_timer_activate((char *)(a1 + 2928)) )
                  goto LABEL_166;
                v149 = "%s: could not activate Auth Retry failure timer";
                goto LABEL_146;
              }
              if ( v32 != 1 )
                goto LABEL_125;
            }
            sae_auth_retry = mlme_get_sae_auth_retry(*(_QWORD *)(v23 + 16), v24, v25, v26, v27, v28, v29, v30, v31);
            if ( sae_auth_retry && *(_QWORD *)(sae_auth_retry + 16) )
            {
              v214 = sae_auth_retry;
              if ( *(_BYTE *)sae_auth_retry )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Retry sae auth for seq num %d vdev id %d",
                  v206,
                  v207,
                  v208,
                  v209,
                  v210,
                  v211,
                  v212,
                  v213,
                  "lim_handle_sae_auth_timeout",
                  *(unsigned __int16 *)(v11 + 1052),
                  *(unsigned __int8 *)(v23 + 10));
                lim_send_frame(a1, *(unsigned __int8 *)(v23 + 10), *(_QWORD *)(v214 + 16), *(unsigned int *)(v214 + 8));
                --*(_BYTE *)v214;
                if ( !(unsigned int)tx_timer_activate((char *)(a1 + 2928)) )
                  goto LABEL_166;
              }
              else if ( !wlan_cm_is_vdev_connecting(
                           *(_QWORD *)(v23 + 16),
                           v206,
                           v207,
                           v208,
                           v209,
                           v210,
                           v211,
                           v212,
                           v213) )
              {
                v215 = *(_QWORD *)(v214 + 16);
                v216 = *(unsigned __int8 *)(v23 + 10);
                v290 = 0;
                v291 = 0;
                v288 = 0;
                v289 = 0;
                v286 = 0;
                v287 = nullptr;
                v217 = (unsigned __int8 *)_qdf_mem_malloc(0x20u, "lim_send_pre_auth_failure", 1794);
                if ( v217 )
                {
                  v218 = v217;
                  *(_DWORD *)v217 = v216;
                  *((_DWORD *)v217 + 1) = 1;
                  qdf_mem_copy(v217 + 8, (const void *)(v215 + 16), 6u);
                  qdf_mem_set(v218 + 14, 0x10u, 0);
                  v287 = v218;
                  LOWORD(v286) = 4267;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Sending pre auth failure for mac_addr %02x:%02x:%02x:**:**:%02x",
                    v219,
                    v220,
                    v221,
                    v222,
                    v223,
                    v224,
                    v225,
                    v226,
                    "lim_send_pre_auth_failure",
                    v218[8],
                    v218[9],
                    v218[10],
                    v218[13]);
                  if ( (unsigned int)scheduler_post_message_debug(
                                       0x35u,
                                       0x36u,
                                       54,
                                       (unsigned __int16 *)&v286,
                                       0x713u,
                                       (__int64)"lim_send_pre_auth_failure") )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: Sending preauth status failed",
                      v227,
                      v228,
                      v229,
                      v230,
                      v231,
                      v232,
                      v233,
                      v234,
                      "lim_send_pre_auth_failure");
                    _qdf_mem_free((__int64)v218);
                  }
                }
              }
              lim_sae_auth_cleanup_retry(a1, *(unsigned __int8 *)(v23 + 10));
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: sae auth frame is not buffered vdev id %d",
                v206,
                v207,
                v208,
                v209,
                v210,
                v211,
                v212,
                v213,
                "lim_handle_sae_auth_timeout",
                *(unsigned __int8 *)(v23 + 10));
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: session does not exist for pe_session_id: %d",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "lim_process_auth_retry_timer",
              v13);
          }
        }
        goto LABEL_166;
      }
      v108 = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(a1 + 2186));
      if ( !v108 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: session does not exist for given SessionId: %d",
          v109,
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          v116,
          "lim_process_periodic_join_probe_req_timer",
          *(unsigned __int8 *)(a1 + 2186));
        goto LABEL_166;
      }
      v117 = v108;
      if ( (tx_timer_running(a1 + 1072) & 1) != 0 && *(_DWORD *)(v117 + 72) == 2 )
      {
        lim_send_probe_req_mgmt_frame(a1, v117, *(_QWORD *)(v117 + 112) + 260LL, *(_QWORD *)(v117 + 112) + 262LL);
        lim_deactivate_and_change_timer(a1, 18);
        if ( !(unsigned int)tx_timer_activate((char *)(a1 + 2136)) )
        {
          ++*(_BYTE *)(v117 + 10074);
          goto LABEL_166;
        }
        v118 = "%s: could not activate Periodic Join req failure timer";
        v119 = "lim_process_periodic_join_probe_req_timer";
        goto LABEL_93;
      }
      goto LABEL_166;
    }
    if ( v12 != 5077 )
    {
      if ( v12 == 5108 )
      {
        ((void (__fastcall *)(__int64))lim_process_rrm_sta_stats_rsp_timeout)(a1);
      }
      else if ( v12 == 5110 )
      {
        lim_send_disassoc_cnf(a1);
      }
      goto LABEL_166;
    }
LABEL_55:
    lim_process_assoc_failure_timeout();
    goto LABEL_166;
  }
  if ( *a2 <= 0x13D1u )
  {
    if ( v12 != 1006 )
    {
      if ( v12 == 1009 )
      {
        v39 = *((unsigned __int8 **)a2 + 1);
        v286 = 0x1000001F4LL;
        if ( v39 )
        {
          v137 = pe_find_session_by_session_id(a1, v39[10]);
          if ( v137 )
          {
            v146 = *(unsigned int *)(v137 + 88);
            v147 = v137;
            v284 = *(_DWORD *)(v137 + 24);
            v285 = *(_WORD *)(v137 + 28);
            if ( (_DWORD)v146 != 1 )
            {
              v148 = *(_DWORD *)(v137 + 72);
              if ( v148 == 9 || v148 == 3 )
              {
                if ( !(unsigned int)qdf_mem_cmp(v39, &v284, 6u) )
                {
                  *(_BYTE *)(a1 + 330) = v39[10];
                  if ( *(_DWORD *)(v147 + 7036) )
                  {
                    v235 = *(_DWORD *)(v147 + 72);
                  }
                  else
                  {
                    v235 = *(_DWORD *)(v147 + 72);
                    if ( (*(_BYTE *)(v147 + 7024) & 0x10) != 0 )
                    {
                      v236 = *(_DWORD *)(v147 + 76);
                      *(_DWORD *)(v147 + 8056) = v235;
                      *(_DWORD *)(v147 + 8052) = v236;
                    }
                  }
                  v237 = *(_WORD *)(v147 + 8);
                  *(_DWORD *)(v147 + 72) = 10;
                  *(_DWORD *)(v147 + 76) = v235;
                  qdf_trace(53, 0, v237, 10);
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: vdev %d Sending Assoc_Req Frame, timeout %d msec",
                    v238,
                    v239,
                    v240,
                    v241,
                    v242,
                    v243,
                    v244,
                    v245,
                    "lim_process_mlm_assoc_req",
                    *(unsigned __int8 *)(v147 + 10),
                    *(unsigned int *)(a1 + 352));
                  lim_send_assoc_req_mgmt_frame(a1, v39, v147);
                  qdf_trace(53, 0xDu, *(_WORD *)(v147 + 8), 5);
                  if ( !(unsigned int)tx_timer_activate((char *)(a1 + 280)) )
                    goto LABEL_166;
                  qdf_trace_msg(
                    0x35u,
                    3u,
                    "%s: SessionId:%d couldn't start Assoc failure timer",
                    v246,
                    v247,
                    v248,
                    v249,
                    v250,
                    v251,
                    v252,
                    v253,
                    "lim_process_mlm_assoc_req",
                    *(unsigned __int16 *)(v147 + 8));
                  goto LABEL_55;
                }
                v146 = *(unsigned int *)(v147 + 88);
              }
            }
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: received unexpected MLM_ASSOC_CNF in state %X for role=%d, MAC addr= %02x:%02x:%02x:**:**:%02x",
              v138,
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              v145,
              "lim_process_mlm_assoc_req",
              *(unsigned int *)(v147 + 72),
              v146,
              *v39,
              v39[1],
              v39[2],
              v39[5]);
            lim_print_mlm_state(a1, 3, *(unsigned int *)(v147 + 72));
            BYTE6(v286) = v39[10];
            _qdf_mem_free((__int64)v39);
            lim_process_mlm_rsp_messages(a1, 1010, &v286);
            goto LABEL_166;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: SessionId:%d Session Does not exist",
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            "lim_process_mlm_assoc_req",
            v39[10]);
          goto LABEL_89;
        }
        v149 = "%s: Buffer is Pointing to NULL";
        v150 = "lim_process_mlm_assoc_req";
      }
      else
      {
        if ( v12 != 1012 )
          goto LABEL_166;
        v39 = *((unsigned __int8 **)a2 + 1);
        if ( v39 )
        {
          v287 = nullptr;
          v288 = 0;
          v40 = v39[12];
          v283 = 0;
          v285 = 0;
          v284 = 0;
          v286 = 0;
          v41 = pe_find_session_by_session_id(a1, v40);
          if ( v41 )
          {
            v50 = v41;
            qdf_mem_copy(&v284, (const void *)(v41 + 24), 6u);
            if ( *(_DWORD *)(v50 + 88) == 2 && (*(_DWORD *)v39 != v284 || *((unsigned __int16 *)v39 + 2) != v285) )
            {
              qdf_trace_msg(
                0x35u,
                3u,
                "%s: received MLM_DISASSOC_REQ with invalid BSS: %02x:%02x:%02x:**:**:%02x",
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                "lim_process_mlm_disassoc_req_ntf",
                *v39,
                v39[1],
                v39[2],
                v39[5]);
              v60 = _qdf_mem_malloc(0x14u, "lim_process_mlm_disassoc_req_ntf", 1115);
              if ( v60 )
              {
                v69 = v60;
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: send disassoc rsp with ret code %d for %02x:%02x:%02x:**:**:%02x",
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  v68,
                  "lim_process_mlm_disassoc_req_ntf",
                  539,
                  *v39,
                  v39[1],
                  v39[2],
                  v39[5]);
                *(_DWORD *)v69 = 1315849;
                v70 = v39[12];
                *(_DWORD *)(v69 + 8) = 539;
                *(_BYTE *)(v69 + 4) = v70;
                v71 = *(_DWORD *)v39;
                *(_WORD *)(v69 + 16) = *((_WORD *)v39 + 2);
                *(_DWORD *)(v69 + 12) = v71;
                lim_send_sme_disassoc_deauth_ntf(a1, 0, v69);
              }
              goto LABEL_89;
            }
            v151 = dph_lookup_hash_entry(v51, v52, v53, v54, v55, v56, v57, v58, a1, v39, &v283, v50 + 360);
            v160 = v151;
            if ( v151 )
            {
              v161 = *(_DWORD *)(v151 + 8);
              if ( v161 <= 0xF && ((1 << v161) & 0xD000) != 0 )
              {
                *(_DWORD *)(v151 + 24) = *((unsigned __int16 *)v39 + 3);
                v162 = (unsigned __int8)send_disassoc_frame;
                v163 = *((_WORD *)v39 + 4);
                *(_DWORD *)(v151 + 8) = 22;
                *(_WORD *)(v151 + 34) = v163;
                if ( v162 == 1 && *((_WORD *)v39 + 3) != 46 )
                {
                  if ( *(_QWORD *)(a1 + 12392) )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: pMlmDisassocReq is not NULL, freeing",
                      v152,
                      v153,
                      v154,
                      v155,
                      v156,
                      v157,
                      v158,
                      v159,
                      "lim_process_mlm_disassoc_req_ntf");
                    _qdf_mem_free(*(_QWORD *)(a1 + 12392));
                  }
                  *(_QWORD *)(a1 + 12392) = v39;
                  *(_DWORD *)(v160 + 8) = 22;
                  lim_send_disassoc_mgmt_frame(a1, *((unsigned __int16 *)v39 + 3), v39, v50, 1);
                  if ( *(_DWORD *)(v50 + 88) == 2 )
                    wma_tx_abort(*(unsigned __int8 *)(v50 + 10));
                  goto LABEL_166;
                }
                send_disassoc_frame = 1;
                if ( (unsigned int)lim_cleanup_rx_path(
                                     a1,
                                     (__int16 *)v151,
                                     v50,
                                     1,
                                     v152,
                                     v153,
                                     v154,
                                     v155,
                                     v156,
                                     v157,
                                     v158,
                                     v159) )
                {
                  v164 = 502;
LABEL_116:
                  HIDWORD(v287) = v164;
                  qdf_mem_copy(&v286, v39, 6u);
                  LODWORD(v288) = *((_DWORD *)v39 + 2);
                  BYTE4(v288) = v39[12];
                  _qdf_mem_free((__int64)v39);
                  lim_process_mlm_rsp_messages(a1, 1013, &v286);
                  goto LABEL_166;
                }
LABEL_89:
                _qdf_mem_free((__int64)v39);
                goto LABEL_166;
              }
            }
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: Invalid MLM_DISASSOC_REQ, Addr= %02x:%02x:%02x:**:**:%02x",
              v152,
              v153,
              v154,
              v155,
              v156,
              v157,
              v158,
              v159,
              "lim_process_mlm_disassoc_req_ntf",
              *v39,
              v39[1],
              v39[2],
              v39[5]);
            if ( !v160 )
            {
LABEL_115:
              v164 = 500;
              goto LABEL_116;
            }
            v165 = *(unsigned int *)(v160 + 8);
            v166 = "%s: Sta MlmState: %d";
          }
          else
          {
            v165 = v39[12];
            v166 = "%s: session does not exist for given sessionId %d";
          }
          qdf_trace_msg(
            0x35u,
            2u,
            v166,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "lim_process_mlm_disassoc_req_ntf",
            v165);
          goto LABEL_115;
        }
        v149 = "%s: Buffer is Pointing to NULL";
        v150 = "lim_process_mlm_disassoc_req";
      }
LABEL_78:
      qdf_trace_msg(0x35u, 2u, v149, a3, a4, a5, a6, a7, a8, a9, a10, v150);
      goto LABEL_166;
    }
    v120 = *((_QWORD *)a2 + 1);
    LODWORD(v288) = 0;
    v286 = 0;
    v287 = nullptr;
    if ( v120 )
    {
      *(_QWORD *)(a1 + 11376) = v120;
      v121 = *(unsigned __int8 *)(v120 + 12);
      v122 = pe_find_session_by_session_id(a1, *(unsigned __int8 *)(v120 + 12));
      if ( !v122 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: SessionId:%d does not exist",
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          "lim_process_mlm_auth_req",
          v121);
        _qdf_mem_free(v120);
        *(_QWORD *)(a1 + 11376) = 0;
        goto LABEL_166;
      }
      v131 = *(unsigned __int8 **)(a1 + 11376);
      v132 = v122;
      if ( v131 )
      {
        v133 = *v131;
        v134 = v131[1];
        v135 = v131[2];
        v136 = v131[5];
      }
      else
      {
        v135 = 0;
        v133 = 0;
        v134 = 0;
        v136 = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev %d Systemrole %d mlmstate %d from: %02x:%02x:%02x:**:**:%02xwith authtype %d",
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        v130,
        "lim_process_mlm_auth_req",
        *(unsigned __int8 *)(v122 + 10),
        *(unsigned int *)(v122 + 88),
        *(unsigned int *)(v122 + 72),
        v133,
        v134,
        v135,
        v136,
        *((_DWORD *)v131 + 2));
      if ( *(_DWORD *)(v132 + 88) != 2
        || (v175 = *(_DWORD *)(v132 + 72), v175 != 14) && v175 != 3
        || (v176 = *(_QWORD *)(a1 + 11376), (*(_BYTE *)v176 & 1) != 0)
        || !(unsigned __int8)lim_is_auth_algo_supported(a1, *(unsigned int *)(v176 + 8), v132) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Auth req not expected is_privacy_enabled %d is_auth_open_system %d auth type %d",
          v167,
          v168,
          v169,
          v170,
          v171,
          v172,
          v173,
          v174,
          "lim_process_mlm_auth_req",
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5436LL),
          *(unsigned __int8 *)(*(_QWORD *)(a1 + 8) + 5438LL),
          *(unsigned int *)(*(_QWORD *)(a1 + 11376) + 8LL));
        v194 = 500;
LABEL_110:
        HIDWORD(v287) = v194;
LABEL_111:
        qdf_mem_copy(&v286, *(const void **)(a1 + 11376), 6u);
        v195 = *(_QWORD *)(a1 + 11376);
        v196 = *(_DWORD *)(v195 + 8);
        BYTE2(v288) = v121;
        LODWORD(v287) = v196;
        _qdf_mem_free(v195);
        *(_QWORD *)(a1 + 11376) = 0;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: SessionId:%d LimPostSme LIM_MLM_AUTH_CNF",
          v197,
          v198,
          v199,
          v200,
          v201,
          v202,
          v203,
          v204,
          "lim_process_mlm_auth_req",
          v121);
        lim_process_mlm_rsp_messages(a1, 1007, &v286);
        goto LABEL_166;
      }
      v284 = *(_DWORD *)(v132 + 24);
      v285 = *(_WORD *)(v132 + 28);
      hash_entry = dph_get_hash_entry(a1, 1u, v132 + 360);
      v178 = lim_search_pre_auth_list(a1, *(_QWORD *)(a1 + 11376));
      if ( *(_DWORD *)(v132 + 88) == 2 && *(_DWORD *)(v132 + 72) == 14 )
      {
        if ( hash_entry )
        {
          if ( *(_DWORD *)(*(_QWORD *)(a1 + 11376) + 8LL) == *(_DWORD *)(hash_entry + 12) )
          {
            v187 = v178;
            v188 = qdf_mem_cmp(*(const void **)(a1 + 11376), &v284, 6u);
            v178 = v187;
            if ( !v188 )
            {
              v189 = *(unsigned __int8 **)(a1 + 11376);
              if ( v189 )
                goto LABEL_108;
              goto LABEL_162;
            }
          }
        }
      }
      if ( v178 )
      {
        v189 = *(unsigned __int8 **)(a1 + 11376);
        if ( *(_DWORD *)(v178 + 16) == *((_DWORD *)v189 + 2) )
        {
          if ( v189 )
          {
LABEL_108:
            v190 = *v189;
            v191 = v189[1];
            v192 = v189[2];
            v193 = v189[5];
LABEL_163:
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Already have pre-auth context with peer: %02x:%02x:%02x:**:**:%02x",
              v179,
              v180,
              v181,
              v182,
              v183,
              v184,
              v185,
              v186,
              "lim_process_mlm_auth_req",
              v190,
              v191,
              v192,
              v193);
            HIDWORD(v287) = 0;
            goto LABEL_111;
          }
LABEL_162:
          v192 = 0;
          v190 = 0;
          v191 = 0;
          v193 = 0;
          goto LABEL_163;
        }
      }
      if ( *(_DWORD *)(a1 + 11404) == *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1692LL) )
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Number of pre-auth reached max limit",
          v179,
          v180,
          v181,
          v182,
          v183,
          v184,
          v185,
          v186,
          "lim_process_mlm_auth_req");
        v194 = 512;
        goto LABEL_110;
      }
      *(_DWORD *)(v132 + 76) = *(_DWORD *)(v132 + 72);
      v254 = _qdf_mem_malloc(0x3FFu, "lim_process_mlm_auth_req", 854);
      if ( v254 )
      {
        v255 = v254;
        if ( *(_DWORD *)(*(_QWORD *)(a1 + 11376) + 8LL) == 3 && (*(_BYTE *)(v132 + 10008) & 1) == 0 )
        {
          if ( (unsigned int)lim_process_mlm_auth_req_sae(a1, v132) )
          {
            HIDWORD(v287) = 500;
            _qdf_mem_free(v255);
            goto LABEL_111;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: lim_process_mlm_auth_req_sae is successful",
            v275,
            v276,
            v277,
            v278,
            v279,
            v280,
            v281,
            v282,
            "lim_process_mlm_auth_req");
          *(_WORD *)(v255 + 4) = 0;
          *(_DWORD *)v255 = 65539;
          host_log_wlan_auth_info(3, 1, 0);
        }
        else
        {
          v256 = *(_WORD *)(v132 + 8);
          *(_DWORD *)(v132 + 72) = 5;
          qdf_trace(53, 0, v256, 5);
          if ( *(_DWORD *)(*(_QWORD *)(a1 + 11376) + 8LL) == 3 && (*(_BYTE *)(v132 + 10008) & 1) != 0 )
            v257 = 0;
          else
            v257 = (unsigned __int8)*(_DWORD *)(*(_QWORD *)(a1 + 11376) + 8LL);
          *(_WORD *)v255 = v257;
          *(_DWORD *)(v255 + 2) = 1;
          host_log_wlan_auth_info(v257, 1, 0);
          v258 = *(_QWORD *)(a1 + 11376);
          *(_DWORD *)(v11 + 1108) = 0;
          lim_send_auth_mgmt_frame(a1, v255, v258, 0, v132);
          *(_BYTE *)(a1 + 858) = v121;
          *(_BYTE *)(a1 + 2978) = v121;
          lim_deactivate_and_change_timer(a1, 20);
          qdf_trace(53, 0xDu, *(_WORD *)(v132 + 8), 3);
          lim_deactivate_and_change_timer(a1, 3);
          if ( (unsigned int)tx_timer_activate((char *)(a1 + 808)) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: could not start Auth failure timer",
              v259,
              v260,
              v261,
              v262,
              v263,
              v264,
              v265,
              v266,
              "lim_process_mlm_auth_req");
            lim_process_auth_failure_timeout(a1);
          }
          else
          {
            qdf_trace(53, 0xDu, *(_WORD *)(v132 + 8), 20);
            if ( (unsigned int)tx_timer_activate((char *)(a1 + 2928)) )
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: could not activate Auth Retry timer",
                v267,
                v268,
                v269,
                v270,
                v271,
                v272,
                v273,
                v274,
                "lim_process_mlm_auth_req");
          }
        }
        _qdf_mem_free(v255);
        goto LABEL_166;
      }
      v149 = "%s: mem alloc failed for auth frame body";
    }
    else
    {
      v149 = "%s: Buffer is Pointing to NULL";
    }
    v150 = "lim_process_mlm_auth_req";
    goto LABEL_78;
  }
  switch ( v12 )
  {
    case 0x13D2u:
      lim_process_join_failure_timeout(a1);
      break;
    case 0x13D3u:
      lim_process_auth_failure_timeout(a1);
      break;
    case 0x13D4u:
      v72 = *((_DWORD *)a2 + 1);
      LOBYTE(v286) = 0;
      pre_auth_node_from_index = lim_get_pre_auth_node_from_index(a3, a4, a5, a6, a7, a8, a9, a10, a1, a1 + 11408, v72);
      if ( pre_auth_node_from_index )
      {
        v82 = pre_auth_node_from_index;
        session_by_bssid = pe_find_session_by_bssid(a1, pre_auth_node_from_index + 8, &v286);
        if ( session_by_bssid )
        {
          v84 = session_by_bssid;
          lim_diag_event_report(a1, 75, session_by_bssid, 0);
          if ( *(_DWORD *)(v84 + 88) == 1 )
          {
            if ( *(_DWORD *)(v82 + 20) == 6 )
            {
              v93 = *(unsigned __int8 *)(v82 + 8);
              v94 = *(unsigned __int8 *)(v82 + 9);
              v95 = *(unsigned __int8 *)(v82 + 10);
              v96 = *(unsigned __int8 *)(v82 + 13);
              v97 = *(_BYTE *)(v82 + 278) & 0xFE;
              *(_DWORD *)(v82 + 20) = 8;
              *(_BYTE *)(v82 + 278) = v97;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: AUTH rsp timedout for MAC address %02x:%02x:%02x:**:**:%02x",
                v85,
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                "lim_process_auth_rsp_timeout",
                v93,
                v94,
                v95,
                v96);
              lim_deactivate_and_change_per_sta_id_timer(a1, 9, *(unsigned __int8 *)(v82 + 24));
              lim_delete_pre_auth_node(a1, v82 + 8);
            }
            else
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: received AUTH rsp timeout in unexpected state for MAC address: %02x:%02x:%02x:**:**:%02x",
                v85,
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                v92,
                "lim_process_auth_rsp_timeout",
                *(unsigned __int8 *)(v82 + 8),
                *(unsigned __int8 *)(v82 + 9),
                *(unsigned __int8 *)(v82 + 10),
                *(unsigned __int8 *)(v82 + 13));
            }
          }
          break;
        }
        v118 = "%s: session does not exist for given BSSID";
      }
      else
      {
        v118 = "%s: Invalid auth node";
      }
      v119 = "lim_process_auth_rsp_timeout";
LABEL_93:
      qdf_trace_msg(0x35u, 3u, v118, v74, v75, v76, v77, v78, v79, v80, v81, v119);
      break;
  }
LABEL_166:
  _ReadStatusReg(SP_EL0);
}
