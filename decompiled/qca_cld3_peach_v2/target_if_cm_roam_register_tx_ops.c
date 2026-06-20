__int64 __fastcall target_if_cm_roam_register_tx_ops(
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
    a1[10] = target_if_cm_roam_send_roam_sync_complete;
    a1[11] = target_if_cm_roam_rt_stats_config;
    a1[12] = target_if_cm_roam_ho_delay_config;
    a1[13] = target_if_cm_exclude_rm_partial_scan_freq;
    a1[14] = target_if_cm_roam_full_scan_6ghz_on_disc;
    a1[15] = target_if_cm_roam_mcc_disallow;
    a1[16] = target_if_cm_roam_scan_offload_rssi_params;
    a1[17] = target_if_cm_roam_linkspeed_state;
    *a1 = target_if_cm_roam_send_vdev_set_pcl_cmd;
    a1[1] = target_if_cm_roam_send_roam_init;
    a1[2] = target_if_cm_roam_send_start;
    a1[3] = target_if_cm_roam_send_stop;
    a1[4] = target_if_cm_roam_send_update_config;
    a1[5] = target_if_cm_roam_abort;
    a1[6] = target_if_cm_roam_per_config;
    a1[7] = target_if_cm_roam_triggers;
    a1[8] = target_if_cm_roam_send_disable_config;
    a1[9] = target_if_cm_roam_send_roam_invoke_cmd;
    a1[20] = target_if_cm_roam_idle_params;
    a1[21] = target_if_cm_roam_update_freqs;
    a1[18] = target_if_cm_roam_vendor_handoff_config;
    a1[19] = target_if_cm_roam_send_mlo_config;
    a1[22] = target_if_cm_roam_disconnect_params;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: target if tx ops is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_cm_roam_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
