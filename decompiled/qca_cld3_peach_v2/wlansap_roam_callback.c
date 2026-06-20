__int64 __fastcall wlansap_roam_callback(unsigned int *a1, __int64 a2, int a3, unsigned int a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  _QWORD *context; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _QWORD *v26; // x23
  unsigned int v27; // w24
  __int64 e_roam_cmd_status_str; // x25
  __int64 e_csr_roam_result_str; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int *v46; // x0
  __int64 v47; // x1
  __int64 v48; // x2
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  const char *v57; // x2
  unsigned int *v58; // x0
  __int64 v59; // x1
  __int64 v60; // x2
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 sap_ch_sw_info; // x0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  _DWORD *v79; // x24
  int v80; // w0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned int *v89; // x0
  __int64 v90; // x1
  __int64 v91; // x2
  unsigned int *v92; // x0
  __int64 v93; // x1
  __int64 v94; // x2
  char v95; // w8
  __int64 v96; // x3
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  size_t v105; // x2
  char is_dfs_cac_wait_state; // w0
  unsigned int v107; // w24
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  __int64 v124; // x24
  __int64 v125; // x24
  __int64 v126; // x24
  __int64 v127; // x24
  __int64 v128; // x24
  __int64 v129; // x24
  char v130; // w0
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  double v139; // d0
  char v140; // w0
  char v141; // w24
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  _DWORD *v149; // x0
  _DWORD *v150; // x24
  int v151; // w8
  int v152; // w8
  int v153; // w8
  __int64 v154; // x24
  __int64 v155; // x24
  __int64 v156; // x24
  __int64 v157; // x24
  __int64 v158; // x24
  __int64 v159; // x24
  __int64 v160; // [xsp+8h] [xbp-28h] BYREF
  __int64 v161; // [xsp+10h] [xbp-20h] BYREF
  __int64 v162; // [xsp+18h] [xbp-18h]
  __int64 v163; // [xsp+20h] [xbp-10h]
  __int64 v164; // [xsp+28h] [xbp-8h]

  v164 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v162 = 0;
  v163 = 0;
  v160 = 0;
  v161 = 0;
  if ( !(unsigned int)wlansap_context_get(a1) )
  {
    context = _cds_get_context(53, (__int64)"sap_get_mac_context", v8, v9, v10, v11, v12, v13, v14, v15);
    if ( !context )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Invalid MAC context",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "wlansap_roam_callback");
      wlansap_context_put(a1);
      result = 2;
      goto LABEL_98;
    }
    v26 = context;
    v27 = *((unsigned __int8 *)a1 + 12);
    e_roam_cmd_status_str = get_e_roam_cmd_status_str((unsigned int)a3);
    e_csr_roam_result_str = get_e_csr_roam_result_str(a4);
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: vdev %d status %s(%d) result %s(%d)",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlansap_roam_callback",
      v27,
      e_roam_cmd_status_str,
      (unsigned int)a3,
      e_csr_roam_result_str,
      a4);
    if ( a3 <= 37 )
    {
      if ( a3 <= 30 )
      {
        if ( a3 == 17 )
        {
          if ( a4 == 1 )
          {
            sap_signal_hdd_event(a1, a2, 6, 1);
LABEL_32:
            v61 = get_e_csr_roam_result_str(a4);
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: result %s(%d) not handled",
              v62,
              v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              "wlansap_roam_callback",
              v61,
              a4);
LABEL_97:
            wlansap_context_put(a1);
            result = HIDWORD(v160);
            goto LABEL_98;
          }
        }
        else if ( a3 == 18 && a4 == 8 )
        {
          v161 = a2;
          v162 = 0x120000000ALL;
          LODWORD(v163) = 8;
          if ( (unsigned int)sap_fsm(a1, &v161) )
            HIDWORD(v160) = 16;
          goto LABEL_32;
        }
LABEL_30:
        switch ( a4 )
        {
          case 0u:
            if ( a3 == 17 )
            {
              sap_signal_hdd_event(a1, a2, 6, 0);
              sap_check_and_process_go_force_scc(a1);
            }
            goto LABEL_97;
          case 2u:
            v92 = a1;
            v93 = a2;
            v94 = 5;
            goto LABEL_59;
          case 3u:
            v58 = a1;
            v59 = a2;
            v60 = 5;
            goto LABEL_67;
          case 4u:
          case 5u:
            v58 = a1;
            v59 = a2;
            v60 = 7;
            goto LABEL_67;
          case 6u:
            v92 = a1;
            v93 = a2;
            v94 = 6;
LABEL_59:
            sap_signal_hdd_event(v92, v93, v94, 0);
            goto LABEL_97;
          case 7u:
            if ( !a2 )
              goto LABEL_70;
            v95 = *(_BYTE *)(a2 + 41);
            v161 = a2;
            LODWORD(v162) = 7;
            HIDWORD(v162) = a3;
            *((_BYTE *)a1 + 1642) = v95;
            LODWORD(v163) = 7;
LABEL_50:
            if ( !(unsigned int)sap_fsm(a1, &v161) )
              goto LABEL_97;
            goto LABEL_68;
          case 9u:
            v161 = a2;
            LODWORD(v162) = 6;
            HIDWORD(v162) = a3;
            LODWORD(v163) = 9;
            goto LABEL_50;
          case 0xAu:
            if ( a2 )
              wlansap_roam_process_infra_assoc_ind(a1, a2, (char *)&v160 + 4);
            goto LABEL_97;
          case 0xBu:
            if ( a2 )
            {
              v105 = *(unsigned __int8 *)(a2 + 43);
              a1[306] = v105;
              if ( (_DWORD)v105 )
                qdf_mem_copy(a1 + 307, *(const void **)(a2 + 48), v105);
              v58 = a1;
              v59 = a2;
              v60 = 3;
LABEL_67:
              if ( (unsigned int)sap_signal_hdd_event(v58, v59, v60, 0) )
LABEL_68:
                HIDWORD(v160) = 16;
            }
            else
            {
LABEL_70:
              qdf_trace_msg(
                0x39u,
                2u,
                "%s: csr_roam_info is NULL",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "wlansap_roam_callback");
              HIDWORD(v160) = 29;
            }
            break;
          case 0xCu:
            v58 = a1;
            v59 = a2;
            v60 = 8;
            goto LABEL_67;
          case 0xDu:
            v58 = a1;
            v59 = a2;
            v60 = 12;
            goto LABEL_67;
          case 0xEu:
            if ( (policy_mgr_get_dfs_master_dynamic_enabled(v26[2703]) & 1) != 0 )
              wlansap_roam_process_dfs_radar_found(v26, a1, (char *)&v160 + 4);
            goto LABEL_97;
          case 0xFu:
            wlansap_roam_process_ch_change_success(v26, a1, a2, (char *)&v160 + 4);
            if ( HIDWORD(v160) )
              goto LABEL_53;
            v89 = a1;
            v90 = a2;
            v91 = 24;
            goto LABEL_95;
          case 0x10u:
LABEL_53:
            v89 = a1;
            v90 = a2;
            v91 = 24;
            v96 = 1;
            goto LABEL_96;
          case 0x11u:
            HIDWORD(v160) = wlansap_dfs_send_csa_ie_request(a1);
            if ( HIDWORD(v160) )
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: CSR roam_result = eCSR_ROAM_RESULT_CSA_RESTART_RSP %d",
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                v104,
                "wlansap_roam_callback",
                17);
            goto LABEL_97;
          case 0x12u:
            wlansap_roam_process_dfs_chansw_update(v26, a1, (char *)&v160 + 4);
            goto LABEL_97;
          case 0x13u:
            v58 = a1;
            v59 = a2;
            v60 = 22;
            goto LABEL_67;
          case 0x16u:
            sap_dfs_cac_timer_callback(v26);
            goto LABEL_97;
          case 0x17u:
            v89 = a1;
            v90 = a2;
            v91 = 25;
LABEL_95:
            v96 = 0;
LABEL_96:
            HIDWORD(v160) = sap_signal_hdd_event(v89, v90, v91, v96);
            break;
          default:
            goto LABEL_32;
        }
        goto LABEL_97;
      }
      if ( a3 == 31 )
      {
        v46 = a1;
        v47 = a2;
        v48 = 9;
      }
      else
      {
        if ( a3 != 32 )
          goto LABEL_30;
        v46 = a1;
        v47 = a2;
        v48 = 10;
      }
