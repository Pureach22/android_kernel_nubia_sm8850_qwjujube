__int64 __fastcall wmi_mlme_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[630] = csa_event_status_ind_tlv;
  v1[631] = audio_transport_switch_resp_tlv;
  v1[632] = extract_audio_transport_switch_req_event_tlv;
  v1[633] = oob_connect_request_tlv;
  v1[634] = extract_oob_connect_response_event_tlv;
  v1[635] = get_tsf_stats_for_csa_tlv;
  return result;
}
