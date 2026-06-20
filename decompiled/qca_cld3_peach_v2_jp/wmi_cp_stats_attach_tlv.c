__int64 __fastcall wmi_cp_stats_attach_tlv(__int64 a1)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(a1 + 728);
  v1[53] = send_stats_request_cmd_tlv;
  v1[566] = send_big_data_stats_request_cmd_tlv;
  v1[372] = extract_all_stats_counts_tlv;
  v1[374] = extract_pdev_stats_tlv;
  v1[378] = extract_vdev_stats_tlv;
  v1[380] = extract_peer_stats_tlv;
  v1[382] = extract_peer_extd_stats_tlv;
  v1[562] = &send_infra_cp_stats_request_cmd_tlv;
  v1[375] = extract_pmf_bcn_protect_stats_tlv;
  return wmi_mc_cp_stats_attach_tlv();
}
