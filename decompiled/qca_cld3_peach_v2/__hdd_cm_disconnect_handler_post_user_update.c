__int64 __fastcall _hdd_cm_disconnect_handler_post_user_update(
        unsigned __int8 *a1,
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
  int v15; // w25
  __int64 *v16; // x19
  __int64 v17; // x23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
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
  unsigned int v50; // w24
  __int64 values; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
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
  int *v105; // x10
  __int64 result; // x0
  int v107; // w14
  __int64 v108; // x14
  __int64 v109; // x15
  __int64 v110; // x10
  int v111; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v112; // [xsp+38h] [xbp-8h]

  v112 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)a1;
  v15 = *(_DWORD *)(a2 + 64);
  v16 = *(__int64 **)(*(_QWORD *)a1 + 24LL);
  v17 = v16[2];
  ucfg_p2p_status_disconnect(a2, a4, a5, a6, a7, a8, a9, a10, a11);
  hdd_cfr_disconnect(a2);
  ucfg_cm_reset_key(v16[1], a1[8]);
  hdd_clear_roam_profile_ie(v14, v18, v19, v20, v21, v22, v23, v24, v25);
  wlan_hdd_reset_bcn_rssi_history_stats(a1);
  if ( !*(_DWORD *)(v14 + 40) )
    wlan_crypto_reset_vdev_params(a2, v26, v27, v28, v29, v30, v31, v32, v33);
  hdd_remove_beacon_filter((__int64)v16, a1[8]);
  if ( (sme_is_beacon_report_started(v17, a1[8]) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Sending beacon pause indication to userspace",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "__hdd_cm_disconnect_handler_post_user_update");
    hdd_beacon_recv_pause_indication(v16, a1[8], 19, 1);
  }
  if ( (v15 & 0x2000000) == 0 )
  {
    hdd_conn_remove_connect_info((__int64)(a1 + 80));
    if ( a3 == 16 )
    {
      hdd_cm_clear_ieee_link_id((__int64)a1, 0, v42, v43, v44, v45, v46, v47, v48, v49);
    }
    else
    {
      hdd_wmm_adapter_clear(v14);
      v34 = hdd_adapter_reset_station_ctx(v14);
    }
  }
  ucfg_dp_remove_conn_info(a2, v34, v35, v36, v37, v38, v39, v40, v41);
  v50 = a1[8];
  values = cfg_psoc_get_values(*v16);
  if ( (unsigned int)sme_cli_set_command(v50, 44, *(unsigned int *)(values + 1268), 1) )
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Failed to set RTS_PROFILE",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "__hdd_cm_disconnect_handler_post_user_update");
  hdd_init_scan_reject_params(v16);
  ucfg_pmo_flush_gtk_offload_req(a2);
  if ( (*(_DWORD *)(v14 + 40) | 2) == 2 )
  {
    ((void (__fastcall *)(__int64, _QWORD))sme_ps_disable_auto_ps_timer)(v17, a1[8]);
    *(_BYTE *)(v14 + 52208) = 1;
  }
  v60 = wlan_hdd_clear_link_layer_stats(v14);
  ucfg_dp_reset_cont_txtimeout_cnt(a2, v60, v61, v62, v63, v64, v65, v66, v67);
  ucfg_dp_clear_net_dev_stats(*(_QWORD *)(v14 + 32));
  ucfg_dp_nud_reset_tracking(a2, v68, v69, v70, v71, v72, v73, v74, v75);
  hdd_reset_limit_off_chan(v14);
  if ( (v15 & 0x2000000) == 0 && *(_WORD *)(*(_QWORD *)a1 + 71144LL) )
  {
    v84 = *(_DWORD *)(*(_QWORD *)a1 + 40LL);
    v111 = 0;
    if ( v84 > 2 )
    {
      if ( v84 <= 4 )
      {
        if ( v84 == 3 )
          v85 = "PM_P2P_GO_MODE";
        else
          v85 = "PM_NDI_MODE";
        goto LABEL_33;
      }
      if ( v84 == 5 )
      {
        v85 = "PM_NAN_DISC_MODE";
        goto LABEL_33;
      }
      if ( v84 == 6 )
      {
        v85 = "PM_LL_LT_SAP_MODE";
        goto LABEL_33;
      }
      goto LABEL_29;
    }
    if ( v84 )
    {
      if ( v84 == 1 )
      {
        v85 = "PM_SAP_MODE";
        goto LABEL_33;
      }
      if ( v84 == 2 )
      {
        v85 = "PM_P2P_CLIENT_MODE";
LABEL_33:
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Not supported for device mode %s = ",
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          "hdd_reset_sta_keep_alive_interval",
          v85);
        goto LABEL_34;
      }
LABEL_29:
      v85 = "Unknown";
      goto LABEL_33;
    }
    if ( (wlan_vdev_mlme_get_is_mlo_link(*v16, a1[8]) & 1) == 0 )
      wlan_hdd_save_sta_keep_alive_interval(*(_QWORD *)a1, 0);
    ucfg_mlme_get_sta_keep_alive_period(*v16, &v111);
    hdd_vdev_send_sta_keep_alive_interval((__int64)a1, (__int64)v16, v111);
  }
