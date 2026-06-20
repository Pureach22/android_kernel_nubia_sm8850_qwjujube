__int64 (__fastcall *__fastcall select_interface(char a1))()
{
  __int64 (__fastcall *v1)(); // x8
  __int64 (__fastcall *v2)(); // x9
  __int64 (__fastcall *v3)(); // x10
  __int64 (__fastcall *v4)(); // x11
  __int64 (__fastcall *v5)(); // x12
  __int64 (__fastcall *v6)(); // x13
  __int64 (__fastcall *v7)(); // x14
  __int64 (__fastcall *v8)(); // x15
  __int64 (__fastcall *v9)(); // x16
  __int64 (__fastcall *v10)(); // x17
  __int64 (__fastcall *result)(); // x0
  __int64 (__fastcall *v12)(); // x1
  __int64 (__fastcall *v13)(); // x2
  __int64 (__fastcall *v14)(); // x3
  __int64 (__fastcall *v15)(); // x4
  __int64 (__fastcall *v16)(); // x5
  __int64 (__fastcall *v17)(); // x6
  __int64 (__fastcall *v18)(); // x7
  __int64 (__fastcall *v19)(); // x19
  __int64 (__fastcall *v20)(); // x20

  if ( (a1 & 1) != 0 )
  {
    v1 = hdcp2_update_app_data_smcinvoke;
    v2 = hdcp2_close_stream_smcinvoke;
    v3 = hdcp2_open_stream_smcinvoke;
    v4 = hdcp2_force_encryption_smcinvoke;
    v5 = hdcp2_feature_supported_smcinvoke;
    v6 = hdcp2_app_stop_smcinvoke;
    v7 = (__int64 (__fastcall *)())&hdcp2_app_query_stream_smcinvoke;
    v8 = (__int64 (__fastcall *)())&hdcp2_app_timeout_smcinvoke;
    v9 = hdcp2_app_enable_encryption_smcinvoke;
    v10 = (__int64 (__fastcall *)())&hdcp2_app_process_msg_smcinvoke;
    result = (__int64 (__fastcall *)())&hdcp2_app_start_auth_smcinvoke;
    v12 = hdcp2_app_start_smcinvoke;
    v13 = hdcp2_deinit_smcinvoke;
    v14 = hdcp2_init_smcinvoke;
    v15 = hdcp1_stop_smcinvoke;
    v16 = hdcp1_start_smcinvoke;
    v17 = hdcp1_ops_notify_smcinvoke;
    v18 = hdcp1_set_enc_smcinvoke;
    v19 = hdcp1_feature_supported_smcinvoke;
    v20 = hdcp1_init_smcinvoke;
  }
  else
  {
    v1 = hdcp2_update_app_data_qseecom;
    v2 = hdcp2_close_stream_qseecom;
    v3 = hdcp2_open_stream_qseecom;
    v4 = hdcp2_force_encryption_qseecom;
    v5 = hdcp2_feature_supported_qseecom;
    v6 = hdcp2_app_stop_qseecom;
    v7 = hdcp2_app_query_stream_qseecom;
    v8 = hdcp2_app_timeout_qseecom;
    v9 = hdcp2_app_enable_encryption_qseecom;
    v10 = hdcp2_app_process_msg_qseecom;
    result = hdcp2_app_start_auth_qseecom;
    v12 = hdcp2_app_start_qseecom;
    v13 = hdcp2_deinit_qseecom;
    v14 = hdcp2_init_qseecom;
    v15 = hdcp1_stop_qseecom;
    v16 = hdcp1_start_qseecom;
    v17 = hdcp1_ops_notify_qseecom;
    v18 = hdcp1_set_enc_qseecom;
    v19 = hdcp1_feature_supported_qseecom;
    v20 = hdcp1_init_qseecom;
  }
  ta_interface = v20;
  off_BC58 = v19;
  off_BC60 = v18;
  off_BC68 = v17;
  off_BC70 = v16;
  off_BC78 = v15;
  off_BC80 = v14;
  off_BC88 = v13;
  qword_BC90 = (__int64)v12;
  qword_BC98 = (__int64)result;
  qword_BCA0 = (__int64)v10;
  off_BCA8 = v8;
  qword_BCB0 = (__int64)v9;
  qword_BCB8 = (__int64)v7;
  off_BCC0 = v6;
  off_BCC8 = v5;
  off_BCD0 = v4;
  off_BCD8 = v3;
  off_BCE0 = v2;
  off_BCE8 = v1;
  return result;
}
