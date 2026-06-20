__int64 init_module()
{
  __int64 compatible_node; // x0
  char v1; // w0

  compatible_node = of_find_compatible_node(0, 0, "qcom,hdcp");
  if ( compatible_node )
  {
    v1 = of_find_property(compatible_node, "qcom,use-smcinvoke", 0) != 0;
    select_interface(v1);
  }
  else
  {
    ta_interface = hdcp1_init_qseecom;
    off_BC58 = hdcp1_feature_supported_qseecom;
    off_BC60 = hdcp1_set_enc_qseecom;
    off_BC68 = hdcp1_ops_notify_qseecom;
    off_BC70 = hdcp1_start_qseecom;
    off_BC78 = hdcp1_stop_qseecom;
    off_BC80 = hdcp2_init_qseecom;
    off_BC88 = hdcp2_deinit_qseecom;
    qword_BC90 = (__int64)hdcp2_app_start_qseecom;
    qword_BC98 = (__int64)hdcp2_app_start_auth_qseecom;
    qword_BCA0 = (__int64)hdcp2_app_process_msg_qseecom;
    off_BCA8 = hdcp2_app_timeout_qseecom;
    qword_BCB0 = (__int64)hdcp2_app_enable_encryption_qseecom;
    qword_BCB8 = (__int64)hdcp2_app_query_stream_qseecom;
    off_BCC0 = hdcp2_app_stop_qseecom;
    off_BCC8 = hdcp2_feature_supported_qseecom;
    off_BCD0 = hdcp2_force_encryption_qseecom;
    off_BCD8 = hdcp2_open_stream_qseecom;
    off_BCE0 = hdcp2_close_stream_qseecom;
    off_BCE8 = hdcp2_update_app_data_qseecom;
  }
  return 0;
}
