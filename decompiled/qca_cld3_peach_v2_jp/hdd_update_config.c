__int64 __fastcall hdd_update_config(__int64 *a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _QWORD *context; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x0
  char v53; // w8
  int runtime_pm_delay; // w0
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x20
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  __int64 v68; // x0
  unsigned int v69; // w20
  __int64 v70; // x0
  _BYTE *v71; // x20
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 sap_max_offload_reorder_buffs; // x0
  char v99; // w8
  __int64 values; // x0
  char v101; // w9
  int v102; // w10
  char v103; // w8
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  _QWORD v112[2]; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v113[4]; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v114[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _BYTE v115[4]; // [xsp+20h] [xbp-10h] BYREF
  _BYTE v116[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v117; // [xsp+28h] [xbp-8h]

  v117 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (ucfg_pmo_is_ns_offloaded(*a1) & 1) != 0 )
    *((_BYTE *)a1 + 1168) = 1;
  LOBYTE(v112[0]) = 0;
  if ( _cds_get_context(66, (__int64)"hdd_update_ol_config", v2, v3, v4, v5, v6, v7, v8, v9) )
  {
    if ( (unsigned int)wlan_mlme_get_self_recovery(*a1, v112) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get self recovery ini config",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "hdd_update_ol_config");
    v10 = hdd_lpass_is_supported(a1);
  }
  context = _cds_get_context(61, (__int64)"hdd_update_hif_config", v10, v11, v12, v13, v14, v15, v16, v17);
  v112[0] = 0;
  v116[0] = 0;
  v115[0] = 0;
  if ( context )
  {
    v35 = (__int64)context;
    if ( (unsigned int)wlan_mlme_get_prevent_link_down(*a1, v116) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get prevent_link_down config",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "hdd_update_hif_config");
    if ( (unsigned int)wlan_mlme_get_self_recovery(*a1, v115) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get self recovery ini config",
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        "hdd_update_hif_config");
    v52 = *a1;
    v53 = *(_BYTE *)(a1[13] + 123);
    LOBYTE(v112[0]) = v115[0];
    BYTE1(v112[0]) = v53;
    runtime_pm_delay = ucfg_pmo_get_runtime_pm_delay(v52);
    v55 = *a1;
    HIDWORD(v112[0]) = runtime_pm_delay;
    v112[1] = ucfg_dp_get_rx_softirq_yield_duration(v55);
    hif_init_ini_config(v35, (int)v112);
    hif_set_enable_rpm(v35);
    if ( v116[0] == 1 )
      hif_vote_link_up(v35);
  }
  if ( curr_con_mode == 5 )
  {
    hdd_update_cds_config_ftm(a1);
    goto LABEL_28;
  }
  v56 = *a1;
  LODWORD(v112[0]) = 0;
  v116[0] = 0;
  v115[0] = 0;
  v114[0] = 0;
  v113[0] = 0;
  if ( !v56 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: psoc is null", v27, v28, v29, v30, v31, v32, v33, v34, "hdd_update_cds_config");
    goto LABEL_28;
  }
  v57 = _qdf_mem_malloc(0x94u, "hdd_update_cds_config", 16658);
  if ( !v57 )
    goto LABEL_28;
  *(_DWORD *)(v57 + 8) = 0;
  v58 = v57;
  wlan_mlme_get_sap_max_modulated_dtim(*a1, (_BYTE *)(v57 + 4));
  wlan_mlme_get_max_modulated_dtim_ms(*a1, (_WORD *)(v58 + 6));
  if ( (unsigned int)wlan_mlme_get_crash_inject(*a1, v115) )
  {
    v67 = "%s: Failed to get crash inject ini config";
LABEL_27:
    qdf_trace_msg(0x33u, 2u, v67, v59, v60, v61, v62, v63, v64, v65, v66, "hdd_update_cds_config");
    _qdf_mem_free(v58);
    goto LABEL_28;
  }
  if ( (unsigned int)wlan_mlme_get_self_recovery(*a1, v114) )
  {
    v67 = "%s: Failed to get self recovery ini config";
    goto LABEL_27;
  }
  if ( (unsigned int)wlan_mlme_get_fw_timeout_crash(*a1, v113) )
  {
    v67 = "%s: Failed to get fw timeout crash ini config";
    goto LABEL_27;
  }
  if ( (unsigned int)wlan_mlme_get_ito_repeat_count(*a1, v116) )
  {
    v67 = "%s: Failed to get ITO repeat count ini config";
    goto LABEL_27;
  }
  *(_BYTE *)(v58 + 121) = v115[0];
  wlan_mlme_get_sap_max_offload_peers(*a1, v112);
  *(_BYTE *)(v58 + 12) = v112[0];
  sap_max_offload_reorder_buffs = wlan_mlme_get_sap_max_offload_reorder_buffs(*a1, v112);
  v99 = v112[0];
  *(_BYTE *)(v58 + 14) = 1;
  *(_BYTE *)(v58 + 13) = v99;
  *(_BYTE *)(v58 + 15) = ucfg_ipa_uc_is_enabled(sap_max_offload_reorder_buffs) & 1;
  *(_BYTE *)(v58 + 16) = ucfg_dp_is_rx_common_thread_enabled(*a1) & 1;
  wlan_mlme_get_sap_max_peers(*a1, v112);
  *(_WORD *)v58 = v112[0];
  *(_DWORD *)(v58 + 32) = *(_DWORD *)(a1[13] + 196);
  values = cfg_psoc_get_values(*a1);
  v101 = v113[0];
  v102 = *(_DWORD *)(values + 4172);
  *(_BYTE *)(v58 + 37) = v114[0];
  v103 = v116[0];
  *(_BYTE *)(v58 + 38) = v101;
  *(_BYTE *)(v58 + 36) = v102;
  *(_BYTE *)(v58 + 120) = v103;
  *(_DWORD *)(v58 + 124) = *(unsigned __int8 *)(a1[13] + 64);
  *(_BYTE *)(v58 + 128) = hdd_tsf_is_tsf64_tx_set(a1) & 1;
  hdd_txrx_populate_cds_config(v58, a1);
  hdd_lpass_populate_cds_config(v58, a1);
  *(_BYTE *)(v58 + 146) = ucfg_pmo_is_fw_debug_enable(*a1) & 1;
  *(_BYTE *)(v58 + 147) = ucfg_cp_stats_is_bcn_rssi_history_report_cfg_enable(*a1) & 1;
  cds_init_ini_config(v58, v104, v105, v106, v107, v108, v109, v110, v111);
LABEL_28:
  v68 = *a1;
  LODWORD(v112[0]) = 0;
  v116[0] = 0;
  if ( (unsigned int)wlan_mlme_get_band_capability(v68, v112) )
  {
    v69 = -5;
  }
  else
  {
    v70 = _qdf_mem_malloc(4u, "hdd_update_user_config", 16757);
    if ( v70 )
    {
      v71 = (_BYTE *)v70;
      *(_BYTE *)(v70 + 2) = *(_DWORD *)a1[13];
      if ( (unsigned int)wlan_mlme_is_11d_enabled(*a1, v116) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid 11d_enable flag",
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          "hdd_update_user_config");
      *v71 = v116[0];
      v80 = *a1;
      v116[0] = 0;
      if ( (unsigned int)wlan_mlme_is_11h_enabled(v80, v116) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Invalid 11h_enable flag",
          v81,
          v82,
          v83,
          v84,
          v85,
          v86,
          v87,
          v88,
          "hdd_update_user_config");
      v71[1] = v116[0];
      v71[3] = wlan_reg_band_bitmap_to_band_info(v112[0]);
      wlan_objmgr_psoc_set_user_config(*a1, v71, v89, v90, v91, v92, v93, v94, v95, v96);
      _qdf_mem_free((__int64)v71);
      v69 = 0;
    }
    else
    {
      v69 = -12;
    }
  }
  hdd_update_regdb_offload_config(a1);
  _ReadStatusReg(SP_EL0);
  return v69;
}
