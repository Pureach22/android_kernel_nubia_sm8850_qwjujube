__int64 __fastcall hdd_create_adapter_sysfs_files(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7

  v1 = *(_DWORD *)(result + 40);
  v2 = result;
  if ( v1 <= 3 )
  {
    if ( v1 > 1 )
    {
      if ( v1 != 2 )
        goto LABEL_12;
    }
    else if ( v1 )
    {
      if ( v1 != 1 )
        return result;
LABEL_12:
      hdd_sysfs_channel_interface_create(result);
      hdd_sysfs_sta_info_interface_create(v2);
      hdd_sysfs_crash_inject_create(v2);
      hdd_sysfs_unit_test_target_create(v2);
      hdd_sysfs_modify_acl_create(v2);
      hdd_sysfs_connect_info_interface_create(v2);
      hdd_sysfs_tx_stbc_create(v2);
      hdd_sysfs_txrx_fw_st_rst_create(v2);
      hdd_sysfs_gtx_bw_mask_create(v2);
      hdd_sysfs_dcm_create(v2);
      hdd_sysfs_radar_create(v2);
      hdd_sysfs_rts_cts_create(v2);
      hdd_sysfs_stats_create(v2);
      hdd_sysfs_he_bss_color_create(v2);
      hdd_sysfs_txrx_fw_stats_create(v2);
      hdd_sysfs_txrx_stats_create(v2);
      hdd_sysfs_temperature_create(v2);
      hdd_sysfs_range_ext_create(v2);
      hdd_sysfs_ipa_create(v2);
      hdd_sysfs_dl_modes_create(v2);
      hdd_sysfs_11be_rate_create(v2);
      hdd_sysfs_dp_tx_delay_stats_create(v2);
      hdd_sysfs_dp_traffic_end_indication_create(v2);
      hdd_sysfs_direct_link_ut_cmd_create(v2, v3, v4, v5, v6, v7, v8, v9, v10);
      hdd_sysfs_dfsnol_create(v2);
      return hdd_sysfs_sap_bitrates_create(v2);
    }
    goto LABEL_15;
  }
  if ( v1 > 6 )
  {
    if ( v1 == 11 )
    {
      hdd_sysfs_unit_test_target_create(result);
      hdd_sysfs_11be_rate_create(v2);
      return hdd_sysfs_dp_tx_delay_stats_create(v2);
    }
    if ( v1 != 7 )
      return result;
LABEL_15:
    if ( (unsigned int)device_create_file(*(_QWORD *)(result + 32) + 1376LL, &dev_attr_beacon_stats) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: could not create beacon stats sysfs file",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "hdd_sysfs_create_bcn_reception_interface");
    hdd_sysfs_reassoc_create(v2);
    hdd_sysfs_crash_inject_create(v2);
    hdd_sysfs_unit_test_target_create(v2);
    hdd_sysfs_connect_info_interface_create(v2);
    hdd_sysfs_dcm_create(v2);
    hdd_sysfs_wowl_add_ptrn_create(v2);
    hdd_sysfs_wowl_del_ptrn_create(v2);
    hdd_sysfs_tx_stbc_create(v2);
    hdd_sysfs_txrx_fw_st_rst_create(v2);
    hdd_sysfs_gtx_bw_mask_create(v2);
    hdd_sysfs_rts_cts_create(v2);
    hdd_sysfs_stats_create(v2);
    hdd_sysfs_txrx_fw_stats_create(v2);
    hdd_sysfs_txrx_stats_create(v2);
    hdd_sysfs_tdls_peers_interface_create(v2);
    hdd_sysfs_temperature_create(v2);
    hdd_sysfs_range_ext_create(v2);
    hdd_sysfs_dl_modes_create(v2);
    hdd_sysfs_11be_rate_create(v2);
    hdd_sysfs_bmiss_create(v2);
    hdd_sysfs_dp_tx_delay_stats_create(v2);
    hdd_sysfs_direct_link_ut_cmd_create(v2, v19, v20, v21, v22, v23, v24, v25, v26);
    hdd_sysfs_sta_bitrates_create(v2);
    return hdd_sysfs_ipa_create(v2);
  }
  if ( v1 != 4 )
  {
    if ( v1 != 6 )
      return result;
    hdd_sysfs_txrx_stats_create(result);
    hdd_sysfs_monitor_mode_channel_create(v2);
  }
  return hdd_sysfs_unit_test_target_create(v2);
}
