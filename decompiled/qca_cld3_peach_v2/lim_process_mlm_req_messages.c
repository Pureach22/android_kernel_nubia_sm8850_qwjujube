__int64 __fastcall lim_process_mlm_req_messages(
        __int64 result,
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
  __int64 v10; // x19
  __int64 v11; // x23
  unsigned int v12; // w8
  unsigned int v13; // w21
  __int64 session_by_session_id; // x0
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
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v107; // x0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x20
  const char *v117; // x2
  const char *v118; // x3
  __int64 v119; // x22
  unsigned int v120; // w20
  __int64 v121; // x0
  double v122; // d0
  double v123; // d1
  double v124; // d2
  double v125; // d3
  double v126; // d4
  double v127; // d5
  double v128; // d6
  double v129; // d7
  unsigned __int8 *v130; // x9
  __int64 v131; // x21
  __int64 v132; // x7
  int v133; // w8
  int v134; // w10
  int v135; // w11
  __int64 v136; // x0
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 v145; // x5
  __int64 v146; // x21
  int v147; // w8
  const char *v148; // x2
  const char *v149; // x3
  __int64 v150; // x0
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  __int64 v159; // x22
  unsigned int v160; // w8
  int v161; // w8
  __int16 v162; // w9
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  int v171; // w8
  __int64 v172; // x4
  const char *v173; // x2
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  int v182; // w8
  __int64 v183; // x8
  __int64 hash_entry; // x22
  __int64 v185; // x0
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  __int64 v194; // x22
  int v195; // w8
  unsigned __int8 *v196; // x8
  __int64 v197; // x4
  __int64 v198; // x5
  __int64 v199; // x6
  __int64 v200; // x7
  int v201; // w8
  __int64 v202; // x0
  int v203; // w8
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  __int64 sae_auth_retry; // x0
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  __int64 v221; // x21
  __int64 v222; // x22
  int v223; // w23
  unsigned __int8 *v224; // x0
  unsigned __int8 *v225; // x21
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  double v234; // d0
  double v235; // d1
  double v236; // d2
  double v237; // d3
  double v238; // d4
  double v239; // d5
  double v240; // d6
  double v241; // d7
  int v242; // w8
  int v243; // w9
  __int16 v244; // w2
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  __int64 v261; // x0
  __int64 v262; // x22
  __int16 v263; // w2
  __int64 v264; // x0
  __int64 v265; // x2
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  double v282; // d0
  double v283; // d1
  double v284; // d2
  double v285; // d3
  double v286; // d4
  double v287; // d5
  double v288; // d6
  double v289; // d7
  __int16 v290; // [xsp+2Ch] [xbp-44h] BYREF
  int v291; // [xsp+30h] [xbp-40h] BYREF
  unsigned __int16 v292; // [xsp+34h] [xbp-3Ch]
  __int64 v293; // [xsp+38h] [xbp-38h] BYREF
  unsigned __int8 *v294; // [xsp+40h] [xbp-30h]
  __int64 v295; // [xsp+48h] [xbp-28h]
  __int64 v296; // [xsp+50h] [xbp-20h]
  __int64 v297; // [xsp+58h] [xbp-18h]
  __int64 v298; // [xsp+60h] [xbp-10h]
  __int64 v299; // [xsp+68h] [xbp-8h]

  v10 = result;
  v11 = result + 20480;
  v299 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a2;
  if ( v12 > 0x13D4 )
  {
    if ( *a2 > 0x13F7u )
    {
      if ( *a2 > 0x13FDu )
      {
        if ( v12 == 5118 )
        {
          result = lim_process_sae_auth_timeout(result);
        }
        else if ( v12 == 5120 )
        {
          v98 = *(unsigned __int8 *)(result + 3770);
          result = pe_find_session_by_session_id(result, *(unsigned __int8 *)(result + 3770));
          if ( result )
          {
            if ( *(_DWORD *)(result + 7036) == 2 )
              result = lim_handle_heart_beat_failure(v10, result);
          }
          else
          {
            result = qdf_trace_msg(
                       0x35u,
                       2u,
                       "%s: Session does not exist for given session id %d",
                       v99,
                       v100,
                       v101,
                       v102,
                       v103,
                       v104,
                       v105,
                       v106,
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
          v13 = *(unsigned __int8 *)(result + 2978);
          session_by_session_id = pe_find_session_by_session_id(result, *(unsigned __int8 *)(result + 2978));
          if ( session_by_session_id )
          {
            v23 = session_by_session_id;
            if ( (tx_timer_running(v10 + 808) & 1) != 0 && *(_DWORD *)(v23 + 72) == 5 )
            {
              v32 = *(_DWORD *)(v11 + 1180);
              if ( (unsigned int)(v32 - 2) < 2 )
              {
                v33 = *(_QWORD *)(v10 + 11376);
                if ( v33 )
                {
                  v34 = *(_DWORD *)(v33 + 8);
                  v35 = _qdf_mem_malloc(0x3FFu, "lim_process_auth_retry_timer", 1894);
                  if ( !v35 )
                  {
                    v148 = "%s: malloc failed for auth_frame";
LABEL_146:
                    v149 = "lim_process_auth_retry_timer";
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
                  lim_send_auth_mgmt_frame(v10, v36, *(_QWORD *)(v10 + 11376), 0, v23);
                  _qdf_mem_free(v36);
                }
LABEL_125:
                lim_deactivate_and_change_timer(v10, 20);
                result = tx_timer_activate((char *)(v10 + 2928));
                if ( !(_DWORD)result )
                  goto LABEL_166;
                v148 = "%s: could not activate Auth Retry failure timer";
                goto LABEL_146;
              }
              if ( v32 != 1 )
                goto LABEL_125;
            }
            sae_auth_retry = mlme_get_sae_auth_retry(*(_QWORD *)(v23 + 16), v24, v25, v26, v27, v28, v29, v30, v31);
            if ( sae_auth_retry && *(_QWORD *)(sae_auth_retry + 16) )
            {
              v221 = sae_auth_retry;
              if ( *(_BYTE *)sae_auth_retry )
              {
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: Retry sae auth for seq num %d vdev id %d",
                  v213,
                  v214,
                  v215,
                  v216,
                  v217,
                  v218,
                  v219,
                  v220,
                  "lim_handle_sae_auth_timeout",
                  *(unsigned __int16 *)(v11 + 1124),
                  *(unsigned __int8 *)(v23 + 10));
                lim_send_frame(v10, *(unsigned __int8 *)(v23 + 10), *(_QWORD *)(v221 + 16), *(unsigned int *)(v221 + 8));
                --*(_BYTE *)v221;
                result = tx_timer_activate((char *)(v10 + 2928));
                if ( !(_DWORD)result )
                  goto LABEL_166;
              }
              else if ( !wlan_cm_is_vdev_connecting(
                           *(_QWORD *)(v23 + 16),
                           v213,
                           v214,
                           v215,
                           v216,
                           v217,
                           v218,
                           v219,
                           v220) )
              {
                v222 = *(_QWORD *)(v221 + 16);
                v223 = *(unsigned __int8 *)(v23 + 10);
                v297 = 0;
                v298 = 0;
                v295 = 0;
                v296 = 0;
                v293 = 0;
                v294 = nullptr;
                v224 = (unsigned __int8 *)_qdf_mem_malloc(0x20u, "lim_send_pre_auth_failure", 1794);
                if ( v224 )
                {
                  v225 = v224;
                  *(_DWORD *)v224 = v223;
                  *((_DWORD *)v224 + 1) = 1;
                  qdf_mem_copy(v224 + 8, (const void *)(v222 + 16), 6u);
                  qdf_mem_set(v225 + 14, 0x10u, 0);
                  v294 = v225;
                  LOWORD(v293) = 4267;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Sending pre auth failure for mac_addr %02x:%02x:%02x:**:**:%02x",
                    v226,
                    v227,
                    v228,
                    v229,
                    v230,
                    v231,
                    v232,
                    v233,
                    "lim_send_pre_auth_failure",
                    v225[8],
                    v225[9],
                    v225[10],
                    v225[13]);
                  if ( (unsigned int)scheduler_post_message_debug(
                                       0x35u,
                                       0x36u,
                                       54,
                                       (unsigned __int16 *)&v293,
                                       0x713u,
                                       (__int64)"lim_send_pre_auth_failure") )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: Sending preauth status failed",
                      v234,
                      v235,
                      v236,
                      v237,
                      v238,
                      v239,
                      v240,
                      v241,
                      "lim_send_pre_auth_failure");
                    _qdf_mem_free((__int64)v225);
                  }
                }
              }
              result = lim_sae_auth_cleanup_retry(v10, *(unsigned __int8 *)(v23 + 10));
            }
            else
            {
              result = qdf_trace_msg(
                         0x35u,
                         8u,
                         "%s: sae auth frame is not buffered vdev id %d",
                         v213,
                         v214,
                         v215,
                         v216,
                         v217,
                         v218,
                         v219,
                         v220,
                         "lim_handle_sae_auth_timeout",
                         *(unsigned __int8 *)(v23 + 10));
            }
          }
          else
          {
            result = qdf_trace_msg(
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
      v107 = pe_find_session_by_session_id(result, *(unsigned __int8 *)(result + 2186));
      if ( !v107 )
      {
        result = qdf_trace_msg(
                   0x35u,
                   2u,
                   "%s: session does not exist for given SessionId: %d",
                   v108,
                   v109,
                   v110,
                   v111,
                   v112,
                   v113,
                   v114,
                   v115,
                   "lim_process_periodic_join_probe_req_timer",
                   *(unsigned __int8 *)(v10 + 2186));
        goto LABEL_166;
      }
      v116 = v107;
      result = tx_timer_running(v10 + 1072);
      if ( (result & 1) != 0 && *(_DWORD *)(v116 + 72) == 2 )
      {
        lim_send_probe_req_mgmt_frame(v10, v116, *(_QWORD *)(v116 + 112) + 260LL, *(_QWORD *)(v116 + 112) + 262LL);
        lim_deactivate_and_change_timer(v10, 18);
        result = tx_timer_activate((char *)(v10 + 2136));
        if ( !(_DWORD)result )
        {
          ++*(_BYTE *)(v116 + 13283);
          goto LABEL_166;
        }
        v117 = "%s: could not activate Periodic Join req failure timer";
        v118 = "lim_process_periodic_join_probe_req_timer";
        goto LABEL_93;
      }
      goto LABEL_166;
    }
    if ( v12 != 5077 )
    {
      if ( v12 == 5108 )
      {
        result = ((__int64 (__fastcall *)(__int64))lim_process_rrm_sta_stats_rsp_timeout)(result);
      }
      else if ( v12 == 5110 )
      {
        result = lim_send_disassoc_cnf(result);
      }
      goto LABEL_166;
    }
LABEL_55:
    result = lim_process_assoc_failure_timeout();
    goto LABEL_166;
  }
  if ( *a2 <= 0x13D1u )
  {
    if ( v12 != 1006 )
    {
      if ( v12 == 1009 )
      {
        v39 = *((unsigned __int8 **)a2 + 1);
        v293 = 0x1000001F4LL;
        if ( v39 )
        {
          v136 = pe_find_session_by_session_id(result, v39[10]);
          if ( v136 )
          {
            v145 = *(unsigned int *)(v136 + 88);
            v146 = v136;
            v291 = *(_DWORD *)(v136 + 24);
            v292 = *(_WORD *)(v136 + 28);
            if ( (_DWORD)v145 != 1 )
            {
              v147 = *(_DWORD *)(v136 + 72);
              if ( v147 == 9 || v147 == 3 )
              {
                if ( !(unsigned int)qdf_mem_cmp(v39, &v291, 6u) )
                {
                  *(_BYTE *)(v10 + 330) = v39[10];
                  if ( *(_DWORD *)(v146 + 7036) )
                  {
                    v242 = *(_DWORD *)(v146 + 72);
                  }
                  else
                  {
                    v242 = *(_DWORD *)(v146 + 72);
                    if ( (*(_BYTE *)(v146 + 7024) & 0x10) != 0 )
                    {
                      v243 = *(_DWORD *)(v146 + 76);
                      *(_DWORD *)(v146 + 8056) = v242;
                      *(_DWORD *)(v146 + 8052) = v243;
                    }
                  }
                  v244 = *(_WORD *)(v146 + 8);
                  *(_DWORD *)(v146 + 72) = 10;
                  *(_DWORD *)(v146 + 76) = v242;
                  qdf_trace(53, 0, v244, 10);
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: vdev %d Sending Assoc_Req Frame, timeout %d msec",
                    v245,
                    v246,
                    v247,
                    v248,
                    v249,
                    v250,
                    v251,
                    v252,
                    "lim_process_mlm_assoc_req",
                    *(unsigned __int8 *)(v146 + 10),
                    *(unsigned int *)(v10 + 352));
                  lim_send_assoc_req_mgmt_frame(v10, v39, v146);
                  qdf_trace(53, 0xDu, *(_WORD *)(v146 + 8), 5);
                  result = tx_timer_activate((char *)(v10 + 280));
                  if ( !(_DWORD)result )
                    goto LABEL_166;
                  qdf_trace_msg(
                    0x35u,
                    3u,
                    "%s: SessionId:%d couldn't start Assoc failure timer",
                    v253,
                    v254,
                    v255,
                    v256,
                    v257,
                    v258,
                    v259,
                    v260,
                    "lim_process_mlm_assoc_req",
                    *(unsigned __int16 *)(v146 + 8));
                  goto LABEL_55;
                }
                v145 = *(unsigned int *)(v146 + 88);
              }
            }
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: received unexpected MLM_ASSOC_CNF in state %X for role=%d, MAC addr= %02x:%02x:%02x:**:**:%02x",
              v137,
              v138,
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              "lim_process_mlm_assoc_req",
              *(unsigned int *)(v146 + 72),
              v145,
              *v39,
              v39[1],
              v39[2],
              v39[5]);
            lim_print_mlm_state(v10, 3, *(unsigned int *)(v146 + 72));
            BYTE6(v293) = v39[10];
            _qdf_mem_free((__int64)v39);
            result = lim_process_mlm_rsp_messages(v10, 1010, &v293);
            goto LABEL_166;
          }
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: SessionId:%d Session Does not exist",
            v137,
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            "lim_process_mlm_assoc_req",
            v39[10]);
          goto LABEL_89;
        }
        v148 = "%s: Buffer is Pointing to NULL";
        v149 = "lim_process_mlm_assoc_req";
      }
      else
      {
        if ( v12 != 1012 )
          goto LABEL_166;
        v39 = *((unsigned __int8 **)a2 + 1);
        if ( v39 )
        {
          v294 = nullptr;
          v295 = 0;
          v40 = v39[12];
          v290 = 0;
          v292 = 0;
          v291 = 0;
          v293 = 0;
          v41 = pe_find_session_by_session_id(result, v40);
          if ( v41 )
          {
            v50 = v41;
            qdf_mem_copy(&v291, (const void *)(v41 + 24), 6u);
            if ( *(_DWORD *)(v50 + 88) == 2 && (*(_DWORD *)v39 != v291 || *((unsigned __int16 *)v39 + 2) != v292) )
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
                lim_send_sme_disassoc_deauth_ntf(v10, 0, v69);
              }
              goto LABEL_89;
            }
            v150 = dph_lookup_hash_entry(v51, v52, v53, v54, v55, v56, v57, v58, v10, v39, &v290, v50 + 360);
            v159 = v150;
            if ( v150 )
            {
              v160 = *(_DWORD *)(v150 + 8);
              if ( v160 <= 0xF && ((1 << v160) & 0xD000) != 0 )
              {
                *(_DWORD *)(v150 + 24) = *((unsigned __int16 *)v39 + 3);
                v161 = (unsigned __int8)send_disassoc_frame;
                v162 = *((_WORD *)v39 + 4);
                *(_DWORD *)(v150 + 8) = 22;
                *(_WORD *)(v150 + 34) = v162;
                if ( v161 == 1 && *((_WORD *)v39 + 3) != 46 )
                {
                  if ( *(_QWORD *)(v10 + 12392) )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: pMlmDisassocReq is not NULL, freeing",
                      v151,
                      v152,
                      v153,
                      v154,
                      v155,
                      v156,
                      v157,
                      v158,
                      "lim_process_mlm_disassoc_req_ntf");
                    _qdf_mem_free(*(_QWORD *)(v10 + 12392));
                  }
                  *(_QWORD *)(v10 + 12392) = v39;
                  *(_DWORD *)(v159 + 8) = 22;
                  result = lim_send_disassoc_mgmt_frame(v10, *((unsigned __int16 *)v39 + 3), v39, v50, 1);
                  if ( *(_DWORD *)(v50 + 88) == 2 )
                    result = wma_tx_abort(*(unsigned __int8 *)(v50 + 10));
                  goto LABEL_166;
                }
                lim_mlo_notify_peer_disconn(v50, v150);
                send_disassoc_frame = 1;
                if ( (unsigned int)lim_cleanup_rx_path(
                                     v10,
                                     (__int16 *)v159,
                                     v50,
                                     1,
                                     v163,
                                     v164,
                                     v165,
                                     v166,
                                     v167,
                                     v168,
                                     v169,
                                     v170) )
                {
                  v171 = 502;
LABEL_116:
                  HIDWORD(v294) = v171;
                  qdf_mem_copy(&v293, v39, 6u);
                  LODWORD(v295) = *((_DWORD *)v39 + 2);
                  BYTE4(v295) = v39[12];
                  _qdf_mem_free((__int64)v39);
                  result = lim_process_mlm_rsp_messages(v10, 1013, &v293);
                  goto LABEL_166;
                }
LABEL_89:
                result = _qdf_mem_free((__int64)v39);
                goto LABEL_166;
              }
            }
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: Invalid MLM_DISASSOC_REQ, Addr= %02x:%02x:%02x:**:**:%02x",
              v151,
              v152,
              v153,
              v154,
              v155,
              v156,
              v157,
              v158,
              "lim_process_mlm_disassoc_req_ntf",
              *v39,
              v39[1],
              v39[2],
              v39[5]);
            if ( !v159 )
            {
LABEL_115:
              v171 = 500;
              goto LABEL_116;
            }
            v172 = *(unsigned int *)(v159 + 8);
            v173 = "%s: Sta MlmState: %d";
          }
          else
          {
            v172 = v39[12];
            v173 = "%s: session does not exist for given sessionId %d";
          }
          qdf_trace_msg(
            0x35u,
            2u,
            v173,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "lim_process_mlm_disassoc_req_ntf",
            v172);
          goto LABEL_115;
        }
        v148 = "%s: Buffer is Pointing to NULL";
        v149 = "lim_process_mlm_disassoc_req";
      }
