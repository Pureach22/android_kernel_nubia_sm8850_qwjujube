__int64 hdd_destroy_sysfs_files()
{
  __int64 wifi_kobj; // x19
  double v1; // d0
  double v2; // d1
  double v3; // d2
  double v4; // d3
  double v5; // d4
  double v6; // d5
  double v7; // d6
  double v8; // d7
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
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
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // x19
  _QWORD *context; // x0
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  __int64 v91; // x21
  const char *v92; // x2
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 result; // x0

  wifi_kobj = pld_get_wifi_kobj();
  if ( (unsigned int)hdd_get_conparam() )
    goto LABEL_23;
  hdd_sysfs_ipa_opt_dp_ctrl_rm_destroy(driver_kobject, v1, v2, v3, v4, v5, v6, v7, v8);
  hdd_sysfs_ipa_opt_dp_ctrl_destroy(driver_kobject, v9, v10, v11, v12, v13, v14, v15, v16);
  if ( driver_kobject )
    sysfs_remove_file_ns(driver_kobject, &logging_config_attribute, 0);
  else
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not get wifi kobject!",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "hdd_sysfs_destroy_logging_config_interface");
  hdd_sysfs_rf_test_mode_destroy(driver_kobject);
  v25 = hdd_sysfs_log_buffer_destroy(driver_kobject);
  hdd_sysfs_runtime_pm_destroy(driver_kobject, v25, v26, v27, v28, v29, v30, v31, v32);
  hdd_sysfs_dp_pkt_add_ts_destroy(driver_kobject, v33, v34, v35, v36, v37, v38, v39, v40);
  hdd_sysfs_get_valid_freq_for_power_destroy(driver_kobject, v41, v42, v43, v44, v45, v46, v47, v48);
  hdd_sysfs_dp_txrx_stats_sysfs_destroy(driver_kobject);
  if ( driver_kobject )
    sysfs_remove_file_ns(driver_kobject, &wakeup_logs_to_console_attribute, 0);
  else
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not get driver kobject!",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "hdd_sysfs_destroy_wakeup_logs_to_console");
  hdd_sysfs_dp_swlm_destroy(driver_kobject, v57, v58, v59, v60, v61, v62, v63, v64);
  hdd_sysfs_dp_aggregation_destroy(driver_kobject);
  hdd_sysfs_dp_stc_destroy(driver_kobject);
  hdd_sysfs_pm_pcl_destroy(driver_kobject);
  hdd_sysfs_pm_cinfo_destroy(driver_kobject);
  hdd_sysfs_thermal_cfg_destroy(driver_kobject);
  hdd_sysfs_dp_trace_destroy(driver_kobject);
  hdd_sysfs_scan_config_destroy(driver_kobject);
  hdd_sysfs_wlan_dbg_destroy(driver_kobject);
  v65 = hdd_sysfs_wow_ito_destroy(driver_kobject);
  hdd_sysfs_scan_disable_destroy(driver_kobject, v65, v66, v67, v68, v69, v70, v71, v72);
  hdd_sysfs_fw_mode_config_destroy(driver_kobject);
  if ( !wifi_kobj )
    hdd_sysfs_destroy_dump_in_progress_interface(wifi_kobject, v73, v74, v75, v76, v77, v78, v79, v80);
  v81 = wifi_kobject;
  context = _cds_get_context(
              51,
              (__int64)"hdd_sysfs_destroy_max_chipset_log_size_interface",
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              v79,
              v80);
  if ( !context )
  {
    v91 = jiffies;
    if ( hdd_sysfs_destroy_max_chipset_log_size_interface___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: hdd_ctx is NULL",
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        "hdd_sysfs_destroy_max_chipset_log_size_interface");
      hdd_sysfs_destroy_max_chipset_log_size_interface___last_ticks = v91;
    }
    goto LABEL_19;
  }
  if ( !v81 )
  {
    v92 = "%s: could not get wifi kobject!";
LABEL_18:
    qdf_trace_msg(
      0x33u,
      2u,
      v92,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "hdd_sysfs_destroy_max_chipset_log_size_interface");
    goto LABEL_19;
  }
  if ( (*((_BYTE *)context + 7115) & 1) == 0 )
  {
    v92 = "%s: max_chipset_log_size feature is disabled/no supp";
    goto LABEL_18;
  }
  sysfs_remove_file_ns(v81, &max_chipset_log_size_attribute, 0);
LABEL_19:
  if ( driver_kobject )
    sysfs_remove_file_ns(driver_kobject, &power_stats_attribute, 0);
  else
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not get driver kobject!",
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      v90,
      "hdd_sysfs_destroy_powerstats_interface");
  hdd_sysfs_apfmode_destroy(driver_kobject, v93, v94, v95, v96, v97, v98, v99, v100);
LABEL_23:
  hdd_sysfs_mem_stats_destroy(wlan_kobject);
  if ( psoc_kobject )
  {
    kobject_put(psoc_kobject);
    psoc_kobject = 0;
    kobject_put(fw_kobject);
    fw_kobject = 0;
  }
  if ( wlan_kobject )
  {
    kobject_put(wlan_kobject);
    wlan_kobject = 0;
  }
  result = driver_kobject;
  if ( driver_kobject )
  {
    result = kobject_put(driver_kobject);
    driver_kobject = 0;
  }
  return result;
}
