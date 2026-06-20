__int64 __fastcall wma_hold_req_timer(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x21
  __int64 v20; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _QWORD *v39; // x0
  _QWORD *v40; // x22
  int v41; // w0
  __int64 v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  const char *v51; // x2
  unsigned int v52; // w1
  __int64 v53; // x8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  int v78; // w4
  __int64 v79; // x21
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x0
  __int64 v89; // x1
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  int v98; // w21
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  char v123; // w21
  __int64 v124; // x0
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  long double v133; // q0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 v142; // x4
  __int64 v143; // x5
  __int64 v144; // x6
  __int64 v145; // x7
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  int v154; // w5
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  int v163; // w5
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  __int64 v172; // x4
  __int64 v173; // x5
  __int64 v174; // x6
  __int64 v175; // x7
  int v176; // w22
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  __int64 v201; // x22
  long double v202; // q0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  __int64 *v210; // x21
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  _DWORD *v219; // x21
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  int v228; // w22
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  _QWORD *v253[2]; // [xsp+10h] [xbp-10h] BYREF

  v253[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(53, (__int64)"wma_hold_req_timer", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !result )
    goto LABEL_22;
  v19 = result;
  result = (__int64)_cds_get_context(54, (__int64)"wma_hold_req_timer", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !result )
    goto LABEL_22;
  v20 = result;
  v253[0] = nullptr;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(result + 600);
  }
  else
  {
    raw_spin_lock_bh(result + 600);
    *(_QWORD *)(v20 + 608) |= 1uLL;
  }
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v20 + 576), v253) )
  {
    while ( 1 )
    {
      v39 = (_QWORD *)(v20 + 576);
      if ( v253[0] - 21 == (_QWORD *)a1 )
        break;
      if ( (unsigned int)qdf_list_peek_next(v39, v253[0], v253) )
      {
        v53 = *(_QWORD *)(v20 + 608);
        if ( (v53 & 1) != 0 )
        {
          *(_QWORD *)(v20 + 608) = v53 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v20 + 600);
        }
        else
        {
          raw_spin_unlock(v20 + 600);
        }
        v51 = "%s: target request not found for req %pK";
        v52 = 2;
        goto LABEL_20;
      }
    }
    v40 = v253[0];
    v41 = qdf_list_remove_node((__int64)v39, v253[0]);
    v42 = *(_QWORD *)(v20 + 608);
    if ( v41 )
    {
      if ( (v42 & 1) != 0 )
      {
        *(_QWORD *)(v20 + 608) = v42 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v20 + 600);
      }
      else
      {
        raw_spin_unlock(v20 + 600);
      }
      v51 = "%s: Failed to remove request for req %pK";
      v52 = 8;
LABEL_20:
      qdf_trace_msg(0x36u, v52, v51, v43, v44, v45, v46, v47, v48, v49, v50, "wma_find_req_on_timer_expiry", a1);
      goto LABEL_21;
    }
    if ( (v42 & 1) != 0 )
    {
      *(_QWORD *)(v20 + 608) = v42 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v20 + 600);
    }
    else
    {
      raw_spin_unlock(v20 + 600);
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: target request found for vdev id: %d type %d",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "wma_find_req_on_timer_expiry",
      *((unsigned __int8 *)v40 + 36),
      *((unsigned __int8 *)v40 + 37));
    qdf_trace_msg(
      0x36u,
      1u,
      "%s: request %d is timed out for vdev_id - %d",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "wma_hold_req_timer",
      *(unsigned int *)(a1 + 200),
      *(unsigned __int8 *)(a1 + 204));
    v78 = *(_DWORD *)(a1 + 200);
    if ( v78 > 4281 )
    {
      if ( v78 <= 4548 )
      {
        if ( v78 != 4282 )
        {
          if ( v78 == 4457 && *(_BYTE *)(a1 + 205) == 6 )
          {
            v79 = _qdf_mem_malloc(0x2Cu, "wma_hold_req_timer", 4200);
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: set hw mode req timed out",
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              "wma_hold_req_timer");
            if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
              wma_trigger_recovery_assert_on_fw_timeout(4457, 13);
            if ( !v79 )
              goto LABEL_105;
            *(_DWORD *)(v79 + 8) = 0;
            v88 = v20;
            *(_QWORD *)v79 = 2;
            v89 = 4458;
            goto LABEL_98;
          }
LABEL_104:
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Unhandled timeout for msg_type:%d and type:%d",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "wma_hold_req_timer");
          goto LABEL_105;
        }
        if ( *(_BYTE *)(a1 + 205) != 7 )
          goto LABEL_104;
        v79 = _qdf_mem_malloc(4u, "wma_hold_req_timer", 4219);
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: set dual mac config timeout",
          v146,
          v147,
          v148,
          v149,
          v150,
          v151,
          v152,
          v153,
          "wma_hold_req_timer");
        if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
          wma_trigger_recovery_assert_on_fw_timeout(4282, 14);
        if ( !v79 )
          goto LABEL_105;
        v88 = v20;
        v89 = 4283;
        *(_DWORD *)v79 = 2;
