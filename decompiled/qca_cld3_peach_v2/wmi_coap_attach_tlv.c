__int64 __fastcall wmi_coap_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[619] = send_coap_add_pattern_cmd_tlv;
  v1[620] = send_coap_del_pattern_cmd_tlv;
  v1[621] = send_coap_add_keepalive_pattern_cmd_tlv;
  v1[622] = send_coap_del_keepalive_pattern_cmd_tlv;
  v1[623] = send_coap_cache_get_cmd_tlv;
  v1[624] = coap_extract_buf_info_tlv;
  return result;
}
