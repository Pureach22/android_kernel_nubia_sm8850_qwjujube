__int64 __fastcall hdd_create_sysfs_files(__int64 a1)
{
  __int64 wifi_kobj; // x20
  __int64 v3; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x24
  const char *v21; // x2
  __int64 result; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w3
  const char *v41; // x2
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
  const char *v66; // x2
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
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  const char *v91; // x2
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  const char *v108; // x2
  __int64 v109; // x0
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  __int64 v118; // [xsp+8h] [xbp-18h] BYREF
  __int16 v119; // [xsp+10h] [xbp-10h]
  __int64 v120; // [xsp+18h] [xbp-8h]

  v120 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  wifi_kobj = pld_get_wifi_kobj();
  v3 = kobject_create_and_add("peach_v2", kernel_kobj);
  driver_kobject = v3;
  if ( v3 )
  {
    wlan_kobject = kobject_create_and_add("wlan", v3);
    if ( !wlan_kobject )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: could not allocate wlan kobject",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "hdd_sysfs_create_driver_root_obj");
      kobject_put(driver_kobject);
      driver_kobject = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not allocate driver kobject",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "hdd_sysfs_create_driver_root_obj");
  }
  v20 = *(_QWORD *)a1;
  v119 = 0;
  v118 = 0;
  if ( !driver_kobject || !wlan_kobject )
  {
    v21 = "%s: could not get driver kobject!";
    goto LABEL_10;
  }
  if ( (unsigned int)sysfs_create_file_ns(wlan_kobject, &dr_ver_attribute, 0) )
  {
    v21 = "%s: could not create wlan sysfs file";
LABEL_10:
    qdf_trace_msg(0x33u, 2u, v21, v12, v13, v14, v15, v16, v17, v18, v19, "hdd_sysfs_create_version_interface");
    goto LABEL_11;
  }
  fw_kobject = kobject_create_and_add("fw", wlan_kobject);
  if ( !fw_kobject )
  {
    v108 = "%s: could not allocate fw kobject";
LABEL_48:
    qdf_trace_msg(0x33u, 2u, v108, v32, v33, v34, v35, v36, v37, v38, v39, "hdd_sysfs_create_version_interface");
    goto LABEL_49;
  }
  if ( v20 )
    v40 = *(_DWORD *)(v20 + 8);
  else
    v40 = -1;
  scnprintf(&v118, 10, "%d", v40);
  v109 = kobject_create_and_add(&v118, fw_kobject);
  psoc_kobject = v109;
  if ( !v109 )
  {
    v108 = "%s: could not allocate psoc kobject";
    goto LABEL_48;
  }
  if ( !(unsigned int)sysfs_create_file_ns(v109, &fw_ver_attribute, 0) )
    goto LABEL_11;
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: could not create fw sysfs file",
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    v116,
    v117,
    "hdd_sysfs_create_version_interface");
  kobject_put(psoc_kobject);
  psoc_kobject = 0;
LABEL_49:
  kobject_put(fw_kobject);
  fw_kobject = 0;
LABEL_11:
  hdd_sysfs_mem_stats_create(wlan_kobject);
  result = hdd_get_conparam();
  if ( !(_DWORD)result )
  {
    if ( driver_kobject )
    {
      if ( !(unsigned int)sysfs_create_file_ns(driver_kobject, &power_stats_attribute, 0) )
        goto LABEL_20;
      v31 = "%s: could not create power_stats sysfs file";
    }
    else
    {
      v31 = "%s: could not get driver kobject!";
    }
    qdf_trace_msg(0x33u, 2u, v31, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_sysfs_create_powerstats_interface");
LABEL_20:
    if ( wifi_kobject )
    {
      if ( (*(_BYTE *)(a1 + 7091) & 1) != 0 )
      {
        if ( !(unsigned int)sysfs_create_file_ns(wifi_kobject, &max_chipset_log_size_attribute, 0) )
        {
          *(_WORD *)(a1 + 7092) = 50;
          if ( wifi_kobj )
          {
LABEL_28:
            v42 = hdd_sysfs_fw_mode_config_create(driver_kobject);
            hdd_sysfs_scan_disable_create(driver_kobject, v42, v43, v44, v45, v46, v47, v48, v49);
            hdd_sysfs_wow_ito_create(driver_kobject);
            hdd_sysfs_wlan_dbg_create(driver_kobject);
            hdd_sysfs_scan_config_create(driver_kobject);
            hdd_sysfs_dp_trace_create(driver_kobject);
            hdd_sysfs_thermal_cfg_create(driver_kobject);
            hdd_sysfs_pm_cinfo_create(driver_kobject);
            hdd_sysfs_pm_pcl_create(driver_kobject);
            hdd_sysfs_dp_aggregation_create(driver_kobject);
            v50 = hdd_sysfs_dp_stc_create(driver_kobject);
            hdd_sysfs_dp_swlm_create(driver_kobject, v50, v51, v52, v53, v54, v55, v56, v57);
            if ( driver_kobject )
            {
              if ( !(unsigned int)sysfs_create_file_ns(driver_kobject, &wakeup_logs_to_console_attribute, 0) )
                goto LABEL_33;
              v66 = "%s: could not create power_stats sysfs file";
            }
            else
            {
              v66 = "%s: could not get driver kobject!";
            }
            qdf_trace_msg(
              0x33u,
              2u,
              v66,
              v58,
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              "hdd_sysfs_create_wakeup_logs_to_console");
LABEL_33:
            hdd_sysfs_dp_txrx_stats_sysfs_create(driver_kobject);
            hdd_sysfs_get_valid_freq_for_power_create(driver_kobject);
            hdd_sysfs_dp_pkt_add_ts_create(driver_kobject, v67, v68, v69, v70, v71, v72, v73, v74);
            hdd_sysfs_runtime_pm_create(driver_kobject, v75, v76, v77, v78, v79, v80, v81, v82);
            hdd_sysfs_log_buffer_create(driver_kobject);
            hdd_sysfs_rf_test_mode_create(driver_kobject);
            if ( driver_kobject )
            {
              if ( !(unsigned int)sysfs_create_file_ns(driver_kobject, &logging_config_attribute, 0) )
              {
LABEL_38:
                hdd_sysfs_ipa_opt_dp_ctrl_create(driver_kobject, v83, v84, v85, v86, v87, v88, v89, v90);
                hdd_sysfs_ipa_opt_dp_ctrl_rm_create(driver_kobject, v92, v93, v94, v95, v96, v97, v98, v99);
                result = hdd_sysfs_apfmode_create(driver_kobject, v100, v101, v102, v103, v104, v105, v106, v107);
                goto LABEL_39;
              }
              v91 = "%s: could not create logging config sysfs file";
            }
            else
            {
              v91 = "%s: could not get wifi kobject!";
            }
            qdf_trace_msg(
              0x33u,
              2u,
              v91,
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              "hdd_sysfs_create_logging_config_interface");
            goto LABEL_38;
          }
LABEL_27:
          hdd_sysfs_create_dump_in_progress_interface(wifi_kobject, a1, v23, v24, v25, v26, v27, v28, v29, v30);
          goto LABEL_28;
        }
        v41 = "%s: could not create max_chipset_log_size sysfs file";
      }
      else
      {
        v41 = "%s: max_chipset_log_size feature is disabled/no supp";
      }
    }
    else
    {
      v41 = "%s: could not get wifi kobject!";
    }
    qdf_trace_msg(
      0x33u,
      2u,
      v41,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "hdd_sysfs_create_max_chipset_log_size_interface");
    if ( wifi_kobj )
      goto LABEL_28;
    goto LABEL_27;
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