LABEL_98:
        wma_send_msg_high_priority(v88, v89, v79, 0);
        goto LABEL_105;
      }
      if ( v78 != 4549 )
      {
        if ( v78 == 4551 && *(_BYTE *)(a1 + 205) == 11 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: PASN Peer delete all resp not received. vdev:%d",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "wma_hold_req_timer",
            *(unsigned __int8 *)(a1 + 204));
          if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
            *(double *)&v133 = wma_trigger_recovery_assert_on_fw_timeout(11, 8000);
          wma_resume_vdev_delete(v20, *(unsigned __int8 *)(a1 + 204), v133);
          goto LABEL_105;
        }
        goto LABEL_104;
      }
      v154 = *(unsigned __int8 *)(a1 + 205);
      switch ( v154 )
      {
        case 15:
          v201 = *(_QWORD *)(a1 + 184);
          if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
            *(double *)&v202 = wma_trigger_recovery_assert_on_fw_timeout(15, 8000);
          if ( !v201 )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: vdev:%d msg_type:%d req_type: %d Invalid target request user data",
              *(double *)&v202,
              v203,
              v204,
              v205,
              v206,
              v207,
              v208,
              v209,
              "wma_hold_req_timer",
              *(unsigned __int8 *)(a1 + 204),
              *(unsigned int *)(a1 + 200),
              *(unsigned __int8 *)(a1 + 205));
            goto LABEL_105;
          }
          lim_send_sme_tdls_add_sta_rsp(
            v19,
            *(unsigned __int8 *)(a1 + 204),
            v201 + 9,
            *(unsigned __int8 *)(v201 + 104),
            0,
            16,
            v202);
          break;
        case 10:
          if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
            wma_trigger_recovery_assert_on_fw_timeout(8, 8000);
          wma_pasn_handle_peer_create_conf(
            v20,
            *(_QWORD *)(a1 + 184),
            *(unsigned __int8 *)(a1 + 205),
            15,
            *(unsigned __int8 *)(a1 + 204));
          break;
        case 8:
          if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
            v155 = wma_trigger_recovery_assert_on_fw_timeout(8, 8000);
          wma_remove_peer(
            (__int64 *)v20,
            *(const void **)(a1 + 184),
            *(unsigned __int8 *)(a1 + 204),
            0,
            v155,
            v156,
            v157,
            v158,
            v159,
            v160,
            v161,
            v162);
          lim_send_peer_create_resp(v19, *(unsigned __int8 *)(a1 + 204), 15);
          break;
        default:
          goto LABEL_104;
      }
LABEL_86:
      _qdf_mem_free(*(_QWORD *)(a1 + 184));
