__int64 __fastcall wmi_twt_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[499] = send_twt_enable_cmd_tlv;
  v1[500] = send_twt_disable_cmd_tlv;
  v1[501] = send_twt_add_dialog_cmd_tlv;
  v1[502] = send_twt_del_dialog_cmd_tlv;
  v1[503] = send_twt_pause_dialog_cmd_tlv;
  v1[504] = send_twt_nudge_dialog_cmd_tlv;
  v1[505] = send_twt_resume_dialog_cmd_tlv;
  v1[506] = extract_twt_enable_comp_event_tlv;
  v1[507] = extract_twt_disable_comp_event_tlv;
  v1[508] = extract_twt_add_dialog_comp_event_tlv;
  v1[509] = extract_twt_add_dialog_comp_additional_parameters;
  v1[510] = extract_twt_del_dialog_comp_event_tlv;
  v1[511] = extract_twt_pause_dialog_comp_event_tlv;
  v1[512] = extract_twt_nudge_dialog_comp_event_tlv;
  v1[513] = extract_twt_resume_dialog_comp_event_tlv;
  v1[516] = extract_twt_session_stats_event_tlv;
  v1[517] = extract_twt_session_stats_event_data;
  v1[514] = extract_twt_notify_event_tlv;
  v1[426] = extract_twt_cap_service_ready_ext2_tlv;
  v1[515] = extract_twt_ack_comp_event_tlv;
  return result;
}
