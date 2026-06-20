__int64 __fastcall ipa3_qmi_req_ind(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v4; // w19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v14[2]; // [xsp+10h] [xbp-30h] BYREF
  int v15; // [xsp+24h] [xbp-1Ch] BYREF
  __int64 v16; // [xsp+28h] [xbp-18h] BYREF
  char v17; // [xsp+30h] [xbp-10h]
  char v18; // [xsp+31h] [xbp-Fh]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 1;
  v14[1] = &ipa3_indication_reg_req_msg_data_v01_ei;
  v13[1] = &ipa3_indication_reg_resp_msg_data_v01_ei;
  v16 = 0;
  v15 = 0;
  v18 = a1;
  v14[0] = 0x1000000020LL;
  v13[0] = 0x700000020LL;
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v2 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v2, "ipa-wan %s:%d Sending QMI_IPA_INDICATION_REGISTER_REQ_V01\n", "ipa3_qmi_req_ind", 2761);
  }
  if ( ipa_q6_clnt )
  {
    v3 = ipa3_qmi_send_req_wait(
           ipa_q6_clnt,
           (unsigned __int16 *)v14,
           (__int64)&v16,
           (__int64)v13,
           (__int64)&v15,
           0x1388u);
    v4 = v3;
    if ( (v3 & 0x80000000) != 0 )
    {
      v8 = printk(&unk_3CCE82, "ipa3_qmi_req_ind");
      ipc_logbuf = ipa3_get_ipc_logbuf(v8);
      if ( ipc_logbuf )
      {
        v10 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v10,
                       "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n",
                       "ipa3_qmi_req_ind",
                       2772,
                       32,
                       v4);
      }
      v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( v11 )
      {
        v12 = ipa3_get_ipc_logbuf_low(v11);
        ipc_log_string(v12, "ipa-wan %s:%d QMI send Req %d failed, rc= %d\n", "ipa3_qmi_req_ind", 2772, 32, v4);
      }
      result = v4;
    }
    else
    {
      v5 = ipa3_get_ipc_logbuf_low(v3);
      if ( v5 )
      {
        v6 = ipa3_get_ipc_logbuf_low(v5);
        ipc_log_string(v6, "ipa-wan %s:%d QMI_IPA_INDICATION_REGISTER_RESP_V01 received\n", "ipa3_qmi_req_ind", 2776);
      }
      result = ipa3_check_qmi_response(v4, 32, (unsigned __int16)v15, HIWORD(v15), "ipa_indication_reg_req_msg_v01");
    }
  }
  else
  {
    result = 4294967186LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
