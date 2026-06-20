__int64 __fastcall wmi_mc_cp_stats_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[379] = extract_per_chain_rssi_stats_tlv;
  v1[384] = extract_peer_adv_stats_tlv;
  v1[387] = extract_mib_stats_tlv;
  v1[54] = send_request_peer_stats_info_cmd_tlv;
  v1[397] = extract_peer_stats_count_tlv;
  v1[398] = extract_peer_stats_info_tlv;
  v1[386] = extract_recv_bcn_stats_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3192LL) = extract_peer_tx_pkt_per_mcs_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3200LL) = extract_peer_rx_pkt_per_mcs_tlv;
  v1[373] = extract_big_data_stats_tlv;
  return result;
}
