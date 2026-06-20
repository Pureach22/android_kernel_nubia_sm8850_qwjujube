__int64 __fastcall wmi_dbr_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[429] = send_dbr_cfg_cmd_tlv;
  v1[431] = extract_dbr_buf_release_entry_tlv;
  v1[432] = extract_dbr_buf_metadata_tlv;
  v1[433] = extract_dbr_buf_cv_metadata_tlv;
  v1[434] = extract_dbr_buf_cqi_metadata_tlv;
  v1[430] = extract_dbr_buf_release_fixed_tlv;
  v1[425] = extract_scaling_params_service_ready_ext_tlv;
  v1[435] = extract_dbr_buf_wifi_radar_metadata_tlv;
  return result;
}
