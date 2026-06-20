__int64 __fastcall hdd_driver_unload(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v4; // w19
  void *v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 driver_state; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 *context; // x0
  __int64 *v48; // x20
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 result; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x1
  __int64 v82; // x0
  __int64 v83; // x1
  __int64 v84; // x2
  __int64 v85; // x3
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  unsigned int pidx; // w19
  __int64 v98; // x1
  __int64 v99; // x2
  __int64 v100; // x3
  __int64 v101; // x1
  __int64 v102; // x1
  __int64 v103; // x2
  __int64 v104; // x3
  __int64 v105; // [xsp+0h] [xbp-10h] BYREF
  __int64 v106; // [xsp+8h] [xbp-8h]

  v106 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = g_soft_unload;
  v105 = 0;
  if ( g_soft_unload )
    v5 = &unk_A634F2;
  else
    v5 = &unk_9CDCEC;
  printk(v5, aQcaCld3PeachV2, "5.2.1.137C", a4);
  if ( (cds_get_driver_state(v6, v7, v8, v9, v10, v11, v12, v13) & 0x200) == 0 )
  {
    LODWORD(driver_state) = _osif_driver_sync_trans_start_wait(&v105, "hdd_driver_unload");
    if ( (_DWORD)driver_state )
      goto LABEL_15;
  }
  if ( _cds_get_context(61, (__int64)"hdd_driver_unload", v14, v15, v16, v17, v18, v19, v20, v21) )
    qdf_rtpm_sync_resume();
  cds_clear_driver_state(1, v23, v24, v25, v26, v27, v28, v29, v30);
  cds_set_driver_state(4, v31, v32, v33, v34, v35, v36, v37, v38);
  context = _cds_get_context(51, (__int64)"hdd_driver_unload", v39, v40, v41, v42, v43, v44, v45, v46);
  if ( context )
  {
    v48 = context;
    _qdf_delayed_work_stop_sync();
    qdf_wake_lock_release((__int64)wlan_wake_lock, 0x15u);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Stopped psoc idle timer",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "hdd_psoc_idle_timer_stop");
    ucfg_dp_bus_bw_compute_timer_stop(*v48, v57, v58, v59, v60, v61, v62, v63, v64);
  }
  if ( v105 )
    osif_driver_sync_trans_stop(v105);
  v65 = hdd_destroy_apfmode_interface_sysfs_file();
  v66 = hdd_destroy_rtpm_interface_sysfs_file(v65);
  v67 = hdd_destroy_wifi_feature_interface_sysfs_file(v66);
  v68 = hdd_sysfs_destroy_wifi_root_obj(v67);
  if ( (v4 & 1) == 0 )
  {
    wlan_hdd_tx_power_boost_dev_destroy(v68);
    cdev_del(&wlan_hdd_state_cdev);
    device_destroy(class, (unsigned int)device);
    class_destroy(class);
    if ( dev_num )
      v101 = 2;
    else
      v101 = 0;
    unregister_chrdev_region((unsigned int)device, v101);
    printk(&unk_A196AA, v102, v103, v104);
  }
  wlan_hdd_unregister_driver();
  driver_state = cds_get_driver_state(v69, v70, v71, v72, v73, v74, v75, v76);
  if ( (driver_state & 0x200) != 0
    || (driver_state = _osif_driver_sync_trans_start_wait(&v105, "hdd_driver_unload"), !(_DWORD)driver_state) )
  {
    osif_driver_sync_unregister(driver_state);
    if ( v105 )
      osif_driver_sync_wait_for_ops();
    hdd_set_con_mode_cb[0] = hdd_set_con_mode;
    pld_deinit();
    curr_con_mode = 0;
    _qdf_wake_lock_destroy((__int64)wlan_wake_lock);
    v78 = hdd_component_deinit();
    v79 = osif_ll_sap_unregister_cb(v78);
    hdd_pre_cac_unregister_cb(v79);
    osif_vdev_mgr_reset_legacy_cb();
    hdd_cm_unregister_cb();
    v82 = wlan_logging_sock_deinit_svc(v80, v81);
    if ( !cds_get_global_context(v82, v83, v84, v85) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: cds context is NULL",
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        "wlan_destroy_bug_report_lock");
    qdf_op_callbacks_register(nullptr, nullptr);
    cds_deinit();
    if ( v105 )
    {
      osif_driver_sync_trans_stop(v105);
      osif_driver_sync_destroy(v105);
    }
    v94 = osif_sync_deinit();
    qdf_ssr_driver_dump_deinit(v94);
    _qdf_minidump_deinit();
    qdf_trace_deinit();
    qdf_cpuhp_deinit(v95);
    qdf_event_list_destroy();
    v96 = qdf_mem_exit();
    qdf_debugfs_exit(v96);
    pidx = qdf_get_pidx();
    qdf_set_pidx(0xFFFFFFFFLL);
    qdf_print_ctrl_cleanup(pidx, v98, v99, v100);
    result = qdf_mem_check_prealloc_leaks();
  }
  else
  {
LABEL_15:
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: Unable to unload wlan; status:%u",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "hdd_driver_unload",
               (unsigned int)driver_state,
               v105,
               v106);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
