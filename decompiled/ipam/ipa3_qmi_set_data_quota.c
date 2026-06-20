__int64 __fastcall ipa3_qmi_set_data_quota(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int v5; // w19
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  _QWORD v14[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-20h] BYREF
  int v16; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[1] = &ipa3_set_data_usage_quota_req_msg_data_v01_ei;
  v14[1] = &ipa3_set_data_usage_quota_resp_msg_data_v01_ei;
  v16 = 0;
  v15[0] = 0xC800000032LL;
  v14[0] = 0x700000032LL;
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v3 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v3, "ipa-wan %s:%d Sending QMI_IPA_SET_DATA_USAGE_QUOTA_REQ_V01\n", "ipa3_qmi_set_data_quota", 2665);
  }
  if ( ipa_q6_clnt )
  {
    v4 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v15, a1, (__int64)v14, (__int64)&v16, 0x1388u);
    v5 = v4;
    if ( (v4 & 0x80000000) != 0 )
    {
      v9 = printk(&unk_3CCE82, "ipa3_qmi_set_data_quota");
      ipc_logbuf = ipa3_get_ipc_logbuf(v9);
      if ( ipc_logbuf )
      {
        v11 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v11,
                       "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
                       "ipa3_qmi_set_data_quota",
                       2676,
                       50,
                       v5);
      }
      v12 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v12 )
      {
        v13 = ipa3_get_ipc_logbuf_low(v12);
        ipc_log_string(v13, "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n", "ipa3_qmi_set_data_quota", 2676, 50, v5);
      }
      result = v5;
    }
    else
    {
      v6 = ipa3_get_ipc_logbuf_low(v4);
      if ( v6 )
      {
        v7 = ipa3_get_ipc_logbuf_low(v6);
        ipc_log_string(
          v7,
          "ipa-wan %s:%d QMI_IPA_SET_DATA_USAGE_QUOTA_RESP_V01 received\n",
          "ipa3_qmi_set_data_quota",
          2680);
      }
      result = ipa3_check_qmi_response(
                 v5,
                 50,
                 (unsigned __int16)v16,
                 HIWORD(v16),
                 "ipa_set_data_usage_quota_req_msg_v01");
    }
  }
  else
  {
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
