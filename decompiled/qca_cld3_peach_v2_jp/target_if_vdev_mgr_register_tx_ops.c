__int64 __fastcall target_if_vdev_mgr_register_tx_ops(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( a1 )
  {
    a1[173] = target_if_vdev_mgr_register_event_handler;
    a1[174] = target_if_vdev_mgr_unregister_event_handler;
    a1[175] = target_if_vdev_mgr_create_send;
    a1[176] = target_if_vdev_mgr_start_send;
    a1[177] = target_if_vdev_mgr_up_send;
    a1[178] = target_if_vdev_mgr_delete_send;
    a1[179] = target_if_vdev_mgr_stop_send;
    a1[180] = target_if_vdev_mgr_down_send;
    a1[183] = target_if_vdev_mgr_set_nac_rssi_send;
    a1[184] = target_if_vdev_mgr_set_neighbour_rx_cmd_send;
    a1[185] = target_if_vdev_mgr_sifs_trigger_send;
    a1[186] = target_if_vdev_mgr_set_custom_aggr_size_cmd_send;
    a1[187] = target_if_vdev_mgr_config_ratemask_cmd_send;
    a1[188] = target_if_vdev_mgr_peer_flush_tids_send;
    a1[189] = &target_if_vdev_mgr_multiple_vdev_restart_req_cmd;
    a1[190] = target_if_vdev_mgr_multiple_vdev_set_param_cmd;
    a1[191] = target_if_vdev_mgr_beacon_send;
    a1[192] = target_if_vdev_mgr_beacon_tmpl_send;
    a1[181] = target_if_vdev_mgr_set_param_send;
    a1[182] = target_if_vdev_set_tx_rx_decap_type;
    a1[195] = target_if_vdev_mgr_sta_ps_param_send;
    a1[200] = target_if_vdev_mgr_rsp_timer_mod;
    a1[196] = target_if_vdev_mgr_peer_delete_all_send;
    a1[193] = target_if_vdev_mgr_fils_enable_send;
    a1[197] = target_if_psoc_vdev_rsp_timer_init;
    a1[198] = target_if_psoc_vdev_rsp_timer_deinit;
    a1[199] = target_if_psoc_vdev_rsp_timer_inuse;
    a1[201] = target_if_wake_lock_init;
    a1[202] = target_if_wake_lock_deinit;
    a1[203] = target_if_vdev_mgr_rsp_timer_stop;
    a1[204] = target_if_vdev_mgr_set_mac_address_send;
    a1[205] = &target_if_vdev_peer_set_param_send;
    a1[206] = target_if_sap_suspend_param_send;
    a1[207] = target_if_sap_is_suspend_support_enabled;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Invalid input",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_vdev_mgr_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
