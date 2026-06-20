__int64 __fastcall ttlm_subst_sta_inprogress_event(
        __int64 a1,
        unsigned __int16 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12)
{
  __int64 result; // x0
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
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int *v50; // x8
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 first_vdev_by_ml_peer; // x0
  __int64 v61; // x21
  __int64 bsspeer; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x8
  __int64 v72; // x8
  __int64 v73; // x24
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  char v90; // w20
  int v91; // w22
  int v92; // w0
  __int64 v93; // x8
  _BOOL4 v94; // w19
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  __int64 v104; // x20
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  const char *v113; // x2
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned int v122; // w24
  __int64 v123; // x0
  unsigned int *v124; // x8
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  __int64 v133; // x26
  __int64 v134; // x21
  __int64 v135; // x23
  _DWORD *v136; // x25
  __int64 v137; // x21
  unsigned int *v138; // x8
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  __int64 v147; // x19
  unsigned int *v148; // x8
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  __int64 v157; // x20
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  int v166; // w9
  __int64 v167; // x5
  const char *v168; // x2
  __int64 v169; // x4
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  double v194; // d0
  double v195; // d1
  double v196; // d2
  double v197; // d3
  double v198; // d4
  double v199; // d5
  double v200; // d6
  double v201; // d7
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  double v218; // d0
  double v219; // d1
  double v220; // d2
  double v221; // d3
  double v222; // d4
  double v223; // d5
  double v224; // d6
  double v225; // d7
  unsigned int *v226; // x8
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  __int64 v243; // [xsp+10h] [xbp-D0h] BYREF
  __int64 v244; // [xsp+18h] [xbp-C8h]
  unsigned __int16 v245; // [xsp+20h] [xbp-C0h]
  _QWORD dest[23]; // [xsp+28h] [xbp-B8h] BYREF

  result = 0;
  dest[22] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 <= 4u )
  {
    if ( a2 == 1 )
    {
      memset(dest, 0, 48);
      result = _qdf_mem_malloc(0xA8u, "wlan_ttlm_handle_tx_action_req", 155);
      if ( !result )
        goto LABEL_30;
      v104 = result;
      qdf_mem_set((void *)result, 0xA8u, 0);
      *(_QWORD *)v104 = a1;
      *(_DWORD *)(v104 + 8) = 4;
      *(_DWORD *)(v104 + 60) = 4;
      *(_DWORD *)(v104 + 112) = 4;
      qdf_mem_copy((void *)(v104 + 112), (const void *)a12, 0x34u);
      dest[1] = v104;
      dest[2] = ttlm_tx_action_req_cb;
      if ( (unsigned int)scheduler_post_message_debug(
                           0x48u,
                           0x1Fu,
                           72,
                           (unsigned __int16 *)dest,
                           0xADu,
                           (__int64)"wlan_ttlm_handle_tx_action_req") )
      {
        qdf_trace_msg(
          0x8Fu,
          2u,
          "%s: Post TTLM STA Request msg fail",
          v105,
          v106,
          v107,
          v108,
          v109,
          v110,
          v111,
          v112,
          "wlan_ttlm_handle_tx_action_req");
        _qdf_mem_free(v104);
        result = 0;
        goto LABEL_30;
      }
LABEL_29:
      result = 1;
      goto LABEL_30;
    }
    if ( a2 != 2 )
      goto LABEL_30;
    memset(dest, 0, 172);
    v245 = 0;
    v243 = 0;
    v244 = 0;
    if ( a1 )
    {
      first_vdev_by_ml_peer = mlo_get_first_vdev_by_ml_peer(a1);
      if ( first_vdev_by_ml_peer )
      {
        v61 = first_vdev_by_ml_peer;
        bsspeer = wlan_objmgr_vdev_try_get_bsspeer(first_vdev_by_ml_peer, 0x5Au);
        if ( bsspeer )
        {
          if ( *(_QWORD *)(v61 + 1360) && (v71 = *(_QWORD *)(v61 + 216)) != 0 && (v72 = *(_QWORD *)(v71 + 80)) != 0 )
          {
            v73 = bsspeer;
            ml_nlink_get_curr_force_state(v72, v61, &v243);
            qdf_trace_msg(
              0x99u,
              8u,
              "%s: Current force state force_inactive_bitmap: %d force_active_bitmap: %d curr_dynamic_inactive_bitmap: %d"
              " curr_active_bitmap: %d curr_inactive_bitmap: %d",
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              "ttlm_populate_tx_action_req",
              WORD1(v243),
              (unsigned __int16)v243,
              WORD2(v244),
              HIWORD(v244),
              v245);
            if ( (*(_BYTE *)(a12 + 4) & 1) != 0
              || !*(_WORD *)(a12 + 16)
              || (*(unsigned __int16 *)(a12 + 16) & ~WORD1(v243)) != 0 )
            {
              v157 = *(_QWORD *)(v73 + 784);
              memcpy(dest, (const void *)(v157 + 376), 0xACu);
              LODWORD(dest[0]) = 1;
              v90 = t2lm_gen_dialog_token(v157 + 208);
              BYTE4(dest[0]) = v90;
              qdf_mem_set(&dest[1], 0x9Cu, 0);
              v166 = *(unsigned __int8 *)(a12 + 4);
              LODWORD(dest[1]) = 4;
              HIDWORD(dest[7]) = 4;
              LODWORD(dest[14]) = 2;
              if ( v166 == 1 )
              {
                v167 = BYTE4(dest[0]);
                BYTE4(dest[14]) = 1;
                v168 = "%s: Default mapping: %d dialog_token: %d";
                v169 = 1;
              }
              else
              {
                WORD2(dest[14]) = 0;
                BYTE6(dest[14]) = 0;
                BYTE1(dest[20]) = 1;
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: dir %d dialog_token: %d",
                  v158,
                  v159,
                  v160,
                  v161,
                  v162,
                  v163,
                  v164,
                  v165,
                  "ttlm_populate_tx_action_req",
                  2,
                  BYTE4(dest[0]));
                LOWORD(dest[16]) = *(_WORD *)(a12 + 16);
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: TID[%d]: %d",
                  v170,
                  v171,
                  v172,
                  v173,
                  v174,
                  v175,
                  v176,
                  v177,
                  "ttlm_populate_tx_action_req",
                  0);
                WORD1(dest[16]) = *(_WORD *)(a12 + 18);
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: TID[%d]: %d",
                  v178,
                  v179,
                  v180,
                  v181,
                  v182,
                  v183,
                  v184,
                  v185,
                  "ttlm_populate_tx_action_req",
                  1);
                WORD2(dest[16]) = *(_WORD *)(a12 + 20);
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: TID[%d]: %d",
                  v186,
                  v187,
                  v188,
                  v189,
                  v190,
                  v191,
                  v192,
                  v193,
                  "ttlm_populate_tx_action_req",
                  2);
                HIWORD(dest[16]) = *(_WORD *)(a12 + 22);
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: TID[%d]: %d",
                  v194,
                  v195,
                  v196,
                  v197,
                  v198,
                  v199,
                  v200,
                  v201,
                  "ttlm_populate_tx_action_req",
                  3);
                LOWORD(dest[17]) = *(_WORD *)(a12 + 24);
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: TID[%d]: %d",
                  v202,
                  v203,
                  v204,
                  v205,
                  v206,
                  v207,
                  v208,
                  v209,
                  "ttlm_populate_tx_action_req",
                  4);
                WORD1(dest[17]) = *(_WORD *)(a12 + 26);
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: TID[%d]: %d",
                  v210,
                  v211,
                  v212,
                  v213,
                  v214,
                  v215,
                  v216,
                  v217,
                  "ttlm_populate_tx_action_req",
                  5);
                WORD2(dest[17]) = *(_WORD *)(a12 + 28);
                qdf_trace_msg(
                  0x99u,
                  8u,
                  "%s: TID[%d]: %d",
                  v218,
                  v219,
                  v220,
                  v221,
                  v222,
                  v223,
                  v224,
                  v225,
                  "ttlm_populate_tx_action_req",
                  6);
                v167 = *(unsigned __int16 *)(a12 + 30);
                v168 = "%s: TID[%d]: %d";
                v169 = 7;
                HIWORD(dest[17]) = *(_WORD *)(a12 + 30);
              }
              qdf_trace_msg(
                0x99u,
                8u,
                v168,
                v158,
                v159,
                v160,
                v161,
                v162,
                v163,
                v164,
                v165,
                "ttlm_populate_tx_action_req",
                v169,
                v167);
              v91 = t2lm_deliver_event(v61, v73, 2, dest, 0, (char *)dest + 4);
            }
            else
            {
              qdf_trace_msg(
                0x99u,
                2u,
                "%s: TTLM req: 0x%x failed due to force_inactive link: 0x%x",
                v82,
                v83,
                v84,
                v85,
                v86,
                v87,
                v88,
                v89,
                "ttlm_populate_tx_action_req");
              v90 = 0;
              v91 = 4;
            }
            bsspeer = v73;
          }
          else
          {
            v90 = 0;
            v91 = 29;
          }
          wlan_objmgr_peer_release_ref(bsspeer, 0x5Au, v63, v64, v65, v66, v67, v68, v69, v70);
          wlan_objmgr_vdev_release_ref(v61, 0x5Au, v226, v227, v228, v229, v230, v231, v232, v233, v234);
          if ( !v91 )
          {
            if ( (unsigned int)qdf_mc_timer_start(a1 + 736, 0x1388u) )
              qdf_trace_msg(
                0x99u,
                2u,
                "%s: Failed to start the timer",
                v235,
                v236,
                v237,
                v238,
                v239,
                v240,
                v241,
                v242,
                "ttlm_subst_sta_inprogress_event");
            v91 = 0;
            v122 = 1;
LABEL_35:
            dest[1] = 0;
            v123 = mlo_get_first_vdev_by_ml_peer(a1);
            if ( !v123 )
            {
              qdf_trace_msg(
                0x99u,
                2u,
                "%s: VDEV is null",
                v125,
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                v132,
                "ttlm_handle_status_ind");
              result = v122;
              goto LABEL_30;
            }
            v133 = *(_QWORD *)(v123 + 1360);
            if ( v133 )
            {
              v134 = *(_QWORD *)(v133 + 2224);
              if ( v134 )
              {
                v135 = v123;
                qdf_mutex_acquire(v133 + 1656);
                v136 = *(_DWORD **)(v134 + 1504);
                v137 = *(_QWORD *)(v134 + 1512);
                qdf_mutex_release(v133 + 1656);
                wlan_objmgr_vdev_release_ref(v135, 0x5Au, v138, v139, v140, v141, v142, v143, v144, v145, v146);
                dest[0] = a1;
                LOBYTE(dest[1]) = v90;
                HIDWORD(dest[1]) = v91;
                if ( v136 && v137 )
                {
                  if ( *(v136 - 1) != 323970278 )
                    __break(0x8239u);
                  ((void (__fastcall *)(_QWORD *, __int64))v136)(dest, v137);
                }
                result = v122;
                goto LABEL_30;
              }
            }
            else
            {
              v147 = v123;
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: null mlo_dev_ctx",
                v125,
                v126,
                v127,
                v128,
                v129,
                v130,
                v131,
                v132,
                "ttlm_handle_status_ind");
              v123 = v147;
            }
            wlan_objmgr_vdev_release_ref(v123, 0x5Au, v124, v125, v126, v127, v128, v129, v130, v131, v132);
            result = v122;
            goto LABEL_30;
          }
