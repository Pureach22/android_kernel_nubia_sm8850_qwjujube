__int64 __fastcall ipa3_handle_modem_init_cmplt_req(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 ipc_logbuf; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x0
  int v10; // w9
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x7
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 result; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  _QWORD v29[2]; // [xsp+0h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v29[0]) = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v7 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v7,
                   "ipa-wan %s:%d Received QMI_IPA_INIT_MODEM_DRIVER_CMPLT_REQ_V01\n",
                   "ipa3_handle_modem_init_cmplt_req",
                   282);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v9 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(
                       v9,
                       "ipa-wan %s:%d Received QMI_IPA_INIT_MODEM_DRIVER_CMPLT_REQ_V01\n",
                       "ipa3_handle_modem_init_cmplt_req",
                       282);
  }
  if ( (ipa3_modem_init_cmplt & 1) == 0 )
  {
    v10 = *(unsigned __int8 *)(ipa3_ctx + 43308);
    ipa3_modem_init_cmplt = 1;
    if ( v10 == 1 && ipa3_qmi_modem_init_fin == 1 )
    {
      v11 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
      if ( v11 )
      {
        v12 = ipa3_get_ipc_logbuf(v11);
        v11 = ipc_log_string(
                v12,
                "ipa-wan %s:%d load uc related registers (%d)\n",
                "ipa3_handle_modem_init_cmplt_req",
                290,
                (unsigned __int8)ipa3_qmi_modem_init_fin);
      }
      v13 = ipa3_get_ipc_logbuf_low(v11);
      if ( v13 )
      {
        v14 = ipa3_get_ipc_logbuf_low(v13);
        v13 = ipc_log_string(
                v14,
                "ipa-wan %s:%d load uc related registers (%d)\n",
                "ipa3_handle_modem_init_cmplt_req",
                290,
                (unsigned __int8)ipa3_qmi_modem_init_fin);
      }
      ipc_logbuf_low = ipa3_uc_load_notify(v13);
    }
  }
  HIDWORD(v29[0]) = 0;
  v15 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
  if ( v15 )
  {
    v16 = ipa3_get_ipc_logbuf(v15);
    v15 = ipc_log_string(
            v16,
            "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
            "ipa3_handle_modem_init_cmplt_req",
            299,
            0,
            0);
  }
  v17 = ipa3_get_ipc_logbuf_low(v15);
  if ( v17 )
  {
    v19 = ipa3_get_ipc_logbuf_low(v17);
    ipc_log_string(v19, "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n", "ipa3_handle_modem_init_cmplt_req", 299, 0, 0);
  }
  v20 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, void *, char *, __int64, _QWORD))qmi_send_response)(
          a1,
          a2,
          a3,
          53,
          7,
          &ipa3_init_modem_driver_cmplt_resp_msg_data_v01_ei,
          (char *)v29 + 4,
          v18,
          v29[0]);
  if ( (v20 & 0x80000000) != 0 )
  {
    v25 = printk(&unk_3C75E8, "ipa3_handle_modem_init_cmplt_req");
    v26 = ipa3_get_ipc_logbuf(v25);
    if ( v26 )
    {
      v27 = ipa3_get_ipc_logbuf(v26);
      v26 = ipc_log_string(
              v27,
              "ipa-wan %s:%d QMI_IPA_INIT_MODEM_DRIVER_CMPLT_RESP_V01 failed\n",
              "ipa3_handle_modem_init_cmplt_req",
              308);
    }
    result = ipa3_get_ipc_logbuf_low(v26);
    if ( result )
    {
      v28 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v28,
                 "ipa-wan %s:%d QMI_IPA_INIT_MODEM_DRIVER_CMPLT_RESP_V01 failed\n",
                 "ipa3_handle_modem_init_cmplt_req",
                 308);
    }
  }
  else
  {
    v21 = ipa3_get_ipc_logbuf(v20);
    if ( v21 )
    {
      v22 = ipa3_get_ipc_logbuf(v21);
      v21 = ipc_log_string(
              v22,
              "ipa-wan %s:%d Sent QMI_IPA_INIT_MODEM_DRIVER_CMPLT_RESP_V01\n",
              "ipa3_handle_modem_init_cmplt_req",
              310);
    }
    result = ipa3_get_ipc_logbuf_low(v21);
    if ( result )
    {
      v24 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v24,
                 "ipa-wan %s:%d Sent QMI_IPA_INIT_MODEM_DRIVER_CMPLT_RESP_V01\n",
                 "ipa3_handle_modem_init_cmplt_req",
                 310);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
