__int64 __fastcall hdd_driver_load(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w0
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x3
  __int64 v11; // x0
  unsigned int v12; // w0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w19
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x0
  __int64 v41; // x0
  unsigned int v42; // w20
  __int64 v43; // x1
  __int64 v44; // x2
  __int64 v45; // x3
  __int64 result; // x0
  void *v47; // x0
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w19
  unsigned int v58; // w19
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
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w0
  __int64 v78; // x0
  __int64 v79; // x1
  __int64 v80; // x0
  __int64 v81; // x1
  __int64 v82; // x2
  __int64 v83; // x3
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x0
  __int64 v93; // x0
  unsigned int pidx; // w20
  __int64 v95; // x1
  __int64 v96; // x2
  __int64 v97; // x3
  unsigned int v98; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int v107; // w19
  __int64 v108; // x0
  unsigned int v109; // w0
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  unsigned int v118; // w19
  unsigned int v119; // w0
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  unsigned int v128; // w0
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x0
  unsigned int v138; // w0
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  unsigned int v147; // w0
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  const char *v156; // x2
  unsigned int v157; // w0
  __int64 v158; // x0
  __int64 v159; // x1
  __int64 v160; // x0
  __int64 v161; // [xsp+0h] [xbp-10h] BYREF
  __int64 v162; // [xsp+8h] [xbp-8h]

  v162 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v161 = 0;
  printk(&unk_9E6D76, aQcaCld3PeachV2, g_wlan_driver_version, a4);
  v4 = qdf_print_setup();
  if ( v4 )
  {
    v21 = v4;
    printk(&unk_9DA8F9, v4, v5, v6);
    goto LABEL_11;
  }
  v7 = qdf_print_ctrl_register((__int64)&cinfo, 0, 0, "MCL_WLAN");
  if ( (v7 & 0x80000000) != 0 )
  {
    printk(&unk_9DA91E, v8, v9, v10);
    v21 = 16;
    goto LABEL_11;
  }
  v11 = qdf_set_pidx(v7);
  v12 = qdf_debugfs_init(v11);
  if ( !v12 )
  {
    qdf_mem_init();
    qdf_event_list_init();
    v22 = qdf_cpuhp_init();
    if ( v22 )
    {
      v21 = v22;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to init cpuhp; status:%u",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "hdd_qdf_init",
        v22);
LABEL_9:
      qdf_event_list_destroy();
      v41 = qdf_mem_exit();
      qdf_debugfs_exit(v41);
      goto LABEL_10;
    }
    v31 = qdf_trace_spin_lock_init();
    if ( v31 )
    {
      v21 = v31;
      v40 = qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to init spinlock; status:%u",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "hdd_qdf_init",
              v31);
      qdf_cpuhp_deinit(v40);
      goto LABEL_9;
    }
    qdf_trace_init();
    _qdf_minidump_init();
    qdf_ssr_driver_dump_init();
    v47 = qdf_register_debugcb_init();
    osif_sync_init(v47);
    v48 = _osif_driver_sync_create_and_trans(&v161, "hdd_driver_load");
    if ( v48 )
    {
      v57 = v48;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to init driver sync; status:%u",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "hdd_driver_load",
        v48);
      v58 = qdf_status_to_os_return(v57);
LABEL_33:
      v92 = osif_sync_deinit();
      qdf_ssr_driver_dump_deinit(v92);
      _qdf_minidump_deinit();
      qdf_trace_deinit();
      ((void (*)(void))qdf_cpuhp_deinit)();
      qdf_event_list_destroy();
      v93 = qdf_mem_exit();
      qdf_debugfs_exit(v93);
      pidx = qdf_get_pidx();
      qdf_set_pidx(0xFFFFFFFFLL);
      qdf_print_ctrl_cleanup(pidx, v95, v96, v97);
      result = v58;
      goto LABEL_12;
    }
    v59 = hdd_init();
    if ( v59 )
    {
      v58 = v59;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to init HDD; errno:%d",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "hdd_driver_load");
LABEL_31:
      if ( v161 )
      {
        osif_driver_sync_trans_stop(v161);
        osif_driver_sync_destroy(v161);
      }
      goto LABEL_33;
    }
    v68 = hdd_cm_register_cb();
    if ( v68 )
      goto LABEL_27;
    osif_vdev_mgr_set_legacy_cb((__int64)osif_vdev_mgrlegacy_ops);
    v68 = osif_vdev_mgr_register_cb();
    if ( v68 )
    {
LABEL_26:
      hdd_cm_unregister_cb();
LABEL_27:
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to init component cb; status:%u",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "hdd_driver_load",
        v68,
        v161,
        v162);
      v78 = qdf_status_to_os_return(v68);
      v58 = v78;
