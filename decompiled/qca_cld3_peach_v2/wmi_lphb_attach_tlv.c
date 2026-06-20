__int64 __fastcall wmi_lphb_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[160] = send_lphb_config_hbenable_cmd_tlv;
  v1[161] = send_lphb_config_tcp_params_cmd_tlv;
  v1[162] = send_lphb_config_tcp_pkt_filter_cmd_tlv;
  v1[163] = send_lphb_config_udp_params_cmd_tlv;
  v1[164] = send_lphb_config_udp_pkt_filter_cmd_tlv;
  return result;
}
