__int64 __fastcall hdd_stop_adapter_ext(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v11; // x27
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x4
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  int v40; // w20
  _QWORD *v41; // x24
  __int64 v42; // x0
  __int64 v43; // x25
  __int64 v44; // x26
  __int64 v45; // x23
  double v46; // d0
  __int64 v47; // x22
  _QWORD *v48; // x28
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int v64; // w1
  const char *v65; // x2
  const char *v66; // x3
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x22
  int v76; // w1
  __int64 v77; // x0
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  __int64 v86; // x0
  __int64 v87; // x22
  double v88; // d0
  unsigned int *v89; // x8
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  int v113; // w8
  _QWORD *v114; // x22
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  __int64 v124; // x21
  __int64 v125; // x22
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  _QWORD *context; // x0
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  __int64 v143; // x8
  void (*v144)(void); // x8
  __int64 v145; // x21
  double v146; // d0
  double v147; // d1
  double v148; // d2
  double v149; // d3
  double v150; // d4
  double v151; // d5
  double v152; // d6
  double v153; // d7
  __int64 v154; // x22
  __int64 v155; // x23
  __int64 *v156; // x21
  __int64 *v158; // x25
  int v159; // w20
  __int64 v160; // x28
  __int64 vdev_by_user; // x26
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
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
  __int64 v210; // x8
  __int64 v211; // x8
  __int64 v212; // x23
  __int16 v213; // w8
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  double v238; // d0
  double v239; // d1
  double v240; // d2
  double v241; // d3
  double v242; // d4
  double v243; // d5
  double v244; // d6
  double v245; // d7
  char v246; // w23
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  unsigned int v255; // w0
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  __int64 v264; // x0
  __int64 v265; // x22
  unsigned __int64 v271; // x8
  unsigned __int64 v273; // x8
  __int64 v274; // [xsp+0h] [xbp-30h]
  __int64 v275; // [xsp+8h] [xbp-28h]
  _QWORD v276[4]; // [xsp+10h] [xbp-20h] BYREF

  v11 = (__int64 *)(a2 + 52824);
  v276[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 52824);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_stop_adapter_ext");
  hdd_destroy_adapter_sysfs_files(a2);
  if ( *(unsigned __int8 *)(v13 + 8) != 255 )
    wlan_hdd_cfg80211_deregister_frames(a2, v14, v15, v16, v17, v18, v19, v20, v21);
  hdd_reset_tsf_sync(a2);
  if ( *(_QWORD *)(a2 + 41728) )
  {
    cds_flush_work(a2 + 41704);
  }
  else
  {
    if ( *(_QWORD *)(a2 + 32) == -296 )
      v30 = "none";
    else
      v30 = (const char *)(*(_QWORD *)(a2 + 32) + 296LL);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: iface: %s Scan block work has been already cleaned up",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hdd_flush_scan_block_work",
      v30);
  }
  wlan_hdd_cfg80211_scan_block(a2);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d Disabling queues",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "hdd_stop_adapter_ext",
    *(unsigned __int8 *)(*v11 + 8));
  v39 = wlan_hdd_netif_queue_control(a2, 4, 1);
  v40 = *(_DWORD *)(a2 + 40);
  if ( v40 <= 5 )
  {
    if ( v40 > 1 )
    {
      if ( v40 == 2 )
        goto LABEL_25;
      if ( v40 != 3 )
        goto LABEL_63;
    }
    else
    {
      if ( !v40 )
        goto LABEL_25;
      if ( v40 != 1 )
        goto LABEL_63;
    }
    v274 = *(_QWORD *)(a2 + 24);
    v275 = a1;
    if ( !a2 || (*(_QWORD *)(a2 + 1640) & 1) == 0 )
    {
LABEL_23:
      hdd_clear_cached_sta_info(a2);
      cancel_work_sync(a2 + 48);
      cancel_work_sync(a2 + 80);
      ucfg_ipa_flush(*(_QWORD *)(v274 + 8));
      goto LABEL_62;
    }
    v155 = v11[1];
    v156 = v11 + 1;
    _X24 = (unsigned __int64 *)(a2 + 57248);
    while ( 1 )
    {
      v158 = *(__int64 **)(v155 + 24);
      v159 = *(_DWORD *)(v155 + 40);
      v160 = v11[35];
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(v11 + 1, 36, "hdd_stop_sap_go_per_link");
      if ( v159 == 1 )
      {
        wlan_hdd_scan_abort(v11 + 1);
        hdd_abort_ongoing_sta_connection((__int64)v158, v162, v163, v164, v165, v166, v167, v168, v169);
        if ( (*_X24 & 2) != 0 && (unsigned int)wlan_hdd_del_station(v155, 0) )
          hdd_sap_indicate_disconnect_for_sta(v155);
        wlan_hdd_flush_pmksa_cache((__int64)(v11 + 1));
        wlansap_reset_sap_config_add_ie(a2 + 53112, 6);
        if ( vdev_by_user )
        {
          if ( (ucfg_pre_cac_adapter_is_active(vdev_by_user) & 1) != 0 )
          {
            if ( (unsigned int)ucfg_pre_cac_set_status(vdev_by_user, 0) )
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: Failed to set is_pre_cac_on to false",
                v170,
                v171,
                v172,
                v173,
                v174,
                v175,
                v176,
                v177,
                "hdd_stop_and_close_pre_cac_adapter");
          }
          else
          {
            ucfg_pre_cac_stop(*v158);
            hdd_close_pre_cac_adapter(v158);
          }
        }
      }
      wlansap_cleanup_cac_timer(v160);
      if ( *(_QWORD *)(a2 + 57352) )
        cds_flush_work(a2 + 57328);
      if ( *((_DWORD *)v11 + 588) )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: ACS in progress, wait for complete",
          v178,
          v179,
          v180,
          v181,
          v182,
          v183,
          v184,
          v185,
          "hdd_stop_sap_go_per_link");
        qdf_wait_for_event_completion(a2 + 55208, 0xBB8u);
      }
      if ( v159 == 3 )
      {
        wlan_hdd_cleanup_remain_on_channel_ctx(v11 + 1);
        hdd_abort_ongoing_sta_connection((__int64)v158, v186, v187, v188, v189, v190, v191, v192, v193);
      }
      hdd_destroy_acs_timer(v155);
      mutex_lock(v158 + 24);
      if ( (*_X24 & 2) != 0 )
      {
        qdf_event_reset(a2 + 52960);
        if ( (unsigned int)wlansap_stop_bss(v11[35]) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: failure in wlansap_stop_bss",
            v202,
            v203,
            v204,
            v205,
            v206,
            v207,
            v208,
            v209,
            "hdd_stop_sap_go_per_link");
        }
        else
        {
          v255 = qdf_wait_single_event(a2 + 52960, 0x4650u);
          if ( v255 )
          {
            v264 = qdf_trace_msg(
                     0x33u,
                     2u,
                     "%s: failure waiting for wlansap_stop_bss %d",
                     v256,
                     v257,
                     v258,
                     v259,
                     v260,
                     v261,
                     v262,
                     v263,
                     "hdd_stop_sap_go_per_link",
                     v255);
            v265 = *(_QWORD *)(v155 + 52824);
            if ( (ucfg_ipa_is_enabled(v264) & 1) != 0 )
            {
              ucfg_ipa_uc_disconnect_ap(v158[1], *(_QWORD *)(v155 + 32));
              ucfg_ipa_cleanup_dev_iface(v158[1], *(_QWORD *)(v155 + 32), *(unsigned __int8 *)(v265 + 8));
            }
          }
        }
        __asm { PRFM            #0x11, [X24] }
        do
          v273 = __ldxr(_X24);
        while ( __stxr(v273 & 0xFFFFFFFFFFFFFFFDLL, _X24) );
        policy_mgr_decr_session_set_pcl(*v158, *(_DWORD *)(v155 + 40), *((unsigned __int8 *)v11 + 16));
        hdd_green_ap_start_state_mc(v158, *(unsigned int *)(v155 + 40), 0);
        v210 = v11[1];
        if ( v210 && (v211 = *(_QWORD *)(v210 + 24)) != 0 )
          v212 = *(_QWORD *)(v211 + 16);
        else
          v212 = 0;
        v213 = *((unsigned __int8 *)v11 + 16);
        memset(v276, 0, 24);
        HIWORD(v276[0]) = v213;
        if ( (unsigned int)sme_update_add_ie(v212, v276, 1) == 16 )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Could not pass PROBE_RSP_BCN to PE",
            v214,
            v215,
            v216,
            v217,
            v218,
            v219,
            v220,
            v221,
            "hdd_reset_ies_on_sap_stop");
        if ( (unsigned int)sme_update_add_ie(v212, v276, 3) == 16 )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Could not pass ASSOC_RSP to PE",
            v222,
            v223,
            v224,
            v225,
            v226,
            v227,
            v228,
            v229,
            "hdd_reset_ies_on_sap_stop");
        wlan_hdd_reset_prob_rspies(v11 + 1, v222, v223, v224, v225, v226, v227, v228, v229);
      }
      if ( (cds_get_driver_state(v194, v195, v196, v197, v198, v199, v200, v201) & 8) == 0
        || (cds_get_driver_state(v230, v231, v232, v233, v234, v235, v236, v237) & 4) != 0 )
      {
        __asm { PRFM            #0x11, [X24] }
        do
          v271 = __ldxr(_X24);
        while ( __stxr(v271 & 0xFFFFFFFFFFFFFFFBLL, _X24) );
        _qdf_mem_free(v11[271]);
        v11[271] = 0;
        if ( vdev_by_user )
        {
          ucfg_crypto_free_key_by_link_id();
LABEL_119:
          if ( (policy_mgr_is_dnsc_set(vdev_by_user, v238, v239, v240, v241, v242, v243, v244, v245) & 1) != 0 )
            wlan_hdd_send_avoid_freq_for_dnbs((__int64)v158, 0);
          v246 = 0;
          goto LABEL_123;
        }
      }
      else if ( vdev_by_user )
      {
        goto LABEL_119;
      }
      v246 = 1;
LABEL_123:
      sap_release_vdev_ref(v160);
      if ( v159 == 1 )
        ucfg_ipa_flush_pending_vdev_events(v158[1], *((unsigned __int8 *)v11 + 16));
      if ( (v246 & 1) == 0 )
        _hdd_objmgr_put_vdev_by_user(vdev_by_user, 36, "hdd_stop_sap_go_per_link");
      hdd_vdev_destroy((__int64)(v11 + 1), v247, v248, v249, v250, v251, v252, v253, v254);
      mutex_unlock(v158 + 24);
      v155 = *v156;
      if ( (unsigned __int8)~(-910593773 * (((unsigned int)v156 - (unsigned int)*v156 - 52832) >> 4))
        || (*(_QWORD *)(a2 + 1640) & 1) == 0 )
      {
        goto LABEL_23;
      }
    }
  }
  if ( v40 <= 7 )
  {
    if ( v40 == 6 )
    {
      v145 = *(_QWORD *)(a2 + 24);
      if ( a2 && (*(_QWORD *)(a2 + 1640) & 1) != 0 )
      {
        do
          v39 = wlan_hdd_delete_mon_link(a2, v11 + 1);
        while ( !(unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v11 + 8 - *((_DWORD *)v11 + 2) - 52832) >> 4))
             && (*(_QWORD *)(a2 + 1640) & 1) != 0 );
      }
      if ( (unsigned int)hdd_disable_monitor_mode(v39) )
      {
        v154 = jiffies;
        if ( hdd_stop_mon_adapter___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: datapath reset failed for montior mode",
            v146,
            v147,
            v148,
            v149,
            v150,
            v151,
            v152,
            v153,
            "hdd_stop_mon_adapter");
          hdd_stop_mon_adapter___last_ticks = v154;
        }
      }
      hdd_set_idle_ps_config(v145, 1, v146, v147, v148, v149, v150, v151, v152, v153);
      goto LABEL_63;
    }