LABEL_78:
      result = qdf_trace_msg(0x35u, 2u, v148, a3, a4, a5, a6, a7, a8, a9, a10, v149);
      goto LABEL_166;
    }
    v119 = *((_QWORD *)a2 + 1);
    LODWORD(v295) = 0;
    v293 = 0;
    v294 = nullptr;
    if ( v119 )
    {
      *(_QWORD *)(result + 11376) = v119;
      v120 = *(unsigned __int8 *)(v119 + 12);
      v121 = pe_find_session_by_session_id(result, *(unsigned __int8 *)(v119 + 12));
      if ( !v121 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: SessionId:%d does not exist",
          v122,
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          "lim_process_mlm_auth_req",
          v120);
        result = _qdf_mem_free(v119);
        *(_QWORD *)(v10 + 11376) = 0;
        goto LABEL_166;
      }
      v130 = *(unsigned __int8 **)(v10 + 11376);
      v131 = v121;
      if ( v130 )
      {
        v132 = *v130;
        v133 = v130[1];
        v134 = v130[2];
        v135 = v130[5];
      }
      else
      {
        v134 = 0;
        v132 = 0;
        v133 = 0;
        v135 = 0;
      }
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: vdev %d Systemrole %d mlmstate %d from: %02x:%02x:%02x:**:**:%02xwith authtype %d",
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        v128,
        v129,
        "lim_process_mlm_auth_req",
        *(unsigned __int8 *)(v121 + 10),
        *(unsigned int *)(v121 + 88),
        *(unsigned int *)(v121 + 72),
        v132,
        v133,
        v134,
        v135,
        *((_DWORD *)v130 + 2));
      if ( *(_DWORD *)(v131 + 88) != 2
        || (v182 = *(_DWORD *)(v131 + 72), v182 != 14) && v182 != 3
        || (v183 = *(_QWORD *)(v10 + 11376), (*(_BYTE *)v183 & 1) != 0)
        || !(unsigned __int8)lim_is_auth_algo_supported(v10, *(unsigned int *)(v183 + 8), v131) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Auth req not expected is_privacy_enabled %d is_auth_open_system %d auth type %d",
          v174,
          v175,
          v176,
          v177,
          v178,
          v179,
          v180,
          v181,
          "lim_process_mlm_auth_req",
          *(unsigned __int8 *)(*(_QWORD *)(v10 + 8) + 5652LL),
          *(unsigned __int8 *)(*(_QWORD *)(v10 + 8) + 5654LL),
          *(unsigned int *)(*(_QWORD *)(v10 + 11376) + 8LL));
        v201 = 500;