LABEL_34:
  qdf_trace_msg(0x33u, 8u, "*********** WIFI DATA LOGGER **************", v76, v77, v78, v79, v80, v81, v82, v83);
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
    *((unsigned int *)a1 + 175),
    *((unsigned int *)a1 + 172),
    *((unsigned int *)a1 + 222),
    a1[848],
    a1 + 849,
    *((_DWORD *)a1 + 209),
    a1[709],
    *((unsigned __int16 *)a1 + 353),
    a1[708],
    (char)a1[840],
    (char)a1[732]);
  if ( (a1[771] & 1) == 0 )
  {
    v102 = 0;
    if ( (a1[771] & 2) != 0 )
      goto LABEL_36;
LABEL_39:
    v103 = 0;
    if ( (a1[771] & 8) != 0 )
      goto LABEL_37;
    goto LABEL_40;
  }
  v102 = *(unsigned int *)(a1 + 733);
  if ( (a1[771] & 2) == 0 )
    goto LABEL_39;
LABEL_36:
  v103 = *(unsigned int *)(a1 + 759);
  if ( (a1[771] & 8) != 0 )
  {
LABEL_37:
    v104 = a1[773] >> 4;
    goto LABEL_41;
  }
LABEL_40:
  v104 = 0;
LABEL_41:
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
  if ( !v14 )
    goto LABEL_47;
  if ( (*(_QWORD *)(v14 + 1640) & 1) != 0 )
  {
    v105 = (int *)(v14 + 52840);
  }
  else
  {
    v105 = (int *)(v14 + 58928);
    if ( v14 == -58928 || (*(_QWORD *)(v14 + 1640) & 2) == 0 )
    {
      v105 = (int *)(v14 + 65016);
      if ( v14 == -65016 || (*(_QWORD *)(v14 + 1640) & 4) == 0 )
        goto LABEL_47;
    }
  }
  do
  {
    v107 = *v105;
    v105[209] = 0;
    LODWORD(v108) = 73 * ((unsigned int)((_DWORD)v105 - v107 - 52840) >> 3) + 1;
    if ( (unsigned __int8)v108 > 2u )
      break;
    v108 = (unsigned __int8)v108;
    v105 = nullptr;
    v109 = v14 + 52840 + 6088LL * (unsigned __int8)v108;
    do
    {
      if ( v105 )
        break;
      v110 = *(_QWORD *)(v14 + 1640) >> v108++;
      v105 = (int *)((v110 << 63 >> 63) & v109);
      v109 += 6088;
    }
    while ( v108 != 3 );
  }
  while ( v105 );
LABEL_47:
  ucfg_clear_user_disabled_roaming(*v16, a1[8]);
  result = wlan_mlme_set_ext_mld_cap_supp(*v16, 0);
  _ReadStatusReg(SP_EL0);
  return result;
}
