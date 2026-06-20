__int64 __fastcall wmi_cp_stats_attach_tlv(__int64 a1)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(a1 + 728);
  v1[54] = send_stats_request_cmd_tlv;
  v1[568] = send_big_data_stats_request_cmd_tlv;
  v1[374] = extract_all_stats_counts_tlv;
  v1[376] = extract_pdev_stats_tlv;
  v1[380] = extract_vdev_stats_tlv;
  v1[382] = extract_peer_stats_tlv;
  v1[384] = extract_peer_extd_stats_tlv;
  v1[564] = &send_infra_cp_stats_request_cmd_tlv;
  v1[377] = extract_pmf_bcn_protect_stats_tlv;
  return wmi_mc_cp_stats_attach_tlv();
}
