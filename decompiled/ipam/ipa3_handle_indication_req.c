__int64 __fastcall ipa3_handle_indication_req(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 ipc_logbuf; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  int v11; // w11
  __int64 v12; // x10
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x7
  __int64 v17; // x0
  __int64 v18; // x0
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
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x0
  _QWORD v36[2]; // [xsp+0h] [xbp-10h] BYREF

  v36[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v36[0]) = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v7 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v7, "ipa-wan %s:%d Received INDICATION Request\n", "ipa3_handle_indication_req", 105);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v9 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(
                       v9,
                       "ipa-wan %s:%d Received INDICATION Request\n",
                       "ipa3_handle_indication_req",
                       105);
  }
  v10 = *a2;
  v11 = *((_DWORD *)a2 + 2);
  HIDWORD(v36[0]) = 0;
  v12 = ipa3_qmi_ctx + 28864;
  *(_QWORD *)(ipa3_qmi_ctx + 28864) = v10;
  *(_DWORD *)(v12 + 8) = v11;
  v13 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
  if ( v13 )
  {
    v14 = ipa3_get_ipc_logbuf(v13);
    v13 = ipc_log_string(v14, "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n", "ipa3_handle_indication_req", 114, 0, 0);
  }
  v15 = ipa3_get_ipc_logbuf_low(v13);
  if ( v15 )
  {
    v17 = ipa3_get_ipc_logbuf_low(v15);
    ipc_log_string(v17, "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n", "ipa3_handle_indication_req", 114, 0, 0);
  }
  v18 = ((__int64 (__fastcall *)(__int64, __int64 *, __int64, __int64, __int64, void *, char *, __int64, _QWORD))qmi_send_response)(
          a1,
          a2,
          a3,
          32,
          7,
          &ipa3_indication_reg_resp_msg_data_v01_ei,
          (char *)v36 + 4,
          v16,
          v36[0]);
  if ( (v18 & 0x80000000) != 0 )
  {
    v24 = printk(&unk_3F8794, "ipa3_handle_indication_req");
    v25 = ipa3_get_ipc_logbuf(v24);
    if ( v25 )
    {
      v26 = ipa3_get_ipc_logbuf(v25);
      v25 = ipc_log_string(
              v26,
              "ipa-wan %s:%d send response for Indication register failed\n",
              "ipa3_handle_indication_req",
              122);
    }
    result = ipa3_get_ipc_logbuf_low(v25);
    if ( result )
    {
      v27 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v27,
                 "ipa-wan %s:%d send response for Indication register failed\n",
                 "ipa3_handle_indication_req",
                 122);
    }
  }
  else
  {
    ipa3_qmi_indication_fin = 1;
    if ( ipa3_qmi_modem_init_fin == 1 )
    {
      v19 = ipa3_get_ipc_logbuf(v18);
      if ( v19 )
      {
        v20 = ipa3_get_ipc_logbuf(v19);
        v19 = ipc_log_string(
                v20,
                "ipa-wan %s:%d send indication to modem (%d)\n",
                "ipa3_handle_indication_req",
                131,
                (unsigned __int8)ipa3_qmi_modem_init_fin);
      }
      v21 = ipa3_get_ipc_logbuf_low(v19);
      if ( v21 )
      {
        v22 = ipa3_get_ipc_logbuf_low(v21);
        ipc_log_string(
          v22,
          "ipa-wan %s:%d send indication to modem (%d)\n",
          "ipa3_handle_indication_req",
          131,
          (unsigned __int8)ipa3_qmi_modem_init_fin);
      }
      LODWORD(v36[0]) = 0;
      result = qmi_send_indication(
                 a1,
                 ipa3_qmi_ctx + 28864,
                 34,
                 7,
                 &ipa3_master_driver_init_complt_ind_msg_data_v01_ei,
                 v36);
      if ( (result & 0x80000000) != 0 )
      {
        v32 = printk(&unk_3E40EE, "ipa3_handle_indication_req");
        v33 = ipa3_get_ipc_logbuf(v32);
        if ( v33 )
        {
          v34 = ipa3_get_ipc_logbuf(v33);
          v33 = ipc_log_string(v34, "ipa-wan %s:%d send indication failed\n", "ipa3_handle_indication_req", 145);
        }
        result = ipa3_get_ipc_logbuf_low(v33);
        if ( result )
        {
          v35 = ipa3_get_ipc_logbuf_low(result);
          result = ipc_log_string(v35, "ipa-wan %s:%d send indication failed\n", "ipa3_handle_indication_req", 145);
        }
        ipa3_qmi_indication_fin = 0;
      }
    }
    else
    {
      v28 = printk(&unk_3E148F, "ipa3_handle_indication_req");
      v29 = ipa3_get_ipc_logbuf(v28);
      if ( v29 )
      {
        v30 = ipa3_get_ipc_logbuf(v29);
        v29 = ipc_log_string(v30, "ipa-wan %s:%d not send indication\n", "ipa3_handle_indication_req", 149);
      }
      result = ipa3_get_ipc_logbuf_low(v29);
      if ( result )
      {
        v31 = ipa3_get_ipc_logbuf_low(result);
        result = ipc_log_string(v31, "ipa-wan %s:%d not send indication\n", "ipa3_handle_indication_req", 149);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
