__int64 __fastcall hdd_features_init(
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
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
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
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x0
  int v57; // w21
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
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
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x21
  unsigned int inited; // w0
  unsigned int v92; // w0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned int v101; // w19
  __int64 result; // x0
  unsigned __int8 tx_power; // w0
  __int64 v104; // x8
  unsigned int v105; // w0
  double v106; // d0
  double v107; // d1
  double v108; // d2
  double v109; // d3
  double v110; // d4
  double v111; // d5
  double v112; // d6
  double v113; // d7
  int v114; // w0
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
  const char *v131; // x2
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  _BYTE v140[4]; // [xsp+Ch] [xbp-54h] BYREF
  _BYTE v141[4]; // [xsp+10h] [xbp-50h] BYREF
  _BYTE v142[4]; // [xsp+14h] [xbp-4Ch] BYREF
  char v143[4]; // [xsp+18h] [xbp-48h] BYREF
  _BYTE v144[4]; // [xsp+1Ch] [xbp-44h] BYREF
  __int64 v145; // [xsp+20h] [xbp-40h] BYREF
  __int64 v146; // [xsp+28h] [xbp-38h] BYREF
  int v147; // [xsp+30h] [xbp-30h] BYREF
  int v148; // [xsp+34h] [xbp-2Ch] BYREF
  __int64 v149; // [xsp+38h] [xbp-28h] BYREF
  int v150; // [xsp+40h] [xbp-20h]
  int v151; // [xsp+44h] [xbp-1Ch]
  int v152; // [xsp+48h] [xbp-18h]
  int v153; // [xsp+4Ch] [xbp-14h]
  int v154; // [xsp+50h] [xbp-10h]
  int v155; // [xsp+54h] [xbp-Ch]
  __int64 v156; // [xsp+58h] [xbp-8h]

  v156 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v145 = 0;
  v144[0] = 0;
  v143[0] = 0;
  v142[0] = 0;
  v141[0] = 0;
  v140[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_features_init");
  v10 = *(_QWORD *)a1;
  v148 = 0;
  v147 = 0;
  v146 = 0;
  ucfg_mlme_get_mws_coex_4g_quick_tdm(v10, &v148);
  v11 = *(_QWORD *)a1;
  LODWORD(v149) = 164;
  HIDWORD(v149) = v148;
  ucfg_mlme_get_mws_coex_5g_nr_pwr_limit(v11, &v147);
  v12 = *(_QWORD *)a1;
  v150 = 165;
  v151 = v147;
  ucfg_mlme_get_mws_coex_pcc_channel_avoid_delay(v12, (_DWORD *)&v146 + 1);
  v13 = *(_QWORD *)a1;
  v152 = 193;
  v153 = HIDWORD(v146);
  ucfg_mlme_get_mws_coex_scc_channel_avoid_delay(v13, &v146);
  v154 = 194;
  v155 = v146;
  if ( (unsigned int)sme_send_multi_pdev_vdev_set_params(0, 0, &v149, 4) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to send pdev MWSCOEX set params",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_init_mws_coex");
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Error initializing mws-coex",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "hdd_features_init");
  }
  v30 = *(_QWORD *)(a1 + 16);
  sme_setdef_dot11mode(v30);
  wlan_mlme_is_imps_enabled(*(_QWORD *)a1, v143);
  hdd_set_idle_ps_config(a1, v143[0], v31, v32, v33, v34, v35, v36, v37, v38);
  v39 = ucfg_dp_fw_data_stall_evt_enabled();
  sme_cli_set_command(0, 155, v39, 2);
  ucfg_mlme_get_go_cts2self_for_sta(*(_QWORD *)a1, v144);
  if ( v144[0] == 1 )
    sme_set_cts2self_for_p2p_go(v30);
  if ( (unsigned int)sme_set_vc_mode_config(*(unsigned int *)(*(_QWORD *)(a1 + 104) + 4LL)) )
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Error in setting Voltage Corner mode config to FW",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "hdd_features_init");
  if ( (unsigned int)ucfg_dp_rx_ol_init(*(_QWORD *)a1, *(_BYTE *)(a1 + 7088)) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to initialize Rx LRO/GRO in fw",
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      "hdd_features_init");
  v56 = *(_QWORD *)a1;
  v150 = 0;
  v149 = 0;
  ucfg_fwol_get_all_adaptive_dwelltime_params(v56, &v149);
  v57 = fwol_set_adaptive_dwelltime_config(&v149);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Sending Adaptive Dwelltime Configuration to fw",
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    "hdd_adaptive_dwelltime_init");
  if ( v57 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to send Adaptive Dwelltime configuration!",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "hdd_adaptive_dwelltime_init");
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to send adaptive dwelltime setting to FW",
      v74,
      v75,
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      "hdd_features_init");
  }
  if ( (unsigned int)hdd_dbs_scan_selection_init((__int64 *)a1) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Unable to send DBS scan selection setting to FW",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "hdd_features_init");
  v90 = *(_QWORD *)(a1 + 16);
  inited = sme_init_thermal_info(v90);
  if ( inited )
  {
    v92 = qdf_status_to_os_return(inited);
    if ( v92 )
    {
      v101 = v92;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Error while initializing thermal information",
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        "hdd_features_init");
      result = v101;
      goto LABEL_37;
    }
  }
  else
  {
    sme_add_set_thermal_level_callback(v90, hdd_set_thermal_level_cb);
  }
  if ( curr_con_mode != 4 )
    cds_get_driver_state(v93, v94, v95, v96, v97, v98, v99, v100);
  tx_power = wlan_mlme_get_tx_power(*(_QWORD *)a1, 1);
  v104 = *(_QWORD *)a1;
  LODWORD(v145) = tx_power;
  HIDWORD(v145) = (unsigned __int8)wlan_mlme_get_tx_power(v104, 2);
  v105 = sme_txpower_limit(v30, &v145);
  if ( v105 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error setting txlimit in sme: %d",
      v106,
      v107,
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      "hdd_features_init",
      v105);
  wlan_hdd_tsf_init(a1);
  v114 = sme_enable_disable_chanavoidind_event(v30, 0);
  if ( v114 && v114 != 11 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to disable Chan Avoidance Indication",
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      "hdd_features_init");
    result = 4294967274LL;
    goto LABEL_37;
  }
  if ( (wma_is_p2p_lo_capable() & 1) != 0 )
    sme_register_p2p_lo_event(v30, a1, wlan_hdd_p2p_lo_event_callback);
  wlan_hdd_register_mcc_quota_event_callback(a1);
  wlan_hdd_init_chan_info((__int64 *)a1);
  wlan_hdd_twt_init(a1);
  if ( (unsigned int)wlan_mlme_is_rf_test_mode_enabled(*(_QWORD *)a1, v142) )
  {
    v131 = "%s: Get rf test mode failed";
LABEL_36:
    qdf_trace_msg(0x33u, 2u, v131, v123, v124, v125, v126, v127, v128, v129, v130, "hdd_features_init");
    result = 16;
    goto LABEL_37;
  }
  if ( v142[0] == 1 )
  {
    wlan_cm_set_check_6ghz_security(*(_QWORD *)a1, 0);
    wlan_cm_set_6ghz_key_mgmt_mask(*(_QWORD *)a1, 0xFFFFFFFF);
  }
  if ( (unsigned int)wlan_mlme_is_standard_6ghz_conn_policy_enabled(*(_QWORD *)a1, v141) )
  {
    v131 = "%s: Get 6ghz standard connection policy failed";
    goto LABEL_36;
  }
  if ( v141[0] == 1 )
    wlan_cm_set_standard_6ghz_conn_policy(*(_QWORD *)a1, 1);
  if ( (unsigned int)wlan_mlme_is_relaxed_lpi_conn_policy_enabled(*(_QWORD *)a1, v140) )
  {
    v131 = "%s: Get relaxed LPI connection policy failed";
    goto LABEL_36;
  }
  if ( v140[0] == 1 )
    wlan_cm_set_relaxed_lpi_conn_policy(*(_QWORD *)a1, 1);
  hdd_send_get_thermal_stats_cmd(a1, 1, 0, 0);
  sme_set_cal_failure_event_cb(*(_QWORD *)(a1 + 16), hdd_cal_fail_send_event);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v132, v133, v134, v135, v136, v137, v138, v139, "hdd_features_init");
  result = 0;
LABEL_37:
  _ReadStatusReg(SP_EL0);
  return result;
}
