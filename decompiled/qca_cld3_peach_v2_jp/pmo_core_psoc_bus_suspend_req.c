__int64 __fastcall pmo_core_psoc_bus_suspend_req(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int ref; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  __int64 result; // x0
  const char *v25; // x2
  __int64 comp_private_obj; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v37; // x8
  unsigned int v38; // w21
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x25
  int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 hif_handle; // x21
  unsigned __int64 v59; // x8
  __int64 v60; // x8
  unsigned int host_credits; // w23
  unsigned int pending_cmnds; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  int v79; // w8
  int v80; // w4
  __int64 v81; // x8
  __int64 v82; // x0
  __int64 v83; // x23
  unsigned __int64 v84; // x8
  __int64 v85; // x8
  __int64 *v86; // x24
  int v87; // w4
  int v88; // w8
  __int64 v89; // x0
  __int64 v90; // x23
  unsigned __int64 v91; // x8
  __int64 v92; // x8
  __int64 *v93; // x24
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 v118; // x0
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  const char *v135; // x2
  unsigned int v136; // w1
  int v137; // w0
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  int v146; // w20
  int v147; // w0
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  int v156; // w23
  unsigned int v157; // w22
  unsigned int v158; // w0
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  unsigned __int64 v167; // x8
  __int64 v168; // x8
  int v169; // w21
  unsigned __int64 v170; // x8
  __int64 v171; // x8
  unsigned int v172; // w21
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  int v181; // w21
  unsigned int v182; // w22
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  __int64 v191; // x0
  __int64 v192; // x23
  unsigned __int64 v193; // x8
  __int64 v194; // x8
  __int64 v195; // x24
  unsigned __int64 v196; // x8
  __int64 v197; // x8
  unsigned __int64 v198; // x8
  unsigned int v199; // w20
  unsigned __int64 v200; // x8
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  __int64 v209; // [xsp+0h] [xbp-10h] BYREF
  __int64 v210; // [xsp+8h] [xbp-8h]

  v210 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v25 = "%s: psoc is NULL";
LABEL_7:
    qdf_trace_msg(0x4Du, 2u, v25, a4, a5, a6, a7, a8, a9, a10, a11, "pmo_core_psoc_bus_suspend_req");
    result = 29;
    goto LABEL_8;
  }
  if ( !a3 )
  {
    v25 = "%s: wow_params is NULL";
    goto LABEL_7;
  }
  ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( ref )
  {
    v23 = ref;
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: pmo cannot get the reference out of psoc",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "pmo_core_psoc_bus_suspend_req");
    result = v23;
    goto LABEL_8;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v35 = comp_private_obj;
  if ( comp_private_obj )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(comp_private_obj + 1040);
      v37 = *(_QWORD *)(v35 + 1048);
      v38 = *(unsigned __int8 *)(v35 + 488);
      if ( (v37 & 1) == 0 )
      {
LABEL_14:
        raw_spin_unlock(v35 + 1040);
LABEL_15:
        qdf_trace_msg(
          0x4Du,
          8u,
          "%s: WoW enable %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "pmo_core_is_wow_enabled",
          v38);
        goto LABEL_17;
      }
    }
    else
    {
      raw_spin_lock_bh(comp_private_obj + 1040);
      v37 = *(_QWORD *)(v35 + 1048) | 1LL;
      *(_QWORD *)(v35 + 1048) = v37;
      v38 = *(unsigned __int8 *)(v35 + 488);
      if ( (v37 & 1) == 0 )
        goto LABEL_14;
    }
    *(_QWORD *)(v35 + 1048) = v37 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v35 + 1040);
    goto LABEL_15;
  }
  qdf_trace_msg(0x4Du, 2u, "%s: psoc_ctx is null", v27, v28, v29, v30, v31, v32, v33, v34, "pmo_core_is_wow_enabled");
  v38 = 0;
