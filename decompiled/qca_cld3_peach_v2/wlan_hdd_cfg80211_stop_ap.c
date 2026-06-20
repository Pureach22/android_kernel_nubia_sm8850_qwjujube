__int64 __fastcall wlan_hdd_cfg80211_stop_ap(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 *v3; // x22
  __int64 v4; // x24
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  unsigned int v34; // w1
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  const char *v44; // x2
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x23
  __int64 v54; // x25
  const char *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
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
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x23
  __int16 v113; // w9
  __int16 v114; // w10
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
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  unsigned __int64 v141; // x10
  unsigned __int64 v148; // x10
  __int64 v149; // [xsp+8h] [xbp-28h] BYREF
  __int64 v150; // [xsp+10h] [xbp-20h] BYREF
  __int64 v151; // [xsp+18h] [xbp-18h]
  __int64 v152; // [xsp+20h] [xbp-10h]
  __int64 v153; // [xsp+28h] [xbp-8h]

  v153 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v149 = 0;
  if ( !(unsigned int)_osif_vdev_sync_op_start(a2, &v149, "wlan_hdd_cfg80211_stop_ap") )
  {
    if ( a1 )
    {
      v151 = 0;
      v152 = 0;
      v150 = 0;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: enter(%s)",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "__wlan_hdd_cfg80211_stop_ap",
        a2 + 296);
      v4 = 55520;
      v2 = *(_QWORD *)(a2 + 55520);
      if ( !v2 )
      {
        v33 = "%s: invalid link_info";
        v34 = 2;
LABEL_10:
        qdf_trace_msg(0x33u, v34, v33, v16, v17, v18, v19, v20, v21, v22, v23, "__wlan_hdd_cfg80211_stop_ap");
        v15 = -22;
        goto LABEL_11;
      }
      v3 = (__int64 *)(a1 + 1536);
      v24 = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_stop_ap");
      if ( (_DWORD)v24 )
      {
LABEL_6:
        _qdf_mem_free(*(_QWORD *)(v2 + 2432));
        *(_QWORD *)(v2 + 2432) = 0;
        qdf_trace_msg(0x33u, 8u, "%s: exit", v25, v26, v27, v28, v29, v30, v31, v32, "__wlan_hdd_cfg80211_stop_ap");
        v15 = 0;
LABEL_11:
        _osif_vdev_sync_op_stop(v149, "wlan_hdd_cfg80211_stop_ap");
        goto LABEL_12;
      }
      if ( *(_BYTE *)(a1 + 2024) == 1 )
      {
        v33 = "%s: wiphy is suspended";
        v34 = 8;
        goto LABEL_10;
      }
      if ( (unsigned int)hdd_get_conparam(v24) == 5 )
      {
        v44 = "%s: Command not allowed in FTM mode";
LABEL_17:
        qdf_trace_msg(0x33u, 2u, v44, v36, v37, v38, v39, v40, v41, v42, v43, "__wlan_hdd_cfg80211_stop_ap");
        goto LABEL_6;
      }
      if ( *(_DWORD *)(a1 + 3000) == 2 )
      {
        v44 = "%s: Driver module is closed; dropping request";
        goto LABEL_17;
      }
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(*(unsigned __int8 *)(v2 + 8), "__wlan_hdd_cfg80211_stop_ap") )
        goto LABEL_6;
      qdf_mtrace(51, 51, 0x1Cu, *(_BYTE *)(v2 + 8), *(_DWORD *)(a2 + 2728));
      if ( (*(_DWORD *)(a2 + 2728) | 2) != 3 )
      {
        v44 = "%s: stop ap is given on device modes other than SAP/GO. Hence return";
        goto LABEL_17;
      }
      if ( (unsigned int)policy_mgr_reset_sap_mandatory_channels(*v3) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: failed to reset mandatory channels",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "__wlan_hdd_cfg80211_stop_ap");
      hdd_abort_ongoing_sta_sae_connection(a1 + 1536, v45, v46, v47, v48, v49, v50, v51, v52);
    }
    else
    {
      __break(0x800u);
    }
    _X8 = (unsigned __int64 *)(v2 + 5968);
    __asm { PRFM            #0x11, [X8] }
    do
      v141 = __ldxr(_X8);
    while ( __stxr(v141 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    v53 = *(_QWORD *)(a2 + 4312);
    v54 = *(_QWORD *)(a2 + 2720);
    v55 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Event flags 0x%lx(%s) Device_mode %s(%d)",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "__wlan_hdd_cfg80211_stop_ap",
      v53,
      v54 + 296,
      v55,
      *(unsigned int *)(a2 + 2728));
    if ( *(_DWORD *)(a2 + 2728) == 1 )
    {
      if ( policy_mgr_is_vdev_ll_lt_sap(*v3, *(unsigned __int8 *)(v2 + 8)) )
        wlan_ll_sap_switch_bearer_on_stop_ap(*v3, *(unsigned __int8 *)(v2 + 8));
      wlan_hdd_del_station(a2 + 2688, 0);
      wlan_hdd_flush_pmksa_cache(v2);
    }
    policy_mgr_flush_deferred_csa(*v3, *(_BYTE *)(v2 + 8));
    cds_flush_work(v2 + 6056);
    *(_BYTE *)(v2 + 1424) = 0;
    hdd_dcs_clear(a2 + 2688);
    *(_DWORD *)(v2 + 2616) = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev %d Disabling queues",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "__wlan_hdd_cfg80211_stop_ap",
      *(unsigned __int8 *)(*(_QWORD *)(a2 + v4) + 8LL));
    wlan_hdd_netif_queue_control(a2 + 2688, 4, 1);
    wlan_hdd_cleanup_actionframe(v2);
    wlan_hdd_cleanup_remain_on_channel_ctx(v2);
    if ( (policy_mgr_is_hw_dbs_capable(*v3) & 1) == 0
      && *(_DWORD *)(a2 + 2728) == 1
      && !policy_mgr_is_vdev_ll_lt_sap(*v3, *(unsigned __int8 *)(v2 + 8)) )
    {
      ucfg_twt_cfg_reset_responder(*v3);
    }
    mutex_lock(a1 + 1728);
    if ( (*(_QWORD *)(v2 + 5968) & 2) == 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: SAP already down",
        v72,
        v73,
        v74,
        v75,
        v76,
        v77,
        v78,
        v79,
        "__wlan_hdd_cfg80211_stop_ap");
      mutex_unlock(a1 + 1728);
      goto LABEL_6;
    }
    qdf_event_reset(v2 + 128);
    if ( !(unsigned int)wlansap_stop_bss(*(_QWORD *)(v2 + 272))
      && (unsigned int)qdf_wait_single_event(v2 + 128, 0x4650u) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: qdf wait for single_event failed!!",
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        "__wlan_hdd_cfg80211_stop_ap");
      hdd_sap_indicate_disconnect_for_sta(a2 + 2688);
    }
    _X8 = (unsigned __int64 *)(v2 + 5968);
    __asm { PRFM            #0x11, [X8] }
    do
      v148 = __ldxr(_X8);
    while ( __stxr(v148 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    policy_mgr_decr_session_set_pcl(*v3, *(_DWORD *)(a2 + 2728), *(unsigned __int8 *)(v2 + 8));
    hdd_green_ap_start_state_mc(v3, *(unsigned int *)(a2 + 2728), 0);
    wlan_twt_concurrency_update(v3);
    wlan_set_sap_user_config_freq(*(_QWORD *)(v2 + 32), 0, v88, v89, v90, v91, v92, v93, v94, v95);
    wlan_sap_set_acs_band_mask(*(_QWORD *)(v2 + 32), 7, v96, v97, v98, v99, v100, v101, v102, v103);
    if ( !(unsigned int)if_mgr_deliver_event(
                          *(_QWORD *)(v2 + 32),
                          8u,
                          0,
                          v104,
                          v105,
                          v106,
                          v107,
                          v108,
                          v109,
                          v110,
                          v111) )
    {
      _qdf_mem_free(*(_QWORD *)(v2 + 2432));
      *(_QWORD *)(v2 + 2432) = 0;
      mutex_unlock(a1 + 1728);
      v112 = *(_QWORD *)(a1 + 1552);
      if ( (ucfg_pre_cac_is_active(*(_QWORD *)(a1 + 1536)) & 1) != 0 )
        ucfg_pre_cac_clean_up(*v3);
      v113 = *(_WORD *)(v2 + 76);
      v114 = *(unsigned __int8 *)(v2 + 8);
      LODWORD(v150) = *(_DWORD *)(v2 + 72);
      WORD2(v150) = v113;
      HIWORD(v150) = v114;
      v152 = 0;
      LODWORD(v151) = 257;
      if ( (unsigned int)sme_update_add_ie(v112, &v150, 1) == 16 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Could not pass on PROBE_RSP_BCN data to PE",
          v115,
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          "__wlan_hdd_cfg80211_stop_ap");
      if ( (unsigned int)sme_update_add_ie(v112, &v150, 3) == 16 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Could not pass on ASSOC_RSP data to PE",
          v123,
          v124,
          v125,
          v126,
          v127,
          v128,
          v129,
          v130,
          "__wlan_hdd_cfg80211_stop_ap");
      wlan_hdd_reset_prob_rspies(v2);
      hdd_destroy_acs_timer(a2 + 2688);
      ucfg_p2p_status_stop_bss(*(_QWORD *)(v2 + 32), v131, v132, v133, v134, v135, v136, v137, v138);
      goto LABEL_6;
    }
    v44 = "%s: Stopping the BSS failed";
    goto LABEL_17;
  }
  v15 = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v15;
}
