__int64 __fastcall handle_ipa_config_req(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 ipc_logbuf; // x0
  __int64 v9; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  int v13; // w22
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x7
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 result; // x0
  __int64 v23; // x0
  int v24; // w22
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  _QWORD v32[2]; // [xsp+0h] [xbp-10h] BYREF

  v32[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v32[0]) = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v9 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(v9, "ipa-wan %s:%d Received IPA CONFIG Request\n", "handle_ipa_config_req", 251);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v11 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v11, "ipa-wan %s:%d Received IPA CONFIG Request\n", "handle_ipa_config_req", 251);
  }
  v12 = ipa_mhi_handle_ipa_config_req(a4);
  if ( !(_DWORD)v12 )
  {
    v13 = 0;
    v14 = ipa3_get_ipc_logbuf(v12);
    if ( !v14 )
      goto LABEL_8;
    goto LABEL_7;
  }
  v24 = v12;
  v25 = printk(&unk_3AD3D8, "handle_ipa_config_req");
  v26 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v27 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v27 )
    {
      ipc_log_string(v27, "ipa %s:%d ipa3_mhi_handle_ipa_config_req failed %d\n", "handle_ipa_config_req", 255, v24);
      v26 = ipa3_ctx;
    }
    v25 = *(_QWORD *)(v26 + 34160);
    if ( v25 )
      v25 = ipc_log_string(
              v25,
              "ipa %s:%d ipa3_mhi_handle_ipa_config_req failed %d\n",
              "handle_ipa_config_req",
              255,
              v24);
  }
  v13 = 1;
  WORD2(v32[0]) = 1;
  v14 = ipa3_get_ipc_logbuf(v25);
  if ( v14 )
  {
LABEL_7:
    v15 = ipa3_get_ipc_logbuf(v14);
    v14 = ipc_log_string(v15, "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n", "handle_ipa_config_req", 260, v13, 0);
  }
LABEL_8:
  v16 = ipa3_get_ipc_logbuf_low(v14);
  if ( v16 )
  {
    v18 = ipa3_get_ipc_logbuf_low(v16);
    ipc_log_string(v18, "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n", "handle_ipa_config_req", 260, v13, 0);
  }
  v19 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, void *, char *, __int64, _QWORD))qmi_send_response)(
          a1,
          a2,
          a3,
          39,
          7,
          &ipa3_config_resp_msg_data_v01_ei,
          (char *)v32 + 4,
          v17,
          v32[0]);
  if ( (v19 & 0x80000000) != 0 )
  {
    v28 = printk(&unk_3AA228, "handle_ipa_config_req");
    v29 = ipa3_get_ipc_logbuf(v28);
    if ( v29 )
    {
      v30 = ipa3_get_ipc_logbuf(v29);
      v29 = ipc_log_string(v30, "ipa-wan %s:%d QMI_IPA_CONFIG_RESP_V01 failed\n", "handle_ipa_config_req", 268);
    }
    result = ipa3_get_ipc_logbuf_low(v29);
    if ( result )
    {
      v31 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v31, "ipa-wan %s:%d QMI_IPA_CONFIG_RESP_V01 failed\n", "handle_ipa_config_req", 268);
    }
  }
  else
  {
    v20 = ipa3_get_ipc_logbuf(v19);
    if ( v20 )
    {
      v21 = ipa3_get_ipc_logbuf(v20);
      v20 = ipc_log_string(v21, "ipa-wan %s:%d Responsed QMI_IPA_CONFIG_RESP_V01\n", "handle_ipa_config_req", 270);
    }
    result = ipa3_get_ipc_logbuf_low(v20);
    if ( result )
    {
      v23 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(v23, "ipa-wan %s:%d Responsed QMI_IPA_CONFIG_RESP_V01\n", "handle_ipa_config_req", 270);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