LABEL_34:
          wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, v114, v115, v116, v117, v118, v119, v120, v121);
          v122 = 0;
          goto LABEL_35;
        }
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: peer is null",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "ttlm_populate_tx_action_req");
        wlan_objmgr_vdev_release_ref(v61, 0x5Au, v148, v149, v150, v151, v152, v153, v154, v155, v156);
LABEL_33:
        v90 = 0;
        v91 = 29;
        goto LABEL_34;
      }
      v113 = "%s: VDEV is null";
    }
    else
    {
      v113 = "%s: ML peer is NULL";
    }
    qdf_trace_msg(0x99u, 2u, v113, a3, a4, a5, a6, a7, a8, a9, a10, "ttlm_populate_tx_action_req");
    goto LABEL_33;
  }
  switch ( a2 )
  {
    case 5u:
      v92 = ttlm_handle_rx_action_rsp_in_sta_in_progress_state(a1, a12);
      v93 = *(_QWORD *)(a1 + 720);
      v94 = v92 == 0;
      wlan_sm_transition_to(v93, 2u, v95, v96, v97, v98, v99, v100, v101, v102);
      result = v94;
      break;
    case 0xAu:
      wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, a3, a4, a5, a6, a7, a8, a9, a10);
      goto LABEL_29;
    case 0xBu:
      v14 = mlo_get_first_vdev_by_ml_peer(a1);
      if ( v14 )
      {
        v23 = v14;
        v24 = wlan_objmgr_vdev_try_get_bsspeer(v14, 0x5Au);
        if ( v24 )
        {
          v33 = v24;
          v34 = wlan_t2lm_clear_ongoing_negotiation();
          wlan_sm_transition_to(*(_QWORD *)(a1 + 720), 2u, v34, v35, v36, v37, v38, v39, v40, v41);
          wlan_objmgr_peer_release_ref(v33, 0x5Au, v42, v43, v44, v45, v46, v47, v48, v49);
        }
        else
        {
          qdf_trace_msg(
            0x99u,
            2u,
            "%s: Peer is NULL",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "ttlm_handle_timer_timeout");
        }
        wlan_objmgr_vdev_release_ref(v23, 0x5Au, v50, v51, v52, v53, v54, v55, v56, v57, v58);
      }
      else
      {
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: VDEV is null",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "ttlm_handle_timer_timeout");
      }
      goto LABEL_29;
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
