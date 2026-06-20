__int64 __fastcall wmi_tdls_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[212] = send_set_tdls_offchan_mode_cmd_tlv;
  v1[213] = send_update_fw_tdls_state_cmd_tlv;
  v1[214] = send_update_tdls_peer_state_cmd_tlv;
  v1[215] = extract_vdev_tdls_ev_param_tlv;
  return result;
}
