__int64 __fastcall wmi_pmo_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x8
  __int64 v3; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[144] = send_add_wow_wakeup_event_cmd_tlv;
  v1[145] = send_wow_patterns_to_fw_cmd_tlv;
  v1[146] = &send_enable_arp_ns_offload_cmd_tlv;
  v1[149] = send_add_clear_mcbc_filter_cmd_tlv;
  v1[150] = send_multiple_add_clear_mcbc_filter_cmd_tlv;
  v1[147] = send_conf_hw_filter_cmd_tlv;
  v1[151] = send_gtk_offload_cmd_tlv;
  v1[152] = &send_igmp_offload_cmd_tlv;
  v1[153] = send_process_gtk_offload_getinfo_cmd_tlv;
  v1[148] = send_enable_enhance_multicast_offload_tlv;
  v1[156] = extract_gtk_rsp_event_tlv;
  v1[155] = send_action_frame_patterns_cmd_tlv;
  v1[157] = send_wow_delete_pattern_cmd_tlv;
  v1[158] = send_host_wakeup_ind_to_fw_cmd_tlv;
  v1[159] = send_wow_timer_pattern_cmd_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 1232LL) = send_wow_sta_ra_filter_cmd_tlv;
  v2 = *(_QWORD **)(result + 728);
  v2[160] = send_lphb_config_hbenable_cmd_tlv;
  v2[161] = send_lphb_config_tcp_params_cmd_tlv;
  v2[162] = send_lphb_config_tcp_pkt_filter_cmd_tlv;
  v2[163] = send_lphb_config_udp_params_cmd_tlv;
  v2[164] = send_lphb_config_udp_pkt_filter_cmd_tlv;
  v3 = *(_QWORD *)(result + 728);
  *(_QWORD *)(v3 + 1320) = send_enable_disable_packet_filter_cmd_tlv;
  *(_QWORD *)(v3 + 1328) = send_config_packet_filter_cmd_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 1336LL) = &send_icmp_offload_config_cmd_tlv;
  return result;
}
