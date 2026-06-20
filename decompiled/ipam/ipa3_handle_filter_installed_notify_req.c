__int64 __fastcall ipa3_handle_filter_installed_notify_req(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 ipc_logbuf; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x7
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  _QWORD v24[2]; // [xsp+0h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  HIDWORD(v24[0]) = 0;
  ipc_logbuf = ipa3_get_ipc_logbuf(a1);
  if ( ipc_logbuf )
  {
    v7 = ipa3_get_ipc_logbuf(ipc_logbuf);
    ipc_logbuf = ipc_log_string(
                   v7,
                   "ipa-wan %s:%d Received filter_install_notify Request\n",
                   "ipa3_handle_filter_installed_notify_req",
                   224);
  }
  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
  if ( ipc_logbuf_low )
  {
    v9 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_logbuf_low = ipc_log_string(
                       v9,
                       "ipa-wan %s:%d Received filter_install_notify Request\n",
                       "ipa3_handle_filter_installed_notify_req",
                       224);
  }
  v10 = ipa3_get_ipc_logbuf(ipc_logbuf_low);
  if ( v10 )
  {
    v11 = ipa3_get_ipc_logbuf(v10);
    v10 = ipc_log_string(
            v11,
            "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
            "ipa3_handle_filter_installed_notify_req",
            228,
            0,
            0);
  }
  v12 = ipa3_get_ipc_logbuf_low(v10);
  if ( v12 )
  {
    v14 = ipa3_get_ipc_logbuf_low(v12);
    ipc_log_string(
      v14,
      "ipa-wan %s:%d qmi_snd_rsp: result %d, err %d\n",
      "ipa3_handle_filter_installed_notify_req",
      228,
      0,
      0);
  }
  v15 = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64, __int64, void *, char *, __int64, _QWORD))qmi_send_response)(
          a1,
          a2,
          a3,
          36,
          7,
          &ipa3_fltr_installed_notif_resp_msg_data_v01_ei,
          (char *)v24 + 4,
          v13,
          v24[0]);
  if ( (v15 & 0x80000000) != 0 )
  {
    v20 = printk(&unk_3C13B0, "ipa3_handle_filter_installed_notify_req");
    v21 = ipa3_get_ipc_logbuf(v20);
    if ( v21 )
    {
      v22 = ipa3_get_ipc_logbuf(v21);
      v21 = ipc_log_string(
              v22,
              "ipa-wan %s:%d handle filter rules failed\n",
              "ipa3_handle_filter_installed_notify_req",
              236);
    }
    result = ipa3_get_ipc_logbuf_low(v21);
    if ( result )
    {
      v23 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v23,
                 "ipa-wan %s:%d handle filter rules failed\n",
                 "ipa3_handle_filter_installed_notify_req",
                 236);
    }
  }
  else
  {
    v16 = ipa3_get_ipc_logbuf(v15);
    if ( v16 )
    {
      v17 = ipa3_get_ipc_logbuf(v16);
      v16 = ipc_log_string(
              v17,
              "ipa-wan %s:%d Responsed filter_install_notify Request\n",
              "ipa3_handle_filter_installed_notify_req",
              238);
    }
    result = ipa3_get_ipc_logbuf_low(v16);
    if ( result )
    {
      v19 = ipa3_get_ipc_logbuf_low(result);
      result = ipc_log_string(
                 v19,
                 "ipa-wan %s:%d Responsed filter_install_notify Request\n",
                 "ipa3_handle_filter_installed_notify_req",
                 238);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