LABEL_25:
    v275 = a1;
    if ( a2 && (*(_QWORD *)(a2 + 1640) & 1) != 0 )
    {
      v41 = v11 + 1;
      while ( 1 )
      {
        v42 = _hdd_objmgr_get_vdev_by_user(v11 + 1, 36, "hdd_stop_station_adapter");
        if ( v42 )
          break;
LABEL_59:
        if ( (unsigned __int8)~(-910593773 * ((unsigned int)((_DWORD)v41 - *(_DWORD *)v41 - 52832) >> 4))
          || (*(_QWORD *)(a2 + 1640) & 1) == 0 )
        {
          goto LABEL_61;
        }
      }
      v43 = v42;
      if ( v40 != 11 )
      {
        if ( !hdd_cm_is_disconnected((__int64)(v11 + 1)) )
        {
          v75 = *v41;
          v76 = (cds_get_driver_state(v67, v68, v69, v70, v71, v72, v73, v74) & 8) != 0 ? 65525 : 65528;
          v77 = wlan_hdd_cm_issue_disconnect((__int64)(v11 + 1), v76, 1);
          if ( (_DWORD)v77 )
          {
            if ( (ucfg_ipa_is_enabled(v77) & 1) != 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: STA disconnect failed",
                v78,
                v79,
                v80,
                v81,
                v82,
                v83,
                v84,
                v85,
                "hdd_sta_disconnect_and_cleanup");
              ucfg_ipa_uc_cleanup_sta(
                *(_QWORD *)(*(_QWORD *)(v75 + 24) + 8LL),
                *(_QWORD *)(v75 + 32),
                *((unsigned __int8 *)v11 + 16));
            }
          }
        }
        goto LABEL_50;
      }
      v44 = *v41;
      v45 = *(_QWORD *)(*v41 + 24LL);
      v46 = hdd_destroy_adapter_sysfs_files(*v41);
      *(_DWORD *)(v44 + 1744) = 0;
      v47 = *v41;
      v48 = *(_QWORD **)(*v41 + 24LL);
      if ( (hdd_any_valid_peer_present((__int64)(v11 + 1), v46, v49, v50, v51, v52, v53, v54, v55) & 1) != 0 )
      {
        if ( *(_DWORD *)(v47 + 40) != 11
          || (unsigned int)ucfg_nan_disable_ndi(*v48, *((unsigned __int8 *)v11 + 16))
          || !(unsigned int)qdf_wait_for_event_completion(v47 + 52408, 0x1388u) )
        {
LABEL_46:
          if ( !(unsigned int)sme_roam_ndi_stop(*(_QWORD *)(v45 + 16), *((unsigned __int8 *)v11 + 16)) )
          {
            if ( !wait_for_completion_timeout(v44 + 1744, 4500) )
              qdf_trace_msg(
                0x33u,
                3u,
                "%s: disconn_comp_var wait fail",
                v97,
                v98,
                v99,
                v100,
                v101,
                v102,
                v103,
                v104,
                "hdd_stop_and_cleanup_ndi");
            hdd_cleanup_ndi(v11 + 1);
          }
LABEL_50:
          hdd_reset_scan_operation(v11 + 1);
          wlan_hdd_cleanup_actionframe(v11 + 1);
          wlan_hdd_flush_pmksa_cache((__int64)(v11 + 1));
          if ( !v40 )
            ucfg_ipa_flush_pending_vdev_events(*(_QWORD *)(v43 + 152), *((unsigned __int8 *)v11 + 16));
          _hdd_objmgr_put_vdev_by_user(v43, 36, "hdd_stop_station_adapter");
          v113 = *(_DWORD *)(a2 + 40);
          v114 = *(_QWORD **)(a2 + 24);
          if ( (v113 == 16 || !v113 && (ucfg_nan_is_vdev_creation_allowed(*v114) & 1) == 0)
            && (ucfg_is_nan_conc_control_supported(*v114) & 1) != 0
            && (ucfg_is_nan_disc_active(*v114) & 1) != 0 )
          {
            v105 = ucfg_disable_nan_discovery(*v114, 0, 0);
          }
          hdd_vdev_destroy((__int64)(v11 + 1), v105, v106, v107, v108, v109, v110, v111, v112);
          goto LABEL_59;
        }
        v64 = 8;
        v65 = "%s: peer_cleanup_done wait fail";
        v66 = "hdd_peer_cleanup";
      }
      else
      {
        v86 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                *v48,
                *((unsigned __int8 *)v11 + 16),
                20);
        if ( v86 )
        {
          v87 = v86;
          v88 = _ucfg_nan_set_ndi_state(v86, 9, "hdd_ndp_state_cleanup");
          wlan_objmgr_vdev_release_ref(v87, 0x14u, v89, v88, v90, v91, v92, v93, v94, v95, v96);
          goto LABEL_46;
        }
        v64 = 2;
        v65 = "%s: Cannot obtain NDI vdev object!";
        v66 = "hdd_ndp_state_cleanup";
      }
      qdf_trace_msg(0x33u, v64, v65, v56, v57, v58, v59, v60, v61, v62, v63, v66);
      goto LABEL_46;
    }
