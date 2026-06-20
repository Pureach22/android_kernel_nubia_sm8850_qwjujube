__int64 __fastcall ipa3_qmi_get_per_client_packet_stats(__int64 a1, unsigned __int16 *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 v5; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int v9; // w20
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  _QWORD v20[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v21[3]; // [xsp+18h] [xbp-18h] BYREF

  v21[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[1] = &ipa3_get_stats_per_client_req_msg_data_v01_ei;
  v20[1] = &ipa3_get_stats_per_client_resp_msg_data_v01_ei;
  v21[0] = 57;
  v20[0] = 57;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v5 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v5,
                   "ipa-wan %s:%d Sending QMI_IPA_GET_STATS_PER_CLIENT_REQ_V01\n",
                   "ipa3_qmi_get_per_client_packet_stats",
                   2883);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v7 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(
      v7,
      "ipa-wan %s:%d Sending QMI_IPA_GET_STATS_PER_CLIENT_REQ_V01\n",
      "ipa3_qmi_get_per_client_packet_stats",
      2883);
  }
  if ( ipa_q6_clnt )
  {
    v8 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v21, a1, (__int64)v20, (__int64)a2, 0x1388u);
    v9 = v8;
    if ( (v8 & 0x80000000) != 0 )
    {
      v15 = printk(&unk_3EF59E, "ipa3_qmi_get_per_client_packet_stats");
      v16 = ipa3_get_ipc_logbuf(v15);
      if ( v16 )
      {
        v17 = ipa3_get_ipc_logbuf(v16);
        v16 = ipc_log_string(
                v17,
                "ipa-wan %s:%d send Req %d failed, rc= %d\n",
                "ipa3_qmi_get_per_client_packet_stats",
                2895,
                57,
                v9);
      }
      v18 = ipa3_get_ipc_logbuf_low(v16);
      if ( v18 )
      {
        v19 = ipa3_get_ipc_logbuf_low(v18);
        ipc_log_string(
          v19,
          "ipa-wan %s:%d send Req %d failed, rc= %d\n",
          "ipa3_qmi_get_per_client_packet_stats",
          2895,
          57,
          v9);
      }
      result = v9;
    }
    else
    {
      v10 = ipa3_get_ipc_logbuf(v8);
      if ( v10 )
      {
        v11 = ipa3_get_ipc_logbuf(v10);
        v10 = ipc_log_string(
                v11,
                "ipa-wan %s:%d QMI_IPA_GET_STATS_PER_CLIENT_RESP_V01 received\n",
                "ipa3_qmi_get_per_client_packet_stats",
                2899);
      }
      v12 = ipa3_get_ipc_logbuf_low(v10);
      if ( v12 )
      {
        v13 = ipa3_get_ipc_logbuf_low(v12);
        ipc_log_string(
          v13,
          "ipa-wan %s:%d QMI_IPA_GET_STATS_PER_CLIENT_RESP_V01 received\n",
          "ipa3_qmi_get_per_client_packet_stats",
          2899);
      }
      result = ipa3_check_qmi_response(v9, 57, *a2, a2[1], "struct ipa_get_stats_per_client_req_msg_v01");
    }
  }
  else
  {
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