LABEL_110:
        HIDWORD(v294) = v201;
LABEL_111:
        qdf_mem_copy(&v293, *(const void **)(v10 + 11376), 6u);
        v202 = *(_QWORD *)(v10 + 11376);
        v203 = *(_DWORD *)(v202 + 8);
        BYTE2(v295) = v120;
        LODWORD(v294) = v203;
        _qdf_mem_free(v202);
        *(_QWORD *)(v10 + 11376) = 0;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: SessionId:%d LimPostSme LIM_MLM_AUTH_CNF",
          v204,
          v205,
          v206,
          v207,
          v208,
          v209,
          v210,
          v211,
          "lim_process_mlm_auth_req",
          v120);
        result = lim_process_mlm_rsp_messages(v10, 1007, &v293);
        goto LABEL_166;
      }
      v291 = *(_DWORD *)(v131 + 24);
      v292 = *(_WORD *)(v131 + 28);
      hash_entry = dph_get_hash_entry(v10, 1u, v131 + 360);
      v185 = lim_search_pre_auth_list(v10, *(_QWORD *)(v10 + 11376));
      if ( *(_DWORD *)(v131 + 88) == 2 && *(_DWORD *)(v131 + 72) == 14 )
      {
        if ( hash_entry )
        {
          if ( *(_DWORD *)(*(_QWORD *)(v10 + 11376) + 8LL) == *(_DWORD *)(hash_entry + 12) )
          {
            v194 = v185;
            v195 = qdf_mem_cmp(*(const void **)(v10 + 11376), &v291, 6u);
            v185 = v194;
            if ( !v195 )
            {
              v196 = *(unsigned __int8 **)(v10 + 11376);
              if ( v196 )
                goto LABEL_108;
              goto LABEL_162;
            }
          }
        }
      }
      if ( v185 )
      {
        v196 = *(unsigned __int8 **)(v10 + 11376);
        if ( *(_DWORD *)(v185 + 16) == *((_DWORD *)v196 + 2) )
        {
          if ( v196 )
          {
LABEL_108:
            v197 = *v196;
            v198 = v196[1];
            v199 = v196[2];
            v200 = v196[5];
LABEL_163:
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Already have pre-auth context with peer: %02x:%02x:%02x:**:**:%02x",
              v186,
              v187,
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              "lim_process_mlm_auth_req",
              v197,
              v198,
              v199,
              v200);
            HIDWORD(v294) = 0;
            goto LABEL_111;
          }
LABEL_162:
          v199 = 0;
          v197 = 0;
          v198 = 0;
          v200 = 0;
          goto LABEL_163;
        }
      }
      if ( *(_DWORD *)(v10 + 11404) == *(_DWORD *)(*(_QWORD *)(v10 + 8) + 1896LL) )
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Number of pre-auth reached max limit",
          v186,
          v187,
          v188,
          v189,
          v190,
          v191,
          v192,
          v193,
          "lim_process_mlm_auth_req");
        v201 = 512;
        goto LABEL_110;
      }
      *(_DWORD *)(v131 + 76) = *(_DWORD *)(v131 + 72);
      v261 = _qdf_mem_malloc(0x3FFu, "lim_process_mlm_auth_req", 854);
      if ( v261 )
      {
        v262 = v261;
        if ( *(_DWORD *)(*(_QWORD *)(v10 + 11376) + 8LL) == 3 && (*(_BYTE *)(v131 + 10008) & 1) == 0 )
        {
          if ( (unsigned int)lim_process_mlm_auth_req_sae(v10, v131) )
          {
            HIDWORD(v294) = 500;
            _qdf_mem_free(v262);
            goto LABEL_111;
          }
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: lim_process_mlm_auth_req_sae is successful",
            v282,
            v283,
            v284,
            v285,
            v286,
            v287,
            v288,
            v289,
            "lim_process_mlm_auth_req");
          *(_WORD *)(v262 + 4) = 0;
          *(_DWORD *)v262 = 65539;
          host_log_wlan_auth_info(3, 1, 0);
        }
        else
        {
          v263 = *(_WORD *)(v131 + 8);
          *(_DWORD *)(v131 + 72) = 5;
          qdf_trace(53, 0, v263, 5);
          if ( *(_DWORD *)(*(_QWORD *)(v10 + 11376) + 8LL) == 3 && (*(_BYTE *)(v131 + 10008) & 1) != 0 )
            v264 = 0;
          else
            v264 = (unsigned __int8)*(_DWORD *)(*(_QWORD *)(v10 + 11376) + 8LL);
          *(_WORD *)v262 = v264;
          *(_DWORD *)(v262 + 2) = 1;
          host_log_wlan_auth_info(v264, 1, 0);
          v265 = *(_QWORD *)(v10 + 11376);
          *(_DWORD *)(v11 + 1180) = 0;
          lim_send_auth_mgmt_frame(v10, v262, v265, 0, v131);
          *(_BYTE *)(v10 + 858) = v120;
          *(_BYTE *)(v10 + 2978) = v120;
          lim_deactivate_and_change_timer(v10, 20);
          qdf_trace(53, 0xDu, *(_WORD *)(v131 + 8), 3);
          lim_deactivate_and_change_timer(v10, 3);
          if ( (unsigned int)tx_timer_activate((char *)(v10 + 808)) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: could not start Auth failure timer",
              v266,
              v267,
              v268,
              v269,
              v270,
              v271,
              v272,
              v273,
              "lim_process_mlm_auth_req");
            lim_process_auth_failure_timeout(v10);
          }
          else
          {
            qdf_trace(53, 0xDu, *(_WORD *)(v131 + 8), 20);
            if ( (unsigned int)tx_timer_activate((char *)(v10 + 2928)) )
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: could not activate Auth Retry timer",
                v274,
                v275,
                v276,
                v277,
                v278,
                v279,
                v280,
                v281,
                "lim_process_mlm_auth_req");
          }
        }
        result = _qdf_mem_free(v262);
        goto LABEL_166;
      }
      v148 = "%s: mem alloc failed for auth frame body";
    }
    else
    {
      v148 = "%s: Buffer is Pointing to NULL";
    }
    v149 = "lim_process_mlm_auth_req";
    goto LABEL_78;
  }
  switch ( v12 )
  {
    case 0x13D2u:
      result = lim_process_join_failure_timeout(result);
      break;
    case 0x13D3u:
      result = lim_process_auth_failure_timeout(result);
      break;
    case 0x13D4u:
      v72 = *((_DWORD *)a2 + 1);
      LOBYTE(v293) = 0;
      pre_auth_node_from_index = lim_get_pre_auth_node_from_index(
                                   a3,
                                   a4,
                                   a5,
                                   a6,
                                   a7,
                                   a8,
                                   a9,
                                   a10,
                                   result,
                                   result + 11408,
                                   v72);
      if ( pre_auth_node_from_index )
      {
        v82 = pre_auth_node_from_index;
        session_by_bssid = pe_find_session_by_bssid(v10, pre_auth_node_from_index + 8, &v293);
        if ( session_by_bssid )
        {
          v84 = session_by_bssid;
          result = lim_diag_event_report(v10, 75, session_by_bssid, 0);
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
              lim_deactivate_and_change_per_sta_id_timer(v10, 9, *(unsigned __int8 *)(v82 + 24));
              result = lim_delete_pre_auth_node(v10, v82 + 8);
            }
            else
            {
              result = qdf_trace_msg(
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
        v117 = "%s: session does not exist for given BSSID";
      }
      else
      {
        v117 = "%s: Invalid auth node";
      }
      v118 = "lim_process_auth_rsp_timeout";
LABEL_93:
      result = qdf_trace_msg(0x35u, 3u, v117, v74, v75, v76, v77, v78, v79, v80, v81, v118);
      break;
  }
LABEL_166:
  _ReadStatusReg(SP_EL0);
  return result;
}
