__int64 (__fastcall **__fastcall target_if_pmo_register_tx_ops(
        __int64 (__fastcall **result)(__int64 a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9),
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9))(__int64 a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8, double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30

  if ( !result )
    return (__int64 (__fastcall **)(__int64, double, double, double, double, double, double, double, double))qdf_trace_msg(0x49u, 2u, "%s: pmo_tx_ops is null", a2, a3, a4, a5, a6, a7, a8, a9, "target_if_pmo_register_tx_ops", v9, v10);
  *result = target_if_pmo_send_arp_offload_req;
  result[1] = target_if_pmo_conf_hw_filter;
  result[6] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_disable_wow_wakeup_event;
  result[7] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_wow_patterns_to_fw;
  result[8] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_del_wow_patterns_to_fw;
  result[9] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_enhance_mc_offload_req;
  result[10] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_set_mc_filter_req;
  result[11] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_clear_mc_filter_req;
  result[12] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_get_multiple_mc_filter_support;
  result[13] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_set_multiple_mc_filter_req;
  result[14] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_clear_multiple_mc_filter_req;
  result[15] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_ra_filter_req;
  result[16] = target_if_pmo_send_gtk_offload_req;
  result[17] = target_if_pmo_send_gtk_response_req;
  result[18] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_action_frame_patterns;
  result[19] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_lphb_enable;
  result[20] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_lphb_tcp_params;
  result[21] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_lphb_tcp_pkt_filter;
  result[22] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_lphb_udp_params;
  result[23] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_lphb_udp_pkt_filter;
  result[24] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_vdev_update_param_req;
  result[25] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_vdev_ps_param_req;
  result[26] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_igmp_offload_req;
  result[27] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_update_bus_suspend;
  result[28] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_get_host_credits;
  result[29] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_get_pending_cmnds;
  result[30] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_update_target_suspend_flag;
  result[31] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_update_target_suspend_acked_flag;
  result[32] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_is_target_suspended;
  result[33] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_send_wow_enable_req;
  result[34] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_send_suspend_req;
  result[35] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_set_runtime_pm_in_progress;
  result[36] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_get_runtime_pm_in_progress;
  result[37] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_send_host_wakeup_ind;
  result[38] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_send_target_resume_req;
  result[39] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_send_d0wow_enable_req;
  result[40] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_send_d0wow_disable_req;
  result[41] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_psoc_send_idle_monitor_cmd;
  result[2] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_ns_offload_req;
  result[3] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_pkt_filter_req;
  result[4] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_clear_pkt_filter_req;
  result[5] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_enable_wow_wakeup_event;
  result[42] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_send_icmp_offload_req;
  result[43] = (__int64 (__fastcall *)(__int64, double, double, double, double, double, double, double, double))target_if_pmo_set_wow_enable_ack_failed;
  result[44] = target_if_pmo_send_apf_mode_req;
  return result;
}
