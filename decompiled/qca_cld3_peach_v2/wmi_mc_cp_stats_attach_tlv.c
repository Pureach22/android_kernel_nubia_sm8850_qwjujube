__int64 __fastcall wmi_mc_cp_stats_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[381] = extract_per_chain_rssi_stats_tlv;
  v1[386] = extract_peer_adv_stats_tlv;
  v1[389] = extract_mib_stats_tlv;
  v1[55] = send_request_peer_stats_info_cmd_tlv;
  v1[399] = extract_peer_stats_count_tlv;
  v1[400] = extract_peer_stats_info_tlv;
  v1[388] = extract_recv_bcn_stats_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3208LL) = extract_peer_tx_pkt_per_mcs_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 3216LL) = extract_peer_rx_pkt_per_mcs_tlv;
  v1[375] = extract_big_data_stats_tlv;
  return result;
}
