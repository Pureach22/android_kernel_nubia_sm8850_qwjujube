__int64 __fastcall ipa3_check_qmi_response(__int64 a1, int a2, unsigned int a3, int a4, const char *a5)
{
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v12; // x0
  __int64 ipc_logbuf; // x0
  __int64 v14; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v16; // x0
  unsigned int v17; // w20
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0

  if ( (a1 & 0x80000000) == 0 )
  {
    if ( a3 && ipa3_rmnet_ctx == 1 )
    {
      v12 = printk(&unk_3B87F3, "ipa3_check_qmi_response");
      ipc_logbuf = ipa3_get_ipc_logbuf(v12);
      if ( ipc_logbuf )
      {
        v14 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v14,
                       "ipa-wan %s:%d Got bad response %d from request id %d (error %d)\n",
                       "ipa3_check_qmi_response",
                       541,
                       a2,
                       a3,
                       a4);
      }
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( ipc_logbuf_low )
      {
        v16 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
        ipc_log_string(
          v16,
          "ipa-wan %s:%d Got bad response %d from request id %d (error %d)\n",
          "ipa3_check_qmi_response",
          541,
          a2,
          a3,
          a4);
      }
      return a3;
    }
    else
    {
      result = ipa3_get_ipc_logbuf_low(a1);
      if ( result )
      {
        v7 = ipa3_get_ipc_logbuf_low(result);
        ipc_log_string(v7, "ipa-wan %s:%d Received %s successfully\n", "ipa3_check_qmi_response", 544, a5);
        return 0;
      }
    }
    return result;
  }
  if ( (int)a1 > -103 )
  {
    if ( (_DWORD)a1 != -102 && (_DWORD)a1 != -19 )
      goto LABEL_29;
    goto LABEL_18;
  }
  if ( (_DWORD)a1 != -110 )
  {
    if ( (_DWORD)a1 != -104 )
      goto LABEL_29;
LABEL_18:
    v17 = a1;
    v18 = printk(&unk_3A3FC6, "ipa3_check_qmi_response");
    v19 = ipa3_get_ipc_logbuf(v18);
    if ( v19 )
    {
      v20 = ipa3_get_ipc_logbuf(v19);
      v19 = ipc_log_string(
              v20,
              "ipa-wan %s:%d SSR while waiting for qmi request id %d\n",
              "ipa3_check_qmi_response",
              530,
              a2);
    }
    v21 = ipa3_get_ipc_logbuf_low(v19);
    if ( v21 )
    {
      v22 = ipa3_get_ipc_logbuf_low(v21);
      ipc_log_string(v22, "ipa-wan %s:%d SSR while waiting for qmi request id %d\n", "ipa3_check_qmi_response", 530, a2);
    }
    return v17;
  }
  if ( ipa3_rmnet_ctx != 1 )
  {
LABEL_29:
    v17 = a1;
    v28 = printk(&unk_3FBA1B, "ipa3_check_qmi_response");
    v29 = ipa3_get_ipc_logbuf(v28);
    if ( v29 )
    {
      v30 = ipa3_get_ipc_logbuf(v29);
      v29 = ipc_log_string(
              v30,
              "ipa-wan %s:%d Error sending qmi request id %d, rc = %d\n",
              "ipa3_check_qmi_response",
              534,
              a2,
              v17);
    }
    v31 = ipa3_get_ipc_logbuf_low(v29);
    if ( v31 )
    {
      v32 = ipa3_get_ipc_logbuf_low(v31);
      ipc_log_string(
        v32,
        "ipa-wan %s:%d Error sending qmi request id %d, rc = %d\n",
        "ipa3_check_qmi_response",
        534,
        a2,
        v17);
    }
    return v17;
  }
  v23 = printk(&unk_3BB7A8, "ipa3_check_qmi_response");
  v24 = ipa3_get_ipc_logbuf(v23);
  if ( v24 )
  {
    v25 = ipa3_get_ipc_logbuf(v24);
    v24 = ipc_log_string(v25, "ipa-wan %s:%d Timeout for qmi request id %d\n", "ipa3_check_qmi_response", 525, a2);
  }
  v26 = ipa3_get_ipc_logbuf_low(v24);
  if ( v26 )
  {
    v27 = ipa3_get_ipc_logbuf_low(v26);
    ipc_log_string(v27, "ipa-wan %s:%d Timeout for qmi request id %d\n", "ipa3_check_qmi_response", 525, a2);
  }
  return 4294967186LL;
}
