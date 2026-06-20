__int64 __fastcall ipa3_qmi_set_aggr_info(__int64 a1)
{
  int v1; // w19
  __int64 ipc_logbuf; // x0
  __int64 v3; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned int v12; // w19
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  _QWORD v26[2]; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v27[2]; // [xsp+10h] [xbp-20h] BYREF
  int v28; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v29; // [xsp+28h] [xbp-8h]

  v1 = a1;
  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v3 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v3, "ipa-wan %s:%d sending aggr_info_request\n", "ipa3_qmi_set_aggr_info", 2693);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v5 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(v5, "ipa-wan %s:%d sending aggr_info_request\n", "ipa3_qmi_set_aggr_info", 2693);
  }
  v28 = 0;
  dword_8784 = v1;
  v6 = *(_DWORD *)(ipa3_ctx + 43284);
  dword_8798 = v1;
  dword_87AC = v1;
  dword_87C0 = v1;
  dword_877C = v6;
  v27[1] = &ipa_mhi_prime_aggr_info_req_msg_v01_ei;
  v27[0] = 64;
  v26[1] = &ipa_mhi_prime_aggr_info_resp_msg_v01_ei;
  v26[0] = 64;
  v7 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
  if ( v7 )
  {
    v8 = ipa3_get_ipc_logbuf(v7);
    v7 = ipc_log_string(
           v8,
           "ipa-wan %s:%d Sending QMI_IPA_MHI_PRIME_AGGR_INFO_REQ_V01(%d)\n",
           "ipa3_qmi_set_aggr_info",
           2714,
           v1);
  }
  v9 = ipa3_get_ipc_logbuf_low(v7);
  if ( v9 )
  {
    v10 = ipa3_get_ipc_logbuf_low(v9);
    ipc_log_string(
      v10,
      "ipa-wan %s:%d Sending QMI_IPA_MHI_PRIME_AGGR_INFO_REQ_V01(%d)\n",
      "ipa3_qmi_set_aggr_info",
      2714,
      v1);
  }
  if ( ipa_q6_clnt )
  {
    v11 = ipa3_qmi_send_req_wait(
            ipa_q6_clnt,
            (unsigned __int16 *)v27,
            (__int64)&aggr_req,
            (__int64)v26,
            (__int64)&v28,
            0x1388u);
    v12 = v11;
    if ( (v11 & 0x80000000) != 0 )
    {
      v16 = printk(&unk_3CCE82, "ipa3_qmi_set_aggr_info");
      v17 = ipa3_get_ipc_logbuf(v16);
      if ( v17 )
      {
        v18 = ipa3_get_ipc_logbuf(v17);
        v17 = ipc_log_string(
                v18,
                "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
                "ipa3_qmi_set_aggr_info",
                2727,
                50,
                v12);
      }
      v19 = ipa3_get_ipc_logbuf_low(v17);
      if ( v19 )
      {
        v20 = ipa3_get_ipc_logbuf_low(v19);
        ipc_log_string(v20, "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n", "ipa3_qmi_set_aggr_info", 2727, 50, v12);
      }
      result = v12;
    }
    else
    {
      v13 = ipa3_get_ipc_logbuf_low(v11);
      if ( v13 )
      {
        v14 = ipa3_get_ipc_logbuf_low(v13);
        ipc_log_string(
          v14,
          "ipa-wan %s:%d QMI_IPA_MHI_PRIME_AGGR_INFO_RESP_V01 received\n",
          "ipa3_qmi_set_aggr_info",
          2731);
      }
      result = ipa3_check_qmi_response(
                 v12,
                 50,
                 (unsigned __int16)v28,
                 HIWORD(v28),
                 "ipa_mhi_prime_aggr_info_req_msg_v01");
    }
  }
  else
  {
    v21 = printk(&unk_3C747D, "ipa3_qmi_set_aggr_info");
    v22 = ipa3_get_ipc_logbuf(v21);
    if ( v22 )
    {
      v23 = ipa3_get_ipc_logbuf(v22);
      v22 = ipc_log_string(v23, "ipa-wan %s:%d  ipa_q6_clnt not initialized\n", "ipa3_qmi_set_aggr_info", 2716);
    }
    v24 = ipa3_get_ipc_logbuf_low(v22);
    if ( v24 )
    {
      v25 = ipa3_get_ipc_logbuf_low(v24);
      ipc_log_string(v25, "ipa-wan %s:%d  ipa_q6_clnt not initialized\n", "ipa3_qmi_set_aggr_info", 2716);
    }
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
