__int64 __fastcall _hdd_cm_disconnect_handler_post_user_update(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x21
  __int64 *v15; // x20
  __int64 v16; // x23
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w24
  __int64 values; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x0
  int v84; // w8
  const char *v85; // x4
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x3
  __int64 v103; // x4
  __int64 v104; // x5
  __int64 result; // x0
  int v106; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v107; // [xsp+38h] [xbp-8h]

  v107 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)a1;
  v15 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v16 = v15[2];
  ucfg_p2p_status_disconnect(a2, a4, a5, a6, a7, a8, a9, a10, a11);
  hdd_cfr_disconnect(a2);
  ucfg_cm_reset_key(v15[1], *(_BYTE *)(a1 + 8));
  hdd_clear_roam_profile_ie(v14, v17, v18, v19, v20, v21, v22, v23, v24);
  wlan_hdd_reset_bcn_rssi_history_stats(a1);
  if ( !*(_DWORD *)(v14 + 40) )
    wlan_crypto_reset_vdev_params(a2, v25, v26, v27, v28, v29, v30, v31, v32);
  hdd_remove_beacon_filter((__int64)v15, *(_BYTE *)(a1 + 8));
  if ( (sme_is_beacon_report_started(v16, *(unsigned __int8 *)(a1 + 8)) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Sending beacon pause indication to userspace",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "__hdd_cm_disconnect_handler_post_user_update");
    hdd_beacon_recv_pause_indication(v15, *(unsigned __int8 *)(a1 + 8), 19, 1);
  }
  hdd_conn_remove_connect_info(a1 + 80);
  if ( a3 != 16 )
  {
    hdd_wmm_adapter_clear(v14);
    v41 = hdd_adapter_reset_station_ctx(v14);
  }
  ucfg_dp_remove_conn_info(a2, v41, v42, v43, v44, v45, v46, v47, v48);
  v49 = *(unsigned __int8 *)(a1 + 8);
  values = cfg_psoc_get_values(*v15);
  if ( (unsigned int)sme_cli_set_command(v49, 44, *(unsigned int *)(values + 1192), 1) )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Failed to set RTS_PROFILE",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "__hdd_cm_disconnect_handler_post_user_update");
  hdd_init_scan_reject_params(v15);
  ucfg_pmo_flush_gtk_offload_req(a2);
  if ( (*(_DWORD *)(v14 + 40) | 2) == 2 )
  {
    ((void (__fastcall *)(__int64, _QWORD))sme_ps_disable_auto_ps_timer)(v16, *(unsigned __int8 *)(a1 + 8));
    *(_BYTE *)(v14 + 52208) = 1;
  }
  v59 = wlan_hdd_clear_link_layer_stats(v14);
  ucfg_dp_reset_cont_txtimeout_cnt(a2, v59, v60, v61, v62, v63, v64, v65, v66);
  ucfg_dp_clear_net_dev_stats(*(_QWORD *)(v14 + 32));
  ucfg_dp_nud_reset_tracking(a2, v67, v68, v69, v70, v71, v72, v73, v74);
  hdd_reset_limit_off_chan(v14);
  v83 = *(_QWORD *)a1;
  if ( *(_WORD *)(*(_QWORD *)a1 + 57392LL) )
  {
    v84 = *(_DWORD *)(v83 + 40);
    v106 = 0;
    if ( v84 <= 2 )
    {
      switch ( v84 )
      {
        case 0:
          wlan_hdd_save_sta_keep_alive_interval(v83, 0);
          ucfg_mlme_get_sta_keep_alive_period(*v15, &v106);
          hdd_vdev_send_sta_keep_alive_interval(a1, (__int64)v15, v106);
          goto LABEL_29;
        case 1:
          v85 = "PM_SAP_MODE";
          goto LABEL_28;
        case 2:
          v85 = "PM_P2P_CLIENT_MODE";
LABEL_28:
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Not supported for device mode %s = ",
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            v82,
            "hdd_reset_sta_keep_alive_interval",
            v85);
          goto LABEL_29;
      }
    }
    else
    {
      if ( v84 <= 4 )
      {
        if ( v84 == 3 )
          v85 = "PM_P2P_GO_MODE";
        else
          v85 = "PM_NDI_MODE";
        goto LABEL_28;
      }
      if ( v84 == 5 )
      {
        v85 = "PM_NAN_DISC_MODE";
        goto LABEL_28;
      }
      if ( v84 == 6 )
      {
        v85 = "PM_LL_LT_SAP_MODE";
        goto LABEL_28;
      }
    }
    v85 = "Unknown";
    goto LABEL_28;
  }
LABEL_29:
  qdf_trace_msg(0x33u, 8u, "*********** WIFI DATA LOGGER **************", v75, v76, v77, v78, v79, v80, v81, v82);
  qdf_trace_msg(
    0x33u,
    8u,
    "freq: %d dot11mode %d AKM %d ssid: \"%.*s\" ,roam_count %d nss %d legacy %d mcs %d signal %d noise: %d",
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    *(unsigned int *)(a1 + 692),
    *(unsigned int *)(a1 + 680),
    *(unsigned int *)(a1 + 880),
    *(unsigned __int8 *)(a1 + 840),
    a1 + 841,
    *(_DWORD *)(a1 + 828),
    *(unsigned __int8 *)(a1 + 701),
    *(unsigned __int16 *)(a1 + 698),
    *(unsigned __int8 *)(a1 + 700),
    *(char *)(a1 + 832),
    *(char *)(a1 + 724));
  if ( (*(_BYTE *)(a1 + 763) & 1) == 0 )
  {
    v102 = 0;
    if ( (*(_BYTE *)(a1 + 763) & 2) != 0 )
      goto LABEL_31;
LABEL_34:
    v103 = 0;
    if ( (*(_BYTE *)(a1 + 763) & 8) != 0 )
      goto LABEL_32;
LABEL_35:
    v104 = 0;
    goto LABEL_36;
  }
  v102 = *(unsigned int *)(a1 + 725);
  if ( (*(_BYTE *)(a1 + 763) & 2) == 0 )
    goto LABEL_34;
LABEL_31:
  v103 = *(unsigned int *)(a1 + 751);
  if ( (*(_BYTE *)(a1 + 763) & 8) == 0 )
    goto LABEL_35;
LABEL_32:
  v104 = *(unsigned __int8 *)(a1 + 765) >> 4;
LABEL_36:
  qdf_trace_msg(
    0x33u,
    8u,
    "HT 0x%x VHT 0x%x ht20 info 0x%x",
    v94,
    v95,
    v96,
    v97,
    v98,
    v99,
    v100,
    v101,
    v102,
    v103,
    v104);
  if ( v14 && (*(_QWORD *)(v14 + 1640) & 1) != 0 )
  {
    while ( (unsigned __int8)(19 * ((unsigned int)(v14 - *(_DWORD *)(v14 + 52832)) >> 4)) == 255
         && (*(_QWORD *)(v14 + 1640) & 1) != 0 )
      ;
    *(_DWORD *)(v14 + 53660) = 0;
  }
  result = ucfg_clear_user_disabled_roaming(*v15, *(unsigned __int8 *)(a1 + 8));
  _ReadStatusReg(SP_EL0);
  return result;
}
