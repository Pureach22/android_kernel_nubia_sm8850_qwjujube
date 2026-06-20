__int64 __fastcall ipa3_qmi_get_network_stats(__int64 a1, unsigned __int16 *a2)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w20
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x0
  __int64 ipc_logbuf; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  _QWORD v16[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v17[3]; // [xsp+18h] [xbp-18h] BYREF

  v17[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17[1] = &ipa3_get_apn_data_stats_req_msg_data_v01_ei;
  v16[1] = &ipa3_get_apn_data_stats_resp_msg_data_v01_ei;
  v17[0] = 49;
  v16[0] = 49;
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v5, "ipa-wan %s:%d Sending QMI_IPA_GET_APN_DATA_STATS_REQ_V01\n", "ipa3_qmi_get_network_stats", 2625);
  }
  if ( ipa_q6_clnt )
  {
    v6 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v17, a1, (__int64)v16, (__int64)a2, 0x1388u);
    v7 = v6;
    if ( (v6 & 0x80000000) != 0 )
    {
      v11 = printk(&unk_3CCE82, "ipa3_qmi_get_network_stats");
      ipc_logbuf = ipa3_get_ipc_logbuf(v11);
      if ( ipc_logbuf )
      {
        v13 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v13,
                       "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
                       "ipa3_qmi_get_network_stats",
                       2637,
                       49,
                       v7);
      }
      v14 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v14 )
      {
        v15 = ipa3_get_ipc_logbuf_low(v14);
        ipc_log_string(
          v15,
          "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
          "ipa3_qmi_get_network_stats",
          2637,
          49,
          v7);
      }
      result = v7;
    }
    else
    {
      v8 = ipa3_get_ipc_logbuf_low(v6);
      if ( v8 )
      {
        v9 = ipa3_get_ipc_logbuf_low(v8);
        ipc_log_string(
          v9,
          "ipa-wan %s:%d QMI_IPA_GET_APN_DATA_STATS_RESP_V01 received\n",
          "ipa3_qmi_get_network_stats",
          2641);
      }
      result = ipa3_check_qmi_response(v7, 49, *a2, a2[1], "ipa_get_apn_data_stats_req_msg_v01");
    }
  }
  else
  {
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
