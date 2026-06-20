__int64 __fastcall wmi_packet_filtering_attach_tlv(__int64 result)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(result + 728);
  *(_QWORD *)(v1 + 1304) = send_enable_disable_packet_filter_cmd_tlv;
  *(_QWORD *)(v1 + 1312) = send_config_packet_filter_cmd_tlv;
  return result;
}
