__int64 __fastcall wmi_p2p_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[71] = send_set_p2pgo_oppps_req_cmd_tlv;
  v1[72] = send_set_p2pgo_noa_req_cmd_tlv;
  v1[360] = &extract_p2p_noa_ev_param_tlv;
  v1[361] = extract_mac_addr_rx_filter_evt_param_tlv;
  v1[362] = send_p2p_ap_assist_dfs_group_params_cmd_tlv;
  v1[363] = extract_p2p_ap_assist_dfs_group_bmiss_param_tlv;
  v1[73] = send_p2p_usd_req_cmd_tlv;
  v2 = *(_QWORD **)(result + 728);
  v2[74] = send_p2p_lo_start_cmd_tlv;
  v2[75] = send_p2p_lo_stop_cmd_tlv;
  v2[359] = extract_p2p_lo_stop_ev_param_tlv;
  return result;
}