LABEL_17:
  __isb(0xFu);
  v47 = _ReadStatusReg(CNTVCT_EL0);
  if ( 10 * v47 >= v47 )
  {
    v48 = 10 * v47 / 0xC0;
    if ( !v38 )
      goto LABEL_19;
LABEL_21:
    v209 = 0;
    hif_handle = pmo_core_psoc_get_hif_handle(a1);
    qdf_event_reset(v35 + 496);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v59 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v59 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v59 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v35 + 1040);
      v60 = *(_QWORD *)(v35 + 1048);
    }
    else
    {
      raw_spin_lock_bh(v35 + 1040);
      v60 = *(_QWORD *)(v35 + 1048) | 1LL;
      *(_QWORD *)(v35 + 1048) = v60;
    }
    *(_BYTE *)(v35 + 576) = 0;
    *(_WORD *)(v35 + 578) = 0;
    if ( (v60 & 1) != 0 )
    {
      *(_QWORD *)(v35 + 1048) = v60 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v35 + 1040);
    }
    else
    {
      raw_spin_unlock(v35 + 1040);
    }
    host_credits = pmo_tgt_psoc_get_host_credits(a1);
    pending_cmnds = pmo_tgt_psoc_get_pending_cmnds(a1);
    qdf_trace_msg(
      0x4Du,
      8u,
      "%s: Credits:%d; Pending_Cmds: %d",
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      "pmo_core_enable_wow_in_fw",
      host_credits,
      pending_cmnds,
      v209,
      v210);
    v79 = *a3;
    LOBYTE(v209) = 1;
    if ( v79 == 1 )
      HIDWORD(v209) = 4;
    v80 = *((_DWORD *)a3 + 1);
    if ( v80 )
    {
      if ( v80 == 1 )
      {
        LOBYTE(v81) = 1;
LABEL_43:
        BYTE1(v209) = v81;
LABEL_44:
        v87 = *((_DWORD *)a3 + 2);
        if ( v87 )
        {
          if ( v87 == 1 )
          {
            HIDWORD(v209) |= 8u;
          }
          else if ( v87 != 2 )
          {
            qdf_trace_msg(
              0x4Du,
              2u,
              "%s: Invalid resume trigger setting: %d",
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "pmo_core_enable_wow_in_fw");
          }
        }
        if ( *(_BYTE *)(v35 + 15) != 1 || (*(_BYTE *)(v35 + 955) & 1) != 0 || (v209 & 0x100) != 0 )
        {
          if ( BYTE1(v209) == 1 )
            v88 = 3;
          else
            v88 = 2;
        }
        else
        {
          v88 = 1;
        }
        *(_DWORD *)(v35 + 492) = v88;
        v89 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
        if ( v89 )
        {
          v90 = v89;
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (v91 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v91 + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(v91 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v89 + 1040);
            v92 = *(_QWORD *)(v90 + 1048);
            v93 = *(__int64 **)(v90 + 968);
            if ( (v92 & 1) == 0 )
            {
LABEL_61:
              raw_spin_unlock(v90 + 1040);
              goto LABEL_63;
            }
          }
          else
          {
            raw_spin_lock_bh(v89 + 1040);
            v92 = *(_QWORD *)(v90 + 1048) | 1LL;
            *(_QWORD *)(v90 + 1048) = v92;
            v93 = *(__int64 **)(v90 + 968);
            if ( (v92 & 1) == 0 )
              goto LABEL_61;
          }
          *(_QWORD *)(v90 + 1048) = v92 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v90 + 1040);
        }
        else
        {
          v93 = nullptr;
        }
LABEL_63:
        if ( (htc_can_suspend_link(v93) & 1) != 0 )
        {
          if ( (qdf_is_drv_connected(v94, v95, v96, v97, v98, v99, v100, v101) & 1) != 0 )
          {
            qdf_trace_msg(
              0x4Du,
              4u,
              "%s: drv wow is enabled",
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              "pmo_core_enable_wow_in_fw");
            HIDWORD(v209) |= 0x10u;
          }
          else
          {
            qdf_trace_msg(
              0x4Du,
              8u,
              "%s: non-drv wow is enabled",
              v102,
              v103,
              v104,
              v105,
              v106,
              v107,
              v108,
              v109,
              "pmo_core_enable_wow_in_fw");
          }
        }
        else
        {
          v118 = qdf_trace_msg(
                   0x4Du,
                   4u,
                   "%s: Prevent link down, non-drv wow is enabled",
                   v94,
                   v95,
                   v96,
                   v97,
                   v98,
                   v99,
                   v100,
                   v101,
                   "pmo_core_enable_wow_in_fw");
          if ( hif_handle )
          {
            ((void (__fastcall *)(__int64))hif_rtpm_print_prevent_list)(v118);
            htc_log_link_user_votes();
          }
        }
        if ( *a3 == 1 )
        {
          qdf_trace_msg(
            0x4Du,
            4u,
            "%s: Unit test WoW, force DRV mode",
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            v116,
            v117,
            "pmo_core_enable_wow_in_fw");
          HIDWORD(v209) |= 0x10u;
        }
        pmo_set_wow_suspend_type(a1, a2);
        if ( a2 == 2 )
        {
          v135 = "%s: unit test wow suspend";
          v136 = 4;
        }
        else
        {
          if ( !a2 )
          {
            qdf_trace_msg(
              0x4Du,
              4u,
              "%s: system suspend wow",
              v119,
              v120,
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              "pmo_core_enable_wow_in_fw");
            HIDWORD(v209) |= 0x20u;
            goto LABEL_77;
          }
          v135 = "%s: RTPM wow";
          v136 = 8;
        }
        qdf_trace_msg(
          0x4Du,
          v136,
          v135,
          v119,
          v120,
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          "pmo_core_enable_wow_in_fw",
          v209);
LABEL_77:
        if ( *(_BYTE *)(v35 + 81) == 1 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: mod DTIM enabled",
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            "pmo_core_enable_wow_in_fw");
          HIDWORD(v209) |= 0x40u;
        }
        if ( *(_BYTE *)(v35 + 82) == 1 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: teles DTIM enabled",
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            "pmo_core_enable_wow_in_fw");
          HIDWORD(v209) |= 0x200u;
        }
        if ( *(_BYTE *)(v35 + 30) == 1 )
        {
          qdf_trace_msg(
            0x4Du,
            8u,
            "%s: forced DTIM enabled",
            v127,
            v128,
            v129,
            v130,
            v131,
            v132,
            v133,
            v134,
            "pmo_core_enable_wow_in_fw");
          HIDWORD(v209) |= 0x80u;
        }
        v137 = pmo_tgt_psoc_send_wow_enable_req(a1, &v209);
        if ( v137 )
        {
          v146 = v137;
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Failed to enable wow in fw",
            v138,
            v139,
            v140,
            v141,
            v142,
            v143,
            v144,
            v145,
            "pmo_core_enable_wow_in_fw");
          v49 = v146;
          goto LABEL_130;
        }
        pmo_tgt_update_target_suspend_flag(a1, 1);
        v147 = qdf_wait_for_event_completion(v35 + 496, 0xFA0u);
        if ( v147 )
        {
          v156 = v147;
          if ( hif_handle )
          {
            hif_display_ctrl_traffic_pipes_state(hif_handle, v148, v149, v150, v151, v152, v153, v154, v155);
            hif_display_latest_desc_hist(hif_handle);
          }
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Failed to receive WoW Enable Ack from FW",
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            v154,
            v155,
            "pmo_core_enable_wow_in_fw",
            v209);
          v157 = pmo_tgt_psoc_get_host_credits(a1);
          v158 = pmo_tgt_psoc_get_pending_cmnds(a1);
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Credits:%d; Pending_Cmds: %d",
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            v165,
            v166,
            "pmo_core_enable_wow_in_fw",
            v157,
            v158);
          if ( (*(_BYTE *)(v35 + 533) & 1) == 0 )
          {
            pmo_tgt_psoc_set_wow_enable_ack_failed(a1);
            _qdf_trigger_self_recovery();
          }
          pmo_tgt_update_target_suspend_flag(a1, 0);
          v49 = v156;
          goto LABEL_130;
        }
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v167 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v167 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v167 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v35 + 1040);
          v168 = *(_QWORD *)(v35 + 1048);
          v169 = *(unsigned __int8 *)(v35 + 576);
          if ( (v168 & 1) == 0 )
            goto LABEL_95;
        }
        else
        {
          raw_spin_lock_bh(v35 + 1040);
          v168 = *(_QWORD *)(v35 + 1048) | 1LL;
          *(_QWORD *)(v35 + 1048) = v168;
          v169 = *(unsigned __int8 *)(v35 + 576);
          if ( (v168 & 1) == 0 )
          {
LABEL_95:
            raw_spin_unlock(v35 + 1040);
            if ( v169 )
            {
LABEL_96:
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (v170 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v170 + 16) & 0xF0000) != 0)
                || (*(_DWORD *)(v170 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v35 + 1040);
                v171 = *(_QWORD *)(v35 + 1048);
                v172 = *(unsigned __int16 *)(v35 + 578);
                if ( (v171 & 1) == 0 )
                {
LABEL_100:
                  raw_spin_unlock(v35 + 1040);
LABEL_101:
                  qdf_trace_msg(
                    0x4Du,
                    2u,
                    "%s: FW not ready to WOW reason code: %d",
                    v173,
                    v174,
                    v175,
                    v176,
                    v177,
                    v178,
                    v179,
                    v180,
                    "pmo_core_enable_wow_in_fw",
                    v172,
                    v209);
                  pmo_tgt_update_target_suspend_flag(a1, 0);
                  v49 = 3;
                  goto LABEL_130;
                }
              }
              else
              {
                raw_spin_lock_bh(v35 + 1040);
                v171 = *(_QWORD *)(v35 + 1048) | 1LL;
                *(_QWORD *)(v35 + 1048) = v171;
                v172 = *(unsigned __int16 *)(v35 + 578);
                if ( (v171 & 1) == 0 )
                  goto LABEL_100;
              }
              *(_QWORD *)(v35 + 1048) = v171 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v35 + 1040);
              goto LABEL_101;
            }
