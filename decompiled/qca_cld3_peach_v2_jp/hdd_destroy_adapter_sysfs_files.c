__int64 __fastcall hdd_destroy_adapter_sysfs_files(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  __int64 v3; // x19
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19

  v1 = *(_DWORD *)(result + 40);
  if ( v1 <= 3 )
  {
    if ( v1 > 1 )
    {
      if ( v1 != 2 )
        goto LABEL_11;
    }
    else if ( v1 )
    {
      if ( v1 != 1 )
        return result;
LABEL_11:
      v3 = result;
      hdd_sysfs_sap_bitrates_destroy();
      v4 = hdd_sysfs_dfsnol_destroy(v3);
      hdd_sysfs_direct_link_ut_destroy(v3, v4, v5, v6, v7, v8, v9, v10, v11);
      hdd_sysfs_dp_traffic_end_indication_destroy(v3);
      hdd_sysfs_dp_tx_delay_stats_destroy(v3);
      hdd_sysfs_11be_rate_destroy(v3);
      hdd_sysfs_dl_modes_destroy(v3);
      hdd_sysfs_ipa_destroy(v3);
      hdd_sysfs_range_ext_destroy(v3);
      hdd_sysfs_temperature_destroy(v3);
      hdd_sysfs_txrx_stats_destroy(v3);
      hdd_sysfs_txrx_fw_stats_destroy(v3);
      hdd_sysfs_he_bss_color_destroy(v3);
      hdd_sysfs_stats_destroy(v3);
      hdd_sysfs_rts_cts_destroy(v3);
      hdd_sysfs_radar_destroy(v3);
      hdd_sysfs_dcm_destroy(v3);
      hdd_sysfs_gtx_bw_mask_destroy(v3);
      hdd_sysfs_txrx_fw_st_rst_destroy(v3);
      hdd_sysfs_tx_stbc_destroy(v3);
      hdd_sysfs_connect_info_interface_destroy(v3);
      hdd_sysfs_modify_acl_destroy(v3);
      hdd_sysfs_unit_test_target_destroy(v3);
      hdd_sysfs_crash_inject_destroy(v3);
      hdd_sysfs_sta_info_interface_destroy(v3);
      return hdd_sysfs_channel_interface_destroy(v3);
    }
LABEL_14:
    v12 = result;
    hdd_sysfs_ipa_destroy(result);
    v13 = hdd_sysfs_sta_bitrates_destroy(v12);
    hdd_sysfs_direct_link_ut_destroy(v12, v13, v14, v15, v16, v17, v18, v19, v20);
    hdd_sysfs_dp_tx_delay_stats_destroy(v12);
    hdd_sysfs_bmiss_destroy(v12);
    hdd_sysfs_11be_rate_destroy(v12);
    hdd_sysfs_dl_modes_destroy(v12);
    hdd_sysfs_range_ext_destroy(v12);
    hdd_sysfs_temperature_destroy(v12);
    hdd_sysfs_tdls_peers_interface_destroy(v12);
    hdd_sysfs_txrx_stats_destroy(v12);
    hdd_sysfs_txrx_fw_stats_destroy(v12);
    hdd_sysfs_stats_destroy(v12);
    hdd_sysfs_rts_cts_destroy(v12);
    hdd_sysfs_gtx_bw_mask_destroy(v12);
    hdd_sysfs_txrx_fw_st_rst_destroy(v12);
    hdd_sysfs_tx_stbc_destroy(v12);
    hdd_sysfs_wowl_del_ptrn_destroy(v12);
    hdd_sysfs_wowl_add_ptrn_destroy(v12);
    hdd_sysfs_dcm_destroy(v12);
    hdd_sysfs_connect_info_interface_destroy(v12);
    hdd_sysfs_unit_test_target_destroy(v12);
    hdd_sysfs_crash_inject_destroy(v12);
    hdd_sysfs_reassoc_destroy(v12);
    return device_remove_file(*(_QWORD *)(v12 + 32) + 1376LL, &dev_attr_beacon_stats);
  }
  if ( v1 > 6 )
  {
    if ( v1 != 11 )
    {
      if ( v1 != 7 )
        return result;
      goto LABEL_14;
    }
    v21 = result;
    hdd_sysfs_dp_tx_delay_stats_destroy(result);
    hdd_sysfs_11be_rate_destroy(v21);
    result = v21;
    return hdd_sysfs_unit_test_target_destroy(result);
  }
  if ( v1 == 4 )
    return hdd_sysfs_unit_test_target_destroy(result);
  if ( v1 == 6 )
  {
    v2 = result;
    hdd_sysfs_unit_test_target_destroy(result);
    hdd_sysfs_monitor_mode_channel_destroy(v2);
    return hdd_sysfs_txrx_stats_destroy(v2);
  }
  return result;
}