LABEL_105:
      qdf_mc_timer_destroy(a1);
      result = _qdf_mem_free(a1);
      goto LABEL_22;
    }
    if ( v78 == 4129 )
    {
      v79 = *(_QWORD *)(a1 + 184);
      *(_DWORD *)(v79 + 100) = 15;
      qdf_trace_msg(
        0x36u,
        1u,
        "%s: WMA_ADD_STA_REQ timed out",
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        "wma_hold_req_timer");
      if ( v79 == -9 )
      {
        v144 = 0;
        v142 = 0;
        v143 = 0;
        v145 = 0;
      }
      else
      {
        v142 = *(unsigned __int8 *)(v79 + 9);
        v143 = *(unsigned __int8 *)(v79 + 10);
        v144 = *(unsigned __int8 *)(v79 + 11);
        v145 = *(unsigned __int8 *)(v79 + 14);
      }
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Sending add sta rsp to umac (mac:%02x:%02x:%02x:**:**:%02x, status:%d)",
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        v141,
        "wma_hold_req_timer",
        v142,
        v143,
        v144,
        v145,
        *(_DWORD *)(v79 + 100));
      v176 = *(unsigned __int8 *)(v20 + 3777);
      if ( (cds_get_driver_state(v177, v178, v179, v180, v181, v182, v183, v184) & 8) == 0
        && !cds_is_fw_down(v185, v186, v187, v188, v189, v190, v191, v192)
        && (cds_get_driver_state(v193, v194, v195, v196, v197, v198, v199, v200) & 4) == 0
        && v176 )
      {
        wma_trigger_recovery_assert_on_fw_timeout(4129, 11);
      }
      v88 = v20;
      v89 = 4130;
      goto LABEL_98;
    }
    if ( v78 != 4131 )
    {
      if ( v78 == 4133 )
      {
        qdf_trace_msg(
          0x36u,
          1u,
          "%s: WMA_ADD_BSS_REQ timed out",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "wma_hold_req_timer");
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: Sending add bss rsp to umac (vdev %d, status:%d)",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "wma_hold_req_timer",
          *(unsigned __int8 *)(a1 + 204),
          15);
        v98 = *(unsigned __int8 *)(v20 + 3777);
        if ( (cds_get_driver_state(v99, v100, v101, v102, v103, v104, v105, v106) & 8) == 0
          && !cds_is_fw_down(v107, v108, v109, v110, v111, v112, v113, v114)
          && (cds_get_driver_state(v115, v116, v117, v118, v119, v120, v121, v122) & 4) == 0
          && v98 )
        {
          wma_trigger_recovery_assert_on_fw_timeout(4133, 12);
        }
        v123 = *(_BYTE *)(a1 + 204);
        v124 = _qdf_mem_malloc(0x10u, "wma_send_add_bss_resp", 4863);
        if ( v124 )
        {
          *(_BYTE *)v124 = v123;
          *(_DWORD *)(v124 + 4) = 15;
          lim_handle_add_bss_rsp(
            *(_QWORD *)(v20 + 16),
            (unsigned __int8 *)v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            v131,
            v132);
        }
        goto LABEL_105;
      }
      goto LABEL_104;
    }
    v163 = *(unsigned __int8 *)(a1 + 205);
    if ( v163 != 14 )
    {
      if ( v163 == 3 )
      {
        v210 = *(__int64 **)(a1 + 184);
        *(_DWORD *)(*v210 + 8) = 15;
        qdf_trace_msg(
          0x36u,
          1u,
          "%s: wma delete sta p2p request timed out",
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          "wma_hold_req_timer");
        if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
          v211 = wma_trigger_recovery_assert_on_fw_timeout(4131, 2);
        wma_handle_vdev_detach(v20, *v210, v211, v212, v213, v214, v215, v216, v217, v218);
        mlme_vdev_self_peer_delete_resp(*v210);
        goto LABEL_86;
      }
      if ( v163 != 2 )
      {
        if ( (v163 & 0xFE) == 4 )
        {
          v219 = *(_DWORD **)(a1 + 184);
          *v219 = 15;
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: wma delete peer for del bss req timed out",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "wma_hold_req_timer");
          if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
            v220 = wma_trigger_recovery_assert_on_fw_timeout(4131, 2);
          wma_send_vdev_down_req(v20, (__int64)v219, v220, v221, v222, v223, v224, v225, v226, v227);
          goto LABEL_105;
        }
        if ( v163 == 17 )
        {
          if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
            wma_trigger_recovery_assert_on_fw_timeout(4131, 2);
          lim_continue_bss_peer_create(*(unsigned __int8 **)(a1 + 184));
          goto LABEL_105;
        }
        if ( v163 == 9 )
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: wma delete peer timed out vdev %d",
            v70,
            v71,
            v72,
            v73,
            v74,
            v75,
            v76,
            v77,
            "wma_hold_req_timer",
            *(unsigned __int8 *)(a1 + 204));
          if ( (wma_crash_on_fw_timeout(*(unsigned __int8 *)(v20 + 3777)) & 1) != 0 )
            wma_trigger_recovery_assert_on_fw_timeout(4131, 2);
          lim_cm_send_connect_rsp(v19, 0, *(_QWORD *)(a1 + 184), 14, 16, 0, 0);
          cm_free_join_req(*(_QWORD *)(a1 + 184));
          goto LABEL_105;
        }
        goto LABEL_104;
      }
    }
    v79 = *(_QWORD *)(a1 + 184);
    *(_DWORD *)(v79 + 4) = 15;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: WMA_DEL_STA_REQ timed out for rsp type %d",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "wma_hold_req_timer",
      *(unsigned __int8 *)(a1 + 205));
    if ( v79 == -12 )
    {
      v174 = 0;
      v172 = 0;
      v173 = 0;
      v175 = 0;
    }
    else
    {
      v172 = *(unsigned __int8 *)(v79 + 12);
      v173 = *(unsigned __int8 *)(v79 + 13);
      v174 = *(unsigned __int8 *)(v79 + 14);
      v175 = *(unsigned __int8 *)(v79 + 17);
    }
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Sending del sta rsp to umac (mac:%02x:%02x:%02x:**:**:%02x, status:%d)",
      v164,
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      v171,
      "wma_hold_req_timer",
      v172,
      v173,
      v174,
      v175,
      *(_DWORD *)(v79 + 4));
    v228 = *(unsigned __int8 *)(v20 + 3777);
    if ( (cds_get_driver_state(v229, v230, v231, v232, v233, v234, v235, v236) & 8) == 0
      && !cds_is_fw_down(v237, v238, v239, v240, v241, v242, v243, v244)
      && (cds_get_driver_state(v245, v246, v247, v248, v249, v250, v251, v252) & 4) == 0
      && v228 )
    {
      wma_trigger_recovery_assert_on_fw_timeout(4131, 2);
    }
    v88 = v20;
    v89 = 4132;
    goto LABEL_98;
  }
  v22 = *(_QWORD *)(v20 + 608);
  if ( (v22 & 1) != 0 )
  {
    *(_QWORD *)(v20 + 608) = v22 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v20 + 600);
  }
  else
  {
    raw_spin_unlock(v20 + 600);
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: unable to get msg node from request queue",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "wma_find_req_on_timer_expiry");
LABEL_21:
  result = qdf_trace_msg(
             0x36u,
             8u,
             "%s: Failed to lookup request message - %pK",
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             "wma_hold_req_timer",
             a1);
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