LABEL_29:
      sap_signal_hdd_event(v46, v47, v48, 0);
      goto LABEL_30;
    }
    if ( a3 > 46 )
    {
      if ( a3 != 47 )
      {
        if ( a3 == 50 )
          wlansap_process_chan_info_event(a1, a2);
        goto LABEL_30;
      }
      sap_ch_sw_info = wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), v38, v39, v40, v41, v42, v43, v44, v45);
      if ( !sap_ch_sw_info )
      {
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: Invalid channel info",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "wlansap_update_vendor_acs_chan");
        goto LABEL_30;
      }
      v79 = (_DWORD *)sap_ch_sw_info;
      v80 = wlan_reg_legacy_chan_to_freq(
              v26[2704],
              *((unsigned __int8 *)a1 + 1629),
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78);
      *v79 = v80;
      v79[4] = *((unsigned __int8 *)a1 + 1630);
      v79[5] = *((unsigned __int8 *)a1 + 1630);
      if ( !v80 )
      {
        qdf_trace_msg(
          0x39u,
          3u,
          "%s: Failed to get channel from userspace",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          "wlansap_update_vendor_acs_chan");
        if ( (*((_DWORD *)v26 + 3724) | 2) == 3 )
        {
          v124 = v26[1861];
          if ( v124 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: sapdfs: no available channel for sapctx[%pK], StopBss",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wlansap_update_vendor_acs_chan",
              v26[1861]);
            wlansap_stop_bss(v124);
          }
        }
        if ( (*((_DWORD *)v26 + 3728) | 2) == 3 )
        {
          v125 = v26[1863];
          if ( v125 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: sapdfs: no available channel for sapctx[%pK], StopBss",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wlansap_update_vendor_acs_chan",
              v26[1863]);
            wlansap_stop_bss(v125);
          }
        }
        if ( (*((_DWORD *)v26 + 3732) | 2) == 3 )
        {
          v126 = v26[1865];
          if ( v126 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: sapdfs: no available channel for sapctx[%pK], StopBss",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wlansap_update_vendor_acs_chan",
              v26[1865]);
            wlansap_stop_bss(v126);
          }
        }
        if ( (*((_DWORD *)v26 + 3736) | 2) == 3 )
        {
          v127 = v26[1867];
          if ( v127 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: sapdfs: no available channel for sapctx[%pK], StopBss",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wlansap_update_vendor_acs_chan",
              v26[1867]);
            wlansap_stop_bss(v127);
          }
        }
        if ( (*((_DWORD *)v26 + 3740) | 2) == 3 )
        {
          v128 = v26[1869];
          if ( v128 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: sapdfs: no available channel for sapctx[%pK], StopBss",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wlansap_update_vendor_acs_chan",
              v26[1869]);
            wlansap_stop_bss(v128);
          }
        }
        if ( (*((_DWORD *)v26 + 3744) | 2) == 3 )
        {
          v129 = v26[1871];
          if ( v129 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: sapdfs: no available channel for sapctx[%pK], StopBss",
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45,
              "wlansap_update_vendor_acs_chan",
              v26[1871]);
            wlansap_stop_bss(v129);
          }
        }
        goto LABEL_30;
      }
    }
    else
    {
      if ( a3 != 38 )
      {
        if ( a3 == 39 )
          if_mgr_deliver_event(*((_QWORD *)a1 + 2), 0x12u, 0, v38, v39, v40, v41, v42, v43, v44, v45);
        goto LABEL_30;
      }
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: Rcvd Radar Indication on sap ch freq %d, session %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "wlansap_roam_callback",
        *a1,
        *((unsigned __int8 *)a1 + 12));
      if ( (policy_mgr_get_dfs_master_dynamic_enabled(v26[2703]) & 1) == 0 )
      {
        v57 = "%s: Ignore the Radar indication";
        goto LABEL_37;
      }
      if ( a1[182] == 2 )
        goto LABEL_26;
      is_dfs_cac_wait_state = sap_is_dfs_cac_wait_state(a1);
      v107 = a1[182];
      if ( (is_dfs_cac_wait_state & 1) == 0 )
      {
        v130 = sap_is_dfs_cac_wait_state(a1);
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: Ignore Radar event in sap state %d cac wait state %d",
          v131,
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          "wlansap_roam_callback",
          v107,
          v130 & 1);
        goto LABEL_97;
      }
      if ( v107 == 2 )
      {
LABEL_26:
        if ( (sap_is_csa_vdev_restart_state(v26[2703], a1) & 1) != 0 )
        {
          v57 = "%s: Ignore Radar event in csa restart state";
LABEL_37:
          qdf_trace_msg(0x39u, 8u, v57, v49, v50, v51, v52, v53, v54, v55, v56, "wlansap_roam_callback");
          goto LABEL_97;
        }
      }
      if ( (sap_chan_bond_dfs_sub_chan(a1, *a1, 11) & 1) == 0 )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: Ignore Radar event for sap ch freq: %d",
          v108,
          v109,
          v110,
          v111,
          v112,
          v113,
          v114,
          v115,
          "wlansap_roam_callback",
          *a1);
        goto LABEL_97;
      }
      if ( (wlan_pre_cac_get_status(v26[2703]) & 1) != 0 )
      {
        wlan_sap_pre_cac_radar_ind(a1, v26);
        goto LABEL_30;
      }
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sapdfs: Indicate eSAP_DFS_RADAR_DETECT to HDD",
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        "wlansap_roam_callback");
      sap_signal_hdd_event(a1, 0, 17, 0);
      v139 = sap_is_chan_change_needed_for_radar(a1, &v160);
      v141 = v140;
      v149 = (_DWORD *)wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), v139, v142, v143, v144, v145, v146, v147, v148);
      if ( !v149 )
      {
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: Invalid channel info",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wlansap_roam_callback");
        goto LABEL_97;
      }
      if ( !(v141 & 1 | ((_DWORD)v160 != 0)) )
      {
        *v149 = 0;
        *((_BYTE *)a1 + 13) = 0;
        goto LABEL_30;
      }
      if ( (v141 & 1) != 0 || !(_DWORD)v160 )
      {
        v150 = v149;
        v151 = sap_indicate_radar(a1);
        v149 = v150;
        *v150 = v151;
      }
      else
      {
        *v149 = v160;
        *((_BYTE *)a1 + 13) = 1;
      }
      v152 = v149[1];
      if ( v152 )
      {
        *v149 = v152;
        v149[1] = 0;
      }
      v153 = *v149;
      if ( *((_BYTE *)a1 + 1628) == 1 )
      {
        if ( !v153 )
          goto LABEL_97;
      }
      else if ( !v153 )
      {
        if ( (*((_DWORD *)v26 + 3724) | 2) == 3 )
        {
          v154 = v26[1861];
          if ( v154 )
          {
            if ( wlan_reg_is_passive_or_disable_for_pwrmode(
                   v26[2704],
                   *(_DWORD *)v154,
                   0,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45) )
            {
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: Vdev %d no channel available , stop bss",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "wlansap_roam_callback",
                *(unsigned __int8 *)(v154 + 12));
              sap_signal_hdd_event(v154, 0, 19, 0);
            }
          }
        }
        if ( (*((_DWORD *)v26 + 3728) | 2) == 3 )
        {
          v155 = v26[1863];
          if ( v155 )
          {
            if ( wlan_reg_is_passive_or_disable_for_pwrmode(
                   v26[2704],
                   *(_DWORD *)v155,
                   0,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45) )
            {
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: Vdev %d no channel available , stop bss",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "wlansap_roam_callback",
                *(unsigned __int8 *)(v155 + 12));
              sap_signal_hdd_event(v155, 0, 19, 0);
            }
          }
        }
        if ( (*((_DWORD *)v26 + 3732) | 2) == 3 )
        {
          v156 = v26[1865];
          if ( v156 )
          {
            if ( wlan_reg_is_passive_or_disable_for_pwrmode(
                   v26[2704],
                   *(_DWORD *)v156,
                   0,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45) )
            {
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: Vdev %d no channel available , stop bss",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "wlansap_roam_callback",
                *(unsigned __int8 *)(v156 + 12));
              sap_signal_hdd_event(v156, 0, 19, 0);
            }
          }
        }
        if ( (*((_DWORD *)v26 + 3736) | 2) == 3 )
        {
          v157 = v26[1867];
          if ( v157 )
          {
            if ( wlan_reg_is_passive_or_disable_for_pwrmode(
                   v26[2704],
                   *(_DWORD *)v157,
                   0,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45) )
            {
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: Vdev %d no channel available , stop bss",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "wlansap_roam_callback",
                *(unsigned __int8 *)(v157 + 12));
              sap_signal_hdd_event(v157, 0, 19, 0);
            }
          }
        }
        if ( (*((_DWORD *)v26 + 3740) | 2) == 3 )
        {
          v158 = v26[1869];
          if ( v158 )
          {
            if ( wlan_reg_is_passive_or_disable_for_pwrmode(
                   v26[2704],
                   *(_DWORD *)v158,
                   0,
                   v38,
                   v39,
                   v40,
                   v41,
                   v42,
                   v43,
                   v44,
                   v45) )
            {
              qdf_trace_msg(
                0x39u,
                8u,
                "%s: Vdev %d no channel available , stop bss",
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                "wlansap_roam_callback",
                *(unsigned __int8 *)(v158 + 12));
              sap_signal_hdd_event(v158, 0, 19, 0);
            }
          }
        }
        if ( (*((_DWORD *)v26 + 3744) | 2) != 3 )
          goto LABEL_30;
        v159 = v26[1871];
        if ( !v159
          || !wlan_reg_is_passive_or_disable_for_pwrmode(
                v26[2704],
                *(_DWORD *)v159,
                0,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45) )
        {
          goto LABEL_30;
        }
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: Vdev %d no channel available , stop bss",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "wlansap_roam_callback",
          *(unsigned __int8 *)(v159 + 12));
        v46 = (unsigned int *)v159;
        v47 = 0;
        v48 = 19;
        goto LABEL_29;
      }
    }
    sap_cac_reset_notify(v26);
    goto LABEL_30;
  }
  result = 16;
LABEL_98:
  _ReadStatusReg(SP_EL0);
  return result;
}
