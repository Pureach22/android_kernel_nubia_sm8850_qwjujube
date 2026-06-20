__int64 __fastcall wmi_cfr_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[530] = send_peer_cfr_capture_cmd_tlv;
  v1[529] = extract_cfr_peer_tx_event_param_tlv;
  v1[571] = extract_cfr_phase_param_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 4248LL) = send_cfr_rcc_cmd_tlv;
  return result;
}