LABEL_112:
            pmo_tgt_update_target_suspend_acked_flag(a1, 1);
            v181 = pmo_tgt_psoc_get_host_credits(a1);
            v182 = pmo_tgt_psoc_get_pending_cmnds(a1);
            if ( v181 > 0 )
            {
LABEL_121:
              qdf_trace_msg(
                0x4Du,
                8u,
                "%s: WOW enabled successfully in fw: credits:%d pending_cmds: %d",
                v183,
                v184,
                v185,
                v186,
                v187,
                v188,
                v189,
                v190,
                "pmo_core_enable_wow_in_fw",
                (unsigned int)v181,
                v182,
                v209);
              pmo_core_psoc_get_hif_handle(a1);
              if ( (unsigned int)hif_rtpm_get_autosuspend_delay() == 1200 )
                hif_rtpm_restore_autosuspend_delay();
              if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                || (v196 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v196 + 16) & 0xF0000) != 0)
                || (*(_DWORD *)(v196 + 16) & 0xFF00) != 0 )
              {
                raw_spin_lock(v35 + 1040);
                v197 = *(_QWORD *)(v35 + 1048);
              }
              else
              {
                raw_spin_lock_bh(v35 + 1040);
                v197 = *(_QWORD *)(v35 + 1048) | 1LL;
                *(_QWORD *)(v35 + 1048) = v197;
              }
              *(_BYTE *)(v35 + 489) = 1;
              if ( (v197 & 1) != 0 )
              {
                *(_QWORD *)(v35 + 1048) = v197 & 0xFFFFFFFFFFFFFFFELL;
                raw_spin_unlock_bh(v35 + 1040);
              }
              else
              {
                raw_spin_unlock(v35 + 1040);
              }
              v49 = 0;
              goto LABEL_130;
            }
            qdf_trace_msg(
              0x4Du,
              2u,
              "%s: No Credits after HTC ACK:%d, pending_cmds:%d,cannot resume back",
              v183,
              v184,
              v185,
              v186,
              v187,
              v188,
              v189,
              v190,
              "pmo_core_enable_wow_in_fw",
              (unsigned int)v181,
              v182);
            v191 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
            if ( !v191 )
            {
              v195 = 0;
              goto LABEL_120;
            }
            v192 = v191;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (v193 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v193 + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(v193 + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(v191 + 1040);
              v194 = *(_QWORD *)(v192 + 1048);
              v195 = *(_QWORD *)(v192 + 968);
              if ( (v194 & 1) == 0 )
              {
LABEL_118:
                raw_spin_unlock(v192 + 1040);
LABEL_120:
                htc_dump_counter_info(v195);
                _qdf_trigger_self_recovery();
                goto LABEL_121;
              }
            }
            else
            {
              raw_spin_lock_bh(v191 + 1040);
              v194 = *(_QWORD *)(v192 + 1048) | 1LL;
              *(_QWORD *)(v192 + 1048) = v194;
              v195 = *(_QWORD *)(v192 + 968);
              if ( (v194 & 1) == 0 )
                goto LABEL_118;
            }
            *(_QWORD *)(v192 + 1048) = v194 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v192 + 1040);
            goto LABEL_120;
          }
        }
        *(_QWORD *)(v35 + 1048) = v168 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v35 + 1040);
        if ( v169 )
          goto LABEL_96;
        goto LABEL_112;
      }
      if ( v80 == 2 )
      {
        BYTE1(v209) = 0;
        goto LABEL_44;
      }
      qdf_trace_msg(
        0x4Du,
        2u,
        "%s: Invalid interface pause setting: %d",
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        "pmo_core_enable_wow_in_fw",
        v209);
    }
    v82 = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( !v82 )
    {
      v86 = nullptr;
      goto LABEL_42;
    }
    v83 = v82;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (v84 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v84 + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(v84 + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v82 + 1040);
      v85 = *(_QWORD *)(v83 + 1048);
      v86 = *(__int64 **)(v83 + 968);
      if ( (v85 & 1) == 0 )
      {
LABEL_40:
        raw_spin_unlock(v83 + 1040);
LABEL_42:
        v81 = htc_can_suspend_link(v86) & 1;
        goto LABEL_43;
      }
    }
    else
    {
      raw_spin_lock_bh(v82 + 1040);
      v85 = *(_QWORD *)(v83 + 1048) | 1LL;
      *(_QWORD *)(v83 + 1048) = v85;
      v86 = *(__int64 **)(v83 + 968);
      if ( (v85 & 1) == 0 )
        goto LABEL_40;
    }
    *(_QWORD *)(v83 + 1048) = v85 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v83 + 1040);
    goto LABEL_42;
  }
  v48 = 10 * (v47 / 0xC0);
  if ( v38 )
    goto LABEL_21;
LABEL_19:
  v49 = pmo_core_psoc_suspend_target(a1, 0);
LABEL_130:
  __isb(0xFu);
  v198 = _ReadStatusReg(CNTVCT_EL0);
  v199 = v49;
  if ( 10 * v198 >= v198 )
    v200 = 10 * v198 / 0xC0;
  else
    v200 = 10 * (v198 / 0xC0);
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: fw took total time %lu microseconds to enable wow",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "pmo_core_psoc_bus_suspend_req",
    v200 - v48,
    v209);
  wlan_objmgr_psoc_release_ref(a1, 0xAu, v201, v202, v203, v204, v205, v206, v207, v208);
  result = v199;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
