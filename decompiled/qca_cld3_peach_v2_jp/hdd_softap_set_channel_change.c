__int64 __fastcall hdd_softap_set_channel_change(
        __int64 *a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        char a6)
{
  __int64 v12; // x25
  __int64 v13; // x24
  __int64 *v14; // x22
  __int64 result; // x0
  __int64 v16; // x28
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int ll_lt_sap_freq; // w28
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  unsigned int v59; // w0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w19
  unsigned __int8 *ie_ptr_from_eid; // x28
  unsigned __int8 *v70; // x24
  unsigned int param; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 adapter; // x28
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  const char *v97; // x2
  int v98; // w28
  __int64 v100; // x20
  __int64 v101; // x20
  double csa_chanwidth_from_phymode; // d0
  unsigned int v103; // w0
  unsigned int v104; // w26
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  unsigned int v112; // w0
  __int64 v113; // x28
  unsigned int v114; // w27
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  unsigned int bw; // w0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  bool is_5ghz_ch_freq; // w0
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  __int64 vdev_by_user; // x0
  __int64 v150; // x25
  char v151; // w22
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  unsigned int v165; // w9
  signed int v166; // w9
  unsigned int v167; // [xsp+Ch] [xbp-154h]
  __int64 v168; // [xsp+10h] [xbp-150h]
  __int64 v169; // [xsp+18h] [xbp-148h] BYREF
  __int64 v170; // [xsp+20h] [xbp-140h]
  _BYTE v171[4]; // [xsp+28h] [xbp-138h] BYREF
  _BYTE v172[4]; // [xsp+2Ch] [xbp-134h] BYREF
  _DWORD s[72]; // [xsp+30h] [xbp-130h] BYREF
  __int64 v174; // [xsp+150h] [xbp-10h]

  v174 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v172[0] = 0;
  v169 = 0;
  v170 = 0;
  memset(s, 0, sizeof(s));
  if ( !a1 )
    goto LABEL_31;
  v12 = *a1;
  v13 = a1[270];
  v171[0] = 0;
  v14 = *(__int64 **)(v12 + 24);
  result = _wlan_hdd_validate_context(v14, "hdd_softap_set_channel_change");
  if ( !(_DWORD)result )
  {
    if ( (*(_DWORD *)(v12 + 40) | 2) != 3 )
      goto LABEL_31;
    v16 = a1[34];
    if ( !v16 )
      goto LABEL_31;
    if ( (hdd_is_sta_connect_or_link_switch_in_prog(v14) & 1) != 0
      || *(_DWORD *)(v12 + 40) == 3 && (ucfg_p2p_is_p2p_go_noa_in_progress(v14[1], *((_BYTE *)a1 + 8)) & 1) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: vdev %d Do not allow CSA, STA connect/link switch/eapol/noa is in progress",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "hdd_softap_set_channel_change",
        *((unsigned __int8 *)a1 + 8));
      result = 4294967280LL;
    }
    else
    {
      if ( policy_mgr_is_vdev_ll_lt_sap(*v14, *(unsigned __int8 *)(*(_QWORD *)(v16 + 16) + 104LL))
        && (*(_DWORD *)(v16 + 732) | 8) != 0xA )
      {
        wlan_hdd_set_sap_csa_reason(*v14, *((_BYTE *)a1 + 8), 0x10u);
        hdd_dcs_trigger_csa_for_ll_lt_sap(*v14, v14, *(unsigned __int8 *)(*(_QWORD *)(v16 + 16) + 104LL), 0);
        result = 0;
        goto LABEL_32;
      }
      v168 = v16;
      ll_lt_sap_freq = policy_mgr_get_ll_lt_sap_freq(*v14);
      v34 = policy_mgr_qdf_opmode_to_pm_con_mode(
              *v14,
              *(_DWORD *)(v12 + 40),
              *((_BYTE *)a1 + 8),
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              v33);
      if ( ll_lt_sap_freq && v34 == 1 && (policy_mgr_are_2_freq_on_same_mac(*v14, a2, ll_lt_sap_freq) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: ll_sap freq %d and sap freq %d are on same mac",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_softap_set_channel_change",
          ll_lt_sap_freq,
          a2);
LABEL_31:
        result = 4294967274LL;
        goto LABEL_32;
      }
      if ( wlan_reg_is_6ghz_chan_freq(a2)
        && (wlan_reg_is_6ghz_band_set(v14[1], v43, v44, v45, v46, v47, v48, v49, v50) & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: 6 GHz band disabled",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "hdd_softap_set_channel_change");
        goto LABEL_31;
      }
      v59 = hdd_validate_channel_and_bandwidth(v12, a2, a3, a4);
      if ( v59 )
      {
        v68 = v59;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid CH and BW combo",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "hdd_softap_set_channel_change");
        result = v68;
        goto LABEL_32;
      }
      if ( wlan_reg_is_6ghz_chan_freq(a2) )
      {
        ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x30u, *(unsigned __int8 **)(v13 + 8), *(_DWORD *)(v13 + 36));
        v70 = wlan_get_ie_ptr_from_eid(0xF4u, *(unsigned __int8 **)(v13 + 8), *(_DWORD *)(v13 + 36));
        if ( ie_ptr_from_eid )
          wlan_crypto_rsnie_check(s, ie_ptr_from_eid, nullptr);
        param = wlan_crypto_get_param(*(_QWORD *)(v168 + 16), 7u);
        if ( (param & 0x80000000) != 0 )
        {
          v100 = jiffies;
          if ( hdd_softap_set_channel_change___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Invalid keymgmt",
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              "hdd_softap_set_channel_change");
            hdd_softap_set_channel_change___last_ticks = v100;
          }
          goto LABEL_31;
        }
        if ( (wlan_cm_6ghz_allowed_for_akm(*v14, param, s[38], (__int64)v70, 0, *(_DWORD *)(v12 + 40) == 3) & 1) == 0 )
        {
          v101 = jiffies;
          if ( hdd_softap_set_channel_change___last_ticks_92 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: 6Ghz channel switch not capable",
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              "hdd_softap_set_channel_change");
            hdd_softap_set_channel_change___last_ticks_92 = v101;
          }
          goto LABEL_31;
        }
      }
      adapter = hdd_get_adapter(v14, 0);
      ucfg_policy_mgr_get_conc_rule1(*v14, v172);
      if ( adapter && v172[0] && hdd_cm_is_vdev_associated(*(_DWORD **)(adapter + 52824)) )
      {
        v97 = "%s: Channel switch not allowed after STA connection with conc_custom_rule1 enabled";
LABEL_28:
        qdf_trace_msg(0x33u, 2u, v97, v89, v90, v91, v92, v93, v94, v95, v96, "hdd_softap_set_channel_change");
        result = 4294967280LL;
        goto LABEL_32;
      }
      v98 = policy_mgr_mode_specific_connection_count(*v14, 0, nullptr);
      result = policy_mgr_get_sta_sap_scc_on_dfs_chnl(*v14, v171);
      if ( (_DWORD)result )
        goto LABEL_32;
      if ( (policy_mgr_is_sap_go_interface_allowed_on_indoor(v14[1], *((unsigned __int8 *)a1 + 8), a2) & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Channel switch is not allowed to indoor frequency %d",
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          "hdd_softap_set_channel_change",
          a2);
        goto LABEL_31;
      }
      if ( !v98 && (policy_mgr_is_hw_dbs_capable(*v14) & 1) == 0 && v171[0] == 1 )
      {
        if ( (wlan_reg_is_dfs_for_freq(v14[1], a2, v89, v90, v91, v92, v93, v94, v95, v96) & 1) != 0
          || (is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(a2), a4 == 3) && is_5ghz_ch_freq )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Channel switch not allowed for non-DBS HW on DFS channel %d width %d",
            v89,
            v90,
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            "hdd_softap_set_channel_change",
            a2,
            a4);
          goto LABEL_31;
        }
      }
      _X8 = (unsigned int *)a1 + 587;
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v165 = __ldxr(_X8);
        v166 = v165 + 1;
      }
      while ( __stlxr(v166, _X8) );
      __dmb(0xBu);
      if ( v166 >= 2 )
      {
        v97 = "%s: Channel switch in progress!!";
        goto LABEL_28;
      }
      LODWORD(v169) = a4;
      HIDWORD(v170) = a3;
      wlan_reg_set_input_punc_bitmap();
      csa_chanwidth_from_phymode = wlansap_get_csa_chanwidth_from_phymode(v168, a2, &v169);
      v104 = v103;
      v167 = HIDWORD(v170);
      v112 = policy_mgr_qdf_opmode_to_pm_con_mode(
               *v14,
               *(_DWORD *)(v12 + 40),
               *((_BYTE *)a1 + 8),
               csa_chanwidth_from_phymode,
               v105,
               v106,
               v107,
               v108,
               v109,
               v110,
               v111);
      v113 = *v14;
      v114 = v112;
      bw = policy_mgr_get_bw(v104, v115, v116, v117, v118, v119, v120, v121, v122);
      if ( (policy_mgr_allow_concurrency_csa(
              v113,
              v114,
              a2,
              bw,
              *((unsigned __int8 *)a1 + 8),
              a6 & 1,
              *(_DWORD *)(v168 + 732))
          & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Channel switch failed due to concurrency check failure",
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          v131,
          "hdd_softap_set_channel_change");
        if ( *(_DWORD *)(v12 + 40) == 1
          && (policy_mgr_is_hw_dbs_capable(*v14) & 1) == 0
          && (mlme_is_wapi_sta_active(v14[1]) & 1) != 0
          && (unsigned int)policy_mgr_get_connection_count(*v14) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: vdev:%d stop sap as wapi sta present",
            v141,
            v142,
            v143,
            v144,
            v145,
            v146,
            v147,
            v148,
            "hdd_softap_set_channel_change",
            *((unsigned __int8 *)a1 + 8));
          queue_work_on(32, system_wq, a1 + 562);
        }
        *((_DWORD *)a1 + 587) = 0;
        goto LABEL_31;
      }
      if ( (sme_is_any_session_in_middle_of_roaming(v14[2]) & 1) != 0 || (hdd_is_roaming_in_progress(v14) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: Channel switch not allowed as reassoc in progress",
          v132,
          v133,
          v134,
          v135,
          v136,
          v137,
          v138,
          v139,
          "hdd_softap_set_channel_change");
        *((_DWORD *)a1 + 587) = 0;
        goto LABEL_31;
      }
      wlan_hdd_set_roaming_state(a1, 8, 0);
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(a1, 6, "hdd_softap_set_channel_change");
      if ( !vdev_by_user )
      {
LABEL_66:
        *((_DWORD *)a1 + 587) = 0;
        wlan_hdd_set_roaming_state(a1, 8, 1);
        goto LABEL_31;
      }
      v150 = vdev_by_user;
      if ( *(_DWORD *)(vdev_by_user + 16) == 3 )
        v151 = 1;
      else
        v151 = wlansap_override_csa_strict_for_sap(v14[2], v168, a2, a6 & 1);
      _hdd_objmgr_put_vdev_by_user(v150, 6, "hdd_softap_set_channel_change");
      result = wlansap_set_channel_change_with_csa(a1[34], a2, v167, v104, a5, v151 & 1);
      if ( (_DWORD)result )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: SAP set channel failed for channel freq: %d, bw: %d",
          v152,
          v153,
          v154,
          v155,
          v156,
          v157,
          v158,
          v159,
          "hdd_softap_set_channel_change",
          a2,
          v104);
        goto LABEL_66;
      }
    }
  }
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
