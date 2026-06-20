__int64 __fastcall hdd_softap_set_channel_change(
        __int64 *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        char a6,
        char a7)
{
  __int64 v14; // x26
  __int64 v15; // x22
  __int64 *v16; // x20
  unsigned int sta_sap_scc_on_dfs_chnl; // w24
  __int64 v18; // x24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int ll_lt_sap_freq; // w24
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  int v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  unsigned __int8 *ie_ptr_from_eid; // x24
  unsigned __int8 *v71; // x22
  unsigned int param; // w0
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 adapter; // x24
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  const char *v98; // x2
  int v100; // w22
  __int64 v102; // x20
  __int64 v103; // x20
  bool is_5ghz_ch_freq; // w0
  unsigned int v110; // w9
  signed int v111; // w9
  double csa_chanwidth_from_phymode; // d0
  unsigned int v113; // w0
  unsigned int v114; // w27
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned int v122; // w0
  __int64 v123; // x24
  unsigned int v124; // w28
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  unsigned int bw; // w0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  unsigned int v142; // w0
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  unsigned int v151; // w24
  int v152; // w8
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  __int64 vdev_by_user; // x0
  __int64 v170; // x24
  char v171; // w23
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  unsigned int v180; // [xsp+Ch] [xbp-164h]
  __int64 v181; // [xsp+10h] [xbp-160h]
  unsigned int v182; // [xsp+1Ch] [xbp-154h]
  __int64 v183; // [xsp+20h] [xbp-150h] BYREF
  __int64 v184; // [xsp+28h] [xbp-148h]
  __int64 v185; // [xsp+30h] [xbp-140h]
  _BYTE v186[4]; // [xsp+38h] [xbp-138h] BYREF
  _BYTE v187[4]; // [xsp+3Ch] [xbp-134h] BYREF
  _DWORD s[72]; // [xsp+40h] [xbp-130h] BYREF
  __int64 v189; // [xsp+160h] [xbp-10h]

  v189 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v187[0] = 0;
  v184 = 0;
  v185 = 0;
  v183 = 0;
  memset(s, 0, sizeof(s));
  if ( !a1 )
    goto LABEL_31;
  v14 = *a1;
  v182 = a5;
  v15 = a1[304];
  v186[0] = 0;
  v16 = *(__int64 **)(v14 + 24);
  sta_sap_scc_on_dfs_chnl = _wlan_hdd_validate_context(v16, "hdd_softap_set_channel_change");
  if ( !sta_sap_scc_on_dfs_chnl )
  {
    if ( (*(_DWORD *)(v14 + 40) | 2) != 3 )
      goto LABEL_31;
    v18 = a1[34];
    if ( !v18 )
      goto LABEL_31;
    if ( (hdd_is_sta_connect_or_link_switch_in_prog(v16) & 1) != 0
      || *(_DWORD *)(v14 + 40) == 3 && (ucfg_p2p_is_p2p_go_noa_in_progress(v16[1], *((_BYTE *)a1 + 8)) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: vdev %d Do not allow CSA, STA connect/link switch/eapol/noa is in progress",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "hdd_softap_set_channel_change",
        *((unsigned __int8 *)a1 + 8));
      sta_sap_scc_on_dfs_chnl = -16;
    }
    else
    {
      if ( policy_mgr_is_vdev_ll_lt_sap(*v16, *(unsigned __int8 *)(*(_QWORD *)(v18 + 16) + 168LL))
        && (*(_DWORD *)(v18 + 732) | 8) != 0xA )
      {
        wlan_hdd_set_sap_csa_reason(*v16, *((_BYTE *)a1 + 8), 0x10u);
        hdd_dcs_trigger_csa_for_ll_lt_sap(*v16, v16, *(unsigned __int8 *)(*(_QWORD *)(v18 + 16) + 168LL), 0);
        sta_sap_scc_on_dfs_chnl = 0;
        goto LABEL_32;
      }
      v181 = v18;
      ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(*v16);
      v36 = policy_mgr_qdf_opmode_to_pm_con_mode(
              *v16,
              *(_DWORD *)(v14 + 40),
              *((_BYTE *)a1 + 8),
              v28,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35);
      if ( ll_lt_sap_freq && v36 == 1 && (policy_mgr_are_2_freq_on_same_mac(*v16, a2, ll_lt_sap_freq) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: ll_sap freq %d and sap freq %d are on same mac",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "hdd_softap_set_channel_change",
          ll_lt_sap_freq,
          a2);
LABEL_31:
        sta_sap_scc_on_dfs_chnl = -22;
        goto LABEL_32;
      }
      if ( wlan_reg_is_6ghz_chan_freq(a2)
        && (wlan_reg_is_6ghz_band_set(v16[1], v45, v46, v47, v48, v49, v50, v51, v52) & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: 6 GHz band disabled",
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          "hdd_softap_set_channel_change");
        goto LABEL_31;
      }
      v61 = hdd_validate_channel_and_bandwidth(v14, a2, a3, a4);
      if ( v61 )
      {
        sta_sap_scc_on_dfs_chnl = v61;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid CH and BW combo",
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          "hdd_softap_set_channel_change");
        goto LABEL_32;
      }
      if ( wlan_reg_is_6ghz_chan_freq(a2) )
      {
        ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x30u, *(unsigned __int8 **)(v15 + 8), *(_DWORD *)(v15 + 36));
        v71 = wlan_get_ie_ptr_from_eid(0xF4u, *(unsigned __int8 **)(v15 + 8), *(_DWORD *)(v15 + 36));
        if ( ie_ptr_from_eid )
          wlan_crypto_rsnie_check(s, ie_ptr_from_eid, nullptr);
        param = wlan_crypto_get_param(*(_QWORD *)(v181 + 16), 7u);
        if ( (param & 0x80000000) != 0 )
        {
          v102 = jiffies;
          if ( hdd_softap_set_channel_change___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Invalid keymgmt",
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              "hdd_softap_set_channel_change");
            hdd_softap_set_channel_change___last_ticks = v102;
          }
          goto LABEL_31;
        }
        if ( (wlan_cm_6ghz_allowed_for_akm(*v16, param, s[38], (__int64)v71, 0, *(_DWORD *)(v14 + 40) == 3) & 1) == 0 )
        {
          v103 = jiffies;
          if ( hdd_softap_set_channel_change___last_ticks_92 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: 6Ghz channel switch not capable",
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              "hdd_softap_set_channel_change");
            hdd_softap_set_channel_change___last_ticks_92 = v103;
          }
          goto LABEL_31;
        }
      }
      adapter = hdd_get_adapter(v16, 0);
      ucfg_policy_mgr_get_conc_rule1(*v16, v187);
      if ( adapter && v187[0] && hdd_cm_is_vdev_associated(*(_DWORD **)(adapter + 52832)) )
      {
        v98 = "%s: Channel switch not allowed after STA connection with conc_custom_rule1 enabled";
LABEL_28:
        qdf_trace_msg(0x33u, 2u, v98, v90, v91, v92, v93, v94, v95, v96, v97, "hdd_softap_set_channel_change");
        sta_sap_scc_on_dfs_chnl = -16;
        goto LABEL_32;
      }
      v100 = policy_mgr_mode_specific_connection_count(*v16, 0, nullptr);
      sta_sap_scc_on_dfs_chnl = policy_mgr_get_sta_sap_scc_on_dfs_chnl(*v16, v186);
      if ( sta_sap_scc_on_dfs_chnl )
        goto LABEL_32;
      if ( (policy_mgr_is_sap_go_interface_allowed_on_indoor(v16[1], *((unsigned __int8 *)a1 + 8), a2) & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Channel switch is not allowed to indoor frequency %d",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "hdd_softap_set_channel_change",
          a2);
        goto LABEL_31;
      }
      if ( !v100 && (policy_mgr_is_hw_dbs_capable(*v16) & 1) == 0 && v186[0] == 1 )
      {
        if ( (wlan_reg_is_dfs_for_freq(v16[1], a2, v90, v91, v92, v93, v94, v95, v96, v97) & 1) != 0
          || (is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a2), a4 == 3) && is_5ghz_ch_freq )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Channel switch not allowed for non-DBS HW on DFS channel %d width %d",
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            "hdd_softap_set_channel_change",
            a2,
            a4);
          goto LABEL_31;
        }
      }
      _X8 = (unsigned int *)a1 + 655;
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v110 = __ldxr(_X8);
        v111 = v110 + 1;
      }
      while ( __stlxr(v111, _X8) );
      __dmb(0xBu);
      if ( v111 >= 2 )
      {
        v98 = "%s: Channel switch in progress!!";
        goto LABEL_28;
      }
      LODWORD(v183) = a4;
      HIDWORD(v184) = a3;
      wlan_reg_set_input_punc_bitmap((__int64)&v183, v182);
      csa_chanwidth_from_phymode = wlansap_get_csa_chanwidth_from_phymode(v181, a2, &v183);
      v114 = v113;
      v180 = HIDWORD(v184);
      v122 = policy_mgr_qdf_opmode_to_pm_con_mode(
               *v16,
               *(_DWORD *)(v14 + 40),
               *((_BYTE *)a1 + 8),
               csa_chanwidth_from_phymode,
               v115,
               v116,
               v117,
               v118,
               v119,
               v120,
               v121);
      v123 = *v16;
      v124 = v122;
      bw = policy_mgr_get_bw(v114, v125, v126, v127, v128, v129, v130, v131, v132);
      if ( (policy_mgr_allow_concurrency_csa(
              v123,
              v124,
              a2,
              bw,
              *((unsigned __int8 *)a1 + 8),
              a6 & 1,
              *(_DWORD *)(v181 + 732))
          & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Channel switch failed due to concurrency check failure",
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          v140,
          v141,
          "hdd_softap_set_channel_change");
        if ( *(_DWORD *)(v14 + 40) == 1
          && (policy_mgr_is_hw_dbs_capable(*v16) & 1) == 0
          && (mlme_is_wapi_sta_active(v16[1]) & 1) != 0
          && (unsigned int)policy_mgr_get_connection_count(*v16) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: vdev:%d stop sap as wapi sta present",
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            v159,
            v160,
            "hdd_softap_set_channel_change",
            *((unsigned __int8 *)a1 + 8));
          queue_work_on(32, system_wq, a1 + 757);
        }
        *((_DWORD *)a1 + 655) = 0;
        goto LABEL_31;
      }
      v142 = policy_mgr_ap_csa_request(
               *v16,
               *((unsigned __int8 *)a1 + 8),
               *(_DWORD *)v181,
               *(_DWORD *)(v181 + 732),
               a2,
               v114,
               a6 & 1,
               a7 & 1);
      if ( !v142 )
      {
        if ( (sme_is_any_session_in_middle_of_roaming(v16[2]) & 1) != 0 || (hdd_is_roaming_in_progress(v16) & 1) != 0 )
        {
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: Channel switch not allowed as reassoc in progress",
            v161,
            v162,
            v163,
            v164,
            v165,
            v166,
            v167,
            v168,
            "hdd_softap_set_channel_change");
          *((_DWORD *)a1 + 655) = 0;
        }
        else
        {
          wlan_hdd_set_roaming_state(a1, 8, 0);
          vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_softap_set_channel_change");
          if ( vdev_by_user )
          {
            v170 = vdev_by_user;
            if ( *(_DWORD *)(vdev_by_user + 16) == 3 )
              v171 = 1;
            else
              v171 = wlansap_override_csa_strict_for_sap(v16[2], v181, a2, a6 & 1);
            _hdd_objmgr_put_vdev_by_user(v170, 6, "hdd_softap_set_channel_change");
            if ( !(unsigned int)wlansap_set_channel_change_with_csa(a1[34], a2, v180, v114, v182, v171 & 1) )
            {
              sta_sap_scc_on_dfs_chnl = 0;
              goto LABEL_32;
            }
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: SAP set channel failed for channel freq: %d, bw: %d",
              v172,
              v173,
              v174,
              v175,
              v176,
              v177,
              v178,
              v179,
              "hdd_softap_set_channel_change",
              a2,
              v114);
          }
          *((_DWORD *)a1 + 655) = 0;
          wlan_hdd_set_roaming_state(a1, 8, 1);
        }
        policy_mgr_ap_csa_end(*v16, *((unsigned __int8 *)a1 + 8), 1, 1);
        goto LABEL_31;
      }
      v151 = v142;
      *((_DWORD *)a1 + 655) = 0;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: defer csa request status %d",
        v143,
        v144,
        v145,
        v146,
        v147,
        v148,
        v149,
        v150,
        "hdd_softap_set_channel_change",
        v142);
      if ( v151 == 8 )
        v152 = -16;
      else
        v152 = -22;
      if ( v151 == 24 )
        sta_sap_scc_on_dfs_chnl = 0;
      else
        sta_sap_scc_on_dfs_chnl = v152;
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return sta_sap_scc_on_dfs_chnl;
}
