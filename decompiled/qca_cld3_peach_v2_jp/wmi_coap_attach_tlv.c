__int64 __fastcall wmi_coap_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[586] = send_coap_add_pattern_cmd_tlv;
  v1[587] = send_coap_del_pattern_cmd_tlv;
  v1[588] = send_coap_add_keepalive_pattern_cmd_tlv;
  v1[589] = send_coap_del_keepalive_pattern_cmd_tlv;
  v1[590] = send_coap_cache_get_cmd_tlv;
  v1[591] = coap_extract_buf_info_tlv;
  return result;
}
