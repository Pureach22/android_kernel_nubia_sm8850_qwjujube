__int64 __fastcall wmi_nan_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[183] = send_nan_req_cmd_tlv;
  v1[184] = send_nan_disable_req_cmd_tlv;
  v1[185] = extract_nan_event_rsp_tlv;
  v1[475] = send_terminate_all_ndps_cmd_tlv;
  v1[472] = nan_ndp_initiator_req_tlv;
  v1[473] = nan_ndp_responder_req_tlv;
  v1[474] = &nan_ndp_end_req_tlv;
  v1[476] = nan_ndp_update_config_tlv;
  v1[477] = extract_ndp_initiator_rsp_tlv;
  v1[478] = extract_ndp_ind_tlv;
  v1[479] = extract_nan_msg_tlv;
  v1[480] = &extract_ndp_confirm_tlv;
  v1[481] = extract_ndp_responder_rsp_tlv;
  v1[482] = extract_ndp_end_rsp_tlv;
  v1[483] = extract_ndp_end_ind_tlv;
  v1[484] = extract_ndp_sch_update_tlv;
  v1[485] = extract_ndp_host_event_tlv;
  return result;
}
