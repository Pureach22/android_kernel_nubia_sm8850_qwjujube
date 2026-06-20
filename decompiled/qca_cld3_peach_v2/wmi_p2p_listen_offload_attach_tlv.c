__int64 __fastcall wmi_p2p_listen_offload_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[74] = send_p2p_lo_start_cmd_tlv;
  v1[75] = send_p2p_lo_stop_cmd_tlv;
  v1[359] = extract_p2p_lo_stop_ev_param_tlv;
  return result;
}
