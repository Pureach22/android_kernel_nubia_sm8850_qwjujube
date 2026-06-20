__int64 __fastcall ipa3_qmi_send_mhi_cleanup_request(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0
  int v13; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v14[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v15[3]; // [xsp+18h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v3,
                   "ipa-wan %s:%d Sending QMI_IPA_MHI_CLEANUP_REQ_V01\n",
                   "ipa3_qmi_send_mhi_cleanup_request",
                   3059);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v5, "ipa-wan %s:%d Sending QMI_IPA_MHI_CLEANUP_REQ_V01\n", "ipa3_qmi_send_mhi_cleanup_request", 3059);
  }
  if ( ipa_q6_clnt )
  {
    v15[1] = &ipa_mhi_cleanup_req_msg_v01_ei;
    v15[0] = 62;
    v14[1] = &ipa_mhi_cleanup_resp_msg_v01_ei;
    v14[0] = 62;
    v6 = ipa3_qmi_send_req_wait(ipa_q6_clnt, (unsigned __int16 *)v15, a1, (__int64)v14, (__int64)&v13, 0x3E8u);
    v7 = v6;
    v8 = ipa3_get_ipc_logbuf(v6);
    if ( v8 )
    {
      v9 = ipa3_get_ipc_logbuf(v8);
      v8 = ipc_log_string(
             v9,
             "ipa-wan %s:%d QMI_IPA_MHI_CLEANUP_RESP_V01 received\n",
             "ipa3_qmi_send_mhi_cleanup_request",
             3078);
    }
    v10 = ipa3_get_ipc_logbuf_low(v8);
    if ( v10 )
    {
      v11 = ipa3_get_ipc_logbuf_low(v10);
      ipc_log_string(
        v11,
        "ipa-wan %s:%d QMI_IPA_MHI_CLEANUP_RESP_V01 received\n",
        "ipa3_qmi_send_mhi_cleanup_request",
        3078);
    }
    result = ipa3_check_qmi_response(v7, 62, (unsigned __int16)v13, HIWORD(v13), "ipa_mhi_cleanup_req_msg");
  }
  else
  {
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