LABEL_28:
      v80 = wlan_logging_sock_deinit_svc(v78, v79);
      if ( !cds_get_global_context(v80, v81, v82, v83) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: cds context is NULL",
          v84,
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          "wlan_destroy_bug_report_lock");
      qdf_op_callbacks_register(nullptr, nullptr);
      cds_deinit();
      goto LABEL_31;
    }
    v68 = osif_twt_register_cb();
    if ( v68 || (v68 = hdd_pre_cac_register_cb()) != 0 )
    {
LABEL_25:
      osif_vdev_mgr_reset_legacy_cb();
      goto LABEL_26;
    }
    v77 = osif_ll_sap_register_cb();
    if ( v77 )
    {
      v68 = v77;
      hdd_pre_cac_unregister_cb();
      goto LABEL_25;
    }
    v98 = hdd_component_init();
    if ( v98 )
    {
      v107 = v98;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to init components; status:%u",
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        "hdd_driver_load",
        v98);
      v108 = qdf_status_to_os_return(v107);
      v58 = v108;
      v78 = hdd_component_cb_deinit(v108);
      goto LABEL_28;
    }
    v109 = _qdf_wake_lock_create(wlan_wake_lock, (__int64)"wlan");
    if ( v109 )
    {
      v118 = v109;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to create wake lock; status:%u",
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        "hdd_driver_load",
        v109);
      v58 = qdf_status_to_os_return(v118);
LABEL_56:
      v160 = hdd_component_deinit();
      v78 = hdd_component_cb_deinit(v160);
      goto LABEL_28;
    }
    curr_con_mode = con_mode;
    v119 = pld_init();
    if ( v119 )
    {
      v58 = v119;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to init PLD; errno:%d",
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        v127,
        "hdd_driver_load",
        v119);
LABEL_55:
      _qdf_wake_lock_destroy((__int64)wlan_wake_lock);
      goto LABEL_56;
    }
    v128 = pld_set_mode((unsigned int)con_mode);
    if ( v128 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to set mode in PLD; errno:%d",
        v129,
        v130,
        v131,
        v132,
        v133,
        v134,
        v135,
        v136,
        "hdd_driver_load",
        v128);
    hdd_set_con_mode_cb[0] = hdd_driver_mode_change;
    osif_driver_sync_register(v161);
    v137 = osif_driver_sync_trans_stop(v161);
    v138 = hdd_register_driver_retry(v137);
    if ( v138 )
    {
      v58 = v138;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to register driver; errno:%d",
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        "hdd_driver_load",
        v138);
LABEL_51:
      v158 = _osif_driver_sync_trans_start(&v161, "hdd_driver_load");
      osif_driver_sync_unregister(v158);
      if ( v161 )
        osif_driver_sync_wait_for_ops();
      hdd_set_con_mode_cb[0] = hdd_set_con_mode;
      pld_deinit();
      wlan_start_ret_val = v58;
      complete_all(&wlan_start_comp, v159);
      while ( wlan_hdd_state_fops_ref )
        ;
      goto LABEL_55;
    }
    if ( (g_soft_unload & 1) != 0 )
    {
LABEL_45:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: %s: driver loaded",
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        "hdd_driver_load",
        aQcaCld3PeachV2,
        v161,
        v162);
      result = 0;
      goto LABEL_12;
    }
    v147 = wlan_hdd_state_ctrl_param_create();
    if ( v147 )
    {
      v58 = v147;
      v156 = "%s: Failed to create ctrl param; errno:%d";
    }
    else
    {
      v157 = wlan_hdd_tx_power_boost_dev_create();
      if ( !v157 )
      {
        hdd_create_wifi_root_obj_sysfs_files();
        goto LABEL_45;
      }
      v58 = v157;
      v156 = "%s: Failed to create dev txpb; errno:%d";
    }
    qdf_trace_msg(0x33u, 2u, v156, v148, v149, v150, v151, v152, v153, v154, v155, "hdd_driver_load", v58, v161, v162);
    wlan_hdd_unregister_driver();
    goto LABEL_51;
  }
  v21 = v12;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: Failed to init debugfs; status:%u",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "hdd_qdf_init",
    v12);
LABEL_10:
  v42 = qdf_get_pidx();
  qdf_set_pidx(0xFFFFFFFFLL);
  qdf_print_ctrl_cleanup(v42, v43, v44, v45);
LABEL_11:
  result = qdf_status_to_os_return(v21);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
