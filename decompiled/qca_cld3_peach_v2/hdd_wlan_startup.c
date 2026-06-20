__int64 __fastcall hdd_wlan_startup(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w0
  __int64 result; // x0
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w20
  __int64 v22; // x0
  unsigned int inited; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x1
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
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
  _QWORD *context; // x0
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned int v92; // w0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  const char *v101; // x2
  __int64 v102; // x0
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  __int64 v111; // x0
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  char v120[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v121; // [xsp+8h] [xbp-8h]

  v121 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v120[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_wlan_startup");
  _qdf_nbuf_init_replenish_timer();
  v10 = qdf_mutex_create((__int64)(a1 + 453));
  if ( v10 )
  {
    result = qdf_status_to_os_return(v10);
    goto LABEL_15;
  }
  _mutex_init(a1 + 398, "&hdd_ctx->avoid_freq_lock", &hdd_wlan_startup___key);
  osif_request_manager_init();
  hdd_driver_memdump_init();
  v12 = wlan_hdd_alloc_iface_combination_mem((__int64)a1);
  if ( !v12 )
  {
    inited = hdd_init_regulatory_update_event(a1);
    if ( inited )
    {
      v32 = "%s: Failed to initialize regulatory update event; errno:%d";
LABEL_9:
      v21 = inited;
      qdf_trace_msg(0x33u, 2u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "hdd_wlan_startup");
LABEL_10:
      v22 = wlan_hdd_free_iface_combination_mem((__int64)a1);
      goto LABEL_11;
    }
    inited = hdd_wlan_start_modules(a1, 0, v24, v25, v26, v27, v28, v29, v30, v31);
    if ( inited )
    {
      v32 = "%s: Failed to start modules; errno:%d";
      goto LABEL_9;
    }
    hdd_init_epm_value_cfg(a1[13], *a1);
    if ( curr_con_mode == 8 )
    {
      result = 0;
      goto LABEL_15;
    }
    wlan_hdd_update_wiphy(a1, v58, v59, v60, v61, v62, v63, v64, v65);
    context = _cds_get_context(52, (__int64)"hdd_wlan_startup", v66, v67, v68, v69, v70, v71, v72, v73);
    a1[2] = (__int64)context;
    if ( !context )
    {
      v21 = 0;
      goto LABEL_28;
    }
    v83 = hdd_wiphy_init(a1);
    if ( v83 )
    {
      v21 = v83;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to initialize wiphy; errno:%d",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "hdd_wlan_startup");
LABEL_28:
      hdd_wlan_stop_modules(a1, 0, v75, v76, v77, v78, v79, v80, v81, v82);
      goto LABEL_10;
    }
    v92 = hdd_initialize_mac_address(a1);
    if ( v92 )
    {
      v101 = "%s: MAC initializtion failed: %d";
    }
    else
    {
      v92 = register_netdevice_notifier(&hdd_netdev_notifier);
      if ( !v92 )
      {
        wlan_hdd_update_11n_mode(a1);
        v102 = ((__int64 (__fastcall *)(__int64 *))hdd_lpass_notify_wlan_version)(a1);
        if ( !(unsigned int)wlansap_global_init(v102) )
        {
          wlan_mlme_is_imps_enabled(*a1, v120);
          hdd_set_idle_ps_config((__int64)a1, v120[0], v103, v104, v105, v106, v107, v108, v109, v110);
          hdd_debugfs_mws_coex_info_init(a1);
          v111 = hdd_debugfs_ini_config_init(a1);
          wlan_hdd_create_mib_stats_lock(v111);
          wlan_cfg80211_init_interop_issues_ap(a1[1]);
          qdf_trace_msg(0x33u, 8u, "%s: exit", v112, v113, v114, v115, v116, v117, v118, v119, "hdd_wlan_startup");
          result = 0;
          goto LABEL_15;
        }
        unregister_netdevice_notifier(&hdd_netdev_notifier);
        v21 = 0;
        goto LABEL_27;
      }
      v101 = "%s: register_netdevice_notifier failed; errno:%d";
    }
    v21 = v92;
    qdf_trace_msg(0x33u, 2u, v101, v93, v94, v95, v96, v97, v98, v99, v100, "hdd_wlan_startup");
LABEL_27:
    qdf_dp_trace_deinit();
    wiphy_unregister(a1[3]);
    goto LABEL_28;
  }
  v21 = v12;
  v22 = qdf_trace_msg(
          0x33u,
          2u,
          "%s: failed to alloc iface combination mem",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "hdd_wlan_startup");
LABEL_11:
  hdd_driver_memdump_deinit(v22);
  osif_request_manager_deinit();
  _qdf_nbuf_deinit_replenish_timer();
  if ( cds_is_fw_down(v33, v34, v35, v36, v37, v38, v39, v40) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Not setting the complete event as fw is down",
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      "hdd_wlan_startup");
  }
  else
  {
    wlan_start_ret_val = v21;
    complete_all(&wlan_start_comp, v41);
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v50, v51, v52, v53, v54, v55, v56, v57, "hdd_wlan_startup");
  result = v21;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