LABEL_61:
    cancel_work_sync(a2 + 48);
    cancel_work_sync(a2 + 80);
LABEL_62:
    a1 = v275;
    goto LABEL_63;
  }
  if ( v40 != 8 )
  {
    if ( v40 != 16 && v40 != 11 )
      goto LABEL_63;
    goto LABEL_25;
  }
  v124 = *v11;
  v125 = _hdd_objmgr_get_vdev_by_user(*v11, 36, "hdd_stop_ocb_adapter");
  context = _cds_get_context(71, (__int64)"hdd_stop_ocb_adapter", v126, v127, v128, v129, v130, v131, v132, v133);
  if ( context && *context && (v143 = *(_QWORD *)(*context + 72LL)) != 0 )
  {
    v144 = *(void (**)(void))(v143 + 8);
    if ( v144 )
    {
      if ( *((_DWORD *)v144 - 1) != -1003232309 )
        __break(0x8228u);
      v144();
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v135, v136, v137, v138, v139, v140, v141, v142, "cdp_clear_peer");
  }
  if ( v125 )
    _hdd_objmgr_put_vdev_by_user(v125, 36, "hdd_stop_ocb_adapter");
  hdd_vdev_destroy(v124, v135, v136, v137, v138, v139, v140, v141, v142);
LABEL_63:
  wlan_cfg80211_cleanup_scan_queue(*(_QWORD *)(a1 + 8), *(_QWORD *)(a2 + 32));
  qdf_trace_msg(0x33u, 8u, "%s: exit", v115, v116, v117, v118, v119, v120, v121, v122, "hdd_stop_adapter_ext");
  _ReadStatusReg(SP_EL0);
  return 0;
}
