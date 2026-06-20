__int64 __fastcall wmi_fwol_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[540] = send_set_elna_bypass_cmd_tlv;
  v1[541] = send_get_elna_bypass_cmd_tlv;
  v1[542] = extract_get_elna_bypass_resp_tlv;
  v1[543] = send_set_mdns_config_cmd_tlv;
  v1[544] = send_get_thermal_stats_cmd_tlv;
  return result;
}
