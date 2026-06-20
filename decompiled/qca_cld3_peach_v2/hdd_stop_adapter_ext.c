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
  __int64 *v10; // x24
  __int64 v12; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  const char *v29; // x4
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x0
  int v39; // w20
  __int64 v40; // x24
  unsigned __int8 *v41; // x22
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x9
  _QWORD *v51; // x13
  __int64 v52; // x14
  __int64 v53; // x14
  char v54; // w9
  const char *v56; // x23
  __int64 v57; // x24
  __int64 v58; // x0
  __int64 v59; // x25
  __int64 v60; // x26
  __int64 v61; // x20
  const char *v62; // x24
  __int64 v63; // x21
  double v64; // d0
  __int64 v65; // x23
  _QWORD *v66; // x27
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int v82; // w1
  const char *v83; // x2
  const char *v84; // x3
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x21
  int v94; // w1
  __int64 v95; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x0
  __int64 v105; // x23
  double v106; // d0
  unsigned int *v107; // x8
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
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  int v131; // w8
  _QWORD *v132; // x21
  __int64 v133; // x8
  __int64 v134; // x9
  __int64 v135; // x10
  __int64 v136; // x21
  __int64 v137; // x22
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  _QWORD *context; // x0
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  __int64 v155; // x8
  void (*v156)(void); // x8
  __int64 v157; // x21
  _DWORD *v158; // x22
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  __int64 v167; // x22
  __int64 v168; // x22
  __int64 v169; // x28
  __int64 *v170; // x25
  int v171; // w23
  __int64 vdev_by_user; // x26
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  __int64 v221; // x8
  __int64 v222; // x22
  double v223; // d0
  double v224; // d1
  double v225; // d2
  double v226; // d3
  double v227; // d4
  double v228; // d5
  double v229; // d6
  double v230; // d7
  double v231; // d0
  double v232; // d1
  double v233; // d2
  double v234; // d3
  double v235; // d4
  double v236; // d5
  double v237; // d6
  double v238; // d7
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  char v255; // w22
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  __int64 v264; // x8
  __int64 v265; // x9
  __int64 v266; // x10
  unsigned int v267; // w0
  double v268; // d0
  double v269; // d1
  double v270; // d2
  double v271; // d3
  double v272; // d4
  double v273; // d5
  double v274; // d6
  double v275; // d7
  __int64 v276; // x0
  __int64 v277; // x21
  unsigned __int64 v284; // x9
  unsigned __int64 v287; // x9
  __int64 v288; // x8
  __int64 v289; // x9
  __int64 v290; // x10
  __int64 *v291; // [xsp+0h] [xbp-40h]
  __int64 v292; // [xsp+8h] [xbp-38h]
  int v293; // [xsp+8h] [xbp-38h]
  _QWORD v295[4]; // [xsp+20h] [xbp-20h] BYREF

  v10 = (__int64 *)(a2 + 52832);
  v295[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a2 + 52832);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_stop_adapter_ext");
  hdd_destroy_adapter_sysfs_files(a2);
  if ( *(unsigned __int8 *)(v12 + 8) != 255 )
    wlan_hdd_cfg80211_deregister_frames(a2, v13, v14, v15, v16, v17, v18, v19, v20);
  hdd_reset_tsf_sync(a2);
  if ( *(_QWORD *)(a2 + 41728) )
  {
    cds_flush_work(a2 + 41704);
  }
  else
  {
    if ( *(_QWORD *)(a2 + 32) == -296 )
      v29 = "none";
    else
      v29 = (const char *)(*(_QWORD *)(a2 + 32) + 296LL);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: iface: %s Scan block work has been already cleaned up",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "hdd_flush_scan_block_work",
      v29);
  }
  wlan_hdd_cfg80211_scan_block(a2);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev %d Disabling queues",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "hdd_stop_adapter_ext",
    *(unsigned __int8 *)(*v10 + 8));
  v38 = wlan_hdd_netif_queue_control(a2, 4, 1);
  v39 = *(_DWORD *)(a2 + 40);
  if ( v39 <= 5 )
  {
    if ( v39 > 1 )
    {
      if ( v39 != 2 )
      {
        if ( v39 != 3 )
          goto LABEL_37;
        goto LABEL_21;
      }
    }
    else if ( v39 )
    {
      if ( v39 != 1 )
        goto LABEL_37;
LABEL_21:
      v291 = v10;
      v292 = *(_QWORD *)(a2 + 24);
      if ( !a2 )
        goto LABEL_27;
      if ( (*(_QWORD *)(a2 + 1640) & 1) != 0 )
      {
        v40 = a2 + 52840;
        goto LABEL_108;
      }
      v40 = a2 + 58928;
      if ( a2 == -58928 || (*(_QWORD *)(a2 + 1640) & 2) == 0 )
      {
        v40 = a2 + 65016;
        if ( a2 == -65016 || (*(_QWORD *)(a2 + 1640) & 4) == 0 )
        {
LABEL_27:
          hdd_clear_cached_sta_info(a2);
          cancel_work_sync(a2 + 48);
          cancel_work_sync(a2 + 80);
          ucfg_ipa_flush(*(_QWORD *)(v292 + 8));
LABEL_36:
          v10 = v291;
          goto LABEL_37;
        }
      }
      while ( 1 )
      {
LABEL_108:
        v168 = *(_QWORD *)v40;
        v169 = *(_QWORD *)(v40 + 272);
        v170 = *(__int64 **)(*(_QWORD *)v40 + 24LL);
        v171 = *(_DWORD *)(*(_QWORD *)v40 + 40LL);
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(v40, 36, "hdd_stop_sap_go_per_link");
        policy_mgr_flush_deferred_csa(*v170, *(_BYTE *)(v40 + 8));
        if ( v171 == 1 )
        {
          wlan_hdd_scan_abort(v40);
          hdd_abort_ongoing_sta_connection((__int64)v170, v173, v174, v175, v176, v177, v178, v179, v180);
          if ( (*(_QWORD *)(v40 + 5968) & 2) != 0 && (unsigned int)wlan_hdd_del_station(v168, 0) )
            hdd_sap_indicate_disconnect_for_sta(v168);
          wlan_hdd_flush_pmksa_cache(v40);
          wlansap_reset_sap_config_add_ie(v40 + 280, 6);
          if ( vdev_by_user )
          {
            if ( (ucfg_pre_cac_adapter_is_active(vdev_by_user) & 1) != 0 )
            {
              if ( (unsigned int)ucfg_pre_cac_set_status(vdev_by_user, 0) )
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed to set is_pre_cac_on to false",
                  v181,
                  v182,
                  v183,
                  v184,
                  v185,
                  v186,
                  v187,
                  v188,
                  "hdd_stop_and_close_pre_cac_adapter");
            }
            else
            {
              ucfg_pre_cac_stop(*v170);
              hdd_close_pre_cac_adapter(v170);
            }
          }
        }
        wlansap_cleanup_cac_timer(v169);
        if ( *(_QWORD *)(v40 + 6080) )
          cds_flush_work(v40 + 6056);
        if ( *(_DWORD *)(v40 + 2616) )
        {
          qdf_trace_msg(
            0x33u,
            4u,
            "%s: ACS in progress, wait for complete",
            v189,
            v190,
            v191,
            v192,
            v193,
            v194,
            v195,
            v196,
            "hdd_stop_sap_go_per_link");
          qdf_wait_for_event_completion(v40 + 2648, 0xBB8u);
        }
        if ( v171 == 3 )
        {
          wlan_hdd_cleanup_remain_on_channel_ctx(v40);
          hdd_abort_ongoing_sta_connection((__int64)v170, v197, v198, v199, v200, v201, v202, v203, v204);
        }
        hdd_destroy_acs_timer(v168);
        mutex_lock(v170 + 24);
        if ( (*(_QWORD *)(v40 + 5968) & 2) != 0 )
        {
          qdf_event_reset(v40 + 128);
          if ( (unsigned int)wlansap_stop_bss(*(_QWORD *)(v40 + 272)) )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: failure in wlansap_stop_bss",
              v213,
              v214,
              v215,
              v216,
              v217,
              v218,
              v219,
              v220,
              "hdd_stop_sap_go_per_link");
          }
          else
          {
            v267 = qdf_wait_single_event(v40 + 128, 0x4650u);
            if ( v267 )
            {
              v276 = qdf_trace_msg(
                       0x33u,
                       2u,
                       "%s: failure waiting for wlansap_stop_bss %d",
                       v268,
                       v269,
                       v270,
                       v271,
                       v272,
                       v273,
                       v274,
                       v275,
                       "hdd_stop_sap_go_per_link",
                       v267);
              v277 = *(_QWORD *)(v168 + 52832);
              if ( (ucfg_ipa_is_enabled(v276) & 1) != 0 )
              {
                ucfg_ipa_uc_disconnect_ap(v170[1], *(_QWORD *)(v168 + 32));
                ucfg_ipa_cleanup_dev_iface(v170[1], *(_QWORD *)(v168 + 32), *(unsigned __int8 *)(v277 + 8));
              }
            }
          }
          _X8 = (unsigned __int64 *)(v40 + 5968);
          __asm { PRFM            #0x11, [X8] }
          do
            v287 = __ldxr(_X8);
          while ( __stxr(v287 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
          policy_mgr_decr_session_set_pcl(*v170, *(_DWORD *)(v168 + 40), *(unsigned __int8 *)(v40 + 8));
          hdd_green_ap_start_state_mc(v170, *(unsigned int *)(v168 + 40), 0);
          if ( *(_QWORD *)v40 && (v221 = *(_QWORD *)(*(_QWORD *)v40 + 24LL)) != 0 )
            v222 = *(_QWORD *)(v221 + 16);
          else
            v222 = 0;
          memset(v295, 0, 24);
          HIWORD(v295[0]) = *(unsigned __int8 *)(v40 + 8);
          if ( (unsigned int)sme_update_add_ie(v222, v295, 1) == 16 )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Could not pass PROBE_RSP_BCN to PE",
              v223,
              v224,
              v225,
              v226,
              v227,
              v228,
              v229,
              v230,
              "hdd_reset_ies_on_sap_stop");
          if ( (unsigned int)sme_update_add_ie(v222, v295, 3) == 16 )
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Could not pass ASSOC_RSP to PE",
              v231,
              v232,
              v233,
              v234,
              v235,
              v236,
              v237,
              v238,
              "hdd_reset_ies_on_sap_stop");
          wlan_hdd_reset_prob_rspies((__int64 *)v40, v231, v232, v233, v234, v235, v236, v237, v238);
        }
        if ( (cds_get_driver_state(v205, v206, v207, v208, v209, v210, v211, v212) & 8) == 0
          || (cds_get_driver_state(v239, v240, v241, v242, v243, v244, v245, v246) & 4) != 0 )
        {
          _X8 = (unsigned __int64 *)(v40 + 5968);
          __asm { PRFM            #0x11, [X8] }
          do
            v284 = __ldxr(_X8);
          while ( __stxr(v284 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
          _qdf_mem_free(*(_QWORD *)(v40 + 2432));
          *(_QWORD *)(v40 + 2432) = 0;
          if ( vdev_by_user )
          {
            ucfg_crypto_free_key_by_link_id(*v170, (unsigned __int8 *)(v40 + 72), *(_BYTE *)(vdev_by_user + 93));
LABEL_143:
            if ( (policy_mgr_is_dnsc_set(vdev_by_user, v247, v248, v249, v250, v251, v252, v253, v254) & 1) != 0 )
              wlan_hdd_send_avoid_freq_for_dnbs((__int64)v170, 0);
            v255 = 0;
            goto LABEL_147;
          }
        }
        else if ( vdev_by_user )
        {
          goto LABEL_143;
        }
        v255 = 1;
LABEL_147:
        sap_release_vdev_ref(v169);
        if ( v171 == 1 )
          ucfg_ipa_flush_pending_vdev_events(v170[1], *(unsigned __int8 *)(v40 + 8));
        if ( (v255 & 1) == 0 )
          _hdd_objmgr_put_vdev_by_user(vdev_by_user, 36, "hdd_stop_sap_go_per_link");
        hdd_vdev_destroy(v40, v256, v257, v258, v259, v260, v261, v262, v263);
        mutex_unlock(v170 + 24);
        if ( (unsigned __int8)(73 * ((unsigned int)(v40 - *(_DWORD *)v40 - 52840) >> 3) + 1) <= 2u )
        {
          v264 = (unsigned __int8)(73 * ((unsigned int)(v40 - *(_DWORD *)v40 - 52840) >> 3) + 1);
          v40 = 0;
          v265 = a2 + 52840 + 6088LL * (unsigned int)v264;
          do
          {
            if ( v40 )
              break;
            v266 = *(_QWORD *)(a2 + 1640) >> v264++;
            v40 = (v266 << 63 >> 63) & v265;
            v265 += 6088;
          }
          while ( v264 != 3 );
          if ( v40 )
            continue;
        }
        goto LABEL_27;
      }
    }
LABEL_29:
    v291 = v10;
    if ( !a2 )
    {
LABEL_35:
      cancel_work_sync(a2 + 48);
      cancel_work_sync(a2 + 80);
      goto LABEL_36;
    }
    if ( (*(_QWORD *)(a2 + 1640) & 1) != 0 )
    {
      v41 = (unsigned __int8 *)(a2 + 52840);
    }
    else
    {
      v41 = (unsigned __int8 *)(a2 + 58928);
      if ( a2 == -58928 || (*(_QWORD *)(a2 + 1640) & 2) == 0 )
      {
        v41 = (unsigned __int8 *)(a2 + 65016);
        if ( a2 == -65016 || (*(_QWORD *)(a2 + 1640) & 4) == 0 )
          goto LABEL_35;
      }
    }
    v56 = "hdd_stop_station_adapter";
    v57 = a2 + 52840;
    v293 = *(_DWORD *)(a2 + 40);
    while ( 1 )
    {
      v58 = _hdd_objmgr_get_vdev_by_user(v41, 36, v56);
      if ( v58 )
        break;
LABEL_79:
      if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v41 - *(_DWORD *)v41 - 52840) >> 3) + 1) <= 2u )
      {
        v133 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v41 - *(_DWORD *)v41 - 52840) >> 3) + 1);
        v41 = nullptr;
        v134 = v57 + 6088LL * (unsigned int)v133;
        do
        {
          if ( v41 )
            break;
          v135 = *(_QWORD *)(a2 + 1640) >> v133++;
          v41 = (unsigned __int8 *)((v135 << 63 >> 63) & v134);
          v134 += 6088;
        }
        while ( v133 != 3 );
        if ( v41 )
          continue;
      }
      goto LABEL_35;
    }
    v59 = v58;
    if ( v39 != 11 )
    {
      if ( !hdd_cm_is_disconnected((__int64)v41) )
      {
        v93 = *(_QWORD *)v41;
        v94 = (cds_get_driver_state(v85, v86, v87, v88, v89, v90, v91, v92) & 8) != 0 ? 65525 : 65528;
        v95 = wlan_hdd_cm_issue_disconnect((__int64)v41, v94, 1);
        if ( (_DWORD)v95 )
        {
          if ( (ucfg_ipa_is_enabled(v95) & 1) != 0 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: STA disconnect failed",
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              "hdd_sta_disconnect_and_cleanup");
            ucfg_ipa_uc_cleanup_sta(*(_QWORD *)(*(_QWORD *)(v93 + 24) + 8LL), *(_QWORD *)(v93 + 32), v41[8]);
          }
        }
      }
      goto LABEL_70;
    }
    v60 = *(_QWORD *)v41;
    v61 = v57;
    v62 = v56;
    v63 = *(_QWORD *)(*(_QWORD *)v41 + 24LL);
    v64 = hdd_destroy_adapter_sysfs_files(*(_QWORD *)v41);
    *(_DWORD *)(v60 + 1744) = 0;
    v65 = *(_QWORD *)v41;
    v66 = *(_QWORD **)(*(_QWORD *)v41 + 24LL);
    if ( (hdd_any_valid_peer_present((__int64)v41, v64, v67, v68, v69, v70, v71, v72, v73) & 1) != 0 )
    {
      if ( *(_DWORD *)(v65 + 40) != 11
        || (unsigned int)ucfg_nan_disable_ndi(*v66, v41[8])
        || !(unsigned int)qdf_wait_for_event_completion(v65 + 52408, 0x1388u) )
      {
LABEL_66:
        v56 = v62;
        v57 = v61;
        v39 = v293;
        if ( !(unsigned int)sme_roam_ndi_stop(*(_QWORD *)(v63 + 16), v41[8]) )
        {
          if ( !wait_for_completion_timeout(v60 + 1744, 4500) )
            qdf_trace_msg(
              0x33u,
              3u,
              "%s: disconn_comp_var wait fail",
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              v121,
              v122,
              "hdd_stop_and_cleanup_ndi");
          hdd_cleanup_ndi(v41);
        }
LABEL_70:
        hdd_reset_scan_operation(v41);
        wlan_hdd_cleanup_actionframe(v41);
        wlan_hdd_flush_pmksa_cache((__int64)v41);
        if ( !v39 )
        {
          ucfg_ipa_flush_pending_vdev_events(*(_QWORD *)(v59 + 216), v41[8]);
          ucfg_cm_delete_crypto_keys_for_all_links();
        }
        _hdd_objmgr_put_vdev_by_user(v59, 36, v56);
        v131 = *(_DWORD *)(a2 + 40);
        v132 = *(_QWORD **)(a2 + 24);
        if ( (v131 == 16 || !v131 && (ucfg_nan_is_vdev_creation_allowed(*v132) & 1) == 0)
          && (ucfg_is_nan_conc_control_supported(*v132) & 1) != 0
          && (ucfg_is_nan_disc_active(*v132) & 1) != 0 )
        {
          v123 = ucfg_disable_nan_discovery(*v132, 0, 0);
        }
        hdd_vdev_destroy((__int64)v41, v123, v124, v125, v126, v127, v128, v129, v130);
        goto LABEL_79;
      }
      v82 = 8;
      v83 = "%s: peer_cleanup_done wait fail";
      v84 = "hdd_peer_cleanup";
    }
    else
    {
      v104 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*v66, v41[8], 20);
      if ( v104 )
      {
        v105 = v104;
        v106 = _ucfg_nan_set_ndi_state(v104, 9, "hdd_ndp_state_cleanup");
        wlan_objmgr_vdev_release_ref(v105, 0x14u, v107, v106, v108, v109, v110, v111, v112, v113, v114);
        goto LABEL_66;
      }
      v82 = 2;
      v83 = "%s: Cannot obtain NDI vdev object!";
      v84 = "hdd_ndp_state_cleanup";
    }
    qdf_trace_msg(0x33u, v82, v83, v74, v75, v76, v77, v78, v79, v80, v81, v84, v291);
    goto LABEL_66;
  }
  if ( v39 <= 7 )
  {
    if ( v39 != 6 )
      goto LABEL_29;
    v157 = *(_QWORD *)(a2 + 24);
    if ( a2 )
    {
      if ( (*(_QWORD *)(a2 + 1640) & 1) != 0 )
      {
        v158 = v10 + 1;
      }
      else
      {
        v158 = (_DWORD *)(a2 + 58928);
        if ( a2 == -58928 || (*(_QWORD *)(a2 + 1640) & 2) == 0 )
        {
          v158 = (_DWORD *)(a2 + 65016);
          if ( a2 == -65016 || (*(_QWORD *)(a2 + 1640) & 4) == 0 )
            goto LABEL_97;
        }
      }
      do
      {
        v38 = wlan_hdd_delete_mon_link(a2, v158);
        if ( (unsigned __int8)(73 * ((unsigned int)((_DWORD)v158 - *v158 - 52840) >> 3) + 1) > 2u )
          break;
        v288 = (unsigned __int8)(73 * ((unsigned int)((_DWORD)v158 - *v158 - 52840) >> 3) + 1);
        v158 = nullptr;
        v289 = a2 + 52840 + 6088LL * (unsigned int)v288;
        do
        {
          if ( v158 )
            break;
          v290 = *(_QWORD *)(a2 + 1640) >> v288++;
          v158 = (_DWORD *)((v290 << 63 >> 63) & v289);
          v289 += 6088;
        }
        while ( v288 != 3 );
      }
      while ( v158 );
    }
LABEL_97:
    if ( (unsigned int)hdd_disable_monitor_mode(v38) )
    {
      v167 = jiffies;
      if ( hdd_stop_mon_adapter___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: datapath reset failed for montior mode",
          v159,
          v160,
          v161,
          v162,
          v163,
          v164,
          v165,
          v166,
          "hdd_stop_mon_adapter");
        hdd_stop_mon_adapter___last_ticks = v167;
      }
    }
    hdd_set_idle_ps_config(v157, 1, v159, v160, v161, v162, v163, v164, v165, v166);
    goto LABEL_37;
  }
  if ( v39 != 8 )
  {
    if ( v39 != 16 && v39 != 11 )
      goto LABEL_37;
    goto LABEL_29;
  }
  v136 = *v10;
  v137 = _hdd_objmgr_get_vdev_by_user(*v10, 36, "hdd_stop_ocb_adapter");
  context = _cds_get_context(71, (__int64)"hdd_stop_ocb_adapter", v138, v139, v140, v141, v142, v143, v144, v145);
  if ( context && *context && (v155 = *(_QWORD *)(*context + 72LL)) != 0 )
  {
    v156 = *(void (**)(void))(v155 + 8);
    if ( v156 )
    {
      if ( *((_DWORD *)v156 - 1) != -1003232309 )
        __break(0x8228u);
      v156();
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v147, v148, v149, v150, v151, v152, v153, v154, "cdp_clear_peer");
  }
  if ( v137 )
    _hdd_objmgr_put_vdev_by_user(v137, 36, "hdd_stop_ocb_adapter");
  hdd_vdev_destroy(v136, v147, v148, v149, v150, v151, v152, v153, v154);
LABEL_37:
  wlan_cfg80211_cleanup_scan_queue(*(_QWORD *)(a1 + 8), *(_QWORD *)(a2 + 32));
  if ( !*(_DWORD *)(a2 + 40) )
  {
    if ( a2 )
    {
      v50 = 0;
      v51 = v10 + 1;
      do
      {
        if ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v50 >> 3)) > 2 )
          break;
        v52 = *v51;
        *((_WORD *)v51 + 38) = 0;
        *((_DWORD *)v51 + 18) = 0;
        v53 = 0x71B3F945A27B1F49LL * ((a2 + v50 - v52) >> 3);
        if ( (unsigned __int8)v53 > 2u )
          __break(0x5512u);
        v51 += 761;
        v50 += 6088;
        *(_BYTE *)(a2 + 1632 + (v53 & 3)) = v53;
      }
      while ( v51 );
    }
    v54 = *(_BYTE *)(a2 + 1648);
    *v10 = (__int64)(v10 + 1);
    *(_QWORD *)(a2 + 1640) = (unsigned int)~(-1 << v54);
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v42, v43, v44, v45, v46, v47, v48, v49, "hdd_stop_adapter_ext", v291);
  _ReadStatusReg(SP_EL0);
  return 0;
}
